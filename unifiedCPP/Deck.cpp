//
//  Deck.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "Deck.hpp"
#include <iostream>
#include <random>

Deck::Deck() {
    m_noCardsLeft = 52;
    for(unsigned int i = 0; i < 13; i++) {
        m_cardsLeft.push_back(Card(i+2, HEARTS));
        m_cardsLeft.push_back(Card(i+2, DIAMONDS));
        m_cardsLeft.push_back(Card(i+2, SPADES));
        m_cardsLeft.push_back(Card(i+2, CLUBS));
    }
}

int Deck::GetNoCardsLeft() {
    return m_noCardsLeft;
}

Card Deck::DrawCard() {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, m_noCardsLeft-1);
    int index = dist(rng);
    Card cardDrawn = m_cardsLeft[index];
    m_noCardsLeft -= 1;
    m_cardsLeft.erase(m_cardsLeft.begin()+index);
    return cardDrawn;
}


