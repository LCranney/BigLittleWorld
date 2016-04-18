#include "HelpScene.h"
#include "HelpSceneSecondPage.h"
#include "HelloWorldScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelpScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = HelpScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelpScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Help Screen.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto home2Item = MenuItemImage::create("Home Button.png", "Home Button Pressed.png", CC_CALLBACK_1(HelpScene::GoToMainMenuScene, this));
	home2Item->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 5 + origin.y));
	auto home2 = Menu::create(home2Item, NULL);
	home2->setPosition(Point::ZERO);
	this->addChild(home2);

	auto nextHelpPage = MenuItemImage::create("Next Button 1.png", "Next Button 1.png", CC_CALLBACK_1(HelpScene::GoToHelpSceneSecondPage, this));
	nextHelpPage->setPosition(Point(visibleSize.width / 1.15 + origin.x, visibleSize.height / 2 + origin.y));
	auto helpSecond = Menu::create(nextHelpPage, NULL);
	helpSecond->setPosition(Point::ZERO);
	this->addChild(helpSecond);

    return true;
}

void HelpScene::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void HelpScene::GoToHelpSceneSecondPage(cocos2d::Ref *sender)
{
	auto scene = HelpSceneSecondPage::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}



