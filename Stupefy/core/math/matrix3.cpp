/****************************************************************************/
/*  matrix3.cpp                                                             */
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


#include "Core/Math/Matrix3.h"

namespace Stupefy
{
	matrix3::matrix3()
	{
		for (int i = 0; i < 9; i++)
		{
			matrixData[i] = 0.0f;
		}

		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	};

	matrix3::~matrix3(){}

	matrix3::matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8)
	{
		matrixData[0] = m0;
		matrixData[3] = m3;
		matrixData[6] = m6;

		matrixData[1] = m1;
		matrixData[4] = m4;
		matrixData[7] = m7;

		matrixData[2] = m2;
		matrixData[5] = m5;
		matrixData[8] = m8;
	}

	matrix3& matrix3::operator=(const matrix3& val)
	{
		for (int i = 0; i < 9; i++)
		{
			matrixData[i] = val.matrixData[i];
		}

		return *this;
	}

	const matrix3 matrix3::operator+(const matrix3& m)
	{
		matrix3 n;

		n.matrixData[0] = matrixData[0] + m.matrixData[0];
		n.matrixData[3] = matrixData[3] + m.matrixData[3];
		n.matrixData[6] = matrixData[6] + m.matrixData[6];
		
		n.matrixData[1] = matrixData[1] + m.matrixData[1];
		n.matrixData[4] = matrixData[4] + m.matrixData[4];
		n.matrixData[7] = matrixData[7] + m.matrixData[7];

		n.matrixData[2] = matrixData[2] + m.matrixData[2];
		n.matrixData[5] = matrixData[5] + m.matrixData[5];
		n.matrixData[8] = matrixData[8] + m.matrixData[8];

		return n;
	}

	const matrix3 matrix3::operator*(const float s)
	{
		matrix3 n;

		n.matrixData[0] = matrixData[0] * s;
		n.matrixData[3] = matrixData[3] * s;
		n.matrixData[6] = matrixData[6] * s;

		n.matrixData[1] = matrixData[1] * s;
		n.matrixData[4] = matrixData[4] * s;
		n.matrixData[7] = matrixData[7] * s;

		n.matrixData[2] = matrixData[2] * s;
		n.matrixData[5] = matrixData[5] * s;
		n.matrixData[8] = matrixData[8] * s;

		return n;
	}

	const matrix3 matrix3::operator*(const matrix3& m)
	{
		return matrix3(
			matrixData[0] * m.matrixData[0] + matrixData[3] * m.matrixData[1] + matrixData[6] * m.matrixData[2],
			matrixData[0] * m.matrixData[3] + matrixData[3] * m.matrixData[4] + matrixData[6] * m.matrixData[5],
			matrixData[0] * m.matrixData[6] + matrixData[3] * m.matrixData[7] + matrixData[6] * m.matrixData[8],

			matrixData[1] * m.matrixData[0] + matrixData[4] * m.matrixData[1] + matrixData[7] * m.matrixData[2],
			matrixData[1] * m.matrixData[3] + matrixData[4] * m.matrixData[4] + matrixData[7] * m.matrixData[5],
			matrixData[1] * m.matrixData[6] + matrixData[4] * m.matrixData[7] + matrixData[7] * m.matrixData[8],

			matrixData[2] * m.matrixData[0] + matrixData[5] * m.matrixData[1] + matrixData[8] * m.matrixData[2],
			matrixData[2] * m.matrixData[3] + matrixData[5] * m.matrixData[4] + matrixData[8] * m.matrixData[5],
			matrixData[2] * m.matrixData[6] + matrixData[5] * m.matrixData[7] + matrixData[8] * m.matrixData[8]);
	}

	const vector3 matrix3::operator*(const vector3& v)
	{
		return vector3(
			matrixData[0] * v.x + matrixData[3] * v.y + matrixData[6] * v.z,
			matrixData[1] * v.x + matrixData[4] * v.y + matrixData[7] * v.z,
			matrixData[2] * v.x + matrixData[5] * v.y + matrixData[8] * v.z);
	}

	void matrix3::operator+=(const matrix3& m)
	{
		matrixData[0] += m.matrixData[0];
		matrixData[3] += m.matrixData[3];
		matrixData[6] += m.matrixData[6];

		matrixData[1] += m.matrixData[1];
		matrixData[4] += m.matrixData[4];
		matrixData[7] += m.matrixData[7];

		matrixData[2] += m.matrixData[2];
		matrixData[5] += m.matrixData[5];
		matrixData[8] += m.matrixData[8];
	}

	void matrix3::operator*=(const float s)
	{
		matrixData[0] *= s;
		matrixData[3] *= s;
		matrixData[6] *= s;

		matrixData[1] *= s;
		matrixData[4] *= s;
		matrixData[7] *= s;

		matrixData[2] *= s;
		matrixData[5] *= s;
		matrixData[8] *= s;
	}

	void matrix3::operator*=(const matrix3& m)
	{
		float data1;
		float data2;
		float data3;

		data1 = matrixData[0] * m.matrixData[0] + matrixData[3] * m.matrixData[1] + matrixData[6] * m.matrixData[2];
		data2 = matrixData[0] * m.matrixData[3] + matrixData[3] * m.matrixData[4] + matrixData[6] * m.matrixData[5];
		data3 = matrixData[0] * m.matrixData[6] + matrixData[3] * m.matrixData[7] + matrixData[6] * m.matrixData[8];

		matrixData[0] = data1;
		matrixData[3] = data2;
		matrixData[6] = data3;

		data1 = matrixData[1] * m.matrixData[0] + matrixData[4] * m.matrixData[1] + matrixData[7] * m.matrixData[2];
		data2 = matrixData[1] * m.matrixData[3] + matrixData[4] * m.matrixData[4] + matrixData[7] * m.matrixData[5];
		data3 = matrixData[1] * m.matrixData[6] + matrixData[4] * m.matrixData[7] + matrixData[7] * m.matrixData[8];

		matrixData[1] = data1;
		matrixData[4] = data2;
		matrixData[7] = data3;

		data1 = matrixData[2] * m.matrixData[0] + matrixData[5] * m.matrixData[1] + matrixData[8] * m.matrixData[2];
		data2 = matrixData[2] * m.matrixData[3] + matrixData[5] * m.matrixData[4] + matrixData[8] * m.matrixData[5];
		data3 = matrixData[2] * m.matrixData[6] + matrixData[5] * m.matrixData[7] + matrixData[8] * m.matrixData[8];

		matrixData[2] = data1;
		matrixData[5] = data2;
		matrixData[8] = data3;
	}

	const vector3 matrix3::transformVectorByMatrix(const vector3& v)
	{
		return (*this) * v;
	}

	void matrix3::setIdentityMatrix()
	{
		for (int i = 0; i < 9; i++)
		{
			matrixData[i] = 0.0f;
		}

		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	}

	void matrix3::setInverseOfMatrix(const matrix3& m)
	{
		float data1 = m.matrixData[0] * m.matrixData[4];
		float data2 = m.matrixData[0] * m.matrixData[7];
		float data3 = m.matrixData[3] * m.matrixData[1];
		float data4 = m.matrixData[6] * m.matrixData[1];
		float data5 = m.matrixData[3] * m.matrixData[2];
		float data6 = m.matrixData[6] * m.matrixData[2];

		float determinent = (
			data1 * m.matrixData[8] - data2 * m.matrixData[5] - data3 * m.matrixData[8] + data4 * m.matrixData[5] + data5 * m.matrixData[7] - data6 * m.matrixData[4]);

		if (determinent == 0.0) return;

		float invd = 1.0f / determinent;

		float m0 = (m.matrixData[4] * m.matrixData[8] - m.matrixData[7] * m.matrixData[5]) * invd;
		float m3 = -(m.matrixData[3] * m.matrixData[8] - m.matrixData[6] * m.matrixData[5]) * invd;

		float m6 = (m.matrixData[3] * m.matrixData[7] - m.matrixData[6] * m.matrixData[4]) * invd;

		float m1 = -(m.matrixData[1] * m.matrixData[8] - m.matrixData[7] * m.matrixData[2]) * invd;

		float m4 = (m.matrixData[0] * m.matrixData[8] - data6) * invd;

		float m7 = -(data2 - data4) * invd;

		float m2 = (m.matrixData[1] * m.matrixData[5] - m.matrixData[4] * m.matrixData[2]) * invd;

		float m5 = -(m.matrixData[0] * m.matrixData[5] - data5) * invd;

		float m8 = (data1 - data3) * invd;

		matrixData[0] = m0;
		matrixData[3] = m3;
		matrixData[6] = m6;

		matrixData[1] = m1;
		matrixData[4] = m4;
		matrixData[7] = m7;

		matrixData[2] = m2;
		matrixData[5] = m5;
		matrixData[8] = m8;
	}

	const matrix3 matrix3::getInverse()
	{
		matrix3 result;
		result.setInverseOfMatrix(*this);
		return result;
	}

	void matrix3::invertMatrix()
	{
		setInverseOfMatrix(*this);
	}

	const float matrix3::getDeterminent()
	{
		float data1 = matrixData[0] * matrixData[4];
		float data2 = matrixData[0] * matrixData[7];
		float data3 = matrixData[3] * matrixData[1];
		float data4 = matrixData[6] * matrixData[1];
		float data5 = matrixData[3] * matrixData[2];
		float data6 = matrixData[6] * matrixData[2];
	
		float determinent = (
			data1 * matrixData[8] - data2 * matrixData[5] - data3 * matrixData[8] + data4 * matrixData[5] + data5 * matrixData[7] - data6 * matrixData[4]);

		return determinent;
	}

	void matrix3::setTransposeMatrix(const matrix3& m)
	{
		matrixData[0] = m.matrixData[0];
		matrixData[3] = m.matrixData[1];
		matrixData[6] = m.matrixData[2];

		matrixData[1] = m.matrixData[3];
		matrixData[4] = m.matrixData[4];
		matrixData[7] = m.matrixData[5];

		matrixData[2] = m.matrixData[6];
		matrixData[5] = m.matrixData[7];
		matrixData[8] = m.matrixData[8];
	}

	const matrix3 matrix3::getTranspose(const matrix3& m)
	{
		matrix3 result;
		result.setTransposeMatrix(*this);
		return result;
	}

	void matrix3::invertAndTranspose()
	{
		float determinent = matrixData[0] * (matrixData[4] * matrixData[8] - matrixData[5] * matrixData[7]) - matrixData[3] * (matrixData[1] * matrixData[8] - matrixData[2] * matrixData[7]) + matrixData[6] * (matrixData[1] * matrixData[5] - matrixData[2] * matrixData[4]);

		matrix3 transpose;

		transpose.matrixData[0] = matrixData[0];
		transpose.matrixData[1] = matrixData[3];
		transpose.matrixData[2] = matrixData[6];

		transpose.matrixData[3] = matrixData[1];
		transpose.matrixData[4] = matrixData[4];
		transpose.matrixData[5] = matrixData[7];

		transpose.matrixData[6] = matrixData[2];
		transpose.matrixData[7] = matrixData[5];
		transpose.matrixData[8] = matrixData[8];

		float m11, m12, m13, m21, m22, m23, m31, m32, m33;

		m11 = +(transpose.matrixData[4] * transpose.matrixData[8] - transpose.matrixData[5] * transpose.matrixData[7]) / determinent;
		m12 = -(transpose.matrixData[1] * transpose.matrixData[8] - transpose.matrixData[2] * transpose.matrixData[7]) / determinent;
		m13 = +(transpose.matrixData[1] * transpose.matrixData[5] - transpose.matrixData[2] * transpose.matrixData[4]) / determinent;

		m21 = -(transpose.matrixData[3] * transpose.matrixData[8] - transpose.matrixData[5] * transpose.matrixData[6]) / determinent;
		m22 = +(transpose.matrixData[0] * transpose.matrixData[8] - transpose.matrixData[2] * transpose.matrixData[6]) / determinent;
		m23 = -(transpose.matrixData[0] * transpose.matrixData[5] - transpose.matrixData[2] * transpose.matrixData[3]) / determinent;

		m31 = +(transpose.matrixData[3] * transpose.matrixData[7] - transpose.matrixData[4] * transpose.matrixData[6]) / determinent;
		m32 = -(transpose.matrixData[0] * transpose.matrixData[7] - transpose.matrixData[1] * transpose.matrixData[6]) / determinent;
		m33 = +(transpose.matrixData[0] * transpose.matrixData[4] - transpose.matrixData[1] * transpose.matrixData[3]) / determinent;

		matrix3 preResult;

		preResult.matrixData[0] = m11;
		preResult.matrixData[1] = m21;
		preResult.matrixData[2] = m31;

		preResult.matrixData[3] = m12;
		preResult.matrixData[4] = m22;
		preResult.matrixData[5] = m32;

		preResult.matrixData[6] = m13;
		preResult.matrixData[7] = m23;
		preResult.matrixData[8] = m33;

		matrixData[0] = preResult.matrixData[0];
		matrixData[1] = preResult.matrixData[3];
		matrixData[2] = preResult.matrixData[6];

		matrixData[3] = preResult.matrixData[1];
		matrixData[4] = preResult.matrixData[4];
		matrixData[5] = preResult.matrixData[7];

		matrixData[6] = preResult.matrixData[2];
		matrixData[7] = preResult.matrixData[5];
		matrixData[8] = preResult.matrixData[8];
	}

	void matrix3::matrixRotateXByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		(*this).setIdentityMatrix();

		matrix3 m(
			1.0, 0.0, 0.0,
			0.0, cos(uAngle), -sin(uAngle),
			0.0, sin(uAngle), cos(uAngle));

		*this = m * (*this);
	}

	void matrix3::matrixRotateYByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);
		(*this).setIdentityMatrix();

		matrix3 m(
			cos(uAngle), 0.0, sin(uAngle),
			0.0, 1.0, 0.0,
			-sin(uAngle), 0.0, cos(uAngle));

		*this = m * (*this);
	}

	void matrix3::matrixRotateZByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);
		(*this).setIdentityMatrix();

		matrix3 m(
			cos(uAngle), -sin(uAngle), 0.0,
			sin(uAngle), cos(uAngle), 0.0,
			0.0, 0.0, 1.0);

		*this = m * (*this);
	}

	void matrix3::matrixTransformXByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		matrix3 m(
			1.0, 0.0, 0.0,
			0.0, cos(uAngle), -sin(uAngle),
			0.0, sin(uAngle), cos(uAngle));

		*this = m * (*this);
	}

	void matrix3::matrixTransformYByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		matrix3 m(
			cos(uAngle), 0.0, sin(uAngle),
			0.0, 1.0, 0.0,
			-sin(uAngle), 0.0, cos(uAngle));

		*this = m * (*this);
	}

	void matrix3::matrixTransformZByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		matrix3 m(
			cos(uAngle), -sin(uAngle), 0.0,
			sin(uAngle), cos(uAngle), 0.0,
			0.0, 0.0, 1.0);

		*this = m * (*this);
	}

	void matrix3::show()
	{
		std::cout << "[" << matrixData[0] << "," << matrixData[3] << "," << matrixData[6] << "," << std::endl;
		std::cout << matrixData[1] << "," << matrixData[4] << "," << matrixData[7] << "," << std::endl;
		std::cout << matrixData[2] << "," << matrixData[5] << "," << matrixData[8] << "]" << std::endl;
	}
}