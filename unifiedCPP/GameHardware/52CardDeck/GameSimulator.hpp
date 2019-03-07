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
    void GameOutcome();
    void AskPlayerStickOrTwist();
    void CheckIfPlayerIsBust();
private:
    int m_whichPlayersTurn;
    bool m_gameEnded;
    BasicDeck* m_deck;
    BasicPlayer* m_player1;
    BasicPlayer* m_player2;
};

#endif /* GameSimulator_hpp */
