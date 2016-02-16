#pragma once
class SoundManager
{
public:
	//CON / dCON
	SoundManager();
	~SoundManager();
	//bool INIT for Pre-Loading audio
	virtual bool init(void);
	//PLAY SFX METHODS
	/*
	//Base SFX
	void playSFXMenuClick;
	void playSFXCollectPickup;
	void playSFXKillHostile;
	void playSFXDeath;
	void playSFXStickToWall;
	void playSFXRicochet;
	void playSFXMovement;
	//BONUS FEATURE SOUNDS ADDED BELOW
	*/
	//PLAY MUSIC METHODS
	/*
	//Base Music
	void playMusicMenu;
	void playMusicGameOne;
	//BONUS FEATURE MUSIC ADDED BELOW
	*/


};

//RESEARCH
//http://super-fashion-puzzle-cocos2d-x.googlecode.com/svn/trunk/Classes/SoundManager.h
//http://super-fashion-puzzle-cocos2d-x.googlecode.com/svn/trunk/Classes/SoundManager.cpp
//http://www.cocos2d-x.org/wiki/Audio
//http://www.ogre3d.org/tikiwiki/tiki-index.php?page=FMOD+SoundManager
//https://github.com/MikelEiza/Cocos2d-x-Game-Structure/blob/master/Classes/Singletons/SoundManager.h