namespace grndr {

void GLState::bind_shader(const PipelineSpec* spec)
{
  spec->shader.glsl.use();
}

void GLState::set_uniform_matrix4(const PipelineSpec* spec, const PipelineSpec::Shader::Uniform& u, const GLfloat* elements)
{
  spec->shader.glsl.uniform_mat4(u.location, 1, elements);
}

void GLState::enable_input_layout(const PipelineSpec* spec)
{
  for (uint8_t i=0; i < spec->attributes.size(); ++i) {
    glEnableVertexAttribArray(i);
  }
}

void GLState::bind_input_layout(const PipelineSpec* spec, ogl::VBO* slot, uint8_t slot_size)
{
  int16_t prev_vbo_slot = -1;
  for (const PipelineSpec::VertexAttribute& attr : spec->attributes) {
    GLint size;
    GLenum type = GL_FLOAT;
    switch (attr.format) {
      case PipelineSpec::VertexAttribute::Format::FLOAT2:
        size = 2;
        break;
      case PipelineSpec::VertexAttribute::Format::FLOAT3:
        size = 3;
        break;
      default: abort();
    }
    if (attr.vbo_slot != prev_vbo_slot) {
      assert(attr.vbo_slot < slot_size);
      slot[attr.vbo_slot].bind();
    }
    slot[attr.vbo_slot].vertex_attrib_pointer(attr.index, size, type, attr.normalized, attr.stride, (const GLvoid*)attr.offset);
    prev_vbo_slot = attr.vbo_slot;
  }
}

} // name grndr

