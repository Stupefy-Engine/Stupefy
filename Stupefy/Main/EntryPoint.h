/****************************************************************************/
/*  EntryPoint.h                                                            */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2020] Harshit Bargujar                                        */
/*                                                                          */
/*  Licensed under the Apache License, Version 2.0 (the "License");         */
/*  you may not use this file except in compliance with the License.        */
/*  You may obtain a copy of the License at                                 */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/
/*  See the License for the specific language governing permissions and     */
/*  limitations under the License.                                          */
/****************************************************************************/


#pragma once

#include "Core/CoreCommon.h"
#include "Editor/Logger/Logger.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern Stupefy::Application* Stupefy::CreateApplication();

unsigned int SCR_HEIGHT = 600;
unsigned int SCR_WIDTH = 800;

void display(GLFWwindow* window);

int main()
{
	auto app = Stupefy::CreateApplication();
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "STUPEFY", NULL, NULL);

	if (window == NULL)
	{
		Stupefy::Logger::Error("Failed to create OPENGL window!");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Stupefy::Logger::Error("Failed to initialize Glad");
		return -1;
	}

	Stupefy::Logger::Log("OpenGL Info:");
	Stupefy::Logger::Log(" Vendor: %s", glGetString(GL_VENDOR));
	Stupefy::Logger::Log(" Renderer: %s", glGetString(GL_RENDERER));
	Stupefy::Logger::Log(" Version: %s", glGetString(GL_VERSION));

	while (!glfwWindowShouldClose(window))
	{
		display(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	app->Run();
	delete app;
}

void display(GLFWwindow* window)
{
	glClearColor(1.0, 0.5, 0.25, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

/*
int main(int argc, char* argv)
{
	Stupefy::Logger::Log("Initializing Stupefy Engine: v%d.0", 1);
	Stupefy::Logger::Trace("Checking Trace");
	Stupefy::Logger::Debug("Checking Debug");
	Stupefy::Logger::Warn("Checking Warn");
	Stupefy::Logger::Error("Checking Error");
	//Stupefy::Logger::Fatal("Checking Fatal");

}*/