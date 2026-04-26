//
// Created by daksh beniwal on 29/03/26.
//

#ifndef ENTITY_H
#define ENTITY_H
#include "headers.h"

class Entity {
    public:
    // warrior sprite : wsprite/Player
       sf::Sprite wsprite;
       sf::Vector2f mpostion;
       sf::Vector2f mvelocity;

    //Entity constructor takes one argument texture of running animation
    //why it is nessecary to pass initializer in constructors, ans->because sprite need to be initailized because of white square bug
    //not the default constructor needed to be initailized manually in the child constructor
    Entity(sf::Texture& texRun) : wsprite(texRun) {}

    virtual ~Entity() = default;

    //virtuall function used by entity child to update their self separatly
    virtual void update(float dt)=0;

    //draw function draws to the given window
    virtual void draw(sf::RenderWindow& window) {
        window.draw(wsprite);
    }

    virtual float getDepth()const=0;
};

#endif //ENTITY_H