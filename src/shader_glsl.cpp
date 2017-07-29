namespace grndr {

static bool
shader_compile(ShaderGLSL* s, GLenum type, const char* src)
{
  GLuint shdr = glCreateShader(type);
  glShaderSource(shdr, 1, &src, NULL);
  glCompileShader(shdr);

  GLint status = GL_TRUE;
  glGetShaderiv(shdr, GL_COMPILE_STATUS, &status);

  if (status == GL_FALSE) {
    GLint len;
    glGetShaderiv(shdr, GL_INFO_LOG_LENGTH, &len);

    GLchar* info_log = (GLchar*)malloc(sizeof(GLchar)*len);
    glGetShaderInfoLog(shdr, len, NULL, info_log);
    
    fprintf(stderr, "%s\n", info_log);
    free(info_log);

    glDeleteShader(shdr);

    return false;
  }

  if (type == GL_VERTEX_SHADER) { s->vert = shdr; }
  if (type == GL_FRAGMENT_SHADER) { s->frag = shdr; }

  return true;
}

void ShaderGLSL::create_program()
{
  this->prog = glCreateProgram();
}

void ShaderGLSL::delete_program()
{
  glDeleteProgram(this->prog);
}

bool ShaderGLSL::compile_vert(const char* src)
{
  return shader_compile(this, GL_VERTEX_SHADER, src);
}

bool ShaderGLSL::compile_frag(const char* src)
{
  return shader_compile(this, GL_FRAGMENT_SHADER, src);
}

void ShaderGLSL::bind_attr(GLuint location, const char* name)
{
  glBindAttribLocation(this->prog, location, name);
}

//void ShaderGLSL::bind_frag_data_location(GLuint color_number, const char* name)
//{
//  glBindFragDataLocation(this->prog, color_number, name);
//}

bool ShaderGLSL::link()
{
  glAttachShader(this->prog, this->vert);
  glAttachShader(this->prog, this->frag);
  glLinkProgram(this->prog);

  GLint status = GL_TRUE;
  glGetProgramiv(this->prog, GL_LINK_STATUS, &status);

  if (status == GL_FALSE) {
    GLint len;
    glGetProgramiv(this->prog, GL_INFO_LOG_LENGTH, &len);

    GLchar* info_log = (GLchar*)malloc(sizeof(GLchar)*len);
    glGetProgramInfoLog(this->prog, len, NULL, info_log);

    fprintf(stderr, "%s\n", info_log);
    free(info_log);

    glDeleteProgram(this->prog);
    glDeleteShader(this->vert);
    glDeleteShader(this->frag);

    return false;
  }

  glDetachShader(this->prog, this->vert);
  glDetachShader(this->prog, this->frag);

  return true;
}

void ShaderGLSL::use()
{
  glUseProgram(this->prog);
}

GLint ShaderGLSL::get_uniform_location(const char* name)
{
  return glGetUniformLocation(this->prog, name);
}

void ShaderGLSL::uniform_mat4(GLint location, GLsizei count, const GLfloat* v)
{
  glUniformMatrix4fv(location, count, GL_FALSE, v);
}

}
