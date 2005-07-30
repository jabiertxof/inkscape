#ifndef SEEN_SP_VERBS_H
#define SEEN_SP_VERBS_H

/** \file
 * \brief Frontend to actions
 *
 * Author:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *   Ted Gould <ted@gould.cx>
 *
 * This code is in public domain if done by Lauris
 * This code is GPL if done by Ted
 */

#include "require-config.h"   /* HAVE_GTK_WINDOW_FULLSCREEN */
#include "helper/helper-forward.h"
#include "forward.h"    /* SPView */

/** \brief This anonymous enum is used to provide a list of the Verbs
           which are defined staticly in the verb files.  There may be
           other verbs which are defined dynamically also. */
enum {
    /* Header */
    SP_VERB_INVALID,               /**< A dummy verb to represent doing something wrong. */
    SP_VERB_NONE,                  /**< A dummy verb to represent not having a verb. */
    /* File */
    SP_VERB_FILE_NEW,              /**< A new file in a new window. */
    SP_VERB_FILE_OPEN,             /**< Open a file. */
    SP_VERB_FILE_REVERT,           /**< Revert this file to its original state. */
    SP_VERB_FILE_SAVE,             /**< Save the current file with its saved filename */
    SP_VERB_FILE_SAVE_AS,          /**< Save the current file with a new filename */
    SP_VERB_FILE_PRINT,
    SP_VERB_FILE_VACUUM,
    SP_VERB_FILE_PRINT_DIRECT,
    SP_VERB_FILE_PRINT_PREVIEW,
    SP_VERB_FILE_IMPORT,
    SP_VERB_FILE_EXPORT,
    SP_VERB_FILE_NEXT_DESKTOP,
    SP_VERB_FILE_PREV_DESKTOP,
    SP_VERB_FILE_CLOSE_VIEW,
    SP_VERB_FILE_QUIT,
    /* Edit */
    SP_VERB_EDIT_UNDO,
    SP_VERB_EDIT_REDO,
    SP_VERB_EDIT_CUT,
    SP_VERB_EDIT_COPY,
    SP_VERB_EDIT_PASTE,
    SP_VERB_EDIT_PASTE_STYLE,
    SP_VERB_EDIT_PASTE_IN_PLACE,
    SP_VERB_EDIT_DELETE,
    SP_VERB_EDIT_DUPLICATE,
    SP_VERB_EDIT_CLONE,
    SP_VERB_EDIT_UNLINK_CLONE,
    SP_VERB_EDIT_CLONE_ORIGINAL,
    SP_VERB_EDIT_TILE,
    SP_VERB_EDIT_UNTILE,
    SP_VERB_EDIT_CLEAR_ALL,
    SP_VERB_EDIT_SELECT_ALL,
    SP_VERB_EDIT_SELECT_ALL_IN_ALL_LAYERS,
    SP_VERB_EDIT_INVERT,
    SP_VERB_EDIT_INVERT_IN_ALL_LAYERS,
    SP_VERB_EDIT_DESELECT,
    /* Selection */
    SP_VERB_SELECTION_TO_FRONT,
    SP_VERB_SELECTION_TO_BACK,
    SP_VERB_SELECTION_RAISE,
    SP_VERB_SELECTION_LOWER,
    SP_VERB_SELECTION_GROUP,
    SP_VERB_SELECTION_UNGROUP,
    SP_VERB_SELECTION_TEXTTOPATH,
    SP_VERB_SELECTION_TEXTFROMPATH,
    SP_VERB_SELECTION_REMOVE_KERNS,
    SP_VERB_SELECTION_UNION,
    SP_VERB_SELECTION_INTERSECT,
    SP_VERB_SELECTION_DIFF,
    SP_VERB_SELECTION_SYMDIFF,
    SP_VERB_SELECTION_CUT,
    SP_VERB_SELECTION_SLICE,
    SP_VERB_SELECTION_OFFSET,
    SP_VERB_SELECTION_OFFSET_SCREEN,
    SP_VERB_SELECTION_OFFSET_SCREEN_10,
    SP_VERB_SELECTION_INSET,
    SP_VERB_SELECTION_INSET_SCREEN,
    SP_VERB_SELECTION_INSET_SCREEN_10,
    SP_VERB_SELECTION_DYNAMIC_OFFSET,
    SP_VERB_SELECTION_LINKED_OFFSET,
    SP_VERB_SELECTION_OUTLINE,
    SP_VERB_SELECTION_SIMPLIFY,
    SP_VERB_SELECTION_REVERSE,
    SP_VERB_SELECTION_TRACE,
    SP_VERB_SELECTION_CREATE_BITMAP,
    SP_VERB_SELECTION_COMBINE,
    SP_VERB_SELECTION_BREAK_APART,
    SP_VERB_SELECTION_GRIDTILE,
    /* Layer */
    SP_VERB_LAYER_NEW,
    SP_VERB_LAYER_RENAME,
    SP_VERB_LAYER_NEXT,
    SP_VERB_LAYER_PREV,
    SP_VERB_LAYER_MOVE_TO_NEXT,
    SP_VERB_LAYER_MOVE_TO_PREV,
    SP_VERB_LAYER_TO_TOP,
    SP_VERB_LAYER_TO_BOTTOM,
    SP_VERB_LAYER_RAISE,
    SP_VERB_LAYER_LOWER,
    SP_VERB_LAYER_DELETE,
    /* Object */
    SP_VERB_OBJECT_ROTATE_90_CW,
    SP_VERB_OBJECT_ROTATE_90_CCW,
    SP_VERB_OBJECT_FLATTEN,
    SP_VERB_OBJECT_TO_CURVE,
    SP_VERB_OBJECT_FLOW_TEXT,
    SP_VERB_OBJECT_UNFLOW_TEXT,
    SP_VERB_OBJECT_FLOWTEXT_TO_TEXT,
    SP_VERB_OBJECT_FLIP_HORIZONTAL,
    SP_VERB_OBJECT_FLIP_VERTICAL,
    /* Tools */
    SP_VERB_CONTEXT_SELECT,
    SP_VERB_CONTEXT_NODE,
    SP_VERB_CONTEXT_RECT,
    SP_VERB_CONTEXT_ARC,
    SP_VERB_CONTEXT_STAR,
    SP_VERB_CONTEXT_SPIRAL,
    SP_VERB_CONTEXT_PENCIL,
    SP_VERB_CONTEXT_PEN,
    SP_VERB_CONTEXT_CALLIGRAPHIC,
    SP_VERB_CONTEXT_TEXT,
    SP_VERB_CONTEXT_GRADIENT,
    SP_VERB_CONTEXT_ZOOM,
    SP_VERB_CONTEXT_DROPPER,
    /* Tool preferences */
    SP_VERB_CONTEXT_SELECT_PREFS,
    SP_VERB_CONTEXT_NODE_PREFS,
    SP_VERB_CONTEXT_RECT_PREFS,
    SP_VERB_CONTEXT_ARC_PREFS,
    SP_VERB_CONTEXT_STAR_PREFS,
    SP_VERB_CONTEXT_SPIRAL_PREFS,
    SP_VERB_CONTEXT_PENCIL_PREFS,
    SP_VERB_CONTEXT_PEN_PREFS,
    SP_VERB_CONTEXT_CALLIGRAPHIC_PREFS,
    SP_VERB_CONTEXT_TEXT_PREFS,
    SP_VERB_CONTEXT_GRADIENT_PREFS,
    SP_VERB_CONTEXT_ZOOM_PREFS,
    SP_VERB_CONTEXT_DROPPER_PREFS,
    /* Zooming and desktop settings */
    SP_VERB_ZOOM_IN,
    SP_VERB_ZOOM_OUT,
    SP_VERB_TOGGLE_RULERS,
    SP_VERB_TOGGLE_SCROLLBARS,
    SP_VERB_TOGGLE_GRID,
    SP_VERB_TOGGLE_GUIDES,
    SP_VERB_ZOOM_NEXT,
    SP_VERB_ZOOM_PREV,
    SP_VERB_ZOOM_1_1,
    SP_VERB_ZOOM_1_2,
    SP_VERB_ZOOM_2_1,
#ifdef HAVE_GTK_WINDOW_FULLSCREEN
    SP_VERB_FULLSCREEN,
#endif /* HAVE_GTK_WINDOW_FULLSCREEN */
    SP_VERB_VIEW_NEW,
    SP_VERB_VIEW_NEW_PREVIEW,
    SP_VERB_VIEW_ICON_PREVIEW,
    SP_VERB_ZOOM_PAGE,
    SP_VERB_ZOOM_PAGE_WIDTH,
    SP_VERB_ZOOM_DRAWING,
    SP_VERB_ZOOM_SELECTION,
    /* Dialogs */
    SP_VERB_DIALOG_DISPLAY,
    SP_VERB_DIALOG_NAMEDVIEW,
    SP_VERB_DIALOG_FILL_STROKE,
    SP_VERB_DIALOG_SWATCHES,
    SP_VERB_DIALOG_TRANSFORM,
    SP_VERB_DIALOG_ALIGN_DISTRIBUTE,
    SP_VERB_DIALOG_TEXT,
    SP_VERB_DIALOG_XML_EDITOR,
    SP_VERB_DIALOG_FIND,
    SP_VERB_DIALOG_DEBUG,
    SP_VERB_DIALOG_SCRIPT,
    SP_VERB_DIALOG_TOGGLE,
    SP_VERB_DIALOG_CLONETILER,
    SP_VERB_DIALOG_ITEM,
    /* Help */
    SP_VERB_HELP_KEYS,
    SP_VERB_HELP_ABOUT_EXTENSIONS,
    SP_VERB_HELP_MEMORY,
    SP_VERB_HELP_ABOUT,
    SP_VERB_SHOW_LICENSE,
    /* Tutorials */
    SP_VERB_TUTORIAL_BASIC,
    SP_VERB_TUTORIAL_SHAPES,
    SP_VERB_TUTORIAL_ADVANCED,
    SP_VERB_TUTORIAL_TRACING,
    SP_VERB_TUTORIAL_CALLIGRAPHY,
    SP_VERB_TUTORIAL_DESIGN,
    SP_VERB_TUTORIAL_TIPS,
    /* Effects */
    SP_VERB_EFFECT_LAST,
    SP_VERB_EFFECT_LAST_PREF,
    /* Footer */
    SP_VERB_LAST
};

gchar *sp_action_get_title (const SPAction *action);

#include <map>

namespace Inkscape {

/** \brief A class to represent things the user can do.  In many ways
           these are 'action factories' as they are used to create
           individual actions that are based on a given view.
*/
class Verb {
private:
    /** \brief An easy to use defition of the table of verbs by code. */
    typedef std::map<unsigned int, Inkscape::Verb *> VerbTable;
    /** \brief A table of all the dynamically created verbs. */
    static VerbTable _verbs;
    /** \brief The table of statically created verbs which are mostly
               'base verbs'. */
    static Verb * _base_verbs[SP_VERB_LAST + 1];
    /* Plus one because there is an entry for SP_VERB_LAST */

    /** \brief A simple typedef to make using the action table easier. */
    typedef std::map<SPView *, SPAction *> ActionTable;
    /** \brief A list of all the actions that have been created for this
               verb.  It is referenced by the view that they are created for. */
    ActionTable * _actions;

    /** \brief A unique textual ID for the verb. */
    gchar const * _id;
    /** \brief The full name of the verb.  (shown on menu entries) */
    gchar const * _name;
    /** \brief Tooltip for the verb. */
    gchar const * _tip;
    /** \brief Name of the image that represents the verb. */
    gchar const * _image;
    /** \brief Unique numerical representation of the verb.  In most cases
               it is a value from the anonymous enum at the top of this
               file. */
    unsigned int  _code;

    /** \brief Whether this verb is set to default to sensitive or
               insensitive when new actions are created. */
    bool _default_sensitive;
protected:
    /** \brief Allows for preliminary setting of the \c _default_sensitive
               value without effecting existing actions
        \param in_val New value

        This function is mostly used at initialization where there are
        not actions to effect.  I can't think of another case where it
        should be used.
    */
    bool set_default_sensitive (bool in_val) { return _default_sensitive = in_val; }
public:
    /** \brief Accessor to get the \c _default_sensitive value */
    bool get_default_sensitive (void) { return _default_sensitive; }

public:
    /** \brief Accessor to get the internal variable. */
    unsigned int get_code (void) { return _code; }
    /** \brief Accessor to get the internal variable. */
    gchar const * get_id (void) { return _id; }

protected:
    SPAction * make_action_helper (SPView * view, SPActionEventVector * vector, void * in_pntr = NULL);
    virtual SPAction * make_action (SPView * view);

public:
    /** \brief Inititalizes the Verb with the parameters
        \param code  Goes to \c _code
        \param id    Goes to \c _id
        \param name  Goes to \c _name
        \param tip   Goes to \c _tip
        \param image Goes to \c _image

        This function also sets \c _actions to NULL.

        \warning NO DATA IS COPIED BY CALLING THIS FUNCTION.

        In many respects this is very bad object oriented design, but it
        is done for a reason.  All verbs today are of two types: 1) static
        or 2) created for extension.  In the static case all of the
        strings are constants in the code, and thus don't really need to
        be copied.  In the extensions case the strings are identical to
        the ones already created in the extension object, copying them
        would be a waste of memory.
    */
    Verb(const unsigned int code,
         gchar const * id,
         gchar const * name,
         gchar const * tip,
         gchar const * image) :
        _actions(NULL), _id(id), _name(name), _tip(tip), _image(image), _code(code), _default_sensitive(true) {
    }
    Verb (gchar const * id, gchar const * name, gchar const * tip, gchar const * image);
    virtual ~Verb (void);

    SPAction * get_action(SPView * view);

private:
    static Verb * get_search (unsigned int code);
public:
    /** \brief A function to turn a code into a verb.
        \param  code  The code to be translated
        \return A pointer to a verb object or a NULL if not found.

        This is an inline function to translate the codes which are
        static quickly.  This should optimize into very quick code
        everywhere which hard coded \c codes are used.  In the case
        where the \c code is not static the \c get_search function
        is used.
    */
    static Verb * get (unsigned int code) {
        if (code <= SP_VERB_LAST) {
            return _base_verbs[code];
        } else {
            return get_search(code);
        }
    }

    static void delete_all_view (SPView * view);
    void delete_view (SPView * view);

    void sensitive (SPDocument * in_doc = NULL, bool in_sensitive = true);
}; /* Verb class */


}  /* Inkscape namespace */

#endif // SEEN_SP_VERBS_H

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
