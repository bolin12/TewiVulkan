#pragma once
#include <memory>



class WindowSystem;

struct RenderSystemInitInfo
{
    std::shared_ptr<WindowSystem> window_system;
};


class RenderSystem
{
public:
    RenderSystem() = default;
    ~RenderSystem();

    void initialize(RenderSystemInitInfo init_info);


};

























