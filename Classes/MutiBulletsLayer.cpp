//
//  MutiBulletsLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "MutiBulletsLayer.hpp"
#include "PlaneLayer.hpp"

MutiBulletsLayer::MutiBulletsLayer() {
    m_pAllMutiBullets = __Array::create();
    m_pAllMutiBullets->retain();
}

MutiBulletsLayer::~MutiBulletsLayer() {
    m_pAllMutiBullets->release();
    m_pAllMutiBullets = nullptr;
}

bool MutiBulletsLayer::init() {
    bool bRet = false;
    do {
        CC_BREAK_IF(!Layer::init());
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void MutiBulletsLayer::StartShoot() {
    this->schedule(schedule_selector(MutiBulletsLayer::AddMutiBullets), 0.2f, 30, 0.0f);
}

void MutiBulletsLayer::StopShoot() {
    this->unschedule(schedule_selector(MutiBulletsLayer::AddMutiBullets));
}

void MutiBulletsLayer::AddMutiBullets(float dt) {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("bullet.mp3");
    
    auto bulletLeft = Sprite::createWithSpriteFrameName("bullet2.png");
    auto bulletRight = Sprite::createWithSpriteFrameName("bullet2.png");
    this->addChild(bulletLeft);
    this->addChild(bulletRight);
    this->m_pAllMutiBullets->addObject(bulletLeft);
    this->m_pAllMutiBullets->addObject(bulletRight);
    
    auto planePosition = PlaneLayer::sharedPlane->getChildByTag(AIRPLANE)->getPosition();
    auto bulletLeftPosition = Point(planePosition.x - 33, planePosition.y + 35);
    auto bulletRightPosition = Point(planePosition.x + 33, planePosition.y + 35);
    bulletLeft->setPosition(bulletLeftPosition);
    bulletRight->setPosition(bulletRightPosition);
    
    float length = Director::getInstance()->getWinSize().height+bulletLeft->getContentSize().height/2-bulletLeftPosition.y;
    float velocity = 420/1;//420pixel/sec
    float realMoveDuration = length/velocity;
    
    auto actionLeftMove = MoveTo::create(realMoveDuration, Point(bulletLeftPosition.x, Director::getInstance()->getWinSize().height+bulletLeft->getContentSize().height/2));
    auto actionLeftDone = CallFuncN::create(CC_CALLBACK_1(MutiBulletsLayer::mutiBulletsMoveFinished, this));
    auto sequenceLeft = Sequence::create(actionLeftMove, actionLeftDone, nullptr);
    
    auto actionRightMove = MoveTo::create(realMoveDuration, Point(bulletRightPosition.x, Director::getInstance()->getWinSize().height+bulletRight->getContentSize().height/2));
    auto actionRightDone = CallFuncN::create(CC_CALLBACK_1(MutiBulletsLayer::mutiBulletsMoveFinished, this));
    auto sequenceRight = Sequence::create(actionRightMove, actionRightDone, nullptr);
    
    bulletLeft->runAction(sequenceLeft);
    bulletRight->runAction(sequenceRight);
}

void MutiBulletsLayer::mutiBulletsMoveFinished(cocos2d::Node *pSender) {
    auto mutiBullets = (Sprite*)pSender;
    m_pAllMutiBullets->removeObject(mutiBullets);
    this->removeChild(mutiBullets, true);
}

void MutiBulletsLayer::RemoveMutiBullets(cocos2d::Sprite *mutiBullets) {
    if (mutiBullets != nullptr)
    {
        this->m_pAllMutiBullets->removeObject(mutiBullets);
        this->removeChild(mutiBullets, true);
    }
}



