/**
 * \brief Application Implementation class declaration for Inkscape.  This
 *        class implements the functionality of the window layout, menus,
 *        and signals.
 *
 * Authors:
 *   Bryce W. Harrington <bryce@bryceharrington.org>
 *   Derek P. Moore <derekm@hackunix.org>
 *
 * Copyright (C) 2004 Bryce Harrington
 *
 * Released under GNU GPL.  Read the file 'COPYING' for more information.
 */

// TODO:  This stuff should mostly be moved into Inkscape::UI::View::Edit

#ifndef INKSCAPE_APPLICATION_EDITOR_IMPL_H
#define INKSCAPE_APPLICATION_EDITOR_IMPL_H

#include <gtkmm/box.h>
#include <gtkmm/table.h>
#include <gtkmm/entry.h>
#include <gtkmm/ruler.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/statusbar.h>
#include <gtkmm/actiongroup.h>
#include <gtkmm/uimanager.h>
#include <gtkmm/drawingarea.h>  // TODO: remove this when SVG Canvas is hooked in

#include "application/editor.h"
#include "ui/dialog/dialog-manager.h"
#include "ui/widget/toolbox.h"

struct SPCanvas;
struct SPCanvasItem;
struct SPCanvasGroup;
struct SPCSSAttr;
struct SPDesktopWidget;
struct SPNamedView;

namespace Inkscape {
class Selection;
class Document;

namespace NSApplication {

class Editor;

class Editor::EditorImpl : public Gtk::Window {
public:
    EditorImpl();
    ~EditorImpl();

    // Initialization
    void initActions();
    void initUIManager();
    void initLayout();

    // Actions
    void onActionFileNew();
    void onActionFileOpen();
    void onActionFilePrint();
    void onActionFileQuit();
    void onToolbarItem();
    void onSelectTool();
    void onNodeTool();

    // Menus
    void onMenuItem();

    void onDialogAbout();
    void onDialogAlignAndDistribute();
    void onDialogInkscapePreferences();
    void onDialogDialog();
    void onDialogDocumentProperties();
    void onDialogExport();
    void onDialogExtensionEditor();
    void onDialogFillAndStroke();
    void onDialogFind();
    void onDialogLayerEditor();
    void onDialogMessages();
    void onDialogObjectProperties();
    void onDialogTextProperties();
    void onDialogTransform();
    void onDialogTransformation();
    void onDialogTrace();
    void onDialogXmlEditor();

    void onUriChanged();

protected:
    SPDesktopWidget      *_owner;
    SPNamedView          *_namedview;
    Inkscape::Document   *_document;
    Inkscape::Selection  *_selection;
    sigc::connection     _sel_modified_connection;
    sigc::connection     _sel_changed_connection;

    SPEventContext       *_event_context;

    unsigned int         dkey;

    SPCanvasItem         *_acetate;
    SPCanvasGroup        *_main;
    SPCanvasGroup        *_grid;
    SPCanvasGroup        *_guides;
    SPCanvasItem         *_drawing;
    SPCanvasGroup        *_sketch;
    SPCanvasGroup        *_controls;

    SPCanvasItem         *_table; // outside-of-page background
    SPCanvasItem         *_page; // page background
    SPCanvasItem         *_page_border; // page border

/* TODO
    NR::Matrix d2w, w2d, doc2dt;
*/
    gboolean             is_fullscreen;

    // current style
    SPCSSAttr            *_current_style;

    // Child widgets:
    Gtk::Table           _main_window_table;
    Gtk::VBox            _toolbars_vbox;
    Gtk::HBox            _sub_window_hbox;
    Gtk::Table           _viewport_table;

    UI::Widget::Toolbox  *_tool_ctrl;
    Gtk::Toolbar         *_select_ctrl;
    Gtk::Toolbar         *_uri_ctrl;
    Gtk::Label           _uri_label;
    Gtk::Entry           _uri_entry;
    Gtk::Toolbar         *_node_ctrl;

    Gtk::HRuler          _top_ruler;
    Gtk::VRuler          _left_ruler;
    Gtk::HScrollbar      _bottom_scrollbar;
    Gtk::VScrollbar      _right_scrollbar;
    Gtk::Widget*         _svg_canvas;
    Gtk::Statusbar       _statusbar;

    Glib::RefPtr<Gtk::ActionGroup>  _act_grp;
    Glib::RefPtr<Gtk::UIManager>    _ui_mgr;
    UI::Dialog::DialogManager       _dlg_mgr;

    void initMenuActions();
    void initToolbarActions();
    void initAccelMap();
    void initMenuBar();
    void initCommandsBar();
    void initToolControlsBar();
    void initUriBar();
    void initToolsBar();
    void initBottomScrollbar();
    void initRightScrollbar();
    void initLeftRuler();
    void initTopRuler();
    void initSvgCanvas();
    void initStatusbar();
};

} // namespace NSApplication
} // namespace Inkscape

#endif // INKSCAPE_APPLICATION_EDITOR_IMPL_H

/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=c++:expandtab:shiftwidth=4:tabstop=8:softtabstop=4 :
