#include "game.h"

namespace GameXD
{
	Game::Game()
	{
		player = nullptr;
		shape = nullptr;
		shape2 = nullptr;
		fireplace = nullptr;
		tileMap = nullptr;
	}

	Game::~Game()
	{
	}

	void Game::Init()
	{
		player = new Player();
		player->Init(render, 1.f, "../res/Textures/player.png");
		
		fireplace = new Sprite(render);
		fireplace->Init();
		fireplace->LoadTexture("../res/Textures/bonfire.png", false);
		fireplace->SetPos(0.0f, 20.0f, 0.0f);
		fireplace->SetScale(50.f, 50.f, 50.0f);
		fireplace->SetCollider(true);
		GL::AtlasConfig atlas = GL::AtlasConfig(5, 1, 0, 0, 1, 5);
		fireplace->AddAnimation(atlas,10);

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
		fireplace->Draw();
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
		if (fireplace != nullptr)
		{
			fireplace->DeInit();
			delete fireplace;
			fireplace = nullptr;
		}
		if (tileMap != nullptr)
		{
			tileMap->DeInit();
			delete tileMap;
			tileMap = nullptr;
		}
	}
}

