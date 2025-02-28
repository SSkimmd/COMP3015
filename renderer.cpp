#include "renderer.hpp"

Renderer::Renderer(int screen_width, int screen_height) {
    SetSize(screen_width, screen_height);
}

void Renderer::Render(Scene* scene) {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(int i = 0; i < scene->GetObjects().size(); i++) {
        auto* obj = scene->GetObject(i);

        if(obj->IsHidden()) continue;
        obj->Render();
    }
}
