#pragma once
#include <unordered_map>
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/model.h"
#include "enschin/graphics/texture.h"

#define MODEL 0
#define TEXTURE 1
#define COLOR 2

struct Ressources {
public:
    std::unordered_map<short, Model> models;
    std::unordered_map<short, Texture> textures;
    std::unordered_map<short, Color> colors;
};