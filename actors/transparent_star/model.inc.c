/********************************************************************************
	gex.h: Ultra 64 MARIO Brothers include file

	Copyright (C) 1995-1997 Nintendo Co., LTD.  All rights reserved.

	Sept 25, 1995
 ********************************************************************************/
#define	GEX_H


/********************************************************************************/
/*	gsDPLoadTextureBlock() without gsDPSetTextureImage()						*/
/********************************************************************************/

#define	gsxDPLoadTextureImage(fmt, siz, width, height,		\
		pal, cms, cmt, masks, maskt, shifts, shiftt)		\
									\
	gsDPSetTile(fmt, siz, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt,	\
		shiftt, cms, masks, shifts),				\
	gsDPLoadSync(),							\
	gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (width)*(height)-1,		\
				 	CALC_DXT(width, siz##_BYTES)),					\
	gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), 0,	\
		G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks,	\
		shifts),						\
	gsDPSetTileSize(G_TX_RENDERTILE, 0, 0,				\
		((width)-1) << G_TEXTURE_IMAGE_FRAC,			\
		((height)-1) << G_TEXTURE_IMAGE_FRAC)


/********************************************************************************/
/*	Static display-list to load texture image made by Tanimoto.					*/
/********************************************************************************/

#define	g_Tani_LoadTextureImage(gfxptr, timg, fmt, siz, width, height,	tmem, ttdn)		\
																						\
	gDPSetTextureImage(gfxptr, fmt, siz, 1, timg);										\
	gDPTileSync(gfxptr);																\
	gDPSetTile(gfxptr, fmt, siz, 0, tmem, ttdn, 0,  0,0,0, 0,0,0);						\
	gDPLoadSync(gfxptr);																\
	gDPLoadBlock(gfxptr, ttdn, 0, 0, ((width)*(height)-1),								\
				  CALC_DXT(width, siz##_BYTES) )


#define	gs_Tani_LoadTextureImage(timg, fmt, siz, width, height,	tmem, ttdn)			\
																					\
	gsDPSetTextureImage(fmt, siz, 1, timg),											\
	gsDPTileSync(),																	\
	gsDPSetTile(fmt, siz, 0, tmem, ttdn, 0,  0,0,0, 0,0,0),							\
	gsDPLoadSync(),																	\
	gsDPLoadBlock(ttdn, 0, 0, ((width)*(height)-1),									\
				  CALC_DXT(width, siz##_BYTES) )

/********************************************************************************/
/*	Static display-list to load texture image Ver.2 made by Tanimoto.			*/
/********************************************************************************/

#define	g_Tani_LoadTextureImage2(gfxptr, timg, fmt, siz, width, height,	tmem, ttdn)		\
																						\
	gDPSetTextureImage(gfxptr, fmt, siz, 1, timg);										\
	gDPLoadSync(gfxptr);																\
	gDPLoadBlock(gfxptr, ttdn, 0, 0, ((width)*(height)-1),								\
				  CALC_DXT(width, siz##_BYTES) )


#define	gs_Tani_LoadTextureImage2(timg, fmt, siz, width, height, tmem, ttdn)		\
																					\
	gsDPSetTextureImage(fmt, siz, 1, timg),											\
	gsDPLoadSync(),																	\
	gsDPLoadBlock(ttdn, 0, 0, ((width)*(height)-1),									\
				  CALC_DXT(width, siz##_BYTES) )


/********************************************************************************/
/*	Static display-list to set up Texture Tile Descriptor made by Tanimoto.		*/
/********************************************************************************/

#define	g_Tani_SetUpTileDescrip(gfxptr, fmt, siz, width, height, tmem, ttdn, 		\
							 cms, masks, shifts, cmt, maskt, shiftt)				\
																					\
	gDPTileSync(gfxptr);															\
	gDPSetTile(gfxptr, fmt, siz, ((((width)*siz##_LINE_BYTES)+7)>>3), tmem,			\
				ttdn, 0, (cmt), (maskt), (shiftt), (cms), (masks), (shifts));		\
	gDPSetTileSize(gfxptr, ttdn, 0, 0,												\
					(((width) -1) << G_TEXTURE_IMAGE_FRAC),							\
					(((height)-1) << G_TEXTURE_IMAGE_FRAC) )


#define	gs_Tani_SetUpTileDescrip(fmt, siz, width, height, tmem, ttdn, 				\
							 	 cms, masks, shifts, cmt, maskt, shiftt)			\
																					\
	gsDPTileSync(),																	\
	gsDPSetTile(fmt, siz, ((((width)*siz##_LINE_BYTES)+7)>>3), tmem,				\
				ttdn, 0, (cmt), (maskt), (shiftt), (cms), (masks), (shifts)),		\
	gsDPSetTileSize(ttdn, 0, 0,														\
					(((width) -1) << G_TEXTURE_IMAGE_FRAC),							\
					(((height)-1) << G_TEXTURE_IMAGE_FRAC) )


/********************************************************************************
	RCP_HmsItemStar [ New New Version ]
														[ Nob 19, 1995 ]
 ********************************************************************************/

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"

#define		STAR_POLYGON_R		255
#define		STAR_POLYGON_G		255
#define		STAR_POLYGON_B		 46
#define		STAR_POLYGON_A		255


/********************************************************************************/
/*	Vertex data [common].														*/
/********************************************************************************/
static Vtx vtx_dotstar[] = {
	{ -64, -64, 0,  0,	   0<<5, 31<<5,		STAR_POLYGON_R, STAR_POLYGON_G, STAR_POLYGON_B, STAR_POLYGON_A 	},
	{  64, -64, 0,  0,	  31<<5, 31<<5,		STAR_POLYGON_R, STAR_POLYGON_G, STAR_POLYGON_B, STAR_POLYGON_A	},
	{  64,  64, 0,  0,	  31<<5,  0<<5,		STAR_POLYGON_R, STAR_POLYGON_G, STAR_POLYGON_B, STAR_POLYGON_A	},
	{ -64,  64, 0,  0,	   0<<5,  0<<5,		STAR_POLYGON_R, STAR_POLYGON_G, STAR_POLYGON_B, STAR_POLYGON_A	},
};

/********************************************************************************/
/*	Texture data of star coin.													*/
/********************************************************************************/
// 0x050055E0
ALIGNED8 static const u8 dotstar_txt[] = {
#include "actors/transparent_star/dotstar_txt.rgba16.inc.c"
};
/********************************************************************************/
/*	Graphic display list of star coin.											*/
/********************************************************************************/
extern Gfx gfx_dotstar[] = {
	gsSPClearGeometryMode(G_CULL_BACK),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
	gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0xffff, 0xffff, 0, G_TX_RENDERTILE, G_ON),

	gs_Tani_LoadTextureImage2(dotstar_txt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, 7),

    gsxDPLoadTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
			 G_TX_CLAMP | G_TX_NOMIRROR, G_TX_CLAMP | G_TX_NOMIRROR,
			 5, 5, G_TX_NOLOD, G_TX_NOLOD),

	gsSPVertex(&vtx_dotstar[0], 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),

    gsSPTexture(0xffff, 0xffff, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTextureFilter(G_TF_BILERP),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList()
};

// 0x0302C488
static const Lights1 transparent_star_seg3_lights_0302C488 = gdSPDefLights1(
    0x03, 0x05, 0x17,
    0x1e, 0x32, 0xe6, 0x28, 0x28, 0x28
);

// 0x0302C4A0
static const Vtx transparent_star_seg3_vertex_0302C4A0[] = {
    {{{     0,      8,    -89}, 0, {     0,      0}, {0x00, 0x07, 0x82, 0xff}}},
    {{{   190,   -201,      0}, 0, {     0,      0}, {0x55, 0xa3, 0x00, 0xff}}},
    {{{     0,   -129,      0}, 0, {     0,      0}, {0x00, 0x82, 0x00, 0xff}}},
    {{{   146,    -42,      0}, 0, {     0,      0}, {0x7c, 0xe7, 0x00, 0xff}}},
    {{{     0,      8,     90}, 0, {     0,      0}, {0x00, 0x07, 0x7e, 0xff}}},
    {{{   257,     84,      0}, 0, {     0,      0}, {0x68, 0x47, 0x00, 0xff}}},
    {{{  -145,    -42,      0}, 0, {     0,      0}, {0x84, 0xe7, 0x00, 0xff}}},
    {{{  -189,   -201,      0}, 0, {     0,      0}, {0xaa, 0xa3, 0x00, 0xff}}},
    {{{  -256,     84,      0}, 0, {     0,      0}, {0x97, 0x47, 0x00, 0xff}}},
    {{{     0,    246,      0}, 0, {     0,      0}, {0x00, 0x7e, 0x00, 0xff}}},
    {{{    96,     99,      0}, 0, {     0,      0}, {0x3d, 0x6f, 0x00, 0xff}}},
    {{{   -95,     99,      0}, 0, {     0,      0}, {0xc3, 0x6f, 0x00, 0xff}}},
};

// 0x0302C560 - 0x0302C620
const Gfx transparent_star_seg3_dl_0302C560[] = {
    gsSPLight(&transparent_star_seg3_lights_0302C488.l, 1),
    gsSPLight(&transparent_star_seg3_lights_0302C488.a, 2),
    gsSPVertex(transparent_star_seg3_vertex_0302C4A0, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 2,  1,  4, 0x0,  1,  3,  4, 0x0),
    gsSP2Triangles( 5,  3,  0, 0x0,  4,  3,  5, 0x0),
    gsSP2Triangles( 6,  7,  4, 0x0,  7,  2,  4, 0x0),
    gsSP2Triangles( 8,  6,  4, 0x0,  9,  4, 10, 0x0),
    gsSP2Triangles( 9, 11,  4, 0x0,  4,  5, 10, 0x0),
    gsSP2Triangles(11,  8,  4, 0x0,  0,  2,  7, 0x0),
    gsSP2Triangles( 0,  7,  6, 0x0,  0,  6,  8, 0x0),
    gsSP2Triangles( 0,  8, 11, 0x0,  0, 11,  9, 0x0),
    gsSP2Triangles(10,  5,  0, 0x0, 10,  0,  9, 0x0),
    gsSPEndDisplayList(),
};

// 0x0302C620 - 0x0302C658
const Gfx transparent_star_seg3_dl_0302C620[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADEFADEA, G_CC_SHADEFADEA),
    gsDPSetEnvColor(255, 255, 255, 120),
    gsSPDisplayList(transparent_star_seg3_dl_0302C560),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};
