#include "includes.h"

/* Includes is having a problem on my end with intellisense 
 * This solution will be temporary until I fix it... */
#include "cocos2d/cocos-headers/cocos2dx/support/zip_support/ZipUtils.h"


/* Someone's gonna have to brute-force all 40 of these using a mod of some kind... */
static int GLOBAL_ARTISTAUDIOMAP[0x29];


int LevelTools::artistForAudio(int ArtistID)
{
    return (ArtistID + 1 < 0x29) ? GLOBAL_ARTISTAUDIOMAP[ArtistID] : 0;
}


std::string LevelTools::base64DecodeString(std::string str){
    if (str.size() == 0) 
        str = ""; 
    return cocos2d::ZipUtils::base64URLDecode(str);
}

std::string LevelTools::base64EncodeString(std::string str){
    if (str.size() == 0) 
        str = ""; 
    return cocos2d::ZipUtils::base64URLEncode(str);
}



cocos2d::CCDictionary* LevelTools::createStarPackDict(){
    auto starpack = cocos2d::CCDictionary::create();
    
    /* This doesn't seem to be super optimized to me and 
     * I am of the beleif that Robtop put this in here to 
     * troll me -_-  it is possible to switch to using a 
     * static array to optimize all of this... */

    std::string stars("1,3,2,4,3,4,5,5,6,6,7,6,8,7,9,8,10,8,11,9,19,10,20,10,21,10,22,10,26,10,27,10,28,10,29,10,30,10,31,10,32,4,33,5,34,6,35,8,36,8,37,5,38,5,39,6,40,7,41,8,42,8,43,8,44,9,45,6,4 6,10,47,10,48,10,49,10,50,10,52,4,53,3,54,4,55,4,56,5,57,6,58,7,59,8,60,8,61,8,62,9,63,9,64,10,65,10,66,10");
    auto array = cocos2d::CCArray::create();

    size_t endpos = stars.find(",",0);
    size_t startpos = 0;

    while (true) {
        std::string num = stars.substr(startpos, endpos - startpos);
        if (num.size() != 0 || num != "") {
          array->addObject(cocos2d::CCString::create(num));
        }
        if (endpos == std::string::npos) break;
        startpos = endpos + 1;
        endpos = stars.find(",", startpos);
    }

    int idx1 , idx = 0;

    while (true) {
        idx1 = idx + 1;
        if (array->count() <= idx) break;
        cocos2d::CCString* str = array->stringAtIndex(idx);
        idx += 2;
        starpack->setObject(array->stringAtIndex(idx1) , str->intValue());
    }
    return starpack;
}

/* Facebook */

std::string LevelTools::fbURLForArtist(int artistID)
{
    /* NOTE: case 2: is missing what happened to 2 Robtop? */
    switch(artistID) {
        case 0:
            return "https://www.facebook.com/DJVITechno";
        case 1:
            return "https://www.facebook.com/pages/Waterflame/210371073165";
        case 3:
            return "https://www.facebook.com/foreverboundofficial";
        case 4:
            return "https://www.facebook.com/StephanWellsMusic";
        case 5:
            return "https://www.facebook.com/pages/Dj-Nate/280339788656689";
        case 6:
            return "https://www.facebook.com/pages/F-777/286884484660892";
        case 7:
            return "https://www.facebook.com/MDKOfficial";
        case 8:
            return "https://www.facebook.com/dexarsonoffical";
        case 9:
            return "https://www.facebook.com/BoomKittyMusic";
        case 10:
            return "https://www.facebook.com/Bossfightswe";
        case 11:
            return "https://www.facebook.com/hinkik";
        default:
            return "";
    }
}

/* TODO Brute-force for the different return values...*/
static int GLOBAL_AUDIOBPM[15];

int LevelTools::getAudioBPM(int BPM)
{
    return (BPM < 0xf) ? GLOBAL_AUDIOBPM[BPM] : 0x82;
}



std::string LevelTools::getAudioFileName(int songID)
{ 
    switch(songID) {
        case 0:
            return "StereoMadness.mp3";
        case 1:
            return "BackOnTrack.mp3";
        case 2:
            return "Polargeist.mp3";
        case 3:
            return "DryOut.mp3";
        case 4:
            return "BaseAfterBase.mp3";
        case 5:
            return "CantLetGo.mp3";
        case 6:
            return "Jumper.mp3";
        case 7:
            return "TimeMachine.mp3";
        case 8:
            return "Cycles.mp3";
        case 9:
            return "xStep.mp3";
        case 10:
            return "Clutterfunk.mp3";
        case 11:
            return "TheoryOfEverything.mp3";
        case 12:
            return "Electroman.mp3";
        case 13:
            return "Clubstep.mp3";
        case 14:
            return "Electrodynamix.mp3";
        case 15:
            return "HexagonForce.mp3";
        case 16:
            return "BlastProcessing.mp3";
        case 17:
            return "TheoryOfEverything2.mp3";
        case 18:
            return "GeometricalDominator.mp3";
        case 19:
            return "Deadlocked.mp3";
        case 20:
            return "Fingerdash.mp3";
        case 21:
            return "Dash.mp3";
        /* Coming soon... */
        case 22:
            return "Explorers.mp3";
        /* Mealtdown */
        case 23:
            return "The7Seas.mp3";
        case 24:
            return "VikingArena.mp3";
        case 25:
            return "AirborneRobots.mp3";
        case 26: /* Random Song 6 / The Challenge) Vault Keeper's level */
            return "DJRubRub.mp3";
        /* GDWorld */
        case 27:
            return "Payload.mp3";
        case 28:
            return "BeastMode.mp3";
        case 29:
            return "Machina.mp3";
        case 30:
            return "Years.mp3";
        case 31:
            return "ElectroFrontlines.mp3";
        case 32:
            return "SpacePirates.mp3";
        case 33:
            return "Striker.mp3";
        case 34:
            return "Embers.mp3";
        case 35:
            return "Round1.mp3";
        case 36:
            return "MonsterDanceOff.mp3";
        /* SubZero */
        case 37:
            return "PressStart.mp3";
        case 38:
            return "knockemout.mp3";
        case 39:
            return "PowerTrip.mp3";
        default: /* Guess were back on crack... */
            return "BackOnTrack.mp3";
    }
}

/* Unknown Globals... TODO: Figure out globals... */
// std::string LevelTools::getAudioString(int audioID);

std::string LevelTools::getAudioTitle(int ID)
{   
    switch(ID) {
        /* Main Game Music */
        case 0:
            return "Stereo Madness";
        
        case 1:
            return "Back On Track";
        
        case 2:
            return "Polargeist";
        
        case 3:
            return "Dry Out";
        
        case 4:
            return "Base After Base";
        
        case 5:
            return "Cant Let Go";
        
        case 6:
            return "Jumper";
        
        case 7:
            return "Time Machine";
        
        case 8:
            return "Cycles";
        
        case 9:
            return "xStep";
        
        case 10:
            return "Clutterfunk";
        
        case 11:
            return "Theory of Everything";
        
        case 12:
            return "Electroman Adventures";
        
        case 13:
            return "Clubstep";
       
        case 14:
            return "Electrodynamix";
        
        case 15:
            return "Hexagon Force";
        
        case 16:
            return "Blast Processing";
        
        case 17:
            return "Theory of Everything 2";
        
        case 18:
            return "Geometrical Dominator";
        
        case 19:
            return "Deadlocked";
        
        case 20:
            return "Fingerdash";
        
        case 21:
            return "Dash";
        
        case 22:
            return "Explorers";

        /* Meltdown */
        case 23:
            return "The Seven Seas";
        case 24:
            return "Viking Arena";
        case 25:
            return "Airborne Robots";

        /* Vault Secret Level */
        case 26:
            return "Secret";

        /* GD World */
        case 27:
            return "Payload";
        
        case 28:
            return "Beast Mode";

        case 29:
            return "Machina";

        case 30:
            return "Years";

        case 31:
            return "Frontlines";

        case 32:
            return "Space Pirates";

        case 33:
            return "Striker";

        case 34:
            return "Embers";

        case 35:
            return "Round 1";

        case 36:
            return "Monster Dance Off";
        
        /* SubZero */
        case 37:
            return "Press Start";

        case 38:
            return "Nock Em";

        case 39:
            return "Power Trip";

        /* Practice Music */
        case -1:
            return "Practice: Stay Inside Me";
        
        /* Unknown */
        default:
            return "Unknown";
        
    }
}


/* Unknown... */
/* 
undefined LevelTools::getLastGameplayReversed(void)
{
  return GLOBAL_LASTGAMEPLAYREVERSED;
}

undefined LevelTools::getLastGameplayRotated(void)

{
  return GLOBAL_LASTGAMEPLAYROTATED;
}

*/

static float GLOBAL_LASTTIMEWARP = 0.0;

float LevelTools::getLastTimewarp()
{
    return GLOBAL_LASTTIMEWARP;
}

GJGameLevel * LevelTools::getLevel(int levelID, bool loaded){
    auto level = GJGameLevel::create();
    if (levelID == 0xe) {
      level->m_levelName = getAudioTitle(0xd);
      level->m_audioTrack = 0xd;
      level->m_difficulty = kGJDifficultyDemon;
      level->setStars(0xe);
      level->m_requiredCoins = 10;
      level->setDemon(1);
      level->m_capacityString = "29_237_29_54_29_29_29_132_29_29_98_29_132_29_29_29";
    }
    else {
        if (levelID < 0xf) {
            if (levelID == 7) {
              level->m_levelName = getAudioTitle(6);
              level->m_audioTrack = 6;
              level->m_difficulty = kGJDifficultyHarder;
              level->setStars(7);
              level->m_capacityString = "29_98_29_40_29_29_29_29_29_29_98_29_98_29_29_29";
            }
        else if (levelID < 8) {
            if (levelID == 3) {
                level->m_levelName = getAudioTitle(2);
                level->m_audioTrack = 2;
                level->m_difficulty = kGJDifficultyNormal;
                level->setStars(3);
                level->m_capacityString = "29_98_29_40_29_29_29_29_29_29_29_29_98_29_29_29";
            }
            else if (levelID < 4) {
                if (levelID == 1) {
                    level->m_levelName = getAudioTitle(0);
                    level->m_audioTrack = 0;
                    level->m_difficulty = kGJDifficultyEasy;
                    level->setStars(1);
                    level->m_capacityString = "29_98_29_40_29_29_29_29_29_29_177_29_73_29_29_29";
                }
                else {
                    if (levelID == 2){ 
                        level->m_levelName = getAudioTitle(1);
                        level->m_audioTrack = 1;
                        level->m_difficulty = kGJDifficultyEasy;
                        level->setStars(2);
                        level->m_capacityString = "29_54_29_40_29_29_29_29_29_29_98_29_54_29_29_29";
                    }
                }
            }
            else {
                if (levelID == 5) {
                    level->m_levelName = getAudioTitle(4);
                    level->m_audioTrack = 4;
                    level->m_difficulty = kGJDifficultyHard;
                    level->setStars(5);
                    level->m_capacityString = "29_73_29_40_29_29_29_29_29_29_98_29_73_29_29_29";
                }
                else if (levelID < 6) {
                    level->m_levelName = getAudioTitle(3);
                    level->m_audioTrack = 3;
                    level->m_difficulty = kGJDifficultyNormal;
                    level->setStars(4);
                    level->m_capacityString = "29_73_29_40_29_29_29_29_29_29_73_29_73_29_29_29";
                }
                else {
                    level->m_levelName = getAudioTitle(5);
                    level->m_audioTrack = 5;
                    level->m_difficulty = kGJDifficultyHard;
                    level->setStars(6);
                    level->m_capacityString = "29_73_29_40_29_29_29_29_29_29_29_29_73_29_29_29";
                }
            }
        }
        else if (levelID == 10) {
          level->m_levelName = getAudioTitle(9);
          level->m_audioTrack = 9;
          level->m_difficulty = kGJDifficultyInsane;
          level->setStars(10);
          level->m_capacityString = "29_132_29_40_29_29_29_54_29_29_132_29_73_29_29_29";
        }
        else if (levelID < 0xb) {
            if (levelID == 8) {
                level->m_levelName = getAudioTitle(7);
                level->m_audioTrack = 7;
                level->m_difficulty = kGJDifficultyHarder;
                level->setStars(8);
                level->m_capacityString = "29_132_29_40_29_29_29_29_29_29_73_29_98_29_29_29";
            }   
            else if (levelID == 9) {
                level->m_levelName = getAudioTitle(8);
                level->m_audioTrack = 8;
                level->m_difficulty = kGJDifficultyHarder;
                level->setStars(9);
                level->m_capacityString = "29_98_29_40_29_29_29_40_29_29_98_29_98_29_29_29";
            }
        }
        else {
            if (levelID == 0xc) {
                level->m_levelName = getAudioTitle(0xb);
                level->m_audioTrack = 0xb;
                level->m_difficulty = kGJDifficultyInsane;
                level->setStars(0xc);
                level->m_capacityString = "29_237_29_54_29_29_29_73_29_29_132_29_132_29_29_29";
            }
            else if (levelID < 0xd) {
              level->m_levelName = getAudioTitle(10);
              level->m_audioTrack = 10;
              level->m_difficulty = kGJDifficultyInsane;
              level->setStars(0xb);
              level->m_capacityString = "29_237_29_40_29_29_29_73_29_29_29_29_98_29_29_29";
            }
            else {
                level->m_levelName = getAudioTitle(0xc);
                level->m_audioTrack = 0xc;
                level->m_difficulty = kGJDifficultyInsane;
                level->setStars(10);
                level->m_capacityString = "29_237_29_40_29_29_29_98_29_29_98_29_132_29_29_29";
            }
        }
    }   
    if (levelID == 0x15) {
        level->m_levelName = getAudioTitle(0x14);
        level->m_audioTrack = 0x14;
        level->m_difficulty = kGJDifficultyInsane;
        level->setStars(0xc);
        level->m_capacityString = "40_630_195_48_0_0_210_114_0_0_572_247_97_0_0_53_466_135_0_459_276_71_448_0_101_88_101_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0";
    }
    if (levelID < 0x16) {
        if (levelID == 0x11) {
            level->m_levelName = getAudioTitle(0x10);
            level->m_audioTrack = 0x10;
            level->m_difficulty = kGJDifficultyHarder;
            level->setStars(10);
            level->m_capacityString = "29_237_29_73_29_29_98_132_29_29_566_54_132_29_29_29";
        }
        else if (levelID < 0x12) {
            if (levelID == 0xf) {
                level->m_levelName = getAudioTitle(0xe);
                level->m_audioTrack = 0xe;
                level->m_difficulty = kGJDifficultyInsane;
                level->setStars(0xc);
                level->m_capacityString = "29_237_98_40_29_29_29_237_29_29_98_73_177_29_29_29";
            }
            else if (levelID == 0x10){
                level->m_levelName = getAudioTitle(0xf);
                level->m_audioTrack = 0xf;
                level->m_difficulty = kGJDifficultyInsane;
                level->setStars(0xc);
                level->m_capacityString = "29_317_73_73_29_29_54_132_29_29_237_132_177_29_29_29";
            }
        }
        else {
            if (levelID == 0x13) {
                level->m_levelName = getAudioTitle(0x12);
                level->m_audioTrack = 0x12;
                level->m_difficulty = kGJDifficultyHarder;
                level->setStars(10);
                level->m_levelName = "29_424_132_40_29_29_566_132_29_29_756_237_132_29_73_29";
            }
            else if (levelID < 0x14) {
                level->m_levelName = getAudioTitle(0x11);
                level->m_audioTrack = 0x11;
                level->m_difficulty = kGJDifficultyDemon;
                level->setStars(0xe);
                level->m_requiredCoins = 0x14;
                level->setDemon(1);
                level->m_levelName = "29_317_40_54_29_40_132_132_29_29_424_98_237_29_29_29";
            }
            else {
                getAudioTitle(0x13);
                level->m_audioTrack = 0x13;
                level->m_difficulty = kGJDifficultyDemon;
                level->setStars(0xf);
                level->m_requiredCoins = 0x1e;
                level->setDemon(1);
                level->m_capacityString = "29_317_73_73_29_29_317_424_73_29_566_317_177_29_132_54";
            }
        }
    }
    /* The Tower */
    if (levelID == 0x1389) {
        level->m_levelName = "The Tower";
        level->m_audioTrack = 0;
        // level->m_songID = (int)&DAT_0098a25f;
        level->m_difficulty = kGJDifficultyNormal;
        level->setStars(5);
        level->m_capacityString = "1,210,25,209,56,310,58,250,62,249";
        level->m_levelLength = kGJLengthPlat;
    }
    else {
        if (0x1389 < levelID) {
            /* The Cellar */
            if (levelID == 0x138b) {
                level->m_levelName = "The Cellar";
                level->m_audioTrack = 0;
                // level->m_songID = (int)&DAT_0098a1bb;
                level->m_difficulty = kGJDifficultyHarder;
                level->setStars(7);
                level->m_capacityString = "50,206,52,396,54,682";
            }
            /* The Sewers */
            else if (levelID < 0x138b) {
                level->m_levelName = "The Sewers";
                level->m_audioTrack = 0;
                // level->m_songID = (int)&DAT_0098a2b9;
                level->m_difficulty = kGJDifficultyHard;
                level->setStars(6);
                level->m_capacityString = "50,366,52,332,54,408";
            }
            else if (levelID == 0x138c){
                level->m_levelName = "The Secret Hollow";
                level->m_audioTrack = 0;
                level->m_songID = 10006086;
                level->m_difficulty = kGJDifficultyHarder;
                level->setStars(7);
                level->m_capacityString = "52,505,54,1104,56,556,58,368";
            }
        }
        if (levelID != 0x16) {
            if (levelID != 0xbb9) { 
                /* Memory leak? */
                /* Robtop, I Have a fix for it -> level->release(); */
                return getLevel(1, loaded);
            }
            level->m_levelName = "The Challenge";
            level->m_audioTrack = 0x1a;
            level->m_difficulty = kGJDifficultyHard;
            level->setStars(3);
            level->m_capacityString = "73_237_29_40_29_29_237_98_29_29_237_237_132_29_29_29";
        }
        level->m_levelName = getAudioTitle(0x15);
        level->m_audioTrack = 0x15;
        level->m_difficulty = kGJDifficultyInsane;
        level->setStars(0xc);
        level->m_capacityString = "24,340,52,244,54,1335,56,356,58,510,60,1257";
        level->m_timestamp = 21940;
    }
    }
    if (!loaded) {
        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
    }
    level->setLevelID(levelID);
    // level->m_levelType = 1; TODO Enums for m_levelType 
    level->m_coins = 3;
    return level;
}


static std::map<int, int> GLOBAL_LEVELLIST;

std::map<int, int> LevelTools::getLevelList()
{
    return GLOBAL_LEVELLIST;
}


SongInfoObject* LevelTools::getSongObject(int songID){
    int ArtistID = artistForAudio(songID);
    return SongInfoObject::create(songID, getAudioTitle(songID), nameForArtist(ArtistID), ArtistID, 0, "", "", "", 0);
}

/* TODO: IF anyone wants to do it, feel free... */
/* LevelTools::moveTriggerObjectsToArray(cocos2d::CCArray*, cocos2d::CCDictionary*, int) */

std::string LevelTools::nameForArtist(int ArtistID){
    switch(ArtistID) {
        case 0:
            return "DJVI";
        case 1:
            return "Waterflame";
        case 2:
            return "OcularNebula";
        case 3:
            return "ForeverBound";
        case 4:
            return "Step";
        case 5:
            return "DJ-Nate";
        case 6:
            return "F-777";
        case 7:
            return "MDK";
        case 8:
            return "Dex Arson";
        case 9:
            return "Boom Kitty";
        case 10:
            return "Bossfight";
        case 0xb:
            return "Hinkik";
        default:
            return " ";
    }
}   

std::string LevelTools::ngURLForArtist(int ID){
    switch(ID) {
        case 0:
            return "https://djvi.newgrounds.com/";
        case 1:
            return "https://waterflame.newgrounds.com/";
        case 2:
            return "https://ocularnebula.newgrounds.com/";
        case 3:
            return "https://foreverbound.newgrounds.com/";
        case 4:
            return "https://step.newgrounds.com/";
        case 5:
            return "https://dj-nate.newgrounds.com/";
        case 6:
            return "https://f-777.newgrounds.com/";
        case 7:
            return "";
        case 8:
            return "https://dexarson.newgrounds.com/";
        case 9:
            return "https://boomkitty.newgrounds.com/";
        case 10:
            return "https://bossfightofficial.newgrounds.com/";
        case 0xb:
            return "https://hinkik.newgrounds.com/";
        default:
            return "";
    }
}



/* TODO Brute-Force For Values to solve for GLOBAL_OFFSET_BPM_FOR_TRACK's Values... */
static int GLOBAL_OFFSET_BPM_FOR_TRACK;

int LevelTools::offsetBPMForTrack(int BPM)
{
    return (BPM - 10 < 4) ? (GLOBAL_OFFSET_BPM_FOR_TRACK + (BPM - 10) * 4) : 0;
}


/* 

Feel free to solve this one for me if you have time... as well as "posForTimeInternal"

void * LevelTools::posForTime(float param_1,CCArray *param_2,int param_3,bool param_4,int param_5 )

{
  bool in_r3;
  
  posForTimeInternal(param_1,param_2,param_3,in_r3,param_4,false,0,param_5);
  return (void *)param_1;
}

*/

/* TODO: LevelTools::sortChannelOrderObjects(cocos2d::CCArray*, cocos2d::CCDictionary*, bool) */
/* TODO: LevelTools::sortSpeedObjects(cocos2d::CCArray*, GJBaseGameLayer*) */

/* TODO: WARNING LARGE FUNCTION!  LevelTools::timeForPos(cocos2d::CCPoint, cocos2d::CCArray*, int, int, int, bool, bool, bool, bool, int) */

/* Robtop Only It seems... :/ */
void LevelTools::toggleDebugLogging(bool debug)
{
  return /* NOOP */;
}


std::string LevelTools::urlForAudio(int ID)
{
    switch(ID) {
        case 0:
            return "https://www.youtube.com/watch?v=JhKyKEDxo8Q";
        case 1:
            return "https://www.youtube.com/watch?v=N9vDTYZpqXM";
        case 2:
            return "https://www.youtube.com/watch?v=4W28wWWxKuQ";
        case 3:
            return "https://www.youtube.com/watch?v=FnXabH2q2A0";
        case 4:
            return "https://www.youtube.com/watch?v=TZULkgQPHt0";
        case 5:
            return "https://www.youtube.com/watch?v=fLnF-QnR1Zw";
        case 6:
            return "https://www.youtube.com/watch?v=ZXHO4AN_49Q";
        case 7:
            return "https://www.youtube.com/watch?v=zZ1L9JD6l0g";
        case 8:
            return "https://www.youtube.com/watch?v=KDdvGZn6Gfs";
        case 9:
            return "https://www.youtube.com/watch?v=PSvYfVGyQfw";
        case 10:
            return "https://www.youtube.com/watch?v=D5uJOpItgNg";
        case 11:
            return "https://www.newgrounds.com/audio/listen/354826";
        case 12:
            return "https://www.youtube.com/watch?v=Pb6KyewC_Vg";
        case 13:
            return "https://www.newgrounds.com/audio/listen/396093";
        case 14:
            return "https://www.newgrounds.com/audio/listen/368392";
        case 15:
            return "https://www.youtube.com/watch?v=afwK743PL2Y";
        case 16:
            return "https://www.youtube.com/watch?v=Z5RufkDHsdM";
        case 17:
            return "https://www.youtube.com/watch?v=fn98711CEoI";
        case 18: 
            /* Redirect Link */
            return "https://www.robtopgames.com/geometricaldominator";
        case 19:
            return "https://www.youtube.com/watch?v=QRGkFkf2r0U";
        case 20:
            return "https://www.youtube.com/watch?v=BuPmq7yjDnI";
        case 21:
            /* Redirect Link */
            return "https://www.robtopgames.com/dash";
        case 22:
            return "https://www.youtube.com/watch?v=fc1tg9qkGyI";
        case 23:
            return "https://www.youtube.com/watch?v=38fPQ5JKQ_Q";
        case 24:
            return "https://www.youtube.com/watch?v=RaJ6Vf2w9hY";
        case 25:
            return "https://www.youtube.com/watch?v=guBpnPY32s0";
        case 26:
            return "https://www.youtube.com/watch?v=2SFOjJxEL7g";
        case 27:
            return "https://www.newgrounds.com/audio/listen/589874";
        case 28:
            return "https://www.youtube.com/watch?v=EWjZOxs87yg";
        case 30:
            return "https://www.youtube.com/watch?v=0MZvDD_sy-w";
        case 31:
            return "https://www.youtube.com/watch?v=f3wAripOdag";
        case 32:
            return "https://www.youtube.com/watch?v=Cu7HaeRHMhM";
        case 33:
            return "https://www.youtube.com/watch?v=MU9wRCGt9h8";
        case 34:
            return "https://www.youtube.com/watch?v=nMDMlIvdqlA";
        case 35:
            return "https://www.youtube.com/watch?v=NvQoY4gTIGU";
        case 36:
            return "https://www.youtube.com/watch?v=B8YkwDbGBr8";
        case 37:
            return "https://www.youtube.com/watch?v=XoLouT7TqZY";
        case 38:
            return "https://www.youtube.com/watch?v=ePv2X_CCaGg";
        case 39:
            return "https://www.youtube.com/watch?v=l6OsF7RlQb4";
        case -1:
            return "https://www.youtube.com/watch?v=5Epc1Beme90";
        default:
            return "";
    }
}

/* TODO Brute-Force For Values */
static int* GLOBAL_VALUE_FOR_SPEEDMOD;

int LevelTools::valueForSpeedMod(int _SpeedMod)
{
  return (_SpeedMod - 1U < 4) ? GLOBAL_VALUE_FOR_SPEEDMOD[_SpeedMod - 1U] : 0x439bca41;
}

bool LevelTools::verifyLevelIntegrity(std::string _levelStr, int _ID)
{
    switch(_ID) {
        case 1:
            return _levelStr == "\xa3\xd5";
        case 2:
            return _levelStr == "\x6a\x3a";
        case 3:
            return _levelStr == "\x6b\x5d";
        case 4:
            return _levelStr == "\x6e\xe3";
        case 5:
            return _levelStr == "\x99\x8a";
        case 6:
            return _levelStr == "\x7f\x16";
        case 7:
            return _levelStr == "\xcd\x61";
        case 8:
            return _levelStr == "";
        case 9:
            return _levelStr == "";
        case 10:
            return _levelStr == "\x17\x48\0";
        case 11:
            return _levelStr == "\x17\x8e\2";
        case 12:
            return _levelStr == "\x11\b\x01";
        case 13:
            return _levelStr == "";
        case 14:
            return _levelStr == "";
        case 15:
            return _levelStr == "";
        case 16:
            return _levelStr == "";
        case 17:
            return _levelStr == "";
        case 18:
            return _levelStr == "\x06";
        case 19:
            return _levelStr == "0GameObject";
        case 20:
            return _levelStr == "ResumePlaytestEv";
        default:
            return true;
    }
}

std::string LevelTools::ytURLForArtist(int artistID)
{
    switch(artistID) {
        case 0:
            return "https://www.youtube.com/user/DJVITechno";
        case 1:
            return "https://www.youtube.com/user/waterflame89";
        case 2:
            return "https://www.youtube.com/user/OcularNebula";
        case 3:
            return "https://www.youtube.com/user/ForeverBoundOfficial";
        case 4:
            return "https://www.youtube.com/user/NGStep";
        case 5:
            return "https://www.youtube.com/c/NateIngalls";
        case 6:
            return "https://www.youtube.com/user/JesseValentineMusic";
        case 7:
            return "https://www.youtube.com/user/MDKOfficialYT";
        case 8:
            return "https://www.youtube.com/user/MrDexarson";
        case 9:
            return "https://www.youtube.com/user/BoomKittyMusic";
        case 10:
            return "https://www.youtube.com/c/Bossfightmusic";
        case 11:
            return "https://www.youtube.com/user/HinkikProductions";
        default:
            return "";
    }
}

