namespace grndr {

static const char* gles2_vert = R"(#version 100

precision mediump float;

uniform mat4 projection;

attribute vec2 pos;

varying vec4 vColor;

void main()
{
  gl_Position = projection * vec4(pos, 0.0, 1.0);
  vColor = vec4(1.0, 1.0, 1.0, 1.0);
}
)";

static const char* gles2_frag = R"(#version 100

precision mediump float;

varying vec4 vColor;

void main()
{
  gl_FragColor = vColor;
}
)";

static const char* gl33_vert = R"(#version 330

uniform mat4 projection;

in vec2 pos;

out vec4 vColor;

void main()
{
  gl_Position = projection * vec4(pos, 0.0, 1.0);
  vColor = vec4(1.0, 1.0, 1.0, 1.0);
}
)";

static const char* gl33_frag = R"(#version 330

in vec4 vColor;

out vec4 FragColor;

void main()
{
  FragColor = vColor;
}
)";

bool Renderer2D::setup(bool gles)
{
  this->shdr.create_program();

  if (!this->shdr.compile_vert(gles ? gles2_vert : gl33_vert)) { return false; }

  if (!this->shdr.compile_frag(gles ? gles2_frag : gl33_frag)) { return false; }

  this->shdr.bind_attr(0, "pos");
  //this->shdr.bind_attr(1, "uv");
  //this->shdr.bind_attr(2, "color");
  if (!gles) {this->shdr.bind_frag_data_location(0, "FragColor"); }
  if (!this->shdr.link()) { return false; }

  this->shdr.use();
  this->projection_location = this->shdr.get_uniform_location("projection");
  if (this->projection_location < 0) { return false; }
  glUseProgram(0);

  return true;
}

void Renderer2D::set_ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
  gmath::Mat4 m;

  m = gmath::mat4::ortho(left, right, bottom, top, z_near, z_far);

  this->shdr.uniform_mat4(this->projection_location, 1, (const GLfloat*)m.elements);
}

void Renderer2D::begin_pass()
{
  this->shdr.use();
  glEnableVertexAttribArray(0);
  //glEnableVertexAttribArray(1);
  //glEnableVertexAttribArray(2);
}

void Renderer2D::end_pass()
{
  //glDisableVertexAttribArray(0);
  //glDisableVertexAttribArray(1);
  //glDisableVertexAttribArray(2);
  glUseProgram(0);
}

} // namespace grndr
