//
//  main.cpp
//  unifiedCPP
//
//  Created by Harry Prudden on 20/02/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"

int main() {
    Deck deck;
    Player harry("Harry", &deck);
    return 0;
}
