#ifndef ENTITY_H_
#define ENTITY_H_
#include<QPainter>
#include"Global.h"
class Entity
{
public:
	virtual ~Entity() {}
	virtual void update() = 0;
	virtual void render(QPainter* painter) = 0;

	bool active()const { return m_active; }
	void destory() { m_active = false; }

	int type()const { return m_type; }
	void setType(int type) { m_type = type; }

private:
	bool m_active{ true };	//实体是否是活动的
	int m_type{};			//实体类型
};

#endif
