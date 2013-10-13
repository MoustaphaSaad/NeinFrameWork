#ifndef SDLUTIL
#define SDLUTIL
#include<SDL.h>
class SDLUtil{
public:
	static bool SDLIsCloseRequested();
	static void SDLSetIsWindowClosed(bool val);
	static void SDLCreateWindow(const char*title, int x,int y, int width,int height,bool fullscreen);
	static void SDLWindowFullscreen(bool val);
	static void SDLSwapBuffers();
	static void SDLDestroyWindow();
	static void SDLSetMousePosition(int x,int y);
private :
	static SDL_Window* m_window;
	static SDL_GLContext m_glContext;
	static bool m_closed;
};
#endif

