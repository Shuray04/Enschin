#pragma once

#include "light.h"
#include "color.h"
#include "shader_program.h"
#include "model.h"
#include "texture.h"
#include "vec2f.h"
#include "matrix.h"
#include "mouse.h"

/**
 * @brief Renderer for rendering out to the Screen. Holds projection
 * Matrices, Shaderprograms and functions to transform and render.
 */
class Renderer {
private:
    float fov, ratio;
    float proj[16] = {0};
    float view[16] = {0};
    float mvp[16] = {0};

    static ShaderProgram colorProgram;
    static ShaderProgram textureProgram;
    static ShaderProgram coloredTextureProgram;
    static ShaderProgram rainbowProgram;
    static ShaderProgram cropProgram;
    static ShaderProgram circleColorProgram;
    static ShaderProgram circleTextureProgram;

public:
    Renderer() = default;
    Renderer(float fov, float ratio);

    static void free();
    static void initShaderPrograms();

    void resetProjection(float fov, float ratio);
    void resetMatrix();
    void translate(Vec2f pos);
    void rotate(float angle);
    void scale(Vec2f scaling);

    float getRatio() { return ratio; }
    float getFov() { return fov; }

    void translateAndRenderTexture(const Model *model, const Texture *tex, Vec2f pos, float rotation = .0f);
    void renderColor(const Model *model, const Color *) const;
    void renderTexture(const Model *model, const Texture *texture) const;
    void renderColoredTexture(const Model *model, const Texture *texture, const Color *color) const;
    void renderRainbow(const Model *model, float totalTime) const;
    void renderCroppedTexture(const Model* model, const Texture* tex, Vec2f topLeft, Vec2f bottomRight) const;
    void renderCircleColor(const Model *model, const Color *color);
    void renderCircleTexture(const Model *model, const Texture *texture);
};

