
/* Generated data (by glib-mkenums) */

#include "pluma-file-browser-enum-types.h"

/* enumerations from "pluma-file-browser-store.h" */
#include "pluma-file-browser-store.h"

static GType pluma_file_browser_store_column_type = 0;

static GType
register_pluma_file_browser_store_column (GTypeModule *module)
{
	static const GEnumValue values[] = {
		{ PLUMA_FILE_BROWSER_STORE_COLUMN_ICON,
		  "PLUMA_FILE_BROWSER_STORE_COLUMN_ICON",
		  "icon" },
		{ PLUMA_FILE_BROWSER_STORE_COLUMN_NAME,
		  "PLUMA_FILE_BROWSER_STORE_COLUMN_NAME",
		  "name" },
		{ PLUMA_FILE_BROWSER_STORE_COLUMN_URI,
		  "PLUMA_FILE_BROWSER_STORE_COLUMN_URI",
		  "uri" },
		{ PLUMA_FILE_BROWSER_STORE_COLUMN_FLAGS,
		  "PLUMA_FILE_BROWSER_STORE_COLUMN_FLAGS",
		  "flags" },
		{ PLUMA_FILE_BROWSER_STORE_COLUMN_EMBLEM,
		  "PLUMA_FILE_BROWSER_STORE_COLUMN_EMBLEM",
		  "emblem" },
		{ PLUMA_FILE_BROWSER_STORE_COLUMN_NUM,
		  "PLUMA_FILE_BROWSER_STORE_COLUMN_NUM",
		  "num" },
		{ 0, NULL, NULL }
	};

	pluma_file_browser_store_column_type =
		g_type_module_register_enum (module,
		                               "PlumaFileBrowserStoreColumn",
		                               values);

	return pluma_file_browser_store_column_type;
}

GType
pluma_file_browser_store_column_get_type (void)
{
	return pluma_file_browser_store_column_type;
}

static GType pluma_file_browser_store_flag_type = 0;

static GType
register_pluma_file_browser_store_flag (GTypeModule *module)
{
	static const GFlagsValue values[] = {
		{ PLUMA_FILE_BROWSER_STORE_FLAG_IS_DIRECTORY,
		  "PLUMA_FILE_BROWSER_STORE_FLAG_IS_DIRECTORY",
		  "is-directory" },
		{ PLUMA_FILE_BROWSER_STORE_FLAG_IS_HIDDEN,
		  "PLUMA_FILE_BROWSER_STORE_FLAG_IS_HIDDEN",
		  "is-hidden" },
		{ PLUMA_FILE_BROWSER_STORE_FLAG_IS_TEXT,
		  "PLUMA_FILE_BROWSER_STORE_FLAG_IS_TEXT",
		  "is-text" },
		{ PLUMA_FILE_BROWSER_STORE_FLAG_LOADED,
		  "PLUMA_FILE_BROWSER_STORE_FLAG_LOADED",
		  "loaded" },
		{ PLUMA_FILE_BROWSER_STORE_FLAG_IS_FILTERED,
		  "PLUMA_FILE_BROWSER_STORE_FLAG_IS_FILTERED",
		  "is-filtered" },
		{ PLUMA_FILE_BROWSER_STORE_FLAG_IS_DUMMY,
		  "PLUMA_FILE_BROWSER_STORE_FLAG_IS_DUMMY",
		  "is-dummy" },
		{ 0, NULL, NULL }
	};

	pluma_file_browser_store_flag_type =
		g_type_module_register_flags (module,
		                               "PlumaFileBrowserStoreFlag",
		                               values);

	return pluma_file_browser_store_flag_type;
}

GType
pluma_file_browser_store_flag_get_type (void)
{
	return pluma_file_browser_store_flag_type;
}

static GType pluma_file_browser_store_result_type = 0;

static GType
register_pluma_file_browser_store_result (GTypeModule *module)
{
	static const GEnumValue values[] = {
		{ PLUMA_FILE_BROWSER_STORE_RESULT_OK,
		  "PLUMA_FILE_BROWSER_STORE_RESULT_OK",
		  "ok" },
		{ PLUMA_FILE_BROWSER_STORE_RESULT_NO_CHANGE,
		  "PLUMA_FILE_BROWSER_STORE_RESULT_NO_CHANGE",
		  "no-change" },
		{ PLUMA_FILE_BROWSER_STORE_RESULT_ERROR,
		  "PLUMA_FILE_BROWSER_STORE_RESULT_ERROR",
		  "error" },
		{ PLUMA_FILE_BROWSER_STORE_RESULT_NO_TRASH,
		  "PLUMA_FILE_BROWSER_STORE_RESULT_NO_TRASH",
		  "no-trash" },
		{ PLUMA_FILE_BROWSER_STORE_RESULT_MOUNTING,
		  "PLUMA_FILE_BROWSER_STORE_RESULT_MOUNTING",
		  "mounting" },
		{ PLUMA_FILE_BROWSER_STORE_RESULT_NUM,
		  "PLUMA_FILE_BROWSER_STORE_RESULT_NUM",
		  "num" },
		{ 0, NULL, NULL }
	};

	pluma_file_browser_store_result_type =
		g_type_module_register_enum (module,
		                               "PlumaFileBrowserStoreResult",
		                               values);

	return pluma_file_browser_store_result_type;
}

GType
pluma_file_browser_store_result_get_type (void)
{
	return pluma_file_browser_store_result_type;
}

static GType pluma_file_browser_store_filter_mode_type = 0;

static GType
register_pluma_file_browser_store_filter_mode (GTypeModule *module)
{
	static const GFlagsValue values[] = {
		{ PLUMA_FILE_BROWSER_STORE_FILTER_MODE_NONE,
		  "PLUMA_FILE_BROWSER_STORE_FILTER_MODE_NONE",
		  "none" },
		{ PLUMA_FILE_BROWSER_STORE_FILTER_MODE_HIDE_HIDDEN,
		  "PLUMA_FILE_BROWSER_STORE_FILTER_MODE_HIDE_HIDDEN",
		  "hide-hidden" },
		{ PLUMA_FILE_BROWSER_STORE_FILTER_MODE_HIDE_BINARY,
		  "PLUMA_FILE_BROWSER_STORE_FILTER_MODE_HIDE_BINARY",
		  "hide-binary" },
		{ 0, NULL, NULL }
	};

	pluma_file_browser_store_filter_mode_type =
		g_type_module_register_flags (module,
		                               "PlumaFileBrowserStoreFilterMode",
		                               values);

	return pluma_file_browser_store_filter_mode_type;
}

GType
pluma_file_browser_store_filter_mode_get_type (void)
{
	return pluma_file_browser_store_filter_mode_type;
}

/* enumerations from "pluma-file-browser-view.h" */
#include "pluma-file-browser-view.h"

static GType pluma_file_browser_view_click_policy_type = 0;

static GType
register_pluma_file_browser_view_click_policy (GTypeModule *module)
{
	static const GEnumValue values[] = {
		{ PLUMA_FILE_BROWSER_VIEW_CLICK_POLICY_DOUBLE,
		  "PLUMA_FILE_BROWSER_VIEW_CLICK_POLICY_DOUBLE",
		  "double" },
		{ PLUMA_FILE_BROWSER_VIEW_CLICK_POLICY_SINGLE,
		  "PLUMA_FILE_BROWSER_VIEW_CLICK_POLICY_SINGLE",
		  "single" },
		{ 0, NULL, NULL }
	};

	pluma_file_browser_view_click_policy_type =
		g_type_module_register_enum (module,
		                               "PlumaFileBrowserViewClickPolicy",
		                               values);

	return pluma_file_browser_view_click_policy_type;
}

GType
pluma_file_browser_view_click_policy_get_type (void)
{
	return pluma_file_browser_view_click_policy_type;
}

/* enumerations from "pluma-file-browser-error.h" */
#include "pluma-file-browser-error.h"

static GType pluma_file_browser_error_type = 0;

static GType
register_pluma_file_browser_error (GTypeModule *module)
{
	static const GEnumValue values[] = {
		{ PLUMA_FILE_BROWSER_ERROR_NONE,
		  "PLUMA_FILE_BROWSER_ERROR_NONE",
		  "none" },
		{ PLUMA_FILE_BROWSER_ERROR_RENAME,
		  "PLUMA_FILE_BROWSER_ERROR_RENAME",
		  "rename" },
		{ PLUMA_FILE_BROWSER_ERROR_DELETE,
		  "PLUMA_FILE_BROWSER_ERROR_DELETE",
		  "delete" },
		{ PLUMA_FILE_BROWSER_ERROR_NEW_FILE,
		  "PLUMA_FILE_BROWSER_ERROR_NEW_FILE",
		  "new-file" },
		{ PLUMA_FILE_BROWSER_ERROR_NEW_DIRECTORY,
		  "PLUMA_FILE_BROWSER_ERROR_NEW_DIRECTORY",
		  "new-directory" },
		{ PLUMA_FILE_BROWSER_ERROR_OPEN_DIRECTORY,
		  "PLUMA_FILE_BROWSER_ERROR_OPEN_DIRECTORY",
		  "open-directory" },
		{ PLUMA_FILE_BROWSER_ERROR_SET_ROOT,
		  "PLUMA_FILE_BROWSER_ERROR_SET_ROOT",
		  "set-root" },
		{ PLUMA_FILE_BROWSER_ERROR_LOAD_DIRECTORY,
		  "PLUMA_FILE_BROWSER_ERROR_LOAD_DIRECTORY",
		  "load-directory" },
		{ PLUMA_FILE_BROWSER_ERROR_NUM,
		  "PLUMA_FILE_BROWSER_ERROR_NUM",
		  "num" },
		{ 0, NULL, NULL }
	};

	pluma_file_browser_error_type =
		g_type_module_register_enum (module,
		                               "PlumaFileBrowserError",
		                               values);

	return pluma_file_browser_error_type;
}

GType
pluma_file_browser_error_get_type (void)
{
	return pluma_file_browser_error_type;
}


/* Generated data ends here */


/* Generated data (by glib-mkenums) */

void
pluma_file_browser_enum_and_flag_register_type (GTypeModule * module)
{
	/* Enumerations from "pluma-file-browser-store.h" */
	
	register_pluma_file_browser_store_column (module);

	register_pluma_file_browser_store_flag (module);

	register_pluma_file_browser_store_result (module);

	register_pluma_file_browser_store_filter_mode (module);

	/* Enumerations from "pluma-file-browser-view.h" */
	
	register_pluma_file_browser_view_click_policy (module);

	/* Enumerations from "pluma-file-browser-error.h" */
	
	register_pluma_file_browser_error (module);

}


/* Generated data ends here */

