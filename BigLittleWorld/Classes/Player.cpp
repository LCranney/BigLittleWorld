#include "Player.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;

Player* Player::create(float SXPos, float SYPos)
{
	Player* myNode = new Player();
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

bool Player::init(float SXPos, float SYPos)
{
	if (!Node::init())
	{
		return false;
	}

	//Load this object in from cocos studio.
	auto rootNode = CSLoader::createNode("Player.csb");
	addChild(rootNode);

	auto winSize = Director::getInstance()->getVisibleSize();
	this->scheduleUpdate();

	player = (Sprite*)rootNode->getChildByName("Player");

	startXPosition = SXPos;
	startYPosition = SYPos;

	player->setPosition(startXPosition, startYPosition);





	return true;
}

Player::Player()
{
}


Player::~Player()
{

}
