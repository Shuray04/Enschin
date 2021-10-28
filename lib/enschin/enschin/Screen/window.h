#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "enschin/math/dim2.h"
#include "enschin/math/vec2.h"
#include "enschin/graphics/effects/color.hpp"
#include "enschin/graphics/renderer.h"
#include "enschin/input/keyboard.h"
#include "enschin/input/mouse.h"

/**
 * @brief GLFWWindow wrapper
 */
class Window {
private:
	Dim2 windowSize;
	bool fullScreen;
	bool vSync = true;
	std::string windowTitle;
	GLFWwindow* window;
public:
	Window(std::string title, Dim2 size, bool fullscreen);
	bool update();
	Dim2 getSize() { return windowSize; }
	GLFWwindow* getGlfw() { return window; }
	void setSize(Dim2& v);
	void setFullScreen(bool fullscreen);
	void setTitle(std::string title);
	void setClearColor(Color newColor);
	void setVSync(bool vSync);
};