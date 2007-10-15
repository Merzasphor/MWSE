/*
	Copyright Ryan Kluzak

	This file is part of MWSE

    MWSE is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    MWSE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MWSE; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef GUI_H


#define GUI_H
#include "vm.h"

#define ATTRIB_err_success 		 0xFFFF8001
#define ATTRIB_err_null_pointer 	0xFFFF8002
#define ATTRIB_err_does_not_exist    0xFFFF8003
#define ATTRIB_err_cant_load_model  0xFFFF8004
#define ATTRIB_err_value_is_pointer  0xFFFF8005
#define ATTRIB_err_bad_pointer e  0xFFFF8006
#define ATTRIB_err_free_memory 		0xFFFF8007
#define ATTRIB_err_incorrect_type	0xFFFF8008
#define ATTRIB_id     				0xFFFF8009
#define ATTRIB_name       		    0xFFFF800A
#define ATTRIB_border  			   0xFFFF800B
#define ATTRIB_border_top 		    0xFFFF800C
#define ATTRIB_border_left   	    0xFFFF800D
#define ATTRIB_border_bottom 	    0xFFFF800E
#define ATTRIB_border_right  	    0xFFFF800F
#define ATTRIB_padding       	    0xFFFF8010
#define ATTRIB_padding_top 		    0xFFFF8011
#define ATTRIB_padding_left  	    0xFFFF8012
#define ATTRIB_padding_bottom	    0xFFFF8013
#define ATTRIB_padding_right 	    0xFFFF8014
#define ATTRIB_type      		    0xFFFF8015
#define ATTRIB_font   			    0xFFFF8016
#define ATTRIB_pointer		0xFFFF8017
#define ATTRIB_x_loc   		0xFFFF8018
#define ATTRIB_y_loc   		0xFFFF8019
#define ATTRIB_abs_x 		0xFFFF801A
#define ATTRIB_abs_y  		0xFFFF801B
#define ATTRIB_y_visible  0xFFFF801C
#define ATTRIB_node_min_x  	0xFFFF801F
#define ATTRIB_node_max_x  	0xFFFF8020
#define ATTRIB_node_min_y  0xFFFF8021
#define ATTRIB_node_max_y   0xFFFF8022
#define ATTRIB_clip_min_x   0xFFFF8025
#define ATTRIB_clip_max_x   0xFFFF8026
#define ATTRIB_clip_min_y   0xFFFF8027
#define ATTRIB_clip_max_y   0xFFFF8028
#define ATTRIB_mid_x        0xFFFF8029
#define ATTRIB_mid_y        0xFFFF802A
#define ATTRIB_width        0xFFFF802B
#define ATTRIB_height       0xFFFF802C
#define ATTRIB_min_width    0xFFFF802D
#define ATTRIB_min_height   0xFFFF802E
#define ATTRIB_max_width    0xFFFF802F
#define ATTRIB_max_height   0xFFFF8030
#define ATTRIB_extra_data   0xFFFF8031
#define ATTRIB_idle         0xFFFF8032
#define ATTRIB_over         0xFFFF8033
#define ATTRIB_pressed      0xFFFF8034
#define ATTRIB_click        0xFFFF8035
#define ATTRIB_scroll_up    0xFFFF8036
#define ATTRIB_scroll_down  0xFFFF8037
#define ATTRIB_double_click 0xFFFF8038
#define ATTRIB_still_idle   0xFFFF8039
#define ATTRIB_still_over  0xFFFF803A
#define ATTRIB_still_pressed_outside    0xFFFF803B
#define ATTRIB_still_pressed            0xFFFF803C
#define ATTRIB_release                  0xFFFF803D
#define ATTRIB_key                      0xFFFF803E
#define ATTRIB_enter        			0xFFFF803F
#define ATTRIB_leave_menu_mode         0xFFFF8040
#define ATTRIB_enter_menu_mode          0xFFFF8041
#define ATTRIB_focus                    0xFFFF8042
#define ATTRIB_unfocus                  0xFFFF8043
#define ATTRIB_update                   0xFFFF8044
#define ATTRIB_pre_update               0xFFFF8045
#define ATTRIB_update_disable           0xFFFF8046
#define ATTRIB_destroy                  0xFFFF8047
#define ATTRIB_focusable                0xFFFF8048
#define ATTRIB_hypertext                0xFFFF8049
#define ATTRIB_override                 0xFFFF804A
#define ATTRIB_dragable                 0xFFFF804B
#define ATTRIB_resizeable               0xFFFF804C
#define ATTRIB_red                      0xFFFF804D
#define ATTRIB_green                    0xFFFF804E
#define ATTRIB_blue                     0xFFFF804F
#define ATTRIB_alpha                    0xFFFF8050
#define ATTRIB_use_global_alpha         0xFFFF8051
#define ATTRIB_false         		   0xFFFF80bd
#define ATTRIB_partial         		   0xFFFF80be
#define ATTRIB_align_x         		   0xFFFF8054
#define ATTRIB_align_y         		   0xFFFF8055

#define ATTRIB_null	         		   0xFFFF80b4
#define ATTRIB_repeat_keys      		   0xFFFF80b3
#define PartTextInput_length_limit      0xFB72
#define NAME_TEXT						0x1e7



//581f30 attributes
#define ATTRIB_leave_front	           0xFFFF80AD
#define ATTRIB_become_front	           0xFFFF80AE
#define ATTRIB_top_to_bottom		   0xFFFF80CC
#define ATTRIB_shunt_children		   0xFFFF8067



//This is the char pointer used to hold the address of the current result of an input box entry.
char *GLOBAL_inputText;  

//holds the address of the current window being displayed
char *GLOBAL_windowAddress;


int *newWindow(int windowID);
int setWidth(int *widgetAddress,int width);
int setHeight(int *widgetAddress, int height);
int setFocus();
int *newCanvas(int *parentWindow, int id);
int *newBorder(int *parentWidget,int *NIFAddressPointer);
int *newBlock(int *parentWidget);
int addText(int *parentWidget,char *textPointer);
int addText2(int *parentWidget,int buttonText);
int show(int *widget);
int *newWidget(int *parentWidget, int data1, int data2, int id);
int *setAttribute(int *widgetAddress, int data1, int data2, int data3);
int *newButton(int *parentWidget, char *textPointer, int *callbackFunction, int id);
int *newTextInput(int *parentWidget,int id);
int doSomething(int *widget);
int dialogCallback(int *widget);
int newInputDialog(char *title, char *buttonText);
int leaveMenuMode(char *widget);
int enterMenuMode();





#endif