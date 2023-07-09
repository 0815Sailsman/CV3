/*
     ____ __     ____   ___    ____ __         (((((()
    | |_  \ \  /   ) ) | |  ) | |_  \ \  /  \(@)- /
    |_|__  \_\/  __)_) |_|_/  |_|__  \_\/   /(@)- \
                                               ((())))
 *//**
 *  \file  sensor.c
 *  \brief  ev3dev-c Sensors example.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_sensor.h"
#include "ev3_tacho.h"

// WIN32 /////////////////////////////////////////
#ifdef __WIN32__

#include <windows.h>

// UNIX //////////////////////////////////////////
#else

#include <unistd.h>
#define Sleep( msec ) usleep(( msec ) * 1000 )

//////////////////////////////////////////////////
#endif

const char const *color[] = { "?", "BLACK", "BLUE", "GREEN", "YELLOW", "RED", "WHITE", "BROWN" };
#define COLOR_COUNT  (( int )( sizeof( color ) / sizeof( color[ 0 ])))

char s[ 256 ];
int val;
uint32_t n, i, ii;
uint8_t sn;
int scount = 0;
FLAGS_T state;
char s[256];
int tempbuf;
int mcount = 0;

void scan_sensors() {
	printf("Scanning sensors...\n");
	scount = ev3_sensor_init();
	printf("sensor count: %d\n", scount);
	printf( "Found sensors:\n" );
	for ( i = 0; i < DESC_LIMIT; i++ ) {
		if ( ev3_sensor[ i ].type_inx != SENSOR_TYPE__NONE_ ) {
			printf( "  type = %s\n", ev3_sensor_type( ev3_sensor[ i ].type_inx ));
			printf( "  port = %s\n", ev3_sensor_port_name( i, s ));
			if ( get_sensor_mode( i, s, sizeof( s ))) {
				printf( "  mode = %s\n", s );
			}
			if ( get_sensor_num_values( i, &n )) {
				for ( ii = 0; ii < n; ii++ ) {
					if ( get_sensor_value( ii, i, &val )) {
						printf( "  value%d = %d\n", ii, val );
					}
				}
			}
		}
	}
	printf("\n");
}

void scan_motors() {
	printf("Scanning motors...\n");
		mcount = ev3_tacho_init();
		printf( "Found %d tacho motors:\n", mcount);
		for ( i = 0; i < DESC_LIMIT; i++ ) {
			if ( ev3_tacho[ i ].type_inx != TACHO_TYPE__NONE_ ) {
				printf( "  type = %s\n", ev3_tacho_type( ev3_tacho[ i ].type_inx ));
				get_tacho_speed(i, &tempbuf);
				printf( " Speed = %d\n", tempbuf);
				get_tacho_position(i, &tempbuf);
				printf( " Position = %d\n", tempbuf);
				get_tacho_duty_cycle(i, &tempbuf);
				printf( " Duty Cycle (auslastung) = %d\n", tempbuf);
				printf( " Polarity / Direction = %s\n", ev3_tacho_polarity(ev3_tacho[ i ].type_inx));
				printf( " State flags = %zx\n", get_tacho_state_flags(i, s));
				printf( "  port = %s\n", ev3_tacho_port_name( i, s ));
			}
		}
		printf("\n");
}

int main( void ) {
	srand(time(NULL));	

	printf( "Waiting the EV3 brick online...\n" );
	if ( ev3_init() < 1 ) return ( 1 );

	printf( "*** ( EV3 ) Hello! ***\n" );
	while (true) {
		scan_sensors();
		scan_motors();
		sleep(1);
	}
	ev3_uninit();
	printf( "\n*** ( EV3 ) Bye! ***\n" );

	return ( 0 );
}
