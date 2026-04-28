//
// Created by daksh beniwal on 24/04/26.
//

#ifndef ENEMY_H
#define ENEMY_H
#include <Entity.h>
#include <Map.h>

class Enemy : public Entity {

private:
    sf::Texture &texRunen;
    sf::Texture &texIdleen;
    sf::Texture& texAttacken;
    Map &map;
    sf::Vector2f plyposition;

public:
    float healthen=health;
    //three different animation for player
    Animator aniEnemy;
    Animator aniEnemyIdle;
    Animator aniEnemyAttack;

    //player constructor takes three texture for three different animation in the Game.cpp
    Enemy(sf::Texture &texRunen, sf::Texture &texIdleen,sf::Texture& texAttacken,Map& gamemap);

    //using Entity virtual fuction to update player evry frame
    //override ?? still question,ans-> protect from creating its own new function instead of the parent virtual function
    void update(float dt) override;
    float getDepth()const override {
        return wsprite.getPosition().y;
    }
    void getPlayerpos(sf::Vector2f pos) {
        plyposition = pos;
    }
    bool attack();
};

#endif //ENEMY_H
