//
//  PlaneLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/19.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "PlaneLayer.hpp"

PlaneLayer* PlaneLayer::sharedPlane = nullptr;

PlaneLayer::PlaneLayer() {
}

PlaneLayer::~PlaneLayer() {
}

PlaneLayer* PlaneLayer::create() {
    
    PlaneLayer *pRet = new PlaneLayer();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        sharedPlane = pRet;
        return pRet;
    }else {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}

bool PlaneLayer::init() {
    bool bRet = false;
    do {
        if (!Layer::init()) {
            return false;
        }
        auto winSize = Director::getInstance()->getWinSize();
        
        auto plane = Sprite::createWithSpriteFrameName("hero1.png");
        plane->setPosition(Point(winSize.width / 2, plane -> getContentSize().height / 2));
        this->addChild(plane,0, AIRPLANE);
        
        auto blink = Blink::create(1, 3);
        
        auto animation = Animation::create();
        animation->setDelayPerUnit(0.1f);
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero1.png"));
        animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero2.png"));
        auto animate = Animate::create(animation);
        
        plane->runAction(blink);
        plane->runAction(RepeatForever::create(animate));

        bRet = true;
        
    } while (0);
    
    return bRet;
}

void PlaneLayer::MoveTo(Point location) {
    
}

void PlaneLayer::Blowup(int passScore) {
    
}

void PlaneLayer::RemovePlane() {

}
