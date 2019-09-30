#include "THISDUST.H"
#include "MENU.H"


// decompiled code
// original method signature: 
// int /*$ra*/ menu_data_size()
 // line 83, offset 0x800b6390
	/* begin block 1 */
		// Start line: 85
		// Start offset: 0x800B6390
	/* end block 1 */
	// End offset: 0x800B6390
	// End Line: 86

	/* begin block 2 */
		// Start line: 166
	/* end block 2 */
	// End Line: 167

	/* begin block 3 */
		// Start line: 167
	/* end block 3 */
	// End Line: 168

	/* begin block 4 */
		// Start line: 168
	/* end block 4 */
	// End Line: 169

	/* begin block 5 */
		// Start line: 169
	/* end block 5 */
	// End Line: 170

/* WARNING: Unknown calling convention yet parameter storage is locked */

int menu_data_size(void)

{
  return 0x388;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_initialize(struct menu_t *menu /*$s0*/, void *opaque /*$s1*/)
 // line 89, offset 0x800b6398
	/* begin block 1 */
		// Start line: 178
	/* end block 1 */
	// End Line: 179

void menu_initialize(menu_t *menu,void *opaque)

{
                    /* WARNING: Subroutine does not return */
  memset(menu,0,0x388);
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_format(struct menu_t *menu /*$a0*/, int center /*$a1*/, int xpos /*$a2*/, int ypos /*$a3*/, int width /*stack 16*/, int lineskip /*stack 20*/, int itemskip /*stack 24*/, int border /*stack 28*/)
 // line 97, offset 0x800b63dc
	/* begin block 1 */
		// Start line: 98
		// Start offset: 0x800B63DC

		/* begin block 1.1 */
			// Start line: 98
			// Start offset: 0x800B63DC
			// Variables:
		// 		struct menu_format_t *fmt; // $a0
		/* end block 1.1 */
		// End offset: 0x800B63DC
		// End Line: 101
	/* end block 1 */
	// End offset: 0x800B63DC
	// End Line: 101

	/* begin block 2 */
		// Start line: 196
	/* end block 2 */
	// End Line: 197

	/* begin block 3 */
		// Start line: 199
	/* end block 3 */
	// End Line: 200

void menu_format(menu_t *menu,int center,int xpos,int ypos,int width,int lineskip,int itemskip,
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



// decompiled code
// original method signature: 
// void /*$ra*/ menu_set(struct menu_t *menu /*$a0*/, TDRFuncPtr_menu_set1fn fn /*$a1*/)
 // line 115, offset 0x800b642c
	/* begin block 1 */
		// Start line: 240
	/* end block 1 */
	// End Line: 241

void menu_set(menu_t *menu,TDRFuncPtr_menu_set1fn fn)

{
  menu->nmenus = 0;
  menu->drawfn = (_func_62 *)0x0;
  menu_push(menu,(TDRFuncPtr_menu_push1fn)fn);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_push(struct menu_t *menu /*$a0*/, TDRFuncPtr_menu_push1fn fn /*$a1*/)
 // line 123, offset 0x800b6450
	/* begin block 1 */
		// Start line: 125
		// Start offset: 0x800B6450

		/* begin block 1.1 */
			// Start line: 127
			// Start offset: 0x800B6450
			// Variables:
		// 		struct menu_stack_t *stack; // $a0
		/* end block 1.1 */
		// End offset: 0x800B6450
		// End Line: 127
	/* end block 1 */
	// End offset: 0x800B6450
	// End Line: 127

	/* begin block 2 */
		// Start line: 256
	/* end block 2 */
	// End Line: 257

	/* begin block 3 */
		// Start line: 257
	/* end block 3 */
	// End Line: 258

	/* begin block 4 */
		// Start line: 259
	/* end block 4 */
	// End Line: 260

void menu_push(menu_t *menu,TDRFuncPtr_menu_push1fn fn)

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



// decompiled code
// original method signature: 
// void /*$ra*/ menu_pop(struct menu_t *menu /*$a0*/)
 // line 134, offset 0x800b64c0
	/* begin block 1 */
		// Start line: 279
	/* end block 1 */
	// End Line: 280

	/* begin block 2 */
		// Start line: 281
	/* end block 2 */
	// End Line: 282

void menu_pop(menu_t *menu)

{
  menu->nmenus = menu->nmenus + -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_item_flags(struct menu_t *menu /*$s2*/, TDRFuncPtr_menu_item_flags1fn fn /*$a1*/, long parameter /*$a2*/, long flags /*$a3*/, char *format /*stack 16*/)
 // line 152, offset 0x800b64d4
	/* begin block 1 */
		// Start line: 153
		// Start offset: 0x800B64D4

		/* begin block 1.1 */
			// Start line: 153
			// Start offset: 0x800B64D4
			// Variables:
		// 		struct menu_item_t *item; // $s1
		/* end block 1.1 */
		// End offset: 0x800B64D4
		// End Line: 153
	/* end block 1 */
	// End offset: 0x800B64D4
	// End Line: 153

	/* begin block 2 */
		// Start line: 294
	/* end block 2 */
	// End Line: 295

void menu_item_flags(menu_t *menu,TDRFuncPtr_menu_item_flags1fn fn,long parameter,long flags,
                    char *format)

{
  int iVar1;
  menu_item_t *pmVar2;
  
  pmVar2 = menu->items + menu->nitems;
  menu->nitems = menu->nitems + 1;
  *(TDRFuncPtr_menu_item_flags1fn *)&pmVar2->fn = fn;
  pmVar2->parameter = parameter;
  iVar1 = menu->nbytes;
  pmVar2->flags = flags;
  pmVar2->text = menu->bytes + iVar1;
                    /* WARNING: Subroutine does not return */
  vsprintf(menu->bytes + iVar1,format,&stack0x00000014);
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_item(struct menu_t *menu /*$s2*/, TDRFuncPtr_menu_item1fn fn /*$a1*/, long parameter /*$a2*/, char *format /*stack 12*/)
 // line 170, offset 0x800b6564
	/* begin block 1 */
		// Start line: 171
		// Start offset: 0x800B6564

		/* begin block 1.1 */
			// Start line: 171
			// Start offset: 0x800B6564
			// Variables:
		// 		struct menu_item_t *item; // $s1

			/* begin block 1.1.1 */
				// Start line: 181
				// Start offset: 0x800B65C4
			/* end block 1.1.1 */
			// End offset: 0x800B65C4
			// End Line: 183
		/* end block 1.1 */
		// End offset: 0x800B65F0
		// End Line: 192
	/* end block 1 */
	// End offset: 0x800B65F0
	// End Line: 193

	/* begin block 2 */
		// Start line: 344
	/* end block 2 */
	// End Line: 345

void menu_item(menu_t *menu,TDRFuncPtr_menu_item1fn fn,long parameter,char *format)

{
  int iVar1;
  menu_item_t *pmVar2;
  
  pmVar2 = menu->items + menu->nitems;
  menu->nitems = menu->nitems + 1;
  *(TDRFuncPtr_menu_item1fn *)&pmVar2->fn = fn;
  pmVar2->parameter = parameter;
  iVar1 = menu->nbytes;
  pmVar2->flags = 0;
  pmVar2->text = menu->bytes + iVar1;
  if (format != (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    vsprintf(menu->bytes + iVar1,format,&stack0x00000010);
  }
  pmVar2->text = (char *)0x0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_build(struct menu_t *menu /*$a0*/)
 // line 195, offset 0x800b6608
	/* begin block 1 */
		// Start line: 196
		// Start offset: 0x800B6608

		/* begin block 1.1 */
			// Start line: 196
			// Start offset: 0x800B6608
			// Variables:
		// 		struct menu_stack_t *stack; // $s0
		/* end block 1.1 */
		// End offset: 0x800B6608
		// End Line: 196
	/* end block 1 */
	// End offset: 0x800B6608
	// End Line: 196

	/* begin block 2 */
		// Start line: 403
	/* end block 2 */
	// End Line: 404

void menu_build(menu_t *menu)

{
  menu_stack_t *pmVar1;
  int iVar2;
  
  menu->nitems = 0;
  menu->nbytes = 0;
  pmVar1 = menu->stack + menu->nmenus;
  iVar2 = (*pmVar1[-1].fn)(menu->opaque,pmVar1[-1].index);
  pmVar1[-1].index = iVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ DisplayHintBox(int len /*$a0*/, int y /*$a1*/)
 // line 221, offset 0x800b6660
	/* begin block 1 */
		// Start line: 222
		// Start offset: 0x800B6660
		// Variables:
	// 		struct Extents2d ext; // stack offset -24
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 239
			// Start offset: 0x800B6698
		/* end block 1.1 */
		// End offset: 0x800B6698
		// End Line: 239
	/* end block 1 */
	// End offset: 0x800B677C
	// End Line: 255

	/* begin block 2 */
		// Start line: 458
	/* end block 2 */
	// End Line: 459

void DisplayHintBox(int len,int y)

{
  short x1;
  int x2;
  int y3;
  
  x2 = 0xfb - (len >> 1);
  y3 = y + 0xd;
  x1 = (short)x2;
                    /* WARNING: Subroutine does not return */
  DRAW_TranslucentQuad
            (x1 + -0xe,(short)(y + -1 + y3 >> 1),x1,(short)y3,x2,y + -1,(len >> 1) + 0x105,y3,0,0,0,
             0,gameTrackerX.primPool,gameTrackerX.drawOT + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DisplayMenuBox(int x0 /*$a0*/, int x1 /*$a1*/, int y0 /*$a2*/, int y1 /*$a3*/)
 // line 257, offset 0x800b678c
	/* begin block 1 */
		// Start line: 258
		// Start offset: 0x800B678C
		// Variables:
	// 		struct Extents2d ext; // stack offset -56
	// 		static int dy[16]; // offset 0x0
	// 		int i; // $s3
	// 		int j; // $s6
	// 		int k; // $s2
	// 		int slice0; // $s7
	// 		unsigned long **ot; // $s5
	// 		struct _PrimPool *primPool; // $s4

		/* begin block 1.1 */
			// Start line: 276
			// Start offset: 0x800B682C

			/* begin block 1.1.1 */
				// Start line: 278
				// Start offset: 0x800B683C
			/* end block 1.1.1 */
			// End offset: 0x800B683C
			// End Line: 278
		/* end block 1.1 */
		// End offset: 0x800B6934
		// End Line: 290
	/* end block 1 */
	// End offset: 0x800B699C
	// End Line: 300

	/* begin block 2 */
		// Start line: 552
	/* end block 2 */
	// End Line: 553

void DisplayMenuBox(int x0,int x1,int y0,int y1)

{
  short y0_00;
  int y2;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = x0 + -0xc;
  y2 = y0 + -5;
  y0_00 = (short)y1 + 5;
  if (y1 - y0 < 0x50) {
    piVar1 = &DAT_800d0c70;
    do {
      piVar1 = piVar1 + 1;
      iVar4 = iVar4 + 1;
    } while (y1 - y0 < *piVar1 << 1);
  }
  iVar3 = iVar4 + 1;
  if (iVar4 < 0xf) {
                    /* WARNING: Subroutine does not return */
    DRAW_TranslucentQuad
              ((short)(iVar2 + iVar4),y0_00 - (short)(&DAT_800d0c70)[iVar4],
               (short)iVar2 + (short)iVar3,y0_00 - (short)(&DAT_800d0c70)[iVar3],iVar2 + iVar4,
               y2 + (&DAT_800d0c70)[iVar4],iVar2 + iVar3,y2 + (&DAT_800d0c70)[iVar3],0,0,0,0,
               gameTrackerX.primPool,gameTrackerX.drawOT + 1);
  }
                    /* WARNING: Subroutine does not return */
  DRAW_TranslucentQuad
            ((short)(x0 + 3),y0_00,(short)x1 + -3,y0_00,x0 + 3,y2,x1 + -3,y2,0,0,0,0,
             gameTrackerX.primPool,gameTrackerX.drawOT + 1);
}



// decompiled code
// original method signature: 
// int /*$ra*/ menu_draw_item(struct menu_t *menu /*$a0*/, int ypos /*stack 4*/, int xadj /*stack 8*/, int yadj /*$a3*/, char *text /*stack 16*/, int color /*stack 20*/, long flags /*stack 24*/, struct Extents2d *e /*stack 28*/)
 // line 311, offset 0x800b69cc
	/* begin block 1 */
		// Start line: 312
		// Start offset: 0x800B69CC
		// Variables:
	// 		struct menu_format_t *fmt; // stack offset -64
	// 		int numColumns; // $a1
	// 		int i; // $v1
	// 		int texLen; // $a0
	// 		int columnWidth; // $fp
	// 		char *columnText; // $a1
	// 		char tmpBuff[256]; // stack offset -320
	// 		char *lineText; // $s1
	// 		int columnYPos; // $s5
	// 		int maxColumnYPos; // stack offset -60
	// 		int center; // stack offset -56
	// 		int leftEdge; // stack offset -52
	// 		int xpos; // $s4

		/* begin block 1.1 */
			// Start line: 403
			// Start offset: 0x800B6B94
			// Variables:
		// 		char *eol; // $s6

			/* begin block 1.1.1 */
				// Start line: 410
				// Start offset: 0x800B6BB8
				// Variables:
			// 		char *eop; // $s2

				/* begin block 1.1.1.1 */
					// Start line: 412
					// Start offset: 0x800B6BD0
					// Variables:
				// 		char *tmp; // $s0
				// 		int wd; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x800B6C10
				// End Line: 427

				/* begin block 1.1.1.2 */
					// Start line: 434
					// Start offset: 0x800B6C38
				/* end block 1.1.1.2 */
				// End offset: 0x800B6C78
				// End Line: 440

				/* begin block 1.1.1.3 */
					// Start line: 443
					// Start offset: 0x800B6C80
					// Variables:
				// 		int wd; // $s0
				/* end block 1.1.1.3 */
				// End offset: 0x800B6CD0
				// End Line: 450
			/* end block 1.1.1 */
			// End offset: 0x800B6CE4
			// End Line: 453
		/* end block 1.1 */
		// End offset: 0x800B6CFC
		// End Line: 457
	/* end block 1 */
	// End offset: 0x800B6D9C
	// End Line: 478

	/* begin block 2 */
		// Start line: 733
	/* end block 2 */
	// End Line: 734

int menu_draw_item(menu_t *menu,int ypos,int xadj,int yadj,char *text,int color,long flags,
                  Extents2d *e)

{
                    /* WARNING: Subroutine does not return */
  strlen(text);
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_draw(struct menu_t *menu /*$s3*/)
 // line 481, offset 0x800b6dd0
	/* begin block 1 */
		// Start line: 482
		// Start offset: 0x800B6DD0

		/* begin block 1.1 */
			// Start line: 482
			// Start offset: 0x800B6DD0
			// Variables:
		// 		struct Extents2d ext; // stack offset -48
		// 		struct menu_stack_t *stack; // $s6
		// 		int index; // $s5
		// 		int ypos; // $s2
		// 		int i; // $s0

			/* begin block 1.1.1 */
				// Start line: 496
				// Start offset: 0x800B6E74
				// Variables:
			// 		struct menu_item_t *item; // $t0
			/* end block 1.1.1 */
			// End offset: 0x800B6E74
			// End Line: 496
		/* end block 1.1 */
		// End offset: 0x800B6EF0
		// End Line: 513
	/* end block 1 */
	// End offset: 0x800B6EF0
	// End Line: 514

	/* begin block 2 */
		// Start line: 1118
	/* end block 2 */
	// End Line: 1119

void menu_draw(menu_t *menu)

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
  local_30.xmax = PTR_DAT_800d0cb8;
  local_30.ymin = DAT_800d0cbc;
  local_30.ymax = &DAT_80000000;
  iVar2 = menu->nmenus;
  iVar6 = (&menu->nmenus + iVar2 * 9)[-5];
  ypos = 0;
  if (menu->drawfn != (_func_62 *)0x0) {
    (*menu->drawfn)(menu->opaque);
  }
  iVar4 = 0;
  if (0 < menu->nitems) {
    iVar5 = 0xc0;
    do {
      ppcVar3 = (char **)((int)&menu->nmenus + iVar5);
      iVar5 = iVar5 + 0x10;
      bVar1 = iVar4 != iVar6;
      iVar4 = iVar4 + 1;
      ypos = menu_draw_item(menu,ypos,0,0,*ppcVar3,(uint)bVar1,(long)ppcVar3[3],&local_30);
    } while (iVar4 < menu->nitems);
  }
  if ((&menu->nmenus + iVar2 * 9)[2] != 0) {
    DisplayMenuBox(local_30.xmin,(int)local_30.xmax,local_30.ymin,(int)local_30.ymax);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_run(struct menu_t *menu /*$s2*/)
 // line 520, offset 0x800b6f18
	/* begin block 1 */
		// Start line: 521
		// Start offset: 0x800B6F18
		// Variables:
	// 		enum menu_ctrl_t ctrl; // $s1
	// 		struct menu_stack_t *stack; // $s4
	// 		int index; // $s0
	// 		struct menu_item_t *item; // $s3

		/* begin block 1.1 */
			// Start line: 542
			// Start offset: 0x800B6F80
			// Variables:
		// 		enum menu_sound_t sound; // $v0
		/* end block 1.1 */
		// End offset: 0x800B6FB4
		// End Line: 555
	/* end block 1 */
	// End offset: 0x800B70E8
	// End Line: 584

	/* begin block 2 */
		// Start line: 1220
	/* end block 2 */
	// End Line: 1221

void menu_run(menu_t *menu)

{
  undefined ctrl;
  menu_sound_t sound;
  int iVar1;
  int *piVar2;
  void *gt;
  long menuparam;
  int iVar3;
  
  _ctrl = menu_get_ctrl(menu->opaque);
  ctrl = (undefined)_ctrl;
  piVar2 = &menu->nmenus + menu->nmenus * 9;
  iVar3 = piVar2[-5];
  if ((-1 < iVar3) && (_ctrl != menu_ctrl_none)) {
    menudefs_reset_hack_attract_mode();
    gt = menu->opaque;
    menuparam = menu->items[iVar3].parameter;
    sound = (*menu->items[iVar3].fn)();
    if (sound == menu_sound_none) {
      if (_ctrl == menu_ctrl_down) {
        iVar3 = (iVar3 + 1) % menu->nitems;
        if (menu->items[iVar3].fn == (_func_64 *)0x0) {
          do {
            iVar3 = (iVar3 + 1) % menu->nitems;
          } while (menu->items[iVar3].fn == (_func_64 *)0x0);
          FUN_800b70cc(gt,menuparam,ctrl);
          return;
        }
      }
      else {
        if (_ctrl < menu_ctrl_left) {
          if (_ctrl != menu_ctrl_up) {
            FUN_800b70cc(gt,menuparam,ctrl);
            return;
          }
          iVar1 = menu->nitems;
          iVar3 = (iVar3 + iVar1 + -1) % iVar1;
          if (menu->items[iVar3].fn == (_func_64 *)0x0) {
            do {
              iVar3 = (iVar3 + iVar1 + -1) % iVar1;
            } while (menu->items[iVar3].fn == (_func_64 *)0x0);
            FUN_800b70cc(gt,menuparam,ctrl);
            return;
          }
        }
        else {
          if (_ctrl != menu_ctrl_cancel) {
            FUN_800b70cc(gt,menuparam,ctrl);
            return;
          }
          if (1 < menu->nmenus) {
            menu_sound(menu_sound_pop);
            menu_pop(menu);
          }
        }
      }
      if (iVar3 != piVar2[-5]) {
        menu_sound(menu_sound_select);
      }
      piVar2[-5] = iVar3;
    }
    else {
      menu_sound(sound);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ menu_process(struct menu_t *menu /*$s0*/)
 // line 588, offset 0x800b7108
	/* begin block 1 */
		// Start line: 1360
	/* end block 1 */
	// End Line: 1361

void menu_process(menu_t *menu)

{
  menu_build(menu);
  menu_draw(menu);
  menu_run(menu);
  return;
}





