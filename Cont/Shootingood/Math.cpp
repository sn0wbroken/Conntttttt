#include "Math.h"
#include <numeric>

namespace VMath {
	Vector3D VectorLength(Vector3D vec)
	{
		Vector3D tmp;
		tmp.x = vec.x * vec.x;
		tmp.y = vec.y * vec.y;
		tmp.z = vec.z * vec.z;
		return tmp;
	}

	double Norm2(double _x, double _y)
	{
		return sqrt(_x * _x + _y * _y);
	}

	double sqrt(double s)
	{
		double x = s / 2.0; // Is there any better way to determine initial value?
		double last_x = 0.0; // the value one before the last step

		while (x != last_x) // until the difference is not significant
		{ // apply Babylonian method step
			last_x = x;
			x = (x + s / x) / 2.0;
		}

		return x;
	}

	Vector3D normalize(Vector3D vector)
	{
		float mag = 1 / Norm2(vector.x, vector.y);
		float _x = vector.x * mag;
		float _y = vector.y * mag;

		return Vector3D(VGet(_x, _y, 0));
	}

	Vector3D dot(Vector3D vector, Vector3D vector2)
	{
		float a[] = { vector.x,vector.y,vector.z };
		float b[] = { vector.x,vector.y,vector.z };
		std::inner_product(a, a + sizeof(a) / sizeof(a[0]), b, 0);
		return Vector3D();
	}
	Vector3D cross(Vector3D vector, Vector3D vector2)
	{
		Vector3D TempVector;
		TempVector.x = vector.y * vector2.z - vector.z * vector2.y;
		TempVector.y = vector.x * vector2.z - vector.z * vector2.x;
		TempVector.z = vector.x * vector2.y - vector.y * vector2.x;

		return TempVector;
	}
}