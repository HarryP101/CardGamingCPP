//
//  GameSimulator.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "GameSimulator.hpp"
//include state variable for pointer to current player
GameSimulator::GameSimulator(int cardsDealt) {
    m_whichPlayersTurn = 1;
    m_deck = new BasicDeck();
    m_player1 = new BasicPlayer(m_deck, cardsDealt, 1);
    m_player2 = new BasicPlayer(m_deck, cardsDealt, 2);
    m_currentPlayer = m_player1;
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
    return (m_player1->GetStatus() && m_player2->GetStatus());
}

void GameSimulator::CheckIfPlayerIsBust() {
    int sum = m_currentPlayer->GetValueInHand();
    if(sum > 21) {
        m_currentPlayer->SetStatus(true, true);
        std::cout << "Player " << GetPlayerTurn() << " is bust!" << std::endl;
        m_whichPlayersTurn = m_whichPlayersTurn * -1;
        SetNextPlayer();
    }
}

int GameSimulator::GetPlayerTurn() {
    if(m_whichPlayersTurn == -1) {
        return 2;
    }
    return m_whichPlayersTurn;
}

void GameSimulator::SetNextPlayer() {
    switch(GetPlayerTurn()) {
        case(1):
            m_currentPlayer = m_player1;
        case(2):
            m_currentPlayer = m_player2;
    }
}

void GameSimulator::AskPlayerStickOrTwist() {
    std::cout << "stick or twist? ";
    std::string decision = Decider();
    std::cout << "Decision was " << decision << std::endl;
    
    if(decision == "twist") {
        m_currentPlayer->DrawCard();
        CheckIfPlayerIsBust();
    }
    
    if(decision == "stick") {
        m_whichPlayersTurn = m_whichPlayersTurn * -1;
        m_currentPlayer->SetStatus(true, false);
        SetNextPlayer();
    }
}

void GameSimulator::GameOutcome() {
    if(m_player1->GoneBust() && m_player2 ->GoneBust()) {
        std::cout << "No winners here!" << std::endl;
        return;
    }
    if(m_player1->GoneBust()) {
        std::cout << "Player 2 wins!!" << std::endl;
        return;
    }
    if(m_player2->GoneBust()) {
        std::cout << "Player 1 wins!!" << std::endl;
        return;
    }
    if(m_player1->GetValueInHand() > m_player2->GetValueInHand()) {
        std::cout << "Player 1 wins with " << m_player1->GetValueInHand() << std::endl;
        return;
    }
    if(m_player1->GetValueInHand() < m_player2->GetValueInHand()) {
        std::cout << "Player 2 wins with " << m_player2->GetValueInHand() << std::endl;
        return;
    }
    std::cout << "Its a draw!!" << std::endl;
}

std::string GameSimulator::Decider() {
    if(m_currentPlayer->GetValueInHand() < 16) {
        return "twist";
    }
    else return "stick";
}
