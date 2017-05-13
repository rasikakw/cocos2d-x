#include "Joystick.h"

#define JOYSTICK_OFFSET_X 5.0f
#define JOYSTICK_OFFSET_Y 5.0f
#define JOYSTICK_RADIUS 64.0f
#define STICK_RADIUS 26.0f

static Point convertCoordinate(Point point)
{
    return Director::getInstance()->convertToGL(point);
}

static bool isPointInCircle(Point point, Point center, float radius)
{
    float dx = (point.x - center.x);
    float dy = (point.y - center.y);
    return (radius >= sqrt((dx * dx) + (dy * dy)));
}

void Joystick::updateVelocity(Point point)
{
    // calculate Angle and length
    float dx = point.x - kCenter.x;
    float dy = point.y - kCenter.y;

    float distance = sqrt(dx * dx + dy * dy);
    float angle = atan2(dy, dx); // in radians

    if(distance > JOYSTICK_RADIUS)
    {
        dx = cos(angle) * JOYSTICK_RADIUS;
        dy = sin(angle) * JOYSTICK_RADIUS;
    }

    velocity = Point(dx / JOYSTICK_RADIUS, dy / JOYSTICK_RADIUS);

    if(distance > STICK_RADIUS)
    {
        point.x = kCenter.x + cos(angle) * STICK_RADIUS;
        point.y = kCenter.y + sin(angle) * STICK_RADIUS;
    }

    thumb->setPosition(point);
}

void Joystick::resetJoystick()
{
    this->updateVelocity(kCenter);
}

bool Joystick::handleLastTouch()
{
    bool wasPressed = isPressed;
    if(wasPressed){
        this->resetJoystick();
        isPressed = false;
    }
    return (wasPressed ? true : false);
}

void Joystick::onEnter()
{
    Layer::onEnter();

    // Register Touch Event
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = CC_CALLBACK_2(Joystick::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Joystick::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Joystick::onTouchCancelled, this);

    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Joystick::onExit()
{
    // You don't need to unregister listeners here as new API
    // removes all linked listeners automatically in Node's destructor
    // which is the base class for all cocos2d DRAWING classes

    Layer::onExit();
}

bool Joystick::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    Point point = touch->getLocation();
    point = convertCoordinate(point);

    if(isPointInCircle(point, kCenter, JOYSTICK_RADIUS)){
        isPressed = true;
        this->updateVelocity(point);
    }
    return true;
}

void Joystick::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
    if(isPressed){
        Point point = touch->getLocation();
        point = convertCoordinate(point);
        this->updateVelocity(point);
    }
}

void Joystick::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{
    this->handleLastTouch();
}

void Joystick::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    this->handleLastTouch();
}

bool Joystick::init()
{
    bool bRet = false;
    do
    {
        kCenter = Point(JOYSTICK_RADIUS + JOYSTICK_OFFSET_X,
                        JOYSTICK_RADIUS + JOYSTICK_OFFSET_Y);

        // Super init first.
        CC_BREAK_IF(!Layer::init());

        // Add your code below.
        velocity = Point(0, 0);

        Sprite *bg = Sprite::create("JoyBase.png");
        bg->setPosition(kCenter);
        this->addChild(bg, 0);

        thumb = Sprite::create("JoyStick.png");
        thumb->setPosition(kCenter);
        this->addChild(thumb, 1);

        bRet=true;

    } while(0);

    return bRet;
}