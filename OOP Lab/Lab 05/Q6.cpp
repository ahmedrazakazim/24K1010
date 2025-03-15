#include <iostream>
using namespace std;

class GraphicsRenderEngine
{
public:
    GraphicsRenderEngine()
    {
        cout << "Graphics Rendering Engine has been initialized." << endl;
    }

    ~GraphicsRenderEngine()
    {
        cout << "Graphics Rendering Engine has been shut down." << endl;
    }
};

class InputHandler
{
public:
    InputHandler()
    {
        cout << "Input Handler has been initialized." << endl;
    }

    ~InputHandler()
    {
        cout << "Input Handler has been shut down." << endl;
    }
};

class PhysicsEngine
{
public:
    PhysicsEngine()
    {
        cout << "Physics Engine has been initialized." << endl;
    }

    ~PhysicsEngine()
    {
        cout << "Physics Engine has been shut down." << endl;
    }
};

class GameEngine
{
    GraphicsRenderEngine renderEngine;
    InputHandler input;
    PhysicsEngine physics;

public:
    GameEngine()
    {
        cout << "Game Engine has been initialized." << endl;
    }

    ~GameEngine()
    {
        cout << "Game Engine has been shut down." << endl;
    }
};

int main()
{
    GameEngine game;
    return 0;
}
