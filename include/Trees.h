//
// Created by daksh beniwal on 01/04/26.
//

#ifndef TREES_H
#define TREES_H
#include "Entity.h"
class Tree: public Entity {
    public:
    Animator aniTree;
    Tree(sf::Texture& texture);

    void update(float dt)override;
    float getDepth()const override {
        return wsprite.getPosition().y;
    }
};


#endif //TREES_H
