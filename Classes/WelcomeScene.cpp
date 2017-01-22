//
//  WelcomeScene.cpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "WelcomeScene.hpp"

WelcomeScene::WelcomeScene() {
    _welcomeLayer = nullptr;
}

WelcomeScene::~WelcomeScene() {
    
}

bool WelcomeScene::init() {
    bool bRet = false;
    do {
        CC_BREAK_IF(!Scene::init());
        _welcomeLayer = WelcomeLayer::create();
        CC_BREAK_IF(!_welcomeLayer);
        this->addChild(_welcomeLayer);
        PreloadMusic();
        bRet = true;
    } while (0);
    
    return bRet;
}

void WelcomeScene::PreloadMusic() {
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("game_music.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("bullet.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("enemy1_down.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("enemy2_down.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("enemy3_down.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("game_over.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("get_bomb.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("get_double_laser.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("use_bomb.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("big_spaceship_flying.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("achievement.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("out_porp.mp3");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("button.mp3");
    
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("game_music.mp3",true);
}
