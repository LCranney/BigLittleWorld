#ifndef __PickMeUp_H__
#define __PickMeUp_H__

#include "cocos2d.h"

class PickMeUp : public cocos2d::Layer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	void Update(float);

	//Custom Methods for each Collectible type
	void Shield();
	void WingsOfLife();
	void Glue();
	void Slingshot();
	void cCommon();
	void cUncommon();
	void cRare();


	//Temporary Variables
	//TEMP scoreing
	int TEMP_score;
	int TEMP_pointValueCommon;
	int TEMP_pointValueUncommon;
	int TEMP_pointValueRare;
	//TEMP collisions
	int TEMP_collisionValue;
	int TEMP_playerProtectionCount;
	bool TEMP_playerProtection;
	//TEMP Lives
	int TEMP_lifeValue;
	int TEMP_playerLives;
	//TEMP speed
	int TEMP_speedBoost;
	int TEMP_playerSpeed;
	//TEMP Sticky


};

#endif // __PickMeUp_H__
