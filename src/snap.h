#ifndef SEEN_SNAP_H
#define SEEN_SNAP_H

/**
 * \file snap.h
 * \brief Various snapping methods.
 *
 * Authors:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *   Frank Felfe <innerspace@iname.com>
 *   Carl Hetherington <inkscape@carlh.net>
 *
 * Copyright (C) 2000-2002 Lauris Kaplinski
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#include <vector>

#include <libnr/nr-coord.h>
#include <libnr/nr-dim2.h>
#include <libnr/nr-forward.h>
#include "snapper.h"

class SPNamedView;

/* Single point methods */
NR::Coord namedview_free_snap(SPNamedView const *nv, Inkscape::Snapper::PointType t, NR::Point &req,
                              SPItem const *it);
NR::Coord namedview_vector_snap(SPNamedView const *nv, Inkscape::Snapper::PointType t, NR::Point &req,
                                NR::Point const &d, std::list<SPItem const *> const &it);
NR::Coord namedview_vector_snap(SPNamedView const *nv, Inkscape::Snapper::PointType t, NR::Point &req,
                                NR::Point const &d, SPItem const *it);
NR::Coord namedview_dim_snap(SPNamedView const *nv, Inkscape::Snapper::PointType t, NR::Point& req,
                             NR::Dim2 const dim, SPItem const *it);
NR::Coord namedview_dim_snap(SPNamedView const *nv, Inkscape::Snapper::PointType t, NR::Point& req,
                             NR::Dim2 const dim, std::list<SPItem const *> const &it);

/* List of points methods */

std::pair<int, NR::Point> namedview_free_snap(SPNamedView const *nv,
                                              std::vector<Inkscape::Snapper::PointWithType> const &p);

std::pair<double, bool> namedview_vector_snap_list(SPNamedView const *nv,
                                                   Inkscape::Snapper::PointType t, const std::vector<NR::Point> &p,
                                                   NR::Point const &norm, NR::scale const &s,
                                                   std::list<SPItem const *> const &it
                                                   );

std::pair<NR::Coord, bool> namedview_dim_snap_list(SPNamedView const *nv,
                                                   Inkscape::Snapper::PointType t, const std::vector<NR::Point> &p,
                                                   double const dx, NR::Dim2 const dim,
                                                   std::list<SPItem const *> const &it
                                                   );

std::pair<double, bool> namedview_dim_snap_list_scale(SPNamedView const *nv,
                                                      Inkscape::Snapper::PointType t, const std::vector<NR::Point> &p,
                                                      NR::Point const &norm, double const sx,
                                                      NR::Dim2 const dim,
                                                      std::list<SPItem const *> const &it);

NR::Coord namedview_dim_snap_list_skew(SPNamedView const *nv, Inkscape::Snapper::PointType t,
                                       const std::vector<NR::Point> &p,
                                       NR::Point const &norm, double const sx, NR::Dim2 const dim);


/** \todo
 * FIXME:
 * Temporary methods.  These snap a single point as if it were both a snap point
 * and a bbox point.  Any callers of these methods should instead be calling
 * namedview_*_snap twice; once with a snap point and once with the corresponding
 * bbox point (taking, e.g., stroke width into account).  However in some cases
 * working out the bbox point is hard, so these methods are a hack for now.
 * They should be removed.
 */
NR::Coord namedview_free_snap_all_types(SPNamedView const *nv,
                                        NR::Point &req,
                                        SPItem const *it = NULL);
NR::Coord namedview_vector_snap_all_types(SPNamedView const *nv,
                                          NR::Point &req,
                                          NR::Point const &d,
                                          SPItem const *it = NULL);
NR::Coord namedview_dim_snap_all_types(SPNamedView const *nv,
                                       NR::Point& req,
                                       NR::Dim2 const dim,
                                       SPItem const *it = NULL);


#endif /* !SEEN_SNAP_H */

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4 :
