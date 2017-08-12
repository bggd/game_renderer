namespace grndr {

struct PipelineSpec {

  struct Shader {

    struct Uniform {

      enum class Type {
        MAT4
      };

      Uniform::Type type;
      const char* name;

    };

    const char* vs;
    const char* fs;

  };

  struct VertexAttribute {

    enum class Format {
      FLOAT3
    };

    VertexAttribute::Format format;
    GLboolean normalized;
    GLsizei stride;
    size_t offset;
    const char* name;
  };

  std::vector<PipelineSpec::VertexAttribute> attributes;
  PipelineSpec::Shader shader;
  std::vector<PipelineSpec::Shader::Uniform> uniforms;

};

} // namespace grndr
