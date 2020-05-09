/****************************************************************************/
/*  Matrix3.cpp                                                             */
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
	Matrix3::Matrix3()
	{
		for (int i = 0; i < 9; i++)
		{
			MatrixData[i] = 0.0f;
		}

		MatrixData[0] = MatrixData[4] = MatrixData[8] = 1.0f;
	};

	Matrix3::~Matrix3() {}

	Matrix3::Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8)
	{
		MatrixData[0] = m0;
		MatrixData[3] = m3;
		MatrixData[6] = m6;

		MatrixData[1] = m1;
		MatrixData[4] = m4;
		MatrixData[7] = m7;

		MatrixData[2] = m2;
		MatrixData[5] = m5;
		MatrixData[8] = m8;
	}

	Matrix3& Matrix3::operator=(const Matrix3& val)
	{
		for (int i = 0; i < 9; i++)
		{
			MatrixData[i] = val.MatrixData[i];
		}

		return *this;
	}

	const Matrix3 Matrix3::operator+(const Matrix3& m)
	{
		Matrix3 n;

		n.MatrixData[0] = MatrixData[0] + m.MatrixData[0];
		n.MatrixData[3] = MatrixData[3] + m.MatrixData[3];
		n.MatrixData[6] = MatrixData[6] + m.MatrixData[6];

		n.MatrixData[1] = MatrixData[1] + m.MatrixData[1];
		n.MatrixData[4] = MatrixData[4] + m.MatrixData[4];
		n.MatrixData[7] = MatrixData[7] + m.MatrixData[7];

		n.MatrixData[2] = MatrixData[2] + m.MatrixData[2];
		n.MatrixData[5] = MatrixData[5] + m.MatrixData[5];
		n.MatrixData[8] = MatrixData[8] + m.MatrixData[8];

		return n;
	}

	const Matrix3 Matrix3::operator*(const float s)
	{
		Matrix3 n;

		n.MatrixData[0] = MatrixData[0] * s;
		n.MatrixData[3] = MatrixData[3] * s;
		n.MatrixData[6] = MatrixData[6] * s;

		n.MatrixData[1] = MatrixData[1] * s;
		n.MatrixData[4] = MatrixData[4] * s;
		n.MatrixData[7] = MatrixData[7] * s;

		n.MatrixData[2] = MatrixData[2] * s;
		n.MatrixData[5] = MatrixData[5] * s;
		n.MatrixData[8] = MatrixData[8] * s;

		return n;
	}

	const Matrix3 Matrix3::operator*(const Matrix3& m)
	{
		return Matrix3(
			MatrixData[0] * m.MatrixData[0] + MatrixData[3] * m.MatrixData[1] + MatrixData[6] * m.MatrixData[2],
			MatrixData[0] * m.MatrixData[3] + MatrixData[3] * m.MatrixData[4] + MatrixData[6] * m.MatrixData[5],
			MatrixData[0] * m.MatrixData[6] + MatrixData[3] * m.MatrixData[7] + MatrixData[6] * m.MatrixData[8],

			MatrixData[1] * m.MatrixData[0] + MatrixData[4] * m.MatrixData[1] + MatrixData[7] * m.MatrixData[2],
			MatrixData[1] * m.MatrixData[3] + MatrixData[4] * m.MatrixData[4] + MatrixData[7] * m.MatrixData[5],
			MatrixData[1] * m.MatrixData[6] + MatrixData[4] * m.MatrixData[7] + MatrixData[7] * m.MatrixData[8],

			MatrixData[2] * m.MatrixData[0] + MatrixData[5] * m.MatrixData[1] + MatrixData[8] * m.MatrixData[2],
			MatrixData[2] * m.MatrixData[3] + MatrixData[5] * m.MatrixData[4] + MatrixData[8] * m.MatrixData[5],
			MatrixData[2] * m.MatrixData[6] + MatrixData[5] * m.MatrixData[7] + MatrixData[8] * m.MatrixData[8]);
	}

	const Vector3 Matrix3::operator*(const Vector3& v)
	{
		return Vector3(
			MatrixData[0] * v.x + MatrixData[3] * v.y + MatrixData[6] * v.z,
			MatrixData[1] * v.x + MatrixData[4] * v.y + MatrixData[7] * v.z,
			MatrixData[2] * v.x + MatrixData[5] * v.y + MatrixData[8] * v.z);
	}

	void Matrix3::operator+=(const Matrix3& m)
	{
		MatrixData[0] += m.MatrixData[0];
		MatrixData[3] += m.MatrixData[3];
		MatrixData[6] += m.MatrixData[6];

		MatrixData[1] += m.MatrixData[1];
		MatrixData[4] += m.MatrixData[4];
		MatrixData[7] += m.MatrixData[7];

		MatrixData[2] += m.MatrixData[2];
		MatrixData[5] += m.MatrixData[5];
		MatrixData[8] += m.MatrixData[8];
	}

	void Matrix3::operator*=(const float s)
	{
		MatrixData[0] *= s;
		MatrixData[3] *= s;
		MatrixData[6] *= s;

		MatrixData[1] *= s;
		MatrixData[4] *= s;
		MatrixData[7] *= s;

		MatrixData[2] *= s;
		MatrixData[5] *= s;
		MatrixData[8] *= s;
	}

	void Matrix3::operator*=(const Matrix3& m)
	{
		float data1;
		float data2;
		float data3;

		data1 = MatrixData[0] * m.MatrixData[0] + MatrixData[3] * m.MatrixData[1] + MatrixData[6] * m.MatrixData[2];
		data2 = MatrixData[0] * m.MatrixData[3] + MatrixData[3] * m.MatrixData[4] + MatrixData[6] * m.MatrixData[5];
		data3 = MatrixData[0] * m.MatrixData[6] + MatrixData[3] * m.MatrixData[7] + MatrixData[6] * m.MatrixData[8];

		MatrixData[0] = data1;
		MatrixData[3] = data2;
		MatrixData[6] = data3;

		data1 = MatrixData[1] * m.MatrixData[0] + MatrixData[4] * m.MatrixData[1] + MatrixData[7] * m.MatrixData[2];
		data2 = MatrixData[1] * m.MatrixData[3] + MatrixData[4] * m.MatrixData[4] + MatrixData[7] * m.MatrixData[5];
		data3 = MatrixData[1] * m.MatrixData[6] + MatrixData[4] * m.MatrixData[7] + MatrixData[7] * m.MatrixData[8];

		MatrixData[1] = data1;
		MatrixData[4] = data2;
		MatrixData[7] = data3;

		data1 = MatrixData[2] * m.MatrixData[0] + MatrixData[5] * m.MatrixData[1] + MatrixData[8] * m.MatrixData[2];
		data2 = MatrixData[2] * m.MatrixData[3] + MatrixData[5] * m.MatrixData[4] + MatrixData[8] * m.MatrixData[5];
		data3 = MatrixData[2] * m.MatrixData[6] + MatrixData[5] * m.MatrixData[7] + MatrixData[8] * m.MatrixData[8];

		MatrixData[2] = data1;
		MatrixData[5] = data2;
		MatrixData[8] = data3;
	}

	const Vector3 Matrix3::transformVectorByMatrix(const Vector3& v)
	{
		return (*this) * v;
	}

	void Matrix3::SetIdentityMatrix()
	{
		for (int i = 0; i < 9; i++)
		{
			MatrixData[i] = 0.0f;
		}

		MatrixData[0] = MatrixData[4] = MatrixData[8] = 1.0f;
	}

	void Matrix3::SetInverseOfMatrix(const Matrix3& m)
	{
		float data1 = m.MatrixData[0] * m.MatrixData[4];
		float data2 = m.MatrixData[0] * m.MatrixData[7];
		float data3 = m.MatrixData[3] * m.MatrixData[1];
		float data4 = m.MatrixData[6] * m.MatrixData[1];
		float data5 = m.MatrixData[3] * m.MatrixData[2];
		float data6 = m.MatrixData[6] * m.MatrixData[2];

		float determinent = (
			data1 * m.MatrixData[8] - data2 * m.MatrixData[5] - data3 * m.MatrixData[8] + data4 * m.MatrixData[5] + data5 * m.MatrixData[7] - data6 * m.MatrixData[4]);

		if (determinent == 0.0) return;

		float invd = 1.0f / determinent;

		float m0 = (m.MatrixData[4] * m.MatrixData[8] - m.MatrixData[7] * m.MatrixData[5]) * invd;
		float m3 = -(m.MatrixData[3] * m.MatrixData[8] - m.MatrixData[6] * m.MatrixData[5]) * invd;

		float m6 = (m.MatrixData[3] * m.MatrixData[7] - m.MatrixData[6] * m.MatrixData[4]) * invd;

		float m1 = -(m.MatrixData[1] * m.MatrixData[8] - m.MatrixData[7] * m.MatrixData[2]) * invd;

		float m4 = (m.MatrixData[0] * m.MatrixData[8] - data6) * invd;

		float m7 = -(data2 - data4) * invd;

		float m2 = (m.MatrixData[1] * m.MatrixData[5] - m.MatrixData[4] * m.MatrixData[2]) * invd;

		float m5 = -(m.MatrixData[0] * m.MatrixData[5] - data5) * invd;

		float m8 = (data1 - data3) * invd;

		MatrixData[0] = m0;
		MatrixData[3] = m3;
		MatrixData[6] = m6;

		MatrixData[1] = m1;
		MatrixData[4] = m4;
		MatrixData[7] = m7;

		MatrixData[2] = m2;
		MatrixData[5] = m5;
		MatrixData[8] = m8;
	}

	const Matrix3 Matrix3::getInverse()
	{
		Matrix3 result;
		result.SetInverseOfMatrix(*this);
		return result;
	}

	void Matrix3::invertMatrix()
	{
		SetInverseOfMatrix(*this);
	}

	const float Matrix3::getDeterminent()
	{
		float data1 = MatrixData[0] * MatrixData[4];
		float data2 = MatrixData[0] * MatrixData[7];
		float data3 = MatrixData[3] * MatrixData[1];
		float data4 = MatrixData[6] * MatrixData[1];
		float data5 = MatrixData[3] * MatrixData[2];
		float data6 = MatrixData[6] * MatrixData[2];

		float determinent = (
			data1 * MatrixData[8] - data2 * MatrixData[5] - data3 * MatrixData[8] + data4 * MatrixData[5] + data5 * MatrixData[7] - data6 * MatrixData[4]);

		return determinent;
	}

	void Matrix3::SetTransposeMatrix(const Matrix3& m)
	{
		MatrixData[0] = m.MatrixData[0];
		MatrixData[3] = m.MatrixData[1];
		MatrixData[6] = m.MatrixData[2];

		MatrixData[1] = m.MatrixData[3];
		MatrixData[4] = m.MatrixData[4];
		MatrixData[7] = m.MatrixData[5];

		MatrixData[2] = m.MatrixData[6];
		MatrixData[5] = m.MatrixData[7];
		MatrixData[8] = m.MatrixData[8];
	}

	const Matrix3 Matrix3::getTranspose(const Matrix3& m)
	{
		Matrix3 result;
		result.SetTransposeMatrix(*this);
		return result;
	}

	void Matrix3::invertAndTranspose()
	{
		float determinent = MatrixData[0] * (MatrixData[4] * MatrixData[8] - MatrixData[5] * MatrixData[7]) - MatrixData[3] * (MatrixData[1] * MatrixData[8] - MatrixData[2] * MatrixData[7]) + MatrixData[6] * (MatrixData[1] * MatrixData[5] - MatrixData[2] * MatrixData[4]);

		Matrix3 transpose;

		transpose.MatrixData[0] = MatrixData[0];
		transpose.MatrixData[1] = MatrixData[3];
		transpose.MatrixData[2] = MatrixData[6];

		transpose.MatrixData[3] = MatrixData[1];
		transpose.MatrixData[4] = MatrixData[4];
		transpose.MatrixData[5] = MatrixData[7];

		transpose.MatrixData[6] = MatrixData[2];
		transpose.MatrixData[7] = MatrixData[5];
		transpose.MatrixData[8] = MatrixData[8];

		float m11, m12, m13, m21, m22, m23, m31, m32, m33;

		m11 = +(transpose.MatrixData[4] * transpose.MatrixData[8] - transpose.MatrixData[5] * transpose.MatrixData[7]) / determinent;
		m12 = -(transpose.MatrixData[1] * transpose.MatrixData[8] - transpose.MatrixData[2] * transpose.MatrixData[7]) / determinent;
		m13 = +(transpose.MatrixData[1] * transpose.MatrixData[5] - transpose.MatrixData[2] * transpose.MatrixData[4]) / determinent;

		m21 = -(transpose.MatrixData[3] * transpose.MatrixData[8] - transpose.MatrixData[5] * transpose.MatrixData[6]) / determinent;
		m22 = +(transpose.MatrixData[0] * transpose.MatrixData[8] - transpose.MatrixData[2] * transpose.MatrixData[6]) / determinent;
		m23 = -(transpose.MatrixData[0] * transpose.MatrixData[5] - transpose.MatrixData[2] * transpose.MatrixData[3]) / determinent;

		m31 = +(transpose.MatrixData[3] * transpose.MatrixData[7] - transpose.MatrixData[4] * transpose.MatrixData[6]) / determinent;
		m32 = -(transpose.MatrixData[0] * transpose.MatrixData[7] - transpose.MatrixData[1] * transpose.MatrixData[6]) / determinent;
		m33 = +(transpose.MatrixData[0] * transpose.MatrixData[4] - transpose.MatrixData[1] * transpose.MatrixData[3]) / determinent;

		Matrix3 preResult;

		preResult.MatrixData[0] = m11;
		preResult.MatrixData[1] = m21;
		preResult.MatrixData[2] = m31;

		preResult.MatrixData[3] = m12;
		preResult.MatrixData[4] = m22;
		preResult.MatrixData[5] = m32;

		preResult.MatrixData[6] = m13;
		preResult.MatrixData[7] = m23;
		preResult.MatrixData[8] = m33;

		MatrixData[0] = preResult.MatrixData[0];
		MatrixData[1] = preResult.MatrixData[3];
		MatrixData[2] = preResult.MatrixData[6];

		MatrixData[3] = preResult.MatrixData[1];
		MatrixData[4] = preResult.MatrixData[4];
		MatrixData[5] = preResult.MatrixData[7];

		MatrixData[6] = preResult.MatrixData[2];
		MatrixData[7] = preResult.MatrixData[5];
		MatrixData[8] = preResult.MatrixData[8];
	}

	void Matrix3::MatrixRotateXByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		(*this).SetIdentityMatrix();

		Matrix3 m(
			1.0, 0.0, 0.0,
			0.0, cos(uAngle), -sin(uAngle),
			0.0, sin(uAngle), cos(uAngle));

		*this = m * (*this);
	}

	void Matrix3::MatrixRotateYByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);
		(*this).SetIdentityMatrix();

		Matrix3 m(
			cos(uAngle), 0.0, sin(uAngle),
			0.0, 1.0, 0.0,
			-sin(uAngle), 0.0, cos(uAngle));

		*this = m * (*this);
	}

	void Matrix3::MatrixRotateZByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);
		(*this).SetIdentityMatrix();

		Matrix3 m(
			cos(uAngle), -sin(uAngle), 0.0,
			sin(uAngle), cos(uAngle), 0.0,
			0.0, 0.0, 1.0);

		*this = m * (*this);
	}

	void Matrix3::MatrixTransformXByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		Matrix3 m(
			1.0, 0.0, 0.0,
			0.0, cos(uAngle), -sin(uAngle),
			0.0, sin(uAngle), cos(uAngle));

		*this = m * (*this);
	}

	void Matrix3::MatrixTransformYByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		Matrix3 m(
			cos(uAngle), 0.0, sin(uAngle),
			0.0, 1.0, 0.0,
			-sin(uAngle), 0.0, cos(uAngle));

		*this = m * (*this);
	}

	void Matrix3::MatrixTransformZByAngle(float uAngle)
	{
		uAngle = DegreesToRadian(uAngle);

		Matrix3 m(
			cos(uAngle), -sin(uAngle), 0.0,
			sin(uAngle), cos(uAngle), 0.0,
			0.0, 0.0, 1.0);

		*this = m * (*this);
	}

	void Matrix3::show()
	{
		std::cout << "[" << MatrixData[0] << "," << MatrixData[3] << "," << MatrixData[6] << "," << std::endl;
		std::cout << MatrixData[1] << "," << MatrixData[4] << "," << MatrixData[7] << "," << std::endl;
		std::cout << MatrixData[2] << "," << MatrixData[5] << "," << MatrixData[8] << "]" << std::endl;
	}
}