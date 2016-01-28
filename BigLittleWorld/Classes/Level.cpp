#include "Level.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Level::Level(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	platform1 = Sprite::create("robot.png"); platform1->setPosition(0, 0); platform1->setScale(100); 
	platform2 = Sprite::create("robot.png"); platform2->setPosition(0, 0); platform2->setScale(100);
	platform3 = Sprite::create("robot.png"); platform3->setPosition(0, 0); platform3->setScale(100);
	platform4 = Sprite::create("robot.png"); platform4->setPosition(0, 0); platform4->setScale(100);
	platform5 = Sprite::create("robot.png"); platform5->setPosition(0, 0); platform5->setScale(100);
}

Level::~Level()
{
}

void Level::AddSprite(cocos2d::Layer *layer)
{
	layer->addChild(platform1, 100);
	layer->addChild(platform2, 100);
	layer->addChild(platform3, 100);
	layer->addChild(platform4, 100);
	layer->addChild(platform5, 100);
}

void Level::RemoveSprite(cocos2d::Layer *layer)
{
	layer->removeChild(platform1, 100);
	layer->removeChild(platform2, 100);
	layer->removeChild(platform3, 100);
	layer->removeChild(platform4, 100);
	layer->removeChild(platform5, 100);
}