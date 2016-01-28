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
//========================================//
//=========== Pick Up Methods ============//
//========================================//
//=========== Special PickUps ============//
//Protects from Hotiles for one Collision
void PickMeUp::Shield()
{
	//Auto Activated on PickUp
}
//Grants extra life to try level again retaining score
void PickMeUp::WingsOfLife()
{
	//Auto Activated on PickUp
}
//Allows player to stick to walls
void PickMeUp::Glue()
{
	//Has to be Activated
}
//Speed boost, fly throw hostiles, kill flown through hostiles, further distance
void PickMeUp::Slingshot()
{
	//Has to be Activated
}
//========================================//
//=========== Points  PickUps ============//
//Low Value
void PickMeUp::cCommon()
{
	//Auto Activated on PickUp
}
//Medium Value
void PickMeUp::cUncommon()
{
	//Auto Activated on PickUp
}
//High Value
void PickMeUp::cRare()
{
	//Auto Activated on PickUp
}
