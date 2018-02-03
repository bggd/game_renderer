namespace grndr {

struct PipelineSpec {

  struct Shader {

    struct Uniform {

      enum class Type {
        MAT4
      };

      int32_t location = -1;
      Uniform::Type type;
      const char* name = nullptr;

    };

    ogl::ShaderGLSL glsl;
    const char* vs = nullptr;
    const char* fs = nullptr;
    const char* glFragColor = nullptr;

  };

  struct VertexAttribute {

    enum class Format {
      FLOAT2,
      FLOAT3
    };

    uint8_t vbo_slot = 0;
    uint8_t index;
    VertexAttribute::Format format;
    bool normalized = false;
    size_t stride;
    size_t offset = 0;
    const char* name = nullptr;
  };

  std::vector<PipelineSpec::VertexAttribute> attributes;
  PipelineSpec::Shader shader;
  std::vector<PipelineSpec::Shader::Uniform> uniforms;
  bool compiled = false;

  static PipelineSpec* get_default_2d();
  static PipelineSpec* get_default_3d();

  bool compile_shader();

};

} // namespace grndr
