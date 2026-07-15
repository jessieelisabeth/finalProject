#ifndef FRIEND_H
#define FRIEND_H

#include "Character.h"
#include <string>
using namespace std;

class Friend : public Character {
private:
    int supportLevel;
    string adviceType;
    string rewardItem;
    bool rewardGiven;

    string introDialogue;
    string adviceDialogue;
    string rewardDialogue; // do we really need to model all these dialogues based off a similar structure to love interests? OR is it evil and reserved for love interst...

public:
    Friend();
    Friend(string newName, string newDialogue, string newLocation, int newSupportLevel, string newAdviceType, string newRewardItem);

    int getSupportLevel();
    string getAdviceType();
    string getRewardItem();
    bool isRewardGiven();

    void setSupportLevel(int newSupportLevel);
    void setAdviceType(string newAdviceType);
    void setRewardItem(string newRewardItem);

    void setFriendDialogues(string newIntroDialogue, string newAdviceDialogue, string newRewardDialogue);

    void displayFriend();
    string interact();
};

#endif