#include"input.h"
#include<SDL.h>
#include"SDLUtil.h"
bool* Input::inputs = new bool[256];
bool* Input::downKeys = new bool[256];
bool* Input::upKeys = new bool[256];

bool* Input::mouseInput = new bool[5];
bool* Input::downMouse = new bool[5];
bool* Input::upMouse = new bool[5];

static SDL_Event e;
static int mouseX=0;
static int mouseY=0;

void Input::update(){
	for(int i=0;i<5;i++){
		downMouse[i]=false;
		upMouse[i]=false;
	}
	for(int i=0;i<256;i++){
		downKeys[i]=false;
		upKeys[i]=false;
	}
	while(SDL_PollEvent(&e)){
		if(e.type == SDL_QUIT)
			SDLUtil::SDLSetIsWindowClosed(true);

		if(e.type == SDL_MOUSEMOTION){
			mouseX = e.motion.x;
			mouseY = e.motion.y;
		}
		if(e.type == SDL_KEYDOWN){
			int val = e.key.keysym.scancode;

			inputs[val]=true;
			downKeys[val] = true;
		}
		if(e.type == SDL_KEYDOWN){
			int val = e.key.keysym.scancode;

			inputs[val]=false;
			upKeys[val] = true;
		}
		if(e.type == SDL_MOUSEBUTTONDOWN){
			int val = e.button.button;

			mouseInput[val]=true;
			downMouse[val]=true;
		}
		if(e.type == SDL_MOUSEBUTTONUP){
			int val = e.button.button;

			mouseInput[val]=false;
			upMouse[val]=true;
		}

	}
}
bool Input::getKey(int keyCode){
	return inputs[keyCode];
}
bool Input::getKeyDown(int keyCode){
	return downKeys[keyCode];
}
bool Input::getKeyUp(int keyCode){
	return upKeys[keyCode];
}
bool Input::getMouse(int button){
	return mouseInput[button];
}
bool Input::getMouseDown(int button){
	return downMouse[button];
}
bool Input::getMouseUp(int button){
	return upMouse[button];
}
Vector2 Input::getMousePosition(){
	Vector2 res((float)mouseX,(float)mouseY);
	return res;
}
void Input::setCursor(bool val){
	if(val)
		SDL_ShowCursor(1);
	else
		SDL_ShowCursor(0);
}
void Input::setMousePosition(Vector2 pos){
	SDLUtil::SDLSetMousePosition((int)pos.x,(int)pos.y);
}