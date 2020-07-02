/**
 * @file  mouseMove.h
 * @author Vedant
 * @date 16/2/2017
 * 
 * This is a header file having Xlib headers and function declarations
 *
 */

//Headers
// Xlib

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/X.h>

#include <X11/extensions/XTest.h>

//Functions Declarations

/**
 * moves mouse using x, y coordinates, on curent display and window
 *
 */
void move_mouse(Display *cur_disp, float x, float y);

int mousebutton(Display *cur_disp, int button, bool is_press);

void get_mouse_location(Display *disp, XButtonEvent *xbe);

void minimizewindow(Display *cur_disp, Window window);

unsigned int get_input_state(Display *disp);


