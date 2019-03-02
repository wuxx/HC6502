/***************************************************************************
 * STM32 VGA demo
 * Copyright (C) 2012 Artekit Italy
 * http://www.artekit.eu
 * Written by Ruben H. Meleca
 
### gdi.h
 
#   This program is free software; you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program; if not, write to the Free Software
#   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

***************************************************************************/

#ifndef	__GDI_H
#define	__GDI_H

#include "gdptypes.h"

//	System font

#define	GDI_SYSFONT_WIDTH		6		// Width in pixels
#define	GDI_SYSFONT_HEIGHT		9		// Height in pixels
#define	GDI_SYSFONT_BYTEWIDTH	1		// Width in bytes
#define	GDI_SYSFONT_OFFSET		0x20

//	RASTER OPERATION

#define	GDI_ROP_COPY			0
#define	GDI_ROP_XOR				1
#define	GDI_ROP_AND				2
#define	GDI_ROP_OR				3

typedef __packed  struct
{
	i16		x;							// X position
	i16		y;							// Y position
	i16		w;							// Width
	i16		h;							// Height

} GDI_RECT, *PGDI_RECT;

#define	GDI_WINCAPTION			0x0001
#define	GDI_WINBORDER			0x0002
#define	GDI_WINCLOSEICON		0x0003

//	Text align mode

#define	GDI_WINCAPTION_LEFT		0x0000
#define	GDI_WINCAPTION_CENTER	0x0010
#define	GDI_WINCAPTION_RIGHT	0x0020
#define	GDI_WINCAPTION_MASK		0x0030

typedef __packed struct
{
	u16				style;				// Mode, see GDI_WINxxx defines
	GDI_RECT		rc;					// Absolute rectangle
	pu8				caption;			// Caption text

} GDI_WINDOW, *PGDI_WINDOW;

typedef __packed struct
{
	i16		w;							// Width in bits
	i16		h;							// Height in bits
	i16		wb;							// width in bytes
	i16		wh;							// Height in bytes
	pu8		*bm;						// Pointer to bitmap bits

} GDI_BITMAP, PGDI_BITMAP;

//	Function definitions

void	gdiGetClientRect(PGDI_WINDOW, PGDI_RECT);
void	gdiCopyRect(PGDI_RECT rc1, PGDI_RECT rc2);
void	gdiBitBlt(PGDI_RECT prc, i16 x, i16 y, i16 w, i16 h, pu8 bm, u16 rop);
void	gdiPoint(PGDI_RECT rc, u16 x, u16 y, u16 rop);
void	gdiLine(PGDI_RECT prc, i16 x0, i16 y0, i16 x1, i16 y1, u16 rop);
void	gdiRectangle(i16 x0, i16 y0, i16 x1, i16 y1, u16 rop);
void	gdiRectangleEx(PGDI_RECT rc, u16 rop);
void	gdiCircle(u16 x, u16 y, u16 r, u16 rop);
void	gdiDrawWindow(PGDI_WINDOW pwin);
void	gdiDrawTextEx(i16 x, i16 y, pu8 ptext, u16 rop);

#endif	// __GDI_H
