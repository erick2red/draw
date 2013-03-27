dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(draw, 0.0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CC

dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=draw
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [GETTEXT package name])

AM_GLIB_GNU_GETTEXT

LT_INIT

GNOME_COMPILE_WARNINGS(maximum)
GNOME_MAINTAINER_MODE_DEFINES

MAINTAINER_COMPILER_FLAGS="$MAINTAINER_COMPILER_FLAGS                        \
                           -Wall -Wcast-align -Wuninitialized                \
                           -Wno-strict-aliasing -Wempty-body -Wformat        \
                           -Wformat-security -Wformat-nonliteral -Winit-self \
      	                   -Wdeclaration-after-statement -Wvla               \
                           -Wpointer-arith -Wmissing-declarations            \
                           -Wcast-align                                      \
                           -Wredundant-decls"

# strip leading spaces                                                                                                        
MAINTAINER_COMPILER_FLAGS=${MAINTAINER_COMPILER_FLAGS#*  }
AC_SUBST(MAINTAINER_COMPILER_FLAGS)

PKG_CHECK_MODULES(DRAW, [gtk+-3.0 >= 2.90.3 gtk+-3.0])

AC_OUTPUT([
Makefile
src/Makefile
po/Makefile.in
])
