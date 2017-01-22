//
//  WelcomeLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"

USING_NS_CC;

class WelcomeLayer : public Layer {
public:
    
    WelcomeLayer();
    
    ~WelcomeLayer();
    
    virtual bool init();
    
    CREATE_FUNC(WelcomeLayer);
    
    void loadingDone(Node* pNode);
    
    bool isHaveSaveFile();
    
    void getHighestHistoryScore();
};
