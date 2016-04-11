//INCLUDES
#include "SoundManager.h"
//========================================////========================================////========================================//
//CON / dCON
SoundManager::SoundManager()
{
}
SoundManager::~SoundManager()
{
}
//========================================////========================================////========================================//
//SINGLETON SETUP

//========================================////========================================////========================================//
//INIT METHOD FOR PRE-LOADING
bool SoundManager::init()
{
	//Music Pre-Loads (Cross Platform)
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sound/MenuMusic.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sound/GameLoop.mp3");

	//IOS Sound Pre-Loads
	//NOTE = Preloads the TempSound.wav file. Make it ready to play.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/iDeath.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/iMenuClick.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/iMove.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/iStickToWall.wav");

	//Andriod Sound Pre-Loads
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/aDeath.ogg");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/aMenuClick.ogg");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/aMove.ogg");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/aStickToWall.ogg");

	return true;
}
//========================================////========================================////========================================//
//Kills the sound files.
/*
void KillSound()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic("sound/MenuMusic.mp3");
}
*/
//========================================////========================================////========================================//
//IOS PLAY SFX --- 'iTempSound.wav' being used as a placeholder until the actual sound files are created.
void SoundManager::i_playSFXMenuClick()
{
	//NOTE = Plays the TempSound.wav file when this method is called elsewhere in the game.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iMenuClick.wav");
}
void SoundManager::i_playSFXDeath()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iDeath.wav");
}
void SoundManager::i_playSFXStickToWall()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iStickToWall.wav");
}
void SoundManager::i_playSFXMovement()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iMove.wav");
}
//========================================////========================================////========================================//
//ANDRIOD PLAY SFX --- 'aTempSound.wav' being used as a placeholder until the actual sound files are created.
void SoundManager::a_playSFXMenuClick()
{
	//NOTE = Plays the TempSound.wav file when this method is called elsewhere in the game.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aMenuClick.ogg");
}
void SoundManager::a_playSFXDeath()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aDeath.ogg");
}
void SoundManager::a_playSFXStickToWall()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aStickToWall.ogg");
}
void SoundManager::a_playSFXMovement()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aMove.ogg");
}
//========================================////========================================////========================================//
//PLAY MUSIC
void SoundManager::playMusicMenu()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/MenuMusic.mp3");
}
void SoundManager::playMusicGameOne()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/GameLoop.mp3");
}