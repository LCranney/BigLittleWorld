#include "GameOverScene.h"
#include "GameScene.h"
#include "HelloWorldScene.h"
#include "HelpScene.h"
#include "LevelScene.h"
#include "Definitions.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* LevelScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = LevelScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LevelScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("LevelScene.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgroundSprite);

	auto backLevelItem = MenuItemImage::create("Back Button1.png", "Back Button Clicked2.png", CC_CALLBACK_1(LevelScene::GoToMainMenuScene, this));
	backLevelItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 3 + origin.y));
	auto level = Menu::create(backLevelItem, NULL);
	level->setPosition(Point::ZERO);

	this->addChild(level);

    return true;
}

void LevelScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}



