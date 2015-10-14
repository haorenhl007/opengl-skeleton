#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstdlib>

#include "Window.h"
#include "DebugUi.h"

int main(int argc, char *argv[])
{
	Window window = Window("OpenGL Skeleton", 1280, 720);
	DebugUi debugUi = DebugUi(window.getWindow());

	while (!window.isCloseRequested()) {

		// Poll inputs
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
				window.requestClose();
			}
		}

		// Clear
		window.clear();

		// 3D Render

		// 2D Render
		debugUi.prepare();
		debugUi.render();

		// Swap
		window.swap();
	}

	window.cleanUp();

	return EXIT_SUCCESS;
}