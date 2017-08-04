namespace grndr {

void VBO::bind_zero()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, this->id);
}


void VBO::vertex_attrib_pointer(GLuint location, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset)
{
  glVertexAttribPointer(location, size, type, normalized, stride, offset);
}

void VBO::buffer_data(size_t size, const void* vertices, GLenum usage)
{
  glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
}

void VBO::draw_arrays(GLenum mode, GLint first, GLsizei count)
{
  glDrawArrays(mode, first, count);
}

} // namespace grndr
