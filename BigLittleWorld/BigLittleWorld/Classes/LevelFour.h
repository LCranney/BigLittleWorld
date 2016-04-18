#ifndef _LEVEL_FOUR_H__
#define _LEVEL_FOUR_H__

#include "cocos2d.h"

class Enemy1;
class Enemy2;
class Player;

class LevelFour : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LevelFour);

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

	Enemy1*			    enemy1Node;
	Enemy1*				enemy1aNode;
	Enemy2*				enemy2Node;
	Enemy1*				enemy1;
	Enemy1*				enemy1a;
	Enemy2*				enemy2;

	cocos2d::Vec2 startPosition;
	cocos2d::Vec2 playerPosition;

	cocos2d::Sprite* Floor1;
	cocos2d::Sprite* Floor2;
	cocos2d::Sprite* Floor3;
	cocos2d::Sprite* Floor4;
	cocos2d::Sprite* Wall1;
	cocos2d::Sprite* Wall2;
	cocos2d::Sprite* Wall3;
	cocos2d::Sprite* Wall4;
	cocos2d::Sprite* Wall5;
	cocos2d::Sprite* Roof;
	cocos2d::Sprite* Roof2;
	cocos2d::Sprite* Roof3;
	cocos2d::Sprite* SpikeRoof1;
	cocos2d::Sprite* SpikeRoof2;
	cocos2d::Sprite* SpikeRoof3;
	cocos2d::Sprite* SpikeRoof4;
	cocos2d::Sprite* Spike1;
	cocos2d::Sprite* Spike2;
	cocos2d::Sprite* Spike3;
	cocos2d::Sprite* SpikeWall1;
	cocos2d::Sprite* SpikeWall2;
	cocos2d::Sprite* Finish;
	cocos2d::Sprite* player;

	bool opposite;
	bool slingshot;

	void GoToGameOverScene();
	void GoToLevelScene();
	void GoToMainMenuScene(cocos2d::Ref *sender);

};

#endif // __SPLASHSCENE_SCENE_H__






