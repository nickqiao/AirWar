//
//  BulletLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/19.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

class BulletLayer : public Layer {
    
public:
    
    BulletLayer();
    
    ~BulletLayer();
    
    CREATE_FUNC(BulletLayer);
    
    virtual bool init();
    
    void AddBullet(float dt);
    
    void bulletMoveFinished(Node* pSender);
    
    void RemoveBullet(Sprite* bullet);
    
    void StartShoot(float delay = 0.0f);
    
    void StopShoot();
    
public:
    
    __Array* m_pAllBullet;
    
};
