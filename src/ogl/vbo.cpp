namespace grndr { namespace ogl {

GLuint VBO::current_id = 0;

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
  VBO::current_id = 0;
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::draw_triangles(GLint first, GLsizei count)
{
  glDrawArrays(GL_TRIANGLES, first, count);
}

void VBO::draw_lines(GLint first, GLsizei count)
{
  glDrawArrays(GL_LINES, first, count);
}

void VBO::create()
{
  assert(this->id == 0);
  VBO::gen_buffers(1, &this->id);
}

void VBO::destroy()
{
  assert(this->id != 0);
  VBO::delete_buffers(1, &this->id);
  this->id = 0;
}

void VBO::bind()
{
  assert(this->id != 0);
  VBO::current_id = this->id;
  glBindBuffer(GL_ARRAY_BUFFER, this->id);
}


void VBO::vertex_attrib_pointer(GLuint location, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset)
{
  assert(VBO::current_id == this->id);
  glVertexAttribPointer(location, size, type, normalized, stride, offset);
}

void VBO::buffer_data(size_t size, const void* vertices, GLenum usage)
{
  assert(VBO::current_id == this->id);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, usage);
}

void VBO::buffer_sub_data(size_t offset, size_t size, const void* vertices)
{
  assert(VBO::current_id == this->id);
  glBufferSubData(GL_ARRAY_BUFFER, offset, size, vertices);
}

}} // namespace grndr::ogl
