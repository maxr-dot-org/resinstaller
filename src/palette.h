/***************************************************************************
 *              Resinstaller - installs missing GFX for MAXR               *
 *              This file is part of the resinstaller project              *
 *   Copyright (C) 2007, 2008 Eiko Oltmanns                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef paletteH
#define paletteH

/* 	
spezial meanings of colors in the palette:

Playercolors:  32,33,34,35,36,37,38,39

Effektcolors:  11,14,21,22,	...

most likely, all colors < 64 have a special meaning

*/

unsigned char orig_palette[] =
	{0, 0, 0, 255, 0, 0, 0, 255, 0, 0, 0, 255, 255, 255, 0, 255, 171, 0, 131, 131, 163, 255, 71, 0, 255, 255, 147, 203, 203, 255, 171, 171, 227, 99, 91, 223, 171, 171, 227, 255, 255, 159, 243, 171, 103, 235, 51, 51, 243, 171, 103, 23, 99, 135, 43, 63, 75, 15, 15, 15, 43, 63, 75, 183, 103, 0, 75, 59, 39, 15, 15, 15, 75, 59, 39, 15, 15, 15, 27, 27, 27, 43, 43, 43, 55, 55, 55, 71, 67, 67, 87, 83, 83, 0, 0, 0, 131, 187, 27, 111, 171, 15, 95, 159, 11, 79, 147, 7, 67, 119, 7, 51, 95, 7, 39, 67, 7, 27, 43, 7, 187, 187, 7, 179, 135, 7, 171, 87, 7, 163, 47, 7, 255, 255, 255, 103, 7, 123, 123, 55, 7, 147, 187, 15, 107, 159, 187, 71, 135, 171, 47, 115, 151, 23, 99, 135, 15, 79, 111, 11, 59, 87, 7, 43, 67, 7, 27, 43, 187, 123, 87, 175, 99, 55, 163, 79, 27, 151, 59, 7, 123, 47, 7, 99, 39, 7, 71, 27, 7, 39, 15, 7, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 215, 7, 255, 255, 251, 247, 243, 223, 211, 243, 219, 187, 223, 199, 175, 223, 195, 155, 219, 183, 143, 199, 167, 127, 183, 163, 131, 171, 155, 123, 159, 151, 139, 175, 167, 147, 191, 171, 151, 199, 187, 175, 207, 163, 107, 191, 155, 103, 171, 139, 95, 163, 139, 107, 155, 135, 99, 147, 135, 115, 131, 127, 119, 123, 115, 103, 131, 115, 91, 139, 123, 99, 147, 119, 83, 159, 127, 75, 171, 131, 75, 179, 139, 83, 195, 147, 83, 199, 139, 67, 179, 127, 59, 167, 115, 55, 147, 111, 59, 131, 107, 59, 123, 99, 71, 115, 99, 59, 115, 87, 43, 103, 83, 47, 91, 79, 59, 83, 71, 51, 83, 63, 43, 75, 59, 39, 67, 59, 43, 59, 51, 39, 51, 43, 31, 43, 39, 35, 39, 35, 31, 31, 27, 23, 15, 15, 15, 55, 31, 31, 47, 43, 43, 55, 51, 51, 63, 59, 59, 75, 71, 71, 87, 83, 83, 95, 91, 91, 103, 99, 99, 111, 107, 107, 115, 103, 83, 107, 95, 75, 99, 87, 67, 87, 67, 35, 75, 43, 43, 47, 43, 59, 131, 99, 43, 131, 107, 75, 207, 131, 107, 171, 111, 91, 187, 83, 55, 123, 79, 67, 155, 63, 47, 115, 39, 35, 75, 31, 23, 31, 15, 15, 139, 171, 99, 115, 147, 79, 87, 147, 59, 95, 115, 67, 67, 107, 47, 59, 83, 35, 43, 67, 27, 23, 27, 15, 119, 111, 159, 99, 87, 131, 59, 67, 139, 67, 67, 107, 47, 51, 107, 67, 59, 79, 31, 35, 75, 15, 19, 43, 183, 103, 0, 135, 75, 0, 91, 51, 0, 155, 155, 0, 111, 111, 0, 67, 67, 0, 255, 255, 255};

#endif //paletteH
