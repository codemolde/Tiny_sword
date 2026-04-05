//
// Created by daksh beniwal on 29/03/26.
//

#ifndef ANIMATOR_H
#define ANIMATOR_H
#include "headers.h"
class Animator {
    private:
        float frameTime;
        float elapsedTime;
        int currentFrame;
        int frameCount;
        sf::IntRect frameRect;
    public:
        Animator(int width,int height,int framecount,float switchTime);

        void update(float deltaTime,int row);

    const sf::IntRect& getFrameRect() const;
};

#endif //ANIMATOR_H
