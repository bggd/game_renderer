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

void Renderer::set_vbo(VBO vbo)
{
  this->vbo = vbo;
}

void Renderer::draw_triangles(uint16_t first, uint16_t count)
{
  this->vbo.bind();
  for (uint32_t i=0; i < this->spec.attributes.size(); ++i) {
    const PipelineSpec::VertexAttribute& attr = this->spec.attributes[i];
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
    this->vbo.vertex_attrib_pointer(i, size, type, attr.normalized, attr.stride, (const GLvoid*)attr.offset);
  }
  VBO::draw_triangles(first, count);
}

} // namespace grndr
