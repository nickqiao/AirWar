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
    highestScoreLabel = nullptr;
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
        
        auto normalBackToGame = Sprite::createWithSpriteFrameName("btn_finish.png");
        auto pressedBackToGame = Sprite::createWithSpriteFrameName("btn_finish.png");
        auto pBackItem = MenuItemSprite::create(normalBackToGame, pressedBackToGame, nullptr, CC_CALLBACK_1(GameOverLayer::menuBackCallback, this));
        
        pBackItem->setPosition(Point(winSize.width - normalBackToGame->getContentSize().width/2 - 10,
                                     normalBackToGame->getContentSize().height / 2 + 10));
        
        auto menuBack = Menu::create(pBackItem, NULL);
        menuBack->setPosition(Point(Point::ZERO));
        this->addChild(menuBack);
        
        Value strScore(score);
        auto finalScore = Label::createWithBMFont("font.fnt", strScore.asString());
        finalScore->setColor(Color3B(143,146,147));
        finalScore->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(finalScore);
        
        auto delay = DelayTime::create(1.0f);
        auto scalebig = ScaleTo::create(1.0f, 3.0f);
        auto scaleLittle = ScaleTo::create(0.3f, 2.0f);
        auto AD = CallFuncN::create(CC_CALLBACK_0(GameOverLayer::showAD, this));
        auto sequence = Sequence::create(delay, scalebig, scaleLittle, AD, nullptr);
        finalScore->runAction(sequence);
        
        Value strHighestScore(highestHistoryScore);
        highestScoreLabel = Label::createWithBMFont("font.fnt", strHighestScore.asString());
        highestScoreLabel->setColor(Color3B(143,146,147));
        highestScoreLabel->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
        highestScoreLabel->setPosition(Point(140, winSize.height - 30));
        this->addChild(highestScoreLabel);
        
        if (score > highestHistoryScore) {
            UserDefault::getInstance()->setIntegerForKey("HighestScore", score);
            highestHistoryScore = score;
            auto delayChange = DelayTime::create(1.3f);
            auto moveOut = MoveBy::create(0.1f, Point(0,100));
            auto beginChange = CallFuncN::create(CC_CALLBACK_1(GameOverLayer::beginChangeHighestScore, this));
            auto moveIn = MoveBy::create(0.1f, Point(0,-100));
            auto sequence = Sequence::create(delayChange, moveOut, beginChange, moveIn, NULL);
            highestScoreLabel->runAction(sequence);
        }
        
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

void GameOverLayer::menuBackCallback(cocos2d::Ref *pSender) {
    auto pScene = GameScene::create();
    auto animateScene = TransitionSlideInL::create(0.8f, pScene);
    Director::getInstance()->replaceScene(animateScene);
}

void GameOverLayer::beginChangeHighestScore(cocos2d::Node *pNode) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("achievement.mp3");
    Value changeScore(score);
    highestScoreLabel->setString(changeScore.asString());
}

void GameOverLayer::showAD() {
    log("添加广告");
}
