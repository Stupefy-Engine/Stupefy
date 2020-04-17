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
	class matrix3
	{
	public:

		F32 matrixData[9] = { 0.0 };

		matrix3();
		~matrix3();

		matrix3(F32 m0, F32 m3, F32 m6, F32 m1, F32 m4, F32 m7, F32 m2, F32 m5, F32 m8);
		matrix3& operator=(const matrix3& val);

		const matrix3 operator+(const matrix3& m);
		const matrix3 operator*(const F32 s);
		const matrix3 operator*(const matrix3& m);

		const vector3 operator*(const vector3& v);
		
		void operator+=(const matrix3& m);
		void operator*=(const F32 s);
		void operator*=(const matrix3& m);

		const vector3 transformVectorByMatrix(const vector3& v);

		void setIdentityMatrix();
		void setInverseOfMatrix(const matrix3& m);

		const matrix3 getInverse();
		void invertMatrix();
		const F32 getDeterminent();
		void setTransposeMatrix(const matrix3& m);
		const matrix3 getTranspose(const matrix3& m);
		void invertAndTranspose();

		void matrixRotateXByAngle(F32 uAngle);
		void matrixRotateYByAngle(F32 uAngle);
		void matrixRotateZByAngle(F32 uAngle);

		void matrixTransformXByAngle(F32 uAngle);
		void matrixTransformYByAngle(F32 uAngle);
		void matrixTransformZByAngle(F32 uAngle);

		void show();
	};
}