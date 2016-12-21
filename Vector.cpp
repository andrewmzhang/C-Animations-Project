#include "Vector.h"
#include <sstream>
#include <assert.h>
Vector::Vector(double *vector, int size) : v(size) {

	this->size = size;

	for (int i = 0; i < size; i++) {
		v[i] = vector[i];
	}
	
}

Vector::Vector(vector<double> &vector) : v(vector.size()) {
	
	this->size = vector.size();
	
	for (int i = 0; i < vector.size(); i++) {
		v[i] = vector[i];
	}
}


int Vector::getSize() const {
	return size;
}


int Vector::get(int x) const {
	return v[x];
}


//double *Vector::getArray() const {
//	return v;
//}

/*
vector<double> Vector::getVector() const {
	vector<double> vector(ddsize);

	for (int i = 0; i < size; i++) {
		vector[i] = v[i];
	}
	return vector;
}
*/



Vector* Vector::dot(Vector &vector_in) {
	assert(this->getSize() == vector_in.getSize());
	
	vector<double> vec(getSize());
	for(int i = 0; i < getSize(); i++) {
		vec[i] = this->v[i] * vector_in.get(i);
	}

	Vector* v =  new Vector(vec);

	return v;


}


string Vector::to_string() const {

	string s = "[";
	for (int i = 0; i < size; i++) {
		
		ostringstream stream;
		stream << v[i];
		s += " " + stream.str();
		if (i != size-1)
			s += ",";
		
	}


	s += " ]\n";

	return s;
}
