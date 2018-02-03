namespace grndr {

struct Renderer {

  PipelineSpec* current_spec = nullptr;
  std::vector<ogl::VBO> vbo_list;
  ogl::IBO ibo;

  void set_vbo(uint8_t idx, ogl::VBO vbo);
  void set_ibo(ogl::IBO ibo);
  void bind_pipeline(PipelineSpec* spec);
  void bind_vertex_attributes(const PipelineSpec* spec, bool use_ibo=false);
  void set_uniform_matrix4(const PipelineSpec::Shader::Uniform& u, const GLfloat* elements);

  void draw_lines(uint16_t count);
  void draw_triangles(uint16_t first, uint16_t count, bool use_ibo=false);

};

} // namespace grndr
