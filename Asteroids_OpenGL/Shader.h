#pragma once
#include <string>
#include <glew.h>

class Shader
{
public:
	Shader();
	~Shader();

	bool Load(const std::string& vertName,
		const std::string& fragName);

	void SetActive();

private:
	bool CompileShader(const std::string& fileName,
		GLenum shaderType, GLuint& outShader);
	bool IsCompiled(GLuint shader);
	bool IsValidProgaram();

	GLuint mVertexShader;
	GLuint mFragShader;
	GLuint mShaderProgram;
};