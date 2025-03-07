#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "glm/glm.hpp"
#include "scenes.hpp"

class UserInterface {
public:
	UserInterface(GLFWwindow* window);
	void Render();
private:
	ImGuiIO* io;
	float x_pos = 0.0f, y_pos = 0.0f, z_pos = 0.0f;
	float x_scale = 0.0f, y_scale = 0.0f, z_scale = 0.0f;
	float x_rot = 0.0f, y_rot = 0.0f, z_rot = 0.0f;
};