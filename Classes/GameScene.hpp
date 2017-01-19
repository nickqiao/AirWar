//
//  GameScene.hpp
//  AirWar
//
//  Created by nick on 2017/1/18.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"
#include "GameLayer.hpp"

USING_NS_CC;

class GameScene : public Scene {
public:
    
    GameScene();
    
    ~GameScene();
    
    CREATE_FUNC(GameScene);
    
    virtual bool init();
    
    GameLayer* _gameLayer;
    
};

#endif /* GameScene_hpp */
