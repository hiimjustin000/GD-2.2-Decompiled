#ifndef __LEVELTOOLS_H__
#define __LEVELTOOLS_H__

#include "includes.h"


#define UNKNOWN_RETURN void


class LevelTools {
	static int artistForAudio(int);
	static std::string base64DecodeString(std::string);
	static std::string base64EncodeString(std::string);
	static cocos2d::CCDictionary* createStarPackDict();
	static std::string fbURLForArtist(int);
	static int getAudioBPM(int);
	static std::string getAudioFileName(int);

    /* TODO: This one carries around unknown globals... */
	static std::string getAudioString(int);
	
  static std::string getAudioTitle(int);
	static UNKNOWN_RETURN getLastGameplayReversed();
	static UNKNOWN_RETURN getLastGameplayRotated();
	static float getLastTimewarp();
	static GJGameLevel* getLevel(int, bool);
	static std::map<int, int> getLevelList();
	static SongInfoObject* getSongObject(int);
    /* TODO */
	static void moveTriggerObjectsToArray(cocos2d::CCArray*, cocos2d::CCDictionary*, int);
	
    static std::string nameForArtist(int);
	static std::string ngURLForArtist(int);
	static int offsetBPMForTrack(int);
	static float posForTime(float, cocos2d::CCArray*, int, bool, int&);
	static float posForTimeInternal(float, cocos2d::CCArray*, int, bool, bool, bool, int&, int);
	/* TODO */
  static UNKNOWN_RETURN sortChannelOrderObjects(cocos2d::CCArray*, cocos2d::CCDictionary*, bool);
	/* TODO */
  static UNKNOWN_RETURN sortSpeedObjects(cocos2d::CCArray* arr, GJBaseGameLayer* baseGameLayer);
	static float timeForPos(cocos2d::CCPoint, cocos2d::CCArray*, int, int, int, bool, bool, bool, bool, int);
    /* Seems to be Robtop only :/ */
	static void toggleDebugLogging(bool);
	static std::string urlForAudio(int);
	static int valueForSpeedMod(int);
	static bool verifyLevelIntegrity(std::string, int);
	static std::string ytURLForArtist(int);
};


#endif // __LEVELTOOLS_H__
