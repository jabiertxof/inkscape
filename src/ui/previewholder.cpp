
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


#include "previewholder.h"

#include <gtkmm.h>
#include <gtkmm/scrolledwindow.h>


namespace Inkscape {
namespace UI {


PreviewHolder::PreviewHolder() :
    VBox(),
    PreviewFillable(),
    _scroller(0),
    _baseSize(Gtk::ICON_SIZE_MENU),
    _view(VIEW_TYPE_LIST)
{
    _scroller = manage(new Gtk::ScrolledWindow());
    Gtk::Table* stuff = manage(new Gtk::Table( 1, 2 ));
    _insides = stuff;
    _scroller->add(*stuff);

    pack_start(*_scroller, Gtk::PACK_EXPAND_WIDGET);
}

PreviewHolder::~PreviewHolder()
{
}



void PreviewHolder::clear()
{
    items.clear();
}

void PreviewHolder::addPreview( Previewable* preview )
{
    items.push_back(preview);


    Gtk::Widget* thing = manage(preview->getPreview(PREVIEW_STYLE_PREVIEW, _baseSize));
    Gtk::Widget* label = manage(preview->getPreview(PREVIEW_STYLE_BLURB, _baseSize));


    int i = items.size() - 1;
    _insides->attach( *thing, 0, 1, i, i+1, Gtk::FILL|Gtk::EXPAND, Gtk::FILL|Gtk::EXPAND );
    _insides->attach( *label, 1, 2, i, i+1, Gtk::FILL|Gtk::EXPAND, Gtk::SHRINK );
}

void PreviewHolder::setStyle(Gtk::BuiltinIconSize size, ViewType view)
{
    if ( size != _baseSize || view != _view ) {
        _baseSize = size;
        _view = view;
        rebuildUI();
    }
}


void PreviewHolder::rebuildUI()
{
    _scroller->remove();

    if ( _view == VIEW_TYPE_LIST ) {
        Gtk::Table* stuff = manage(new Gtk::Table( 1, 2 ));
        stuff->set_col_spacings( 8 );

        for ( unsigned int i = 0; i < items.size(); i++ ) {
            Gtk::Widget* label = manage(items[i]->getPreview(PREVIEW_STYLE_BLURB, _baseSize));
            //label->set_alignment(Gtk::ALIGN_LEFT, Gtk::ALIGN_CENTER);

            Gtk::Widget* thing = manage(items[i]->getPreview(PREVIEW_STYLE_PREVIEW, _baseSize));

            stuff->attach( *thing, 0, 1, i, i+1, Gtk::FILL|Gtk::EXPAND, Gtk::FILL|Gtk::EXPAND );
            stuff->attach( *label, 1, 2, i, i+1, Gtk::FILL|Gtk::EXPAND, Gtk::SHRINK );
        }
        _scroller->add(*stuff);
    } else {
        int width = _baseSize == Gtk::ICON_SIZE_MENU ? 16 : 8;
        int height = (items.size() + (width - 1)) / width;

        Gtk::Table* stuff = manage(new Gtk::Table( width, height ));
        int col = 0;
        int row = 0;

        for ( unsigned int i = 0; i < items.size(); i++ ) {
            Gtk::Widget* thing = manage(items[i]->getPreview(PREVIEW_STYLE_PREVIEW, _baseSize));

            stuff->attach( *thing, col, col+1, row, row+1, Gtk::FILL|Gtk::EXPAND, Gtk::FILL|Gtk::EXPAND );
            col++;
            if ( col >= width ) {
                col = 0;
                row++;
            }
        }
        _scroller->add(*stuff);
    }

    _scroller->show_all_children();
    _scroller->queue_draw();
}





} //namespace UI
} //namespace Inkscape


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
