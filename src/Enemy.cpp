//
// Created by daksh beniwal on 24/04/26.
//
#include "Enemy.h"

Enemy::Enemy(sf::Texture &texRunen, sf::Texture &texIdleen, sf::Texture &texAttacken, Map &gamemap): Entity(texRunen),texRunen(texRunen),texIdleen(texIdleen),texAttacken(texAttacken), aniEnemy(192, 192, 6, 0.09f),aniEnemyIdle(192, 192, 6, 0.09f),aniEnemyAttack(192, 192, 4, 0.09f),map(gamemap){
    wsprite.setTextureRect(aniEnemy.getFrameRect());
    wsprite.setPosition(sf::Vector2f(400, 400));
    wsprite.setScale(sf::Vector2f(1, 1));
    wsprite.setOrigin({96, 96});
}

void Enemy::update(float dt) {

    mvelocity=plyposition-wsprite.getPosition();

    float length = std::sqrt(mvelocity.x * mvelocity.x + mvelocity.y * mvelocity.y);
    mvelocity.x /= length;
    mvelocity.y /= length;
    float distanceRadius=3*64;

    if (length<=distanceRadius && distanceRadius> 96) {

        float speed = 150.f;
        mvelocity.x *= speed*dt;
        mvelocity.y *= speed*dt;

        sf::Vector2f pos = wsprite.getPosition();

        sf::Vector2f rpos = map.getGridPos(pos,mvelocity);

        if (mvelocity.x > 0) {
            wsprite.setScale({1, 1});
        } else if (mvelocity.x < 0) {
            wsprite.setScale({-1, 1});
        }

        wsprite.setPosition(rpos);
    }


    // checks if moving or not
    bool running = true;
    if (length>distanceRadius || length<=16) {
        running = false;
    } else {
        running = true;
    }


    if (attack()) {
        wsprite.setTexture(texAttacken);
        aniEnemyAttack.update(dt, 0);
        wsprite.setTextureRect(aniEnemyAttack.getFrameRect());
        healthen-=0.01;
    }
    else if (!running) {
        wsprite.setTexture(texIdleen);
        aniEnemyIdle.update(dt, 0);
        wsprite.setTextureRect(aniEnemyIdle.getFrameRect());
    }
    else {
        wsprite.setTexture(texRunen);
        aniEnemy.update(dt, 0);
        wsprite.setTextureRect(aniEnemy.getFrameRect());
    }
}

bool Enemy::attack() {
    mvelocity=plyposition-wsprite.getPosition();

    float length = std::sqrt(mvelocity.x * mvelocity.x + mvelocity.y * mvelocity.y);
    if (length<=32) {
        return true;
    }
    return false;
}
