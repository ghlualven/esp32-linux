/*
 * Copyright (C) 2015-2020 Espressif Systems (Shanghai) PTE LTD
 *
 * This software file (the "File") is distributed by Espressif Systems (Shanghai)
 * PTE LTD under the terms of the GNU General Public License Version 2, June 1991
 * (the "License").  You may use, redistribute and/or modify this File in
 * accordance with the terms and conditions of the License, a copy of which
 * is available by writing to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA or on the
 * worldwide web at http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt.
 *
 * THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE
 * ARE EXPRESSLY DISCLAIMED.  The License provides additional details about
 * this warranty disclaimer.
 */
#ifndef _ESP_SPI_H_
#define _ESP_SPI_H_

#include "esp.h"

#define SPI_BUF_SIZE		2048

struct esp_spi_context {
	struct esp_adapter 	*adapter;
	struct spi_device 	*esp_spi_dev;
	struct sk_buff_head 	tx_q;
	struct sk_buff_head 	rx_q;
	struct workqueue_struct *spi_workqueue;
	struct work_struct	spi_work;
	struct gpio_desc	*reset_gpio;
};

enum {
	CLOSE_DATAPATH,
	OPEN_DATAPATH,
};

#endif
