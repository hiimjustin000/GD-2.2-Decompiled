#include <includes.h>

/* TODO Move to enums */
enum class UnlockType {
    UNKNOWN,
    ICON,
    COLOR,
    COLOR2,
    SHIP,
    BALL,
    BIRD,
    DART,
    ROBOT,
    SPIDER,
    SPECIAL,
    DEATH,
    ITEM,
    SWING,
    JETPACK,
    SHIPSTREAK
};

/* NOTE: Seems robtop is using the old libformat library during the 4.x period... */
/* TODO Maybe make a mod where this function is updated with modern tools? */
/* NOTE: This function "achievementForUnlock" may not be super accurate due to fmt::BasicWriter using inline functions and other techniques*/
const char* AchievementManager::achievementForUnlock(int _ID, UnlockType type){
    std::string typeName;
    fmt::BasicWriter<char> writer = fmt::BasicWriter<char>();
    switch(type) {
        case UnlockType::ICON:
            typeName = "icon_";
            break;
        case UnlockType::COLOR:
            typeName = "color_";
            break;
        case UnlockType::COLOR2:
            typeName = "color2_";
            break;
        case UnlockType::SHIP:
            typeName = "ship_";
            break;
        case UnlockType::BALL :
            typeName = "ball_";
            break;
        case UnlockType::BIRD:
            typeName = "bird_";
            break;
        case UnlockType::DART:
            typeName = "dart_";
            break;
        case UnlockType::ROBOT:
            typeName = "robot_";
            break;
        case UnlockType::SPIDER:
            typeName = "spider_";
            break;
        case UnlockType::SPECIAL:
            typeName = "special_";
            break;
        case UnlockType::DEATH:
            typeName = "death_";
            break;
        case UnlockType::ITEM:
            typeName = "item_";
            break;
        case UnlockType::SWING:
            typeName = "swing_";
            break;
        case UnlockType::JETPACK:
            typeName = "jetpack_";
            break;
        case UnlockType::SHIPSTREAK:
            typeName = "shipstreak_";
            break;
        default:
            typeName = " _";
    }
    writer << typeName;
    if (_ID < 10) {
        writer << "0";
    }
    writer << _ID;
    return m_achievementUnlocks->valueForKey(writer.str())->getCString(obj);
}

void AchievementManager::addAchievement(std::string identifier,std::string title,
    std::string achievedDescription,std::string unachievedDescription,std::string icon, int limits)
{
    cocos2d::CCDictionary* dict = cocos2d::CCDictionary::create();
    dict->setObject(cocos2d::CCString::create(identifier), "identifier");
    dict->setObject(cocos2d::CCString::create(title), "title");
    dict->setObject(cocos2d::CCString::create(achievedDescription), "achievedDescription");
    dict->setObject(cocos2d::CCString::create(unachievedDescription), "unachievedDescription");
    dict->setObject(cocos2d::CCString::create(icon), "icon");
    if (limits > 0) {
        dict->setObject(cocos2d::CCString::createWithFormat("%i",limits), "limits");
    }
    m_order++;
    dict->setObject(cocos2d::CCString::createWithFormat("%i", m_order), "order");
    if (limits - 2 < 3) {
        dict->setObject(m_unAchieved, "un");
    }
    m_platformAchievements->setObject(dict, identifier);
}


void AchievementManager::addManualAchievements()
{
    addAchievement("geometry.ach.subzero.level001","Press Start!","Completed \'Press Start\' in Normal mode","Complete \'Press Start\' in Normal mode","icon_143",3);
    addAchievement("geometry.ach.subzero.level002","Nock Em!","Completed \'Nock Em\' in Normal mode","Complete \'Nock Em\' in Normal mode","icon_144",3);
    addAchievement("geometry.ach.subzero.level003","Power Trip!","Completed \'Power Trip\' in Normal mode","Complete \'Power Trip\' in Normal mode","icon_145",3);
    addAchievement("geometry.ach.subzero.coins001","Ultimate Press Start","Collected all 3 Secret Coins on \'Press Start\'","Collect all 3 Secret Coins on \'Press Start\'","icon_146",3);
    addAchievement("geometry.ach.subzero.coins002","Ultimate Nock Em","Collected all 3 Secret Coins on \'Nock Em\'","Collect all 3 Secret Coins on \'Nock Em\'","icon_147",3);
    addAchievement("geometry.ach.subzero.coins003","Ultimate Power Trip","Collected all 3 Secret Coins on \'Power Trip\'","Collect all 3 Secret Coins on \'Power Trip\'","icon_148",3);
    addAchievement("geometry.ach.world.level001b","So it begins...","Completed \'Payload\' in Normal mode","Complete \'Payload\' in Normal mode","color_04",2);
    addAchievement("geometry.ach.world.level002b","Impressive...","Completed \'Beast Mode\' in Normal mode","Complete \'Beast Mode\' in Normal mode","color_05",2);
    addAchievement("geometry.ach.world.level003b","It gets worse...","Completed \'Machina\' in Normal mode","Complete \'Machina\' in Normal mode","color_06",2);
    addAchievement("geometry.ach.world.level004b","You got this!","Completed \'Years\' in Normal mode","Complete \'Years\' in Normal mode","color_07",2);
    addAchievement("geometry.ach.world.level005b","Get to the front!","Completed \'Frontlines\' in Normal mode","Complete \'Frontlines\' in Normal mode","icon_72",2);
    addAchievement("geometry.ach.world.level006b","That was spooky","Completed \'Space Pirates\' in Normal mode","Complete \'Space Pirates\' in Normal mode","color_09",2);
    addAchievement("geometry.ach.world.level007b","Striker!","Completed \'Striker\' in Normal mode","Complete \'Striker\' in Normal mode","color_10",2);
    addAchievement("geometry.ach.world.level008b","Member?","Completed \'Embers\' in Normal mode","Complete \'Embers\' in Normal mode","color_12",2);
    addAchievement("geometry.ach.world.level009b","Round One!","Completed \'Round 1\' in Normal mode","Complete \'Round 1\' in Normal mode","color_13",2);
    addAchievement("geometry.ach.world.level010b","MOOOONSTER!","Completed \'Monster Dance Off\' in Normal mode","Complete \'Monster Dance Off\' in Normal mode","icon_75",2);
    addAchievement("geometry.ach.mdlevel01b","The Seven Seas!","Completed \'The Seven Seas\' in Normal mode","Complete \'The Seven Seas\' in Normal mode","icon_65",4);
    addAchievement("geometry.ach.mdlevel02b","Viking Arena!","Completed \'Viking Arena\' in Normal mode","Complete \'Viking Arena\' in Normal mode","icon_67",4);
    addAchievement("geometry.ach.mdlevel03b","Airborne Robots!","Completed \'Airborne Robots\' in Normal mode","Complete \'Airborne Robots\' in Normal mode","icon_69",4);
    addAchievement("geometry.ach.level01a","Stereo Bump","Completed \'Stereo Madness\' in Practice mode","Complete \'Stereo Madness\' in Practice mode","color_04",1);
    addAchievement("geometry.ach.level01b","Stereo Madness!","Completed \'Stereo Madness\' in Normal mode","Complete \'Stereo Madness\' in Normal mode","icon_05",1);
    addAchievement("geometry.ach.level02a","On my way","Completed \'Back On Track\' in Practice mode","Complete \'Back On Track\' in Practice mode","color_05",1);
    addAchievement("geometry.ach.level02b","Back On Track!","Completed \'Back On Track\' in Normal mode","Complete \'Back On Track\' in Normal mode","icon_06",1);
    addAchievement("geometry.ach.level03a","Polarbear","Completed \'Polargeist\' in Practice mode","Complete \'Polargeist\' in Practice mode","color_06",1);
    addAchievement("geometry.ach.level03b","Polargeist!","Completed \'Polargeist\' in Normal mode","Complete \'Polargeist\' in Normal mode","icon_07",1);
    addAchievement("geometry.ach.level04a","Dehydrated","Completed \'Dry Out\' in Practice mode","Complete \'Dry Out\' in Practice mode","color_07",1);
    addAchievement("geometry.ach.level04b","Dry Out!","Completed \'Dry Out\' in Normal mode","Complete \'Dry Out\' in Normal mode","icon_08",1);
    addAchievement("geometry.ach.level05a","All your base...","Completed \'Base After Base\' in Practice mode","Complete \'Base After Base\' in Practice mode","color_08",1);
    addAchievement("geometry.ach.level05b","Base After Base!","Completed \'Base After Base\' in Normal mode","Complete \'Base After Base\' in Normal mode","icon_09",1);
    addAchievement("geometry.ach.level06a","Hold on","Completed \'Cant Let Go\' in Practice mode","Complete \'Cant Let Go\' in Practice mode","color_09",1);
    addAchievement("geometry.ach.level06b","Cant Let Go!","Completed \'Cant Let Go\' in Normal mode","Complete \'Cant Let Go\' in Normal mode","icon_10",1);
    addAchievement("geometry.ach.level07a","Hop Hop...","Completed \'Jumper\' in Practice mode","Complete \'Jumper\' in Practice mode","color_10",1);
    addAchievement("geometry.ach.level07b","Jumper!","Completed \'Jumper\' in Normal mode","Complete \'Jumper\' in Normal mode","icon_11",1);
    addAchievement("geometry.ach.level08a","Tick Tock","Completed \'Time Machine\' in Practice mode","Complete \'Time Machine\' in Practice mode","color_12",1);
    addAchievement("geometry.ach.level08b","Time Machine!","Completed \'Time Machine\' in Normal mode","Complete \'Time Machine\' in Normal mode","icon_14",1);
    addAchievement("geometry.ach.level09a","Loops","Completed \'Cycles\' in Practice mode","Complete \'Cycles\' in Practice mode","icon_15",1);
    addAchievement("geometry.ach.level09b","Cycles!","Completed \'Cycles\' in Normal mode","Complete \'Cycles\' in Normal mode","icon_16",1);
    addAchievement("geometry.ach.level10a","yStep","Completed \'xStep\' in Practice mode","Complete \'xStep\' in Practice mode","icon_17",1);
    addAchievement("geometry.ach.level10b","xStep!","Completed \'xStep\' in Normal mode","Complete \'xStep\' in Normal mode","icon_18",1);
    addAchievement("geometry.ach.level11a","Funky","Completed \'Clutterfunk\' in Practice mode","Complete \'Clutterfunk\' in Practice mode","color_13",1);
    addAchievement("geometry.ach.level11b","Clutterfunk!","Completed \'Clutterfunk\' in Normal mode","Complete \'Clutterfunk\' in Normal mode","ship_02",1);
    addAchievement("geometry.ach.level12a","Theory of Something","Completed \'Theory of Everything\' in Practice mode","Complete \'Theory of Everything\' in Practice mode","color_14",1);
    addAchievement("geometry.ach.level12b","Theory of Everything!","Completed \'Theory of Everything\' in Normal mode","Complete \'Theory of Everything\' in Normal mode","icon_27",1);
    addAchievement("geometry.ach.level13a","Electro Time","Completed \'Electroman Adventures\' in Practice mode","Complete \'Electroman Adventures\' in Practice mode","color_16",1);
    addAchievement("geometry.ach.level13b","Electroman Adventures!","Completed \'Electroman Adventures\' in Normal mode","Complete \'Electroman Adventures\' in Normal mode","ship_09",1);
    addAchievement("geometry.ach.level14a","Clubbin","Completed \'Clubstep\' in Practice mode","Complete \'Clubstep\' in Practice mode","bird_02",1);
    addAchievement("geometry.ach.level14b","Clubstep!","Completed \'Clubstep\' in Normal mode","Complete \'Clubstep\' in Normal mode","color2_15",1);
    addAchievement("geometry.ach.level15a","Electromaniac","Completed \'Electrodynamix\' in Practice mode","Complete \'Electrodynamix\' in Practice mode","color_17",1);
    addAchievement("geometry.ach.level15b","Electrodynamix!","Completed \'Electrodynamix\' in Normal mode","Complete \'Electrodynamix\' in Normal mode","icon_35",1);
    addAchievement("geometry.ach.level16a","Hexagonest","Completed \'Hexagon Force\' in Practice mode","Complete \'Hexagon Force\' in Practice mode","color_18",1);
    addAchievement("geometry.ach.level16b","Hexagon Force!","Completed \'Hexagon Force\' in Normal mode","Complete \'Hexagon Force\' in Normal mode","icon_42",1);
    addAchievement("geometry.ach.level17a","Blast Power","Completed \'Blast Processing\' in Practice mode","Complete \'Blast Processing\' in Practice mode","color_20",1);
    addAchievement("geometry.ach.level17b","Blast Processing!","Completed \'Blast Processing\' in Normal mode","Complete \'Blast Processing\' in Normal mode","icon_44",1);
    addAchievement("geometry.ach.level18a","Second Theory","Completed \'Theory of Everything 2\' in Practice mode","Complete \'Theory of Everything 2\' in Practice mode","color_21",1);
    addAchievement("geometry.ach.level18b","Theory of Everything 2!","Completed \'Theory of Everything 2\' in Normal mode","Complete \'Theory of Everything 2\' in Normal mode","icon_45",1);
    addAchievement("geometry.ach.level19a","Geometry Warrior","Completed \'Geometrical Dominator\' in Practice mode","Complete \'Geometrical Dominator\' in Practice mode","color_24",1);
    addAchievement("geometry.ach.level19b","Geometrical Dominator!","Completed \'Geometrical Dominator\' in Normal mode","Complete \'Geometrical Dominator\' in Normal mode","robot_03",1);
    addAchievement("geometry.ach.level20a","Living Open","Completed \'Deadlocked\' in Practice mode","Complete \'Deadlocked\' in Practice mode","color_25",1);
    addAchievement("geometry.ach.level20b","Deadlocked!","Completed \'Deadlocked\' in Normal mode","Complete \'Deadlocked\' in Normal mode","robot_05",1);
    addAchievement("geometry.ach.level21a","Fingerdash","Completed \'Fingerdash\' in Practice mode","Complete \'Fingerdash\' in Practice mode","color_29",1);
    addAchievement("geometry.ach.level21b","Fingerdash!","Completed \'Fingerdash\' in Normal mode","Complete \'Fingerdash\' in Normal mode","icon_74",1);
    addAchievement("geometry.ach.level22a","Eat. Sleep. Dash. Repeat.","Completed \'Dash\' in Practice mode","Complete \'Dash\' in Practice mode","color_63",1);
    addAchievement("geometry.ach.level22b","Dash!","Completed \'Dash\' in Normal mode","Complete \'Dash\' in Normal mode","spider_38",1);
    addAchievement("geometry.ach.tower01","The Tower","Completed Tower level 1","Complete Tower level 1","icon_240",1);
    addAchievement("geometry.ach.tower02","The Sewers","Completed Tower level 2","Complete Tower level 2","ship_75",1);
    addAchievement("geometry.ach.tower03","The Cellar","Completed Tower level 3","Complete Tower level 3","icon_222",1);
    addAchievement("geometry.ach.tower04","The Secret Hollow","Completed Tower level 4","Complete Tower level 4","jetpack_02",1);
    addAchievement("geometry.ach.tower01Coin","I See You","Collected all 3 Secret Coins on Tower level 1","Collect all 3 Secret Coins on Tower level 1","icon_233",1);
    addAchievement("geometry.ach.tower02Coin","Ahar, matey!","Collected all 3 Secret Coins on Tower level 2","Collect all 3 Secret Coins on Tower level 2","robot_31",1);
    addAchievement("geometry.ach.tower03Coin","Well Met!","Collected all 3 Secret Coins on Tower level 3","Collect all 3 Secret Coins on Tower level 3","ball_104",1);
    addAchievement("geometry.ach.tower04Coin","INTRUSION DETECTED","Collected all 3 Secret Coins on Tower level 4","Collect all 3 Secret Coins on Tower level 4","icon_205",1);
    addAchievement("geometry.ach.demon01","Reflex Champion","Completed a Demon difficulty level in Normal mode","Complete a Demon difficulty level in Normal mode","icon_19",1);
    addAchievement("geometry.ach.demon02","Demon Chaser","Completed 2 Demon difficulty levels in Normal mode","Complete 2 Demon difficulty levels in Normal mode","icon_20",1);
    addAchievement("geometry.ach.demon03","The One","Completed 3 Demon difficulty levels in Normal mode","Complete 3 Demon difficulty levels in Normal mode","icon_21",1);
    addAchievement("geometry.ach.demon04","Demon Master","Completed 4 Demon difficulty levels in Normal mode","Complete 4 Demon difficulty levels in Normal mode","icon_22",1);
    addAchievement("geometry.ach.demon05","Demonic Guardian","Completed 5 Demon difficulty levels in Normal mode","Complete 5 Demon difficulty levels in Normal mode","ship_03",1);
    addAchievement("geometry.ach.demon06","Demonic Overmind","Completed 10 Demon difficulty levels in Normal mode","Complete 10 Demon difficulty levels in Normal mode","ship_06",1);
    addAchievement("geometry.ach.demon07","Master of Timing","Completed 15 Demon difficulty levels in Normal mode","Complete 15 Demon difficulty levels in Normal mode","ship_08",1);
    addAchievement("geometry.ach.demon08","Unstoppable!","Completed 20 Demon difficulty levels in Normal mode","Complete 20 Demon difficulty levels in Normal mode","ball_05",1);
    addAchievement("geometry.ach.demon09","Demolicious!","Completed 30 Demon difficulty levels in Normal mode","Complete 30 Demon difficulty levels in Normal mode","icon_37",1);
    addAchievement("geometry.ach.demon10","Give me a CHALLENGE!","Completed 40 Demon difficulty levels in Normal mode","Complete 40 Demon difficulty levels in Normal mode","ball_10",1);
    addAchievement("geometry.ach.demon11","Grim Reaper","Completed 50 Demon difficulty levels in Normal mode","Complete 50 Demon difficulty levels in Normal mode","bird_15",1);
    addAchievement("geometry.ach.demon12","You fear nothing","Completed 60 Demon difficulty levels in Normal mode","Complete 60 Demon difficulty levels in Normal mode","ship_35",1);
    addAchievement("geometry.ach.demon13","Like the devil","Completed 70 Demon difficulty levels in Normal mode","Complete 70 Demon difficulty levels in Normal mode","robot_28",1);
    addAchievement("geometry.ach.demon14","Speed Demon","Completed 80 Demon difficulty levels in Normal mode","Complete 80 Demon difficulty levels in Normal mode","color_53",0);
    addAchievement("geometry.ach.demon15","9 circles of hell","Completed 90 Demon difficulty levels in Normal mode","Complete 90 Demon difficulty levels in Normal mode","dart_64",1);
    addAchievement("geometry.ach.demon16","Is it over yet?","Completed 100 Demon difficulty levels in Normal mode","Complete 100 Demon difficulty levels in Normal mode","ball_45",1);
    addAchievement("geometry.ach.demon17","Supersonic speed","Completed 120 Demon difficulty levels in Normal mode","Complete 120 Demon difficulty levels in Normal mode","swing_03",1);
    addAchievement("geometry.ach.demon18","Straight fly master","Completed 140 Demon difficulty levels in Normal mode","Complete 140 Demon difficulty levels in Normal mode","color_62",0);
    addAchievement("geometry.ach.demon19","RIP AND TEAR","Completed 160 Demon difficulty levels in Normal mode","Complete 160 Demon difficulty levels in Normal mode","robot_65",1);
    addAchievement("geometry.ach.demon20","Gotta beat them all","Completed 180 Demon difficulty levels in Normal mode","Complete 180 Demon difficulty levels in Normal mode","icon_446",1);
    addAchievement("geometry.ach.demon21","Deal with the devil","Completed 200 Demon difficulty levels in Normal mode","Complete 200 Demon difficulty levels in Normal mode","robot_53",1);
    addAchievement("geometry.ach.demon22","This is a nightmare","Completed 225 Demon difficulty levels in Normal mode","Complete 225 Demon difficulty levels in Normal mode","icon_270",1);
    addAchievement("geometry.ach.demon23","The Chosen One","Completed 250 Demon difficulty levels in Normal mode","Complete 250 Demon difficulty levels in Normal mode","spider_46",1);
    addAchievement("geometry.ach.demon24","What a bloodbath","Completed 300 Demon difficulty levels in Normal mode","Complete 300 Demon difficulty levels in Normal mode","icon_308",1);
    addAchievement("geometry.ach.demon25","Tarsorado Demon","Completed 350 Demon difficulty levels in Normal mode","Complete 350 Demon difficulty levels in Normal mode","ship_123",1);
    addAchievement("geometry.ach.demon26","Insatiable bloodlust","Completed 400 Demon difficulty levels in Normal mode","Complete 400 Demon difficulty levels in Normal mode","dart_37",1);
    addAchievement("geometry.ach.demon27","GG! :)","Completed 500 Demon difficulty levels in Normal mode","Complete 500 Demon difficulty levels in Normal mode","icon_459",1);
    addAchievement("geometry.ach.mdcoin01","Ultimate Seven Seas","Collected all 3 Secret Coins on \'The Seven Seas\'","Collect all 3 Secret Coins on \'The Seven Seas\'","icon_66",4);
    addAchievement("geometry.ach.mdcoin02","Ultimate Viking Arena","Collected all 3 Secret Coins on \'Viking Arena\'","Collect all 3 Secret Coins on \'Viking Arena\'","icon_68",4);
    addAchievement("geometry.ach.mdcoin03","Ultimate Airborne Robots","Collected all 3 Secret Coins on \'Airborne Robots\'","Collect all 3 Secret Coins on \'Airborne Robots\'","icon_70",4);
    addAchievement("geometry.ach.demoncoin01","Ultimate Clubstep","Collected all 3 Secret Coins on \'Clubstep\'","Collect all 3 Secret Coins on \'Clubstep\'","bird_14",1);
    addAchievement("geometry.ach.demoncoin02","Ultimate TOE2","Collected all 3 Secret Coins on \'Theory of Everything 2\'","Collect all 3 Secret Coins on \'Theory of Everything 2\'","icon_60",1);
    addAchievement("geometry.ach.demoncoin03","Ultimate Deadlocked","Collected all 3 Secret Coins on \'Deadlocked\'","Collect all 3 Secret Coins on \'Deadlocked\'","icon_59",1);
    addAchievement("geometry.ach.stars01","Oh, Shiny!","Collected 100 Stars","Collect 100 Stars","icon_23",0);
    addAchievement("geometry.ach.stars02","More Stars!","Collected 200 Stars","Collect 200 Stars","icon_24",0);
    addAchievement("geometry.ach.stars03","Star Maniac","Collected 300 Stars","Collect 300 Stars","icon_25",0);
    addAchievement("geometry.ach.stars04","Master Collector","Collected 400 Stars","Collect 400 Stars","icon_26",0);
    addAchievement("geometry.ach.stars05","Epic Collector","Collected 500 Stars","Collect 500 Stars","ship_04",0);
    addAchievement("geometry.ach.stars06","Epic Master Collector","Collected 600 Stars","Collect 600 Stars","ship_05",0);
    addAchievement("geometry.ach.stars07","Star Factory","Collected 700 Stars","Collect 700 Stars","ship_07",0);
    addAchievement("geometry.ach.stars08","Starshine","Collected 800 Stars","Collect 800 Stars","icon_28",0);
    addAchievement("geometry.ach.stars09","All MINE!","Collected 900 Stars","Collect 900 Stars","icon_29",0);
    addAchievement("geometry.ach.stars10","MORE SHINY!!!","Collected 1000 Stars","Collect 1000 Stars","icon_30",0);
    addAchievement("geometry.ach.stars11","Was that all of them?","Collected 1500 Stars","Collect 1500 Stars","ship_18",0);
    addAchievement("geometry.ach.stars12","Knock knock. Who\'s there? STARS!","Collected 2000 Stars","Collect 2000 Stars","ball_09",0);
    addAchievement("geometry.ach.stars13","These are pretty warm...","Collected 2500 Stars","Collect 2500 Stars","dart_12",0);
    addAchievement("geometry.ach.stars14","They are REALLY warm!","Collected 3000 Stars","Collect 3000 Stars","icon_61",0);
    addAchievement("geometry.ach.stars15","IT BURNS!!","Collected 3500 Stars","Collect 3500 Stars","ship_19",0);
    addAchievement("geometry.ach.stars16","GAAAAAAAAAH!","Collected 4000 Stars","Collect 4000 Stars","dart_09",0);
    addAchievement("geometry.ach.stars17","More Star Achievements?","Collected 4500 Stars","Collect 4500 Stars","dart_15",0);
    addAchievement("geometry.ach.stars18","You want me to collect 5000!?","Collected 5000 Stars","Collect 5000 Stars","color_28",0);
    addAchievement("geometry.ach.stars19","I should sell these","Collected 5500 Stars","Collect 5500 Stars","icon_82",0);
    addAchievement("geometry.ach.stars20","Why so many?","Collected 6000 Stars","Collect 6000 Stars","ball_27",0);
    addAchievement("geometry.ach.stars21","No Stars for You!","Collected 6500 Stars","Collect 6500 Stars","color_34",0);
    addAchievement("geometry.ach.stars22","All Stars Are My Stars","Collected 7000 Stars","Collect 7000 Stars","ship_30",0);
    addAchievement("geometry.ach.stars23","This is the Last Star Achievement","Collected 7500 Stars","Collect 7500 Stars","icon_100",0);
    addAchievement("geometry.ach.stars24","Just Kidding, There Are More","Collected 8000 Stars","Collect 8000 Stars","spider_04",0);
    addAchievement("geometry.ach.stars25","I Think I Got All the Stars","Collected 9000 Stars","Collect 9000 Stars","icon_83",0);
    addAchievement("geometry.ach.stars26","Nope, Found More Over There","Collected 10000 Stars","Collect 10000 Stars","robot_08",0);
    addAchievement("geometry.ach.stars27","But Wait, There\'s Even More!","Collected 12000 Stars","Collect 12000 Stars","swing_18",0);
    addAchievement("geometry.ach.stars28","PLEASE NO MORE!!!!!","Collected 14000 Stars","Collect 14000 Stars","dart_51",0);
    addAchievement("geometry.ach.stars29","There\'s Always More, My Friend","Collected 16000 Stars","Collect 16000 Stars","ball_80",0);
    addAchievement("geometry.ach.stars30","Aim for the stars","Collected 18000 Stars","Collect 18000 Stars","swing_37",0);
    addAchievement("geometry.ach.stars31","Wish Come True!","Collected 20000 Stars","Collect 20000 Stars","spider_19",0);
    addAchievement("geometry.ach.stars32","The Stars Align","Collected 22500 Stars","Collect 22500 Stars","ship_122",0);
    addAchievement("geometry.ach.stars33","SUPERSTAR","Collected 25000 Stars","Collect 25000 Stars","bird_73",0);
    addAchievement("geometry.ach.moons01","One small step for player","Collected 100 Moons","Collect 100 Moons","swing_26",0);
    addAchievement("geometry.ach.moons02","Houston, we have a problem","Collected 200 Moons","Collect 200 Moons","jetpack_03",0);
    addAchievement("geometry.ach.moons03","Is this the moon?","Collected 300 Moons","Collect 300 Moons","color_86",0);
    addAchievement("geometry.ach.moons04","This is the moon alright","Collected 400 Moons","Collect 400 Moons","icon_207",0);
    addAchievement("geometry.ach.moons05","Dark side of the moon?","Collected 500 Moons","Collect 500 Moons","bird_38",0);
    addAchievement("geometry.ach.moons06","Nope, just the moon","Collected 600 Moons","Collect 600 Moons","ball_111",0);
    addAchievement("geometry.ach.moons07","Moons are like this?","Collected 700 Moons","Collect 700 Moons","color2_65",0);
    addAchievement("geometry.ach.moons08","They told me it was made of cheese","Collected 800 Moons","Collect 800 Moons","icon_158",0);
    addAchievement("geometry.ach.moons09","Fly me to the moon","Collected 900 Moons","Collect 900 Moons","robot_38",0);
    addAchievement("geometry.ach.moons10","You\'re too used to stars","Collected 1000 Moons","Collect 1000 Moons","swing_21",0);
    addAchievement("geometry.ach.moons11","Maybe I like stars more","Collected 1500 Moons","Collect 1500 Moons","icon_199",0);
    addAchievement("geometry.ach.moons12","Okay, when do you not get stars?","Collected 2000 Moons","Collect 2000 Moons","ball_94",0);
    addAchievement("geometry.ach.moons13","Once in a blue moon","Collected 2500 Moons","Collect 2500 Moons","jetpack_04",0);
    addAchievement("geometry.ach.moons14","Or on a full moon","Collected 3000 Moons","Collect 3000 Moons","color_91",0);
    addAchievement("geometry.ach.moons15","The werewolves are out","Collected 3500 Moons","Collect 3500 Moons","ship_70",0);
    addAchievement("geometry.ach.moons16","So moons are the new thing","Collected 4000 Moons","Collect 4000 Moons","icon_268",0);
    addAchievement("geometry.ach.moons17","I\'ve heard of a moon before","Collected 4500 Moons","Collect 4500 Moons","dart_41",0);
    addAchievement("geometry.ach.moons18","Death Moon","Collected 5000 Moons","Collect 5000 Moons","spider_39",0);
    addAchievement("geometry.ach.moons19","It\'s gotta be Platformer","Collected 5500 Moons","Collect 5500 Moons","bird_144",0);
    addAchievement("geometry.ach.moons20","Yeah, Platformer is my thing","Collected 6000 Moons","Collect 6000 Moons","color_63",0);
    addAchievement("geometry.ach.moons21","Moons are kinda neat","Collected 6500 Moons","Collect 6500 Moons","icon_457",0);
    addAchievement("geometry.ach.moons22","I like moons","Collected 7000 Moons","Collect 7000 Moons","bird_75",0);
    addAchievement("geometry.ach.moons23","Moons > Stars","Collected 7500 Moons","Collect 7500 Moons","ball_118",0);
    addAchievement("geometry.ach.moons24","I love moons!","Collected 8000 Moons","Collect 8000 Moons","ship_105",0);
    addAchievement("geometry.ach.moons25","We are going to steal the moon","Collected 9000 Moons","Collect 9000 Moons","swing_38",0);
    addAchievement("geometry.ach.moons26","One giant leap for mankind","Collected 10000 Moons","Collect 10000 Moons","ball_62",0);
    addAchievement("geometry.ach.coins01","Coins?!","Collected 5 Secret Coins","Collect 5 Secret Coins","icon_31",1);
    addAchievement("geometry.ach.coins02","Maybe behind that block?","Collected 10 Secret Coins","Collect 10 Secret Coins","ball_02",1);
    addAchievement("geometry.ach.coins03","I.. Need... MORE!","Collected 15 Secret Coins","Collect 15 Secret Coins","color2_16",1);
    addAchievement("geometry.ach.coins04","We wants it!","Collected 20 Secret Coins","Collect 20 Secret Coins","bird_03",1);
    addAchievement("geometry.ach.coins05","We needs it!","Collected 25 Secret Coins","Collect 25 Secret Coins","icon_32",1);
    addAchievement("geometry.ach.coins06","Must have the precious","Collected 30 Secret Coins","Collect 30 Secret Coins","color_15",1);
    addAchievement("geometry.ach.coins07","They stole it from us!","Collected 35 Secret Coins","Collect 35 Secret Coins","ball_03",1);
    addAchievement("geometry.ach.coins08","Where is it?! Where is it?!","Collected 40 Secret Coins","Collect 40 Secret Coins","icon_34",1);
    addAchievement("geometry.ach.coins09","Thief, thief, thief!","Collected 45 Secret Coins","Collect 45 Secret Coins","bird_04",1);
    addAchievement("geometry.ach.coins10","My Precious...","Collected 50 Secret Coins","Collect 50 Secret Coins","ball_04",1);
    addAchievement("geometry.ach.coins11","There\'s more!?","Collected 55 Secret Coins","Collect 55 Secret Coins","ship_14",1);
    addAchievement("geometry.ach.coins12","Found it under a rock!","Collected 60 Secret Coins","Collect 60 Secret Coins","icon_38",1);
    addAchievement("geometry.ach.coins13","Not so secret","Collected 65 Secret Coins","Collect 65 Secret Coins","bird_06",1);
    addAchievement("geometry.ach.coins14","Nothing is secret!","Collected 70 Secret Coins","Collect 70 Secret Coins","ball_06",1);
    addAchievement("geometry.ach.coins15","Finders Keepers!","Collected 75 Secret Coins","Collect 75 Secret Coins","ship_12",1);
    addAchievement("geometry.ach.coins16","The Golden Rule","Collected 80 Secret Coins","Collect 80 Secret Coins","bird_07",1);
    addAchievement("geometry.ach.coins17","Robin Hood","Collected 85 Secret Coins","Collect 85 Secret Coins","bird_08",1);
    addAchievement("geometry.ach.coins18","The Finder","Collected 90 Secret Coins","Collect 90 Secret Coins","ship_16",1);
    addAchievement("geometry.ach.coins19","Tax Collector","Collected 95 Secret Coins","Collect 95 Secret Coins","icon_43",1);
    addAchievement("geometry.ach.coins20","The King\'s Vault","Collected 100 Secret Coins","Collect 100 Secret Coins","bird_09",1);
    addAchievement("geometry.ach.coins21","These are pretty heavy","Collected 105 Secret Coins","Collect 105 Secret Coins","ball_14",1);
    addAchievement("geometry.ach.coins22","Where do I even put this?","Collected 110 Secret Coins","Collect 110 Secret Coins","icon_56",1);
    addAchievement("geometry.ach.coins23","Seriously, enough!","Collected 115 Secret Coins","Collect 115 Secret Coins","ship_24",1);
    addAchievement("geometry.ach.coins24","Leave some for the rest of us!","Collected 120 Secret Coins","Collect 120 Secret Coins","bird_18",1);
    addAchievement("geometry.ach.coins25","Insatiable Greed","Collected 130 Secret Coins","Collect 130 Secret Coins","icon_88",1);
    addAchievement("geometry.ach.coins26","Getting rich","Collected 140 Secret Coins","Collect 140 Secret Coins","dart_36",1);
    addAchievement("geometry.ach.coins27","Never enough with you...","Collected 150 Secret Coins","Collect 150 Secret Coins","swing_34",1);
    addAchievement("geometry.ach.coins28","Ultimate Coin","Collected 160 Secret Coins","Collect 160 Secret Coins","ship_88",1);
    addAchievement("geometry.ach.usercoins01","What are those!?","Collected your first User Coin!","Collect 1 User Coins","dart_02",0);
    addAchievement("geometry.ach.usercoins02","The journey begins...","Collected 10 User Coins","Collect 10 User Coins","icon_49",0);
    addAchievement("geometry.ach.usercoins03","I can\'t stop!","Collected 20 User Coins","Collect 20 User Coins","dart_04",0);
    addAchievement("geometry.ach.usercoins04","Mom, get the camera!!!","Collected 30 User Coins","Collected 30 User Coins","ship_25",0);
    addAchievement("geometry.ach.usercoins05","I feel rich!","Collected 40 User Coins","Collected 40 User Coins","ball_16",0);
    addAchievement("geometry.ach.usercoins06","What to buy...","Collected 50 User Coins","Collect 50 User Coins","bird_13",0);
    addAchievement("geometry.ach.usercoins07","i\'ll get that for you","Collected 60 User Coins","Collect 60 User Coins","icon_53",0);
    addAchievement("geometry.ach.usercoins08","Piece of cake","Collected 70 User Coins","Collect 70 User Coins","dart_06",0);
    addAchievement("geometry.ach.usercoins09","We\'re gonna need a bigger boat","Collected 80 User Coins","Collect 80 User Coins","ship_23",0);
    addAchievement("geometry.ach.usercoins10","Got coins?","Collected 90 User Coins","Collect 90 User Coins","ball_17",0);
    addAchievement("geometry.ach.usercoins11","So... greed much?","Collected 100 User Coins","Collect 100 User Coins","robot_06",0);
    addAchievement("geometry.ach.usercoins12","MAX COINS!","Collected 110 User Coins","Collected 110 User Coins","icon_54",0);
    addAchievement("geometry.ach.usercoins13","Just kidding...","Collected 120 User Coins","Collect 120 User Coins","dart_07",0);
    addAchievement("geometry.ach.usercoins14","I think there\'s one left","Collected 130 User Coins","Collect 130 User Coins","ship_21",0);
    addAchievement("geometry.ach.usercoins15","Where did you get those?","Collected 140 User Coins","Collect 140 User Coins","ball_11",0);
    addAchievement("geometry.ach.usercoins16","So many shinies...","Collected 150 User Coins","Collect 150 User Coins","icon_52",0);
    addAchievement("geometry.ach.usercoins17","Power level increasing","Collected 160 User Coins","Collect 160 User Coins","bird_17",0);
    addAchievement("geometry.ach.usercoins18","Ultra mega coin catcher","Collected 170 User Coins","Collect 170 User Coins","dart_10",0);
    addAchievement("geometry.ach.usercoins19","Something that rhymes with coin","Collected 180 User Coins","Collect 180 User Coins","ship_22",0);
    addAchievement("geometry.ach.usercoins20","Will you ever be satisfied?","Collected 190 User Coins","Collect 190 User Coins","ball_18",0);
    addAchievement("geometry.ach.usercoins21","Level up! Ultra Greedy...","Collected 200 User Coins","Collect 200 User Coins","robot_04",0);
    addAchievement("geometry.ach.usercoins22","Something funny about coins","Collected 225 User Coins","Collect 225 User Coins","icon_99",0);
    addAchievement("geometry.ach.usercoins23","Who makes these?","Collected 250 User Coins","Collect 250 User Coins","color_30",0);
    addAchievement("geometry.ach.usercoins24","More coins, give reward","Collected 300 User Coins","Collect 300 User Coins","spider_08",0);
    addAchievement("geometry.ach.usercoins25","Much coin, very wow","Collected 350 User Coins","Collect 350 User Coins","color_32",0);
    addAchievement("geometry.ach.usercoins26","Who has this many coins?","Collected 425 User Coins","Collect 425 User Coins","ball_29",0);
    addAchievement("geometry.ach.usercoins27","Enough is enough","Collected 500 User Coins","Collect 500 User Coins","icon_93",0);
    addAchievement("geometry.ach.usercoins28","Stop collecting coins","Collected 600 User Coins","Collect 600 User Coins","dart_22",0);
    addAchievement("geometry.ach.usercoins29","Y u take all coin?","Collected 700 User Coins","Collect 700 User Coins","robot_15",0);
    addAchievement("geometry.ach.usercoins30","Can I have some?","Collected 800 User Coins","Collect 800 User Coins","ship_33",0);
    addAchievement("geometry.ach.usercoins31","Congratulations, you have them all!","Collected 900 User Coins","Collect 900 User Coins","ball_28",0);
    addAchievement("geometry.ach.usercoins32","You have them all again! :O","Collected 1000 User Coins","Collect 1000 User Coins","bird_28",0);
    addAchievement("geometry.ach.usercoins33","Just kidding again!","Collected 1200 User Coins","Collect 1200 User Coins","swing_25",0);
    addAchievement("geometry.ach.usercoins34","The other side of the coin","Collected 1400 User Coins","Collect 1400 User Coins","color_59",0);
    addAchievement("geometry.ach.usercoins35","Just a coin toss away","Collected 1600 User Coins","Collect 1600 User Coins","icon_325",0);
    addAchievement("geometry.ach.usercoins36","Almighty dollar","Collected 1800 User Coins","Collect 1800 User Coins","dart_66",0);
    addAchievement("geometry.ach.usercoins37","Have fun, kid!","Collected 2000 User Coins","Collect 2000 User Coins","ship_134",0);
    addAchievement("geometry.ach.usercoins38","Nickel and dime","Collected 2300 User Coins","Collect 2300 User Coins","icon_284",0);
    addAchievement("geometry.ach.usercoins39","Heads or tails","Collected 2600 User Coins","Collect 2600 User Coins","spider_21",0);
    addAchievement("geometry.ach.usercoins40","Swag","Collected 3000 User Coins","Collect 3000 User Coins","robot_41",0);
    addAchievement("geometry.ach.mappacks01","Jump, Forrest, jump","Completed a Map Pack","Complete a Map Pack","icon_33",1);
    addAchievement("geometry.ach.mappacks02","Failure is not an option","Completed 5 Map Packs","Complete 5 Map Packs","ship_10",1);
    addAchievement("geometry.ach.mappacks03","Map Packer","Completed 10 Map Packs","Complete 10 Map Packs","special_02",1);
    addAchievement("geometry.ach.mappacks04","Pack it up","Completed 15 Map Packs","Complete 15 Map Packs","ship_11",1);
    addAchievement("geometry.ach.mappacks05","Package Complete","Completed 20 Map Packs","Complete 20 Map Packs","ball_07",1);
    addAchievement("geometry.ach.mappacks06","You pack, I complete","Completed 25 Map Packs","Complete 25 Map Packs","ball_08",1);
    addAchievement("geometry.ach.mappacks07","I R Unstoppable!","Completed 30 Map Packs","Complete 30 Map Packs","bird_10",1);
    addAchievement("geometry.ach.mappacks08","Hah, you call that a pack?","Completed 35 Map Packs","Complete 35 Map Packs","icon_58",1);
    addAchievement("geometry.ach.mappacks09","40, not bad...","Completed 40 Map Packs","Complete 40 Map Packs","ball_15",1);
    addAchievement("geometry.ach.mappacks10","Ha! What now?","Completed 45 Map Packs","Complete 45 Map Packs","dart_11",1);
    addAchievement("geometry.ach.gauntlets01","A new beginning","Completed a Gauntlet","Complete a Gauntlet","icon_242",1);
    addAchievement("geometry.ach.gauntlets02","The Infinity Gauntlet","Completed 5 Gauntlets","Complete 5 Gauntlets","bird_37",1);
    addAchievement("geometry.ach.gauntlets03","Throw down the gauntlet","Completed 10 Gauntlets","Complete 10 Gauntlets","color_89",1);
    addAchievement("geometry.ach.gauntlets04","2.1 Complete","Completed 15 Gauntlets","Complete 15 Gauntlets","dart_74",1);
    addAchievement("geometry.ach.daily01","What a day...","Completed a Daily level in Normal mode","Complete a Daily level in Normal mode","icon_267",0);
    addAchievement("geometry.ach.daily02","Dashing on a daily basis","Completed 25 Daily levels in Normal mode","Complete 25 Daily levels in Normal mode","swing_22",0);
    addAchievement("geometry.ach.daily03","My daily bread","Completed 50 Daily levels in Normal mode","Complete 50 Daily levels in Normal mode","color_58",0);
    addAchievement("geometry.ach.daily04","A level a day keeps the doctor away","Completed 100 Daily levels in Normal mode","Complete 100 Daily levels in Normal mode","icon_403",0);
    addAchievement("geometry.ach.daily05","Hello daily chat","Completed 150 Daily levels in Normal mode","Complete 150 Daily levels in Normal mode","spider_43",0);
    addAchievement("geometry.ach.daily06","Do you sleep?","Completed 250 Daily levels in Normal mode","Complete 250 Daily levels in Normal mode","bird_91",0);
    addAchievement("geometry.ach.daily07","Happy New Year!","Completed 365 Daily levels in Normal mode","Complete 365 Daily levels in Normal mode","icon_396",0);
    addAchievement("geometry.ach.diamonds01","New shinies!?!","Collected 100 Diamonds","Collect 100 Diamonds","color_31",0);
    addAchievement("geometry.ach.diamonds02","Sparkle sparkle","Collected 250 Diamonds","Collect 250 Diamonds","icon_87",0);
    addAchievement("geometry.ach.diamonds03","This is addictive","Collected 500 Diamonds","Collect 500 Diamonds","robot_11",0);
    addAchievement("geometry.ach.diamonds04","DIAMONDS","Collected 1000 Diamonds","Collect 1000 Diamonds","color_38",0);
    addAchievement("geometry.ach.diamonds05","Can\'t stop my shine","Collected 1500 Diamonds","Collect 1500 Diamonds","dart_19",0);
    addAchievement("geometry.ach.diamonds06","One for you, ten for me","Collected 2000 Diamonds","Collect 2000 Diamonds","icon_101",0);
    addAchievement("geometry.ach.diamonds07","How many can I carry?","Collected 2500 Diamonds","Collect 2500 Diamonds","ship_32",0);
    addAchievement("geometry.ach.diamonds08","House of Diamonds","Collected 3000 Diamonds","Collect 3000 Diamonds","bird_24",0);
    addAchievement("geometry.ach.diamonds09","Diamond Castle","Collected 4000 Diamonds","Collect 4000 Diamonds","dart_17",0);
    addAchievement("geometry.ach.diamonds10","Diamond Master","Collected 5000 Diamonds","Collect 5000 Diamonds","death_10",0);
    addAchievement("geometry.ach.diamonds11","Diamond Grandmaster","Collected 6000 Diamonds","Collect 6000 Diamonds","icon_159",0);
    addAchievement("geometry.ach.diamonds12","Diamond MVP","Collected 7000 Diamonds","Collect 7000 Diamonds","color_82",0);
    addAchievement("geometry.ach.diamonds13","Diamond Legend","Collected 9000 Diamonds","Collect 9000 Diamonds","icon_319",0);
    addAchievement("geometry.ach.diamonds14","The Diamond GOAT","Collected 11000 Diamonds","Collect 11000 Diamonds","ship_103",0);
    addAchievement("geometry.ach.diamonds15","I\'ma buy a diamond ring for you","Collected 14000 Diamonds","Collect 14000 Diamonds","color_52",0);
    addAchievement("geometry.ach.diamonds16","Iron pickaxe not required","Collected 17000 Diamonds","Collect 17000 Diamonds","icon_226",0);
    addAchievement("geometry.ach.diamonds17","Shine bright like a diamond","Collected 20000 Diamonds","Collect 20000 Diamonds","dart_52",0);
    addAchievement("geometry.ach.diamonds18","Diamond Is Unbreakable","Collected 25000 Diamonds","Collect 25000 Diamonds","robot_58",0);
    addAchievement("geometry.ach.lists01","Lists?!","Claimed a list reward","Claim a List Reward","icon_246",0);
    addAchievement("geometry.ach.lists02","I\'m Listening","Claimed 10 list rewards","Claim 10 list rewards","icon_173",0);
    addAchievement("geometry.ach.lists03","List-avaganza!","Claimed 25 list rewards","Claim 25 list rewards","ball_52",0);
    addAchievement("geometry.ach.lists04","Listen to me!","Claimed 50 list rewards","Claim 50 list rewards","ship_140",0);
    addAchievement("geometry.ach.lists05","Lists! Lists everywhere!","Claimed 100 list rewards","Claim 100 list rewards","ball_96",0);
    addAchievement("geometry.ach.lists06","List Whisperer","Claimed 150 list rewards","Claim 150 list rewards","dart_89",0);
    addAchievement("geometry.ach.lists07","200 Lists, 1 Legend","Claimed 200 list rewards","Claim 200 list rewards","swing_39",0);
    addAchievement("geometry.ach.custom01","Challenger","Completed a user created level in Normal mode","Complete a user created level in Normal mode","color_11",0);
    addAchievement("geometry.ach.custom02","Master","Completed 10 user created levels in Normal mode","Complete 10 user created levels in Normal mode","icon_12",0);
    addAchievement("geometry.ach.custom03","The Gamer","Completed 50 user created levels in Normal mode","Complete 50 user created levels in Normal mode","icon_36",0);
    addAchievement("geometry.ach.custom04","Geometrician","Completed 100 user created levels in Normal mode","Complete 100 user created levels in Normal mode","ship_13",0);
    addAchievement("geometry.ach.custom05","Spike dodger","Completed 200 user created levels in Normal mode","Complete 200 user created levels in Normal mode","color_19",0);
    addAchievement("geometry.ach.custom06","No match for me!","Completed 300 user created levels in Normal mode","Complete 300 user created levels in Normal mode","icon_40",0);
    addAchievement("geometry.ach.custom07","Bring me their heads!","Completed 500 user created levels in Normal mode","Complete 500 user created levels in Normal mode","ship_15",0);
    addAchievement("geometry.ach.custom08","Tonight, we dine in GEOMETRY DASH!","Completed 1000 user created levels in Normal mode","Complete 1000 user created levels in Normal mode","ship_17",0);
    addAchievement("geometry.ach.custom09","Keep going...","Completed 1500 user created levels in Normal mode","Complete 1500 user created levels in Normal mode","ship_148",0);
    addAchievement("geometry.ach.custom10","No Title!","Completed 2000 user created levels in Normal mode","Complete 2000 user created levels in Normal mode","icon_164",0);
    addAchievement("geometry.ach.custom11","You beat them all","Completed 2500 user created levels in Normal mode","Complete 2500 user created levels in Normal mode","color_60",0);
    addAchievement("geometry.ach.custom12","Ultimate Dasher","Completed 3000 user created levels in Normal mode","Complete 3000 user created levels in Normal mode","icon_161",0);
    addAchievement("geometry.ach.custom13","Secret way!","Completed 4000 user created levels in Normal mode","Complete 4000 user created levels in Normal mode","icon_200",0);
    addAchievement("geometry.ach.custom14","Look yonder, kid","Completed 5000 user created levels in Normal mode","Complete 5000 user created levels in Normal mode","bird_108",0);
    addAchievement("geometry.ach.rate","Supporter","You are playing \'Geometry Dash\', thanks!","Have fun :)","icon_13",0);
    addAchievement("geometry.ach.mdrate","Meltdown Supporter!","Rated \'Geometry Dash Meltdown\', thanks!","Rate \'Geometry Dash Meltdown\' and let us know what you think","icon_71",4);
    addAchievement("geometry.ach.jump01","Bounce","Jumped 1000 times","Jump 1000 times","color2_05",0);
    addAchievement("geometry.ach.jump02","I like jumping","Jumped 10000 times","Jump 10000 times","color2_11",0);
    addAchievement("geometry.ach.jump03","You jump like a pro!","Jumped 20000 times","Jump 20000 times","color2_12",0);
    addAchievement("geometry.ach.jump04","Hop Hop Hop","Jumped 50000 times","Jump 50000 times","bird_05",0);
    addAchievement("geometry.ach.jump05","Can\'t stop jumping!!!","Jumped 100000 times","Jump 100000 times","ball_13",0);
    addAchievement("geometry.ach.jump06","Jumper","Jumped 200000 times","Jump 200000 times","color_56",0);
    addAchievement("geometry.ach.jump07","You need to rest...","Jumped 300000 times","Jump 300000 times","icon_371",0);
    addAchievement("geometry.ach.jump08","Jumpman","Jumped 400000 times","Jump 400000 times","dart_93",0);
    addAchievement("geometry.ach.jump09","One hop this time!","Jumped 500000 times","Jump 500000 times","icon_365",0);
    addAchievement("geometry.ach.jump10","Leaps and bounds","Jumped 750000 times","Jump 750000 times","dart_45",0);
    addAchievement("geometry.ach.jump11","Jump King","Jumped 1000000 times","Jump 1000000 times","swing_32",0);
    addAchievement("geometry.ach.attempt01","Trial and error","Did 100 attempts","Do 100 attempts","color2_06",0);
    addAchievement("geometry.ach.attempt02","Crash Tester","Did 500 attempts","Do 500 attempts","color2_07",0);
    addAchievement("geometry.ach.attempt03","You Shall Not Pass!","Did 2000 attempts","Do 2000 attempts","color2_14",0);
    addAchievement("geometry.ach.attempt04","Ouch...","Did 10000 attempts","Do 10000 attempts","color2_17",0);
    addAchievement("geometry.ach.attempt05","That hurts!","Did 20000 attempts","Do 20000 attempts","dart_03",0);
    addAchievement("geometry.ach.attempt06","Never Give Up","Did 30000 attempts","Do 30000 attempts","icon_341",0);
    addAchievement("geometry.ach.attempt07","Never Surrender","Did 40000 attempts","Do 40000 attempts","color_96",0);
    addAchievement("geometry.ach.attempt08","Mom said it\'s my turn","Did 60000 attempts","Do 60000 attempts","ship_161",0);
    addAchievement("geometry.ach.attempt09","If at first you don\'t succeed","Did 80000 attempts","Do 80000 attempts","icon_407",0);
    addAchievement("geometry.ach.attempt10","Stop Trying","Did 100000 attempts","Do 100000 attempts","swing_09",0);
    addAchievement("geometry.ach.attempt11","This could become a meme","Did 135000 attempts","Do 135000 attempts","ball_117",0);
    addAchievement("geometry.ach.attempt12","Take a break!","Did 185000 attempts","Do 185000 attempts","ball_46",0);
    addAchievement("geometry.ach.attempt13","Made an attempt","Did 250000 attempts","Do 250000 attempts","ship_65",0);
    addAchievement("geometry.ach.attempt14","This is the one","Did 300000 attempts","Do 300000 attempts","icon_368",0);
    addAchievement("geometry.ach.like","Helper","Liked an online level","Like an online level","color2_08",0);
    addAchievement("geometry.ach.like02","Cleric","Liked or Disliked 100 online levels","Like or Dislike 100 online levels","color2_23",0);
    addAchievement("geometry.ach.like02b","Watcher","Liked or Disliked 500 online levels","Like or Dislike 500 online levels","color_26",0);
    addAchievement("geometry.ach.like03","Spymaster","Liked or Disliked 1000 online levels","Like or Dislike 1000 online levels","color_22",0);
    addAchievement("geometry.ach.like04","The Happy One","Liked or Disliked 2000 online levels","Like or Dislike 2000 online levels","special_03",0);
    addAchievement("geometry.ach.like05","Your vote matters!","Liked or Disliked 3000 online levels","Like or Dislike 3000 online levels","icon_271",0);
    addAchievement("geometry.ach.like06","Critic","Liked or Disliked 4000 online levels","Like or Dislike 4000 online levels","ball_70",0);
    addAchievement("geometry.ach.rateDiff","Guide","Rated the stars of an online level","Rate the stars of an online level","color2_09",1);
    addAchievement("geometry.ach.rateDiff02","Visionary","Rated the stars of 100 online levels","Rate the stars of 100 online levels","color2_22",1);
    addAchievement("geometry.ach.rateDiff02b","Organizer","Rated the stars of 500 online levels","Rate the stars of 500 online levels","dart_05",1);
    addAchievement("geometry.ach.rateDiff03","Guiding Light","Rated the stars of 1000 online levels","Rate the stars of 1000 online levels","color_23",1);
    addAchievement("geometry.ach.rateDiff04","Justice!","Rated the stars of 2000 online levels","Rate the stars of 2000 online levels","icon_57",1);
    addAchievement("geometry.ach.followCreator","Geometry Dash is Love","Followed a creator!","Follow a creator","color2_25",0);
    addAchievement("geometry.ach.followCreator02","Geometry Dasher","Followed 10 creators!","Follow 10 creators","color2_24",0);
    addAchievement("geometry.ach.followCreator03","Life is dash","Followed 25 creators!","Follow 25 creators","icon_344",0);
    addAchievement("geometry.ach.followCreator04","Geometry is me","Followed 50 creators!","Follow 50 creators","ball_75",0);
    addAchievement("geometry.ach.friends01","No longer lonely","You added a friend!","Add a friend","color2_26",0);
    addAchievement("geometry.ach.friends02","I\'m popular!","You added 10 friends!","Add 10 friends","color_27",0);
    addAchievement("geometry.ach.friends03","Friends? What friends?","You added 25 friends!","Add 25 friends","icon_296",0);
    addAchievement("geometry.ach.friends04","Touched grass","You added 50 friends!","Add 50 friends","icon_272",0);
    addAchievement("geometry.ach.submit","Creator","Created and submitted a custom level","Create and submit a custom level","color2_10",1);
    addAchievement("geometry.ach.creator01","Geometry Creator","Got 100 Likes on a created level","Get 100 Likes on a created level","icon_46",1);
    addAchievement("geometry.ach.creator02","Geometry Star","Got a star rated level","Get a star rated level","bird_16",1);
    addAchievement("geometry.ach.creator03","Geometry Mechanic","Got 50 Likes on a created level","Get 50 Likes on a created level","icon_63",1);
    addAchievement("geometry.ach.creator04","Geometry Knower","Got 250 Likes on a created level","Get 250 Likes on a created level","ball_72",1);
    addAchievement("geometry.ach.creator05","Geometry Influencer","Got 500 Likes on a created level","Get 500 Likes on a created level","icon_238",1);
    addAchievement("geometry.ach.creator06","Geometry Genius","Got 1000 Likes on a created level","Get 1000 Likes on a created level","icon_275",1);
    addAchievement("geometry.ach.moreGames","RobTop Gamer","Looked at more RobTop Games","Tap the More Games button!","color2_04",0);
    addAchievement("geometry.ach.facebook","Number one fan!","Liked Geometry Dash on Facebook","Like Geometry Dash on Facebook","color2_13",0);
    addAchievement("geometry.ach.youtube","GeometryTube","Subscribed to RobTop Games on YouTube","Subscribe to RobTop Games on YouTube","color2_20",0);
    addAchievement("geometry.ach.twitter","Geometry Bird!","Followed RobTop Games on Twitter","Follow RobTop Games on Twitter","color2_31",0);
    addAchievement("geometry.ach.special01","So close","Crashed at over 95%","Crash at over 95% on a main level in normal mode","color2_18",0);
    addAchievement("geometry.ach.secret01","Rampage!","Destroyed a player","A secret is required","color2_19",0);
    addAchievement("geometry.ach.secret02","Dominating!","Destroyed 50 players","A secret is required","icon_41",0);
    addAchievement("geometry.ach.secret02b","Ultrakill!","Destroyed 100 players","A secret is required","color2_27",0);
    addAchievement("geometry.ach.secret03","Godlike!","Destroyed 200 players","A secret is required","icon_39",0);
    addAchievement("geometry.ach.secret03b","Wickedsick!","Destroyed 500 players","A secret is required","ball_12",0);
    addAchievement("geometry.ach.secret04","Master Detective","Found the hidden coin","A hidden treasure is required","color2_21",0);
    addAchievement("geometry.ach.secret05","Oh no...","Found the secret","A secret is required","icon_62",0);
    addAchievement("geometry.ach.secret06","Thief!","Stole the Vault Keepers coin","A secret is required"," ",0);
    addAchievement("geometry.ach.secret07","Thief! Thief!","Stole the Vault Keepers icon","A secret is required","icon_51",0);
    addAchievement("geometry.ach.secret08","Decrypter","Found the secret","A secret is required","bird_11",0);
    addAchievement("geometry.ach.secret09","The Unknown","Found the secret","A secret is required","robot_02",0);
    addAchievement("geometry.ach.secret10","The Unseen","Found the secret","A secret is required","dart_08",0);
    addAchievement("geometry.ach.secret11","Catch them all!","Found the secret","A secret is required","icon_55",0);
    addAchievement("geometry.ach.secret12","Nice shot!","Found the secret","A secret is required","icon_50",0);
    addAchievement("geometry.ach.secret13","Revealing...","Found the secret","A secret is required","ship_20",0);
    addAchievement("geometry.ach.secret14","Third eye open...","Found the secret","A secret is required","bird_12",0);
    addAchievement("geometry.ach.secret15","Very clever...","Found the secret","A secret is required","special_04",0);
    addAchievement("geometry.ach.secret16","Doomed us all!","Found the secret","A secret is required","dart_13",0);
    addAchievement("geometry.ach.secret17","Nothing is hidden","Found the secret","A secret is required","icon_64",0);
    addAchievement("geometry.ach.secret18","KILLAMANJARO","Destroyed 750 players","A secret is required","ball_71",0);
    addAchievement("geometry.ach.secret19","A true memer","Found the secret","A secret is required","swing_02",0);
    addAchievement("geometry.ach.v2.secret01","Ultimate Energy","Found the secret","A secret is required","icon_80",0);
    addAchievement("geometry.ach.v2.secret02","Uber Hacker","Found the secret","A secret is required","icon_78",0);
    addAchievement("geometry.ach.v2.secret03","Cold as Ice","Found the secret","A secret is required"," ",0);
    addAchievement("geometry.ach.v2.secret04","Sneaky Sneak","Found the secret","A secret is required","icon_81",0);
    addAchievement("geometry.ach.v2.secret05","I can count!","Found the secret","A secret is required","icon_76",0);
    addAchievement("geometry.ach.v2.secret06","Cant be fooled","Found the secret","A secret is required","icon_108",0);
    addAchievement("geometry.ach.v2.secret07","Paintbucket","Found the secret","A secret is required","color_37",0);
    addAchievement("geometry.ach.v2.secret08","Burnt Chicken","Found the secret","A secret is required","color2_33",0);
    addAchievement("geometry.ach.v2.secret09","Nostalgia","Found the secret","A secret is required","icon_466",0);
    addAchievement("geometry.ach.v2.secret10","Cooked","Found the secret","A secret is required","ship_163",0);
    addAchievement("geometry.ach.v3.secret01","Gatekeepers Riddle","Found the secret","A secret is required","icon_91",1);
    addAchievement("geometry.ach.v3.secret02","Gatekeepers Query","Found the secret","A secret is required","icon_89",1);
    addAchievement("geometry.ach.v3.secret03","Gatekeepers Code","Found the secret","A secret is required","color2_38",1);
    addAchievement("geometry.ach.v3.secret04","Gatekeepers Curse","Found the secret","A secret is required","icon_90",1);
    addAchievement("geometry.ach.v3.secret05","Gatekeepers Vision","Found the secret","A secret is required","dart_23",1);
    addAchievement("geometry.ach.v3.secret06","Gatekeepers Enigma","Found the secret","A secret is required","spider_26",1);
    addAchievement("geometry.ach.v3.secret07","Gatekeepers Cipher","Found the secret","A secret is required","robot_46",1);
    addAchievement("geometry.ach.steam01","Steamrolling!","Completed level 1-3 in Normal mode (Steam Exclusive)","Complete level 1-3 in Normal mode (Steam Exclusive)","icon_47",1);
    addAchievement("geometry.ach.steam02","SteamStep!","Completed \'Clubstep\' in Normal mode (Steam Exclusive Bonus)","Complete \'Clubstep\' in Normal mode (Steam Exclusive Bonus)","icon_48",1);
    addAchievement("geometry.ach.shardFire01","Fire Recruit","Collected 5 Fire Shards","Collect 5 Fire Shards","icon_95",0);
    addAchievement("geometry.ach.shardFire02","Fire Apprentice","Collected 15 Fire Shards","Collect 15 Fire Shards","ball_24",0);
    addAchievement("geometry.ach.shardFire03","Fire Guardian","Collected 35 Fire Shards","Collect 35 Fire Shards","robot_09",0);
    addAchievement("geometry.ach.shardFire04","Fire Champion","Collected 65 Fire Shards","Collect 65 Fire Shards","ship_29",0);
    addAchievement("geometry.ach.shardFire05","Fire Master","Collected 100 Fire Shards","Collect 100 Fire Shards","death_02",0);
    addAchievement("geometry.ach.shardIce01","Ice Recruit","Collected 5 Ice Shards","Collect 5 Ice Shards","icon_84",0);
    addAchievement("geometry.ach.shardIce02","Ice Apprentice","Collected 15 Ice Shards","Collect 15 Ice Shards","ball_26",0);
    addAchievement("geometry.ach.shardIce03","Ice Guardian","Collected 35 Ice Shards","Collect 35 Ice Shards","spider_06",0);
    addAchievement("geometry.ach.shardIce04","Ice Champion","Collected 65 Ice Shards","Collect 65 Ice Shards","ship_31",0);
    addAchievement("geometry.ach.shardIce05","Ice Master","Collected 100 Ice Shards","Collect 100 Ice Shards","death_09",0);
    addAchievement("geometry.ach.shardPoison01","Poison Recruit","Collected 5 Poison Shards","Collect 5 Poison Shards","ball_22",0);
    addAchievement("geometry.ach.shardPoison02","Poison Apprentice","Collected 15 Poison Shards","Collect 15 Poison Shards","bird_20",0);
    addAchievement("geometry.ach.shardPoison03","Poison Guardian","Collected 35 Poison Shards","Collect 35 Poison Shards","icon_105",0);
    addAchievement("geometry.ach.shardPoison04","Poison Champion","Collected 65 Poison Shards","Collect 65 Poison Shards","spider_05",0);
    addAchievement("geometry.ach.shardPoison05","Poison Master","Collected 100 Poison Shards","Collect 100 Poison Shards","death_04",0);
    addAchievement("geometry.ach.shardShadow01","Shadow Recruit","Collected 5 Shadow Shards","Collect 5 Shadow Shards","dart_20",0);
    addAchievement("geometry.ach.shardShadow02","Shadow Apprentice","Collected 15 Shadow Shards","Collect 15 Shadow Shards","ship_28",0);
    addAchievement("geometry.ach.shardShadow03","Shadow Guardian","Collected 35 Shadow Shards","Collect 35 Shadow Shards","bird_26",0);
    addAchievement("geometry.ach.shardShadow04","Shadow Champion","Collected 65 Shadow Shards","Collect 65 Shadow Shards","robot_17",0);
    addAchievement("geometry.ach.shardShadow05","Shadow Master","Collected 100 Shadow Shards","Collect 100 Shadow Shards","death_05",0);
    addAchievement("geometry.ach.shardLava01","Lava Recruit","Collected 5 Lava Shards","Collect 5 Lava Shards","dart_14",0);
    addAchievement("geometry.ach.shardLava02","Lava Apprentice","Collected 15 Lava Shards","Collect 15 Lava Shards","icon_92",0);
    addAchievement("geometry.ach.shardLava03","Lava Guardian","Collected 35 Lava Shards","Collect 35 Lava Shards","robot_07",0);
    addAchievement("geometry.ach.shardLava04","Lava Champion","Collected 65 Lava Shards","Collect 65 Lava Shards","spider_09",0);
    addAchievement("geometry.ach.shardLava05","Lava Master","Collected 100 Lava Shards","Collect 100 Lava Shards","death_06",0);
    addAchievement("geometry.ach.shardBonus01","Bonus Recruit","Collected 5 of each Tier 1 Shard","Collect 5 of each Tier 1 Shard","icon_98",0);
    addAchievement("geometry.ach.shardBonus02","Bonus Apprentice","Collected 15 of each Tier 1 Shard","Collect 15 of each Tier 1 Shard","bird_22",0);
    addAchievement("geometry.ach.shardBonus03","Bonus Guardian","Collected 35 of each Tier 1 Shard","Collect 35 of each Tier 1 Shard","ship_34",0);
    addAchievement("geometry.ach.shardBonus04","Bonus Champion","Collected 65 of each Tier 1 Shard","Collect 65 of each Tier 1 Shard","robot_13",0);
    addAchievement("geometry.ach.shardBonus05","Bonus Master","Collected 100 of each Tier 1 Shard","Collect 100 of each Tier 1 Shard","death_07",0);
    addAchievement("geometry.ach.shardEarth01","Earth Recruit","Collected 5 Earth Shards","Collect 5 Earth Shards","spider_32",0);
    addAchievement("geometry.ach.shardEarth02","Earth Apprentice","Collected 15 Earth Shards","Collect 15 Earth Shards","icon_352",0);
    addAchievement("geometry.ach.shardEarth03","Earth Guardian","Collected 35 Earth Shards","Collect 35 Earth Shards","dart_43",0);
    addAchievement("geometry.ach.shardEarth04","Earth Champion","Collected 65 Earth Shards","Collect 65 Earth Shards","ship_156",0);
    addAchievement("geometry.ach.shardEarth05","Earth Master","Collected 100 Earth Shards","Collect 100 Earth Shards","robot_54",0);
    addAchievement("geometry.ach.shardBlood01","Blood Recruit","Collected 5 Blood Shards","Collect 5 Blood Shards","icon_165",0);
    addAchievement("geometry.ach.shardBlood02","Blood Apprentice","Collected 15 Blood Shards","Collect 15 Blood Shards","robot_43",0);
    addAchievement("geometry.ach.shardBlood03","Blood Guardian","Collected 35 Blood Shards","Collect 35 Blood Shards","swing_15",0);
    addAchievement("geometry.ach.shardBlood04","Blood Champion","Collected 65 Blood Shards","Collect 65 Blood Shards","dart_59",0);
    addAchievement("geometry.ach.shardBlood05","Blood Master","Collected 100 Blood Shards","Collect 100 Blood Shards","spider_45",0);
    addAchievement("geometry.ach.shardMetal01","Metal Recruit","Collected 5 Metal Shards","Collect 5 Metal Shards","icon_235",0);
    addAchievement("geometry.ach.shardMetal02","Metal Apprentice","Collected 15 Metal Shards","Collect 15 Metal Shards","dart_50",0);
    addAchievement("geometry.ach.shardMetal03","Metal Guardian","Collected 35 Metal Shards","Collect 35 Metal Shards","ship_108",0);
    addAchievement("geometry.ach.shardMetal04","Metal Champion","Collected 65 Metal Shards","Collect 65 Metal Shards","bird_117",0);
    addAchievement("geometry.ach.shardMetal05","Metal Master","Collected 100 Metal Shards","Collect 100 Metal Shards","spider_25",0);
    addAchievement("geometry.ach.shardLight01","Light Recruit","Collected 5 Light Shards","Collect 5 Light Shards","bird_74",0);
    addAchievement("geometry.ach.shardLight02","Light Apprentice","Collected 15 Light Shards","Collect 15 Light Shards","robot_57",0);
    addAchievement("geometry.ach.shardLight03","Light Guardian","Collected 35 Light Shards","Collect 35 Light Shards","spider_55",0);
    addAchievement("geometry.ach.shardLight04","Light Champion","Collected 65 Light Shards","Collect 65 Light Shards","icon_438",0);
    addAchievement("geometry.ach.shardLight05","Light Master","Collected 100 Light Shards","Collect 100 Light Shards","ball_102",0);
    addAchievement("geometry.ach.shardSoul01","Soul Recruit","Collected 5 Soul Shards","Collect 5 Soul Shards","ship_78",0);
    addAchievement("geometry.ach.shardSoul02","Soul Apprentice","Collected 15 Soul Shards","Collect 15 Soul Shards","ball_78",0);
    addAchievement("geometry.ach.shardSoul03","Soul Guardian","Collected 35 Soul Shards","Collect 35 Soul Shards","spider_35",0);
    addAchievement("geometry.ach.shardSoul04","Soul Champion","Collected 65 Soul Shards","Collect 65 Soul Shards","icon_395",0);
    addAchievement("geometry.ach.shardSoul05","Soul Master","Collected 100 Soul Shards","Collect 100 Soul Shards","bird_148",0);
    addAchievement("geometry.ach.shardBonusB01","Bonus Initiate","Collected 5 of each Tier 2 Shard","Collect 5 of each Tier 2 Shard","icon_388",0);
    addAchievement("geometry.ach.shardBonusB02","Bonus Novice","Collected 15 of each Tier 2 Shard","Collect 15 of each Tier 2 Shard","ball_106",0);
    addAchievement("geometry.ach.shardBonusB03","Bonus Adept","Collected 35 of each Tier 2 Shard","Collect 35 of each Tier 2 Shard","dart_62",0);
    addAchievement("geometry.ach.shardBonusB04","Bonus Sage","Collected 65 of each Tier 2 Shard","Collect 65 of each Tier 2 Shard","bird_84",0);
    addAchievement("geometry.ach.shardBonusB05","Bonus Paragon","Collected 100 of each Tier 2 Shard","Collect 100 of each Tier 2 Shard","death_20",0);
    addAchievement("geometry.ach.path01.00","Path of Fire","Unlocked the Path of Fire","Unlock the Path of Fire","icon_213",0);
    addAchievement("geometry.ach.path01.01","Flame Initiate","Reached Path of Fire Rank 1","Reach Path of Fire Rank 1","color_48",0);
    addAchievement("geometry.ach.path01.02","Blaze Adept","Reached Path of Fire Rank 2","Reach Path of Fire Rank 2","icon_236",0);
    addAchievement("geometry.ach.path01.03","Firestarter","Reached Path of Fire Rank 3","Reach Path of Fire Rank 3","color_54",0);
    addAchievement("geometry.ach.path01.04","Torch Bearer","Reached Path of Fire Rank 4","Reach Path of Fire Rank 4","dart_60",0);
    addAchievement("geometry.ach.path01.05","Flame Wielder","Reached Path of Fire Rank 5","Reach Path of Fire Rank 5","color2_51",0);
    addAchievement("geometry.ach.path01.06","Fire Conductor","Reached Path of Fire Rank 6","Reach Path of Fire Rank 6","robot_35",0);
    addAchievement("geometry.ach.path01.07","Inferno Crafter","Reached Path of Fire Rank 7","Reach Path of Fire Rank 7","ship_143",0);
    addAchievement("geometry.ach.path01.08","Flame Enchanter","Reached Path of Fire Rank 8","Reach Path of Fire Rank 8","dart_46",0);
    addAchievement("geometry.ach.path01.09","Firestorm Summoner","Reached Path of Fire Rank 9","Reach Path of Fire Rank 9","robot_55",0);
    addAchievement("geometry.ach.path01.10","Flame Master","Reached Path of Fire Rank 10","Reach Path of Fire Rank 10","bird_79",0);
    addAchievement("geometry.ach.path02.00","Path of Ice","Unlocked the Path of Ice","Unlock the Path of Ice","spider_49",0);
    addAchievement("geometry.ach.path02.01","Frost Novice","Reached Path of Ice Rank 1","Reach Path of Ice Rank 1","color2_47",0);
    addAchievement("geometry.ach.path02.02","Ice Apprentice","Reached Path of Ice Rank 2","Reach Path of Ice Rank 2","icon_394",0);
    addAchievement("geometry.ach.path02.03","Snow Tracker","Reached Path of Ice Rank 3","Reach Path of Ice Rank 3","color_44",0);
    addAchievement("geometry.ach.path02.04","Winter Wanderer","Reached Path of Ice Rank 4","Reach Path of Ice Rank 4","ball_66",0);
    addAchievement("geometry.ach.path02.05","Frost Forger","Reached Path of Ice Rank 5","Reach Path of Ice Rank 5","color_106",0);
    addAchievement("geometry.ach.path02.06","Blizzard Navigator","Reached Path of Ice Rank 6","Reach Path of Ice Rank 6","ship_130",0);
    addAchievement("geometry.ach.path02.07","Hailstorm Harbinger","Reached Path of Ice Rank 7","Reach Path of Ice Rank 7","bird_135",0);
    addAchievement("geometry.ach.path02.08","Frostbite Guardian","Reached Path of Ice Rank 8","Reach Path of Ice Rank 8","robot_29",0);
    addAchievement("geometry.ach.path02.09","Arctic Conqueror","Reached Path of Ice Rank 9","Reach Path of Ice Rank 9","ball_76",0);
    addAchievement("geometry.ach.path02.10","Icebound Master","Reached Path of Ice Rank 10","Reach Path of Ice Rank 10","ship_99",0);
    addAchievement("geometry.ach.path03.00","Path of Poison","Unlocked the Path of Poison","Unlock the Path of Poison","icon_274",0);
    addAchievement("geometry.ach.path03.01","Venom Apprentice","Reached Path of Poison Rank 1","Reach Path of Poison Rank 1","color2_73",0);
    addAchievement("geometry.ach.path03.02","Toxin Courier","Reached Path of Poison Rank 2","Reach Path of Poison Rank 2","robot_42",0);
    addAchievement("geometry.ach.path03.03","Pestilence Seeker","Reached Path of Poison Rank 3","Reach Path of Poison Rank 3","color2_79",0);
    addAchievement("geometry.ach.path03.04","Noxious Nomad","Reached Path of Poison Rank 4","Reach Path of Poison Rank 4","swing_08",0);
    addAchievement("geometry.ach.path03.05","Poison Pioneer","Reached Path of Poison Rank 5","Reach Path of Poison Rank 5","color_80",0);
    addAchievement("geometry.ach.path03.06","Plague Prodigy","Reached Path of Poison Rank 6","Reach Path of Poison Rank 6","icon_276",0);
    addAchievement("geometry.ach.path03.07","Venom Vanguard","Reached Path of Poison Rank 7","Reach Path of Poison Rank 7","spider_57",0);
    addAchievement("geometry.ach.path03.08","Toxic Tyrant","Reached Path of Poison Rank 8","Reach Path of Poison Rank 8","bird_121",0);
    addAchievement("geometry.ach.path03.09","Plague Overlord","Reached Path of Poison Rank 9","Reach Path of Poison Rank 9","ball_110",0);
    addAchievement("geometry.ach.path03.10","Venomous Master","Reached Path of Poison Rank 10","Reach Path of Poison Rank 10","icon_342",0);
    addAchievement("geometry.ach.path04.00","Path of Shadow","Unlocked the Path of Shadow","Unlock the Path of Shadow","icon_188",0);
    addAchievement("geometry.ach.path04.01","Shadow Initiate","Reached Path of Shadow Rank 1","Reach Path of Shadow Rank 1","color_93",0);
    addAchievement("geometry.ach.path04.02","Obscure Apprentice","Reached Path of Shadow Rank 2","Reach Path of Shadow Rank 2","icon_232",0);
    addAchievement("geometry.ach.path04.03","Twilight Treader","Reached Path of Shadow Rank 3","Reach Path of Shadow Rank 3","color2_99",0);
    addAchievement("geometry.ach.path04.04","Mystic Shade","Reached Path of Shadow Rank 4","Reach Path of Shadow Rank 4","spider_36",0);
    addAchievement("geometry.ach.path04.05","Nocturnal Nomad","Reached Path of Shadow Rank 5","Reach Path of Shadow Rank 5","color2_96",0);
    addAchievement("geometry.ach.path04.06","Veil Wanderer","Reached Path of Shadow Rank 6","Reach Path of Shadow Rank 6","ship_141",0);
    addAchievement("geometry.ach.path04.07","Ethereal Emissary","Reached Path of Shadow Rank 7","Reach Path of Shadow Rank 7","dart_72",0);
    addAchievement("geometry.ach.path04.08","Nightfall Navigator","Reached Path of Shadow Rank 8","Reach Path of Shadow Rank 8","ball_61",0);
    addAchievement("geometry.ach.path04.09","Shadow Sovereign","Reached Path of Shadow Rank 9","Reach Path of Shadow Rank 9","icon_385",0);
    addAchievement("geometry.ach.path04.10","Darkness Master","Reached Path of Shadow Rank 10","Reach Path of Shadow Rank 10","ship_127",0);
    addAchievement("geometry.ach.path05.00","Path of Lava","Unlocked the Path of Lava","Unlock the Path of Lava","ship_60",0);
    addAchievement("geometry.ach.path05.01","Cinder Seeker","Reached Path of Lava Rank 1","Reach Path of Lava Rank 1","color2_56",0);
    addAchievement("geometry.ach.path05.02","Crust Breaker","Reached Path of Lava Rank 2","Reach Path of Lava Rank 2","icon_239",0);
    addAchievement("geometry.ach.path05.03","Lava Walker","Reached Path of Lava Rank 3","Reach Path of Lava Rank 3","color_51",0);
    addAchievement("geometry.ach.path05.04","Sulfur Sage","Reached Path of Lava Rank 4","Reach Path of Lava Rank 4","bird_47",0);
    addAchievement("geometry.ach.path05.05","Brimstone Bridger","Reached Path of Lava Rank 5","Reach Path of Lava Rank 5","color_57",0);
    addAchievement("geometry.ach.path05.06","Molten Marauder","Reached Path of Lava Rank 6","Reach Path of Lava Rank 6","icon_429",0);
    addAchievement("geometry.ach.path05.07","Volcanic Vanguard","Reached Path of Lava Rank 7","Reach Path of Lava Rank 7","robot_47",0);
    addAchievement("geometry.ach.path05.08","Ash Ascendant","Reached Path of Lava Rank 8","Reach Path of Lava Rank 8","ball_79",0);
    addAchievement("geometry.ach.path05.09","Magma Monarch","Reached Path of Lava Rank 9","Reach Path of Lava Rank 9","icon_221",0);
    addAchievement("geometry.ach.path05.10","Volcano Master","Reached Path of Lava Rank 10","Reach Path of Lava Rank 10","spider_28",0);
    addAchievement("geometry.ach.path06.00","Path of Earth","Unlocked the Path of Earth","Unlock the Path of Earth","icon_227",0);
    addAchievement("geometry.ach.path06.01","Nature\'s Novice","Reached Path of Earth Rank 1","Reach Path of Earth Rank 1","color_65",0);
    addAchievement("geometry.ach.path06.02","Sprout Whisperer","Reached Path of Earth Rank 2","Reach Path of Earth Rank 2","ship_79",0);
    addAchievement("geometry.ach.path06.03","Sapling Sage","Reached Path of Earth Rank 3","Reach Path of Earth Rank 3","color2_68",0);
    addAchievement("geometry.ach.path06.04","Terra Tamer","Reached Path of Earth Rank 4","Reach Path of Earth Rank 4","bird_102",0);
    addAchievement("geometry.ach.path06.05","Herbal Harbinger","Reached Path of Earth Rank 5","Reach Path of Earth Rank 5","color_45",0);
    addAchievement("geometry.ach.path06.06","Woodland Warden","Reached Path of Earth Rank 6","Reach Path of Earth Rank 6","robot_32",0);
    addAchievement("geometry.ach.path06.07","Grove Guardian","Reached Path of Earth Rank 7","Reach Path of Earth Rank 7","dart_53",0);
    addAchievement("geometry.ach.path06.08","Terrain Tempest","Reached Path of Earth Rank 8","Reach Path of Earth Rank 8","ball_77",0);
    addAchievement("geometry.ach.path06.09","Earthbound Elder","Reached Path of Earth Rank 9","Reach Path of Earth Rank 9","spider_23",0);
    addAchievement("geometry.ach.path06.10","Elemental Master","Reached Path of Earth Rank 10","Reach Path of Earth Rank 10","icon_247",0);
    addAchievement("geometry.ach.path07.00","Path of Blood","Unlocked the Path of Blood","Unlock the Path of Blood","icon_431",0);
    addAchievement("geometry.ach.path07.01","Crimson Initiate","Reached Path of Blood Rank 1","Reach Path of Blood Rank 1","color2_54",0);
    addAchievement("geometry.ach.path07.02","Blood Novice","Reached Path of Blood Rank 2","Reach Path of Blood Rank 2","ball_92",0);
    addAchievement("geometry.ach.path07.03","Scarlet Seeker","Reached Path of Blood Rank 3","Reach Path of Blood Rank 3","color2_53",0);
    addAchievement("geometry.ach.path07.04","Rouge Ranger","Reached Path of Blood Rank 4","Reach Path of Blood Rank 4","swing_23",0);
    addAchievement("geometry.ach.path07.05","Bloodline Baron","Reached Path of Blood Rank 5","Reach Path of Blood Rank 5","color2_57",0);
    addAchievement("geometry.ach.path07.06","Vein Vanquisher","Reached Path of Blood Rank 6","Reach Path of Blood Rank 6","dart_81",0);
    addAchievement("geometry.ach.path07.07","Vampiric Vanguard","Reached Path of Blood Rank 7","Reach Path of Blood Rank 7","spider_53",0);
    addAchievement("geometry.ach.path07.08","Crimson King","Reached Path of Blood Rank 8","Reach Path of Blood Rank 8","bird_127",0);
    addAchievement("geometry.ach.path07.09","Eternal Emperor","Reached Path of Blood Rank 9","Reach Path of Blood Rank 9","icon_237",0);
    addAchievement("geometry.ach.path07.10","Path of Blood Master","Reached Path of Blood Rank 10","Reach Path of Blood Rank 10","ball_83",0);
    addAchievement("geometry.ach.path08.00","Path of Metal","Unlocked the Path of Metal","Unlock the Path of Metal","icon_217",0);
    addAchievement("geometry.ach.path08.01","Iron Initiate","Reached Path of Metal Rank 1","Reach Path of Metal Rank 1","color_102",0);
    addAchievement("geometry.ach.path08.02","Copper Cadet","Reached Path of Metal Rank 2","Reach Path of Metal Rank 2","spider_51",0);
    addAchievement("geometry.ach.path08.03","Silver Seeker","Reached Path of Metal Rank 3","Reach Path of Metal Rank 3","color2_94",0);
    addAchievement("geometry.ach.path08.04","Cast Crusader","Reached Path of Metal Rank 4","Reach Path of Metal Rank 4","ball_105",0);
    addAchievement("geometry.ach.path08.05","Bronze Baron","Reached Path of Metal Rank 5","Reach Path of Metal Rank 5","color2_91",0);
    addAchievement("geometry.ach.path08.06","Metalwork Maestro","Reached Path of Metal Rank 6","Reach Path of Metal Rank 6","ship_150",0);
    addAchievement("geometry.ach.path08.07","Steel Scion","Reached Path of Metal Rank 7","Reach Path of Metal Rank 7","bird_85",0);
    addAchievement("geometry.ach.path08.08","Titanium Titan","Reached Path of Metal Rank 8","Reach Path of Metal Rank 8","icon_299",0);
    addAchievement("geometry.ach.path08.09","Mithril Monarch","Reached Path of Metal Rank 9","Reach Path of Metal Rank 9","robot_56",0);
    addAchievement("geometry.ach.path08.10","Path of Metal Master","Reached Path of Metal Rank 10","Reach Path of Metal Rank 10","spider_44",0);
    addAchievement("geometry.ach.path09.00","Path of Light","Unlocked the Path of Light","Unlock the Path of Light","ball_93",0);
    addAchievement("geometry.ach.path09.01","Luminary Learner","Reached Path of Light Rank 1","Reach Path of Light Rank 1","color2_71",0);
    addAchievement("geometry.ach.path09.02","Shine Seeker","Reached Path of Light Rank 2","Reach Path of Light Rank 2","icon_415",0);
    addAchievement("geometry.ach.path09.03","Daylight Dreamer","Reached Path of Light Rank 3","Reach Path of Light Rank 3","color_105",0);
    addAchievement("geometry.ach.path09.04","Shimmering Sage","Reached Path of Light Rank 4","Reach Path of Light Rank 4","spider_20",0);
    addAchievement("geometry.ach.path09.05","Heavenly Herald","Reached Path of Light Rank 5","Reach Path of Light Rank 5","color2_62",0);
    addAchievement("geometry.ach.path09.06","Celestial Champion","Reached Path of Light Rank 6","Reach Path of Light Rank 6","ship_162",0);
    addAchievement("geometry.ach.path09.07","Aurora Archon","Reached Path of Light Rank 7","Reach Path of Light Rank 7","dart_84",0);
    addAchievement("geometry.ach.path09.08","Luminous Lord","Reached Path of Light Rank 8","Reach Path of Light Rank 8","spider_42",0);
    addAchievement("geometry.ach.path09.09","Divine Dawnbringer","Reached Path of Light Rank 9","Reach Path of Light Rank 9","icon_329",0);
    addAchievement("geometry.ach.path09.10","Path of Light Master","Reached Path of Light Rank 10","Reach Path of Light Rank 10","ship_114",0);
    addAchievement("geometry.ach.path10.00","Path of Souls","Unlocked the Path of Souls","Unlock the Path of Souls","icon_172",0);
    addAchievement("geometry.ach.path10.01","Ethereal Initiate","Reached Path of Souls Rank 1","Reach Path of Souls Rank 1","color_95",0);
    addAchievement("geometry.ach.path10.02","Spectral Student","Reached Path of Souls Rank 2","Reach Path of Souls Rank 2","robot_60",0);
    addAchievement("geometry.ach.path10.03","Soul Seeker","Reached Path of Souls Rank 3","Reach Path of Souls Rank 3","color2_100",0);
    addAchievement("geometry.ach.path10.04","Spirit Scholar","Reached Path of Souls Rank 4","Reach Path of Souls Rank 4","icon_178",0);
    addAchievement("geometry.ach.path10.05","Abyssal Arbitrator","Reached Path of Souls Rank 5","Reach Path of Souls Rank 5","color_103",0);
    addAchievement("geometry.ach.path10.06","Nether Knight","Reached Path of Souls Rank 6","Reach Path of Souls Rank 6","robot_39",0);
    addAchievement("geometry.ach.path10.07","Phantom Protector","Reached Path of Souls Rank 7","Reach Path of Souls Rank 7","dart_58",0);
    addAchievement("geometry.ach.path10.08","Spiritual Sentinel","Reached Path of Souls Rank 8","Reach Path of Souls Rank 8","bird_93",0);
    addAchievement("geometry.ach.path10.09","Soul Commander","Reached Path of Souls Rank 9","Reach Path of Souls Rank 9","ball_68",0);
    addAchievement("geometry.ach.path10.10","Path of Souls Master","Reached Path of Souls Rank 10","Reach Path of Souls Rank 10","spider_24",0);
}


bool __thiscall AchievementManager::areAchievementsEarned(cocos2d::CCArray *arr)
{
    bool earned = false;
    unsigned int i = 0;
    while( true ) {
        if (arr->count() <= i) {
          return true;
        }
        earned = isAchievementEarned((reinterpret_cast<cocos2d::CCString*>(arr->objectAtIndex(i)))->getCString());
        if (!earned) 
            break;
        i++;
    }
    return earned;
}





void AchievementManager::dataLoaded(DS_Dictionary *dsdict)
{
    cocos2d::CCDictionary *reportedAchievements = dsdict->getDictForKey("reportedAchievements",0);
    if (m_reportedAchievements != nullptr) {
      GameToolbox::mergeDictsSaveLargestInt(m_reportedAchievements, reportedAchievements);
      return;
    }
    else {
        reportedAchievements->retain();
        if (m_reportedAchievements != nullptr) {
            m_reportedAchievements->retain();
        }
        m_reportedAchievements = reportedAchievements;
    }
}

void AchievementManager::encodeDataTo(DS_Dictionary *dsdict){
    dsdict->setDictForKey("reportedAchievements", m_reportedAchievements);
}

void AchievementManager::firstSetup() {
    cocos2d::CCDictionary *dict = cocos2d::CCDictionary::create();
    if (this->m_reportedAchievements != dict) {
        if (dict != nullptr) {
            dict->retain(dict);
        }
        if (this->m_reportedAchievements != nullptr) {
          cocos2d::CCObject::release(this->m_reportedAchievements);
        }
        m_reportedAchievements = dict;
    }
    return;
}


cocos2d::CCDictionary* AchievementManager::getAchievementRewardDict()
{
    cocos2d::CCDictionary* dict = cocos2d::CCDictionary::create();
    dict->setObject(cocos2d::CCString::create("icon_43"), "geometry.ach.coins19");
    dict->setObject(cocos2d::CCString::create("bird_09"), "geometry.ach.coins20");
    dict->setObject(cocos2d::CCString::create("dart_11"), "geometry.ach.mappacks10");
    dict->setObject(cocos2d::CCString::create("icon_98"), "geometry.ach.shardBonus01");
    dict->setObject(cocos2d::CCString::create("icon_76"), "geometry.ach.v2.secret05");
    dict->setObject(cocos2d::CCString::create("color_13"), "geometry.ach.world.level009b");
    dict->setObject(cocos2d::CCString::create("death_10"), "geometry.ach.diamonds10");
    dict->setObject(cocos2d::CCString::create("color2_25"), "geometry.ach.followCreator");
    dict->setObject(cocos2d::CCString::create("dart_08"), "geometry.ach.secret10");
    dict->setObject(cocos2d::CCString::create("ship_04"), "geometry.ach.stars05");
    dict->setObject(cocos2d::CCString::create("bird_15"), "geometry.ach.demon11");
    dict->setObject(cocos2d::CCString::create("icon_93"), "geometry.ach.usercoins27");
    dict->setObject(cocos2d::CCString::create("bird_04"), "geometry.ach.coins09");
    dict->setObject(cocos2d::CCString::create("color_11"), "geometry.ach.custom01");
    dict->setObject(cocos2d::CCString::create("ball_04"), "geometry.ach.coins10");
    dict->setObject(cocos2d::CCString::create("icon_82"), "geometry.ach.stars19");
    dict->setObject(cocos2d::CCString::create("icon_90"), "geometry.ach.v3.secret04");
    dict->setObject(cocos2d::CCString::create("bird_17"), "geometry.ach.usercoins17");
    dict->setObject(cocos2d::CCString::create("ball_07"), "geometry.ach.mappacks05");
    dict->setObject(cocos2d::CCString::create("ball_27"), "geometry.ach.stars20");
    dict->setObject(cocos2d::CCString::create("bird_18"), "geometry.ach.coins24");
    dict->setObject(cocos2d::CCString::create("icon_47"), "geometry.ach.steam01");
    dict->setObject(cocos2d::CCString::create("dart_19"), "geometry.ach.diamonds05");
    dict->setObject(cocos2d::CCString::create("icon_53"), "geometry.ach.usercoins07");
    dict->setObject(cocos2d::CCString::create("icon_19"), "geometry.ach.demon01");
    dict->setObject(cocos2d::CCString::create("color2_19"), "geometry.ach.secret01");
    dict->setObject(cocos2d::CCString::create("color2_27"), "geometry.ach.secret02b");
    dict->setObject(cocos2d::CCString::create("color2_10"), "geometry.ach.submit");
    dict->setObject(cocos2d::CCString::create("robot_17"), "geometry.ach.shardShadow04");
    dict->setObject(cocos2d::CCString::create("icon_13"), "geometry.ach.rate");
    dict->setObject(cocos2d::CCString::create("icon_50"), "geometry.ach.secret12");
    dict->setObject(cocos2d::CCString::create("color_12"), "geometry.ach.level08a");
    dict->setObject(cocos2d::CCString::create("color_21"), "geometry.ach.level18a");
    dict->setObject(cocos2d::CCString::create("icon_29"), "geometry.ach.stars09");
    dict->setObject(cocos2d::CCString::create("icon_78"), "geometry.ach.v2.secret02");
    dict->setObject(cocos2d::CCString::create("ball_22"), "geometry.ach.shardPoison01");
    dict->setObject(cocos2d::CCString::create("icon_30"), "geometry.ach.stars10");
    dict->setObject(cocos2d::CCString::create("icon_36"), "geometry.ach.custom03");
    dict->setObject(cocos2d::CCString::create("robot_03"), "geometry.ach.level19b");
    dict->setObject(cocos2d::CCString::create("icon_16"), "geometry.ach.level09b");
    dict->setObject(cocos2d::CCString::create("ball_06"), "geometry.ach.coins14");
    dict->setObject(cocos2d::CCString::create("spider_08"), "geometry.ach.usercoins24");
    dict->setObject(cocos2d::CCString::create("spider_04"), "geometry.ach.stars24");
    dict->setObject(cocos2d::CCString::create("color_09"), "geometry.ach.level06a");
    dict->setObject(cocos2d::CCString::create("color_18"), "geometry.ach.level16a");
    dict->setObject(cocos2d::CCString::create("color2_20"), "geometry.ach.youtube");
    dict->setObject(cocos2d::CCString::create("icon_91"), "geometry.ach.v3.secret01");
    dict->setObject(cocos2d::CCString::create("ship_21"), "geometry.ach.usercoins14");
    dict->setObject(cocos2d::CCString::create("icon_39"), "geometry.ach.secret03");
    dict->setObject(cocos2d::CCString::create("ship_03"), "geometry.ach.demon05");
    dict->setObject(cocos2d::CCString::create("icon_44"), "geometry.ach.level17b");
    dict->setObject(cocos2d::CCString::create("icon_11"), "geometry.ach.level07b");
    dict->setObject(cocos2d::CCString::create("bird_12"), "geometry.ach.secret14");
    dict->setObject(cocos2d::CCString::create("ship_25"), "geometry.ach.usercoins04");
    dict->setObject(cocos2d::CCString::create("bird_03"), "geometry.ach.coins04");
    dict->setObject(cocos2d::CCString::create("color_07"), "geometry.ach.level04a");
    dict->setObject(cocos2d::CCString::create("bird_02"), "geometry.ach.level14a");
    dict->setObject(cocos2d::CCString::create("spider_09"), "geometry.ach.shardLava04");
    dict->setObject(cocos2d::CCString::create("ship_34"), "geometry.ach.shardBonus03");
    dict->setObject(cocos2d::CCString::create("color_19"), "geometry.ach.custom05");
    dict->setObject(cocos2d::CCString::create("icon_61"), "geometry.ach.stars14");
    dict->setObject(cocos2d::CCString::create("icon_09"), "geometry.ach.level05b");
    dict->setObject(cocos2d::CCString::create("ship_16"), "geometry.ach.coins18");
    dict->setObject(cocos2d::CCString::create("color2_13"), "geometry.ach.facebook");
    dict->setObject(cocos2d::CCString::create("icon_35"), "geometry.ach.level15b");
    dict->setObject(cocos2d::CCString::create("ball_08"), "geometry.ach.mappacks06");
    dict->setObject(cocos2d::CCString::create("ball_28"), "geometry.ach.usercoins31");
    dict->setObject(cocos2d::CCString::create("ship_29"), "geometry.ach.shardFire04");
    dict->setObject(cocos2d::CCString::create("icon_101"), "geometry.ach.diamonds06");
    dict->setObject(cocos2d::CCString::create("color_05"), "geometry.ach.level02a");
    dict->setObject(cocos2d::CCString::create("color_14"), "geometry.ach.level12a");
    dict->setObject(cocos2d::CCString::create("robot_04"), "geometry.ach.usercoins21");
    dict->setObject(cocos2d::CCString::create("icon_62"), "geometry.ach.secret05");
    dict->setObject(cocos2d::CCString::create("icon_37"), "geometry.ach.demon09");
    dict->setObject(cocos2d::CCString::create("icon_07"), "geometry.ach.level03b");
    dict->setObject(cocos2d::CCString::create("ship_09"), "geometry.ach.level13b");
    dict->setObject(cocos2d::CCString::create("color2_24"), "geometry.ach.followCreator02");
    dict->setObject(cocos2d::CCString::create("icon_26"), "geometry.ach.stars04");
    dict->setObject(cocos2d::CCString::create("dart_13"), "geometry.ach.secret16");
    dict->setObject(cocos2d::CCString::create("robot_06"), "geometry.ach.usercoins11");
    dict->setObject(cocos2d::CCString::create("ball_10"), "geometry.ach.demon10");
    dict->setObject(cocos2d::CCString::create("color_05"), "geometry.ach.world.level002b");
    dict->setObject(cocos2d::CCString::create("icon_34"), "geometry.ach.coins08");
    dict->setObject(cocos2d::CCString::create("icon_17"), "geometry.ach.level10a");
    dict->setObject(cocos2d::CCString::create("color_25"), "geometry.ach.level20a");
    dict->setObject(cocos2d::CCString::create("ship_15"), "geometry.ach.custom07");
    dict->setObject(cocos2d::CCString::create("dart_02"), "geometry.ach.usercoins01");
    dict->setObject(cocos2d::CCString::create("color_28"), "geometry.ach.stars18");
    dict->setObject(cocos2d::CCString::create("icon_84"), "geometry.ach.shardIce01");
    dict->setObject(cocos2d::CCString::create("death_05"), "geometry.ach.shardShadow05");
    dict->setObject(cocos2d::CCString::create("icon_05"), "geometry.ach.level01b");
    dict->setObject(cocos2d::CCString::create("ship_02"), "geometry.ach.level11b");
    dict->setObject(cocos2d::CCString::create("icon_74"), "geometry.ach.level21b");
    dict->setObject(cocos2d::CCString::create("dart_14"), "geometry.ach.shardLava01");
    dict->setObject(cocos2d::CCString::create("ship_24"), "geometry.ach.coins23");
    dict->setObject(cocos2d::CCString::create("icon_108"), "geometry.ach.v2.secret06");
    dict->setObject(cocos2d::CCString::create("bird_20"), "geometry.ach.shardPoison02");
    dict->setObject(cocos2d::CCString::create("icon_51"), "geometry.ach.secret07");
    dict->setObject(cocos2d::CCString::create("icon_95"), "geometry.ach.shardFire01");
    dict->setObject(cocos2d::CCString::create("dart_22"), "geometry.ach.usercoins28");
    dict->setObject(cocos2d::CCString::create("icon_28"), "geometry.ach.stars08");
    dict->setObject(cocos2d::CCString::create("color_07"), "geometry.ach.world.level004b");
    dict->setObject(cocos2d::CCString::create("bird_14"), "geometry.ach.demoncoin01");
    dict->setObject(cocos2d::CCString::create("dart_10"), "geometry.ach.usercoins18");
    dict->setObject(cocos2d::CCString::create("bird_06"), "geometry.ach.coins13");
    dict->setObject(cocos2d::CCString::create("bird_10"), "geometry.ach.mappacks07");
    dict->setObject(cocos2d::CCString::create("dart_23"), "geometry.ach.v3.secret05");
    dict->setObject(cocos2d::CCString::create("color2_22"), "geometry.ach.rateDiff02");
    dict->setObject(cocos2d::CCString::create("color_26"), "geometry.ach.like02b");
    dict->setObject(cocos2d::CCString::create("color2_06"), "geometry.ach.attempt01");
    dict->setObject(cocos2d::CCString::create("icon_100"), "geometry.ach.stars23");
    dict->setObject(cocos2d::CCString::create("ship_32"), "geometry.ach.diamonds07");
    dict->setObject(cocos2d::CCString::create("dart_06"), "geometry.ach.usercoins08");
    dict->setObject(cocos2d::CCString::create("death_07"), "geometry.ach.shardBonus05");
    dict->setObject(cocos2d::CCString::create("icon_22"), "geometry.ach.demon04");
    dict->setObject(cocos2d::CCString::create("robot_02"), "geometry.ach.secret09");
    dict->setObject(cocos2d::CCString::create("ball_13"), "geometry.ach.jump05");
    dict->setObject(cocos2d::CCString::create(" "), "geometry.ach.v2.secret03");
    dict->setObject(cocos2d::CCString::create("color_09"), "geometry.ach.world.level006b");
    dict->setObject(cocos2d::CCString::create("color2_16"), "geometry.ach.coins03");
    dict->setObject(cocos2d::CCString::create("dart_12"), "geometry.ach.stars13");
    dict->setObject(cocos2d::CCString::create("ball_26"), "geometry.ach.shardIce02");
    dict->setObject(cocos2d::CCString::create("color_32"), "geometry.ach.usercoins25");
    dict->setObject(cocos2d::CCString::create("bird_08"), "geometry.ach.coins17");
    dict->setObject(cocos2d::CCString::create("color2_07"), "geometry.ach.attempt02");
    dict->setObject(cocos2d::CCString::create("icon_33"), "geometry.ach.mappacks01");
    dict->setObject(cocos2d::CCString::create("icon_89"), "geometry.ach.v3.secret02");
    dict->setObject(cocos2d::CCString::create("ball_11"), "geometry.ach.usercoins15");
    dict->setObject(cocos2d::CCString::create("color_31"), "geometry.ach.diamonds01");
    dict->setObject(cocos2d::CCString::create("ball_05"), "geometry.ach.demon08");
    dict->setObject(cocos2d::CCString::create("color_12"), "geometry.ach.world.level008b");
    dict->setObject(cocos2d::CCString::create("ball_16"), "geometry.ach.usercoins05");
    dict->setObject(cocos2d::CCString::create("icon_25"), "geometry.ach.stars03");
    dict->setObject(cocos2d::CCString::create("color2_09"), "geometry.ach.rateDiff");
    dict->setObject(cocos2d::CCString::create("death_06"), "geometry.ach.shardLava05");
    dict->setObject(cocos2d::CCString::create("ball_03"), "geometry.ach.coins07");
    dict->setObject(cocos2d::CCString::create("icon_105"), "geometry.ach.shardPoison03");
    dict->setObject(cocos2d::CCString::create("special_03"), "geometry.ach.like04");
    dict->setObject(cocos2d::CCString::create("icon_58"), "geometry.ach.mappacks08");
    dict->setObject(cocos2d::CCString::create("dart_15"), "geometry.ach.stars17");
    dict->setObject(cocos2d::CCString::create("dart_20"), "geometry.ach.shardShadow01");
    dict->setObject(cocos2d::CCString::create("bird_28"), "geometry.ach.usercoins32");
    dict->setObject(cocos2d::CCString::create("bird_05"), "geometry.ach.jump04");
    dict->setObject(cocos2d::CCString::create("color_23"), "geometry.ach.rateDiff03");
    dict->setObject(cocos2d::CCString::create("death_02"), "geometry.ach.shardFire05");
    dict->setObject(cocos2d::CCString::create("color2_14"), "geometry.ach.attempt03");
    dict->setObject(cocos2d::CCString::create("bird_24"), "geometry.ach.diamonds08");
    dict->setObject(cocos2d::CCString::create("icon_46"), "geometry.ach.creator01");
    dict->setObject(cocos2d::CCString::create("icon_56"), "geometry.ach.coins22");
    dict->setObject(cocos2d::CCString::create("icon_99"), "geometry.ach.usercoins22");
    dict->setObject(cocos2d::CCString::create("icon_54"), "geometry.ach.usercoins12");
    dict->setObject(cocos2d::CCString::create("icon_55"), "geometry.ach.secret11");
    dict->setObject(cocos2d::CCString::create("color2_31"), "geometry.ach.twitter");
    dict->setObject(cocos2d::CCString::create("ship_07"), "geometry.ach.stars07");
    dict->setObject(cocos2d::CCString::create("color2_18"), "geometry.ach.special01");
    dict->setObject(cocos2d::CCString::create("icon_49"), "geometry.ach.usercoins02");
    dict->setObject(cocos2d::CCString::create("icon_12"), "geometry.ach.custom02");
    dict->setObject(cocos2d::CCString::create("color_24"), "geometry.ach.level19a");
    dict->setObject(cocos2d::CCString::create("icon_15"), "geometry.ach.level09a");
    dict->setObject(cocos2d::CCString::create("icon_38"), "geometry.ach.coins12");
    dict->setObject(cocos2d::CCString::create("spider_06"), "geometry.ach.shardIce03");
    dict->setObject(cocos2d::CCString::create("icon_92"), "geometry.ach.shardLava02");
    dict->setObject(cocos2d::CCString::create("bird_22"), "geometry.ach.shardBonus02");
    dict->setObject(cocos2d::CCString::create("color2_17"), "geometry.ach.attempt04");
    dict->setObject(cocos2d::CCString::create("ship_30"), "geometry.ach.stars22");
    dict->setObject(cocos2d::CCString::create("color_37"), "geometry.ach.v2.secret07");
    dict->setObject(cocos2d::CCString::create("ship_10"), "geometry.ach.mappacks02");
    dict->setObject(cocos2d::CCString::create("bird_16"), "geometry.ach.creator02");
    dict->setObject(cocos2d::CCString::create("color_22"), "geometry.ach.like03");
    dict->setObject(cocos2d::CCString::create("ball_24"), "geometry.ach.shardFire02");
    dict->setObject(cocos2d::CCString::create("icon_41"), "geometry.ach.secret02");
    dict->setObject(cocos2d::CCString::create("color_10"), "geometry.ach.level07a");
    dict->setObject(cocos2d::CCString::create("color_20"), "geometry.ach.level17a");
    dict->setObject(cocos2d::CCString::create("color2_12"), "geometry.ach.jump03");
    dict->setObject(cocos2d::CCString::create("icon_87"), "geometry.ach.diamonds02");
    dict->setObject(cocos2d::CCString::create("icon_21"), "geometry.ach.demon03");
    dict->setObject(cocos2d::CCString::create("robot_15"), "geometry.ach.usercoins29");
    dict->setObject(cocos2d::CCString::create("ball_12"), "geometry.ach.secret03b");
    dict->setObject(cocos2d::CCString::create("ship_20"), "geometry.ach.secret13");
    dict->setObject(cocos2d::CCString::create("icon_14"), "geometry.ach.level08b");
    dict->setObject(cocos2d::CCString::create("icon_45"), "geometry.ach.level18b");
    dict->setObject(cocos2d::CCString::create("color2_26"), "geometry.ach.friends01");
    dict->setObject(cocos2d::CCString::create("ball_02"), "geometry.ach.coins02");
    dict->setObject(cocos2d::CCString::create("icon_60"), "geometry.ach.demoncoin02");
    dict->setObject(cocos2d::CCString::create("ship_22"), "geometry.ach.usercoins19");
    dict->setObject(cocos2d::CCString::create("ball_09"), "geometry.ach.stars12");
    dict->setObject(cocos2d::CCString::create("ship_13"), "geometry.ach.custom04");
    dict->setObject(cocos2d::CCString::create("ball_15"), "geometry.ach.mappacks09");
    dict->setObject(cocos2d::CCString::create("color_08"), "geometry.ach.level05a");
    dict->setObject(cocos2d::CCString::create("color_17"), "geometry.ach.level15a");
    dict->setObject(cocos2d::CCString::create("bird_07"), "geometry.ach.coins16");
    dict->setObject(cocos2d::CCString::create("icon_57"), "geometry.ach.rateDiff04");
    dict->setObject(cocos2d::CCString::create("dart_03"), "geometry.ach.attempt05");
    dict->setObject(cocos2d::CCString::create("ship_23"), "geometry.ach.usercoins09");
    dict->setObject(cocos2d::CCString::create("dart_17"), "geometry.ach.diamonds09");
    dict->setObject(cocos2d::CCString::create("icon_63"), "geometry.ach.creator03");
    dict->setObject(cocos2d::CCString::create("robot_08"), "geometry.ach.stars26");
    dict->setObject(cocos2d::CCString::create("icon_10"), "geometry.ach.level06b");
    dict->setObject(cocos2d::CCString::create("icon_42"), "geometry.ach.level16b");
    dict->setObject(cocos2d::CCString::create("spider_05"), "geometry.ach.shardPoison04");
    dict->setObject(cocos2d::CCString::create("color2_21"), "geometry.ach.secret04");
    dict->setObject(cocos2d::CCString::create("ship_28"), "geometry.ach.shardShadow02");
    dict->setObject(cocos2d::CCString::create("icon_81"), "geometry.ach.v2.secret04");
    dict->setObject(cocos2d::CCString::create("ship_08"), "geometry.ach.demon07");
    dict->setObject(cocos2d::CCString::create("color_06"), "geometry.ach.level03a");
    dict->setObject(cocos2d::CCString::create("color_16"), "geometry.ach.level13a");
    dict->setObject(cocos2d::CCString::create("icon_24"), "geometry.ach.stars02");
    dict->setObject(cocos2d::CCString::create("special_04"), "geometry.ach.secret15");
    dict->setObject(cocos2d::CCString::create("color_27"), "geometry.ach.friends02");
    dict->setObject(cocos2d::CCString::create("color_15"), "geometry.ach.coins06");
    dict->setObject(cocos2d::CCString::create("icon_08"), "geometry.ach.level04b");
    dict->setObject(cocos2d::CCString::create("color_04"), "geometry.ach.world.level001b");
    dict->setObject(cocos2d::CCString::create("color2_15"), "geometry.ach.level14b");
    dict->setObject(cocos2d::CCString::create("color2_23"), "geometry.ach.like02");
    dict->setObject(cocos2d::CCString::create("ball_29"), "geometry.ach.usercoins26");
    dict->setObject(cocos2d::CCString::create("ship_31"), "geometry.ach.shardIce04");
    dict->setObject(cocos2d::CCString::create("icon_40"), "geometry.ach.custom06");
    dict->setObject(cocos2d::CCString::create("dart_09"), "geometry.ach.stars16");
    dict->setObject(cocos2d::CCString::create("color2_11"), "geometry.ach.jump02");
    dict->setObject(cocos2d::CCString::create("dart_05"), "geometry.ach.rateDiff02b");
    dict->setObject(cocos2d::CCString::create("color_04"), "geometry.ach.level01a");
    dict->setObject(cocos2d::CCString::create("color_13"), "geometry.ach.level11a");
    dict->setObject(cocos2d::CCString::create("color_29"), "geometry.ach.level21a");
    dict->setObject(cocos2d::CCString::create("icon_52"), "geometry.ach.usercoins16");
    dict->setObject(cocos2d::CCString::create("special_02"), "geometry.ach.mappacks03");
    dict->setObject(cocos2d::CCString::create("ball_14"), "geometry.ach.coins21");
    dict->setObject(cocos2d::CCString::create("color2_38"), "geometry.ach.v3.secret03");
    dict->setObject(cocos2d::CCString::create("icon_06"), "geometry.ach.level02b");
    dict->setObject(cocos2d::CCString::create("icon_27"), "geometry.ach.level12b");
    dict->setObject(cocos2d::CCString::create("robot_11"), "geometry.ach.diamonds03");
    dict->setObject(cocos2d::CCString::create("bird_13"), "geometry.ach.usercoins06");
    dict->setObject(cocos2d::CCString::create(" "), "geometry.ach.secret06");
    dict->setObject(cocos2d::CCString::create("robot_13"), "geometry.ach.shardBonus04");
    dict->setObject(cocos2d::CCString::create("icon_64"), "geometry.ach.secret17");
    dict->setObject(cocos2d::CCString::create("ship_35"), "geometry.ach.demon12");
    dict->setObject(cocos2d::CCString::create("ship_05"), "geometry.ach.stars06");
    dict->setObject(cocos2d::CCString::create("color_06"), "geometry.ach.world.level003b");
    dict->setObject(cocos2d::CCString::create("color2_08"), "geometry.ach.like");
    dict->setObject(cocos2d::CCString::create("icon_80"), "geometry.ach.v2.secret01");
    dict->setObject(cocos2d::CCString::create("ship_17"), "geometry.ach.custom08");
    dict->setObject(cocos2d::CCString::create("ship_14"), "geometry.ach.coins11");
    dict->setObject(cocos2d::CCString::create("robot_05"), "geometry.ach.level20b");
    dict->setObject(cocos2d::CCString::create("icon_18"), "geometry.ach.level10b");
    dict->setObject(cocos2d::CCString::create("color_34"), "geometry.ach.stars21");
    dict->setObject(cocos2d::CCString::create("color_30"), "geometry.ach.usercoins23");
    dict->setObject(cocos2d::CCString::create("icon_88"), "geometry.ach.coins25");
    dict->setObject(cocos2d::CCString::create("icon_48"), "geometry.ach.steam02");
    dict->setObject(cocos2d::CCString::create("icon_20"), "geometry.ach.demon02");
    dict->setObject(cocos2d::CCString::create("color2_05"), "geometry.ach.jump01");
    dict->setObject(cocos2d::CCString::create("dart_07"), "geometry.ach.usercoins13");
    dict->setObject(cocos2d::CCString::create("bird_11"), "geometry.ach.secret08");
    dict->setObject(cocos2d::CCString::create("icon_75"), "geometry.ach.world.level010b");
    dict->setObject(cocos2d::CCString::create("icon_72"), "geometry.ach.world.level005b");
    dict->setObject(cocos2d::CCString::create("icon_31"), "geometry.ach.coins01");
    dict->setObject(cocos2d::CCString::create("color2_04"), "geometry.ach.moreGames");
    dict->setObject(cocos2d::CCString::create("dart_04"), "geometry.ach.usercoins03");
    dict->setObject(cocos2d::CCString::create("death_09"), "geometry.ach.shardIce05");
    dict->setObject(cocos2d::CCString::create("death_04"), "geometry.ach.shardPoison05");
    dict->setObject(cocos2d::CCString::create("ship_18"), "geometry.ach.stars11");
    dict->setObject(cocos2d::CCString::create("robot_07"), "geometry.ach.shardLava03");
    dict->setObject(cocos2d::CCString::create("bird_26"), "geometry.ach.shardShadow03");
    dict->setObject(cocos2d::CCString::create("ship_12"), "geometry.ach.coins15");
    dict->setObject(cocos2d::CCString::create("color2_33"), "geometry.ach.v2.secret08");
    dict->setObject(cocos2d::CCString::create("ship_11"), "geometry.ach.mappacks04");
    dict->setObject(cocos2d::CCString::create("icon_83"), "geometry.ach.stars25");
    dict->setObject(cocos2d::CCString::create("ship_33"), "geometry.ach.usercoins30");
    dict->setObject(cocos2d::CCString::create("robot_09"), "geometry.ach.shardFire03");
    dict->setObject(cocos2d::CCString::create("color_38"), "geometry.ach.diamonds04");
    dict->setObject(cocos2d::CCString::create("ship_06"), "geometry.ach.demon06");
    dict->setObject(cocos2d::CCString::create("ball_18"), "geometry.ach.usercoins20");
    dict->setObject(cocos2d::CCString::create("color_10"), "geometry.ach.world.level007b");
    dict->setObject(cocos2d::CCString::create("icon_23"), "geometry.ach.stars01");
    dict->setObject(cocos2d::CCString::create("icon_59"), "geometry.ach.demoncoin03");
    dict->setObject(cocos2d::CCString::create("icon_32"), "geometry.ach.coins05");
    dict->setObject(cocos2d::CCString::create("ball_17"), "geometry.ach.usercoins10");
    dict->setObject(cocos2d::CCString::create("ship_19"), "geometry.ach.stars15");
    return dict;
}


int AchievementManager::percentForAchievement(char *achievement){  
  return (reinterpret_cast<cocos2d::CCString*>(m_reportedAchievements->valueForKey(achievement)))->intValue();
}

cocos2d::CCDictionary * AchievementManager::getAchievementsWithID(const char *ID){
    return reinterpret_cast<cocos2d::CCDictionary*>m_platformAchievements->objectForKey(std::string(ID));
}


bool AchievementManager::isAchievementAvailable(std::string achievement)
{
    cocos2d::CCDictionary * achievements = getAchievementsWithID(this, achievement->c_str());
    if (achievements != nullptr) {
        return (bool)(achievements->objectForKey("un" + achievement) == nullptr);
    }
    return false;
}



int AchievementManager::limitForAchievement(std::string achievement)
{
    cocos2d::CCDictionary *achievements = getAchievementsWithID(achievement->c_str());
    if (achievements != nullptr) {
        cocos2d::CCString* str = reinterpret_cast<cocos2d::CCString *>(cocos2d::CCDictionary::objectForKey(achievements,"limits"));
        if (str != nullptr) {
            return str->intValue(str);
        }
    }
    return 0;
}

/* TODO */
class AchievementNotifier;

void AchievementManager::notifyAchievement(const char* title,const char* achievedDescription, const char* icon)
{  
    if (!m_dontNotify) {
        AchievementNotifier::sharedState()->notifyAchievement(title, achievedDescription, icon ,1);
    }
}


void AchievementManager::notifyAchievementWithID(const char *ID)
{
    if (!m_dontNotify) {
        cocos2d::CCDictionary* dict = getAchievementsWithID(ID);
        if (dict != nullptr) {       
            const char* title = reinterpret_cast<cocos2d::CCString*>(dict->valueForKey("title"))->getCString();
            const char* achievedDescription = reinterpret_cast<cocos2d::CCString*>(dict->valueForKey("achievedDescription"))->getCString();
            const char* icon = reinterpret_cast<cocos2d::CCString*>(dict->valueForKey("icon"))->getCString();
            AchievementNotifier::sharedState()->notifyAchievement(notifier,title,achievedDescription,icon,0);
        }
    }
}

float AchievementManager::percentageForCount(int a, int b){
    float unknown;
    float answer = floorf((a / b) * 100.0);
    if ((answer < 100.0) << 0x1f < 0) {
        unknown = answer;
    }
    if (-1 < answer) {
        answer = 1.401298e-43;
    }
    if (answer < 0) {
        answer = unknown;
    }
    return answer;
}

int AchievementManager::percentForAchievement(char *achievement)
{ 
  return (reinterpret_cast<cocos2d::CCString*>(m_reportedAchievements->valueForKey(std::string(achievement))))->intValue();
}

/* AchievementManager::reportAchievementWithID(char const*, int, bool) */

void AchievementManager::reportAchievementWithID(const char *ID,int percent,bool levelCompleted)
{
    if (isAchievementEarned(ID)) {
        if (percent > percentForAchievement(ID)) {
            if (percent > 99) {
                percent = 100;
            }
            m_reportedAchievements->setObject(cocos2d::CCString::createWithFormat("%i",percent),std::string(achievement));
            reportPlatformAchievementWithID(ID,percent);
        }
        /* The 99% achievement */
        if ((percent > 99) && (!levelCompleted)) {   
            sharedState()->notifyAchievementWithID(ID);
        }
    }
}



void AchievementManager::reportPlatformAchievementWithID(const char *ID,int _report)
{
    auto dict = getAchievementsWithID(ID);
    if (m_platformAchievements != nullptr) {
        auto googleID = reinterpret_cast<cocos2d::CCString*>(dict->valueForKey("googleID"));
        if (googleID != nullptr) {
            if (std::string(googleID->getCString()) == "") {
                PlatformToolbox::reportAchievementWithID(googleID, _report);
            }
        }
    }
}

void AchievementManager::resetAchievement(const char *achievementName)
{
    return m_reportedAchievements->removeObjectForKey(std::string(achievementName));
}

void AchievementManager::resetAchievements(){
    return m_reportedAchievements->removeAllObjects();
}




void AchievementManager::storeAchievementUnlocks(){
    cocos2d::CCString* strObj;
    if (m_achievementUnlocks == nullptr) {
        m_achievementUnlocks = cocos2d::CCDictionary::create();
        m_achievementUnlocks->retain();
        cocos2d::CCArray* pfkeys = m_platformAchievements->allKeys();
        for (index = 0; index < pfkeys; index++) {
            cocos2d::CCDictionary* dict = reinterpret_cast<cocos2d::CCDictionary*>(m_platformAchievements->objectForKey(pfkeys->stringAtIndex(index)->getCString()));
            cocos2d::CCString* icon = reinterpret_cast<cocos2d::CCString*>(cocos2d::CCDictionary::objectForKey(dict,"icon"));
            if (icon != nullptr) {
                std::string iconStr(icon->getCString());
                if (iconStr.size() != 0) {
                    strObj = cocos2d::CCString::create(key);
                    m_achievementUnlocks->setObject(strObj, std::string(strObj->getCString()));
                }
            }
        }
    } 
}




AchievementManager *GLOBAL_AchievementManager;

AchievementManager * AchievementManager::sharedState()
{
    if (GLOBAL_AchievementManager == nullptr) {
        GLOBAL_AchievementManager = new AchievementManager;
        GLOBAL_AchievementManager->m_allAchievements = nullptr;
        GLOBAL_AchievementManager->m_platformAchievements = nullptr;
        GLOBAL_AchievementManager->m_achievementUnlocks = nullptr;
        // GLOBAL_AchievementManager->field173_0x114 = 0;
        GLOBAL_AchievementManager->m_reportedAchievements = nullptr;
        GLOBAL_AchievementManager->m_dontNotify = false;
        GLOBAL_AchievementManager->m_allAchievementsSorted = nullptr;
        // Unknown...
        // GLOBAL_AchievementManager->field180_0x124 = 0;
        // GLOBAL_AchievementManager->field181_0x128 = (CCString *)0x0;
        GLOBAL_AchievementManager = this;
        GLOBAL_AchievementManager->init();
    }
    return GLOBAL_AchievementManager;
}
