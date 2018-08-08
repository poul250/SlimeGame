#include "Camera.hpp"

Camera::Camera(FloatRect rect, RenderTarget * target, int scale)
    : View(FloatRect(rect.left * scale, rect.top * scale, rect.width * scale, rect.height * scale))
    , target(target)
    , scale(scale)
    , shiftFunc(&Camera::None)
    , centerFunc(&Camera::MapCenter)
    , xy(rect.width / 2, rect.height / 2)
    , width(rect.width)
    , height(rect.height)
{ }

Camera::Camera(RenderTarget * target, int scale)
    : target(target)
    , scale(scale)
    , shiftFunc(&Camera::None)
{ }

Camera::~Camera()
{ }

void Camera::update()
{
    (this->*actionFunc)();
    (this->*shiftFunc)();
    setCenter((xy + shift + off) * float(scale));
    target->setView(*this);
}

void Camera::setTarget(RenderTarget * target)
{
    this->target = target;
}

void Camera::setScale(int scale)
{
    this->scale = scale;
}

Vector2f Camera::getCoords() const
{
    return xy + shift + off;
}

float Camera::getWidth() const
{
    return width;
}

float Camera::getHeight() const
{
    return height;
}

void Camera::followEntity(Entity * entity)
{
    this->entity = entity;
    shiftFunc  = &Camera::CleverFollowEntity;
    centerFunc = &Camera::CenterOnEntity;
    actionFunc = &Camera::Centering;
}

void Camera::stopMove()
{
    shiftFunc = &Camera::None;
    actionFunc = &Camera::None;
}

void Camera::defaultView()
{
    stopMove();
    reset(FloatRect(0, 0, Assets::getWidth() * Assets::getScale(), Assets::getHeight() * Assets::getScale()));
}

void Camera::moveTo(Entity * entity)
{
    upds = updsForMove;
    this->entity = entity;
    actionFunc = &Camera::ExpMoveToEntity;
}

void Camera::setOffset(float x, float y)
{
    off.x = x;
    off.y = y;
}

void Camera::setOffset(Vector2f off)
{
    this->off = off;
}

void Camera::floatCamera()
{
    centerFunc = &Camera::FloatingCamera;
}

void Camera::CleverFollowEntity()
{
    moveDir = -Keyboard::isKeyPressed(Keyboard::A) + Keyboard::isKeyPressed(Keyboard::D);
    float shX = moveDir * maxShift;

    shift.x = shX - (shX - shift.x) * shiftCoef;
}

void Camera::None()
{ }

void Camera::ExpMoveToEntity()
{
    Vector2f center = (this->*centerFunc)();
    float newX = center.x;
    float newY = center.y;
    xy = Vector2f(newX - (newX - xy.x) * (exp(upds / 30) - 1) / exp(updsForMove / 30),
                  newY - (newY - xy.y) * (exp(upds / 30) - 1) / exp(updsForMove / 30));
    if (--upds == 0) {
        actionFunc = &Camera::Centering;
    }
}

void Camera::Centering()
{
    xy = (this->*centerFunc)();
}

Vector2f Camera::CenterOnEntity()
{
    auto rect = entity->getGlobalBounds();
    return Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2);
}

Vector2f Camera::FloatingCamera()
{
    FloatRect rect = entity->getGlobalBounds();
    Vector2f center(rect.left + rect.width / 2, rect.top + rect.height / 2);
    Vector2f rad = hiddenPoint - currPoint;
    while (hypot(rad.x, rad.y) < 1) {
        hiddenPoint = Vector2f(-MAX_DIST + rand() % (2 * MAX_DIST), -MAX_DIST + rand() % (2 * MAX_DIST));
        rad = hiddenPoint - currPoint;
    }
    float hyp = hypot(rad.x, rad.y);
    accel = Vector2f(rad.x / hyp, rad.y / hyp) / 1000.f;
    pointSpeed += accel;
    currPoint += pointSpeed;
    return center + currPoint;
}

Vector2f Camera::MapCenter()
{
    return Vector2f(width / 2, height / 2);
}
