//
//  TestDeck.swift
//  ShitHead
//
//  Created by Harry Prudden on 31/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

import Foundation

class TestDeck {
    
    public var NumberOfCardsLeft: Int!
    public var CardsLeft = [TestCard]()
    
    init() {
        
        NumberOfCardsLeft = 52
        for i in 2...15 {
            var value = i
            var specialCard = SpecialCard.normal
            
            if(i == 11) {
                specialCard = SpecialCard.jack
                value = 10
            }
            
            if(i == 12) {
                specialCard = SpecialCard.queen
                value = 10
            }
            
            if(i == 13) {
                specialCard = SpecialCard.king
                value = 10
            }
            
            if(i == 14) {
                specialCard = SpecialCard.ace
                value = 10
            }

            CardsLeft.append(TestCard(Value: value, Suit: CardSuit.hearts, Special: specialCard, X: 0, Y: 0))
            CardsLeft.append(TestCard(Value: value, Suit: CardSuit.diamonds, Special: specialCard, X: 0, Y: 0))
            CardsLeft.append(TestCard(Value: value, Suit: CardSuit.clubs, Special: specialCard, X: 0, Y: 0))
            CardsLeft.append(TestCard(Value: value, Suit: CardSuit.spades, Special: specialCard, X: 0, Y: 0))
        }
        
    }
    
    func DrawCard() -> TestCard {
        assert(NumberOfCardsLeft != 0)
        let randomIndex = Int(arc4random_uniform(UInt32(NumberOfCardsLeft - 1)))
        let cardDrawn = CardsLeft[randomIndex]
        NumberOfCardsLeft -= 1
        CardsLeft.remove(at: randomIndex)
        return cardDrawn
    }
    
    func ShuffleCard(Card: TestCard) {
        CardsLeft.append(Card)
        NumberOfCardsLeft += 1
    }
}
