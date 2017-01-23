//
//  GameOverLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "GameOverLayer.hpp"
#include "GameScene.hpp"

int GameOverLayer::highestHistoryScore = 0;

GameOverLayer::GameOverLayer() {
    
    score = 0;
    highestScore = nullptr;
}

GameOverLayer::~GameOverLayer() {

}

bool GameOverLayer::init() {
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        
        if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
            CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        }
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("game_over.mp3");
        
        auto winSize = Director::getInstance()->getWinSize();
        
        Sprite* background = Sprite::createWithSpriteFrameName("gameover.png");
        background->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(background);
        
        
        
        bRet = true;
    } while (0);
    return bRet;
}

GameOverLayer* GameOverLayer::create(int score) {
    GameOverLayer* pRet = new GameOverLayer();
    pRet->score = score;
    if (pRet && pRet->init()) {
        pRet->autorelease();
    }else {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

