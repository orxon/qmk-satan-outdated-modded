#include "satan.h"
extern uint32_t layer_state;
extern struct cRGB led[16];

__attribute__ ((weak))
void * matrix_init_user(void) {
	// Leave Blank
};

__attribute__ ((weak))
void * matrix_scan_user(void) {
	
	uint8_t layer = biton32(layer_state);

    switch (layer) {
        case 1:
			led[15].r = 255;
			led[15].g = 0;
			led[15].b = 0;
			ws2812_setleds(led, 16);
            break;
        case 2:
			led[15].r = 0;
			led[15].g = 255;
			led[15].b = 0;
			ws2812_setleds(led, 16);
            break;
        case 3:
			led[15].r = 0;
			led[15].g = 0;
			led[15].b = 255;
			ws2812_setleds(led, 16);
            break;
        default:
			led[15].r = 0;
			led[15].g = 0;
			led[15].b = 0;
			ws2812_setleds(led, 16);
            break;
    }

	
	
};

void * matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	#ifdef BACKLIGHT_ENABLE
    	backlight_init_ports();
	#endif

	#ifdef RGBLIGHT_ENABLE
	    rgblight_init();
	#endif



	if (matrix_init_user) {
		(*matrix_init_user)();
	}
};

void * matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	if (matrix_scan_user) {
		(*matrix_scan_user)();
	}
};
