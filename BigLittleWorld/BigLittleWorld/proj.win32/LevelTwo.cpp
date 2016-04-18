#include "LevelTwo.h"
#include "Definitions.h"
#include "GameOver2.h"
#include "HelloWorldScene.h"
#include "LevelScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "LevelThree.h"
#include <iostream>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;

Scene* LevelTwo::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
	// 'layer' is an autorelease object
	auto layer = LevelTwo::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelTwo::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("Level2.csb");

	addChild(rootNode);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto homeButtonGame = MenuItemImage::create("GameSceneHomeButton.png", "GameSceneHomeButton 1.png", CC_CALLBACK_1(LevelTwo::GoToMainMenuScene, this));
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

	Floor4 = (Sprite*)rootNode->getChildByName("Floor4");

	{
		auto floorBody4 = PhysicsBody::createBox(Floor4->getContentSize());
		floorBody4->setDynamic(false);
		floorBody4->setCollisionBitmask(5);
		floorBody4->setContactTestBitmask(true);

		Floor4->setPhysicsBody(floorBody4);
	}

	rootNode->addChild(Floor4);

	Roof1 = (Sprite*)rootNode->getChildByName("Roof1");

	{
		auto roofBody1 = PhysicsBody::createBox(Roof1->getContentSize());
		roofBody1->setDynamic(false);
		roofBody1->setCollisionBitmask(6);
		roofBody1->setContactTestBitmask(true);

		Roof1->setPhysicsBody(roofBody1);
	}

	rootNode->addChild(Roof1);

	Roof2 = (Sprite*)rootNode->getChildByName("Roof2");

	{
		auto roofBody2 = PhysicsBody::createBox(Roof2->getContentSize());
		roofBody2->setDynamic(false);
		roofBody2->setCollisionBitmask(7);
		roofBody2->setContactTestBitmask(true);

		Roof2->setPhysicsBody(roofBody2);
	}

	rootNode->addChild(Roof2);

	Roof3 = (Sprite*)rootNode->getChildByName("Roof3");

	{
		auto roofBody3 = PhysicsBody::createBox(Roof3->getContentSize());
		roofBody3->setDynamic(false);
		roofBody3->setCollisionBitmask(8);
		roofBody3->setContactTestBitmask(true);

		Roof3->setPhysicsBody(roofBody3);
	}

	rootNode->addChild(Roof3);

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

	SpikeRoof1 = (Sprite*)rootNode->getChildByName("SpikeRoof1");

	{
		auto spikeRoofBody1 = PhysicsBody::createBox(SpikeRoof1->getContentSize());
		spikeRoofBody1->setDynamic(false);
		spikeRoofBody1->setCollisionBitmask(12);
		spikeRoofBody1->setContactTestBitmask(true);

		SpikeRoof1->setPhysicsBody(spikeRoofBody1);
	}

	rootNode->addChild(SpikeRoof1);

	SpikeRoof2 = (Sprite*)rootNode->getChildByName("SpikeRoof2");

	{
		auto spikeRoofBody2 = PhysicsBody::createBox(SpikeRoof2->getContentSize());
		spikeRoofBody2->setDynamic(false);
		spikeRoofBody2->setCollisionBitmask(13);
		spikeRoofBody2->setContactTestBitmask(true);

		SpikeRoof2->setPhysicsBody(spikeRoofBody2);
	}

	rootNode->addChild(SpikeRoof2);

	SpikeRoof3 = (Sprite*)rootNode->getChildByName("SpikeRoof3");

	{
		auto spikeRoofBody3 = PhysicsBody::createBox(SpikeRoof3->getContentSize());
		spikeRoofBody3->setDynamic(false);
		spikeRoofBody3->setCollisionBitmask(14);
		spikeRoofBody3->setContactTestBitmask(true);

		SpikeRoof3->setPhysicsBody(spikeRoofBody3);
	}

	rootNode->addChild(SpikeRoof3);

	SpikeRoof4 = (Sprite*)rootNode->getChildByName("SpikeRoof4");

	{
		auto spikeRoofBody4 = PhysicsBody::createBox(SpikeRoof4->getContentSize());
		spikeRoofBody4->setDynamic(false);
		spikeRoofBody4->setCollisionBitmask(15);
		spikeRoofBody4->setContactTestBitmask(true);

		SpikeRoof4->setPhysicsBody(spikeRoofBody4);
	}

	rootNode->addChild(SpikeRoof4);

	Finish = (Sprite*)rootNode->getChildByName("Finish");

	{
		auto finishBody = PhysicsBody::createBox(Finish->getContentSize());
		finishBody->setDynamic(false);
		finishBody->setCollisionBitmask(16);
		finishBody->setContactTestBitmask(true);

		Finish->setPhysicsBody(finishBody);
	}

	rootNode->addChild(Finish);

	Wall1 = (Sprite*)rootNode->getChildByName("Wall");
	{
		auto wallBody = PhysicsBody::createBox(Wall1->getContentSize());
		wallBody->setDynamic(false);
		wallBody->setCollisionBitmask(17);
		wallBody->setContactTestBitmask(true);

		Wall1->setPhysicsBody(wallBody);
	}

	rootNode->addChild(Wall1);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(LevelTwo::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(LevelTwo::onContactPreSolve, this);
	contactListener->onContactPostSolve = CC_CALLBACK_2(LevelTwo::onContactPostSolve, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(LevelTwo::onContactSeperate, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(LevelTwo::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(LevelTwo::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(LevelTwo::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(LevelTwo::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	opposite = false;
	slingshot = true;

	/*auto gameOver = MenuItemImage::create("help Button.png", "Help Button Clicked.png", CC_CALLBACK_1(LevelTwo::GoToGameOverScene, this));
	gameOver->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y));
	auto over = Menu::create(gameOver, NULL);
	over->setPosition(Point::ZERO);
	this->addChild(over);*/

	return true;
}

bool LevelTwo::onContactBegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//On contact between player and any enemy, spike, or laser. Kill player. Check Lives. Run reset/Game Over.

	return true;
}

bool LevelTwo::onContactPreSolve(cocos2d::PhysicsContact &contact, cocos2d::PhysicsContactPreSolve& solve)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{
		solve.setRestitution(0);
	}

	return true;
}

void LevelTwo::onContactPostSolve(cocos2d::PhysicsContact &contact, const cocos2d::PhysicsContactPostSolve& solve)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() && 16 == b->getCollisionBitmask())
	{
		this->removeAllChildren();
		LevelTwo::GoToLevel3();
		slingshot = true;
	}
	else if (16 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
	{
		this->removeAllChildren();
		LevelTwo::GoToLevel3();
		slingshot = true;
	}
	else
	{
		if (1 == a->getCollisionBitmask() && 9 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (9 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 10 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (10 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 11 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (11 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 12 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (12 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 13 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (13 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 14 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (14 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 15 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
			slingshot = false;
		}
		else if (15 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			LevelTwo::GoToGameOverScene();
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
		if (1 == a->getCollisionBitmask() && 5 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (5 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
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
		if (1 == a->getCollisionBitmask() && 17 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (17 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
	}
}

void LevelTwo::onContactSeperate(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{

	}
}

bool LevelTwo::onTouchBegan(Touch* touch, Event* event)
{
	startPosition = touch->getLocation();

	return true;
}

void LevelTwo::onTouchEnded(Touch* touch, Event* event)
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

void LevelTwo::onTouchMoved(Touch* touch, Event* event)
{
}

void LevelTwo::onTouchCancelled(Touch* touch, Event* event)
{
}

void LevelTwo::GoToGameOverScene()
{
	auto scene = GameOver2::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelTwo::GoToLevelScene()
{
	auto scene = LevelScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelTwo::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelTwo::GoToLevel3()
{
	auto scene = LevelThree::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}