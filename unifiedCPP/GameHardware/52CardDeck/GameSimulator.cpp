//
//  GameSimulator.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "GameSimulator.hpp"

GameSimulator::GameSimulator() {
    m_deck = new BasicDeck();
}

DeckHandle* GameSimulator::GetDeckHandle() {
    return m_deck;
}
