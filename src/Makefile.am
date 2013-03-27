AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(MAINTAINER_COMPILER_FLAGS) \
	$(DRAW_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = draw

draw_SOURCES = \
	main.c \
	draw-application.h \
	draw-application.c

draw_LDFLAGS = \
	-Wl,--export-dynamic

draw_LDADD = $(DRAW_LIBS)
