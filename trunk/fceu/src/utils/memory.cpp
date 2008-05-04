/* FCE Ultra - NES/Famicom Emulator
 *
 * Copyright notice for this file:
 *  Copyright (C) 2002 Xodnizel
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/// \file
/// \brief memory management services provided by FCEU core

#include <stdlib.h>
#include "../types.h"
#include "../fceu.h"
#include "memory.h"

///allocates the specified number of bytes. exits process if this fails
void *FCEU_gmalloc(uint32 size)
{
 void *ret;
 ret=malloc(size);
 if(!ret)  
 {
  FCEU_PrintError("Error allocating memory!  Doing a hard exit.");
  exit(1);
 }
 return ret;
}

///allocates the specified number of bytes. returns null if this fails
void *FCEU_malloc(uint32 size)
{
 void *ret;
 ret=malloc(size);
 if(!ret)
 {
  FCEU_PrintError("Error allocating memory!");
  return(0);
 }
 return ret;
}

///frees memory allocated with FCEU_gmalloc
void FCEU_gfree(void *ptr)
{
 free(ptr);
}

///frees memory allocated with FCEU_malloc
void FCEU_free(void *ptr)    // Might do something with this and FCEU_malloc later...
{
 free(ptr);
}
