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


	//						Sprite Animation BEGIN
	SpriteBatchNode* _spritebatch = SpriteBatchNode::create("Enemy2.png");

	SpriteFrameCache* _cache = SpriteFrameCache::getInstance();
	_cache->addSpriteFramesWithFile("Enemy2.plist");

	enemy2 = Sprite::createWithSpriteFrameName("Enemy002-1.png");
	_spritebatch->addChild(enemy2);
	addChild(_spritebatch);
	
	//Vector<SpriteFrame*> frames;
	const int kNumberOfFrames = 2;
	for (int i = 1; i <= kNumberOfFrames; i++)
	{
		stringstream ss;
		ss << "Enemy002-" << i << ".png";
		string string1 = ss.str();
		frames.pushBack(_cache->getSpriteFrameByName(string1));
	}

	Animation* animation = Animation::createWithSpriteFrames(frames, 1.0f);
	enemy2->runAction(RepeatForever::create(Animate::create(animation)));
	//						Sprite Animation END

	startXPosition = SXPos;
	startYPosition = SYPos;
	distance = Dis;
	enemy2->setPosition(startXPosition, startYPosition);
	enemy2->setScale(0.35f);

	MovingDown = false;

	currentSpeed = 214.8f;

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
		//enemy2->setSpriteFrame(frames.at(0));
	}
	else
	{
		enemy2->setPositionY(enemy2->getPositionY() + (currentSpeed * deltaTime));
		//enemy2->setSpriteFrame(frames.at(1));
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