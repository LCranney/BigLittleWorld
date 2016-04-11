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
	static bool init(void);
	//KILL SOUND
//	static void KillSound();
	//PLAY SFX METHODS
	//Base SFX
	//.wav
	void i_playSFXMenuClick();
	void i_playSFXDeath();
	void i_playSFXStickToWall();
	void i_playSFXMovement();
	//.ogg
	static void a_playSFXMenuClick();
	static void a_playSFXDeath();
	static void a_playSFXStickToWall();
	static void a_playSFXMovement();
	//BONUS FEATURE SOUNDS ADDED BELOW

	//PLAY MUSIC METHODS
	//Base Music
	static void playMusicMenu();
	static void playMusicGameOne();
	//BONUS FEATURE MUSIC ADDED BELOW
};

// FORMATTING - MP3 for music on both, WAV for iOS SFX and OGG for SFX on andriod.