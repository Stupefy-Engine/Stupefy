/****************************************************************************/
/*  vector2.cpp                                                             */
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


#include "core/math/vector2.h"

namespace Stupefy
{
	vector2::vector2() : x(0.0), y(0.0) {}

	vector2::~vector2() {}

	vector2::vector2(float uX, float uY) : x(uX), y(uY) {}

	vector2::vector2(const vector2& v) : x(v.x), y(v.y) {}

	vector2& vector2::operator=(const vector2& v)
	{
		x = v.x;
		y = v.x;
		return *this;
	}
	
	const vector2 vector2::operator+(const vector2& v)
	{
		return vector2(x + v.x, y + v.y);
	}

	const vector2 vector2::operator-(const vector2& v)
	{
		return vector2(x - v.x, y - v.y);
	}

	const vector2 vector2::operator*(const float s)
	{
		return vector2(x * s, y * s);
	}

	const vector2 vector2::operator/(const float s)
	{
		return vector2(x / s, y / s);
	}

	void vector2::operator+=(const vector2& v)
	{
		x += v.x;
		y += v.y;
	}
	void vector2::operator-=(const vector2& v)
	{
		x -= v.x;
		y -= v.y;
	}

	void vector2::operator*=(const float s)
	{
		x *= s;
		y *= s;
	}

	void vector2::operator/=(const float s)
	{
		x /= s;
		y /= s;
	}

	const float vector2::operator*(const vector2& v)
	{
		return (x * v.x + y * v.x);
	}

	const float vector2::dot(const vector2& v)
	{
		return (x * v.x + y * v.y);
	}

	void vector2::conjugate()
	{
		x = -1 * x;
		y = -1 * y;
	}

	void vector2::normalize()
	{
		float mag = sqrt(x * x + y * y);
		if (mag > 0.0f)
		{
			float oneOverMag = 1.0f / mag;
			x = x * oneOverMag;
			y = y * oneOverMag;
		}
	}

	void vector2::zero()
	{
		x = 0;
		y = 0;
	}

	void vector2::absolute()
	{
		x = abs(x);
		y = abs(y);
	}

	float vector2::magnitude()
	{
		float magnitude = std::sqrt(x * x + y * y);
		return magnitude;
	}

	float vector2::magnitudeSquare()
	{
		float magnitude = x * x + y * y;
		return magnitude;
	}

	void vector2::show()
	{
		std::cout << " ( " << x << " , " << y << " ) " << std::endl;
	}
}