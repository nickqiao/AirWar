//
//  MutiBulletsLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class MutiBulletsLayer : public Layer {
    
public:
    
    MutiBulletsLayer();
    
    ~MutiBulletsLayer();
    
    virtual bool init();
    
    CREATE_FUNC(MutiBulletsLayer);
    
    void AddMutiBullets(float dt);
    
    void mutiBulletsMoveFinished(Node* pSender);
    
    void RemoveMutiBullets(Sprite* mutiBullets);
    
    void StartShoot();
    
    void StopShoot();
    
public:
    
    __Array* m_pAllMutiBullets;
};
