#ifndef __INKSCAPE_PRIVATE_H__
#define __INKSCAPE_PRIVATE_H__

/*
 * Some forward declarations
 *
 * Authors:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *
 * Copyright (C) 1999-2002 Lauris Kaplinski
 * Copyright (C) 2001-2002 Ximian, Inc.
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */

#define SP_TYPE_INKSCAPE (inkscape_get_type ())
#define SP_INKSCAPE(obj) (GTK_CHECK_CAST ((obj), SP_TYPE_INKSCAPE, Inkscape))
#define SP_INKSCAPE_CLASS(klass) (GTK_CHECK_CLASS_CAST ((klass), SP_TYPE_INKSCAPE, InkscapeClass))
#define SP_IS_INKSCAPE(obj) (GTK_CHECK_TYPE ((obj), SP_TYPE_INKSCAPE))
#define SP_IS_INKSCAPE_CLASS(klass) (GTK_CHECK_CLASS_TYPE ((klass), SP_TYPE_INKSCAPE))

#include "inkscape.h"

GType inkscape_get_type (void);

Inkscape *inkscape_new ();

void inkscape_ref (void);
void inkscape_unref (void);

/*
 * These are meant solely for desktop, document etc. implementations
 */

void inkscape_selection_modified (SPSelection *selection, guint flags);
void inkscape_selection_changed (SPSelection * selection);
void inkscape_selection_set (SPSelection * selection);
void inkscape_eventcontext_set (SPEventContext * eventcontext);
void inkscape_add_desktop (SPDesktop * desktop);
void inkscape_remove_desktop (SPDesktop * desktop);
void inkscape_activate_desktop (SPDesktop * desktop);
void inkscape_reactivate_desktop (SPDesktop * desktop);
void inkscape_add_document (SPDocument *document);
void inkscape_remove_document (SPDocument *document);

void inkscape_set_color (SPColor *color, float opacity);

#endif


