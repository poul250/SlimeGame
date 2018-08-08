#pragma once
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Assets.hpp"
#include "Entity.hpp"

using namespace sf;

class Camera : public View {
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
    void setOffset(Vector2f off);
    void floatCamera();

    void setTarget(RenderTarget * target);
    void setScale(int scale);

    //Getters
    Vector2f getCoords() const;
    float getWidth() const;
    float getHeight() const;
private:
    typedef void(Camera::*ShiftFunc)();
    typedef void(Camera::*ActionFunc)();
    typedef Vector2f(Camera::*CenterFunc)();

    ActionFunc actionFunc;
    CenterFunc centerFunc;
    ShiftFunc shiftFunc;

	//Shift funcs
    void None();
    void CleverFollowEntity();

    //Action funcs
    void ExpMoveToEntity();
    void Centering();

    //Center funcs
    Vector2f CenterOnEntity();
    Vector2f FloatingCamera();
    Vector2f MapCenter();
    
    //Entity for centering
    Entity * entity;

    //Target, where change view
    RenderTarget * target;

    //Target scale
    int scale;

    //Center position
    Vector2f xy;

    // Size
    float width, height;

    //Shift from center
    Vector2f shift = Vector2f(0.f, 0.f);

    //Const Offset of cam
    Vector2f off = Vector2f(0.f, 0.f);

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
