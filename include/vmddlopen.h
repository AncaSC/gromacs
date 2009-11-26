/* -*- mode: c; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; c-file-style: "stroustrup"; -*-
 *
 * 
 * This file is part of Gromacs        Copyright (c) 1991-2008
 * David van der Spoel, Erik Lindahl, Berk Hess, University of Groningen.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out http://www.gromacs.org
 * 
 * And Hey:
 * Gnomes, ROck Monsters And Chili Sauce
 */

/***************************************************************************
 *cr
 *cr            (C) Copyright 1995-2009 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *      $RCSfile: vmddlopen.h,v $
 *      $Author: johns $        $Locker:  $             $State: Exp $
 *      $Revision: 1.9 $      $Date: 2009/07/07 02:40:05 $
 *
 ***************************************************************************
 * DESCRIPTION:
 *   Routines for loading dynamic link libraries and shared object files
 *   on various platforms, abstracting from machine dependent APIs.
 *
 * LICENSE:
 *   UIUC Open Source License 
 *   http://www.ks.uiuc.edu/Research/vmd/plugins/pluginlicense.html
 *
 ***************************************************************************/

/*
 * vmddlopen: thin multi-platform wrapper around dlopen/LoadLibrary
 */

#ifndef VMD_DLOPEN__

#ifdef __cplusplus
extern "C" {
#endif

/* Try to open the specified library.  All symbols must be resolved or the 
 * load will fail (RTLD_NOW).  
 */
void *vmddlopen(const char *fname);

/* Try to load the specified symbol using the given handle.  Returns NULL if 
 * the symbol cannot be loaded.
 */
void *vmddlsym(void *h, const char *sym);

/* Unload the library.  Return 0 on success, nonzero on error. 
 */
int vmddlclose(void *h);

/* Return last error from any of the above functions.  Not thread-safe on
 * Windows due to static buffer in our code. 
 */ 
const char *vmddlerror(void);

#ifdef __cplusplus
}
#endif

#endif

