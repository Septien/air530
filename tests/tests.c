#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "tests.h"
#include "cUnit.h"
#include "air530.h"

struct data {
    uint8_t *data;
};

void setup(void *arg) {
    (void) arg;
}

void teardown(void *arg) {
    (void) arg;
}

bool test_checksum(void *arg)
{
    (void) arg;
    memset(cmd, 0, BUFF_SIZE);

    strncpy(cmd, "$PGKC051,1\0", 11);
    uint8_t cs = checksum(cmd);
    bool passed = cs == 0x36;

    return passed;
}

void tests(void)
{
    printf("Testing Air530 module.\n");

    cUnit_t *tests;
    struct data data;

    cunit_init(&tests, &setup, &teardown, (void *)&data);

    cunit_add_test(tests, &test_checksum, "test_checksum");

    cunit_execute_tests(tests);

    cunit_terminate(&tests);

    //init_air530((uart_t)1, 9600);

    return;
}
