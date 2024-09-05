#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "test.h"
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
    cUnit_t *cUnit;
    struct data *_data;

    cunit_init(&cUnit, setup, teardown, (void *)_data);

    return;
}
