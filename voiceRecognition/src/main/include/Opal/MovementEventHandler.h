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

#ifndef OPAL_MOVEMENT_EVENT_HANDLER_H
#define OPAL_MOVEMENT_EVENT_HANDLER_H

namespace opal
{
	//! Stores details about movement event.
	/**
	 * @author Oleksandr Lozitskiy
	 */
	class MovementEvent
	{
		public:
			MovementEvent( Solid * moved_solid )
			{
				solid = moved_solid;
			}

			Solid * solid;
	};

	//! Abstract interface.
	/**
	 * @author Oleksandr Lozitskiy
	 */
	class MovementEventHandler
	{
		public:
			OPAL_DECL virtual ~MovementEventHandler() {}

			OPAL_DECL virtual void OPAL_CALL handleMovementEvent( const MovementEvent & move ) = 0;
	};
}

#endif
