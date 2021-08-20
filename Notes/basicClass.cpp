#include <iostream>
#include <string>

class Restaurant {
	public:
		void SetName(std::string restaurantName) { this->name = restaurantName; }
		void SetRating(int userRating) { this->rating = userRating; }
		void print() { std::cout << "name " << this->name << "\nrating= " << this->rating << std::endl; }

private:
		std::string name;
		int rating;

};

int main() {

	Restaurant favLunchPlace;
	Restaurant favDinnerPlace;

	favLunchPlace.SetName("Central Deli");
	favLunchPlace.SetRating (5);



	favDinnerPlace.SetName("friends Cafe");
	favDinnerPlace.SetRating(8);

	favLunchPlace.print();
	favDinnerPlace.print();

	

	return 0;
};

