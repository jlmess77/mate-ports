
/* Generated data (by glib-mkenums) */

#include "pluma-enum-types.h"

/* enumerations from "pluma-app.h" */
#include "pluma-app.h"

GType
pluma_lockdown_mask_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GFlagsValue values[] = {
			{ PLUMA_LOCKDOWN_COMMAND_LINE,
			  "PLUMA_LOCKDOWN_COMMAND_LINE",
			  "command-line" },
			{ PLUMA_LOCKDOWN_PRINTING,
			  "PLUMA_LOCKDOWN_PRINTING",
			  "printing" },
			{ PLUMA_LOCKDOWN_PRINT_SETUP,
			  "PLUMA_LOCKDOWN_PRINT_SETUP",
			  "print-setup" },
			{ PLUMA_LOCKDOWN_SAVE_TO_DISK,
			  "PLUMA_LOCKDOWN_SAVE_TO_DISK",
			  "save-to-disk" },
			{ PLUMA_LOCKDOWN_ALL,
			  "PLUMA_LOCKDOWN_ALL",
			  "all" },
			{ 0, NULL, NULL }
		};
		the_type = g_flags_register_static (
				g_intern_static_string ("PlumaLockdownMask"),
				values);
	}
	return the_type;
}

/* enumerations from "pluma-debug.h" */
#include "pluma-debug.h"

GType
pluma_debug_section_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GFlagsValue values[] = {
			{ PLUMA_NO_DEBUG,
			  "PLUMA_NO_DEBUG",
			  "no-debug" },
			{ PLUMA_DEBUG_VIEW,
			  "PLUMA_DEBUG_VIEW",
			  "debug-view" },
			{ PLUMA_DEBUG_SEARCH,
			  "PLUMA_DEBUG_SEARCH",
			  "debug-search" },
			{ PLUMA_DEBUG_PRINT,
			  "PLUMA_DEBUG_PRINT",
			  "debug-print" },
			{ PLUMA_DEBUG_PREFS,
			  "PLUMA_DEBUG_PREFS",
			  "debug-prefs" },
			{ PLUMA_DEBUG_PLUGINS,
			  "PLUMA_DEBUG_PLUGINS",
			  "debug-plugins" },
			{ PLUMA_DEBUG_TAB,
			  "PLUMA_DEBUG_TAB",
			  "debug-tab" },
			{ PLUMA_DEBUG_DOCUMENT,
			  "PLUMA_DEBUG_DOCUMENT",
			  "debug-document" },
			{ PLUMA_DEBUG_COMMANDS,
			  "PLUMA_DEBUG_COMMANDS",
			  "debug-commands" },
			{ PLUMA_DEBUG_APP,
			  "PLUMA_DEBUG_APP",
			  "debug-app" },
			{ PLUMA_DEBUG_SESSION,
			  "PLUMA_DEBUG_SESSION",
			  "debug-session" },
			{ PLUMA_DEBUG_UTILS,
			  "PLUMA_DEBUG_UTILS",
			  "debug-utils" },
			{ PLUMA_DEBUG_METADATA,
			  "PLUMA_DEBUG_METADATA",
			  "debug-metadata" },
			{ PLUMA_DEBUG_WINDOW,
			  "PLUMA_DEBUG_WINDOW",
			  "debug-window" },
			{ PLUMA_DEBUG_LOADER,
			  "PLUMA_DEBUG_LOADER",
			  "debug-loader" },
			{ PLUMA_DEBUG_SAVER,
			  "PLUMA_DEBUG_SAVER",
			  "debug-saver" },
			{ 0, NULL, NULL }
		};
		the_type = g_flags_register_static (
				g_intern_static_string ("PlumaDebugSection"),
				values);
	}
	return the_type;
}

/* enumerations from "pluma-document.h" */
#include "pluma-document.h"

GType
pluma_document_newline_type_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GEnumValue values[] = {
			{ PLUMA_DOCUMENT_NEWLINE_TYPE_LF,
			  "PLUMA_DOCUMENT_NEWLINE_TYPE_LF",
			  "lf" },
			{ PLUMA_DOCUMENT_NEWLINE_TYPE_CR,
			  "PLUMA_DOCUMENT_NEWLINE_TYPE_CR",
			  "cr" },
			{ PLUMA_DOCUMENT_NEWLINE_TYPE_CR_LF,
			  "PLUMA_DOCUMENT_NEWLINE_TYPE_CR_LF",
			  "cr-lf" },
			{ 0, NULL, NULL }
		};
		the_type = g_enum_register_static (
				g_intern_static_string ("PlumaDocumentNewlineType"),
				values);
	}
	return the_type;
}

GType
pluma_search_flags_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GFlagsValue values[] = {
			{ PLUMA_SEARCH_DONT_SET_FLAGS,
			  "PLUMA_SEARCH_DONT_SET_FLAGS",
			  "dont-set-flags" },
			{ PLUMA_SEARCH_ENTIRE_WORD,
			  "PLUMA_SEARCH_ENTIRE_WORD",
			  "entire-word" },
			{ PLUMA_SEARCH_CASE_SENSITIVE,
			  "PLUMA_SEARCH_CASE_SENSITIVE",
			  "case-sensitive" },
			{ PLUMA_SEARCH_PARSE_ESCAPES,
			  "PLUMA_SEARCH_PARSE_ESCAPES",
			  "parse-escapes" },
			{ 0, NULL, NULL }
		};
		the_type = g_flags_register_static (
				g_intern_static_string ("PlumaSearchFlags"),
				values);
	}
	return the_type;
}

GType
pluma_document_save_flags_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GFlagsValue values[] = {
			{ PLUMA_DOCUMENT_SAVE_IGNORE_MTIME,
			  "PLUMA_DOCUMENT_SAVE_IGNORE_MTIME",
			  "ignore-mtime" },
			{ PLUMA_DOCUMENT_SAVE_IGNORE_BACKUP,
			  "PLUMA_DOCUMENT_SAVE_IGNORE_BACKUP",
			  "ignore-backup" },
			{ PLUMA_DOCUMENT_SAVE_PRESERVE_BACKUP,
			  "PLUMA_DOCUMENT_SAVE_PRESERVE_BACKUP",
			  "preserve-backup" },
			{ 0, NULL, NULL }
		};
		the_type = g_flags_register_static (
				g_intern_static_string ("PlumaDocumentSaveFlags"),
				values);
	}
	return the_type;
}

/* enumerations from "pluma-prefs-manager.h" */
#include "pluma-prefs-manager.h"

GType
pluma_toolbar_setting_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GEnumValue values[] = {
			{ PLUMA_TOOLBAR_SYSTEM,
			  "PLUMA_TOOLBAR_SYSTEM",
			  "system" },
			{ PLUMA_TOOLBAR_ICONS,
			  "PLUMA_TOOLBAR_ICONS",
			  "icons" },
			{ PLUMA_TOOLBAR_ICONS_AND_TEXT,
			  "PLUMA_TOOLBAR_ICONS_AND_TEXT",
			  "icons-and-text" },
			{ PLUMA_TOOLBAR_ICONS_BOTH_HORIZ,
			  "PLUMA_TOOLBAR_ICONS_BOTH_HORIZ",
			  "icons-both-horiz" },
			{ 0, NULL, NULL }
		};
		the_type = g_enum_register_static (
				g_intern_static_string ("PlumaToolbarSetting"),
				values);
	}
	return the_type;
}

/* enumerations from "pluma-tab.h" */
#include "pluma-tab.h"

GType
pluma_tab_state_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GEnumValue values[] = {
			{ PLUMA_TAB_STATE_NORMAL,
			  "PLUMA_TAB_STATE_NORMAL",
			  "state-normal" },
			{ PLUMA_TAB_STATE_LOADING,
			  "PLUMA_TAB_STATE_LOADING",
			  "state-loading" },
			{ PLUMA_TAB_STATE_REVERTING,
			  "PLUMA_TAB_STATE_REVERTING",
			  "state-reverting" },
			{ PLUMA_TAB_STATE_SAVING,
			  "PLUMA_TAB_STATE_SAVING",
			  "state-saving" },
			{ PLUMA_TAB_STATE_PRINTING,
			  "PLUMA_TAB_STATE_PRINTING",
			  "state-printing" },
			{ PLUMA_TAB_STATE_PRINT_PREVIEWING,
			  "PLUMA_TAB_STATE_PRINT_PREVIEWING",
			  "state-print-previewing" },
			{ PLUMA_TAB_STATE_SHOWING_PRINT_PREVIEW,
			  "PLUMA_TAB_STATE_SHOWING_PRINT_PREVIEW",
			  "state-showing-print-preview" },
			{ PLUMA_TAB_STATE_GENERIC_NOT_EDITABLE,
			  "PLUMA_TAB_STATE_GENERIC_NOT_EDITABLE",
			  "state-generic-not-editable" },
			{ PLUMA_TAB_STATE_LOADING_ERROR,
			  "PLUMA_TAB_STATE_LOADING_ERROR",
			  "state-loading-error" },
			{ PLUMA_TAB_STATE_REVERTING_ERROR,
			  "PLUMA_TAB_STATE_REVERTING_ERROR",
			  "state-reverting-error" },
			{ PLUMA_TAB_STATE_SAVING_ERROR,
			  "PLUMA_TAB_STATE_SAVING_ERROR",
			  "state-saving-error" },
			{ PLUMA_TAB_STATE_GENERIC_ERROR,
			  "PLUMA_TAB_STATE_GENERIC_ERROR",
			  "state-generic-error" },
			{ PLUMA_TAB_STATE_CLOSING,
			  "PLUMA_TAB_STATE_CLOSING",
			  "state-closing" },
			{ PLUMA_TAB_STATE_EXTERNALLY_MODIFIED_NOTIFICATION,
			  "PLUMA_TAB_STATE_EXTERNALLY_MODIFIED_NOTIFICATION",
			  "state-externally-modified-notification" },
			{ PLUMA_TAB_NUM_OF_STATES,
			  "PLUMA_TAB_NUM_OF_STATES",
			  "num-of-states" },
			{ 0, NULL, NULL }
		};
		the_type = g_enum_register_static (
				g_intern_static_string ("PlumaTabState"),
				values);
	}
	return the_type;
}

/* enumerations from "pluma-window.h" */
#include "pluma-window.h"

GType
pluma_window_state_get_type (void)
{
	static GType the_type = 0;
	
	if (the_type == 0)
	{
		static const GFlagsValue values[] = {
			{ PLUMA_WINDOW_STATE_NORMAL,
			  "PLUMA_WINDOW_STATE_NORMAL",
			  "normal" },
			{ PLUMA_WINDOW_STATE_SAVING,
			  "PLUMA_WINDOW_STATE_SAVING",
			  "saving" },
			{ PLUMA_WINDOW_STATE_PRINTING,
			  "PLUMA_WINDOW_STATE_PRINTING",
			  "printing" },
			{ PLUMA_WINDOW_STATE_LOADING,
			  "PLUMA_WINDOW_STATE_LOADING",
			  "loading" },
			{ PLUMA_WINDOW_STATE_ERROR,
			  "PLUMA_WINDOW_STATE_ERROR",
			  "error" },
			{ PLUMA_WINDOW_STATE_SAVING_SESSION,
			  "PLUMA_WINDOW_STATE_SAVING_SESSION",
			  "saving-session" },
			{ 0, NULL, NULL }
		};
		the_type = g_flags_register_static (
				g_intern_static_string ("PlumaWindowState"),
				values);
	}
	return the_type;
}


/* Generated data ends here */

