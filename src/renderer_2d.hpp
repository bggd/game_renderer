namespace grndr {

struct Renderer2D {

  grndr::ShaderGLSL shader;
  GLint projection_location;

  bool setup(bool gles);

  void set_ortho(float left, float right, float bottom, float top, float z_near, float z_far);

  void begin_pass();
  void end_pass();

};

} // namespace grndr
