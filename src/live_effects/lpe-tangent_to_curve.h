// SPDX-License-Identifier: GPL-2.0-or-later
#ifndef INKSCAPE_LPE_TANGENT_TO_CURVE_H
#define INKSCAPE_LPE_TANGENT_TO_CURVE_H

/** \file
 * LPE <tangent_to_curve> implementation, see lpe-tangent_to_curve.cpp.
 */

/*
 * Authors:
 *   Johan Engelen
 *   Maximilian Albert
 *
 * Copyright (C) Johan Engelen 2007 <j.b.c.engelen@utwente.nl>
 * Copyright (C) Maximilian Albert 2008 <maximilian.albert@gmail.com>
 *
 * Released under GNU GPL v2+, read the file 'COPYING' for more information.
 */

#include "live_effects/effect.h"
#include "live_effects/parameter/parameter.h"
#include "live_effects/parameter/point.h"

namespace Inkscape {
namespace LivePathEffect {

namespace TtC {
  // we need a separate namespace to avoid clashes with LPEPerpBisector
  class KnotHolderEntityLeftEnd;
  class KnotHolderEntityRightEnd;
  class KnotHolderEntityAttachPt;
}

class LPETangentToCurve : public Effect {
public:
    LPETangentToCurve(LivePathEffectObject *lpeobject);
    ~LPETangentToCurve() override;
    Geom::Piecewise<Geom::D2<Geom::SBasis> >
      doEffect_pwd2 (Geom::Piecewise<Geom::D2<Geom::SBasis> > const & pwd2_in) override;

    /* the knotholder entity classes must be declared friends */
    friend class TtC::KnotHolderEntityLeftEnd;
    friend class TtC::KnotHolderEntityRightEnd;
    friend class TtC::KnotHolderEntityAttachPt;
    void addKnotHolderEntities(KnotHolder * knotholder, SPItem * item) override;

private:
    ScalarParam angle;

    ScalarParam t_attach;
    ScalarParam length_left;
    ScalarParam length_right;

    Geom::Point ptA; // point of attachment to the curve
    Geom::Point derivA;

    Geom::Point C; // left end of tangent
    Geom::Point D; // right end of tangent

    LPETangentToCurve(const LPETangentToCurve&) = delete;
    LPETangentToCurve& operator=(const LPETangentToCurve&) = delete;
};

} //namespace LivePathEffect
} //namespace Inkscape

#endif
