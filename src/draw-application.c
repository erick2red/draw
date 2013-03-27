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

struct _DrawApplicationPrivate
{
  GtkWidget *window;
};

G_DEFINE_TYPE (DrawApplication, draw_application, GTK_TYPE_APPLICATION);

static void
draw_application_new_window (GApplication *app)
{
  DrawApplicationPrivate *priv;
  priv = DRAW_APPLICATION (app)->priv;

  priv->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (priv->window), "draw");

  gtk_window_set_application (GTK_WINDOW (priv->window), GTK_APPLICATION (app));
  gtk_widget_show_all (GTK_WIDGET (priv->window));
}

static void
draw_application_activate (GApplication *application)
{
  DrawApplicationPrivate *priv;

  priv = DRAW_APPLICATION (application)->priv;

  if (priv->window == NULL)
    draw_application_new_window (application);

  gtk_window_present (GTK_WINDOW (priv->window));
}

static void
draw_application_class_init (DrawApplicationClass *klass)
{
  GApplicationClass *application_class;

  application_class = G_APPLICATION_CLASS (klass);
  application_class->activate = draw_application_activate;

  g_type_class_add_private ((gpointer) klass, sizeof(DrawApplicationPrivate));
}

static void
draw_application_init (DrawApplication *self)
{
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self,
                                            DRAW_TYPE_APPLICATION,
                                            DrawApplicationPrivate);
}

DrawApplication*
draw_application_new (void)
{
  return g_object_new (draw_application_get_type (),
                       "application-id", "org.gnome.draw",
                       "flags", 0,
                       NULL);
}
