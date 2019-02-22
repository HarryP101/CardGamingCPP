//
//  Player.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 21/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "Player.hpp"
// Add player class here. Every player has a hand - so inheritance?
#include "Hand.hpp"

Player::Player(std::string playerName, Deck* deck) : Hand(deck) {
    m_playerName = playerName;
}
