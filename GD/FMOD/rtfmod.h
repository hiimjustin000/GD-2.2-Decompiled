#ifndef __RTFMOD_H__
#define __RTFMOD_H__

#include "FMOD/fmod.hpp"
#include "../includes.h"
#include <unordered_set>
#include <map>
#include <unordered_map>

/* Robtop's FMOD Library */

/* Belive these are also robtop's class objets and Enums */

enum AudioTargetType{

};

enum AudioModType{

};


class FMODSound {

};

class FMODSoundState{

};

class FMODSoundTween{

};

class FMODAudioState {
public:
	// ~FMODAudioState();
	FMODAudioState();
	FMODAudioState operator=(FMODAudioState const&);
	unsigned int unknown0;
	unsigned int unknown1;
	std::map<std::pair<int,int>,FMODSoundTween> unknownMap0;
  	std::map<std::pair<int,int>,FMODSoundTween> unknownMap1;
  	std::map<std::pair<int,int>,FMODSoundTween> unknownMap2;
	std::unordered_map<int, float> volumeRelated00;
	std::unordered_map<int, float> volumeRelated01;
	std::unordered_map<int, float> pitchRelated0;
	std::unordered_map<int, float> volumeRelated10;
	std::unordered_map<int, float> volumeRelated11;
	std::unordered_map<int, float> pitchRelated1;
	std::unordered_map<int, float> unknownUMap6;
	std::unordered_map<int, float> unknownUMap7;
	std::unordered_map<int, float> unknownUMap8;
  	std::unordered_map<int, float> unknownUMap9;
	std::unordered_map<int, FMODQueuedMusic> m_needLoadMusic;
	std::unordered_map<int, FMODQueuedMusic> m_queuedMusic;
	std::unordered_map<int, FMODSoundState> unknownUMap12;
	uint64_t unknown2;
};


class FMODReverbPreset{

};

class FMODQueuedMusic{

};

class FMODAudioEngine : public cocos2d::CCNode {
	// virtual ~FMODAudioEngine();
	// FMODAudioEngine();
public:
	static FMODAudioEngine* sharedEngine();

	TodoReturn activateQueuedMusic(int);
	TodoReturn channelForChannelID(int);
	TodoReturn channelForUniqueID(int);
	TodoReturn channelIDForUniqueID(int);
	TodoReturn channelLinkSound(int ID, FMODSound* sound);
	TodoReturn channelStopped(FMOD::Channel* channel, bool);
	TodoReturn channelUnlinkSound(int);
	void clearAllAudio();
	int countActiveEffects();
	int countActiveMusic();
	TodoReturn createStream(std::string _fileName);
	TodoReturn disableMetering();
	TodoReturn enableMetering();
	TodoReturn fadeInBackgroundMusic(float);
	TodoReturn fadeInMusic(float _fadeTime, int _musicID);
	TodoReturn fadeOutMusic(float _fadeTime, int _musicID);
	TodoReturn getActiveMusic(int);
	TodoReturn getActiveMusicChannel(int);
	float getBackgroundMusicVolume();
	TodoReturn getChannelGroup(int, bool);
	float getEffectsVolume();
	TodoReturn getFMODStatus(int);
	float getMeteringValue();
	TodoReturn getMusicChannelID(int);
	TodoReturn getMusicLengthMS(int);
	TodoReturn getMusicTime(int);
	TodoReturn getMusicTimeMS(int);
	TodoReturn getNextChannelID();
	TodoReturn getTweenContainer(AudioTargetType);
	bool isChannelStopping(int _channelID);
	bool isEffectLoaded(std::string);
	bool isMusicPlaying(std::string _musicName, int MID);
	bool isMusicPlaying(int MID);
	bool isSoundReady(FMOD::Sound* sound);
	TodoReturn lengthForSound(std::string);
	TodoReturn loadAndPlayMusic(std::string, unsigned int, int);
	TodoReturn loadAudioState(FMODAudioState&);
	TodoReturn loadMusic(std::string, float, float, float, bool, int, int);
	TodoReturn loadMusic(std::string);
	TodoReturn pauseAllAudio();
	TodoReturn pauseAllEffects();
	TodoReturn pauseAllMusic();
	TodoReturn pauseEffect(unsigned int);
	TodoReturn pauseMusic(int);
	TodoReturn pitchForIdx(int);
	void playEffect(std::string, float, float, float);
	void playEffect(std::string);
	TodoReturn playEffectAdvanced(std::string, float, float, float, float, bool, bool, int, int, int, int, bool, int, bool, bool, int, int, float, int);
	TodoReturn playEffectAsync(std::string);
	TodoReturn playMusic(std::string, bool, float, int);
	TodoReturn preloadEffect(std::string);
	TodoReturn preloadEffectAsync(std::string);
	TodoReturn preloadMusic(std::string, bool, int);
	TodoReturn printResult(FMOD_RESULT result);
	TodoReturn queuedEffectFinishedLoading(std::string);
	TodoReturn queuePlayEffect(std::string, float, float, float, float, bool, bool, int, int, int, int, bool, int, bool, int, float, int);
	TodoReturn queueStartMusic(std::string, float, float, float, bool, int, int, int, int, int, bool, int, bool);
	TodoReturn registerChannel(FMOD::Channel* channel, int, int);
	void releaseRemovedSounds();
	TodoReturn resumeAllAudio();
	TodoReturn resumeAllEffects();
	TodoReturn resumeAllMusic();
	TodoReturn resumeAudio();
	TodoReturn resumeEffect(unsigned int);
	TodoReturn resumeMusic(int);
	TodoReturn reverbToString(FMODReverbPreset);
	TodoReturn saveAudioState(FMODAudioState&);
	void setBackgroundMusicVolume(float);
	void setChannelPitch(int, AudioTargetType, float);
	void setChannelVolume(int, AudioTargetType, float);
	void setChannelVolumeMod(int, AudioTargetType, float);
	void setEffectsVolume(float);
	void setMusicTimeMS(unsigned int, bool, int);
	void setup();
	TodoReturn setupAudioEngine();
	void start();
	void startMusic(int, int, int, int, bool, int, bool);
	TodoReturn stop();
	void stopAllEffects();
	void stopAllMusic();
	TodoReturn stopAndGetFade(FMOD::Channel* channel);
	TodoReturn stopAndRemoveMusic(int);
	TodoReturn stopChannel(FMOD::Channel*, bool, float);
	TodoReturn stopChannel(int, AudioTargetType, bool, float);
	TodoReturn stopChannel(int);
	TodoReturn stopChannelTween(int, AudioTargetType, AudioModType);
	TodoReturn stopChannelTweens(int, AudioTargetType);
	TodoReturn stopMusic(int _musicID);
	TodoReturn stopMusicNotInSet(std::unordered_set<int> set);
	TodoReturn storeEffect(FMOD::Sound* _effectSound, std::string _effectName);
	TodoReturn swapMusicIndex(int, int);
	TodoReturn testFunction(int);
	TodoReturn triggerQueuedMusic(FMODQueuedMusic* queue);
	TodoReturn unloadAllEffects();
	TodoReturn unloadEffect(std::string _effectName);
	TodoReturn unregisterChannel(int _channelID);
	void updateBackgroundFade();
	TodoReturn updateChannel(int, AudioTargetType, AudioModType, float, float);
	TodoReturn updateChannelTweens(float);
	void updateMetering();
	TodoReturn updateQueuedEffects();
	void updateQueuedMusic();
	TodoReturn updateReverb(FMODReverbPreset reverb, bool);
	void updateTemporaryEffects();
	TodoReturn waitUntilSoundReady(FMOD::Sound* sound);

	virtual void update(float);

    /* WARNING SOME Members ARE OUT OF ORDER! */

    float m_bgMusicVolume;
	float m_musicVolume;
	float m_sfxVolume;

    float m_meteringValue;

    bool m_metering;


    unsigned int m_bufferSize;

    int m_inputEnabled; /* Could be a boolean? */
    FMOD::ChannelGroup* m_pausedEffects;
    int m_unkDSPID;


    /* Unknown Object Goes Here... 0x19c */
    bool m_unkBool;
    bool m_audioPaused;

    bool m_started;


    /* 0x3d8 */
    FMODReverbPreset* m_reverbPreset;



	
    FMOD::Channel* m_backgroundMusicChannel;
	FMOD::System* m_system;
	FMOD::Sound* m_sound;
	FMOD::Channel* m_currentSoundChannel;
	FMOD::Channel* m_globalChannel;
	FMOD::DSP* m_DSP;
	FMOD_RESULT m_lastResult;
	int m_version;
	void* m_extraDriverData;
	int m_musicOffset;

    /* TODO: Map Objects... */
};






#endif // __RTFMOD_H__
