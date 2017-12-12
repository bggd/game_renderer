namespace grndr { namespace ogl {


struct Info {

  static bool gles;
  static uint8_t major;
  static uint8_t minor;

};

void make_current(bool gles, uint8_t major, uint8_t minor);

}} // namespace grndr::ogl
