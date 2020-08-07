#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	cout << "Hello, Welcome to Frank's Carpet Cleaning Service" << endl;

	int small_rooms {0};
	cout << "How many small rooms would you like cleaned? ";
	cin >> small_rooms;

	int large_rooms {0};
	cout << "How many large rooms would you like cleaned? ";
	cin >> large_rooms;

	const unsigned short price_small_rooms {25};
	const unsigned short price_large_rooms {35};
	const float tax {0.06};
	cout << "\nEstimates for service" << endl;
	cout << "Price of Small Rooms: " << price_small_rooms << endl;
	cout << "Price of Large Rooms: " << price_large_rooms << endl;

	int cost {0};
	cost = (small_rooms * price_small_rooms) + (large_rooms * price_large_rooms);
	float total_cost {0};
	total_cost = cost + (cost * tax);

	cout << "Cost: " << cost << endl;
	cout << "Tax: " << tax << endl;
	cout << "=================" << endl;
	cout << "Total cost: " << total_cost << endl;

	const short total_days {30};
	cout << "Estimated days: " << total_days << endl;

	return 0;
}
