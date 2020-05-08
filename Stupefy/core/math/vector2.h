/****************************************************************************/
/*  vector2.h                                                               */
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
	class STUPEFY_API vector2
	{
	public:
		float x, y;

		vector2();
		~vector2();

		vector2(float uX, float uY);
		vector2(const vector2& v);

		vector2& operator =(const vector2& v);

		const vector2 operator+(const vector2& v);
		const vector2 operator-(const vector2& v);
		const vector2 operator*(const float s);
		const vector2 operator/(const float s);

		void operator+=(const vector2& v);
		void operator-=(const vector2& v);
		void operator*=(const float s);
		void operator/=(const float s);

		const float operator*(const vector2& v);
		const float dot(const vector2& v);

		void conjugate();
		void normalize();
		void zero();
		void absolute();

		float magnitude();
		float magnitudeSquare();

		void show();
	};
}