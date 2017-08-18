namespace grndr {

void Renderer::set_pipeline(const PipelineSpec& spec)
{
  for (uint32_t i=0; i < this->spec.attributes.size(); ++i) {
    glDisableVertexAttribArray(i);
  }
  this->spec = spec;
  if (this->spec.compiled == false) {
    assert(this->spec.compile_shader());
  }
  for (uint32_t i=0; i < this->spec.attributes.size(); ++i) {
    glEnableVertexAttribArray(i);
  }
}

void Renderer::set_uniform_matrix4(const PipelineSpec::Shader::Uniform& u, const GLfloat* elements)
{
  this->spec.shader.glsl.uniform_mat4(u.location, 1, elements);
}

void Renderer::set_vbo(uint8_t idx, ogl::VBO vbo)
{
  size_t size = idx+1;
  if (size > this->vbo_list.capacity()) { this->vbo_list.reserve(size); }
  this->vbo_list[idx] = vbo;
}

void Renderer::draw_triangles(uint16_t first, uint16_t count)
{
  uint32_t prev = -1;
  for (const PipelineSpec::VertexAttribute& attr : this->spec.attributes) {
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
  ogl::VBO::draw_triangles(first, count);
}

} // namespace grndr
