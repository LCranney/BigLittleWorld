#include "Level.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Level::Level(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	platform1 = Sprite::create("robot.png");
	platform1->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
}

void Level::AddEnemy(cocos2d::Layer *layer)
{
	layer->addChild(platform1, 100);
}

void Level::RemoveEnemy(cocos2d::Layer *layer)
{
	layer->removeChild(platform1, 100);
}

Level::~Level()
{

}