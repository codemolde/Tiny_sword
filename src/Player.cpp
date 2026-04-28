//
// Created by daksh beniwal on 29/03/26.
//
#include "Player.h"

// so many initailizer woohh... ,?? why? needed that.
Player::Player(sf::Texture &texRun,sf::Texture& texIdle,sf::Texture& texAttack,Map& gamemap) : Entity(texRun),texRun(texRun),texIdle(texIdle),texAttack(texAttack), animator(192, 192, 6, 0.09f),animatorIdle(192, 192, 6, 0.09f),animatorAttack(192, 192, 4, 0.09f),map(gamemap) {
    wsprite.setTextureRect(animator.getFrameRect());
    wsprite.setPosition(sf::Vector2f(200, 200));
    wsprite.setScale(sf::Vector2f(1, 1));
    wsprite.setOrigin({96, 96});
}

void Player::update(float dt) {
    mvelocity = {0,0};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        mvelocity.y -= 1.f;
        wsprite.setScale({1, 1});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        mvelocity.y += 1.f;
        wsprite.setScale({-1, 1});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        mvelocity.x -= 1.f;
        wsprite.setScale({-1, 1});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        mvelocity.x += 1.f;
        wsprite.setScale({1, 1});
}

    //velocity normilizer
    if (mvelocity.x != 0 || mvelocity.y != 0) {
        float length = std::sqrt(mvelocity.x * mvelocity.x + mvelocity.y * mvelocity.y);
        mvelocity.x /= length;
        mvelocity.y /= length;

        float speed = 300.f;
        mvelocity.x *= speed*dt;
        mvelocity.y *= speed*dt;

        sf::Vector2f pos = wsprite.getPosition();

        sf::Vector2f rpos = map.getGridPos(pos,mvelocity);

        wsprite.setPosition(rpos);
    }


    // checks if moving or not
    bool running = true;
    if (mvelocity.x == 0 && mvelocity.y == 0) {
        running = false;
    } else {
        running = true;
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        wsprite.setTexture(texAttack);
        animatorAttack.update(dt, 0);
        wsprite.setTextureRect(animatorAttack.getFrameRect());
        healthpy-=0.02;
    }
    else if (!running) {
        wsprite.setTexture(texIdle);
        animatorIdle.update(dt, 0);
        wsprite.setTextureRect(animatorIdle.getFrameRect());
    }
    else {
        wsprite.setTexture(texRun);
        animator.update(dt, 0);
        wsprite.setTextureRect(animator.getFrameRect());
    }
}