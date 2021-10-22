#pragma once
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include <enschin/graphics/Color.hpp>
#include "../math/Vec2.h"
#include "../math/Dim.h"
#include "../math/Physics.h"
#include "../math/Ray.hpp"
#include "../input/Mouse.h"
#include "../objects/GameObject.h"
#include "ShaderProgram.h"
#include "Model.h"
#include "Light.hpp"
#include "Texture.h"

class Renderer
{
private:
	static glm::mat4* proj;
	static glm::mat4* view;
	static glm::mat4* mvp;

	static ShaderProgram* colorProgram;
	static ShaderProgram* textureProgram;
	static ShaderProgram* coloredTextureProgram;

	static void apply();
	static void initShaderPrograms();
	static float ratio;
	static float units;
public:
	static void init(Dim windowSize, float units=100);
	static void resetProjection(Dim windowDim);
	static void absoluteTranslate(Vec2 pos);
	static void translate(Vec2 pos);
	static void rotate(float angle);
	static void scale(Vec2 scaling);
	/*void applyMatrixChange();
	void resetMatrix();*/
	static void renderColor(Model& model, Color& color);
	static void renderTexture(Model& model, Texture& texture);
	static void renderColoredTexture(Model& model, Texture& texture, Color& color);
	static void renderRaytracing(Model& model, float vertices[], int amountOfVertices, Light& light, std::vector<GameObject> objects);

	static float getRatio(){ return ratio; }
	static float getUnits(){ return units; }
};
