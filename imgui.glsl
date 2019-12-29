/*
cgc -oglsl -strict -profile arbvp1 -entry VSMain -DVS imgui.glsl | sed -z 's/\n/\"\n\"/g'
cgc -oglsl -strict -profile arbfp1 -entry PSMain      imgui.glsl | sed -z 's/\n/\"\n\"/g'
*/

#version 130

varying vec4 g_color;
varying vec2 g_uv;

#ifdef VS
void VSMain() {
  g_color     = gl_Color;
  g_uv        = gl_Vertex.zw;
  gl_Position = vec4(gl_Vertex.xy, 0, 1);
}
#endif

uniform sampler2D s_texture;

void PSMain() {
  vec4 image   = texture(s_texture, g_uv);
  gl_FragColor = g_color * image;
}
