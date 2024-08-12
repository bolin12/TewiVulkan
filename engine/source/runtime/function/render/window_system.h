#pragma once

#include <vector>
#include <GLFW/glfw3.h>

#include <functional>
#include <array>

struct WindowCreateInfo
{
    int width {1920};
    int height {1080};
    const char * title{"TewiEngine"};
    bool is_fullscreen{false};
};

class WindowSystem
{

public:
    WindowSystem() = default;
    ~WindowSystem();

    void                initialize(WindowCreateInfo create_info);
    void                pollEvents() const;
    bool                shouldClose() const;
    void                setTitle(const char * title);
    GLFWwindow*         getWindow() const;
    std::array<int, 2>  getWindowSize() const;




    typedef std::function<void()>           onResetFunc;
    typedef std::function<void(int, int, int, int)> onKeyFunc;


    void registerOnResetFunc(onResetFunc func){m_onResetFunc.push_back(func);}
    void registerOnResetFunc(onKeyFunc func){m_onKeyFunc.push_back(func);}



protected:

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if(app)
        {
            app->onKey(key, scancode, action, mods);
        }
    }


    void onReset()
    {
        for(auto& func: m_onResetFunc)
            func();
    }

    void onKey(int key, int scancode, int action, int mods)
    {
        for(auto& func: m_onKeyFunc)
            func(key, scancode, action, mods);
    }



private:


    GLFWwindow* m_window {nullptr};
    int m_width{0};
    int m_height{0};

    std::vector<onResetFunc>      m_onResetFunc;
    std::vector<onKeyFunc>        m_onKeyFunc;


};
