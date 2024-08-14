#include "runtime/function/render/render_system.h"

RenderSystem::~RenderSystem()
{
    triangle_app->cleanup();
}

void RenderSystem::initialize(RenderSystemInitInfo init_info)
{
    triangle_app->initVulkan();
}


void RenderSystem::tick(float delta_time)
{
    triangle_app->drawFrame();
}


































