//
//  GameOverScene.cpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "GameOverScene.hpp"

GameOverScene::GameOverScene() {
    gameOverlayer = nullptr;
    score = 0;
}

GameOverScene::~GameOverScene() {

}

bool GameOverScene::init() {
    bool bRet = false;
    do {
        CC_BREAK_IF(!Scene::init());
        
        gameOverlayer = GameOverLayer::create(score);
        this->addChild(gameOverlayer);
        bRet = true;
        
    } while (0);
    return bRet;
}

GameOverScene* GameOverScene::create(int passScore) {
    GameOverScene* pRet = new GameOverScene();
    pRet->score = passScore;
    if (pRet && pRet->init()) {
        pRet->autorelease();
    }else{
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}
