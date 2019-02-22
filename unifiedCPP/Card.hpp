//
//  Card.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>
#include <string>

enum CardType {HEARTS, DIAMONDS, SPADES, CLUBS};

class Card {
public:
    Card(int value, CardType cardType);
    int GetValue();
    CardType GetType();
    std::string GetTypeText();
private:
    int m_value;
    CardType m_cardType;
    std::string m_cardTypeText;
};

#endif /* Card_hpp */
