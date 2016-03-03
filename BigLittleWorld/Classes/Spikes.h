#ifndef __CocosProject__SPIKES__
#define __CocosProject__SPIKES__

#include "cocos2d.h"
#include "ui/cocosGUI.h"

#include <stdio.h>


class Spikes : public cocos2d::Node
{
public:
	Spikes();
	~Spikes();

	virtual bool init(float SXPos, float SYPos, float Dis);
	static Spikes* create(float SXPos, float SYPos, float Dis);

	void    update(float);

private:
	cocos2d::Sprite* spike;
	float       startXPosition;
	float       startYPosition;
	float		distance;

};
#endif 