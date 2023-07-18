#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//窗口大小发生变化的回调
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//处理输入
void processInput(GLFWwindow* window);