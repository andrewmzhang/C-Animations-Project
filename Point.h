#include <iostream>
#include <string>

using namespace std;

class Point {

	private:
		double x;
		double y;
		double z;

	public:
		// Constructor
		Point(double x = 0.0, double y = 0.0, double z = 0.0);

		// Getters and Setters
		double getX() const;
		double getY() const;
		double getZ() const;
	
		void setX(double value);
		void setY(double value);
		void setZ(double value);

		// Public member functions
		
};


int main() {

	cout << "Running Tests!!!" << endl;
	cout << "Testing Point: 1, 2, 3" << endl;
	Point p1(1, 2, 3);
	cout << "X: " << p1.getX() << endl
		<< "Y: " << p1.getY() << endl
		<< "Z: " << p1.getZ() << endl;

	cout << "Testing changing points" << endl;
	p1.setX(101.10);

	cout << p1.getX() << endl;
	
}
