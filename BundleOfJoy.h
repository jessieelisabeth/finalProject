#ifndef BUNDLEOFJOY_H
#define BUNDLEOFJOY_H

#include "Item.h"
#include <string>
using namespace std;

class BundleOfJoy
{
private:
    Item requiredItems[5];
    Item donatedItems[5];

    int requiredSize;
    int donatedSize;

public:
    BundleOfJoy();

    bool needsItem(string itemName);
    bool isDonated(string itemName);
    bool donateItem(Item item);

    bool isComplete();
    int getProgress();
    int getRequiredCount();

    void displayBundle();
};

#endif