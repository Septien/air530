APPLICATION = ts_ring

BOARD ?= native

RIOTBASE ?= ../RIOT
DEVHELP ?= 1
DEVELHELP ?= 1

INCLUDES += -I$(CURDIR)/include

FEATURE_REQUIRED += periph_uart

USEMODULE += tsrb
USEMODULE += ztimer
USEMODULE += ztimer_msec

include $(RIOTBASE)/Makefile.include
