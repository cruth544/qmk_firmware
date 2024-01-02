// Copyright 2023 JoyLee (@itarze)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* RGB Config */
#define AW20216S_CS_PIN_1 B6
#define AW20216S_EN_PIN_1 B7
#define RGB_MATRIX_LED_COUNT 67

/* SPI Config */
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4

/* SPI Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12

/* RGB Matrix */
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
