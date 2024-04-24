#include "includes.h"



/* TODO: More functions when PlayLayer Gets Re-reversed or Redone... */







/* This code is a Freebie From Robtop's Twitch Stream :  https://youtube.com/watch?v=eBcUC9lYLdI : 12:00 
 * I would give eatch switchcase a "break;" to match robtop's version but it's not nessesary 
 * since we're always returning with a constant character */

const char * EndLevelLayer::getEndText(){
    int idx = rand();
    if (!GameManager::sharedState()->getGameVariable("0095")) {
        switch(idx % 18) {
            case 2: return "Good Job!";
            case 3: return "Well Done!";
            case 4: return "Impressive!";
            case 5: return "Amazing!";
            case 6: return "Incredible!";
            case 7: return "Skillful!";
            case 8: return "Brilliant!";
            case 9: return "You are... The One!";
            case 10: return "How is this possible!?";
            case 11: return "You beat me...";
            case 12: return "Challenge Breaker!";
            case 13: return "I am speechless...";
            case 14: return "Reflex Master!";
            case 15: return "Not bad!";
            case 16: return "Warp Speed!";
            case 17: return "Y u do dis?";
            default: return "Awesome!";
        }
    }

    /* Do Not... end texts */

    /* I'll give you all a little bit of trivia 
     * comments to some of these since 
     * there's a lot of easter eggs to unravel - Calloc */

    switch(idx % 100) {
        case 1: return "Took you long enough..."; 
        case 2: return "Teach me oh great one";
        case 3: return "Haxxor?";
        case 4: return "Tripple spikes?";
        case 5: return "RubRubRubRubRubRub";
        case 6: return "SO FAST";
        case 7: return "Hmmmmmmmmmmm";
        case 8: return "Ship part was cool";
        case 9: return "Timing could be better";
        case 10: return "I cant hear the music.";
        case 11: return "Pump. It. Up.";
        case 12: return "I am Batman";
        case 13: return "Take a break.";
        case 14: return "AFK";
        case 15: return "he protec";
        case 16: return "Kappa"; /* Kappa */
        case 17: return "lol is lol backwards";
        case 18: return "Dr. Click";
        case 19: return "Speedrun complete";
        case 20: return "YEEEEEEEEEEEEEEEEEEES!";
        case 21: return "Why are we here, just to suffer?";
        case 22: return "HOW!?";
        case 23: return "Task failed successfully";
        case 24: return "ok boomling"; /* Reference to "Ok Boomer" */
        case 25: return "I am not not impressed";
        case 26: return "You are inevitable"; /* "I am, Inevitable" - Thanos */
        case 27: return "Sorry I fell asleep. Do it again?";
        case 28: return "Did we win?";
        case 29: return "Big brain moment";
        case 30: return "E";
        case 31: return "Nice song";
        case 32: return "QUACK";
        case 33: return "OMG Poggers";
        case 34: return "pogchamp";
        case 35: return "That\'s Sus"; /* Amongus */
        case 36: return "BASED";
        case 37: return "Fluked";
        case 38: return "RubRub Approves";
        case 39: return "NOICE";
        case 40: return "You were not the Impostor"; /* Amongus */
        case 41: return "I have the highground"; /* Star Wars Revenge Of The Sith */
        case 42: return "You got the W";
        case 43: return "After a mental breakdown";
        case 44: return "Not 1 attempt but ok";
        case 45: return "Cool, now beat it with your eyes closed";
        case 46: return "Some doubted... it happened";
        case 47: return "Press alt + f4 for secret way";
        case 48: return "Are ya winning son?"; /* MEME */
        case 49: return "el pepe";
        case 50: return "LET\'S ROCK IT!";
        case 51: return "Well done... Now try to complete it without any checkpoints!";
        case 52: return "You\'re cheating aren\'t you?";
        case 53: return "YOU CANNOT VERIFY A LEVEL IF IT HAS A START POSITION!";
        case 54: return "That doesnt count";
        case 55: return "why am i argentina";
        case 56: return "You are fuk map"; /* Cursed Gd comment that got reposted like crazy*/
        case 57: return "Robert Game";
        case 58: return "You can now play as Luigi!"; /* Mario Galaxy */
        case 59: return "these nuts";
        case 60: return "What the BEEP was that?";
        case 61: return "do it again I wasn\'t looking";
        case 62: return "youre going to brazil"; /* MEME */
        case 63: return "Never Gonna Give You Up"; /* RickRoll */
        case 64: return "You cannot level a verify if the start pos has a checkpoint.";
        case 65: return "You popped off fr.";
        case 66: return "EMERGENCY MEETING!!!"; /* Amongus */
        case 67: return "L";
        case 68: return "huhu yo";
        case 69: return "u have winned";
        case 70: return "We\'re making balls ladies and gentleman";
        case 71: return "I like ya cut G";
        case 72: return "HOW";
        case 73: return "Not impressive I beat that in like 2 seconds";
        case 74: return "Does anyone read this?";
        case 75: return "Uh oh, forgot to record";
        case 76: return "Boy that\'s cap";
        case 77: return "Time to go outside";
        case 78: return "F in the chat"; /* Press "F" to pay respects */
        case 79: return "Don\'t forget to thank the bus driver";
        case 80: return "I can\'t believe you\'ve done this";
        case 81: return "Take a break!";
        case 82: return "Update 2.3 coming soon";
        case 83: return "She\'s in love with the concept..."; /* Geometry Dash Song */
        case 84: return "RobTop said funny messages, not cringe";
        case 85: return "You\'re a pro? Name every Demon then";
        case 86: return "poggie woggie";
        case 87: return "Well yes, but actually no."; /* MEME */
        case 88: return "Robala Topala approves";
        case 89: return "Ropert Topert disapproves";
        case 90: return "Never before have I seen such skill";
        case 91: return "Listen here you little...";
        case 92: return "kinda sloppy but ok u win";
        case 93: return "This is why you have no friends";
        case 94: return "BEHOLD, an endscreen comment!";
        case 95: return "To be continued..."; /* To be Continued... https://youtube.com/watch?v=ChgsdBN0VHM  */
        case 96: return "Have you just... DASHED it???";
        case 97: return "Why am I spending time on these messages";
        case 98: return "Harder than FNF";
        case 99: return "BUT BRO, DO YOU EVEN LIFT!?";
        default: return "DROP THE BEAT";
    }
}



bool EndLevelLayer::init(PlayLayer *pLayer)
{
    this->m_playLayer = pLayer;
    return GJDropDownLayer::init(" ", 230.0, true);
}




