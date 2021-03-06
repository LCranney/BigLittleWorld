#ifndef __GAME_OVER_3_H__
#define __GAME_OVER_3_H__

#include "cocos2d.h"

class GameOver4 : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(GameOver4);


private:
	void GoToLevelScene(cocos2d::Ref *sender);
	void GoToLevel4(cocos2d::Ref *sender);
	void GoToMainMenuScene(cocos2d::Ref *sender);
};

#endif // __GAME_OVER_SCENE_H__



