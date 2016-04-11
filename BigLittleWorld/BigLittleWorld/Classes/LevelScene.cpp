#include "LevelScene.h"
#include "GameScene.h"
#include "HelloWorldScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "LevelFour.h"

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

	auto backgroundSprite = Sprite::create("Level Screen.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto home1Item = MenuItemImage::create("Home Button.png", "Home Button Pressed.png", CC_CALLBACK_1(LevelScene::GoToMainMenuScene, this));
	home1Item->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 5 + origin.y));
	auto home = Menu::create(home1Item, NULL);
	home->setPosition(Point::ZERO);
	this->addChild(home);

	auto Level1ButtonItem = MenuItemImage::create("Level 1 Button.png", "Level 1 Button Pressed.png", CC_CALLBACK_1(LevelScene::GoToGameScene, this));
	Level1ButtonItem->setPosition(Point(visibleSize.width / 6 + origin.x, visibleSize.height / 2 + origin.y));
	auto Level1Button = Menu::create(Level1ButtonItem, NULL);
	Level1Button->setPosition(Point::ZERO);
	this->addChild(Level1Button);

	auto Level2ButtonItem = MenuItemImage::create("Level 2 Button.png", "Level 2 Button Pressed.png", CC_CALLBACK_1(LevelScene::GoToLevel2, this));
	Level2ButtonItem->setPosition(Point(visibleSize.width / 2.6 + origin.x, visibleSize.height / 2 + origin.y));
	auto Level2Button = Menu::create(Level2ButtonItem, NULL);
	Level2Button->setPosition(Point::ZERO);
	this->addChild(Level2Button);

	auto Level3ButtonItem = MenuItemImage::create("Level 3 Button.png", "Level 3 Button Pressed.png", CC_CALLBACK_1(LevelScene::GoToLevel3, this));
	Level3ButtonItem->setPosition(Point(visibleSize.width / 1.65 + origin.x, visibleSize.height / 2 + origin.y));
	auto Level3Button = Menu::create(Level3ButtonItem, NULL);
	Level3Button->setPosition(Point::ZERO);
	this->addChild(Level3Button);

	auto Level4ButtonItem = MenuItemImage::create("Level 4 Button.png", "Level 4 Button Pressed.png", CC_CALLBACK_1(LevelScene::GoToLevel4, this));
	Level4ButtonItem->setPosition(Point(visibleSize.width / 1.2 + origin.x, visibleSize.height / 2 + origin.y));
	auto Level4Button = Menu::create(Level4ButtonItem, NULL);
	Level4Button->setPosition(Point::ZERO);
	this->addChild(Level4Button);

    return true;
}

void LevelScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelScene::GoToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelScene::GoToLevel2(cocos2d::Ref *sender)
{
	auto scene = LevelTwo::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelScene::GoToLevel3(cocos2d::Ref *sender)
{
	auto scene = LevelThree::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelScene::GoToLevel4(cocos2d::Ref *sender)
{
	auto scene = LevelFour::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

