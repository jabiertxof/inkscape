
#ifndef SEEN_PREVIEWABLE_H
#define SEEN_PREVIEWABLE_H
/*
 * A simple interface for previewing representations.
 *
 * Authors:
 *   Jon A. Cruz
 *
 * Copyright (C) 2005 Jon A. Cruz
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */


#include <gtkmm/widget.h>


namespace Inkscape {
namespace UI {

typedef enum {
    PREVIEW_STYLE_ICON,
    PREVIEW_STYLE_PREVIEW,
    PREVIEW_STYLE_NAME,
    PREVIEW_STYLE_BLURB,
    PREVIEW_STYLE_ICON_NAME,
    PREVIEW_STYLE_ICON_BLURB,
    PREVIEW_STYLE_PREVIEW_NAME,
    PREVIEW_STYLE_PREVIEW_BLURB
} PreviewStyle;

typedef enum {
    VIEW_TYPE_LIST,
    VIEW_TYPE_GRID
} ViewType;

class Previewable
{
public:
// TODO need to add some nice parameters
    virtual Gtk::Widget* getPreview( PreviewStyle style, Gtk::BuiltinIconSize size ) = 0;
};


} //namespace UI
} //namespace Inkscape


#endif // SEEN_PREVIEWABLE_H

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:encoding=utf-8:textwidth=99 :
