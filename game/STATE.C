#include "THISDUST.H"
#include "STATE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitMessageQueue(struct __MessageQueue *In /*$a0*/)
 // line 88, offset 0x80070024
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
 // line 95, offset 0x80070030
	/* begin block 1 */
		// Start line: 97
		// Start offset: 0x80070030
	/* end block 1 */
	// End offset: 0x80070064
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
 // line 113, offset 0x8007006c
	/* begin block 1 */
		// Start line: 167
	/* end block 1 */
	// End Line: 168

	/* begin block 2 */
		// Start line: 168
	/* end block 2 */
	// End Line: 169

void PurgeMessageQueue(__MessageQueue *In)

{
  In->Tail = 0;
  In->Head = 0;
  return;
}



// decompiled code
// original method signature: 
// struct __Event * /*$ra*/ PeekMessageQueue(struct __MessageQueue *In /*$a0*/)
 // line 120, offset 0x80070078
	/* begin block 1 */
		// Start line: 181
	/* end block 1 */
	// End Line: 182

	/* begin block 2 */
		// Start line: 183
	/* end block 2 */
	// End Line: 184

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
 // line 153, offset 0x800700a0
	/* begin block 1 */
		// Start line: 223
	/* end block 1 */
	// End Line: 224

	/* begin block 2 */
		// Start line: 250
	/* end block 2 */
	// End Line: 251

void EnMessageQueue(__MessageQueue *In,__Event *Element)

{
  EnMessageQueueData(In,Element->ID,Element->Data);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ EnMessageQueueData(struct __MessageQueue *In /*$a0*/, int ID /*$a1*/, int Data /*$a2*/)
 // line 160, offset 0x800700cc
	/* begin block 1 */
		// Start line: 162
		// Start offset: 0x800700CC
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80070140
	// End Line: 207

	/* begin block 2 */
		// Start line: 264
	/* end block 2 */
	// End Line: 265

	/* begin block 3 */
		// Start line: 265
	/* end block 3 */
	// End Line: 266

	/* begin block 4 */
		// Start line: 269
	/* end block 4 */
	// End Line: 270

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
 // line 224, offset 0x80070148
	/* begin block 1 */
		// Start line: 226
		// Start offset: 0x80070148
		// Variables:
	// 		void *ret; // $v1
	/* end block 1 */
	// End offset: 0x80070188
	// End Line: 243

	/* begin block 2 */
		// Start line: 393
	/* end block 2 */
	// End Line: 394

	/* begin block 3 */
		// Start line: 394
	/* end block 3 */
	// End Line: 395

	/* begin block 4 */
		// Start line: 398
	/* end block 4 */
	// End Line: 399

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
 // line 254, offset 0x80070190
	/* begin block 1 */
		// Start line: 255
		// Start offset: 0x80070190
		// Variables:
	// 		struct _CollideInfo *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800701DC
	// End Line: 261

	/* begin block 2 */
		// Start line: 455
	/* end block 2 */
	// End Line: 456

int SetCollideInfoData(_CollideInfo *srcCI)

{
  void **ppvVar1;
  void **ppvVar2;
  _CollideInfo *p_Var3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  
  ppvVar1 = (void **)CIRC_Alloc(0x30);
  p_Var3 = srcCI + 1;
  ppvVar2 = ppvVar1;
  do {
    pvVar4 = *(void **)&srcCI->flags;
    pvVar5 = srcCI->prim0;
    pvVar6 = srcCI->prim1;
    *ppvVar2 = srcCI->level;
    ppvVar2[1] = pvVar4;
    ppvVar2[2] = pvVar5;
    ppvVar2[3] = pvVar6;
    srcCI = (_CollideInfo *)&srcCI->inst0;
    ppvVar2 = ppvVar2 + 4;
  } while (srcCI != p_Var3);
  return (int)ppvVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterHitData(struct _Instance *Sender /*$s1*/, struct _Instance *lastHit /*$s2*/, int Power /*$s3*/, int knockBackDistance /*$s4*/, int knockBackFrames /*stack 16*/)
 // line 271, offset 0x800701ec
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x800701EC
		// Variables:
	// 		struct evMonsterHitData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800701EC
	// End Line: 272

	/* begin block 2 */
		// Start line: 489
	/* end block 2 */
	// End Line: 490

int SetMonsterHitData(_Instance *Sender,_Instance *lastHit,int Power,int knockBackDistance,
                     int knockBackFrames)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
  *pp_Var1 = Sender;
  pp_Var1[1] = lastHit;
  *(int *)(pp_Var1 + 3) = Power;
  *(short *)(pp_Var1 + 2) = (short)knockBackDistance;
  *(undefined2 *)((int)pp_Var1 + 10) = (short)knockBackFrames;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterThrownData(struct _Instance *Sender /*$s1*/, struct _Rotation *Direction /*$s0*/, int Power /*$s2*/)
 // line 288, offset 0x80070258
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x80070258
		// Variables:
	// 		struct evMonsterThrownData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070258
	// End Line: 289

	/* begin block 2 */
		// Start line: 523
	/* end block 2 */
	// End Line: 524

int SetMonsterThrownData(_Instance *Sender,_Rotation *Direction,int Power)

{
  short sVar1;
  _Instance **pp_Var2;
  
  pp_Var2 = (_Instance **)CIRC_Alloc(0x10);
  *pp_Var2 = Sender;
  *(short *)(pp_Var2 + 1) = Direction->x;
  *(short *)((int)pp_Var2 + 6) = Direction->y;
  sVar1 = Direction->z;
  *(short *)(pp_Var2 + 3) = (short)Power;
  *(short *)(pp_Var2 + 2) = sVar1;
  return (int)pp_Var2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterAlarmData(struct _Instance *sender /*$s1*/, struct _Position *position /*$s0*/, int type /*$s2*/)
 // line 304, offset 0x800702c0
	/* begin block 1 */
		// Start line: 305
		// Start offset: 0x800702C0
		// Variables:
	// 		struct evMonsterAlarmData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800702C0
	// End Line: 305

	/* begin block 2 */
		// Start line: 556
	/* end block 2 */
	// End Line: 557

int SetMonsterAlarmData(_Instance *sender,_Position *position,int type)

{
  short sVar1;
  _Instance **pp_Var2;
  
  pp_Var2 = (_Instance **)CIRC_Alloc(0xc);
  *pp_Var2 = sender;
  *(short *)(pp_Var2 + 1) = position->x;
  *(short *)((int)pp_Var2 + 6) = position->y;
  sVar1 = position->z;
  *(undefined2 *)((int)pp_Var2 + 10) = (short)type;
  *(short *)(pp_Var2 + 2) = sVar1;
  return (int)pp_Var2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterSoulSuckData(struct _Instance *Sender /*$s0*/, int x /*$s1*/, int y /*$s2*/, int z /*$s3*/)
 // line 321, offset 0x80070328
	/* begin block 1 */
		// Start line: 322
		// Start offset: 0x80070328
		// Variables:
	// 		struct evMonsterSoulSuckData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070328
	// End Line: 322

	/* begin block 2 */
		// Start line: 591
	/* end block 2 */
	// End Line: 592

int SetMonsterSoulSuckData(_Instance *Sender,int x,int y,int z)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0xc);
  *pp_Var1 = Sender;
  *(short *)(pp_Var1 + 1) = (short)x;
  *(undefined2 *)((int)pp_Var1 + 6) = (short)y;
  *(short *)(pp_Var1 + 2) = (short)z;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetMonsterImpaleData(struct _Instance *weapon /*$s2*/, struct _Rotation *direction /*$s0*/, struct _Position *position /*$s1*/, int distance /*$s3*/)
 // line 338, offset 0x80070384
	/* begin block 1 */
		// Start line: 339
		// Start offset: 0x80070384
		// Variables:
	// 		struct evMonsterImpaleData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070384
	// End Line: 339

	/* begin block 2 */
		// Start line: 625
	/* end block 2 */
	// End Line: 626

int SetMonsterImpaleData(_Instance *weapon,_Rotation *direction,_Position *position,int distance)

{
  short sVar1;
  _Instance **pp_Var2;
  
  pp_Var2 = (_Instance **)CIRC_Alloc(0x14);
  *pp_Var2 = weapon;
  *(short *)(pp_Var2 + 1) = direction->x;
  *(short *)((int)pp_Var2 + 6) = direction->y;
  *(short *)(pp_Var2 + 2) = direction->z;
  *(short *)(pp_Var2 + 3) = position->x;
  *(short *)((int)pp_Var2 + 0xe) = position->y;
  sVar1 = position->z;
  *(undefined2 *)((int)pp_Var2 + 0x12) = (short)distance;
  *(short *)(pp_Var2 + 4) = sVar1;
  return (int)pp_Var2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectData(int x /*$s1*/, int y /*$s2*/, int PathNumber /*$s3*/, struct _Instance *Force /*$s4*/, int node /*stack 16*/)
 // line 359, offset 0x8007041c
	/* begin block 1 */
		// Start line: 360
		// Start offset: 0x8007041C
		// Variables:
	// 		struct evObjectData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x8007041C
	// End Line: 360

	/* begin block 2 */
		// Start line: 668
	/* end block 2 */
	// End Line: 669

int SetObjectData(int x,int y,int PathNumber,_Instance *Force,int node)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(0x10);
  *puVar1 = (short)x;
  puVar1[1] = (short)y;
  puVar1[2] = (short)PathNumber;
  *(_Instance **)(puVar1 + 4) = Force;
  puVar1[3] = (short)node;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPositionData(int x /*$s0*/, int y /*$s1*/, int z /*$s2*/)
 // line 376, offset 0x80070488
	/* begin block 1 */
		// Start line: 377
		// Start offset: 0x80070488
		// Variables:
	// 		struct evPositionData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070488
	// End Line: 377

	/* begin block 2 */
		// Start line: 702
	/* end block 2 */
	// End Line: 703

int SetPositionData(int x,int y,int z)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(8);
  *puVar1 = (short)x;
  puVar1[1] = (short)y;
  puVar1[2] = (short)z;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsGravityData(int UpperOffset /*$s2*/, int LowerOffset /*$s3*/, int x /*$s4*/, int y /*$s5*/, int z /*stack 16*/, int slope /*stack 20*/)
 // line 394, offset 0x800704d4
	/* begin block 1 */
		// Start line: 395
		// Start offset: 0x800704D4
		// Variables:
	// 		struct evPhysicsGravityData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800704D4
	// End Line: 395

	/* begin block 2 */
		// Start line: 738
	/* end block 2 */
	// End Line: 739

int SetPhysicsGravityData(int UpperOffset,int LowerOffset,int x,int y,int z,int slope)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(0xc);
  *puVar1 = (short)UpperOffset;
  puVar1[1] = (short)LowerOffset;
  puVar1[2] = (short)x;
  puVar1[3] = (short)y;
  puVar1[4] = (short)z;
  puVar1[5] = (short)slope;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsEdgeData(int UpperOffset /*$s5*/, int ForwardOffset /*$s6*/, int AboveOffset /*$s7*/, int x /*$fp*/, int y /*stack 16*/, int z /*stack 20*/, struct _SVector *Normal1 /*stack 24*/, struct _SVector *Normal2 /*stack 28*/, struct _SVector *Delta /*stack 32*/)
 // line 418, offset 0x80070550
	/* begin block 1 */
		// Start line: 419
		// Start offset: 0x80070550
		// Variables:
	// 		struct evPhysicsEdgeData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070550
	// End Line: 419

	/* begin block 2 */
		// Start line: 786
	/* end block 2 */
	// End Line: 787

int SetPhysicsEdgeData(int UpperOffset,int ForwardOffset,int AboveOffset,int x,int y,int z,
                      _SVector *Normal1,_SVector *Normal2,_SVector *Delta)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(0x24);
  *puVar1 = (short)UpperOffset;
  puVar1[1] = (short)ForwardOffset;
  puVar1[2] = (short)AboveOffset;
  puVar1[3] = (short)x;
  puVar1[4] = (short)y;
  puVar1[5] = (short)z;
  *(_SVector **)(puVar1 + 6) = Normal1;
  *(_SVector **)(puVar1 + 8) = Normal2;
  *(_SVector **)(puVar1 + 10) = Delta;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsSwimData(int CheckDepth /*$s1*/, struct _SVector *iVelocity /*$s2*/, int SwimDepth /*$s3*/, int WadeDepth /*$s4*/, int TreadDepth /*stack 16*/)
 // line 441, offset 0x800705fc
	/* begin block 1 */
		// Start line: 442
		// Start offset: 0x800705FC
		// Variables:
	// 		struct evPhysicsSwimData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800705FC
	// End Line: 442

	/* begin block 2 */
		// Start line: 832
	/* end block 2 */
	// End Line: 833

int SetPhysicsSwimData(int CheckDepth,_SVector *iVelocity,int SwimDepth,int WadeDepth,int TreadDepth
                      )

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(0x18);
  *puVar1 = (short)CheckDepth;
  *(_SVector **)(puVar1 + 4) = iVelocity;
  puVar1[1] = (short)SwimDepth;
  puVar1[2] = (short)WadeDepth;
  puVar1[3] = (short)TreadDepth;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsDropOffData(int xOffset /*$s0*/, int yOffset /*$s1*/, int DropOffset /*$s2*/, int slipSlope /*$s3*/)
 // line 459, offset 0x80070668
	/* begin block 1 */
		// Start line: 460
		// Start offset: 0x80070668
		// Variables:
	// 		struct evPhysicsDropOffData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070668
	// End Line: 460

	/* begin block 2 */
		// Start line: 868
	/* end block 2 */
	// End Line: 869

int SetPhysicsDropOffData(int xOffset,int yOffset,int DropOffset,int slipSlope)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(8);
  *puVar1 = (short)xOffset;
  puVar1[1] = (short)yOffset;
  puVar1[2] = (short)DropOffset;
  puVar1[3] = (short)slipSlope;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsSlideData(int Segment /*$s3*/, int ForwardVectorX /*$s4*/, int ForwardVectorY /*$s5*/, int ForwardVectorZ /*$s6*/, int DropOffset /*stack 16*/, int UpperOffset /*stack 20*/, int Height /*stack 24*/)
 // line 478, offset 0x800706c4
	/* begin block 1 */
		// Start line: 479
		// Start offset: 0x800706C4
		// Variables:
	// 		struct evPhysicsSlideData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800706C4
	// End Line: 479

	/* begin block 2 */
		// Start line: 906
	/* end block 2 */
	// End Line: 907

int SetPhysicsSlideData(int Segment,int ForwardVectorX,int ForwardVectorY,int ForwardVectorZ,
                       int DropOffset,int UpperOffset,int Height)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(0x28);
  puVar1[0xc] = (short)Segment;
  *puVar1 = (short)ForwardVectorX;
  puVar1[1] = (short)ForwardVectorY;
  puVar1[2] = (short)ForwardVectorZ;
  puVar1[0xd] = (short)DropOffset;
  puVar1[0xe] = (short)UpperOffset;
  puVar1[0xf] = (short)Height;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsWallCrawlData(int Segment /*$s0*/, int Length /*$s1*/, int ForwardOffset /*$s2*/, int NormalDistance /*$s3*/)
 // line 499, offset 0x80070750
	/* begin block 1 */
		// Start line: 500
		// Start offset: 0x80070750
		// Variables:
	// 		struct evPhysicsWallCrawlData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070750
	// End Line: 500

	/* begin block 2 */
		// Start line: 948
	/* end block 2 */
	// End Line: 949

int SetPhysicsWallCrawlData(int Segment,int Length,int ForwardOffset,int NormalDistance)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CIRC_Alloc(0x2c);
  *puVar1 = (short)Segment;
  puVar1[1] = (short)Length;
  puVar1[2] = (short)ForwardOffset;
  puVar1[3] = (short)NormalDistance;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsLinkedMoveData(struct _Instance *instance /*$s1*/, int segment /*$s0*/, struct _SVector *posDelta /*$s2*/, struct _SVector *rotDelta /*$s3*/)
 // line 516, offset 0x800707ac
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x800707AC
		// Variables:
	// 		struct evPhysicsLinkedMoveData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070830
	// End Line: 529

	/* begin block 2 */
		// Start line: 982
	/* end block 2 */
	// End Line: 983

int SetPhysicsLinkedMoveData(_Instance *instance,int segment,_SVector *posDelta,_SVector *rotDelta)

{
  _Instance **pp_Var1;
  _Instance *p_Var2;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x18);
  *(int *)(pp_Var1 + 1) = segment;
  *pp_Var1 = instance;
  if (posDelta != (_SVector *)0x0) {
    p_Var2 = *(_Instance **)&posDelta->z;
    pp_Var1[2] = *(_Instance **)posDelta;
    pp_Var1[3] = p_Var2;
  }
  if (rotDelta != (_SVector *)0x0) {
    p_Var2 = *(_Instance **)&rotDelta->z;
    pp_Var1[4] = *(_Instance **)rotDelta;
    pp_Var1[5] = p_Var2;
  }
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetPhysicsDropHeightData(struct _Position *offset /*$s0*/, int dropOffset /*$s1*/, int mode /*$s2*/)
 // line 537, offset 0x8007084c
	/* begin block 1 */
		// Start line: 538
		// Start offset: 0x8007084C
		// Variables:
	// 		struct evPhysicsDropHeightData *ptr; // $v0
	/* end block 1 */
	// End offset: 0x8007084C
	// End Line: 538

	/* begin block 2 */
		// Start line: 1024
	/* end block 2 */
	// End Line: 1025

int SetPhysicsDropHeightData(_Position *offset,int dropOffset,int mode)

{
  short *psVar1;
  
  psVar1 = (short *)CIRC_Alloc(0x14);
  psVar1[4] = (short)dropOffset;
  psVar1[3] = (short)mode;
  *psVar1 = offset->x;
  psVar1[1] = offset->y;
  psVar1[2] = offset->z + 0x19;
  return (int)psVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetAnimationControllerDoneData(struct _Instance *instance /*$s0*/, long segment /*$s1*/, long type /*$s2*/, int data /*$s3*/)
 // line 557, offset 0x800708bc
	/* begin block 1 */
		// Start line: 558
		// Start offset: 0x800708BC
		// Variables:
	// 		struct evAnimationControllerDoneData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800708BC
	// End Line: 558

	/* begin block 2 */
		// Start line: 1064
	/* end block 2 */
	// End Line: 1065

int SetAnimationControllerDoneData(_Instance *instance,long segment,long type,int data)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
  *pp_Var1 = instance;
  *(long *)(pp_Var1 + 1) = segment;
  *(long *)(pp_Var1 + 2) = type;
  *(int *)(pp_Var1 + 3) = data;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetAnimationInstanceSwitchData(struct _Instance *instance /*$s1*/, int anim /*$s2*/, int frame /*$s3*/, int frames /*$s4*/, int mode /*stack 16*/)
 // line 575, offset 0x80070918
	/* begin block 1 */
		// Start line: 576
		// Start offset: 0x80070918
		// Variables:
	// 		struct evAnimationInstanceSwitchData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070918
	// End Line: 576

	/* begin block 2 */
		// Start line: 1100
	/* end block 2 */
	// End Line: 1101

int SetAnimationInstanceSwitchData(_Instance *instance,int anim,int frame,int frames,int mode)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x14);
  *pp_Var1 = instance;
  *(int *)(pp_Var1 + 1) = anim;
  *(int *)(pp_Var1 + 2) = frame;
  *(int *)(pp_Var1 + 3) = frames;
  *(int *)(pp_Var1 + 4) = mode;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetFXHitData(struct _Instance *hitter /*$s2*/, int segment /*$s3*/, int amount /*$s0*/, int type /*$s1*/)
 // line 594, offset 0x80070984
	/* begin block 1 */
		// Start line: 595
		// Start offset: 0x80070984
		// Variables:
	// 		struct evFXHitData *Ptr; // $a1
	/* end block 1 */
	// End offset: 0x80070A60
	// End Line: 611

	/* begin block 2 */
		// Start line: 1138
	/* end block 2 */
	// End Line: 1139

int SetFXHitData(_Instance *hitter,int segment,int amount,int type)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)CIRC_Alloc(0x14);
  psVar2[8] = (short)amount;
  psVar2[9] = (short)type;
  if (hitter != (_Instance *)0x0) {
    sVar1 = *(short *)hitter->matrix[segment].t;
    *psVar2 = sVar1;
    psVar2[4] = sVar1 - *(short *)hitter->oldMatrix[segment].t;
    sVar1 = *(short *)(hitter->matrix[segment].t + 1);
    psVar2[1] = sVar1;
    psVar2[5] = sVar1 - *(short *)(hitter->oldMatrix[segment].t + 1);
    sVar1 = *(short *)(hitter->matrix[segment].t + 2);
    psVar2[2] = sVar1;
    psVar2[6] = sVar1 - *(short *)(hitter->oldMatrix[segment].t + 2);
  }
  return (int)psVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectThrowData(void *target /*$s2*/, struct _SVector *angularVel /*$s7*/, unsigned short type /*$s0*/, unsigned short spinType /*$s1*/, int speed /*stack 16*/, int gravity /*stack 20*/, int zVel /*stack 24*/, int initialXRot /*stack 28*/)
 // line 648, offset 0x80070a80
	/* begin block 1 */
		// Start line: 649
		// Start offset: 0x80070A80
		// Variables:
	// 		struct evObjectThrowData *Ptr; // $a0
	/* end block 1 */
	// End offset: 0x80070BAC
	// End Line: 701

	/* begin block 2 */
		// Start line: 1278
	/* end block 2 */
	// End Line: 1279

int SetObjectThrowData(void *target,_SVector *angularVel,ushort type,ushort spinType,int speed,
                      int gravity,int zVel,int initialXRot)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  puVar2 = (ushort *)CIRC_Alloc(0x1c);
  *puVar2 = type;
  puVar2[1] = spinType;
  if (target == (void *)0x0) {
    *puVar2 = 0;
  }
  else {
    switch(type) {
    case 1:
      *(void **)(puVar2 + 2) = target;
      break;
    case 2:
    case 4:
      uVar1 = *(ushort *)((int)target + 4);
      *(undefined4 *)(puVar2 + 2) = *(undefined4 *)target;
      puVar2[4] = uVar1;
      break;
    case 3:
      uVar3 = *(undefined4 *)((int)target + 4);
      *(undefined4 *)(puVar2 + 2) = *(undefined4 *)target;
      *(undefined4 *)(puVar2 + 4) = uVar3;
    }
  }
  if ((1 < spinType) && (spinType == 2)) {
    if (angularVel == (_SVector *)0x0) {
      puVar2[1] = 0;
    }
    else {
      uVar3 = *(undefined4 *)&angularVel->z;
      *(undefined4 *)(puVar2 + 6) = *(undefined4 *)angularVel;
      *(undefined4 *)(puVar2 + 8) = uVar3;
    }
  }
  puVar2[10] = (ushort)speed;
  puVar2[0xb] = (ushort)gravity;
  puVar2[0xd] = (ushort)zVel;
  puVar2[0xc] = (ushort)initialXRot;
  return (int)puVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectBreakOffData(struct _Instance *force /*$s3*/, short node /*$a1*/, short distance /*$a2*/, short animation /*$a3*/, int frame /*stack 16*/, int type /*stack 20*/, int action /*stack 24*/)
 // line 705, offset 0x80070bec
	/* begin block 1 */
		// Start line: 706
		// Start offset: 0x80070BEC
		// Variables:
	// 		struct evObjectBreakOffData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070BEC
	// End Line: 706

	/* begin block 2 */
		// Start line: 1328
	/* end block 2 */
	// End Line: 1329

int SetObjectBreakOffData
              (_Instance *force,short node,short distance,short animation,int frame,int type,
              int action)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
  *pp_Var1 = force;
  *(short *)(pp_Var1 + 1) = node;
  *(short *)((int)pp_Var1 + 6) = distance;
  *(short *)(pp_Var1 + 2) = animation;
  *(undefined2 *)((int)pp_Var1 + 10) = (short)frame;
  *(short *)(pp_Var1 + 3) = (short)type;
  *(undefined2 *)((int)pp_Var1 + 0xe) = (short)action;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetControlInitHangData(struct _Instance *instance /*$s0*/, long frame /*$s1*/, long frames /*$s2*/)
 // line 722, offset 0x80070c78
	/* begin block 1 */
		// Start line: 723
		// Start offset: 0x80070C78
		// Variables:
	// 		struct evControlInitHangData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070C78
	// End Line: 723

	/* begin block 2 */
		// Start line: 1362
	/* end block 2 */
	// End Line: 1363

int SetControlInitHangData(_Instance *instance,long frame,long frames)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0xc);
  *pp_Var1 = instance;
  *(long *)(pp_Var1 + 1) = frame;
  *(long *)(pp_Var1 + 2) = frames;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetControlInitIdleData(int mode /*$s0*/, long frame /*$s1*/, long frames /*$s2*/)
 // line 736, offset 0x80070cc4
	/* begin block 1 */
		// Start line: 737
		// Start offset: 0x80070CC4
		// Variables:
	// 		struct evControlInitIdleData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070CC4
	// End Line: 737

	/* begin block 2 */
		// Start line: 1390
	/* end block 2 */
	// End Line: 1391

int SetControlInitIdleData(int mode,long frame,long frames)

{
  int *piVar1;
  
  piVar1 = (int *)CIRC_Alloc(0xc);
  *piVar1 = mode;
  piVar1[1] = frame;
  piVar1[2] = frames;
  return (int)piVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectDraftData(short force /*$a0*/, unsigned short radius /*$a1*/, unsigned short radiusCoef /*$a2*/, unsigned short height /*$a3*/, int maxVelocity /*stack 16*/)
 // line 750, offset 0x80070d10
	/* begin block 1 */
		// Start line: 751
		// Start offset: 0x80070D10
		// Variables:
	// 		struct evObjectDraftData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070D10
	// End Line: 751

	/* begin block 2 */
		// Start line: 1418
	/* end block 2 */
	// End Line: 1419

int SetObjectDraftData(short force,ushort radius,ushort radiusCoef,ushort height,int maxVelocity)

{
  short *psVar1;
  
  psVar1 = (short *)CIRC_Alloc(10);
  *psVar1 = force;
  psVar1[1] = radius;
  psVar1[2] = radiusCoef;
  psVar1[3] = height;
  psVar1[4] = (short)maxVelocity;
  return (int)psVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectAbsorbData(struct _Instance *force /*$s0*/, unsigned short node /*$a1*/, unsigned short steps /*$a2*/)
 // line 766, offset 0x80070d7c
	/* begin block 1 */
		// Start line: 767
		// Start offset: 0x80070D7C
		// Variables:
	// 		struct evObjectAbsorbData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070D7C
	// End Line: 767

	/* begin block 2 */
		// Start line: 1450
	/* end block 2 */
	// End Line: 1451

int SetObjectAbsorbData(_Instance *force,ushort node,ushort steps)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(8);
  *pp_Var1 = force;
  *(ushort *)(pp_Var1 + 1) = node;
  *(ushort *)((int)pp_Var1 + 6) = steps;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetControlSaveDataData(long length /*$s0*/, void *data /*$s1*/)
 // line 782, offset 0x80070dc8
	/* begin block 1 */
		// Start line: 783
		// Start offset: 0x80070DC8
		// Variables:
	// 		struct evControlSaveDataData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070DC8
	// End Line: 783

	/* begin block 2 */
		// Start line: 1482
	/* end block 2 */
	// End Line: 1483

int SetControlSaveDataData(long length,void *data)

{
  long *plVar1;
  
  plVar1 = (long *)CIRC_Alloc(8);
  *plVar1 = length;
  *(void **)(plVar1 + 1) = data;
  return (int)plVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectIdleData(long mode /*$s0*/, struct _Instance *instance /*$s1*/)
 // line 795, offset 0x80070e04
	/* begin block 1 */
		// Start line: 796
		// Start offset: 0x80070E04
		// Variables:
	// 		struct evObjectIdleData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070E04
	// End Line: 796

	/* begin block 2 */
		// Start line: 1508
	/* end block 2 */
	// End Line: 1509

int SetObjectIdleData(long mode,_Instance *instance)

{
  long *plVar1;
  
  plVar1 = (long *)CIRC_Alloc(8);
  *plVar1 = mode;
  *(_Instance **)(plVar1 + 1) = instance;
  return (int)plVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetActionPlayHostAnimationData(struct _Instance *instance /*$s2*/, struct _Instance *host /*$s3*/, int newAnim /*$s4*/, int newFrame /*$s5*/, int frames /*stack 16*/, int mode /*stack 20*/)
 // line 824, offset 0x80070e40
	/* begin block 1 */
		// Start line: 825
		// Start offset: 0x80070E40
		// Variables:
	// 		struct evActionPlayHostAnimationData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070E40
	// End Line: 825

	/* begin block 2 */
		// Start line: 1644
	/* end block 2 */
	// End Line: 1645

int SetActionPlayHostAnimationData
              (_Instance *instance,_Instance *host,int newAnim,int newFrame,int frames,int mode)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x18);
  *pp_Var1 = instance;
  pp_Var1[1] = host;
  *(int *)(pp_Var1 + 2) = newAnim;
  *(int *)(pp_Var1 + 3) = newFrame;
  *(int *)(pp_Var1 + 4) = frames;
  *(int *)(pp_Var1 + 5) = mode;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetObjectBirthProjectileData(struct _Instance *instance /*$s0*/, int joint /*$s1*/, int type /*$s2*/)
 // line 843, offset 0x80070ebc
	/* begin block 1 */
		// Start line: 844
		// Start offset: 0x80070EBC
		// Variables:
	// 		struct evObjectBirthProjectileData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070EBC
	// End Line: 844

	/* begin block 2 */
		// Start line: 1584
	/* end block 2 */
	// End Line: 1585

int SetObjectBirthProjectileData(_Instance *instance,int joint,int type)

{
  _Instance **pp_Var1;
  
  pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
  *pp_Var1 = instance;
  *(int *)(pp_Var1 + 1) = joint;
  *(int *)(pp_Var1 + 2) = type;
  pp_Var1[3] = (_Instance *)0x0;
  return (int)pp_Var1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetShadowSegmentData(unsigned long total /*$s0*/)
 // line 862, offset 0x80070f0c
	/* begin block 1 */
		// Start line: 863
		// Start offset: 0x80070F0C
		// Variables:
	// 		struct evShadowSegmentData *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80070F0C
	// End Line: 863

	/* begin block 2 */
		// Start line: 1622
	/* end block 2 */
	// End Line: 1623

int SetShadowSegmentData(ulong total)

{
  ulong *puVar1;
  
  puVar1 = (ulong *)CIRC_Alloc(0xc);
  *puVar1 = total;
  return (int)puVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInit()
 // line 876, offset 0x80070f38
	/* begin block 1 */
		// Start line: 1650
	/* end block 1 */
	// End Line: 1651

	/* begin block 2 */
		// Start line: 1654
	/* end block 2 */
	// End Line: 1655

/* WARNING: Unknown calling convention yet parameter storage is locked */

void G2EmulationInit(void)

{
  G2AlphaTables7 = (_G2AnimAlphaTable_Type *)0x0;
  if (PTR_800d0160 == (_G2AnimAlphaTable_Type *)0x0) {
    PTR_800d0160 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12,'\x19');
    PTR_800d0160->size = 4;
    PTR_800d0160[1] = (_G2AnimAlphaTable_Type)0x0;
    PTR_800d0160[2] = (_G2AnimAlphaTable_Type)0x100;
    PTR_800d0160[3] = (_G2AnimAlphaTable_Type)0x400;
    PTR_800d0160[4] = (_G2AnimAlphaTable_Type)0x1000;
  }
  if (PTR_800d0164 == (_G2AnimAlphaTable_Type *)0x0) {
    PTR_800d0164 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12,'\x19');
    PTR_800d0164->size = 4;
    PTR_800d0164[1] = (_G2AnimAlphaTable_Type)0x0;
    PTR_800d0164[2] = (_G2AnimAlphaTable_Type)0xc00;
    PTR_800d0164[3] = (_G2AnimAlphaTable_Type)0xf00;
    PTR_800d0164[4] = (_G2AnimAlphaTable_Type)0x1000;
  }
  if (PTR_800d0168 == (_G2AnimAlphaTable_Type *)0x0) {
    PTR_800d0168 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(6,'\x19');
    PTR_800d0168->size = 1;
    PTR_800d0168[1] = (_G2AnimAlphaTable_Type)0x1000;
  }
  if (PTR_800d016c == (_G2AnimAlphaTable_Type *)0x0) {
    PTR_800d016c = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12,'\x19');
    PTR_800d016c->size = 4;
    PTR_800d016c[1] = (_G2AnimAlphaTable_Type)0x0;
    PTR_800d016c[2] = (_G2AnimAlphaTable_Type)0x100;
    PTR_800d016c[3] = (_G2AnimAlphaTable_Type)0xf00;
    PTR_800d016c[4] = (_G2AnimAlphaTable_Type)0x1000;
  }
  if (PTR_800d0170 == (_G2AnimAlphaTable_Type *)0x0) {
    PTR_800d0170 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12,'\x19');
    PTR_800d0170->size = 4;
    PTR_800d0170[1] = (_G2AnimAlphaTable_Type)0x0;
    PTR_800d0170[2] = (_G2AnimAlphaTable_Type)0x80;
    PTR_800d0170[3] = (_G2AnimAlphaTable_Type)0x200;
    PTR_800d0170[4] = (_G2AnimAlphaTable_Type)0x1000;
  }
  if (PTR_800d0174 == (_G2AnimAlphaTable_Type *)0x0) {
    PTR_800d0174 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12,'\x19');
    PTR_800d0174->size = 4;
    PTR_800d0174[1] = (_G2AnimAlphaTable_Type)0x0;
    PTR_800d0174[2] = (_G2AnimAlphaTable_Type)0xe00;
    PTR_800d0174[3] = (_G2AnimAlphaTable_Type)0xf80;
    PTR_800d0174[4] = (_G2AnimAlphaTable_Type)0x1000;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstancePlayAnimation(struct _Instance *instance /*$a0*/)
 // line 933, offset 0x80071124
	/* begin block 1 */
		// Start line: 934
		// Start offset: 0x80071124
		// Variables:
	// 		int i; // $s0
	// 		struct _G2Anim_Type *anim; // $s1
	/* end block 1 */
	// End offset: 0x80071178
	// End Line: 945

	/* begin block 2 */
		// Start line: 1774
	/* end block 2 */
	// End Line: 1775

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
 // line 950, offset 0x8007118c
	/* begin block 1 */
		// Start line: 1817
	/* end block 1 */
	// End Line: 1818

void G2EmulatePlayAnimation(__CharacterState *In)

{
  G2EmulationInstancePlayAnimation(In->CharacterInstance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceToInstanceSwitchAnimation(struct _Instance *instance /*$a0*/, struct _Instance *host /*$a1*/, int CurrentSection /*$a2*/, int NewAnim /*$s2*/, int NewFrame /*stack 16*/, int Frames /*stack 20*/, int Mode /*stack 24*/)
 // line 961, offset 0x800711b0
	/* begin block 1 */
		// Start line: 962
		// Start offset: 0x800711B0
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s4
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	/* end block 1 */
	// End offset: 0x80071284
	// End Line: 983

	/* begin block 2 */
		// Start line: 1839
	/* end block 2 */
	// End Line: 1840

void G2EmulationInstanceToInstanceSwitchAnimation
               (_Instance *instance,_Instance *host,int CurrentSection,int NewAnim,int NewFrame,
               int Frames,int Mode)

{
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section;
  
  section = (instance->anim).section + CurrentSection;
  keylist = G2Instance_GetKeylist(host,NewAnim);
  G2AnimSection_SetAlphaTable(section,(_G2AnimAlphaTable_Type *)0x0);
  G2AnimSection_InterpToKeylistFrame(section,keylist,NewAnim,NewFrame,Frames * 0x640000 >> 0x10);
  if (Mode == 0) {
    G2AnimSection_SetPaused(section);
  }
  else {
    G2AnimSection_SetUnpaused(section);
    if (Mode == 2) {
      G2AnimSection_SetLooping(section);
    }
    else {
      G2AnimSection_SetNoLooping(section);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSwitchAnimation(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$s2*/, int NewFrame /*$s3*/, int Frames /*stack 16*/, int Mode /*stack 20*/)
 // line 987, offset 0x800712a8
	/* begin block 1 */
		// Start line: 988
		// Start offset: 0x800712A8
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s4
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	/* end block 1 */
	// End offset: 0x80071378
	// End Line: 1009

	/* begin block 2 */
		// Start line: 1913
	/* end block 2 */
	// End Line: 1914

void G2EmulationInstanceSwitchAnimation
               (_Instance *instance,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode)

{
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section;
  
  section = (instance->anim).section + CurrentSection;
  keylist = G2Instance_GetKeylist(instance,NewAnim);
  G2AnimSection_SetAlphaTable(section,(_G2AnimAlphaTable_Type *)0x0);
  G2AnimSection_InterpToKeylistFrame(section,keylist,NewAnim,NewFrame,Frames * 0x640000 >> 0x10);
  if (Mode == 0) {
    G2AnimSection_SetPaused(section);
  }
  else {
    G2AnimSection_SetUnpaused(section);
    if (Mode == 2) {
      G2AnimSection_SetLooping(section);
    }
    else {
      G2AnimSection_SetNoLooping(section);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSwitchAnimationAlpha(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/, int Mode /*stack 20*/, int AlphaTable /*stack 24*/)
 // line 1012, offset 0x8007139c
	/* begin block 1 */
		// Start line: 1013
		// Start offset: 0x8007139C
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s1
	/* end block 1 */
	// End offset: 0x8007139C
	// End Line: 1013

	/* begin block 2 */
		// Start line: 1980
	/* end block 2 */
	// End Line: 1981

void G2EmulationInstanceSwitchAnimationAlpha
               (_Instance *instance,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode,
               int AlphaTable)

{
  G2EmulationInstanceSwitchAnimation(instance,CurrentSection,NewAnim,NewFrame,Frames,Mode);
  G2AnimSection_SetAlphaTable
            ((instance->anim).section + (CurrentSection & 0xff),(&G2AlphaTables7)[AlphaTable]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimation(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/, int Mode /*stack 20*/)
 // line 1022, offset 0x8007140c
	/* begin block 1 */
		// Start line: 2002
	/* end block 1 */
	// End Line: 2003

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
 // line 1036, offset 0x80071450
	/* begin block 1 */
		// Start line: 1037
		// Start offset: 0x80071450
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s1
	/* end block 1 */
	// End offset: 0x80071450
	// End Line: 1037

	/* begin block 2 */
		// Start line: 2030
	/* end block 2 */
	// End Line: 2031

void G2EmulationSwitchAnimationAlpha
               (__CharacterState *In,int CurrentSection,int NewAnim,int NewFrame,int Frames,int Mode
               ,int AlphaTable)

{
  _Instance *p_Var1;
  
  p_Var1 = In->CharacterInstance;
  G2EmulationInstanceSwitchAnimation
            (In->CharacterInstance,CurrentSection,NewAnim,NewFrame,Frames,Mode);
  G2AnimSection_SetAlphaTable
            ((p_Var1->anim).section + (CurrentSection & 0xff),(&G2AlphaTables7)[AlphaTable]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationSync(struct __CharacterState *In /*stack 0*/, int SlaveSectionID /*$fp*/, int MasterSectionID /*$a2*/, int Frames /*stack 12*/)
 // line 1048, offset 0x800714c8
	/* begin block 1 */
		// Start line: 1049
		// Start offset: 0x800714C8
		// Variables:
	// 		struct _Instance *instance; // $a1
	// 		struct _G2AnimSection_Type *masterAnimSection; // $s6
	// 		struct _G2AnimSection_Type *slaveAnimSection; // $s5
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	// 		int keylistID; // $s3
	// 		struct __State *masterSection; // $s7
	// 		struct __State *slaveSection; // $s2
	/* end block 1 */
	// End offset: 0x80071638
	// End Line: 1085

	/* begin block 2 */
		// Start line: 2056
	/* end block 2 */
	// End Line: 2057

void G2EmulationSwitchAnimationSync
               (__CharacterState *In,int SlaveSectionID,int MasterSectionID,int Frames)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section;
  _G2AnimSection_Type *section_00;
  __State *p_Var4;
  
  section_00 = (In->CharacterInstance->anim).section + (MasterSectionID & 0xff);
  section = (In->CharacterInstance->anim).section + (SlaveSectionID & 0xff);
  p_Var4 = In->SectionList + MasterSectionID;
  keylist = section_00->keylist;
  uVar1 = section_00->keylistID;
  iVar2 = G2AnimSection_GetKeyframeNumber(section_00);
  iVar3 = G2AnimKeylist_GetKeyframeCount(keylist);
  G2AnimSection_SetAlphaTable(section,(_G2AnimAlphaTable_Type *)0x0);
  G2AnimSection_InterpToKeylistFrame
            (section,keylist,(uint)uVar1,(iVar2 + Frames) % iVar3,Frames * 0x640000 >> 0x10);
  if ((section_00->flags & 2) == 0) {
    G2AnimSection_SetNoLooping(section);
  }
  else {
    G2AnimSection_SetLooping(section);
  }
  if ((section_00->flags & 1) == 0) {
    G2AnimSection_SetUnpaused(section);
  }
  else {
    G2AnimSection_SetPaused(section);
  }
  StateSwitchStateData
            (In,SlaveSectionID,(TDRFuncPtr_StateSwitchStateData2NewProcess)p_Var4->Process,0);
  In->SectionList[SlaveSectionID].Data1 = p_Var4->Data1;
  In->SectionList[SlaveSectionID].Data2 = p_Var4->Data2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceToInstanceSwitchAnimationCharacter(struct _Instance *instance /*$s0*/, struct _Instance *host /*$a1*/, int NewAnim /*$s2*/, int NewFrame /*$s3*/, int Frames /*stack 16*/, int Mode /*stack 20*/)
 // line 1092, offset 0x80071694
	/* begin block 1 */
		// Start line: 1093
		// Start offset: 0x80071694
		// Variables:
	// 		struct _G2AnimKeylist_Type *keylist1; // $s0
	/* end block 1 */
	// End offset: 0x8007175C
	// End Line: 1115

	/* begin block 2 */
		// Start line: 2167
	/* end block 2 */
	// End Line: 2168

void G2EmulationInstanceToInstanceSwitchAnimationCharacter
               (_Instance *instance,_Instance *host,int NewAnim,int NewFrame,int Frames,int Mode)

{
  _G2AnimKeylist_Type *keylist;
  _G2Anim_Type *anim;
  
  keylist = G2Instance_GetKeylist(host,NewAnim);
  anim = &instance->anim;
  G2Anim_SetAlphaTable(anim,(_G2AnimAlphaTable_Type *)0x0);
  G2Anim_InterpToKeylistFrame(anim,keylist,NewAnim,NewFrame,Frames * 0x640000 >> 0x10);
  if (Mode == 0) {
    G2Anim_SetPaused(anim);
  }
  else {
    G2Anim_SetUnpaused(anim);
    if (Mode == 2) {
      G2Anim_SetLooping(anim);
    }
    else {
      G2Anim_SetNoLooping(anim);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationCharacter(struct __CharacterState *In /*$a0*/, int NewAnim /*$s2*/, int NewFrame /*$s5*/, int Frames /*$s3*/, int Mode /*stack 16*/)
 // line 1119, offset 0x80071780
	/* begin block 1 */
		// Start line: 1120
		// Start offset: 0x80071780
		// Variables:
	// 		struct _Instance *instance; // $s0
	// 		struct _G2AnimKeylist_Type *keylist; // $s0
	/* end block 1 */
	// End offset: 0x80071850
	// End Line: 1147

	/* begin block 2 */
		// Start line: 2229
	/* end block 2 */
	// End Line: 2230

void G2EmulationSwitchAnimationCharacter
               (__CharacterState *In,int NewAnim,int NewFrame,int Frames,int Mode)

{
  _G2AnimKeylist_Type *keylist;
  _Instance *instance;
  _G2Anim_Type *anim;
  
  if (NewAnim < 0) {
    NewAnim = 0;
  }
  instance = In->CharacterInstance;
  keylist = G2Instance_GetKeylist(instance,NewAnim);
  anim = &instance->anim;
  G2Anim_SetAlphaTable(anim,(_G2AnimAlphaTable_Type *)0x0);
  G2Anim_InterpToKeylistFrame(anim,keylist,NewAnim,NewFrame,Frames * 0x640000 >> 0x10);
  if (Mode == 0) {
    G2Anim_SetPaused(anim);
  }
  else {
    G2Anim_SetUnpaused(anim);
    if (Mode == 2) {
      G2Anim_SetLooping(anim);
    }
    else {
      G2Anim_SetNoLooping(anim);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSwitchAnimationCharacterAlpha(struct __CharacterState *In /*$s1*/, int NewAnim /*$a1*/, int NewFrame /*$a2*/, int Frames /*$a3*/, int Mode /*stack 16*/, int AlphaTable /*stack 20*/)
 // line 1150, offset 0x80071874
	/* begin block 1 */
		// Start line: 2291
	/* end block 1 */
	// End Line: 2292

void G2EmulationSwitchAnimationCharacterAlpha
               (__CharacterState *In,int NewAnim,int NewFrame,int Frames,int Mode,int AlphaTable)

{
  G2EmulationSwitchAnimationCharacter(In,NewAnim,NewFrame,Frames,Mode);
  G2Anim_SetAlphaTable(&In->CharacterInstance->anim,(&G2AlphaTables7)[AlphaTable]);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetAnimation(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$s3*/, int NewFrame /*$s4*/, int Frames /*stack 16*/)
 // line 1158, offset 0x800718cc
	/* begin block 1 */
		// Start line: 1159
		// Start offset: 0x800718CC
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s2
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	/* end block 1 */
	// End offset: 0x800718CC
	// End Line: 1159

	/* begin block 2 */
		// Start line: 2307
	/* end block 2 */
	// End Line: 2308

void G2EmulationInstanceSetAnimation
               (_Instance *instance,int CurrentSection,int NewAnim,int NewFrame,int Frames)

{
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section;
  
  section = (instance->anim).section + (CurrentSection & 0xff);
  keylist = G2Instance_GetKeylist(instance,NewAnim);
  G2AnimSection_SetAlphaTable(section,(_G2AnimAlphaTable_Type *)0x0);
  G2AnimSection_InterpToKeylistFrame(section,keylist,NewAnim,NewFrame,Frames * 0x640000 >> 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetAnimation(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int NewAnim /*$a2*/, int NewFrame /*$a3*/, int Frames /*stack 16*/)
 // line 1172, offset 0x80071974
	/* begin block 1 */
		// Start line: 2356
	/* end block 1 */
	// End Line: 2357

void G2EmulationSetAnimation
               (__CharacterState *In,int CurrentSection,int NewAnim,int NewFrame,int Frames)

{
  if (NewAnim < 0) {
    NewAnim = 0;
  }
  G2EmulationInstanceSetAnimation(In->CharacterInstance,CurrentSection,NewAnim,NewFrame,Frames);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetMode(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int Mode /*$s1*/)
 // line 1187, offset 0x800719ac
	/* begin block 1 */
		// Start line: 1188
		// Start offset: 0x800719AC
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s0
	/* end block 1 */
	// End offset: 0x80071A18
	// End Line: 1204

	/* begin block 2 */
		// Start line: 2386
	/* end block 2 */
	// End Line: 2387

void G2EmulationInstanceSetMode(_Instance *instance,int CurrentSection,int Mode)

{
  _G2AnimSection_Type *section;
  
  section = (instance->anim).section + (CurrentSection & 0xff);
  if (Mode == 0) {
    G2AnimSection_SetPaused(section);
  }
  else {
    G2AnimSection_SetUnpaused(section);
    if (Mode == 1) {
      G2AnimSection_SetNoLooping(section);
    }
    else {
      G2AnimSection_SetLooping(section);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationSetMode(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/, int Mode /*$a2*/)
 // line 1208, offset 0x80071a2c
	/* begin block 1 */
		// Start line: 2436
	/* end block 1 */
	// End Line: 2437

void G2EmulationSetMode(__CharacterState *In,int CurrentSection,int Mode)

{
  G2EmulationInstanceSetMode(In->CharacterInstance,CurrentSection,Mode);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetAnimSpeed(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, int speed /*$a2*/)
 // line 1217, offset 0x80071a50
	/* begin block 1 */
		// Start line: 1219
		// Start offset: 0x80071A50
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $v0
	/* end block 1 */
	// End offset: 0x80071A50
	// End Line: 1221

	/* begin block 2 */
		// Start line: 2454
	/* end block 2 */
	// End Line: 2455

	/* begin block 3 */
		// Start line: 2455
	/* end block 3 */
	// End Line: 2456

	/* begin block 4 */
		// Start line: 2457
	/* end block 4 */
	// End Line: 2458

void G2EmulationInstanceSetAnimSpeed(_Instance *instance,int CurrentSection,int speed)

{
  (instance->anim).section[CurrentSection & 0xff].speedAdjustment = speed;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryAnimation(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1227, offset 0x80071a6c
	/* begin block 1 */
		// Start line: 1230
		// Start offset: 0x80071A6C
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $v0
	/* end block 1 */
	// End offset: 0x80071A6C
	// End Line: 1232

	/* begin block 2 */
		// Start line: 2474
	/* end block 2 */
	// End Line: 2475

	/* begin block 3 */
		// Start line: 2476
	/* end block 3 */
	// End Line: 2477

	/* begin block 4 */
		// Start line: 2478
	/* end block 4 */
	// End Line: 2479

int G2EmulationInstanceQueryAnimation(_Instance *instance,int CurrentSection)

{
  return (uint)(instance->anim).section[CurrentSection & 0xff].keylistID;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationQueryAnimation(struct __CharacterState *In /*$a0*/, int CurrentSection /*$a1*/)
 // line 1238, offset 0x80071a8c
	/* begin block 1 */
		// Start line: 2496
	/* end block 1 */
	// End Line: 2497

int G2EmulationQueryAnimation(__CharacterState *In,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2EmulationInstanceQueryAnimation(In->CharacterInstance,CurrentSection);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryFrame(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1246, offset 0x80071ab0
	/* begin block 1 */
		// Start line: 1247
		// Start offset: 0x80071AB0
	/* end block 1 */
	// End offset: 0x80071AB0
	// End Line: 1247

	/* begin block 2 */
		// Start line: 2512
	/* end block 2 */
	// End Line: 2513

int G2EmulationInstanceQueryFrame(_Instance *instance,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2AnimSection_GetKeyframeNumber((instance->anim).section + (CurrentSection & 0xff));
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryLastFrame(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1258, offset 0x80071ae4
	/* begin block 1 */
		// Start line: 1259
		// Start offset: 0x80071AE4
	/* end block 1 */
	// End offset: 0x80071AE4
	// End Line: 1259

	/* begin block 2 */
		// Start line: 2540
	/* end block 2 */
	// End Line: 2541

int G2EmulationInstanceQueryLastFrame(_Instance *instance,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2AnimSection_GetStoredKeyframeNumber((instance->anim).section + (CurrentSection & 0xff));
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryPassedFrame(struct _Instance *instance /*$s2*/, int CurrentSection /*$a1*/, int frame /*$s1*/)
 // line 1269, offset 0x80071b18
	/* begin block 1 */
		// Start line: 1270
		// Start offset: 0x80071B18
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $s0
	/* end block 1 */
	// End offset: 0x80071BA8
	// End Line: 1284

	/* begin block 2 */
		// Start line: 2565
	/* end block 2 */
	// End Line: 2566

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
 // line 1288, offset 0x80071bc0
	/* begin block 1 */
		// Start line: 2611
	/* end block 1 */
	// End Line: 2612

int G2EmulationQueryFrame(__CharacterState *In,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2EmulationInstanceQueryFrame(In->CharacterInstance,CurrentSection);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ G2EmulationInstanceQueryMode(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/)
 // line 1296, offset 0x80071be4
	/* begin block 1 */
		// Start line: 1299
		// Start offset: 0x80071BE4
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $v0
	/* end block 1 */
	// End offset: 0x80071C24
	// End Line: 1311

	/* begin block 2 */
		// Start line: 2627
	/* end block 2 */
	// End Line: 2628

	/* begin block 3 */
		// Start line: 2629
	/* end block 3 */
	// End Line: 2630

	/* begin block 4 */
		// Start line: 2631
	/* end block 4 */
	// End Line: 2632

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
 // line 1315, offset 0x80071c2c
	/* begin block 1 */
		// Start line: 2671
	/* end block 1 */
	// End Line: 2672

int G2EmulationQueryMode(__CharacterState *In,int CurrentSection)

{
  int iVar1;
  
  iVar1 = G2EmulationInstanceQueryMode(In->CharacterInstance,CurrentSection);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetStartAndEndSegment(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, short Start /*$a2*/, short End /*$a3*/)
 // line 1323, offset 0x80071c50
	/* begin block 1 */
		// Start line: 1326
		// Start offset: 0x80071C50
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $a0
	/* end block 1 */
	// End offset: 0x80071C50
	// End Line: 1328

	/* begin block 2 */
		// Start line: 2687
	/* end block 2 */
	// End Line: 2688

	/* begin block 3 */
		// Start line: 2689
	/* end block 3 */
	// End Line: 2690

	/* begin block 4 */
		// Start line: 2691
	/* end block 4 */
	// End Line: 2692

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
 // line 1334, offset 0x80071c7c
	/* begin block 1 */
		// Start line: 2709
	/* end block 1 */
	// End Line: 2710

void G2EmulationSetStartAndEndSegment(__CharacterState *In,int CurrentSection,short Start,short End)

{
  G2EmulationInstanceSetStartAndEndSegment(In->CharacterInstance,CurrentSection,Start,End);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceSetTotalSections(struct _Instance *instance /*$s2*/, short Total /*$a1*/)
 // line 1342, offset 0x80071cac
	/* begin block 1 */
		// Start line: 1343
		// Start offset: 0x80071CAC
		// Variables:
	// 		struct _G2Anim_Type *anim; // $s0
	/* end block 1 */
	// End offset: 0x80071D04
	// End Line: 1352

	/* begin block 2 */
		// Start line: 2727
	/* end block 2 */
	// End Line: 2728

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
 // line 1359, offset 0x80071d30
	/* begin block 1 */
		// Start line: 2767
	/* end block 1 */
	// End Line: 2768

void G2EmulationSetTotalSections(__CharacterState *In,short Total)

{
  In->TotalSections = (int)Total;
  G2EmulationInstanceSetTotalSections(In->CharacterInstance,Total);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ G2EmulationInstanceInitSection(struct _Instance *instance /*$a0*/, int CurrentSection /*$a1*/, void *callback /*$a2*/, void *data /*$a3*/)
 // line 1369, offset 0x80071d60
	/* begin block 1 */
		// Start line: 1372
		// Start offset: 0x80071D60
		// Variables:
	// 		struct _G2AnimSection_Type *animSection; // $a0
	/* end block 1 */
	// End offset: 0x80071D60
	// End Line: 1374

	/* begin block 2 */
		// Start line: 2789
	/* end block 2 */
	// End Line: 2790

	/* begin block 3 */
		// Start line: 2791
	/* end block 3 */
	// End Line: 2792

	/* begin block 4 */
		// Start line: 2793
	/* end block 4 */
	// End Line: 2794

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
 // line 1395, offset 0x80071d84
	/* begin block 1 */
		// Start line: 2784
	/* end block 1 */
	// End Line: 2785

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
// void /*$ra*/ StateSwitchStateData(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s2*/, TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess /*$s5*/, int Data /*$s4*/)
 // line 1412, offset 0x80071e0c
	/* begin block 1 */
		// Start line: 2880
	/* end block 1 */
	// End Line: 2881

void StateSwitchStateData
               (__CharacterState *In,int CurrentSection,
               TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess,int Data)

{
  __MessageQueue *In_00;
  
  In_00 = &In->SectionList[CurrentSection].Event;
  PurgeMessageQueue(In_00);
  EnMessageQueueData(In_00,0x100001,Data);
  *(TDRFuncPtr_StateSwitchStateData2NewProcess *)&In->SectionList[CurrentSection].Process =
       NewProcess;
  (*NewProcess)(In,CurrentSection,0);
  EnMessageQueueData(In_00,0x100004,0);
  EnMessageQueueData(In_00,0x100004,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateSwitchStateCharacterData(struct __CharacterState *In /*$s1*/, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess /*$s2*/, int Data /*$s3*/)
 // line 1426, offset 0x80071ed8
	/* begin block 1 */
		// Start line: 1427
		// Start offset: 0x80071ED8
		// Variables:
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x80071F34
	// End Line: 1435

	/* begin block 2 */
		// Start line: 2912
	/* end block 2 */
	// End Line: 2913

void StateSwitchStateCharacterData
               (__CharacterState *In,TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess,
               int Data)

{
  int CurrentSection;
  
  CurrentSection = 0;
  if (0 < In->TotalSections) {
    do {
      StateSwitchStateData
                (In,CurrentSection,(TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess,Data);
      CurrentSection = CurrentSection + 1;
    } while (CurrentSection < In->TotalSections);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateGovernState(struct __CharacterState *In /*$s7*/, int Frames /*$fp*/)
 // line 1439, offset 0x80071f50
	/* begin block 1 */
		// Start line: 1440
		// Start offset: 0x80071F50
		// Variables:
	// 		struct __State *pSectionA; // $v0
	// 		struct __State *pSectionB; // $v1
	// 		struct _G2AnimSection_Type *animSectionA; // $s1
	// 		struct _G2AnimSection_Type *animSectionB; // $s3
	// 		struct _G2AnimKeylist_Type *keylist; // $s1
	// 		int keylistID; // $s2
	// 		int i; // $s4
	/* end block 1 */
	// End offset: 0x800720A0
	// End Line: 1489

	/* begin block 2 */
		// Start line: 2939
	/* end block 2 */
	// End Line: 2940

void StateGovernState(__CharacterState *In,int Frames)

{
  ushort uVar1;
  _G2Bool_Enum _Var2;
  int iVar3;
  int iVar4;
  _G2AnimSection_Type *section;
  _G2AnimKeylist_Type *keylist;
  _G2AnimSection_Type *section_00;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = 1;
  iVar7 = 0x124;
  iVar6 = 8;
  do {
    if (*(int *)((int)&In->CharacterInstance + iVar6) ==
        *(int *)((int)&In->CharacterInstance + iVar7)) {
      section = (In->CharacterInstance->anim).section + (uVar5 - 1 & 0xff);
      section_00 = (In->CharacterInstance->anim).section + (uVar5 & 0xff);
      if (((section->keylistID == section_00->keylistID) &&
          (_Var2 = G2AnimSection_IsInInterpolation(section), _Var2 == G2FALSE)) &&
         (_Var2 = G2AnimSection_IsInInterpolation(section_00), _Var2 == G2FALSE)) {
        iVar3 = G2AnimSection_GetKeyframeNumber(section);
        iVar4 = G2AnimSection_GetKeyframeNumber(section_00);
        if (iVar3 != iVar4) {
          keylist = section->keylist;
          uVar1 = section->keylistID;
          iVar3 = G2AnimSection_GetKeyframeNumber(section);
          iVar4 = G2AnimKeylist_GetKeyframeCount(keylist);
          G2AnimSection_InterpToKeylistFrame
                    (section_00,keylist,(uint)uVar1,(iVar3 + Frames) % iVar4,
                     Frames * 0x640000 >> 0x10);
        }
      }
    }
    iVar7 = iVar7 + 0x11c;
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 0x11c;
  } while ((int)uVar5 < 3);
  return;
}





