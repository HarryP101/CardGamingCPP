//
//  Simulator.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 29/09/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "Simulator.hpp"

BasicDeck* Simulator::GetDeckHandle() {
    return m_deck;
}

BasicPlayer* Simulator::GetPlayer1() {
    return m_player1;
}

BasicPlayer* Simulator::GetPlayer2() {
    return m_player2;
}

BasicPlayer* Simulator::GetCurrentPlayer() {
    return m_currentPlayer;
}

