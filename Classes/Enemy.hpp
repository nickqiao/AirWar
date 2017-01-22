//
//  Enemy.hpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"

USING_NS_CC;

class Enemy : public Node {
public:
    
    Enemy();
    
    ~Enemy();
    
    static Enemy* create();
    
    void bindSprite(Sprite* sprite, int life);
    
    Sprite* getSprite();
    
    int getLife();
    
    void loseLife();
    
    Rect getBoundingBox();
    
private:
    
    Sprite* m_sprite;
    
    int m_life;
    
    
};
