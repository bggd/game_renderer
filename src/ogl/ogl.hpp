namespace grndr { namespace ogl {


struct Info {

  static bool gles;
  static uint8_t major;
  static uint8_t minor;

};

bool Info::gles = false;
uint8_t Info::major = 0;
uint8_t Info::minor = 0;

void make_current(bool gles, uint8_t major, uint8_t minor)
{
  Info::gles = gles;
  Info::major = major;
  Info::minor = minor;
}

}} // namespace grndr::ogl
