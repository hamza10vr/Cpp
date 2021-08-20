#include <iostream>
#include <string>

class Restaurant {
	public:
		void SetName(std::string restaurantName) { this->name = restaurantName; }
		void SetRating(int userRating) { this->rating = userRating; }
		void print();

	private:
		std::string name;
		int rating;

};

int main() {

	std::cout << "hello world\n";

	return 0;
};

