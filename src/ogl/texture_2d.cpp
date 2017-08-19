namespace grndr { namespace ogl {

GLuint Texture2D::current_id = 0;

void Texture2D::gen_textures(GLsizei n, GLuint* textures)
{
  glGenTextures(n, textures);
}

void Texture2D::delete_textures(GLsizei n, const GLuint* textures)
{
  glDeleteTextures(n, textures);
}

void Texture2D::bind_zero()
{
  Texture2D::current_id = 0;
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::create()
{
  assert(this->id == 0);
  Texture2D::gen_textures(1, &this->id);
}

void Texture2D::destroy()
{
  assert(this->id != 0);
  this->id = 0;
  Texture2D::delete_textures(1, &this->id);
}

void Texture2D::bind()
{
  assert(this->id != 0);
  Texture2D::current_id = this->id;
  glBindTexture(GL_TEXTURE_2D, this->id);
}

void Texture2D::tex_parameteri(GLenum pname, GLint param)
{
  assert(Texture2D::current_id == this->id);
  glTexParameteri(GL_TEXTURE_2D, pname, param);
}

void Texture2D::upload_rgb8(int width, int height, const unsigned char* image)
{
  GLint internal_format = Info::gles ? GL_RGB : GL_RGB8;
  assert(Texture2D::current_id == this->id);
  glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
}


void Texture2D::upload_rgba8(int width, int height, const unsigned char* image)
{
  GLint internal_format = Info::gles ? GL_RGBA : GL_RGBA8;
  assert(Texture2D::current_id == this->id);
  glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}

}} // namespace grndr::ogl
