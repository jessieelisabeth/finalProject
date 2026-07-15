#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Item.h"
using namespace std;

class Player
{
private:
    string name;
    int currentDay;
    int energy;
    int selfWorth;
    int loveInterestPoints;
    int friendshipPoints;
    int jojaInfluence;
    string currentLocation;

    Item inventory[20];
    int inventorySize;

public:
    Player();
    Player(string newName);

    string getName();
    int getCurrentDay();
    int getEnergy();
    int getSelfWorth();
    int getLoveInterestPoints();
    int getFriendshipPoints();
    int getJojaInfluence();
    string getCurrentLocation();

    void setName(string newName);
    void setCurrentLocation(string newLocation);

    void loseEnergy(int amount);
    void gainEnergy(int amount);

    void loseSelfWorth(int amount);
    void gainSelfWorth(int amount);

    void addLoveInterestPoints(int amount);
    void addFriendshipPoints(int amount);
    void addJojaInfluence(int amount);

    void nextDay();

    void addItem(Item newItem);
    bool hasItem(string itemName);
    bool removeItem(string itemName);
    void displayInventory();

    void showStats();
};

#endif