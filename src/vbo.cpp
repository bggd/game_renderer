namespace grndr {

void VBO::gen_buffers(GLsizei n, GLuint* buffers)
{
  glGenBuffers(n, buffers);
}

void VBO::delete_buffers(GLsizei n, const GLuint* buffers)
{
  glDeleteBuffers(n, buffers);
}


void VBO::bind_zero()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::create()
{
  VBO::gen_buffers(1, &this->id);
}

void VBO::destroy()
{
  VBO::delete_buffers(1, &this->id);
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
