# CSCI 1300 Final Project
## Theme -
an intentionally frustrating, satirical strategy game that mocks modern dating
the player must navigate social situations that they may not know have long term ramifications in the long term.
the game will have multiple endings that are directly influenced by the player's choices.

## Planned classes -
Game - keeps track of day, game itself, 
Player - name, energy, "self points", social battery
Option - represents each prospect in the game
Friend - represents each friend in the game
Event - different possible situations that may occur. party, home, gym, bar, etc..
Choice - represents player decisions which will affect player stats and modify their ending
Ending - contains different endings based on the player stats

## Planned limited resource -
self points
affected by player choices
although some choices may max out other player stats
self points are the most important one that unlocks better endings
energy will also be a secondary limited resource in order to see what a player prioritizes

## Tradeoff -
it is possible to "beat" the game with very low self points. 
if the player were to focus only on the short term ease of increasing love points, then they would finish the game quickly
albeit with low self points
there is a short term reward (and it will seem like that is the right path as it will be kind of encouraged by the game design)

## Time-
One week duration in which the time is limited by the energy you used each day

## EC Opportunities-
I'm going to try to implement the following:
smarter bundle
if the player is low on good stats 
the game will suggest going to a friend's house or meditating to get the points up
i will probably use booleans in Game 
will probably get added to the main menu

## weighted route planning
it will show different possible paths and what they cost in energy and how the may affect your stats.
every path has a cost
the planner recommends the lowest cost

to implement it i think i may assign each place a number and assign a cost that is from or to depending on how the map is
spekaing of 
# Map-
Will have locations Apartment, Gym, Bar, Library, Friend's House etc... and different houses.

To win? (fake ending)-
The player must achieve high romance points and conquer one of their prospects.
To win (good ending)-
The player must have above average self worth while achieving high romance points to realize that none of the stupidity the player goes through is worth the prospect.
To win (best ending)-
The player gives up, maxes out self worth, and gets the best ending.
To really lose-
The player must max out delusion points.
