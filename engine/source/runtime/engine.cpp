

#include "engine.h"



void TewiEngine::initialize(){}

void TewiEngine::clear()
{

}



void TewiEngine::run()
{


}


void TewiEngine::logicTick(float delta_time)
{

}

void TewiEngine::rendererTick(float delta_time)
{

}




void TewiEngine::startEngine()
{

}


float TewiEngine::calculateDeltaTime()
{
    float delta_time;
    {
        using namespace std::chrono;
        steady_clock::time_point tick_time_point = steady_clock::now();
        duration<float> time_span = duration_cast<duration<float>>(tick_time_point - m_last_tick_time_point);

        delta_time = time_span.count();

        m_last_tick_time_point = tick_time_point;
    }
    return delta_time;

}




































