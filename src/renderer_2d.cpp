namespace grndr {

void Renderer2D::setup()
{
  this->shdr.create_program();

  this->shdr.compile_vert(R"(
#version 100

precision mediump float;

uniform mat4 projection;

attribute vec2 pos;

varying vec4 vColor;

void main()
{
  gl_Position = projection * vec4(pos, 0.0, 1.0);
  vColor = vec4(1.0, 0.0, 0.0, 1.0);
}
  )");
  this->shdr.compile_frag(R"(
#version 100

precision mediump float;

varying vec4 vColor;

void main()
{
  gl_FragColor = vColor;
}
  )");
  this->shdr.bind_attr(0, "pos");
  //this->shdr.bind_attr(1, "uv");
  //this->shdr.bind_attr(2, "color");
  this->shdr.link();

  this->shdr.use();
  this->projection_location = this->shdr.get_uniform_location("projection");
  glUseProgram(0);
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
  glDisableVertexAttribArray(0);
  //glDisableVertexAttribArray(1);
  //glDisableVertexAttribArray(2);
  glUseProgram(0);
}

} // namespace grndr
