//
//  BasicDeck.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef BasicDeck_hpp
#define BasicDeck_hpp

#include <stdio.h>
#include "BasicCard.hpp"
#include "../DeckHandle.hpp"

class BasicDeck : public DeckHandle {
public:
    BasicDeck();
    int GetNoOfCardsLeft();
    BasicCard DrawCard();
    void AddCard(BasicCard card);
private:
    std::vector<BasicCard> m_cardsLeft;
    int m_noOfCardsLeft;
};
#endif /* BasicDeck_hpp */
