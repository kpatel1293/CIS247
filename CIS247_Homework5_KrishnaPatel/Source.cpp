#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Class
//...Animal
class Animal
{
protected:
	int numLegs;
	string skinType;
	bool warmBlooded;
public:
	Animal() { numLegs = 0; skinType = "unknown"; if (warmBlooded == true) { warmBlooded = "warm-blooded"; } }
	Animal(int legs, string skin, bool blood) { numLegs = legs; skinType = skin; warmBlooded = blood; }
	void printInfo()
	{
		cout << "\n---------------------------------------------" << endl;
		if (warmBlooded == true)
			cout << "This is a warm - blooded animal with " << numLegs << " legs and a skin type of " << skinType << endl;
		else
			cout << "This is a cold - blooded animal with " << numLegs << " legs and a skin type of " << skinType << endl;
	}
};
//...Mammal
class Mammal : public Animal
{
protected:
	string reproType;
public:
	Mammal() : reproType("unknown") {}
	Mammal(int legs, string skin, bool blood, string rType) { numLegs = legs; skinType = skin; warmBlooded = blood; reproType = rType; }
	void setRepro(string type) { reproType = type; }
	string getRepro() { return reproType; }
	void printInfo()
	{
		Animal::printInfo();
		cout << "This mammal's reproduction type is " << reproType << endl;
	}
};
//...Bird
class Bird : public Animal
{
protected:
	bool flighted;
public:
	Bird() {}
	Bird(int legs, string skin, bool blood, bool flies) { numLegs = legs; skinType = skin; warmBlooded = blood; flighted = flies; }
	void setFlighted(bool flies) { flighted = flies; }
	bool getFlighted() { return flighted; }
	void printInfo()
	{
		Animal::printInfo();
		if (flighted == true)
			cout << "This is a flighted bird" << endl;
		else
			cout << "This is a flightless bird" << endl;
	}
};
//...Dog
class Dog : public Mammal
{
private:
	string breed;
	string name;
public:
	Dog() {}
	Dog(int legs, string skin, bool blood, string rType, string b, string nm) { numLegs = legs; skinType = skin; warmBlooded = blood; reproType = rType; breed = b; name = nm; }
	void setBreed(string b) { breed = b; }
	string getBreed() { return breed; }
	void setName(string nm) { name = nm; }
	string getName() { return name; }
	void printInfo()
	{
		Mammal::printInfo();
		cout << "This is a dog of the " << breed << " breed whose name is " << name << endl;
	}
};
//...Macaw
class Macaw : public Bird
{
private:
	string color;
	string name;
public:
	Macaw() {}
	Macaw(int legs, string skin, bool blood, bool flies, string clrs, string nm) { numLegs = legs; skinType = skin; warmBlooded = blood; flighted = flies; color = clrs; name = nm; }
	void setColor(string clrs) { color = clrs; }
	string getColor() { return color; }
	void setName(string nm) { name = nm; }
	string getName() { return name; }
	void printInfo()
	{
		Bird::printInfo();
		cout << "This a macaw colored " << color << " whose name is " << name << endl;
	}
};
//Main
int main()
{
	Dog dog(4, "fur", true, "placenta", "pug", "Happy");
	dog.printInfo();

	Macaw macaw(2, "feathers", true, true, "blue-and-gold", "Artie");
	macaw.printInfo();

	return 0;
}