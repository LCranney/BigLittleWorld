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
	
	/*enemyAnimation = new SpriteAnimator("Enemy1.plist", "Enemy1.png", "Enemy001-", 2);
	enemy1 = Sprite::createWithSpriteFrameName("Enemy001-1.png");
	enemyAnimation->GetSpriteBatchNode()->addChild(enemy1);
	addChild(enemyAnimation->GetSpriteBatchNode());
	enemyAnimation->Initialise();

	Animation* anim = Animation::createWithSpriteFrames(enemyAnimation->GetSpriteFrames(), 1.0f);
	enemy1->runAction(RepeatForever::create(Animate::create(anim)));*/


	//							Sprite Animation						//
	//SpriteBatchNode* _spritebatch = SpriteBatchNode::create("Enemy1.png");

	//SpriteFrameCache* _cache = SpriteFrameCache::getInstance();
	//_cache->addSpriteFramesWithFile("Enemy1.plist");

	//enemy1 = Sprite::createWithSpriteFrameName("Enemy001-1.png");
	//_spritebatch->addChild(enemy1);
	//addChild(_spritebatch);

	//const int kNumberOfFrames = 2;
	//for (int i = 1; i <= kNumberOfFrames; i++)
	//{
	//	stringstream ss;
	//	ss << "Enemy001-" << i << ".png";
	//	string string1 = ss.str();
	//	frames.pushBack(_cache->getSpriteFrameByName(string1));
	//}

	////animation = Animation::createWithSpriteFrames(frames, 1.0f);
	////enemy1->runAction(RepeatForever::create(Animate::create(animation)));
	//							Sprite Animation END					//

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