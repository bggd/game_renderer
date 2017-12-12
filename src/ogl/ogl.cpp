bool grndr::ogl::Info::gles = false;
uint8_t grndr::ogl::Info::major = 0;
uint8_t grndr::ogl::Info::minor = 0;


void grndr::ogl::make_current(bool gles, uint8_t major, uint8_t minor)
{
  grndr::ogl::Info::gles = gles;
  grndr::ogl::Info::major = major;
  grndr::ogl::Info::minor = minor;
}




