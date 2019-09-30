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
#include "Simulator.hpp"
#include <map>

class BlackJackSimulator : public Simulator {
public:
    BlackJackSimulator(int cardsDealt);
    bool CheckIfGameHasEnded();
    int GameOutcome(std::map<BasicPlayer*, int>&);
    void AskPlayerStickOrTwist();
    void CheckIfPlayerIsBust();
    int GetPlayerTurn();
    void SetNextPlayer();
    void Decider();
    void Reset(int cardsDealt);
    
private:
    enum BlackJackDecision {STICK, TWIST};
    BlackJackDecision m_decision;
};

#endif /* GameSimulator_hpp */
