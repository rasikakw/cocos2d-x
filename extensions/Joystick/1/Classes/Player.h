#pragma once

#include "cocos2d.h"
#include "Joystick.h"

#ifndef PTM_RATIO
#define PTM_RATIO 32
#endif

using namespace cocos2d;

class Player : public Node
{
private:
    Sprite *pPlayer;
    Sprite *pShadow;
    Animate *stoneMove;
    Speed *action;
    Joystick *m_pJoystick;

    virtual void update(float dt);
public:
    Player();
    ~Player();
    void initPlayer();
    static Player* node(void);
    void setJoystick(Joystick *joystick);
};