//
//  Card.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef BasicCard_hpp
#define BasicCard_hpp

#include <stdio.h>
#include <string>
#include "../CardHandle.hpp"

enum CardSuit {HEARTS, DIAMONDS, SPADES, CLUBS};
enum SpecialCard {NONE, JACK, QUEEN, KING, ACE};

class BasicCard : public CardHandle {
public:
    BasicCard(int value, CardSuit cardType, SpecialCard specialCard);
    int GetValue();
    CardSuit GetSuit();
    SpecialCard GetSpecialType();
    std::string GetSpecialTypeText();
    std::string GetSuitText();
private:
    int m_value;
    CardSuit m_cardSuit;
    SpecialCard m_specialCard;
    std::string m_cardTypeText;
};

#endif /* Card_hpp */
