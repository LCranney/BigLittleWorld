#ifndef __LEVEL3_SCENE_H__
#define __LEVEL3_SCENE_H__

#include "cocos2d.h"

class Level3
{
public:
	Level3(cocos2d::Layer *layer);
	void AddLevel(cocos2d::Layer *layer);
	void RemoveLevel(cocos2d::Layer *layer);
	~Level3();

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *platform1;
	cocos2d::Sprite *platform2;
	cocos2d::Sprite *platform3;
	cocos2d::Sprite *platform4;
	cocos2d::Sprite *platform5;

	Level3 *level3;
};

#endif // __LEVEL3_SCENE_H__