#ifndef LoadMap_h
#define LoadMap_h

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void LoadMap(const char* fileName)
{
    std::ifstream ifs(fileName);
    std::stringstream ss;
    char textMap[256];
    
    if(ifs.fail())
    {
        std::cerr << "Read failure!\n";
        return;
    }
    
    while(ifs.getline(textMap, 256 - 1))
    {
        for(int i = 0; textMap[i] != '\0'; i++)
        {
            
        }
    }
}

#endif /* LoadMap_h */
