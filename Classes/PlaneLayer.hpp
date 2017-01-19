//
//  PlaneLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/19.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"

USING_NS_CC;

const int AIRPLANE=747;

class PlaneLayer : public Layer {
public:
    
    PlaneLayer();
    
    ~PlaneLayer();
    
    static PlaneLayer* create();
    
    virtual bool init();
    
    void MoveTo(Point location);
    
    void Blowup(int passScore);
    
    void RemovePlane();
    
public:
    
    static PlaneLayer* sharedPlane;
    
    bool isAlive;
    
    int score;
    
};


