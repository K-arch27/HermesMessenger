/* extension.c
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

#include <webkit2/webkit-web-extension.h>
#include <glib-object.h>
#include <JavaScriptCore/JavaScript.h>

static void
window_object_cleared_callback (WebKitScriptWorld *world,
                                WebKitWebPage     *web_page,
                                WebKitFrame       *frame,
                                gpointer           user_data)
{
    JSGlobalContextRef jsContext;
    JSObjectRef        globalObject;

    jsContext = webkit_frame_get_javascript_context_for_script_world (frame, world);
    globalObject = JSContextGetGlobalObject (jsContext);

    /* Use JSC API to add the JavaScript code you want */
}

G_MODULE_EXPORT void
webkit_web_extension_initialize (WebKitWebExtension *extension)
{
    g_signal_connect (webkit_script_world_get_default (),
                      "window-object-cleared",
                      G_CALLBACK (window_object_cleared_callback),
                      NULL);
}
