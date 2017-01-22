//
//  GameLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/18.
//
//

#include "cocos2d.h"
#include "PlaneLayer.hpp"
#include "BulletLayer.hpp"
#include "EnemyLayer.hpp"
USING_NS_CC;

class GameLayer : public Layer {
    
public:
    GameLayer();
    
    ~GameLayer();
    
    CREATE_FUNC(GameLayer);
    
    virtual bool init();
    
    void backgroundMove(float dt);
    
    bool onTouchBegan(Touch* touch, Event  *event);
    
    void onTouchMoved(Touch* touch, Event  *event);
    
    void onTouchEnded(Touch* touch, Event  *event);
    
    static Level getCurLevel();
    
private:
    Sprite* background1;
    Sprite* background2;
    
    PlaneLayer* planeLayer;
    BulletLayer* bulletLayer;
    EnemyLayer* enemyLayer;
    
    static Level level;
    
};


