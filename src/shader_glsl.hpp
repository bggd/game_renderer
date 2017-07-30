namespace grndr {

struct ShaderGLSL {

  GLuint vert;
  GLuint frag;
  GLuint prog;

  void create_program();
  void delete_program();

  bool compile_vert(const char* src);
  bool compile_frag(const char* src);

  void bind_attr(GLuint location, const char* name);
  void bind_frag_data_location(GLuint color_number, const char* name);

  bool link();

  void use();

  GLint get_uniform_location(const char* name);
  void uniform_mat4(GLint location, GLsizei count, const GLfloat* v);

};

} // namespace gshdr
