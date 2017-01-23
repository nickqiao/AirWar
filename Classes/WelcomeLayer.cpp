//
//  WelcomeLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "WelcomeLayer.hpp"
#include "GameScene.hpp"
#include "GameOverLayer.hpp"

WelcomeLayer::WelcomeLayer() {

}

WelcomeLayer::~WelcomeLayer() {

}

bool WelcomeLayer::init() {
    
    bool bRet = false;
    do {
        CC_BREAK_IF( !Layer::init() );
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");
        
        auto winSize = Director::getInstance()->getWinSize();
        
        auto background = Sprite::createWithSpriteFrameName("background.png");
        background->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(background);
        
        auto copyright = Sprite::createWithSpriteFrameName("shoot_copyright.png");
        copyright->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
        copyright->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(copyright);
        
        auto loading = Sprite::createWithSpriteFrameName("game_loading1.png");
        loading->setPosition(Point(winSize.width/2, winSize.height/2 - 40));
        this->addChild(loading);
        
        auto animation = Animation::create();
        animation->setDelayPerUnit(0.2f);
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading1.png"));
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading2.png"));
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading3.png"));
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("game_loading4.png"));
        
        auto animate = Animate::create(animation);
        auto repeat = Repeat::create(animate, 2);
        auto repeatDone = CallFuncN::create(CC_CALLBACK_1(WelcomeLayer::loadingDone, this));
        auto sequence = Sequence::create(repeat, repeatDone, NULL);
        loading->runAction(sequence);
        
        getHighestHistoryScore();
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void WelcomeLayer::loadingDone(cocos2d::Node *pNode) {
    
    auto pScene = GameScene::create();
    auto animateScene = TransitionMoveInB::create(0.5, pScene);
    Director::getInstance()->replaceScene(animateScene);
}

bool WelcomeLayer::isHaveSaveFile() {
    if ( !UserDefault::getInstance()->getBoolForKey("isHaveSaveFileXml") ) {
        UserDefault::getInstance()->setBoolForKey("isHaveSaveFileXml", true);
        UserDefault::getInstance()->setIntegerForKey("HighestScore", 0);
        UserDefault::getInstance()->flush();
        return false;
    }else {
        return true;
    }
}

void WelcomeLayer::getHighestHistoryScore() {
    if (isHaveSaveFile()) {
        GameOverLayer::highestHistoryScore = UserDefault::getInstance()->getIntegerForKey("HighestScore",0);
    }
}
