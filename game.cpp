#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}


void Game::Start() {    
    GameObject* player = new GameObject();
    Shader shader = Shader("shaders/models/model.vs", "shaders/models/model.fs");
    player->CreateWithModel("models/backpack/backpack.obj", shader, true);
    player->AddComponent(new Player());
    //player->AddComponent(new Rotate(player));
    
    player->SetName("player");
    player->SetPosition(glm::vec3(2.0f, 0.0f, -3.0f));
    SceneManager::get().AddObjectToScene(player);

    GameObject* spider = new GameObject();
    Shader spiderShader = Shader("shaders/normals/normals.vs", "shaders/normals/normals.fs");
    spider->CreateWithModel("models/spider/Only_Spider_with_Animations_Export.obj", spiderShader, false);
    //player->AddComponent(new Rotate(player));
    spider->SetScale(glm::vec3(0.01f, 0.01f, 0.01f));
    spider->SetName("backpack_normals");
    spider->SetPosition(glm::vec3(0.0f, 0.0f, -200.0f));
    spider->AddComponent(new Rotate(spider));
    SceneManager::get().AddObjectToScene(spider);
    spider->SetHidden(true);

    std::vector<std::string> faces
    {
        "textures/skybox/right.jpg",
        "textures/skybox/left.jpg",
        "textures/skybox/top.jpg",
        "textures/skybox/bottom.jpg",
        "textures/skybox/front.jpg",
        "textures/skybox/back.jpg"
    };
    GameObject* skybox = new GameObject(faces);
    skybox->SetType("skybox");
    skybox->SetName("skybox");
    SceneManager::get().AddObjectToScene(skybox);
}