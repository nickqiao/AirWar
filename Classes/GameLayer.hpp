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
#include "ControlLayer.hpp"
#include "MutiBulletsLayer.hpp"
#include "UFOLayer.hpp"

USING_NS_CC;

const int ENEMY1_SCORE = 1000;
const int ENEMY2_SCORE = 1000;
const int ENEMY3_SCORE = 1000;

const int MAX_BIGBOOM_COUNT = 100000;
const int TAG_BIGBOOM_MENUITEM = 1;
const int TAG_BIGBOOMCOUNT_LABEL = 2;

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
    
    void update(float dt);
    
    void menuBigBoomCallback(Ref* pSender);
    
    void updateBigBoomItem(int bigBoomCount);
    
    static Level getCurLevel();
    
private:
    Sprite* background1;
    Sprite* background2;
    
    PlaneLayer* planeLayer;
    BulletLayer* bulletLayer;
    EnemyLayer* enemyLayer;
    ControlLayer* controlLayer;
    MutiBulletsLayer* mutiBulletLayer;
    UFOLayer* ufoLayer;
    
    Menu* menuBigBoom;
    Label* bigBoomCountItem;
    
    int score;
    int bigBoomCount;
    static Level level;
    
    void dealWithEnemy1Collide(__Array* bulletsToDelete);
    void dealWithEnemy2Collide(__Array* bulletsToDelete);
    void dealWithEnemy3Collide(__Array* bulletsToDelete);
    
    void mutiBulletEnemy1Collide(__Array* mutiBulletsToDelete);
    void mutiBulletEnemy2Collide(__Array* mutiBulletsToDelete);
    void mutiBulletEnemy3Collide(__Array* mutiBulletsToDelete);
    
    void ufoCollide();
    void bigBoom();
    
    void checkPlaneCollide();
    
};


