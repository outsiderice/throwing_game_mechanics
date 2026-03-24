#include <raylib.h>

int	main(void)
{
	const int	screenWidth = 800;
	const int	screenHeight= 450;

	InitWindow(screenWidth, screenHeight, "Throwing Game Mechanics");

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		//Update vars here
		//-------------------

		//-------------------
		// Draw
		// ------------------
		BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawText("Our protagonist, the humble rectangle!", 20, 20, 20, DARKGRAY);
			
			DrawRectangle(screenWidth/4*2 - 40, 300, 80, 100, BLACK);
		EndDrawing();
		// ------------------
	}

	CloseWindow();
}
