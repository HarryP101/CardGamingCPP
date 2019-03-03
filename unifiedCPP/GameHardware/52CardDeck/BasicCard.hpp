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

enum CardType {HEARTS, DIAMONDS, SPADES, CLUBS};

class BasicCard : public CardHandle {
public:
    BasicCard(int value, CardType cardType);
    int GetValue();
    CardType GetType();
    std::string GetTypeText();
private:
    int m_value;
    CardType m_cardType;
    std::string m_cardTypeText;
};

#endif /* Card_hpp */
