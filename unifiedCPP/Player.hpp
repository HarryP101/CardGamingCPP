//
//  Player.hpp
//  unifiedCPP
//
//  Created by Harry Prudden on 21/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Deck.hpp"
#include "Hand.hpp"

class Player : public Hand {
public:
    Player(std::string playerName, Deck* deck);
private:
    std::string m_playerName;
};
#endif /* Player_hpp */
