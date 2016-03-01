#ifndef __CocosProject__ENEMY1__
#define __CocosProject__ENEMY1__

#include "cocos2d.h"
#include "SpriteAnimator.h"
#include "ui/cocosGUI.h"
#include <string>

#include <stdio.h>

using namespace std;

class Enemy1 : public cocos2d::Node
{
public:
	Enemy1();
	~Enemy1();

	virtual bool init(float SXPos, float SYPos, float Dis);
	static Enemy1* create(float SXPos, float SYPos, float Dis);

	void    update(float);

private:
	cocos2d::Sprite* enemy1;
	float       startXPosition;
	float       startYPosition;
	float       currentSpeed;
	bool		MovingLeft;
	float		distance;
	int movement;
	int startMovement;
	SpriteAnimator* enemyAnimation;

	Vector<SpriteFrame*> frames;
	Animation* animation;
};
#endif 