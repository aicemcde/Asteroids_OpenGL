#pragma once
#include "Math.h"
#include <SDL.h>
#include <glew.h>
#include <memory>

class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	static Game& Get() { return *sInstance; }

	void InitSpriteVerts(unsigned int vertexBuffer, unsigned int indexBuffer);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	static Game* sInstance;
	Vector2 mScreenSize;

	SDL_Window* mWindow = nullptr;
	bool mIsRunning = false;
	SDL_GLContext mContext;

	std::unique_ptr<class VertexArray> mSpriteVerts = nullptr;
};