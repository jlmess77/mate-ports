
#ifndef __pluma_marshal_MARSHAL_H__
#define __pluma_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* BOOLEAN:NONE (pluma-marshal.list:1) */
extern void pluma_marshal_BOOLEAN__VOID (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);
#define pluma_marshal_BOOLEAN__NONE	pluma_marshal_BOOLEAN__VOID

/* BOOLEAN:OBJECT (pluma-marshal.list:2) */
extern void pluma_marshal_BOOLEAN__OBJECT (GClosure     *closure,
                                           GValue       *return_value,
                                           guint         n_param_values,
                                           const GValue *param_values,
                                           gpointer      invocation_hint,
                                           gpointer      marshal_data);

/* VOID:BOOLEAN (pluma-marshal.list:3) */
#define pluma_marshal_VOID__BOOLEAN	g_cclosure_marshal_VOID__BOOLEAN

/* VOID:BOOLEAN,POINTER (pluma-marshal.list:4) */
extern void pluma_marshal_VOID__BOOLEAN_POINTER (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:BOXED,BOXED (pluma-marshal.list:5) */
extern void pluma_marshal_VOID__BOXED_BOXED (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

/* VOID:OBJECT (pluma-marshal.list:6) */
#define pluma_marshal_VOID__OBJECT	g_cclosure_marshal_VOID__OBJECT

/* VOID:POINTER (pluma-marshal.list:7) */
#define pluma_marshal_VOID__POINTER	g_cclosure_marshal_VOID__POINTER

/* VOID:STRING,BOXED,FLAGS (pluma-marshal.list:8) */
extern void pluma_marshal_VOID__STRING_BOXED_FLAGS (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);

/* VOID:STRING,BOXED,INT,BOOLEAN (pluma-marshal.list:9) */
extern void pluma_marshal_VOID__STRING_BOXED_INT_BOOLEAN (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);

/* VOID:UINT,POINTER (pluma-marshal.list:10) */
#define pluma_marshal_VOID__UINT_POINTER	g_cclosure_marshal_VOID__UINT_POINTER

/* VOID:UINT64,UINT64 (pluma-marshal.list:11) */
extern void pluma_marshal_VOID__UINT64_UINT64 (GClosure     *closure,
                                               GValue       *return_value,
                                               guint         n_param_values,
                                               const GValue *param_values,
                                               gpointer      invocation_hint,
                                               gpointer      marshal_data);

/* VOID:VOID (pluma-marshal.list:12) */
#define pluma_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID

/* VOID:INT,INT (pluma-marshal.list:13) */
extern void pluma_marshal_VOID__INT_INT (GClosure     *closure,
                                         GValue       *return_value,
                                         guint         n_param_values,
                                         const GValue *param_values,
                                         gpointer      invocation_hint,
                                         gpointer      marshal_data);

G_END_DECLS

#endif /* __pluma_marshal_MARSHAL_H__ */

