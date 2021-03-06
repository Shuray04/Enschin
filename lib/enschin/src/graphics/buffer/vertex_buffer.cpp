#include <enschin/vertex_buffer.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &vertexBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &vertexBufferId);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}