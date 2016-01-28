#ifndef __CocosProject__ENEMY2__
#define __CocosProject__ENEMY2__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

#include <stdio.h>


class Enemy2 : public cocos2d::Node
{
public:
	Enemy2();
	~Enemy2();

	virtual bool init() override;
	static Enemy2* create();

	void    update(float);

private:
	cocos2d::Sprite* enemy2;
	float       startXPosition;
	float       startYPosition;
	float       currentSpeed;
	bool		MovingDown;


};
#endif 