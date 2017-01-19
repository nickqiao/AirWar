//
//  GameLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/18.
//
//

#include "GameLayer.hpp"

GameLayer::GameLayer() {
    background1 = nullptr;
    background2 = nullptr;
    planeLayer = nullptr;
}

GameLayer::~GameLayer() {

}

bool GameLayer::init() {
    bool bRet = false;
    do {
        if (!Layer::init()) {
            return false;
        }
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot_background.plist");
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shoot.plist");
        
        background1 = Sprite::createWithSpriteFrameName("background.png");
        background1->setAnchorPoint(Point::ZERO);
        background1->setPosition(Point::ZERO);
        background1->getTexture()->setAliasTexParameters();
        this->addChild(background1);
        
        background2 = Sprite::createWithSpriteFrameName("background.png");
        background2->setAnchorPoint(Point::ZERO);
        background2->setPosition(Point(0, background2->getContentSize().height - 2));
        background2->getTexture()->setAliasTexParameters();
        this->addChild(background2);
        
        this->planeLayer = PlaneLayer::create();
        this->addChild(planeLayer);
        
        this->schedule(schedule_selector(GameLayer::backgroundMove), 0.01f);
        this->scheduleUpdate();
        bRet = true;
    } while (0);
    return bRet;
    
}

void GameLayer::backgroundMove(float dt) {

    background1->setPositionY(int(background1->getPositionY()) - 2);
    background2->setPositionY(int(background1->getPositionY()) + int(background1->getContentSize().height) - 2);
    if (background2->getPositionY() == 0) {
        background1->setPositionY(0);
    }
}
