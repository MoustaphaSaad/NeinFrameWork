#ifndef WINDOWX
#define WINDOWX
#include<string>
#include"Game.h"
class Window{
public :
	static void create(int width,int height,const std::string& title);
	static void render();
	static void dispose();

	static bool isCloseRequested();
	static int getWidth();
	static int getHeight();
	static const std::string& getTitle();
	
	static void setFullScreen(bool val);

	Window(Game* x);
	~Window();

	void start();
	void stop();
	void setShowFrames(bool val);
	static void setGame(Game *g);
	static Game* getGame();
private:
	static int m_width,m_height;
	static std::string m_title;

	static Game* m_game;
	bool m_isRunning,m_showFrames;
	void run();
};
#endif