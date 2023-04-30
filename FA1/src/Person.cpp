#include "include/Game.hpp"
#include "include/Person.hpp"
#include <algorithm>
#include <iostream>


bool Person::buy(Game game) {
    float budget = this->getBudget();

    // kijkt of de gebruiker de game niet al heeft
    for (Game g : this->games) {
        if (g.getTitle() == game.getTitle()) {
            return false; 
        }
    }
    // kijkt of de gebruiker nog genoeg budget heeft om een game te kopen
    if (budget > game.calculateCurrentPrice()) {
        this->setBudget(budget - game.calculateCurrentPrice());
        this->addGame(game);
        return true;
    } else {
        return false; 
    }
}

bool Person::sell(Game game, Person& buyer) {
    // kijkt of de gebruiker de game heeft
    std::list<Game>::iterator it = std::find(games.begin(), games.end(), game);

    if (it != games.end()) {
        float price = game.calculateCurrentPrice();

        // als de koper genoeg budget heeft
        if (buyer.getBudget() >= price) {
            bool heeftGame = false;

            // kijkt of de koper de game al heeft
            for (auto& ownedGame : buyer.getGames()) {
                if (ownedGame.getTitle() == game.getTitle()) {
                    heeftGame = true;
                    break;
                }
            }
            if (heeftGame) {
                return false;
            }

            // Hier berekent die het budget van de koper en verkoper en voegt de games toe en verwijdert ze ook
            buyer.setBudget(buyer.getBudget() - price);
            this->setBudget(this->getBudget() + price);
            buyer.addGame(game);
            this->removeGame(game);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}


float Person::getBudget() {
    return this->budget;
}

void Person::setBudget(float budget) {
    this->budget = budget;
}

std::list<Game> Person::getGames() {
    return this->games;
}

void Person::setGames(std::list<Game> games) {
    this->games = games;
}

void Person::addGame(Game game) {
    this->games.push_back(game);
}

void Person::removeGame(Game game) {
    this->games.remove(game);
}

std::string Person::getName() {
    return this->name;
}

void Person::setName(std::string name) {
    this->name = name;
}

Person::Person(std::string name, float budget) {
    this->name = name;
    this->budget = budget;
}








