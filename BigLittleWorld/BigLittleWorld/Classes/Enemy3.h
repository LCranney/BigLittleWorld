#ifndef __CocosProject__ENEMY3__
#define __CocosProject__ENEMY3__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

#include <stdio.h>


class Enemy3 : public cocos2d::Node
{
public:
	Enemy3();
	~Enemy3();

	virtual bool init(float SXPos, float SYPos, float Dis);
	static Enemy3* create(float SXPos, float SYPos, float Dis);

	void    update(float);

private:
	cocos2d::Sprite* enemy3;
	float       startXPosition;
	float       startYPosition;
	float       currentSpeed;
	bool		MovingLeft;
	float		distance;
	int			movement;
	int			startMovement;

};
#endif 