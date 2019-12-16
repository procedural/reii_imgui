#if 0
rm -f a.out
clang main.c reii.c libglfw.so.3 -lGL -lm
LD_LIBRARY_PATH=. ./a.out
exit
#endif

#include "reii.h"
#include "imgui.h"

#define GLFW_INCLUDE_NONE
#include "glfw3.h"

#include <stdio.h>
#include <math.h>

const float mesh_vertices[] = {
  #include "mesh_vertices.h"
};

const unsigned mesh_indices[] = {
  #include "mesh_indices.h"
};

#define _countof(x) (sizeof(x) / sizeof((x)[0]))

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_RESIZABLE, 0);
  glfwWindowHint(GLFW_SAMPLES, 4);
  GLFWwindow * window = glfwCreateWindow(700, 700, "", NULL, NULL);
  glfwMakeContextCurrent(window);

  ReiiContext   context = {};
  ReiiContext * ctx     = &context;
  reiiCreateContext((ReiiTypeProcedureGetProcAddress)glfwGetProcAddress, &context);

  char vp_string[] =
    "!!ARBvp1.0"
    "TEMP pos;"
    "TEMP R0;"
    "ADD pos, vertex.position, -program.env[0];"
    "MUL R0.xyzw, pos.xzzx, program.env[1].xyxy;"
    "ADD pos.x, R0.x,-R0.y;"
    "ADD pos.z, R0.z, R0.w;"
    "MUL R0.xyzw, pos.yzzy, program.env[1].zwzw;"
    "ADD pos.y, R0.x,-R0.y;"
    "ADD pos.z, R0.z, R0.w;"
    "MOV result.color, vertex.color;"
    "MOV result.position.xyw, pos.xyzz;"
    "MOV result.position.z, 0.1;"
    "END";

  char fp_string[] =
    "!!ARBfp1.0"
    "MOV result.color, fragment.color;"
    "END";

  ReiiMeshState mesh_state                                  = {};
  mesh_state.codeVertex                                     = vp_string;
  mesh_state.codeFragment                                   = fp_string;
  mesh_state.rasterizationDepthClampEnable                  = 0;
  mesh_state.rasterizationCullMode                          = REII_CULL_MODE_BACK;
  mesh_state.rasterizationFrontFace                         = REII_FRONT_FACE_CLOCKWISE;
  mesh_state.rasterizationDepthBiasEnable                   = 0;
  mesh_state.rasterizationDepthBiasConstantFactor           = 0;
  mesh_state.rasterizationDepthBiasSlopeFactor              = 0;
  mesh_state.multisampleEnable                              = 1;
  mesh_state.multisampleAlphaToCoverageEnable               = 0;
  mesh_state.multisampleAlphaToOneEnable                    = 0;
  mesh_state.depthTestEnable                                = 1;
  mesh_state.depthTestDepthWriteEnable                      = 1;
  mesh_state.depthTestDepthCompareOp                        = REII_COMPARE_OP_GREATER_OR_EQUAL;
  mesh_state.stencilTestEnable                              = 0;
  mesh_state.stencilTestFrontStencilTestFailOp              = REII_STENCIL_OP_KEEP;
  mesh_state.stencilTestFrontStencilTestPassDepthTestPassOp = REII_STENCIL_OP_KEEP;
  mesh_state.stencilTestFrontStencilTestPassDepthTestFailOp = REII_STENCIL_OP_KEEP;
  mesh_state.stencilTestFrontCompareOp                      = REII_COMPARE_OP_NEVER;
  mesh_state.stencilTestFrontCompareMask                    = 0;
  mesh_state.stencilTestFrontWriteMask                      = 0;
  mesh_state.stencilTestFrontReference                      = 0;
  mesh_state.stencilTestBackStencilTestFailOp               = REII_STENCIL_OP_KEEP;
  mesh_state.stencilTestBackStencilTestPassDepthTestPassOp  = REII_STENCIL_OP_KEEP;
  mesh_state.stencilTestBackStencilTestPassDepthTestFailOp  = REII_STENCIL_OP_KEEP;
  mesh_state.stencilTestBackCompareOp                       = REII_COMPARE_OP_NEVER;
  mesh_state.stencilTestBackCompareMask                     = 0;
  mesh_state.stencilTestBackWriteMask                       = 0;
  mesh_state.stencilTestBackReference                       = 0;
  mesh_state.blendLogicOpEnable                             = 0;
  mesh_state.blendLogicOp                                   = REII_LOGIC_OP_CLEAR;
  mesh_state.blendConstants[0]                              = 0;
  mesh_state.blendConstants[1]                              = 0;
  mesh_state.blendConstants[2]                              = 0;
  mesh_state.blendConstants[3]                              = 0;
  mesh_state.outputColorWriteEnableR                        = 1;
  mesh_state.outputColorWriteEnableG                        = 1;
  mesh_state.outputColorWriteEnableB                        = 1;
  mesh_state.outputColorWriteEnableA                        = 1;
  mesh_state.outputColorBlendEnable                         = 0;
  mesh_state.outputColorBlendColorFactorSource              = REII_BLEND_FACTOR_ZERO;
  mesh_state.outputColorBlendColorFactorTarget              = REII_BLEND_FACTOR_ZERO;
  mesh_state.outputColorBlendColorOp                        = REII_BLEND_OP_ADD;
  mesh_state.outputColorBlendAlphaFactorSource              = REII_BLEND_FACTOR_ZERO;
  mesh_state.outputColorBlendAlphaFactorTarget              = REII_BLEND_FACTOR_ZERO;
  mesh_state.outputColorBlendAlphaOp                        = REII_BLEND_OP_ADD;

  imguiInit(window, ctx);

  ImguiIO    * io    = (ImguiIO *)igGetIO();
  ImguiStyle * style = (ImguiStyle *)igGetStyle();

  style->scrollbarRounding = 0;
  style->windowRounding    = 0;
  style->frameRounding     = 0;

  ImFontAtlas_AddFontFromFileTTF(io->fonts, "NotoSans.ttf", 21, NULL, NULL);

  ReiiHandleCommandList clear_list = 0;
  reiiCreateCommandList(ctx, &clear_list);

  ReiiHandleCommandList list = 0;
  reiiCreateCommandList(ctx, &list);
  reiiCommandListSet(ctx, list);
    reiiCommandMeshSetState(ctx, &mesh_state, 0);
    reiiCommandMeshSet(ctx);
    for (int i = 0, mesh_indices_count = _countof(mesh_indices); i < mesh_indices_count; i += 1) {
      unsigned index = mesh_indices[i];
      reiiCommandMeshColor(ctx, (mesh_vertices[index * 4 + 2] + 1.f) / 1.5f, 0, 0.1f, 1);
      reiiCommandMeshPosition(ctx, mesh_vertices[index * 4 + 0], mesh_vertices[index * 4 + 1], mesh_vertices[index * 4 + 2], 1);
    }
    reiiCommandMeshEnd(ctx);
  reiiCommandListEnd(ctx);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  float pos_x = 0;
  float pos_y = 0;
  float pos_z = -2.f;
  float rot_x = 0;
  float rot_y = 0;

  glfwPollEvents();

  double start_mouse_x = 0;
  double start_mouse_y = 0;
  glfwGetCursorPos(window, &start_mouse_x, &start_mouse_y);
  double mouse_x_prev = start_mouse_x;
  double mouse_y_prev = start_mouse_y;

  for (; glfwWindowShouldClose(window) == 0;) {
    glfwPollEvents();

    imguiNewFrame();

    double mouse_x = 0;
    double mouse_y = 0;
    glfwGetCursorPos(window, &mouse_x, &mouse_y);

    float mouse_disp_x = (float)(mouse_x_prev - mouse_x) * 0.0035f;
    float mouse_disp_y = (float)(mouse_y - mouse_y_prev) * 0.0035f;

    rot_x += mouse_disp_x;
    rot_y += mouse_disp_y;

    float move_vec_x = 0;
    float move_vec_y = 0;
    float move_vec_z = 0;

    move_vec_x += glfwGetKey(window, GLFW_KEY_D);
    move_vec_x -= glfwGetKey(window, GLFW_KEY_A);

#if 0
    move_vec_y += glfwGetKey(window, GLFW_KEY_E);
    move_vec_y -= glfwGetKey(window, GLFW_KEY_Q);
#endif

    move_vec_z += glfwGetKey(window, GLFW_KEY_W);
    move_vec_z -= glfwGetKey(window, GLFW_KEY_S);

    float move_vec_len = sqrtf(move_vec_x*move_vec_x + move_vec_y*move_vec_y + move_vec_z*move_vec_z);
    if (move_vec_len != 0) {
      move_vec_x /= move_vec_len;
      move_vec_y /= move_vec_len;
      move_vec_z /= move_vec_len;
    }

    {
      float rot_cos = cosf(rot_y);
      float rot_sin = sinf(rot_y);
      float pos_y = move_vec_y;
      float pos_z = move_vec_z;
      move_vec_y = pos_y * rot_cos - pos_z * rot_sin;
      move_vec_z = pos_z * rot_cos + pos_y * rot_sin;
    }

    {
      float rot_cos = cosf(rot_x);
      float rot_sin = sinf(rot_x);
      float pos_x = move_vec_x;
      float pos_z = move_vec_z;
      move_vec_x = pos_x * rot_cos - pos_z * rot_sin;
      move_vec_z = pos_z * rot_cos + pos_x * rot_sin;
    }

#if 0
    static bool showTestWindow = 1;
    igShowTestWindow(&showTestWindow);
    {
      // Flat UI by yorick.penninks: https://color.adobe.com/Flat-UI-color-theme-2469224/
      static ImVec3 color_for_text = {236 / 255.f, 240 / 255.f, 241 / 255.f};
      static ImVec3 color_for_head = { 41 / 255.f, 128 / 255.f, 185 / 255.f};
      static ImVec3 color_for_area = { 57 / 255.f,  79 / 255.f, 105 / 255.f};
      static ImVec3 color_for_body = { 44 / 255.f,  62 / 255.f,  80 / 255.f};
      static ImVec3 color_for_pops = { 33 / 255.f,  46 / 255.f,  60 / 255.f};

      // Mint Y Dark:
      //static struct ImVec3 color_for_text = {211 / 255.f, 211 / 255.f, 211 / 255.f};
      //static struct ImVec3 color_for_head = { 95 / 255.f, 142 / 255.f,  85 / 255.f};
      //static struct ImVec3 color_for_area = { 47 / 255.f,  47 / 255.f,  47 / 255.f};
      //static struct ImVec3 color_for_body = { 64 / 255.f,  64 / 255.f,  64 / 255.f};
      //static struct ImVec3 color_for_pops = { 30 / 255.f,  30 / 255.f,  30 / 255.f};

      // Arc Theme:
      //static struct ImVec3 color_for_text = {211 / 255.f, 218 / 255.f, 227 / 255.f};
      //static struct ImVec3 color_for_head = { 64 / 255.f, 132 / 255.f, 214 / 255.f};
      //static struct ImVec3 color_for_area = { 47 / 255.f,  52 / 255.f,  63 / 255.f};
      //static struct ImVec3 color_for_body = { 56 / 255.f,  60 / 255.f,  74 / 255.f};
      //static struct ImVec3 color_for_pops = { 28 / 255.f,  30 / 255.f,  37 / 255.f};

      igColorEdit3("Text", &color_for_text.x);
      igColorEdit3("Head", &color_for_head.x);
      igColorEdit3("Area", &color_for_area.x);
      igColorEdit3("Body", &color_for_body.x);
      igColorEdit3("Pops", &color_for_pops.x);

      imguiEasyTheming(color_for_text, color_for_head, color_for_area, color_for_body, color_for_pops);
    }
#endif

    int windowWidth  = 0;
    int windowHeight = 0;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    reiiCommandListSet(ctx, clear_list);
      reiiCommandSetViewport(ctx, 0, 0, windowWidth, windowHeight);
      reiiCommandSetScissor(ctx, 0, 0, windowWidth, windowHeight);
      reiiCommandClear(ctx, REII_CLEAR_DEPTH_BIT | REII_CLEAR_COLOR_BIT, 0.f, 0, 0.f, 0.f, 0.08f, 1.f);
    reiiCommandListEnd(ctx);
    reiiSubmitCommandLists(ctx, 1, &clear_list);

    float future_pos_x = pos_x;
    float future_pos_z = pos_z;

    future_pos_x += move_vec_x * 0.025;
    future_pos_z += move_vec_z * 0.025;

    float quanta = (float)(100);

    int64_t quantized_future_pos_x = (int64_t)(future_pos_x * quanta);
    int64_t quantized_future_pos_z = (int64_t)(future_pos_z * quanta);

#if 1
    printf("%ld %ld\n", quantized_future_pos_x, quantized_future_pos_z);
    fflush(stdout);
#endif

    // Test area
    {
      if (quantized_future_pos_x > 400) {
        pos_x = 400 / quanta;
        move_vec_x = 0.f;
      }

      if (quantized_future_pos_x < -400) {
        pos_x = -400 / quanta;
        move_vec_x = 0.f;
      }

      if (quantized_future_pos_z > 400) {
        pos_z = 400 / quanta;
        move_vec_z = 0.f;
      }

      if (quantized_future_pos_z < -400) {
        pos_z = -400 / quanta;
        move_vec_z = 0.f;
      }
    }

    pos_x += move_vec_x * 0.025;
#if 0
    pos_y += move_vec_y * 0.025;
#endif
    pos_z += move_vec_z * 0.025;

    reiiSetProgramEnvironmentValueVertex(ctx, 0, pos_x, pos_y, pos_z, 0);
    reiiSetProgramEnvironmentValueVertex(ctx, 1, cosf(-rot_x), sinf(-rot_x), cosf(-rot_y), sinf(-rot_y));
    reiiSubmitCommandLists(ctx, 1, &list);

    igRender();

    glfwSwapBuffers(window);

    mouse_x_prev = mouse_x;
    mouse_y_prev = mouse_y;
  }

  imguiDeinit();
  glfwDestroyWindow(window);
  glfwTerminate();
}
