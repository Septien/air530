APPLICATION = gps_air530

BOARD ?= native

RIOTBASE ?= ../../RTOS/RIOT
DEVHELP ?= 1
DEVELHELP ?= 1

INCLUDES += -I$(CURDIR)/include

ifdef TEST
	CFLAGS += -DTESTS
	INCLUDES += -I$(CURDIR)/tests/include
	USEMODULE += tests
	EXTERNAL_MODULE_DIRS += $(CURDIR)
endif

FEATURE_REQUIRED += periph_uart

USEMODULE += tsrb
USEMODULE += ztimer
USEMODULE += ztimer_msec
ifneq ($(BOARD), native)
	USEMODULE += stdio_uart
	USEMODULE += printf_float
endif

CFLAGS += -Wno-error=unused-variable

include $(RIOTBASE)/Makefile.include
