#include "THISDUST.H"
#include "GLYPH.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GlyphInit(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 117, offset 0x80079b64
	/* begin block 1 */
		// Start line: 118
		// Start offset: 0x80079B64
		// Variables:
	// 		struct __GlyphData *data; // $s1
	/* end block 1 */
	// End offset: 0x80079C4C
	// End Line: 160

	/* begin block 2 */
		// Start line: 234
	/* end block 2 */
	// End Line: 235

void GlyphInit(_Instance *instance,GameTracker *gameTracker)

{
  undefined4 *puVar1;
  
  if ((instance->flags & 0x20000U) == 0) {
    puVar1 = (undefined4 *)MEMPACK_Malloc(0x9c,'\x1d');
    *(undefined4 **)&instance->extraData = puVar1;
    InitMessageQueue((__MessageQueue *)(puVar1 + 1));
    EnMessageQueueData((__MessageQueue *)(puVar1 + 1),0x100001,0);
    *puVar1 = 0x8007a570;
    puVar1[0x23] = 7;
    *(undefined2 *)(puVar1 + 0x26) = 0xdb6;
    *(undefined2 *)(puVar1 + 0x24) = 0;
    glyph_time = 0;
    *(undefined2 *)((int)puVar1 + 0x92) = 0;
    *(undefined2 *)(puVar1 + 0x25) = 0;
    *(undefined2 *)((int)puVar1 + 0x9a) = 1;
    glyph_trigger = 0;
    fx_blastring = (_FXBlastringEffect *)0x0;
    fx_going = 0;
    *(short *)((int)puVar1 + 0x96) = ((short)puVar1[0x23] + -1) * 0x249;
    glyph_cost = -1;
    instance->flags = instance->flags | 0x10800;
  }
  else {
    MEMPACK_Free((char *)instance->extraData);
  }
  HUD_Init();
  MANNA_Position = -0x40;
  MANNA_Pos_vel = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphCollide(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 168, offset 0x80079c78
	/* begin block 1 */
		// Start line: 373
	/* end block 1 */
	// End Line: 374

	/* begin block 2 */
		// Start line: 375
	/* end block 2 */
	// End Line: 376

void GlyphCollide(_Instance *instance,GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphProcess(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 175, offset 0x80079c80
	/* begin block 1 */
		// Start line: 176
		// Start offset: 0x80079C80
		// Variables:
	// 		struct __GlyphData *data; // $v0
	/* end block 1 */
	// End offset: 0x80079C80
	// End Line: 176

	/* begin block 2 */
		// Start line: 387
	/* end block 2 */
	// End Line: 388

void GlyphProcess(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  long lVar2;
  
  (**(code **)instance->extraData)(instance,0,0);
  sVar1 = (instance->parent->position).z;
  *(undefined4 *)&instance->position = *(undefined4 *)&instance->parent->position;
  (instance->position).z = sVar1;
  lVar2 = instance->parent->currentStreamUnitID;
  instance->flags = instance->flags | 0xc00;
  instance->currentStreamUnitID = lVar2;
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ GlyphQuery(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 204, offset 0x80079cf0
	/* begin block 1 */
		// Start line: 205
		// Start offset: 0x80079CF0

		/* begin block 1.1 */
			// Start line: 212
			// Start offset: 0x80079D0C
			// Variables:
		// 		struct evControlSaveDataData *pdata; // $v0
		/* end block 1.1 */
		// End offset: 0x80079D2C
		// End Line: 220
	/* end block 1 */
	// End offset: 0x80079D30
	// End Line: 227

	/* begin block 2 */
		// Start line: 448
	/* end block 2 */
	// End Line: 449

ulong GlyphQuery(_Instance *instance,ulong query)

{
  undefined4 *puVar1;
  
  if (query == 1) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)0x0;
    if (query == 0x18) {
      puVar1 = (undefined4 *)CIRC_Alloc(8);
      *puVar1 = 4;
      puVar1[1] = 0x800d4d8c;
    }
  }
  return (ulong)puVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphPost(struct _Instance *instance /*$a0*/, unsigned long message /*$a1*/, unsigned long messageData /*$a2*/)
 // line 231, offset 0x80079d40
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80079D40
		// Variables:
	// 		struct __GlyphData *data; // $a0

		/* begin block 1.1 */
			// Start line: 244
			// Start offset: 0x80079D5C
		/* end block 1.1 */
		// End offset: 0x80079D80
		// End Line: 249
	/* end block 1 */
	// End offset: 0x80079D88
	// End Line: 255

	/* begin block 2 */
		// Start line: 502
	/* end block 2 */
	// End Line: 503

void GlyphPost(_Instance *instance,ulong message,ulong messageData)

{
  if (message == 0x100007) {
    HudSave = **(undefined4 **)(messageData + 4);
  }
  else {
    EnMessageQueueData((__MessageQueue *)((int)instance->extraData + 4),message,messageData);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphSwitchProcess(struct _Instance *instance /*$s1*/, TDRFuncPtr__GlyphSwitchProcess1process process /*$s3*/)
 // line 265, offset 0x80079d98
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x80079D98
		// Variables:
	// 		struct __GlyphData *data; // $s2
	/* end block 1 */
	// End offset: 0x80079D98
	// End Line: 266

	/* begin block 2 */
		// Start line: 579
	/* end block 2 */
	// End Line: 580

void _GlyphSwitchProcess(_Instance *instance,TDRFuncPtr__GlyphSwitchProcess1process process)

{
  __MessageQueue *In;
  TDRFuncPtr__GlyphSwitchProcess1process *ppTVar1;
  
  ppTVar1 = (TDRFuncPtr__GlyphSwitchProcess1process *)instance->extraData;
  In = (__MessageQueue *)(ppTVar1 + 1);
  PurgeMessageQueue(In);
  EnMessageQueueData(In,0x100004,0);
  (**ppTVar1)(instance,0,0);
  EnMessageQueueData(In,0x100001,0);
  *ppTVar1 = process;
  (*process)(instance,0,0);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsGlyphSet(int glyph /*$s0*/)
 // line 287, offset 0x80079e38
	/* begin block 1 */
		// Start line: 627
	/* end block 1 */
	// End Line: 628

int _GlyphIsGlyphSet(int glyph)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance,0x24);
  return 1 << (glyph + 0x11U & 0x1f) & uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsGlyphUsable(int glyph /*$s0*/)
 // line 291, offset 0x80079e74
	/* begin block 1 */
		// Start line: 636
	/* end block 1 */
	// End Line: 637

int _GlyphIsGlyphUsable(int glyph)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance,0x13);
  return 1 << (glyph + 0x11U & 0x1f) & uVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsAnyGlyphSet()
 // line 295, offset 0x80079eb0
	/* begin block 1 */
		// Start line: 645
	/* end block 1 */
	// End Line: 646

/* WARNING: Unknown calling convention yet parameter storage is locked */

int _GlyphIsAnyGlyphSet(void)

{
  ulong uVar1;
  
  uVar1 = INSTANCE_Query(gameTrackerX.playerInstance,0x24);
  return uVar1 & 0x3fc0000;
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphCost(struct _GlyphTuneData *glyphtunedata /*$a0*/, int glyphNum /*$a1*/)
 // line 300, offset 0x80079ed8
	/* begin block 1 */
		// Start line: 656
	/* end block 1 */
	// End Line: 657

	/* begin block 2 */
		// Start line: 657
	/* end block 2 */
	// End Line: 658

int _GlyphCost(_GlyphTuneData *glyphtunedata,int glyphNum)

{
  return (uint)*(byte *)((int)&glyphtunedata->glyph_darkness + glyphNum + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphDefaultProcess(struct _Instance *instance /*$s1*/, int data1 /*$a1*/, int data2 /*$a2*/)
 // line 313, offset 0x80079ee8
	/* begin block 1 */
		// Start line: 314
		// Start offset: 0x80079EE8
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $v0
	/* end block 1 */
	// End offset: 0x80079F50
	// End Line: 333

	/* begin block 2 */
		// Start line: 682
	/* end block 2 */
	// End Line: 683

void _GlyphDefaultProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  __MessageQueue *In;
  
  In = (__MessageQueue *)((int)instance->extraData + 4);
  while (p_Var1 = PeekMessageQueue(In), p_Var1 != (__Event *)0x0) {
    if ((undefined *)p_Var1->ID == &DAT_80000010) {
      _GlyphSwitchProcess(instance,_GlyphSelectProcess);
    }
    DeMessageQueue(In);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_GetPlayerScreenPt(struct DVECTOR *center /*$s0*/)
 // line 335, offset 0x80079f6c
	/* begin block 1 */
		// Start line: 336
		// Start offset: 0x80079F6C
		// Variables:
	// 		struct _Position position; // stack offset -16
	/* end block 1 */
	// End offset: 0x80079F6C
	// End Line: 336

	/* begin block 2 */
		// Start line: 734
	/* end block 2 */
	// End Line: 735

void HUD_GetPlayerScreenPt(DVECTOR *center)

{
  DVECTOR DVar1;
  undefined4 in_zero;
  undefined4 in_at;
  uint local_c;
  
  PushMatrix();
  SetRotMatrix((undefined4 *)theCamera.core.wcTransform);
  SetTransMatrix((int)theCamera.core.wcTransform);
  local_c = local_c & 0xffff0000 |
            (uint)(ushort)(((gameTrackerX.playerInstance)->position).z + 0x1c0);
  setCopReg(2,in_zero,*(undefined4 *)&(gameTrackerX.playerInstance)->position);
  setCopReg(2,in_at,local_c);
  copFunction(2,0x180001);
  DVar1 = (DVECTOR)getCopReg(2,0xe);
  *center = DVar1;
  PopMatrix();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphDrawMenu(struct _Instance *instance /*stack 0*/)
 // line 353, offset 0x80079ffc
	/* begin block 1 */
		// Start line: 354
		// Start offset: 0x80079FFC
		// Variables:
	// 		struct _Position place; // stack offset -72
	// 		struct DVECTOR center; // stack offset -64
	// 		int n; // $s5
	// 		int rot; // $s3
	// 		int radius; // $s6
	// 		int glyph_rotation_speed; // $s0
	// 		struct __GlyphData *data; // $s4
	// 		struct _GlyphTuneData *glyphtunedata; // $s7

		/* begin block 1.1 */
			// Start line: 373
			// Start offset: 0x8007A054
			// Variables:
		// 		int diff; // $v0
		/* end block 1.1 */
		// End offset: 0x8007A0B8
		// End Line: 389

		/* begin block 1.2 */
			// Start line: 400
			// Start offset: 0x8007A0EC
			// Variables:
		// 		int enabled; // $v1
		// 		int scale_modify; // $s2
		// 		int num; // $s1
		/* end block 1.2 */
		// End offset: 0x8007A22C
		// End Line: 442

		/* begin block 1.3 */
			// Start line: 451
			// Start offset: 0x8007A29C
			// Variables:
		// 		struct _Vector f1; // stack offset -56
		/* end block 1.3 */
		// End offset: 0x8007A2F8
		// End Line: 467

		/* begin block 1.4 */
			// Start line: 472
			// Start offset: 0x8007A2F8
		/* end block 1.4 */
		// End offset: 0x8007A2F8
		// End Line: 474
	/* end block 1 */
	// End offset: 0x8007A2F8
	// End Line: 474

	/* begin block 2 */
		// Start line: 770
	/* end block 2 */
	// End Line: 771

	/* begin block 3 */
		// Start line: 785
	/* end block 3 */
	// End Line: 786

void GlyphDrawMenu(_Instance *instance)

{
  short current;
  ushort uVar1;
  int iVar2;
  int glyphnum;
  uint enabled;
  uint uVar3;
  int glyph;
  int iVar4;
  void *pvVar5;
  int iVar6;
  _GlyphTuneData *glyphtunedata;
  _Position local_48;
  DVECTOR local_40 [2];
  _Vector local_38;
  
  pvVar5 = instance->extraData;
  uVar3 = (gameTrackerX.idleTime << 6) >> 0xc;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  if (*(short *)((int)pvVar5 + 0x98) != *(short *)((int)pvVar5 + 0x96)) {
    current = AngleDiff(*(short *)((int)pvVar5 + 0x98),*(short *)((int)pvVar5 + 0x96));
    iVar2 = (int)current;
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if ((int)uVar3 < iVar2) {
      current = (short)uVar3;
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
  HUD_GetPlayerScreenPt(local_40);
  if (local_40[0].vy < 0x48) {
    local_40[0].vy = 0x48;
  }
  iVar6 = 0;
  iVar2 = (int)*(short *)((int)pvVar5 + 0x92);
  uVar3 = (int)*(short *)((int)pvVar5 + 0x96) + 0xc00;
  do {
    uVar3 = uVar3 & 0xfff;
    current = (short)uVar3;
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
    glyphnum = rcos(uVar3);
    local_48.x = local_40[0].vx + (short)(glyphnum * iVar2 >> 0xc);
    glyphnum = rsin(uVar3);
    glyphnum = glyphnum * iVar2 >> 0xc;
    glyph = iVar6 + 1;
    if (glyphnum < 0) {
      glyphnum = glyphnum + 7;
    }
    local_48.y = local_40[0].vy - (short)(glyphnum >> 3);
    glyphnum = _GlyphIsGlyphSet(glyph);
    if (glyphnum == 0) {
      glyphnum = 7;
      if (glyph == 7) goto LAB_8007a20c;
      enabled = 1;
    }
    else {
      glyphnum = _GlyphIsGlyphUsable(glyph);
      if (glyphnum == 0) {
LAB_8007a20c:
        enabled = 0;
        glyphnum = iVar6;
      }
      else {
        glyphnum = _GlyphCost(glyphtunedata,glyph);
        enabled = (uint)(HudSave.MANNA_Count < glyphnum) ^ 1;
        glyphnum = iVar6;
      }
    }
    iVar4 = (int)glyphtunedata->glyph_size * (iVar4 >> 0xc);
    if (iVar4 < 0) {
      iVar4 = iVar4 + 0x1fff;
    }
    uVar3 = uVar3 - 0x249;
    iVar6 = iVar6 + 1;
    FX_MakeGlyphIcon(&local_48,instance->object,iVar4 >> 0xd,glyphnum,enabled);
    if (6 < iVar6) {
      iVar6 = (int)*(short *)((int)pvVar5 + 0x90);
      if (iVar6 == 0x1000) {
        if ((*(short *)((int)pvVar5 + 0x98) == *(short *)((int)pvVar5 + 0x96)) &&
           (iVar6 = _GlyphCost(glyphtunedata,*(int *)((int)pvVar5 + 0x8c)),
           iVar6 <= HudSave.MANNA_Count)) {
          local_38.x = (int)local_40[0].vx;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 7;
          }
          local_38.y = (int)local_40[0].vy + (iVar2 >> 3);
          DRAW_CreateAGlowingCircle
                    (&local_38,0x140,gameTrackerX.primPool,(ulong **)gameTrackerX.defVVRemoveDist,5,
                     0x1404040,0x1a,0x18,0);
        }
        iVar6 = (int)*(short *)((int)pvVar5 + 0x90);
      }
      uVar3 = iVar6 / (int)glyphtunedata->glyph_darkness;
      FX_DrawScreenPoly(2,uVar3 | uVar3 << 0x10 | uVar3 << 8,0x20);
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// long /*$ra*/ GlyphTime(int time /*$a0*/)
 // line 480, offset 0x8007a358
	/* begin block 1 */
		// Start line: 1143
	/* end block 1 */
	// End Line: 1144

	/* begin block 2 */
		// Start line: 1144
	/* end block 2 */
	// End Line: 1145

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
 // line 487, offset 0x8007a374
	/* begin block 1 */
		// Start line: 488
		// Start offset: 0x8007A374
		// Variables:
	// 		struct __GlyphData *data; // $s0
	// 		int time; // $a0
	// 		short accl; // stack offset -24
	/* end block 1 */
	// End offset: 0x8007A438
	// End Line: 517

	/* begin block 2 */
		// Start line: 1157
	/* end block 2 */
	// End Line: 1158

void ShrinkGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24 [4];
  
  pvVar3 = instance->extraData;
  gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffefffff;
  if (*(short *)((int)pvVar3 + 0x90) < 1) {
    glyph_cost = -1;
  }
  else {
    iVar1 = (uint)*(ushort *)((int)pvVar3 + 0x90) - ((gameTrackerX.idleTime << 9) >> 0xc);
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
  CriticalDampValue(5,&MANNA_Position,-0x40,&MANNA_Pos_vel,asStack24,0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EnlargeGlyphMenu(struct _Instance *instance /*$s1*/)
 // line 520, offset 0x8007a478
	/* begin block 1 */
		// Start line: 521
		// Start offset: 0x8007A478
		// Variables:
	// 		struct __GlyphData *data; // $s0
	// 		int time; // $a1
	// 		short accl; // stack offset -24
	/* end block 1 */
	// End offset: 0x8007A520
	// End Line: 544

	/* begin block 2 */
		// Start line: 1238
	/* end block 2 */
	// End Line: 1239

void EnlargeGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24 [4];
  
  pvVar3 = instance->extraData;
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x100000;
  if (*(short *)((int)pvVar3 + 0x90) < 0x1000) {
    iVar1 = (uint)*(ushort *)((int)pvVar3 + 0x90) + ((gameTrackerX.idleTime << 9) >> 0xc);
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
  CriticalDampValue(5,&MANNA_Position,0x30,&MANNA_Pos_vel,asStack24,0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphOffProcess(struct _Instance *instance /*$s0*/, int data1 /*$s3*/, int data2 /*$s4*/)
 // line 554, offset 0x8007a570
	/* begin block 1 */
		// Start line: 555
		// Start offset: 0x8007A570
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $s2
	/* end block 1 */
	// End offset: 0x8007A640
	// End Line: 582

	/* begin block 2 */
		// Start line: 1318
	/* end block 2 */
	// End Line: 1319

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
    if (puVar2 != (undefined *)0x100001) {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == &DAT_80000010) {
          _GlyphSwitchProcess(instance,_GlyphSelectProcess);
          SndPlayVolPan(0x13,0x7f,0x40,0);
        }
        else {
LAB_8007a628:
          _GlyphDefaultProcess(instance,data1,data2);
        }
      }
      else {
        if (puVar2 != (undefined *)0x100004) goto LAB_8007a628;
      }
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphSelectProcess(struct _Instance *instance /*$s4*/, int data1 /*$s7*/, int data2 /*$fp*/)
 // line 587, offset 0x8007a668
	/* begin block 1 */
		// Start line: 588
		// Start offset: 0x8007A668
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $s0
	// 		struct _GlyphTuneData *glyphtunedata; // $s5
	// 		int dontdraw_flag; // $s3

		/* begin block 1.1 */
			// Start line: 671
			// Start offset: 0x8007AAD4
		/* end block 1.1 */
		// End offset: 0x8007AAD4
		// End Line: 674
	/* end block 1 */
	// End offset: 0x8007AB0C
	// End Line: 689

	/* begin block 2 */
		// Start line: 1384
	/* end block 2 */
	// End Line: 1385

void _GlyphSelectProcess(_Instance *instance,int data1,int data2)

{
  bool bVar1;
  ushort vol;
  short sVar2;
  __Event *p_Var3;
  int iVar4;
  undefined *puVar5;
  uint sample;
  void *pvVar6;
  _GlyphTuneData *glyphtunedata;
  
  bVar1 = false;
  pvVar6 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  do {
    p_Var3 = PeekMessageQueue((__MessageQueue *)((int)pvVar6 + 4));
    if (p_Var3 == (__Event *)0x0) {
      if (!bVar1) {
        iVar4 = _GlyphCost(glyphtunedata,*(int *)((int)pvVar6 + 0x8c));
        glyph_cost = (short)iVar4;
        EnlargeGlyphMenu(instance);
      }
      Glyph_DoFX(instance);
      return;
    }
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 == (undefined *)0x100004) {
      bVar1 = true;
      goto LAB_8007aadc;
    }
    if ((int)puVar5 < 0x100005) {
      if (puVar5 != &DAT_80000010) {
        if ((int)puVar5 < -0x7fffffef) {
          if (puVar5 == (undefined *)0x80000000) {
            if ((fx_going != 0) ||
               (iVar4 = _GlyphIsGlyphSet(*(int *)((int)pvVar6 + 0x8c)), iVar4 == 0))
            goto LAB_8007aadc;
            iVar4 = _GlyphCost(glyphtunedata,*(int *)((int)pvVar6 + 0x8c));
            sample = 0x12;
            if (iVar4 <= HudSave.MANNA_Count) {
              iVar4 = _GlyphIsGlyphUsable(*(int *)((int)pvVar6 + 0x8c));
              if (iVar4 != 0) {
                bVar1 = true;
                _GlyphSwitchProcess(instance,_GlyphGenericProcess);
                goto LAB_8007aadc;
              }
              sample = 0x12;
            }
LAB_8007aabc:
            vol = 100;
            goto LAB_8007aac0;
          }
        }
        else {
          if (puVar5 == (undefined *)0x100001) {
            bVar1 = true;
            *(undefined4 *)((int)pvVar6 + 0x8c) = 7;
            *(undefined2 *)((int)pvVar6 + 0x98) = 0xdb6;
            *(undefined2 *)((int)pvVar6 + 0x96) = 0xdb6;
            *(undefined2 *)((int)pvVar6 + 0x96) = *(undefined2 *)((int)pvVar6 + 0x98);
            goto LAB_8007aadc;
          }
        }
        goto LAB_8007aad4;
      }
      bVar1 = true;
      _GlyphSwitchProcess(instance,_GlyphOffProcess);
      sample = 0x11;
      vol = 0x7f;
LAB_8007aac0:
      SndPlayVolPan(sample,vol,0x40,0);
    }
    else {
      if (puVar5 == (undefined *)0x10000002) {
        iVar4 = _GlyphIsAnyGlyphSet();
        if (iVar4 != 0) {
          vol = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
          if ((int)((uint)vol << 0x10) < 0) {
            sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
            if (-(int)sVar2 < 0x40) goto LAB_8007a980;
          }
          else {
            sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
            if (sVar2 < 0x40) {
LAB_8007a980:
              do {
                *(undefined2 *)((int)pvVar6 + 0x9a) = 1;
                iVar4 = *(int *)((int)pvVar6 + 0x8c) + 1;
                *(int *)((int)pvVar6 + 0x8c) = iVar4;
                if (7 < iVar4) {
                  *(undefined4 *)((int)pvVar6 + 0x8c) = 1;
                }
                *(short *)((int)pvVar6 + 0x98) = ((short)*(int *)((int)pvVar6 + 0x8c) + -1) * 0x249;
                iVar4 = _GlyphIsGlyphSet(*(int *)((int)pvVar6 + 0x8c));
              } while (iVar4 == 0);
              vol = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
              if ((int)((uint)vol << 0x10) < 0) {
                sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
                sample = 0x14;
                if (0x3f < -(int)sVar2) {
                  vol = 100;
                  goto LAB_8007aac0;
                }
              }
              else {
                sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
joined_r0x8007a8bc:
                sample = 0x14;
                if (0x3f < sVar2) goto LAB_8007aabc;
              }
            }
          }
        }
      }
      else {
        if ((int)puVar5 < 0x10000003) {
          if (puVar5 == (undefined *)0x200001) goto LAB_8007aadc;
        }
        else {
          if (puVar5 == (undefined *)0x10000004) {
            iVar4 = _GlyphIsAnyGlyphSet();
            if (iVar4 != 0) {
              vol = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
              if ((int)((uint)vol << 0x10) < 0) {
                sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
                if (-(int)sVar2 < 0x40) goto LAB_8007a83c;
              }
              else {
                sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
                if (sVar2 < 0x40) {
LAB_8007a83c:
                  do {
                    *(undefined2 *)((int)pvVar6 + 0x9a) = 0xffff;
                    iVar4 = *(int *)((int)pvVar6 + 0x8c) + -1;
                    *(int *)((int)pvVar6 + 0x8c) = iVar4;
                    if (iVar4 < 1) {
                      *(undefined4 *)((int)pvVar6 + 0x8c) = 7;
                    }
                    *(short *)((int)pvVar6 + 0x98) =
                         ((short)*(int *)((int)pvVar6 + 0x8c) + -1) * 0x249;
                    iVar4 = _GlyphIsGlyphSet(*(int *)((int)pvVar6 + 0x8c));
                  } while (iVar4 == 0);
                  vol = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
                  if (-1 < (int)((uint)vol << 0x10)) {
                    sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98))
                    ;
                    goto joined_r0x8007a8bc;
                  }
                  sVar2 = AngleDiff(*(short *)((int)pvVar6 + 0x96),*(short *)((int)pvVar6 + 0x98));
                  sample = 0x14;
                  if (0x3f < -(int)sVar2) {
                    vol = 100;
                    goto LAB_8007aac0;
                  }
                }
              }
            }
            goto LAB_8007aadc;
          }
        }
LAB_8007aad4:
        _GlyphDefaultProcess(instance,data1,data2);
      }
    }
LAB_8007aadc:
    DeMessageQueue((__MessageQueue *)((int)pvVar6 + 4));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_StartSpell(struct _Instance *instance /*$a0*/, int glyphnum /*$a1*/)
 // line 695, offset 0x8007ab44
	/* begin block 1 */
		// Start line: 696
		// Start offset: 0x8007AB44
		// Variables:
	// 		int message; // $a2
	/* end block 1 */
	// End offset: 0x8007ABCC
	// End Line: 729

	/* begin block 2 */
		// Start line: 1633
	/* end block 2 */
	// End Line: 1634

void Glyph_StartSpell(_Instance *instance,int glyphnum)

{
  int Message;
  
  Message = 0;
  switch(glyphnum) {
  case 1:
    Message = 0x80001;
    break;
  case 2:
    Message = 0x80002;
    break;
  case 3:
    Message = 0x80003;
    break;
  case 4:
    Message = 0x80004;
    break;
  case 5:
    Message = 0x80005;
    break;
  case 6:
    Message = 0x80006;
    break;
  case 7:
    Message = 0x80007;
  }
  INSTANCE_Post(gameTrackerX.playerInstance,Message,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_Broadcast(struct _Instance *sender /*$s5*/, int glyphnum /*$a1*/)
 // line 732, offset 0x8007abec
	/* begin block 1 */
		// Start line: 733
		// Start offset: 0x8007ABEC
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		int plane; // $s6
	// 		long whatAmIMask; // $s3
	// 		int Message; // $s2
	// 		int Data; // $s7
	// 		int dist; // $v1
	// 		int fx_radius; // $s4

		/* begin block 1.1 */
			// Start line: 783
			// Start offset: 0x8007ACD0
			// Variables:
		// 		long whatAmI; // $s1
		/* end block 1.1 */
		// End offset: 0x8007AD84
		// End Line: 801
	/* end block 1 */
	// End offset: 0x8007AD94
	// End Line: 802

	/* begin block 2 */
		// Start line: 1707
	/* end block 2 */
	// End Line: 1708

void Glyph_Broadcast(_Instance *sender,int glyphnum)

{
  ulong uVar1;
  int iVar2;
  _Instance *Inst;
  int Message;
  uint uVar3;
  int iVar4;
  int plane;
  
  uVar3 = 0;
  Message = 0;
  plane = (int)gameTrackerX.gameData.asmData.MorphType;
  iVar4 = fx_blastring->radius;
  switch(glyphnum) {
  case 1:
    uVar3 = 2;
    Message = 0x80001;
    break;
  case 2:
    uVar3 = 2;
    Message = 0x80002;
    break;
  case 3:
    uVar3 = 0x2a;
    Message = 0x80003;
    break;
  case 4:
    uVar3 = 10;
    Message = 0x80004;
    break;
  case 5:
    uVar3 = 10;
    Message = 0x80005;
    break;
  case 6:
    uVar3 = 2;
    Message = 0x80006;
    break;
  case 7:
    goto switchD_8007ac54_caseD_7;
  }
  Inst = (gameTrackerX.instanceList)->first;
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
        INSTANCE_Post(Inst,Message,0);
      }
    }
    Inst = Inst->next;
  }
switchD_8007ac54_caseD_7:
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_DoSpell(struct _Instance *instance /*stack 0*/, int glyphnum /*$s1*/)
 // line 804, offset 0x8007adc0
	/* begin block 1 */
		// Start line: 805
		// Start offset: 0x8007ADC0
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
	// End offset: 0x8007B02C
	// End Line: 904

	/* begin block 2 */
		// Start line: 1900
	/* end block 2 */
	// End Line: 1901

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
  MATRIX MStack80;
  long local_30;
  
  radius = 0;
  vel = 0;
  height1 = 0;
  height2 = 0;
  height3 = 0;
  size1 = 0;
  size2 = 0;
  pvVar1 = instance->object->data;
  fx_going = 0;
  local_30 = 0;
  MATH3D_SetUnityMatrix(&MStack80);
  fx_radius_old = 0;
  blast_range = (int)*(short *)((int)pvVar1 + (glyphnum + -1) * 2 + 0xc);
  pred_offset = 0;
  colorChangeRadius = blast_range;
  if (blast_range < 0) {
    colorChangeRadius = blast_range + 3;
  }
  colorChangeRadius = blast_range - (colorChangeRadius >> 2);
  startColor = local_30;
  switch(glyphnum) {
  case 1:
    radius = 1;
    startColor = 0xffffff;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    vel = 0x100000;
    size1 = 0x280;
    fx_going = 1;
    size2 = 0x340;
    break;
  case 2:
    radius = 1;
    startColor = 0xff0000;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    vel = 0x100000;
    size1 = 0x280;
    fx_going = 2;
    size2 = 0x340;
    break;
  case 3:
    radius = 1;
    vel = 0x100000;
    startColor = 0xff;
    height1 = -0x200;
    height2 = 0;
    height3 = 0x200;
    size1 = 0x280;
    fx_going = 3;
    size2 = 0x340;
    break;
  case 4:
    CAMERA_SetShake(&theCamera,0x3c,0x800);
    radius = 0x280;
    vel = 0x140000;
    startColor = 0xa0a0a0;
    height3 = 0;
    height2 = 0;
    height1 = 0;
    size1 = 0x280;
    fx_going = 4;
    size2 = 0x340;
    break;
  case 5:
    radius = 1;
    startColor = 0xc0c0c0;
    height1 = -0x100;
    height2 = 0x100;
    height3 = 0x300;
    vel = 0x200000;
    size1 = -0x280;
    fx_going = 5;
    size2 = 0;
    break;
  case 6:
    radius = 1;
    startColor = 0xffffff;
    height1 = 0;
    height2 = 0x40;
    height3 = 0x80;
    vel = 0x100000;
    size1 = 0x280;
    size2 = 0x340;
    fx_going = 6;
    pred_offset = 5;
  }
  if ((fx_going != 0) &&
     (fx_blastring = FX_DoBlastRing((_Instance *)0x0,(_SVector *)&instance->position,&MStack80,-1,
                                    radius,blast_range,colorChangeRadius,size1,size2,vel,-0x800,
                                    height1,height2,height3,startColor,0,pred_offset,-99,0),
     fx_blastring == (_FXBlastringEffect *)0x0)) {
    fx_going = 0;
  }
  blast_range = blast_range << 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_EndFX()
 // line 907, offset 0x8007b068
	/* begin block 1 */
		// Start line: 2142
	/* end block 1 */
	// End Line: 2143

	/* begin block 2 */
		// Start line: 2143
	/* end block 2 */
	// End Line: 2144

/* WARNING: Unknown calling convention yet parameter storage is locked */

void Glyph_EndFX(void)

{
  _FXBlastringEffect *p_Var1;
  
  p_Var1 = fx_blastring;
  fx_going = 0;
  fx_blastring = (_FXBlastringEffect *)0x0;
  p_Var1->lifeTime = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ Glyph_DoFX(struct _Instance *instance /*$a0*/)
 // line 914, offset 0x8007b07c
	/* begin block 1 */
		// Start line: 2154
	/* end block 1 */
	// End Line: 2155

	/* begin block 2 */
		// Start line: 2158
	/* end block 2 */
	// End Line: 2159

void Glyph_DoFX(_Instance *instance)

{
  int *piVar1;
  _FXBlastringEffect *p_Var2;
  
  if (((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) &&
     ((int)fx_going != 0)) {
    Glyph_Broadcast(instance,(int)fx_going);
    fx_radius_old = fx_blastring->radius;
    if (blast_range < fx_radius_old) {
      Glyph_EndFX();
    }
    p_Var2 = fx_blastring;
    if (fx_going == 3) {
      piVar1 = &fx_blastring->height2;
      fx_blastring->accl = fx_blastring->accl + -0x3c;
      p_Var2->height2 = *piVar1 + 0x3c;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _GlyphGenericProcess(struct _Instance *instance /*$s1*/, int data1 /*$s3*/, int data2 /*$s4*/)
 // line 947, offset 0x8007b12c
	/* begin block 1 */
		// Start line: 948
		// Start offset: 0x8007B12C
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		struct __GlyphData *data; // $s0
	/* end block 1 */
	// End offset: 0x8007B210
	// End Line: 980

	/* begin block 2 */
		// Start line: 2228
	/* end block 2 */
	// End Line: 2229

void _GlyphGenericProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  int iVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  do {
    p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
    if (p_Var1 == (__Event *)0x0) {
      if (glyph_trigger != 0) {
        Glyph_DoSpell(instance,*(int *)((int)pvVar3 + 0x8c));
        glyph_trigger = 0;
      }
      Glyph_DoFX(instance);
      ShrinkGlyphMenu(instance);
      return;
    }
    iVar2 = p_Var1->ID;
    if (iVar2 == 0x100001) {
      Glyph_StartSpell(instance,*(int *)((int)pvVar3 + 0x8c));
    }
    else {
      if (iVar2 < 0x100002) {
        if (iVar2 == -0x80000000) {
          _GlyphSwitchProcess(instance,_GlyphOffProcess);
        }
        else {
LAB_8007b1d8:
          _GlyphDefaultProcess(instance,data1,data2);
        }
      }
      else {
        if (iVar2 != 0x100004) goto LAB_8007b1d8;
      }
    }
    DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ GlyphTrigger()
 // line 985, offset 0x8007b240
	/* begin block 1 */
		// Start line: 2312
	/* end block 1 */
	// End Line: 2313

	/* begin block 2 */
		// Start line: 2313
	/* end block 2 */
	// End Line: 2314

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GlyphTrigger(void)

{
  if (fx_going == 0) {
    glyph_trigger = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MANNA_Pickup(struct _Instance *instance /*$a0*/, int amount /*$a1*/)
 // line 1002, offset 0x8007b25c
	/* begin block 1 */
		// Start line: 2346
	/* end block 1 */
	// End Line: 2347

	/* begin block 2 */
		// Start line: 2347
	/* end block 2 */
	// End Line: 2348

void MANNA_Pickup(_Instance *instance,int amount)

{
  HudSave.MANNA_Count = HudSave.MANNA_Count + (short)amount;
  INSTANCE_KillInstance(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HEALTHU_Pickup(struct _Instance *instance /*$s0*/)
 // line 1008, offset 0x8007b288
	/* begin block 1 */
		// Start line: 2359
	/* end block 1 */
	// End Line: 2360

void HEALTHU_Pickup(_Instance *instance)

{
  ApplyMatrixSV(theCamera.core.wcTransform2,&instance->position,&HUD_Cap_Pos);
  HUD_Cap_Pos.x = HUD_Cap_Pos.x + *(short *)(theCamera.core.wcTransform2)->t;
  HUD_Cap_Pos.y = HUD_Cap_Pos.y + *(short *)((theCamera.core.wcTransform2)->t + 1);
  HUD_Cap_Vel.z = 0;
  HUD_Cap_Vel.y = 0;
  HUD_Cap_Vel.x = 0;
  HUD_Cap_Pos.z = HUD_Cap_Pos.z + *(short *)((theCamera.core.wcTransform2)->t + 2);
  INSTANCE_KillInstance(instance);
  HUD_Captured = 1;
  HUD_State = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Damp(short *val /*$v1*/, short target /*$a1*/, short *vel /*$a3*/, short max /*$a3*/)
 // line 1024, offset 0x8007b318
	/* begin block 1 */
		// Start line: 1025
		// Start offset: 0x8007B318
		// Variables:
	// 		short accl; // stack offset -16
	/* end block 1 */
	// End offset: 0x8007B318
	// End Line: 1025

	/* begin block 2 */
		// Start line: 2394
	/* end block 2 */
	// End Line: 2395

void HUD_Damp(short *val,short target,short *vel,short max)

{
  short asStack16 [4];
  
  CriticalDampValue(1,val,target,vel,asStack16,(int)max);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUD_Init()
 // line 1031, offset 0x8007b360
	/* begin block 1 */
		// Start line: 2414
	/* end block 1 */
	// End Line: 2415

	/* begin block 2 */
		// Start line: 2420
	/* end block 2 */
	// End Line: 2421

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Init(void)

{
  HudSave.MANNA_Count = 0;
  HudSave.HUD_Count = 0;
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
// void /*$ra*/ HUD_Update()
 // line 1046, offset 0x8007b398
	/* begin block 1 */
		// Start line: 1047
		// Start offset: 0x8007B398
		// Variables:
	// 		short accl; // stack offset -16
	/* end block 1 */
	// End offset: 0x8007B5A0
	// End Line: 1127

	/* begin block 2 */
		// Start line: 2449
	/* end block 2 */
	// End Line: 2450

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Update(void)

{
  bool bVar1;
  short sVar2;
  short asStack16 [4];
  
  if ((gameTrackerX.gameMode == 6) && (HUD_State == 0)) {
    HUD_State = 10;
  }
  if ((gameTrackerX.gameMode != 6) && ((uint)(ushort)HUD_State - 10 < 2)) {
    HUD_State = 0xc;
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
      if (HudSave.HUD_Count == 5) {
        HudSave.HUD_Count = 0;
      }
      break;
    case 1:
    case 10:
      HUD_Damp(&HUD_Position,0,&HUD_Pos_vel,0x60);
      if (-1 < HUD_Position) {
        HUD_Position = 0;
        bVar1 = HUD_State != 10;
        HUD_State = 0xb;
        if ((bVar1) && (HUD_State = 2, HudSave.HUD_Count < 1)) {
          HUD_State = 3;
        }
      }
      sVar2 = HUD_Wait;
      if (HUD_State == 10) {
        CriticalDampValue(5,&MANNA_Position,0x30,&MANNA_Pos_vel,asStack16,0xc);
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
      HudSave.HUD_Count = HudSave.HUD_Count + 1;
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
 // line 1136, offset 0x8007b5b0
	/* begin block 1 */
		// Start line: 1137
		// Start offset: 0x8007B5B0
		// Variables:
	// 		struct _SVector Rotation; // stack offset -72
	// 		struct _SVector Pos; // stack offset -64
	// 		struct _SVector offset; // stack offset -56
	// 		int n; // $s0

		/* begin block 1.1 */
			// Start line: 1143
			// Start offset: 0x8007B5E4
			// Variables:
		// 		struct DVECTOR center; // stack offset -48
		// 		int glow; // $a1
		// 		int left; // $t0
		// 		int right; // $s0
		/* end block 1.1 */
		// End offset: 0x8007B758
		// End Line: 1181

		/* begin block 1.2 */
			// Start line: 1202
			// Start offset: 0x8007B7F0
			// Variables:
		// 		struct _SVector targetPos; // stack offset -40
		// 		struct _SVector accl; // stack offset -32
		// 		struct _SVector HUD_Cap_Rot; // stack offset -24
		/* end block 1.2 */
		// End offset: 0x8007B8D4
		// End Line: 1223

		/* begin block 1.3 */
			// Start line: 1231
			// Start offset: 0x8007B91C
		/* end block 1.3 */
		// End offset: 0x8007B960
		// End Line: 1241
	/* end block 1 */
	// End offset: 0x8007B9B4
	// End Line: 1250

	/* begin block 2 */
		// Start line: 2641
	/* end block 2 */
	// End Line: 2642

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Draw(void)

{
  bool bVar1;
  int fade;
  int iVar2;
  int fade_00;
  uint uVar3;
  undefined **ppuVar4;
  _SVector local_48;
  _SVector local_40;
  _SVector local_38;
  DVECTOR local_30 [2];
  _Position local_28;
  _SVector _Stack32;
  _SVector local_18;
  
  if ((theCamera.instance_mode & 0x80000000) == 0) {
    if (warpDraw == 0) goto LAB_8007b758;
    warpDraw = warpDraw - (gameTrackerX.idleTime >> 4);
    if (warpDraw < 0) {
      warpDraw = 0;
    }
  }
  else {
    warpDraw = warpDraw + (gameTrackerX.idleTime >> 4);
    if (0x1000 < warpDraw) {
      warpDraw = 0x1000;
    }
  }
  HUD_GetPlayerScreenPt(local_30);
  fade = rcos(glowdeg);
  fade = (warpDraw / 10) * fade;
  if (fade < 0) {
    fade = fade + 0xfff;
  }
  fade = warpDraw / 3 + (fade >> 0xc);
  if (fade < 0) {
    fade = 0;
  }
  glowdeg = glowdeg + (gameTrackerX.idleTime >> 5);
  fade_00 = fade;
  if (hud_warp_arrow_flash < 1) {
LAB_8007b6e4:
    if (hud_warp_arrow_flash < 0) {
      iVar2 = hud_warp_arrow_flash + (gameTrackerX.idleTime >> 3);
      fade = fade - hud_warp_arrow_flash;
      hud_warp_arrow_flash = iVar2;
      if (0 < iVar2) {
        hud_warp_arrow_flash = 0;
      }
    }
  }
  else {
    iVar2 = hud_warp_arrow_flash - (gameTrackerX.idleTime >> 3);
    fade_00 = fade + hud_warp_arrow_flash;
    hud_warp_arrow_flash = iVar2;
    if (iVar2 < 0) {
      hud_warp_arrow_flash = 0;
      goto LAB_8007b6e4;
    }
  }
  FX_MakeWarpArrow((int)local_30[0].vx + -0x40,(int)local_30[0].vy,-0x40,0x20,fade);
  FX_MakeWarpArrow((int)local_30[0].vx + 0x40,(int)local_30[0].vy,0x40,0x20,fade_00);
LAB_8007b758:
  HUD_Update();
  local_38.x = 0;
  local_38.y = 0;
  local_38.z = 0x87;
  if (-0x40 < (int)MANNA_Position) {
    FX_MakeMannaIcon((int)MANNA_Position,0x14,0x33,0x20);
    FX_DrawNumber((int)MANNA_Position + 0x37,0x1c,(int)HudSave.MANNA_Count,0x808080);
    if ((int)glyph_cost != -1) {
      FX_DrawNumber((int)MANNA_Position + 0x11,0x1c,(int)glyph_cost,0x808080);
    }
  }
  if (-1000 < HUD_Position) {
    if (HUD_Captured != 0) {
      local_18.x = 0x400;
      local_28.x = -0x600;
      local_18.y = 0;
      local_18.z = 0;
      local_28.z = 0xa00;
      if (HUD_State < 4) {
        local_28.y = 0x140;
      }
      else {
        local_28.y = 0x280;
      }
      CriticalDampPosition(1,(_Position *)&HUD_Cap_Pos,&local_28,&HUD_Cap_Vel,&_Stack32,0x80);
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
      FX_DrawModel((Object *)(void *)0x0,0,&local_18,&HUD_Cap_Pos,&local_38,0);
    }
    uVar3 = 0;
    ppuVar4 = &PTR_LAB_80011c84;
    local_48.x = 0x400;
    local_40.y = 0x280;
    local_48.y = 0;
    local_40.z = 0xa00;
    local_38.z = 0;
    local_40.x = HUD_Position + -0x600;
    local_48.z = HUD_Rotation;
    bVar1 = true;
    do {
      if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x8007b930. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)*ppuVar4)();
        return;
      }
      ppuVar4 = (code **)ppuVar4 + 1;
      local_48.z = local_48.z - HUD_Rotation & 0xfff;
      FX_DrawModel((Object *)(void *)0x0,0,&local_48,&local_40,&local_38,
                   (uint)((int)uVar3 < (int)HudSave.HUD_Count) ^ 1);
      uVar3 = uVar3 + 1;
      bVar1 = uVar3 < 5;
    } while ((int)uVar3 < 5);
  }
  return;
}





