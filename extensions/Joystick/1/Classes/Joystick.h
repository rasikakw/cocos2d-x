#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Joystick : public Layer
{

private:
    bool isPressed;
    Point kCenter;
    Sprite *thumb;
    Point velocity;

    void updateVelocity(Point point);

    void resetJoystick();

    bool handleLastTouch();

    virtual void onEnter();

    virtual void onExit();

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

    void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

public:
    virtual bool init();

    Point getVelocity()
    {
        return velocity;
    }

    CREATE_FUNC(Joystick);
};