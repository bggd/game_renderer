namespace grndr { namespace ogl {

struct ShaderGLSL {

  GLuint vert;
  GLuint frag;
  GLuint prog;

  static void use_zero();

  void create_program();
  void delete_program();

  bool compile_vert(const char* src);
  bool compile_frag(const char* src);

  void bind_attr(GLuint location, const char* name);
  void bind_frag_data_location(GLuint color_number, const char* name);

  bool link();

  void use() const;

  GLint get_uniform_location(const char* name) const;
  void uniform_mat4(GLint location, GLsizei count, const GLfloat* v) const;

};

}} // namespace gshdr::ogl
