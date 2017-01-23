//
//  GameOverScene.hpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#pragma once

#include "cocos2d.h"
#include "GameOverLayer.hpp"
USING_NS_CC;

class GameOverScene : public Scene {
    
public:
    
    GameOverScene();
    
    ~GameOverScene();
    
    static GameOverScene* create(int passScore);
    
    virtual bool init();
    
public:
    
    GameOverLayer* gameOverlayer;
    
    int score;
};
