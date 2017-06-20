namespace grndr {

struct VBO {

  GLuint id;

  void bind();

  void vertex_attrib_pointer(GLuint location, GLuint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset);
  void buffer_data(size_t size, const void* vertices, GLenum usage);
  void draw_arrays(GLenum mode, GLint first, GLsizei count);

};

} // namespace grndr
