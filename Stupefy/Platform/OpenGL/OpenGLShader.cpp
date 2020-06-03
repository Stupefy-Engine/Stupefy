/****************************************************************************/
/*  OpenGLShader.cpp                                                        */
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


#include "OpenGLShader.h"

namespace Stupefy
{
	static unsigned int ShaderType(const std::string type)
	{
		if (type == "vertex")
		{
			return GL_VERTEX_SHADER;
		}
		if (type == "fragment")
		{
			return GL_FRAGMENT_SHADER;
		}

		Logger::Error("Unknown shader type!", false);
	}

	Stupefy::OpenGLShader::OpenGLShader(const std::string& filepath)
	{
		std::string source = FileReader(filepath);
		auto shaderSource = ProcessShader(source);
		CompileShader(shaderSource);
	}

	Stupefy::OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource)
		:m_Name(name)
	{
		std::unordered_map<unsigned int, std::string> sources;
		sources[GL_VERTEX_SHADER] = vertexSource;
		sources[GL_FRAGMENT_SHADER] = fragmentSource;
	}

	Stupefy::OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RenderID);
	}

	void Stupefy::OpenGLShader::Bind() const
	{
		glUseProgram(m_RenderID);
	}

	void Stupefy::OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	std::string OpenGLShader::FileReader(const std::string& filepath)
	{
		std::string output;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			if (size != -1)
			{
				output.resize(size);
				in.seekg(0, std::ios::beg);
				in.read(&output[0], size);
				in.close();
			}
			else
			{
				Logger::Error("Could not read from file", filepath);
			}
		}
		else
		{
			Logger::Error("Could not open the file", filepath);
		}
		return output;
	}

	std::string OpenGLShader::ProcessShader(const std::string& source)
	{
		return false;
	}

	void OpenGLShader::CompileShader(const std::string& shaderSource)
	{

	}
}