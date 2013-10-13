#ifndef GAME
#define GAME
class Game{
public:
	virtual void init(){}
	virtual void input(){}
	virtual void update(){}
	virtual void render(){}
};
#endif