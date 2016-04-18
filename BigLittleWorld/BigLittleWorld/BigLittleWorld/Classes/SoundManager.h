#pragma once
//INCLUDES
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
//CLASS START
class SoundManager
{
public:
//CON / dCON
	SoundManager();
	~SoundManager();
//bool INIT for Pre-Loading audio
	virtual bool init(void);
//PLAY SFX METHODS
	//Base SFX
	//.wav
	void i_playSFXMenuClick();
	void i_playSFXCollectPickup();
	void i_playSFXKillHostile();
	void i_playSFXDeath();
	void i_playSFXStickToWall();
	void i_playSFXRicochet();
	void i_playSFXMovement();
	//.ogg
	void a_playSFXMenuClick();
	void a_playSFXCollectPickup();
	void a_playSFXKillHostile();
	void a_playSFXDeath();
	void a_playSFXStickToWall();
	void a_playSFXRicochet();
	void a_playSFXMovement();
	//BONUS FEATURE SOUNDS ADDED BELOW

//PLAY MUSIC METHODS
	//Base Music
	void playMusicMenu();
	void playMusicGameOne();
	//BONUS FEATURE MUSIC ADDED BELOW


};

//RESEARCH
//http://super-fashion-puzzle-cocos2d-x.googlecode.com/svn/trunk/Classes/SoundManager.h
//http://super-fashion-puzzle-cocos2d-x.googlecode.com/svn/trunk/Classes/SoundManager.cpp
//http://www.cocos2d-x.org/wiki/Audio
//http://www.ogre3d.org/tikiwiki/tiki-index.php?page=FMOD+SoundManager
//https://github.com/MikelEiza/Cocos2d-x-Game-Structure/blob/master/Classes/Singletons/SoundManager.h
//http://www.bfxr.net/ //<<< Make sound effects
// FORMATTING - MP3 for music on both, WAV for iOS SFX and OGG for SFX on andriod.