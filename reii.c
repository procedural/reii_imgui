// REI

#ifdef __linux__
#define __inline inline
#endif

#ifdef _WIN32
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")
#endif

typedef unsigned ReiBool32;

typedef unsigned ReiHandleProgram;
typedef unsigned ReiHandleTexture;
typedef unsigned ReiHandleCommandList;

// Context creation

typedef struct ReiContext {
  void * glGenProgramsARB;
  void * glDeleteProgramsARB;
  void * glBindProgramARB;
  void * glProgramStringARB;
  void * glGenTextures;
  void * glDeleteTextures;
  void * glActiveTexture;
  void * glBindTexture;
  void * glTexParameteri;
  void * glPixelStorei;
  void * glTexImage2D;
  void * glTexSubImage2D;
  void * glCopyTexImage2D;
  void * glCopyTexSubImage2D;
  void * glReadPixels;
  void * glGenLists;
  void * glDeleteLists;
  void * glNewList;
  void * glEndList;
  void * glClearDepthf;
  void * glClearStencil;
  void * glClearColor;
  void * glClear;
  void * glEnable;
  void * glDisable;
  void * glViewport;
  void * glScissor;
  void * glCullFace;
  void * glFrontFace;
  void * glPolygonOffset;
  void * glDepthMask;
  void * glDepthFunc;
  void * glStencilOpSeparate;
  void * glStencilFuncSeparate;
  void * glStencilMaskSeparate;
  void * glLogicOp;
  void * glBlendColor;
  void * glBlendFuncSeparate;
  void * glBlendEquationSeparate;
  void * glColorMask;
  void * glBegin;
  void * glEnd;
  void * glMultiTexCoord4f;
  void * glColor4f;
  void * glNormal3f;
  void * glVertex4f;
  void * glProgramEnvParameter4fARB;
  void * glProgramLocalParameter4fARB;
  void * glCallList;
  void * glGetError;
  void * glGetString;
  void * glGetIntegerv;
  void * glFlush;
  void * glFinish;
} ReiContext;

typedef void * (*ReiTypeProcedureGetProcAddress)(char * procname);

// Program binding

typedef enum ReiProgramBinding {
  REI_PROGRAM_BINDING_VERTEX   = 0x8620,
  REI_PROGRAM_BINDING_FRAGMENT = 0x8804,
} ReiProgramBinding;

// Texture binding

typedef enum ReiTextureBinding {
  REI_TEXTURE_BINDING_2D              = 0x0DE1,
  REI_TEXTURE_BINDING_CUBE            = 0x8513,
  REI_TEXTURE_BINDING_CUBE_POSITIVE_X = 0x8515,
  REI_TEXTURE_BINDING_CUBE_NEGATIVE_X = 0x8516,
  REI_TEXTURE_BINDING_CUBE_POSITIVE_Y = 0x8517,
  REI_TEXTURE_BINDING_CUBE_NEGATIVE_Y = 0x8518,
  REI_TEXTURE_BINDING_CUBE_POSITIVE_Z = 0x8519,
  REI_TEXTURE_BINDING_CUBE_NEGATIVE_Z = 0x851A,
} ReiTextureBinding;

// Texture initialization

typedef enum ReiSamplerFiltering {
  REI_SAMPLER_FILTERING_NEAREST             = 0x2600,
  REI_SAMPLER_FILTERING_NEAREST_MIP_NEAREST = 0x2700,
  REI_SAMPLER_FILTERING_NEAREST_MIP_LINEAR  = 0x2702,
  REI_SAMPLER_FILTERING_LINEAR              = 0x2601,
  REI_SAMPLER_FILTERING_LINEAR_MIP_NEAREST  = 0x2701,
  REI_SAMPLER_FILTERING_LINEAR_MIP_LINEAR   = 0x2703,
} ReiSamplerFiltering;

typedef enum ReiSamplerBehaviorOutsideTextureCoordinate {
  REI_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_REPEAT              = 0x2901,
  REI_SAMPLER_BEHAVIOR_OUTSIDE_TEXTURE_COORDINATE_CLAMP_TO_EDGE_VALUE = 0x812F,
} ReiSamplerBehaviorOutsideTextureCoordinate;

// Texture texels upload and backbuffer readback

typedef enum ReiTextureTexelFormat {
  REI_TEXTURE_TEXEL_FORMAT_A    = 0x1906,
  REI_TEXTURE_TEXEL_FORMAT_RGB  = 0x1907,
  REI_TEXTURE_TEXEL_FORMAT_RGBA = 0x1908,
} ReiTextureTexelFormat;

typedef enum ReiTextureTexelType {
  REI_TEXTURE_TEXEL_TYPE_SBYTE  = 0x1400,
  REI_TEXTURE_TEXEL_TYPE_UBYTE  = 0x1401,
  REI_TEXTURE_TEXEL_TYPE_SSHORT = 0x1402,
  REI_TEXTURE_TEXEL_TYPE_USHORT = 0x1403,
  REI_TEXTURE_TEXEL_TYPE_SINT   = 0x1404,
  REI_TEXTURE_TEXEL_TYPE_UINT   = 0x1405,
  REI_TEXTURE_TEXEL_TYPE_FLOAT  = 0x1406,
} ReiTextureTexelType;

// Command recording of backbuffer(s) clearing

typedef unsigned ReiClearFlags;
typedef enum ReiClearFlagBits {
  REI_CLEAR_DEPTH_BIT   = 0x00000100,
  REI_CLEAR_STENCIL_BIT = 0x00000400,
  REI_CLEAR_COLOR_BIT   = 0x00004000,
} ReiClearFlagBits;

// Command recording of mesh state and mesh work domain execution

typedef enum ReiCullMode {
  REI_CULL_MODE_NONE           = 0,
  REI_CULL_MODE_FRONT          = 0x0404,
  REI_CULL_MODE_BACK           = 0x0405,
  REI_CULL_MODE_FRONT_AND_BACK = 0x0408,
} ReiCullMode;

typedef enum ReiFrontFace {
  REI_FRONT_FACE_COUNTER_CLOCKWISE = 0x0901,
  REI_FRONT_FACE_CLOCKWISE         = 0x0900,
} ReiFrontFace;

typedef enum ReiCompareOp {
  REI_COMPARE_OP_NEVER            = 0x0200,
  REI_COMPARE_OP_LESS             = 0x0201,
  REI_COMPARE_OP_EQUAL            = 0x0202,
  REI_COMPARE_OP_LESS_OR_EQUAL    = 0x0203,
  REI_COMPARE_OP_GREATER          = 0x0204,
  REI_COMPARE_OP_NOT_EQUAL        = 0x0205,
  REI_COMPARE_OP_GREATER_OR_EQUAL = 0x0206,
  REI_COMPARE_OP_ALWAYS           = 0x0207,
} ReiCompareOp;

typedef enum ReiStencilOp {
  REI_STENCIL_OP_KEEP                = 0x1E00,
  REI_STENCIL_OP_ZERO                = 0,
  REI_STENCIL_OP_REPLACE             = 0x1E01,
  REI_STENCIL_OP_INCREMENT_AND_CLAMP = 0x1E02,
  REI_STENCIL_OP_DECREMENT_AND_CLAMP = 0x1E03,
  REI_STENCIL_OP_INVERT              = 0x150A,
} ReiStencilOp;

typedef enum ReiLogicOp {
  REI_LOGIC_OP_CLEAR         = 0x1500,
  REI_LOGIC_OP_AND           = 0x1501,
  REI_LOGIC_OP_AND_REVERSE   = 0x1502,
  REI_LOGIC_OP_COPY          = 0x1503,
  REI_LOGIC_OP_AND_INVERTED  = 0x1504,
  REI_LOGIC_OP_NO_OP         = 0x1505,
  REI_LOGIC_OP_XOR           = 0x1506,
  REI_LOGIC_OP_OR            = 0x1507,
  REI_LOGIC_OP_NOR           = 0x1508,
  REI_LOGIC_OP_EQUIVALENT    = 0x1509,
  REI_LOGIC_OP_INVERT        = 0x150A,
  REI_LOGIC_OP_OR_REVERSE    = 0x150B,
  REI_LOGIC_OP_COPY_INVERTED = 0x150C,
  REI_LOGIC_OP_OR_INVERTED   = 0x150D,
  REI_LOGIC_OP_NAND          = 0x150E,
  REI_LOGIC_OP_SET           = 0x150F,
} ReiLogicOp;

typedef enum ReiBlendFactor {
  REI_BLEND_FACTOR_ZERO                     = 0,
  REI_BLEND_FACTOR_ONE                      = 1,
  REI_BLEND_FACTOR_SOURCE_COLOR             = 0x0300,
  REI_BLEND_FACTOR_ONE_MINUS_SOURCE_COLOR   = 0x0301,
  REI_BLEND_FACTOR_TARGET_COLOR             = 0x0306,
  REI_BLEND_FACTOR_ONE_MINUS_TARGET_COLOR   = 0x0307,
  REI_BLEND_FACTOR_SOURCE_ALPHA             = 0x0302,
  REI_BLEND_FACTOR_ONE_MINUS_SOURCE_ALPHA   = 0x0303,
  REI_BLEND_FACTOR_TARGET_ALPHA             = 0x0304,
  REI_BLEND_FACTOR_ONE_MINUS_TARGET_ALPHA   = 0x0305,
  REI_BLEND_FACTOR_CONSTANT_COLOR           = 0x8001,
  REI_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 0x8002,
  REI_BLEND_FACTOR_CONSTANT_ALPHA           = 0x8003,
  REI_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 0x8004,
  REI_BLEND_FACTOR_SOURCE_ALPHA_SATURATE    = 0x0308,
} ReiBlendFactor;

typedef enum ReiBlendOp {
  REI_BLEND_OP_ADD              = 0x8006,
  REI_BLEND_OP_SUBTRACT         = 0x800A,
  REI_BLEND_OP_REVERSE_SUBTRACT = 0x800B,
  REI_BLEND_OP_MIN              = 0x8007,
  REI_BLEND_OP_MAX              = 0x8008,
} ReiBlendOp;

typedef struct ReiMeshState {
  ReiHandleProgram programVertex;
  ReiHandleProgram programFragment;
  ReiBool32        rasterizationDepthClampEnable;
  ReiCullMode      rasterizationCullMode;
  ReiFrontFace     rasterizationFrontFace;
  ReiBool32        rasterizationDepthBiasEnable;
  float            rasterizationDepthBiasConstantFactor;
  float            rasterizationDepthBiasSlopeFactor;
  ReiBool32        multisampleEnable;
  ReiBool32        multisampleAlphaToCoverageEnable;
  ReiBool32        multisampleAlphaToOneEnable;
  ReiBool32        depthTestEnable;
  ReiBool32        depthTestDepthWriteEnable;
  ReiCompareOp     depthTestDepthCompareOp;
  ReiBool32        stencilTestEnable;
  ReiStencilOp     stencilTestFrontStencilTestFailOp;
  ReiStencilOp     stencilTestFrontStencilTestPassDepthTestPassOp;
  ReiStencilOp     stencilTestFrontStencilTestPassDepthTestFailOp;
  ReiCompareOp     stencilTestFrontCompareOp;
  unsigned         stencilTestFrontCompareMask;
  unsigned         stencilTestFrontWriteMask;
  unsigned         stencilTestFrontReference;
  ReiStencilOp     stencilTestBackStencilTestFailOp;
  ReiStencilOp     stencilTestBackStencilTestPassDepthTestPassOp;
  ReiStencilOp     stencilTestBackStencilTestPassDepthTestFailOp;
  ReiCompareOp     stencilTestBackCompareOp;
  unsigned         stencilTestBackCompareMask;
  unsigned         stencilTestBackWriteMask;
  unsigned         stencilTestBackReference;
  ReiBool32        blendLogicOpEnable;
  ReiLogicOp       blendLogicOp;
  float            blendConstants[4];
  ReiBool32        outputColorWriteEnableR;
  ReiBool32        outputColorWriteEnableG;
  ReiBool32        outputColorWriteEnableB;
  ReiBool32        outputColorWriteEnableA;
  ReiBool32        outputColorBlendEnable;
  ReiBlendFactor   outputColorBlendColorFactorSource;
  ReiBlendFactor   outputColorBlendColorFactorTarget;
  ReiBlendOp       outputColorBlendColorOp;
  ReiBlendFactor   outputColorBlendAlphaFactorSource;
  ReiBlendFactor   outputColorBlendAlphaFactorTarget;
  ReiBlendOp       outputColorBlendAlphaOp;
} ReiMeshState;

// Error handling

typedef enum ReiStatus {
  REI_STATUS_SUCCESS                 = 0,
  REI_STATUS_ERROR_INVALID_ENUM      = 0x0500,
  REI_STATUS_ERROR_INVALID_VALUE     = 0x0501,
  REI_STATUS_ERROR_INVALID_OPERATION = 0x0502,
  REI_STATUS_ERROR_STACK_OVERFLOW    = 0x0503,
  REI_STATUS_ERROR_STACK_UNDERFLOW   = 0x0504,
  REI_STATUS_ERROR_OUT_OF_MEMORY     = 0x0505,
} ReiStatus;

// Context creation

typedef struct ReiTypeContext {
  void (*glGenProgramsARB)(int programsCount, ReiHandleProgram * outPrograms);
  void (*glDeleteProgramsARB)(int programsCount, ReiHandleProgram * programs);
  void (*glBindProgramARB)(ReiProgramBinding binding, ReiHandleProgram program);
  void (*glProgramStringARB)(ReiProgramBinding binding, unsigned stringType, unsigned stringLengthWithoutNullTerminator, char * string);
  void (*glGenTextures)(int texturesCount, ReiHandleTexture * outTextures);
  void (*glDeleteTextures)(int texturesCount, ReiHandleTexture * textures);
  void (*glActiveTexture)(unsigned slot);
  void (*glBindTexture)(ReiTextureBinding binding, ReiHandleTexture texture);
  void (*glTexParameteri)(ReiTextureBinding binding, unsigned parameter, int value);
  void (*glPixelStorei)(unsigned parameter, int value);
  void (*glTexImage2D)(ReiTextureBinding binding, int bindingLevel, ReiTextureTexelFormat bindingTexelFormat, int width, int height, int setTo0, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, void * texels);
  void (*glTexSubImage2D)(ReiTextureBinding binding, int bindingLevel, int bindingX, int bindingY, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, void * texels);
  void (*glCopyTexImage2D)(ReiTextureBinding binding, int bindingLevel, ReiTextureTexelFormat bindingTexelFormat, int backbufferX, int backbufferY, int width, int height, int setTo0);
  void (*glCopyTexSubImage2D)(ReiTextureBinding binding, int bindingLevel, int bindingX, int bindingY, int backbufferX, int backbufferY, int width, int height);
  void (*glReadPixels)(int backbufferX, int backbufferY, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, void * outTexels);
  ReiHandleCommandList (*glGenLists)(int setTo1);
  void (*glDeleteLists)(ReiHandleCommandList list, int setTo1);
  void (*glNewList)(ReiHandleCommandList list, unsigned mode);
  void (*glEndList)();
  void (*glClearDepthf)(float value);
  void (*glClearStencil)(int value);
  void (*glClearColor)(float r, float g, float b, float a);
  void (*glClear)(ReiClearFlags mask);
  void (*glEnable)(unsigned cap);
  void (*glDisable)(unsigned cap);
  void (*glViewport)(int x, int y, int width, int height);
  void (*glScissor)(int x, int y, int width, int height);
  void (*glCullFace)(unsigned mode);
  void (*glFrontFace)(unsigned mode);
  void (*glPolygonOffset)(float factor, float units);
  void (*glDepthMask)(unsigned char flag);
  void (*glDepthFunc)(unsigned func);
  void (*glStencilOpSeparate)(unsigned face, unsigned sfail, unsigned dpfail, unsigned dppass);
  void (*glStencilFuncSeparate)(unsigned face, unsigned func, int ref, unsigned mask);
  void (*glStencilMaskSeparate)(unsigned face, unsigned mask);
  void (*glLogicOp)(unsigned opcode);
  void (*glBlendColor)(float red, float green, float blue, float alpha);
  void (*glBlendFuncSeparate)(unsigned sfactorRGB, unsigned dfactorRGB, unsigned sfactorAlpha, unsigned dfactorAlpha);
  void (*glBlendEquationSeparate)(unsigned modeRGB, unsigned modeAlpha);
  void (*glColorMask)(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
  void (*glBegin)(unsigned topology);
  void (*glEnd)();
  void (*glMultiTexCoord4f)(unsigned slot, float x, float y, float z, float w);
  void (*glColor4f)(float r, float g, float b, float a);
  void (*glNormal3f)(float x, float y, float z);
  void (*glVertex4f)(float x, float y, float z, float w);
  void (*glProgramEnvParameter4fARB)(ReiProgramBinding binding, unsigned index, float x, float y, float z, float w);
  void (*glProgramLocalParameter4fARB)(ReiProgramBinding binding, unsigned index, float x, float y, float z, float w);
  void (*glCallList)(ReiHandleCommandList list);
  ReiStatus (*glGetError)();
  char * (*glGetString)(unsigned parameter);
  void (*glGetIntegerv)(unsigned parameter, int * outValue);
  void (*glFlush)();
  void (*glFinish)();
} ReiTypeContext;

static __inline void reiCreateContext(ReiTypeProcedureGetProcAddress getProcAddress, ReiContext * outContext) {
  outContext->glGenProgramsARB = getProcAddress("glGenProgramsARB");
  outContext->glDeleteProgramsARB = getProcAddress("glDeleteProgramsARB");
  outContext->glBindProgramARB = getProcAddress("glBindProgramARB");
  outContext->glProgramStringARB = getProcAddress("glProgramStringARB");
  outContext->glGenTextures = getProcAddress("glGenTextures");
  outContext->glDeleteTextures = getProcAddress("glDeleteTextures");
  outContext->glActiveTexture = getProcAddress("glActiveTexture");
  outContext->glBindTexture = getProcAddress("glBindTexture");
  outContext->glTexParameteri = getProcAddress("glTexParameteri");
  outContext->glPixelStorei = getProcAddress("glPixelStorei");
  outContext->glTexImage2D = getProcAddress("glTexImage2D");
  outContext->glTexSubImage2D = getProcAddress("glTexSubImage2D");
  outContext->glCopyTexImage2D = getProcAddress("glCopyTexImage2D");
  outContext->glCopyTexSubImage2D = getProcAddress("glCopyTexSubImage2D");
  outContext->glReadPixels = getProcAddress("glReadPixels");
  outContext->glGenLists = getProcAddress("glGenLists");
  outContext->glDeleteLists = getProcAddress("glDeleteLists");
  outContext->glNewList = getProcAddress("glNewList");
  outContext->glEndList = getProcAddress("glEndList");
  outContext->glClearDepthf = getProcAddress("glClearDepthf");
  outContext->glClearStencil = getProcAddress("glClearStencil");
  outContext->glClearColor = getProcAddress("glClearColor");
  outContext->glClear = getProcAddress("glClear");
  outContext->glEnable = getProcAddress("glEnable");
  outContext->glDisable = getProcAddress("glDisable");
  outContext->glViewport = getProcAddress("glViewport");
  outContext->glScissor = getProcAddress("glScissor");
  outContext->glCullFace = getProcAddress("glCullFace");
  outContext->glFrontFace = getProcAddress("glFrontFace");
  outContext->glPolygonOffset = getProcAddress("glPolygonOffset");
  outContext->glDepthMask = getProcAddress("glDepthMask");
  outContext->glDepthFunc = getProcAddress("glDepthFunc");
  outContext->glStencilOpSeparate = getProcAddress("glStencilOpSeparate");
  outContext->glStencilFuncSeparate = getProcAddress("glStencilFuncSeparate");
  outContext->glStencilMaskSeparate = getProcAddress("glStencilMaskSeparate");
  outContext->glLogicOp = getProcAddress("glLogicOp");
  outContext->glBlendColor = getProcAddress("glBlendColor");
  outContext->glBlendFuncSeparate = getProcAddress("glBlendFuncSeparate");
  outContext->glBlendEquationSeparate = getProcAddress("glBlendEquationSeparate");
  outContext->glColorMask = getProcAddress("glColorMask");
  outContext->glBegin = getProcAddress("glBegin");
  outContext->glEnd = getProcAddress("glEnd");
  outContext->glMultiTexCoord4f = getProcAddress("glMultiTexCoord4f");
  outContext->glColor4f = getProcAddress("glColor4f");
  outContext->glNormal3f = getProcAddress("glNormal3f");
  outContext->glVertex4f = getProcAddress("glVertex4f");
  outContext->glProgramEnvParameter4fARB = getProcAddress("glProgramEnvParameter4fARB");
  outContext->glProgramLocalParameter4fARB = getProcAddress("glProgramLocalParameter4fARB");
  outContext->glCallList = getProcAddress("glCallList");
  outContext->glGetError = getProcAddress("glGetError");
  outContext->glGetString = getProcAddress("glGetString");
  outContext->glGetIntegerv = getProcAddress("glGetIntegerv");
  outContext->glFlush = getProcAddress("glFlush");
  outContext->glFinish = getProcAddress("glFinish");
}

// Program handle creation and destruction

static __inline ReiHandleProgram reiCreateProgram(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ReiHandleProgram out = (ReiHandleProgram)0;
  ctx->glGenProgramsARB(1, &out);
  return out;
}

static __inline void reiDestroyProgram(ReiContext * context, ReiHandleProgram program) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glDeleteProgramsARB(1, &program);
}

// Program binding

static __inline void reiBindProgram(ReiContext * context, ReiProgramBinding binding, ReiHandleProgram program) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glBindProgramARB(binding, program);
}

// Program initialization

static __inline void reiProgramInitialize(ReiContext * context, ReiProgramBinding binding, unsigned codeStringLengthWithoutNullTerminator, char * codeString) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glProgramStringARB(binding, 0x8875, codeStringLengthWithoutNullTerminator, codeString); // GL_PROGRAM_FORMAT_ASCII
}

// Texture handle creation and deletion

static __inline ReiHandleTexture reiCreateTexture(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ReiHandleTexture out = (ReiHandleTexture)0;
  ctx->glGenTextures(1, &out);
  return out;
}

static __inline void reiDestroyTexture(ReiContext * context, ReiHandleTexture texture) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glDeleteTextures(1, &texture);
}

// Texture binding

static __inline void reiSetActiveTextureSlot(ReiContext * context, unsigned slot) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glActiveTexture(0x84C0 + slot); // GL_TEXTURE0
}

static __inline void reiBindTextureToActiveTextureSlot(ReiContext * context, ReiTextureBinding binding, ReiHandleTexture texture) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glBindTexture(binding, texture);
}

// Texture initialization

static __inline void reiTextureInitialize(ReiContext * context, ReiTextureBinding binding, ReiSamplerFiltering magFiltering, ReiSamplerFiltering minFiltering, ReiSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, ReiSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, int maxAnisotropy, ReiBool32 generateMipLevels) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glTexParameteri(binding, 0x2800, magFiltering); // GL_TEXTURE_MAG_FILTER
  ctx->glTexParameteri(binding, 0x2801, minFiltering); // GL_TEXTURE_MIN_FILTER
  ctx->glTexParameteri(binding, 0x2802, behaviorOutsideTextureCoordinateU); // GL_TEXTURE_WRAP_S
  ctx->glTexParameteri(binding, 0x2803, behaviorOutsideTextureCoordinateV); // GL_TEXTURE_WRAP_T
  ctx->glTexParameteri(binding, 0x84FE, maxAnisotropy); // GL_TEXTURE_MAX_ANISOTROPY
  ctx->glTexParameteri(binding, 0x8191, generateMipLevels); // GL_GENERATE_MIPMAP
}

// Texture texels upload and backbuffer readback

static __inline void reiTextureDefineAndCopyFromCpu(ReiContext * context, ReiTextureBinding binding, int bindingLevel, ReiTextureTexelFormat bindingTexelFormat, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, int texelsBytesAlignment, void * texels) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glPixelStorei(0x0CF5, texelsBytesAlignment); // GL_UNPACK_ALIGNMENT
  ctx->glTexImage2D(binding, bindingLevel, bindingTexelFormat, width, height, 0, texelsFormat, texelsType, texels);
}

static __inline void reiTextureDefineAndCopyFromBackbuffer(ReiContext * context, ReiTextureBinding binding, int bindingLevel, ReiTextureTexelFormat bindingTexelFormat, int backbufferX, int backbufferY, int width, int height) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glCopyTexImage2D(binding, bindingLevel, bindingTexelFormat, backbufferX, backbufferY, width, height, 0);
}

static __inline void reiTextureCopyFromCpu(ReiContext * context, ReiTextureBinding binding, int bindingLevel, int bindingX, int bindingY, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, int texelsBytesAlignment, void * texels) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glPixelStorei(0x0CF5, texelsBytesAlignment); // GL_UNPACK_ALIGNMENT
  ctx->glTexSubImage2D(binding, bindingLevel, bindingX, bindingY, width, height, texelsFormat, texelsType, texels);
}

static __inline void reiTextureCopyFromBackbuffer(ReiContext * context, ReiTextureBinding binding, int bindingLevel, int bindingX, int bindingY, int backbufferX, int backbufferY, int width, int height) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glCopyTexSubImage2D(binding, bindingLevel, bindingX, bindingY, backbufferX, backbufferY, width, height);
}

static __inline void reiReadbackToCpuFromBackbuffer(ReiContext * context, int backbufferX, int backbufferY, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, int texelsBytesAlignment, void * outTexels) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glPixelStorei(0x0D05, texelsBytesAlignment); // GL_PACK_ALIGNMENT
  ctx->glReadPixels(backbufferX, backbufferY, width, height, texelsFormat, texelsType, outTexels);
}

// Command list creation and deletion

static __inline ReiHandleCommandList reiCreateCommandList(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  return ctx->glGenLists(1);
}

static __inline void reiDestroyCommandList(ReiContext * context, ReiHandleCommandList list) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glDeleteLists(list, 1);
}

// Command list recording

static __inline void reiCommandListSet(ReiContext * context, ReiHandleCommandList list) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glNewList(list, 0x1300); // GL_COMPILE
  ctx->glEnable(REI_PROGRAM_BINDING_VERTEX);
  ctx->glEnable(REI_PROGRAM_BINDING_FRAGMENT);
  ctx->glEnable(0x0C11); // GL_SCISSOR_TEST
}

static __inline void reiCommandListEnd(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glEndList();
}

// Command recording viewport and scissor size

static __inline void reiCommandSetViewport(ReiContext * context, int x, int y, int width, int height) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glViewport(x, y, width, height);
}

static __inline void reiCommandSetScissor(ReiContext * context, int x, int y, int width, int height) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glScissor(x, y, width, height);
}

// Command recording of backbuffer(s) clearing

static __inline void reiCommandClear(ReiContext * context, ReiClearFlags clear, float depthValue, int stencilValue, float colorR, float colorG, float colorB, float colorA) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glClearDepthf(depthValue);
  ctx->glClearStencil(stencilValue);
  ctx->glClearColor(colorR, colorG, colorB, colorA);
  ctx->glClear(clear);
}

// Command recording of mesh state and mesh work domain execution

static __inline void reiCommandMeshSetState(ReiContext * context, ReiMeshState * state) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  state->rasterizationDepthClampEnable == 1 ? ctx->glEnable(0x864F) : ctx->glDisable(0x864F);  // GL_DEPTH_CLAMP
  if (state->rasterizationCullMode == REI_CULL_MODE_NONE) {
    ctx->glDisable(0x0B44); // GL_CULL_FACE
  } else {
    ctx->glEnable(0x0B44);  // GL_CULL_FACE
    ctx->glCullFace(state->rasterizationCullMode);
  }
  ctx->glFrontFace(state->rasterizationFrontFace);
  state->rasterizationDepthBiasEnable == 1 ? ctx->glEnable(0x8037) : ctx->glDisable(0x8037); // GL_POLYGON_OFFSET_FILL
  ctx->glPolygonOffset(state->rasterizationDepthBiasSlopeFactor, state->rasterizationDepthBiasConstantFactor);
  state->multisampleEnable == 1 ? ctx->glEnable(0x809D)  : ctx->glDisable(0x809D); // GL_MULTISAMPLE
  state->multisampleAlphaToCoverageEnable == 1 ? ctx->glEnable(0x809E) : ctx->glDisable(0x809E); // GL_SAMPLE_ALPHA_TO_COVERAGE
  state->multisampleAlphaToOneEnable == 1 ? ctx->glEnable(0x809F) : ctx->glDisable(0x809F); // GL_SAMPLE_ALPHA_TO_ONE
  state->depthTestEnable == 1 ? ctx->glEnable(0x0B71) : ctx->glDisable(0x0B71); // GL_DEPTH_TEST
  ctx->glDepthMask(state->depthTestDepthWriteEnable == 1 ? 1 : 0);
  ctx->glDepthFunc(state->depthTestDepthCompareOp);
  state->stencilTestEnable == 1 ? ctx->glEnable(0x0B90) : ctx->glDisable(0x0B90); // GL_STENCIL_TEST
  ctx->glStencilOpSeparate(0x0404, state->stencilTestFrontStencilTestFailOp, state->stencilTestFrontStencilTestPassDepthTestFailOp, state->stencilTestFrontStencilTestPassDepthTestPassOp); // GL_FRONT
  ctx->glStencilFuncSeparate(0x0404, state->stencilTestFrontCompareOp, state->stencilTestFrontReference, state->stencilTestFrontCompareMask); // GL_FRONT
  ctx->glStencilMaskSeparate(0x0404, state->stencilTestFrontWriteMask); // GL_FRONT
  ctx->glStencilOpSeparate(0x0405, state->stencilTestBackStencilTestFailOp, state->stencilTestBackStencilTestPassDepthTestFailOp, state->stencilTestBackStencilTestPassDepthTestPassOp); // GL_BACK
  ctx->glStencilFuncSeparate(0x0405, state->stencilTestBackCompareOp, state->stencilTestBackReference, state->stencilTestBackCompareMask); // GL_BACK
  ctx->glStencilMaskSeparate(0x0405, state->stencilTestBackWriteMask); // GL_BACK
  state->blendLogicOpEnable == 1 ? ctx->glEnable(0x0BF2) : ctx->glDisable(0x0BF2); // GL_COLOR_LOGIC_OP
  ctx->glLogicOp(state->blendLogicOp);
  ctx->glBlendColor(state->blendConstants[0], state->blendConstants[1], state->blendConstants[2], state->blendConstants[3]);
  ctx->glColorMask(state->outputColorWriteEnableR == 1 ? 1 : 0, state->outputColorWriteEnableG == 1 ? 1 : 0, state->outputColorWriteEnableB == 1 ? 1 : 0, state->outputColorWriteEnableA == 1 ? 1 : 0);
  state->outputColorBlendEnable == 1 ? ctx->glEnable(0x0BE2) : ctx->glDisable(0x0BE2); // GL_BLEND
  ctx->glBlendFuncSeparate(state->outputColorBlendColorFactorSource, state->outputColorBlendColorFactorTarget, state->outputColorBlendAlphaFactorSource, state->outputColorBlendAlphaFactorTarget);
  ctx->glBlendEquationSeparate(state->outputColorBlendColorOp, state->outputColorBlendAlphaOp);
  ctx->glBindProgramARB(REI_PROGRAM_BINDING_VERTEX,   state->programVertex);
  ctx->glBindProgramARB(REI_PROGRAM_BINDING_FRAGMENT, state->programFragment);
}

static __inline void reiCommandMeshSet(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glBegin(0x0004); // GL_TRIANGLES
}

static __inline void reiCommandMeshEnd(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glEnd();
}

static __inline void reiCommandMeshTexcoord(ReiContext * context, unsigned index, float x, float y, float z, float w) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glMultiTexCoord4f(0x84C0 + index, x, y, z, w); // GL_TEXTURE0
}

static __inline void reiCommandMeshColor(ReiContext * context, float r, float g, float b, float a) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glColor4f(r, g, b, a);
}

static __inline void reiCommandMeshNormal(ReiContext * context, float x, float y, float z) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glNormal3f(x, y, z);
}

static __inline void reiCommandMeshPosition(ReiContext * context, float x, float y, float z, float w) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glVertex4f(x, y, z, w);
}

// Command list submission and dynamic state setting

static __inline void reiSetProgramEnvironmentValue(ReiContext * context, ReiProgramBinding binding, unsigned index, float x, float y, float z, float w) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glProgramEnvParameter4fARB(binding, index, x, y, z, w);
}

static __inline void reiSetProgramLocalValue(ReiContext * context, ReiProgramBinding binding, unsigned index, float x, float y, float z, float w) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glProgramLocalParameter4fARB(binding, index, x, y, z, w);
}

static __inline void reiSubmitCommandLists(ReiContext * context, unsigned commandListsCount, ReiHandleCommandList * commandLists) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  unsigned i = 0;
  for (i = 0; i < commandListsCount; i += 1) {
    ctx->glCallList(commandLists[i]);
  }
}

// Error handling

static __inline ReiStatus reiGetStatus(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  return ctx->glGetError();
}

static __inline char * reiGetProgramStatusString(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  return ctx->glGetString(0x8874); // GL_PROGRAM_ERROR_STRING
}

static __inline int reiGetProgramStatusCodePosition(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  int out = 0;
  ctx->glGetIntegerv(0x864B, &out); // GL_PROGRAM_ERROR_POSITION
  return out;
}

// Misc

static __inline void reiFlush(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glFlush();
}

static __inline void reiFinish(ReiContext * context) {
  const ReiTypeContext * ctx = (ReiTypeContext *)(void *)context;
  ctx->glFinish();
}

// REII

#include <string.h>
#include <stdio.h>

#define REII_MAX_TEXTURE_BINDINGS_COUNT 8

typedef struct ReiiMeshTextureBindings {
  ReiTextureBinding binding[REII_MAX_TEXTURE_BINDINGS_COUNT];
  ReiHandleTexture  texture[REII_MAX_TEXTURE_BINDINGS_COUNT];
} ReiiMeshTextureBindings;

typedef struct ReiiMeshState {
  ReiHandleProgram programVertex;
  ReiHandleProgram programFragment;
  ReiBool32        rasterizationDepthClampEnable;
  ReiCullMode      rasterizationCullMode;
  ReiFrontFace     rasterizationFrontFace;
  ReiBool32        rasterizationDepthBiasEnable;
  float            rasterizationDepthBiasConstantFactor;
  float            rasterizationDepthBiasSlopeFactor;
  ReiBool32        multisampleEnable;
  ReiBool32        multisampleAlphaToCoverageEnable;
  ReiBool32        multisampleAlphaToOneEnable;
  ReiBool32        depthTestEnable;
  ReiBool32        depthTestDepthWriteEnable;
  ReiCompareOp     depthTestDepthCompareOp;
  ReiBool32        stencilTestEnable;
  ReiStencilOp     stencilTestFrontStencilTestFailOp;
  ReiStencilOp     stencilTestFrontStencilTestPassDepthTestPassOp;
  ReiStencilOp     stencilTestFrontStencilTestPassDepthTestFailOp;
  ReiCompareOp     stencilTestFrontCompareOp;
  unsigned         stencilTestFrontCompareMask;
  unsigned         stencilTestFrontWriteMask;
  unsigned         stencilTestFrontReference;
  ReiStencilOp     stencilTestBackStencilTestFailOp;
  ReiStencilOp     stencilTestBackStencilTestPassDepthTestPassOp;
  ReiStencilOp     stencilTestBackStencilTestPassDepthTestFailOp;
  ReiCompareOp     stencilTestBackCompareOp;
  unsigned         stencilTestBackCompareMask;
  unsigned         stencilTestBackWriteMask;
  unsigned         stencilTestBackReference;
  ReiBool32        blendLogicOpEnable;
  ReiLogicOp       blendLogicOp;
  float            blendConstants[4];
  ReiBool32        outputColorWriteEnableR;
  ReiBool32        outputColorWriteEnableG;
  ReiBool32        outputColorWriteEnableB;
  ReiBool32        outputColorWriteEnableA;
  ReiBool32        outputColorBlendEnable;
  ReiBlendFactor   outputColorBlendColorFactorSource;
  ReiBlendFactor   outputColorBlendColorFactorTarget;
  ReiBlendOp       outputColorBlendColorOp;
  ReiBlendFactor   outputColorBlendAlphaFactorSource;
  ReiBlendFactor   outputColorBlendAlphaFactorTarget;
  ReiBlendOp       outputColorBlendAlphaOp;
  char *           codeVertex;
  char *           codeFragment;
} ReiiMeshState;

ReiiMeshState * REII_GLOBAL_CURRENT_MESH_STATE = 0;

// Context

void reiiCreateContext(ReiTypeProcedureGetProcAddress getProcAddress, ReiContext * outContext) {
  reiCreateContext(getProcAddress, outContext);
}

// Texture

void reiiCreateTexture(ReiContext * context, ReiTextureBinding binding, ReiSamplerFiltering magFiltering, ReiSamplerFiltering minFiltering, ReiSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateU, ReiSamplerBehaviorOutsideTextureCoordinate behaviorOutsideTextureCoordinateV, int maxAnisotropy, ReiBool32 generateMipLevels, ReiHandleTexture * outTexture) {
  ReiHandleTexture texture = reiCreateTexture(context);
  ReiTextureBinding metabinding = binding == REI_TEXTURE_BINDING_2D ? REI_TEXTURE_BINDING_2D : REI_TEXTURE_BINDING_CUBE;
  reiSetActiveTextureSlot(context, 0);
  reiBindTextureToActiveTextureSlot(context, metabinding, texture);
  reiTextureInitialize(context, binding, magFiltering, minFiltering, behaviorOutsideTextureCoordinateU, behaviorOutsideTextureCoordinateV, maxAnisotropy, generateMipLevels);
  reiBindTextureToActiveTextureSlot(context, metabinding, 0);
  outTexture[0] = texture;
}

void reiiTextureDefineAndCopyFromCpu(ReiContext * context, ReiTextureBinding binding, ReiHandleTexture bindingTexture, int bindingLevel, ReiTextureTexelFormat bindingTexelFormat, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, int texelsBytesAlignment, void * texels) {
  ReiTextureBinding metabinding = binding == REI_TEXTURE_BINDING_2D ? REI_TEXTURE_BINDING_2D : REI_TEXTURE_BINDING_CUBE;
  reiSetActiveTextureSlot(context, 0);
  reiBindTextureToActiveTextureSlot(context, metabinding, bindingTexture);
  reiTextureDefineAndCopyFromCpu(context, binding, bindingLevel, bindingTexelFormat, width, height, texelsFormat, texelsType, texelsBytesAlignment, texels);
  reiBindTextureToActiveTextureSlot(context, metabinding, 0);
}

void reiiTextureDefineAndCopyFromBackbuffer(ReiContext * context, ReiTextureBinding binding, ReiHandleTexture bindingTexture, int bindingLevel, ReiTextureTexelFormat bindingTexelFormat, int backbufferX, int backbufferY, int width, int height) {
  ReiTextureBinding metabinding = binding == REI_TEXTURE_BINDING_2D ? REI_TEXTURE_BINDING_2D : REI_TEXTURE_BINDING_CUBE;
  reiSetActiveTextureSlot(context, 0);
  reiBindTextureToActiveTextureSlot(context, metabinding, bindingTexture);
  reiTextureDefineAndCopyFromBackbuffer(context, binding, bindingLevel, bindingTexelFormat, backbufferX, backbufferY, width, height);
  reiBindTextureToActiveTextureSlot(context, metabinding, 0);
}

void reiiTextureCopyFromCpu(ReiContext * context, ReiTextureBinding binding, ReiHandleTexture bindingTexture, int bindingLevel, int bindingX, int bindingY, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, int texelsBytesAlignment, void * texels) {
  ReiTextureBinding metabinding = binding == REI_TEXTURE_BINDING_2D ? REI_TEXTURE_BINDING_2D : REI_TEXTURE_BINDING_CUBE;
  reiSetActiveTextureSlot(context, 0);
  reiBindTextureToActiveTextureSlot(context, metabinding, bindingTexture);
  reiTextureCopyFromCpu(context, binding, bindingLevel, bindingX, bindingY, width, height, texelsFormat, texelsType, texelsBytesAlignment, texels);
  reiBindTextureToActiveTextureSlot(context, metabinding, 0);
}

void reiiTextureCopyFromBackbuffer(ReiContext * context, ReiTextureBinding binding, ReiHandleTexture bindingTexture, int bindingLevel, int bindingX, int bindingY, int backbufferX, int backbufferY, int width, int height) {
  ReiTextureBinding metabinding = binding == REI_TEXTURE_BINDING_2D ? REI_TEXTURE_BINDING_2D : REI_TEXTURE_BINDING_CUBE;
  reiSetActiveTextureSlot(context, 0);
  reiBindTextureToActiveTextureSlot(context, metabinding, bindingTexture);
  reiTextureCopyFromBackbuffer(context, binding, bindingLevel, bindingX, bindingY, backbufferX, backbufferY, width, height);
  reiBindTextureToActiveTextureSlot(context, metabinding, 0);
}

void reiiReadbackToCpuFromBackbuffer(ReiContext * context, int backbufferX, int backbufferY, int width, int height, ReiTextureTexelFormat texelsFormat, ReiTextureTexelType texelsType, int texelsBytesAlignment, void * outTexels) {
  reiReadbackToCpuFromBackbuffer(context, backbufferX, backbufferY, width, height, texelsFormat, texelsType, texelsBytesAlignment, outTexels);
}

// Command list

void reiiCreateCommandList(ReiContext * context, ReiHandleCommandList * outList) {
  outList[0] = reiCreateCommandList(context);
}

void reiiCommandListSet(ReiContext * context, ReiHandleCommandList list) {
  reiCommandListSet(context, list);
}

void reiiCommandListEnd(ReiContext * context) {
  reiCommandListEnd(context);
  REII_GLOBAL_CURRENT_MESH_STATE = 0;
}

void reiiCommandSetViewport(ReiContext * context, int x, int y, int width, int height) {
  reiCommandSetViewport(context, x, y, width, height);
}

void reiiCommandSetScissor(ReiContext * context, int x, int y, int width, int height) {
  reiCommandSetScissor(context, x, y, width, height);
}

void reiiCommandClear(ReiContext * context, ReiClearFlags clear, float depthValue, int stencilValue, float colorR, float colorG, float colorB, float colorA) {
  reiCommandClear(context, clear, depthValue, stencilValue, colorR, colorG, colorB, colorA);
}

void reiiCommandMeshSetState(ReiContext * context, ReiiMeshState * state, ReiiMeshTextureBindings * bindings) {
  unsigned i = 0;
  if (state->programVertex == 0) {
    ReiHandleProgram program = reiCreateProgram(context);
    reiBindProgram(context, REI_PROGRAM_BINDING_VERTEX, program);
    reiProgramInitialize(context, REI_PROGRAM_BINDING_VERTEX, strlen(state->codeVertex), state->codeVertex);
    reiBindProgram(context, REI_PROGRAM_BINDING_VERTEX, REII_GLOBAL_CURRENT_MESH_STATE == 0 ? 0 : REII_GLOBAL_CURRENT_MESH_STATE->programVertex);
    printf("%s", reiGetProgramStatusString(context));
    fflush(stdout);
    state->programVertex = program;
  }
  if (state->programFragment == 0) {
    ReiHandleProgram program = reiCreateProgram(context);
    reiBindProgram(context, REI_PROGRAM_BINDING_FRAGMENT, program);
    reiProgramInitialize(context, REI_PROGRAM_BINDING_FRAGMENT, strlen(state->codeFragment), state->codeFragment);
    reiBindProgram(context, REI_PROGRAM_BINDING_FRAGMENT, REII_GLOBAL_CURRENT_MESH_STATE == 0 ? 0 : REII_GLOBAL_CURRENT_MESH_STATE->programFragment);
    printf("%s", reiGetProgramStatusString(context));
    fflush(stdout);
    state->programFragment = program;
  }
  if (state != REII_GLOBAL_CURRENT_MESH_STATE) {
    reiCommandMeshSetState(context, (ReiMeshState *)((void *)state));
  }
  REII_GLOBAL_CURRENT_MESH_STATE = state;
  if (bindings != 0) {
    for (; i < REII_MAX_TEXTURE_BINDINGS_COUNT; i += 1) {
      if (bindings->binding[i] != 0 && bindings->texture[i] == 0) {
        printf("Error: binding[%d] != 0 but texture[%d] == 0\n", i, i);
        fflush(stdout);
      }
      if (bindings->binding[i] == 0 && bindings->texture[i] != 0) {
        printf("Error: binding[%d] == 0 but texture[%d] != 0\n", i, i);
        fflush(stdout);
      }
      if (bindings->binding[i] != 0) {
        reiSetActiveTextureSlot(context, i);
        reiBindTextureToActiveTextureSlot(context, bindings->binding[i], bindings->texture[i]);
      } else {
        reiSetActiveTextureSlot(context, i);
        reiBindTextureToActiveTextureSlot(context, REI_TEXTURE_BINDING_2D, 0);
      }
    }
  }
}

void reiiCommandMeshSet(ReiContext * context) {
  reiCommandMeshSet(context);
}

void reiiCommandMeshEnd(ReiContext * context) {
  reiCommandMeshEnd(context);
}

void reiiCommandMeshTexcoord(ReiContext * context, unsigned index, float x, float y, float z, float w) {
  reiCommandMeshTexcoord(context, index, x, y, z, w);
}

void reiiCommandMeshColor(ReiContext * context, float r, float g, float b, float a) {
  reiCommandMeshColor(context, r, g, b, a);
}

void reiiCommandMeshNormal(ReiContext * context, float x, float y, float z) {
  reiCommandMeshNormal(context, x, y, z);
}

void reiiCommandMeshPosition(ReiContext * context, float x, float y, float z, float w) {
  reiCommandMeshPosition(context, x, y, z, w);
}

// Submit

void reiiSetProgramEnvironmentValueVertex(ReiContext * context, unsigned index, float x, float y, float z, float w) {
  reiSetProgramEnvironmentValue(context, REI_PROGRAM_BINDING_VERTEX, index, x, y, z, w);
}

void reiiSetProgramEnvironmentValueFragment(ReiContext * context, unsigned index, float x, float y, float z, float w) {
  reiSetProgramEnvironmentValue(context, REI_PROGRAM_BINDING_FRAGMENT, index, x, y, z, w);
}

void reiiSubmitCommandLists(ReiContext * context, unsigned listsCount, ReiHandleCommandList * lists) {
  reiSubmitCommandLists(context, listsCount, lists);
}

// Destroy

void reiiDestroyTexture(ReiContext * context, ReiHandleTexture texture) {
  reiDestroyTexture(context, texture);
}

void reiiDestroyCommandList(ReiContext * context, ReiHandleCommandList list) {
  reiDestroyCommandList(context, list);
}

void reiiDestroyProgram(ReiContext * context, ReiHandleProgram program) {
  reiDestroyProgram(context, program);
}

void reiiDestroyContext(ReiContext * context) {
}

// Status

void reiiGetStatus(ReiContext * context, ReiStatus * outStatus) {
  outStatus[0] = reiGetStatus(context);
}

// Misc

void reiiFlush(ReiContext * context) {
  reiFlush(context);
}

void reiiFinish(ReiContext * context) {
  reiFinish(context);
}
