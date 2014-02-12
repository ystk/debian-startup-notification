/* 
 * Copyright (C) 2002 Red Hat, Inc.
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef __SN_INTERNALS_H__
#define __SN_INTERNALS_H__

#include <libsn/sn-common.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <libsn/sn-list.h>
#include <libsn/sn-xutils.h>

SN_BEGIN_DECLS

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL ((void*) 0)
#endif

/* --- From sn-common.c --- */
xcb_screen_t* sn_internal_display_get_x_screen (SnDisplay              *display,
                                                int                     number);

xcb_window_t sn_internal_display_get_root_window (SnDisplay              *display,
                                                  int                     number);

int        sn_internal_display_get_screen_number (SnDisplay *display);

void*      sn_internal_display_get_id (SnDisplay *display);

void       sn_internal_display_get_xmessage_data (SnDisplay              *display,
                                                  SnList                **funcs,
                                                  SnList                **pending);

xcb_atom_t sn_internal_get_utf8_string_atom(SnDisplay *display);

xcb_atom_t sn_internal_get_net_startup_id_atom(SnDisplay *display);

xcb_atom_t sn_internal_get_net_startup_info_atom(SnDisplay *display);

xcb_atom_t sn_internal_get_net_startup_info_begin_atom(SnDisplay *display);

/* --- From sn-monitor.c --- */
sn_bool_t sn_internal_monitor_process_event (SnDisplay *display);

/* --- From sn-util.c --- */
sn_bool_t sn_internal_utf8_validate (const char *str,
                                     int         max_len);
char*     sn_internal_strdup        (const char *str);
char*     sn_internal_strndup       (const char *str,
                                     int         n);
void      sn_internal_strfreev      (char      **strings);

unsigned long sn_internal_string_to_ulong (const char* str);

char*     sn_internal_find_last_occurrence (const char* haystack, 
                                            const char* needle);

void sn_internal_append_to_string (char      **append_to,
                                   int        *current_len,
                                   const char *append);

/* --- From sn-xmessages.c --- */
sn_bool_t sn_internal_xmessage_process_client_message (SnDisplay  *display,
                                                       xcb_window_t window,
                                                       xcb_atom_t   type,
                                                       const char  *data);

SN_END_DECLS

#endif /* __SN_INTERNALS_H__ */
