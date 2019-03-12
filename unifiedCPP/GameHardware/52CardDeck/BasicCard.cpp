//
//  Card.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include "BasicCard.hpp"
#include <string>

BasicCard::BasicCard(int value, CardSuit cardSuit, SpecialCard specialCard) {
    m_cardSuit = cardSuit;
    m_value = value;
    m_specialCard = specialCard;
}

int BasicCard::GetValue() {
    return m_value;
}

CardSuit BasicCard::GetSuit() {
    return m_cardSuit;
}

SpecialCard BasicCard::GetSpecialType() {
    return m_specialCard;
}

std::string BasicCard::GetSuitText() {
    CardSuit cardSuit = BasicCard::GetSuit();
    switch(cardSuit) {
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

std::string BasicCard::GetSpecialTypeText() {
    SpecialCard cardType = BasicCard::GetSpecialType();
    switch(cardType) {
        case NONE:
            return std::to_string(GetValue());
        case JACK:
            return "JACK";
        case QUEEN:
            return "QUEEN";
        case KING:
            return "KING";
        case ACE:
            return "ACE";
    }
    return "";
}
