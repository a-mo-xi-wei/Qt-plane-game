﻿#ifndef MAP_H_
#define MAP_H_

#include"Entity.h"

class Map : public Entity
{
public:
	Map();
	void update() override;
	void render(QPainter* painter) override;

private:
	QPixmap m_pixmap;
	int yPos1, yPos2;
	int m_scrollSpeed{ 2 };
};

#endif // !MAP_H
