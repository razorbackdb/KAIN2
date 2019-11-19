#include "THISDUST.H"
#include "MENUUTIL.H"


// decompiled code
// original method signature: 
// enum menu_ctrl_t /*$ra*/ menu_get_ctrl(void *gt /*$a0*/)
 // line 18, offset 0x800b2848
	/* begin block 1 */
		// Start line: 20
		// Start offset: 0x800B2848
		// Variables:
	// 		enum menu_ctrl_t ctrl; // $a0
	/* end block 1 */
	// End offset: 0x800B28BC
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
 // line 33, offset 0x800b28c4
	/* begin block 1 */
		// Start line: 66
	/* end block 1 */
	// End Line: 67

void menu_print(int xpos,int ypos,char *text,int color)

{
  FONT_SetCursor((short)xpos,(short)ypos);
  if (color != 0) {
    FONT_SetColorIndex(color);
  }
  FONT_Print(text);
  if (color != 0) {
    FONT_SetColorIndex(0);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ menu_text_width(char *text /*$a0*/)
 // line 54, offset 0x800b292c
	/* begin block 1 */
		// Start line: 122
	/* end block 1 */
	// End Line: 123

int menu_text_width(char *text)

{
  int iVar1;
  
  iVar1 = FONT_GetStringWidth(text);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_sound(enum menu_sound_t sound /*$a0*/)
 // line 77, offset 0x800b294c
	/* begin block 1 */
		// Start line: 78
		// Start offset: 0x800B294C
		// Variables:
	// 		struct menu_sound_entry_t *entry; // $a0
	/* end block 1 */
	// End offset: 0x800B294C
	// End Line: 78

	/* begin block 2 */
		// Start line: 168
	/* end block 2 */
	// End Line: 169

void menu_sound(menu_sound_t sound)

{
  SndPlay((&the_menu_sounds)[sound].sfx);
  return;
}





