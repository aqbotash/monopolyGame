# monopolyGame
<!-- Monopoly game rules -->
This is a game for a group of people. Every player will have 200000 dollars initially. There will be 40 spaces where players can go. In most places there will be properties. To start the game die will be rolled. According to the random number, player will step into corresponding place. If there is a property and it is not taken, program will ask whether a player wil buy this property. Player can buy this property spending 200 dollars. If this place is taken, player should rent this place for 200 dollars.
This program do not increase the money of property owner, even if some rents his or her place. 
There also can be Free Parking,
Income Tax -> 10% of all money that player owns.
Chances -> tasks where player's money can increase or decrease according to the task which is written in chance card. In this game, there is only 5 cards.
Finally, when there is only one player left, program will end game and announce the winner.
<!-- Monopoly game logic written in c++ -->
<!-- C++ knowledge -->
Object Oriented Programming
<!-- Further development -->
This program must increase the money of property owner, if someone rents his or her place.
<!-- Inconsistencies -->
There are some inconsistencies with <window.h> ans sleep() function. If your OS is linux change it to <unistd.h> and Sleep()
