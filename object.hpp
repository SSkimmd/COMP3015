#pragma once

#include "shader.hpp"
#include "input.hpp"
#include "component.hpp"
#include "model.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "stb/stb_image.h"
#include <GLFW/glfw3.h>
#include <vector>

class GameObject {
public:
    GameObject(std::string textureFile);
    GameObject(std::vector<std::string> faces);
    GameObject* CreateWithModel(std::string modelFile, Shader shader, bool isFlipped);

    GameObject() = default;
    ~GameObject() = default;

    void LoadTexture(std::string textureFile);
    void LoadCubemap(std::vector<std::string> faces);

    void Render();
    void GameObject::Start() {
        for (int i = 0; i < components.size(); i++) {
            if (components[i]) {
                components[i]->Start();
            }
        }
    }

    void GameObject::Update(float deltaTime) {
        for (int i = 0; i < components.size(); i++) {
            if (components[i]) {
                components[i]->Update(deltaTime);
            }
        }
    }

    template <class T>
    T* GetComponent(int id) {
        if (id > components.size() - 1 || id < 0) return nullptr;

        Component* component = components[id];
        return dynamic_cast<T*>(component);
    }

    void RemoveComponent(int id) {
        components.erase(std::remove(components.begin(), components.end(), components[id]), components.end());
    }

    Component* AddComponent(Component* component) {
        components.push_back(component);
        return component;
    }

    std::vector<Component*> GetAllComponents() {
        return components;
    }

    void SetPosition(glm::vec3 position) {
        this->position = position;
    }

    glm::vec3 GetPosition() {
        return position;
    }

    glm::vec3 GetScale() {
        return scale;
    }

    void SetScale(glm::vec3 scale) {
        this->scale = scale;
    }

    glm::vec3 GetRotation() {
        return rotation;
    }

    void SetRotation(glm::vec3 rotation) {
        this->rotation = rotation;
    }

    bool SetHidden(bool hidden) {
        this->hidden = hidden;
        return this->hidden;
    }

    bool ToggleHidden() {
        hidden = !hidden;
        return hidden;
    }

    bool IsHidden() {
        return hidden;
    }

    int SetID(int ID) {
        this->ID = ID;
        return this->ID;
    }

    int GetID() {
        return ID;
    }

    std::string SetName(std::string name) {
        this->name = name;
        return this->name;
    }

    std::string GetName() {
        return name;
    }

    std::string SetType(std::string type) {
        this->type = type;
        return this->type;
    }

    std::string GetType() {
        return this->type;
    }

    Shader GetShader() {
        return shader;
    }
private:
    std::vector<Component*> components;
    
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);

    std::string name = "blank";
    std::string type = "";

    Shader shader;
    Shader light;
    Model model;

    bool IsLit = false;
    bool hidden = false;
    unsigned int ID = 0;
    unsigned int texture = 0;
    unsigned int VBO = 0, VAO = 0;
    unsigned int lightVAO = 0;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};