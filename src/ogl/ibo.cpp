namespace grndr { namespace ogl {

GLuint IBO::current_id = 0;

void IBO::bind_zero()
{
  IBO::current_id = 0;
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IBO::draw_triangles(GLsizei count)
{
  glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, NULL);
}

void IBO::create()
{
  assert(this->id == 0);
  VBO::gen_buffers(1, &this->id);
}

void IBO::destroy()
{
  assert(this->id != 0);
  VBO::delete_buffers(1, &this->id);
  this->id = 0;
}

void IBO::bind()
{
  assert(this->id != 0);
  IBO::current_id = this->id;
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void IBO::buffer_data(size_t size, const void* vertices, GLenum usage)
{
  assert(IBO::current_id == this->id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, vertices, usage);
}

}} // namespace grndr::ogl
