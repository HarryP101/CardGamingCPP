//
//  Card.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "BasicCard.hpp"
#include <string>

BasicCard::BasicCard(int value, CardType cardType) {
    m_cardType = cardType;
    m_value = value;
}

int BasicCard::GetValue() {
    return m_value;
}

CardType BasicCard::GetType() {
    return m_cardType;
}

std::string BasicCard::GetTypeText() {
    CardType cardType = BasicCard::GetType();
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
