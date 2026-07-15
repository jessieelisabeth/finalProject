#ifndef LOVEINTEREST_H
#define LOVEINTEREST_H

#include "Character.h"
#include <string>
using namespace std;

class LoveInterest : public Character
{
private:
    string routeName;
    int romanceLevel;
    int redFlagLevel;

    string earlyDialogue;
    string middleDialogue;
    string lateDialogue;

public:
    LoveInterest();
    LoveInterest(string newName, string newDialogue, string newLocation, string newRouteName, int newRedFlagLevel);

    string getRouteName();
    int getRomanceLevel();
    int getRedFlagLevel();

    void setRouteName(string newRouteName);
    void setRomanceLevel(int newRomanceLevel);
    void setRedFlagLevel(int newRedFlagLevel);

    void setRouteDialogues(string newEarlyDialogue, string newMiddleDialogue, string newLateDialogue);

    void displayLoveInterest();
    int interact();
};

#endif