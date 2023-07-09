
/*  ev3_light.h was generated by yup.py (yupp) 1.0c6
    out of ev3_light.yu-h 
 *//**
 *  \file  ev3_light.h (ev3_light.yu-h)
 *  \brief  EV3 Lights (GREEN and RED LEDs at once).
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#pragma once

/**
 *  \brief Identifiers of light locations.
 */
#define LIT_LEFT 0
#define LIT_RIGHT 1
#define LIT__LOC__ 2

/**
 *  \brief Identifiers of light colors.
 */
#define LIT_OFF 0
#define LIT_GREEN 1
#define LIT_RED 2
#define LIT_AMBER 3

#define LIT__COL__ 4
};

/**
 *  \brief Light colors.
 */
.extern LIT_COLOR

/**
 *  \fn const char *light_color( uint8_t col )
 *  \brief Get the light color name.
 *  \param col Color.
 *  \return Color name.
 */
.extern light_color

/**
 *  \fn void set_light( uint8_t loc, uint8_t col )
 *  \brief Set the light color.
 *  \param loc Location.
 *  \param col Color.
 */
.extern set_light

/**
 *  \fn uint8_t get_light( uint8_t loc )
 *  \brief Get the light color.
 *  \param loc Location.
 *  \return Color.
 */
.extern get_light

/**
 *  \fn void set_light_trigger( uint8_t loc, uint8_t col, uint8_t trigger )
 *  \brief Set the light trigger.
 *  \param loc Location.
 *  \param col Color.
 *  \param trigger Index of trigger.
 */
.extern set_light_trigger

/**
 *  \fn uint8_t get_light_trigger( uint8_t loc, uint8_t col )
 *  \brief Get the light trigger.
 *  \param loc Location.
 *  \param col Color.
 *  \return Index of trigger or TRIGGER__COUNT_ - error has occurred.
 */
.extern get_light_trigger

/**
 *  \fn void set_light_blink( uint8_t loc, uint8_t col, int delay_on, int delay_off )
 *  \brief Set the light blink.
 *  \param loc Location.
 *  \param col Color.
 *  \param delay_on Time of "on" state in ms.
 *  \param delay_off Time of "off" state in ms.
 */
.extern set_light_blink

/**
 *  \fn bool get_light_blink( uint8_t loc, uint8_t col )
 *  \brief Check the light is blinking.
 *  \param loc Location.
 *  \param col Color.
 *  \return Flag - the light is blinking.
 */
.extern get_light_blink