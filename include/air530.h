/**
 * @brief
 */

#ifndef AIR530_H
#define AIR530_H

#include "board.h"
#include "periph/uart.h"
#include "ztimer.h"
#include "tsrb.h"

// Memory size
#define BUFF_SIZE 128
#define CMD_SIZE 128

// NMEA commands
#define NMEA_GLL 0x01
#define NMEA_RMC 0x02
#define NMEA_VTG 0X04
#define NMEA_GGA 0X08
#define NMEA_GSA 0X10
#define NMEA_GSV 0x20
#define NMEA_GRS 0X40
#define NMEA_GST 0x80

typedef enum {
    MODE_GPS = 0,
    MODE_GPS_BEIDOU,
    MODE_GPS_GLONASS,
    MODE_GPS_GALILEO,
    MODE_GPS_MULTI
}GPS_MODE;

static char     cmd[CMD_SIZE];
static uint8_t  last;
static uint8_t  buffer[BUFF_SIZE];
static tsrb_t   _tsrb = TSRB_INIT(buffer);
static uart_t   _uart;

void init_air530(uart_t dev, uint32_t bauds);
uint8_t checksum(char *str);

#endif // AIR530_H
