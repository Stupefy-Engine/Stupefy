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


#include "core/math/matrix3.h"

namespace Stupefy
{
	matrix3::matrix3(){}
	matrix3::~matrix3(){}

	matrix3::matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8)
	{

	}

	matrix3& matrix3::operator=(const matrix3& val)
	{

	}

	const matrix3 matrix3::operator+(const matrix3& m)
	{

	}

	const matrix3 matrix3::operator*(const float s)
	{

	}

	void matrix3::operator+=(const matrix3& m)
	{

	}

	void matrix3::operator*=(const float s)
	{

	}

	void matrix3::setIdentityMatrix()
	{

	}

	void matrix3::setInverseOfMatrix(const matrix3& m)
	{

	}

	const void matrix3::getInverse()
	{

	}

	void matrix3::invertMatrix()
	{

	}

	const float matrix3::getDeterminent()
	{

	}

	void matrix3::setTransposeMatrix(const matrix3& m)
	{

	}

	const matrix3 matrix3::getTranspose(const matrix3& m)
	{

	}

	void matrix3::matrixRotateXByAngle(float uAngle)
	{

	}

	void matrix3::matrixRotateYByAngle(float uAngle)
	{

	}

	void matrix3::matrixRotateZByAngle(float uAngle)
	{

	}

	void matrix3::matrixTransformXByAngle(float uAngle)
	{

	}

	void matrix3::matrixTransformYByAngle(float uAngle)
	{

	}

	void matrix3::matrixTransformZByAngle(float uAngle)
	{

	}

	void matrix3::show()
	{

	}
}