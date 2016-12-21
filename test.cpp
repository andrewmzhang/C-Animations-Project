#include <iostream>

class A {
	public:
		  int i;
};

std::ostream& operator<<(std::ostream &strm, const A &a) {
	  return strm << "A(" << a.i << ")";
}

int main() {
	A x;
	x.i = 1;
	std::cout << x << std::endl;
}
