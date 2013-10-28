#include"Window.h"
#include"MyGame.h"
int main(int argc, char** argv){
	Window::create(800,600,"Moka");
	MyGame mine;
	Window x(&mine);
	x.setShowFrames(true);
	x.start();
    return 0;
}
