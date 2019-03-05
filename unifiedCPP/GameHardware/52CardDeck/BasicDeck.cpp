//
//  BasicDeck.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include <random>
#include <iostream>
#include "BasicDeck.hpp"
#include "BasicCard.hpp"
#include "../DeckHandle.hpp"

BasicDeck::BasicDeck() : DeckHandle() {
    m_noOfCardsLeft = 52;
    for(unsigned int i = 2; i < 13; i++) {
        m_cardsLeft.push_back(BasicCard(i, HEARTS));
        m_cardsLeft.push_back(BasicCard(i, DIAMONDS));
        m_cardsLeft.push_back(BasicCard(i, CLUBS));
        m_cardsLeft.push_back(BasicCard(i, SPADES));
    }
}

int BasicDeck::GetNoOfCardsLeft() {
    return m_noOfCardsLeft;
}

BasicCard BasicDeck::DrawCard() {
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, m_noOfCardsLeft-1);
    int index = dist(rng);
    BasicCard cardDrawn = m_cardsLeft[index];
    m_noOfCardsLeft -= 1;
    m_cardsLeft.erase(m_cardsLeft.begin()+index);
    return cardDrawn;
}
