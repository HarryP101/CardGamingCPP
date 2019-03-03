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
#include "BasicCard.hpp"
#include "BasicDeck.hpp"

class Hand {
public:
    Hand(BasicDeck* deck);
    BasicCard PlayCard(int index);
    int GetNoCardsInHand();
private:
    std::vector<BasicCard> m_cardsInHand;
    int m_noCardsInHand;
    int m_totalValueHand;
    BasicDeck* m_deck;
};

#endif /* Hand_hpp */
