#include "Game.h"
#include <iostream>
#include <fstream>
 //no time for random
using namespace std;

Game::Game() : player("Player")
{
 
    running = true;
    loveInterestCount = 5;
    friendCount = 4;
//Did these idiots justice.
    loveInterests[0] = LoveInterest("Otter", "I drink coffee and I code. Unique right?", "Party", "Pride Route", 8); //base dialogue off Pride
    loveInterests[0].setRouteDialogues(
        "You have high standards.",
        "You should stop pretending to be someone you aren't. I can see through you. Can you stop asking me to wear deodorant? It has chemicals.",
        "I guess we could have a future together. I don't know. I'll let you know in 10 business days."
    );

    loveInterests[1] = LoveInterest("Panda", "I like everything and everyone.", "Party", "Lust Route", 7); // base dialougue off Lust 
    loveInterests[1].setRouteDialogues( //Assigning character locations was a good one!
        "You're beautiful.",
        "I wasn't looking at anyone else. I only have eyes for you!",
        "It's natural to look around. I'm only human."
    );

    loveInterests[2] = LoveInterest("Seal", "I worked hard to get to where I am.", "Cafe", "Envy Route", 9); //base dialogue off Envy
    loveInterests[2].setRouteDialogues(
        "I've never met anyone as spontaneous as you are.",
        "I could never have as much free time as you.",
        "I love how creative you are. Have you considered a harder career?"
    );

    loveInterests[3] = LoveInterest("Penguin", "I know what things are worth.", "Gym", "Greed Route", 6); // base dialogue off Greed
    loveInterests[3].setRouteDialogues(
        "I really like your ambition. How do you feel about not having kids?", // amended
        "Have you maxed out your Roth IRA?",
        "You and I would make a great power couple."
    );

    loveInterests[4] = LoveInterest("Retriever", "I'm never asking for too much.", "Bedroom", "Sloth Route", 8); // base dialogue off Sloth
    loveInterests[4].setRouteDialogues(
        "I wouldn't mind seeing you next weekend. Come lay in bed with me.", //This warrants a giggle.
        "I told my mom about you. Anyway, listen to my most traumatic experience that affected my development...",
        "I'm off to play golf! See ya!"
    );

    friends[0] = Friend("Reagan", "I'm probably one of the best human beings alive.", "Cafe", 40, "Reality Check", "Friendship Bracelet");
    friends[0].setFriendDialogues(
        "Stand up!",
        "I'm glad to see you around more. Remember, chemistry isn't character. Drink your coffee.",
        "I made you a friendship bracelet."
    );

    friends[1] = Friend("Emma", "I'm really awesome and encourage your academic pursuits.", "Classroom", 40, "Academic Support", "Letter of Acceptance");
    friends[1].setFriendDialogues(
        "Did you go to class today?",
        "Isn't it great to have a stable routine?",
        "Here's a letter for you!"
    );

    friends[2] = Friend("Brayden", "I will always be here for you, no matter what.", "Party", 40, "Social Support", "Thank You Note");
    friends[2].setFriendDialogues(
        "Come dance! Who cares! Stop spiraling!",
        "Did you remember how much you've always loved dancing?",
        "Here's a Thank You Note."
    );

    friends[3] = Friend("Maren", "I've been by your side since the beginning, and will stay here until the end.", "Cafe", 40, "Comfort", "Cafe Gift Card");
    friends[3].setFriendDialogues(
        "How's your drink?",
        "Sit down and finish your coffee.",
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
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "           PROSPECTS            " << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Seven days, five prospects." << endl;
    cout << "Complete the Bundle of Joy and find love before the week ends!" << endl;
    cout << "Remember, nothing in this world is free..." << endl;
    cout << endl;
    cout << "(Press Enter to begin)" << endl;
    cin.get();
    cout << endl;

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
            if (player.getCurrentDay() >= 5) {
            displayGameTips();
            }
            else {
                cout << "You haven't suffered enough yet to unlock this." << endl;
            }
        }
        else if (choice == 9)
        {
            useUnHinge();
        }
        else if (choice == 10) {
            travel();
        }
        else if (choice==11) {
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
    cout << "PROSPECTS" << endl;
    cout << "Day: " << player.getCurrentDay() << " / 7" << endl;

    cout << "1. View player stats" << endl;
    cout << "2. View inventory" << endl;
    cout << "3. View Bundle of Joy" << endl;
    cout << "4. Talk to a love interest" << endl;
    cout << "5. Talk to a friend" << endl;
    cout << "6. Donate item to Bundle of Joy" << endl;
    cout << "7. End day" << endl;
    if (player.getCurrentDay() >= 5)
    {
    cout << "8. Learn secrets" << endl; 
    }
    cout << "9. Open unHinge" << endl;
    cout << "10. Travel" << endl;
    cout << "11. Quit" << endl;
    cout << "Choose an option: ";
}

void Game::talkToLoveInterest()
{
    int choice = 0;

    cout << endl;
    cout << "Choose a love interest:" << endl;

    for (int i = 0; i < loveInterestCount; i++)
    {
        cout << i + 1 << ". " << loveInterests[i].getName() << " - " << loveInterests[i].getLocation() << endl;
    }

    cout << "Choice: ";
    cin >> choice;

    if (choice < 1 || choice > loveInterestCount)
    {
        cout << "Invalid choice." << endl;
        return;
    }

    int index = choice - 1;

    if (loveInterests[index].getLocation() != player.getCurrentLocation()) {
    cout << loveInterests[index].getName()
         << " is currently at " << loveInterests[index].getLocation()
         << ", maybe get there first?" << endl;
    return;
}
  if (player.getEnergy() < 2) {
        cout << "You don't have enough energy to talk to a prospect!" << endl;
        cout << "End the day to restore energy!" << endl;
        return;
    }
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
        cout << i + 1 << ". " << friends[i].getName() << " - " << friends[i].getLocation() << endl;
    }

    cout << "Choice: ";
    cin >> choice;

    if (choice < 1 || choice > friendCount)
    {
        cout << "Invalid choice." << endl;
        return;
    }

    int index = choice - 1;

    // Made locations meaningful.
    if (friends[index].getLocation() != player.getCurrentLocation()) {
        cout << friends[index].getName() << " is currently at " << friends[index].getLocation() << ", maybe get there first?" << endl;
        return;
    }

    // making energy actually mean something here.
    if (player.getEnergy() < 1) {
        cout << "You don't have enough energy to talk to your friend!" << endl;
        cout << "End the day to restore energy!" << endl;
        return;
    }

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
    if (friendMaxxing && player.getunHingePoints() == 0 &&    player.getLoveInterestPoints() == 0 && !player.hasItem("Sunflower") && !bundle.isDonated("Sunflower")) {
        //addItem to my player! 
        player.addItem(makeItemByName("Sunflower"));
         cout << endl;
         cout << "Your friends have surprised you and gather around you." << endl;
         cout << "(*˘︶˘*).｡.:*♡ They thank you for growing with them. (Ɔ ˘⌣˘)♥(˘⌣˘ C)" << endl;
         cout << "Your friends have given you a Sunflower!" << endl;
    }
}

void Game::travel()
{
    int choice;
    cout << endl;
    cout << "               ~Classroom~" << endl;
    cout << "                    |    " << endl;
    cout << "   ~Party~ ------ ~Cafe~ ------ ~Gym~" << endl;
    cout << "                    |     " << endl;
    cout << "                ~Bedroom~ " << endl;
    cout << endl;

    cout << "You are currently at: " << player.getCurrentLocation() << endl;
    cout << endl;

    cout << "Where to?" << endl;
    cout << "1. Party" << endl;
    cout << "2. Cafe" << endl;
    cout << "3. Classroom" << endl;
    cout << "4. Gym" << endl;
    cout << "5. Bedroom" << endl;
    cout << "6. Stay" << endl;
    cout << "Choice: ";
    cin >> choice;

    string newLocation = "";

    if (choice == 1) {
        newLocation = "Party";

    }
    else if (choice ==2) {
        newLocation = "Cafe";
    }
    else if (choice == 3) {
        newLocation = "Classroom";
    }
    else if (choice == 4) {
        newLocation = "Gym";

    }
    else if (choice == 5) {
        newLocation = "Bedroom";
    }
    else if (choice == 6) {
        cout << "You've stayed at "<< player.getCurrentLocation() << endl;
        return;
    }
    else {
        cout << "That is not a valid input! But it was a valiant effort!" << endl;
        return;
    }
    // prevent unecessary energy loss when i make travel cost energy.
    if (newLocation == player.getCurrentLocation()) {
        cout << "You're already at " << newLocation << endl;
        return;
    }
//this will make travel cost energy of course accounting for if the player doesn't have enough...
    if (player.getEnergy() < 1) {
        cout << "You don't have enough energy to travel!" << endl;
        cout << "End the day for more energy." << endl;
        return;
    }
    player.loseEnergy(1);
    player.setCurrentLocation(newLocation);
    cout << "You've moved to " << newLocation << endl;
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
    if (donated && itemName == "Sunflower" && player.getSelfWorth()== 100 && player.getLoveInterestPoints() == 0 && player.getunHingePoints() == 0) {
        displayEnding();
        running = false;
    }
}

void Game::displayBundlePlanner() { //Added Extra credit
    bool playerMissingItems = false; //assume the player is missing no items
    cout << endl;
    cout << "------ Bundle Planner -------" << endl;
    cout << "Running a bundle analysis..." << endl;
    cout << "---------------------------- " << endl;
    cout << endl;
    cout << "Based on your gameplay, we recommend the following: "<< endl;
    if (!bundle.isDonated("Friendship Bracelet")) {
        playerMissingItems = true;
        cout << "Friendship Bracelet:" << endl;

        if (player.hasItem("Friendship Bracelet")) {
            cout << "Donate this item!" << endl;
        }
        else {
            cout << "Go see at Reagan at " << friends[0].getLocation() << endl;
        }
    }
    if (!bundle.isDonated("Letter of Acceptance")) {
        playerMissingItems = true;
        cout << "Letter of Acceptance:" << endl;

         if (player.hasItem("Letter of Acceptance")) {
            cout << "Donate this item!" << endl;
        }
        else {
            cout << "Go see Emma at " << friends[1].getLocation() << endl;
        }
    }
    if (!bundle.isDonated("Thank You Note")) {
        playerMissingItems = true;
        cout << "Thank You Note:" << endl;
         if (player.hasItem("Thank You Note")) {
            cout << "Donate this item!" << endl;
        }
        else {
            cout << "Go see Brayden at " << friends[2].getLocation() << endl;
        }
    }
    if (!bundle.isDonated("Cafe Gift Card")) {
        playerMissingItems = true;
        cout << "Cafe Gift Card:" << endl;
         if (player.hasItem("Cafe Gift Card")) {
            cout << "Donate this item!" << endl;
        }
        else {
            cout << "Go see Maren at " << friends[3].getLocation() << endl;
        }
    }
    // account for sunflower and rose, true when rose or sunflower are donated
    bool flowerDonated = bundle.isDonated("Rose") || bundle.isDonated("Sunflower");
    if (!flowerDonated) {
        playerMissingItems = true;
        cout << "Flower:" << endl;
        if (player.hasItem("Sunflower")) {
            cout << "Donate this Sunflower!" << endl;
        }
        else if (player.hasItem("Rose"))
        {
            cout << "Donate this Rose!" << endl;
        }
        else
        {
            cout << "Talk to your love interests to earn a rose." << endl;
            cout << "Or prioritize something different! " << endl;
            cout << "Something else may bloom!" << endl;
        }
        cout << endl;
    }
    if (!playerMissingItems) {
        cout << "You've already completed the bundle! If you're unhappy with your ending, maybe try something different?" << endl;
    }
    //if the boolean is flase after all the checks, the bundle is complete

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
    cout << "--- Final Outcome ---" << endl; //refine this later....

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

if (player.getSelfWorth() == 100 && player.getLoveInterestPoints() == 0 &&
    bundle.isDonated("Sunflower")
    && player.getunHingePoints() == 0) // Closed unHinge best ending loophole
{
    cout << "Congratulations on getting the secret best ending!" << endl;
    perfectDate();
}
else if (!bundle.isComplete())
{
    cout << "--- EMPTY BUNDLE ---" << endl;
    cout << "Did you even try to play the game?" << endl;
    cout << "Seriously?" << endl;
    cout << "I wrote all that code and for what?" << endl;
    cout << "You better restart. Do better." << endl;
}

    else if (highestRomance >= 60)
    {
        if (highestRomanceIndex == 0) {
            cout <<"--- CLOCKSTOPPER ---"<<  endl; //i believe in case of a tie otter beats all.
            cout << endl;
            cout <<"You ended up with Otter." << endl;
            cout <<"Otter didn't get the memo that you're together." << endl;
            cout << "After 10 business days, you finally get a text back." << endl;
            cout << "Otter is notifying you that your biological clocks are not aligned." << endl;
            cout << endl;
            cout << "7 months later, you run into Otter in the engineering building." << endl;
            cout << "You just hold your breath." << endl;
        }
        else if (highestRomanceIndex == 1 ) {
            cout << "--- CAN'T TAKE MY EYES OFF OF YOU and you... and you... and you... ---" << endl;
            cout << endl;
            cout << "You ended up with Panda." << endl;
            cout << "Panda's a lot of fun to hang out with." << endl;
            cout << "Panda adores you." << endl;
            cout << "And the other thousands of scantily clad people on their following list." << endl;
            cout << endl;
            cout << "You have enough romantic overlap to fill an entire sorority chapter." << endl;
        }
        else if (highestRomanceIndex == 2 ) {
            cout << "--- HAPPY WIFE HAPPY LIFE ---" << endl;
            cout << endl;
            cout << "You married Seal!" << endl;
            cout << "Congratulations!" << endl;
            cout << "This is what you wanted, right? To get married?" << endl;
             cout << endl;
            cout << "Every accomplishment you achieve will be subject to criticism. The spontaneity Seal loved about you? Not allowed anymore." << endl;
        }
        else if (highestRomanceIndex == 3) {
            cout << "--- INTEREST ---" << endl;
            cout << endl;
            cout << "You end up with Penguin." << endl;
            cout << "Love compounds annually." << endl;
            cout << "Penguin says they want to move you to Slovakia, where their family has 5 estates." << endl;
            cout << endl;
            cout << "Penguin accused you of being a gold digger after you saw him leave a ten percent tip on a bill at a sushi restaurant." << endl;
        }
        else if (highestRomanceIndex == 4) { // Tidied up endings
            cout << "--- HE'S AT A FARM SOMEWHERE ----" << endl;
            cout << endl;
            cout << "You ended up with... I don't even know man." << endl;
            cout << "Retriever ran off into the sunset, probably chasing a golf club in a game of fetch, while simultaneously running away from commitment." << endl;
            cout << "The running? It's the most effort you've seen Retriever put into anything. Ever." << endl;
            cout << endl; 
            cout << "It's okay. You're more of a cat person anyway." << endl;
        }
    }
    else {
        cout << "--- BUNDLE OF NOTHING ---" << endl;
        cout << endl;
        cout << "You finished the bundle." << endl;
        cout << "Congrats." << endl;
        cout << "You don't feel anything." << endl;
        cout << endl;
     cout << "Your phone lights up with a message:" << endl;
    cout << "\"hey\"" << endl;
    }
    displayCredits();

//added endings
    cout << "============================" << endl;
}
    void Game::displayGameTips() { //Added bundle planner as this seemed most appropriate rather than giving a new menu options



    ifstream tipsFile("game_tips.txt");
    string line;

    while (getline(tipsFile, line))
    {
        cout << line << endl;
    }
    
    tipsFile.close();
    displayBundlePlanner();

    }
    void Game::perfectDate() {
        string playerName;
        cin.ignore();

        cout << endl;
        cout << "☆*:.｡.o You've made it far! o.｡.:*☆" << endl;
        cout << endl;
        cout << "Some time later, you're sitting at the cafe..." << endl;
        cout << "And someone sits in the usually empty chair in front of you." << endl;
        cout << "(Press Enter to continue)";
        cin.get();

        cout << endl;
        cout << "After a heated debate on the superiority of flat whites over lattes," << endl;
        cout << "The stranger asks you a question." << endl;
        cout << endl;
        cout << "\"What's your name?\"" << endl;
        cout << "Enter your name:";
        getline(cin, playerName);
        if (playerName == "") {
            playerName = "Mysterious Young Lad";
        }

        cout << endl;
        cout << "\"" << playerName << "!\"" << endl;
        cout << "It's a pleasure to finally meet you." << endl;

        int dateChoice;

        cout << endl;
        cout<< "\"Wanna get out of here?\"" << endl;
        cout << "1. Go stargazing" << endl;
        cout << "2. Visit the Boulder Bookstore" << endl;
        cout << "3. Spontaneously drive up to the mountains" << endl;
        cout << "Choice: ";
        cin >> dateChoice;
        cin.ignore();
        cout << endl;

        if (dateChoice == 1) {
            cout << "You and the stranger find yourselves staring at the sky, in comfortable silence." << endl;
        }
        else if (dateChoice == 2) {
            cout << "You and the stranger wander around the bookstore until you find a title that intrigues you," << endl;
            cout << "The Stranger by Albert Camus" << endl;
            cout << "You make Jung proud and decide to not ignore the synchronicity. You go home with a copy of The Stranger." << endl;
            cout << endl;
            cout << "You decide to go stargazing." << endl;
            cout << "You and the stranger find yourselves staring at the sky, in comfortable silence." << endl;
        }
        else if (dateChoice == 3) {
            cout << "You take the stranger up to Breckenridge. You've booked a cabin last minute." << endl;
            cout << "Despite the novelty of each other, there is no anxious energy in the car." << endl;
            cout << "You decide to go stargazing." << endl;
            cout << "You and the stranger find yourselves staring at the sky, in comfortable silence." << endl;
        }
        else {
            cout << "You've asked the stranger to surprise you." << endl;
            cout << "He smiles like he already knew where you were going." << endl;
            cout << "You decide to go stargazing." << endl;
            cout << "You and the stranger find yourselves staring at the sky, in comfortable silence." << endl;
        }

        cout << endl;
        cout << "(Press Enter to continue)";
        cin.get();

        cout << endl;
cout << "        .                  *              ." << endl;
cout << "                 ✦                           *" << endl;
cout << "   *                           .                 " << endl;
cout << "             .          *              ✦        " << endl;
cout << "                                                " << endl;
cout << "      ✦               .               *         " << endl;
cout << "                           .                    " << endl;
cout << "  .          *                         ✦         " << endl;
cout << "                    *                           " << endl;
cout << "         .                       .          *    " << endl;
cout << "                                                " << endl;
cout << "                         /\\                     " << endl;
cout << "            /\\          /  \\        /\\          " << endl;
cout << "       /\\  /  \\    /\\  /    \\      /  \\        " << endl;
cout << "      /  \\/    \\  /  \\/      \\ /\\ /    \\       " << endl;
cout << "_____/__________\\/_____________V__________\\_____" << endl;
cout << endl;
        cout << "The stranger turns his head and sees you focused on the stars." << endl;
        cout << "\"What are you thinking about?\"" << endl;
        cout << endl;
        cout << "\"I'm hoping I won't have to turn you into a character in my game.\"" << endl;
        cout << endl;
        cout << "\"Game? What game?\"" << endl;
        // BAM END CREDITS IM THE GOAT
        // no literally roll credits now

    }
    //here
    void Game::displayCredits()
    {
        cout << endl;
        cout << "✧･ﾟ: *✧･ﾟ:*         *:･ﾟ✧*:･ﾟ✧" << endl;
        cout << "✧･ﾟ: *✧･ﾟ:* THE END *:･ﾟ✧*:･ﾟ✧" << endl;
        cout << "✧･ﾟ: *✧･ﾟ:*         *:･ﾟ✧*:･ﾟ✧" << endl;
        cout<< endl;
        cout << "Story, design, and code by Jessie." << endl;
        cout << endl;
        cout << "Thank you to Reagan, Maren, Brayden, and Emma for keeping me sane IRL." << endl;
        cout << endl;
        cout << "Thank you to the boys who inspired my prospects." << endl;
        cout << "No, you will not be paid royalties. " << endl;
        cout << endl;
        cout << "No men were improved in the making of this game." << endl;
        cout << "No emotional damage was incurred during development." << endl;
        cout << endl;
        cout << "You can git commit, but you can't git them to commit!" << endl;
        cout << endl;

    }