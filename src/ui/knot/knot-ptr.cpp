// SPDX-License-Identifier: GPL-2.0-or-later
/** @file
 * TODO: insert short description here
 *//*
 * Authors: see git history
 *
 * Copyright (C) 2018 Authors
 * Released under GNU GPL v2+, read the file 'COPYING' for more information.
 */
#include <algorithm>
#include <glib.h>
#include <list>
#include "knot-ptr.h"

static std::list<void*> deleted_knots;

void knot_deleted_callback(void* knot) {
    if (std::find(deleted_knots.begin(), deleted_knots.end(), knot) == deleted_knots.end()) {
        deleted_knots.push_back(knot);
    }
}

void knot_created_callback(void* knot) {
    std::list<void*>::iterator it = std::find(deleted_knots.begin(), deleted_knots.end(), knot);
    if (it != deleted_knots.end()) {
        deleted_knots.erase(it);
    }
}

void check_if_knot_deleted(void* knot) {
    if (std::find(deleted_knots.begin(), deleted_knots.end(), knot) != deleted_knots.end()) {
        g_warning("Accessed knot after it was freed at %p", knot);
    }
}
