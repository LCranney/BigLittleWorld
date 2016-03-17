#ifndef __CocosProject__PLAYER__
#define __CocosProject__PLAYER__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

#include <stdio.h>


class Player : public cocos2d::Node
{
public:
	Player();
	~Player();

	virtual bool init(float SXPos, float SYPos);
	static Player* create(float SXPos, float SYPos);

private:
	cocos2d::Sprite* player;
	float       startXPosition;
	float       startYPosition;

};
#endif 