#pragma once

#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <string>
#include <iostream>
#include "game_object.h"
#include "vec2f.h"
#include "sprite.h"
#include "model.h"
#include "context.h"
#include "chunk.h"

enum RenderType {
    COLOR, SPRITE, SHADER
};

struct UpdateContext;
struct RenderContext;
struct Chunk;
class GameObject {
private:
    const std::string name;
    b2World *world;
    RenderType renderType;
protected:
    float updateRadius;
    bool alive = true;
    bool visible = true;
    bool active = true;
    const Model *model;
    const SpriteSheet *sprite;
    const Color *color;
    Chunk* currentChunk;
    b2Body *body;
public:
    GameObject(const UpdateContext &ctx, const std::string name, const Model *model, const SpriteSheet *sprite,
               Vec2f pos, bool fixedRotation = false, bool collision = true, bool isStatic = false, float gravity = 1.0f,
               float density = 1.0f, float friction = 0.3f);

    GameObject(const UpdateContext &ctx, const std::string name, const Model *model, const Color *c, Vec2f pos,
               bool fixedRotation = false, bool collision = true, bool isStatic = false, float gravity = 1.0f,
               float density = 1.0f, float friction = 0.3f);

    GameObject(const UpdateContext &ctx, const std::string name, const Model *model, Vec2f pos,
               bool fixedRotation = false, bool collision = true, bool isStatic = false, float gravity = 1.0f,
               float density = 1.0f, float friction = 0.3f);

    ~GameObject();

    void createBody(const UpdateContext &ctx, Vec2f pos, bool fixedRotation, bool collision, bool isStatic, float gravity,
               float density, float friction);

    virtual void update(const UpdateContext &ctx) {}
    virtual void render(const RenderContext &ctx);
    virtual void onCollision(const GameObject *go = nullptr) {}
    virtual void onRelease(const GameObject *go = nullptr) {}

    Chunk* getCurrentChunk(){ return currentChunk; }
    void setCurrentChunk(Chunk* newChunk){ this->currentChunk = newChunk; }

    void applyForce(const b2Vec2 &force) { body->ApplyLinearImpulseToCenter(force); }
    void applyForce(const b2Vec2 &force, const b2Vec2 &point) { body->ApplyLinearImpulse(force, point, true); }

    bool isVisible() const { return visible; }
    void setVisible(bool visible) { this->visible = visible; }

    bool isActive() const { return active; }
    void setActive(bool active) { this->active = active; }

    bool isAlive() const { return alive; }
    void kill() { alive = false; }

    Vec2f getPos() const { return Vec2f(body->GetPosition()); }
    void setPos(Vec2f pos) { body->SetTransform({pos.x, pos.y}, body->GetAngle()); }
    float getRotation() { return body->GetAngle(); }
    void setRotation(float rotation) { body->SetTransform(body->GetPosition(), rotation); }

    float getUpdateRadius() const { return updateRadius; }
    void setUpdateRadius(float updateRadius) { this->updateRadius = updateRadius; }

    std::string getName() const { return name; }
    void setCollision(bool collision) {
        for (b2Fixture *f = body->GetFixtureList(); f; f = f->GetNext()) {
            f->SetSensor(collision);
        }
    }

    const b2Body *getBody() const { return body; }
    const b2Shape *getShape() const { return model->getCollisionShape(); }
};