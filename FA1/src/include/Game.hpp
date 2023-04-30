#pragma once
#include <string>
#include <list>




class Game {

private:
	std::string title;
	int releaseDate;
	float originalPrice;

public:
	bool operator==(const Game& other) const{ return title == other.title; }

	std::string getTitle();

	void setTitle(std::string title);

	int getReleaseDate();

	void setReleaseDate(int releaseDate);

	float getOriginalPrice();

	void setOriginalPrice(float originalPrice);

	float calculateCurrentPrice();

	Game(std::string title, int releaseDate, float originalPrice);
};



