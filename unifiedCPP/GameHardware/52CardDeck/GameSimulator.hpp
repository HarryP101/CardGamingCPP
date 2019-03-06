//
//  GameSimulator.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef GameSimulator_hpp
#define GameSimulator_hpp

#include <stdio.h>
#include "BasicDeck.hpp"
#include "BasicPlayer.hpp"

class GameSimulator {
public:
    GameSimulator(int cardsDealt);
    BasicDeck* GetDeckHandle();
    BasicPlayer* GetPlayerHandle();
    bool CheckIfGameHasEnded();
    void AskPlayerStickOrTwist();
    void CheckIfPlayerIsBust();
private:
    bool m_gameEnded;
    BasicDeck* m_deck;
    BasicPlayer* m_player;
};

#endif /* GameSimulator_hpp */
