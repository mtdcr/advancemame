/*
 * This file is part of the Advance project.
 *
 * Copyright (C) 2003 Andrea Mazzoleni
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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * In addition, as a special exception, Andrea Mazzoleni
 * gives permission to link the code of this program with
 * the MAME library (or with modified versions of MAME that use the
 * same license as MAME), and distribute linked combinations including
 * the two.  You must obey the GNU General Public License in all
 * respects for all of the code used other than MAME.  If you modify
 * this file, you may extend this exception to your version of the
 * file, but you are not obligated to do so.  If you do not wish to
 * do so, delete this exception statement from your version.
 */

#ifndef __LQ3X_H
#define __LQ3X_H

#include <assert.h>

#include "interp.h"

/***************************************************************************/
/* LQ3x C implementation */

/*
 * This effect is derived from the lq3x effect made by Maxim Stepin
 */

static void lq3x_16_def(interp_uint16* dst0, interp_uint16* dst1, interp_uint16* dst2, const interp_uint16* src0, const interp_uint16* src1, const interp_uint16* src2, unsigned count)
{
	unsigned i;

	for(i=0;i<count;++i) {
		unsigned char mask;

		interp_uint16 c[9];

		c[1] = src0[0];
		c[4] = src1[0];
		c[7] = src2[0];

		if (i>0) {
			c[0] = src0[-1];
			c[3] = src1[-1];
			c[6] = src2[-1];
		} else {
			c[0] = c[1];
			c[3] = c[4];
			c[6] = c[7];
		}

		if (i<count-1) {
			c[2] = src0[1];
			c[5] = src1[1];
			c[8] = src2[1];
		} else {
			c[2] = c[1];
			c[5] = c[4];
			c[8] = c[7];
		}

		mask = 0;

		if (c[0] != c[4])
			mask |= 1 << 0;
		if (c[1] != c[4])
			mask |= 1 << 1;
		if (c[2] != c[4])
			mask |= 1 << 2;
		if (c[3] != c[4])
			mask |= 1 << 3;
		if (c[5] != c[4])
			mask |= 1 << 4;
		if (c[6] != c[4])
			mask |= 1 << 5;
		if (c[7] != c[4])
			mask |= 1 << 6;
		if (c[8] != c[4])
			mask |= 1 << 7;

#define P0 dst0[0]
#define P1 dst0[1]
#define P2 dst0[2]
#define P3 dst1[0]
#define P4 dst1[1]
#define P5 dst1[2]
#define P6 dst2[0]
#define P7 dst2[1]
#define P8 dst2[2]
#define MUR (c[1] != c[5])
#define MDR (c[5] != c[7])
#define MDL (c[7] != c[3])
#define MUL (c[3] != c[1])
#define IC(p0) c[p0]
#define I211(p0,p1,p2) interp_16_211(c[p0], c[p1], c[p2])
#define I31(p0,p1) interp_16_31(c[p0], c[p1])
#define I772(p0,p1,p2) interp_16_772(c[p0], c[p1], c[p2])
#define I71(p0,p1) interp_16_71(c[p0], c[p1])
#define I11(p0,p1) interp_16_11(c[p0], c[p1])

		switch (mask) {
		#include "hq3x.dat"
		}

#undef P0
#undef P1
#undef P2
#undef P3
#undef P4
#undef P5
#undef P6
#undef P7
#undef P8
#undef MUR
#undef MDR
#undef MDL
#undef MUL
#undef IC
#undef I211
#undef I31
#undef I772
#undef I71
#undef I11

		src0 += 1;
		src1 += 1;
		src2 += 1;
		dst0 += 3;
		dst1 += 3;
		dst2 += 3;
	}
}

static void lq3x_32_def(interp_uint32* dst0, interp_uint32* dst1, interp_uint32* dst2, const interp_uint32* src0, const interp_uint32* src1, const interp_uint32* src2, unsigned count)
{
	unsigned i;

	for(i=0;i<count;++i) {
		unsigned char mask;

		interp_uint32 c[9];

		c[1] = src0[0];
		c[4] = src1[0];
		c[7] = src2[0];

		if (i>0) {
			c[0] = src0[-1];
			c[3] = src1[-1];
			c[6] = src2[-1];
		} else {
			c[0] = c[1];
			c[3] = c[4];
			c[6] = c[7];
		}

		if (i<count-1) {
			c[2] = src0[1];
			c[5] = src1[1];
			c[8] = src2[1];
		} else {
			c[2] = c[1];
			c[5] = c[4];
			c[8] = c[7];
		}

		mask = 0;

		if (c[0] != c[4])
			mask |= 1 << 0;
		if (c[1] != c[4])
			mask |= 1 << 1;
		if (c[2] != c[4])
			mask |= 1 << 2;
		if (c[3] != c[4])
			mask |= 1 << 3;
		if (c[5] != c[4])
			mask |= 1 << 4;
		if (c[6] != c[4])
			mask |= 1 << 5;
		if (c[7] != c[4])
			mask |= 1 << 6;
		if (c[8] != c[4])
			mask |= 1 << 7;

#define P0 dst0[0]
#define P1 dst0[1]
#define P2 dst0[2]
#define P3 dst1[0]
#define P4 dst1[1]
#define P5 dst1[2]
#define P6 dst2[0]
#define P7 dst2[1]
#define P8 dst2[2]
#define MUR (c[1] != c[5])
#define MDR (c[5] != c[7])
#define MDL (c[7] != c[3])
#define MUL (c[3] != c[1])
#define IC(p0) c[p0]
#define I211(p0,p1,p2) interp_32_211(c[p0], c[p1], c[p2])
#define I31(p0,p1) interp_32_31(c[p0], c[p1])
#define I772(p0,p1,p2) interp_32_772(c[p0], c[p1], c[p2])
#define I71(p0,p1) interp_32_71(c[p0], c[p1])
#define I11(p0,p1) interp_32_11(c[p0], c[p1])

		switch (mask) {
		#include "hq3x.dat"
		}

#undef P0
#undef P1
#undef P2
#undef P3
#undef P4
#undef P5
#undef P6
#undef P7
#undef P8
#undef MUR
#undef MDR
#undef MDL
#undef MUL
#undef IC
#undef I211
#undef I31
#undef I772
#undef I71
#undef I11

		src0 += 1;
		src1 += 1;
		src2 += 1;
		dst0 += 3;
		dst1 += 3;
		dst2 += 3;
	}
}

#endif
