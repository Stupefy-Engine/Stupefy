/****************************************************************************/
/*  Vector3.h                                                               */
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

#include "Core/CoreCommon.h"
#include "Core/Math/MathFunctions.h"

namespace Stupefy
{
	class Vector3
	{
	public:
		float x, y, z;

		Vector3();
		~Vector3();
		Vector3(float uX, float uY, float uZ);

		Vector3(const Vector3& v);
		Vector3& operator=(const Vector3& v);

		const Vector3 operator+(const Vector3& v);
		const Vector3 operator-(const Vector3& v);
		const Vector3 operator*(const float s);
		const Vector3 operator/(const float s);

		void operator+=(const Vector3& v);
		void operator-=(const Vector3& v);
		void operator*=(const float s);
		void operator/=(const float s);

		const float operator*(const Vector3& v);
		const float dot(const Vector3& v);
		float angle(const Vector3& v);

		const Vector3 operator%(const Vector3& v);
		void operator%=(const Vector3& v);
		const Vector3 cross(const Vector3& v);

		void conjugate();
		void normalize();
		void zero();
		void absolute();

		float magnitude();
		float magnitudeSquare();

		Vector3 rotateVectorAboutAngleAndAxis(float uAngle, Vector3& uAxis);

		void show();
		void negate();
	};
}