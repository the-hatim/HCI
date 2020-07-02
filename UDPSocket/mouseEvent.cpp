#include <iostream>
#include <unistd.h>
#include <string.h>
#include<mouseEvent.h>


float a1 = 0, a2 = 0, vx = 0, vy = 0, ux = 0, uy = 0;
static int state = 0; //0 = IDlE and 1 = MOving




void move_mouse(Display *cur_disp,float x, float y)
{


 /*   a2 = x + y;

    a1 = a2;

    vx = ux + x;
    vy = uy + y;

    ux = vx;
    uy = vy;

    float values[2];
    values[0] = vx;
    values[1] = vy;

   float velocityMagnitude = KinematicsGovernor::vectorMagnitude(values);

   switch(state){
   case 0:
        ux = 0;
        uy = 0;

        if (velocityMagnitude > 1)
                state = 1;
       break;

   case 1:
       ux = vx;
       uy = vy;

       if (velocityMagnitude < 1)
            state = 0;
       break;


   }*/

    XWarpPointer(cur_disp, None,None, 0, 0, 0, 0, x, y);
    XFlush(cur_disp);




}

int mousebutton(Display *cur_disp, int button, bool is_press)
{
	//MIght create someproblem.
	XTestFakeButtonEvent(cur_disp, button, is_press, CurrentTime);
        XTestFakeButtonEvent(cur_disp, button, False, CurrentTime);
	XFlush(cur_disp);
/*	XEvent event;
	memset(&event, 0, sizeof(event));

	event.xbutton.button = button;
	event.xbutton.same_screen = True;
	event.xbutton.subwindow = DefaultRootWindow(cur_disp);
    tFakeButtonEvent requests the server to simulate either a ButtonPress (if is_press is True) or a ButtonRelease
	while(event.xbutton.subwindow){
		event.xbutton.window = event.xbutton.subwindow;
		
		XQueryPointer(cur_disp, event.xbutton.window, &event.xbutton.root, &event.xbutton.subwindow, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);

	}

	event.type = ButtonPress;

	if (XSendEvent(cur_disp, PointerWindow, True, ButtonPressMask, &event) == 0)
		cout<<"Error to send the event \n";
	XFlush(cur_disp);
	
	usleep(1);

	event.type = ButtonRelease;

	if (XSendEvent(cur_disp, PointerWindow, True, ButtonPressMask, &event) == 0)
                cout<<"Error to send the event \n";
        XFlush(cur_disp);

        usleep(1);
*/
	return 0;
}

