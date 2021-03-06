#pragma once

#include <algorithm>
#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_circle_shape.h>
#include <box2d/b2_chain_shape.h>
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "vec2f.h"

/**
 * @brief Model for rendering without collisions
 */
struct Model {
protected:
    float *localBuffer;
    const static float defaultTexCoords[8];
    const static unsigned int defaultIndices[6];
    unsigned short amountOfVertices;
    unsigned short amountOfIndices;
    const VertexArray va;
    const IndexBuffer ib;
    const VertexBuffer vb;
    Vec2f* vertices = nullptr;
    b2Shape* shape;
public:
    Model(float radius);
    Model(Vec2f size);
    Model(const float vertices[],
          const bool chain = false,
          const unsigned short amountOfVertices = 4,
          const unsigned int indices[6] = defaultIndices,
          const unsigned short amountOfIndices = 6);

    ~Model();
    static float *generateVerticesTex(Vec2f size);
    void bind() const;
    Vec2f* getVertices(){ return vertices; }
    int getAmountOfVertices() const { return amountOfVertices; }
    unsigned int getAmountOfIndices() const { return amountOfIndices; }
    const b2Shape *getCollisionShape() const { return shape; };
};