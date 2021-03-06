#pragma once

#include <unordered_map>
#include <json/json.h>
#include <fstream>
#include "color.h"
#include "model.h"
#include "texture.h"
#include "sprite.h"
#include "terrain_definition.h"

struct CommonResources {
private:
    static float *jsonToFloatArray(const Json::Value &jsonArray, unsigned int size);

    static unsigned int *jsonToUIntArray(const Json::Value &jsonArray, unsigned int size);

    std::unordered_map<std::string, const TerrainDefinition*> terrainDefinitions;
    std::unordered_map<std::string, const Model*> models;
    std::unordered_map<std::string, const SpriteSheet*> spriteSheets;
    std::unordered_map<std::string, const Sprite*> sprites;
    std::unordered_map<std::string, const Color*> colors;
public:
    CommonResources() = default;
    CommonResources(std::string ressources);
    ~CommonResources();
    void load(std::string);
    const Model* getModel(const std::string &key) const { return models.at(key); }
    const SpriteSheet* getSpriteSheet(const std::string &key) const { return spriteSheets.at(key); }
    const Sprite* getSprite(const std::string &key) const { return sprites.at(key); }
    const TerrainDefinition* getTerrain(const std::string &key) const { return terrainDefinitions.at(key); }
    const Color* getColor(const std::string &key) const { return colors.at(key); }
};