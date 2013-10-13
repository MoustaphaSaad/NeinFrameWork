#include"Window.h"
#include<SDL.h>
#include<GL\glew.h>
#include"SDLUtil.h"
#include"RenderUtil.h"
#include"gameTime.h"
#include"input.h"

using namespace std;

int Window::m_height=0;
int Window::m_width=0;
string Window::m_title = "Title";
Game* Window::m_game=NULL;

Window::Window(Game* x){
	RenderUtil::initGraphics();
	m_isRunning = false;
	m_showFrames = true;
	Window::m_game = x;
}
Window::~Window(){
	Window::dispose();
}
void Window::stop(){
	if(!m_isRunning)
		return;
	m_isRunning=false;
}
void Window::start(){
	if(m_isRunning)
		return;
	this->m_game->init();
	run();
}
void Window::setShowFrames(bool val){
	m_showFrames = val;
}
void Window::run(){
	m_isRunning=true;

	const double frameTime = 1.0/gameTime::FRAME_CAP;
	double lastTime = gameTime::getTime();
	double unprocessedTime =0;
	double frameCounter=0;
	int frames=0;
	while(m_isRunning){
		bool render = false;
		double startTime = gameTime::getTime();
		double passedTime = startTime-lastTime;
		lastTime =startTime;

		unprocessedTime+=passedTime;
		frameCounter+=passedTime;

		if(frameCounter>=1.0){
			if(m_showFrames){
				printf("%i\n",frames);
				frames=0;
				frameCounter=0;
			}
		}
		while(unprocessedTime>frameTime){
			render = true;
			if(Window::isCloseRequested())
				m_isRunning=false;
			gameTime::setDelta(frameTime);

			Input::update();
			this->m_game->input();
			this->m_game->update();
			unprocessedTime-=frameTime;
		}
		if(render){
			RenderUtil::clearScreen();
			this->m_game->render();
			Window::render();
			frames++;
		}
		else
			SDL_Delay(1);
	}
}
void Window::create(int width,int height,const string& title){
	Window::m_height=height;
	Window::m_width=width;
	Window::m_title=title;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	SDLUtil::SDLCreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,false);

	GLenum res = glewInit();
	if(res != GLEW_OK)
		fprintf(stderr,"ERROR :%s \n",glewGetErrorString(res));

}

void Window::render(){
	SDLUtil::SDLSwapBuffers();
}
void Window::dispose(){
	SDLUtil::SDLDestroyWindow();
	SDL_Quit();
}

bool Window::isCloseRequested(){
	return SDLUtil::SDLIsCloseRequested();
}
void Window::setFullScreen(bool val){
	SDLUtil::SDLWindowFullscreen(val);
}
int Window::getWidth(){
	return Window::m_width;
}
int Window::getHeight(){
	return Window::m_height;
}
const std::string& Window::getTitle(){
	return Window::m_title;
}
void Window::setGame(Game *g){
	Window::m_game = g;
}
Game* Window::getGame(){
	return Window::m_game;
}