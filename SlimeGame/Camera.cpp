#include "Camera.hpp"

Camera::Camera(FloatRect rect, RenderTarget * target, int scale)
    : View(FloatRect(rect.left * scale, rect.top * scale, rect.width * scale, rect.height * scale))
    , target(target)
    , scale(scale)
    , shiftFunc(&Camera::None)
    , centerFunc(&Camera::None)
    , x(rect.width / 2)
    , y(rect.height / 2)
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
    (this->*centerFunc)();
    (this->*shiftFunc)();
    setCenter((x + shiftX + offX) * scale, (y + shiftY + offY) * scale);
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

float Camera::getX() const
{
    return x + shiftX + offX;
}

float Camera::getY() const
{
    return y + shiftY + offY;
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
    shiftFunc = &Camera::CleverFollowEntity;
    centerFunc = &Camera::CenterOnEntity;
}

void Camera::stopMove()
{
    shiftFunc = &Camera::None;
    centerFunc = &Camera::None;
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
    centerFunc = &Camera::ExpMoveToEntity;
}

void Camera::setOffset(float x, float y)
{
    offX = x;
    offY = y;
}

void Camera::FollowEntity()
{
    int left = Keyboard::isKeyPressed(Keyboard::A);
    int right = Keyboard::isKeyPressed(Keyboard::D);
    int addX = 2 * (-left + right) + abs((left + right - 1)) * (-(count > 0) + (count < 0));
    count = std::max(-10, std::min(count + addX, 10));
    shiftX = 20 * ((count >= 0) - (count < 0)) * (1 - exp(-pow(count, 2) / 30));
    shiftY = 0;
}

void Camera::CleverFollowEntity()
{
    moveDir = -Keyboard::isKeyPressed(Keyboard::A) + Keyboard::isKeyPressed(Keyboard::D);
    float shX = moveDir * maxShift;
    shiftX = shX - (shX - shiftX) * shiftCoef;
}

void Camera::None()
{ }

void Camera::ExpMoveToEntity()
{
    FloatRect rect = entity->getGlobalBounds();
    float newX = rect.left + rect.width / 2;
    float newY = rect.top + rect.height / 2;
    x = newX - (newX - x) * (exp(upds / 30) - 1) / exp(updsForMove / 30);
    y = newY - (newY - y) * (exp(upds / 30) - 1) / exp(updsForMove / 30);
    if (--upds == 0) {
        centerFunc = &Camera::CenterOnEntity;
    }
}

void Camera::CenterOnEntity()
{
    auto rect = entity->getGlobalBounds();
    x = rect.left + rect.width / 2;
    y = rect.top + rect.height / 2;
}

void Camera::FloatingCamera()
{
    auto rect = entity->getGlobalBounds();
    x = rect.left + rect.width / 2;
    y = rect.top + rect.height / 2;
}
