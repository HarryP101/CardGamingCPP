//
//  BasicPlayer.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 04/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef BasicPlayer_hpp
#define BasicPlayer_hpp

#include <stdio.h>
#include <iostream>
#include "BasicCard.hpp"
#include "BasicDeck.hpp"
#include "../PlayerHandle.hpp"

class BasicPlayer : public PlayerHandle {
public:
    BasicPlayer(BasicDeck* deck, int cardsDealt) {
        m_deck = deck;
        for(int i = 0; i < cardsDealt; i++) {
            m_cardsInHand.push_back(m_deck->DrawCard());
        }
        m_noOfCardsInHand = cardsDealt;
    }
    BasicCard PlayCard(int index);
    int GetNoOfCardsInHand() {
        return m_noOfCardsInHand;
    }
    std::vector<BasicCard> GetCardsInHand();
    void PrintCardsInHand();
    void DrawCard();
private:
    std::vector<BasicCard> m_cardsInHand;
    BasicDeck* m_deck;
};
#endif /* BasicPlayer_hpp */
