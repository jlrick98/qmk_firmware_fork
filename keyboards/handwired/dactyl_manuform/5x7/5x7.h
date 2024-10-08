#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT_5x7( \
    L00, L01, L02, L03, L04, L05, L06, \
    L10, L11, L12, L13, L14, L15, L16, \
    L20, L21, L22, L23, L24, L25, L26, \
    L30, L31, L32, L33, L34, L35, \
    L40, L41, L42, L43, \
						L44, L45, \
                                  L53, L55, \
                                  L54, L56, \
         R00, R01, R02, R03, R04, R05, R06, \
         R10, R11, R12, R13, R14, R15, R16, \
         R20, R21, R22, R23, R24, R25, R26, \
              R31, R32, R33, R34, R35, R36, \
                        R43, R44, R45, R46, \
              R41, R42, \
    R51, R53, \
    R50, R52 \
) { \
    { L00, L01, L02, L03, L04, L05, L06 }, \
    { L10, L11, L12, L13, L14, L15, L16 }, \
    { L20, L21, L22, L23, L24, L25, L26 }, \
    { L30, L31, L32, L33, L34, L35, XXX }, \
    { L40, L41, L42, L43, L44, L45, XXX }, \
    { XXX, XXX, XXX, L53, L54, L55, L56 }, \
    { R00, R01, R02, R03, R04, R05, R06 }, \
    { R10, R11, R12, R13, R14, R15, R16 }, \
    { R20, R21, R22, R23, R24, R25, R26 }, \
    { XXX, R31, R32, R33, R34, R35, R36 }, \
    { XXX, R41, R42, R43, R44, R45, R46 }, \
    { R50, R51, R52, R53, XXX, XXX, XXX } \
}
