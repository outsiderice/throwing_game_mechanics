#include <raylib.h>

int	main(void)
{
	// Initialization
	// -------------------------------------------------------------------
	const int	screenWidth = 800;
	const int	screenHeight= 450;

	InitWindow(screenWidth, screenHeight, "Throwing Game Mechanics");

	Vector2	playerPosition = { (float)screenWidth/2, 300};
	Vector2	playerSize = { 60, 80};

	SetTargetFPS(60);
	// -------------------------------------------------------------------

	// Main game loop
	while(!WindowShouldClose())
	{
		//Update 
		//------------------------------------------------------------
		if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 4.0f;
		if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 4.0f;
		//------------------------------------------------------------

		// Draw
		// -----------------------------------------------------------
		BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawText("Move with [LEFT] and [RIGHT] arrow keys", 20, 20, 20, DARKGRAY);
			
			DrawRectangleV(playerPosition, playerSize, BLACK);
		EndDrawing();
		// -----------------------------------------------------------
	}

	// De-Initialization
	// -------------------------------------------------------------------
	CloseWindow();
	// -------------------------------------------------------------------
	
	return (0);
}
