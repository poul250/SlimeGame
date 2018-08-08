#include <iostream>
#include "EnvManager.hpp"

EnvManager::EnvManager()
    : gz(0.f, 0.f, 1646.f, 300.f)
{
    objects = { FloatRect(gz.left - 100,       gz.top - 100.f,      gz.width + 200.f,  100.f),
                FloatRect(gz.left - 100.f,     gz.top + gz.height,  gz.width + 200.f,  100.f),
                FloatRect(gz.left - 100.f,     gz.top - 100.f,      100.f,             gz.height + 200.f),
                FloatRect(gz.left + gz.width,  -100.f,              100.f,             gz.height + 200.f),
    };
    objects.push_back(FloatRect(300.f, 270.f, 100.f, 250.f));
}

EnvManager::~EnvManager()
{ }

void EnvManager::interactWithEnv(std::shared_ptr<Entity> entity) const
{
    if (!entity->interactsWithEnv())
        return;

    for (auto obj : objects) {
        FloatRect rect = entity->getGlobalBounds();
        FloatRect prev = entity->getPrevGlobalBounds();
        if (!rect.intersects(obj)) {
            continue;
        }

        Vector2f prevRectLU(prev.left             , prev.top              );
        Vector2f prevRectRU(prev.left + prev.width, prev.top              );
        Vector2f prevRectLD(prev.left             , prev.top + prev.height);
        Vector2f prevRectRD(prev.left + prev.width, prev.top + prev.height);

        Vector2f rectLU(rect.left             , rect.top              );
        Vector2f rectRU(rect.left + rect.width, rect.top              );
        Vector2f rectLD(rect.left             , rect.top + rect.height);
        Vector2f rectRD(rect.left + rect.width, rect.top + rect.height);
        
        Vector2f objLU(obj.left            , obj.top             );
        Vector2f objRU(obj.left + obj.width, obj.top             );
        Vector2f objLD(obj.left            , obj.top + obj.height);
        Vector2f objRD(obj.left + obj.width, obj.top + obj.height);

        bool rd = obj.contains(rectRD);
        bool ld = obj.contains(rectLD);
        bool ru = obj.contains(rectRU);
        bool lu = obj.contains(rectLU);
        
        if (rd && ld) {
            entity->setPosition(rect.left, obj.top - rect.height - SHIFT);
        } else if (ru && rd) {
            entity->setPosition(obj.left - rect.width - SHIFT, rect.top);
        } else if (lu && ld) {
            entity->setPosition(obj.left + obj.width + SHIFT, rect.top);
        } else if (lu && ru) {
            entity->setPosition(rect.left, obj.top + obj.height + SHIFT);
        } else if (rd) {
            Vector2f drect = rectRD - prevRectRD;
            Vector2f dobj = objLU - prevRectRD;
            if (drect.x * dobj.y - drect.y * dobj.x >= 0) {
                entity->setPosition(rect.left, obj.top - rect.height - SHIFT);
            } else {
                entity->setPosition(obj.left - rect.width - SHIFT, rect.top);
            }
        } else if (ld) {
            Vector2f drect = rectLD - prevRectLD;
            Vector2f dobj = objRU - prevRectLD;
            if (drect.x * dobj.y - drect.y * dobj.x >= 0) {
                entity->setPosition(obj.left + obj.width + SHIFT, rect.top);
            } else {
                entity->setPosition(rect.left, obj.top - rect.height - SHIFT);
            }
        } else if (lu) {
            Vector2f drect = rectLU - prevRectLU;
            Vector2f dobj = objRD - prevRectLU;
            if (drect.x * dobj.y - drect.y * dobj.x >= 0) {
                entity->setPosition(obj.left + obj.width + SHIFT, rect.top);
            } else {
                entity->setPosition(rect.left, obj.top + obj.height + SHIFT);
            }
        } else if (ru) {
            Vector2f drect = rectRU - prevRectRU;
            Vector2f dobj = objLD - prevRectRU;
            if (drect.x * dobj.y - drect.y * dobj.x >= 0) {
                entity->setPosition(rect.left, obj.top + obj.height + SHIFT);
            } else {
                entity->setPosition(obj.left - rect.width - SHIFT, rect.top);
            }
        }
    }

    FloatRect rect = entity->getGlobalBounds();
    FloatRect check(rect.left, rect.top + rect.height, rect.width, 1.1 * SHIFT);
    bool standing = false;
    for (auto obj : objects) {
        if (check.intersects(obj)) {
            standing = true;
            break;
        }
    }
    if (standing) {
        entity->stand();
    } else {
        entity->fall();
    }
}