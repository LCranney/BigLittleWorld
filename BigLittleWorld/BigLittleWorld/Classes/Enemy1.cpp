#include "Enemy1.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Enemy1* Enemy1::create(float SXPos, float SYPos, float Dis)
{
	Enemy1* myNode = new Enemy1();
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

bool Enemy1::init(float SXPos, float SYPos, float Dis)
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("res/Enemy1.csb");
	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height*0.4));
	this->scheduleUpdate();

	enemy1 = (Sprite*)rootNode->getChildByName("Enemy1");

	startXPosition = SXPos;
	startYPosition = SYPos;
	distance = Dis;
	enemy1->setPosition(startXPosition, startYPosition);

	MovingLeft = false;

	currentSpeed = 350.0f;
	movement = 1;

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
	if (enemy1->getPositionX() > startXPosition + distance)
	{
		MovingLeft = true;
	}
	if (enemy1->getPositionX() < startXPosition - distance)
	{
		MovingLeft = false;
	}
}