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
    BasicPlayer(BasicDeck* deck, int cardsDealt, int playerID) {
        m_deck = deck;
        m_playerID = playerID;
        m_goneBust = false;
        m_finished = false;
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
    int GetValueInHand();
    void PrintCardsInHand();
    void DrawCard();
    int GetPlayerID();
    void SetStatus(bool finished, bool goneBust);
    bool GetStatus();
    bool GoneBust();
private:
    int m_playerID;
    std::vector<BasicCard> m_cardsInHand;
    BasicDeck* m_deck;
    bool m_goneBust;
    bool m_finished;
};
#endif /* BasicPlayer_hpp */
