#include <iostream>
#include <vector>
using namespace std;
#include "smart_city.h"

int main()
{
	Hotel *temp;
	int input_int;
	string input_str;
	vector<City *> cities;
	vector<Hotel *> hotels;

	while (true)
	{
		cout << "---- Smart City - Menu ----" << endl;
		cout << "1- Books a hotel." << endl;
		cout << "2- Look for a hotel." << endl;
		cout << "3- Admin mode." << endl;
		cout << "option> ";
		cin >> input_int;

		switch (input_int)
		{
		case 1:
			if (hotels.size())
			{
				for (int hotel_id = 0; hotel_id < (int)hotels.size(); hotel_id++)
				{
					cout << (hotel_id + 1) << ". " << hotels.at(hotel_id)->name << endl;
				}
				cout << "Select a hotel: ";
				cin >> input_int;
				hotels.at(input_int - 1)->books();
				cout << "Hotel booked." << endl;
			}
			else
			{
				cout << "No hotel available." << endl;
			}
			break;
		case 2:
			if (hotels.size())
			{
				cout << "1- By city." << endl;
				cout << "2- By evaluation." << endl;
				cout << "option> ";
				cin >> input_int;

				switch (input_int)
				{
				case 1:
					for (int city_id = 0; city_id < (int)cities.size(); city_id++)
					{
						cout << cities.at(city_id)->name << endl;

						for (int hotel_id = 0; hotel_id < (int)hotels.size(); hotel_id++)
						{
							if (cities.at(city_id) == hotels.at(hotel_id)->city)
							{
								cout << '\t' << hotels.at(hotel_id)->name << endl;
							}
						}
					}
					break;
				case 2:
					for (int hotel_id = 0; hotel_id < (int)hotels.size(); hotel_id++)
					{
						for (int h_id = 0; h_id < (int)hotels.size(); h_id++)
						{
							if (hotels.at(hotel_id)->recommendations < hotels.at(h_id)->recommendations)
							{
								temp = hotels.at(hotel_id);
								hotels.at(hotel_id) = hotels.at(h_id);
								hotels.at(h_id) = temp;
							}
						}
					}
					for (int hotel_id = 0; hotel_id < (int)hotels.size(); hotel_id++)
					{
						cout << hotels.at(hotel_id)->name << ": " << hotels.at(hotel_id)->getEvaluation() << endl;
					}
					break;
				default:
					break;
				}
			}
			else
			{
				cout << "No hotel available." << endl;
			}
			break;
		case 3:
			cout << "---- Smart City - Admin Menu ----" << endl;
			cout << "1- Add city." << endl;
			cout << "2- Add hotel." << endl;
			cout << "option> ";
			cin >> input_int;

			switch (input_int)
			{
			case 1:
				cout << "Enter the name: ";
				cin >> input_str;
				cities.push_back(new City(input_str));
				cout << "City saved." << endl;
				break;
			case 2:
				if (cities.size())
				{
					for (int city_id = 0; city_id < (int)cities.size(); city_id++)
					{
						cout << (city_id + 1) << ". " << cities.at(city_id)->name << endl;
					}
					cout << "Select the city: ";
					cin >> input_int;
					cout << "Enter the name: ";
					cin >> input_str;
					hotels.push_back(new Hotel(input_str, 0, cities.at(input_int - 1)));
					cout << "Enter the price: ";
					cin >> input_int;
					hotels.front()->price = input_int;
					cout << "Hotel saved." << endl;
				}
				else
				{
					cout << "No city available." << endl;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
