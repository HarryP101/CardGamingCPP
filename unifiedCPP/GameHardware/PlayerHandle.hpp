//
//  HandHandle.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 04/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef HandHandle_hpp
#define HandHandle_hpp

#include <stdio.h>
class PlayerHandle{
public:
    virtual ~PlayerHandle() {
    }
    virtual int GetNoOfCardsInHand() = 0;
protected:
    int m_noOfCardsInHand;
};

#endif /* HandHandle_hpp */
