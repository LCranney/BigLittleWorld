#include "PickMeUp.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

// on "init" you need to initialize your instance
bool PickMeUp::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void PickMeUp::Update(float deltatime)
{



}

//========================================////========================================////========================================//
//========================================////=========== Pick Up Methods ============////========================================//
//========================================////========================================////========================================//
//========================================////=========== Special PickUps ============////========================================//
//Protects from Hotiles for one Collision
void PickMeUp::Shield()
{
	TEMP_collisionValue = 1;
	TEMP_playerProtectionCount = TEMP_playerProtection + TEMP_collisionValue; 
	/*
	PlayerProtectionCount should be a global variable handled by the GameManager to determine how many collisions with hostiles should be ignored.
	*/

	//Auto Activated on PickUp
}
//Grants extra life to try level again retaining score
void PickMeUp::WingsOfLife()
{
	TEMP_lifeValue = 1;
	TEMP_playerLives = TEMP_playerLives + TEMP_lifeValue;
	/*
	PlayerLives should be a global variable handled by the GameManger in order to determine how many lives the player has remaining.
	*/

	//Auto Activated on PickUp
}
//Allows player to stick to walls
void PickMeUp::Glue()
{
	/*
	Not sure how just yet but, once activated  this method will make it so that once the player collides with a wall
	this method stops the player where the collision happened and disables gravity so that the player sits on the wall to be moved 
	again when ready. 
	As soon as the player moves gravity is re-enabled and normal richochets occur off walls.
	*/

	//Has to be Activated
}
//Speed boost, fly through hostiles, kill flown through hostiles, further distance
void PickMeUp::Slingshot()
{
	TEMP_playerProtection = true;
	TEMP_speedBoost = 2;
	TEMP_playerSpeed = TEMP_playerSpeed * TEMP_speedBoost;
	/*
	PlayerProtection should be a global variable handled by the GameManger to determine if hostile collisons is turned on or off.
	*/

	//Has to be Activated
}
//========================================////========================================////========================================//
//========================================////=========== Points  PickUps ============////========================================//
//Low Value
void PickMeUp::cCommon()
{
	TEMP_pointValueCommon = 5;
	TEMP_score = TEMP_score + TEMP_pointValueCommon;

	//Auto Activated on PickUp
}
//Medium Value
void PickMeUp::cUncommon()
{
	TEMP_pointValueUncommon = 10;
	TEMP_score = TEMP_score + TEMP_pointValueUncommon;

	//Auto Activated on PickUp
}
//High Value
void PickMeUp::cRare()
{
	TEMP_pointValueRare = 20;
	TEMP_score = TEMP_score + TEMP_pointValueRare;

	//Auto Activated on PickUp
}
