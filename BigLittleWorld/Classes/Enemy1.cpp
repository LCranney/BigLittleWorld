#include "Enemy1.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Enemy1* Enemy1::create()
{
	Enemy1* myNode = new Enemy1();
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

bool Enemy1::init()
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
	startYPosition = enemy1->getPositionY();
	enemy1->setPosition(startXPosition, startYPosition);

	MovingLeft = false;

	currentSpeed = 514.8f;

	return true;
}

Enemy1::Enemy1()
{
}


Enemy1::~Enemy1()
{

}


void Enemy1::update(float deltaTime)
{
	//Get the window size.
	auto  winSize = Director::getInstance()->getVisibleSize();

	if (MovingLeft == true)
	{
		enemy1->setPositionX(enemy1->getPositionX() - (currentSpeed * deltaTime));
	}
	else
	{
		enemy1->setPositionX(enemy1->getPositionX() + (currentSpeed * deltaTime));
	}

	if (enemy1->getPositionX() > startXPosition + 400.0f)
	{
		MovingLeft = true;
	}

	if (enemy1->getPositionX() < startXPosition - 400.0f)
	{
		MovingLeft = false;
	}
}