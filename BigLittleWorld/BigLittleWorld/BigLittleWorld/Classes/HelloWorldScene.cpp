#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "GameScene.h"
#include "HelpScene.h"
#include "LevelScene.h"
#include "Definitions.h"
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
    
    /*auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
*/
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Background.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto playItem = MenuItemImage::create("Start Button.png", "Start Button Clicked.png", CC_CALLBACK_1(HelloWorld::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 2 + origin.y));
	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	auto helpItem = MenuItemImage::create("Help Button.png", "Help Button Pressed.png", CC_CALLBACK_1(HelloWorld::GoToHelpScene, this));
	helpItem->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 5 + origin.y));
	auto help = Menu::create(helpItem, NULL);
	help->setPosition(Point::ZERO);
	this->addChild(help);

	auto levelItem = MenuItemImage::create("Level Button.png", "Level Button Pressed.png", CC_CALLBACK_1(HelloWorld::GoToLevelScene, this));
	levelItem->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 2.85 + origin.y));
	auto level = Menu::create(levelItem, NULL);
	level->setPosition(Point::ZERO);
	this->addChild(level);


	return true;
}

void HelloWorld::GoToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void HelloWorld::GoToHelpScene(cocos2d::Ref *sender)
{
	auto scene = HelpScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void HelloWorld::GoToLevelScene(cocos2d::Ref *sender)
{
	auto scene = LevelScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

