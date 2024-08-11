/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* serial.c configuration (for split keyboard). */
#define SOFT_SERIAL_PIN GP0
//#define SERIAL_USART_TX_PIN GP0


/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { GP2, GP3, GP4, GP5, GP6, GP7 }
#define MATRIX_COL_PINS { GP21, GP23, GP20, GP22, GP26, GP27, GP28 }
//#define MATRIX_COL_PINS_RIGHT { GP21, GP23, GP20, GP22, GP26, GP27, GP28 }
#define MATRIX_COL_PINS_RIGHT { GP28, GP27, GP26, GP22, GP20, GP23, GP21 }
#define DIODE_DIRECTION COL2ROW
#define MASTER_RIGHT

// WS2812 RGB LED strip input and number of LEDs
//#define RGB_DI_PIN D3
//#define RGBLED_NUM 12
