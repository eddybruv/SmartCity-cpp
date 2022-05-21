class City
{
public:
	string name;

	City(string name)
	{
		this->name = name;
	}
};

class Hotel
{
public:
	string name;
	unsigned int price;
	City *city;
	int recommendations;

	Hotel(string name, unsigned int price, City *city)
	{
		this->name = name;
		this->price = price;
		this->city = city;
		this->recommendations = 0;
	}

	void books()
	{
		this->recommendations++;
	}

	int getEvaluation()
	{
		int result = this->recommendations / 100;

		return (result > 5) ? 5 : result;
	}
};
