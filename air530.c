#include <string.h>

#include "air530.h"

static void uart_cb(void *arg, uint8_t data)
{
    (void) arg;
    printf("%c", (char)data);
}

void init_air530(uart_t dev, uint32_t bauds)
{
    /* Clear memory for command variable. */
    memset(cmd, 0, BUFF_SIZE);

    /* Init the ring buffer for uart usage */
    tsrb_clear(&_tsrb);

    /* Init the uart interface */
    _uart = dev;
    uart_init(UART_DEV(_uart), bauds, uart_cb, (void *)(uintptr_t)dev);
    /* Last position of cmd variable */
    last = 0;

    /* Create cold start command and send */
    strncpy(cmd, "$PGKC030,4,1*29\r\n\0", 18);
    last += 17;

    uart_write(UART_DEV(_uart), (uint8_t *)cmd, 17);

    strncpy(cmd, "$PGKC051,1*36\r\n\0", 16);
    uart_write(UART_DEV(_uart), (uint8_t *)cmd, 15);
}

uint8_t checksum(char *str)
{
    uint8_t sum = (uint8_t)str[1];
    int i = 2;
    while (str[i] != '\0') {
        sum ^= (uint8_t)str[i];
        i++;
    }

    return sum;
}
