//
//  Deck.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

class Deck {
public:
    Deck();
    int GetNoCardsLeft();
    double GetProbability(int value, CardType cardType);
    Card DrawCard();
private:
    int m_noCardsLeft;
    std::vector<Card> m_cardsLeft;
};
#endif /* Deck_hpp */
