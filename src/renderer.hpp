namespace grndr {

struct Renderer {

  PipelineSpec spec;
  std::vector<ogl::VBO> vbo_list;
  ogl::IBO ibo;

  void set_pipeline(const PipelineSpec& spec);
  void set_uniform_matrix4(const PipelineSpec::Shader::Uniform& u, const GLfloat* elements);
  void set_vbo(uint8_t idx, ogl::VBO vbo);
  void set_ibo(ogl::IBO ibo);

  void draw_triangles(uint16_t first, uint16_t count, bool use_ibo=false);

};

} // namespace grndr
