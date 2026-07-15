#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name = "Player";
    currentDay = 1;
    energy = 10;
    selfWorth = 100;
    loveInterestPoints = 0;
    friendshipPoints = 0;
    jojaInfluence = 0; //check
    currentLocation = "Bedroom";
    inventorySize = 0;
}

Player::Player(string newName)
{
    name = newName;
    currentDay = 1;
    energy = 10;
    selfWorth = 100;
    loveInterestPoints = 0;
    friendshipPoints = 0;
    jojaInfluence = 0;
    currentLocation = "Bedroom";
    inventorySize = 0;
}

string Player::getName()
{
    return name;
}

int Player::getCurrentDay()
{
    return currentDay;
}

int Player::getEnergy()
{
    return energy;
}

int Player::getSelfWorth()
{
    return selfWorth;
}

int Player::getLoveInterestPoints()
{
    return loveInterestPoints;
}

int Player::getFriendshipPoints()
{
    return friendshipPoints;
}

int Player::getJojaInfluence()
{
    return jojaInfluence;
}

string Player::getCurrentLocation()
{
    return currentLocation;
}

void Player::setName(string newName)
{
    name = newName;
}

void Player::setCurrentLocation(string newLocation)
{
    currentLocation = newLocation;
}

void Player::loseEnergy(int amount)
{
    energy = energy - amount;

    if (energy < 0)
    {
        energy = 0;
    }
}

void Player::gainEnergy(int amount)
{
    energy = energy + amount;

    if (energy > 10)
    {
        energy = 10;
    }
}

void Player::loseSelfWorth(int amount)
{
    selfWorth = selfWorth - amount;

    if (selfWorth < 0)
    {
        selfWorth = 0;
    }
}

void Player::gainSelfWorth(int amount)
{
    selfWorth = selfWorth + amount;

    if (selfWorth > 100)
    {
        selfWorth = 100;
    }
}

void Player::addLoveInterestPoints(int amount)
{
    loveInterestPoints = loveInterestPoints + amount;

    if (loveInterestPoints > 100)
    {
        loveInterestPoints = 100;
    }
}

void Player::addFriendshipPoints(int amount)
{
    friendshipPoints = friendshipPoints + amount;

    if (friendshipPoints > 100)
    {
        friendshipPoints = 100;
    }
}

void Player::addJojaInfluence(int amount) //just naming this jojaInfluence for now because i have no idea what to name it and i kind of want to give it more of a sparkly backstory.
{
    jojaInfluence = jojaInfluence + amount;
}

void Player::nextDay()
{
    currentDay = currentDay + 1;
    energy = 10;
}

void Player::addItem(Item newItem) {
    if (inventorySize < 20)   {
        inventory[inventorySize] = newItem;
        inventorySize = inventorySize + 1;
        cout << "Added to inventory: " << newItem.getName() << endl;
    }
    else
    {
        cout << "Your inventory is full!" << endl;
    }
}

bool Player::hasItem(string itemName)
{
    for (int i = 0; i < inventorySize; i++) {
        if (inventory[i].getName() == itemName)
        {
            return true;
        }
    }

    return false;
}

bool Player::removeItem(string itemName)
{
    for (int i = 0; i < inventorySize; i++)
    {
        if (inventory[i].getName() == itemName)
        {
            for (int j = i; j < inventorySize - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }

            inventorySize = inventorySize - 1;
            return true;
        }
    }

    return false;
}

void Player::displayInventory()
{
    cout << endl;
    cout << "inventory" << endl;

    if (inventorySize == 0)
    {
        cout << "Your inventory is empty." << endl;
    }
    else
    {
        for (int i = 0; i < inventorySize; i++)
        {
            cout << i + 1 << ". ";
            inventory[i].displayItem();
        }
    }

    cout << "===============================" << endl;
}

void Player::showStats()
{
    cout << endl;
    cout << "Player Stats" << endl;
    cout << "Name: " << name << endl;
    cout << "Day: " << currentDay << " / 7" << endl;
    cout << "Energy: " << energy << " / 10" << endl;
    cout << "Self-worth: " << selfWorth << " / 100" << endl; // do i really want to display these or do i want to keep the frustration in the game?
    cout << "Love Interest Points: " << loveInterestPoints << endl;
    cout << "Friendship Points: " << friendshipPoints << endl;
    cout << "Joja Influence: " << jojaInfluence << endl;
    cout << "Current Location: " << currentLocation << endl;
    cout << "Inventory Items: " << inventorySize << " / 20" << endl;
    cout << "==================================" << endl;
}