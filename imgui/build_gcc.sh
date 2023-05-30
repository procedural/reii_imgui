#!/bin/bash
cd "$(dirname -- "$(readlink -fn -- "${0}")")"

g++ -fPIC -c imgui.cpp imgui_demo.cpp imgui_draw.cpp cimgui.cpp fontAtlas.cpp drawList.cpp ${@}
g++ -shared -o ../libimgui.so cimgui.o drawList.o fontAtlas.o imgui.o imgui_demo.o imgui_draw.o
rm -f cimgui.o drawList.o fontAtlas.o imgui.o imgui_demo.o imgui_draw.o
