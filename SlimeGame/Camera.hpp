#pragma once
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Assets.hpp"
#include "Entity.hpp"
using namespace sf;

class Camera : public View{
public:
    Camera(FloatRect rect, RenderTarget * target = nullptr, int scale = 1);
    Camera(RenderTarget * target = nullptr, int scale = 1);

    virtual ~Camera();
    void update();
    void followEntity(Entity * entity);
    void stopMove();
    void defaultView();
    void moveTo(Entity * entity);
    void setOffset(float x, float y);
    void floatCamera();

    void setTarget(RenderTarget * target);
    void setScale(int scale);

    //Getters
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
private:
    typedef void(Camera::*ShiftFunc)();
    typedef void(Camera::*CenterFunc)();
    typedef void(Camera::*CleverFollowFunc)();

    CenterFunc centerFunc;
    ShiftFunc shiftFunc;
    void None();

	//Shift funcs
    void FollowEntity();
    void CleverFollowEntity();

    //Center funcs
    void ExpMoveToEntity();
    void CenterOnEntity();
    void FloatingCamera();

    //Clever follow funcs, that halps to the CleverFollowEntity funcs

    //Entity for centering
    Entity * entity;

    //Target, where change view
    RenderTarget * target;

    //Target scale
    int scale;

    //Center position
    float x, y;

    // Size
    float width, height;

    //Shift from center
    float shiftX = 0;
    float shiftY = 0;

    //Const Offset of cam
    float offX = 0;
    float offY = 0;

    //Variables for some functions

    //ExpMoveToEntity
    int count;
    const int updsForMove = 60;
    float upds = 0;

    //CleverFollowEntity
    int moveDir = 0;
    const float maxShift = 20;
    const float shiftCoef = 0.85f;

    //FloatingCamera
    const int MAX_DIST = 10;
    const float MAX_SPEED = 0.05;
    Vector2f accel = Vector2f(0.f, 0.f);

    Vector2f pointSpeed = Vector2f(0.f, 0.f);
    Vector2f hiddenPoint = Vector2f(0.f, 0.f);
    Vector2f currPoint = Vector2f(0.f, 0.f);
};
