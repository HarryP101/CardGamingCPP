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
#include <map>

//Should change game simulator name to TwoPlayerBlackjackSimulator

int main() {
    std::map<BasicPlayer*, int> resultsContainer;
    
    GameSimulator Game(2);
    
    resultsContainer[Game.GetPlayer1()] = 0;
    resultsContainer[Game.GetPlayer2()] = 0;
    
    Game.GetPlayer1()->PrintCardsInHand();
    Game.GetPlayer2()->PrintCardsInHand();
    
    //Need a check to see if a player has stuck
    for(int i = 0; i < 100; i++) {
        while(!Game.CheckIfGameHasEnded()) {
            //std::cout << "Player " << Game.GetPlayerTurn() << std::endl;
            Game.AskPlayerStickOrTwist();
        }
        Game.GameOutcome(resultsContainer);
        Game.Reset(2);
    }
    std::cout << resultsContainer.at(Game.GetPlayer1()) << std::endl;
    
}

