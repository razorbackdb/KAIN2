#include "THISDUST.H"
#include "REAVER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 50, offset 0x8007933c
	/* begin block 1 */
		// Start line: 51
		// Start offset: 0x8007933C
		// Variables:
	// 		struct __ReaverData *data; // $v1
	/* end block 1 */
	// End offset: 0x800793BC
	// End Line: 102

	/* begin block 2 */
		// Start line: 100
	/* end block 2 */
	// End Line: 101

void SoulReaverInit(_Instance *instance,GameTracker *gameTracker)

{
  char *pcVar1;
  
  if ((instance->flags & 0x20000U) == 0) {
    pcVar1 = MEMPACK_Malloc(0x20,'\x1e');
    *(char **)&instance->extraData = pcVar1;
    *(undefined2 *)(pcVar1 + 4) = 2;
    pcVar1[1] = '\x01';
    *(undefined4 *)(pcVar1 + 8) = 0;
    *pcVar1 = '\0';
    *(undefined2 *)(pcVar1 + 2) = 0x1000;
    *(undefined2 *)(pcVar1 + 6) = 0;
    *(undefined2 *)(pcVar1 + 0x18) = 0x1000;
    *(undefined2 *)(pcVar1 + 0x1a) = 0x1000;
    COLLIDE_SegmentCollisionOff(instance,0);
  }
  else {
    MEMPACK_Free((char *)instance->extraData);
  }
  FX_ReaverBladeInit();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverCollide(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 107, offset 0x800793d4
	/* begin block 1 */
		// Start line: 108
		// Start offset: 0x800793D4
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s2
	// 		struct _HSphere *S; // $v0
	// 		struct _Instance *target; // $s3
	// 		struct __ReaverData *reaverData; // $v0

		/* begin block 1.1 */
			// Start line: 123
			// Start offset: 0x80079440
			// Variables:
		// 		long type; // $s0
		/* end block 1.1 */
		// End offset: 0x800794F4
		// End Line: 195
	/* end block 1 */
	// End offset: 0x800794F4
	// End Line: 217

	/* begin block 2 */
		// Start line: 272
	/* end block 2 */
	// End Line: 273

void SoulReaverCollide(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  int Data;
  int Power;
  void *pvVar2;
  _Instance *Inst;
  
  pvVar2 = instance->collideInfo;
  if ((((*(uint *)((int)pvVar2 + 4) & 0xffff0000) == 0x1010000) &&
      (*(char *)(*(int *)((int)pvVar2 + 8) + 4) == '\t')) &&
     (*(char *)(*(int *)((int)pvVar2 + 0xc) + 4) == '\b')) {
    Inst = *(_Instance **)((int)pvVar2 + 0x14);
    COLLIDE_SegmentCollisionOff(instance,0);
    sVar1 = *(short *)((int)instance->extraData + 4);
    Power = 0;
    if (0 < sVar1) {
      if (sVar1 < 3) {
        Power = 0x1000;
      }
      else {
        if (sVar1 == 6) {
          Power = 0x20;
        }
      }
    }
    if (instance->LinkParent != (_Instance *)0x0) {
      COLLIDE_SegmentCollisionOff(instance,0);
      Data = SetMonsterHitData(instance->LinkParent,(_Instance *)0x0,Power,0,0);
      INSTANCE_Post(Inst,0x100001f,Data);
      Power = SetFXHitData(instance,(uint)*(byte *)((int)pvVar2 + 5),0x32,Power);
      INSTANCE_Post(Inst,0x400000,Power);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverProcess(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 221, offset 0x80079510
	/* begin block 1 */
		// Start line: 222
		// Start offset: 0x80079510
	/* end block 1 */
	// End offset: 0x80079510
	// End Line: 222

	/* begin block 2 */
		// Start line: 511
	/* end block 2 */
	// End Line: 512

void SoulReaverProcess(_Instance *instance,GameTracker *gameTracker)

{
  _SoulReaverAnimate(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CollideReaverProjectile(struct _Instance *instance /*$s3*/, struct GameTracker *gameTracker /*$s4*/)
 // line 244, offset 0x80079530
	/* begin block 1 */
		// Start line: 245
		// Start offset: 0x80079530
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1
	// 		struct _Instance *target; // $s2
	// 		long type; // $a2
	// 		long reavType; // $s0
	/* end block 1 */
	// End offset: 0x80079618
	// End Line: 318

	/* begin block 2 */
		// Start line: 557
	/* end block 2 */
	// End Line: 558

void CollideReaverProjectile(_Instance *instance,GameTracker *gameTracker)

{
  int Power;
  int iVar1;
  void *pvVar2;
  _Instance *Inst;
  
  pvVar2 = instance->collideInfo;
  Inst = *(_Instance **)((int)pvVar2 + 0x14);
  iVar1 = *(int *)((int)instance->extraData + 4) + -2;
  Power = 0;
  if ((*(uint *)((int)pvVar2 + 4) & 0xffff0000) == 0x1010000) {
    if (0 < iVar1) {
      if (iVar1 < 3) {
        Power = 0x1000;
      }
      else {
        if (iVar1 == 6) {
          Power = 0x20;
        }
      }
    }
    if (Power != 0) {
      Power = SetMonsterHitData(instance,(_Instance *)0x0,Power,0,0);
      INSTANCE_Post(Inst,0x1000021,Power);
      if (iVar1 == 2) {
        Power = SetFXHitData(instance,(uint)*(byte *)((int)pvVar2 + 5),0x20,0x100);
        INSTANCE_Post(Inst,0x400000,Power);
        INSTANCE_Post(Inst,0x80005,0);
      }
    }
  }
  CollidePhysicalObject(instance,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SoulReaverQuery(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 323, offset 0x80079644
	/* begin block 1 */
		// Start line: 326
		// Start offset: 0x80079644

		/* begin block 1.1 */
			// Start line: 335
			// Start offset: 0x8007968C
			// Variables:
		// 		struct __ReaverData *reaverData; // $a0
		// 		unsigned long retval; // $v1
		/* end block 1.1 */
		// End offset: 0x800796C0
		// End Line: 344
	/* end block 1 */
	// End offset: 0x800796C0
	// End Line: 350

	/* begin block 2 */
		// Start line: 723
	/* end block 2 */
	// End Line: 724

	/* begin block 3 */
		// Start line: 725
	/* end block 3 */
	// End Line: 726

ulong SoulReaverQuery(_Instance *instance,ulong query)

{
  ulong uVar1;
  
  if (query == 4) {
    return 0x1000;
  }
  if (query < 5) {
    if (query == 1) {
      return 0x20000;
    }
  }
  else {
    if ((query == 0x28) && (*(char *)((int)instance->extraData + 1) != '\0')) {
      uVar1 = 1;
      if (*(short *)((int)instance->extraData + 0x1a) != 0) {
        uVar1 = 3;
      }
      return uVar1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverImbue(struct _Instance *instance /*$a0*/, int number /*$a1*/)
 // line 352, offset 0x800796c8
	/* begin block 1 */
		// Start line: 353
		// Start offset: 0x800796C8
		// Variables:
	// 		long color; // $a1
	// 		struct __ReaverTuneData *tuneData; // $v0
	/* end block 1 */
	// End offset: 0x800796C8
	// End Line: 353

	/* begin block 2 */
		// Start line: 781
	/* end block 2 */
	// End Line: 782

void SoulReaverImbue(_Instance *instance,int number)

{
  FX_DoBlastRing(instance,(_SVector *)&instance->position,(MATRIX *)instance->matrix,0,0x140,0,
                 -0x500,0,0,-0x10000,0,0,0xa0,0x140,*(long *)((int)instance->data + number * 4 + -4)
                 ,0,0,0x14,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverPost(struct _Instance *instance /*$s1*/, unsigned long message /*$a1*/, unsigned long data /*$s2*/)
 // line 384, offset 0x80079754
	/* begin block 1 */
		// Start line: 385
		// Start offset: 0x80079754
		// Variables:
	// 		struct __ReaverData *reaverData; // $s0

		/* begin block 1.1 */
			// Start line: 429
			// Start offset: 0x800798E4
			// Variables:
		// 		struct SVECTOR oldVector; // stack offset -32
		// 		struct SVECTOR startPos; // stack offset -24

			/* begin block 1.1.1 */
				// Start line: 433
				// Start offset: 0x800798E4
				// Variables:
			// 		struct __ReaverData *reaverData; // $v0
			// 		struct evObjectBirthProjectileData *pData; // $a3

				/* begin block 1.1.1.1 */
					// Start line: 460
					// Start offset: 0x80079970
					// Variables:
				// 		short _x1; // $v1
				// 		short _y1; // $a0
				// 		short _z1; // $a2
				// 		struct _Position *_v0; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x80079970
				// End Line: 460
			/* end block 1.1.1 */
			// End offset: 0x80079970
			// End Line: 460
		/* end block 1.1 */
		// End offset: 0x80079970
		// End Line: 460
	/* end block 1 */
	// End offset: 0x800799E4
	// End Line: 498

	/* begin block 2 */
		// Start line: 854
	/* end block 2 */
	// End Line: 855

void SoulReaverPost(_Instance *instance,ulong message,ulong data)

{
  int Data;
  evObjectBirthProjectileData *peVar1;
  _Instance *p_Var2;
  undefined *puVar3;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  short local_18;
  short local_16;
  short local_14;
  
  puVar3 = (undefined *)instance->extraData;
  if (message == 0x800101) {
    puVar3[1] = 0;
    instance->flags = instance->flags | 0x800;
  }
  else {
    if (message < 0x800102) {
      if (message == 0x800002) {
        if (instance->LinkParent == (_Instance *)0x0) {
          INSTANCE_LinkToParent(instance,(_Instance *)data,0x29);
        }
        puVar3[1] = 1;
        *puVar3 = 1;
      }
      else {
        if (message < 0x800003) {
          if (message == 0x200002) {
            COLLIDE_SegmentCollisionOn(instance,0);
            return;
          }
          if (message != 0x200003) {
            return;
          }
          COLLIDE_SegmentCollisionOff(instance,0);
          return;
        }
        if (message == 0x800010) {
          local_20 = 0;
          local_1e = 0;
          local_1c = 0x80;
          ApplyMatrixSV(instance->matrix,&local_20,&local_18);
          local_18 = local_18 + (instance->position).x;
          local_16 = local_16 + (instance->position).y;
          local_14 = local_14 + (instance->position).z;
          peVar1 = PHYSOB_BirthProjectile
                             (instance->LinkParent,0,
                              (int)*(short *)((int)instance->extraData + 4) + 2);
          if (peVar1->birthInstance == (_Instance *)0x0) {
            return;
          }
          peVar1->birthInstance->collideFunc = CollideReaverProjectile;
          p_Var2 = peVar1->birthInstance;
          (p_Var2->position).x = local_18;
          (p_Var2->position).y = local_16;
          (p_Var2->position).z = local_14;
          INSTANCE_Post(peVar1->birthInstance,0x800010,data);
          return;
        }
        if (message != 0x800100) {
          return;
        }
        puVar3[1] = 1;
      }
      instance->flags = instance->flags & 0xfffff7ff;
    }
    else {
      if (message == 0x800107) {
        *(short *)(puVar3 + 0x1a) = (short)data;
      }
      else {
        if (message < 0x800108) {
          if (message == 0x800103) {
            *(short *)(puVar3 + 4) = (short)data;
            SoulReaverImbue(instance,data);
          }
          else {
            if (message == 0x800104) {
              Data = SetObjectAbsorbData(instance,0,0x3c);
              INSTANCE_Broadcast(instance,0x20,0x800028,Data);
            }
          }
        }
        else {
          if (message == 0x800108) {
            *(undefined2 *)(puVar3 + 0x1a) = 0;
          }
          else {
            if (message == 0x800109) {
              *(undefined2 *)(puVar3 + 0x1a) = 0x1000;
            }
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ _SoulReaverAnimate(struct _Instance *instance /*$a0*/)
 // line 508, offset 0x800799fc
	/* begin block 1 */
		// Start line: 509
		// Start offset: 0x800799FC
		// Variables:
	// 		struct __ReaverData *data; // $s0
	// 		struct __ReaverTuneData *tuneData; // $s1
	/* end block 1 */
	// End offset: 0x80079B50
	// End Line: 552

	/* begin block 2 */
		// Start line: 1111
	/* end block 2 */
	// End Line: 1112

void _SoulReaverAnimate(_Instance *instance)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar3 = instance->extraData;
  pvVar4 = instance->data;
  FX_SetReaverInstance(instance);
  iVar1 = rand();
  *(ushort *)((int)pvVar3 + 6) =
       *(short *)((int)pvVar3 + 6) + 0x100 + ((ushort)iVar1 & 0x1f) & 0xfff;
  if (*(char *)((int)pvVar3 + 1) == '\x01') {
    if (*(short *)((int)pvVar3 + 2) < 0x1000) {
      *(short *)((int)pvVar3 + 2) = *(short *)((int)pvVar3 + 2) + 0x100;
    }
  }
  else {
    if (0 < *(short *)((int)pvVar3 + 2)) {
      *(short *)((int)pvVar3 + 2) = *(short *)((int)pvVar3 + 2) + -0x100;
    }
  }
  if (0 < (int)*(short *)((int)pvVar3 + 4)) {
    *(undefined4 *)((int)pvVar3 + 0x10) =
         *(undefined4 *)((int)pvVar4 + (int)*(short *)((int)pvVar3 + 4) * 4 + 0x1c);
    *(undefined4 *)((int)pvVar3 + 0x14) =
         *(undefined4 *)((int)pvVar4 + (int)*(short *)((int)pvVar3 + 4) * 4 + 0x3c);
    *(undefined4 *)((int)pvVar3 + 0xc) =
         *(undefined4 *)((int)pvVar4 + (int)*(short *)((int)pvVar3 + 4) * 4 + -4);
  }
  iVar2 = (int)*(short *)((int)pvVar3 + 0x18);
  iVar1 = *(short *)((int)pvVar3 + 0x1a) - iVar2;
  if (iVar1 < 0) {
    if (0x80 < iVar2 - *(short *)((int)pvVar3 + 0x1a)) {
      iVar2 = (int)*(short *)((int)pvVar3 + 0x18);
      goto LAB_80079b14;
    }
  }
  else {
    if (0x80 < iVar1) {
LAB_80079b14:
      if (*(short *)((int)pvVar3 + 0x1a) < iVar2) {
        *(short *)((int)pvVar3 + 0x18) = *(short *)((int)pvVar3 + 0x18) + -0x80;
      }
      if (*(short *)((int)pvVar3 + 0x1a) <= *(short *)((int)pvVar3 + 0x18)) {
        return;
      }
      *(short *)((int)pvVar3 + 0x18) = *(short *)((int)pvVar3 + 0x18) + 0x80;
      return;
    }
  }
  *(undefined2 *)((int)pvVar3 + 0x18) = *(undefined2 *)((int)pvVar3 + 0x1a);
  return;
}





