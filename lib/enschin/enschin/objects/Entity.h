#pragma once
#include <string>
#include "../math/Dim2.h"
#include "../math/Vec2.h"
#include <iostream>

class Entity {
private:
	std::string tag;
	float health;
	float maxHealth;
public:
	Vec2 pos;
	Vec2 dir;
	Dim2 dim;
	Entity(std::string tag, Vec2 pos = {}, Dim2 dim = {}, Vec2 dir = {})
		: tag(tag), pos(pos), dim(dim), dir(dir) {};
	~Entity();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onEntityCollision() = 0;
	virtual void onDamage(float damage) = 0;
	virtual void onDeath() = 0;
	virtual void onAttack() = 0;
};