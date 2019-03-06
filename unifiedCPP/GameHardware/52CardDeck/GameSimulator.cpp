//
//  GameSimulator.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "GameSimulator.hpp"

GameSimulator::GameSimulator(int cardsDealt) {
    m_gameEnded = false;
    m_deck = new BasicDeck();
    m_player = new BasicPlayer(m_deck, cardsDealt);
}

BasicDeck* GameSimulator::GetDeckHandle() {
    return m_deck;
}

BasicPlayer* GameSimulator::GetPlayerHandle() {
    return m_player;
}

bool GameSimulator::CheckIfGameHasEnded() {
    return m_gameEnded;
}

void GameSimulator::CheckIfPlayerIsBust() {
    //check here if the value of the cards is over 21 (for example)
}

void GameSimulator::AskPlayerStickOrTwist() {
    std::string decision;
    std::cout << "stick or twist? ";
    std::cin >> decision;
    
    if(decision == "twist") {
        m_player->DrawCard();
    }
}
