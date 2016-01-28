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

    addChild(rootNode);

	Ball = (Sprite*)rootNode->getChildByName("Ball");
	Platform = (Sprite*)rootNode->getChildByName("Platform");

	auto physicsbody = PhysicsBody::createBox(Size(Ball->getBoundingBox().size.width, Ball->getBoundingBox().size.height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	Ball->setPhysicsBody(physicsbody);

	physicsbody = PhysicsBody::createBox(Size(Platform->getBoundingBox().size.width, Platform->getBoundingBox().size.height), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsbody->setDynamic(false);
	Platform->setPhysicsBody(physicsbody);
	

    return true;
}

bool HelloWorld::BoxtoBoxCollision(Sprite* sprite1, Sprite* sprite2)
{
	if (sprite1->getBoundingBox().intersectsRect(sprite2->getBoundingBox()))
	{
		return true;
	}
	return false;
}

bool HelloWorld::BoxtoCircleCollision(Sprite* sprite1, Sprite* sprite2)
{
	if (sprite1->getBoundingBox().intersectsCircle(sprite1->getPosition(), sprite1->getBoundingBox().size.height / 2))
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