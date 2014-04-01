/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 3 "plumautils.override"
#define NO_IMPORT_PYGOBJECT
#define NO_IMPORT_PYGTK
#include <pygobject.h>
#include <pygtk/pygtk.h>

#include "pluma-utils.h"

void pyplumautils_register_classes (PyObject *d);
void pyplumautils_add_constants (PyObject *module, const gchar *strip_prefix);

#line 19 "plumautils.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)
static PyTypeObject *_PyGtkTreeView_Type;
#define PyGtkTreeView_Type (*_PyGtkTreeView_Type)
static PyTypeObject *_PyGtkMenu_Type;
#define PyGtkMenu_Type (*_PyGtkMenu_Type)


/* ---------- forward type declarations ---------- */

#line 33 "plumautils.c"



/* ----------- functions ----------- */

static PyObject *
_wrap_pluma_utils_uri_has_writable_scheme(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:uri_has_writable_scheme", kwlist, &uri))
        return NULL;
    
    ret = pluma_utils_uri_has_writable_scheme(uri);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_utils_uri_has_file_scheme(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:uri_has_file_scheme", kwlist, &uri))
        return NULL;
    
    ret = pluma_utils_uri_has_file_scheme(uri);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_utils_uri_exists(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text_uri", NULL };
    char *text_uri;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:uri_exists", kwlist, &text_uri))
        return NULL;
    
    ret = pluma_utils_uri_exists(text_uri);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_utils_is_valid_uri(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:uri_is_valid", kwlist, &uri))
        return NULL;
    
    ret = pluma_utils_is_valid_uri(uri);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_utils_uri_get_dirname(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:uri_get_dirname", kwlist, &uri))
        return NULL;
    
    ret = pluma_utils_uri_get_dirname(uri);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

#line 24 "plumautils.override"
static PyObject *
_wrap_pluma_utils_menu_position_under_widget (PyObject *self,
					      PyObject *args,
					      PyObject *kwargs)
{
	static char *kwlist[] = { "menu", "widget", NULL };
	PyObject *py_menu, *py_widget;
	GtkMenu *menu;
	GtkWidget *widget;
	gint x, y;
	gboolean push_in;
	PyObject *tuple;
	
	if (!PyArg_ParseTupleAndKeywords (args, kwargs,
					  "O!O!", kwlist,
					  &PyGtkMenu_Type, &py_menu,
					  &PyGtkWidget_Type, &py_widget))
		return NULL;
	
	menu   = GTK_MENU (pygobject_get (py_menu));
	widget = GTK_WIDGET (pygobject_get (py_widget));

	pluma_utils_menu_position_under_widget (menu, &x, &y, &push_in, widget);

	tuple = PyTuple_New (3);
	PyTuple_SetItem (tuple, 0, PyInt_FromLong (x));
	PyTuple_SetItem (tuple, 1, PyInt_FromLong (y));
	PyTuple_SetItem (tuple, 2, PyBool_FromLong (push_in));
	return tuple;
}
#line 155 "plumautils.c"


#line 56 "plumautils.override"
static PyObject *
_wrap_pluma_utils_menu_position_under_tree_view (PyObject *self,
					         PyObject *args,
					         PyObject *kwargs)
{
	static char *kwlist[] = { "menu", "tree_view", NULL };
	PyObject *py_menu, *py_view;
	GtkMenu *menu;
	GtkTreeView *view;
	gint x, y;
	gboolean push_in;
	PyObject *tuple;
	
	if (!PyArg_ParseTupleAndKeywords (args, kwargs,
					  "O!O!", kwlist,
					  &PyGtkMenu_Type, &py_menu,
					  &PyGtkTreeView_Type, &py_view))
		return NULL;
	
	menu = GTK_MENU (pygobject_get (py_menu));
	view = GTK_TREE_VIEW (pygobject_get (py_view));

	pluma_utils_menu_position_under_widget (menu, &x, &y, &push_in, view);

	tuple = PyTuple_New (3);
	PyTuple_SetItem (tuple, 0, PyInt_FromLong (x));
	PyTuple_SetItem (tuple, 1, PyInt_FromLong (y));
	PyTuple_SetItem (tuple, 2, PyBool_FromLong (push_in));
	return tuple;
}
#line 189 "plumautils.c"


const PyMethodDef pyplumautils_functions[] = {
    { "uri_has_writable_scheme", (PyCFunction)_wrap_pluma_utils_uri_has_writable_scheme, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "uri_has_file_scheme", (PyCFunction)_wrap_pluma_utils_uri_has_file_scheme, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "uri_exists", (PyCFunction)_wrap_pluma_utils_uri_exists, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "uri_is_valid", (PyCFunction)_wrap_pluma_utils_is_valid_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "uri_get_dirname", (PyCFunction)_wrap_pluma_utils_uri_get_dirname, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "menu_position_under_widget", (PyCFunction)_wrap_pluma_utils_menu_position_under_widget, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "menu_position_under_tree_view", (PyCFunction)_wrap_pluma_utils_menu_position_under_tree_view, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

/* initialise stuff extension classes */
void
pyplumautils_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkWidget_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Widget");
        if (_PyGtkWidget_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Widget from gtk");
            return ;
        }
        _PyGtkTreeView_Type = (PyTypeObject *)PyObject_GetAttrString(module, "TreeView");
        if (_PyGtkTreeView_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name TreeView from gtk");
            return ;
        }
        _PyGtkMenu_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Menu");
        if (_PyGtkMenu_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Menu from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }


#line 242 "plumautils.c"
}
