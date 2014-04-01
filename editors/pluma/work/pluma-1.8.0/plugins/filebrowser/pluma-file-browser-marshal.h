
#ifndef __pluma_file_browser_marshal_MARSHAL_H__
#define __pluma_file_browser_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:UINT,STRING (pluma-file-browser-marshal.list:1) */
extern void pluma_file_browser_marshal_VOID__UINT_STRING (GClosure     *closure,
                                                          GValue       *return_value,
                                                          guint         n_param_values,
                                                          const GValue *param_values,
                                                          gpointer      invocation_hint,
                                                          gpointer      marshal_data);

/* VOID:STRING,STRING (pluma-file-browser-marshal.list:2) */
extern void pluma_file_browser_marshal_VOID__STRING_STRING (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* BOOL:OBJECT,POINTER (pluma-file-browser-marshal.list:3) */
extern void pluma_file_browser_marshal_BOOLEAN__OBJECT_POINTER (GClosure     *closure,
                                                                GValue       *return_value,
                                                                guint         n_param_values,
                                                                const GValue *param_values,
                                                                gpointer      invocation_hint,
                                                                gpointer      marshal_data);
#define pluma_file_browser_marshal_BOOL__OBJECT_POINTER	pluma_file_browser_marshal_BOOLEAN__OBJECT_POINTER

/* BOOL:POINTER (pluma-file-browser-marshal.list:4) */
extern void pluma_file_browser_marshal_BOOLEAN__POINTER (GClosure     *closure,
                                                         GValue       *return_value,
                                                         guint         n_param_values,
                                                         const GValue *param_values,
                                                         gpointer      invocation_hint,
                                                         gpointer      marshal_data);
#define pluma_file_browser_marshal_BOOL__POINTER	pluma_file_browser_marshal_BOOLEAN__POINTER

/* BOOL:VOID (pluma-file-browser-marshal.list:5) */
extern void pluma_file_browser_marshal_BOOLEAN__VOID (GClosure     *closure,
                                                      GValue       *return_value,
                                                      guint         n_param_values,
                                                      const GValue *param_values,
                                                      gpointer      invocation_hint,
                                                      gpointer      marshal_data);
#define pluma_file_browser_marshal_BOOL__VOID	pluma_file_browser_marshal_BOOLEAN__VOID

G_END_DECLS

#endif /* __pluma_file_browser_marshal_MARSHAL_H__ */

