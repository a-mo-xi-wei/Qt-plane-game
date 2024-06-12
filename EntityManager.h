#ifndef		ENTITYMANAGER_H_
#define		ENTITYMANAGER_H_

#include"Sprite.h"
#include<QDebug>
#include<QList>
#include<memory>
#define eMgr  EntityManager::instance()
class EntityManager
{
public:
	static EntityManager& instance() { static EntityManager em; return em; };

	void update()
	{
		for (auto& e : m_entities)
			e->update();
	}
	void render(QPainter* painter)
	{
		for (auto& e : m_entities)
			e->render(painter);
	}

	template<typename T>
	T* addEntity(T* e)
	{
		m_entities.emplaceBack(e);
		return e;
	}

	void refresh()
	{
		m_entities.removeIf([](Entity* e)
			{
				if (!e->active())
				{
					qDebug() << "destoryed" << e;
					delete e;
					return true;
				}
				return false;
			});
		qDebug() << "size is " << m_entities.size();
	}

	QList<Sprite*> getSpriteByType(int type)
	{
		QList<Sprite*> s;
		for (auto& e : m_entities)
		{
			if (e->type() == type && e->active())
			{
				s.append(dynamic_cast<Sprite*>(e));
			}
		}
		return s;
	}

private:
	EntityManager() {}
	QList<Entity*> m_entities;
};

#endif
