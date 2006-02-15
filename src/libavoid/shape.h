/*
 * vim: ts=4 sw=4 et tw=0 wm=0
 *
 * libavoid - Fast, Incremental, Object-avoiding Line Router
 * Copyright (C) 2004-2006  Michael Wybrow <mjwybrow@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
*/

#ifndef AVOID_SHAPE_H
#define AVOID_SHAPE_H

#include "libavoid/geometry.h"
#include <list>


namespace Avoid {

class VertInf;
class Router;
class ShapeRef;
typedef std::list<ShapeRef *> ShapeRefList;


class ShapeRef
{
    public:
        ShapeRef(Router *router, uint id, Polygn& poly);
        ~ShapeRef();
        VertInf *firstVert(void);
        VertInf *lastVert(void);
        uint id(void);
        Polygn poly(void);
        Router *router(void);
        void boundingBox(BBox& bbox);
        
        void makeActive(void);
        void makeInactive(void);

        void removeFromGraph(void);
        
    private:
        Router *_router;
        uint _id;
        Polygn _poly;
        bool _active;
        ShapeRefList::iterator _pos;
        VertInf *_firstVert;
        VertInf *_lastVert;
};


}


#endif


