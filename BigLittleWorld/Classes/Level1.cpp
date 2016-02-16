#include "Level1.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Level1::Level1(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	//platform1 = Sprite::create("Platformblack.png"); platform1->setPosition(Point(visibleSize.width / 1 + origin.x, visibleSize.height / 1 + origin.y));
	platform2 = Sprite::create("Platform.png"); platform2->setPosition(700, 50);
	platform3 = Sprite::create("Platform.png"); platform3->setPosition(600, 450);
	platform4 = Sprite::create("Platform.png"); platform4->setPosition(200, 50);
	platform5 = Sprite::create("Platform.png"); platform5->setPosition(300, 275);
}

Level1::~Level1()
{
}

void Level1::AddLevel(cocos2d::Layer *layer)
{
	//layer->addChild(platform1, 100);
	layer->addChild(platform2, 100);
	layer->addChild(platform3, 100);
	layer->addChild(platform4, 100);
	layer->addChild(platform5, 100);
}

void Level1::RemoveLevel(cocos2d::Layer *layer)
{
	//layer->removeChild(platform1, 100);
	layer->removeChild(platform2, 100);
	layer->removeChild(platform3, 100);
	layer->removeChild(platform4, 100);
	layer->removeChild(platform5, 100);
}