#include "THISDUST.H"
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

void GlyphInit(_Instance *instance,GameTracker *gameTracker)

{
  if ((instance->flags & 0x20000U) != 0) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)instance->extraData);
  }
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x9c,'\x1d');
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

void GlyphPost(_Instance *instance,ulong message,ulong messageData)

{
  if ((undefined *)message != &DAT_00100007) {
                    /* WARNING: Subroutine does not return */
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

void _GlyphSwitchProcess(_Instance *instance,TDRFuncPtr__GlyphSwitchProcess1process process)

{
  __MessageQueue *In;
  
  In = (__MessageQueue *)((int)instance->extraData + 4);
  PurgeMessageQueue(In);
                    /* WARNING: Subroutine does not return */
  EnMessageQueueData(In,(int)&DAT_00100004,0);
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

int _GlyphIsGlyphSet(int glyph)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(gameTrackerX.playerInstance,0x24);
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsGlyphUsable(int glyph /*$s0*/)
 // line 294, offset 0x8007a51c
	/* begin block 1 */
		// Start line: 645
	/* end block 1 */
	// End Line: 646

int _GlyphIsGlyphUsable(int glyph)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(gameTrackerX.playerInstance,0x13);
}



// decompiled code
// original method signature: 
// int /*$ra*/ _GlyphIsAnyGlyphSet()
 // line 298, offset 0x8007a558
	/* begin block 1 */
		// Start line: 654
	/* end block 1 */
	// End Line: 655

/* WARNING: Unknown calling convention yet parameter storage is locked */

int _GlyphIsAnyGlyphSet(void)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(gameTrackerX.playerInstance,0x24);
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

void _GlyphDefaultProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  __MessageQueue *In;
  
  In = (__MessageQueue *)((int)instance->extraData + 4);
  p_Var1 = PeekMessageQueue(In);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  if ((undefined *)p_Var1->ID == &DAT_80000010) {
    _GlyphSwitchProcess(instance,_GlyphSelectProcess);
                    /* WARNING: Subroutine does not return */
    SndPlayVolPan(0x11,0x7f,0x40,0);
  }
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(In);
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

void HUD_GetPlayerScreenPt(DVECTOR *center)

{
  PushMatrix();
                    /* WARNING: Subroutine does not return */
  SetRotMatrix((undefined4 *)theCamera.core.wcTransform);
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

void GlyphDrawMenu(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  INSTANCE_Query(gameTrackerX.playerInstance,0x20);
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
    iVar1 = (uint)*(ushort *)((int)pvVar3 + 0x90) - ((gameTrackerX.timeMult << 9) >> 0xc);
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
    MANNA_Pickup_Time = MANNA_Pickup_Time - gameTrackerX.timeMult;
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

void EnlargeGlyphMenu(_Instance *instance)

{
  int iVar1;
  long lVar2;
  void *pvVar3;
  short asStack24 [4];
  
  pvVar3 = instance->extraData;
  gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x100000;
  if (*(short *)((int)pvVar3 + 0x90) < 0x1000) {
    iVar1 = (uint)*(ushort *)((int)pvVar3 + 0x90) + ((gameTrackerX.timeMult << 9) >> 0xc);
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

void _GlyphOffProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  undefined *puVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  ShrinkGlyphMenu(instance);
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
                    /* WARNING: Subroutine does not return */
        SndPlayVolPan(0x11,0x7f,0x40,0);
      }
    }
    else {
      if (puVar2 == &DAT_00100004) goto LAB_8007ad28;
    }
    _GlyphDefaultProcess(instance,data1,data2);
  }
LAB_8007ad28:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
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

void _GlyphSelectProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  int iVar2;
  undefined *puVar3;
  uint sample;
  ushort vol;
  void *pvVar4;
  _GlyphTuneData *glyphtunedata;
  
  pvVar4 = instance->extraData;
  glyphtunedata = (_GlyphTuneData *)instance->object->data;
  p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar4 + 4));
  if (p_Var1 == (__Event *)0x0) {
    iVar2 = _GlyphCost(glyphtunedata,(int)*(short *)((int)pvVar4 + 0x8c));
    glyph_cost = (short)iVar2;
    EnlargeGlyphMenu(instance);
    Glyph_DoFX(instance);
    return;
  }
  puVar3 = (undefined *)p_Var1->ID;
  if (puVar3 == &DAT_00100001) {
    *(undefined2 *)((int)pvVar4 + 0x8c) = 7;
    *(undefined2 *)((int)pvVar4 + 0x98) = 0xdb6;
    *(short *)((int)pvVar4 + 0x96) = (*(short *)((int)pvVar4 + 0x8c) + -1) * 0x249;
    *(undefined2 *)((int)pvVar4 + 0x96) = *(undefined2 *)((int)pvVar4 + 0x98);
  }
  else {
    if ((int)puVar3 < 0x100002) {
      if (puVar3 == (undefined *)0x80000000) {
        if ((fx_going == 0) &&
           (iVar2 = _GlyphIsGlyphSet((int)*(short *)((int)pvVar4 + 0x8c)), iVar2 != 0)) {
                    /* WARNING: Subroutine does not return */
          INSTANCE_Query(gameTrackerX.playerInstance,0x20);
        }
        sample = 0x10;
        vol = 100;
LAB_8007b1a4:
                    /* WARNING: Subroutine does not return */
        SndPlayVolPan(sample,vol,0x40,0);
      }
      if (puVar3 == &DAT_80000010) {
        _GlyphSwitchProcess(instance,_GlyphOffProcess);
        sample = 0xf;
        vol = 0x7f;
        goto LAB_8007b1a4;
      }
    }
    else {
      if (puVar3 == (undefined *)0x10000002) {
        iVar2 = _GlyphIsAnyGlyphSet();
        if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          AngleDiff(*(short *)((int)pvVar4 + 0x96),*(short *)((int)pvVar4 + 0x98));
        }
        goto LAB_8007b1c4;
      }
      if ((int)puVar3 < 0x10000003) {
        if (puVar3 == &DAT_00100004) goto LAB_8007b1c4;
      }
      else {
        if (puVar3 == (undefined *)0x10000004) {
          iVar2 = _GlyphIsAnyGlyphSet();
          if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
            AngleDiff(*(short *)((int)pvVar4 + 0x96),*(short *)((int)pvVar4 + 0x98));
          }
          goto LAB_8007b1c4;
        }
      }
    }
    _GlyphDefaultProcess(instance,data1,data2);
  }
LAB_8007b1c4:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)pvVar4 + 4));
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
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(gameTrackerX.playerInstance,Message,0);
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

void Glyph_Broadcast(_Instance *sender,int glyphnum)

{
  switch(glyphnum) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    goto switchD_8007b338_caseD_7;
  }
  if ((gameTrackerX.instanceList)->first != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
    INSTANCE_Query((gameTrackerX.instanceList)->first,1);
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

void Glyph_DoSpell(_Instance *instance,int glyphnum)

{
  int colorChangeRadius;
  long startColor;
  void *pvVar1;
  int pred_offset;
  int size2;
  int size1;
  int height3;
  undefined *vel;
  int height2;
  int height1;
  int radius;
  MATRIX MStack80;
  long lStack48;
  
  radius = 0;
  vel = (undefined *)0x0;
  height1 = 0;
  height2 = 0;
  height3 = 0;
  size1 = 0;
  size2 = 0;
  pvVar1 = instance->object->data;
  fx_going = 0;
  lStack48 = 0;
  MATH3D_SetUnityMatrix(&MStack80);
  fx_radius_old = 0;
  blast_range = (int)*(short *)((int)pvVar1 + (glyphnum + -1) * 2 + 0xc);
  pred_offset = 0;
  colorChangeRadius = blast_range;
  if (blast_range < 0) {
    colorChangeRadius = blast_range + 3;
  }
  colorChangeRadius = blast_range - (colorChangeRadius >> 2);
  startColor = lStack48;
  switch(glyphnum) {
  case 1:
    radius = 1;
    startColor = 0xc0c0c0;
    height1 = -0x100;
    height2 = 0x100;
    height3 = 0x300;
    vel = (undefined *)0x200000;
    size1 = -0x280;
    fx_going = 1;
    size2 = 0;
    break;
  case 2:
    CAMERA_SetShake(&theCamera,0x3c,0x800);
    radius = 0x280;
    vel = &UNK_00140000;
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
    vel = (undefined *)0x100000;
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
    vel = (undefined *)0x100000;
    size1 = 0x280;
    fx_going = 4;
    size2 = 0x340;
    break;
  case 5:
    radius = 1;
    vel = (undefined *)0x100000;
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
    vel = (undefined *)0x100000;
    size1 = 0x280;
    fx_going = 6;
    size2 = 0x340;
  }
  if ((fx_going != 0) &&
     (fx_blastring = FX_DoBlastRing((_Instance *)0x0,(_SVector *)&instance->position,&MStack80,-1,
                                    radius,blast_range,colorChangeRadius,size1,size2,(int)vel,-0x800
                                    ,height1,height2,height3,startColor,0,pred_offset,-99,0),
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
 // line 935, offset 0x8007b760
	/* begin block 1 */
		// Start line: 2216
	/* end block 1 */
	// End Line: 2217

	/* begin block 2 */
		// Start line: 2220
	/* end block 2 */
	// End Line: 2221

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
    if (fx_going == 5) {
      piVar1 = &fx_blastring->height3;
      fx_blastring->height1 = fx_blastring->height1 + -0x3c;
      p_Var2->height3 = *piVar1 + 0x3c;
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

void _GlyphGenericProcess(_Instance *instance,int data1,int data2)

{
  __Event *p_Var1;
  int Data;
  undefined *puVar2;
  _GlyphTuneData *glyphtunedata;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  ShrinkGlyphMenu(instance);
  p_Var1 = PeekMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
  if (p_Var1 == (__Event *)0x0) {
    if (glyph_trigger == 0) {
      Glyph_DoFX(instance);
      return;
    }
    glyphtunedata = (_GlyphTuneData *)instance->object->data;
    Glyph_DoSpell(instance,(int)*(short *)((int)pvVar3 + 0x8c));
    glyph_trigger = 0;
    Data = _GlyphCost(glyphtunedata,(int)*(short *)((int)pvVar3 + 0x8c));
                    /* WARNING: Subroutine does not return */
    INSTANCE_Post(gameTrackerX.playerInstance,0x40008,Data);
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100001) {
    Glyph_StartSpell(instance,(int)*(short *)((int)pvVar3 + 0x8c));
  }
  else {
    if ((int)puVar2 < 0x100002) {
      if (puVar2 == (undefined *)0x80000000) {
        _GlyphSwitchProcess(instance,_GlyphOffProcess);
        goto LAB_8007b8c8;
      }
    }
    else {
      if (puVar2 == &DAT_00100004) goto LAB_8007b8c8;
    }
    _GlyphDefaultProcess(instance,data1,data2);
  }
LAB_8007b8c8:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)((int)pvVar3 + 4));
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

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

void HEALTHU_Pickup(_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  ApplyMatrixSV(theCamera.core.wcTransform2,&instance->position,&HUD_Cap_Pos);
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

/* WARNING: Unknown calling convention yet parameter storage is locked */

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

/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Update(void)

{
  bool bVar1;
  short sVar2;
  short asStack16 [4];
  
  if ((gameTrackerX.gameMode == 6) && (HUD_State == 0)) {
    HUD_State = 10;
  }
  else {
    if (gameTrackerX.gameMode == 6) {
      if ((1 < HUD_State) && (HUD_State < 7)) {
        HUD_Captured = 0;
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
                    /* WARNING: Read-only address (ram,0x800d081c) is written */
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
                    /* WARNING: Read-only address (ram,0x800d081c) is written */
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

/* WARNING: Removing unreachable block (ram,0x8007bfbc) */
/* WARNING: Removing unreachable block (ram,0x8007bfcc) */
/* WARNING: Removing unreachable block (ram,0x8007bffc) */
/* WARNING: Removing unreachable block (ram,0x8007bff4) */
/* WARNING: Removing unreachable block (ram,0x8007c000) */
/* WARNING: Removing unreachable block (ram,0x8007c040) */
/* WARNING: Removing unreachable block (ram,0x8007c050) */
/* WARNING: Removing unreachable block (ram,0x8007c060) */
/* WARNING: Removing unreachable block (ram,0x8007c078) */
/* WARNING: Removing unreachable block (ram,0x8007c080) */
/* WARNING: Removing unreachable block (ram,0x8007c070) */
/* WARNING: Removing unreachable block (ram,0x8007c084) */
/* WARNING: Removing unreachable block (ram,0x8007c08c) */
/* WARNING: Removing unreachable block (ram,0x8007c090) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void HUD_Draw(void)

{
  bool bVar1;
  uint uVar2;
  undefined **ppuVar3;
  _SVector local_50;
  _SVector local_48;
  _SVector local_40;
  DVECTOR local_38 [8];
  
  if ((theCamera.instance_mode & 0x80000000) == 0) {
    if (warpDraw == 0) {
      HUD_Update();
      local_40.x = 0;
      local_40.y = 0;
      local_40.z = 0x87;
      if (-0x40 < MANNA_Position) {
                    /* WARNING: Subroutine does not return */
        INSTANCE_Query(gameTrackerX.playerInstance,0x20);
      }
      if (-1000 < HUD_Position) {
        local_40.y = 0;
        local_40.x = 0;
                    /* WARNING: Read-only address (ram,0x800d4e1c) is written */
                    /* WARNING: Read-only address (ram,0x800d4e1e) is written */
                    /* WARNING: Read-only address (ram,0x800d4e20) is written */
        uVar2 = 0;
        ppuVar3 = &PTR_LAB_80011d6c;
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
            (*(code *)*ppuVar3)();
            return;
          }
          ppuVar3 = (code **)ppuVar3 + 1;
          local_50.z = local_50.z - HUD_Rotation & 0xfff;
          FX_DrawModel((Object *)(void *)0x0,0,&local_50,&local_48,&local_40,
                       (uint)((int)uVar2 < HUD_Count) ^ 1);
          uVar2 = uVar2 + 1;
          bVar1 = uVar2 < 5;
        } while ((int)uVar2 < 5);
      }
      return;
    }
    warpDraw = warpDraw - (gameTrackerX.timeMult >> 4);
    if (warpDraw < 0) {
      warpDraw = 0;
    }
  }
  else {
    warpDraw = warpDraw + (gameTrackerX.timeMult >> 4);
    if (0x1000 < warpDraw) {
      warpDraw = 0x1000;
    }
  }
  HUD_GetPlayerScreenPt(local_38);
                    /* WARNING: Subroutine does not return */
  rcos(glowdeg);
}





