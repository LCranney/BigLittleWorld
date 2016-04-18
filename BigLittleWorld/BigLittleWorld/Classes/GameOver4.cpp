#include "GameOver4.h"
#include "HelloWorldScene.h"
#include "LevelScene.h"
#include "LevelFour.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameOver4::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOver4::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameOver4::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Level Failed.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	//auto retryItem = MenuItemImage::create("Retry Button.png", "Retry Button Pressed.png", CC_CALLBACK_1(GameOverScene::GoToGameScene, this));
	//retryItem->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 2.7));

	auto mainMenuItem = MenuItemImage::create("Retry Button.png", "Retry Button Pressed.png", CC_CALLBACK_1(GameOver4::GoToLevel4, this));
	mainMenuItem->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 2.7));


	auto home2Item = MenuItemImage::create("Home Button.png", "Home Button Pressed.png", CC_CALLBACK_1(GameOver4::GoToMainMenuScene, this));
	home2Item->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 4.3));

	auto menu = Menu::create(home2Item, mainMenuItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	return true;
}

void GameOver4::GoToLevelScene(cocos2d::Ref *sender)
{
	auto scene = LevelScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOver4::GoToLevel4(cocos2d::Ref *sender)
{
	auto scene = LevelFour::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void GameOver4::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


