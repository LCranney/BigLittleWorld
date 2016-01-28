#ifndef __LEVEL_SCENE_H__
#define __LEVEL_SCENE_H__

#include "cocos2d.h"

class Level
{
public:
	Level(cocos2d::Layer *layer);
	void AddSprite(cocos2d::Layer *layer);
	void RemoveSprite(cocos2d::Layer *layer);
	~Level();

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *platform1;
};

#endif // __ENEMY_H__