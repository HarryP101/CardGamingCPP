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
#include "BlackJackSimulator.hpp"
#include <map>

//Should change game simulator name to TwoPlayerBlackjackSimulator

int main() {
    std::map<BasicPlayer*, int> resultsContainer;
    
    BlackJackSimulator Game(2);
    
    resultsContainer[Game.GetPlayer1()] = 0;
    resultsContainer[Game.GetPlayer2()] = 0;
    
    for(int i = 0; i < 100; i++) {
        while(!Game.CheckIfGameHasEnded()) {
            //std::cout << "Player " << Game.GetPlayerTurn() << std::endl;
            Game.AskPlayerStickOrTwist();
        }
        Game.GameOutcome(resultsContainer);
        Game.Reset(2);
    }
    std::cout << "Player 1 won " << resultsContainer.at(Game.GetPlayer1()) << "%" << std::endl;
    std::cout << "Player 2 won " << resultsContainer.at(Game.GetPlayer2()) << "%" << std::endl;
    std::cout << "The rest were draws or both went bust" << std::endl;
    
}

// TODO: Add strategy function to basic player to decide whether to stick or twist or not.
// TODO: Keep track of how 'hot' the deck is; use this to influence strategy on riskier decisions
// TODO: Make new Card game which uses basic deck, basic card
