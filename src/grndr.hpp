#pragma once


#include "ogl/ogl.hpp"
#include "ogl/vbo.hpp"
#include "ogl/ibo.hpp"
#include "ogl/texture_2d.hpp"
#include "ogl/shader_glsl.hpp"

#include "pipeline_spec.hpp"
#include "gl_state.hpp"


#ifdef GAME_RENDERER_IMPLEMENTATION
#include "ogl/ogl.cpp"
#include "ogl/vbo.cpp"
#include "ogl/ibo.cpp"
#include "ogl/texture_2d.cpp"
#include "ogl/shader_glsl.cpp"

#include "pipeline_spec.cpp"
#include "gl_state.cpp"
#endif
