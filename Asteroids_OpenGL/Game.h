#pragma once
#include "Math.h"
#include <SDL.h>
#include <glew.h>
#include <memory>
#include <vector>

class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	static Game& Get() { return *sInstance; }

	void InitSpriteVerts();
	bool LoadShaders();
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	static Game* sInstance;
	Vector2 mScreenSize;

	SDL_Window* mWindow = nullptr;
	bool mIsRunning = false;
	SDL_GLContext mContext;

	std::unique_ptr<class VertexArray> mSpriteVerts = nullptr;
	std::unique_ptr<class Shader> mSpriteShader = nullptr;

	std::vector<class SpriteComponent*> mSprites;
	std::unique_ptr<class SpriteComponent> mSpriteComp;
};