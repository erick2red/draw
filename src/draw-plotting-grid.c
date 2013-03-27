/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 8 -*-  */
/*
 * draw-plotting-grid.c
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

#include "draw-plotting-grid.h"

struct _DrawPlottingGridPrivate
{
  int nr_objects;
};

G_DEFINE_TYPE (DrawPlottingGrid, draw_plotting_grid, GTK_TYPE_WIDGET);

static void
draw_plotting_grid_class_init (DrawPlottingGridClass *klass)
{
  g_type_class_add_private ((gpointer) klass, sizeof(DrawPlottingGridPrivate));
}

static void
draw_plotting_grid_init (DrawPlottingGrid *self)
{
  self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self,
					    DRAW_TYPE_PLOTTING_GRID,
					    DrawPlottingGridPrivate);
}

GtkWidget*
draw_plotting_grid_new ()
{
  return g_object_new (draw_plotting_grid_get_type (), NULL);
}
