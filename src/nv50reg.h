/*
 * Copyright 2007 Maarten Maathuis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef __NV50REG_H_
#define __NV50REG_H_

/* This is a grey area. */
#define NV50_DISPLAY_SUPERVISOR	0x00610024
	#define NV50_DISPLAY_SUPERVISOR_DISABLE_CRTC0	(1 << 2)
	#define NV50_DISPLAY_SUPERVISOR_DISABLE_CRTC1	(1 << 3)
	#define NV50_DISPLAY_SUPERVISOR_CLK_MASK		(7 << 4)
	#define NV50_DISPLAY_SUPERVISOR_CLK_UPDATE		(2 << 4)

#define NV50_DISPLAY_UNK30_CTRL	0x00610030
	#define NV50_DISPLAY_UNK30_CTRL_UPDATE_VCLK0	(1 << 9)
	#define NV50_DISPLAY_UNK30_CTRL_UPDATE_VCLK1	(1 << 10)
	#define NV50_DISPLAY_UNK30_CTRL_PENDING			(1 << 31)

#define NV50_DISPLAY_CTRL_STATE		0x00610300
	#define NV50_DISPLAY_CTRL_STATE_DISABLE		(0 << 0)
	#define NV50_DISPLAY_CTRL_STATE_ENABLE		(1 << 0)
	#define NV50_DISPLAY_CTRL_STATE_PENDING		(1 << 31)
#define NV50_DISPLAY_CTRL_VAL		0x00610304

/* Clamped to 256 MiB */
#define NV50_CRTC0_RAM_AMOUNT		0x00610384
#define NV50_CRTC1_RAM_AMOUNT		0x00610784

/* These are probably redrirected from 0x4000 range (very similar regs to nv40, maybe different order) */
#define NV50_CRTC_VPLL1_A		0x00614104
#define NV50_CRTC_VPLL1_B		0x00614108
#define NV50_CRTC_VPLL2_A		0x00614904
#define NV50_CRTC_VPLL2_B		0x00614908

#define NV50_DAC0_DPMS_CTRL	0x0061A004
#define NV50_DAC1_DPMS_CTRL	0x0061A804
#define NV50_DAC2_DPMS_CTRL	0x0061B004
	#define	NV50_DAC_DPMS_CTRL_HSYNC_OFF		(1 << 0)
	#define	NV50_DAC_DPMS_CTRL_VSYNC_OFF		(1 << 2)
	#define	NV50_DAC_DPMS_CTRL_BLANK			(1 << 4)
	#define	NV50_DAC_DPMS_CTRL_OFF			(1 << 6)
	#define	NV50_DAC_DPMS_CTRL_PENDING		(1 << 31)

#define NV50_SOR0_DPMS_CTRL	0x0061C004
#define NV50_SOR1_DPMS_CTRL	0x0061C804
	#define	NV50_SOR_DPMS_CTRL_MODE_ON	(1 << 0)
	#define	NV50_SOR_DPMS_CTRL_PENDING	(1 << 31)

/* These things below are so called "commands" */
#define NV50_UPDATE_DISPLAY		0x80

#define NV50_DAC0_MODE_CTRL		0x400
	#define NV50_DAC_MODE_CTRL_OFF			(0 << 0)
	#define NV50_DAC_MODE_CTRL_CRTC0			(1 << 0)
	#define NV50_DAC_MODE_CTRL_CRTC1			(1 << 1)
#define NV50_DAC1_MODE_CTRL		0x480
#define NV50_DAC2_MODE_CTRL		0x500

#define NV50_DAC0_MODE_CTRL2		0x404
	#define NV50_DAC_MODE_CTRL2_NHSYNC			(1 << 0)
	#define NV50_DAC_MODE_CTRL2_NVSYNC			(2 << 0)
#define NV50_DAC1_MODE_CTRL2		0x484
#define NV50_DAC2_MODE_CTRL2		0x504

#define NV50_SOR0_MODE_CTRL		0x600
	#define NV50_SOR_MODE_CTRL_OFF			(0 << 0)
	#define NV50_SOR_MODE_CTRL_CRTC0			(1 << 0)
	#define NV50_SOR_MODE_CTRL_CRTC1			(1 << 1)
	#define NV50_SOR_MODE_CTRL_LVDS			(0 << 8)
	#define NV50_SOR_MODE_CTRL_TMDS			(1 << 8)
	#define NV50_SOR_MODE_CTRL_TMDS_DUAL_LINK	(4 << 8)
	#define NV50_SOR_MODE_CTRL_NHSYNC			(1 << 12)
	#define NV50_SOR_MODE_CTRL_NVSYNC			(2 << 12)
#define NV50_SOR1_MODE_CTRL		0x640

#define NV50_CRTC0_CLOCK			0x804
#define NV50_CRTC0_INTERLACE		0x808

#define NV50_CRTC0_HBLANK_START	0x814
#define NV50_CRTC0_HSYNC_END		0x818
#define NV50_CRTC0_HBLANK_END		0x81C
#define NV50_CRTC0_HTOTAL			0x820

/* You can't have a palette in 8 bit mode (=OFF) */
#define NV50_CRTC0_CLUT_MODE		0x840
	#define NV50_CRTC0_CLUT_MODE_BLANK		0x00000000
	#define NV50_CRTC0_CLUT_MODE_OFF		0x80000000
	#define NV50_CRTC0_CLUT_MODE_ON		0xC0000000
#define NV50_CRTC0_CLUT_OFFSET		0x844

/* Anyone know what part of the chip is triggered here precisely? */
#define NV84_CRTC0_BLANK_UNK1		0x85C
	#define NV84_CRTC0_BLANK_UNK1_BLANK	0x0
	#define NV84_CRTC0_BLANK_UNK1_UNBLANK	0x1

#define NV50_CRTC0_FB_OFFSET		0x860

#define NV50_CRTC0_FB_SIZE			0x868
#define NV50_CRTC0_PITCH			0x86C

#define NV50_CRTC0_DEPTH			0x870
	#define NV50_CRTC0_DEPTH_8BPP		0x1E00
	#define NV50_CRTC0_DEPTH_15BPP	0xE900
	#define NV50_CRTC0_DEPTH_16BPP	0xE800
	#define NV50_CRTC0_DEPTH_24BPP	0xCF00

/* I'm openminded to better interpretations. */
/* This is an educated guess. */
/* NV50 has RAMDAC and TMDS offchip, so it's unlikely to be that. */
#define NV50_CRTC0_BLANK_CTRL		0x874
	#define NV50_CRTC0_BLANK_CTRL_BLANK	0x0
	#define NV50_CRTC0_BLANK_CTRL_UNBLANK	0x1

#define NV50_CRTC0_CURSOR		0x880
	#define NV50_CRTC0_CURSOR_SHOW		0x85000000
	#define NV50_CRTC0_CURSOR_HIDE		0x05000000

#define NV50_CRTC0_CURSOR_OFFSET	0x884

/* Anyone know what part of the chip is triggered here precisely? */
#define NV84_CRTC0_BLANK_UNK2		0x89C
	#define NV84_CRTC0_BLANK_UNK2_BLANK	0x0
	#define NV84_CRTC0_BLANK_UNK2_UNBLANK	0x1

#define NV50_CRTC0_DITHERING_CTRL	0x8A0
	#define NV50_CRTC0_DITHERING_CTRL_ON	0x11
	#define NV50_CRTC0_DITHERING_CTRL_OFF	0x0

#define NV50_CRTC0_FB_POS			0x8C0
#define NV50_CRTC0_SCRN_SIZE		0x8C8

#define NV50_CRTC1_CLOCK			0xC04
#define NV50_CRTC1_INTERLACE		0xC08

#define NV50_CRTC1_HBLANK_START	0xC14
#define NV50_CRTC1_HSYNC_END		0xC18
#define NV50_CRTC1_HBLANK_END		0xC1C
#define NV50_CRTC1_HTOTAL			0xC20

#define NV50_CRTC1_CLUT_MODE		0xC40
	#define NV50_CRTC1_CLUT_MODE_BLANK		0x00000000
	#define NV50_CRTC1_CLUT_MODE_OFF		0x80000000
	#define NV50_CRTC1_CLUT_MODE_ON		0xC0000000
#define NV50_CRTC1_CLUT_OFFSET		0xC44

/* Anyone know what part of the chip is triggered here precisely? */
#define NV84_CRTC1_BLANK_UNK1		0xC5C
	#define NV84_CRTC1_BLANK_UNK1_BLANK	0x0
	#define NV84_CRTC1_BLANK_UNK1_UNBLANK	0x1

#define NV50_CRTC1_FB_OFFSET		0xC60

#define NV50_CRTC1_FB_SIZE			0xC68
#define NV50_CRTC1_PITCH			0xC6C

#define NV50_CRTC1_DEPTH			0xC70
	#define NV50_CRTC1_DEPTH_8BPP		0x1E00
	#define NV50_CRTC1_DEPTH_15BPP	0xE900
	#define NV50_CRTC1_DEPTH_16BPP	0xE800
	#define NV50_CRTC1_DEPTH_24BPP	0xCF00

/* I'm openminded to better interpretations. */
#define NV50_CRTC1_BLANK_CTRL		0xC74
	#define NV50_CRTC1_BLANK_CTRL_BLANK	0x0
	#define NV50_CRTC1_BLANK_CTRL_UNBLANK	0x1

#define NV50_CRTC1_CURSOR		0xC80
	#define NV50_CRTC1_CURSOR_SHOW		0x85000000
	#define NV50_CRTC1_CURSOR_HIDE		0x05000000

#define NV50_CRTC1_CURSOR_OFFSET	0xC84

/* Anyone know what part of the chip is triggered here precisely? */
#define NV84_CRTC1_BLANK_UNK2		0xC9C
	#define NV84_CRTC1_BLANK_UNK2_BLANK	0x0
	#define NV84_CRTC1_BLANK_UNK2_UNBLANK	0x1

#define NV50_CRTC1_DITHERING_CTRL	0xCA0
	#define NV50_CRTC1_DITHERING_CTRL_ON	0x11
	#define NV50_CRTC1_DITHERING_CTRL_OFF	0x0

#define NV50_CRTC1_FB_POS			0xCC0
#define NV50_CRTC1_SCRN_SIZE		0xCC8

/* misc stuff */
#define NV50_I2C_START		0x7
#define NV50_I2C_STOP		0x3

#endif /* __NV50REG_H_ */
