

#include "engine.h"

#include <string>

#include "runtime/function/global/global_context.h"
#include "runtime/function/render/window_system.h"
#include "runtime/core/base/macro.h"

void TewiEngine::initialize()
{

}

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
    g_runtime_global_context.startSystems();
    LOG_INFO("engine start");
}

void TewiEngine::closeEngine()
{

}


const float TewiEngine::s_fps_alpha = 1.0f / 100.0f;
void TewiEngine::calculateFPS(float delta_time)
{
    m_frame_count++;

    if (m_frame_count == 1)
    {
        m_average_duration = delta_time;
    }
    else
    {
        m_average_duration = m_average_duration * (1 - s_fps_alpha) + delta_time * s_fps_alpha;
    }

    m_fps = static_cast<int>(1.f / m_average_duration);
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



bool TewiEngine::tickOneFrame(float delta_time)
{
    rendererTick(delta_time);
    calculateFPS(delta_time);

    g_runtime_global_context.m_window_system->pollEvents();

    g_runtime_global_context.m_window_system->setTitle(
        std::string("TewiEngine - " + std::to_string(getFPS()) + "FPS").c_str());

    const bool should_window_close = g_runtime_global_context.m_window_system->shouldClose();

    return !should_window_close;

}
































