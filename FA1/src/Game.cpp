#include "include/Game.hpp"
#include "include/Person.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>



std::string Game::getTitle()  {
    return this->title;
}

void Game::setTitle(std::string title) {
    this->title = title;
}

int Game::getReleaseDate() {
    return this->releaseDate;
}

void Game::setReleaseDate(int releaseDate) {
    this->releaseDate = releaseDate;
}

float Game::getOriginalPrice() {
    return this->originalPrice;
}

void Game::setOriginalPrice(float originalPrice) {
    this->originalPrice = originalPrice;
}

float Game::calculateCurrentPrice() {
    // game daalt met 30%
    double daling = 0.3;
    float currentPrice = originalPrice;

    // voor elk jaar dat is gedaald berekent hij de currentprice
    for (int i = releaseDate; i < 2023; i++) {
        currentPrice *= (1 - daling);
    }
    return currentPrice;
}


Game::Game(std::string title, int releaseDate, float originalPrice) {
    this->title = title;
    this->releaseDate = releaseDate;
    this->originalPrice = originalPrice;
}
