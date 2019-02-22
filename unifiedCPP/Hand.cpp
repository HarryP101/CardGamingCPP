//
//  Hand.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 21/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "Hand.hpp"
#include <iostream>

Hand::Hand(Deck* deck) {
    m_deck = deck;
    m_noCardsInHand = 3;
    m_totalValueHand = 0;
    for(unsigned int i = 0; i < m_noCardsInHand; i++) {
        m_cardsInHand.push_back(m_deck->DrawCard());
        m_totalValueHand += m_cardsInHand[i].GetValue();
    }
}

int Hand::GetNoCardsInHand() {
    return m_noCardsInHand;
}

Card Hand::PlayCard(int index) {
    if(m_cardsInHand.empty()){
        std::cout << "Hand is empty!!" << std::endl;
        // Need to add a throw statement here
    }
    Card card = m_cardsInHand[index];
    m_cardsInHand.erase(m_cardsInHand.begin()+index);
    m_noCardsInHand -= 1;
    return card;
}

