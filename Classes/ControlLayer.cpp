//
//  ControlLayer.cpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "ControlLayer.hpp"

ControlLayer::ControlLayer() {
    scoreItem = nullptr;
    pPauseItem = nullptr;
}

ControlLayer::~ControlLayer() {

}

bool ControlLayer::init() {
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!Layer::init());
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void ControlLayer::menuPauseCallback(cocos2d::Ref *pSender) {
    
}

void ControlLayer::updateScore(int score) {
    
}
