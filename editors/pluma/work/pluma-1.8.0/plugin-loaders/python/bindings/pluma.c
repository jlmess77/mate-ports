/* -- THIS FILE IS GENERATED - DO NOT EDIT *//* -*- Mode: C; c-basic-offset: 4 -*- */

#include <Python.h>



#line 3 "pluma.override"
#include <pygobject.h>
#include <pygtk/pygtk.h>

#include <pluma/pluma-language-manager.h>
#include <pluma/pluma-plugin.h>
#include <pluma/pluma-app.h>
#include <pluma/pluma-encodings.h>
#include <pluma/pluma-enum-types.h>
#include <pluma/pluma-statusbar.h>
#include <pluma/pluma-debug.h>
#include <pluma/pluma-help.h>

#include "pluma-plugin-python.h"

void pypluma_register_classes (PyObject *d); 
void pypluma_add_constants (PyObject *module, const gchar *strip_prefix);

static PyObject *
_helper_wrap_gobject_glist (const GList *list)
{
    PyObject *py_list;
    const GList *tmp;

    if ((py_list = PyList_New(0)) == NULL) {
        return NULL;
    }
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        PyObject *py_obj = pygobject_new(G_OBJECT(tmp->data));

        if (py_obj == NULL) {
            Py_DECREF(py_list);
            return NULL;
        }
        PyList_Append(py_list, py_obj);
        Py_DECREF(py_obj);
    }
    return py_list;
}

static PyObject *
_helper_wrap_gobject_gslist (const GSList *list)
{
    PyObject *py_list;
    const GSList *tmp;

    if ((py_list = PyList_New(0)) == NULL) {
        return NULL;
    }
    for (tmp = list; tmp != NULL; tmp = tmp->next) {
        PyObject *py_obj = pygobject_new(G_OBJECT(tmp->data));

        if (py_obj == NULL) {
            Py_DECREF(py_list);
            return NULL;
        }
        PyList_Append(py_list, py_obj);
        Py_DECREF(py_obj);
    }
    return py_list;
}

#line 3 "plumaplugin.override"
#include <pluma/pluma-plugin.h>
#include <pluma/pluma-window.h>

#line 3 "plumamessage.override"

#include <pluma/pluma-message-bus.h>
#include <pluma/pluma-message.h>

static GType
_helper_wrap_get_gtype_from_pytype (PyObject *pytype)
{
    PyTypeObject *type = (PyTypeObject *)pytype;
    
    if (type == &PyList_Type || type == &PyTuple_Type)
    	return G_TYPE_STRV;

    return pyg_type_from_object (pytype);
}

static gchar *
_helper_wrap_get_string (PyObject *obj)
{
	PyObject *str;
	gchar *result;
	
	str = PyObject_Str (obj);
	
	if (!str)
		return NULL;
	
	result = g_strdup (PyString_AsString (str));
	Py_DECREF (str);
	
	return result;
}

static int
_helper_wrap_list_to_gvalue (GValue *gvalue, PyObject *pyvalue)
{
	int num;
	gchar **lst;
	gint i;
	
	num = PySequence_Size (pyvalue);
	lst = g_new0 (gchar *, num + 1);
	
	for (i = 0; i < num; i++)
	{
		lst[i] = _helper_wrap_get_string (PySequence_GetItem (pyvalue, i));
		
		if (lst[i] == NULL)
		{
			g_strfreev (lst);
			return 1;
		}
	}
	
	g_value_set_boxed (gvalue, lst);
	g_strfreev (lst);
	
	return 0;
}

static int
_helper_wrap_get_gvalue_from_pyobject (GValue *gvalue, PyObject *pyvalue)
{
	if (pyvalue->ob_type == &PyList_Type || pyvalue->ob_type == &PyTuple_Type)
		return _helper_wrap_list_to_gvalue (gvalue, pyvalue);

	return pyg_value_from_pyobject(gvalue, pyvalue);
}

static int
_helper_wrap_message_set_value(PlumaMessage *message, PyObject *pykey, PyObject *pyvalue)
{
    gchar *key;
    GType gtype;
    GValue value = {0,};

    key = _helper_wrap_get_string(pykey);
    
    if (key == NULL)
        return 0;

    gtype = pluma_message_get_key_type(message, key);
    
    if (gtype == 0) {
        PyErr_SetString(PyExc_TypeError, "invalid key");
        g_free (key);
        return 0;
    }

    g_value_init(&value, gtype);
    
    if (_helper_wrap_get_gvalue_from_pyobject (&value, pyvalue)) {
        PyErr_SetString(PyExc_TypeError,
                        "value is of the wrong type for this key");
        g_free (key);
        return 0;
    }

    pluma_message_set_value(message, key, &value);
    g_value_unset(&value);
    g_free (key);
    
    return 1;
}

typedef void (*ParsePairFunc)(PyObject *key, PyObject *value, gpointer user_data);

static void
_helper_parse_pairs_dict (PyObject *dict, ParsePairFunc func, gpointer user_data)
{
    if (!dict)
        return;
    
    PyObject *key, *value;
    Py_ssize_t i = 0;
    
    while (PyDict_Next(dict, &i, &key, &value))
    {
        func(key, value, user_data);
    }
}

static void
_helper_parse_pairs(PyObject *args, PyObject *kwargs, ParsePairFunc func, gpointer user_data)
{
    guint len;
    guint i;
    
    len = PyTuple_Size(args);
    
    for (i = 0; i < len; ++i)
    {
    	PyObject *d = PyTuple_GetItem(args, i);
    	
    	if (PyDict_Check(d))
            _helper_parse_pairs_dict(d, func, user_data);
    }
  
    _helper_parse_pairs_dict(kwargs, func, user_data);  
}

static void
_helper_message_set(PyObject *key, PyObject *value, PlumaMessage *message)
{
    _helper_wrap_message_set_value(message, key, value);
}

static void
_helper_message_set_values(PlumaMessage *message, PyObject *args, PyObject *kwargs)
{
    _helper_parse_pairs(args, kwargs, (ParsePairFunc)_helper_message_set, message);
}

static PlumaMessage *
_helper_wrap_create_message(PlumaMessageBus *bus, PyObject *args, PyObject *kwargs)
{
    PyObject *pypath, *pymethod, *pydict;
    
    if (!PyArg_ParseTuple(args, "OO|O:PlumaMessage.create", &pypath, &pymethod, &pydict))
        return NULL;
    
    gchar *object_path = _helper_wrap_get_string(pypath);
    gchar *method = _helper_wrap_get_string(pymethod);
    
    PlumaMessageType *message_type = pluma_message_bus_lookup (bus, object_path, method);
    PlumaMessage *message;
     
    if (message_type)
    {
        message = pluma_message_type_instantiate(message_type, NULL);
        _helper_message_set_values(message, args, kwargs);
    }
    else
    {
    	PyErr_SetString(PyExc_StandardError, "Message type does not exist");
        message = NULL;
    }
    
    g_free(object_path);
    g_free(method);
    
    return message;
}

typedef struct {
    PyObject *func;
    PyObject *data;
} PyPlumaCustomNotify;

static void 
pypluma_custom_destroy_notify(gpointer user_data)
{
    PyPlumaCustomNotify *cunote = user_data;
    PyGILState_STATE state;
    
    g_return_if_fail(user_data);
    state = pyg_gil_state_ensure();
    Py_XDECREF(cunote->func);
    Py_XDECREF(cunote->data);
    pyg_gil_state_release(state);
    
    g_free(cunote);
}
#line 277 "pluma.c"


/* ---------- types from other modules ---------- */
static PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)
static PyTypeObject *_PyGObject_Type;
#define PyGObject_Type (*_PyGObject_Type)
static PyTypeObject *_PyGdkScreen_Type;
#define PyGdkScreen_Type (*_PyGdkScreen_Type)
static PyTypeObject *_PyGtkVBox_Type;
#define PyGtkVBox_Type (*_PyGtkVBox_Type)
static PyTypeObject *_PyGtkWindow_Type;
#define PyGtkWindow_Type (*_PyGtkWindow_Type)
static PyTypeObject *_PyGtkImage_Type;
#define PyGtkImage_Type (*_PyGtkImage_Type)
static PyTypeObject *_PyGtkStatusbar_Type;
#define PyGtkStatusbar_Type (*_PyGtkStatusbar_Type)
static PyTypeObject *_PyGtkSourceBuffer_Type;
#define PyGtkSourceBuffer_Type (*_PyGtkSourceBuffer_Type)
static PyTypeObject *_PyGtkSourceView_Type;
#define PyGtkSourceView_Type (*_PyGtkSourceView_Type)
static PyTypeObject *_PyGtkSourceLanguage_Type;
#define PyGtkSourceLanguage_Type (*_PyGtkSourceLanguage_Type)
static PyTypeObject *_PyGtkSourceLanguageManager_Type;
#define PyGtkSourceLanguageManager_Type (*_PyGtkSourceLanguageManager_Type)


/* ---------- forward type declarations ---------- */
PyTypeObject G_GNUC_INTERNAL PyPlumaEncoding_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaMessageType_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaApp_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaDocument_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaMessage_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaMessageBus_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaPanel_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaPlugin_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaPluginPython_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaStatusbar_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaTab_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaView_Type;
PyTypeObject G_GNUC_INTERNAL PyPlumaWindow_Type;

#line 320 "pluma.c"



/* ----------- PlumaEncoding ----------- */

static int
pygobject_no_constructor(PyObject *self, PyObject *args, PyObject *kwargs)
{
    gchar buf[512];

    g_snprintf(buf, sizeof(buf), "%s is an abstract widget", self->ob_type->tp_name);
    PyErr_SetString(PyExc_NotImplementedError, buf);
    return -1;
}

static PyObject *
_wrap_pluma_encoding_copy(PyObject *self)
{
    PlumaEncoding *ret;

    
    ret = pluma_encoding_copy(pyg_boxed_get(self, PlumaEncoding));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_ENCODING, ret, TRUE, TRUE);
}

static PyObject *
_wrap_pluma_encoding_free(PyObject *self)
{
    
    pluma_encoding_free(pyg_boxed_get(self, PlumaEncoding));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_encoding_to_string(PyObject *self)
{
    gchar *ret;

    
    ret = pluma_encoding_to_string(pyg_boxed_get(self, PlumaEncoding));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_encoding_get_name(PyObject *self)
{
    const gchar *ret;

    
    ret = pluma_encoding_get_name(pyg_boxed_get(self, PlumaEncoding));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_encoding_get_charset(PyObject *self)
{
    const gchar *ret;

    
    ret = pluma_encoding_get_charset(pyg_boxed_get(self, PlumaEncoding));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyPlumaEncoding_methods[] = {
    { "copy", (PyCFunction)_wrap_pluma_encoding_copy, METH_NOARGS,
      NULL },
    { "free", (PyCFunction)_wrap_pluma_encoding_free, METH_NOARGS,
      NULL },
    { "to_string", (PyCFunction)_wrap_pluma_encoding_to_string, METH_NOARGS,
      NULL },
    { "get_name", (PyCFunction)_wrap_pluma_encoding_get_name, METH_NOARGS,
      NULL },
    { "get_charset", (PyCFunction)_wrap_pluma_encoding_get_charset, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaEncoding_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Encoding",                   /* tp_name */
    sizeof(PyGBoxed),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaEncoding_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)pygobject_no_constructor,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaMessageType ----------- */

#line 219 "plumamessage.override"

typedef struct
{
    PlumaMessageType *message_type;
    PyObject *optional;
} MessageTypeSetInfo;

static void
_message_type_set(PyObject *key, PyObject *value, MessageTypeSetInfo *info)
{
    GType gtype;
    
    gchar *k = _helper_wrap_get_string(key);

    if (!k)
        return;

    gtype = _helper_wrap_get_gtype_from_pytype(value);
    
    gboolean optional = info->optional && PySequence_Contains(info->optional, key);
    
    pluma_message_type_set(info->message_type, optional, k, gtype, NULL);
    g_free(k);
}

static int
_wrap_pluma_message_type_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *pypath, *pymethod, *optional = NULL, *pydict;
    
    if (!PyArg_ParseTuple(args, "OO|OO:PlumaMessageType.new", &pypath, &pymethod, &optional, &pydict))
        return -1;
    
    PlumaMessageType *message_type = PLUMA_MESSAGE_TYPE(g_object_new(pyg_type_from_object((PyObject *) self), NULL));
    
    MessageTypeSetInfo info = {message_type, optional && PySequence_Check(optional) ? optional : NULL};
    _helper_parse_pairs (args, kwargs, (ParsePairFunc)_message_type_set, &info);
    
    self->obj = (GObject *)message_type;    
    pygobject_register_wrapper((PyObject *) self);
    
    return 0;
}
#line 510 "pluma.c"


static PyObject *
_wrap_pluma_message_type_ref(PyObject *self)
{
    PlumaMessageType *ret;

    
    ret = pluma_message_type_ref(pyg_boxed_get(self, PlumaMessageType));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_MESSAGE_TYPE, ret, TRUE, TRUE);
}

static PyObject *
_wrap_pluma_message_type_unref(PyObject *self)
{
    
    pluma_message_type_unref(pyg_boxed_get(self, PlumaMessageType));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 264 "plumamessage.override"
static PyObject *
_wrap_pluma_message_type_instantiate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PlumaMessageType *message_type = PLUMA_MESSAGE_TYPE (self->obj);
    PlumaMessage *message = pluma_message_type_instantiate(message_type, NULL);
    
    _helper_message_set_values(message, args, kwargs);
    
    return pygobject_new((GObject *)message);
}
#line 546 "pluma.c"


static PyObject *
_wrap_pluma_message_type_get_object_path(PyObject *self)
{
    const gchar *ret;

    
    ret = pluma_message_type_get_object_path(pyg_boxed_get(self, PlumaMessageType));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_type_get_method(PyObject *self)
{
    const gchar *ret;

    
    ret = pluma_message_type_get_method(pyg_boxed_get(self, PlumaMessageType));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_type_lookup(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    GType ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Pluma.MessageType.lookup", kwlist, &key))
        return NULL;
    
    ret = pluma_message_type_lookup(pyg_boxed_get(self, PlumaMessageType), key);
    
    return pyg_type_wrapper_new(ret);
}

static const PyMethodDef _PyPlumaMessageType_methods[] = {
    { "ref", (PyCFunction)_wrap_pluma_message_type_ref, METH_NOARGS,
      NULL },
    { "unref", (PyCFunction)_wrap_pluma_message_type_unref, METH_NOARGS,
      NULL },
    { "instantiate", (PyCFunction)_wrap_pluma_message_type_instantiate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_object_path", (PyCFunction)_wrap_pluma_message_type_get_object_path, METH_NOARGS,
      NULL },
    { "get_method", (PyCFunction)_wrap_pluma_message_type_get_method, METH_NOARGS,
      NULL },
    { "lookup", (PyCFunction)_wrap_pluma_message_type_lookup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaMessageType_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.MessageType",                   /* tp_name */
    sizeof(PyGBoxed),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    0,             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaMessageType_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    0,                 /* tp_dictoffset */
    (initproc)_wrap_pluma_message_type_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaApp ----------- */

#line 88 "pluma.override"
static PyObject *
_wrap_pluma_app_create_window(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "screen", NULL};
    PyGObject *screen = NULL;
    PlumaWindow *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
			"|O!", kwlist,
			&PyGdkScreen_Type, &screen))
        return NULL;

    ret = pluma_app_create_window(PLUMA_APP(self->obj),
				  screen ? GDK_SCREEN(screen->obj) : NULL);

    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}
#line 676 "pluma.c"


#line 108 "pluma.override"
static PyObject *
_wrap_pluma_app_get_windows(PyGObject *self)
{
    const GList *list;
    PyObject *py_list;

    list = pluma_app_get_windows (PLUMA_APP (self->obj));

    py_list = _helper_wrap_gobject_glist (list);

    return py_list;
}
#line 692 "pluma.c"


static PyObject *
_wrap_pluma_app_get_active_window(PyGObject *self)
{
    PlumaWindow *ret;

    
    ret = pluma_app_get_active_window(PLUMA_APP(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 138 "pluma.override"
static PyObject *
_wrap_pluma_app_get_documents(PyGObject *self)
{
    GList *list;
    PyObject *py_list;

    list = pluma_app_get_documents (PLUMA_APP (self->obj));

    py_list = _helper_wrap_gobject_glist (list);

    g_list_free (list);

    return py_list;
}
#line 722 "pluma.c"


#line 122 "pluma.override"
static PyObject *
_wrap_pluma_app_get_views(PyGObject *self)
{
    GList *list;
    PyObject *py_list;

    list = pluma_app_get_views (PLUMA_APP (self->obj));

    py_list = _helper_wrap_gobject_glist (list);

    g_list_free (list);

    return py_list;
}
#line 740 "pluma.c"


static PyObject *
_wrap_pluma_app_get_lockdown(PyGObject *self)
{
    guint ret;

    
    ret = pluma_app_get_lockdown(PLUMA_APP(self->obj));
    
    return pyg_flags_from_gtype(PLUMA_TYPE_LOCKDOWN_MASK, ret);
}

static const PyMethodDef _PyPlumaApp_methods[] = {
    { "create_window", (PyCFunction)_wrap_pluma_app_create_window, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_windows", (PyCFunction)_wrap_pluma_app_get_windows, METH_VARARGS,
      NULL },
    { "get_active_window", (PyCFunction)_wrap_pluma_app_get_active_window, METH_NOARGS,
      NULL },
    { "get_documents", (PyCFunction)_wrap_pluma_app_get_documents, METH_VARARGS,
      NULL },
    { "get_views", (PyCFunction)_wrap_pluma_app_get_views, METH_VARARGS,
      NULL },
    { "get_lockdown", (PyCFunction)_wrap_pluma_app_get_lockdown, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaApp_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.App",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaApp_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaDocument ----------- */

static int
_wrap_pluma_document_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":pluma.Document.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create pluma.Document object");
        return -1;
    }
    return 0;
}

static PyObject *
_wrap_pluma_document_get_location(PyGObject *self)
{
    GFile *ret;

    
    ret = pluma_document_get_location(PLUMA_DOCUMENT(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_document_get_uri(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_document_get_uri(PLUMA_DOCUMENT(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_set_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Pluma.Document.set_uri", kwlist, &uri))
        return NULL;
    
    pluma_document_set_uri(PLUMA_DOCUMENT(self->obj), uri);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_uri_for_display(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_document_get_uri_for_display(PLUMA_DOCUMENT(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_short_name_for_display(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_document_get_short_name_for_display(PLUMA_DOCUMENT(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_content_type(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_document_get_content_type(PLUMA_DOCUMENT(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_mime_type(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_document_get_mime_type(PLUMA_DOCUMENT(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_readonly(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_get_readonly(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_load(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "encoding", "line_pos", "create", NULL };
    char *uri;
    PlumaEncoding *encoding = NULL;
    int line_pos, create;
    PyObject *py_encoding;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sOii:Pluma.Document.load", kwlist, &uri, &py_encoding, &line_pos, &create))
        return NULL;
    if (pyg_boxed_check(py_encoding, PLUMA_TYPE_ENCODING))
        encoding = pyg_boxed_get(py_encoding, PlumaEncoding);
    else {
        PyErr_SetString(PyExc_TypeError, "encoding should be a PlumaEncoding");
        return NULL;
    }
    
    pluma_document_load(PLUMA_DOCUMENT(self->obj), uri, encoding, line_pos, create);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_insert_file(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "iter", "uri", "encoding", NULL };
    PyObject *py_iter, *py_encoding;
    char *uri;
    int ret;
    GtkTextIter *iter = NULL;
    PlumaEncoding *encoding = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OsO:Pluma.Document.insert_file", kwlist, &py_iter, &uri, &py_encoding))
        return NULL;
    if (pyg_boxed_check(py_iter, GTK_TYPE_TEXT_ITER))
        iter = pyg_boxed_get(py_iter, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "iter should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_encoding, PLUMA_TYPE_ENCODING))
        encoding = pyg_boxed_get(py_encoding, PlumaEncoding);
    else {
        PyErr_SetString(PyExc_TypeError, "encoding should be a PlumaEncoding");
        return NULL;
    }
    
    ret = pluma_document_insert_file(PLUMA_DOCUMENT(self->obj), iter, uri, encoding);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_load_cancel(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_load_cancel(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_save(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "flags", NULL };
    PyObject *py_flags = NULL;
    PlumaDocumentSaveFlags flags;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Pluma.Document.save", kwlist, &py_flags))
        return NULL;
    if (pyg_flags_get_value(PLUMA_TYPE_DOCUMENT_SAVE_FLAGS, py_flags, (gpointer)&flags))
        return NULL;
    
    pluma_document_save(PLUMA_DOCUMENT(self->obj), flags);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_save_as(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "encoding", "flags", NULL };
    char *uri;
    PlumaEncoding *encoding = NULL;
    PlumaDocumentSaveFlags flags;
    PyObject *py_encoding, *py_flags = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sOO:Pluma.Document.save_as", kwlist, &uri, &py_encoding, &py_flags))
        return NULL;
    if (pyg_boxed_check(py_encoding, PLUMA_TYPE_ENCODING))
        encoding = pyg_boxed_get(py_encoding, PlumaEncoding);
    else {
        PyErr_SetString(PyExc_TypeError, "encoding should be a PlumaEncoding");
        return NULL;
    }
    if (pyg_flags_get_value(PLUMA_TYPE_DOCUMENT_SAVE_FLAGS, py_flags, (gpointer)&flags))
        return NULL;
    
    pluma_document_save_as(PLUMA_DOCUMENT(self->obj), uri, encoding, flags);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_is_untouched(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_is_untouched(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_is_untitled(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_is_untitled(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_is_local(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_is_local(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_get_deleted(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_get_deleted(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_goto_line(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "line", NULL };
    int line, ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Pluma.Document.goto_line", kwlist, &line))
        return NULL;
    
    ret = pluma_document_goto_line(PLUMA_DOCUMENT(self->obj), line);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_set_search_text(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "text", "flags", NULL };
    char *text;
    PyObject *py_flags = NULL;
    guint flags = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sO:Pluma.Document.set_search_text", kwlist, &text, &py_flags))
        return NULL;
    if (py_flags) {
        if (PyLong_Check(py_flags))
            flags = PyLong_AsUnsignedLong(py_flags);
        else if (PyInt_Check(py_flags))
            flags = PyInt_AsLong(py_flags);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'flags' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    pluma_document_set_search_text(PLUMA_DOCUMENT(self->obj), text, flags);
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 250 "pluma.override"
static PyObject *
_wrap_pluma_document_get_search_text(PyGObject *self)
{
    PyObject *tuple, *string;
    guint flags;
    gchar *ret;

    ret = pluma_document_get_search_text (PLUMA_DOCUMENT (self->obj), &flags);

    tuple = PyTuple_New(2);
    if (ret) {
        string = PyString_FromString(ret);
        PyTuple_SetItem(tuple, 0, string);
    } else {
        Py_INCREF(Py_None);
        PyTuple_SetItem(tuple, 0, Py_None);
    }
    PyTuple_SetItem(tuple, 1, PyInt_FromLong(flags));

    g_free(ret);

    return tuple;
}
#line 1188 "pluma.c"


static PyObject *
_wrap_pluma_document_get_can_search_again(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_get_can_search_again(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_search_forward(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "start", "end", "match_start", "match_end", NULL };
    PyObject *py_start, *py_end, *py_match_start, *py_match_end;
    int ret;
    GtkTextIter *start = NULL, *end = NULL, *match_start = NULL, *match_end = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOOO:Pluma.Document.search_forward", kwlist, &py_start, &py_end, &py_match_start, &py_match_end))
        return NULL;
    if (pyg_boxed_check(py_start, GTK_TYPE_TEXT_ITER))
        start = pyg_boxed_get(py_start, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "start should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_end, GTK_TYPE_TEXT_ITER))
        end = pyg_boxed_get(py_end, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "end should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_match_start, GTK_TYPE_TEXT_ITER))
        match_start = pyg_boxed_get(py_match_start, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "match_start should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_match_end, GTK_TYPE_TEXT_ITER))
        match_end = pyg_boxed_get(py_match_end, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "match_end should be a GtkTextIter");
        return NULL;
    }
    
    ret = pluma_document_search_forward(PLUMA_DOCUMENT(self->obj), start, end, match_start, match_end);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_replace_all(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "find", "replace", "flags", NULL };
    char *find, *replace;
    PyObject *py_flags = NULL;
    int ret;
    guint flags = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ssO:Pluma.Document.replace_all", kwlist, &find, &replace, &py_flags))
        return NULL;
    if (py_flags) {
        if (PyLong_Check(py_flags))
            flags = PyLong_AsUnsignedLong(py_flags);
        else if (PyInt_Check(py_flags))
            flags = PyInt_AsLong(py_flags);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'flags' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    ret = pluma_document_replace_all(PLUMA_DOCUMENT(self->obj), find, replace, flags);
    
    return PyInt_FromLong(ret);
}

static PyObject *
_wrap_pluma_document_search_backward(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "start", "end", "match_start", "match_end", NULL };
    PyObject *py_start, *py_end, *py_match_start, *py_match_end;
    int ret;
    GtkTextIter *start = NULL, *end = NULL, *match_start = NULL, *match_end = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"OOOO:Pluma.Document.search_backward", kwlist, &py_start, &py_end, &py_match_start, &py_match_end))
        return NULL;
    if (pyg_boxed_check(py_start, GTK_TYPE_TEXT_ITER))
        start = pyg_boxed_get(py_start, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "start should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_end, GTK_TYPE_TEXT_ITER))
        end = pyg_boxed_get(py_end, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "end should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_match_start, GTK_TYPE_TEXT_ITER))
        match_start = pyg_boxed_get(py_match_start, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "match_start should be a GtkTextIter");
        return NULL;
    }
    if (pyg_boxed_check(py_match_end, GTK_TYPE_TEXT_ITER))
        match_end = pyg_boxed_get(py_match_end, GtkTextIter);
    else {
        PyErr_SetString(PyExc_TypeError, "match_end should be a GtkTextIter");
        return NULL;
    }
    
    ret = pluma_document_search_backward(PLUMA_DOCUMENT(self->obj), start, end, match_start, match_end);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_document_set_language(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "lang", NULL };
    GtkSourceLanguage *lang = NULL;
    PyGObject *py_lang;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Pluma.Document.set_language", kwlist, &py_lang))
        return NULL;
    if (py_lang && pygobject_check(py_lang, &PyGtkSourceLanguage_Type))
        lang = GTK_SOURCE_LANGUAGE(py_lang->obj);
    else if ((PyObject *)py_lang != Py_None) {
        PyErr_SetString(PyExc_TypeError, "lang should be a GtkSourceLanguage or None");
        return NULL;
    }
    
    pluma_document_set_language(PLUMA_DOCUMENT(self->obj), (GtkSourceLanguage *) lang);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_language(PyGObject *self)
{
    GtkSourceLanguage *ret;

    
    ret = pluma_document_get_language(PLUMA_DOCUMENT(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_document_get_encoding(PyGObject *self)
{
    const PlumaEncoding *ret;

    
    ret = pluma_document_get_encoding(PLUMA_DOCUMENT(self->obj));
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_ENCODING, (PlumaEncoding*) ret, TRUE, TRUE);
}

static PyObject *
_wrap_pluma_document_set_enable_search_highlighting(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enable", NULL };
    int enable;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Pluma.Document.set_enable_search_highlighting", kwlist, &enable))
        return NULL;
    
    pluma_document_set_enable_search_highlighting(PLUMA_DOCUMENT(self->obj), enable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_document_get_enable_search_highlighting(PyGObject *self)
{
    int ret;

    
    ret = pluma_document_get_enable_search_highlighting(PLUMA_DOCUMENT(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyPlumaDocument_methods[] = {
    { "get_location", (PyCFunction)_wrap_pluma_document_get_location, METH_NOARGS,
      NULL },
    { "get_uri", (PyCFunction)_wrap_pluma_document_get_uri, METH_NOARGS,
      NULL },
    { "set_uri", (PyCFunction)_wrap_pluma_document_set_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_uri_for_display", (PyCFunction)_wrap_pluma_document_get_uri_for_display, METH_NOARGS,
      NULL },
    { "get_short_name_for_display", (PyCFunction)_wrap_pluma_document_get_short_name_for_display, METH_NOARGS,
      NULL },
    { "get_content_type", (PyCFunction)_wrap_pluma_document_get_content_type, METH_NOARGS,
      NULL },
    { "get_mime_type", (PyCFunction)_wrap_pluma_document_get_mime_type, METH_NOARGS,
      NULL },
    { "get_readonly", (PyCFunction)_wrap_pluma_document_get_readonly, METH_NOARGS,
      NULL },
    { "load", (PyCFunction)_wrap_pluma_document_load, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "insert_file", (PyCFunction)_wrap_pluma_document_insert_file, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "load_cancel", (PyCFunction)_wrap_pluma_document_load_cancel, METH_NOARGS,
      NULL },
    { "save", (PyCFunction)_wrap_pluma_document_save, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "save_as", (PyCFunction)_wrap_pluma_document_save_as, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_untouched", (PyCFunction)_wrap_pluma_document_is_untouched, METH_NOARGS,
      NULL },
    { "is_untitled", (PyCFunction)_wrap_pluma_document_is_untitled, METH_NOARGS,
      NULL },
    { "is_local", (PyCFunction)_wrap_pluma_document_is_local, METH_NOARGS,
      NULL },
    { "get_deleted", (PyCFunction)_wrap_pluma_document_get_deleted, METH_NOARGS,
      NULL },
    { "goto_line", (PyCFunction)_wrap_pluma_document_goto_line, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_search_text", (PyCFunction)_wrap_pluma_document_set_search_text, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_search_text", (PyCFunction)_wrap_pluma_document_get_search_text, METH_VARARGS,
      NULL },
    { "get_can_search_again", (PyCFunction)_wrap_pluma_document_get_can_search_again, METH_NOARGS,
      NULL },
    { "search_forward", (PyCFunction)_wrap_pluma_document_search_forward, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "replace_all", (PyCFunction)_wrap_pluma_document_replace_all, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "search_backward", (PyCFunction)_wrap_pluma_document_search_backward, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_language", (PyCFunction)_wrap_pluma_document_set_language, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_language", (PyCFunction)_wrap_pluma_document_get_language, METH_NOARGS,
      NULL },
    { "get_encoding", (PyCFunction)_wrap_pluma_document_get_encoding, METH_NOARGS,
      NULL },
    { "set_enable_search_highlighting", (PyCFunction)_wrap_pluma_document_set_enable_search_highlighting, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_enable_search_highlighting", (PyCFunction)_wrap_pluma_document_get_enable_search_highlighting, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaDocument_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Document",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaDocument_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_pluma_document_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaMessage ----------- */

#line 276 "plumamessage.override"
static PyObject *
_wrap_pluma_message_get(PyGObject *self, PyObject *args)
{
    guint len, i;
    PyObject *ret;

    len = PyTuple_Size(args);
    
    ret = PyTuple_New(len);
    
    for (i = 0; i < len; i++) {
        GValue value = { 0, };
        PyObject *py_key = PyTuple_GetItem(args, i);
        gchar *key = _helper_wrap_get_string(py_key);
        
        if (!key) {
	    PyErr_SetString(PyExc_TypeError, "keys must be strings");
	    Py_DECREF(ret);
	    return NULL;
	}
	
	pluma_message_get_value (PLUMA_MESSAGE (self->obj), key, &value);
	g_free (key);

	PyTuple_SetItem(ret, i, pyg_value_as_pyobject(&value, TRUE));
	g_value_unset(&value);
    }
    
    return ret;
}
#line 1527 "pluma.c"


#line 308 "plumamessage.override"
static PyObject *
_wrap_pluma_message_get_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    const gchar *key;
    PyObject *ret;
    GValue value = { 0, };
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s:PlumaMessage.get_value", kwlist, &key))
        return NULL;

    pluma_message_get_value(PLUMA_MESSAGE(self->obj), key, &value);
    ret = pyg_value_as_pyobject(&value, TRUE);
    g_value_unset(&value);
    
    return ret;
}
#line 1548 "pluma.c"


#line 344 "plumamessage.override"
static PyObject *
_wrap_pluma_message_set (PyGObject *self, PyObject *args, PyObject *kwargs) {
    _helper_message_set_values(PLUMA_MESSAGE(self->obj), args, kwargs);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 1559 "pluma.c"


#line 327 "plumamessage.override"
static PyObject *
_wrap_pluma_message_set_value(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", "value", NULL };
    PyObject *pykey, *pyvalue;
    
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO:PlumaMessage.set_value", kwlist, &pykey, &pyvalue))
        return NULL;
    
    if (!_helper_wrap_message_set_value(PLUMA_MESSAGE(self->obj), pykey, pyvalue))
        return NULL;
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 1578 "pluma.c"


static PyObject *
_wrap_pluma_message_get_object_path(PyGObject *self)
{
    const gchar *ret;

    
    ret = pluma_message_get_object_path(PLUMA_MESSAGE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_get_method(PyGObject *self)
{
    const gchar *ret;

    
    ret = pluma_message_get_method(PLUMA_MESSAGE(self->obj));
    
    if (ret)
        return PyString_FromString(ret);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_has_key(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Pluma.Message.has_key", kwlist, &key))
        return NULL;
    
    ret = pluma_message_has_key(PLUMA_MESSAGE(self->obj), key);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_message_get_key_type(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "key", NULL };
    char *key;
    GType ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Pluma.Message.get_key_type", kwlist, &key))
        return NULL;
    
    ret = pluma_message_get_key_type(PLUMA_MESSAGE(self->obj), key);
    
    return pyg_type_wrapper_new(ret);
}

static PyObject *
_wrap_pluma_message_validate(PyGObject *self)
{
    int ret;

    
    ret = pluma_message_validate(PLUMA_MESSAGE(self->obj));
    
    return PyBool_FromLong(ret);

}

static const PyMethodDef _PyPlumaMessage_methods[] = {
    { "get", (PyCFunction)_wrap_pluma_message_get, METH_VARARGS,
      NULL },
    { "get_value", (PyCFunction)_wrap_pluma_message_get_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set", (PyCFunction)_wrap_pluma_message_set, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "set_value", (PyCFunction)_wrap_pluma_message_set_value, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_object_path", (PyCFunction)_wrap_pluma_message_get_object_path, METH_NOARGS,
      NULL },
    { "get_method", (PyCFunction)_wrap_pluma_message_get_method, METH_NOARGS,
      NULL },
    { "has_key", (PyCFunction)_wrap_pluma_message_has_key, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_key_type", (PyCFunction)_wrap_pluma_message_get_key_type, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "validate", (PyCFunction)_wrap_pluma_message_validate, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

#line 498 "plumamessage.override"
static PyObject *
_wrap_pluma_message_tp_getattro(PyObject *self, PyObject *attrname)
{
	PlumaMessage *message = PLUMA_MESSAGE(((PyGObject *)self)->obj);
	PlumaMessageType *type;

	gchar *name = _helper_wrap_get_string (attrname);
	gboolean exists;
	gboolean intype;
	PyObject *ret;
	
	if (name == NULL)
	{
		PyErr_SetString(PyExc_TypeError, "attr name somehow not a string");
		return NULL;
	}
	
	g_object_get (message, "type", &type, NULL);
	intype = pluma_message_type_lookup (type, name) != G_TYPE_INVALID;
	pluma_message_type_unref (type);
	
	exists = pluma_message_has_key (message, name);
	
	if (!intype)
	{
		ret = PyObject_GenericGetAttr(self, attrname);
	}
	else if (exists)
	{
		GValue value = { 0, };
		pluma_message_get_value (message, name, &value);
		ret = pyg_value_as_pyobject(&value, TRUE);
		g_value_unset (&value);
	}
	else
	{
		Py_INCREF(Py_None);
		ret = Py_None;
	}

	g_free (name);
	return ret;
}
#line 1718 "pluma.c"


#line 543 "plumamessage.override"
static int
_wrap_pluma_message_tp_setattro(PyObject *self, PyObject *attrname, PyObject *value)
{
	PlumaMessage *message = PLUMA_MESSAGE(((PyGObject *)self)->obj);

	if (!_helper_wrap_message_set_value(message, attrname, value))
	{
		return PyObject_GenericSetAttr(self, attrname, value);
	}
	else
	{
		return 1;
	}
}
#line 1736 "pluma.c"


PyTypeObject G_GNUC_INTERNAL PyPlumaMessage_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Message",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)_wrap_pluma_message_tp_getattro,     /* tp_getattro */
    (setattrofunc)_wrap_pluma_message_tp_setattro,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaMessage_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaMessageBus ----------- */

#line 353 "plumamessage.override"
static int
_wrap_pluma_message_bus_new(PyGObject *self)
{
    pygobject_construct (self, NULL);
    
    if (!self->obj) {
        PyErr_SetString (PyExc_RuntimeError, "could not create pluma.MessageBus object");
        return -1;
    }

    return 0;
}
#line 1801 "pluma.c"


static PyObject *
_wrap_pluma_message_bus_lookup(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "object_path", "method", NULL };
    char *object_path, *method;
    PlumaMessageType *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:Pluma.MessageBus.lookup", kwlist, &object_path, &method))
        return NULL;
    
    ret = pluma_message_bus_lookup(PLUMA_MESSAGE_BUS(self->obj), object_path, method);
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_MESSAGE_TYPE, ret, TRUE, TRUE);
}

#line 369 "plumamessage.override"
static PyObject *
_wrap_pluma_message_bus_register(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *pypath, *pymethod, *optional = NULL, *pydict;
    PlumaMessageBus *bus = PLUMA_MESSAGE_BUS(self->obj);

    if (!PyArg_ParseTuple(args, "OO|OO:PlumaMessageBus.register", &pypath, &pymethod, &optional, &pydict))
        return NULL;
    
    gchar *object_path = _helper_wrap_get_string(pypath);
    gchar *method = _helper_wrap_get_string(pymethod);
    
    PlumaMessageType *message_type = pluma_message_bus_register(bus, object_path, method, 0, NULL);
    
    g_free(object_path);
    g_free(method);
    
    if (!message_type)
    {
    	PyErr_SetString(PyExc_StandardError, "Message type already exists");
    	return NULL;
    }
    
    MessageTypeSetInfo info = {message_type, optional && PySequence_Check(optional) ? optional : NULL};
    _helper_parse_pairs (args, kwargs, (ParsePairFunc)_message_type_set, &info);
    
    return pyg_boxed_new(PLUMA_TYPE_MESSAGE_TYPE, message_type, TRUE, TRUE);
}
#line 1849 "pluma.c"


static PyObject *
_wrap_pluma_message_bus_unregister(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message_type", NULL };
    PlumaMessageType *message_type = NULL;
    PyObject *py_message_type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Pluma.MessageBus.unregister", kwlist, &py_message_type))
        return NULL;
    if (pyg_boxed_check(py_message_type, PLUMA_TYPE_MESSAGE_TYPE))
        message_type = pyg_boxed_get(py_message_type, PlumaMessageType);
    else {
        PyErr_SetString(PyExc_TypeError, "message_type should be a PlumaMessageType");
        return NULL;
    }
    
    pluma_message_bus_unregister(PLUMA_MESSAGE_BUS(self->obj), message_type);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_bus_unregister_all(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "object_path", NULL };
    char *object_path;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Pluma.MessageBus.unregister_all", kwlist, &object_path))
        return NULL;
    
    pluma_message_bus_unregister_all(PLUMA_MESSAGE_BUS(self->obj), object_path);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_bus_is_registered(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "object_path", "method", NULL };
    char *object_path, *method;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:Pluma.MessageBus.is_registered", kwlist, &object_path, &method))
        return NULL;
    
    ret = pluma_message_bus_is_registered(PLUMA_MESSAGE_BUS(self->obj), object_path, method);
    
    return PyBool_FromLong(ret);

}

#line 399 "plumamessage.override"
static void
pypluma_message_bus_connect_cb(PlumaMessageBus *bus, PlumaMessage *message, gpointer data)
{
    PyGILState_STATE state;
    PyPlumaCustomNotify *cunote = data;
    PyObject *pybus, *pymessage, *retobj;

    g_assert(cunote->func);

    state = pyg_gil_state_ensure();

    pybus = pygobject_new((GObject *)bus);
    pymessage = pygobject_new((GObject *)message);

    if (cunote->data) {
        retobj = PyEval_CallFunction(cunote->func, "(NNO)", pybus, pymessage, cunote->data);
    } else {
        retobj = PyEval_CallFunction(cunote->func, "(NN)", pybus, pymessage);
    }

    if (PyErr_Occurred()) {
        PyErr_Print();
    }

    Py_XDECREF(retobj);

    pyg_gil_state_release(state);
}

static PyObject *
_wrap_pluma_message_bus_connect(PyGObject *self, PyObject *args, PyObject *kwargs) 
{
    static char *kwlist[] = { "domain", "name", "func", "data", NULL };
    PyObject *pyfunc, *pyarg = NULL;
    const gchar *domain;
    const gchar *name;
    PyPlumaCustomNotify *cunote;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
				     "ssO|O:PlumaMessageBus.connect",
				     kwlist, &domain, &name, &pyfunc, &pyarg))
        return NULL;

    if (!PyCallable_Check(pyfunc)) {
        PyErr_SetString(PyExc_TypeError, "func must be a callable object");
        return NULL;
    }
    cunote = g_new(PyPlumaCustomNotify, 1);
    Py_INCREF(pyfunc);
    cunote->func = pyfunc;
    Py_XINCREF(pyarg);
    cunote->data = pyarg;

    guint id = pluma_message_bus_connect(PLUMA_MESSAGE_BUS(self->obj),
                                         domain,
                                         name,
                                         pypluma_message_bus_connect_cb,
                                         (gpointer)cunote,
                                         pypluma_custom_destroy_notify);
    return PyLong_FromUnsignedLong(id);
}
#line 1967 "pluma.c"


static PyObject *
_wrap_pluma_message_bus_disconnect(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    PyObject *py_id = NULL;
    guint id = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Pluma.MessageBus.disconnect", kwlist, &py_id))
        return NULL;
    if (py_id) {
        if (PyLong_Check(py_id))
            id = PyLong_AsUnsignedLong(py_id);
        else if (PyInt_Check(py_id))
            id = PyInt_AsLong(py_id);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'id' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    pluma_message_bus_disconnect(PLUMA_MESSAGE_BUS(self->obj), id);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_bus_block(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    PyObject *py_id = NULL;
    guint id = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Pluma.MessageBus.block", kwlist, &py_id))
        return NULL;
    if (py_id) {
        if (PyLong_Check(py_id))
            id = PyLong_AsUnsignedLong(py_id);
        else if (PyInt_Check(py_id))
            id = PyInt_AsLong(py_id);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'id' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    pluma_message_bus_block(PLUMA_MESSAGE_BUS(self->obj), id);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_bus_unblock(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "id", NULL };
    PyObject *py_id = NULL;
    guint id = 0;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:Pluma.MessageBus.unblock", kwlist, &py_id))
        return NULL;
    if (py_id) {
        if (PyLong_Check(py_id))
            id = PyLong_AsUnsignedLong(py_id);
        else if (PyInt_Check(py_id))
            id = PyInt_AsLong(py_id);
        else
            PyErr_SetString(PyExc_TypeError, "Parameter 'id' must be an int or a long");
        if (PyErr_Occurred())
            return NULL;
    }
    
    pluma_message_bus_unblock(PLUMA_MESSAGE_BUS(self->obj), id);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_bus_send_message(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message", NULL };
    PyGObject *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.MessageBus.send_message", kwlist, &PyPlumaMessage_Type, &message))
        return NULL;
    
    pluma_message_bus_send_message(PLUMA_MESSAGE_BUS(self->obj), PLUMA_MESSAGE(message->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_message_bus_send_message_sync(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message", NULL };
    PyGObject *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.MessageBus.send_message_sync", kwlist, &PyPlumaMessage_Type, &message))
        return NULL;
    
    pluma_message_bus_send_message_sync(PLUMA_MESSAGE_BUS(self->obj), PLUMA_MESSAGE(message->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 462 "plumamessage.override"
static PyObject *
_wrap_pluma_message_bus_send(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    /* create a new message object */
    PlumaMessage *message;
    PlumaMessageBus *bus = PLUMA_MESSAGE_BUS(self->obj);
    message = _helper_wrap_create_message(bus, args, kwargs);
    
    if (!message)
        return NULL;
    
    pluma_message_bus_send_message(bus, message);
    g_object_unref (message);
    
    Py_INCREF(Py_None);
    return Py_None;
}
#line 2096 "pluma.c"


#line 481 "plumamessage.override"
static PyObject *
_wrap_pluma_message_bus_send_sync(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    /* create a new message object */
    PlumaMessage *message;
    PlumaMessageBus *bus = PLUMA_MESSAGE_BUS(self->obj);
    
    message = _helper_wrap_create_message(bus, args, kwargs);
    
    if (!message)
        return NULL;
    
    pluma_message_bus_send_message_sync(bus, message);
    return pygobject_new((GObject *)message);
}
#line 2115 "pluma.c"


static const PyMethodDef _PyPlumaMessageBus_methods[] = {
    { "lookup", (PyCFunction)_wrap_pluma_message_bus_lookup, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "register", (PyCFunction)_wrap_pluma_message_bus_register, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unregister", (PyCFunction)_wrap_pluma_message_bus_unregister, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unregister_all", (PyCFunction)_wrap_pluma_message_bus_unregister_all, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_registered", (PyCFunction)_wrap_pluma_message_bus_is_registered, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "connect", (PyCFunction)_wrap_pluma_message_bus_connect, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "disconnect", (PyCFunction)_wrap_pluma_message_bus_disconnect, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "block", (PyCFunction)_wrap_pluma_message_bus_block, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "unblock", (PyCFunction)_wrap_pluma_message_bus_unblock, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "send_message", (PyCFunction)_wrap_pluma_message_bus_send_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "send_message_sync", (PyCFunction)_wrap_pluma_message_bus_send_message_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "send", (PyCFunction)_wrap_pluma_message_bus_send, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "send_sync", (PyCFunction)_wrap_pluma_message_bus_send_sync, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaMessageBus_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.MessageBus",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaMessageBus_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_pluma_message_bus_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaPanel ----------- */

static int
_wrap_pluma_panel_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":pluma.Panel.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create pluma.Panel object");
        return -1;
    }
    return 0;
}

#line 275 "pluma.override"
static PyObject *
_wrap_pluma_panel_add_item(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist1[] = { "item", "name", "image", NULL };
    static char *kwlist2[] = { "item", "name", "stock_id", NULL };
    PyGObject *item, *image;
    char *name = NULL;
    char *stock_id = NULL;

    if (PyArg_ParseTupleAndKeywords(args, kwargs, "O!sO!:PlumaPanel.add_item", kwlist1, &PyGtkWidget_Type, &item, &name, &PyGtkImage_Type, &image)) {
        pluma_panel_add_item(PLUMA_PANEL(self->obj), GTK_WIDGET(item->obj), name, GTK_WIDGET(image->obj));
        Py_INCREF(Py_None);
        return Py_None;
    }

    PyErr_Clear();

    if (PyArg_ParseTupleAndKeywords(args, kwargs, "O!ss:PlumaPanel.add_item", kwlist2, &PyGtkWidget_Type, &item, &name, &stock_id)) {
        pluma_panel_add_item_with_stock_icon(PLUMA_PANEL(self->obj), GTK_WIDGET(item->obj), name, stock_id);
        Py_INCREF(Py_None);
        return Py_None;
    }

    PyErr_Clear();
    PyErr_SetString(PyExc_TypeError, "the last arg should be either a gtk.Image or a stock_id string");
    return NULL;
}
#line 2245 "pluma.c"


static PyObject *
_wrap_pluma_panel_remove_item(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "item", NULL };
    PyGObject *item;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.Panel.remove_item", kwlist, &PyGtkWidget_Type, &item))
        return NULL;
    
    ret = pluma_panel_remove_item(PLUMA_PANEL(self->obj), GTK_WIDGET(item->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_panel_activate_item(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "item", NULL };
    PyGObject *item;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.Panel.activate_item", kwlist, &PyGtkWidget_Type, &item))
        return NULL;
    
    ret = pluma_panel_activate_item(PLUMA_PANEL(self->obj), GTK_WIDGET(item->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_panel_item_is_active(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "item", NULL };
    PyGObject *item;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.Panel.item_is_active", kwlist, &PyGtkWidget_Type, &item))
        return NULL;
    
    ret = pluma_panel_item_is_active(PLUMA_PANEL(self->obj), GTK_WIDGET(item->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_panel_get_orientation(PyGObject *self)
{
    gint ret;

    
    ret = pluma_panel_get_orientation(PLUMA_PANEL(self->obj));
    
    return pyg_enum_from_gtype(GTK_TYPE_ORIENTATION, ret);
}

static PyObject *
_wrap_pluma_panel_get_n_items(PyGObject *self)
{
    int ret;

    
    ret = pluma_panel_get_n_items(PLUMA_PANEL(self->obj));
    
    return PyInt_FromLong(ret);
}

static const PyMethodDef _PyPlumaPanel_methods[] = {
    { "add_item", (PyCFunction)_wrap_pluma_panel_add_item, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "remove_item", (PyCFunction)_wrap_pluma_panel_remove_item, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "activate_item", (PyCFunction)_wrap_pluma_panel_activate_item, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "item_is_active", (PyCFunction)_wrap_pluma_panel_item_is_active, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_orientation", (PyCFunction)_wrap_pluma_panel_get_orientation, METH_NOARGS,
      NULL },
    { "get_n_items", (PyCFunction)_wrap_pluma_panel_get_n_items, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaPanel_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Panel",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaPanel_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_pluma_panel_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaPlugin ----------- */

static PyObject *
_wrap_pluma_plugin_get_install_dir(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_plugin_get_install_dir(PLUMA_PLUGIN(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_plugin_get_data_dir(PyGObject *self)
{
    gchar *ret;

    
    ret = pluma_plugin_get_data_dir(PLUMA_PLUGIN(self->obj));
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

#line 7 "plumaplugin.override"
static PyObject *
_wrap_pluma_plugin_activate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
	gpointer klass, klass2;
	static char *kwlist[] = { "window", NULL };
	PyGObject *window;
	PyObject *cls = (PyObject *)(((PyObject *)self)->ob_type);
	
	if (!PyArg_ParseTupleAndKeywords (args, 
					  kwargs,
					  "O!:PlumaPlugin.activate", 
					  kwlist,
					  &PyPlumaWindow_Type, 
					  &window))
		return NULL;

	klass = g_type_class_ref (pyg_type_from_object (cls));
	
	if (PLUMA_IS_PLUGIN_PYTHON_CLASS (klass))
	{
		klass2 = g_type_class_peek_parent (klass);
		g_type_class_unref (klass);
		klass = g_type_class_ref (G_TYPE_FROM_CLASS (klass2));
	}

	if (PLUMA_PLUGIN_CLASS (klass)->activate)
		PLUMA_PLUGIN_CLASS (klass)->activate (PLUMA_PLUGIN (self->obj), 
						      PLUMA_WINDOW (window->obj));
	else {
		PyErr_SetString (PyExc_NotImplementedError, 
				 "virtual method PlumaPlugin.activate not implemented");
		g_type_class_unref (klass);
		return NULL;
	}

	g_type_class_unref (klass);
	Py_INCREF(Py_None);
	return Py_None;
}

#line 2458 "pluma.c"


#line 49 "plumaplugin.override"
static PyObject *
_wrap_pluma_plugin_deactivate(PyGObject *self, PyObject *args, PyObject *kwargs)
{
	gpointer klass, klass2;
	static char *kwlist[] = {"window", NULL};
	PyGObject *window;
	PyObject *cls = (PyObject *)(((PyObject *)self)->ob_type);

	if (!PyArg_ParseTupleAndKeywords (args, 
					  kwargs,
					  "O!:PlumaPlugin.deactivate", 
					  kwlist,
					  &PyPlumaWindow_Type, 
					  &window))
		return NULL;

	klass = g_type_class_ref (pyg_type_from_object (cls));

	if (PLUMA_IS_PLUGIN_PYTHON_CLASS (klass))
	{
		klass2 = g_type_class_peek_parent (klass);
		g_type_class_unref (klass);
		klass = g_type_class_ref (G_TYPE_FROM_CLASS (klass2));
	}
	
	if (PLUMA_PLUGIN_CLASS (klass)->deactivate)
		PLUMA_PLUGIN_CLASS (klass)->deactivate (PLUMA_PLUGIN (self->obj), 
							PLUMA_WINDOW (window->obj));
	else {
		PyErr_SetString (PyExc_NotImplementedError, 
				 "virtual method PlumaPlugin.deactivate not implemented");
		g_type_class_unref (klass);
		return NULL;
	}

	g_type_class_unref (klass);
	Py_INCREF(Py_None);
	return Py_None;
}

#line 2502 "pluma.c"


#line 91 "plumaplugin.override"
static PyObject *
_wrap_pluma_plugin_update_ui (PyGObject *self, PyObject *args, PyObject *kwargs)
{
	gpointer klass, klass2;
	static char *kwlist[] = {"window", NULL};
	PyGObject *window;
	PyObject *cls = (PyObject *)(((PyObject *)self)->ob_type);

	if (!PyArg_ParseTupleAndKeywords (args, 
					  kwargs,
					  "O!:PlumaPlugin.update_ui", 
					  kwlist,
					  &PyPlumaWindow_Type, 
					  &window))
		return NULL;

	klass = g_type_class_ref (pyg_type_from_object (cls));

	if (PLUMA_IS_PLUGIN_PYTHON_CLASS (klass))
	{
		klass2 = g_type_class_peek_parent (klass);
		g_type_class_unref (klass);
		klass = g_type_class_ref (G_TYPE_FROM_CLASS (klass2));
	}
	
	if (PLUMA_PLUGIN_CLASS (klass)->update_ui)
		PLUMA_PLUGIN_CLASS (klass)->update_ui (PLUMA_PLUGIN (self->obj), 
						       PLUMA_WINDOW (window->obj));
	else {
		PyErr_SetString (PyExc_NotImplementedError, 
				 "virtual method PlumaPlugin.update_ui not implemented");
		g_type_class_unref (klass);
		return NULL;
	}

	g_type_class_unref (klass);
	Py_INCREF(Py_None);
	return Py_None;
}

#line 2546 "pluma.c"


#line 133 "plumaplugin.override"
static PyObject *
_wrap_pluma_plugin_is_configurable (PyGObject *self)
{
	int ret;
	gpointer klass, klass2;
	PyObject *cls = (PyObject *)(((PyObject *)self)->ob_type);

	klass = g_type_class_ref (pyg_type_from_object (cls));

	if (PLUMA_IS_PLUGIN_PYTHON_CLASS (klass))
	{
		klass2 = g_type_class_peek_parent (klass);
		g_type_class_unref (klass);
		klass = g_type_class_ref (G_TYPE_FROM_CLASS (klass2));
	}
	
	if (PLUMA_PLUGIN_CLASS (klass)->is_configurable)
		ret = PLUMA_PLUGIN_CLASS (klass)->is_configurable (PLUMA_PLUGIN (self->obj));
	else {
		PyErr_SetString (PyExc_NotImplementedError, 
				 "virtual method PlumaPlugin.is_configurable not implemented");
		g_type_class_unref (klass);
		return NULL;
	}

	g_type_class_unref (klass);
	return PyBool_FromLong (ret);
}

#line 2579 "pluma.c"


static PyObject *
_wrap_pluma_plugin_create_configure_dialog(PyGObject *self)
{
    GtkWidget *ret;

    
    ret = pluma_plugin_create_configure_dialog(PLUMA_PLUGIN(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyPlumaPlugin_methods[] = {
    { "get_install_dir", (PyCFunction)_wrap_pluma_plugin_get_install_dir, METH_NOARGS,
      NULL },
    { "get_data_dir", (PyCFunction)_wrap_pluma_plugin_get_data_dir, METH_NOARGS,
      NULL },
    { "activate", (PyCFunction)_wrap_pluma_plugin_activate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "deactivate", (PyCFunction)_wrap_pluma_plugin_deactivate, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "update_ui", (PyCFunction)_wrap_pluma_plugin_update_ui, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "is_configurable", (PyCFunction)_wrap_pluma_plugin_is_configurable, METH_VARARGS,
      NULL },
    { "create_configure_dialog", (PyCFunction)_wrap_pluma_plugin_create_configure_dialog, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaPlugin_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.__Plugin",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaPlugin_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaPluginPython ----------- */

static int
_wrap_pluma_plugin_python_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char* kwlist[] = { NULL };

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,
                                     ":pluma.Plugin.__init__",
                                     kwlist))
        return -1;

    pygobject_constructv(self, 0, NULL);
    if (!self->obj) {
        PyErr_SetString(
            PyExc_RuntimeError, 
            "could not create pluma.Plugin object");
        return -1;
    }
    return 0;
}

PyTypeObject G_GNUC_INTERNAL PyPlumaPluginPython_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Plugin",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)NULL, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_pluma_plugin_python_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaStatusbar ----------- */

#line 446 "pluma.override"
static PyObject *
_wrap_pluma_statusbar_flash_message(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "context_id", "message", NULL };
    int context_id;
    char *message;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"is:PlumaStatusbar.flash_message", kwlist, &context_id, &message))
        return NULL;
   
    pluma_statusbar_flash_message(PLUMA_STATUSBAR(self->obj), context_id, "%s", message);

    Py_INCREF(Py_None);
    return Py_None;
}
#line 2746 "pluma.c"


static const PyMethodDef _PyPlumaStatusbar_methods[] = {
    { "flash_message", (PyCFunction)_wrap_pluma_statusbar_flash_message, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaStatusbar_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Statusbar",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaStatusbar_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaTab ----------- */

static PyObject *
_wrap_pluma_tab_get_view(PyGObject *self)
{
    PlumaView *ret;

    
    ret = pluma_tab_get_view(PLUMA_TAB(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_tab_get_document(PyGObject *self)
{
    PlumaDocument *ret;

    
    ret = pluma_tab_get_document(PLUMA_TAB(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_tab_get_state(PyGObject *self)
{
    gint ret;

    
    ret = pluma_tab_get_state(PLUMA_TAB(self->obj));
    
    return pyg_enum_from_gtype(PLUMA_TYPE_TAB_STATE, ret);
}

static PyObject *
_wrap_pluma_tab_set_auto_save_enabled(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "enable", NULL };
    int enable;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Pluma.Tab.set_auto_save_enabled", kwlist, &enable))
        return NULL;
    
    pluma_tab_set_auto_save_enabled(PLUMA_TAB(self->obj), enable);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_tab_get_auto_save_enabled(PyGObject *self)
{
    int ret;

    
    ret = pluma_tab_get_auto_save_enabled(PLUMA_TAB(self->obj));
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_tab_set_auto_save_interval(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "interval", NULL };
    int interval;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Pluma.Tab.set_auto_save_interval", kwlist, &interval))
        return NULL;
    
    pluma_tab_set_auto_save_interval(PLUMA_TAB(self->obj), interval);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_tab_get_auto_save_interval(PyGObject *self)
{
    int ret;

    
    ret = pluma_tab_get_auto_save_interval(PLUMA_TAB(self->obj));
    
    return PyInt_FromLong(ret);
}

static const PyMethodDef _PyPlumaTab_methods[] = {
    { "get_view", (PyCFunction)_wrap_pluma_tab_get_view, METH_NOARGS,
      NULL },
    { "get_document", (PyCFunction)_wrap_pluma_tab_get_document, METH_NOARGS,
      NULL },
    { "get_state", (PyCFunction)_wrap_pluma_tab_get_state, METH_NOARGS,
      NULL },
    { "set_auto_save_enabled", (PyCFunction)_wrap_pluma_tab_set_auto_save_enabled, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_auto_save_enabled", (PyCFunction)_wrap_pluma_tab_get_auto_save_enabled, METH_NOARGS,
      NULL },
    { "set_auto_save_interval", (PyCFunction)_wrap_pluma_tab_set_auto_save_interval, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_auto_save_interval", (PyCFunction)_wrap_pluma_tab_get_auto_save_interval, METH_NOARGS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaTab_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Tab",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaTab_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaView ----------- */

static int
_wrap_pluma_view_new(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "doc", NULL };
    PyGObject *doc;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.View.__init__", kwlist, &PyPlumaDocument_Type, &doc))
        return -1;
    self->obj = (GObject *)pluma_view_new(PLUMA_DOCUMENT(doc->obj));

    if (!self->obj) {
        PyErr_SetString(PyExc_RuntimeError, "could not create PlumaView object");
        return -1;
    }
    pygobject_register_wrapper((PyObject *)self);
    return 0;
}

static PyObject *
_wrap_pluma_view_cut_clipboard(PyGObject *self)
{
    
    pluma_view_cut_clipboard(PLUMA_VIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_view_copy_clipboard(PyGObject *self)
{
    
    pluma_view_copy_clipboard(PLUMA_VIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_view_paste_clipboard(PyGObject *self)
{
    
    pluma_view_paste_clipboard(PLUMA_VIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_view_delete_selection(PyGObject *self)
{
    
    pluma_view_delete_selection(PLUMA_VIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_view_select_all(PyGObject *self)
{
    
    pluma_view_select_all(PLUMA_VIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_view_scroll_to_cursor(PyGObject *self)
{
    
    pluma_view_scroll_to_cursor(PLUMA_VIEW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_view_set_font(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "def_", "font_name", NULL };
    int def;
    char *font_name;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"is:Pluma.View.set_font", kwlist, &def, &font_name))
        return NULL;
    
    pluma_view_set_font(PLUMA_VIEW(self->obj), def, font_name);
    
    Py_INCREF(Py_None);
    return Py_None;
}

static const PyMethodDef _PyPlumaView_methods[] = {
    { "cut_clipboard", (PyCFunction)_wrap_pluma_view_cut_clipboard, METH_NOARGS,
      NULL },
    { "copy_clipboard", (PyCFunction)_wrap_pluma_view_copy_clipboard, METH_NOARGS,
      NULL },
    { "paste_clipboard", (PyCFunction)_wrap_pluma_view_paste_clipboard, METH_NOARGS,
      NULL },
    { "delete_selection", (PyCFunction)_wrap_pluma_view_delete_selection, METH_NOARGS,
      NULL },
    { "select_all", (PyCFunction)_wrap_pluma_view_select_all, METH_NOARGS,
      NULL },
    { "scroll_to_cursor", (PyCFunction)_wrap_pluma_view_scroll_to_cursor, METH_NOARGS,
      NULL },
    { "set_font", (PyCFunction)_wrap_pluma_view_set_font, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaView_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.View",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaView_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)_wrap_pluma_view_new,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- PlumaWindow ----------- */

static PyObject *
_wrap_pluma_window_create_tab(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "jump_to", NULL };
    int jump_to;
    PlumaTab *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:Pluma.Window.create_tab", kwlist, &jump_to))
        return NULL;
    
    ret = pluma_window_create_tab(PLUMA_WINDOW(self->obj), jump_to);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_create_tab_from_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", "encoding", "line_pos", "create", "jump_to", NULL };
    char *uri;
    PlumaEncoding *encoding = NULL;
    int line_pos, create, jump_to;
    PyObject *py_encoding = Py_None;
    PlumaTab *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"sOiii:Pluma.Window.create_tab_from_uri", kwlist, &uri, &py_encoding, &line_pos, &create, &jump_to))
        return NULL;
    if (pyg_boxed_check(py_encoding, PLUMA_TYPE_ENCODING))
        encoding = pyg_boxed_get(py_encoding, PlumaEncoding);
    else if (py_encoding != Py_None) {
        PyErr_SetString(PyExc_TypeError, "encoding should be a PlumaEncoding or None");
        return NULL;
    }
    
    ret = pluma_window_create_tab_from_uri(PLUMA_WINDOW(self->obj), uri, encoding, line_pos, create, jump_to);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_close_tab(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "tab", NULL };
    PyGObject *tab;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.Window.close_tab", kwlist, &PyPlumaTab_Type, &tab))
        return NULL;
    
    pluma_window_close_tab(PLUMA_WINDOW(self->obj), PLUMA_TAB(tab->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

#line 202 "pluma.override"
static PyObject *
_wrap_pluma_window_close_tabs (PyGObject *self,
			       PyObject  *args,
			       PyObject  *kwargs)
{
	static char *kwlist[] = { "tabs", NULL };
	PyObject *list, *item;
	GList *glist = NULL;
	int len, i;

	if (!PyArg_ParseTupleAndKeywords (args, kwargs,
					  "O:PlumaWindow.close_tabs", kwlist,
					  &list))
		return NULL;

	if (!PySequence_Check (list))
	{
		PyErr_SetString (PyExc_TypeError,
				 "first argument must be a sequence");
		return NULL;
	}

	len = PySequence_Length (list);

	for (i = 0; i < len; i++)
	{
		item = PySequence_GetItem (list, i);
		Py_DECREF(item);

		if (!pygobject_check (item, &PyPlumaTab_Type))
		{
			PyErr_SetString (PyExc_TypeError,
					 "sequence item not a Gtkwidget object");
			g_list_free (glist);
			return NULL;
		}

		glist = g_list_append (glist, pygobject_get (item));
	}

	pluma_window_close_tabs (PLUMA_WINDOW (self->obj), glist);

	g_list_free (glist);
	Py_INCREF (Py_None);
	return Py_None;
}
#line 3223 "pluma.c"


static PyObject *
_wrap_pluma_window_close_all_tabs(PyGObject *self)
{
    
    pluma_window_close_all_tabs(PLUMA_WINDOW(self->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_window_get_active_tab(PyGObject *self)
{
    PlumaTab *ret;

    
    ret = pluma_window_get_active_tab(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_set_active_tab(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "tab", NULL };
    PyGObject *tab;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:Pluma.Window.set_active_tab", kwlist, &PyPlumaTab_Type, &tab))
        return NULL;
    
    pluma_window_set_active_tab(PLUMA_WINDOW(self->obj), PLUMA_TAB(tab->obj));
    
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
_wrap_pluma_window_get_active_view(PyGObject *self)
{
    PlumaView *ret;

    
    ret = pluma_window_get_active_view(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_active_document(PyGObject *self)
{
    PlumaDocument *ret;

    
    ret = pluma_window_get_active_document(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 154 "pluma.override"
static PyObject *
_wrap_pluma_window_get_documents(PyGObject *self)
{
    GList *list;
    PyObject *py_list;

    list = pluma_window_get_documents (PLUMA_WINDOW (self->obj));

    py_list = _helper_wrap_gobject_glist (list);

    g_list_free(list);

    return py_list;
}
#line 3302 "pluma.c"


#line 170 "pluma.override"
static PyObject *
_wrap_pluma_window_get_unsaved_documents(PyGObject *self)
{
    GList *list;
    PyObject *py_list;

    list = pluma_window_get_unsaved_documents (PLUMA_WINDOW (self->obj));

    py_list = _helper_wrap_gobject_glist (list);

    g_list_free(list);

    return py_list;
}
#line 3320 "pluma.c"


#line 186 "pluma.override"
static PyObject *
_wrap_pluma_window_get_views(PyGObject *self)
{
    GList *list;
    PyObject *py_list;

    list = pluma_window_get_views (PLUMA_WINDOW (self->obj));

    py_list = _helper_wrap_gobject_glist (list);

    g_list_free(list);

    return py_list;
}
#line 3338 "pluma.c"


static PyObject *
_wrap_pluma_window_get_group(PyGObject *self)
{
    GtkWindowGroup *ret;

    
    ret = pluma_window_get_group(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_side_panel(PyGObject *self)
{
    PlumaPanel *ret;

    
    ret = pluma_window_get_side_panel(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_bottom_panel(PyGObject *self)
{
    PlumaPanel *ret;

    
    ret = pluma_window_get_bottom_panel(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_statusbar(PyGObject *self)
{
    GtkWidget *ret;

    
    ret = pluma_window_get_statusbar(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_ui_manager(PyGObject *self)
{
    GtkUIManager *ret;

    
    ret = pluma_window_get_ui_manager(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_state(PyGObject *self)
{
    guint ret;

    
    ret = pluma_window_get_state(PLUMA_WINDOW(self->obj));
    
    return pyg_flags_from_gtype(PLUMA_TYPE_WINDOW_STATE, ret);
}

static PyObject *
_wrap_pluma_window_get_message_bus(PyGObject *self)
{
    PlumaMessageBus *ret;

    
    ret = pluma_window_get_message_bus(PLUMA_WINDOW(self->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_window_get_tab_from_uri(PyGObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "uri", NULL };
    char *uri;
    PlumaTab *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:Pluma.Window.get_tab_from_uri", kwlist, &uri))
        return NULL;
    
    ret = pluma_window_get_tab_from_uri(PLUMA_WINDOW(self->obj), uri);
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static const PyMethodDef _PyPlumaWindow_methods[] = {
    { "create_tab", (PyCFunction)_wrap_pluma_window_create_tab, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "create_tab_from_uri", (PyCFunction)_wrap_pluma_window_create_tab_from_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "close_tab", (PyCFunction)_wrap_pluma_window_close_tab, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "close_tabs", (PyCFunction)_wrap_pluma_window_close_tabs, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "close_all_tabs", (PyCFunction)_wrap_pluma_window_close_all_tabs, METH_NOARGS,
      NULL },
    { "get_active_tab", (PyCFunction)_wrap_pluma_window_get_active_tab, METH_NOARGS,
      NULL },
    { "set_active_tab", (PyCFunction)_wrap_pluma_window_set_active_tab, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_active_view", (PyCFunction)_wrap_pluma_window_get_active_view, METH_NOARGS,
      NULL },
    { "get_active_document", (PyCFunction)_wrap_pluma_window_get_active_document, METH_NOARGS,
      NULL },
    { "get_documents", (PyCFunction)_wrap_pluma_window_get_documents, METH_VARARGS,
      NULL },
    { "get_unsaved_documents", (PyCFunction)_wrap_pluma_window_get_unsaved_documents, METH_VARARGS,
      NULL },
    { "get_views", (PyCFunction)_wrap_pluma_window_get_views, METH_VARARGS,
      NULL },
    { "get_group", (PyCFunction)_wrap_pluma_window_get_group, METH_NOARGS,
      NULL },
    { "get_side_panel", (PyCFunction)_wrap_pluma_window_get_side_panel, METH_NOARGS,
      NULL },
    { "get_bottom_panel", (PyCFunction)_wrap_pluma_window_get_bottom_panel, METH_NOARGS,
      NULL },
    { "get_statusbar", (PyCFunction)_wrap_pluma_window_get_statusbar, METH_NOARGS,
      NULL },
    { "get_ui_manager", (PyCFunction)_wrap_pluma_window_get_ui_manager, METH_NOARGS,
      NULL },
    { "get_state", (PyCFunction)_wrap_pluma_window_get_state, METH_NOARGS,
      NULL },
    { "get_message_bus", (PyCFunction)_wrap_pluma_window_get_message_bus, METH_NOARGS,
      NULL },
    { "get_tab_from_uri", (PyCFunction)_wrap_pluma_window_get_tab_from_uri, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};

PyTypeObject G_GNUC_INTERNAL PyPlumaWindow_Type = {
    PyObject_HEAD_INIT(NULL)
    0,                                 /* ob_size */
    "pluma.Window",                   /* tp_name */
    sizeof(PyGObject),          /* tp_basicsize */
    0,                                 /* tp_itemsize */
    /* methods */
    (destructor)0,        /* tp_dealloc */
    (printfunc)0,                      /* tp_print */
    (getattrfunc)0,       /* tp_getattr */
    (setattrfunc)0,       /* tp_setattr */
    (cmpfunc)0,           /* tp_compare */
    (reprfunc)0,             /* tp_repr */
    (PyNumberMethods*)0,     /* tp_as_number */
    (PySequenceMethods*)0, /* tp_as_sequence */
    (PyMappingMethods*)0,   /* tp_as_mapping */
    (hashfunc)0,             /* tp_hash */
    (ternaryfunc)0,          /* tp_call */
    (reprfunc)0,              /* tp_str */
    (getattrofunc)0,     /* tp_getattro */
    (setattrofunc)0,     /* tp_setattro */
    (PyBufferProcs*)0,  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,                      /* tp_flags */
    NULL,                        /* Documentation string */
    (traverseproc)0,     /* tp_traverse */
    (inquiry)0,             /* tp_clear */
    (richcmpfunc)0,   /* tp_richcompare */
    offsetof(PyGObject, weakreflist),             /* tp_weaklistoffset */
    (getiterfunc)0,          /* tp_iter */
    (iternextfunc)0,     /* tp_iternext */
    (struct PyMethodDef*)_PyPlumaWindow_methods, /* tp_methods */
    (struct PyMemberDef*)0,              /* tp_members */
    (struct PyGetSetDef*)0,  /* tp_getset */
    NULL,                              /* tp_base */
    NULL,                              /* tp_dict */
    (descrgetfunc)0,    /* tp_descr_get */
    (descrsetfunc)0,    /* tp_descr_set */
    offsetof(PyGObject, inst_dict),                 /* tp_dictoffset */
    (initproc)0,             /* tp_init */
    (allocfunc)0,           /* tp_alloc */
    (newfunc)0,               /* tp_new */
    (freefunc)0,             /* tp_free */
    (inquiry)0              /* tp_is_gc */
};



/* ----------- functions ----------- */

static PyObject *
_wrap_pluma_app_get_default(PyObject *self)
{
    PlumaApp *ret;

    
    ret = pluma_app_get_default();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 304 "pluma.override"
/* deprecated wrappers */
static PyObject *
_wrap_pluma_app_get_default_deprecated(PyObject *self)
{
    if (PyErr_Warn(PyExc_DeprecationWarning, "use pluma.app_get_default instead") < 0)
	return NULL;
    return _wrap_pluma_app_get_default(self);
}
#line 3554 "pluma.c"


static PyObject *
_wrap_pluma_encoding_get_from_charset(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "charset", NULL };
    char *charset;
    const PlumaEncoding *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"s:encoding_get_from_charset", kwlist, &charset))
        return NULL;
    
    ret = pluma_encoding_get_from_charset(charset);
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_ENCODING, (PlumaEncoding*) ret, TRUE, TRUE);
}

#line 314 "pluma.override"
static PyObject *
_wrap_pluma_encoding_get_from_charset_deprecated(PyObject *self, PyObject *args, PyObject *kwargs)
{
    if (PyErr_Warn(PyExc_DeprecationWarning, "use pluma.encoding_get_from_charset instead") < 0)
	return NULL;
    return _wrap_pluma_encoding_get_from_charset(self, args, kwargs);
}
#line 3581 "pluma.c"


static PyObject *
_wrap_pluma_encoding_get_from_index(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "index", NULL };
    int index;
    const PlumaEncoding *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"i:encoding_get_from_index", kwlist, &index))
        return NULL;
    
    ret = pluma_encoding_get_from_index(index);
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_ENCODING, (PlumaEncoding*) ret, TRUE, TRUE);
}

#line 323 "pluma.override"
static PyObject *
_wrap_pluma_encoding_get_from_index_deprecated(PyObject *self, PyObject *args, PyObject *kwargs)
{
    if (PyErr_Warn(PyExc_DeprecationWarning, "use pluma.encoding_get_from_index instead") < 0)
	return NULL;
    return _wrap_pluma_encoding_get_from_index(self, args, kwargs);
}
#line 3608 "pluma.c"


static PyObject *
_wrap_pluma_encoding_get_utf8(PyObject *self)
{
    const PlumaEncoding *ret;

    
    ret = pluma_encoding_get_utf8();
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_ENCODING, (PlumaEncoding*) ret, TRUE, TRUE);
}

#line 332 "pluma.override"
static PyObject *
_wrap_pluma_encoding_get_utf8_deprecated(PyObject *self)
{
    if (PyErr_Warn(PyExc_DeprecationWarning, "use pluma.encoding_get_utf8 instead") < 0)
	return NULL;
    return _wrap_pluma_encoding_get_utf8(self);
}
#line 3631 "pluma.c"


static PyObject *
_wrap_pluma_encoding_get_current(PyObject *self)
{
    const PlumaEncoding *ret;

    
    ret = pluma_encoding_get_current();
    
    /* pyg_boxed_new handles NULL checking */
    return pyg_boxed_new(PLUMA_TYPE_ENCODING, (PlumaEncoding*) ret, TRUE, TRUE);
}

#line 341 "pluma.override"
static PyObject *
_wrap_pluma_encoding_get_current_deprecated(PyObject *self)
{
    if (PyErr_Warn(PyExc_DeprecationWarning, "use pluma.encoding_get_current instead") < 0)
	return NULL;
    return _wrap_pluma_encoding_get_current(self);
}
#line 3654 "pluma.c"


static PyObject *
_wrap_pluma_help_display(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "parent", "name", "link_id", NULL };
    PyGObject *parent;
    char *name, *link_id;
    int ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!ss:help_display", kwlist, &PyGtkWindow_Type, &parent, &name, &link_id))
        return NULL;
    
    ret = pluma_help_display(GTK_WINDOW(parent->obj), name, link_id);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_tab_get_from_document(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "doc", NULL };
    PyGObject *doc;
    PlumaTab *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O!:tab_get_from_document", kwlist, &PyPlumaDocument_Type, &doc))
        return NULL;
    
    ret = pluma_tab_get_from_document(PLUMA_DOCUMENT(doc->obj));
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 350 "pluma.override"
static PyObject *
_wrap_pluma_tab_get_from_document_deprecated(PyObject *self, PyObject *args, PyObject *kwargs)
{
    if (PyErr_Warn(PyExc_DeprecationWarning, "use pluma.tab_get_from_document instead") < 0)
	return NULL;
    return _wrap_pluma_tab_get_from_document(self, args, kwargs);
}
#line 3698 "pluma.c"


static PyObject *
_wrap_pluma_get_language_manager(PyObject *self)
{
    GtkSourceLanguageManager *ret;

    
    ret = pluma_get_language_manager();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

#line 359 "pluma.override"
static PyObject *
_wrap_pluma_language_manager_list_languages_sorted(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "lm", "include_hidden", NULL };
    PyGObject *lm;
    int include_hidden;
    PyObject *py_list;
    GSList *list;

    if (!PyArg_ParseTupleAndKeywords (args, kwargs,
                                      "O!i:language_manager_list_languages_sorted",
                                      kwlist, &PyGtkSourceLanguageManager_Type, &lm,
                                      &include_hidden))
        return NULL;

    list = pluma_language_manager_list_languages_sorted (GTK_SOURCE_LANGUAGE_MANAGER (lm->obj),
                                                         include_hidden);

    py_list = _helper_wrap_gobject_gslist (list);

    g_slist_free (list);

    return py_list;
}
#line 3738 "pluma.c"


static PyObject *
_wrap_pluma_message_bus_get_default(PyObject *self)
{
    PlumaMessageBus *ret;

    
    ret = pluma_message_bus_get_default();
    
    /* pygobject_new handles NULL checking */
    return pygobject_new((GObject *)ret);
}

static PyObject *
_wrap_pluma_message_type_is_supported(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "type", NULL };
    PyObject *py_type = NULL;
    int ret;
    GType type;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"O:pluma_message_type_is_supported", kwlist, &py_type))
        return NULL;
    if ((type = pyg_type_from_object(py_type)) == 0)
        return NULL;
    
    ret = pluma_message_type_is_supported(type);
    
    return PyBool_FromLong(ret);

}

static PyObject *
_wrap_pluma_message_type_identifier(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "object_path", "method", NULL };
    char *object_path, *method;
    gchar *ret;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs,"ss:pluma_message_type_identifier", kwlist, &object_path, &method))
        return NULL;
    
    ret = pluma_message_type_identifier(object_path, method);
    
    if (ret) {
        PyObject *py_ret = PyString_FromString(ret);
        g_free(ret);
        return py_ret;
    }
    Py_INCREF(Py_None);
    return Py_None;
}

#line 385 "pluma.override"
static PyObject *
_wrap_pluma_debug(PyObject *self, PyObject *args, PyObject *kwargs)
{
    static char *kwlist[] = { "message", NULL };
    PyObject *traceback_module, *mdict, *func, *traceback, *tuple;
    PyObject *filename, *lineno, *funcname;
    char *message = NULL;

    if (g_getenv ("PLUMA_DEBUG_PLUGINS") == NULL)
    {
        Py_INCREF (Py_None);
        return Py_None;
    }

    if (!PyArg_ParseTupleAndKeywords (args, kwargs, "|s", kwlist, &message))
        return NULL;

    traceback_module = PyImport_ImportModule ("traceback");
    if (traceback_module == NULL)
    {
        g_warning ("traceback module cannot be imported");
        Py_INCREF (Py_None);
        return Py_None;
    }

    mdict = PyModule_GetDict (traceback_module);
    func = PyDict_GetItemString (mdict, "extract_stack");
    traceback = PyObject_CallFunction (func, "zi", NULL, 1);
    tuple = PyList_GetItem (traceback, 0);

    if (tuple == NULL || !PyTuple_Check (tuple))
    {
        g_warning ("traceback tuple is null!");
    }
    else
    {
        filename = PyTuple_GetItem (tuple, 0);
        lineno = PyTuple_GetItem (tuple, 1);
        funcname = PyTuple_GetItem (tuple, 2);

        if (message == NULL)
            pluma_debug (PLUMA_DEBUG_PLUGINS,
                         PyString_AsString (filename),
                         PyInt_AsLong (lineno),
                         PyString_AsString (funcname));
        else
            pluma_debug_message (PLUMA_DEBUG_PLUGINS,
                                 PyString_AsString (filename),
                                 PyInt_AsLong (lineno),
                                 PyString_AsString (funcname),
                                 "%s",
                                 message);
    }
    Py_DECREF (traceback);
    Py_DECREF (traceback_module);

    Py_INCREF (Py_None);
    return Py_None;
}
#line 3853 "pluma.c"


const PyMethodDef pypluma_functions[] = {
    { "app_get_default", (PyCFunction)_wrap_pluma_app_get_default, METH_NOARGS,
      NULL },
    { "pluma_app_get_default", (PyCFunction)_wrap_pluma_app_get_default_deprecated, METH_VARARGS,
      NULL },
    { "encoding_get_from_charset", (PyCFunction)_wrap_pluma_encoding_get_from_charset, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "pluma_encoding_get_from_charset", (PyCFunction)_wrap_pluma_encoding_get_from_charset_deprecated, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "encoding_get_from_index", (PyCFunction)_wrap_pluma_encoding_get_from_index, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "pluma_encoding_get_from_index", (PyCFunction)_wrap_pluma_encoding_get_from_index_deprecated, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "encoding_get_utf8", (PyCFunction)_wrap_pluma_encoding_get_utf8, METH_NOARGS,
      NULL },
    { "pluma_encoding_get_utf8", (PyCFunction)_wrap_pluma_encoding_get_utf8_deprecated, METH_VARARGS,
      NULL },
    { "encoding_get_current", (PyCFunction)_wrap_pluma_encoding_get_current, METH_NOARGS,
      NULL },
    { "pluma_encoding_get_current", (PyCFunction)_wrap_pluma_encoding_get_current_deprecated, METH_VARARGS,
      NULL },
    { "help_display", (PyCFunction)_wrap_pluma_help_display, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "tab_get_from_document", (PyCFunction)_wrap_pluma_tab_get_from_document, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "pluma_tab_get_from_document", (PyCFunction)_wrap_pluma_tab_get_from_document_deprecated, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "get_language_manager", (PyCFunction)_wrap_pluma_get_language_manager, METH_NOARGS,
      NULL },
    { "language_manager_list_languages_sorted", (PyCFunction)_wrap_pluma_language_manager_list_languages_sorted, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "message_bus_get_default", (PyCFunction)_wrap_pluma_message_bus_get_default, METH_NOARGS,
      NULL },
    { "pluma_message_type_is_supported", (PyCFunction)_wrap_pluma_message_type_is_supported, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "pluma_message_type_identifier", (PyCFunction)_wrap_pluma_message_type_identifier, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { "debug", (PyCFunction)_wrap_pluma_debug, METH_VARARGS|METH_KEYWORDS,
      NULL },
    { NULL, NULL, 0, NULL }
};


/* ----------- enums and flags ----------- */

void
pypluma_add_constants(PyObject *module, const gchar *strip_prefix)
{
#ifdef VERSION
    PyModule_AddStringConstant(module, "__version__", VERSION);
#endif
  pyg_flags_add(module, "LockdownMask", strip_prefix, PLUMA_TYPE_LOCKDOWN_MASK);
  pyg_flags_add(module, "SearchFlags", strip_prefix, PLUMA_TYPE_SEARCH_FLAGS);
  pyg_flags_add(module, "DocumentSaveFlags", strip_prefix, PLUMA_TYPE_DOCUMENT_SAVE_FLAGS);
  pyg_enum_add(module, "TabState", strip_prefix, PLUMA_TYPE_TAB_STATE);
  pyg_flags_add(module, "WindowState", strip_prefix, PLUMA_TYPE_WINDOW_STATE);

  if (PyErr_Occurred())
    PyErr_Print();
}

/* initialise stuff extension classes */
void
pypluma_register_classes(PyObject *d)
{
    PyObject *module;

    if ((module = PyImport_ImportModule("gobject")) != NULL) {
        _PyGObject_Type = (PyTypeObject *)PyObject_GetAttrString(module, "GObject");
        if (_PyGObject_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name GObject from gobject");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gobject");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk")) != NULL) {
        _PyGtkWidget_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Widget");
        if (_PyGtkWidget_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Widget from gtk");
            return ;
        }
        _PyGtkVBox_Type = (PyTypeObject *)PyObject_GetAttrString(module, "VBox");
        if (_PyGtkVBox_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name VBox from gtk");
            return ;
        }
        _PyGtkWindow_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Window");
        if (_PyGtkWindow_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Window from gtk");
            return ;
        }
        _PyGtkImage_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Image");
        if (_PyGtkImage_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Image from gtk");
            return ;
        }
        _PyGtkStatusbar_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Statusbar");
        if (_PyGtkStatusbar_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Statusbar from gtk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk");
        return ;
    }
    if ((module = PyImport_ImportModule("gtksourceview2")) != NULL) {
        _PyGtkSourceBuffer_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Buffer");
        if (_PyGtkSourceBuffer_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Buffer from gtksourceview2");
            return ;
        }
        _PyGtkSourceView_Type = (PyTypeObject *)PyObject_GetAttrString(module, "View");
        if (_PyGtkSourceView_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name View from gtksourceview2");
            return ;
        }
        _PyGtkSourceLanguage_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Language");
        if (_PyGtkSourceLanguage_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Language from gtksourceview2");
            return ;
        }
        _PyGtkSourceLanguageManager_Type = (PyTypeObject *)PyObject_GetAttrString(module, "LanguageManager");
        if (_PyGtkSourceLanguageManager_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name LanguageManager from gtksourceview2");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtksourceview2");
        return ;
    }
    if ((module = PyImport_ImportModule("gtk.gdk")) != NULL) {
        _PyGdkScreen_Type = (PyTypeObject *)PyObject_GetAttrString(module, "Screen");
        if (_PyGdkScreen_Type == NULL) {
            PyErr_SetString(PyExc_ImportError,
                "cannot import name Screen from gtk.gdk");
            return ;
        }
    } else {
        PyErr_SetString(PyExc_ImportError,
            "could not import gtk.gdk");
        return ;
    }


#line 4015 "pluma.c"
    pyg_register_boxed(d, "Encoding", PLUMA_TYPE_ENCODING, &PyPlumaEncoding_Type);
    pyg_register_boxed(d, "MessageType", PLUMA_TYPE_MESSAGE_TYPE, &PyPlumaMessageType_Type);
    pygobject_register_class(d, "PlumaApp", PLUMA_TYPE_APP, &PyPlumaApp_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_APP);
    pygobject_register_class(d, "PlumaDocument", PLUMA_TYPE_DOCUMENT, &PyPlumaDocument_Type, Py_BuildValue("(O)", &PyGtkSourceBuffer_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_DOCUMENT);
    pygobject_register_class(d, "PlumaMessage", PLUMA_TYPE_MESSAGE, &PyPlumaMessage_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_MESSAGE);
    pygobject_register_class(d, "PlumaMessageBus", PLUMA_TYPE_MESSAGE_BUS, &PyPlumaMessageBus_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_MESSAGE_BUS);
    pygobject_register_class(d, "PlumaPanel", PLUMA_TYPE_PANEL, &PyPlumaPanel_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_PANEL);
    pygobject_register_class(d, "PlumaPlugin", PLUMA_TYPE_PLUGIN, &PyPlumaPlugin_Type, Py_BuildValue("(O)", &PyGObject_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_PLUGIN);
    pygobject_register_class(d, "PlumaPluginPython", PLUMA_TYPE_PLUGIN_PYTHON, &PyPlumaPluginPython_Type, Py_BuildValue("(O)", &PyPlumaPlugin_Type));
    pyg_set_object_has_new_constructor(PLUMA_TYPE_PLUGIN_PYTHON);
    pygobject_register_class(d, "PlumaStatusbar", PLUMA_TYPE_STATUSBAR, &PyPlumaStatusbar_Type, Py_BuildValue("(O)", &PyGtkStatusbar_Type));
    pygobject_register_class(d, "PlumaTab", PLUMA_TYPE_TAB, &PyPlumaTab_Type, Py_BuildValue("(O)", &PyGtkVBox_Type));
    pygobject_register_class(d, "PlumaView", PLUMA_TYPE_VIEW, &PyPlumaView_Type, Py_BuildValue("(O)", &PyGtkSourceView_Type));
    pygobject_register_class(d, "PlumaWindow", PLUMA_TYPE_WINDOW, &PyPlumaWindow_Type, Py_BuildValue("(O)", &PyGtkWindow_Type));
}
