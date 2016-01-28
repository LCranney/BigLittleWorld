#include "Enemy2.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Enemy2* Enemy2::create(float SXPos, float SYPos, float Dis)
{
	Enemy2* myNode = new Enemy2();
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

bool Enemy2::init(float SXPos, float SYPos, float Dis)
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("res/Enemy2.csb");
	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height*0.4));
	this->scheduleUpdate();

	enemy2 = (Sprite*)rootNode->getChildByName("Enemy2");

	startXPosition = SXPos;
	startYPosition = SYPos;
	distance = Dis;
	enemy2->setPosition(startXPosition, startYPosition);

	MovingDown = false;

	currentSpeed = 514.8f;

	return true;
}

Enemy2::Enemy2()
{
}


Enemy2::~Enemy2()
{

}


void Enemy2::update(float deltaTime)
{
	//Get the window size.
	auto  winSize = Director::getInstance()->getVisibleSize();

	if (MovingDown == true)
	{
		enemy2->setPositionY(enemy2->getPositionY() - (currentSpeed * deltaTime));
	}
	else
	{
		enemy2->setPositionY(enemy2->getPositionY() + (currentSpeed * deltaTime));
	}

	if (enemy2->getPositionY() > startYPosition + distance)
	{
		MovingDown = true;
	}

	if (enemy2->getPositionY() < startYPosition - distance)
	{
		MovingDown = false;
	}
}