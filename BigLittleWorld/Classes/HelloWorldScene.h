#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Enemy1;
class Enemy2;
class Enemy3;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
	CREATE_FUNC(HelloWorld); 


private:
	cocos2d::Sprite*	player;
	cocos2d::Sprite*	ending;
	cocos2d::Sprite*	wall1;
	cocos2d::Sprite*	wall2;
	cocos2d::Sprite*	wall3;
	Enemy1*			    enemy1Node;
	Enemy1*				enemy1aNode;
	Enemy2*				enemy2Node;
	Enemy3*			    enemy3Node;
	Enemy1*				enemy1;
	Enemy1*				enemy1a;
	Enemy2*				enemy2;
	Enemy3*				enemy3;

};

#endif // __HELLOWORLD_SCENE_H__
