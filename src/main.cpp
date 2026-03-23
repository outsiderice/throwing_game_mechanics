#include <raylib.h>

int	main(void)
{
	const int	screenWidth = 800;
	const int	screenHeight= 450;

	InitWindow(screenWidth, screenHeight, "Throwing Game Mechanics");

	SetTargetFPD(60);

	while(!WindowShouldClose())
	{
		//Update vars here
		//-------------------

		//-------------------
		// Draw
		// ------------------
		BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawText("Hello world", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
		// ------------------
	}

	CloseWindow();
}
