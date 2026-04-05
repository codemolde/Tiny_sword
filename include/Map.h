//
// Created by daksh beniwal on 30/03/26.
//

#ifndef MAP_H
#define MAP_H
#include "headers.h"

class Map {
private:
    sf::Sprite smap;
    sf::Sprite smapform;
    sf::Texture &water;
    sf::Texture &texture;
    sf::Texture &waterForm;
    Animator animatorwaterform;


    int map[11][15];
    int mapform[11][15]{
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0}
    };

    float width = 64.f;

public:
    Map(sf::Texture &texture, sf::Texture &water, sf::Texture &waterForm);

    void draw(sf::RenderWindow &window);

    void updatemap(float dt);
};

#endif //MAP_H
