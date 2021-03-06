/*
Spassus2 is a free game (and powerfull engine) for Casio calculators
Copyright (C) 2016 Hugo KUENY

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef _MAINMENUBITMAP_H_
#define _MAINMENUBITMAP_H_

unsigned char mainMenuBackgroundBitmap[1024];
const unsigned char mainMenuTexture[]={
	0x4, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x40, 0x8,
	0x2, 0x1, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x20, 0x10,
	0x1, 0x2, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x10, 0x20,
	0x0, 0xfc, 0x8, 0xff, 0x8f, 0xe0, 0x70, 0x1f, 0xf1, 0xff, 0x8, 0x10, 0xff, 0x88, 0xf, 0xc0,
	0x1, 0x2, 0x8, 0x80, 0x8, 0x20, 0xd8, 0x10, 0x1, 0x0, 0x8, 0x10, 0x80, 0x8, 0x10, 0x20,
	0x2, 0x1, 0x8, 0x80, 0x8, 0x20, 0xa8, 0x10, 0x1, 0x0, 0x8, 0x10, 0x80, 0x8, 0x20, 0x10,
	0x4, 0x0, 0x88, 0x80, 0x8, 0x20, 0xa8, 0x10, 0x1, 0x0, 0x8, 0x10, 0x80, 0x8, 0x40, 0x8,
	0xf8, 0x0, 0x78, 0x80, 0xf, 0xe0, 0xa8, 0x10, 0x1, 0x0, 0x8, 0x10, 0x80, 0xf, 0x80, 0x7,
	0x4, 0x0, 0x88, 0xff, 0x88, 0x0, 0xf8, 0x1f, 0xf1, 0xff, 0x8, 0x10, 0xff, 0x88, 0x40, 0x8,
	0x2, 0x1, 0x8, 0x0, 0x88, 0x1, 0xfc, 0x0, 0x10, 0x1, 0x8, 0x10, 0x0, 0x88, 0x20, 0x10,
	0x1, 0x2, 0x8, 0x0, 0x88, 0x1, 0xfc, 0x0, 0x10, 0x1, 0x8, 0x10, 0x0, 0x88, 0x10, 0x20,
	0x0, 0xfc, 0x8, 0x0, 0x88, 0x3, 0xfe, 0x0, 0x10, 0x1, 0x8, 0x10, 0x0, 0x88, 0xf, 0xc0,
	0x1, 0x2, 0x8, 0xff, 0x88, 0x3, 0xfe, 0x1f, 0xf1, 0xff, 0xf, 0xf0, 0xff, 0x88, 0x10, 0x20,
	0x2, 0x1, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x20, 0x10,
	0x4, 0x0, 0x88, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x40, 0x8,
	0xf8, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x7,
	0x4, 0x0, 0x81, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x40, 0x8,
	0x2, 0x1, 0x1, 0x0, 0x41, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x20, 0x10,
	0x1, 0x2, 0x2, 0x0, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x10, 0x20,
	0x0, 0xfc, 0x4, 0x0, 0x51, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0xf, 0xc0,
	0x1, 0x2, 0x8, 0x0, 0x51, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x10, 0x20,
	0x2, 0x1, 0x10, 0x0, 0x51, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x20, 0x10,
	0x4, 0x0, 0xa0, 0x0, 0x51, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x40, 0x8,
	0xf8, 0x0, 0x40, 0x0, 0x49, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x80, 0x7,
	0x4, 0x0, 0x80, 0x0, 0x49, 0x3c, 0xf3, 0xcf, 0x9f, 0x1e, 0x49, 0x0, 0x0, 0x0, 0xc0, 0x8,
	0x2, 0x1, 0x0, 0x0, 0x49, 0x20, 0x82, 0x8, 0x84, 0x12, 0x9, 0x0, 0x0, 0x0, 0x60, 0x10,
	0x1, 0x2, 0x0, 0x0, 0x49, 0x20, 0x82, 0x8, 0x84, 0x12, 0x4d, 0x0, 0x0, 0x0, 0x30, 0x20,
	0x0, 0xfc, 0x0, 0x0, 0x49, 0x20, 0x82, 0x8, 0x84, 0x1e, 0x4d, 0x0, 0x0, 0x0, 0x1f, 0xc0,
	0x1, 0x8, 0x0, 0x0, 0x45, 0x3c, 0xf3, 0xc8, 0x84, 0x18, 0x4d, 0x0, 0x0, 0x0, 0x8, 0x20,
	0x2, 0x10, 0x0, 0x0, 0x45, 0x20, 0x10, 0x48, 0x84, 0x14, 0x4b, 0x0, 0x0, 0x0, 0x4, 0x10,
	0x4, 0x20, 0x0, 0x0, 0x45, 0x20, 0x10, 0x48, 0x84, 0x14, 0x4b, 0x0, 0x0, 0x0, 0x2, 0x8,
	0xf8, 0x40, 0x0, 0x0, 0x43, 0x20, 0x10, 0x48, 0x84, 0x14, 0x4b, 0x0, 0x0, 0x0, 0x1, 0x7,
	0x4, 0x80, 0x0, 0x0, 0x41, 0x3c, 0xf3, 0xcf, 0x84, 0x12, 0x49, 0x0, 0x0, 0x0, 0x0, 0x88,
	0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50,
	0x2, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20,
	0x4, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10,
	0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,
	0x10, 0x0, 0xfa, 0x1e, 0x8b, 0xdf, 0x78, 0x1e, 0xf7, 0xaf, 0x80, 0x5f, 0x3d, 0x17, 0x80, 0x4,
	0x20, 0x0, 0x8a, 0x12, 0xca, 0x4, 0x40, 0x10, 0x94, 0x8, 0x80, 0xd1, 0x25, 0x94, 0x0, 0x2,
	0xf0, 0x0, 0x8a, 0x12, 0xca, 0x4, 0x40, 0x10, 0x94, 0x28, 0x81, 0x51, 0x25, 0x94, 0x0, 0x1,
	0x8, 0x0, 0xfa, 0x1e, 0xca, 0x4, 0x40, 0x10, 0xf4, 0x28, 0x80, 0x51, 0x25, 0x94, 0x0, 0x2,
	0x4, 0x0, 0x82, 0x12, 0xab, 0xc4, 0x78, 0x10, 0x97, 0xa8, 0x80, 0x51, 0x3d, 0x57, 0x80, 0x4,
	0x2, 0x0, 0x82, 0x12, 0x9a, 0x4, 0x40, 0x10, 0x90, 0xa8, 0x80, 0x51, 0x25, 0x30, 0x80, 0x8,
	0x1, 0x0, 0x82, 0x12, 0x9a, 0x4, 0x40, 0x10, 0x90, 0xa8, 0x80, 0x51, 0x25, 0x30, 0x80, 0x10,
	0x1, 0x80, 0x82, 0x12, 0x9a, 0x4, 0x40, 0x10, 0x90, 0xa8, 0x80, 0x51, 0x25, 0x30, 0x80, 0x20,
	0x2, 0x40, 0x83, 0xd2, 0x8b, 0xc4, 0x78, 0x1e, 0x97, 0xaf, 0x80, 0x5f, 0x25, 0x17, 0x80, 0x50,
	0x4, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x88,
	0xf8, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x7,
	0x4, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x8,
	0x2, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x10,
	0x1, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x20,
	0x0, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x3f, 0x84, 0x80, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xc0,
	0x1, 0x2, 0x80, 0x0, 0x0, 0x0, 0x2, 0x20, 0x8c, 0x80, 0x0, 0x0, 0x0, 0x0, 0x30, 0x20,
	0x2, 0x1, 0x40, 0x0, 0x0, 0x0, 0x2, 0x20, 0x94, 0x80, 0x0, 0x0, 0x0, 0x0, 0x60, 0x10,
	0x4, 0x0, 0xa0, 0x0, 0x0, 0x0, 0x2, 0x20, 0xa4, 0x80, 0x0, 0x0, 0x0, 0x0, 0xc0, 0x8,
	0xf8, 0x0, 0x70, 0x0, 0x0, 0x0, 0x2, 0x20, 0x84, 0x90, 0x0, 0x0, 0x0, 0x1, 0x80, 0x7,
	0x4, 0x0, 0x88, 0x0, 0x0, 0x0, 0x7e, 0x20, 0x84, 0x90, 0x0, 0x0, 0x0, 0x2, 0x40, 0x8,
	0x2, 0x1, 0x4, 0x0, 0x0, 0x0, 0x40, 0x20, 0x84, 0xfc, 0x0, 0x0, 0x0, 0x4, 0x20, 0x10,
	0x1, 0x2, 0x2, 0x0, 0x0, 0x0, 0x40, 0x20, 0x84, 0x10, 0x0, 0x0, 0x0, 0x8, 0x10, 0x20,
	0x0, 0xfc, 0x1, 0x0, 0x0, 0x0, 0x40, 0x20, 0x84, 0x10, 0x0, 0x0, 0x0, 0x10, 0xf, 0xc0,
	0x1, 0x2, 0x0, 0x80, 0x0, 0x0, 0x40, 0x20, 0x84, 0x10, 0x0, 0x0, 0x0, 0x20, 0x10, 0x20,
	0x2, 0x1, 0x0, 0xc0, 0x0, 0x0, 0x7e, 0x3f, 0x84, 0x10, 0x0, 0x0, 0x0, 0x40, 0x20, 0x10,
	0x4, 0x0, 0x81, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa0, 0x40, 0x8,
	0xf8, 0x0, 0x7e, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1f, 0x80, 0x7,
};
#endif