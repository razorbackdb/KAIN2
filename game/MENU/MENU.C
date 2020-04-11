
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

/* File: C:\kain2\game\MENU\MENU.C */

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

/* File: C:\kain2\game\MENU\MENU.C */

void menu_initialize(menu_t *menu,void *opaque)

{
  memset();
  menu->nmenus = -1;
  menu->opaque = opaque;
  return;
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

/* File: C:\kain2\game\MENU\MENU.C */

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

/* File: C:\kain2\game\MENU\MENU.C */

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

/* File: C:\kain2\game\MENU\MENU.C */

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

/* File: C:\kain2\game\MENU\MENU.C */

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

/* File: C:\kain2\game\MENU\MENU.C */

void menu_item_flags(menu_t *menu,TDRFuncPtr_menu_item_flags1fn fn,long parameter,long flags,
                    char *format)

{
  int iVar1;
  int iVar2;
  menu_item_t *pmVar3;
  
  pmVar3 = menu->items + menu->nitems;
  menu->nitems = menu->nitems + 1;
  *(TDRFuncPtr_menu_item_flags1fn *)&pmVar3->fn = fn;
  pmVar3->parameter = parameter;
  iVar1 = menu->nbytes;
  pmVar3->flags = flags;
  pmVar3->text = menu->bytes + iVar1;
  vsprintf(menu->bytes + iVar1,format,&stack0x00000014);
  iVar2 = menu->nbytes;
  iVar1 = strlen();
  menu->nbytes = iVar2 + 1 + iVar1;
  return;
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

/* File: C:\kain2\game\MENU\MENU.C */

void menu_item(menu_t *menu,TDRFuncPtr_menu_item1fn fn,long parameter,char *format)

{
  int iVar1;
  int iVar2;
  menu_item_t *pmVar3;
  
  pmVar3 = menu->items + menu->nitems;
  menu->nitems = menu->nitems + 1;
  *(TDRFuncPtr_menu_item1fn *)&pmVar3->fn = fn;
  pmVar3->parameter = parameter;
  iVar1 = menu->nbytes;
  pmVar3->flags = 0;
  pmVar3->text = menu->bytes + iVar1;
  if (format == (char *)0x0) {
    pmVar3->text = (char *)0x0;
  }
  else {
    vsprintf(menu->bytes + iVar1,format,&stack0x00000010);
    iVar2 = menu->nbytes;
    iVar1 = strlen();
    menu->nbytes = iVar2 + 1 + iVar1;
  }
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

/* File: C:\kain2\game\MENU\MENU.C */

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

/* File: C:\kain2\game\MENU\MENU.C */

void DisplayHintBox(int len,int y)

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
  do {
    x1 = (short)(0xfb - len);
    DRAW_TranslucentQuad
              (x1 + -0xe,(short)(y2 + y >> 1),x1,(short)y,0xfb - len,y2,x3,y,0,0,0,0,DAT_800d210c,
               (ulong **)(DAT_800d22a4 + 4));
    iVar1 = iVar1 + 1;
    DRAW_TranslucentQuad
              (x1,(short)y2,(short)x3,(short)y,x3,y2,len + 0x113,y2 + y >> 1,0,0,0,0,DAT_800d210c,
               (ulong **)(DAT_800d22a4 + 4));
  } while (iVar1 < 2);
  return;
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

/* File: C:\kain2\game\MENU\MENU.C */

void DisplayMenuBox(int x0,int x1,int y0,int y1)

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
  ulong **ot;
  int iVar7;
  int iVar8;
  
  primPool = DAT_800d210c;
  iVar8 = 0;
  iVar3 = x0 + -0xc;
  iVar4 = x1 + 0xc;
  y2 = y0 + -5;
  y0_00 = (short)y1 + 5;
  ot = (ulong **)(DAT_800d22a4 + 4);
  if (y1 - y0 < DAT_800d0c70 << 1) {
    piVar2 = &DAT_800d0c70;
    do {
      piVar2 = piVar2 + 1;
      iVar8 = iVar8 + 1;
    } while (y1 - y0 < *piVar2 << 1);
  }
  iVar7 = 0;
  do {
    iVar1 = iVar8;
    while (iVar1 < 0xf) {
      iVar6 = iVar1 + 1;
      piVar2 = &DAT_800d0c70 + iVar1;
      piVar5 = &DAT_800d0c70 + iVar6;
      DRAW_TranslucentQuad
                ((short)(iVar3 + iVar1),y0_00 - (short)*piVar2,(short)iVar3 + (short)iVar6,
                 y0_00 - (short)*piVar5,iVar3 + iVar1,y2 + *piVar2,iVar3 + iVar6,y2 + *piVar5,0,0,0,
                 0,primPool,ot);
      DRAW_TranslucentQuad
                ((short)(iVar4 - iVar1),y0_00 - (short)*piVar2,(short)iVar4 - (short)iVar6,
                 y0_00 - (short)*piVar5,iVar4 - iVar1,y2 + *piVar2,iVar4 - iVar6,y2 + *piVar5,0,0,0,
                 0,primPool,ot);
      iVar1 = iVar6;
    }
    iVar7 = iVar7 + 1;
    DRAW_TranslucentQuad
              ((short)(x0 + 3),y0_00,(short)iVar4 + -0xf,y0_00,x0 + 3,y2,x1 + -3,y2,0,0,0,0,primPool
               ,ot);
  } while (iVar7 < 2);
  return;
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

/* File: C:\kain2\game\MENU\MENU.C */

int menu_draw_item(menu_t *menu,int ypos,int xadj,int yadj,char *text,int color,long flags,
                  Extents2d *e)

{
  int *piVar1;
  int xpos;
  char *text_00;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int ypos_00;
  int iVar6;
  int xpos_00;
  char acStack320 [256];
  int *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  local_3c = 0;
  piVar1 = &menu->nmenus + menu->nmenus * 9;
  local_40 = piVar1 + -4;
  local_38 = 1;
  if (((flags & 1U) == 0) && (local_38 = 0, (flags & 2U) == 0)) {
    local_38 = piVar1[1];
  }
  if (ypos == 0) {
    ypos = piVar1[-3];
  }
  ypos = ypos + yadj;
  xpos = strlen();
  iVar6 = 1;
  ypos_00 = 0;
  text_00 = text;
  if (0 < xpos) {
    do {
      if (*text_00 == '\t') {
        iVar6 = iVar6 + 1;
      }
      ypos_00 = ypos_00 + 1;
      text_00 = text + ypos_00;
    } while (ypos_00 < xpos);
  }
  iVar6 = local_40[4] / iVar6;
  if (local_40[5] == 0) {
    local_34 = *local_40 + xadj;
  }
  else {
    local_34 = (*local_40 + xadj) - (local_40[4] >> 1);
  }
  text_00 = strtok(text,&LAB_800d0cb0);
  if (text_00 != (char *)0x0) {
    local_30 = 0;
    do {
      xpos = local_34 + xadj + local_30;
      if (local_38 != 0) {
        xpos = xpos + (iVar6 >> 1);
      }
      if (ypos < e->ymin) {
        e->ymin = ypos;
      }
      strcpy();
      text_00 = acStack320;
      ypos_00 = ypos;
      do {
        pcVar2 = strchr(text_00,'\n');
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
        while (text_00 != (char *)0x0) {
          pcVar3 = strchr(text_00,' ');
          if (pcVar3 != (char *)0x0) {
            do {
              pcVar4 = strchr(pcVar3 + 1,' ');
              if (pcVar4 != (char *)0x0) {
                *pcVar4 = '\0';
              }
              iVar5 = menu_text_width(text_00);
              if (pcVar4 != (char *)0x0) {
                *pcVar4 = ' ';
              }
            } while ((iVar5 <= iVar6) && (pcVar3 = pcVar4, pcVar4 != (char *)0x0));
            if (pcVar3 != (char *)0x0) {
              *pcVar3 = '\0';
            }
          }
          if (local_38 == 0) {
            iVar5 = menu_text_width(text_00);
            menu_print(xpos,ypos_00,text_00,color);
            if (xpos < e->xmin) {
              e->xmin = xpos;
            }
            xpos_00 = e->xmax;
          }
          else {
            iVar5 = menu_text_width(text_00);
            iVar5 = iVar5 >> 1;
            xpos_00 = xpos - iVar5;
            menu_print(xpos_00,ypos_00,text_00,color);
            if (xpos_00 < e->xmin) {
              e->xmin = xpos_00;
            }
            xpos_00 = e->xmax;
          }
          if (xpos_00 < xpos + iVar5) {
            e->xmax = xpos + iVar5;
          }
          ypos_00 = ypos_00 + local_40[2];
          if (pcVar3 == (char *)0x0) break;
          text_00 = pcVar3 + 1;
          *pcVar3 = ' ';
        }
        if (pcVar2 == (char *)0x0) break;
        text_00 = pcVar2 + 1;
        *pcVar2 = '\n';
      } while (text_00 != (char *)0x0);
      local_30 = local_30 + iVar6;
      text_00 = strtok((char *)0x0,&LAB_800d0cb0);
      if (local_3c < ypos_00) {
        local_3c = ypos_00;
      }
    } while (text_00 != (char *)0x0);
  }
  if (e->ymax < local_3c) {
    e->ymax = local_3c;
  }
  local_3c = local_3c + local_40[3];
  if ((flags & 4U) != 0) {
    local_3c = local_3c + (local_40[2] >> 1);
  }
  return local_3c;
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

/* File: C:\kain2\game\MENU\MENU.C */

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
  
  local_30.xmin = DAT_800d0cb4;
  local_30.xmax = PTR_DAT_800d0cb8;
  local_30.ymin = DAT_800d0cbc;
  local_30.ymax = PTR_DAT_800d0cc0;
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

/* File: C:\kain2\game\MENU\MENU.C */

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
  if ((-1 < iVar5) && (mVar1 != menu_ctrl_none)) {
    menudefs_reset_hack_attract_mode();
    sound = (*menu->items[iVar5].fn)(menu->opaque,menu->items[iVar5].parameter,mVar1);
    if (sound == menu_sound_none) {
      if (mVar1 == menu_ctrl_down) {
        iVar5 = (iVar5 + 1) % menu->nitems;
        p_Var2 = menu->items[iVar5].fn;
        while (p_Var2 == (_func_64 *)0x0) {
          iVar5 = (iVar5 + 1) % menu->nitems;
          p_Var2 = menu->items[iVar5].fn;
        }
      }
      else {
        if (mVar1 < menu_ctrl_left) {
          if (mVar1 == menu_ctrl_up) {
            iVar3 = menu->nitems;
            iVar5 = (iVar5 + iVar3 + -1) % iVar3;
            p_Var2 = menu->items[iVar5].fn;
            while (p_Var2 == (_func_64 *)0x0) {
              iVar5 = (iVar5 + iVar3 + -1) % iVar3;
              p_Var2 = menu->items[iVar5].fn;
            }
          }
        }
        else {
          if ((mVar1 == menu_ctrl_cancel) && (1 < menu->nmenus)) {
            menu_sound(menu_sound_pop);
            menu_pop(menu);
          }
        }
      }
      if (iVar5 != piVar4[-5]) {
        menu_sound(menu_sound_select);
      }
      piVar4[-5] = iVar5;
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

/* File: C:\kain2\game\MENU\MENU.C */

void menu_process(menu_t *menu)

{
  menu_build(menu);
  menu_draw(menu);
  menu_run(menu);
  return;
}





