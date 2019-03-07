//
//  GameSimulator.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "GameSimulator.hpp"

GameSimulator::GameSimulator(int cardsDealt) {
    m_gameEndedPlayer1 = false;
    m_gameEndedPlayer2 = false;
    m_whichPlayersTurn = 1;
    m_deck = new BasicDeck();
    m_player1 = new BasicPlayer(m_deck, cardsDealt);
    m_player2 = new BasicPlayer(m_deck, cardsDealt);
}

BasicDeck* GameSimulator::GetDeckHandle() {
    return m_deck;
}

BasicPlayer* GameSimulator::GetPlayer1() {
    return m_player1;
}

BasicPlayer* GameSimulator::GetPlayer2() {
    return m_player2;
}

bool GameSimulator::CheckIfGameHasEnded() {
    return (m_gameEndedPlayer1 && m_gameEndedPlayer2);
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
        // these need to be made player attributes i think
        if(m_whichPlayersTurn == 1) {
            m_gameEndedPlayer1 = true;
        }
        if(m_whichPlayersTurn == -1) {
            m_gameEndedPlayer2 = true;
        }
        std::cout << "Player " << GetPlayerTurn() << " is bust!" << std::endl;
        m_whichPlayersTurn = m_whichPlayersTurn * -1;
    }
}

int GameSimulator::GetPlayerTurn() {
    if(m_whichPlayersTurn == -1) {
        return 2;
    }
    return m_whichPlayersTurn;
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
        CheckIfPlayerIsBust();
    }
}

void GameSimulator::GameOutcome() {
    //print outcome of game here
    //or store it
}
