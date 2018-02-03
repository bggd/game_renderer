namespace grndr { namespace ogl {

struct VBO {

  GLuint id = 0;

  static GLuint current_id;

  static void gen_buffers(GLsizei n, GLuint* buffers);
  static void delete_buffers(GLsizei n, const GLuint* buffers);
  static void bind_zero();
  static void draw_triangles(GLint first, GLsizei count);
  static void draw_lines(GLint first, GLsizei count);

  void create();
  void destroy();

  void bind();

  void vertex_attrib_pointer(GLuint location, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset);
  void buffer_data(size_t size, const void* vertices, GLenum usage);
  void buffer_sub_data(size_t offset, size_t size, const void* vertices);

};

}} // namespace grndr::ogl
