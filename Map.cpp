#include "Map.h"
#include "QGame.h"
Map::Map()
{
	m_pixmap.load(":/Resource/images/background.png");
	yPos1 = -m_pixmap.height();
	yPos2 = 0;
}

void Map::update()
{
	yPos1 += m_scrollSpeed;
	if (yPos1 >= 0)
	{
		yPos1 = -m_pixmap.height();
	}

	yPos2 += m_scrollSpeed;
	if (yPos2 >= qGame->height())
	{
		yPos2 = 0;
	}
}

void Map::render(QPainter* painter)
{
	painter->drawPixmap(0,yPos1,m_pixmap);
	painter->drawPixmap(0,yPos2,m_pixmap);
}
