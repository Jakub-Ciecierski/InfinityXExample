#include <game_loop/game_loop.h>
#include <factory/render_object_factory.h>
#include <rendering/renderer.h>
#include <app_gui.h>


int main() {
    ifx::GameLoop game_loop(
            std::move(ifx::RenderObjectFactory().CreateRenderer()));
    auto gui = std::unique_ptr<AppGUI>(
            new AppGUI(game_loop.renderer()->window()->getHandle(),
                       game_loop.renderer()));
    game_loop.renderer()->SetGUI(std::move(gui));

    game_loop.renderer()->scene()->AddRenderObject(
            ifx::RenderObjectFactory().CreateFloor()
    );
    game_loop.renderer()->scene()->AddRenderObject(
            ifx::RenderObjectFactory().CreateNanosuitObject()
    );

    game_loop.Start();
}

