#include "GameOverScene.h"
#include "HelloWorldScene.h"
#include "LevelComplete.h"
#include "GameScene.h"
#include "LevelScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* LevelComplete::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelComplete::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool LevelComplete::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Level Complete.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto LevelHomeItem = MenuItemImage::create("Level Button.png", "Level Button Pressed.png", CC_CALLBACK_1(LevelComplete::GoToLevelScene, this));
	LevelHomeItem->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 4.3 + origin.y));
	auto levelHome = Menu::create(LevelHomeItem, NULL);
	levelHome->setPosition(Point::ZERO);
	this->addChild(levelHome);

	return true;
}

void LevelComplete::GoToLevelScene(cocos2d::Ref *sender)
{
	auto scene = LevelScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


