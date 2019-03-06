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
    for(int i = 0; i < m_noOfCardsInHand; i++)
        std::cout << m_cardsInHand[i].GetValue() << " of " << m_cardsInHand[i].GetTypeText() << std::endl;
}

void BasicPlayer::DrawCard() {
    m_cardsInHand.push_back(m_deck->DrawCard());
    m_noOfCardsInHand += 1;
}
