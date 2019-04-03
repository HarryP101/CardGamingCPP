//
//  TestPlayer.swift
//  ShitHead
//
//  Created by Harry Prudden on 31/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

import Foundation

class TestPlayer {
    
    public var deck: TestDeck!
    public var bust: Bool!
    public var folded: Bool!
    public var finished: Bool!
    public var numberOfCardsInHand: Int!
    
    public var cardsInHand = [TestCard]()
    
    init(deck: TestDeck, cardsDealt: Int) {
        self.deck = deck
        bust = false
        folded = false
        finished = false
        
        numberOfCardsInHand = cardsDealt
        
        for _ in 0...numberOfCardsInHand {
            cardsInHand.append(self.deck.DrawCard())
        }
    }
    
    func PlayCard(index: Int) -> TestCard {
        assert(numberOfCardsInHand != 0)
        return cardsInHand[index]
    }
    
    func DrawCard() {
        assert(self.deck.NumberOfCardsLeft != 0)
        cardsInHand.append(self.deck.DrawCard())
        numberOfCardsInHand += 1
    }
}
