#include "THISDUST.H"
#include "STATE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitMessageQueue(struct __MessageQueue *In /*$a0*/)
 // line 88, offset 0x80070538
	/* begin block 1 */
		// Start line: 117
	/* end block 1 */
	// End Line: 118

	/* begin block 2 */
		// Start line: 167
	/* end block 2 */
	// End Line: 168

	/* begin block 3 */
		// Start line: 118
	/* end block 3 */
	// End Line: 119

void InitMessageQueue(__MessageQueue *In)

{
  In->Head = 0;
  In->Tail = 0;
  return;
}



// decompiled code
// original method signature: 
// struct __Event * /*$ra*/ DeMessageQueue(struct __MessageQueue *In /*$a0*/)
 // line 95, offset 0x80070544
	/* begin block 1 */
		// Start line: 97
		// Start offset: 0x80070544
	/* end block 1 */
	// End offset: 0x80070578
	// End Line: 109

	/* begin block 2 */
		// Start line: 131
	/* end block 2 */
	// End Line: 132

	/* begin block 3 */
		// Start line: 132
	/* end block 3 */
	// End Line: 133

	/* begin block 4 */
		// Start line: 135
	/* end block 4 */
	// End Line: 136

__Event * DeMessageQueue(__MessageQueue *In)

{
  int iVar1;
  
  iVar1 = In->Head;
  if (iVar1 == In->Tail) {
    return (__Event *)0x0;
  }
  In->Head = iVar1 + 1;
  if (iVar1 + 1 == 0x10) {
    In->Head = 0;
  }
  return In->Queue + iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PurgeMessageQueue(struct __MessageQueue *In /*$a0*/)
 // line 157, offset 0x80070580
	/* begin block 1 */
		// Start line: 300
	/* end block 1 */
	// End Line: 301

	/* begin block 2 */
		// Start line: 207
	/* end block 2 */
	// End Line: 208

void PurgeMessageQueue(__MessageQueue *In)

{
  In->Tail = 0;
  In->Head = 0;
  return;
}



// decompiled code
// original method signature: 
// struct __Event * /*$ra*/ PeekMessageQueue(struct __MessageQueue *In /*$a0*/)
 // line 164, offset 0x8007058c
	/* begin block 1 */
		// Start line: 220
	/* end block 1 */
	// End Line: 221

	/* begin block 2 */
		// Start line: 222
	/* end block 2 */
	// End Line: 223

__Event * PeekMessageQueue(__MessageQueue *In)

{
  if (In->Head != In->Tail) {
    return In->Queue + In->Head;
  }
  return (__Event *)0x0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EnMessageQueue(struct __MessageQueue *In /*$a0*/, struct __Event *Element /*$v0*/)
 // line 197, offset 0x800705b4
	/* begin block 1 */
		// Start line: 262
	/* end block 1 */
	// End Line: 263

	/* begin block 2 */
		// Start line: 289
	/* end block 2 */
	// End Line: 290

void EnMessageQueue(__MessageQueue *In,__Event *Element)

{
                    /* WARNING: Subroutine does not return */
  EnMessageQueueData(In,Element->ID,Element->Data);
}



// decompiled code
// original method signature: 
// void /*$ra*/ EnMessageQueueData(struct __MessageQueue *In /*$a0*/, int ID /*$a1*/, int Data /*$a2*/)
 // line 204, offset 0x800705e0
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x800705E0
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80070654
	// End Line: 251

	/* begin block 2 */
		// Start line: 303
	/* end block 2 */
	// End Line: 304

	/* begin block 3 */
		// Start line: 304
	/* end block 3 */
	// End Line: 305

	/* begin block 4 */
		// Start line: 308
	/* end block 4 */
	// End Line: 309

void EnMessageQueueData(__MessageQueue *In,int ID,int Data)

{
  int iVar1;
  
  In->Queue[In->Tail].ID = ID;
  In->Queue[In->Tail].Data = Data;
  iVar1 = In->Tail + 1;
  In->Tail = iVar1;
  if (iVar1 == 0x10) {
    In->Tail = 0;
  }
  iVar1 = In->Head;
  if (iVar1 == In->Tail) {
    do {
      iVar1 = iVar1 + 1;
      if (iVar1 == 0x10) {
        iVar1 = 0;
      }
    } while (iVar1 != In->Tail);
  }
  return;
}



// decompiled code
// original method signature: 
// void * /*$ra*/ CIRC_Alloc(int size /*$a0*/)
 // line 268, offset 0x8007065c
	/* begin block 1 */
		// Start line: 270
		// Start offset: 0x8007065C
		// Variables:
	// 		void *ret; // $v1
	/* end block 1 */
	// End offset: 0x8007069C
	// End Line: 287

	/* begin block 2 */
		// Start line: 432
	/* end block 2 */
	// End Line: 433

	/* begin block 3 */
		// Start line: 433
	/* end block 3 */
	// End Line: 434

	/* begin block 4 */
		// Start line: 437
	/* end block 4 */
	// End Line: 438

void * CIRC_Alloc(int size)

{
  void *pvVar1;
  uint uVar2;
  _BlockVramEntry *p_Var3;
  
  uVar2 = size + 3U & 0xfffffffc;
  p_Var3 = (_BlockVramEntry *)((int)circWhere + uVar2);
  pvVar1 = circWhere;
  if (&vramBlockList < p_Var3) {
    circWhere = &circBuf + uVar2;
    return &circBuf;
  }
  circWhere = p_Var3;
  return pvVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetCollideInfoData(struct _CollideInfo *srcCI /*$s0*/)
 // line 298, offset 0x800706a4
	/* begin block 1 */
		// Start line: 299
		// Start offset: 0x800706A4
		// Variables:
	// 		struct _CollideInfo *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800706F0
	// End Line: 305

	/* begin block 2 */
		// Start line: 494
	/* end block 2 */
	// End Line: 495

int SetCollideInfoData(_CollideInfo *srcCI)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x30);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterHitData(struct _Instance *Sender /*$s1*/, struct _Instance *lastHit /*$s2*/, int Power /*$s3*/, int knockBackDistance /*$s4*/, int knockBackFrames /*stack 16*/)
 // line 315, offset 0x80070700
	/* begin block 1 */
		// Start line: 316
		// Start offset: 0x80070700
		// Variables:
	// 		struct evMonsterHitData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070700
	// End Line: 316

	/* begin block 2 */
		// Start line: 528
	/* end block 2 */
	// End Line: 529

int SetMonsterHitData(_Instance *Sender,_Instance *lastHit,int Power,int knockBackDistance,
                     int knockBackFrames)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterThrownData(struct _Instance *Sender /*$s1*/, struct _Rotation *Direction /*$s0*/, int Power /*$s2*/)
 // line 332, offset 0x8007076c
	/* begin block 1 */
		// Start line: 333
		// Start offset: 0x8007076C
		// Variables:
	// 		struct evMonsterThrownData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x8007076C
	// End Line: 333

	/* begin block 2 */
		// Start line: 562
	/* end block 2 */
	// End Line: 563

int SetMonsterThrownData(_Instance *Sender,_Rotation *Direction,int Power)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterAlarmData(struct _Instance *sender /*$s1*/, struct _Position *position /*$s0*/, int type /*$s2*/)
 // line 348, offset 0x800707d4
	/* begin block 1 */
		// Start line: 349
		// Start offset: 0x800707D4
		// Variables:
	// 		struct evMonsterAlarmData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800707D4
	// End Line: 349

	/* begin block 2 */
		// Start line: 595
	/* end block 2 */
	// End Line: 596

int SetMonsterAlarmData(_Instance *sender,_Position *position,int type)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterSoulSuckData(struct _Instance *Sender /*$s0*/, int x /*$s1*/, int y /*$s2*/, int z /*$s3*/)
 // line 365, offset 0x8007083c
	/* begin block 1 */
		// Start line: 366
		// Start offset: 0x8007083C
		// Variables:
	// 		struct evMonsterSoulSuckData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x8007083C
	// End Line: 366

	/* begin block 2 */
		// Start line: 630
	/* end block 2 */
	// End Line: 631

int SetMonsterSoulSuckData(_Instance *Sender,int x,int y,int z)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterImpaleData(struct _Instance *weapon /*$s2*/, struct _Rotation *direction /*$s0*/, struct _Position *position /*$s1*/, int distance /*$s3*/)
 // line 382, offset 0x80070898
	/* begin block 1 */
		// Start line: 383
		// Start offset: 0x80070898
		// Variables:
	// 		struct evMonsterImpaleData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070898
	// End Line: 383

	/* begin block 2 */
		// Start line: 664
	/* end block 2 */
	// End Line: 665

int SetMonsterImpaleData(_Instance *weapon,_Rotation *direction,_Position *position,int distance)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x14);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectData(int x /*$s1*/, int y /*$s2*/, int PathNumber /*$s3*/, struct _Instance *Force /*$s4*/, int node /*stack 16*/)
 // line 403, offset 0x80070930
	/* begin block 1 */
		// Start line: 404
		// Start offset: 0x80070930
		// Variables:
	// 		struct evObjectData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070930
	// End Line: 404

	/* begin block 2 */
		// Start line: 707
	/* end block 2 */
	// End Line: 708

int SetObjectData(int x,int y,int PathNumber,_Instance *Force,int node)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPositionData(int x /*$s0*/, int y /*$s1*/, int z /*$s2*/)
 // line 420, offset 0x8007099c
	/* begin block 1 */
		// Start line: 421
		// Start offset: 0x8007099C
		// Variables:
	// 		struct evPositionData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x8007099C
	// End Line: 421

	/* begin block 2 */
		// Start line: 741
	/* end block 2 */
	// End Line: 742

int SetPositionData(int x,int y,int z)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsGravityData(int UpperOffset /*$s2*/, int LowerOffset /*$s3*/, int x /*$s4*/, int y /*$s5*/, int z /*stack 16*/, int slope /*stack 20*/)
 // line 438, offset 0x800709e8
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x800709E8
		// Variables:
	// 		struct evPhysicsGravityData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800709E8
	// End Line: 439

	/* begin block 2 */
		// Start line: 777
	/* end block 2 */
	// End Line: 778

int SetPhysicsGravityData(int UpperOffset,int LowerOffset,int x,int y,int z,int slope)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsEdgeData(int UpperOffset /*$s5*/, int ForwardOffset /*$s6*/, int AboveOffset /*$s7*/, int x /*$fp*/, int y /*stack 16*/, int z /*stack 20*/, struct _SVector *Normal1 /*stack 24*/, struct _SVector *Normal2 /*stack 28*/, struct _SVector *Delta /*stack 32*/)
 // line 462, offset 0x80070a64
	/* begin block 1 */
		// Start line: 463
		// Start offset: 0x80070A64
		// Variables:
	// 		struct evPhysicsEdgeData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070A64
	// End Line: 463

	/* begin block 2 */
		// Start line: 825
	/* end block 2 */
	// End Line: 826

int SetPhysicsEdgeData(int UpperOffset,int ForwardOffset,int AboveOffset,int x,int y,int z,
                      _SVector *Normal1,_SVector *Normal2,_SVector *Delta)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x24);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsSwimData(int CheckDepth /*$s1*/, struct _SVector *iVelocity /*$s2*/, int SwimDepth /*$s3*/, int WadeDepth /*$s4*/, int TreadDepth /*stack 16*/)
 // line 485, offset 0x80070b10
	/* begin block 1 */
		// Start line: 486
		// Start offset: 0x80070B10
		// Variables:
	// 		struct evPhysicsSwimData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070B10
	// End Line: 486

	/* begin block 2 */
		// Start line: 871
	/* end block 2 */
	// End Line: 872

int SetPhysicsSwimData(int CheckDepth,_SVector *iVelocity,int SwimDepth,int WadeDepth,int TreadDepth
                      )

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x18);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsDropOffData(int xOffset /*$s1*/, int yOffset /*$s2*/, int DropOffset /*$s3*/, int slipSlope /*$s4*/, int UpperOffset /*stack 16*/)
 // line 503, offset 0x80070b7c
	/* begin block 1 */
		// Start line: 504
		// Start offset: 0x80070B7C
		// Variables:
	// 		struct evPhysicsDropOffData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070B7C
	// End Line: 504

	/* begin block 2 */
		// Start line: 907
	/* end block 2 */
	// End Line: 908

int SetPhysicsDropOffData(int xOffset,int yOffset,int DropOffset,int slipSlope,int UpperOffset)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsSlideData(int Segment /*$s3*/, int ForwardVectorX /*$s4*/, int ForwardVectorY /*$s5*/, int ForwardVectorZ /*$s6*/, int DropOffset /*stack 16*/, int UpperOffset /*stack 20*/, int Height /*stack 24*/)
 // line 523, offset 0x80070be8
	/* begin block 1 */
		// Start line: 524
		// Start offset: 0x80070BE8
		// Variables:
	// 		struct evPhysicsSlideData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070BE8
	// End Line: 524

	/* begin block 2 */
		// Start line: 947
	/* end block 2 */
	// End Line: 948

int SetPhysicsSlideData(int Segment,int ForwardVectorX,int ForwardVectorY,int ForwardVectorZ,
                       int DropOffset,int UpperOffset,int Height)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x28);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsWallCrawlData(int Segment /*$s0*/, int Length /*$s1*/, int ForwardOffset /*$s2*/, int NormalDistance /*$s3*/)
 // line 544, offset 0x80070c74
	/* begin block 1 */
		// Start line: 545
		// Start offset: 0x80070C74
		// Variables:
	// 		struct evPhysicsWallCrawlData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070C74
	// End Line: 545

	/* begin block 2 */
		// Start line: 989
	/* end block 2 */
	// End Line: 990

int SetPhysicsWallCrawlData(int Segment,int Length,int ForwardOffset,int NormalDistance)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x2c);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsLinkedMoveData(struct _Instance *instance /*$s1*/, int segment /*$s0*/, struct _SVector *posDelta /*$s2*/, struct _SVector *rotDelta /*$s3*/)
 // line 561, offset 0x80070cd0
	/* begin block 1 */
		// Start line: 562
		// Start offset: 0x80070CD0
		// Variables:
	// 		struct evPhysicsLinkedMoveData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070D54
	// End Line: 574

	/* begin block 2 */
		// Start line: 1023
	/* end block 2 */
	// End Line: 1024

int SetPhysicsLinkedMoveData(_Instance *instance,int segment,_SVector *posDelta,_SVector *rotDelta)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x18);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsDropHeightData(struct _Position *offset /*$s0*/, int dropOffset /*$s1*/, int mode /*$s2*/)
 // line 582, offset 0x80070d70
	/* begin block 1 */
		// Start line: 583
		// Start offset: 0x80070D70
		// Variables:
	// 		struct evPhysicsDropHeightData *ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070D70
	// End Line: 583

	/* begin block 2 */
		// Start line: 1065
	/* end block 2 */
	// End Line: 1066

int SetPhysicsDropHeightData(_Position *offset,int dropOffset,int mode)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x14);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetAnimationControllerDoneData(struct _Instance *instance /*$s0*/, long segment /*$s1*/, long type /*$s2*/, int data /*$s3*/)
 // line 602, offset 0x80070de0
	/* begin block 1 */
		// Start line: 603
		// Start offset: 0x80070DE0
		// Variables:
	// 		struct evAnimationControllerDoneData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070DE0
	// End Line: 603

	/* begin block 2 */
		// Start line: 1105
	/* end block 2 */
	// End Line: 1106

int SetAnimationControllerDoneData(_Instance *instance,long segment,long type,int data)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetAnimationInstanceSwitchData(struct _Instance *instance /*$s1*/, int anim /*$s2*/, int frame /*$s3*/, int frames /*$s4*/, int mode /*stack 16*/)
 // line 620, offset 0x80070e3c
	/* begin block 1 */
		// Start line: 621
		// Start offset: 0x80070E3C
		// Variables:
	// 		struct evAnimationInstanceSwitchData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070E3C
	// End Line: 621

	/* begin block 2 */
		// Start line: 1141
	/* end block 2 */
	// End Line: 1142

int SetAnimationInstanceSwitchData(_Instance *instance,int anim,int frame,int frames,int mode)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x14);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetFXHitData(struct _Instance *hitter /*$s2*/, int segment /*$s3*/, int amount /*$s0*/, int type /*$s1*/)
 // line 639, offset 0x80070ea8
	/* begin block 1 */
		// Start line: 640
		// Start offset: 0x80070EA8
		// Variables:
	// 		struct evFXHitData *Ptr; // $a1
	/* end block 1 */
	// End offset: 0x80070F84
	// End Line: 656

	/* begin block 2 */
		// Start line: 1179
	/* end block 2 */
	// End Line: 1180

int SetFXHitData(_Instance *hitter,int segment,int amount,int type)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x14);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectThrowData(void *target /*$s2*/, struct _SVector *angularVel /*$s7*/, unsigned short type /*$s0*/, unsigned short spinType /*$s1*/, int speed /*stack 16*/, int gravity /*stack 20*/, int zVel /*stack 24*/, int initialXRot /*stack 28*/)
 // line 693, offset 0x80070fa4
	/* begin block 1 */
		// Start line: 694
		// Start offset: 0x80070FA4
		// Variables:
	// 		struct evObjectThrowData *Ptr; // $a0
	/* end block 1 */
	// End offset: 0x800710D0
	// End Line: 746

	/* begin block 2 */
		// Start line: 1368
	/* end block 2 */
	// End Line: 1369

int SetObjectThrowData(void *target,_SVector *angularVel,ushort type,ushort spinType,int speed,
                      int gravity,int zVel,int initialXRot)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x1c);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectBreakOffData(struct _Instance *force /*$s3*/, short node /*$a1*/, short distance /*$a2*/, short animation /*$a3*/, int frame /*stack 16*/, int type /*stack 20*/, int action /*stack 24*/)
 // line 750, offset 0x80071110
	/* begin block 1 */
		// Start line: 751
		// Start offset: 0x80071110
		// Variables:
	// 		struct evObjectBreakOffData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80071110
	// End Line: 751

	/* begin block 2 */
		// Start line: 1369
	/* end block 2 */
	// End Line: 1370

int SetObjectBreakOffData
              (_Instance *force,short node,short distance,short animation,int frame,int type,
              int action)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetControlInitHangData(struct _Instance *instance /*$s0*/, long frame /*$s1*/, long frames /*$s2*/)
 // line 767, offset 0x8007119c
	/* begin block 1 */
		// Start line: 768
		// Start offset: 0x8007119C
		// Variables:
	// 		struct evControlInitHangData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x8007119C
	// End Line: 768

	/* begin block 2 */
		// Start line: 1403
	/* end block 2 */
	// End Line: 1404

int SetControlInitHangData(_Instance *instance,long frame,long frames)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetControlInitIdleData(int mode /*$s0*/, long frame /*$s1*/, long frames /*$s2*/)
 // line 781, offset 0x800711e8
	/* begin block 1 */
		// Start line: 782
		// Start offset: 0x800711E8
		// Variables:
	// 		struct evControlInitIdleData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800711E8
	// End Line: 782

	/* begin block 2 */
		// Start line: 1431
	/* end block 2 */
	// End Line: 1432

int SetControlInitIdleData(int mode,long frame,long frames)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectDraftData(short force /*$a0*/, unsigned short radius /*$a1*/, unsigned short radiusCoef /*$a2*/, unsigned short height /*$a3*/, int maxVelocity /*stack 16*/)
 // line 795, offset 0x80071234
	/* begin block 1 */
		// Start line: 796
		// Start offset: 0x80071234
		// Variables:
	// 		struct evObjectDraftData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80071234
	// End Line: 796

	/* begin block 2 */
		// Start line: 1459
	/* end block 2 */
	// End Line: 1460

int SetObjectDraftData(short force,ushort radius,ushort radiusCoef,ushort height,int maxVelocity)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectAbsorbData(struct _Instance *force /*$s0*/, unsigned short node /*$a1*/, unsigned short steps /*$a2*/)
 // line 811, offset 0x800712a0
	/* begin block 1 */
		// Start line: 812
		// Start offset: 0x800712A0
		// Variables:
	// 		struct evObjectAbsorbData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800712A0
	// End Line: 812

	/* begin block 2 */
		// Start line: 1491
	/* end block 2 */
	// End Line: 1492

int SetObjectAbsorbData(_Instance *force,ushort node,ushort steps)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetControlSaveDataData(long length /*$s0*/, void *data /*$s1*/)
 // line 827, offset 0x800712ec
	/* begin block 1 */
		// Start line: 828
		// Start offset: 0x800712EC
		// Variables:
	// 		struct evControlSaveDataData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800712EC
	// End Line: 828

	/* begin block 2 */
		// Start line: 1523
	/* end block 2 */
	// End Line: 1524

int SetControlSaveDataData(long length,void *data)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectIdleData(long mode /*$s0*/, struct _Instance *instance /*$s1*/)
 // line 840, offset 0x80071328
	/* begin block 1 */
		// Start line: 841
		// Start offset: 0x80071328
		// Variables:
	// 		struct evObjectIdleData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80071328
	// End Line: 841

	/* begin block 2 */
		// Start line: 1549
	/* end block 2 */
	// End Line: 1550

int SetObjectIdleData(long mode,_Instance *instance)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(8);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetActionPlayHostAnimationData(struct _Instance *instance /*$s2*/, struct _Instance *host /*$s3*/, int newAnim /*$s4*/, int newFrame /*$s5*/, int frames /*stack 16*/, int mode /*stack 20*/)
 // line 869, offset 0x80071364
	/* begin block 1 */
		// Start line: 870
		// Start offset: 0x80071364
		// Variables:
	// 		struct evActionPlayHostAnimationData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80071364
	// End Line: 870

	/* begin block 2 */
		// Start line: 1734
	/* end block 2 */
	// End Line: 1735

int SetActionPlayHostAnimationData
              (_Instance *instance,_Instance *host,int newAnim,int newFrame,int frames,int mode)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x18);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectBirthProjectileData(struct _Instance *instance /*$s0*/, int joint /*$s1*/, int type /*$s2*/)
 // line 888, offset 0x800713e0
	/* begin block 1 */
		// Start line: 889
		// Start offset: 0x800713E0
		// Variables:
	// 		struct evObjectBirthProjectileData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800713E0
	// End Line: 889

	/* begin block 2 */
		// Start line: 1625
	/* end block 2 */
	// End Line: 1626

int SetObjectBirthProjectileData(_Instance *instance,int joint,int type)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetShadowSegmentData(unsigned long total /*$s0*/)
 // line 907, offset 0x80071430
	/* begin block 1 */
		// Start line: 908
		// Start offset: 0x80071430
		// Variables:
	// 		struct evShadowSegmentData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80071430
	// End Line: 908

	/* begin block 2 */
		// Start line: 1663
	/* end block 2 */
	// End Line: 1664

int SetShadowSegmentData(ulong total)

{
                    /* WARNING: Subroutine does not return */
  CIRC_Alloc(0xc);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInit()
 // line 921, offset 0x8007145c
	/* begin block 1 */
		// Start line: 1691
	/* end block 1 */
	// End Line: 1692

	/* begin block 2 */
		// Start line: 1695
	/* end block 2 */
	// End Line: 1696

/* WARNING: Removing unreachable block (ram,0x800715e4) */
/* WARNING: Removing unreachable block (ram,0x800715f4) */
/* WARNING: Removing unreachable block (ram,0x8007153c) */
/* WARNING: Removing unreachable block (ram,0x8007154c) */
/* WARNING: Removing unreachable block (ram,0x800714b8) */
/* WARNING: Removing unreachable block (ram,0x800714c8) */
/* WARNING: Removing unreachable block (ram,0x8007150c) */
/* WARNING: Removing unreachable block (ram,0x8007151c) */
/* WARNING: Removing unreachable block (ram,0x80071590) */
/* WARNING: Removing unreachable block (ram,0x800715a0) */
/* WARNING: Removing unreachable block (ram,0x80071638) */

void G2EmulationInit(void)

{
  G2AlphaTables7 = (_G2AnimAlphaTable_Type *)0x0;
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x12,'\x19');
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstancePlayAnimation(struct _Instance *instance /*$a0*/)
 // line 978, offset 0x80071648
	/* begin block 1 */
		// Start line: 979
		// Start offset: 0x80071648
		// Variables:
	// 		int i; // $s0
	// 		struct _G2Anim_Type *anim; // $s1
	/* end block 1 */
	// End offset: 0x8007169C
	// End Line: 990

	/* begin block 2 */
		// Start line: 1815
	/* end block 2 */
	// End Line: 1816

void G2EmulationInstancePlayAnimation(_Instance *instance)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((instance->anim).sectionCount != '\0') {
    uVar1 = 0;
    do {
      G2AnimSection_NextKeyframe((instance->anim).section + uVar1);
      uVar2 = uVar2 + 1;
      uVar1 = uVar2 & 0xff;
    } while ((int)uVar2 < (int)(uint)(instance->anim).sectionCount);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulatePlayAnimation(struct __CharacterState *In /*$a0*/)
 // line 995, offset 0x800716b0
	/* begin block 1 */
		// Start line: 1858
	/* end block 1 */
	// End Line: 1859

void G2EmulatePlayAnimation(__CharacterState *In)

{
  G2EmulationInstancePlayAnimation(In->CharacterInstance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance /*$a0*/, struct _Instance *host /*$a1*/, int CurrentSection /*$a2*/, int NewAnim /*$s2*/, int NewFrame /*stack 16*/, int Frames /*stack 20*/, int Mode /*stack 24*/)
 // line 1006, offset 0x800716d4
	/* begin block 1 */
		// Start line: 1007
		// Start offset: 0x800716D4
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s4
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	/* end block 1 */
	// End offset: 0x800717A8
	// End Line: 1028

	/* begin block 2 */
		// Start line: 1880
	/* end block 2 */
	// End Line: 1881

void G2EmulationInstanceToInstanceSwitchAnimation
               (_Instance *instance,_Instance *host,int CurrentSection,int NewAnim,int NewFrame,
               int Frames,int Mode)

{
                    /* WARNING: Subroutine does not return */
  G2Instance_GetKeylist(host,NewAnim);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSwitchAnimation(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$s2*/, int NewFrame /*$s3*/, int Frames /*stack 16*/, int Mode /*stack 20*/)
 // line 1032, offset 0x800717cc
	/* begin block 1 */
		// Start line: 1033
		// Start offset: 0x800717CC
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s4
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	/* end block 1 */
	// End offset: 0x8007189C
	// End Line: 1054

	/* begin block 2 */
		// Start line: 1954
	/* end block 2 */
	// End Line: 1955

void G2EmulationInstanceSwitchAnimation
               (_Instance *instance,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode)

{
                    /* WARNING: Subroutine does not return */
  G2Instance_GetKeylist(instance,NewAnim);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/, int Mode /*stack 20*/, int AlphaTable /*stack 24*/)
 // line 1057, offset 0x800718c0
	/* begin block 1 */
		// Start line: 1058
		// Start offset: 0x800718C0
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s1
	/* end block 1 */
	// End offset: 0x800718C0
	// End Line: 1058

	/* begin block 2 */
		// Start line: 2021
	/* end block 2 */
	// End Line: 2022

void G2EmulationInstanceSwitchAnimationAlpha
               (_Instance *instance,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode,
               int AlphaTable)

{
  G2EmulationInstanceSwitchAnimation(instance,CurrentSection,NewAnim,NewFrame,Frames,Mode);
                    /* WARNING: Subroutine does not return */
  G2AnimSection_SetAlphaTable
            ((instance->anim).section + (CurrentSection & 0xff),(&G2AlphaTables7)[AlphaTable]);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimation(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/, int Mode /*stack 20*/)
 // line 1067, offset 0x80071930
	/* begin block 1 */
		// Start line: 2043
	/* end block 1 */
	// End Line: 2044

void G2EmulationSwitchAnimation
               (__CharacterState *In,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode
               )

{
  if (NewAnim < 0) {
    NewAnim = 0;
  }
  G2EmulationInstanceSwitchAnimation
            (In->CharacterInstance,CurrentSection,NewAnim,NewFrame,Frames,Mode);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationAlpha(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/, int Mode /*stack 20*/, int AlphaTable /*stack 24*/)
 // line 1081, offset 0x80071974
	/* begin block 1 */
		// Start line: 1082
		// Start offset: 0x80071974
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s1
	/* end block 1 */
	// End offset: 0x80071974
	// End Line: 1082

	/* begin block 2 */
		// Start line: 2071
	/* end block 2 */
	// End Line: 2072

void G2EmulationSwitchAnimationAlpha
               (__CharacterState *In,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode
               ,int AlphaTable)

{
  _Instance *p_Var1;
  
  p_Var1 = In->CharacterInstance;
  G2EmulationInstanceSwitchAnimation
            (In->CharacterInstance,CurrentSection,NewAnim,NewFrame,Frames,Mode);
                    /* WARNING: Subroutine does not return */
  G2AnimSection_SetAlphaTable
            ((p_Var1->anim).section + (CurrentSection & 0xff),(&G2AlphaTables7)[AlphaTable]);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationSync(struct __CharacterState *In /*stack 0*/, int SlaveSectionID /*$fp*/, int MasterSectionID /*$a2*/, int Frames /*stack 12*/)
 // line 1093, offset 0x800719ec
	/* begin block 1 */
		// Start line: 1094
		// Start offset: 0x800719EC
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct _G2AnimSection_Type *masterAnimSection; // $s6
	// 		struct _G2AnimSection_Type *slaveAnimSection; // $s5
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	// 		int keylistID; // $s3
	// 		struct __State *masterSection; // $s7
	// 		struct __State *slaveSection; // $s2
	/* end block 1 */
	// End offset: 0x80071B5C
	// End Line: 1130

	/* begin block 2 */
		// Start line: 2097
	/* end block 2 */
	// End Line: 2098

void G2EmulationSwitchAnimationSync
               (__CharacterState *In,int SlaveSectionID,int MasterSectionID,int Frames)

{
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section;
  
  section = (In->CharacterInstance->anim).section + (MasterSectionID & 0xff);
  keylist = section->keylist;
  G2AnimSection_GetKeyframeNumber(section);
                    /* WARNING: Subroutine does not return */
  G2AnimKeylist_GetKeyframeCount(keylist);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance /*$s0*/, struct _Instance *host /*$a1*/, int NewAnim /*$s2*/, int NewFrame /*$s3*/, int Frames /*stack 16*/, int Mode /*stack 20*/)
 // line 1137, offset 0x80071bb8
	/* begin block 1 */
		// Start line: 1138
		// Start offset: 0x80071BB8
		// Variables:
	// 		struct _G2AnimKeylist_Type *keylist1; // $s0
	/* end block 1 */
	// End offset: 0x80071C80
	// End Line: 1160

	/* begin block 2 */
		// Start line: 2208
	/* end block 2 */
	// End Line: 2209

void G2EmulationInstanceToInstanceSwitchAnimationCharacter
               (_Instance *instance,_Instance *host,int NewAnim,int NewFrame,int Frames,int Mode)

{
                    /* WARNING: Subroutine does not return */
  G2Instance_GetKeylist(host,NewAnim);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationCharacter(struct __CharacterState *In /*$a0*/, int NewAnim /*$s2*/, int NewFrame /*$s5*/, int Frames /*$s3*/, int Mode /*stack 16*/)
 // line 1164, offset 0x80071ca4
	/* begin block 1 */
		// Start line: 1165
		// Start offset: 0x80071CA4
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _G2AnimKeylist_Type *keylist; // $s0
	/* end block 1 */
	// End offset: 0x80071D74
	// End Line: 1192

	/* begin block 2 */
		// Start line: 2270
	/* end block 2 */
	// End Line: 2271

void G2EmulationSwitchAnimationCharacter
               (__CharacterState *In,int NewAnim,int NewFrame,int Frames,int Mode)

{
  if (NewAnim < 0) {
    NewAnim = 0;
  }
                    /* WARNING: Subroutine does not return */
  G2Instance_GetKeylist(In->CharacterInstance,NewAnim);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationCharacterAlpha(struct __CharacterState *In /*$s1*/, int NewAnim /*$a1*/, int NewFrame /*$a2*/, int Frames /*$a3*/, int Mode /*stack 16*/, int AlphaTable /*stack 20*/)
 // line 1195, offset 0x80071d98
	/* begin block 1 */
		// Start line: 2332
	/* end block 1 */
	// End Line: 2333

void G2EmulationSwitchAnimationCharacterAlpha
               (__CharacterState *In,int NewAnim,int NewFrame,int Frames,int Mode,int AlphaTable)

{
                    /* WARNING: Subroutine does not return */
  G2EmulationSwitchAnimationCharacter(In,NewAnim,NewFrame,Frames,Mode);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetAnimation(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$s3*/, int NewFrame /*$s4*/, int Frames /*stack 16*/)
 // line 1203, offset 0x80071df0
	/* begin block 1 */
		// Start line: 1204
		// Start offset: 0x80071DF0
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s2
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	/* end block 1 */
	// End offset: 0x80071DF0
	// End Line: 1204

	/* begin block 2 */
		// Start line: 2348
	/* end block 2 */
	// End Line: 2349

void G2EmulationInstanceSetAnimation
               (_Instance *instance,int CurrentSection,int NewAnim,int NewFrame,int Frames)

{
                    /* WARNING: Subroutine does not return */
  G2Instance_GetKeylist(instance,NewAnim);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetAnimation(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/)
 // line 1217, offset 0x80071e98
	/* begin block 1 */
		// Start line: 2397
	/* end block 1 */
	// End Line: 2398

void G2EmulationSetAnimation
               (__CharacterState *In,int CurrentSection,int NewAnim,int NewFrame,int Frames)

{
  if (NewAnim < 0) {
    NewAnim = 0;
  }
                    /* WARNING: Subroutine does not return */
  G2EmulationInstanceSetAnimation(In->CharacterInstance,CurrentSection,NewAnim,NewFrame,Frames);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetMode(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int Mode /*$s1*/)
 // line 1232, offset 0x80071ed0
	/* begin block 1 */
		// Start line: 1233
		// Start offset: 0x80071ED0
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s0
	/* end block 1 */
	// End offset: 0x80071F3C
	// End Line: 1249

	/* begin block 2 */
		// Start line: 2427
	/* end block 2 */
	// End Line: 2428

void G2EmulationInstanceSetMode(_Instance *instance,int CurrentSection,int Mode)

{
  _G2AnimSection_Type *section;
  
  section = (instance->anim).section + (CurrentSection & 0xff);
  if (Mode == 0) {
                    /* WARNING: Subroutine does not return */
    G2AnimSection_SetPaused(section);
  }
                    /* WARNING: Subroutine does not return */
  G2AnimSection_SetUnpaused(section);
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetMode(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int Mode /*$a2*/)
 // line 1253, offset 0x80071f50
	/* begin block 1 */
		// Start line: 2477
	/* end block 1 */
	// End Line: 2478

void G2EmulationSetMode(__CharacterState *In,int CurrentSection,int Mode)

{
  G2EmulationInstanceSetMode(In->CharacterInstance,CurrentSection,Mode);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetAnimSpeed(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int speed /*$a2*/)
 // line 1262, offset 0x80071f74
	/* begin block 1 */
		// Start line: 1264
		// Start offset: 0x80071F74
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $v0
	/* end block 1 */
	// End offset: 0x80071F74
	// End Line: 1266

	/* begin block 2 */
		// Start line: 2495
	/* end block 2 */
	// End Line: 2496

	/* begin block 3 */
		// Start line: 2496
	/* end block 3 */
	// End Line: 2497

	/* begin block 4 */
		// Start line: 2498
	/* end block 4 */
	// End Line: 2499

void G2EmulationInstanceSetAnimSpeed(_Instance *instance,int CurrentSection,int speed)

{
  (instance->anim).section[CurrentSection & 0xff].speedAdjustment = speed;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryAnimation(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1272, offset 0x80071f90
	/* begin block 1 */
		// Start line: 1275
		// Start offset: 0x80071F90
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $v0
	/* end block 1 */
	// End offset: 0x80071F90
	// End Line: 1277

	/* begin block 2 */
		// Start line: 2515
	/* end block 2 */
	// End Line: 2516

	/* begin block 3 */
		// Start line: 2517
	/* end block 3 */
	// End Line: 2518

	/* begin block 4 */
		// Start line: 2519
	/* end block 4 */
	// End Line: 2520

int G2EmulationInstanceQueryAnimation(_Instance *instance,int CurrentSection)

{
  return (uint)(instance->anim).section[CurrentSection & 0xff].keylistID;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationQueryAnimation(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/)
 // line 1283, offset 0x80071fb0
	/* begin block 1 */
		// Start line: 2537
	/* end block 1 */
	// End Line: 2538

int G2EmulationQueryAnimation(__CharacterState *In,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2EmulationInstanceQueryAnimation(In->CharacterInstance,CurrentSection);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryFrame(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1291, offset 0x80071fd4
	/* begin block 1 */
		// Start line: 1292
		// Start offset: 0x80071FD4
	/* end block 1 */
	// End offset: 0x80071FD4
	// End Line: 1292

	/* begin block 2 */
		// Start line: 2553
	/* end block 2 */
	// End Line: 2554

int G2EmulationInstanceQueryFrame(_Instance *instance,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2AnimSection_GetKeyframeNumber((instance->anim).section + (CurrentSection & 0xff));
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryLastFrame(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1303, offset 0x80072008
	/* begin block 1 */
		// Start line: 1304
		// Start offset: 0x80072008
	/* end block 1 */
	// End offset: 0x80072008
	// End Line: 1304

	/* begin block 2 */
		// Start line: 2581
	/* end block 2 */
	// End Line: 2582

int G2EmulationInstanceQueryLastFrame(_Instance *instance,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2AnimSection_GetStoredKeyframeNumber((instance->anim).section + (CurrentSection & 0xff));
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryPassedFrame(struct _Instance *instance /*$s2*/, int CurrentSection /*$a1*/, int frame /*$s1*/)
 // line 1314, offset 0x8007203c
	/* begin block 1 */
		// Start line: 1315
		// Start offset: 0x8007203C
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s0
	/* end block 1 */
	// End offset: 0x800720CC
	// End Line: 1329

	/* begin block 2 */
		// Start line: 2606
	/* end block 2 */
	// End Line: 2607

int G2EmulationInstanceQueryPassedFrame(_Instance *instance,int CurrentSection,int frame)

{
  _G2Bool_Enum _Var1;
  uint uVar2;
  _G2AnimKeylist_Type *p_Var3;
  short sVar4;
  _G2AnimSection_Type *section;
  
  section = (instance->anim).section + (CurrentSection & 0xff);
  _Var1 = G2AnimSection_IsInInterpolation(section);
  uVar2 = 0;
  if ((_Var1 == G2FALSE) && (uVar2 = 1, frame != 0)) {
    p_Var3 = G2Anim_GetKeylist(&instance->anim);
    sVar4 = (short)frame * (ushort)p_Var3->s0TailTime;
    uVar2 = 0;
    if (section->storedTime < sVar4) {
      uVar2 = (uint)(section->elapsedTime < sVar4) ^ 1;
    }
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationQueryFrame(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/)
 // line 1333, offset 0x800720e4
	/* begin block 1 */
		// Start line: 2652
	/* end block 1 */
	// End Line: 2653

int G2EmulationQueryFrame(__CharacterState *In,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2EmulationInstanceQueryFrame(In->CharacterInstance,CurrentSection);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryMode(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1341, offset 0x80072108
	/* begin block 1 */
		// Start line: 1344
		// Start offset: 0x80072108
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $v0
	/* end block 1 */
	// End offset: 0x80072148
	// End Line: 1356

	/* begin block 2 */
		// Start line: 2668
	/* end block 2 */
	// End Line: 2669

	/* begin block 3 */
		// Start line: 2670
	/* end block 3 */
	// End Line: 2671

	/* begin block 4 */
		// Start line: 2672
	/* end block 4 */
	// End Line: 2673

int G2EmulationInstanceQueryMode(_Instance *instance,int CurrentSection)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = (instance->anim).section[CurrentSection & 0xff].flags;
  iVar2 = 0;
  if (((bVar1 & 1) == 0) && (iVar2 = 2, (bVar1 & 2) == 0)) {
    return 1;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationQueryMode(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/)
 // line 1360, offset 0x80072150
	/* begin block 1 */
		// Start line: 2712
	/* end block 1 */
	// End Line: 2713

int G2EmulationQueryMode(__CharacterState *In,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2EmulationInstanceQueryMode(In->CharacterInstance,CurrentSection);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, short Start /*$a2*/, short End /*$a3*/)
 // line 1368, offset 0x80072174
	/* begin block 1 */
		// Start line: 1371
		// Start offset: 0x80072174
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $a0
	/* end block 1 */
	// End offset: 0x80072174
	// End Line: 1373

	/* begin block 2 */
		// Start line: 2728
	/* end block 2 */
	// End Line: 2729

	/* begin block 3 */
		// Start line: 2730
	/* end block 3 */
	// End Line: 2731

	/* begin block 4 */
		// Start line: 2732
	/* end block 4 */
	// End Line: 2733

void G2EmulationInstanceSetStartAndEndSegment
               (_Instance *instance,int CurrentSection,short Start,short End)

{
  _G2AnimSection_Type *p_Var1;
  
  p_Var1 = (instance->anim).section + (CurrentSection & 0xff);
  p_Var1->firstSeg = (uchar)Start;
  p_Var1->segCount = ((char)End - (uchar)Start) + '\x01';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetStartAndEndSegment(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, short Start /*$a2*/, short End /*$a3*/)
 // line 1379, offset 0x800721a0
	/* begin block 1 */
		// Start line: 2750
	/* end block 1 */
	// End Line: 2751

void G2EmulationSetStartAndEndSegment(__CharacterState *In,int CurrentSection,short Start,short End)

{
  G2EmulationInstanceSetStartAndEndSegment(In->CharacterInstance,CurrentSection,Start,End);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetTotalSections(struct _Instance *instance /*$s2*/, short Total /*$a1*/)
 // line 1387, offset 0x800721d0
	/* begin block 1 */
		// Start line: 1388
		// Start offset: 0x800721D0
		// Variables:
	// 		struct _G2Anim_Type *anim; // $s0
	/* end block 1 */
	// End offset: 0x80072228
	// End Line: 1397

	/* begin block 2 */
		// Start line: 2768
	/* end block 2 */
	// End Line: 2769

void G2EmulationInstanceSetTotalSections(_Instance *instance,short Total)

{
  byte bVar1;
  _G2Anim_Type *anim;
  
  bVar1 = (instance->anim).sectionCount;
  anim = &instance->anim;
  while ((int)(uint)bVar1 < (int)Total) {
    G2Anim_AddSection(anim,0,0);
    bVar1 = anim->sectionCount;
  }
  G2Anim_SetCallback(anim,INSTANCE_DefaultAnimCallback,instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetTotalSections(struct __CharacterState *In /*$a0*/, short Total /*$a1*/)
 // line 1404, offset 0x80072254
	/* begin block 1 */
		// Start line: 2808
	/* end block 1 */
	// End Line: 2809

void G2EmulationSetTotalSections(__CharacterState *In,short Total)

{
  In->TotalSections = (int)Total;
  G2EmulationInstanceSetTotalSections(In->CharacterInstance,Total);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceInitSection(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, void *callback /*$a2*/, void *data /*$a3*/)
 // line 1414, offset 0x80072284
	/* begin block 1 */
		// Start line: 1417
		// Start offset: 0x80072284
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $a0
	/* end block 1 */
	// End offset: 0x80072284
	// End Line: 1419

	/* begin block 2 */
		// Start line: 2830
	/* end block 2 */
	// End Line: 2831

	/* begin block 3 */
		// Start line: 2832
	/* end block 3 */
	// End Line: 2833

	/* begin block 4 */
		// Start line: 2834
	/* end block 4 */
	// End Line: 2835

void G2EmulationInstanceInitSection
               (_Instance *instance,int CurrentSection,void *callback,void *data)

{
  _G2AnimSection_Type *p_Var1;
  
  p_Var1 = (instance->anim).section + (CurrentSection & 0xff);
  p_Var1->callback = callback;
  p_Var1->callbackData = data;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetInterpController_Vector(struct _Instance *instance /*$a0*/, long segment /*$a1*/, long type /*$a2*/, struct _G2SVector3_Type *vec /*$a3*/, int Frames /*stack 16*/, int Data /*stack 20*/)
 // line 1440, offset 0x800722a8
	/* begin block 1 */
		// Start line: 2874
	/* end block 1 */
	// End Line: 2875

void G2EmulationSetInterpController_Vector
               (_Instance *instance,long segment,long type,_G2SVector3_Type *vec,int Frames,int Data
               )

{
  G2Anim_SetInterpController_Vector
            (&instance->anim,segment & 0xffU,type & 0xffU,vec,Frames * 0x640000 >> 0x10);
  G2Anim_SetControllerCallbackData(&instance->anim,segment & 0xffU,type & 0xffU,(void *)Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateSwitchStateDataDefault(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess /*$a2*/, int Data /*$a3*/)
 // line 1456, offset 0x80072330
	/* begin block 1 */
		// Start line: 1457
		// Start offset: 0x80072330
		// Variables:
	// 		void (*process)(); // $s2
	/* end block 1 */
	// End offset: 0x80072330
	// End Line: 1457

	/* begin block 2 */
		// Start line: 2919
	/* end block 2 */
	// End Line: 2920

void StateSwitchStateDataDefault
               (__CharacterState *In,int CurrentSection,
               TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess,int Data)

{
                    /* WARNING: Subroutine does not return */
  StateSwitchStateData
            (In,CurrentSection,(TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess,Data);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateSwitchStateCharacterDataDefault(struct __CharacterState *In /*$s1*/, TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess /*$s2*/, int Data /*$s3*/)
 // line 1465, offset 0x80072398
	/* begin block 1 */
		// Start line: 1466
		// Start offset: 0x80072398
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800723F4
	// End Line: 1474

	/* begin block 2 */
		// Start line: 2940
	/* end block 2 */
	// End Line: 2941

void StateSwitchStateCharacterDataDefault
               (__CharacterState *In,
               TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess,int Data)

{
  int CurrentSection;
  
  CurrentSection = 0;
  if (0 < In->TotalSections) {
    do {
      StateSwitchStateDataDefault
                (In,CurrentSection,(TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)NewProcess,
                 Data);
      CurrentSection = CurrentSection + 1;
    } while (CurrentSection < In->TotalSections);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateSwitchStateData(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s2*/, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess /*$s5*/, int Data /*$s4*/)
 // line 1478, offset 0x80072410
	/* begin block 1 */
		// Start line: 2967
	/* end block 1 */
	// End Line: 2968

void StateSwitchStateData
               (__CharacterState *In,int CurrentSection,
               TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess,int Data)

{
  __MessageQueue *In_00;
  
  In_00 = &In->SectionList[CurrentSection].Event;
  PurgeMessageQueue(In_00);
                    /* WARNING: Subroutine does not return */
  EnMessageQueueData(In_00,(int)&DAT_00100001,Data);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateSwitchStateCharacterData(struct __CharacterState *In /*$s1*/, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess /*$s2*/, int Data /*$s3*/)
 // line 1492, offset 0x800724dc
	/* begin block 1 */
		// Start line: 1493
		// Start offset: 0x800724DC
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80072538
	// End Line: 1501

	/* begin block 2 */
		// Start line: 2999
	/* end block 2 */
	// End Line: 3000

void StateSwitchStateCharacterData
               (__CharacterState *In,TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess,
               int Data)

{
  if (0 < In->TotalSections) {
                    /* WARNING: Subroutine does not return */
    StateSwitchStateData(In,0,(TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess,Data);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateGovernState(struct __CharacterState *In /*$s7*/, int Frames /*$fp*/)
 // line 1505, offset 0x80072554
	/* begin block 1 */
		// Start line: 1506
		// Start offset: 0x80072554
		// Variables:
	// 		struct __State *pSectionA; // $v0
	// 		struct __State *pSectionB; // $v1
	// 		struct _G2AnimSection_Type *animSectionA; // $s1
	// 		struct _G2AnimSection_Type *animSectionB; // $s3
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	// 		int keylistID; // $s2
	// 		int i; // $s4
	/* end block 1 */
	// End offset: 0x800726A4
	// End Line: 1555

	/* begin block 2 */
		// Start line: 3026
	/* end block 2 */
	// End Line: 3027

void StateGovernState(__CharacterState *In,int Frames)

{
  _G2Bool_Enum _Var1;
  int iVar2;
  int iVar3;
  _G2AnimSection_Type *section;
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section_00;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 1;
  iVar6 = 0x124;
  iVar5 = 8;
  do {
    if (*(int *)((int)&In->CharacterInstance + iVar5) ==
        *(int *)((int)&In->CharacterInstance + iVar6)) {
      section = (In->CharacterInstance->anim).section + (uVar4 - 1 & 0xff);
      section_00 = (In->CharacterInstance->anim).section + (uVar4 & 0xff);
      if (((section->keylistID == section_00->keylistID) &&
          (_Var1 = G2AnimSection_IsInInterpolation(section), _Var1 == G2FALSE)) &&
         (_Var1 = G2AnimSection_IsInInterpolation(section_00), _Var1 == G2FALSE)) {
        iVar2 = G2AnimSection_GetKeyframeNumber(section);
        iVar3 = G2AnimSection_GetKeyframeNumber(section_00);
        if (iVar2 != iVar3) {
          keylist = section->keylist;
          G2AnimSection_GetKeyframeNumber(section);
                    /* WARNING: Subroutine does not return */
          G2AnimKeylist_GetKeyframeCount(keylist);
        }
      }
    }
    iVar6 = iVar6 + 0x11c;
    uVar4 = uVar4 + 1;
    iVar5 = iVar5 + 0x11c;
  } while ((int)uVar4 < 3);
  return;
}





