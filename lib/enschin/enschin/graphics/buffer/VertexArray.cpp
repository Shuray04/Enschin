#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &vertexArrayId);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &vertexArrayId);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
{
    bind();
    vb.Bind();
    const std::vector<VertexBufferElement> elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size() ; i++)
    {
        const VertexBufferElement element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), INT2VOIDP(offset));
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(vertexArrayId);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
};