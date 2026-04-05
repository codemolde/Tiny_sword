//
// Created by daksh beniwal on 29/03/26.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include "headers.h"

class TextureManager {
private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture> > textures;

public:
    sf::Texture &getTexture(const std::string &name,const std::string &path) {
        auto it = textures.find(name);
        if (it != textures.end()) {
            return *(it->second);
        }

        auto newtexture = std::make_unique<sf::Texture>();
        if (!newtexture->loadFromFile(path)) {
            std::cerr << "Failed to load texture " << path << std::endl;
        }
        textures[name] = std::move(newtexture);
        return *textures[name];
    }
};

#endif //TEXTUREMANAGER_H
