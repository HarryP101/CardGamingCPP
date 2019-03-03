//
//  Deck.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef DeckHandle_hpp
#define DeckHandle_hpp

#include <stdio.h>
#include <vector>
#include "CardHandle.hpp"

class DeckHandle {
public:
    virtual ~DeckHandle() {
    }
    virtual int GetNoOfCardsLeft() = 0;
protected:
    int m_noOfCardsLeft;
};

#endif /* Deck_hpp */
