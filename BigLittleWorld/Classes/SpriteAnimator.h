#pragma once
#include <string>
#include "cocos2d.h"


using namespace std;
using namespace cocos2d;

class SpriteAnimator
{
public:
	SpriteAnimator(string plistFilename, string pngFilename, string pushFileName, int frames);
	~SpriteAnimator();

	void Initialise();
	Animation* Animate(float delay);

	SpriteBatchNode* GetSpriteBatchNode(){ return _spritebatch; }

	SpriteFrame* GetSpriteFrame(ssize_t frame)
	{
		if (!_animFrames.size() < frame)
		{
			return _animFrames.at(frame);
		}
	}

	Vector<SpriteFrame*> GetSpriteFrames() { return _animFrames; }


private:
	Vector<SpriteFrame*> _animFrames;
	SpriteBatchNode* _spritebatch;
	SpriteFrameCache* _cache;
	int _frames;
	string _plistFilename; 
	string _pngFilename; 
	string _pushFileName;
};

