#include <raylib.h>
#include <raymath.h>

int	main(void)
{
	// Initialization
	// -------------------------------------------------------------------
	const int	screenWidth = 800;
	const int	screenHeight= 450;

	InitWindow(screenWidth, screenHeight, "Throwing Game Mechanics");

	Rectangle	playerRec = { (float)screenWidth/2-30, 300, 60, 80};

	SetTargetFPS(60);
	// -------------------------------------------------------------------

	// Main game loop
	while(!WindowShouldClose())
	{
		//Update 
		//------------------------------------------------------------
		if (IsKeyDown(KEY_RIGHT)) playerRec.x += 4.0f;
		if (IsKeyDown(KEY_LEFT)) playerRec.x -= 4.0f;

		//Limit player X position to inside the screen
		playerRec.x = Clamp(playerRec.x, 0, screenWidth - playerRec.width);
		//------------------------------------------------------------

		// Draw
		// -----------------------------------------------------------
		BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawText("Move with [LEFT] and [RIGHT] arrow keys\n\n[ESC] to exit", 20, 20, 20, DARKGRAY);
			
			DrawRectangleLines(screenWidth/2 - 60, 50, 120, 180, BLACK);
			DrawCircle(screenWidth/5, 350, 30, DARKGRAY);
		EndDrawing();
			DrawRectangleRec(playerRec, BLACK);
		// -----------------------------------------------------------
	}

	// De-Initialization
	// -------------------------------------------------------------------
	CloseWindow();
	// -------------------------------------------------------------------
	
	return (0);
}
