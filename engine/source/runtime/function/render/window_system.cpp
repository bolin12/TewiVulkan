#include "runtime/function/render/window_system.h"

#include "runtime/core/base/macro.h"

WindowSystem::~WindowSystem()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void WindowSystem::initialize(WindowCreateInfo create_info)
{
    if(!glfwInit())
    {
        return;
    }

    m_width = create_info.width;
    m_height = create_info.height;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_window = glfwCreateWindow(create_info.width, create_info.height, create_info.title, nullptr, nullptr);
    if(!m_window)
    {
        LOG_FATAL(__FUNCTION__, "failed to initialize GLFW");
        glfwTerminate();
        return;
    }

    glfwSetWindowUserPointer(m_window, this);
    glfwSetKeyCallback(m_window, keyCallback);

    glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
}


void WindowSystem::pollEvents() const
{
    glfwPollEvents();
}

void WindowSystem::setTitle(const char* title)
{
    glfwSetWindowTitle(m_window, title);
}

bool WindowSystem::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}


GLFWwindow* WindowSystem::getWindow() const
{
    return m_window;
}

std::array<int, 2> WindowSystem::getWindowSize() const
{
    return std::array<int, 2>({m_width, m_height});
}

