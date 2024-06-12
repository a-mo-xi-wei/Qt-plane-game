#include "QGame.h"
#include "Sprite.h"
#include "EntityManager.h"
#include "PlayerPlane.h"
#include "Map.h"

#include <QApplication>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <qrandom.h>
#define qRand(min,max) QRandomGenerator::global()->bounded(min, max)
static QGame* ins = nullptr;
QGame* QGame::instance()
{
	return ins;
}

QGame::QGame(QWidget* parent)
	:QWidget(parent)
	, m_mainLoopTimer(new QTimer(this))
{
	Q_ASSERT_X(ins == nullptr, "QGame", "There is already an instance of QGame");
	ins = this;
}

QGame::~QGame()
{
	clean();
}

PlayerPlane* player;
void QGame::init(const QSize& size, const QString& title)
{
	setFixedSize(size);
	setWindowTitle(title);
	setMouseTracking(true);

	eMgr.addEntity(new Map);
	player = eMgr.addEntity(new PlayerPlane(":/Resource/images/hero1.png"));
	player->setType(Player);

	//各种资源的初始化，如果初始化失败，那么isrunning = false;
	m_isRunning = true;
}

void QGame::clean()
{
}

void QGame::update(int)
{
	eMgr.refresh();
	eMgr.update();

	static int i = 0;
	if (i % 10 == 0)
		player->emitBullet();

	if (i % 60 == 0)
	{
		QStringList efile = { ":/Resource/images/enemy1.png",":/Resource/images/enemy2.png" };
		auto enemy = new Sprite(efile[qRand(0, 2)]);
		enemy->velocity().setY(1);
		enemy->setPos(qRand(0, width()), -50);
		enemy->setType(Enemy);
		eMgr.addEntity(enemy);
	}

	//获取子弹列表
	auto bullet_list = eMgr.getSpriteByType(bullet);
	//获取敌机列表
	auto enemy_list = eMgr.getSpriteByType(Enemy);

	for (auto& e : enemy_list)
	{
		for (auto& b : bullet_list)
		{
			if (e->collider().intersects(b->collider()))
			{
				e->destory();
				b->destory();
				break;
			}
		}
	}



	i++;
}

void QGame::render(QPainter* painter)
{
	eMgr.render(painter);
}

bool QGame::isRunning() const
{
	return m_isRunning;
}

void QGame::quit()
{
	m_isRunning = false;
}

void QGame::run()
{
	show();
	m_mainLoopTimer->callOnTimeout([=]
		{
			//如果游戏没有在运行，那么就结束游戏
			if (!isRunning())
			{
				m_mainLoopTimer->stop();
				qApp->quit();
			}
			//更新游戏
			update(0);
			//重绘
			QWidget::update();
			//qDebug() << "running";
		});
	m_mainLoopTimer->start(m_fps);
}

void QGame::setFps(qreal fps)
{
	m_fps = fps;
}

void QGame::paintEvent(QPaintEvent* ev)
{
	QPainter painter(this);
	render(&painter);
}

void QGame::keyPressEvent(QKeyEvent* ev)
{
	switch (ev->key())
	{
	case Qt::Key_Up:
		player->velocity().setY(-1);
		break;
	case Qt::Key_Down:
		player->velocity().setY(1);
		break;
	case Qt::Key_Left:
		player->velocity().setX(-1);
		break;
	case Qt::Key_Right:
		player->velocity().setX(1);
		break;
	}
}

void QGame::keyReleaseEvent(QKeyEvent* ev)
{
	switch (ev->key())
	{
	case Qt::Key_Up:
	case Qt::Key_Down:
		player->velocity().setY(0);
		break;
	case Qt::Key_Left:
	case Qt::Key_Right:
		player->velocity().setX(0);
		break;
	}
}

void QGame::mouseMoveEvent(QMouseEvent* ev)
{
	auto s = player->size() / 2;
	player->setPos(ev->pos() - QPoint{ s.width(), s.height() });

}
