#include <iostream>
#include <typeinfo>
#include <SFML/System.hpp>
using namespace std;
int main()
{
	cout << "Hello PacWoman" << endl;
	sf::Time time;
	time = sf::milliseconds(1500);
	auto TimeSec = time.asSeconds();
	cout << typeid(TimeSec).name() << endl
		 << TimeSec << endl;
	return EXIT_SUCCESS;
}
