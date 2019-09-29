//
//  GameSimulator.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "BlackJackSimulator.hpp"

//include state variable for pointer to current player
BlackJackSimulator::BlackJackSimulator(int cardsDealt) {
    m_whichPlayersTurn = 1;
    m_deck = new BasicDeck();
    m_player1 = new BasicPlayer(m_deck, cardsDealt, 1);
    m_player2 = new BasicPlayer(m_deck, cardsDealt, 2);
    m_currentPlayer = m_player1;
}

int BlackJackSimulator::GetPlayerTurn() {
    if(m_whichPlayersTurn == -1) {
        return 2;
    }
    return m_whichPlayersTurn;
}

void BlackJackSimulator::SetNextPlayer() {
    switch(GetPlayerTurn()) {
        case(1):
            m_currentPlayer = m_player1;
        case(2):
            m_currentPlayer = m_player2;
    }
}

bool BlackJackSimulator::CheckIfGameHasEnded() {
    return (m_player1->GetStatus() && m_player2->GetStatus());
}

void BlackJackSimulator::CheckIfPlayerIsBust() {
    int sum = m_currentPlayer->GetValueInHand();
    if(sum > 21) {
        m_currentPlayer->SetStatus(true, true);
//std::cout << "Player " << GetPlayerTurn() << " is bust!" << std::endl;
        m_whichPlayersTurn = m_whichPlayersTurn * -1;
        SetNextPlayer();
    }
}

void BlackJackSimulator::AskPlayerStickOrTwist() {
    //Pass in strategy function here to determine to stick or twist
//std::cout << "stick or twist? ";
    std::string decision = Decider();
//std::cout << "Decision was " << decision << std::endl;
    
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

int BlackJackSimulator::GameOutcome(std::map<BasicPlayer*, int>& results) {
    if(m_player1->GoneBust() && m_player2 ->GoneBust()) {
        //std::cout << "No winners here!" << std::endl;
        return 0;
    }
    if(m_player1->GoneBust()) {
        //std::cout << "Player 2 wins!!" << std::endl;
        results[m_player2] += 1;
        return 2;
    }
    if(m_player2->GoneBust()) {
        //std::cout << "Player 1 wins!!" << std::endl;
        results[m_player1] += 1;
        return 1;
    }
    if(m_player1->GetValueInHand() > m_player2->GetValueInHand()) {
        //std::cout << "Player 1 wins with " << m_player1->GetValueInHand() << std::endl;
        results[m_player1] += 1;
        return 1;
    }
    if(m_player1->GetValueInHand() < m_player2->GetValueInHand()) {
        //std::cout << "Player 2 wins with " << m_player2->GetValueInHand() << std::endl;
        results[m_player2] += 1;
        return 2;
    }
    //std::cout << "Its a draw!!" << std::endl;
    return 0;
}

std::string BlackJackSimulator::Decider() {
    int value = 1;
    if(GetPlayerTurn() == 1) {
        value = 17;
    }
    if(GetPlayerTurn() == 2) {
        if(m_player1->GoneBust()) {
            value = 1;
            //Introduce safe strategy to maximise winning
        }
        value = 16;
    }
    if(m_currentPlayer->GetValueInHand() < value) {
        return "twist";
    }
    else return "stick";
}

void BlackJackSimulator::Reset(int cardsDealt) {
    m_whichPlayersTurn = 1;
    m_currentPlayer = m_player1;
    
    // Reshuffle into deck
    for(int i = 0; i < m_player1->GetNoOfCardsInHand(); i++) {
        m_deck->AddCard(m_player1->GetCardsInHand()[i]);
    }
    
    for(int i = 0; i < m_player2->GetNoOfCardsInHand(); i++) {
        m_deck->AddCard(m_player2->GetCardsInHand()[i]);
    }
    
    m_player1->Reset();
    m_player2->Reset();
}
