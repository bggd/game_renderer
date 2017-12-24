namespace grndr {

PipelineSpec* PipelineSpec::get_default_2d()
{
  static PipelineSpec spec;

  size_t stride = sizeof(GLfloat)*4;

  PipelineSpec::VertexAttribute pos;
  pos.vbo_list_idx = 0;
  pos.index = 0;
  pos.format = PipelineSpec::VertexAttribute::Format::FLOAT2;
  pos.stride = stride;
  pos.offset = 0;
  pos.name = "pos";

  PipelineSpec::VertexAttribute uv;
  uv.vbo_list_idx = 0;
  uv.index = 1;
  uv.format = PipelineSpec::VertexAttribute::Format::FLOAT2;
  uv.stride = stride;
  uv.offset = sizeof(GLfloat)*2;
  uv.name = "uv";

  spec.attributes.push_back(pos);
  spec.attributes.push_back(uv);

  static char vs[] = R"(#version XXX
#ifdef GL_ES
precision mediump float;
#else
#define attribute in
#define varying out
#endif

uniform mat4 u_proj;

attribute vec2 pos;
attribute vec2 uv;

varying vec2 v_uv;

void main()
{
  gl_Position = u_proj * vec4(pos, 0.0, 1.0);
  v_uv = uv;
}
)";

  static char fs[] = R"(#version XXX
#ifdef GL_ES
precision mediump float;
#else
out vec4 FragColor;
#define varying in
#define texture2D texture
#define gl_FragColor FragColor
#endif

uniform sampler2D u_tex;

varying vec2 v_uv;

void main()
{
  gl_FragColor = texture2D(u_tex, v_uv);
}
)";

  if (ogl::Info::gles) {
    fs[9] = vs[9] = '1';
    fs[10] = vs[10] = '0';
    fs[11] = vs[11] = '0';
  }
  else {
    fs[9] = vs[9] = '3';
    fs[10] = vs[10] = '3';
    fs[11] = vs[11] = '0';
  }

  spec.shader.vs = vs;
  spec.shader.fs = fs;
  spec.shader.glFragColor = "FragColor";

  PipelineSpec::Shader::Uniform proj;
  proj.type = PipelineSpec::Shader::Uniform::Type::MAT4;
  proj.name = "u_proj";

  spec.uniforms.push_back(proj);

  return &spec;
}

PipelineSpec* PipelineSpec::get_default_3d()
{
  static PipelineSpec spec;

  size_t stride = sizeof(GLfloat)*5;

  PipelineSpec::VertexAttribute pos;
  pos.vbo_list_idx = 0;
  pos.index = 0;
  pos.format = PipelineSpec::VertexAttribute::Format::FLOAT3;
  pos.stride = stride;
  pos.offset = 0;
  pos.name = "pos";

  PipelineSpec::VertexAttribute uv;
  uv.vbo_list_idx = 0;
  uv.index = 1;
  uv.format = PipelineSpec::VertexAttribute::Format::FLOAT2;
  uv.stride = stride;
  uv.offset = sizeof(GLfloat)*3;
  uv.name = "uv";

  spec.attributes.push_back(pos);
  spec.attributes.push_back(uv);

  static char vs[] = R"(#version XXX
#ifdef GL_ES
precision mediump float;
#else
#define attribute in
#define varying out
#endif

uniform mat4 u_MVP;

attribute vec3 pos;
attribute vec2 uv;

varying vec2 v_uv;

void main()
{
  gl_Position = u_MVP * vec4(pos, 1.0);
  v_uv = uv;
}
)";

  static char fs[] = R"(#version XXX
#ifdef GL_ES
precision mediump float;
#else
out vec4 FragColor;
#define varying in
#define texture2D texture
#define gl_FragColor FragColor
#endif

uniform sampler2D u_tex;

varying vec2 v_uv;

void main()
{
  gl_FragColor = texture2D(u_tex, v_uv);
}
)";

  if (ogl::Info::gles) {
    fs[9] = vs[9] = '1';
    fs[10] = vs[10] = '0';
    fs[11] = vs[11] = '0';
  }
  else {
    fs[9] = vs[9] = '3';
    fs[10] = vs[10] = '3';
    fs[11] = vs[11] = '0';
  }

  spec.shader.vs = vs;
  spec.shader.fs = fs;
  spec.shader.glFragColor = "FragColor";

  PipelineSpec::Shader::Uniform proj;
  proj.type = PipelineSpec::Shader::Uniform::Type::MAT4;
  proj.name = "u_MVP";

  spec.uniforms.push_back(proj);

  return &spec;
}

bool PipelineSpec::compile_shader()
{
  this->shader.glsl.create_program();

  if (!this->shader.glsl.compile_vert(this->shader.vs)) { return false; }
  if (!this->shader.glsl.compile_frag(this->shader.fs)) { return false; }

  for (const PipelineSpec::VertexAttribute& attr : this->attributes) {
    this->shader.glsl.bind_attr(attr.index, attr.name);
  }

  if (!ogl::Info::gles) {
    this->shader.glsl.bind_frag_data_location(0, this->shader.glFragColor);
  }

  if (!this->shader.glsl.link()) { return false; }

  this->shader.glsl.use();
  for (PipelineSpec::Shader::Uniform& u : this->uniforms) {
    u.location = this->shader.glsl.get_uniform_location(u.name);
    if (u.location < 0) { ogl::ShaderGLSL::use_zero(); return false; }
  }
  ogl::ShaderGLSL::use_zero();

  this->compiled = true;

  return true;
}

} // namespace grndr
