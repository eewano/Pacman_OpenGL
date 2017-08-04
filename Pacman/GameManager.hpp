#ifndef GameManager_hpp
#define GameManager_hpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "Vec2.hpp"
#include "Define.hpp"
#include "Objects.hpp"
#include "Player.hpp"

class GameManager
{
public:
    GameManager();
    ~GameManager();
    
public:
    void SetMap();
    void RestartGame();
    void Process();
    void DrawMap(const int id);
    void DrawPlayer(const int id);
    
public:
    std::stringstream ss;
    char mMapData[MAP_SIZE.y][MAP_SIZE.x + 1];
    std::unique_ptr<Objects> objects[MAP_SIZE.y][MAP_SIZE.x];
    std::unique_ptr<Player> player;
};

#endif /* GameManager_hpp */
