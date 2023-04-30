#include <ctime>
#include <iostream>
#include "include/Game.hpp"
#include "include/Person.hpp"
#include <iomanip>


int main()
{
    std::time_t result = std::time(NULL);
    std::cout << std::asctime(std::localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseDate1 = tm_local->tm_year + 1899; // 1 jaar geleden
    int releaseDate2 = tm_local->tm_year + 1898; // 2 jaar geleden
    
    Game g1("Just Cause 3", releaseDate1 , 49.98);
    Game g2("Need for Speed: Rivals", releaseDate2 , 45.99);
    Game g3("Need for Speed: Rivals", releaseDate2 , 45.99);
    
    Person p1("Eric", 200);
    Person p2("Hans", 55);
    Person p3("Arno", 185);

    // Hier zie je alle outputs van de gebruikers die iets proberen te kopen


    bool uitkomst0 = p1.buy(g1);
    if (uitkomst0) {
        std::cout << "p1 buys g1: success" << std::endl;
    } else {
        std::cout << "p1 buys g1: failed" << std::endl;
    }

    bool uitkomst1 = p1.buy(g2);
    if (uitkomst1) {
        std::cout << "p1 buys g2: success" << std::endl;
    } else {
        std::cout << "p1 buys g2: failed" << std::endl;
    }

    bool uitkomst2 = p1.buy(g3);
    if (uitkomst2) {
        std::cout << "p1 buys g3: success" << std::endl;
    } else {
        std::cout << "p1 buys g3: failed" << std::endl;
    }

    bool uitkomst3 = p2.buy(g2);
    if (uitkomst3) {
        std::cout << "p2 buys g2: success" << std::endl;
    } else {
        std::cout << "p2 buys g2: failed" << std::endl;
    }

    bool uitkomst4 = p2.buy(g1);
    if (uitkomst4) {
        std::cout << "p2 buys g1: success" << std::endl;
    } else {
        std::cout << "p2 buys g1: failed" << std::endl;
    }

    bool uitkomst5 = p3.buy(g3);
    if (uitkomst5) {
        std::cout << "p3 buys g3: success" << std::endl;
    } else {
        std::cout << "p3 buys g3: failed" << std::endl;
    }


    // Hier zie je alle outputs van de gebruikers na het kopen van spellen


    std::cout << "Eric's budget = " << p1.getBudget() << " and owns:" << std::endl;
    for (auto& game : p1.getGames()) {
        std::cout << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " << std::fixed << std::setprecision(2) << game.getOriginalPrice() << ", now: " << game.calculateCurrentPrice() << std::endl;
    }

    std::cout << "Hans's budget = " << p2.getBudget() << " and owns:" << std::endl;
    
    for (auto& game : p2.getGames()) {
        std::cout << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " << std::fixed << std::setprecision(2) << game.getOriginalPrice() << ", now: " << game.calculateCurrentPrice() << std::endl;
    }

    std::cout << "Arno's budget = " << p3.getBudget() << " and owns:" << std::endl;
    for (auto& game : p3.getGames()) {
        std::cout << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " << std::fixed << std::setprecision(2) << game.getOriginalPrice() << ", now: " << game.calculateCurrentPrice() << std::endl;
    }


    // Hier zie je alle outputs van het verkopen van games 

    bool verkoop1 = p1.sell(g1, p3);
    if (verkoop1) {
        std::cout << "p1 sells g1 to p3: success" << std::endl;
    } else {
        std::cout << "p1 sells g1 to p3: failed" << std::endl;
    }

    bool verkoop2 = p2.sell(g2, p3);
    if (verkoop2) {
        std::cout << "p2 sells g2 to p3: success" << std::endl;
    } else {
        std::cout << "p2 sells g2 to p3: failed" << std::endl;
    }

    bool verkoop3 = p2.sell(g1, p1);
    if (verkoop3) {
        std::cout << "p2 sells g1 to p1: success" << std::endl;
    } else {
        std::cout << "p2 sells g1 to p1: failed" << std::endl;
    }



    // Hier zie je alle outputs van de gebruikers na het verkopen

    std::cout << "Eric's budget = " << p1.getBudget() << " and owns:" << std::endl;

    for (auto& game : p1.getGames()) {
        std::cout << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " << std::fixed << std::setprecision(2) << game.getOriginalPrice() << ", now: " << game.calculateCurrentPrice() << std::endl;
    }

    std::cout << "Hans's budget = " << p2.getBudget() << " and owns:" << std::endl;
    
    for (auto& game : p2.getGames()) {
        std::cout << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " << std::fixed << std::setprecision(2) << game.getOriginalPrice() << ", now: " << game.calculateCurrentPrice() << std::endl;
    }

    std::cout << "Arno's budget = " << p3.getBudget() << " and owns:" << std::endl;

    for (auto& game : p3.getGames()) {
        std::cout << game.getTitle() << ", released " << game.getReleaseDate() << "; original price: " << std::fixed << std::setprecision(2) << game.getOriginalPrice() << ", now: " << game.calculateCurrentPrice() << std::endl;
    }

}

