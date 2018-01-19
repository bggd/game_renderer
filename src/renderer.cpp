namespace grndr {

void Renderer::set_uniform_matrix4(const PipelineSpec::Shader::Uniform& u, const GLfloat* elements)
{
  this->current_spec->shader.glsl.uniform_mat4(u.location, 1, elements);
}

void Renderer::set_vbo(uint8_t idx, ogl::VBO vbo)
{
  size_t size = idx+1;
  if (size > this->vbo_list.capacity()) { this->vbo_list.resize(size); }
  this->vbo_list[idx] = vbo;
}

void Renderer::set_ibo(ogl::IBO ibo)
{
  this->ibo = ibo;
}

void Renderer::draw_triangles(uint16_t first, uint16_t count, bool use_ibo)
{
  if (use_ibo) { ogl::IBO::draw_triangles(count); }
  else { ogl::VBO::draw_triangles(first, count); }
}

void Renderer::bind_pipeline(PipelineSpec* spec)
{
  this->current_spec = spec;
  spec->shader.glsl.use();
  for (uint32_t i=0; i < spec->attributes.size(); ++i) {
    glEnableVertexAttribArray(i);
  }
}

void Renderer::bind_vertex_attributes(const PipelineSpec* spec, bool use_ibo)
{
  assert(this->current_spec == spec);
  int32_t prev = -1;
  for (const PipelineSpec::VertexAttribute& attr : spec->attributes) {
    GLint size;
    GLenum type;
    switch (attr.format) {
      case PipelineSpec::VertexAttribute::Format::FLOAT2:
        size = 2;
        type = GL_FLOAT;
        break;
      case PipelineSpec::VertexAttribute::Format::FLOAT3:
        size = 3;
        type = GL_FLOAT;
        break;
      default: abort();
    }
    if (attr.vbo_list_idx != prev) {
      assert(this->vbo_list.size() > attr.vbo_list_idx);
      this->vbo_list[attr.vbo_list_idx].bind();
    }
    this->vbo_list[attr.vbo_list_idx].vertex_attrib_pointer(attr.index, size, type, attr.normalized, attr.stride, (const GLvoid*)attr.offset);
    prev = attr.vbo_list_idx;
  }
  
  if (use_ibo) { this->ibo.bind(); }
}

} // namespace grndr
