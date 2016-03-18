#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Enemy1;
class Enemy2;
class Enemy3;

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
	bool onContactPreSolve(cocos2d::PhysicsContact &contact, cocos2d::PhysicsContactPreSolve& solve);
	void onContactPostSolve(cocos2d::PhysicsContact &contact, const cocos2d::PhysicsContactPostSolve& solve);
	void onContactSeperate(cocos2d::PhysicsContact &contact);

	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

	cocos2d::PhysicsWorld *sceneWorld;

	Enemy1*				enemy1;
	Enemy2*				enemy2;
	Enemy3*				enemy3;

	cocos2d::Vec2 startPosition;
	cocos2d::Vec2 playerPosition;

	cocos2d::TMXTiledMap* _level_1;

	cocos2d::TMXLayer* _BlackLayer;
	cocos2d::TMXLayer* _WhiteLayer;
	cocos2d::TMXLayer* _SpikeLayer;
	cocos2d::TMXLayer* _FinishLayer;

	cocos2d::Sprite* Floor1;
	cocos2d::Sprite* Floor2;
	cocos2d::Sprite* Floor3;
	cocos2d::Sprite* Floor4;
	cocos2d::Sprite* Spike1;
	cocos2d::Sprite* Spike2;
	cocos2d::Sprite* Spike3;
	cocos2d::Sprite* Finish;
	cocos2d::Sprite* player;

	void GoToGameOverScene(cocos2d::Ref *sender);

};

#endif // __SPLASHSCENE_SCENE_H__
