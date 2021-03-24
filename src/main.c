/* main.c
 *
 * Copyright 2021 MrBn100ful
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib/gi18n.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JSValueRef.h>


static void destroyWinCb(GtkWidget* widget, GtkWidget* window)
{
    gtk_main_quit();
}

static gboolean closeWebCb(WebKitWebView* webView, GtkWidget* window)
{
    gtk_widget_destroy(window);

    return TRUE;
}

int main(int argc, char* argv[])
{
    GtkWidget *win;

    WebKitWebView *web;

    gchar *script;

    gchar * url = "https://messenger.com/login";

    gtk_init(&argc, &argv);

    if (argc == 2) url = argv[1];

    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_default_size(GTK_WINDOW(win), 360, 720);

    web = WEBKIT_WEB_VIEW(webkit_web_view_new());

    gtk_container_add(GTK_CONTAINER(win), GTK_WIDGET(web));

    g_signal_connect(win, "destroy", G_CALLBACK(destroyWinCb), NULL);

    g_signal_connect(web, "close", G_CALLBACK(closeWebCb), win);

    webkit_web_view_load_uri(web, url);

    gtk_widget_grab_focus(GTK_WIDGET(web));

    gtk_widget_show_all(win);

    gtk_main();

    script = g_strdup_printf ("alert('yes!');", url);

    webkit_web_view_run_javascript (web, script, NULL, NULL, NULL);

    g_free (script);



    return 0;
}
