#include "GameScene.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Spikes.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("GameScene.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
	enemy1 = Enemy1::create(450.0f, 100.0f, 100.0f);
	enemy1a = Enemy1::create(600.0f, 50.0f, 150.0f);
	enemy1b = Enemy1::create(600.0f, 65.0f, 125.0f);
	enemy1c = Enemy1::create(600.0f, 80.0f, 100.0f);
	enemy1d = Enemy1::create(600.0f, 95.0f, 75.0f);
	enemy1e = Enemy1::create(600.0f, 105.0f, 50.0f);
	enemy1f = Enemy1::create(600.0f, 120.0f, 25.0f);
	enemy2 = Enemy2::create(750.0f, 30.0f, 100.0f);
	spike = Spikes::create(500.0f, 100.0f);
	spike2 = Spikes::create(500.0f, 100.0f);
	spike3 = Spikes::create(510.0f, 100.0f);
	spike4 = Spikes::create(520.0f, 100.0f);
	spike5 = Spikes::create(530.0f, 100.0f);
	spike6 = Spikes::create(540.0f, 100.0f);
	spike7 = Spikes::create(550.0f, 100.0f);
	spike8 = Spikes::create(560.0f, 100.0f);

	this->addChild(backgroundSprite);

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(OBSTACLE_COLLISION_BITMASK);
	edgeBody->setContactTestBitmask(true);

	auto edgeNode = Node::create();
	edgeBody->setPositionOffset(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);
	this->addChild(enemy2);	
	this->addChild(enemy1a);
	this->addChild(enemy1b);
	this->addChild(enemy1c);
	this->addChild(enemy1d);
	this->addChild(enemy1e);
	this->addChild(enemy1f);
	this->addChild(enemy1);
	this->addChild(spike);
	this->addChild(spike2);
	this->addChild(spike3);
	this->addChild(spike4);
	this->addChild(spike5);
	this->addChild(spike6);
	this->addChild(spike7);
	this->addChild(spike8);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	
    return true;
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();

	return true;
}