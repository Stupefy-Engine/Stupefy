/****************************************************************************/
/*  OpenGLContext.cpp                                                       */
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


#include "OpenGLContext.h"

namespace Stupefy
{
	Stupefy::OpenGLContext::OpenGLContext(GLFWwindow* window)
		:m_Window(window)
	{
		Logger::Fatal("Window is null", window);
	}

	void Stupefy::OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		Logger::Error("Failed to initialize Glad!", status);

		Logger::Log("OpenGL Info:");
		Logger::Log("  Vendor: %s", glGetString(GL_VENDOR));
		Logger::Log("  Renderer: %s", glGetString(GL_RENDERER));
		Logger::Log("  Version: %s", glGetString(GL_VERSION));
	}

	void Stupefy::OpenGLContext::Swapbuffers()
	{
		glfwSwapBuffers(m_Window);
	}
}