#pragma once
#include <memory>

// #include "runtime/function/render/Triangle.h"
class HelloTriangleApplication;

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

    void tick(float delta_time);

private:

    std::shared_ptr<HelloTriangleApplication> triangle_app;

};

























