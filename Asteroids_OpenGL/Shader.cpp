#include "Shader.h"
#include <sstream>
#include <fstream>
#include <string>
#include <glew.h>
#include <SDL.h>

Shader::Shader()
{

}

Shader::~Shader()
{

}

bool Shader::CompileShader(const std::string& fileName,
	GLenum  shaderType,
	GLuint& outShader)
{
	std::ifstream shaderFile(fileName);
	if (shaderFile.is_open())
	{
		std::stringstream sstream;
		sstream << shaderFile.rdbuf();
		std::string contents = sstream.str();
		const char* contentsChar = contents.c_str();

		outShader = glCreateShader(shaderType);
		glShaderSource(outShader, 1, &(contentsChar), nullptr);
		glCompileShader(outShader);

		if (!IsCompiled(outShader))
		{
			SDL_Log("Shader compilation failed : %s", fileName.c_str());
			return false;
		}
	}
	else
	{
		SDL_Log("Shader file not found : %s", fileName.c_str());
		return false;
	}
	return true;
}

bool Shader::IsCompiled(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		memset(buffer, 0, 512);

	}
}