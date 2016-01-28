#ifndef __PickMeUp_H__
#define __PickMeUp_H__

#include "cocos2d.h"

class PickMeUp : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();


	//Custom Methods for each Collectible type
	void Shield();
	void WingsOfLife();
	void Glue();
	void Slingshot();
	void cCommon();
	void cUncommon();
	void cRare();

};

#endif // __PickMeUp_H__
