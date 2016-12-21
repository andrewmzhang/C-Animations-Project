#include <string>
using namespace std;

class circle {

	private:
		double radius;
		string color;

	public:

		circle(double radius = 1, string color = "red");
		double getRadius() const;
		void setRadius(double radius);
		string getColor() const;
		void setColor(string color);

		double getArea() const;
};
