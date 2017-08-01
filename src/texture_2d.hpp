namespace grndr {

struct Texture2D {

  GLuint id;
  GLint internal_format_rgb8;
  GLint internal_format_rgba8;

  void bind();

  void tex_parameteri(GLenum pname, GLint param);

  void upload_rgb8(int width, int height, const unsigned char* image);
  void upload_rgba8(int width, int height, const unsigned char* image);

};

} // namespace grndr
