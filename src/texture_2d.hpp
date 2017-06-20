namespace grndr {

struct Texture2D {

  GLuint id;

  void bind();

  void tex_parameteri(GLenum pname, GLint param);

  void upload_rgb8(int width, int height, const unsigned char* image);
  void upload_rgba8(int width, int height, const unsigned char* image);

};

} // namespace grndr
