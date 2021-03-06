/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"

#define LED_PIN 25

int main() {
	stdio_init_all();
	char buffer[1024];

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	while(1)
	{
		scanf("%1024s", buffer);
		printf("%s\n", buffer);
		if (strcmp(buffer, "ON") == 0)
		{
			gpio_put(LED_PIN, 1);
		} else if (strcmp(buffer, "OFF") == 0)
		{
			gpio_put(LED_PIN, 0);
		} else if (strcmp(buffer, "REBOOT") == 0)
		{
			reset_usb_boot(0,0);
		}
	}	

}
