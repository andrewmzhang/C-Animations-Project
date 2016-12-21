#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vector {

	private:
		vector<double> v;
		int size;

	public:
		Vector(double *vector = NULL, int size = 0);
		//Vector(vector<double> &vector);

		int getSize() const;
		//double *getArray() const;
		//vector<double> getVector() const;
		string to_string() const;
};

int main() {
	

	double v[3];

	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	Vector vector(v, 3);
	v[0] = 10;

	cout << vector.to_string();


}
