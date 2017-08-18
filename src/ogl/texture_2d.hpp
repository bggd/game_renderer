namespace grndr { namespace ogl {

struct Texture2D {

  GLuint id = 0;

  GLint internal_format_rgb8;
  GLint internal_format_rgba8;

  static GLuint current_id;

  static void gen_textures(GLsizei n, GLuint* textures);
  static void delete_textures(GLsizei n, const GLuint* textures);
  static void bind_zero();

  void create();
  void destroy();

  void bind();

  void tex_parameteri(GLenum pname, GLint param);

  void upload_rgb8(int width, int height, const unsigned char* image);
  void upload_rgba8(int width, int height, const unsigned char* image);

};

}} // namespace grndr::ogl
