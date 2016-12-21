#include <iostream>

using namespace std;


class Matrix {

	private:
		int M;
		int N;

		int A[][];

	public:
		
		int get_cols() const;
		int get_rows() const;

		vector<int[]> get_row_vectors const;
		vector<int[]> get_col_vectors const;

		Matrix dot(Matrix &B)

