//
//  TestCard.swift
//  ShitHead
//
//  Created by Harry Prudden on 26/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

import Foundation
import GameplayKit
import SpriteKit

enum CardSuit {
    case hearts
    case diamonds
    case spades
    case clubs
}

enum SpecialCard {
    case normal
    case jack
    case queen
    case king
    case ace
}

class TestCard {
    
    public var m_value: Int!
    public var m_cardSuit: CardSuit!
    public var m_specialCard: SpecialCard!
    public var m_cardTypeText: String!
    public var shape: SKShapeNode!
    var shapeLabel: SKLabelNode!
    
    init(Value: Int, Suit: CardSuit, Special: SpecialCard, X: CGFloat, Y: CGFloat) {
        self.m_value = Value
        self.m_cardSuit = Suit
        self.m_specialCard = Special
        
        self.shape = SKShapeNode(rect: CGRect(x: 0, y: 0, width: 170, height: 300))
        self.shape.name = GetSpecialTypeText() + " of " + GetSuitText()
        self.shape.zPosition = 2
        self.shape.position = CGPoint(x: X, y: Y)
        self.shape.fillColor = SKColor.red
        self.shape.isHidden = true
        
        self.shapeLabel = SKLabelNode(fontNamed: "ArialRoundedMTBold")
        self.shapeLabel.text = GetSpecialTypeText() + " of " + GetSuitText()
        self.shapeLabel.fontSize = 20
        self.shapeLabel.zPosition = 3
        self.shapeLabel.fontColor = SKColor.white
        self.shapeLabel.position = CGPoint(x: 85, y: 150)
        self.shape.addChild(shapeLabel)
    }
    
    func GetSuitText() -> String {
        switch(m_cardSuit) {
        case .hearts?:
            return "hearts"
        case .diamonds?:
            return "diamonds"
        case .spades?:
            return "spades"
        case .clubs?:
            return "clubs"
        default:
            return "fs"
        }
        // Should throw error here if doesnt exist
    }
    
    func GetSpecialTypeText() -> String {
        switch(m_specialCard) {
        case .normal?:
            return String(m_value)
        case .jack?:
            return "jack"
        case .queen?:
            return "queen"
        case .king?:
            return "king"
        case .ace?:
            return "ace"
        default:
            return "naaaaaah"
        }
    }
    
    func ControlShape(Position: CGPoint, Hide: Bool) {
        self.shape.position = Position
        self.shape.isHidden = Hide
    }
    // Probably create another function here to show the card - maybe as it being drawn and then after on the scene?
    
}


