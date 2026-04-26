//
// Created by daksh beniwal on 29/03/26.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Map.h"

class Map;

// inherits from entity class
class Player : public Entity {
    private:
    sf::Texture &texRun;
    sf::Texture &texIdle;
    sf::Texture& texAttack;
    Map &map;
public:

    //three different animation for player
    Animator animator;
    Animator animatorIdle;
    Animator animatorAttack;

    //player constructor takes three texture for three different animation in the Game.cpp
    Player(sf::Texture &texRun, sf::Texture &texIdle,sf::Texture& texAttack,Map& gamemap);

    //using Entity virtual fuction to update player evry frame
    //override ?? still question,ans-> protect from creating its own new function instead of the parent virtual function
    void update(float dt) override;
    float getDepth()const override {
        return wsprite.getPosition().y;
    }
};

#endif //PLAYER_H