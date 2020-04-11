
#include "GLYPH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GlyphInit(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 121, offset 0x8007a22c
	/* begin block 1 */
		// Start line: 122
		// Start offset: 0x8007A22C
		// Variables:
	// 		struct __GlyphData *data; // $s1
	/* end block 1 */
	// End offset: 0x8007A318
	// End Line: 165

	/* begin block 2 */
		// Start line: 242
	/* end block 2 */
	// End Line: 243

/* File: C:\kain2\game\GLYPH.C */

void GlyphInit(_Instance *instance,GameTracker *gameTracker)

{
  undefined4 *puVar1;
  
  if ((instance->flags & 0x20000U) == 0) {
    puVar1 = (undefined4 *)MEMPACK_Malloc(0x9c,'\x1d');
    *(undefined4 **)&instance->extraData = puVar1;
    InitMessageQueue((__MessageQueue *)(puVar1 + 1));
    EnMessageQueueData((__MessageQueue *)(puVar1 + 1),(int)&DAT_00100001,0);
    *puVar1 = 0x8007ac68;
    *(undefined2 *)(puVar1 + 0x23) = 7;
    *(undefined2 *)(puVar1 + 0x26) = 0xdb6;
    *(undefined2 *)(puVar1 + 0x24) = 0;
    glyph_time = 0;
    *(undefined2 *)((int)puVar1 + 0x92) = 0;
    *(undefined2 *)(puVar1 + 0x25) = 0;
    *(undefined2 *)((int)puVar1 + 0x9a) = 1;
    *(undefined2 *)((int)puVar1 + 0x8e) = 0;
    glyph_trigger = 0;
    fx_blastring = 0;
    fx_going = 0;
    *(short *)((int)puVar1 + 0x96) = (*(short *)(puVar1 + 0x23) + -1) * 0x249;
    glyph_cost = -1;
    instance->flags = instance->flags | 0x10800;
  }
  else {
    MEMPACK_Free((char *)instance->extraData);
  }
  HUD_Init();
  MANNA_Position = -0x40;
  MANNA_Pos_vel = 0;
  MANNA_Pickup_Time = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphCollide(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 174, offset 0x8007a348
	/* begin block 1 */
		// Start line: 388
	/* end block 1 */
	// End Line: 389

	/* begin block 2 */
		// Start line: 390
	/* end block 2 */
	// End Line: 391

/* File: C:\kain2\game\GLYPH.C */

void GlyphCollide(_Instance *instance,GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 181, offset 0x8007a350
	/* begin block 1 */
		// Start line: 182
		// Start offset: 0x8007A350
		// Variables:
	// 		struct __GlyphData *data; // $v0
	/* end block 1 */
	// End offset: 0x8007A350
	// End Line: 182

	/* begin block 2 */
		// Start line: 402
	/* end block 2 */
	// End Line: 403

/* File: C:\kain2\game\GLYPH.C */

void GlyphProcess(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  long lVar2;
  
  (**(code **)instance->extraData)(instance,0,0);
  sVar1 = (instance->parent->position).z;
  *(undefined4 *)&instance->oldPos = *(undefined4 *)&instance->parent->position;
  (instance->oldPos).z = sVar1;
  sVar1 = (instance->oldPos).z;
  *(undefined4 *)&instance->position = *(undefined4 *)&instance->oldPos;
  (instance->position).z = sVar1;
  lVar2 = instance->parent->currentStreamUnitID;
  instance->flags = instance->flags | 0xc00;
  instance->currentStreamUnitID = lVar2;
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ GlyphQuery(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 211, offset 0x8007a3d8
	/* begin block 1 */
		// Start line: 465
	/* end block 1 */
	// End Line: 466

	/* begin block 2 */
		// Start line: 466
	/* end block 2 */
	// End Line: 467

/* File: C:\kain2\game\GLYPH.C */

ulong GlyphQuery(_Instance *instance,ulong query)

{
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphPost(struct _Instance *instance /*$a0*/, unsigned long message /*$a1*/, unsigned long messageData /*$a2*/)
 // line 228, offset 0x8007a3f8
	/* begin block 1 */
		// Start line: 229
		// Start offset: 0x8007A3F8
		// Variables:
	// 		struct __GlyphData *data; // $a0
	/* end block 1 */
	// End offset: 0x8007A41C
	// End Line: 246

	/* begin block 2 */
		// Start line: 499
	/* end block 2 */
	// End Line: 500

/* File: C:\kain2\game\GLYPH.C */

void GlyphPost(_Instance *instance,ulong message,ulong messageData)

{
  if ((undefined *)message != &DAT_00100007) {
    EnMessageQueueData((__MessageQueue *)((int)instance->extraData + 4),message,messageData);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphSwitchProcess(struct _Instance *instance /*$s1*/, TDRFuncPtr__GlyphSwitchProcess1process process /*$s3*/)
 // line 256, offset 0x8007a42c
	/* begin block 1 */
		// Start line: 257
		// Start offset: 0x8007A42C
		// Variables:
	// 		struct __GlyphData *data; // $s2
	/* end block 1 */
	// End offset: 0x8007A42C
	// End Line: 257

	/* begin block 2 */
		// Start line: 564
	/* end block 2 */
	// End Line: 565

/* File: C:\kain2\game\GLYPH.C */

void _GlyphSwitchProcess(_Instance *instance,TDRFuncPtr__GlyphSwitchProcess1process process)

{
  __MessageQueue *In;
  TDRFuncPtr__GlyphSwitchProcess1process *ppTVar1;
  
  ppTVar1 = (TDRFuncPtr__GlyphSwitchProcess1process *)instance->extraData;
  In = (__MessageQueue *)(ppTVar1 + 1);
  PurgeMessageQueue(In);
  EnMessageQueueData(In,(int)&DAT_00100004,0);
  (**ppTVar1)(instance,0,0);
  EnMessageQueueData(In,(int)&DAT_00100001,0);
  *ppTVar1 = process;
  (*process)(instance,0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GlyphIsGlyphOpen(struct _Instance *instance /*$a0*/)
 // line 277, offset 0x8007a4cc
	/* begin block 1 */
		// Start line: 279
		// Start offset: 0x8007A4CC
		// Variables:
	// 		struct __GlyphData *data; // $v0
	/* end block 1 */
	// End offset: 0x8007A4CC
	// End Line: 282

	/* begin block 2 */
		// Start line: 610
	/* end block 2 */
	// End Line: 611

	/* begin block 3 */
		// Start line: 611
	/* end block 3 */
	// End Line: 612

	/* begin block 4 */
		// Start line: 614
	/* end block 4 */
	// End Line: 615

/* File: C:\kain2\game\GLYPH.C */

int GlyphIsGlyphOpen(_Instance *instance)

{
  return (int)*(short *)((int)instance->extraData + 0x8e);
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsGlyphSet(int glyph /*$s0*/)
 // line 290, offset 0x8007a4e0
	/* begin block 1 */
		// Start line: 636
	/* end block 1 */
	// End Line: 637

/* File: C:\kain2\game\GLYPH.C */

int _GlyphIsGlyphSet(int glyph)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(DAT_800d20f8,0x24);
  return 1 << (glyph + 0x11U & 0x1f) & uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsGlyphUsable(int glyph /*$s0*/)
 // line 294, offset 0x8007a51c
	/* begin block 1 */
		// Start line: 645
	/* end block 1 */
	// End Line: 646

/* File: C:\kain2\game\GLYPH.C */

int _GlyphIsGlyphUsable(int glyph)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(DAT_800d20f8,0x13);
  return 1 << (glyph + 0x11U & 0x1f) & uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsAnyGlyphSet()
 // line 298, offset 0x8007a558
	/* begin block 1 */
		// Start line: 654
	/* end block 1 */
	// End Line: 655

/* File: C:\kain2\game\GLYPH.C */

int _GlyphIsAnyGlyphSet(void)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(DAT_800d20f8,0x24);
  return uVar1 & 0x1fc0000;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphCost(struct _GlyphTuneData *glyphtunedata /*$a0*/, int glyphNum /*$a1*/)
 // line 303, offset 0x8007a580
	/* begin block 1 */
		// Start line: 665
	/* end block 1 */
	// End Line: 666

	/* begin block 2 */
		// Start line: 666
	/* end block 2 */
	// End Line: 667

/* File: C:\kain2\game\GLYPH.C */

int _GlyphCost(_GlyphTuneData *glyphtunedata,int glyphNum)

{
  return (uint)*(byte *)((int)&glyphtunedata->glyph_darkness + glyphNum + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphDefaultProcess(struct _Instance *instance /*$s1*/, int data1 /*$a1*/, int data2 /*$a2*/)
 // line 316, offset 0x8007a590
	/* begin block 1 */
		// Start line: 317
		// Start offset: 0x8007A590
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $v0
	/* end block 1 */
	// End offset: 0x8007A60C
	// End Line: 337

	/* begin block 2 */
		// Start line: 691
	/* end block 2 */
	// End Line: 692

/* File: C:\kain2\game\GLYPH.C */

void _GlyphDefaultProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  __MessageQueue *In;
  
  In = (__MessageQueue *)((int)instance->extraData + 4);
  while (p_Var1 = PeekMessageQueue(In), p_Var1 != (__Event *)0x0) {
    if ((undefined *)p_Var1->ID == &DAT_80000010) {
      _GlyphSwitchProcess(instance,_GlyphSelectProcess);
      SndPlayVolPan(0x11,0x7f,0x40,0);
    }
    DeMessageQueue(In);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_GetPlayerScreenPt(struct DVECTOR *center /*$s0*/)
 // line 339, offset 0x8007a628
	/* begin block 1 */
		// Start line: 340
		// Start offset: 0x8007A628
		// Variables:
	// 		struct _Position position; // stack offset -16
	/* end block 1 */
	// End offset: 0x8007A628
	// End Line: 340

	/* begin block 2 */
		// Start line: 745
	/* end block 2 */
	// End Line: 746

/* File: C:\kain2\game\GLYPH.C */

void HUD_GetPlayerScreenPt(undefined center)

{
  undefined4 uVar1;
  undefined4 in_zero;
  undefined4 in_at;
  undefined3 in_register_00000011;
  uint local_c;
  
  PushMatrix();
  SetRotMatrix(DAT_800d0ffc);
  SetTransMatrix(DAT_800d0ffc);
  local_c = local_c & 0xffff0000 | (uint)(ushort)(*(short *)(DAT_800d20f8 + 0x60) + 0x1c0);
  setCopReg(2,in_zero,*(undefined4 *)(DAT_800d20f8 + 0x5c));
  setCopReg(2,in_at,local_c);
  copFunction(2,0x180001);
  uVar1 = getCopReg(2,0xe);
  *(undefined4 *)CONCAT31(in_register_00000011,center) = uVar1;
  PopMatrix();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphDrawMenu(struct _Instance *instance /*stack 0*/)
 // line 357, offset 0x8007a6b8
	/* begin block 1 */
		// Start line: 358
		// Start offset: 0x8007A6B8
		// Variables:
	// 		struct _Position place; // stack offset -72
	// 		struct DVECTOR center; // stack offset -64
	// 		int n; // $s5
	// 		int rot; // $s3
	// 		int radius; // $s6
	// 		int glyph_rotation_speed; // $s0
	// 		int MANNA_Count; // $fp
	// 		struct __GlyphData *data; // $s4
	// 		struct _GlyphTuneData *glyphtunedata; // $s7

		/* begin block 1.1 */
			// Start line: 380
			// Start offset: 0x8007A724
			// Variables:
		// 		int diff; // $v0
		/* end block 1.1 */
		// End offset: 0x8007A788
		// End Line: 396

		/* begin block 1.2 */
			// Start line: 407
			// Start offset: 0x8007A7B8
			// Variables:
		// 		int enabled; // $v1
		// 		int scale_modify; // $s2
		// 		int num; // $s1
		/* end block 1.2 */
		// End offset: 0x8007A8F8
		// End Line: 449

		/* begin block 1.3 */
			// Start line: 458
			// Start offset: 0x8007A960
			// Variables:
		// 		struct _Vector f1; // stack offset -56
		/* end block 1.3 */
		// End offset: 0x8007A9BC
		// End Line: 474

		/* begin block 1.4 */
			// Start line: 479
			// Start offset: 0x8007A9BC
		/* end block 1.4 */
		// End offset: 0x8007A9BC
		// End Line: 481
	/* end block 1 */
	// End offset: 0x8007A9BC
	// End Line: 481

	/* begin block 2 */
		// Start line: 781
	/* end block 2 */
	// End Line: 782

	/* begin block 3 */
		// Start line: 797
	/* end block 3 */
	// End Line: 798

/* File: C:\kain2\game\GLYPH.C */

void GlyphDrawMenu(_Instance *instance)

{
  short current;
  ushort uVar1;
  ulong uVar2;
  int iVar3;
  int glyphnum;
  uint enabled;
  uint a;
  int glyph;
  int iVar4;
  void *pvVar5;
  int iVar6;
  _GlyphTuneData *glyphtunedata;
  _Position local_48;
  short local_40;
  short local_3e;
  _Vector local_38;
  
  a = (uint)(DAT_800d2314 << 6) >> 0xc;
  pvVar5 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  uVar2 = INSTANCE_Query(DAT_800d20f8,0x20);
  if (*(short *)((int)pvVar5 + 0x98) != *(short *)((int)pvVar5 + 0x96)) {
    current = AngleDiff(*(short *)((int)pvVar5 + 0x98),*(short *)((int)pvVar5 + 0x96));
    iVar3 = (int)current;
    if (iVar3 < 0) {
      iVar3 = -iVar3;
    }
    if ((int)a < iVar3) {
      current = (short)a;
      if (*(short *)((int)pvVar5 + 0x9a) < 1) {
        uVar1 = *(short *)((int)pvVar5 + 0x96) - current;
      }
      else {
        uVar1 = *(short *)((int)pvVar5 + 0x96) + current;
      }
      *(ushort *)((int)pvVar5 + 0x96) = uVar1 & 0xfff;
    }
    else {
      *(undefined2 *)((int)pvVar5 + 0x96) = *(undefined2 *)((int)pvVar5 + 0x98);
    }
  }
  HUD_GetPlayerScreenPt(0xc0);
  if (local_3e < 0x48) {
    local_3e = 0x48;
  }
  iVar6 = 0;
  iVar3 = (int)*(short *)((int)pvVar5 + 0x92);
  a = (int)*(short *)((int)pvVar5 + 0x96) + 0xc00;
  do {
    a = a & 0xfff;
    current = (short)a;
    uVar1 = AngleDiff(current,0xc00);
    if ((int)((uint)uVar1 << 0x10) < 0) {
      uVar1 = AngleDiff(current,0xc00);
      iVar4 = (int)((uint)uVar1 << 0x10) >> 0xf;
    }
    else {
      uVar1 = AngleDiff(current,0xc00);
      iVar4 = -((int)((uint)uVar1 << 0x10) >> 0xf);
    }
    iVar4 = iVar4 + 0x1000;
    if (iVar4 < 0x600) {
      iVar4 = 0x600;
    }
    iVar4 = *(short *)((int)pvVar5 + 0x94) * iVar4;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0xfff;
    }
    glyphnum = rcos(a);
    local_48.x = local_40 + (short)(glyphnum * iVar3 >> 0xc);
    glyphnum = rsin(a);
    glyphnum = glyphnum * iVar3 >> 0xc;
    glyph = iVar6 + 1;
    if (glyphnum < 0) {
      glyphnum = glyphnum + 7;
    }
    local_48.y = local_3e - (short)(glyphnum >> 3);
    glyphnum = _GlyphIsGlyphSet(glyph);
    if (glyphnum == 0) {
      glyphnum = 7;
      if (glyph == 7) goto LAB_8007a8d8;
      enabled = 1;
    }
    else {
      glyphnum = _GlyphIsGlyphUsable(glyph);
      if (glyphnum == 0) {
LAB_8007a8d8:
        enabled = 0;
        glyphnum = iVar6;
      }
      else {
        glyphnum = _GlyphCost(glyphtunedata,glyph);
        enabled = (uint)((int)uVar2 < glyphnum) ^ 1;
        glyphnum = iVar6;
      }
    }
    iVar4 = (int)glyphtunedata->glyph_size * (iVar4 >> 0xc);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x1fff;
    }
    a = a - 0x249;
    iVar6 = iVar6 + 1;
    FX_MakeGlyphIcon(&local_48,instance->object,iVar4 >> 0xd,glyphnum,enabled);
    if (6 < iVar6) {
      iVar6 = (int)*(short *)((int)pvVar5 + 0x90);
      if (iVar6 == 0x1000) {
        if ((*(short *)((int)pvVar5 + 0x98) == *(short *)((int)pvVar5 + 0x96)) &&
           (iVar6 = _GlyphCost(glyphtunedata,(int)*(short *)((int)pvVar5 + 0x8c)),
           iVar6 <= (int)uVar2)) {
          local_38.x = (int)local_40;
          if (iVar3 < 0) {
            iVar3 = iVar3 + 7;
          }
          local_38.y = (int)local_3e + (iVar3 >> 3);
          DRAW_CreateAGlowingCircle
                    (&local_38,0x140,DAT_800d210c,DAT_800d22a4,5,0x1404040,0x1a,0x18,0);
        }
        iVar6 = (int)*(short *)((int)pvVar5 + 0x90);
      }
      a = iVar6 / (int)glyphtunedata->glyph_darkness;
      FX_DrawScreenPoly(2,a | a << 0x10 | a << 8,0x20);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ GlyphTime(int time /*$a0*/)
 // line 487, offset 0x8007aa1c
	/* begin block 1 */
		// Start line: 1178
	/* end block 1 */
	// End Line: 1179

	/* begin block 2 */
		// Start line: 1179
	/* end block 2 */
	// End Line: 1180

/* File: C:\kain2\game\GLYPH.C */

long GlyphTime(int time)

{
  time = time * time;
  if (time < 0) {
    time = time + 0xfff;
  }
  return time >> 0xc;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ShrinkGlyphMenu(struct _Instance *instance /*$s1*/)
 // line 494, offset 0x8007aa38
	/* begin block 1 */
		// Start line: 495
		// Start offset: 0x8007AA38
		// Variables:
	// 		struct __GlyphData *data; // $s0
	// 		int time; // $a0
	// 		short accl; // stack offset -24
	/* end block 1 */
	// End offset: 0x8007AB4C
	// End Line: 533

	/* begin block 2 */
		// Start line: 1192
	/* end block 2 */
	// End Line: 1193

/* File: C:\kain2\game\GLYPH.C */

void ShrinkGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24 [4];
  
  pvVar3 = instance->extraData;
  DAT_800d2210 = DAT_800d2210 & 0xffefffff;
  if (*(short *)((int)pvVar3 + 0x90) < 1) {
    glyph_cost = -1;
  }
  else {
    iVar1 = (uint)*(ushort *)((int)pvVar3 + 0x90) - ((uint)(DAT_800d2314 << 9) >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x90) = (short)iVar1;
    if (iVar1 * 0x10000 < 0) {
      *(undefined2 *)((int)pvVar3 + 0x90) = 0;
    }
    glyph_time = *(short *)((int)pvVar3 + 0x90);
    lVar2 = GlyphTime((int)*(short *)((int)pvVar3 + 0x90));
    iVar1 = lVar2 * 0x96;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    *(undefined2 *)((int)pvVar3 + 0x92) = (short)(iVar1 >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x94) = (short)lVar2;
    if (0 < *(short *)((int)pvVar3 + 0x90)) {
      GlyphDrawMenu(instance);
    }
  }
  if (MANNA_Pickup_Time < 1) {
    CriticalDampValue(5,&MANNA_Position,-0x40,&MANNA_Pos_vel,asStack24,0xc);
    *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
  }
  else {
    MANNA_Pickup_Time = MANNA_Pickup_Time - DAT_800d2314;
    *(undefined2 *)((int)pvVar3 + 0x8e) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EnlargeGlyphMenu(struct _Instance *instance /*$s1*/)
 // line 536, offset 0x8007ab64
	/* begin block 1 */
		// Start line: 537
		// Start offset: 0x8007AB64
		// Variables:
	// 		struct __GlyphData *data; // $s0
	// 		int time; // $a1
	// 		short accl; // stack offset -24
	/* end block 1 */
	// End offset: 0x8007AC0C
	// End Line: 560

	/* begin block 2 */
		// Start line: 1291
	/* end block 2 */
	// End Line: 1292

/* File: C:\kain2\game\GLYPH.C */

void EnlargeGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24 [4];
  
  pvVar3 = instance->extraData;
  DAT_800d2210 = DAT_800d2210 | 0x100000;
  if (*(short *)((int)pvVar3 + 0x90) < 0x1000) {
    iVar1 = (uint)*(ushort *)((int)pvVar3 + 0x90) + ((uint)(DAT_800d2314 << 9) >> 0xc);
    *(undefined2 *)((int)pvVar3 + 0x90) = (short)iVar1;
    if (0x1000 < iVar1 * 0x10000 >> 0x10) {
      *(undefined2 *)((int)pvVar3 + 0x90) = 0x1000;
    }
    glyph_time = *(short *)((int)pvVar3 + 0x90);
  }
  lVar2 = GlyphTime((int)*(short *)((int)pvVar3 + 0x90));
  iVar1 = lVar2 * 0x96;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0xfff;
  }
  *(undefined2 *)((int)pvVar3 + 0x92) = (short)(iVar1 >> 0xc);
  *(undefined2 *)((int)pvVar3 + 0x94) = (short)lVar2;
  GlyphDrawMenu(instance);
  MANNA_Pickup_Time = 0;
  CriticalDampValue(5,&MANNA_Position,0x24,&MANNA_Pos_vel,asStack24,0xc);
  *(undefined2 *)((int)pvVar3 + 0x8e) = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphOffProcess(struct _Instance *instance /*$s0*/, int data1 /*$s3*/, int data2 /*$s4*/)
 // line 573, offset 0x8007ac68
	/* begin block 1 */
		// Start line: 574
		// Start offset: 0x8007AC68
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $s2
	/* end block 1 */
	// End offset: 0x8007AD38
	// End Line: 601

	/* begin block 2 */
		// Start line: 1378
	/* end block 2 */
	// End Line: 1379

/* File: C:\kain2\game\GLYPH.C */

void _GlyphOffProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  undefined *puVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  ShrinkGlyphMenu(instance);
  do {
    p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
    if (p_Var1 == (__Event *)0x0) {
      Glyph_DoFX(instance);
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 != &DAT_00100001) {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == &DAT_80000010) {
          _GlyphSwitchProcess(instance,_GlyphSelectProcess);
          SndPlayVolPan(0x11,0x7f,0x40,0);
        }
        else {
LAB_8007ad20:
          _GlyphDefaultProcess(instance,data1,data2);
        }
      }
      else {
        if (puVar2 != &DAT_00100004) goto LAB_8007ad20;
      }
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphSelectProcess(struct _Instance *instance /*$s3*/, int data1 /*$s6*/, int data2 /*$s7*/)
 // line 606, offset 0x8007ad60
	/* begin block 1 */
		// Start line: 607
		// Start offset: 0x8007AD60
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $s1
	// 		struct _GlyphTuneData *glyphtunedata; // $s4
	// 		int dontdraw_flag; // $s2

		/* begin block 1.1 */
			// Start line: 678
			// Start offset: 0x8007B148
			// Variables:
		// 		int MANNA_Count; // $s0
		/* end block 1.1 */
		// End offset: 0x8007B19C
		// End Line: 687
	/* end block 1 */
	// End offset: 0x8007B1F4
	// End Line: 710

	/* begin block 2 */
		// Start line: 1444
	/* end block 2 */
	// End Line: 1445

/* File: C:\kain2\game\GLYPH.C */

void _GlyphSelectProcess(_Instance *instance,int data1,int data2)

{
  bool bVar1;
  ushort vol;
  short sVar2;
  __Event *p_Var3;
  int iVar4;
  ulong uVar5;
  undefined *puVar6;
  uint sample;
  void *pvVar7;
  _GlyphTuneData *glyphtunedata;
  
  bVar1 = false;
  pvVar7 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  do {
    p_Var3 = PeekMessageQueue((__MessageQueue *)((int)pvVar7 + 4));
    if (p_Var3 == (__Event *)0x0) {
      if (!bVar1) {
        iVar4 = _GlyphCost(glyphtunedata,(int)*(short *)((int)pvVar7 + 0x8c));
        glyph_cost = (short)iVar4;
        EnlargeGlyphMenu(instance);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar6 = (undefined *)p_Var3->ID;
    if (puVar6 == &DAT_00100001) {
      bVar1 = true;
      *(undefined2 *)((int)pvVar7 + 0x8c) = 7;
      *(undefined2 *)((int)pvVar7 + 0x98) = 0xdb6;
      *(short *)((int)pvVar7 + 0x96) = (*(short *)((int)pvVar7 + 0x8c) + -1) * 0x249;
      *(undefined2 *)((int)pvVar7 + 0x96) = *(undefined2 *)((int)pvVar7 + 0x98);
      goto LAB_8007b1c4;
    }
    if ((int)puVar6 < 0x100002) {
      if (puVar6 == (undefined *)0x80000000) {
        sample = 0x10;
        if (fx_going == 0) {
          iVar4 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar7 + 0x8c));
          sample = 0x10;
          if (iVar4 != 0) {
            uVar5 = INSTANCE_Query(DAT_800d20f8,0x20);
            iVar4 = _GlyphCost(glyphtunedata,(int)*(short *)((int)pvVar7 + 0x8c));
            sample = 0x10;
            if (iVar4 <= (int)uVar5) {
              iVar4 = _GlyphIsGlyphUsable((int)*(short *)((int)pvVar7 + 0x8c));
              if (iVar4 != 0) {
                bVar1 = true;
                _GlyphSwitchProcess(instance,_GlyphGenericProcess);
                goto LAB_8007b1c4;
              }
              sample = 0x10;
            }
          }
        }
LAB_8007b1a0:
        vol = 100;
      }
      else {
        if (puVar6 != &DAT_80000010) goto LAB_8007b1bc;
        bVar1 = true;
        _GlyphSwitchProcess(instance,_GlyphOffProcess);
        sample = 0xf;
        vol = 0x7f;
      }
LAB_8007b1a4:
      SndPlayVolPan(sample,vol,0x40,0);
    }
    else {
      if (puVar6 == (undefined *)0x10000002) {
        iVar4 = _GlyphIsAnyGlyphSet();
        if (iVar4 != 0) {
          vol = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
          if ((int)((uint)vol << 0x10) < 0) {
            sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
            if (-(int)sVar2 < 0x40) goto LAB_8007b054;
          }
          else {
            sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
            if (sVar2 < 0x40) {
LAB_8007b054:
              do {
                *(short *)((int)pvVar7 + 0x8c) = *(short *)((int)pvVar7 + 0x8c) + 1;
                *(undefined2 *)((int)pvVar7 + 0x9a) = 1;
                if (7 < *(short *)((int)pvVar7 + 0x8c)) {
                  *(undefined2 *)((int)pvVar7 + 0x8c) = 1;
                }
                *(short *)((int)pvVar7 + 0x98) = (*(short *)((int)pvVar7 + 0x8c) + -1) * 0x249;
                iVar4 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar7 + 0x8c));
              } while (iVar4 == 0);
              vol = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
              if ((int)((uint)vol << 0x10) < 0) {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
                sample = 0x12;
                if (0x3f < -(int)sVar2) {
                  vol = 100;
                  goto LAB_8007b1a4;
                }
              }
              else {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
joined_r0x8007b0e4:
                sample = 0x12;
                if (0x3f < sVar2) goto LAB_8007b1a0;
              }
            }
          }
        }
      }
      else {
        if ((int)puVar6 < 0x10000003) {
          if (puVar6 == &DAT_00100004) {
            bVar1 = true;
            goto LAB_8007b1c4;
          }
        }
        else {
          if (puVar6 == (undefined *)0x10000004) {
            iVar4 = _GlyphIsAnyGlyphSet();
            if (iVar4 != 0) {
              vol = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
              if ((int)((uint)vol << 0x10) < 0) {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
                if (-(int)sVar2 < 0x40) goto LAB_8007af0c;
              }
              else {
                sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
                if (sVar2 < 0x40) {
LAB_8007af0c:
                  do {
                    *(undefined2 *)((int)pvVar7 + 0x9a) = 0xffff;
                    vol = *(short *)((int)pvVar7 + 0x8c) - 1;
                    *(ushort *)((int)pvVar7 + 0x8c) = vol;
                    if ((int)((uint)vol << 0x10) < 1) {
                      *(undefined2 *)((int)pvVar7 + 0x8c) = 7;
                    }
                    *(short *)((int)pvVar7 + 0x98) = (*(short *)((int)pvVar7 + 0x8c) + -1) * 0x249;
                    iVar4 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar7 + 0x8c));
                  } while (iVar4 == 0);
                  vol = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
                  if (-1 < (int)((uint)vol << 0x10)) {
                    sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98))
                    ;
                    goto joined_r0x8007b0e4;
                  }
                  sVar2 = AngleDiff(*(short *)((int)pvVar7 + 0x96),*(short *)((int)pvVar7 + 0x98));
                  sample = 0x12;
                  if (0x3f < -(int)sVar2) {
                    vol = 100;
                    goto LAB_8007b1a4;
                  }
                }
              }
            }
            goto LAB_8007b1c4;
          }
        }
LAB_8007b1bc:
        _GlyphDefaultProcess(instance,data1,data2);
      }
    }
LAB_8007b1c4:
    DeMessageQueue((__MessageQueue *)((int)pvVar7 + 4));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_StartSpell(struct _Instance *instance /*$a0*/, int glyphnum /*$a1*/)
 // line 716, offset 0x8007b228
	/* begin block 1 */
		// Start line: 717
		// Start offset: 0x8007B228
		// Variables:
	// 		int message; // $a2
	/* end block 1 */
	// End offset: 0x8007B2B0
	// End Line: 750

	/* begin block 2 */
		// Start line: 1695
	/* end block 2 */
	// End Line: 1696

/* File: C:\kain2\game\GLYPH.C */

void Glyph_StartSpell(_Instance *instance,int glyphnum)

{
  undefined *Message;
  
  Message = (undefined *)0x0;
  switch(glyphnum) {
  case 1:
    Message = &LAB_00080000_1;
    break;
  case 2:
    Message = &LAB_00080000_2;
    break;
  case 3:
    Message = &LAB_00080000_3;
    break;
  case 4:
    Message = &DAT_00080004;
    break;
  case 5:
    Message = &DAT_00080005;
    break;
  case 6:
    Message = &DAT_00080006;
    break;
  case 7:
    Message = &DAT_00080007;
  }
  INSTANCE_Post(DAT_800d20f8,(int)Message,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_Broadcast(struct _Instance *sender /*$s5*/, int glyphnum /*$a1*/)
 // line 753, offset 0x8007b2d0
	/* begin block 1 */
		// Start line: 754
		// Start offset: 0x8007B2D0
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int plane; // $s6
	// 		long whatAmIMask; // $s3
	// 		int Message; // $s2
	// 		int Data; // $s7
	// 		int dist; // $v1
	// 		int fx_radius; // $s4

		/* begin block 1.1 */
			// Start line: 804
			// Start offset: 0x8007B3B4
			// Variables:
		// 		long whatAmI; // $s1
		/* end block 1.1 */
		// End offset: 0x8007B468
		// End Line: 822
	/* end block 1 */
	// End offset: 0x8007B478
	// End Line: 823

	/* begin block 2 */
		// Start line: 1769
	/* end block 2 */
	// End Line: 1770

/* File: C:\kain2\game\GLYPH.C */

void Glyph_Broadcast(_Instance *sender,int glyphnum)

{
  ulong uVar1;
  int iVar2;
  _Instance *Inst;
  undefined *Message;
  uint uVar3;
  int iVar4;
  int plane;
  
  uVar3 = 0;
  Message = (undefined *)0x0;
  plane = (int)DAT_800d20d6;
  iVar4 = *(int *)(fx_blastring + 0x3c);
  switch(glyphnum) {
  case 1:
    uVar3 = 10;
    Message = &LAB_00080000_1;
    break;
  case 2:
    uVar3 = 10;
    Message = &LAB_00080000_2;
    break;
  case 3:
    uVar3 = 10;
    Message = &LAB_00080000_3;
    break;
  case 4:
    uVar3 = 10;
    Message = &DAT_00080004;
    break;
  case 5:
    uVar3 = 0x2a;
    Message = &DAT_00080005;
    break;
  case 6:
    uVar3 = 10;
    Message = &DAT_00080006;
    break;
  case 7:
    goto switchD_8007b338_caseD_7;
  }
  Inst = *(_Instance **)(DAT_800d2100 + 4);
  while (Inst != (_Instance *)0x0) {
    uVar1 = INSTANCE_Query(Inst,1);
    if ((((Inst != sender) && ((uVar1 & uVar3) != 0)) &&
        (iVar2 = INSTANCE_InPlane(Inst,plane), iVar2 != 0)) &&
       ((uVar1 != 0x20 || (uVar1 = INSTANCE_Query(Inst,2), (uVar1 & 0x4000) != 0)))) {
      iVar2 = MATH3D_veclen2((int)(Inst->position).x - (int)(sender->position).x,
                             (int)(Inst->position).y - (int)(sender->position).y);
      iVar2 = iVar2 << 0xc;
      if (((iVar2 <= iVar4) && (fx_radius_old <= iVar2)) ||
         ((iVar4 <= iVar2 && (iVar2 <= fx_radius_old)))) {
        INSTANCE_Post(Inst,(int)Message,0);
      }
    }
    Inst = Inst->next;
  }
switchD_8007b338_caseD_7:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_DoSpell(struct _Instance *instance /*stack 0*/, int glyphnum /*$s1*/)
 // line 825, offset 0x8007b4a4
	/* begin block 1 */
		// Start line: 826
		// Start offset: 0x8007B4A4
		// Variables:
	// 		int fx_radius; // $fp
	// 		int fx_accl; // $v0
	// 		int fx_vel; // $s5
	// 		long fx_color; // $a3
	// 		int fx_height1; // $s7
	// 		int fx_height2; // $s6
	// 		int fx_height3; // $s4
	// 		int fx_rad2; // $s3
	// 		int fx_rad3; // $s2
	// 		int pred_offset; // $s0
	// 		int color_change_radius; // $s1
	// 		struct MATRIX mat; // stack offset -80
	// 		struct _GlyphTuneData *glyphtunedata; // $s0
	/* end block 1 */
	// End offset: 0x8007B710
	// End Line: 925

	/* begin block 2 */
		// Start line: 1962
	/* end block 2 */
	// End Line: 1963

/* File: C:\kain2\game\GLYPH.C */

void Glyph_DoSpell(_Instance *instance,int glyphnum)

{
  int colorChangeRadius;
  long startColor;
  void *pvVar1;
  int pred_offset;
  int size2;
  int size1;
  int height3;
  int vel;
  int height2;
  int height1;
  int radius;
  
  radius = 0;
  vel = 0;
  height1 = 0;
  height2 = 0;
  height3 = 0;
  size1 = 0;
  size2 = 0;
  pvVar1 = instance->object->data;
  fx_going = 0;
  MATH3D_SetUnityMatrix(0xb0);
  startColor = 0;
  fx_radius_old = 0;
  blast_range = (int)*(short *)((int)pvVar1 + (glyphnum + -1) * 2 + 0xc);
  pred_offset = 0;
  colorChangeRadius = blast_range;
  if (blast_range < 0) {
    colorChangeRadius = blast_range + 3;
  }
  colorChangeRadius = blast_range - (colorChangeRadius >> 2);
  switch(glyphnum) {
  case 1:
    radius = 1;
    startColor = 0xc0c0c0;
    height1 = -0x100;
    height2 = 0x100;
    height3 = 0x300;
    vel = 0x200000;
    size1 = -0x280;
    fx_going = 1;
    size2 = 0;
    break;
  case 2:
    CAMERA_SetShake((Camera *)&theCamera,0x3c,0x800);
    radius = 0x280;
    vel = 0x140000;
    startColor = 0xa0a0a0;
    height3 = 0;
    height2 = 0;
    height1 = 0;
    size1 = 0x280;
    fx_going = 2;
    size2 = 0x340;
    break;
  case 3:
    radius = 1;
    startColor = 0xffffff;
    height1 = 0;
    height2 = 0x40;
    height3 = 0x80;
    vel = 0x100000;
    size1 = 0x280;
    size2 = 0x340;
    fx_going = 3;
    pred_offset = 5;
    break;
  case 4:
    radius = 1;
    startColor = 0xff0000;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    vel = 0x100000;
    size1 = 0x280;
    fx_going = 4;
    size2 = 0x340;
    break;
  case 5:
    radius = 1;
    vel = 0x100000;
    startColor = 0xff;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    size1 = 0x280;
    fx_going = 5;
    size2 = 0x340;
    break;
  case 6:
    radius = 1;
    startColor = 0xffffff;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    vel = 0x100000;
    size1 = 0x280;
    fx_going = 6;
    size2 = 0x340;
  }
  if ((fx_going != 0) &&
     (fx_blastring = FX_DoBlastRing((_Instance *)0x0,(_SVector *)&instance->position,0xb0,-1,radius,
                                    blast_range,colorChangeRadius,size1,size2,vel,-0x800,height1,
                                    height2,height3,startColor,0,pred_offset,-99,0),
     fx_blastring == (_FXBlastringEffect *)0x0)) {
    fx_going = 0;
  }
  blast_range = blast_range << 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_EndFX()
 // line 928, offset 0x8007b74c
	/* begin block 1 */
		// Start line: 2204
	/* end block 1 */
	// End Line: 2205

	/* begin block 2 */
		// Start line: 2205
	/* end block 2 */
	// End Line: 2206

/* File: C:\kain2\game\GLYPH.C */

void Glyph_EndFX(void)

{
  int iVar1;
  
  iVar1 = fx_blastring;
  fx_going = 0;
  fx_blastring = 0;
  *(undefined2 *)(iVar1 + 0xe) = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_DoFX(struct _Instance *instance /*$a0*/)
 // line 935, offset 0x8007b760
	/* begin block 1 */
		// Start line: 2216
	/* end block 1 */
	// End Line: 2217

	/* begin block 2 */
		// Start line: 2220
	/* end block 2 */
	// End Line: 2221

/* File: C:\kain2\game\GLYPH.C */

void Glyph_DoFX(_Instance *instance)

{
  int *piVar1;
  int iVar2;
  
  if (((DAT_800d223e != 6) && ((DAT_800d2210 & 0x100000) == 0)) && ((int)fx_going != 0)) {
    Glyph_Broadcast(instance,(int)fx_going);
    fx_radius_old = *(int *)(fx_blastring + 0x3c);
    if (blast_range < fx_radius_old) {
      Glyph_EndFX();
    }
    iVar2 = fx_blastring;
    if (fx_going == 5) {
      piVar1 = (int *)(fx_blastring + 100);
      *(int *)(fx_blastring + 0x5c) = *(int *)(fx_blastring + 0x5c) + -0x3c;
      *(int *)(iVar2 + 100) = *piVar1 + 0x3c;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphGenericProcess(struct _Instance *instance /*$s2*/, int data1 /*$s3*/, int data2 /*$s4*/)
 // line 968, offset 0x8007b810
	/* begin block 1 */
		// Start line: 969
		// Start offset: 0x8007B810
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $s1

		/* begin block 1.1 */
			// Start line: 998
			// Start offset: 0x8007B8E8
			// Variables:
		// 		struct _GlyphTuneData *glyphtunedata; // $s0
		/* end block 1.1 */
		// End offset: 0x8007B920
		// End Line: 1004
	/* end block 1 */
	// End offset: 0x8007B920
	// End Line: 1006

	/* begin block 2 */
		// Start line: 2290
	/* end block 2 */
	// End Line: 2291

/* File: C:\kain2\game\GLYPH.C */

void _GlyphGenericProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  int Data;
  undefined *puVar2;
  _GlyphTuneData *glyphtunedata;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  ShrinkGlyphMenu(instance);
  do {
    p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
    if (p_Var1 == (__Event *)0x0) {
      if (glyph_trigger != 0) {
        glyphtunedata = (_GlyphTuneData *)instance->object->data;
        Glyph_DoSpell(instance,(int)*(short *)((int)pvVar3 + 0x8c));
        glyph_trigger = 0;
        Data = _GlyphCost(glyphtunedata,(int)*(short *)((int)pvVar3 + 0x8c));
        INSTANCE_Post(DAT_800d20f8,0x40008,Data);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001) {
      Glyph_StartSpell(instance,(int)*(short *)((int)pvVar3 + 0x8c));
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == (undefined *)0x80000000) {
          _GlyphSwitchProcess(instance,_GlyphOffProcess);
        }
        else {
LAB_8007b8c0:
          _GlyphDefaultProcess(instance,data1,data2);
        }
      }
      else {
        if (puVar2 != &DAT_00100004) goto LAB_8007b8c0;
      }
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphTrigger()
 // line 1009, offset 0x8007b948
	/* begin block 1 */
		// Start line: 2374
	/* end block 1 */
	// End Line: 2375

	/* begin block 2 */
		// Start line: 2375
	/* end block 2 */
	// End Line: 2376

/* File: C:\kain2\game\GLYPH.C */

void GlyphTrigger(void)

{
  if (fx_going == 0) {
    glyph_trigger = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MANNA_Pickup()
 // line 1026, offset 0x8007b964
	/* begin block 1 */
		// Start line: 2408
	/* end block 1 */
	// End Line: 2409

	/* begin block 2 */
		// Start line: 2409
	/* end block 2 */
	// End Line: 2410

/* File: C:\kain2\game\GLYPH.C */

void MANNA_Pickup(void)

{
  MANNA_Position = 0x24;
  MANNA_Pickup_Time = 0x1e000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HEALTHU_Pickup(struct _Instance *instance /*$s0*/)
 // line 1032, offset 0x8007b980
	/* begin block 1 */
		// Start line: 2420
	/* end block 1 */
	// End Line: 2421

/* File: C:\kain2\game\GLYPH.C */

void HEALTHU_Pickup(_Instance *instance)

{
  ApplyMatrixSV(DAT_800d100c,(SVECTOR *)&instance->position,(SVECTOR *)&HUD_Cap_Pos);
  HUD_Cap_Pos.x = HUD_Cap_Pos.x + *(short *)DAT_800d100c->t;
  HUD_Cap_Pos.y = HUD_Cap_Pos.y + *(short *)(DAT_800d100c->t + 1);
  HUD_Cap_Vel.z = 0;
  HUD_Cap_Vel.y = 0;
  HUD_Cap_Vel.x = 0;
  HUD_Cap_Pos.z = HUD_Cap_Pos.z + *(short *)(DAT_800d100c->t + 2);
  INSTANCE_KillInstance(instance);
  HUD_Captured = 1;
  HUD_State = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Damp(short *val /*$v1*/, short target /*$a1*/, short *vel /*$a3*/, short max /*$a3*/)
 // line 1048, offset 0x8007ba10
	/* begin block 1 */
		// Start line: 1049
		// Start offset: 0x8007BA10
		// Variables:
	// 		short accl; // stack offset -16
	/* end block 1 */
	// End offset: 0x8007BA10
	// End Line: 1049

	/* begin block 2 */
		// Start line: 2455
	/* end block 2 */
	// End Line: 2456

/* File: C:\kain2\game\GLYPH.C */

void HUD_Damp(short *val,short target,short *vel,short max)

{
  short asStack16 [4];
  
  CriticalDampValue(1,val,target,vel,asStack16,(int)max);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Init()
 // line 1055, offset 0x8007ba58
	/* begin block 1 */
		// Start line: 2475
	/* end block 1 */
	// End Line: 2476

	/* begin block 2 */
		// Start line: 2481
	/* end block 2 */
	// End Line: 2482

/* File: C:\kain2\game\GLYPH.C */

void HUD_Init(void)

{
  HUD_Count = 0;
  HUD_Rotation = 0;
  HUD_Rot_vel = 0;
  HUD_Position = -1000;
  HUD_Pos_vel = 0;
  HUD_State = 0;
  HUD_Wait = 0;
  warpDraw = 0;
  glowdeg = 0;
  hud_warp_arrow_flash = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Setup_Chit_Count(int chits /*$a0*/)
 // line 1069, offset 0x8007ba8c
	/* begin block 1 */
		// Start line: 2508
	/* end block 1 */
	// End Line: 2509

	/* begin block 2 */
		// Start line: 2509
	/* end block 2 */
	// End Line: 2510

/* File: C:\kain2\game\GLYPH.C */

void HUD_Setup_Chit_Count(int chits)

{
  HUD_Count = chits % 5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Update()
 // line 1074, offset 0x8007bac0
	/* begin block 1 */
		// Start line: 1075
		// Start offset: 0x8007BAC0
		// Variables:
	// 		short accl; // stack offset -16
	/* end block 1 */
	// End offset: 0x8007BCF8
	// End Line: 1159

	/* begin block 2 */
		// Start line: 2518
	/* end block 2 */
	// End Line: 2519

/* File: C:\kain2\game\GLYPH.C */

void HUD_Update(void)

{
  bool bVar1;
  short sVar2;
  short asStack16 [4];
  
  if ((DAT_800d223e == 6) && (HUD_State == 0)) {
    HUD_State = 10;
  }
  else {
    if (DAT_800d223e == 6) {
      if ((1 < HUD_State) && (HUD_State < 7)) {
        return;
      }
    }
    else {
      if ((uint)(ushort)HUD_State - 10 < 2) {
        HUD_State = 0xc;
      }
    }
  }
  sVar2 = HUD_Wait + -1;
  if (HUD_Wait < 1) {
    sVar2 = HUD_Wait;
    switch(HUD_State) {
    default:
      HUD_Position = -1000;
      HUD_Rotation = 0;
      HUD_Rot_vel = 0;
      HUD_Pos_vel = 0;
      if (HUD_Count == 5) {
        HUD_Count = 0;
      }
      break;
    case 1:
    case 10:
      HUD_Damp(&HUD_Position,0,&HUD_Pos_vel,0x60);
      if (-1 < HUD_Position) {
        HUD_Position = 0;
        bVar1 = HUD_State != 10;
        HUD_State = 0xb;
        if ((bVar1) && (HUD_State = 2, HUD_Count < 1)) {
          HUD_State = 3;
        }
      }
      sVar2 = HUD_Wait;
      if (HUD_State == 10) {
        MANNA_Pickup_Time = 0;
        CriticalDampValue(5,&MANNA_Position,0x24,&MANNA_Pos_vel,asStack16,0xc);
        sVar2 = HUD_Wait;
      }
      break;
    case 2:
      HUD_Damp(&HUD_Rotation,0x333,&HUD_Rot_vel,0x50);
      sVar2 = HUD_Wait;
      if (0x332 < HUD_Rotation) {
        HUD_Rotation = 0x333;
        HUD_State = 3;
      }
      break;
    case 3:
    case 4:
    case 0xb:
      break;
    case 5:
      HUD_State = 6;
      HUD_Rotation = 0;
      HUD_Wait = 10;
      HUD_Captured = 0;
      HUD_Count = HUD_Count + 1;
      sVar2 = HUD_Wait;
      break;
    case 6:
    case 0xc:
      HUD_Damp(&HUD_Position,-1000,&HUD_Pos_vel,0x60);
      sVar2 = HUD_Wait;
      if (HUD_Position < -999) {
        HUD_State = 0;
      }
    }
  }
  HUD_Wait = sVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Draw()
 // line 1170, offset 0x8007bd08
	/* begin block 1 */
		// Start line: 1171
		// Start offset: 0x8007BD08
		// Variables:
	// 		struct _SVector Rotation; // stack offset -80
	// 		struct _SVector Pos; // stack offset -72
	// 		struct _SVector offset; // stack offset -64
	// 		int n; // $s0

		/* begin block 1.1 */
			// Start line: 1177
			// Start offset: 0x8007BD40
			// Variables:
		// 		struct DVECTOR center; // stack offset -56
		// 		int glow; // $a1
		// 		int left; // $t0
		// 		int right; // $s0
		/* end block 1.1 */
		// End offset: 0x8007BEB4
		// End Line: 1215

		/* begin block 1.2 */
			// Start line: 1223
			// Start offset: 0x8007BED8
			// Variables:
		// 		int oldx; // $s2
		// 		int oldy; // $s3
		// 		int MANNA_Count; // $s1
		// 		int MANNA_Max; // $s0
		/* end block 1.2 */
		// End offset: 0x8007BF98
		// End Line: 1246

		/* begin block 1.3 */
			// Start line: 1252
			// Start offset: 0x8007BFCC
			// Variables:
		// 		struct _SVector targetPos; // stack offset -48
		// 		struct _SVector accl; // stack offset -40
		// 		struct _SVector HUD_Cap_Rot; // stack offset -32
		/* end block 1.3 */
		// End offset: 0x8007C0B0
		// End Line: 1273

		/* begin block 1.4 */
			// Start line: 1281
			// Start offset: 0x8007C0F8
		/* end block 1.4 */
		// End offset: 0x8007C13C
		// End Line: 1291
	/* end block 1 */
	// End offset: 0x8007C190
	// End Line: 1300

	/* begin block 2 */
		// Start line: 2723
	/* end block 2 */
	// End Line: 2724

/* File: C:\kain2\game\GLYPH.C */

void HUD_Draw(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int fade;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  int fade_00;
  uint uVar7;
  undefined **ppuVar8;
  _SVector local_50;
  _SVector local_48;
  _SVector local_40;
  short local_38;
  short local_36;
  _Position local_30;
  _SVector _Stack40;
  _SVector local_20;
  
  if ((DAT_800d1438 & 0x80000000) == 0) {
    if (warpDraw == 0) goto LAB_8007beb4;
    warpDraw = warpDraw - (DAT_800d2314 >> 4);
    if (warpDraw < 0) {
      warpDraw = 0;
    }
  }
  else {
    warpDraw = warpDraw + (DAT_800d2314 >> 4);
    if (0x1000 < warpDraw) {
      warpDraw = 0x1000;
    }
  }
  HUD_GetPlayerScreenPt(200);
  fade = rcos(glowdeg);
  fade = (warpDraw / 10) * fade;
  if (fade < 0) {
    fade = fade + 0xfff;
  }
  fade = warpDraw / 3 + (fade >> 0xc);
  if (fade < 0) {
    fade = 0;
  }
  glowdeg = glowdeg + (DAT_800d2314 >> 5);
  fade_00 = fade;
  if (hud_warp_arrow_flash < 1) {
LAB_8007be40:
    if (hud_warp_arrow_flash < 0) {
      iVar4 = hud_warp_arrow_flash + (DAT_800d2314 >> 3);
      fade = fade - hud_warp_arrow_flash;
      hud_warp_arrow_flash = iVar4;
      if (0 < iVar4) {
        hud_warp_arrow_flash = 0;
      }
    }
  }
  else {
    iVar4 = hud_warp_arrow_flash - (DAT_800d2314 >> 3);
    fade_00 = fade + hud_warp_arrow_flash;
    hud_warp_arrow_flash = iVar4;
    if (iVar4 < 0) {
      hud_warp_arrow_flash = 0;
      goto LAB_8007be40;
    }
  }
  FX_MakeWarpArrow((int)local_38 + -0x40,(int)local_36,-0x40,0x20,fade);
  FX_MakeWarpArrow((int)local_38 + 0x40,(int)local_36,0x40,0x20,fade_00);
LAB_8007beb4:
  HUD_Update();
  uVar3 = DAT_800d1cfc;
  uVar2 = DAT_800d1cf8;
  local_40.x = 0;
  local_40.y = 0;
  local_40.z = 0x87;
  if (-0x40 < MANNA_Position) {
    uVar5 = INSTANCE_Query(DAT_800d20f8,0x20);
    uVar6 = INSTANCE_Query(DAT_800d20f8,0x2d);
    FX_MakeMannaIcon((int)MANNA_Position,0x17,0x33,0x20);
    FONT_Flush();
    FONT_SetCursor((short)(((uint)(ushort)MANNA_Position + 0x3a) * 0x10000 >> 0x10),0x20);
    if (glyph_cost != -1) {
      FONT_Print((char *)&PTR_DAT_800d0820);
    }
    if ((int)uVar6 <= (int)uVar5) {
      FONT_SetColorIndex(2);
    }
    FONT_Print((char *)&PTR_DAT_800d0824);
    FONT_SetColorIndex(0);
    FONT_SetCursor((short)uVar2,(short)uVar3);
    FONT_Flush();
  }
  if (-1000 < HUD_Position) {
    if ((HUD_Captured != 0) && (DAT_800d223e != 6)) {
      local_20.x = 0x400;
      local_30.x = -0x600;
      local_20.y = 0;
      local_20.z = 0;
      local_30.z = 0xa00;
      if (HUD_State < 4) {
        local_30.y = 0x120;
      }
      else {
        local_30.y = 0x260;
      }
      CriticalDampPosition
                (1,(_Position *)&HUD_Cap_Pos,&local_30,(_SVector *)&HUD_Cap_Vel,&_Stack40,0x80);
      if (((HUD_Cap_Vel.x == 0) && (HUD_Cap_Vel.y == 0)) && (HUD_Cap_Vel.z == 0)) {
        if (HUD_State == 3) {
          HUD_State = 4;
        }
        else {
          if (HUD_State == 4) {
            HUD_State = 5;
          }
        }
      }
      FX_DrawModel((Object *)objectAccess[21].object,0,&local_20,(_SVector *)&HUD_Cap_Pos,&local_40,
                   0);
    }
    uVar7 = 0;
    ppuVar8 = &PTR_LAB_80011d6c;
    local_50.x = 0x400;
    local_48.y = 0x260;
    local_50.y = 0;
    local_48.z = 0xa00;
    local_40.z = 0;
    local_48.x = HUD_Position + -0x600;
    local_50.z = HUD_Rotation;
    bVar1 = true;
    do {
      if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x8007c10c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)*ppuVar8)();
        return;
      }
      ppuVar8 = (code **)ppuVar8 + 1;
      local_50.z = local_50.z - HUD_Rotation & 0xfff;
      FX_DrawModel((Object *)objectAccess[24].object,0,&local_50,&local_48,&local_40,
                   (uint)((int)uVar7 < HUD_Count) ^ 1);
      uVar7 = uVar7 + 1;
      bVar1 = uVar7 < 5;
    } while ((int)uVar7 < 5);
  }
  return;
}





