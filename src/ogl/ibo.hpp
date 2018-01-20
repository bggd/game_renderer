namespace grndr { namespace ogl {

struct IBO {

  GLuint id = 0;

  static GLuint current_id;

  static void bind_zero();
  static void draw_triangles(GLsizei count);
  static void draw_lines(GLsizei count);

  void create();
  void destroy();

  void bind();

  void buffer_data(size_t size, const void* vertices, GLenum usage);

};

}} // namespace grndr::ogl
