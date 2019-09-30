//
//  Simulator.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 29/09/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef Simulator_hpp
#define Simulator_hpp

#include <stdio.h>
#include "BasicPlayer.hpp"
#include "BasicDeck.hpp"
#include <map>

#endif /* Simulator_hpp */

class Simulator {
    
public:
    virtual ~Simulator() {
    }
    virtual BasicDeck* GetDeckHandle();
    virtual BasicPlayer* GetPlayer1();
    virtual BasicPlayer* GetPlayer2();
    virtual BasicPlayer* GetCurrentPlayer();
    virtual bool CheckIfGameHasEnded() = 0;
    virtual int GameOutcome(std::map<BasicPlayer*, int>&) = 0;
    virtual void Decider() = 0;
    
protected:
    BasicDeck* m_deck;
    BasicPlayer* m_player1;
    BasicPlayer* m_player2;
    BasicPlayer* m_currentPlayer;
    int m_whichPlayersTurn;
};
