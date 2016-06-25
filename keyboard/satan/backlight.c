#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <avr/pgmspace.h>

#include "backlight.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

#ifdef BACKLIGHT_ENABLE
#define CHANNEL OCR1B

void backlight_init_ports()
{

    DDRB |= (1<<6);
    PORTB &= ~(1<<6);

    // Use full 16-bit resolution.
    ICR1 = 0xFFFF;

    TCCR1A = _BV(COM1B1) | _BV(WGM11); // = 0b00001010;
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS10); // = 0b00011001;

    backlight_init();
}

void backlight_set(uint8_t level)
{
    // Prevent backlight blink on lowest level
    PORTB &= ~(_BV(PORTB6));

    if ( level == 0 )
    {
        // Turn off PWM control on PB6, revert to output low.
        TCCR1A &= ~(_BV(COM1B1));
        CHANNEL = 0x0;
    }
    else if ( level == BACKLIGHT_LEVELS )
    {
        // Turn on PWM control of PB6
        TCCR1A |= _BV(COM1B1);
        // Set the brightness
        CHANNEL = 0xFFFF;
    }
    else
    {
        // Turn on PWM control of PB6
        TCCR1A |= _BV(COM1B1);
		
		    switch (level) {
        case 1:
		CHANNEL = 0x005F;
            break;
		case 2:
		CHANNEL = 0x00FF;
            break;
		case 3:
		CHANNEL = 0x0FFF;
            break;
		case 4:
		CHANNEL = 0x2FFF;
            break;
		case 5:
		CHANNEL = 0x7FFF;
            break;
    }
		
    }
}

#endif