namespace grndr {

struct Renderer {

  PipelineSpec spec;
  std::vector<VBO> vbo_list;

  void set_pipeline(const PipelineSpec& spec);
  void set_uniform_matrix4(const PipelineSpec::Shader::Uniform& u, const GLfloat* elements);
  void set_vbo(VBO vbo);

  void draw_triangles(uint16_t first, uint16_t count);

};

} // namespace grndr
