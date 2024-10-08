#pragma once

#include <chrono>

class TewiEngine
{

    friend class TewiEditor;
    static const float s_fps_alpha;

public:


    void startEngine();
    void closeEngine();

    void initialize();
    void clear();

    void run();

    bool tickOneFrame(float delta_time);

    int getFPS() const {return m_fps;}


protected:

    void logicTick(float delta_time);
    void rendererTick(float delta_time);

    void calculateFPS(float delta_time);

    float calculateDeltaTime();

protected:
    std::chrono::steady_clock::time_point m_last_tick_time_point {std::chrono::steady_clock::now()};

    float m_average_duration {0.f};
    int   m_frame_count {0};
    int m_fps {0};


};
