#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Enemy1;
class Enemy2;
class Spikes;

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
	void SetPhysicsWorld(cocos2d::PhysicsWorld *world){ sceneWorld = world; }

	bool onContactBegin(cocos2d::PhysicsContact &contact);

	cocos2d::PhysicsWorld *sceneWorld;

	Enemy1*				enemy1;
	Enemy1*				enemy1a;
	Enemy1*				enemy1b;
	Enemy1*				enemy1c;
	Enemy1*				enemy1d;
	Enemy1*				enemy1e;
	Enemy1*				enemy1f;
	Enemy2*				enemy2;
	Spikes*				spike; 
	Spikes*				spike2;
	Spikes*				spike3;
	Spikes*				spike4;
	Spikes*				spike5;
	Spikes*				spike6;
	Spikes*				spike7;
	Spikes*				spike8;

};

#endif // __SPLASHSCENE_SCENE_H__
