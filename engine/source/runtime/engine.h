#pragma once

#include <chrono>

class TewiEngine
{

    friend class TewiEditor;

public:


    void startEngine();
    void closeEngine();

    void initialize();
    void clear();

    void run();


protected:

    void logicTick(float delta_time);
    void rendererTick(float delta_time);

    void calculateFPS(float delta_time);

    float calculateDeltaTime();

protected:
    std::chrono::steady_clock::time_point m_last_tick_time_point {std::chrono::steady_clock::now()};

    int m_frame_count {0};
    int m_fps {0};


};
