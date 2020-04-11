#include "THISDUST.H"
#include "MENUUTIL.H"


// decompiled code
// original method signature: 
// enum menu_ctrl_t /*$ra*/ menu_get_ctrl(void *gt /*$a0*/)
 // line 18, offset 0x800b713c
	/* begin block 1 */
		// Start line: 20
		// Start offset: 0x800B713C
		// Variables:
	// 		enum menu_ctrl_t ctrl; // $a0
	/* end block 1 */
	// End offset: 0x800B71B0
	// End Line: 30

	/* begin block 2 */
		// Start line: 36
	/* end block 2 */
	// End Line: 37

	/* begin block 3 */
		// Start line: 37
	/* end block 3 */
	// End Line: 38

	/* begin block 4 */
		// Start line: 39
	/* end block 4 */
	// End Line: 40

/* File: C:\kain2\game\MENU\MENUUTIL.C */

menu_ctrl_t menu_get_ctrl(void *gt)

{
  uint uVar1;
  menu_ctrl_t mVar2;
  
  uVar1 = *(uint *)((int)gt + 0x4c);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      if ((uVar1 & 4) == 0) {
        if ((uVar1 & 8) == 0) {
          if ((uVar1 & 0x80) == 0) {
            mVar2 = menu_ctrl_cancel;
            if (((uVar1 & 0x10) == 0) && (mVar2 = menu_ctrl_none, (uVar1 & 0x4000) != 0)) {
              mVar2 = menu_ctrl_start;
            }
          }
          else {
            mVar2 = menu_ctrl_engage;
          }
        }
        else {
          mVar2 = menu_ctrl_right;
        }
      }
      else {
        mVar2 = menu_ctrl_left;
      }
    }
    else {
      mVar2 = menu_ctrl_down;
    }
  }
  else {
    mVar2 = menu_ctrl_up;
  }
  return mVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_print(int xpos /*$a0*/, int ypos /*$a1*/, char *text /*$s1*/, int color /*$s0*/)
 // line 33, offset 0x800b71b8
	/* begin block 1 */
		// Start line: 66
	/* end block 1 */
	// End Line: 67

/* File: C:\kain2\game\MENU\MENUUTIL.C */

void menu_print(int xpos,int ypos,char *text,int color)

{
  FONT_SetCursor((short)xpos,(short)ypos);
  if (color != 0) {
    FONT_SetColorIndex(color);
  }
  FONT_Print2(text);
  if (color != 0) {
    FONT_SetColorIndex(0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menu_text_width(char *text /*$a0*/)
 // line 61, offset 0x800b7220
	/* begin block 1 */
		// Start line: 142
	/* end block 1 */
	// End Line: 143

/* File: C:\kain2\game\MENU\MENUUTIL.C */

int menu_text_width(char *text)

{
  int iVar1;
  
  iVar1 = FONT_GetStringWidth(text);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_sound(enum menu_sound_t sound /*$a0*/)
 // line 84, offset 0x800b7240
	/* begin block 1 */
		// Start line: 85
		// Start offset: 0x800B7240
		// Variables:
	// 		struct menu_sound_entry_t *entry; // $a0
	/* end block 1 */
	// End offset: 0x800B7240
	// End Line: 85

	/* begin block 2 */
		// Start line: 188
	/* end block 2 */
	// End Line: 189

/* File: C:\kain2\game\MENU\MENUUTIL.C */

void menu_sound(menu_sound_t sound)

{
  SndPlay(the_menu_sounds[sound].sfx);
  return;
}





