#ifndef __JOYSCENE_H__
#define __JOYSCENE_H__

#include "cocos2d.h"
#include "Joystick.h"
#include "Player.h"

class JoyScene : public cocos2d::Scene
{
private:
    bool isControllPressed;
    Joystick *joystick;
    Player *m_pPlayer;

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(JoyScene);
};

#endif // __JOYSCENE_H__