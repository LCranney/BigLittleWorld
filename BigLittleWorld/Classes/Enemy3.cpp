#include "Enemy3.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Enemy3* Enemy3::create()
{
	Enemy3* myNode = new Enemy3();
	if (myNode->init())
	{
		myNode->autorelease();
		return myNode;
	}
	else
	{
		CC_SAFE_DELETE(myNode);
		return nullptr;
	}
	return myNode;
}

bool Enemy3::init()
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	/*auto rootNode = CSLoader::createNode("res/Wall.csb");
	addChild(rootNode);*/

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height*0.8));
	this->scheduleUpdate();

	//enemy1 = (Sprite*)rootNode->getChildByName("Wall");

	startXPosition = 400.0f;
	startYPosition = enemy3->getPositionY();
	enemy3->setPosition(startXPosition, startYPosition);

	MovingUp = false;

	currentSpeed = 514.8f;

	return true;
}

Enemy3::Enemy3()
{
}


Enemy3::~Enemy3()
{

}


void Enemy3::update(float deltaTime)
{
	//Get the window size.
	auto  winSize = Director::getInstance()->getVisibleSize();
		
	if (MovingUp == false)
	{
		enemy3->setPositionY(enemy3->getPositionY() + (1.0f));
	}
	//else
	//{
	//	barrel->setPositionY(barrel->getPositionY() + (currentSpeed * deltaTime));
	//}

	//if (barrel->getPositionY() > startXPosition + 400.0f)
	//{
	//	MovingLeft = true;
	//}

	if (enemy3->getPositionY() < startXPosition - 0.0f)
	{
		MovingUp = false;
	}
			
}