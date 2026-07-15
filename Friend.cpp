#include "Friend.h"
#include <iostream>
using namespace std;

Friend::Friend() : Character()
{
    supportLevel = 0;
    adviceType = "General";
    rewardItem = "Friendship Bracelet";
    rewardGiven = false;

    introDialogue = "Your friend checks in on you.";
    adviceDialogue = "Do not lose yourself for validation.";
    rewardDialogue = "Your friend gives you something meaningful."; //this stuff is so generic PLEASE change this i'm sleepless
}

Friend::Friend(string newName, string newDialogue, string newLocation, int newSupportLevel, string newAdviceType, string newRewardItem)
    : Character(newName, newDialogue, newLocation)
{
    supportLevel = newSupportLevel;
    adviceType = newAdviceType;
    rewardItem = newRewardItem;
    rewardGiven = false;

    introDialogue = newDialogue;
    adviceDialogue = "Do not lose yourself for validation.";
    rewardDialogue = "Your friend gives you something meaningful.";
}

int Friend::getSupportLevel()
{
    return supportLevel;
}

string Friend::getAdviceType()
{
    return adviceType;
}

string Friend::getRewardItem()
{
    return rewardItem;
}

bool Friend::isRewardGiven()
{
    return rewardGiven;
}

void Friend::setSupportLevel(int newSupportLevel)
{
    supportLevel = newSupportLevel;

    if (supportLevel > 100)
    {
        supportLevel = 100;
    }

    if (supportLevel < 0)
    {
        supportLevel = 0;
    }
}

void Friend::setAdviceType(string newAdviceType)
{
    adviceType = newAdviceType;
}

void Friend::setRewardItem(string newRewardItem)
{
    rewardItem = newRewardItem;
}

void Friend::setFriendDialogues(string newIntroDialogue, string newAdviceDialogue, string newRewardDialogue)
{
    introDialogue = newIntroDialogue;
    adviceDialogue = newAdviceDialogue;
    rewardDialogue = newRewardDialogue;
}

void Friend::displayFriend()
{
    cout << endl;
    cout << "Name: " << getName() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Support Level: " << supportLevel << " / 100" << endl;
    cout << "Advice Type: " << adviceType << endl;
    cout << "Reward Item: " << rewardItem << endl;
}

string Friend::interact()
{
    string earnedItem = "";

    cout << endl;
    cout << "You spend time with " << getName() << "." << endl;
    cout << getName() << ": " << introDialogue << endl;
    cout << getName() << ": " << adviceDialogue << endl;

    supportLevel = supportLevel + 20;

    if (supportLevel > 100)
    {
        supportLevel = 100;
    }

    cout << "Support increased to " << supportLevel << "." << endl;
    cout << "Self points restored from this interaction: 10" << endl; //BUT SHOULD I DISPLAY THIS?

    if (supportLevel >= 100 && rewardGiven == false)
    {
        cout << getName() << ": " << rewardDialogue << endl;
        cout << "Unlocked item: " << rewardItem << endl;

        earnedItem = rewardItem;
        rewardGiven = true;
    }

    return earnedItem;
}