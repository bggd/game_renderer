namespace grndr {

void Renderer::set_pipeline(const PipelineSpec& spec)
{
  this->spec = spec;
}

void Renderer::set_uniform_matrix4(const char* name, const GLfloat* elements)
{
}

void Renderer::set_vbo(VBO vbo)
{
  this->vbo = vbo;
}

void Renderer::draw_triangles(uint16_t first, uint16_t count)
{
}

} // namespace grndr
