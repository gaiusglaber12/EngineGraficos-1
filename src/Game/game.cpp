#include "game.h"

namespace GameXD
{
	Game::Game()
	{
		player = nullptr;
		shape = nullptr;
		shape2 = nullptr;
		tileMap = nullptr;
	}

	Game::~Game()
	{
	}

	void Game::Init()
	{
		player = new Player();
		player->Init(render, 1.f, "../res/Textures/player.png");
		
		
		GL::AtlasConfig atlas = GL::AtlasConfig(5, 1, 0, 0, 1, 5);

		tileMap = new Tilemap(render);
		tileMap->ImportTileMap("../res/Tiled/engine1_test.tmx", "../res/Textures/tileset.png");
		tileMap->SetSize(1.0f);
	}

	void Game::Update()
	{
		player->Update(input);
		tileMap->CheckCollision(player->GetSprite());
	}

	void Game::Draw()
	{
		tileMap->Draw();
		player->Draw();
	}

	void Game::DeInit()
	{
		if (player != nullptr)
		{
			player->DeInit();
			delete player;
			player = nullptr;
		}
		if (shape != nullptr)
		{
			shape->DeInit();
			delete shape;
			shape = nullptr;
		}
		if (shape2 != nullptr)
		{
			shape2->DeInit();
			delete shape2;
			shape2 = nullptr;
		}
		if (tileMap != nullptr)
		{
			tileMap->DeInit();
			delete tileMap;
			tileMap = nullptr;
		}
	}
}

