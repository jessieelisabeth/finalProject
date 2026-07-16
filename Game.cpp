#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

Game::Game() : player("Player")
{
    running = true;

    loveInterestCount = 5;
    friendCount = 4;
//overall do all these idiots more justice... the game is about the laughs not really about the code (sorry)
    loveInterests[0] = LoveInterest("Otter", "I drink coffee and I code. Unique right?", "Party", "Pride Route", 8); //base dialogue off Pride
    loveInterests[0].setRouteDialogues(
        "You have high standards.",
        "You should stop pretending to be someone you aren't. I can see through you.",
        "I guess we could have a future together."
    );

    loveInterests[1] = LoveInterest("Panda", "I like evertyhing and everyone.", "Party", "Lust Route", 7); // base dialougue off Lust 
    loveInterests[1].setRouteDialogues( //should i be really assigning character locations ? we will see...........
        "You're beautiful.",
        "I wasn't looking at anyone else. I only have eyes for you!",
        "It's natural to look around. I'm only human."
    );

    loveInterests[2] = LoveInterest("Seal", "I worked hard to get to where I am.", "Cafe", "Envy Route", 9); //base dialogue off Envy
    loveInterests[2].setRouteDialogues(
        "I've never met anyone as spontaneous as you are.",
        "I could never have as much free time as you.",
        "I love how creative you are."
    );

    loveInterests[3] = LoveInterest("Penguin", "this one's a bit difficult so idk filler filler .", "Gym", "Greed Route", 6); // base dialogue off Greed
    loveInterests[3].setRouteDialogues(
        " idk yet", //im crine
        "idk yet",
        "idk yet"
    );

    loveInterests[4] = LoveInterest("Retriever", "lorem ipsum", "Bedroom", "Sloth Route", 8); // base dialogue off Sloth
    loveInterests[4].setRouteDialogues(
        "dolor sit amet", //jessie PLEASE give retriever some good dialogue because you need to do this character justice
        "i forgot",
        "whata comes next"
    );

    friends[0] = Friend("Reagan", "Stand up!", "Cafe", 40, "Reality Check", "Friendship Bracelet");
    friends[0].setFriendDialogues(
        "Stand up!",
        "I'm glad to see you around more.",
        "I made you a friendship bracelet."
    );

    friends[1] = Friend("Emma", "Did you go to class today?", "Classroom", 40, "Academic Support", "Letter of Acceptance");
    friends[1].setFriendDialogues(
        "Did you go to class today?",
        "Isn't it great to have a stable routine?",
        "Here's a letter for you!"
    );

    friends[2] = Friend("Brayden", "Come dance and stop spiraling.", "Party", 40, "Social Support", "Thank You Note");
    friends[2].setFriendDialogues(
        "Come dance! Who cares!",
        "Did you remember how much you've always loved dancing?",
        "Here's a Thank You Note."
    );

    friends[3] = Friend("Maren", "don't know yet?", "Cafe", 40, "Comfort", "Cafe Gift Card");
    friends[3].setFriendDialogues(
        "How's your drink?",
        "not sure yet",
        "The cafe gave you a gift card as an apology for messing up your drink..."
    );
}

Item Game::makeItemByName(string itemName) 
{
    if (itemName == "Friendship Bracelet")
    {
        return Item("Friendship Bracelet", "Friendship", 0, true);
    }
    else if (itemName == "Letter of Acceptance")
    {
        return Item("Letter of Acceptance", "Achievement", 0, true);
    }
    else if (itemName == "Rose")
    {
        return Item("Rose", "Romance", 0, true);
    }
    else if (itemName == "Sunflower")
    {
        return Item("Sunflower", "Personal Growth", 0, true); //not a misc anymore.
    }
    
    else if (itemName == "Thank You Note")
    {
        return Item("Thank You Note", "Kindness", 0, true);
    }
    else if (itemName == "Cafe Gift Card")
    {
        return Item("Cafe Gift Card", "Joy", 0, true);
    }

    return Item(itemName, "Misc", 0, false);
}

void Game::run()
{
    int choice = 0;

    cout << "this game hasn't been named yet lol." << endl; // PLEASE NAME

    while (running)
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            player.showStats();
        }
        else if (choice == 2)
        {
            player.displayInventory();
        }
        else if (choice == 3)
        {
            bundle.displayBundle();
        }
        else if (choice == 4)
        {
            talkToLoveInterest();
        }
        else if (choice == 5)
        {
            talkToFriend();
        }
        else if (choice == 6)
        {
            donateToBundle();
        }
        else if (choice == 7)
        {
            endDay();
        }
        else if (choice == 8)
        {
            displayGameTips();
        }
        else if (choice == 9)
        {
            useUnHinge();
        }
        else if (choice == 10) {
            running = false;
            cout << "See you later!" << endl;
        }
        else {
            cout << "That's not allowed!" << endl;
        }
    }
}

void Game::showMenu()
{
    cout << endl;
    cout << "name this thing" << endl;
    cout << "Day: " << player.getCurrentDay() << " / 7" << endl;
    cout << "Energy: " << player.getEnergy() << " / 10" << endl;
    cout << "Self-worth: " << player.getSelfWorth() << " / 100" << endl; //thinking about gatekeeping this
    cout << "Location: " << player.getCurrentLocation() << endl;
    cout << "Bundle Progress: " << bundle.getProgress() << " / " << bundle.getRequiredCount() << endl;
    cout << "===================================" << endl;

    cout << "1. View player stats" << endl;
    cout << "2. View inventory" << endl;
    cout << "3. View Bundle of Joy" << endl;
    cout << "4. Talk to a love interest" << endl;
    cout << "5. Talk to a friend" << endl;
    cout << "6. Donate item to Bundle of Joy" << endl;
    cout << "7. End day" << endl;
    cout << "8. Learn secrets" << endl; //this learn secrets... is there a way i can only make this option appear after a certain day? like after day 5
    //if day > 4 then showNewMenu? something to think about.
    cout << "9. Open unHinge" << endl;
    cout << "10. Quit" << endl;
    cout << "Choose an option: ";
}

void Game::talkToLoveInterest()
{
    int choice = 0;

    cout << endl;
    cout << "Choose a love interest:" << endl;

    for (int i = 0; i < loveInterestCount; i++)
    {
        cout << i + 1 << ". " << loveInterests[i].getName() << endl;
    }

    cout << "Choice: ";
    cin >> choice;

    if (choice < 1 || choice > loveInterestCount)
    {
        cout << "Invalid choice." << endl;
        return;
    }

    int index = choice - 1;

    int damage = loveInterests[index].interact();

    player.loseSelfWorth(damage);
    player.loseEnergy(2);
    player.addLoveInterestPoints(10);

    if (loveInterests[index].getRomanceLevel() >= 100 && !player.hasItem("Rose")) //one of the bundle of joy completion items but not the sunflower for the optimal ending.
    {
        player.addItem(makeItemByName("Rose"));
    }
}

void Game::talkToFriend(){
    int choice = 0;  //menu for friend choice. i can't lie a lot of copy pasting going on here.

    cout << endl;
    cout << "Choose a friend:" << endl;

    for (int i = 0; i < friendCount; i++)
    {
        cout << i + 1 << ". " << friends[i].getName() << endl;
    }

    cout << "Choice: ";
    cin >> choice;

    if (choice < 1 || choice > friendCount)
    {
        cout << "Invalid choice." << endl;
        return;
    }

    int index = choice - 1;

    string reward = friends[index].interact();

    player.gainSelfWorth(10);
    player.loseEnergy(1); //keep in mind that talking to a friend loses one energy unit, whilst talking to a love interest loses 2.
    player.addFriendshipPoints(10);

    if (reward != "")  { //if friend gives player a reward then add item to player inventory. if reward is not empty logic basically?
        player.addItem(makeItemByName(reward));

    }
    // For later: if friendship points are 100 for ALL friends... give player sunflower.
    // ummm also player can NEVER use unHinge ! this isn't supposed to be easy 
    // also obviously you cant have already won the sunflower 
    //closing un hinge --> raise self worth ---> find best ending loophole
    //logic time
    /* Assume all friend support stats are maxxed out.
    Then, for all friend count, if the support start is below 100,
    switch the boolean to false.*/
    bool friendMaxxing = true;
    for (int i = 0; i < friendCount; i++)
    {
        if (friends[i].getSupportLevel() < 100) {
            friendMaxxing = false;
        }
    }
    /* and if i've maxed out all my friends and i've never used unhinge(0) 
    i dont own or havent put a sunflower in the bundle .isdonated then give me a sunflower
    oh yeah*/
    if (friendMaxxing && player.getunHingePoints() == 0 && !player.hasItem("Sunflower") && !bundle.isDonated("Sunflower")) {
        //addItem to my player! 
        player.addItem(makeItemByName("Sunflower"));
         cout << endl;
         cout << "Your friends have surprised you and gather around you." << endl;
         cout << "(*˘︶˘*).｡.:*♡ They thank you for growing with them. (Ɔ ˘⌣˘)♥(˘⌣˘ C)" << endl;
         cout << "Your friends have given you a Sunflower!" << endl;
    }
}



void Game::donateToBundle() {
    int choice = 0;
    string itemName = "";
    //more sunflower logic. if the player ahs sunflower show option for donation.
    bool hasSunflower = player.hasItem("Sunflower");

    cout << endl;
    cout << "What would you like to donate?" << endl;
    cout << "1. Friendship Bracelet" << endl;
    cout << "2. Letter of Acceptance" << endl;
    cout << "3. Rose" << endl; //DONT FORGET SUNFLOWER GOD PLEASE
    cout << "4. Thank You Note" << endl;
    cout << "5. Cafe Gift Card" << endl;

    if (hasSunflower)
    {
        cout << "6. Sunflower" << endl;
        cout << "7. Cancel" << endl;
    }
    else {
        cout << "6. Cancel" << endl;
    }

    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        itemName = "Friendship Bracelet";
    }
    else if (choice == 2) {
        itemName = "Letter of Acceptance";
    }
    else if (choice == 3) {
        itemName = "Rose";
    }
    else if (choice == 4) {
        itemName = "Thank You Note";
    }
    else if (choice == 5) {
        itemName = "Cafe Gift Card";
    }
    else if (choice == 6 && hasSunflower)
    { 
        itemName="Sunflower"; 
    }
    else if ((choice == 6 && !hasSunflower) || (choice == 7 && hasSunflower)){
        cout << "Why are you backtracking?" << endl;
        return;
    }
    
    else {
        cout << "What are you waffling on about?" << endl; 
        return;
    }

    if (!player.hasItem(itemName)) {
        cout << "You don't have " << itemName << ", silly goose." << endl;
        return;
    }

    bool donated = bundle.donateItem(makeItemByName(itemName));

    if (donated){
        player.removeItem(itemName);
    }
    if (donated && itemName == "Sunflower" && player.getSelfWorth()== 100) {
        displayEnding();
        running = false;
    }
}

void Game::useUnHinge() {
    cout << endl;
    cout << "Welcome to unHinge!" << endl;
    cout << "Get what you need, no interaction needed!" << endl;
    cout << endl;
    int choice;
    // setting unhinge use cost at 20
    cout << "1. Get Friendship Bracelet" << endl;
    cout << "2. Get Letter of Acceptance" <<endl;
    cout << "3. Get Rose" << endl;
    cout << "4. Get Thank You Note" << endl;
    cout << "5. Get Cafe Gift Card" << endl;
    cout << "6. Unhinge from unHinge" << endl;
    cout << "Choice: ";
    cin >> choice;

    // logic time for unHinge. 
    if (choice == 1) {
        if (bundle.isDonated("Friendship Bracelet") || player.hasItem("Friendship Bracelet")) {
            cout << "You already have the Friendship Bracelet!" << endl;
        }
        else if (player.getSelfWorth() < 20) { //ensures the player has enough self worth to spend on unhinge 
        cout << "Not to make things weird... but maybe focus on yourself." << endl;
    }
        else {
            Item bracelet("Friendship Bracelet", "Friendship", 0, true);
            player.addItem(bracelet);
            player.loseSelfWorth(20);
            player.addunHingePoints(1);

            cout << "A stranger has given you a Friendship Bracelet!" << endl;

        }
    }
        else if (choice == 2) {
          if (bundle.isDonated("Letter of Acceptance") || player.hasItem("Letter of Acceptance")) {
            cout << "You already have the Letter of Acceptance!" << endl;
        }
        else if (player.getSelfWorth() < 20) { //ensures the player has enough self worth to spend on unhinge 
        cout << "Not to make things weird... but maybe focus on yourself." << endl;
    }
        else {
            Item bracelet("Letter of Acceptance", "Achievement", 0, true);
            player.addItem(bracelet);
            player.loseSelfWorth(20);
            player.addunHingePoints(1);

            cout << "A stranger has given you a Letter of Acceptance" << endl;

        }
}
    else if (choice == 3) {
        if (bundle.isDonated("Rose") || player.hasItem("Rose")) {
            cout << "You already have the Rose!" << endl;
        }
        else if (player.getSelfWorth() < 20) {
            cout <<"Not to make things weird... but maybe focus on yourself." << endl;
        }
        else {
            Item rose("Rose", "Romance", 0, true);

            player.addItem(rose);
            player.loseSelfWorth(20);
            player.addunHingePoints(1);

            cout << "A stranger has given you a Rose!" << endl;
        }
    }
    else if (choice == 4) {
        if (bundle.isDonated("Thank You Note") || player.hasItem("Thank You Note")) {
            cout << "You already have the Thank You Note!" << endl;
        }
        else if (player.getSelfWorth() < 20)
    {
        cout << "Not to make things weird... but maybe focus on yourself." << endl;
    }
    else
    {
        Item note("Thank You Note", "Kindness", 0, true);

        player.addItem(note);
        player.loseSelfWorth(20);
        player.addunHingePoints(1);

        cout << "A stranger has given you a Thank You Note!" << endl;
    }
}
else if (choice == 5) {
    if (bundle.isDonated("Cafe Gift Card") ||
        player.hasItem("Cafe Gift Card"))
    {
        cout << "You already have the Cafe Gift Card!" << endl;
    }
    else if (player.getSelfWorth() < 20)
    {
        cout << "Not to make things weird... but maybe focus on yourself." << endl;
    }
    else
    {
        Item giftCard("Cafe Gift Card", "Joy", 0, true);

        player.addItem(giftCard);
        player.loseSelfWorth(20);
        player.addunHingePoints(1);

        cout << "A stranger has given you a Cafe Gift Card!" << endl;
    }
}
else if (choice == 6) {
    cout << "You unHinged from unHinge." << endl;
}
else
{
    cout << "This is not an option!" << endl;
}
    }


void Game::endDay() {
    cout << endl;
    cout << "The day ends." << endl;
    player.nextDay();

    if (player.getCurrentDay() > 7)
    {
        displayEnding();
        running = false;
    }
}

void Game::displayEnding() {
    cout << endl;
    cout << "Endings" << endl; //refine this later....

// the following is to implement the highest romance stat and chooses which ending you get if you go the romance route
int highestRomance = loveInterests[0].getRomanceLevel(); //assuming Otter has the highest romance
int highestRomanceIndex = 0;

//loop to move from otter to the other interests
for (int i = 1; i < 5; i++) {
    if(loveInterests[i].getRomanceLevel() > highestRomance) { //after otter... check 1 thru 4, find who has the most romance and make that the highest romance index.
highestRomance = loveInterests[i].getRomanceLevel();
highestRomanceIndex = i;
    }
}

if (player.getSelfWorth() == 100 &&
    bundle.isDonated("Sunflower"))
{
    cout << "Congratulations on getting the secret best ending!" << endl;
}
else if (!bundle.isComplete())
{
    cout << "BOO! The Bundle of Joy was not completed." << endl;
    cout << "Seriously? This is probably the easiest aspect of the game." << endl;
}

    else if (highestRomance >= 60)
    {
        if (highestRomanceIndex == 0) {
            cout <<"otter's ending"<<  endl; //i believe in case of a tie otter beats all.
        }
        else if (highestRomanceIndex == 1 ) {
            cout << "panda's ending" << endl;
        }
        else if (highestRomanceIndex == 2 ) {
            cout << " seal's ending" << endl;
        }
        else if (highestRomanceIndex == 3) {
            cout << "peguin's ending" << endl;
        }
        else if (highestRomanceIndex == 4) { //tidy up if you have a chance before the interviw, you're getting sloppy
            cout << "retriever's ending" << endl;
        }
    }
    else {
        cout << "unHinge ending, bundle of joy completed" << endl;
    }

//ADD MORE ENDINGS BEFORE INTERVIEW THIS SUCKS!!!! be evil
    cout << "============================" << endl;
}
    void Game::displayGameTips() { //stuff for file input requirements that i dont quite yet get

    ifstream tipsFile("game_tips.txt");
    string line;

    while (getline(tipsFile, line))
    {
        cout << line << endl;
    }
    
    tipsFile.close();

    }