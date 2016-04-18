#include "HelpScene.h"
#include "HelpSceneSecondPage.h"
#include "HelpSceneThirdPage.h"
#include "HelloWorldScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelpSceneThirdPage::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = HelpSceneThirdPage::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelpSceneThirdPage::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroundSprite = Sprite::create("Help Screen Third Page.png");
	backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundSprite);

	auto homeHelpScene = MenuItemImage::create("Home Button.png", "Home Button Pressed.png", CC_CALLBACK_1(HelpSceneThirdPage::GoToMainMenuScene, this));
	homeHelpScene->setPosition(Point(visibleSize.width / 2.05 + origin.x, visibleSize.height / 5 + origin.y));
	auto homeHelp = Menu::create(homeHelpScene, NULL);
	homeHelp->setPosition(Point::ZERO);
	this->addChild(homeHelp);

    return true;
}

void HelpSceneThirdPage::GoToMainMenuScene(cocos2d::Ref *sender)
{
	auto scene = HelloWorld::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


