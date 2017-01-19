//
//  GameLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/18.
//
//

#include "cocos2d.h"
#include "PlaneLayer.hpp"

USING_NS_CC;

class GameLayer : public Layer {
    
public:
    GameLayer();
    
    ~GameLayer();
    
    CREATE_FUNC(GameLayer);
    
    virtual bool init();
    
    void backgroundMove(float dt);
    
private:
    Sprite* background1;
    Sprite* background2;
    
    PlaneLayer* planeLayer;
    
};


