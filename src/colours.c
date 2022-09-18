/*
 *	A basic program to show off the
 *	named colours in raylib, as well
 *	as the available RGB colours.
 */

#include <raylib.h>

int main(void) {

	const int screenWidth = 800;
	const int screenHeight = 780; // 256 x 3

	// Gradient Square Settings
	const int otherColourVal = 0;
	const int alphaVal = 255;
	const int gradSquareSize = 256;

	// Palette Settings
	const int pltSquareSize = 30;
	const int pltGap = 25;
	const int pltTextX = pltSquareSize + pltGap;
	const int pltTextWidth = 100;
	const int pltTextSize = 16;
	const Color pltTextColor = BLACK;
	const int numColors = 26;

	Color colors[] = {
		LIGHTGRAY,
		GRAY,
		DARKGRAY,
		YELLOW,
		GOLD,
		ORANGE,
		PINK,
		RED,
		MAROON,
		GREEN,
		LIME,
		DARKGREEN,
		SKYBLUE,
		BLUE,
		DARKBLUE,
		PURPLE,
		VIOLET,
		DARKPURPLE,
		BEIGE,
		BROWN,
		DARKBROWN,
		WHITE,
		BLACK,
		BLANK,
		MAGENTA,
		RAYWHITE
	};

	char *names[] = {
		"Light Gray",
		"Gray",
		"Dark Gray",
		"Yellow",
		"Gold",
		"Orange",
		"Pink",
		"Red",
		"Maroon",
		"Green",
		"Lime",
		"Dark Green",
		"Sky Blue",
		"Blue",
		"Dark Blue",
		"Purple",
		"Violet",
		"Dark Purple",
		"Beige",
		"Brown",
		"Dark Brown",
		"White",
		"Black",
		"Transparent",
		"Magenta",
		"Ray White"
	};
	
	int sqXOffset = screenWidth - gradSquareSize;
	int sqYOffset = 0;

	InitWindow(screenWidth, screenHeight, "Raylib Colour Test");
	SetTargetFPS(60);

	// Main Loop
	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(RAYWHITE);

		// Draw Palette colours
		for (int i=0; i<numColors; i++) {
			Color col = colors[i];
			char *name = names[i];
			DrawText(name, pltTextX, i * pltSquareSize + 5, pltTextSize, pltTextColor);
			DrawRectangle(0, i*pltSquareSize, pltSquareSize, pltSquareSize, col);
		}

		// Draw R-G Gradient Square
		for (int y=0; y<gradSquareSize; y++) {
			for (int x=0; x<gradSquareSize; x++) {
				Color col = {x, y, otherColourVal, alphaVal};
				DrawPixel(x + sqXOffset, y + sqYOffset, col);
			}
		}
		sqYOffset += gradSquareSize;

		// Draw G-B Gradient Square
		for (int y=0; y<gradSquareSize; y++) {
			for (int x=0; x<gradSquareSize; x++) {
				Color col = {otherColourVal, x, y, alphaVal};
				DrawPixel(x + sqXOffset, y + sqYOffset, col);
			}
		}
		sqYOffset += gradSquareSize;

		// Draw R-B Gradient Square
		for (int y=0; y<gradSquareSize; y++) {
			for (int x=0; x<gradSquareSize; x++) {
				Color col = {x, otherColourVal, y, alphaVal};
				DrawPixel(x + sqXOffset, y + sqYOffset, col);
			}
		}
		sqYOffset = 0;
	
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
