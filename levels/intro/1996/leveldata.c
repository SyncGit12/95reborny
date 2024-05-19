#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"

#include "make_const_nonconst.h"

// #include "levels/intro/mario_logo66/model.inc.c"

// 0x0700B420 - 0x0700B460
static const Vtx intro_seg7_vertex_0700B420[] = {
    {{{    96,     42,     -1}, 0, {     0,    512}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   224,     42,     -1}, 0, {  4096,    512}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   224,     58,     -1}, 0, {  4096,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{    96,     58,     -1}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
};

// 0x0700B460 - 0x0700B4A0
static const Vtx intro_seg7_vertex_0700B460[] = {
    {{{   268,    180,     -1}, 0, {     0,    512}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   284,    180,     -1}, 0, {   544,    512}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   284,    196,     -1}, 0, {   544,      0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{   268,    196,     -1}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}},
};

#ifdef VERSION_EU
// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const u8 intro_seg7_texture_0700B4A0[] = {
#include "levels/intro/2_eu_copyright.rgba16.inc.c"
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 intro_seg7_texture_0700C4A0[] = {
#include "levels/intro/3_eu_tm.rgba16.inc.c"
};

#else
// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const u8 intro_seg7_texture_0700B4A0[] = {
#include "levels/intro/2_copyright.rgba16.inc.c"
};

// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const u8 intro_seg7_texture_0700C4A0[] = {
#include "levels/intro/3_tm.rgba16.inc.c"
};
#endif

// 0x0700C6A0 - 0x0700C790
const Gfx intro_seg7_dl_0700C6A0[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),

    gsDPLoadTextureBlock(intro_seg7_texture_0700B4A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 7, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(intro_seg7_vertex_0700B420, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),

    //gsDPLoadTextureBlock(intro_seg7_texture_0700C4A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    //gsSPVertex(intro_seg7_vertex_0700B460, 4, 0),
    //gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),

    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};

// 0x0700C790
const f32 intro_seg7_table_0700C790[] = {
    0.000000f, 0.000000f, 0.080000f, 0.012800f,
    0.012800f, 0.012800f, 0.048600f, 0.048600,
    0.048600f, 0.104000f, 0.184000f, 0.104000f,
    0.175400f, 0.175400f, 0.175400f, 0.259300f,
    0.259300f, 0.259300f, 0.352000f, 0.352000,
    0.352000f, 0.450100f, 0.450100f, 0.450100f,
    0.549000f, 0.549900f, 0.549900f, 0.648000,
    0.648000f, 0.648000f, 0.740700f, 0.740700,
    0.740700f, 0.824600f, 0.824600f, 0.824600,
    0.896000f, 0.896000f, 0.896000f, 0.951400f,
    0.951400f, 0.951400f, 0.987300f, 0.987300f,
    0.987300f, 1.000000f, 1.080000f, 1.000000f,
};


// 0x0700C880
const f32 intro_seg7_table_0700C880[] = {
    1.000000f, 1.000000f, 1.000000f, 0.987300f,
    0.987300f, 0.987300f, 0.951400f, 0.951400f,
    0.951400f, 0.896000f, 0.896000f, 0.896000f,
    0.824600f, 0.824600f, 0.824600f, 0.740700f,
    0.740700f, 0.740700f, 0.648000f, 0.648000f,
    0.648000f, 0.549900f, 0.549900f, 0.549900f,
    0.450100f, 0.450100f, 0.450100f, 0.352000f,
    0.352000f, 0.352000f, 0.259300f, 0.259300f,
    0.259300f, 0.175400f, 0.175400f, 0.175400f,
    0.104000f, 0.104000f, 0.104000f, 0.048600f,
    0.048600f, 0.048600f, 0.012800f, 0.012800f,
    0.012800f, 0.000000f, 0.000000f, 0.000000f,
};

// #include "levels/intro/mario65_logo/model.inc.c"
#include "levels/intro/ninten/model.inc.c"