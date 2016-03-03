#include "Spikes.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Spikes* Spikes::create(float SXPos, float SYPos)
{
	Spikes* myNode = new Spikes();
	if (myNode->init(SXPos, SYPos))
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

bool Spikes::init(float SXPos, float SYPos)
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("res/Spike.csb");
	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, winSize.height*0.4));
	this->scheduleUpdate();

	spike = (Sprite*)rootNode->getChildByName("Spike");

	startXPosition = SXPos;
	startYPosition = SYPos;
	spike->setPosition(startXPosition, startYPosition);

	return true;
}

Spikes::Spikes()
{
}


Spikes::~Spikes()
{

}
