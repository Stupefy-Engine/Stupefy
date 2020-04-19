/****************************************************************************/
/*  vector3.cpp                                                             */
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


#include "core/math/vector3.h"

namespace Stupefy
{
    vector3::vector3():x(0.0),y(0.0),z(0.0){};   

    vector3::~vector3(){}   
                                                   
    vector3::vector3(float uX, float uY, float uZ):x(uX),y(uY),z(uZ){}   
      

    vector3::vector3(const vector3& v):x(v.x),y(v.y),z(v.z){}   
                                  
    vector3& vector3::operator =(const vector3& v)
    {
        x=v.x;
        y=v.y;
        z=v.z;
        return *this;
    }   
                    
    const vector3 vector3::operator+(const vector3& v)
    {
        return vector3(x + v.x, y + v.y, z + v.z);
    }   
                   
    const vector3 vector3::operator-(const vector3& v)
    {
        return vector3(x - v.x, y - v.y, z - v.z);
    }   
             
    const vector3 vector3::operator*(const float s)
    {
        return vector3(x * s, y * s, z * s);
    }   
                    
    const vector3 vector3::operator/(const float s)    
    {
        return vector3(x / s, y / s, z / s);
    }   
                  
    void vector3::operator +=(const vector3& v)    
    {
        x += v.x;
        y += v.y;
        z += v.z;
    }   
                     
    void vector3::operator -=(const vector3& v)  
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }   
                          
    void vector3::operator *=(const float s)       
    {
        x *= s;
        y *= s;
        z *= s;
    }   
                         
    void vector3::operator /=(const float s)
    {
        x /= s;
        y /= s;
        z /= s;
    }

    const float vector3::operator *(const vector3& v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    const float vector3::dot(const vector3& v)
    {
        return x * v.x + y * v.y + z * v.z;
    }
    
    float vector3::angle(const vector3& v)
    {
        float theta;
        vector3 u = v;
        vector3 m = *this;
        theta = dot(u) / (m.magnitude() * u.magnitude());
        //theta = RadianToDegrees(acos(theta));      PI needed to be defined
        return theta;
    }
    
    const vector3 vector3::operator %(const vector3& v)
    {
        return vector3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x);
    }

    void vector3::operator %=(const vector3& v)
    {
        *this = cross(v);
    }

    const vector3 vector3::cross(const vector3& v)
    {
        return vector3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x);
    }
    
    void vector3::conjugate()
    {
        x = -1 * x;
        y = -1 * y;
        z = -1 * z;
    }
    
    void vector3::normalize()
    {
        float mag = std::sqrt(x * x + y * y + z * z);
        if (mag > 0.0f)
        {
            float oneOverMag = 1.0f / mag;

            x = x * oneOverMag;
            y = y * oneOverMag;
            z = z * oneOverMag;
        }
    }
    
    void vector3::zero()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    
    void vector3::absolute()
    {
        x = std::abs(x);
        y = std::abs(y);
        z = std::abs(z);
    }
    
    float vector3::magnitude()
    {
        float magnitude = std::sqrt(x * x + y * y + z * z);
        return magnitude;
    }
    
    float vector3::magnitudeSquare()
    {
        float magnitude = x * x + y * y + z * z;
        return magnitude;
    }
    /*
    vector3 vector3::rotateVectorAboutAngleAndAxis(float uAngle, vector3& uAxis)
    {
        //TODO
    }
    */
    void vector3::show()
    {
        std::cout << " ( " << x << " , " << y << " , " << z << " ) " << std::endl;
    }
    
    void vector3::negate()
    {
        x = -1 * x;
        y = -1 * y;
        z = -1 * z;
    }    
}