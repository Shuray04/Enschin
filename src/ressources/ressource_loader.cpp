#include "ressource_loader.h"

namespace RessourceLoader {
    void loadGameRessources(Ressources& res) {
        res.models = {
                {TEST+MODEL, Model({0.5f, 0.5f})}
        };
        res.textures = {
                {TEST+TEXTURE, Texture("./textures/bird.jpg")},
                };
        res.colors = {
                {TEST+COLOR, Color(0, 1, 0, 1)},
                };
    }
}