//
// Created by daksh beniwal on 29/03/26.
//
#include "Animator.h"

Animator::Animator(int width, int height, int framecount, float switchTime) {
    this->frameCount = framecount;
    this->frameTime = switchTime;
    this->currentFrame = 0;
    this->elapsedTime = 0.f;

    frameRect.size.x = width;
    frameRect.size.y = height;
    frameRect.position.x = 0;
    frameRect.position.y = 0; //rows
}

void Animator::update(float deltaTime, int row) {
        frameRect.position.y = row * frameRect.size.y;
        elapsedTime += deltaTime;
    if (elapsedTime >= frameTime) {
        elapsedTime -= frameTime;
        currentFrame++;
        if (currentFrame >= frameCount) {
            currentFrame = 0;
        }
    }
    frameRect.position.x = currentFrame * frameRect.size.x;
}

const sf::IntRect & Animator::getFrameRect() const {
    return frameRect;
}
