/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 8 -*-  */
/*
 * draw-application.h
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

#ifndef _DRAW_APPLICATION_
#define _DRAW_APPLICATION_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define DRAW_TYPE_APPLICATION             (draw_application_get_type ())
#define DRAW_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), DRAW_TYPE_APPLICATION, Draw))
#define DRAW_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), DRAW_TYPE_APPLICATION, DrawClass))
#define DRAW_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DRAW_TYPE_APPLICATION))
#define DRAW_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), DRAW_TYPE_APPLICATION))
#define DRAW_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), DRAW_TYPE_APPLICATION, DrawClass))

typedef struct _DrawApplicationClass       DrawApplicationClass;
typedef struct _DrawApplication            DrawApplication;

struct _DrawApplicationClass
{
  GtkApplicationClass parent_class;
};

struct _DrawApplication
{
  GtkApplication parent_instance;
};

GType              draw_application_get_type (void) G_GNUC_CONST;
DrawApplication   *draw_application_new      (void);

G_END_DECLS

#endif /* _DRAW_APPLICATION_ */
