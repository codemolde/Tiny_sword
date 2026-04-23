//
// Created by daksh beniwal on 30/03/26.
//
#include "Map.h"

Map::Map(sf::Texture &texture, sf::Texture &water, sf::Texture &waterForm) : smap(texture), smapform(waterForm),
                                                                             water(water), texture(texture),
                                                                             waterForm(waterForm),
                                                                             animatorwaterform(192, 192, 16, .09f) {
    int layout[11][15]{
        {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13},
        {13, 3, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 13},
        {13, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13},
        {13, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13},
        {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13},
        {12, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13},
        {13, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13},
        {13, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13},
        {13, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 13},
        {13, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 13},
        {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13}

    };


    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            map[i][j] = layout[i][j];
        }
    }
}

void Map::draw(sf::RenderWindow &window) {

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            float xPos = j * width;
            float yPos = i * width;
            smap.setTexture(water);
            smap.setTextureRect({{0, 0}, {64, 64}});
            smap.setPosition({xPos, yPos});
            window.draw(smap);
        }
    }

    smapform.setOrigin({96, 96});
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            float xPos = j * width;
            float yPos = i * width;
            int tileId2 = mapform[i][j];

            switch (tileId2) {
                case 0: continue;
                case 1:
                    smapform.setTextureRect(animatorwaterform.getFrameRect());
                    smapform.setPosition({xPos + 32, yPos + 104});
                    break;
                case 2:
                    smapform.setTextureRect(animatorwaterform.getFrameRect());
                    smapform.setPosition({xPos + 32, yPos - 32});
                    break;
                case 3:
                    smapform.setTextureRect(animatorwaterform.getFrameRect());
                    smapform.setPosition({xPos + 98, yPos + 32});
                    break;
                case 4:
                    smapform.setTextureRect(animatorwaterform.getFrameRect());
                    smapform.setPosition({xPos - 32, yPos + 32});
                    break;
                case 5:
                    smapform.setTextureRect(animatorwaterform.getFrameRect());
                    smapform.setPosition({xPos + 32, yPos + 98});
                    break;
                default: continue;
            }
            window.draw(smapform);
        }
    }

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 15; j++) {
            float xPos = j * width;
            float yPos = i * width;
            int tileId = map[i][j];


            sf::IntRect textureRect;

            switch (tileId) {
                case 0: smap.setTexture(texture);
                    textureRect = {{64, 64}, {64, 64}};
                    break;
                case 1: smap.setTexture(texture);
                    textureRect = {{64 * 6, 64 * 2}, {64, 64}};
                    break;
                case 2: smap.setTexture(texture);
                    textureRect = {{64 * 5, 64 * 2}, {64, 64}};
                    break;
                case 3: smap.setTexture(texture);
                    textureRect = {{64 * 5, 0}, {64, 64}};
                    break;
                case 4: smap.setTexture(texture);
                    textureRect = {{64 * 7, 0}, {64, 64}};
                    break;
                case 5: smap.setTexture(texture);
                    textureRect = {{64 * 7, 64 * 2}, {64, 64}};
                    break;
                case 6: smap.setTexture(texture);
                    textureRect = {{64 * 5, 64}, {64, 64}};
                    break;
                case 7: smap.setTexture(texture);
                    textureRect = {{64 * 7, 64}, {64, 64}};
                    break;
                case 8: smap.setTexture(texture);
                    textureRect = {{64 * 6, 0}, {64, 64}};
                    break;
                case 9: smap.setTexture(texture);
                    textureRect = {{64 * 5, 64 * 5}, {64, 64}};
                    break;
                case 11: smap.setTexture(texture);
                    textureRect = {{64 * 7, 64 * 5}, {64, 64}};
                    break;
                case 12: smap.setTexture(texture);
                    textureRect = {{64 * 6, 64 * 5}, {64, 64}};
                    break;
                case 14: smap.setTexture(texture);
                    textureRect = {{0, 64 * 4}, {64, 64*2}};
                    break;
                case 10: smap.setTexture(texture);
                    textureRect = {{64 * 5, 64 * 3}, {64, 64}};
                    break;
                default: continue;
            }
            smap.setTextureRect(textureRect);
            smap.setPosition({xPos, yPos});
            window.draw(smap);
        }
    }
}

void Map::updatemap(float dt) {
    animatorwaterform.update(dt, 0);
}

sf::Vector2f Map::getGridPos(sf::Vector2f &pos,sf::Vector2f &movement) {

    float Tile=64.f;
    sf::Vector2f nextgridPos = pos + sf::Vector2f(movement.x, 0.f);

    int gridX = static_cast<int>(nextgridPos.x / Tile);
    int gridY = static_cast<int>(nextgridPos.y / Tile);

    if (gridY >= 0 && gridY < 30 && gridX >= 0 && gridX < 14) {
        if (map[gridY][gridX] == 0) {
            pos.x = nextgridPos.x;
        }
    }

    sf::Vector2f nextPosY = pos + sf::Vector2f(0.f, movement.y);

    gridX = static_cast<int>(pos.x / Tile);
    gridY = static_cast<int>(nextgridPos.y / Tile);

    if (gridY >= 0 && gridY < 30 && gridX >= 0 && gridX < 14) {
        if (map[gridY][gridX] == 0) {
            pos.y = nextPosY.y;
        }
    }

    return {pos.x, pos.y};
}
