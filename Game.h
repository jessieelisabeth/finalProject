#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Item.h"
#include "BundleOfJoy.h"
#include "LoveInterest.h"
#include "Friend.h"
#include <string>
using namespace std;

class Game {
private:
    Player player;
    BundleOfJoy bundle;

    LoveInterest loveInterests[5];
    Friend friends[4];

    int loveInterestCount;
    int friendCount;
    bool running;

    Item makeItemByName(string itemName);

    void showMenu();
    void talkToLoveInterest();
    void talkToFriend();
    void donateToBundle();
    void endDay();
    void displayEnding();
    void displayGameTips();
    void useUnHinge();
    void perfectDate(); //my secret minigame!!!
    void displayCredits();
    void travel();

public:
    Game();
    void run();
};

#endif