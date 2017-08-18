namespace grndr {

struct VBO {

  GLuint id = 0;

  static GLuint current_id;

  static void gen_buffers(GLsizei n, GLuint* buffers);
  static void delete_buffers(GLsizei n, const GLuint* buffers);
  static void bind_zero();
  static void draw_triangles(GLint first, GLsizei count);

  void create();
  void destroy();

  void bind();

  void vertex_attrib_pointer(GLuint location, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset);
  void buffer_data(size_t size, const void* vertices, GLenum usage);

};

} // namespace grndr
