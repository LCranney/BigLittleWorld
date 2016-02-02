#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
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

	enemy1Node = (Enemy1*)rootNode->getChildByName("enemy1");
	enemy1 = Enemy1::create(450.0f, 300.0f, 100.0f);
	this->addChild(enemy1);

	enemy1aNode = (Enemy1*)rootNode->getChildByName("enemy1");
	enemy1a = Enemy1::create(450.0f, 100.0f, 150.0f);
	this->addChild(enemy1a);

	enemy2Node = (Enemy2*)rootNode->getChildByName("enemy2");
	enemy2 = Enemy2::create(150.0f, 0.0f, 600.0f);
	this->addChild(enemy2);

	enemy3Node = (Enemy3*)rootNode->getChildByName("enemy3");
	enemy3 = Enemy3::create();
	this->addChild(enemy3);

    return true;
}
