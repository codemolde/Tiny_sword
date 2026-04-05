//
// Created by daksh beniwal on 01/04/26.
//
#include "Trees.h"

Tree::Tree(sf::Texture &texture):Entity(texture),aniTree(192,252,8,0.09f) {
    wsprite.setTextureRect(aniTree.getFrameRect());
    wsprite.setScale(sf::Vector2f(1.f,1.f));
    wsprite.setOrigin({96,192});
    wsprite.setPosition(sf::Vector2f(480,352));
}

void Tree::update(float dt) {
    aniTree.update(dt,0);
    wsprite.setTextureRect(aniTree.getFrameRect());
}
