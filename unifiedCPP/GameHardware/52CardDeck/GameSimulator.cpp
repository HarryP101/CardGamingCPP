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
    m_whichPlayersTurn = 1;
    m_deck = new BasicDeck();
    m_player1 = new BasicPlayer(m_deck, cardsDealt);
    m_player2 = new BasicPlayer(m_deck, cardsDealt);
}

BasicDeck* GameSimulator::GetDeckHandle() {
    return m_deck;
}

BasicPlayer* GameSimulator::GetPlayerHandle() {
    if(m_whichPlayersTurn == 1) {
        return m_player1;
    }
        else return m_player2;
}

bool GameSimulator::CheckIfGameHasEnded() {
    // Needs to be more complex - i.e. is both player 1 and 2 bust? Just 1?
    return m_gameEnded;
}

void GameSimulator::CheckIfPlayerIsBust() {
    int sum = 0;
    BasicPlayer* player;
    if(m_whichPlayersTurn == 1) {
        player = m_player1;
    }
    else player = m_player2;
    for(int i = 0; i < player->GetNoOfCardsInHand(); i++) {
        sum += player->GetCardsInHand()[i].GetValue();
    }
    if(sum > 21) {
        m_gameEnded = true;
        std::cout << "This player is bust!!" << std::endl;
    }
}

void GameSimulator::AskPlayerStickOrTwist() {
    BasicPlayer* player;
    if(m_whichPlayersTurn == 1) {
        player = m_player1;
    }
    else player = m_player2;
    std::string decision;
    std::cout << "stick or twist? ";
    std::cin >> decision;
    
    if(decision == "twist") {
        player->DrawCard();
    }
}
