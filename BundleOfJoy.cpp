#include "BundleOfJoy.h"
#include <iostream>
using namespace std;

BundleOfJoy::BundleOfJoy() { //bundle requires 5 items... we start off at 0 obviously.
    requiredSize = 5;
    donatedSize = 0;

    requiredItems[0] = Item("Friendship Bracelet", "Friendship", 0, true); //name type value needed for bundle? 
    requiredItems[1] = Item("Letter of Acceptance", "Achievement", 0, true);
    requiredItems[2] = Item("Rose", "Romance", 0, true);  // incorporate sunflower here somehow... eek
    requiredItems[3] = Item("Thank You Note", "Kindness", 0, true);
    requiredItems[4] = Item("Cafe Gift Card", "Joy", 0, true);
} //keep in mind jessie you had an extra argument for when you were deciding whether to have an energy restore option... watch 

bool BundleOfJoy::needsItem(string itemName) { // OR ROSE AND SUNFLOWER
    for (int i = 0; i < requiredSize; i++) {
        if (requiredItems[i].getName() == itemName || (requiredItems[i].getName() == "Rose" && itemName == "Sunflower"))
        {
            return true;
        }
    }

    return false;
}

bool BundleOfJoy::isDonated(string itemName){
    for (int i = 0; i < donatedSize; i++)
    {
        if (donatedItems[i].getName() == itemName)
        {
            return true;
        }
    }

    return false;
}

bool BundleOfJoy::donateItem(Item item)
{
    string itemName = item.getName();

    //sunflower logic time..... let's think about it
    /* RULES
    1. ROSE AND SUNFLOWER TAKE UP THE SAME SLOT IN BOJ
    2. ONLY ONE OF EM CAN BE DONATED, BOTH CANNOT BE USED TO COMPLETE THE BUNDLE
    3. AT LEAST ONE COMPLETES THE SLOT IN BUNDLE
    4. THE SUNFLOWER IS !!!!!!!REQUIRED!!!!!!! TO GET THE BEST ENDING
    So... in donateItem make sure you can't double donate
    If rose is being donated and sunflower has been donated OR if sunflower is being donated and rose has been donated
    Say no!*/

    if ((itemName == "Rose" && isDonated("Sunflower")) || (itemName == "Sunflower" && isDonated("Rose"))) {
        cout << "You've already put a flower in the memory box!" << endl;
        return false;
    }


    if (!needsItem(itemName))
    {
        cout << itemName << " is not needed for the Bundle of Joy." << endl;
        return false;
    }

    if (isDonated(itemName))
    {
        cout << itemName << " is already in the memory box." << endl;
        return false;
    }

    if (donatedSize < requiredSize)
    {
        donatedItems[donatedSize] = item;
        donatedSize++;

        cout << itemName << " was placed in the memory box." << endl;
        return true;
    }

    return false;
}

bool BundleOfJoy::isComplete()
{
    return donatedSize == requiredSize;
}

int BundleOfJoy::getProgress()
{
    return donatedSize;
}

int BundleOfJoy::getRequiredCount()
{
    return requiredSize;
}

void BundleOfJoy::displayBundle()
{
    cout << endl;
    cout << "bundle of joy" << endl;
    cout << "Progress: " << donatedSize << " / " << requiredSize << endl;

    cout << endl;
    cout << "Donated:" << endl;

    if (donatedSize == 0)
    {
        cout << "- Nothing donated yet" << endl;
    }
    else
    {
        for (int i = 0; i < donatedSize; i++)
        {
            cout << "- ";
            donatedItems[i].displayItem();
        }
    }

    cout << endl;
    cout << "Still Needed:" << endl;

    bool allDonated = true;

    for (int i = 0; i < requiredSize; i++) //amend rose sunflower bug
    {
        string requiredName = requiredItems[i].getName(); //requiredName is name of requiredItems[i]
/*
IF the required item has not been donated AND sunflower isn't replacing rose
donated items are NOT!
*/
        if (!isDonated(requiredName) && !(requiredName == "Rose" && isDonated("Sunflower")))
        {
            cout << "- ";
            requiredItems[i].displayItem();
            allDonated = false;
        }
    }

    if (allDonated)
    {
        cout << "Wow! No more needed! The Bundle of Joy is complete!" << endl;
    }

    cout << "===================================" << endl;
}