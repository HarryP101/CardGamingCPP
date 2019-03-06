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
    Game.GetPlayerHandle()->PrintCardsInHand();
    Game.CheckIfGameHasEnded();
    Game.AskPlayerStickOrTwist();
    Game.GetPlayerHandle()->PrintCardsInHand();
}
