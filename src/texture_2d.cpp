namespace grndr {

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
  Texture2D::gen_textures(1, &this->id);
}

void Texture2D::destroy()
{
  Texture2D::delete_textures(1, &this->id);
}

void Texture2D::bind()
{
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
  assert(Texture2D::current_id == this->id);
  glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format_rgb8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
}


void Texture2D::upload_rgba8(int width, int height, const unsigned char* image)
{
  assert(Texture2D::current_id == this->id);
  glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format_rgba8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}

} // namespace grndr
