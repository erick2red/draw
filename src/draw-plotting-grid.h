/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 8 -*-  */
/*
 * draw-plotting-grid.h
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

#ifndef _DRAW_PLOTTING_GRID_
#define _DRAW_PLOTTING_GRID_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define DRAW_TYPE_PLOTTING_GRID             (draw_plotting_grid_get_type ())
#define DRAW_PLOTTING_GRID(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), DRAW_TYPE_PLOTTING_GRID, Draw))
#define DRAW_PLOTTING_GRID_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DRAW_TYPE_PLOTTING_GRID, DrawClass))
#define DRAW_IS_PLOTTING_GRID(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DRAW_TYPE_PLOTTING_GRID))
#define DRAW_IS_PLOTTING_GRID_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DRAW_TYPE_PLOTTING_GRID))
#define DRAW_PLOTTING_GRID_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DRAW_TYPE_PLOTTING_GRID, DrawPlottingGridClass))

typedef struct _DrawPlottingGridClass        DrawPlottingGridClass;
typedef struct _DrawPlottingGrid             DrawPlottingGrid;
typedef struct _DrawPlottingGridPrivate      DrawPlottingGridPrivate;

struct _DrawPlottingGridClass
{
  GtkWidgetClass parent_class;
};

struct _DrawPlottingGrid
{
  GtkWidget parent_instance;

  DrawPlottingGridPrivate *priv;
};

GType               draw_plotting_grid_get_type (void) G_GNUC_CONST;
GtkWidget          *draw_plotting_grid_new      (void);

G_END_DECLS

#endif /* _DRAW_PLOTTING_GRID_ */
