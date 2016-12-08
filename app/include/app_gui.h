#ifndef PROJECT_APP_GUI_H
#define PROJECT_APP_GUI_H

#include <gui/gui.h>
#include <memory>

namespace ifx{
class Renderer;
class EngineGUI;
}

struct GLFWwindow;

class AppGUI : public ifx::GUI {
public:

    AppGUI(GLFWwindow* window,
           std::shared_ptr<ifx::Renderer> renderer);
    ~AppGUI();

    virtual void Render() override;
private:
    std::shared_ptr<ifx::EngineGUI> engine_gui_;
};


#endif //PROJECT_APP_GUI_H
