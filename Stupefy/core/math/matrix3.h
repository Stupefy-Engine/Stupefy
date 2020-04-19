/****************************************************************************/
/*  matrix3.h                                                               */
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

#include "core/math/math_functions.h"
#include "core/math/vector3.h"

namespace Stupefy
{
	class STUPEFY_API matrix3
	{
	public:

		float matrixData[9] = { 0.0 };

		matrix3();
		~matrix3();

		matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);
		matrix3& operator=(const matrix3& val);

		const matrix3 operator+(const matrix3& m);
		const matrix3 operator*(const float s);
		const matrix3 operator*(const matrix3& m);

		const vector3 operator*(const vector3& v);
		
		void operator+=(const matrix3& m);
		void operator*=(const float s);
		void operator*=(const matrix3& m);

		const vector3 transformVectorByMatrix(const vector3& v);

		void setIdentityMatrix();
		void setInverseOfMatrix(const matrix3& m);

		const matrix3 getInverse();
		void invertMatrix();
		const float getDeterminent();
		void setTransposeMatrix(const matrix3& m);
		const matrix3 getTranspose(const matrix3& m);
		void invertAndTranspose();

		void matrixRotateXByAngle(float uAngle);
		void matrixRotateYByAngle(float uAngle);
		void matrixRotateZByAngle(float uAngle);

		void matrixTransformXByAngle(float uAngle);
		void matrixTransformYByAngle(float uAngle);
		void matrixTransformZByAngle(float uAngle);

		void show();
	};
}