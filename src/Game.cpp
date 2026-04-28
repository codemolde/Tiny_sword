//
// Created by daksh beniwal on 29/03/26.
//
#include "Game.h"


// Game constructor takes window as a initializer with private variable width and heigth in Game.h
Game::Game() : window(sf::VideoMode({width, height}), "River Valley") {
    //creates a dynamyic player with three animated textures as parameters

    map = new Map(mapTexture, watermap, waterFormmap);

    player = new Player(wTexRun, wTexIdle, wTexAttack, *map);

    enemy = new Enemy(wTexRunen, wTexIdleen, wTexAttacken, *map);

    tr = new Tree(tree);
}

Game::~Game() {
    //deletes the player in this disconstructor
    delete player;
    delete enemy;
    delete map;
    delete tr;
}

//run function run all the functions when the window is open
void Game::run() {
    while (window.isOpen()) {
        //process event checks if anyevent happens when the window is open like: closing window
        processEvents();

        //delta time for Animations in update function and player movement
        float dt = clock.restart().asSeconds();

        //update function updates all frames been generated
        update(dt);

        //render function draws every thing on the window and clears every frame an display it
        render();
    }
}

void Game::processEvents() {
    while (std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Game::render() {
    window.clear(sf::Color::Black);

    map->draw(window);


    renderQueue.clear();

    if (player->healthpy > 0) {
        renderQueue.push_back(player);
    }
    if (enemy->healthen > 0) renderQueue.push_back(enemy);
    renderQueue.push_back(tr);

    std::stable_sort(renderQueue.begin(), renderQueue.end(), [](const Entity *a, const Entity *b) {
        return a->getDepth() < b->getDepth();
    });

    for (Entity *e: renderQueue) {
        e->draw(window);
    }
    if (player->healthpy > 0) player->healthbarDraw(window);
    if (enemy->healthen > 0) enemy->healthbarDraw(window);


    window.display();
}

void Game::update(float dt) {
    player->update(dt);
    enemy->getPlayerpos(player->wsprite.getPosition());
    enemy->update(dt);
    map->updatemap(dt);
    tr->update(dt);
}
