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
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sound/SunnyWeather.mp3");

	//IOS Sound Pre-Loads
	//NOTE = Preloads the TempSound.wav file. Make it ready to play.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/iTempSound.wav");

	//Andriod Sound Pre-Loads
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/aTempSound.ogg");

	return true;
}

//========================================////========================================////========================================//
//IOS PLAY SFX --- 'iTempSound.wav' being used as a placeholder until the actual sound files are created.
void SoundManager::i_playSFXMenuClick()
{
	//NOTE = Plays the TempSound.wav file when this method is called elsewhere in the game.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
void SoundManager::i_playSFXCollectPickup()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
void SoundManager::i_playSFXKillHostile()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
void SoundManager::i_playSFXDeath()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
void SoundManager::i_playSFXStickToWall()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
void SoundManager::i_playSFXRicochet()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
void SoundManager::i_playSFXMovement()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/iTempSound.wav");
}
//========================================////========================================////========================================//
//ANDRIOD PLAY SFX --- 'aTempSound.wav' being used as a placeholder until the actual sound files are created.
void SoundManager::a_playSFXMenuClick()
{
	//NOTE = Plays the TempSound.wav file when this method is called elsewhere in the game.
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
void SoundManager::a_playSFXCollectPickup()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
void SoundManager::a_playSFXKillHostile()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
void SoundManager::a_playSFXDeath()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
void SoundManager::a_playSFXStickToWall()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
void SoundManager::a_playSFXRicochet()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
void SoundManager::a_playSFXMovement()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/aTempSound.ogg");
}
//========================================////========================================////========================================//
//PLAY MUSIC
void SoundManager::playMusicMenu()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/SunnyWeather.mp3");
}
void SoundManager::playMusicGameOne()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/SunnyWeather.mp3");
}