#ifndef PLAYERPLANE_H_
#define  PLAYERPLANE_H_

#include"Sprite.h"
#include"Bullet.h"
#include<array>
class PlayerPlane : public Sprite
{
public:
	using Sprite::Sprite;
	PlayerPlane();
	bool emitBullet();
};


#endif
