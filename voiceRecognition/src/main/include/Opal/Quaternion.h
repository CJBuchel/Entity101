/*************************************************************************
*                                                                       *
* Open Physics Abstraction Layer                                        *
* Copyright (C) 2004-2005                                               *
* Alan Fischer  alan.fischer@gmail.com                                  *
* Andres Reinot  andres@reinot.com                                      *
* Tyler Streeter  tylerstreeter@gmail.com                               *
* All rights reserved.                                                  *
* Web: opal.sourceforge.net                                             *
*                                                                       *
* This library is free software; you can redistribute it and/or         *
* modify it under the terms of EITHER:                                  *
*   (1) The GNU Lesser General Public License as published by the Free  *
*       Software Foundation; either version 2.1 of the License, or (at  *
*       your option) any later version. The text of the GNU Lesser      *
*       General Public License is included with this library in the     *
*       file license-LGPL.txt.                                          *
*   (2) The BSD-style license that is included with this library in     *
*       the file license-BSD.txt.                                       *
*                                                                       *
* This library is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the files    *
* license-LGPL.txt and license-BSD.txt for more details.                *
*                                                                       *
*************************************************************************/

#ifndef OPAL_QUATERNION_H
#define OPAL_QUATERNION_H

// project headers
#include "OpalMath.h"
#include "Portability.h"

// system headers
#include <iostream>

namespace opal
{
	class Vec3r;
	
    class Quaternion
    {
        public:
            real w;
            real x;
            real y;
            real z;

            OPAL_DECL Quaternion();

            OPAL_DECL Quaternion( real ww, real xx, real yy, real zz );

            OPAL_DECL Quaternion( const Quaternion& src );

            OPAL_DECL void OPAL_CALL set( real ww, real xx, real yy, real zz );

            OPAL_DECL real OPAL_CALL lengthSquared() const;

            OPAL_DECL real OPAL_CALL length() const;

            //! Length will be one.
            OPAL_DECL void OPAL_CALL normalize();

            //! Returns the equivalent rotation.
            /*!
             * @param angle in degrees
             * @param axis axis of rotation
             *
             * @note Quaternion needs to be normalized first
             */
            OPAL_DECL void OPAL_CALL getAngleAxis( real & angle, Vec3r & axis ) const;

            OPAL_DECL real OPAL_CALL getRoll() const;

            OPAL_DECL real OPAL_CALL getPitch() const;

            OPAL_DECL real OPAL_CALL getYaw() const;

            OPAL_DECL real & OPAL_CALL operator[] ( unsigned int i );

            OPAL_DECL const real & OPAL_CALL operator[] ( unsigned int i ) const;
    };

	OPAL_DECL Quaternion operator+( const Quaternion &q1, const Quaternion &q2 );
	OPAL_DECL Quaternion operator-( const Quaternion &q1, const Quaternion &q2 );
	OPAL_DECL Quaternion operator*( const Quaternion& q, real scalar );
	OPAL_DECL Quaternion operator*( real scalar, const Quaternion& q );
	OPAL_DECL bool operator==( const Quaternion &q1, const Quaternion &q2 );
	OPAL_DECL bool operator!=( const Quaternion &q1, const Quaternion &q2 );

    /// Prints the Quaternion to the given output stream.
	OPAL_DECL std::ostream & operator<<( std::ostream& o, const Quaternion& q );

}

#endif
