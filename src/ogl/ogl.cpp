bool grndr::ogl::Info::gles = false;
uint8_t grndr::ogl::Info::major = 0;
uint8_t grndr::ogl::Info::minor = 0;


void grndr::ogl::make_current(bool gles, uint8_t major, uint8_t minor)
{
  grndr::ogl::Info::gles = gles;
  grndr::ogl::Info::major = major;
  grndr::ogl::Info::minor = minor;
}

const char* grndr::ogl::get_glsl_version(bool gles, uint8_t major, uint8_t minor)
{
  if (gles) {
    if (major == 2 && minor == 0) { return "#version 100   "; }
    if (major == 3 && minor == 0) { return "#version 300 es"; }
  }
  else {
    if (major == 3 && minor == 3) { return "#version 330   "; }
  }
  return NULL;
}
