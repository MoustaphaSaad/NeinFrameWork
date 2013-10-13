#include"SDLUtil.h"
#include<SDL.h>

SDL_Window* SDLUtil::m_window=NULL;
SDL_GLContext SDLUtil::m_glContext;
bool SDLUtil::m_closed=false;

bool SDLUtil::SDLIsCloseRequested(){
	return SDLUtil::m_closed;
}

void SDLUtil::SDLSetIsWindowClosed(bool val){
	SDLUtil::m_closed=val;
}
void SDLUtil::SDLCreateWindow(const char*title, int x,int y,int width,int height,bool fullscreen){
	int mode=0;
	if(fullscreen)
		mode=SDL_WINDOW_FULLSCREEN;

	SDLUtil::m_window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_OPENGL|mode);
	SDLUtil::m_glContext = SDL_GL_CreateContext(SDLUtil::m_window);

}

void SDLUtil::SDLWindowFullscreen(bool val){
	int mode =0;
	if(val)
		mode=SDL_WINDOW_FULLSCREEN;
	else
		mode=0;

	SDL_SetWindowFullscreen(SDLUtil::m_window,mode);
}
void SDLUtil::SDLSwapBuffers(){
	SDL_GL_SwapWindow(SDLUtil::m_window);
}
void SDLUtil::SDLDestroyWindow(){
	SDL_GL_DeleteContext(SDLUtil::m_glContext);
	SDL_DestroyWindow(SDLUtil::m_window);
}
void SDLUtil::SDLSetMousePosition(int x,int y){
	SDL_WarpMouseInWindow(SDLUtil::m_window,x,y);
}