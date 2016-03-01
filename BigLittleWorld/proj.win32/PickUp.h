#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <stdio.h>

class PickUp : public cocos2d::Node
{
public:
	PickUp();
	~PickUp();

	virtual bool init(float PXS, float PYS, float Dist);
	static PickUp* create(float PXS, float PYS, float Dist);
	void Update(float);

private:
	cocos2d::Sprite* sShield;
	cocos2d::Sprite* sWOL;
	cocos2d::Sprite* sSlingshot;
	cocos2d::Sprite* seRare;
	cocos2d::Sprite* seCommon;
	cocos2d::Sprite* seUncommon;
	cocos2d::Sprite* sGlue;
	float PositionXStart;
	float PositionYStart;
	float CurrentSpeed;
	bool MovingDown;
	float Distance;
};

