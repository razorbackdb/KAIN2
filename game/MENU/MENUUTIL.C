#include "THISDUST.H"
#include "MENUUTIL.H"

menu_ctrl_t menu_get_ctrl(void *gt)

{
  u_int uVar1;
  menu_ctrl_t mVar2;

  uVar1 = *(u_int *)((int)gt + 0x4c);
  if ((uVar1 & 1) == 0)
  {
    if ((uVar1 & 2) == 0)
    {
      if ((uVar1 & 4) == 0)
      {
        if ((uVar1 & 8) == 0)
        {
          if ((uVar1 & 0x80) == 0)
          {
            mVar2 = menu_ctrl_cancel;
            if (((uVar1 & 0x10) == 0) && (mVar2 = menu_ctrl_none, (uVar1 & 0x4000) != 0))
            {
              mVar2 = menu_ctrl_start;
            }
          }
          else
          {
            mVar2 = menu_ctrl_engage;
          }
        }
        else
        {
          mVar2 = menu_ctrl_right;
        }
      }
      else
      {
        mVar2 = menu_ctrl_left;
      }
    }
    else
    {
      mVar2 = menu_ctrl_down;
    }
  }
  else
  {
    mVar2 = menu_ctrl_up;
  }
  return mVar2;
}

void menu_pop(int xpos, int ypos, char *text, int color)

{
  FONT_SetCursor((short)xpos, (short)ypos);
  if (color != 0)
  {
    FONT_SetColorIndex(color);
  }
  FONT_Print2(text);
  if (color != 0)
  {
    FONT_SetColorIndex(0);
  }
  return;
}

int menu_text_width(char *text)

{
  int iVar1;

  iVar1 = FONT_GetStringWidth(text);
  return iVar1;
}

void menu_set(menu_sound_t sound)

{
  SndPlay((&the_menu_sounds)[sound].sfx);
  return;
}
