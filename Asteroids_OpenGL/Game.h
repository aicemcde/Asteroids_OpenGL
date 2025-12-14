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
	class Scene* GetScene() const { return mScene.get(); }
	class ResourceManager* GetResourceManager() const { return mResourceManager.get(); }
	const Vector2& GetScreenSize() const { return mScreenSize; }
	void SetGameRunning(bool running) { mIsRunning = running; }
	void ScoreUpdate();
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();
	void UpdateAsteroid();
	

	static Game* sInstance;
	Vector2 mScreenSize;

	SDL_Window* mWindow = nullptr;
	bool mIsRunning = false;
	SDL_GLContext mContext;

	std::unique_ptr<class VertexArray> mSpriteVerts = nullptr;
	std::unique_ptr<class Shader> mSpriteShader = nullptr;

	std::unique_ptr<class Scene> mScene;
	std::unique_ptr<class ResourceManager> mResourceManager;
	class Score* mScorePtr = nullptr;

	Uint32 mTicksCount;
	const int mNumAsteroid = 23;
};