#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
    private:
    string name;
    string type;
    int value;
    bool neededForBundle;

    public:
    Item();
    Item(string newName, string newType, int newValue, bool newNeededForBundle);

    string getName();
    string getType();
    int getValue();
    bool isNeededForBundle();


    void setName(string newName);
    void setType(string newType);
    void setValue(int newValue);
    void setNeededForBundle(bool newNeededForBundle);


    void displayItem();
};

#endif