/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 8 -*-  */
/*
 * draw-application.c
 * Copyright (C) 2013 Erick Pérez Castellanos <erick.red@gmail.com>
 *
 * draw is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * draw is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "draw-application.h"

#include <glib/gi18n.h>

G_DEFINE_TYPE (DrawApplication, draw_application, GTK_TYPE_APPLICATION);

/* Create a new window loading a file */
static void
draw_application_new_window (GApplication *app,
                             GFile        *file)
{
  GtkWidget *window;

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "draw");

  gtk_window_set_application (GTK_WINDOW (window), GTK_APPLICATION (app));
  if (file != NULL)
    {
      /* TODO: Add code here to open the file in the new window */
    }
  gtk_widget_show_all (GTK_WIDGET (window));
}


/* GApplication implementation */
static void
draw_application_activate (GApplication *application)
{
  draw_application_new_window (application, NULL);
}

static void
draw_application_open (GApplication  *application,
                       GFile        **files,
                       gint           n_files,
                       const gchar   *hint)
{
  gint i;

  for (i = 0; i < n_files; i++)
    draw_application_new_window (application, files[i]);
}

static void
draw_application_init (DrawApplication *object)
{

}

static void
draw_application_finalize (GObject *object)
{
  G_OBJECT_CLASS (draw_application_parent_class)->finalize (object);
}

static void
draw_application_class_init (DrawApplicationClass *klass)
{
  G_APPLICATION_CLASS (klass)->activate = draw_application_activate;
  G_APPLICATION_CLASS (klass)->open = draw_application_open;

  G_OBJECT_CLASS (klass)->finalize = draw_application_finalize;
}

DrawApplication*
draw_application_new (void)
{
  return g_object_new (draw_application_get_type (),
                       "application-id", "org.gnome.draw",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}
