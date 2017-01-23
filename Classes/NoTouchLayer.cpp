//
//  NoTouchLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "NoTouchLayer.hpp"

bool NoTouchLayer::init(){
    if (!Layer::init() ){
        return false;
    }
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(NoTouchLayer::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(NoTouchLayer::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(NoTouchLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    listener->setSwallowTouches(true);
    
    return true;
}

bool NoTouchLayer::onTouchBegan (Touch *touch, Event *event) {
    return true;
}

void NoTouchLayer::onTouchMoved (Touch *touch, Event *event) {
    
}

void NoTouchLayer::onTouchEnded (Touch *touch, Event *event) {
    
}
