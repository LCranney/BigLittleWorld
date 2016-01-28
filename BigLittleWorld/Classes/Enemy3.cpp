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
	auto rootNode = CSLoader::createNode("res/Enemy3.csb");
	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height*0.0));
	this->scheduleUpdate();

	enemy3 = (Sprite*)rootNode->getChildByName("water");

	startXPosition = 570.0f;
	startYPosition = -50.0f;
	enemy3->setPosition(startXPosition, startYPosition);

	MovingUp = false;

	currentSpeed = 10.8f;

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
		enemy3->setPositionY(enemy3->getPositionY() + (currentSpeed * deltaTime));
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