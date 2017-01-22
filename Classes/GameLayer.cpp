//
//  GameLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/18.
//
//

#include "GameLayer.hpp"

Level GameLayer::level = EASY;

GameLayer::GameLayer() {
    background1 = nullptr;
    background2 = nullptr;
    planeLayer = nullptr;
    bulletLayer = nullptr;
    enemyLayer = nullptr;
}

GameLayer::~GameLayer() {

}

bool GameLayer::init() {
    bool bRet = false;
    do {
        if (!Layer::init()) {
            return false;
        }
        
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
        
        this->bulletLayer = BulletLayer::create();
        this->addChild(bulletLayer);
        bulletLayer->StartShoot();
        
        this->enemyLayer = EnemyLayer::create();
        this->addChild(enemyLayer);
        
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
        listener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
        listener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
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

bool GameLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    return true;
}

void GameLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    if (this->planeLayer->isAlive) {
        Point beginPoint = touch->getLocation();
        Rect planeRect = this->planeLayer->getChildByTag(AIRPLANE)->getBoundingBox();
        planeRect.origin.x -= 15;
        planeRect.origin.y -= 15;
        planeRect.size.width += 30;
        planeRect.size.height += 30;
        if (planeRect.containsPoint(this->getParent()->convertTouchToNodeSpace(touch))) {
            Point endPoint = touch->getPreviousLocation();
            
            Point offSet = beginPoint - endPoint;
            Point toPoint = this->planeLayer->getChildByTag(AIRPLANE)->getPosition() + offSet;
            this->planeLayer->MoveTo(toPoint);
        }
    }
}

void GameLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {

}

Level GameLayer::getCurLevel() {
    return level;
}

