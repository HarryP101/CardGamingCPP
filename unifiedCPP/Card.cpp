//
//  Card.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "Card.hpp"
#include <string>

Card::Card(int value, CardType cardType) {
    m_value = value;
    m_cardType = cardType;
}

int Card::GetValue() {
    return m_value;
}

CardType Card::GetType() {
    return m_cardType;
}

std::string Card::GetTypeText() {
    CardType cardType = Card::GetType();
    switch(cardType) {
        case HEARTS:
            return "HEARTS";
        case DIAMONDS:
            return "DIAMONDS";
        case SPADES:
            return "SPADES";
        case CLUBS:
            return "CLUBS";
        }
    return "";
}
