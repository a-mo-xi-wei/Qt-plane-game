#include "Sprite.h"

Sprite::Sprite(const QString& filename, const QSize& size)
{
	setPixmap(filename, size);
}

QSize Sprite::size() const
{
	if (m_pixmap.isNull())
		return QSize();
	return m_pixmap.size();
}

void Sprite::setPixmap(const QString& filename, const QSize& size)
{
	m_pixmap.load(filename);
	if (size.isValid())
	{
		m_pixmap = m_pixmap.scaled(size, Qt::AspectRatioMode::KeepAspectRatio);
	}
}

void Sprite::update()
{
	float x = m_pos.x();
	float y = m_pos.y();

	x += m_velocity.x() * m_speed;
	y += m_velocity.y() * m_speed;

	m_pos = { x,y };

	m_collider = QRect(m_pos.x(), m_pos.y(), m_pixmap.width(), m_pixmap.height());
}

void Sprite::render(QPainter* painter)
{
	painter->drawPixmap(m_pos.toPoint(), m_pixmap);
}
