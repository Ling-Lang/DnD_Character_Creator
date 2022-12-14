/*******************************************************************************************
*
*   Welcome v1.0.0 - Tool Description
*
*   MODULE USAGE:
*       #define GUI_WELCOME_IMPLEMENTATION
*       #include "gui_welcome.h"
*
*       INIT: GuiWelcomeState state = InitGuiWelcome();
*       DRAW: GuiWelcome(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 ling-lang. All Rights Reserved.
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

#ifndef GUI_WELCOME_H
#define GUI_WELCOME_H

typedef struct {
    bool WindowBox000Active;

    Rectangle layoutRecs[4];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiWelcomeState;

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
GuiWelcomeState InitGuiWelcome(void);
void GuiWelcome(GuiWelcomeState *state);
static void Button001();
static void Button003();

#ifdef __cplusplus
}
#endif

#endif // GUI_WELCOME_H

/***********************************************************************************
*
*   GUI_WELCOME IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_WELCOME_IMPLEMENTATION)

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
GuiWelcomeState InitGuiWelcome(void)
{
    GuiWelcomeState state = { 0 };

    state.WindowBox000Active = true;

    state.layoutRecs[0] = (Rectangle){ 344, 176, 424, 248 };
    state.layoutRecs[1] = (Rectangle){ 376, 376, 136, 32 };
    state.layoutRecs[2] = (Rectangle){ 376, 216, 360, 128 };
    state.layoutRecs[3] = (Rectangle){ 592, 376, 136, 32 };

    // Custom variables initialization

    return state;
}
static void Button001()
{
    // TODO: Implement control logic
}
static void Button003()
{
    // TODO: Implement control logic
}


void GuiWelcome(GuiWelcomeState *state)
{
    if (state->WindowBox000Active)
    {
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "SAMPLE TEXT");
        if (GuiButton(state->layoutRecs[1], "SAMPLE TEXT")) Button001(); 
        GuiLabel(state->layoutRecs[2], "SAMPLE TEXT");
        if (GuiButton(state->layoutRecs[3], "SAMPLE TEXT")) Button003(); 
    }
}

#endif // GUI_WELCOME_IMPLEMENTATION
