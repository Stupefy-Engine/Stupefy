/****************************************************************************/
/*  vector3.h                                                               */
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


#pragma once

#include "core/core_common.h"
#include "core/math/math_functions.h"

namespace Stupefy
{
	class vector3
	{
	public:
		float x, y, z;

		vector3();
		~vector3();
		vector3(float uX, float uY, float uZ);

		vector3(const vector3& v);
		vector3& operator=(const vector3& v);

		const vector3 operator+(const vector3& v);
		const vector3 operator-(const vector3& v);
		const vector3 operator*(const float s);
		const vector3 operator/(const float s);

		void operator+=(const vector3& v);
		void operator-=(const vector3& v);
		void operator*=(const float s);
		void operator/=(const float s);

		const float operator*(const vector3& v);
		const float dot(const vector3& v);
		float angle(const vector3& v);

		const vector3 operator%(const vector3& v);
		void operator%=(const vector3& v);
		const vector3 cross(const vector3& v);

		void conjugate();
		void normalize();
		void zero();
		void absolute();

		float magnitude();
		float magnitudeSquare();

		vector3 rotateVectorAboutAngleAndAxis(float uAngle, vector3& uAxis);

		void show();
		void negate();
	};
}