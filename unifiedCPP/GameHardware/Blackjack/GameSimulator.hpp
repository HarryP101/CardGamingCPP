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
#include <map>

class GameSimulator {
public:
    GameSimulator(int cardsDealt);
    BasicDeck* GetDeckHandle();
    BasicPlayer* GetPlayer1();
    BasicPlayer* GetPlayer2();
    bool CheckIfGameHasEnded();
    int GameOutcome(std::map<BasicPlayer*, int>&);
    void AskPlayerStickOrTwist();
    void CheckIfPlayerIsBust();
    int GetPlayerTurn();
    void SetNextPlayer();
    std::string Decider();
    void Reset(int cardsDealt);
private:
    int m_whichPlayersTurn;
    BasicDeck* m_deck;
    BasicPlayer* m_player1;
    BasicPlayer* m_player2;
    BasicPlayer* m_currentPlayer;
};

#endif /* GameSimulator_hpp */
