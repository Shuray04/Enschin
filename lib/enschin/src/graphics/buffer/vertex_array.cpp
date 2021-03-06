#include <enschin/vertex_array.h>

VertexArray::VertexArray(unsigned int amount) {
    glGenVertexArrays(amount, &vertexArrayId);
}

VertexArray::~VertexArray(){
    glDeleteVertexArrays(1, &vertexArrayId);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const {
    bind();
    vb.bind();
    const std::vector<VertexBufferElement> elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size() ; i++) {
        const VertexBufferElement element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), INT2VOIDP(offset));
        offset += element.count * sizeof(element.type);
    }
}

void VertexArray::bind() const {
    glBindVertexArray(vertexArrayId);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}