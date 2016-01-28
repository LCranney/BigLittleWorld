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
	
	enemy3Node = (Enemy3*)rootNode->getChildByName("Barrel");
	enemy3 = Enemy3::create();
	this->addChild(enemy3);

	enemy1Node = (Enemy1*)rootNode->getChildByName("enemyTank");
	enemy1 = Enemy1::create();
	this->addChild(enemy1);


	enemy2Node = (Enemy2*)rootNode->getChildByName("Wall");
	enemy2 = Enemy2::create();
	this->addChild(enemy2);


	


    return true;
}
