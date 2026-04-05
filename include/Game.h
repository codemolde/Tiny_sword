//
// Created by daksh beniwal on 29/03/26.
//

#ifndef GAME_H
#define GAME_H

#include "headers.h"
#include "TextureManager.h"
#include "Player.h"
#include "Map.h"
#include "Trees.h"

class Game{
private:
    unsigned int width=960;
    unsigned int height=704;
    sf::Clock clock;
    sf::RenderWindow window;
    TextureManager textures;
    Player* player;
    Map* map;
    Tree* tr;
    std::vector<Entity*> renderQueue;

public:
    Game();
    ~Game();
    void run();
    void processEvents();
    void render();
    void update(float dt);

    //Three textures for player animation in Player.cpp
    sf::Texture &wTexRun=textures.getTexture("WarriorRun","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Units/Red Units/Warrior/Warrior_Run.png");
    sf::Texture &wTexIdle=textures.getTexture("WarriorIdle","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Units/Red Units/Warrior/Warrior_Idle.png");
    sf::Texture &wTexAttack=textures.getTexture("WarriorAttack","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Units/Red Units/Warrior/Warrior_Attack1.png");
    sf::Texture &mapTexture=textures.getTexture("Grass","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Terrain/Tileset/Tilemap_color1.png");
    sf::Texture &watermap=textures.getTexture("water","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Terrain/Tileset/Water Background color.png");
    sf::Texture &waterFormmap=textures.getTexture("waterForm","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Terrain/Tileset/Water Foam.png");
    sf::Texture &tree=textures.getTexture("Tree","/Users/dakshbeniwal/codemolde/Tiny_sword/Tiny Swords (Free Pack)/Terrain/Resources/Wood/Trees/Tree1.png");
};

#endif //GAME_H