//
//  WelcomeScene.hpp
//  AirWar
//
//  Created by nick on 2017/1/22.
//  Copyright © 2017年 chenyuqiao. All rights reserved.
//

#include "cocos2d.h"
#include "WelcomeLayer.hpp"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class WelcomeScene : public Scene {
public:
    
    WelcomeScene();
    
    ~WelcomeScene();
    
    virtual bool init();
    
    CREATE_FUNC(WelcomeScene);
    
    void PreloadMusic();
    
public:
    
    WelcomeLayer* _welcomeLayer;
};
