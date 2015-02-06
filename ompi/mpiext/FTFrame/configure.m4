# -*- shell-script -*-
#
# Copyright (c) 2004-2009 The Trustees of Indiana University.
#                         All rights reserved.
# Copyright (c) 2012 Cisco Systems, Inc.  All rights reserved.
# $COPYRIGHT$
# 
# Additional copyrights may follow
# 
# $HEADER$
#

# OMPI_MPIEXT_example_CONFIG([action-if-found], [action-if-not-found])
# -----------------------------------------------------------
AC_DEFUN([OMPI_MPIEXT_FTFrame_CONFIG],[
    AC_CONFIG_FILES([ompi/mpiext/FTFrame/Makefile])

    AC_CONFIG_FILES([ompi/mpiext/FTFrame/c/Makefile])


    # This example can always build, so we just execute $1.
    $1
])

# only need to set this if the component needs init/finalize hooks
AC_DEFUN([OMPI_MPIEXT_FTFrame_NEED_INIT], [1])
