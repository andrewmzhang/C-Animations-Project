#include "Vector.h"
#include <sstream>
Vector::Vector(double *vector, int size) : v(size) {

	this->size = size;

	for (int i = 0; i < size; i++) {
		cout << "ehllo";
		v[i] = vector[i];
	}
	
}


int Vector::getSize() const {
	return size;
}

//double *Vector::getArray() const {
//	return v;
//}
/*
vector<double> Vector::getVector() const {
	vector<double> vector(size);

	for (int i = 0; i < size; i++) {
		vector[i] = v[i];
	}
	return vector;
}
*/

string Vector::to_string() const {
	cout << &v << endl;
	string s = "[";
	for (int i = 0; i < size; i++) {
		cout << v[i] << endl;
		cout << &this->v[i] << endl;
		
		ostringstream stream;
		stream << v[i];
		s += " " + stream.str();
		if (i != size-1)
			s += ",";
		
	}


	s += " ]\n";

	return s;
}
