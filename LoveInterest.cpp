#include "LoveInterest.h"
#include <iostream>
using namespace std;

LoveInterest::LoveInterest() : Character()
{
    routeName = "Unknown Route";
    romanceLevel = 0;
    redFlagLevel = 0;

    earlyDialogue = "good";
    middleDialogue = "neut";
    lateDialogue = "evil";
}

LoveInterest::LoveInterest(string newName, string newDialogue, string newLocation, string newRouteName, int newRedFlagLevel)
    : Character(newName, newDialogue, newLocation)
{
    routeName = newRouteName;
    romanceLevel = 0;
    redFlagLevel = newRedFlagLevel;

    earlyDialogue = newDialogue;
    middleDialogue = "when they're kind of turning evil";
    lateDialogue = "ok fully evil.";
}

string LoveInterest::getRouteName()
{
    return routeName;
}

int LoveInterest::getRomanceLevel()
{
    return romanceLevel;
}

int LoveInterest::getRedFlagLevel()
{
    return redFlagLevel;
}

void LoveInterest::setRouteName(string newRouteName)
{
    routeName = newRouteName;
}

void LoveInterest::setRomanceLevel(int newRomanceLevel)
{
    romanceLevel = newRomanceLevel;

    if (romanceLevel > 100)
    {
        romanceLevel = 100;
    }

    if (romanceLevel < 0)
    {
        romanceLevel = 0;
    }
}

void LoveInterest::setRedFlagLevel(int newRedFlagLevel)
{
    redFlagLevel = newRedFlagLevel;
}

void LoveInterest::setRouteDialogues(string newEarlyDialogue, string newMiddleDialogue, string newLateDialogue)
{
    earlyDialogue = newEarlyDialogue;
    middleDialogue = newMiddleDialogue;
    lateDialogue = newLateDialogue;
}

void LoveInterest::displayLoveInterest()
{
    cout << endl;
    cout << "Name: " << getName() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Route: " << routeName << endl;
    cout << "Romance Level: " << romanceLevel << " / 100" << endl;
    cout << "Red Flag Level: " << redFlagLevel << " / 10" << endl; //doubtful about putting this in but we'll see
}

int LoveInterest::interact() //everything here is about the loveinterests and what they can do to player stats.
{
    int selfWorthDamage = 0;

    cout << endl;
    cout << "You've spent time with  " << getName() << "." << endl;

    if (romanceLevel < 30)
    {
        cout << getName() << ": " << earlyDialogue << endl; //the higher the romanceLevel the worse the dialogue gets essentially.
        romanceLevel = romanceLevel + 15;
        selfWorthDamage = 2;
    }
    else if (romanceLevel < 70)
    {
        cout << getName() << ": " << middleDialogue << endl;
        romanceLevel = romanceLevel + 20;
        selfWorthDamage = redFlagLevel; // skeptical of making it equal although selfworthdamage increases exponentionally after this, maybe randomize it?
    }
    else
    {
        cout << getName() << ": " << lateDialogue << endl;
        romanceLevel = romanceLevel + 25;
        selfWorthDamage = redFlagLevel + 8;
    }

    if (romanceLevel > 100)
    {
        romanceLevel = 100;
    }

    cout << "Romance increased to " << romanceLevel << "." << endl;
    cout << "Self damage from this interaction: " << selfWorthDamage << endl;

    return selfWorthDamage;
}