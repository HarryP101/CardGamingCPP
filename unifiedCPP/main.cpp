//
//  main.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include <iostream>
#include "BasicDeck.hpp"
#include "BasicPlayer.hpp"
#include "GameSimulator.hpp"

int main() {
    GameSimulator Game(2);
    Game.GetPlayerHandle(1)->PrintCardsInHand();
    Game.GetPlayerHandle(2)->PrintCardsInHand();
    
    //Need a check to see if a player has stuck
    // Also need to update card values for anything over 10
    while(!Game.CheckIfGameHasEnded()) {
        for(int i = 1; i < 3; i++) {
            std::cout << "Player " << i << std::endl;
            Game.CheckIfPlayerIsBust(i);
            Game.AskPlayerStickOrTwist(i);
            Game.GetPlayerHandle(i)->PrintCardsInHand();
            
        }
    }
}
