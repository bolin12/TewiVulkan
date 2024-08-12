#pragma once
#include <memory>

class LogSystem;
class WindowSystem;
class RenderSystem;


class RuntimeGlobalContext
{
public:
    void startSystems();

    void closeSystems();

public:

    std::shared_ptr<LogSystem>         m_logger_system;
    std::shared_ptr<WindowSystem>      m_window_system;
    std::shared_ptr<RenderSystem>      m_render_system;


};

extern RuntimeGlobalContext g_runtime_global_context;