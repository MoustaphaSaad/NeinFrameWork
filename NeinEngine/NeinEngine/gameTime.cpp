#include"gameTime.h"

std::chrono::system_clock::time_point gameTime::m_epoch = std::chrono::high_resolution_clock::now();

double gameTime::m_delta=0.0;

double gameTime::getTime(){
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()-m_epoch).count()/1000000000.0;
}
double gameTime::getDelta(){
	return m_delta;
}
void gameTime::setDelta(double val){
	gameTime::m_delta = val;
}
const double gameTime::FRAME_CAP = 1000.0;