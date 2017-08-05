namespace grndr {

struct VBO {

  GLuint id;

  static void gen_buffers(GLsizei n, GLuint* buffers);
  static void delete_buffers(GLsizei n, const GLuint* buffers);
  static void bind_zero();

  void create();
  void destroy();

  void bind();

  void vertex_attrib_pointer(GLuint location, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset);
  void buffer_data(size_t size, const void* vertices, GLenum usage);
  void draw_arrays(GLenum mode, GLint first, GLsizei count);

};

} // namespace grndr
