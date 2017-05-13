#include "Player.h"

void Player::update(float dt)
{
    float vx = m_pJoystick->getVelocity().x;
    float vy = m_pJoystick->getVelocity().y;

    //if (vx > 0.0f || vy > 0.0f)
    //    CCLOG("%f %f", vx, vy);

    // rotation ball by direction
    pPlayer->setRotation(-1 * CC_RADIANS_TO_DEGREES(ccpToAngle(Vec2(vx, vy))));

    setPosition(getPosition().x + vx, getPosition().y + vy);
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::initPlayer()
{
    Size s = Director::getInstance()->getWinSize();

    pPlayer = Sprite::create("Player.png");
    pPlayer->setPosition(Vec2(s.width / 2, s.height / 2));

    addChild(pPlayer);

    scheduleUpdate();
}

Player* Player::node( void )
{
    Player* pRet = new Player();
    pRet->autorelease();
    return pRet;
}

void Player::setJoystick(Joystick *joystick)
{
    m_pJoystick = joystick;
}