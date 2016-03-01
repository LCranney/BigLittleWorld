#include "SpriteAnimator.h"


// NOTE: The pushFileName variable is the name of all of the sprite images minus its number and extension as can be seen in the Initialise method. All image files should be named accordingly.
SpriteAnimator::SpriteAnimator(string plistFilename, string pngFilename, string pushFileName, int frames)
{
	_plistFilename = plistFilename;
	_pngFilename = pngFilename;
	_pushFileName = pushFileName;
	_frames = frames;

	_spritebatch = SpriteBatchNode::create(_pngFilename);

	_cache = SpriteFrameCache::getInstance();
	_cache->addSpriteFramesWithFile(_plistFilename);
}


SpriteAnimator::~SpriteAnimator()
{
}

void SpriteAnimator::Initialise()
{
	Vector<SpriteFrame*> _animFrames;

	for (int i = 1; i <= _frames; i++)
	{
		stringstream ss;
		ss << _pushFileName << i << ".png";
		string string1 = ss.str();
		_animFrames.pushBack(_cache->getSpriteFrameByName(string1));
	}
}

Animation* SpriteAnimator::Animate(float delay)
{
	Animation* animation = Animation::createWithSpriteFrames(_animFrames, delay);
	return animation;
}

