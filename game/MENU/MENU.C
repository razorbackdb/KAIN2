#include "THISDUST.H"
#include "MENU.H"

int menu_data_size(void)

{
  return 0x388;
}

void menuface_initialize(menu_t *menu, void *opaque)

{
  memset(menu, 0, 0x388);
  menu->nmenus = -1;
  menu->opaque = opaque;
  return;
}

void menu_format(menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip,
                 int border)

{
  char *pcVar1;

  pcVar1 = menu[-1].bytes + menu->nmenus * 0x24 + 0x1f0;
  *(int *)(pcVar1 + 8) = xpos;
  *(int *)(pcVar1 + 0xc) = ypos;
  *(int *)(pcVar1 + 0x1c) = center;
  *(int *)(pcVar1 + 0x10) = lineskip;
  *(int *)(pcVar1 + 0x14) = itemskip;
  *(int *)(pcVar1 + 0x18) = width;
  *(int *)(pcVar1 + 0x20) = border;
  return;
}

void menu_sound(menu_t *menu, TDRFuncPtr_menu_set1fn fn)

{
  menu->nmenus = 0;
  menu->drawfn = (_func_62 *)0x0;
  menu_print(menu, (TDRFuncPtr_menu_push1fn)fn);
  return;
}

void menu_print(menu_t *menu, TDRFuncPtr_menu_push1fn fn)

{
  int iVar1;
  menu_stack_t *pmVar2;
  int iVar3;
  int iVar4;

  iVar1 = menu->nmenus;
  menu->nmenus = iVar1 + 1;
  pmVar2 = menu->stack + iVar1;
  *(TDRFuncPtr_menu_push1fn *)&pmVar2->fn = fn;
  pmVar2->index = -1;
  iVar1 = pmVar2[-1].format.ypos;
  iVar3 = pmVar2[-1].format.lineskip;
  iVar4 = pmVar2[-1].format.itemskip;
  (pmVar2->format).xpos = pmVar2[-1].format.xpos;
  (pmVar2->format).ypos = iVar1;
  (pmVar2->format).lineskip = iVar3;
  (pmVar2->format).itemskip = iVar4;
  iVar1 = pmVar2[-1].format.center;
  iVar3 = pmVar2[-1].format.border;
  (pmVar2->format).width = pmVar2[-1].format.width;
  (pmVar2->format).center = iVar1;
  (pmVar2->format).border = iVar3;
  return;
}

void menu_pop(menu_t *menu)

{
  menu->nmenus = menu->nmenus + -1;
  return;
}

void menu_item_flags(menu_t *menu, TDRFuncPtr_menu_item_flags1fn fn, long parameter, long flags,
                     char *format)

{
  int iVar1;
  size_t sVar2;
  menu_item_t *pmVar3;

  pmVar3 = menu->items + menu->nitems;
  menu->nitems = menu->nitems + 1;
  *(TDRFuncPtr_menu_item_flags1fn *)&pmVar3->fn = fn;
  pmVar3->parameter = parameter;
  iVar1 = menu->nbytes;
  pmVar3->flags = flags;
  pmVar3->text = menu->bytes + iVar1;
  vsprintf(menu->bytes + iVar1, format, &stack0x00000014);
  iVar1 = menu->nbytes;
  sVar2 = strlen(pmVar3->text);
  menu->nbytes = iVar1 + 1 + sVar2;
  return;
}

void num_menu_items(menu_t *menu, TDRFuncPtr_menu_item1fn fn, long parameter, char *format)

{
  int iVar1;
  size_t sVar2;
  menu_item_t *pmVar3;

  pmVar3 = menu->items + menu->nitems;
  menu->nitems = menu->nitems + 1;
  *(TDRFuncPtr_menu_item1fn *)&pmVar3->fn = fn;
  pmVar3->parameter = parameter;
  iVar1 = menu->nbytes;
  pmVar3->flags = 0;
  pmVar3->text = menu->bytes + iVar1;
  if (format == (char *)0x0)
  {
    pmVar3->text = (char *)0x0;
  }
  else
  {
    vsprintf(menu->bytes + iVar1, format, &stack0x00000010);
    iVar1 = menu->nbytes;
    sVar2 = strlen(pmVar3->text);
    menu->nbytes = iVar1 + 1 + sVar2;
  }
  return;
}

void menu_build(menu_t *menu)

{
  menu_stack_t *pmVar1;
  int iVar2;

  menu->nitems = 0;
  menu->nbytes = 0;
  pmVar1 = menu->stack + menu->nmenus;
  iVar2 = (*pmVar1[-1].fn)(menu->opaque, pmVar1[-1].index);
  pmVar1[-1].index = iVar2;
  return;
}

void DisplayHintBox(int len, int y)

{
  short x1;
  int y2;
  int x3;
  int iVar1;

  iVar1 = 0;
  len = len >> 1;
  x3 = len + 0x105;
  y2 = y + -1;
  y = y + 0xd;
  do
  {
    x1 = (short)(0xfb - len);
    DRAW_TranslucentQuad(x1 + -0xe, (short)(y2 + y >> 1), x1, (short)y, 0xfb - len, y2, x3, y, 0, 0, 0, 0,
                         gameTrackerX.primPool, gameTrackerX.drawOT + 1);
    iVar1 = iVar1 + 1;
    DRAW_TranslucentQuad(x1, (short)y2, (short)x3, (short)y, x3, y2, len + 0x113, y2 + y >> 1, 0, 0, 0, 0,
                         gameTrackerX.primPool, gameTrackerX.drawOT + 1);
  } while (iVar1 < 2);
  return;
}

void DisplayMenuBox(int x0, int x1, int y0, int y1)

{
  short y0_00;
  int iVar1;
  _PrimPool *primPool;
  int y2;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  u_long **ot;
  int iVar7;
  int iVar8;

  primPool = gameTrackerX.primPool;
  iVar8 = 0;
  iVar3 = x0 + -0xc;
  iVar4 = x1 + 0xc;
  y2 = y0 + -5;
  y0_00 = (short)y1 + 5;
  ot = gameTrackerX.drawOT + 1;
  if (y1 - y0 < 0x50)
  {
    piVar2 = &DAT_800d0c70;
    do
    {
      piVar2 = piVar2 + 1;
      iVar8 = iVar8 + 1;
    } while (y1 - y0 < *piVar2 << 1);
  }
  iVar7 = 0;
  do
  {
    iVar1 = iVar8;
    while (iVar1 < 0xf)
    {
      iVar6 = iVar1 + 1;
      piVar2 = &DAT_800d0c70 + iVar1;
      piVar5 = &DAT_800d0c70 + iVar6;
      DRAW_TranslucentQuad((short)(iVar3 + iVar1), y0_00 - (short)*piVar2, (short)iVar3 + (short)iVar6,
                           y0_00 - (short)*piVar5, iVar3 + iVar1, y2 + *piVar2, iVar3 + iVar6, y2 + *piVar5, 0, 0, 0,
                           0, primPool, ot);
      DRAW_TranslucentQuad((short)(iVar4 - iVar1), y0_00 - (short)*piVar2, (short)iVar4 - (short)iVar6,
                           y0_00 - (short)*piVar5, iVar4 - iVar1, y2 + *piVar2, iVar4 - iVar6, y2 + *piVar5, 0, 0, 0,
                           0, primPool, ot);
      iVar1 = iVar6;
    }
    iVar7 = iVar7 + 1;
    DRAW_TranslucentQuad((short)(x0 + 3), y0_00, (short)iVar4 + -0xf, y0_00, x0 + 3, y2, x1 + -3, y2, 0, 0, 0, 0, primPool, ot);
  } while (iVar7 < 2);
  return;
}

int draw_menu(menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags, Extents2d *e)

{
  int *piVar1;
  size_t sVar2;
  char *__src;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int xpos;
  int iVar7;
  int xpos_00;
  int ypos_00;
  char acStack320[256];
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;

  local_3c = 0;
  piVar1 = &menu->nmenus + menu->nmenus * 9;
  local_40 = piVar1 + -4;
  local_38 = 1;
  if (((flags & 1U) == 0) && (local_38 = 0, (flags & 2U) == 0))
  {
    local_38 = piVar1[1];
  }
  if (ypos == 0)
  {
    ypos = piVar1[-3];
  }
  ypos = ypos + yadj;
  sVar2 = strlen(text);
  iVar7 = 1;
  xpos = 0;
  __src = text;
  if (0 < (int)sVar2)
  {
    do
    {
      if (*__src == '\t')
      {
        iVar7 = iVar7 + 1;
      }
      xpos = xpos + 1;
      __src = text + xpos;
    } while (xpos < (int)sVar2);
  }
  iVar7;
  if (local_40[5] == 0)
  {
    local_34 = *local_40 + xadj;
  }
  else
  {
    local_34 = (*local_40 + xadj) - (local_40[4] >> 1);
  }
  __src = strtok(text, "\t");
  if (__src != (char *)0x0)
  {
    local_30 = 0;
    do
    {
      xpos = local_34 + xadj + local_30;
      if (local_38 != 0)
      {
        xpos = xpos + (iVar7 >> 1);
      }
      if (ypos < e->ymin)
      {
        e->ymin = ypos;
      }
      strcmp(acStack320, __src);
      __src = acStack320;
      ypos_00 = ypos;
      do
      {
        pcVar3 = strchr(__src, 10);
        if (pcVar3 != (char *)0x0)
        {
          *pcVar3 = '\0';
        }
        while (__src != (char *)0x0)
        {
          pcVar4 = strchr(__src, 0x20);
          if (pcVar4 != (char *)0x0)
          {
            do
            {
              pcVar5 = strchr(pcVar4 + 1, 0x20);
              if (pcVar5 != (char *)0x0)
              {
                *pcVar5 = '\0';
              }
              iVar6 = menu_text_width(__src);
              if (pcVar5 != (char *)0x0)
              {
                *pcVar5 = ' ';
              }
            } while ((iVar6 <= iVar7) && (pcVar4 = pcVar5, pcVar5 != (char *)0x0));
            if (pcVar4 != (char *)0x0)
            {
              *pcVar4 = '\0';
            }
          }
          if (local_38 == 0)
          {
            iVar6 = menu_text_width(__src);
            menu_pop(xpos, ypos_00, __src, color);
            if (xpos < e->xmin)
            {
              e->xmin = xpos;
            }
            xpos_00 = e->xmax;
          }
          else
          {
            iVar6 = menu_text_width(__src);
            iVar6 = iVar6 >> 1;
            xpos_00 = xpos - iVar6;
            menu_pop(xpos_00, ypos_00, __src, color);
            if (xpos_00 < e->xmin)
            {
              e->xmin = xpos_00;
            }
            xpos_00 = e->xmax;
          }
          if (xpos_00 < xpos + iVar6)
          {
            e->xmax = xpos + iVar6;
          }
          ypos_00 = ypos_00 + local_40[2];
          if (pcVar4 == (char *)0x0)
            break;
          __src = pcVar4 + 1;
          *pcVar4 = ' ';
        }
        if (pcVar3 == (char *)0x0)
          break;
        __src = pcVar3 + 1;
        *pcVar3 = '\n';
      } while (__src != (char *)0x0);
      local_30 = local_30 + iVar7;
      __src = strtok((char *)0x0, "\t");
      if (local_3c < ypos_00)
      {
        local_3c = ypos_00;
      }
    } while (__src != (char *)0x0);
  }
  if (e->ymax < local_3c)
  {
    e->ymax = local_3c;
  }
  local_3c = local_3c + local_40[3];
  if ((flags & 4U) != 0)
  {
    local_3c = local_3c + (local_40[2] >> 1);
  }
  return local_3c;
}

void menu_draw_item(menu_t *menu)

{
  bool bVar1;
  int iVar2;
  char **ppcVar3;
  int iVar4;
  int iVar5;
  int ypos;
  int iVar6;
  Extents2d local_30;

  local_30.xmin = 0x7fffffff;
  local_30.xmax = &DAT_80000000;
  local_30.ymin = 0x7fffffff;
  local_30.ymax = &DAT_80000000;
  iVar2 = menu->nmenus;
  iVar6 = (&menu->nmenus + iVar2 * 9)[-5];
  ypos = 0;
  if (menu->drawfn != (_func_62 *)0x0)
  {
    (*menu->drawfn)(menu->opaque);
  }
  iVar4 = 0;
  if (0 < menu->nitems)
  {
    iVar5 = 0xc0;
    do
    {
      ppcVar3 = (char **)((int)&menu->nmenus + iVar5);
      iVar5 = iVar5 + 0x10;
      bVar1 = iVar4 != iVar6;
      iVar4 = iVar4 + 1;
      ypos = draw_menu(menu, ypos, 0, 0, *ppcVar3, (u_int)bVar1, (long)ppcVar3[3], &local_30);
    } while (iVar4 < menu->nitems);
  }
  if ((&menu->nmenus + iVar2 * 9)[2] != 0)
  {
    DisplayMenuBox(local_30.xmin, (int)local_30.xmax, local_30.ymin, (int)local_30.ymax);
  }
  return;
}

void menu_run(menu_t *menu)

{
  menu_ctrl_t mVar1;
  menu_sound_t sound;
  _func_64 *p_Var2;
  int iVar3;
  int *piVar4;
  int iVar5;

  mVar1 = menu_get_ctrl(menu->opaque);
  piVar4 = &menu->nmenus + menu->nmenus * 9;
  iVar5 = piVar4[-5];
  if ((-1 < iVar5) && (mVar1 != menu_ctrl_none))
  {
    menudefs_reset_hack_attract_mode();
    sound = (*menu->items[iVar5].fn)(menu->opaque, menu->items[iVar5].parameter, mVar1);
    if (sound == menu_sound_none)
    {
      if (mVar1 == menu_ctrl_down)
      {
        iVar5 = (iVar5 + 1) % menu->nitems;
        p_Var2 = menu->items[iVar5].fn;
        while (p_Var2 == (_func_64 *)0x0)
        {
          iVar5 = (iVar5 + 1) % menu->nitems;
          p_Var2 = menu->items[iVar5].fn;
        }
      }
      else
      {
        if (mVar1 < menu_ctrl_left)
        {
          if (mVar1 == menu_ctrl_up)
          {
            iVar3 = menu->nitems;
            iVar5 = (iVar5 + iVar3 + -1) % iVar3;
            p_Var2 = menu->items[iVar5].fn;
            while (p_Var2 == (_func_64 *)0x0)
            {
              iVar5 = (iVar5 + iVar3 + -1) % iVar3;
              p_Var2 = menu->items[iVar5].fn;
            }
          }
        }
        else
        {
          if ((mVar1 == menu_ctrl_cancel) && (1 < menu->nmenus))
          {
            menu_set(menu_sound_pop);
            menu_pop(menu);
          }
        }
      }
      if (iVar5 != piVar4[-5])
      {
        menu_set(menu_sound_select);
      }
      piVar4[-5] = iVar5;
    }
    else
    {
      menu_set(sound);
    }
  }
  return;
}

void process_menu_line(menu_t *menu)

{
  menu_build(menu);
  menu_draw_item(menu);
  menu_run(menu);
  return;
}
