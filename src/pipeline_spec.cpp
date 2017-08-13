namespace grndr {

PipelineSpec* PipelineSpec::get_default_2d()
{
  PipelineSpec* spec;

  spec = new(std::nothrow) PipelineSpec;
  if (!spec) { return nullptr; }

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

  spec->attributes.push_back(pos);
  spec->attributes.push_back(uv);

  spec->shader.vs = "";
  spec->shader.fs = "";
  spec->shader.glFragColor = "FragColor";

  PipelineSpec::Shader::Uniform proj;
  proj.type = PipelineSpec::Shader::Uniform::Type::MAT4;
  proj.name = "projection";

  spec->uniforms.push_back(proj);

  return spec;
}

bool PipelineSpec::compile_shader()
{
  if (!this->shader.glsl.compile_vert(this->shader.vs)) { return false; }
  if (!this->shader.glsl.compile_frag(this->shader.fs)) { return false; }

  for (uint32_t i=0; i < this->attributes.size(); ++i) {
    const PipelineSpec::VertexAttribute& attr = this->attributes[i];
    this->shader.glsl.bind_attr(attr.index, attr.name);
  }

  this->shader.glsl.bind_frag_data_location(0, this->shader.glFragColor);

  if (!this->shader.glsl.link()) { return false; }

  this->shader.glsl.use();
  for (uint32_t i=0; i < this->uniforms.size(); ++i) {
    PipelineSpec::Shader::Uniform& u = this->uniforms[i];
    u.location = this->shader.glsl.get_uniform_location(u.name);
    if (u.location < 0) { ShaderGLSL::use_zero(); return false; }
  }
  ShaderGLSL::use_zero();

  this->compiled = true;

  return true;
}

} // namespace grndr
