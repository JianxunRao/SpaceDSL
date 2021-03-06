﻿/************************************************************************
* Copyright (C) 2018 Niu ZhiYong
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Author: Niu ZhiYong
* Date:2018-12-26
* Description:
*   SpAttitude.h
*
*   Purpose:
*
*         Calculation of All Kinds of Attitude.
*
*
*   Last modified:
*
*   2018-12-26  Niu Zhiyong (1st edition)
*
*************************************************************************/

#ifndef SPATTITUDE_H
#define SPATTITUDE_H

#include "SpaceDSL_Global.h"


#include <string>
#include <vector>

#include <Eigen/Core>
#include <Eigen/Geometry>


using namespace std;
using namespace Eigen;
/// All the functions are in the namespace SpaceDSL
///
namespace SpaceDSL {

    /*************************************************
     * Class type: The class of SpaceDSL YPR Angles
     * Author: Niu ZhiYong
     * Date:2018-12-26
     * Description:
     *  Angle Unit is [rad]
     *  Rotation Order String Can be "YPR" "PYR" ...
     *  This Class is Thread Safe!
    **************************************************/
    class SPACEDSL_API YPREulerAngle
    {
    public:
        explicit YPREulerAngle();
        YPREulerAngle(const double yaw, const double pitch, const double roll);
        YPREulerAngle(const Matrix3d &rotationMatrix, const string &rotationOrder);
        virtual ~YPREulerAngle();

    public:
        inline void         SetYaw(const double yaw)            { m_Yaw = yaw; }

        inline void         SetPitch(const double pitch)        { m_Pitch = pitch; }

        inline void         SetRoll(const double roll)          { m_Roll = roll; }

        inline double       Yaw() const                     { return m_Yaw; }

        inline double       Pitch() const                   { return m_Pitch; }

        inline double       Roll() const                    { return m_Roll; }

        const  Matrix3d     GetRotationMatrix(const string &rotationOrder) const;

        const Quaterniond   GetQuaternion() const;
    //
    // Attribute.
    //
    protected:
        double                  m_Yaw;
        double                  m_Pitch;
        double                  m_Roll;
    };
}

#endif //SPATTITUDE_H
