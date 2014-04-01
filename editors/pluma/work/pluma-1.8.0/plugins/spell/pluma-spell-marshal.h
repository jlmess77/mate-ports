
#ifndef __pluma_marshal_MARSHAL_H__
#define __pluma_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:STRING (pluma-spell-marshal.list:1) */
#define pluma_marshal_VOID__STRING	g_cclosure_marshal_VOID__STRING

/* VOID:STRING,STRING (pluma-spell-marshal.list:2) */
extern void pluma_marshal_VOID__STRING_STRING (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:STRING,INT (pluma-spell-marshal.list:3) */
extern void pluma_marshal_VOID__STRING_INT (GClosure     *closure,
                                            GValue       *return_value,
                                            guint         n_param_values,
                                            const GValue *param_values,
                                            gpointer      invocation_hint,
                                            gpointer      marshal_data);

/* VOID:POINTER (pluma-spell-marshal.list:4) */
#define pluma_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER

/* VOID:VOID (pluma-spell-marshal.list:5) */
#define pluma_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID

G_END_DECLS

#endif /* __pluma_marshal_MARSHAL_H__ */

