// InverseMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include <cmath>

template <typename T>
void inverse4(T *dst, const T *m)
{
	T m00 = m[0 * 4 + 0];
	T m01 = m[0 * 4 + 1];
	T m02 = m[0 * 4 + 2];
	T m03 = m[0 * 4 + 3];
	T m10 = m[1 * 4 + 0];
	T m11 = m[1 * 4 + 1];
	T m12 = m[1 * 4 + 2];
	T m13 = m[1 * 4 + 3];
	T m20 = m[2 * 4 + 0];
	T m21 = m[2 * 4 + 1];
	T m22 = m[2 * 4 + 2];
	T m23 = m[2 * 4 + 3];
	T m30 = m[3 * 4 + 0];
	T m31 = m[3 * 4 + 1];
	T m32 = m[3 * 4 + 2];
	T m33 = m[3 * 4 + 3];
	T tmp_0 = m22 * m33;
	T tmp_1 = m32 * m23;
	T tmp_2 = m12 * m33;
	T tmp_3 = m32 * m13;
	T tmp_4 = m12 * m23;
	T tmp_5 = m22 * m13;
	T tmp_6 = m02 * m33;
	T tmp_7 = m32 * m03;
	T tmp_8 = m02 * m23;
	T tmp_9 = m22 * m03;
	T tmp_10 = m02 * m13;
	T tmp_11 = m12 * m03;
	T tmp_12 = m20 * m31;
	T tmp_13 = m30 * m21;
	T tmp_14 = m10 * m31;
	T tmp_15 = m30 * m11;
	T tmp_16 = m10 * m21;
	T tmp_17 = m20 * m11;
	T tmp_18 = m00 * m31;
	T tmp_19 = m30 * m01;
	T tmp_20 = m00 * m21;
	T tmp_21 = m20 * m01;
	T tmp_22 = m00 * m11;
	T tmp_23 = m10 * m01;
	T t0 = (tmp_0 * m11 + tmp_3 * m21 + tmp_4 * m31) - (tmp_1 * m11 + tmp_2 * m21 + tmp_5 * m31);
	T t1 = (tmp_1 * m01 + tmp_6 * m21 + tmp_9 * m31) - (tmp_0 * m01 + tmp_7 * m21 + tmp_8 * m31);
	T t2 = (tmp_2 * m01 + tmp_7 * m11 + tmp_10 * m31) - (tmp_3 * m01 + tmp_6 * m11 + tmp_11 * m31);
	T t3 = (tmp_5 * m01 + tmp_8 * m11 + tmp_11 * m21) - (tmp_4 * m01 + tmp_9 * m11 + tmp_10 * m21);
	T b = m00 * t0 + m10 * t1 + m20 * t2 + m30 * t3;
	//std::cout << b <<" ";
	/*if (abs(b) < 0.00001)
	{
		return;
	}*/
	T d = static_cast<T>(1.0) / (m00 * t0 + m10 * t1 + m20 * t2 + m30 * t3);
	dst[0] = d * t0;
	dst[1] = d * t1;
	dst[2] = d * t2;
	dst[3] = d * t3;
	dst[4] =
		d * ((tmp_1 * m10 + tmp_2 * m20 + tmp_5 * m30) - (tmp_0 * m10 + tmp_3 * m20 + tmp_4 * m30));
	dst[5] =
		d * ((tmp_0 * m00 + tmp_7 * m20 + tmp_8 * m30) - (tmp_1 * m00 + tmp_6 * m20 + tmp_9 * m30));
	dst[6] = d * ((tmp_3 * m00 + tmp_6 * m10 + tmp_11 * m30) -
		(tmp_2 * m00 + tmp_7 * m10 + tmp_10 * m30));
	dst[7] = d * ((tmp_4 * m00 + tmp_9 * m10 + tmp_10 * m20) -
		(tmp_5 * m00 + tmp_8 * m10 + tmp_11 * m20));
	dst[8] = d * ((tmp_12 * m13 + tmp_15 * m23 + tmp_16 * m33) -
		(tmp_13 * m13 + tmp_14 * m23 + tmp_17 * m33));
	dst[9] = d * ((tmp_13 * m03 + tmp_18 * m23 + tmp_21 * m33) -
		(tmp_12 * m03 + tmp_19 * m23 + tmp_20 * m33));
	// crash on WASM if calculates dst[10]
	// return;
	dst[10] = d * ((tmp_14 * m03 + tmp_19 * m13 + tmp_22 * m33) -
		(tmp_15 * m03 + tmp_18 * m13 + tmp_23 * m33));
	dst[11] = d * ((tmp_17 * m03 + tmp_20 * m13 + tmp_23 * m23) -
		(tmp_16 * m03 + tmp_21 * m13 + tmp_22 * m23));
	dst[12] = d * ((tmp_14 * m22 + tmp_17 * m32 + tmp_13 * m12) -
		(tmp_16 * m32 + tmp_12 * m12 + tmp_15 * m22));
	dst[13] = d * ((tmp_20 * m32 + tmp_12 * m02 + tmp_19 * m22) -
		(tmp_18 * m22 + tmp_21 * m32 + tmp_13 * m02));
	dst[14] = d * ((tmp_18 * m12 + tmp_23 * m32 + tmp_15 * m02) -
		(tmp_22 * m32 + tmp_14 * m02 + tmp_19 * m12));
	dst[15] = d * ((tmp_22 * m22 + tmp_16 * m02 + tmp_21 * m12) -
		(tmp_20 * m12 + tmp_23 * m22 + tmp_17 * m02));
}

float matrix[16] = { 0.601815,
				0.0,
				-0.798636,
				0.0,
				0,
				1,
				0,
				0,
				0.798636,
				0.0,
				0.601815,
				0.0,
				-16.8509,
				0.0,
				-36.1449,
				1.0 };

float inversematrix[16];
int main()
{
	inverse4(inversematrix, matrix);
	/*for (int i = 0; i < 16; i++)
	{
		std::cout << inversematrix[i] << " ";
	}
	std::cout << std::endl;*/
    std::cout << "Success!\n"; 
}
