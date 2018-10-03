#include <iostream>
using namespace std;

class Bus {     // Friend class should be declared in top
	public:
	void print();           // We will only provide declaration
};

void test();        // Global function

class Truck {
	private:
	int x;

	protected:
	int y;          // Can be accessed through drived class

	public:
	int z;

	friend class Bus;       //All member function will be friend (friend class)
	                        //Bus class is friend of Truck class, so bus can access all private and protected property of truck class

	//friend void Bus :: print();	//This will allow print funtion present in Bus class to access private property of Truck class.
	friend void test();

};

void Bus :: print() {       //Now we will provide defination
	Truck t;
	t.x = 10;
	t.y = 20;
	cout << t.x << " " << t.y << endl;
}

void test() {       // Global function
	// Access truck private
	Truck t;
	t.x = 10;
	t.y = 20;
	cout << t.x << " " << t.y << endl;

}

int main() {
	Bus b;
	b.print();
	test();
}

/*
   10 20
   10 20
 */
