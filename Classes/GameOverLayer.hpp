//
//  GameOverLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class GameOverLayer : public Layer {
public:
    
    GameOverLayer();
    
    ~GameOverLayer();
    
    virtual bool init();
    
    static GameOverLayer* create(int score);
    
    void menuBackCallback(Ref* pSender);
    
    void beginChangeHighestScore(Node* pNode);
  
public:
    
    int score;
    
    static int highestHistoryScore;
    
    Label* highestScore;
    
};
