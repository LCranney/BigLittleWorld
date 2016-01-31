#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

	this->scheduleUpdate();

    addChild(rootNode);

	Ball = (Sprite*)rootNode->getChildByName("Ball");
	Platform = (Sprite*)rootNode->getChildByName("Platform");
	Platform->setRotation(1);

	auto physicsbody = PhysicsBody::createCircle(Ball->getBoundingBox().size.width / 2, PhysicsMaterial(0.4f, 1.0f, 0.0f));
	Ball->setPhysicsBody(physicsbody);

	physicsbody = PhysicsBody::createBox(Size(Platform->getBoundingBox().size.width / 2, Platform->getBoundingBox().size.height / 4), PhysicsMaterial(0.1f, 0.5f, 0.0f));
	physicsbody->setDynamic(false);
	Platform->setPhysicsBody(physicsbody);

    return true;
}

void HelloWorld::update(float delta)
{
	if (this->BoxtoCircleCollision(Platform, Ball))
	{
		Ball->setVisible(false);
	}
	else
	{
		Ball->setVisible(true);
	}
}

bool HelloWorld::BoxtoBoxCollision(Sprite* sprite1, Sprite* sprite2)
{
	if (sprite1->getBoundingBox().intersectsRect(sprite2->getBoundingBox()))
	{
		return true;
	}
	return false;
}

bool HelloWorld::BoxtoCircleCollision(Sprite* Box, Sprite* Circle)
{
	if (Box->getBoundingBox().intersectsCircle(Circle->getPosition(), Circle->getBoundingBox().size.height / 2))
	{
		return true;
	}
	return false;
}

bool HelloWorld::CircletoCircleCollision(Sprite* sprite1, Sprite* sprite2)
{
	Vec2 v = sprite1->getPosition() - sprite2->getPosition();
	float vl = v.length();

	if (vl < ((sprite1->getBoundingBox().size.width / 2) + (sprite2->getBoundingBox().size.width / 2)))
	{
		return true;
	}
	return false;
}