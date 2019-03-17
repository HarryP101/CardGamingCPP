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

//Should change game simulator name to TwoPlayerBlackjackSimulator

int main() {
    GameSimulator Game(2);
    Game.GetPlayer1()->PrintCardsInHand();
    Game.GetPlayer2()->PrintCardsInHand();
    
    //Need a check to see if a player has stuck
    for(int i = 0; i < 100; i++) {
        while(!Game.CheckIfGameHasEnded()) {
            //std::cout << "Player " << Game.GetPlayerTurn() << std::endl;
            Game.AskPlayerStickOrTwist();
        }
        Game.GameOutcome();
        Game.Reset(2);
    }
}

