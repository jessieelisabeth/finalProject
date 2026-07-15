#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Character
{
private:
    string name;
    string dialogue;
    string location;

public:
    Character();
    Character(string newName, string newDialogue, string newLocation);

    string getName();
    string getDialogue();
    string getLocation();

    void setName(string newName);
    void setDialogue(string newDialogue);
    void setLocation(string newLocation);

    void talk();
    void displayCharacter();
};

#endif