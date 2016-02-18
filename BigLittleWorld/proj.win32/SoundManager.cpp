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
	//NOTE = Preloads the TempSound.wav file. Make it ready to play.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/TempSound.wav");

}

//========================================////========================================////========================================//
//PLAY SFX
void SoundManager::playSFXMenuClick()
{
	//NOTE = Plays the TempSound.wav file when this method is called elsewhere in the game.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/TempSound.wav");

}


//========================================////========================================////========================================//
//PLAY MUSIC