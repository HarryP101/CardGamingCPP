//
//  GameScene.swift
//  ShitHead
//
//  Created by Harry Prudden on 03/03/2019.
//  Copyright © 2019 Harry Prudden. All rights reserved.
//

import SpriteKit
import GameplayKit

class GameScene: SKScene {
    
    var gameLogo: SKLabelNode!

    var testCard: TestCard!
    var game: GameManager!
    var currentScore: SKLabelNode!
    var gameBG: SKShapeNode!
    var stickButton: SKShapeNode!
    var twistButton: SKShapeNode!

    var scorePos: CGPoint?
    
    override func didMove(to view: SKView) {
        initializeMenu()
        game = GameManager(scene: self)
        initializeGameView()
        
        let swipeRight:UISwipeGestureRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(swipeR))
        swipeRight.direction = .right
        view.addGestureRecognizer(swipeRight)
        
        let swipeLeft:UISwipeGestureRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(swipeL))
        swipeLeft.direction = .left
        view.addGestureRecognizer(swipeLeft)
        
        let swipeUp:UISwipeGestureRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(swipeU))
        swipeUp.direction = .up
        view.addGestureRecognizer(swipeUp)
        
        let swipeDown:UISwipeGestureRecognizer = UISwipeGestureRecognizer(target: self, action: #selector(swipeD))
        swipeDown.direction = .down
        view.addGestureRecognizer(swipeDown)
    }
    
    @objc func swipeR() {
        game.swipe(ID: 3)
    }
    
    @objc func swipeL() {
        game.swipe(ID: 1)
    }
    
    @objc func swipeU() {
        game.swipe(ID: 2)
    }
    
    @objc func swipeD() {
        game.swipe(ID: 4)
    }
    
    override func update(_ currentTime: TimeInterval) {
        // Called before each frame is rendered
        game.update(time: currentTime)
    }
    
    override func touchesBegan(_ touches:Set<UITouch>, with event: UIEvent?) {
        for touch in touches {
            let location = touch.location(in: self)
            let touchedNode = self.nodes(at: location)
            for node in touchedNode {
                if node.name == "king of spades" {
                    startGame()
                }
                if node.name == "twist" {
                    game.DrawCard()
                }
                // If node is a card in players hand
                // Play that card
            }
        }
    }
    
    private func startGame() {
        print("start game")
        
        gameLogo.run(SKAction.move(by: CGVector(dx: -50, dy: 600), duration: 0.5)) {
            self.gameLogo.isHidden = true
            self.testCard.shape.isHidden = true
        }
        
        let bottomCorner = CGPoint(x: 0, y: (frame.size.height / -2) + 20)
        currentScore.run(SKAction.move(to: bottomCorner, duration: 0.4)) {
            self.gameBG.setScale(0)
            self.currentScore.setScale(0)
            self.stickButton.setScale(0)
            self.twistButton.setScale(0)
            self.gameBG.isHidden = false
            self.currentScore.isHidden = false
            self.twistButton.isHidden = false
            self.stickButton.isHidden = false
            self.gameBG.run(SKAction.scale(to: 1, duration: 0.4))
            self.currentScore.run(SKAction.scale(to: 1, duration: 0.4))
            self.stickButton.run(SKAction.scale(to: 1, duration: 0.4))
            self.twistButton.run(SKAction.scale(to: 1, duration: 0.4))
            self.game.initGame()
        }
    }

    private func initializeMenu() {
        //Create game title
        gameLogo = SKLabelNode(fontNamed: "ArialRoundedMTBold")
        gameLogo.zPosition = 1
        gameLogo.position = CGPoint(x: 0, y: (frame.size.height / 2) - 400)
        gameLogo.fontSize = 80
        gameLogo.text = "BLACKJACK"
        gameLogo.fontColor = SKColor.yellow
        self.addChild(gameLogo)
        
        testCard = TestCard(Value: 10, Suit: CardSuit.spades, Special: SpecialCard.king, X: -85, Y: -150)
        testCard.shape.isHidden = false
        self.addChild(testCard.shape)
    }
    
    private func initializeGameView() {
        currentScore = SKLabelNode(fontNamed: "ArialRoundedMTBold")
        currentScore.zPosition = 1
        currentScore.position = CGPoint(x: 0, y: (frame.size.height / -2) + 60)
        currentScore.fontSize = 40
        currentScore.isHidden = true
        currentScore.text = "Score: 0"
        currentScore.fontColor = SKColor.white
        self.addChild(currentScore)
        
        let width = 550
        let height = 1100
        let rect = CGRect(x: -width / 2, y: -height / 2, width: width, height: height)
        gameBG = SKShapeNode(rect: rect, cornerRadius: 0.02)
        gameBG.fillColor = SKColor.darkGray
        gameBG.zPosition = 2
        gameBG.isHidden = true
        self.addChild(gameBG)
        
        stickButton = SKShapeNode(circleOfRadius: 30)
        stickButton.fillColor = SKColor.yellow
        stickButton.zPosition = 2
        stickButton.isHidden = true
        stickButton.position = CGPoint(x: -width/2+30, y: 0)
        self.addChild(stickButton)
        
        twistButton = SKShapeNode(circleOfRadius: 30)
        twistButton.name = "twist"
        twistButton.fillColor = SKColor.yellow
        twistButton.zPosition = 2
        twistButton.isHidden = true
        twistButton.position = CGPoint(x: width/2-30, y: 0)
        self.addChild(twistButton)
        
        
    }
    

}

