//
// Created by daksh beniwal on 29/03/26.
//

#ifndef GAME_H
#define GAME_H

#include "headers.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
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
    Enemy* enemy;
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
    sf::Texture &wTexRun=textures.getTexture("WarriorRun","assets/Units/Red Units/Warrior/Warrior_Run.png");
    sf::Texture &wTexIdle=textures.getTexture("WarriorIdle","assets/Units/Red Units/Warrior/Warrior_Idle.png");
    sf::Texture &wTexAttack=textures.getTexture("WarriorAttack","assets/Units/Red Units/Warrior/Warrior_Attack1.png");
    sf::Texture &mapTexture=textures.getTexture("Grass","assets/Terrain/Tileset/Tilemap_color1.png");
    sf::Texture &watermap=textures.getTexture("water","assets/Terrain/Tileset/Water Background color.png");
    sf::Texture &waterFormmap=textures.getTexture("waterForm","assets/Terrain/Tileset/Water Foam.png");
    sf::Texture &tree=textures.getTexture("Tree","assets/Terrain/Resources/Wood/Trees/Tree1.png");
    sf::Texture &wTexIdleen=textures.getTexture("enmeyIdle","assets/Units/Blue Units/Warrior/Warrior_Idle.png");
    sf::Texture &wTexRunen=textures.getTexture("enemyRun","assets/Units/Blue Units/Warrior/Warrior_Run.png");
    sf::Texture &wTexAttacken=textures.getTexture("enemyAttack","assets/Units/Blue Units/Warrior/Warrior_Attack2.png");
};

#endif //GAME_H