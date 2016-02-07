#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
    
	scene->getPhysicsWorld()->setGravity(Vec2(0.0f ,-150.0f));

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

	auto winSize = Director::getInstance()->getVisibleSize();

	this->scheduleUpdate();

    addChild(rootNode);


	Ball = (Sprite*)rootNode->getChildByName("Ball");

	Platform[0] = (Sprite*)rootNode->getChildByName("Platform1");
	Platform[1] = (Sprite*)rootNode->getChildByName("Platform2");
	Platform[2] = (Sprite*)rootNode->getChildByName("Platform3");
	Platform[3] = (Sprite*)rootNode->getChildByName("Platform4");
	Platform[4] = (Sprite*)rootNode->getChildByName("Platform5");

	for (int i = 0; i < 2; i++)
	{
		physicsbody[i] = PhysicsBody::createBox(Size(Platform[i]->getBoundingBox().size.width / 2, Platform[i]->getBoundingBox().size.height / 4), PhysicsMaterial(0.1f, 0.5f, 1.5f));
		physicsbody[i]->setDynamic(false);
		Platform[i]->setPhysicsBody(physicsbody[i]);
		Platform[i]->setRotation(90);
	}

	for (int i = 2; i < 5; i++)
	{
		physicsbody[i] = PhysicsBody::createBox(Size(Platform[i]->getBoundingBox().size.width / 2, Platform[i]->getBoundingBox().size.height / 4), PhysicsMaterial(0.1f, 0.5f, 1.5f));
		physicsbody[i]->setDynamic(false);
		Platform[i]->setPhysicsBody(physicsbody[i]);
	}

	Platform[0]->setPosition(Vec2(winSize.width - 50, winSize.height / 2));
	Platform[1]->setPosition(Vec2(50.0f, winSize.height / 2));

	Platform[2]->setPosition(Vec2(winSize.width / 2 + 120, 50.0f));
	Platform[3]->setPosition(Vec2(winSize.width / 2 - 100, winSize.height / 2));
	Platform[4]->setPosition(Vec2(winSize.width / 2 + 120, winSize.height - 135.0f));

	Ball->setPosition(Vec2(winSize.width / 2, 70));
	

	physicsbody[5] = PhysicsBody::createCircle(Ball->getBoundingBox().size.width / 2, PhysicsMaterial(0.1f, 1.0f, 0.8f));
	Ball->setPhysicsBody(physicsbody[5]);
	Ball->getPhysicsBody()->setVelocity(Vec2(350, 400));

	

	/*physicsbody = PhysicsBody::createBox(Size(Platform->getBoundingBox().size.width / 2, Platform->getBoundingBox().size.height / 4), PhysicsMaterial(0.1f, 0.5f, 0.5f));
	physicsbody->setDynamic(false);
	Platform->setPhysicsBody(physicsbody);
	Platform4->setPhysicsBody(physicsbody);

	physicsbody = PhysicsBody::createBox(Size(Platform3->getBoundingBox().size.width / 2, Platform3->getBoundingBox().size.height / 4), PhysicsMaterial(0.1f, 0.5f, 0.8f));
	physicsbody->setDynamic(false);
	Platform2->setPhysicsBody(physicsbody);
	Platform3->setPhysicsBody(physicsbody);
	Platform5->setPhysicsBody(physicsbody);*/

    return true;
}

void HelloWorld::update(float delta)
{
	/*if (this->BoxtoCircleCollision(Platform, Ball))
	{
		Ball->setVisible(false);
	}
	else
	{
		Ball->setVisible(true);
	}*/
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