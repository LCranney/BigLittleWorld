#pragma warning(disable : C4996)

#include "GameScene.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Player.h"
USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
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
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_level_1 = new CCTMXTiledMap();
	_level_1->initWithTMXFile("Level_01.tmx");
	
	_BlackLayer = _level_1->layerNamed("Tile Layer 1");
	_WhiteLayer = _level_1->layerNamed("Tile Layer 2");
	_SpikeLayer = _level_1->layerNamed("Tile Layer 3");
	_FinishLayer = _level_1->layerNamed("Tile Layer 4");

	this->addChild(_level_1);

	auto rootNode = Sprite::create();
	rootNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
	enemy1 = Enemy1::create(450.0f, 100.0f, 100.0f);
	enemy1a = Enemy1::create(600.0f, 50.0f, 150.0f);
	enemy2 = Enemy2::create(750.0f, 30.0f, 100.0f);

	this->addChild(rootNode);


	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);

	player = Player::create(500.0f, 200.0f);

	{
		auto playerBody = PhysicsBody::createBox(Size(10.0f, 10.0f), PhysicsMaterial(0.0f, 0.0f, 0.0f));
		playerBody->setRotationEnable(false);
		playerBody->setCollisionBitmask(1);
		playerBody->setContactTestBitmask(true);
		player->setPhysicsBody(playerBody);
	}

	this->addChild(player);

	{

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
	this->addChild(enemy1);

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

	//Collision between player and ground
}

void GameScene::onContactSeperate(cocos2d::PhysicsContact &contact)
{
	PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (1 == a->getCollisionBitmask() || 1 == b->getCollisionBitmask())
	{
		//Set player grounded false.
	}
}

bool GameScene::onTouchBegan(Touch* touch, Event* event)
{
	startPosition = touch->getLocation();

	return true;
}

void GameScene::onTouchEnded(Touch* touch, Event* event)
{
	Vec2 endPosition = touch->getLocation();
	Vec2 slingshot = startPosition - endPosition;
	player->getPhysicsBody()->setVelocity(slingshot * 2);
}

void GameScene::onTouchMoved(Touch* touch, Event* event)
{
}

void GameScene::onTouchCancelled(Touch* touch, Event* event)
{
}

void GameScene::GoToGameOverScene(cocos2d::Ref *sender)
{
	auto scene = GameOverScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

CCPoint GameScene::tileCoordForPosition(CCPoint position)
{
	int x = position.x / _level_1->getTileSize().width;
	int y = ((_level_1->getMapSize().height * _level_1->getTileSize().height) - position.y) / _level_1->getTileSize().height;
	return ccp(x, y);
}

void GameScene::setPlayerPosition(CCPoint position)
{
	CCPoint tileCoord = this->tileCoordForPosition(position);
	int tileGidWhite = _WhiteLayer->tileGIDAt(tileCoord);
	if (tileGidWhite) 
	{
		ValueMap* properties = _level_1->propertiesForGID(tileGidWhite).asValueMap;
		if (properties) 
		{
			CCString *collision = new CCString();
			*collision = properties->at("Collidable").asString();
			if (collision && (collision->compare("True") == 0)) 
			{
				return;
			}
		}
	}
	int tileGidSpike = _SpikeLayer->tileGIDAt(tileCoord);
	if (tileGidSpike)
	{
		ValueMap* properties = _level_1->propertiesForGID(tileGidSpike).asValueMap;
		if (properties)
		{
			CCString *collision = new CCString();
			*collision = properties->at("Collidable").asString();
			if (collision && (collision->compare("True") == 0))
			{
				GoToGameOverScene(this);
			}
		}
	}
	int tileGidFinish = _FinishLayer->tileGIDAt(tileCoord);
	if (tileGidFinish)
	{
		ValueMap* properties = _level_1->propertiesForGID(tileGidFinish).asValueMap;
		if (properties)
		{
			CCString *collision = new CCString();
			*collision = properties->at("Collidable").asString();
			if (collision && (collision->compare("True") == 0))
			{
				GoToGameOverScene(this);
			}
		}
	}
	player->setPosition(position);
}