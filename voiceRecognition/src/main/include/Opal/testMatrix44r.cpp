/*************************************************************************
*                                                                       *
* Open Physics Abstraction Layer                                        *
* Copyright (C) 2004-2005                                               *
* Alan Fischer  alan.fischer@gmail.com                                  *
* Andres Reinot  andres@reinot.com                                      *
* Tyler Streeter  tylerstreeter@gmail.com                               *
* Oleksandr Lozitskiy mr.olexander@gmail.com                            *
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

// system headers
#include <quicktest.h>

// project headers
#include "opal.h"

using namespace opal;

namespace testMatrix44r
{
    QT_TEST( setQuaternion_values )
    {
        Matrix44r m;
        m.setQuaternion( 0, 0, 0, 1 );
        QT_CHECK_EQUAL( m.getEulerXYZ(), Vec3r( 0, 0, 180 ) );

		QT_CHECK_EQUAL( m.getQuaternion(), Quaternion( 0, 0, 0, 1 ) );
		QT_CHECK_EQUAL( m.getQuaternion(), Quaternion( 0, 0, 0, 1 ) );
    }

    QT_TEST( setQuaternion_object )
    {
        Matrix44r m;
        m.setQuaternion( Quaternion( 0, 0, 0, 1 ) );
        QT_CHECK_EQUAL( m.getEulerXYZ(), Vec3r( 0, 0, 180 ) );

		QT_CHECK_EQUAL( m.getQuaternion(), Quaternion( 0, 0, 0, 1 ) );
		QT_CHECK_EQUAL( m.getQuaternion(), Quaternion( 0, 0, 0, 1 ) );
    }

	QT_TEST( matrix_point_multiply )
	{
		opal::Matrix44r transform;
		transform.translate(5, 0, 0);
		opal::Point3r p;
		p = transform * p;
		opal::Point3r intendedPosition(5, 0, 0);

		QT_CHECK_EQUAL( opal::distance(p, intendedPosition), 0 );
	}
}
