#include "Enemy3.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Enemy3* Enemy3::create(float SXPos, float SYPos, float Dis)
{
	Enemy3* myNode = new Enemy3();
	if (myNode->init(SXPos, SYPos, Dis))
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

bool Enemy3::init(float SXPos, float SYPos, float Dis)
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("res/Enemy3.csb");
	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height*0.4));
	this->scheduleUpdate();

	enemy3 = (Sprite*)rootNode->getChildByName("Enemy3");

	startXPosition = SXPos;
	startYPosition = SYPos;
	distance = Dis;
	enemy3->setPosition(startXPosition, startYPosition);

	currentSpeed = 350.0f;
	movement = 1;

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

	if (movement == 1)
	{
		if (enemy3->getPositionY() > startYPosition - distance)
		{
			enemy3->setPositionY(enemy3->getPositionY() - (currentSpeed * deltaTime));
		}
	}
	else if (movement == 2)
	{
		if (enemy3->getPositionX() < startXPosition + distance)
		{
			enemy3->setPositionX(enemy3->getPositionX() + (currentSpeed * deltaTime));
		}

	}
	else if (movement == 3)
	{
		if (enemy3->getPositionX() > startXPosition)
		{
			enemy3->setPositionX(enemy3->getPositionX() - (currentSpeed * deltaTime));
		}
	}
	else if (movement == 4)
	{
		if (enemy3->getPositionY() < startYPosition)
		{
			enemy3->setPositionY(enemy3->getPositionY() + (currentSpeed * deltaTime));
		}
	}

	if (enemy3->getPositionY() > startYPosition && movement == 4)
		{
			movement = 1;
		}
	if (enemy3->getPositionY() < startYPosition - distance && movement == 1)
		{
			movement = 2;
		}
	if (enemy3->getPositionX() > startXPosition + distance && movement == 2)
		{
			movement = 3;
		}
	if (enemy3->getPositionX() < startXPosition && movement == 3)
		{
			movement = 4;
		}
}