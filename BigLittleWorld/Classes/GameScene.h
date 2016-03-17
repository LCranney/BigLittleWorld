#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "math\CCGeometry.h"

class Enemy1;
class Enemy2;
class Player;

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

	//void setViewPointCenter(CCPoint position);
	cocos2d::CCPoint tileCoordForPosition(CCPoint position);
	void setPlayerPosition(CCPoint position);

	cocos2d::PhysicsWorld *sceneWorld;

	Enemy1*			    enemy1Node;
	Enemy1*				enemy1aNode;
	Enemy2*				enemy2Node;
	Enemy1*				enemy1;
	Enemy1*				enemy1a;
	Enemy2*				enemy2;
	Player*				player;

	cocos2d::Vec2 startPosition;
	cocos2d::Vec2 playerPosition;

	cocos2d::TMXTiledMap* _level_1;

	cocos2d::TMXLayer* _BlackLayer;
	cocos2d::TMXLayer* _WhiteLayer;
	cocos2d::TMXLayer* _SpikeLayer;
	cocos2d::TMXLayer* _FinishLayer;


	
	void GoToGameOverScene(cocos2d::Ref *sender);



};

#endif // __SPLASHSCENE_SCENE_H__
