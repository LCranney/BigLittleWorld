#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
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

	auto helpItem = MenuItemImage::create("help Button.png", "Help Button Clicked.png", CC_CALLBACK_1(HelloWorld::GoToHelpScene, this));
	helpItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2.4 + origin.y));
	auto help = Menu::create(helpItem, NULL);
	help->setPosition(Point::ZERO);
	this->addChild(help);

	auto playItem = MenuItemImage::create("Play Button.png", "Play Button Clicked.png", CC_CALLBACK_1(HelloWorld::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	auto levelItem = MenuItemImage::create("Level Button.png", "Level Button Clicked.png", CC_CALLBACK_1(HelloWorld::GoToLevelScene, this));
	levelItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));
	auto levels = Menu::create(levelItem, NULL);
	levels->setPosition(Point::ZERO);
	this->addChild(levels);

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

