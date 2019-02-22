//
//  Hand.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 21/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include "Card.hpp"
#include "Deck.hpp"

class Hand {
public:
    Hand(Deck* deck);
    Card PlayCard(int index);
    int GetNoCardsInHand();
private:
    std::vector<Card> m_cardsInHand;
    int m_noCardsInHand;
    int m_totalValueHand;
    Deck* m_deck;
};

#endif /* Hand_hpp */
