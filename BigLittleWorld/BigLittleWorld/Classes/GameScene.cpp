#include "GameScene.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "HelloWorldScene.h"
#include "LevelScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "LevelTwo.h"
#include <iostream>

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));
    // 'layer' is an autorelease object
	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto rootNode = CSLoader::createNode("Level1.csb");

	addChild(rootNode);
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto homeButtonGame = MenuItemImage::create("GameSceneHomeButton.png", "GameSceneHomeButton 1.png", CC_CALLBACK_1(GameScene::GoToMainMenuScene, this));
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

	Roof = (Sprite*)rootNode->getChildByName("Roof");

	{
		auto roofBody = PhysicsBody::createBox(Roof->getContentSize());
		roofBody->setDynamic(false);
		roofBody->setCollisionBitmask(5);
		roofBody->setContactTestBitmask(true);

		Roof->setPhysicsBody(roofBody);
	}

	rootNode->addChild(Roof);

	Spike1 = (Sprite*)rootNode->getChildByName("Spike1");

	{
		auto spikeBody1 = PhysicsBody::createBox(Spike1->getContentSize());
		spikeBody1->setDynamic(false);
		spikeBody1->setCollisionBitmask(6);
		spikeBody1->setContactTestBitmask(true);

		Spike1->setPhysicsBody(spikeBody1);
	}

	rootNode->addChild(Spike1);

	Spike2 = (Sprite*)rootNode->getChildByName("Spike2");

	{
		auto spikeBody2 = PhysicsBody::createBox(Spike2->getContentSize());
		spikeBody2->setDynamic(false);
		spikeBody2->setCollisionBitmask(7);
		spikeBody2->setContactTestBitmask(true);

		Spike2->setPhysicsBody(spikeBody2);
	}

	rootNode->addChild(Spike2);

	SpikeRoof1 = (Sprite*)rootNode->getChildByName("SpikeRoof");

	{
		auto spikeRoofBody1 = PhysicsBody::createBox(SpikeRoof1->getContentSize());
		spikeRoofBody1->setDynamic(false);
		spikeRoofBody1->setCollisionBitmask(8);
		spikeRoofBody1->setContactTestBitmask(true);

		SpikeRoof1->setPhysicsBody(spikeRoofBody1);
	}

	rootNode->addChild(SpikeRoof1);

	Finish = (Sprite*)rootNode->getChildByName("Finish");

	{
		auto finishBody = PhysicsBody::createBox(Finish->getContentSize());
		finishBody->setDynamic(false);
		finishBody->setCollisionBitmask(9);
		finishBody->setContactTestBitmask(true);

		Finish->setPhysicsBody(finishBody);
	}

	rootNode->addChild(Finish);

	Wall1 = (Sprite*)rootNode->getChildByName("Wall");

	{
		auto wallBody = PhysicsBody::createBox(Wall1->getContentSize());
		wallBody->setDynamic(false);
		wallBody->setCollisionBitmask(10);
		wallBody->setContactTestBitmask(true);

		Wall1->setPhysicsBody(wallBody);
	}

	rootNode->addChild(Wall1);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	contactListener->onContactPreSolve = CC_CALLBACK_2(GameScene::onContactPreSolve, this);
	contactListener->onContactPostSolve = CC_CALLBACK_2(GameScene::onContactPostSolve, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(GameScene::onContactSeperate, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(GameScene::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	opposite = true;
	slingshot = true;
	

	/*auto gameOver = MenuItemImage::create("help Button.png", "Help Button Clicked.png", CC_CALLBACK_1(GameScene::GoToGameOverScene, this));
	gameOver->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y));
	auto over = Menu::create(gameOver, NULL);
	over->setPosition(Point::ZERO);
	this->addChild(over);*/
	
    return true;
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	//On contact between player and any enemy, spike, or laser. Kill player. Check Lives. Run reset/Game Over.

	return true;
}

bool GameScene::onContactPreSolve(cocos2d::PhysicsContact &contact, cocos2d::PhysicsContactPreSolve& solve)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{
		solve.setRestitution(0);
	}

	return true;
}

void GameScene::onContactPostSolve(cocos2d::PhysicsContact &contact, const cocos2d::PhysicsContactPostSolve& solve)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() && 9 == b->getCollisionBitmask())
	{
		this->removeAllChildren();
		GameScene::GoToLevel2();
		slingshot = true;
	}
	else if (9 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
	{
		this->removeAllChildren();
		GameScene::GoToLevel2();
		slingshot = true;
	}
	else
	{
		if (1 == a->getCollisionBitmask() && 6 == b->getCollisionBitmask())
		{
			GameScene::GoToGameOverScene();
			slingshot = false;
		}
		else if (6 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			GameScene::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 7 == b->getCollisionBitmask())
		{
			GameScene::GoToGameOverScene();
			slingshot = false;
		}
		else if (7 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			GameScene::GoToGameOverScene();
			slingshot = false;
		}
		if (1 == a->getCollisionBitmask() && 8 == b->getCollisionBitmask())
		{
			GameScene::GoToGameOverScene();
			slingshot = false;
		}
		else if (8 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			GameScene::GoToGameOverScene();
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
		if (1 == a->getCollisionBitmask() && 10 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
		else if (10 == a->getCollisionBitmask() && 1 == b->getCollisionBitmask())
		{
			player->getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
			slingshot = true;
		}
	}
}

void GameScene::onContactSeperate(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{
		
	}
}

bool GameScene::onTouchBegan(Touch* touch, Event* event)
{
	startPosition = touch->getLocation();

	return true;
}

void GameScene::onTouchEnded(Touch* touch, Event* event)
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

void GameScene::onTouchMoved(Touch* touch, Event* event)
{
}

void GameScene::onTouchCancelled(Touch* touch, Event* event)
{
}

void GameScene::GoToGameOverScene()
{
	auto scene = GameOverScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GameScene::GoToLevelScene()
{
	auto scene = LevelScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GameScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GameScene::GoToLevel2()
{
	auto scene = LevelTwo::createScene();
	
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}