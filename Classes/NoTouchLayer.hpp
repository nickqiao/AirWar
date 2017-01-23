//
//  NoTouchLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/23.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"

USING_NS_CC;

class NoTouchLayer : public Layer {
public:
    virtual bool init();
    
    // implement the "static node()" method manually
    CREATE_FUNC(NoTouchLayer);
    
    virtual bool onTouchBegan (Touch *touch, Event *event);
    
    virtual void onTouchMoved (Touch *touch, Event *event);
    
    virtual void onTouchEnded (Touch *touch, Event *event);
};
