/****************************************************************************/
/*  Vector3.cpp                                                             */
/****************************************************************************/
/*                          This file is a part of:                         */
/*                              STUPEFY ENGINE                              */
/*                                                                          */
/****************************************************************************/
/*  Copyright[2020] Harshit Bargujar                                        */
/*                                                                          */
/*  Licensed under the Apache License, Version 2.0 (the "License");         */
/*  you may not use this file except in compliance with the License.        */
/*  You may obtain a copy of the License at                                 */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.*/
/*  See the License for the specific language governing permissions and     */
/*  limitations under the License.                                          */
/****************************************************************************/


#include "Core/Math/Vector3.h"

namespace Stupefy
{
	Vector3::Vector3() :x(0.0), y(0.0), z(0.0) {};

	Vector3::~Vector3() {}

	Vector3::Vector3(float uX, float uY, float uZ) :x(uX), y(uY), z(uZ) {}


	Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

	Vector3& Vector3::operator =(const Vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	const Vector3 Vector3::operator+(const Vector3& v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	const Vector3 Vector3::operator-(const Vector3& v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	const Vector3 Vector3::operator*(const float s)
	{
		return Vector3(x * s, y * s, z * s);
	}

	const Vector3 Vector3::operator/(const float s)
	{
		return Vector3(x / s, y / s, z / s);
	}

	void Vector3::operator +=(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	void Vector3::operator -=(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	void Vector3::operator *=(const float s)
	{
		x *= s;
		y *= s;
		z *= s;
	}

	void Vector3::operator /=(const float s)
	{
		x /= s;
		y /= s;
		z /= s;
	}

	const float Vector3::operator *(const Vector3& v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	const float Vector3::dot(const Vector3& v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	float Vector3::angle(const Vector3& v)
	{
		float theta;
		Vector3 u = v;
		Vector3 m = *this;
		theta = dot(u) / (m.magnitude() * u.magnitude());
		//theta = RadianToDegrees(acos(theta));      PI needed to be defined
		return theta;
	}

	const Vector3 Vector3::operator %(const Vector3& v)
	{
		return Vector3(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}

	void Vector3::operator %=(const Vector3& v)
	{
		*this = cross(v);
	}

	const Vector3 Vector3::cross(const Vector3& v)
	{
		return Vector3(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
	}

	void Vector3::conjugate()
	{
		x = -1 * x;
		y = -1 * y;
		z = -1 * z;
	}

	void Vector3::normalize()
	{
		float mag = std::sqrt(x * x + y * y + z * z);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;

			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;
		}
	}

	void Vector3::zero()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	void Vector3::absolute()
	{
		x = std::abs(x);
		y = std::abs(y);
		z = std::abs(z);
	}

	float Vector3::magnitude()
	{
		float magnitude = std::sqrt(x * x + y * y + z * z);
		return magnitude;
	}

	float Vector3::magnitudeSquare()
	{
		float magnitude = x * x + y * y + z * z;
		return magnitude;
	}
	/*
	Vector3 Vector3::rotateVectorAboutAngleAndAxis(float uAngle, Vector3& uAxis)
	{
		//TODO
	}
	*/
	void Vector3::show()
	{
		std::cout << " ( " << x << " , " << y << " , " << z << " ) " << std::endl;
	}

	void Vector3::negate()
	{
		x = -1 * x;
		y = -1 * y;
		z = -1 * z;
	}
}