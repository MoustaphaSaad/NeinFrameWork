#ifndef GAMETIME
#define GAMETIME
#include<chrono>
class gameTime{
public : 
	const static double FRAME_CAP;
	static double getTime();
	static double getDelta();
	static void setDelta(double val);
private:
	static double m_delta;
	static std::chrono::system_clock::time_point m_epoch;
};
#endif