#include "Item.h"
#include <iostream>
using namespace std;

Item::Item()
{
    name = "Idk";
    type = "Whatever"; //lorem ipsum dolor sit amet
    value = 0;
    neededForBundle = false;

}

Item::Item(string newName, string newType, int newValue, bool newNeededForBundle)
{
    name = newName;
    type = newType;
    value = newValue;
    neededForBundle = newNeededForBundle;

}

string Item::getName()
{
    return name;
}

string Item::getType()
{
    return type;
}

int Item::getValue()
{
    return value;
}

bool Item::isNeededForBundle()
{
    return neededForBundle;
}

void Item::setName(string newName)
{
    name = newName;
}

void Item::setType(string newType)
{
    type = newType;
}

void Item::setValue(int newValue)
{
    value = newValue;
}

void Item::setNeededForBundle(bool newNeededForBundle)
{
    neededForBundle = newNeededForBundle;
}



void Item::displayItem()
{
    cout << name << " - " << type;

    if (neededForBundle == true)
    {
        cout << " - Bundle Item";
    }



    cout << endl;
}