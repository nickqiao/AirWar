//
//  UFOLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class UFOLayer : public Layer {
    
public:
    
    UFOLayer(void);
    
    ~UFOLayer(void);
    
    virtual bool init();
    
    CREATE_FUNC(UFOLayer);
    
    void AddMutiBullets(float dt);
    
    void mutiBulletsMoveFinished(Node* pSender);
    
    void AddBigBoom(float dt);
    
    void bigBoomMoveFinished(Node* pSender);
    
    void RemoveMutiBullets(Sprite* mutiBullets);
    
    void RemoveBigBoom(Sprite* bigBoom);
    
public:
    
    __Array* m_pAllMutiBullets;
    
    __Array* m_pAllBigBoom;
    
};
