#include "game.hpp"

Game::Game() {

}

Game::~Game() {

}


void Game::Start() {    
    GameObject* player = new GameObject();
    Shader shader = Shader("shaders/normals/normals.vs", "shaders/normals/normals.fs");
    player->CreateWithModel("models/backpack/backpack.obj", shader);
    player->AddComponent(new Player());
    player->SetName("player");
    player->SetPosition(glm::vec3(0.0f, 0.0f, -3.0f));
    SceneManager::get().AddObjectToScene(player);


    //GameObject* cube = new GameObject("textures/test_two.jpg");
    //cube->AddComponent(new Rotate(cube));
    //cube->AddComponent(new Move(cube));
    //cube->SetName("cube");
    //SceneManager::get().AddObjectToScene(cube);


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