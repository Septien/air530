#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "tests.h"
#include "cUnit.h"

struct data {
    uint8_t *data;
};

void setup(void *arg) {
    (void) arg;
}

void teardown(void *arg) {
    (void) arg;
}

void tests(void)
{
    printf("Testing Air530 module.\n");

    return;
}
