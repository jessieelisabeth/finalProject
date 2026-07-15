#include "Character.h"
#include <iostream>
using namespace std;

Character::Character()
{
    name = "Unknown";
    dialogue = "Hi";
    location = "Bedroom"; //son...
}

Character::Character(string newName, string newDialogue, string newLocation) 
{
    name = newName;
    dialogue = newDialogue;
    location = newLocation;
}

string Character::getName() //methods for characters here
{
    return name;
}

string Character::getDialogue()
{
    return dialogue;
}

string Character::getLocation()
{
    return location;
}

void Character::setName(string newName)
{
    name = newName;
}

void Character::setDialogue(string newDialogue)
{
    dialogue = newDialogue;
}

void Character::setLocation(string newLocation)
{
    location = newLocation;
}

void Character::talk() //displays character dialogue...
{
    cout << name << ": " << dialogue << endl;
}

void Character::displayCharacter() //for character location information...
{
    cout << name << " at " << location << endl;
}