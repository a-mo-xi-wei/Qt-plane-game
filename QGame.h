#ifndef QGAME_H_
#define QGAME_H_
#include<QWidget>
#include<QTimer>

#define qGame QGame::instance()

class QGame : public QWidget
{
	Q_OBJECT
public:
	static QGame* instance();

	QGame(QWidget* parent = nullptr);
	~QGame();
	//游戏初始化
	void init(const QSize& size, const QString& title);
	//游戏反初始化(清理)
	void clean();
	//更新游戏
	void update(int);
	//渲染游戏
	void render(QPainter* painter);
	//游戏是否在运行
	bool isRunning()const;
	//退出游戏
	void quit();
	//运行游戏
	void run();

	//设置游戏帧率
	void setFps(qreal fps);
	qreal fps()const { return m_fps; }
protected:
	void paintEvent(QPaintEvent* ev)override;
	void keyPressEvent(QKeyEvent* ev)override;
	void keyReleaseEvent(QKeyEvent* ev)override;
	void mouseMoveEvent(QMouseEvent* ev)override;
private:
	bool m_isRunning = false;
	qreal m_fps{ 1000 / 60.0 };
	QTimer* m_mainLoopTimer{};


};
#endif // QGAME_H_
