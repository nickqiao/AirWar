//
//  ControlLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "NoTouchLayer.hpp"

USING_NS_CC;

const int MAX_SCORE = 1000000000;

class ControlLayer : public Layer {
    
public:
    
    ControlLayer();
    
    ~ControlLayer();
    
    virtual bool init();
    
    CREATE_FUNC(ControlLayer);
    
    void menuPauseCallback(Ref* pSender);
    
    void updateScore(int score);
 
public:
    
    Label* scoreItem;
    
    MenuItemSprite* pPauseItem;
    
    NoTouchLayer* noTouchLayer;
};
