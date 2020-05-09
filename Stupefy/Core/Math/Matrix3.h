/****************************************************************************/
/*  Matrix3.h                                                               */
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

#include "Core/Math/MathFunctions.h"
#include "Core/Math/Vector3.h"

namespace Stupefy
{
	class STUPEFY_API Matrix3
	{
	public:

		float MatrixData[9] = { 0.0 };

		Matrix3();
		~Matrix3();

		Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);
		Matrix3& operator=(const Matrix3& val);

		const Matrix3 operator+(const Matrix3& m);
		const Matrix3 operator*(const float s);
		const Matrix3 operator*(const Matrix3& m);

		const Vector3 operator*(const Vector3& v);

		void operator+=(const Matrix3& m);
		void operator*=(const float s);
		void operator*=(const Matrix3& m);

		const Vector3 transformVectorByMatrix(const Vector3& v);

		void SetIdentityMatrix();
		void SetInverseOfMatrix(const Matrix3& m);

		const Matrix3 getInverse();
		void invertMatrix();
		const float getDeterminent();
		void SetTransposeMatrix(const Matrix3& m);
		const Matrix3 getTranspose(const Matrix3& m);
		void invertAndTranspose();

		void MatrixRotateXByAngle(float uAngle);
		void MatrixRotateYByAngle(float uAngle);
		void MatrixRotateZByAngle(float uAngle);

		void MatrixTransformXByAngle(float uAngle);
		void MatrixTransformYByAngle(float uAngle);
		void MatrixTransformZByAngle(float uAngle);

		void show();
	};
}