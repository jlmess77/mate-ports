/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 3 "plumacommands.override"
#define NO_IMPORT_PYGOBJECT
#define NO_IMPORT_PYGTK
#include <pygobject.h>
#include <pygtk/pygtk.h>

#include "pluma-commands.h"
#include "pluma-window.h"

void pyplumacommands_register_classes (PyObject *d);
void pyplumacommands_add_constants (PyObject *module, const gchar *strip_prefix);

#line 20 "plumacommands.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyPlumaWindow_Type;
#define PyPlumaWindow_Type (*_PyPlumaWindow_Type)
static PyTypeObject *_PyPlumaDocument_Type;
#define PyPlumaDocument_Type (*_PyPlumaDocument_Type)


/* ---------- forward type declarations ---------- */

#line 32 "plumacommands.c"



/* ----------- functions ----------- */

#line 24 "plumacommands.override"
static PyObject *
_wrap_pluma_commands_load_uri (PyObject *self, PyObject *args, PyObject *kwargs)
{
	static char *kwlist[] = { "window", "uri", "encoding", "line_pos", NULL };
	PyGObject *window;
	char *uri;
	int line_pos = 0;
	PyObject *py_encoding = NULL;
	PlumaEncoding *encoding = NULL;

	if (!PyArg_ParseTupleAndKeywords (args, kwargs, "O!s|Oi:load_uri", 
	                                  kwlist, &PyPlumaWindow_Type, 
	                                  &window, &uri, &py_encoding, 
	                                  &line_pos))
		return NULL;
    
	if (py_encoding != NULL && py_encoding != Py_None)
	{
		if (pyg_boxed_check (py_encoding, PLUMA_TYPE_ENCODING))
			encoding = pyg_boxed_get (py_encoding, PlumaEncoding);
		else
		{
			PyErr_SetString (PyExc_TypeError, 
			                 "encoding should be a PlumaEncoding");
			return NULL;
		}
	}

	pluma_commands_load_uri (PLUMA_WINDOW (window->obj), uri, encoding, 
	                        line_pos);
	Py_INCREF (Py_None);
	return Py_None;
}
#line 72 "plumacommands.c"


#line 59 "plumacommands.override"
static PyObject *
_wrap_pluma_commands_load_uris (PyObject *self, PyObject *args, PyObject *kwargs)
{
	static char *kwlist[] = { "window", "uris", "encoding", "line_pos", NULL };
	PyGObject *window;
	GSList *uris = NULL;
	int line_pos = 0;
	PyObject *py_encoding = NULL;
	PyObject *list;
	PyObject *item;
	PlumaEncoding *encoding = NULL;
	int len;
	int i;

	if (!PyArg_ParseTupleAndKeywords (args, kwargs, "O!O|Oi:load_uri", 
	                                  kwlist, &PyPlumaWindow_Type, 
	                                  &window, &list, &py_encoding, 
	                                  &line_pos))
		return NULL;
    
	if (py_encoding != NULL && py_encoding != Py_None)
	{
		if (pyg_boxed_check (py_encoding, PLUMA_TYPE_ENCODING))
			encoding = pyg_boxed_get (py_encoding, PlumaEncoding);
		else {
			PyErr_SetString (PyExc_TypeError, 
			                 "encoding should be a PlumaEncoding");
			return NULL;
		}
	}

	if (!PySequence_Check (list))
	{
		PyErr_SetString (PyExc_TypeError, 
		                 "second argument must be a sequence");
		return NULL;
	}

	len = PySequence_Length (list);

	for (i = 0; i < len; i++)
	{
		item = PySequence_GetItem (list, i);
		Py_DECREF (item);

		if (!PyString_Check (item))
		{
			PyErr_SetString (PyExc_TypeError,
					 "sequence item not a string");
			g_slist_free (uris);
			return NULL;
		}

		uris = g_slist_prepend (uris, PyString_AsString (item));
	}

	uris = g_slist_reverse (uris);
	pluma_commands_load_uris (PLUMA_WINDOW (window->obj), uris, 
	                          encoding, line_pos);
	g_slist_free (uris);

	Py_INCREF (Py_None);
	return Py_None;
}
#line 140 "plumacommands.c"


static PyObject *
_wrap_pluma_commands_save_document(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "window", "document", NULL };
    PyGObject *window, *document;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!O!:save_document", kwlist, &PyPlumaWindow_Type, &window, &PyPlumaDocument_Type, &document))
        return NULL;
    
    pluma_commands_save_document(PLUMA_WINDOW(window->obj), PLUMA_DOCUMENT(document->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_commands_save_all_documents(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "window", NULL };
    PyGObject *window;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:save_all_documents", kwlist, &PyPlumaWindow_Type, &window))
        return NULL;
    
    pluma_commands_save_all_documents(PLUMA_WINDOW(window->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

const PyMethodDef pyplumacommands_functions[] = {
    { "load_uri", (PyCFunction)_wrap_pluma_commands_load_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "load_uris", (PyCFunction)_wrap_pluma_commands_load_uris, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "save_document", (PyCFunction)_wrap_pluma_commands_save_document, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "save_all_documents", (PyCFunction)_wrap_pluma_commands_save_all_documents, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

/* initialise stuff extension classes */
void
pyplumacommands_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("pluma")) != NULL) {
        _PyPlumaWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Window");
        if (_PyPlumaWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Window from pluma");
            return ;
        }
        _PyPlumaDocument_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Document");
        if (_PyPlumaDocument_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Document from pluma");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import pluma");
        return ;
    }


#line 211 "plumacommands.c"
}
