#include "JoyScene.h"

USING_NS_CC;

Scene* JoyScene::createScene()
{
    return JoyScene::create();
}

bool JoyScene::init()
{
    if ( !Scene::init() )
        return false;

    // Add joystick.
    joystick =  Joystick::create();
    this->addChild(joystick, 2);

    // Add player.
    m_pPlayer = Player::node();
    m_pPlayer->initPlayer();
    m_pPlayer->setJoystick(joystick);
    this->addChild(m_pPlayer);

    scheduleUpdate();

    return true;
}