#include "common.h"

int main(int argc, char *argv[])
{
	Window window = Window("OpenGL Skeleton", 1280, 720);
	DebugUi debugUi = DebugUi(window.getWindow());

	ShaderProgram shader = ShaderProgram("../res/shaders/basicShader");

	Mesh mesh = Mesh("../res/models/box.obj");
	Texture texture = Texture("../res/models/box.jpg");

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
		mesh.render();

		// 2D Render
#ifdef _DEBUG 
		debugUi.prepare();
		debugUi.render();
#endif // _DEBUG 

		// Swap
		window.swap();
	}

	debugUi.cleanUp();
	window.cleanUp();

	return EXIT_SUCCESS;
}