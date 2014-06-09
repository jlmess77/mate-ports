
#ifndef __nld_marshal_MARSHAL_H__
#define __nld_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:INT,STRING (./nld-marshal.list:1) */
extern void nld_marshal_VOID__INT_STRING (GClosure     *closure,
                                          GValue       *return_value,
                                          guint         n_param_values,
                                          const GValue *param_values,
                                          gpointer      invocation_hint,
                                          gpointer      marshal_data);

G_END_DECLS

#endif /* __nld_marshal_MARSHAL_H__ */

