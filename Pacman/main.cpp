#include <iostream>
#include <glad/glad.h>
#include <glad/glad.c>
#include <GLFW/glfw3.h>
#include <linmath.h>
#include "Define.hpp"
#include "Shader.hpp"
#include "Sprite.hpp"
#include "Vec2.hpp"
#include "Vec4.hpp"
#include "Loader.hpp"
#include "Player.hpp"
#include "Objects.hpp"
#include "LoadMap.hpp"
#include "Utility.hpp"
#include "Input.hpp"
#include "GameManager.hpp"

Input input;
Shader shader;

GLFWwindow* window;

std::unique_ptr<GameManager> gameManager;

GLuint playerId;
GLuint objectsId;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
int LibraryInit();
void SetUpBmp();
void ProcessInput();
void Draw();



//--------------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
    
    if(LibraryInit() == -1)
    {
        exit(EXIT_FAILURE);
    }
    
    shader.SetUp();
    
    SetUpBmp();
    
    gameManager = std::make_unique<GameManager>();
    
    int textureChangeTime = 15;
    
    while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
          glfwWindowShouldClose(window) == 0)
    {
        ProcessInput();
        
//        if(isMoveRight)
//        {
//            player->MoveHorizontal(+0.005f);
//            player->mStatus = Player::Type::RIGHT01;
//        }
//        else if(isMoveLeft)
//        {
//            player->MoveHorizontal(-0.005f);
//            player->mStatus = Player::Type::LEFT01;
//        }
//        else if(isMoveUp)
//        {
//            player->MoveVertical(+0.005f);
//            player->mStatus = Player::Type::UP01;
//        }
//        else if(isMoveDown)
//        {
//            player->MoveVertical(-0.005f);
//            player->mStatus = Player::Type::DOWN01;
//        }
        
        input.Update();
        input.ResetNow();
        
        Draw();
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
//--------------------------------------------------------------------------------



void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        input.mKeyStates[key].pressed = true;
    }
    else if(action == GLFW_RELEASE)
    {
        input.mKeyStates[key].pressed = false;
    }
}

int LibraryInit()
{
    std::cout << "Current directory is " << GetCurrentWorkingDir().c_str() << ".\n";
    
    if(!glfwInit())
    {
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Tetris", NULL, NULL);
    
    if(!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetErrorCallback(ErrorCallback);
    glfwSetKeyCallback(window, KeyCallback);
    
    glfwMakeContextCurrent(window);
    auto addr = (GLADloadproc)glfwGetProcAddress;
    gladLoadGLLoader(addr);
    glfwSwapInterval(1);
    
    return 0;
}

void SetUpBmp()
{
    playerId = LoadBmp("Pacman.bmp");
    objectsId = LoadBmp("Objects02.bmp");
}

void ProcessInput()
{
    
}

void Draw()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearDepth(1.0);
    
    gameManager->DrawMap(objectsId);
    gameManager->DrawPlayer(playerId);
}
