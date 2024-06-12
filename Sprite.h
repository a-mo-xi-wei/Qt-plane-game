#ifndef SPRITE_H_
#define SPRITE_H_

#include "Entity.h"
#include <QVector2D>

class Sprite : public Entity
{
public:
	Sprite() = default;
	Sprite(const QString& filename, const QSize& size = QSize());

	void moveBy(float dx, float dy) { m_pos += {dx, dy}; }
	void setPos(float x, float y) { m_pos = { x,y }; }
	void setPos(const QPointF& pos) { m_pos = { (float)pos.x(),(float)pos.y() }; }
	void setPos(const QVector2D& pos) { m_pos = pos; }
	QVector2D pos()const { return m_pos; }

	void setVelocity(float vx, float vy) { m_velocity = { vx,vy }; }
	QVector2D& velocity() { return  m_velocity; }
	QVector2D velocity()const { return  m_velocity; }

	QSize size()const;

	QRect collider()const { return m_collider; }

	void setPixmap(const QString& filename, const QSize& size = QSize());
	QPixmap pixmap()const { return m_pixmap; }

	void update() override;
	void render(QPainter* painter) override;
private:
	QPixmap m_pixmap;
	QVector2D m_pos;
	float m_speed{ 3 };		//速度
	QVector2D m_velocity;	//分量

	QRect m_collider{};		//碰撞器
};

#endif // !SPRITE_H_
