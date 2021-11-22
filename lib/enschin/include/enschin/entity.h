#pragma once
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <string>
#include <iostream>
#include "game.h"
#include "vec2.h"
#include "sprite.h"
#include "model.h"

class Scene;
class Game;
class Entity {
protected:
    Vec2 pos;
    float rotation = 0;
    float scale = 1;
    Model& model;
    SpriteSheet& sprite;
    b2Body* body;
private:
    static unsigned int idCounter;
    unsigned int id;
	float health = 100;
	float maxHealth = 100;
    float friction;
    float density;
    float updateRadius = 10.0f;
//    bool visible, updatable, disabled;
    bool onGround = 1;
    bool fixedRotation;
public:
	Entity(Scene& scene, Model& model, SpriteSheet& sprite, Vec2 pos={0, 0}, float density=1.0f, float friction=0.3f, bool fixedRotation=false);
	~Entity();
	virtual void update(Game& game, Scene& scene) = 0;
	virtual void render(Game&, Renderer& r) = 0;
    virtual void onEntityCollision(Entity& otherEntity) = 0;
    virtual void onCollision() = 0;
//	virtual void onDamage(float damage) = 0;
//	virtual void onDeath() = 0;
//	virtual void onAttack() = 0;

    b2Body& getBody(){ return *body; }

    void setPos(Vec2 newPos){ pos = newPos; }
    Vec2 getPos() { return pos; }
	Vec2* getPosAddress() { return &pos; }
    float getRotation(){ return rotation; }
    void setRotation(float rotation){ this->rotation = rotation; }
    void increaseRotation(float rotation){ this->rotation += rotation; }
    void increasePos(Vec2 increment) { pos += increment; }
    float getUpdateRadius(){ return updateRadius; }

};