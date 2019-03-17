//
//  BasicPlayer.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 04/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "BasicPlayer.hpp"
#include <iostream>

BasicCard BasicPlayer::PlayCard(int index) {
    return m_cardsInHand[index];
}
void BasicPlayer::PrintCardsInHand() {
    std::cout << "Player " << GetPlayerID() << " has" << std::endl;
    for(int i = 0; i < m_noOfCardsInHand; i++)
        std::cout << m_cardsInHand[i].GetSpecialTypeText() << " of " << m_cardsInHand[i].GetSuitText() << std::endl;
}

void BasicPlayer::DrawCard() {
    m_cardsInHand.push_back(m_deck->DrawCard());
    m_noOfCardsInHand += 1;
}

std::vector<BasicCard> BasicPlayer::GetCardsInHand() {
    return m_cardsInHand;
}

int BasicPlayer::GetPlayerID() {
    return m_playerID;
}

void BasicPlayer::SetStatus(bool finished, bool goneBust) {
    m_goneBust = goneBust;
    m_finished = finished;
}

bool BasicPlayer::GetStatus() {
    return m_finished;
}

bool BasicPlayer::GoneBust() {
    return m_goneBust;
}

int BasicPlayer::GetValueInHand() {
    int sum = 0;
    for(int i = 0; i < m_noOfCardsInHand; i++) {
        sum += m_cardsInHand[i].GetValue();
    }
    return sum;
}

void BasicPlayer::Reset() {
    m_goneBust = false;
    m_finished = false;
    m_cardsInHand.clear();
    for(int i = 0; i < m_cardsDealt; i++) {
        m_cardsInHand.push_back(m_deck->DrawCard());
    }
    m_noOfCardsInHand = m_cardsDealt;
}


