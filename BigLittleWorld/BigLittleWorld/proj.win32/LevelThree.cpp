#include "LevelThree.h"
#include "Definitions.h"
#include "GameOver3.h"
#include "HelloWorldScene.h"
#include "LevelScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "LevelFour.h"
#include <iostream>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;

Scene* LevelThree::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
	// 'layer' is an autorelease object
	auto layer = LevelThree::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelThree::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("Level3.csb");

	addChild(rootNode);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto homeButtonGame = MenuItemImage::create("GameSceneHomeButton.png", "GameSceneHomeButton 1.png", CC_CALLBACK_1(LevelThree::GoToMainMenuScene, this));
	homeButtonGame->setPosition(Point(visibleSize.width / 1.1 + origin.x, visibleSize.height / 2 + origin.y));
	auto homeButton = Menu::create(homeButtonGame, NULL);
	homeButton->setPosition(Point::ZERO);
	this->addChild(homeButton);

	//enemy1 = Enemy1::create(450.0f, 100.0f, 100.0f);
	//enemy1a = Enemy1::create(600.0f, 50.0f, 150.0f);
	//enemy2 = Enemy2::create(750.0f, 30.0f, 100.0f);

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);


	player = (Sprite*)rootNode->getChildByName("Player");

	{
		auto playerBody = PhysicsBody::createCircle(24, PhysicsMaterial(0.0f, 0.0f, 0.0f), Vec2(0.0f, 0.0f));
		playerBody->setRotationEnable(false);
		playerBody->setCollisionBitmask(1);
		playerBody->setContactTestBitmask(true);

		player->setPhysicsBody(playerBody);
	}

	rootNode->addChild(player);

	/*{

	auto enemyBody = PhysicsBody::createBox(enemy1->getContentSize());
	enemyBody->setDynamic(false);
	enemyBody->setCollisionBitmask(2);
	enemyBody->setContactTestBitmask(true);

	enemy1->setPhysicsBody(enemyBody);
	enemy1a->setPhysicsBody(enemyBody);
	enemy2->setPhysicsBody(enemyBody);

	}

	this->addChild(enemy2);
	this->addChild(enemy1a);
	this->addChild(enemy1);*/



	Floor1 = (Sprite*)rootNode->getChildByName("Floor1");

	{
		auto floorBody1 = PhysicsBody::createBox(Floor1->getContentSize());
		floorBody1->setDynamic(false);
		floorBody1->setCollisionBitmask(2);
		floorBody1->setContactTestBitmask(true);

		Floor1->setPhysicsBody(floorBody1);
	}

	rootNode->addChild(Floor1);

	Floor2 = (Sprite*)rootNode->getChildByName("Floor2");

	{
		auto floorBody2 = PhysicsBody::createBox(Floor2->getContentSize());
		floorBody2->setDynamic(false);
		floorBody2->setCollisionBitmask(3);
		floorBody2->setContactTestBitmask(true);

		Floor2->setPhysicsBody(floorBody2);
	}

	rootNode->addChild(Floor2);

	Floor3 = (Sprite*)rootNode->getChildByName("Floor3");

	{
		auto floorBody3 = PhysicsBody::createBox(Floor3->getContentSize());
		floorBody3->setDynamic(false);
		floorBody3->setCollisionBitmask(4);
		floorBody3->setContactTestBitmask(true);

		Floor3->setPhysicsBody(floorBody3);
	}

	rootNode->addChild(Floor3);

	Wall1 = (Sprite*)rootNode->getChildByName("Wall1");

	{
		auto wallBody1 = PhysicsBody::createBox(Wall1->getContentSize());
		wallBody1->setDynamic(false);
		wallBody1->setCollisionBitmask(6);
		wallBody1->setContactTestBitmask(true);

		Wall1->setPhysicsBody(wallBody1);
	}

	rootNode->addChild(Wall1);

	Wall2 = (Sprite*)rootNode->getChildByName("Wall2");

	{
		auto wallBody2 = PhysicsBody::createBox(Wall2->getContentSize());
		wallBody2->setDynamic(false);
		wallBody2->setCollisionBitmask(7);
		wallBody2->setContactTestBitmask(true);

		Wall2->setPhysicsBody(wallBody2);
	}

	rootNode->addChild(Wall2);

	Roof1 = (Sprite*)rootNode->getChildByName("Roof");

	{
		auto roofBody = PhysicsBody::createBox(Roof1->getContentSize());
		roofBody->setDynamic(false);
		roofBody->setCollisionBitmask(8);
		roofBody->setContactTestBitmask(true);

		Roof1->setPhysicsBody(roofBody);
	}

	rootNode->addChild(Roof1);

	Spike1 = (Sprite*)rootNode->getChildByName("Spike1");

	{
		auto spikeBody1 = PhysicsBody::createBox(Spike1->getContentSize());
		spikeBody1->setDynamic(false);
		spikeBody1->setCollisionBitmask(9);
		spikeBody1->setContactTestBitmask(true);

		Spike1->setPhysicsBody(spikeBody1);
	}

	rootNode->addChild(Spike1);

	Spike2 = (Sprite*)rootNode->getChildByName("Spike2");

	{
		auto spikeBody2 = PhysicsBody::createBox(Spike2->getContentSize());
		spikeBody2->setDynamic(false);
		spikeBody2->setCollisionBitmask(10);
		spikeBody2->setContactTestBitmask(true);

		Spike2->setPhysicsBody(spikeBody2);
	}

	rootNode->addChild(Spike2);

	Spike3 = (Sprite*)rootNode->getChildByName("Spike3");

	{
		auto spikeBody3 = PhysicsBody::createBox(Spike3->getContentSize());
		spikeBody3->setDynamic(false);
		spikeBody3->setCollisionBitmask(11);
		spikeBody3->setContactTestBitmask(true);

		Spike3->setPhysicsBody(spikeBody3);
	}

	rootNode->addChild(Spike3);

	Spike4 = (Sprite*)rootNode->getChildByName("Spike4");

	{
		auto spikeBody4 = PhysicsBody::createBox(Spike4->getContentSize());
		spikeBody4->setDynamic(false);
		spikeBody4->setCollisionBitmask(12);
		spikeBody4->setContactTestBitmask(true);

		Spike4->setPhysicsBody(spikeBody4);
	}

	rootNode->addChild(Spike4);

	Spike5 = (Sprite*)rootNode->getChildByName("Spike5");

	{
		auto spikeBody5 = PhysicsBody::createBox(Spike5->getContentSize());
		spikeBody5->setDynamic(false);
		spikeBody5->setCollisionBitmask(13);
		spikeBody5->setContactTestBitmask(true);

		Spike5->setPhysicsBody(spikeBody5);
	}

	rootNode->addChild(Spike5);

	Spike6 = (Sprite*)rootNode->getChildByName("Spike6");

	{
		auto spikeBody6 = PhysicsBody::createBox(Spike6->getContentSize());
		spikeBody6->setDynamic(false);
		spikeBody6->setCollisionBitmask(14);
		spikeBody6->setContactTestBitmask(true);

		Spike6->setPhysicsBody(spikeBody6);
	}

	rootNode->addChild(Spike6);

	Spike7 = (Sprite*)rootNode->getChildByName("Spike7");

	{
		auto spikeBody7 = PhysicsBody::createBox(Spike7->getContentSize());
		spikeBody7->setDynamic(false);
		spikeBody7->setCollisionBitmask(15);
		spikeBody7->setContactTestBitmask(true);

		Spike7->setPhysicsBody(spikeBody7);
	}

	rootNode->addChild(Spike7);

	Spike8 = (Sprite*)rootNode->getChildByName("Spike8");

	{
		auto spikeBody8 = PhysicsBody::createBox(Spike8->getContentSize());
		spikeBody8->setDynamic(false);
		spikeBody8->setCollisionBitmask(16);
		spikeBody8->setContactTestBitmask(true);

		Spike8->setPhysicsBody(spikeBody8);
	}

	rootNode->addChild(Spike8);

	Spike9 = (Sprite*)rootNode->getChildByName("Spike9");

	{
		auto spikeBody9 = PhysicsBody::createBox(Spike9->getContentSize());
		spikeBody9->setDynamic(false);
		spikeBody9->setCollisionBitmask(17);
		spikeBody9->setContactTestBitmask(true);

		Spike9->setPhysicsBody(spikeBody9);
	}

	rootNode->addChild(Spike9);

	Spike10 = (Sprite*)rootNode->getChildByName("Spike10");

	{
		auto spikeBody10 = PhysicsBody::createBox(Spike10->getContentSize());
		spikeBody10->setDynamic(false);
		spikeBody10->setCollisionBitmask(18);
		spikeBody10->setContactTestBitmask(true);

		Spike10->setPhysicsBody(spikeBody10);
	}

	rootNode->addChild(Spike10);

	Finish = (Sprite*)rootNode->getChildByName("Finish");

	{
		auto finishBody = PhysicsBody::createBox(Finish->getContentSize());
		finishBody->setDynamic(false);
		finishBody->setCollisionBitmask(21);
		finishBody->setContactTestBitmask(true);

		Finish->setPhysicsBody(finishBody);
	}

	rootNode->addChild(Finish);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(LevelThree::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(LevelThree::onContactPreSolve, this);
	contactListener->onContactPostSolve = CC_CALLBACK_2(LevelThree::onContactPostSolve, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(LevelThree::onContactSeperate, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(LevelThree::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LevelThree::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LevelThree::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(LevelThree::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	opposite = false;
	slingshot = true;

	/*auto gameOver = MenuItemImage::create("help Button.png", "Help Button Clicked.png", CC_CALLBACK_1(LevelThree::GoToGameOverScene, this));
	gameOver->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y));
	auto over = Menu::create(gameOver, NULL);
	over->setPosition(Point::ZERO);
	this->addChild(over);*/

	return true;
}

bool LevelThree::onContactBegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//On contact between player and any enemy, spike, or laser. Kill player. Check Lives. Run reset/Game Over.

	return true;
}

bool LevelThree::onContactPreSolve(cocos2d::PhysicsContact &contact, cocos2d::PhysicsContactPreSolve& solve)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{
		solve.setRestitution(0);
	}

	return true;
}

void LevelThree::onContactPostSolve(cocos2d::PhysicsContact &contact, const cocos2d::PhysicsContactPostSolve& solve)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() && 21 == b->getCollisionBitmask())
	{
		this->removeAllChildren();
		LevelThree::GoToLevel4();
		slingshot = true;
	}
	else if (21 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
	{
		this->removeAllChildren();
		LevelThree::GoToLevel4();
		slingshot = true;
	}
	else
	{
		if (1 == a->getCollisionBitmask() && 9 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (9 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 10 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (10 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 11 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (11 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 12 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (12 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 13 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (13 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 14 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (14 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 15 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (15 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 16 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (16 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 17 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (17 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 18 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		else if (18 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelThree::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 2 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (2 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		if (1 == a->getCollisionBitmask() && 3 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (3 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		if (1 == a->getCollisionBitmask() && 4 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (4 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		if (1 == a->getCollisionBitmask() && 6 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (6 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		if (1 == a->getCollisionBitmask() && 7 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (7 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		if (1 == a->getCollisionBitmask() && 8 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (8 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
	}
}

void LevelThree::onContactSeperate(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{

	}
}

bool LevelThree::onTouchBegan(Touch* touch, Event* event)
{
	startPosition = touch->getLocation();

	return true;
}

void LevelThree::onTouchEnded(Touch* touch, Event* event)
{
	if (slingshot == true)
	{
		if (opposite == false)
		{
			Vec2 endPosition = touch->getLocation();
			Vec2 slingshot = startPosition - endPosition;
			player->getPhysicsBody()->setVelocity(slingshot * 2);
		}
		else if (opposite == true);
		{
			Vec2 endPosition = touch->getLocation();
			Vec2 slingshot = startPosition - endPosition;
			player->getPhysicsBody()->setVelocity(slingshot * -2);
		}
	}
	else  if (slingshot == false)
	{

	}
}

void LevelThree::onTouchMoved(Touch* touch, Event* event)
{
}

void LevelThree::onTouchCancelled(Touch* touch, Event* event)
{
}

void LevelThree::GoToGameOverScene()
{
	auto scene = GameOver3::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelThree::GoToLevelScene()
{
	auto scene = LevelScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelThree::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelThree::GoToLevel4()
{
	auto scene = LevelFour::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

