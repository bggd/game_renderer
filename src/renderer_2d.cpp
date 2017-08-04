namespace grndr {

static const char* gles2_vert = R"(#version 100

precision mediump float;

uniform mat4 projection;

attribute vec2 pos;
attribute vec2 uv;

varying vec2 vUV;

void main()
{
  gl_Position = projection * vec4(pos, 0.0, 1.0);
  vUV = uv;
}
)";

static const char* gles2_frag = R"(#version 100

precision mediump float;

uniform sampler2D tex;

varying vec2 vUV;

void main()
{
  gl_FragColor = texture2D(tex, vUV);
}
)";

static const char* gl33_vert = R"(#version 330

uniform mat4 projection;

in vec2 pos;
in vec2 uv;

out vec2 vUV;

void main()
{
  gl_Position = projection * vec4(pos, 0.0, 1.0);
  vUV = uv;
}
)";

static const char* gl33_frag = R"(#version 330

uniform sampler2D tex;

in vec2 vUV;

out vec4 FragColor;

void main()
{
  FragColor = texture(tex, vUV);
}
)";

bool Renderer2D::setup(bool gles)
{
  this->shader.create_program();

  if (!this->shader.compile_vert(gles ? gles2_vert : gl33_vert)) { return false; }

  if (!this->shader.compile_frag(gles ? gles2_frag : gl33_frag)) { return false; }

  this->shader.bind_attr(0, "pos");
  this->shader.bind_attr(1, "uv");
  //this->shader.bind_attr(2, "color");
  if (!gles) { this->shader.bind_frag_data_location(0, "FragColor"); }
  if (!this->shader.link()) { return false; }

  this->shader.use();
  this->projection_location = this->shader.get_uniform_location("projection");
  if (this->projection_location < 0) { return false; }
  ShaderGLSL::use_zero();

  return true;
}

void Renderer2D::set_ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
  gmath::Mat4 m;

  m = gmath::mat4::ortho(left, right, bottom, top, z_near, z_far);

  this->shader.uniform_mat4(this->projection_location, 1, (const GLfloat*)m.elements);
}

void Renderer2D::begin_pass()
{
  this->shader.use();
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  //glEnableVertexAttribArray(2);
}

void Renderer2D::end_pass()
{
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  //glDisableVertexAttribArray(2);
  ShaderGLSL::use_zero();
}

} // namespace grndr
