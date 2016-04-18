#include "HelpScene.h"
#include "HelpSceneSecondPage.h"
#include "HelpSceneThirdPage.h"
#include "HelloWorldScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelpSceneSecondPage::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = HelpSceneSecondPage::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelpSceneSecondPage::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Help Screen Second Page.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto lastHelpPage = MenuItemImage::create("Next Button 2.png", "Next Button 2.png", CC_CALLBACK_1(HelpSceneSecondPage::GoToHelpSceneThirdPage, this));
	lastHelpPage->setPosition(Point(visibleSize.width / 1.15 + origin.x, visibleSize.height / 2 + origin.y));
	auto helpThird = Menu::create(lastHelpPage, NULL);
	helpThird->setPosition(Point::ZERO);
	this->addChild(helpThird);

    return true;
}

void HelpSceneSecondPage::GoToHelpSceneThirdPage(cocos2d::Ref *sender)
{
	auto scene = HelpSceneThirdPage::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


