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

void BasicPlayer::SetStatus(bool goneBust) {
    m_goneBust = goneBust;
}

bool BasicPlayer::GetStatus() {
    return m_goneBust;
}
