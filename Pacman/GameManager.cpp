#include "GameManager.hpp"

GameManager::GameManager()
{
    SetMap();
}

GameManager::~GameManager()
{
    
}

void GameManager::SetMap()
{
    std::ifstream ifs("Map.txt");
    
    if(ifs.fail())
    {
        std::cerr << "Map.txt" << " Read failure!\n";
        exit(EXIT_FAILURE);
    }
    
    for(int i = MAP_SIZE.y - 1; i >= 0; i--)
    {
        ifs.getline(mMapData[MAP_SIZE.y - 1 - i], MAP_SIZE.x + 1);
        
        for(int j = 0; mMapData[MAP_SIZE.y - 1 - i][j] != '\0'; j++)
        {
            switch(mMapData[MAP_SIZE.y - 1 - i][j])
            {
                case '.':
                    objects[i][j] = std::make_unique<Objects>(OBJECTS_SIZE, Vec2f{ MAP_POS.x + j * 0.1f, MAP_POS.y + i * 0.1f });
                    objects[i][j]->Update(Objects::Type::BLANK);
                    break;
                case '*':
                    objects[i][j] = std::make_unique<Objects>(OBJECTS_SIZE, Vec2f{ MAP_POS.x + j * 0.1f, MAP_POS.y + i * 0.1f });
                    objects[i][j]->Update(Objects::Type::WALL);
                    break;
                case 'e':
                    objects[i][j] = std::make_unique<Objects>(OBJECTS_SIZE, Vec2f{ MAP_POS.x + j * 0.1f, MAP_POS.y + i * 0.1f });
                    objects[i][j]->Update(Objects::Type::EGG);
                    break;
                case 'p':
                    objects[i][j] = std::make_unique<Objects>(OBJECTS_SIZE, Vec2f{ MAP_POS.x + j * 0.1f, MAP_POS.y + i * 0.1f });
                    objects[i][j]->Update(Objects::Type::BLANK);
                    
                    player = std::make_unique<Player>(PLAYER_SIZE, Vec2f{ MAP_POS.x + j * 0.1f, MAP_POS.y + i * 0.1f });
                    break;
                default:
                    std::cout << "Unknown symbol.\n";
                    break;
            }
        }
    }
}

void GameManager::RestartGame()
{
    
}

void GameManager::Process()
{
    
}

void GameManager::DrawMap(const int id)
{
    for(size_t i = 0; i < MAP_SIZE.y; i++)
    {
        for(size_t j = 0; j < MAP_SIZE.x; j++)
        {
            objects[i][j]->Draw(id);
        }
    }
}

void GameManager::DrawPlayer(const int id)
{
    player->Draw(id);
}
