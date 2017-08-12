namespace grndr {

struct Renderer {

  PipelineSpec spec;

  void set_pipeline(const PipelineSpec& spec);
  void set_uniform_matrix4(const char* name, const GLfloat* elements);

  void draw_triangles(GLint first, GLsizei count);

};

} // namespace grndr
