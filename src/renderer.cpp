namespace grndr {

void Renderer::set_pipeline(const PipelineSpec& spec)
{
  this->spec = spec;
}

void Renderer::set_uniform_matrix4(const char* name, const GLfloat* elements)
{
}

void Renderer::draw_triangles(GLint first, GLsizei count)
{
}

} // namespace grndr
