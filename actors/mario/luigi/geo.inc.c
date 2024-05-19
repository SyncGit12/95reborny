// Normal mario Geo

#include "src/game/envfx_snow.h"

// 0x170002E0
const GeoLayout mario_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, mario_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x1700041C
const GeoLayout mario_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000494
const GeoLayout mario_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_cap),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_cap_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// The body loads all the parts with some shared dls to apply the solid color of the dl that has it, the same rule applies to the medium and low poly geos

// 0x1700053C
const GeoLayout mario_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_butt), // starts sharing solid color with mario_torso (blue)
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_geo_face_and_wings), // stops sharing because faces has its own dl
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm), // starts sharing solid color with mario_left_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_left_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, -65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm), // starts sharing solid color of his dl with mario_right_forearm (red)
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_geo_right_hand), // stops sharing because hand has its solid color (white)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot), // stops sharing because foot has its solid color (brown)
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh), // starts sharing solid color of his dl with mario_left_leg (blue)
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 89, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_right_foot), // stops sharing because foot has its solid color (brown)
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Vanish Mario Geo

// 0x17000DEC
const GeoLayout mario_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
         GEO_SWITCH_CASE(0, geo_switch_mario_eyes),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_front),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_half_closed),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_closed),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_right), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_left), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_up), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_down), // unused
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_on_eyes_dead),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000F28
const GeoLayout mario_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 66, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_left_hand_closed),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_open),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_closed),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_closed),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17000FA0
const GeoLayout mario_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 66, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_right_hand_peace), // here we go hand
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_right_hand_cap),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_right_hand_cap),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_right_hand_cap_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rule body as Normal mario

// 0x17001048
const GeoLayout mario_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_butt),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 33, 0, 0, mario_torso),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_vanish_geo_face_and_wings),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_left_arm),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_vanish_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 63, -10, -65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_right_arm),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_vanish_geo_right_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, -34, -9, 40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_left_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 89, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 81, 0, 0, mario_left_foot),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_right_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 89, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Metal mario Geo

// 0x170018F8
const GeoLayout mario_metal_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_metal_cap_on_shared_dl),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_metal_cap_on_shared_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, mario_metal_cap_wings), // left
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_ALPHA, mario_metal_cap_wings), // right
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x170019A4
const GeoLayout mario_metal_geo_left_hand[] = {
   GEO_SWITCH_CASE(1, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 66, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_left_hand_closed_shared_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_open_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_left_hand_closed_shared_dl),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17001A1C
const GeoLayout mario_metal_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 66, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_metal_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_metal_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_right_hand_peace_shared_dl), // here we go hand
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_metal_right_hand_cap_shared_dl),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 60, 0, 0, mario_metal_right_hand_cap_shared_dl),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_metal_right_hand_cap_shared_dl_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// A difference from Normal mario is that the dls after the butt and left thigh shares the metal texture of it, same rule applies to the medium and low poly geos

// 0x17001AC4
const GeoLayout mario_metal_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 261-189, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_metal_butt), // starts sharing metal texture with the dls below
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 33, 0, 0, mario_metal_torso_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 91, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_metal_geo_face_and_wings), // unlike normal mario geo, these dls still share the metal texture
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, 65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_left_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_metal_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 63, -10, -65, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_OPAQUE, 65, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_metal_geo_right_hand), // stop sharing because the wing metal cap of it
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, 40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_metal_left_thigh), // starts sharing metal texture with the dls below
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, mario_left_foot_shared_dl),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_OPAQUE, -34, -9, -40, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, mario_right_thigh_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_OPAQUE, 98, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_OPAQUE, 81, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_OPAQUE, mario_metal_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Metal Vanish Mario Geo

// 0x170022E4
const GeoLayout mario_metal_vanish_geo_face_and_wings[] = {
   GEO_ASM(0, geo_mario_head_rotation),
   GEO_ROTATION_NODE(0x00, 0, 0, 0),
   GEO_OPEN_NODE(),
      GEO_SWITCH_CASE(0, geo_switch_mario_cap_on_off),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_metal_cap_on_shared_dl),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_metal_cap_on_shared_dl),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, -126, 22, -40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_metal_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_TRANSLATE_ROTATE(0, 142, -51, 126, -22, 40, -135),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_rotate_wing_cap_wings),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_metal_cap_wings_transparent),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002390
const GeoLayout mario_metal_vanish_geo_left_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(1, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_left_hand_closed_shared_dl),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_open_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_closed_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_left_hand_closed_shared_dl),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002408
const GeoLayout mario_metal_vanish_geo_right_hand[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_hand),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, NULL),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mario_hand_foot_scaler),
         GEO_SCALE(0x00, 65536),
         GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_metal_right_hand_closed),
         GEO_CLOSE_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_metal_right_hand_open),
      GEO_OPEN_NODE(),
         GEO_HELD_OBJECT(0x00, 0, 0, 0, geo_switch_mario_hand_grab_pos),
      GEO_CLOSE_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_right_hand_peace_shared_dl), // here we go hand
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_metal_right_hand_cap_shared_dl),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 60, 0, 0, mario_metal_right_hand_cap_shared_dl),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_ALPHA, mario_metal_right_hand_cap_shared_dl_wings),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// Same rules as Metal mario

// 0x170024B0
const GeoLayout mario_metal_vanish_geo_body[] = {
   GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, NULL),
   GEO_OPEN_NODE(),
      GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_metal_butt),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_move_mario_part_from_parent),
         GEO_ROTATION_NODE(0x00, 0, 0, 0),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 68, 0, 0, mario_metal_torso_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 87, 0, 0, NULL),
               GEO_OPEN_NODE(),
                  GEO_BRANCH(1, mario_metal_vanish_geo_face_and_wings),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 67, -10, 79, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_left_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, mario_left_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_metal_vanish_geo_left_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 68, -10, -79, NULL),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_right_arm_shared_dl),
                  GEO_OPEN_NODE(),
                     GEO_ANIMATED_PART(LAYER_TRANSPARENT, 65, 0, 0, mario_right_forearm_shared_dl),
                     GEO_OPEN_NODE(),
                        GEO_BRANCH(1, mario_metal_vanish_geo_right_hand),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, 13, -8, 42, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_metal_left_thigh),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 89, 0, 0, mario_left_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 67, 0, 0, mario_left_foot_shared_dl),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
         GEO_ANIMATED_PART(LAYER_TRANSPARENT, 13, -8, -42, NULL),
         GEO_OPEN_NODE(),
            GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, mario_right_thigh_shared_dl),
            GEO_OPEN_NODE(),
               GEO_ANIMATED_PART(LAYER_TRANSPARENT, 89, 0, 0, mario_right_leg_shared_dl),
               GEO_OPEN_NODE(),
                  GEO_ANIMATED_PART(LAYER_TRANSPARENT, 67, 0, 0, NULL),
                  GEO_OPEN_NODE(),
                     GEO_ASM(2, geo_mario_hand_foot_scaler),
                     GEO_SCALE(0x00, 65536),
                     GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, mario_metal_right_foot),
                     GEO_CLOSE_NODE(),
                  GEO_CLOSE_NODE(),
               GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
         GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// High Poly

// 0x17002CE0
const GeoLayout mario_geo_load_body[] = {
   GEO_SWITCH_CASE(0, geo_switch_mario_cap_effect),
   GEO_OPEN_NODE(),
      GEO_BRANCH(1, mario_geo_body),
      GEO_BRANCH(1, mario_vanish_geo_body),
      GEO_BRANCH(1, mario_metal_geo_body),
      GEO_BRANCH(1, mario_metal_vanish_geo_body),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// 0x17002D7C
const GeoLayout mario_geo_render_body[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
         GEO_BRANCH(1, mario_geo_load_body),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_RETURN(),
};

// This last geo is used to load all of mario Geo in the Level Scripts

// 0x17002DD4
const GeoLayout mario_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_PLAYER, 0xB4, 100),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_ASM(0, geo_mirror_mario_backface_culling),
         GEO_ASM(0, geo_mirror_mario_set_alpha),
         GEO_SWITCH_CASE(0, geo_switch_mario_stand_run),
         GEO_OPEN_NODE(),
            GEO_BRANCH(1, mario_geo_load_body),
            GEO_BRANCH(1, mario_geo_render_body),
         GEO_CLOSE_NODE(),
         GEO_ASM(1, geo_mirror_mario_backface_culling),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};

