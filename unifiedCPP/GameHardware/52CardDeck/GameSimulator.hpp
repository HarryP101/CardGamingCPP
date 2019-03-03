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

class GameSimulator {
public:
    GameSimulator();
    DeckHandle* GetDeckHandle();
private:
    DeckHandle* m_deck;
};

#endif /* GameSimulator_hpp */
