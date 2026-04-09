#include <raylib.h>
#include <raymath.h>
#include "Player.hpp"

int	main(void)
{
	// Initialization
	// -------------------------------------------------------------------
	const int	screenWidth = 800;
	const int	screenHeight= 450;

	InitWindow(screenWidth, screenHeight, "Throwing Game Mechanics");

	Player		player;
	Rectangle	object = {(float)GetScreenWidth()/5, 350, 30, 50};

	bool	collision = false;

	SetTargetFPS(60);
	// -------------------------------------------------------------------

	// Main game loop
	while(!WindowShouldClose())
	{
		//Update 
		//------------------------------------------------------------
		if (IsKeyDown(KEY_RIGHT))
			player.setPosition(1.0f);
		if (IsKeyDown(KEY_LEFT)) 
			player.setPosition(-1.0f);
		if (IsKeyDown(KEY_DOWN))
			player.downArrowAction(collision);

		collision = checkCollisionRecs(player.getBody(), object);
		//------------------------------------------------------------

		// Draw
		// -----------------------------------------------------------
		BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawText("Move with [LEFT] and [RIGHT] arrow keys\n\n[ESC] to exit", 20, 20, 20, DARKGRAY);
			
			DrawRectangleLines((float)GetScreenWidth()/2 - 60, 50, 120, 180, BLACK);
			DrawRectangleRec(player.getBody(), BLACK);
			DrawRectangleRec(object , DARKGRAY);
		EndDrawing();
		// -----------------------------------------------------------
	}

	// De-Initialization
	// -------------------------------------------------------------------
	CloseWindow();
	// -------------------------------------------------------------------
	
	return (0);
}
