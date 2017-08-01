namespace grndr {

void Texture2D::bind()
{
  glBindTexture(GL_TEXTURE_2D, this->id);
}

void Texture2D::tex_parameteri(GLenum pname, GLint param)
{
  glTexParameteri(GL_TEXTURE_2D, pname, param);
}

void Texture2D::upload_rgb8(int width, int height, const unsigned char* image)
{
  glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format_rgb8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
}


void Texture2D::upload_rgba8(int width, int height, const unsigned char* image)
{
  glTexImage2D(GL_TEXTURE_2D, 0, this->internal_format_rgba8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
}

} // namespace grndr
