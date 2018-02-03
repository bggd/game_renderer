namespace grndr {

struct GLState {

  GLuint shader_id = 0;

  void bind_shader(const PipelineSpec* spec);
  void set_uniform_matrix4(const PipelineSpec* spec, const PipelineSpec::Shader::Uniform& u, const GLfloat* elements);
  void enable_input_layout(const PipelineSpec* spec);
  void bind_input_layout(const PipelineSpec* spec, ogl::VBO* slot, uint8_t slot_size);

};

} // namespace grndr
