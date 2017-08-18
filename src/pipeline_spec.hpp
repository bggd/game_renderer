namespace grndr {

struct PipelineSpec {

  struct Shader {

    struct Uniform {

      enum class Type {
        MAT4
      };

      int32_t location;
      Uniform::Type type;
      const char* name;

    };

    const char* vs;
    const char* fs;
    const char* glFragColor;
    ogl::ShaderGLSL glsl;
  };

  struct VertexAttribute {

    enum class Format {
      FLOAT2,
      FLOAT3
    };

    uint8_t vbo_list_idx;
    uint8_t index;
    VertexAttribute::Format format;
    bool normalized;
    size_t stride;
    size_t offset;
    const char* name;
  };

  std::vector<PipelineSpec::VertexAttribute> attributes;
  PipelineSpec::Shader shader;
  std::vector<PipelineSpec::Shader::Uniform> uniforms;
  bool compiled = false;

  static PipelineSpec* get_default_2d();

  bool compile_shader();

};

} // namespace grndr
