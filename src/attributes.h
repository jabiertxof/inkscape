#ifndef __SP_ATTRIBUTES_H__
#define __SP_ATTRIBUTES_H__

/** \file
 * Lookup dictionary for attributes/properties.
 */
/*
 * Author:
 *   Lauris Kaplinski <lauris@kaplinski.com>
 *
 * Copyright (C) 2006 Johan Engelen <johan@shouraizou.nl>
 * Copyright (C) 2002 Lauris Kaplinski
 *
 * Released under GNU GPL, read the file 'COPYING' for more information
 */
#include <glib/gtypes.h>
#include <glib/gmessages.h>

unsigned int sp_attribute_lookup(gchar const *key);
unsigned char const *sp_attribute_name(unsigned int id);

/**
 * True iff k is a property in SVG, i.e. something that can be written either in a style attribute
 * or as its own XML attribute.
 */
#define SP_ATTRIBUTE_IS_CSS(k) (((k) >= SP_PROP_INKSCAPE_FONT_SPEC) && ((k) <= SP_PROP_TEXT_RENDERING))

enum SPAttributeEnum {
    SP_ATTR_INVALID,  ///< Must have value 0.
    /* SPObject */
    SP_ATTR_ID,
    SP_ATTR_INKSCAPE_COLLECT,
    SP_ATTR_INKSCAPE_LABEL,
    /* SPItem */
    SP_ATTR_TRANSFORM,
    SP_ATTR_SODIPODI_INSENSITIVE,
    SP_ATTR_SODIPODI_NONPRINTABLE,
    SP_ATTR_CONNECTOR_AVOID,
    SP_ATTR_CONNECTION_POINTS,
    SP_ATTR_STYLE,
    SP_ATTR_TRANSFORM_CENTER_X,
    SP_ATTR_TRANSFORM_CENTER_Y,
    SP_ATTR_INKSCAPE_PATH_EFFECT,
    /* SPAnchor */
    SP_ATTR_XLINK_HREF,
    SP_ATTR_XLINK_TYPE,
    SP_ATTR_XLINK_ROLE,
    SP_ATTR_XLINK_ARCROLE,
    SP_ATTR_XLINK_TITLE,
    SP_ATTR_XLINK_SHOW,
    SP_ATTR_XLINK_ACTUATE,
    SP_ATTR_TARGET,
    /* SPGroup */
    SP_ATTR_INKSCAPE_GROUPMODE,
    /* SPRoot */
    SP_ATTR_VERSION,
    SP_ATTR_WIDTH,
    SP_ATTR_HEIGHT,
    SP_ATTR_VIEWBOX,
    SP_ATTR_PRESERVEASPECTRATIO,
    SP_ATTR_INKSCAPE_VERSION,
    SP_ATTR_ONLOAD,
    /* SPNamedView */
    SP_ATTR_VIEWONLY,
    SP_ATTR_SHOWGUIDES,
    SP_ATTR_SHOWGRIDS,
    SP_ATTR_GRIDTOLERANCE,
    SP_ATTR_GUIDETOLERANCE,
    SP_ATTR_OBJECTTOLERANCE,
    SP_ATTR_GUIDECOLOR,
    SP_ATTR_GUIDEOPACITY,
    SP_ATTR_GUIDEHICOLOR,
    SP_ATTR_GUIDEHIOPACITY,
    SP_ATTR_SHOWBORDER,
    SP_ATTR_SHOWPAGESHADOW,
    SP_ATTR_BORDERLAYER,
    SP_ATTR_BORDERCOLOR,
    SP_ATTR_BORDEROPACITY,
    SP_ATTR_PAGECOLOR,
    SP_ATTR_FIT_MARGIN_TOP,
    SP_ATTR_FIT_MARGIN_LEFT,
    SP_ATTR_FIT_MARGIN_RIGHT,
    SP_ATTR_FIT_MARGIN_BOTTOM,
    SP_ATTR_INKSCAPE_PAGEOPACITY,
    SP_ATTR_INKSCAPE_PAGESHADOW,
    SP_ATTR_INKSCAPE_ZOOM,
    SP_ATTR_INKSCAPE_CX,
    SP_ATTR_INKSCAPE_CY,
    SP_ATTR_INKSCAPE_WINDOW_WIDTH,
    SP_ATTR_INKSCAPE_WINDOW_HEIGHT,
    SP_ATTR_INKSCAPE_WINDOW_X,
    SP_ATTR_INKSCAPE_WINDOW_Y,
    SP_ATTR_INKSCAPE_WINDOW_MAXIMIZED,
    SP_ATTR_INKSCAPE_SNAP_GLOBAL,
    SP_ATTR_INKSCAPE_SNAP_BBOX,
    SP_ATTR_INKSCAPE_SNAP_NODE,
    SP_ATTR_INKSCAPE_SNAP_OTHERS,
    //SP_ATTR_INKSCAPE_SNAP_FROM_GUIDE,
    SP_ATTR_INKSCAPE_SNAP_ROTATION_CENTER,
    SP_ATTR_INKSCAPE_SNAP_GRID,
    SP_ATTR_INKSCAPE_SNAP_TO_GUIDE,
    SP_ATTR_INKSCAPE_SNAP_NODE_SMOOTH,
    SP_ATTR_INKSCAPE_SNAP_LINE_MIDPOINT,
    SP_ATTR_INKSCAPE_SNAP_OBJECT_MIDPOINT,
    SP_ATTR_INKSCAPE_SNAP_TEXT_BASELINE,
    SP_ATTR_INKSCAPE_SNAP_BBOX_EDGE_MIDPOINT,
    SP_ATTR_INKSCAPE_SNAP_BBOX_MIDPOINT,
    SP_ATTR_INKSCAPE_SNAP_PATH_INTERSECTION,
    SP_ATTR_INKSCAPE_SNAP_PATH,
    SP_ATTR_INKSCAPE_SNAP_NODE_CUSP,
    SP_ATTR_INKSCAPE_SNAP_BBOX_EDGE,
    SP_ATTR_INKSCAPE_SNAP_BBOX_CORNER,
    SP_ATTR_INKSCAPE_SNAP_PAGE_BORDER,
    SP_ATTR_INKSCAPE_CURRENT_LAYER,
    SP_ATTR_INKSCAPE_DOCUMENT_UNITS,
    SP_ATTR_UNITS,
    SP_ATTR_INKSCAPE_CONNECTOR_SPACING,
    /* SPColorProfile */
    SP_ATTR_LOCAL,
    SP_ATTR_NAME,
    SP_ATTR_RENDERING_INTENT,
    /* SPGuide */
    SP_ATTR_ORIENTATION,
    SP_ATTR_POSITION,
    /* SPImage */
    SP_ATTR_X,
    SP_ATTR_Y,
    /* SPPath */
    SP_ATTR_D,
    SP_ATTR_INKSCAPE_ORIGINAL_D,
    SP_ATTR_CONNECTOR_TYPE,
    SP_ATTR_CONNECTOR_CURVATURE,
    SP_ATTR_CONNECTION_START,
    SP_ATTR_CONNECTION_END,
    SP_ATTR_CONNECTION_START_POINT,
    SP_ATTR_CONNECTION_END_POINT,
    /* SPRect */
    SP_ATTR_RX,
    SP_ATTR_RY,
    /* Box3D */
    SP_ATTR_INKSCAPE_BOX3D_PERSPECTIVE_ID,
    SP_ATTR_INKSCAPE_BOX3D_CORNER0, // "upper left front" corner (as a point in 3-space)
    SP_ATTR_INKSCAPE_BOX3D_CORNER7, // "lower right rear" corner (as a point in 3-space)
    /* Box3DSide */
    SP_ATTR_INKSCAPE_BOX3D_SIDE_TYPE,
    /* Persp3D */
    SP_ATTR_INKSCAPE_PERSP3D,
    SP_ATTR_INKSCAPE_PERSP3D_VP_X,
    SP_ATTR_INKSCAPE_PERSP3D_VP_Y,
    SP_ATTR_INKSCAPE_PERSP3D_VP_Z,
    SP_ATTR_INKSCAPE_PERSP3D_ORIGIN,
    /* SPEllipse */
    SP_ATTR_R,
    SP_ATTR_CX,
    SP_ATTR_CY,
    SP_ATTR_SODIPODI_CX,
    SP_ATTR_SODIPODI_CY,
    SP_ATTR_SODIPODI_RX,
    SP_ATTR_SODIPODI_RY,
    SP_ATTR_SODIPODI_START,
    SP_ATTR_SODIPODI_END,
    SP_ATTR_SODIPODI_OPEN,
    /* SPStar */
    SP_ATTR_SODIPODI_SIDES,
    SP_ATTR_SODIPODI_R1,
    SP_ATTR_SODIPODI_R2,
    SP_ATTR_SODIPODI_ARG1,
    SP_ATTR_SODIPODI_ARG2,
    SP_ATTR_INKSCAPE_FLATSIDED,
    SP_ATTR_INKSCAPE_ROUNDED,
    SP_ATTR_INKSCAPE_RANDOMIZED,
    /* SPSpiral */
    SP_ATTR_SODIPODI_EXPANSION,
    SP_ATTR_SODIPODI_REVOLUTION,
    SP_ATTR_SODIPODI_RADIUS,
    SP_ATTR_SODIPODI_ARGUMENT,
    SP_ATTR_SODIPODI_T0,
    /* SPOffset */
    SP_ATTR_SODIPODI_ORIGINAL,
    SP_ATTR_INKSCAPE_ORIGINAL,
    SP_ATTR_INKSCAPE_HREF,
    SP_ATTR_INKSCAPE_RADIUS,
    /* SPLine */
    SP_ATTR_X1,
    SP_ATTR_Y1,
    SP_ATTR_X2,
    SP_ATTR_Y2,
    /* SPPolyline */
    SP_ATTR_POINTS,
    /* SPTSpan */
    SP_ATTR_DX,
    SP_ATTR_DY,
    SP_ATTR_ROTATE,
    SP_ATTR_SODIPODI_ROLE,
    /* SPText */
    SP_ATTR_SODIPODI_LINESPACING,
    /* SPTextPath */
    SP_ATTR_STARTOFFSET,
    /* SPStop */
    SP_ATTR_OFFSET,
    /* SPFilter */
    SP_ATTR_FILTERUNITS,
    SP_ATTR_PRIMITIVEUNITS,
    SP_ATTR_FILTERRES,
    /* Filter primitives common */
    SP_ATTR_IN,
    SP_ATTR_RESULT,
    /*feBlend*/
    SP_ATTR_MODE,
    SP_ATTR_IN2,
    /*feColorMatrix*/
    SP_ATTR_TYPE,
    SP_ATTR_VALUES,
    /*feComponentTransfer*/
    //SP_ATTR_TYPE,
    SP_ATTR_TABLEVALUES,
    SP_ATTR_SLOPE,
    SP_ATTR_INTERCEPT,
    SP_ATTR_AMPLITUDE,
    SP_ATTR_EXPONENT,
    //SP_ATTR_OFFSET,
    /*feComposite*/
    SP_ATTR_OPERATOR,
    SP_ATTR_K1,
    SP_ATTR_K2,
    SP_ATTR_K3,
    SP_ATTR_K4,
    //SP_ATTR_IN2,
    /*feConvolveMatrix*/
    SP_ATTR_ORDER,
    SP_ATTR_KERNELMATRIX,
    SP_ATTR_DIVISOR,
    SP_ATTR_BIAS,
    SP_ATTR_TARGETX,
    SP_ATTR_TARGETY,
    SP_ATTR_EDGEMODE,
    SP_ATTR_KERNELUNITLENGTH,
    SP_ATTR_PRESERVEALPHA,
    /*feDiffuseLighting*/
    SP_ATTR_SURFACESCALE,
    SP_ATTR_DIFFUSECONSTANT,
    //SP_ATTR_KERNELUNITLENGTH,
    /*feDisplacementMap*/
    SP_ATTR_SCALE,
    SP_ATTR_XCHANNELSELECTOR,
    SP_ATTR_YCHANNELSELECTOR,
    //SP_ATTR_IN2,
    /*feDistantLight*/
    SP_ATTR_AZIMUTH,
    SP_ATTR_ELEVATION,
    /*fePointLight*/
    SP_ATTR_Z,
    /*feSpotLight*/
    SP_ATTR_POINTSATX,
    SP_ATTR_POINTSATY,
    SP_ATTR_POINTSATZ,
    SP_ATTR_LIMITINGCONEANGLE,
    /*feFlood*/
    SP_ATTR_FLOODCOLOR,
    SP_ATTR_FLOODOPACITY,
    /* SPGaussianBlur */
    SP_ATTR_STDDEVIATION,
    /*feImage*/
    /*feMerge*/
    /*feMorphology*/
    //SP_ATTR_OPERATOR,
    SP_ATTR_RADIUS,
    /*feOffset*/
    //SP_ATTR_DX,
    //SP_ATTR_DY,
    /*feSpecularLighting*/
    //SP_ATTR_SURFACESCALE,
    SP_ATTR_SPECULARCONSTANT,
    SP_ATTR_SPECULAREXPONENT,
    /*feTile*/
    /*feTurbulence*/
    SP_ATTR_BASEFREQUENCY,
    SP_ATTR_NUMOCTAVES,
    SP_ATTR_SEED,
    SP_ATTR_STITCHTILES,
    //SP_ATTR_TYPE,
    /* SPGradient */
    SP_ATTR_GRADIENTUNITS,
    SP_ATTR_GRADIENTTRANSFORM,
    SP_ATTR_SPREADMETHOD,
    SP_ATTR_OSB_SWATCH,
    /* SPRadialGradient */
    SP_ATTR_FX,
    SP_ATTR_FY,
    /* SPPattern */
    SP_ATTR_PATTERNUNITS,
    SP_ATTR_PATTERNCONTENTUNITS,
    SP_ATTR_PATTERNTRANSFORM,
    /* SPClipPath */
    SP_ATTR_CLIPPATHUNITS,
    /* SPMask */
    SP_ATTR_MASKUNITS,
    SP_ATTR_MASKCONTENTUNITS,
    /* SPMarker */
    SP_ATTR_MARKERUNITS,
    SP_ATTR_REFX,
    SP_ATTR_REFY,
    SP_ATTR_MARKERWIDTH,
    SP_ATTR_MARKERHEIGHT,
    SP_ATTR_ORIENT,
    /* SPStyleElem */
    //SP_ATTR_TYPE,
    /* Animations */
    SP_ATTR_ATTRIBUTENAME,
    SP_ATTR_ATTRIBUTETYPE,
    SP_ATTR_BEGIN,
    SP_ATTR_DUR,
    SP_ATTR_END,
    SP_ATTR_MIN,
    SP_ATTR_MAX,
    SP_ATTR_RESTART,
    SP_ATTR_REPEATCOUNT,
    SP_ATTR_REPEATDUR,
    /* Interpolating animations */
    SP_ATTR_CALCMODE,
    //SP_ATTR_VALUES,
    SP_ATTR_KEYTIMES,
    SP_ATTR_KEYSPLINES,
    SP_ATTR_FROM,
    SP_ATTR_TO,
    SP_ATTR_BY,
    SP_ATTR_ADDITIVE,
    SP_ATTR_ACCUMULATE,

    /* SVGFonts */
    /* SPFont */
    SP_ATTR_HORIZ_ORIGIN_X,
    SP_ATTR_HORIZ_ORIGIN_Y,
    SP_ATTR_HORIZ_ADV_X,
    SP_ATTR_VERT_ORIGIN_X,
    SP_ATTR_VERT_ORIGIN_Y,
    SP_ATTR_VERT_ADV_Y,

    SP_ATTR_UNICODE,
    SP_ATTR_GLYPH_NAME,
    //SP_ATTR_ORIENTATION,
    SP_ATTR_ARABIC_FORM,
    SP_ATTR_LANG,

    /*<hkern> and <vkern>*/
    SP_ATTR_U1,
    SP_ATTR_G1,
    SP_ATTR_U2,
    SP_ATTR_G2,
    SP_ATTR_K,

    /*<font-face>*/
//    SP_ATTR_FONT_FAMILY,
//    SP_ATTR_FONT_STYLE,
//    SP_ATTR_FONT_VARIANT,
//    SP_ATTR_FONT_WEIGHT,
//    SP_ATTR_FONT_STRETCH,
//    SP_ATTR_FONT_SIZE,
    SP_ATTR_UNICODE_RANGE,
    SP_ATTR_UNITS_PER_EM,
    SP_ATTR_PANOSE_1,
    SP_ATTR_STEMV,
    SP_ATTR_STEMH,
    //SP_ATTR_SLOPE,
    SP_ATTR_CAP_HEIGHT,
    SP_ATTR_X_HEIGHT,
    SP_ATTR_ACCENT_HEIGHT,
    SP_ATTR_ASCENT,
    SP_ATTR_DESCENT,
    SP_ATTR_WIDTHS,
    SP_ATTR_BBOX,
    SP_ATTR_IDEOGRAPHIC,
    SP_ATTR_ALPHABETIC,
    SP_ATTR_MATHEMATICAL,
    SP_ATTR_HANGING,
    SP_ATTR_V_IDEOGRAPHIC,
    SP_ATTR_V_ALPHABETIC,
    SP_ATTR_V_MATHEMATICAL,
    SP_ATTR_V_HANGING,
    SP_ATTR_UNDERLINE_POSITION,
    SP_ATTR_UNDERLINE_THICKNESS,
    SP_ATTR_STRIKETHROUGH_POSITION,
    SP_ATTR_STRIKETHROUGH_THICKNESS,
    SP_ATTR_OVERLINE_POSITION,
    SP_ATTR_OVERLINE_THICKNESS,

    /* XML */
    SP_ATTR_XML_SPACE,

    /* typeset */
    SP_ATTR_TEXT_NOMARKUP,
    SP_ATTR_TEXT_PANGOMARKUP,
    SP_ATTR_TEXT_INSHAPE,
    SP_ATTR_TEXT_ONPATH,
    SP_ATTR_TEXT_INBOX,
    SP_ATTR_TEXT_INCOLUMN,
    SP_ATTR_TEXT_EXCLUDE,
    SP_ATTR_LAYOUT_OPTIONS,

    /* CSS2 */
    /* Custom full font name because Font stuff below is inadequate */
    SP_PROP_INKSCAPE_FONT_SPEC,
    /* Font */
    SP_PROP_FONT,
    SP_PROP_FONT_FAMILY,
    SP_PROP_FONT_SIZE,
    SP_PROP_FONT_SIZE_ADJUST,
    SP_PROP_FONT_STRETCH,
    SP_PROP_FONT_STYLE,
    SP_PROP_FONT_VARIANT,
    SP_PROP_FONT_WEIGHT,
    /* Text */
    SP_PROP_TEXT_INDENT,
    SP_PROP_TEXT_ALIGN,
    SP_PROP_TEXT_DECORATION,
    SP_PROP_LINE_HEIGHT,
    SP_PROP_LETTER_SPACING,
    SP_PROP_WORD_SPACING,
    SP_PROP_TEXT_TRANSFORM,
    /* text (css3) */
    SP_PROP_DIRECTION,
    SP_PROP_BLOCK_PROGRESSION,
    SP_PROP_WRITING_MODE,
    SP_PROP_UNICODE_BIDI,
    SP_PROP_ALIGNMENT_BASELINE,
    SP_PROP_BASELINE_SHIFT,
    SP_PROP_DOMINANT_BASELINE,
    SP_PROP_GLYPH_ORIENTATION_HORIZONTAL,
    SP_PROP_GLYPH_ORIENTATION_VERTICAL,
    SP_PROP_KERNING,
    SP_PROP_TEXT_ANCHOR,
    /* Misc */
    SP_PROP_CLIP,
    SP_PROP_COLOR,
    SP_PROP_CURSOR,
    SP_PROP_DISPLAY,
    SP_PROP_OVERFLOW,
    SP_PROP_VISIBILITY,
    /* SVG */
    /* Clip/Mask */
    SP_PROP_CLIP_PATH,
    SP_PROP_CLIP_RULE,
    SP_PROP_MASK,
    SP_PROP_OPACITY,
    /* Filter */
    SP_PROP_ENABLE_BACKGROUND,
    SP_PROP_FILTER,
    SP_PROP_FLOOD_COLOR,
    SP_PROP_FLOOD_OPACITY,
    SP_PROP_LIGHTING_COLOR,
    /* Gradient */
    SP_PROP_STOP_COLOR,
    SP_PROP_STOP_OPACITY,
    /* Interactivity */
    SP_PROP_POINTER_EVENTS,
    /* Paint */
    SP_PROP_COLOR_INTERPOLATION,
    SP_PROP_COLOR_INTERPOLATION_FILTERS,
    SP_PROP_COLOR_PROFILE,
    SP_PROP_COLOR_RENDERING,
    SP_PROP_FILL,
    SP_PROP_FILL_OPACITY,
    SP_PROP_FILL_RULE,
    SP_PROP_IMAGE_RENDERING,
    SP_PROP_MARKER,
    SP_PROP_MARKER_END,
    SP_PROP_MARKER_MID,
    SP_PROP_MARKER_START,
    SP_PROP_SHAPE_RENDERING,
    SP_PROP_STROKE,
    SP_PROP_STROKE_DASHARRAY,
    SP_PROP_STROKE_DASHOFFSET,
    SP_PROP_STROKE_LINECAP,
    SP_PROP_STROKE_LINEJOIN,
    SP_PROP_STROKE_MITERLIMIT,
    SP_PROP_STROKE_OPACITY,
    SP_PROP_STROKE_WIDTH,
    SP_PROP_TEXT_RENDERING,
    /* Conditional */
    SP_PROP_SYSTEM_LANGUAGE,
    SP_PROP_REQUIRED_FEATURES,
    SP_PROP_REQUIRED_EXTENSIONS,
    /* LivePathEffect */
    SP_PROP_PATH_EFFECT,
};

#endif


/*
  Local Variables:
  mode:c++
  c-file-style:"stroustrup"
  c-file-offsets:((innamespace . 0)(inline-open . 0)(case-label . +))
  indent-tabs-mode:nil
  fill-column:99
  End:
*/
// vim: filetype=cpp:expandtab:shiftwidth=4:tabstop=8:softtabstop=4:fileencoding=utf-8:textwidth=99 :
