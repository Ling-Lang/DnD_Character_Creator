/*******************************************************************************************
*
*   WelcomeWindow v1.0.0 - Tool Description
*
*   MODULE USAGE:
*       #define GUI_WELCOME_WINDOW_IMPLEMENTATION
*       #include "gui_welcome_window.h"
*
*       INIT: GuiWelcomeWindowState state = InitGuiWelcomeWindow();
*       DRAW: GuiWelcomeWindow(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 Ling-Lang. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#ifndef GUI_WELCOME_WINDOW_H
#define GUI_WELCOME_WINDOW_H

typedef struct {
    bool WindowBox000Active;
    bool CheckBoxEx002Checked;
    bool TextmultiBox003EditMode;
    char TextmultiBox003Text[128];

    Rectangle layoutRecs[5];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiWelcomeWindowState;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiWelcomeWindowState InitGuiWelcomeWindow(void);
void GuiWelcomeWindow(GuiWelcomeWindowState *state);
static void Button004();

#ifdef __cplusplus
}
#endif

#endif // GUI_WELCOME_WINDOW_H

/***********************************************************************************
*
*   GUI_WELCOME_WINDOW IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_WELCOME_WINDOW_IMPLEMENTATION)

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiWelcomeWindowState InitGuiWelcomeWindow(void)
{
    GuiWelcomeWindowState state = { 0 };

    state.WindowBox000Active = true;
    state.CheckBoxEx002Checked = false;
    state.TextmultiBox003EditMode = false;
    strcpy(state.TextmultiBox003Text, "Label");

    state.layoutRecs[0] = (Rectangle){ 416, 176, 424, 240 };
    state.layoutRecs[1] = (Rectangle){ 432, 200, 280, 32 };
    state.layoutRecs[2] = (Rectangle){ 480, 360, 24, 24 };
    state.layoutRecs[3] = (Rectangle){ 480, 240, 328, 112 };
    state.layoutRecs[4] = (Rectangle){ 688, 360, 120, 24 };

    // Custom variables initialization

    return state;
}
static void Button004()
{
        
}


void GuiWelcomeWindow(GuiWelcomeWindowState *state)
{
    if (state->WindowBox000Active)
    {
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "Welcome");
        GuiLabel(state->layoutRecs[1], "Label");
        state->CheckBoxEx002Checked = GuiCheckBox(state->layoutRecs[2], "CheckBox", state->CheckBoxEx002Checked);
        if (GuiTextBoxMulti(state->layoutRecs[3], state->TextmultiBox003Text, 128, state->TextmultiBox003EditMode)) state->TextmultiBox003EditMode = !state->TextmultiBox003EditMode;
        if (GuiButton(state->layoutRecs[4], "Close")) Button004(); 
    }
}

#endif // GUI_WELCOME_WINDOW_IMPLEMENTATION
