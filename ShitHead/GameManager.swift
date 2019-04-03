//
//  GameManager.swift
//  ShitHead
//
//  Created by Harry Prudden on 18/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

import SpriteKit

class GameManager {
    
    var m_scene: GameScene!
    var m_deck: TestDeck!
    var m_player: TestPlayer!
    var m_nextTime: Double?
    var m_timeExtension: Double = 0.15
    var m_playerDirection: Int = 2
    var m_currentScore: Int = 0

    
    init(scene: GameScene) {
        self.m_scene = scene
    }
    
    func initGame() {
        let cardsDealt = 2
        m_deck = TestDeck()
        m_player = TestPlayer(deck: m_deck, cardsDealt: cardsDealt)
        
        m_player.cardsInHand[0].ControlShape(Position: CGPoint(x: -550/2 , y: -1100/2), Hide: false)
        m_player.cardsInHand[1].ControlShape(Position: CGPoint(x: 550/2 - 170, y: -1100/2), Hide: false)
        self.m_scene.addChild(m_player.cardsInHand[0].shape)
        self.m_scene.addChild(m_player.cardsInHand[1].shape)
        
        // Add a stick and twist button
        
    }
    
    func update(time: Double) {
        if m_nextTime == nil {
            m_nextTime = time + m_timeExtension
        } else {
            if time >= m_nextTime! {
                m_nextTime = time + m_timeExtension
                //updatePlayersHand()
                //renderChange()
            }
        }
    }

    
    func renderChange() {
        
    }
    
    private func finishAnimation() {
                
        m_scene.gameBG.run(SKAction.scale(to: 0, duration: 0.4)) {
            self.m_scene.gameBG.isHidden = true
            self.m_scene.gameLogo.isHidden = false
            self.m_scene.gameLogo.run(SKAction.move(to: CGPoint(x: 0, y: (self.m_scene.frame.size.height / 2) - 200), duration: 0.5)) {
                
            }
        }
    }
    
    private func updateScore() {
        if m_currentScore > UserDefaults.standard.integer(forKey: "bestScore") {
            UserDefaults.standard.set(m_currentScore, forKey: "bestScore")
        }
        m_currentScore = 0
        m_scene.currentScore.text = "Score: 0"
    }
    
    func swipe(ID: Int) {
        if !(ID == 2 && m_playerDirection == 4) && !(ID == 4 && m_playerDirection == 2) {
            if !(ID == 1 && m_playerDirection == 3) && !(ID == 3 && m_playerDirection == 1) {
                if m_playerDirection  != 0 {
                    m_playerDirection = ID
                }
            }
        }
    }
    
    private func updatePlayersHand() {
        renderChange()
    }
}
