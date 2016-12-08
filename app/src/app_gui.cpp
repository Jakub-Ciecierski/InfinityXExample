#include <rendering/renderer.h>
#include <engine_gui/factory/engine_gui_factory.h>
#include <engine_gui/engine_gui.h>
#include <gui/imgui/imgui.h>

#include "app_gui.h"

AppGUI::AppGUI(GLFWwindow* window,
               std::shared_ptr<ifx::Renderer> renderer) :
    ifx::GUI(window){
    engine_gui_ = ifx::EngineGUIFactory().CreateEngineGUI(renderer);
}

AppGUI::~AppGUI(){}

void AppGUI::Render(){
    NewFrame();

    engine_gui_->Render();

    ImGui::Render();
}

