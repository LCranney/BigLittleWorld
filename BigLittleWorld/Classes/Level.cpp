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
}

Level::~Level()
{
}

void Level::AddSprite(cocos2d::Layer *layer)
{
	layer->addChild(platform1, 100);
}

void Level::RemoveSprite(cocos2d::Layer *layer)
{
	layer->removeChild(platform1, 100);
}