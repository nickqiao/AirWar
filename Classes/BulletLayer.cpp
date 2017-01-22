//
//  BulletLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/19.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "BulletLayer.hpp"
#include "PlaneLayer.hpp"

BulletLayer::BulletLayer() {
    m_pAllBullet = __Array::create();
    m_pAllBullet->retain();
}

BulletLayer::~BulletLayer() {
    m_pAllBullet->release();
    m_pAllBullet = nullptr;
}

bool BulletLayer::init() {
    bool bRet = false;
    do {
        if (!Layer::init()) {
            return false;
        }
        bRet = true;
    } while (0);
    return bRet;
}

void BulletLayer::StartShoot(float delay) {
    this->schedule(schedule_selector(BulletLayer::AddBullet), 0.20f, kRepeatForever, delay);
}

void BulletLayer::StopShoot() {
    this->unschedule(schedule_selector(BulletLayer::AddBullet));
}

void BulletLayer::AddBullet(float dt) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bullet.mp3");
    auto bullet = Sprite::createWithSpriteFrameName("bullet1.png");
    this->addChild(bullet);
    this->m_pAllBullet->addObject(bullet);
    
    auto planePosition = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
    auto bulletPosition = Point(planePosition.x, planePosition.y + PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getContentSize().height / 2);
    bullet->setPosition(bulletPosition);
    
    float length = Director::getInstance()->getWinSize().height + bullet->getContentSize().height / 2 - bulletPosition.y;
    float velocity = 320 / 1;
    float realMoveDuration = length / velocity;
    
    auto actionMove = MoveTo::create(realMoveDuration, Point(bulletPosition.x, Director::getInstance()->getWinSize().height + bullet->getContentSize().height / 2));
    auto actionDone = CallFuncN::create(CC_CALLBACK_1(BulletLayer::bulletMoveFinished, this));
    auto sequence = Sequence::create(actionMove,actionDone, NULL);
    bullet->runAction(sequence);
}

void BulletLayer::bulletMoveFinished(cocos2d::Node *pSender) {
    auto bullet = (Sprite*)pSender;
    this->removeChild(bullet,true);
    this->m_pAllBullet->removeObject(bullet);
}

void BulletLayer::RemoveBullet(cocos2d::Sprite *bullet) {
    if (bullet != nullptr) {
        this->removeChild(bullet,true);
        this->m_pAllBullet->removeObject(bullet);
    }
}
