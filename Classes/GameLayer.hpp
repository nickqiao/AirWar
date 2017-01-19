//
//  GameLayer.hpp
//  AirWar
//
//  Created by nick on 2017/1/18.
//
//

#ifndef GameLayer_hpp
#define GameLayer_hpp

USING_NS_CC;

class GameLayer : public Layer {
    
public:
    GameLayer();
    
    ~GameLayer();
    
    CREATE_FUNC(GameLayer);
    
    virtual bool init();
    
private:
    Sprite* background1;
    Sprite* background2;
    void backgroundMove(float dt);
};

#endif /* GameLayer_hpp */
