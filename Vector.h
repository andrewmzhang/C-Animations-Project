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
		Vector(vector<double> &vector);

		int getSize() const;
		int get(int x) const;
		//double *getArray() const;
		//vector<double> getVector() const;
		Vector* dot(Vector &vector);
		string to_string() const;
};

int main() {
	

	double v[3];

	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	Vector vector_v(v, 3);
	v[0] = 10;

	cout << "1 2 3" << endl;
	cout << vector_v.to_string();

	vector<double> a(5);
	a[0] = 10;
	a[1] = 14;
	a[2] = 333;
	a[3] = 90;
	a[4] = 100;

	vector<double> b(5);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	b[3] = 4;
	b[4] = 5;

	Vector a_vector(a);
	Vector b_vector(b);
	Vector* result = a_vector.dot(b_vector);
	cout << result->to_string() << endl;
	delete result;


	return 0;

}
