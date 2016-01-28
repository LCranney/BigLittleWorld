#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "GameManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include <string.h>
#include <sstream>

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;

class GameScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);

private:
	Level1* platform1;
	Level2* platform2;
	Level3* platform3;
};

#endif // __ENEMY_H__

