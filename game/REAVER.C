#include "THISDUST.H"
#include "REAVER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 53, offset 0x80079730
	/* begin block 1 */
		// Start line: 54
		// Start offset: 0x80079730
		// Variables:
	// 		struct __ReaverData *data; // $v1
	/* end block 1 */
	// End offset: 0x800797B4
	// End Line: 106

	/* begin block 2 */
		// Start line: 106
	/* end block 2 */
	// End Line: 107

void SoulReaverInit(_Instance *instance,GameTracker *gameTracker)

{
  if ((instance->flags & 0x20000U) != 0) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)instance->extraData);
  }
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x24,'\x1e');
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$a1*/)
 // line 111, offset 0x800797cc
	/* begin block 1 */
		// Start line: 112
		// Start offset: 0x800797CC
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *S; // $v0
	// 		struct _Instance *target; // $s3
	// 		struct __ReaverData *reaverData; // $v0

		/* begin block 1.1 */
			// Start line: 127
			// Start offset: 0x80079838
			// Variables:
		// 		long type; // $s1
		/* end block 1.1 */
		// End offset: 0x800798EC
		// End Line: 199

		/* begin block 1.2 */
			// Start line: 224
			// Start offset: 0x800798FC
			// Variables:
		// 		struct _Instance *inst; // $v1
		/* end block 1.2 */
		// End offset: 0x800798FC
		// End Line: 224
	/* end block 1 */
	// End offset: 0x80079920
	// End Line: 231

	/* begin block 2 */
		// Start line: 282
	/* end block 2 */
	// End Line: 283

void SoulReaverCollide(_Instance *instance,GameTracker *gameTracker)

{
  _CollideInfo *collideInfo;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  if ((((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000) &&
      (*(char *)((int)collideInfo->prim0 + 4) == '\t')) &&
     (*(char *)((int)collideInfo->prim1 + 4) == '\b')) {
                    /* WARNING: Subroutine does not return */
    COLLIDE_SegmentCollisionOff(instance,0);
  }
  if (collideInfo->type1 == '\x03') {
    COLLIDE_SetBSPTreeFlag(collideInfo,0x800);
  }
  else {
    *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverProcess(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 235, offset 0x8007993c
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x8007993C
	/* end block 1 */
	// End offset: 0x8007993C
	// End Line: 236

	/* begin block 2 */
		// Start line: 541
	/* end block 2 */
	// End Line: 542

void SoulReaverProcess(_Instance *instance,GameTracker *gameTracker)

{
  _SoulReaverAnimate(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ CollideReaverProjectile(struct _Instance *instance /*$s4*/, struct GameTracker *gameTracker /*$s5*/)
 // line 258, offset 0x8007995c
	/* begin block 1 */
		// Start line: 259
		// Start offset: 0x8007995C
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s2
	// 		struct _Instance *target; // $s3
	// 		long type; // $s0
	// 		long reavType; // $s1

		/* begin block 1.1 */
			// Start line: 281
			// Start offset: 0x800799D8
			// Variables:
		// 		struct Level *level; // $v1
		/* end block 1.1 */
		// End offset: 0x80079A08
		// End Line: 290

		/* begin block 1.2 */
			// Start line: 343
			// Start offset: 0x80079A88
			// Variables:
		// 		struct _Instance *inst; // $v1
		/* end block 1.2 */
		// End offset: 0x80079A88
		// End Line: 343
	/* end block 1 */
	// End offset: 0x80079AB8
	// End Line: 351

	/* begin block 2 */
		// Start line: 587
	/* end block 2 */
	// End Line: 588

void CollideReaverProjectile(_Instance *instance,GameTracker *gameTracker)

{
  int Power;
  int iVar1;
  _CollideInfo *collideInfo;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  iVar1 = *(int *)((int)instance->extraData + 4) + -2;
  Power = 0;
  if ((*(uint *)&collideInfo->flags & 0xffff0000) == 0x1010000) {
    if (0 < iVar1) {
      if (iVar1 < 3) {
        Power = 0x1000;
      }
      else {
        if (iVar1 == 6) {
                    /* WARNING: Subroutine does not return */
          STREAM_GetLevelWithID(instance->currentStreamUnitID);
        }
      }
    }
    if (Power != 0) {
                    /* WARNING: Subroutine does not return */
      SetMonsterHitData(instance,(_Instance *)0x0,Power,0,0);
    }
  }
  if (collideInfo->type1 == '\x03') {
    COLLIDE_SetBSPTreeFlag(collideInfo,0x800);
  }
  else {
    *(uint *)((int)collideInfo->inst1 + 0x14) = *(uint *)((int)collideInfo->inst1 + 0x14) | 4;
  }
  CollidePhysicalObject(instance,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SoulReaverQuery(struct _Instance *instance /*$a0*/, unsigned long query /*$a1*/)
 // line 355, offset 0x80079adc
	/* begin block 1 */
		// Start line: 358
		// Start offset: 0x80079ADC

		/* begin block 1.1 */
			// Start line: 367
			// Start offset: 0x80079B24
			// Variables:
		// 		struct __ReaverData *reaverData; // $a0
		// 		unsigned long retval; // $v1
		/* end block 1.1 */
		// End offset: 0x80079B58
		// End Line: 376
	/* end block 1 */
	// End offset: 0x80079B58
	// End Line: 382

	/* begin block 2 */
		// Start line: 789
	/* end block 2 */
	// End Line: 790

	/* begin block 3 */
		// Start line: 791
	/* end block 3 */
	// End Line: 792

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
      if (*(short *)((int)instance->extraData + 0x1e) != 0) {
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
 // line 384, offset 0x80079b60
	/* begin block 1 */
		// Start line: 385
		// Start offset: 0x80079B60
		// Variables:
	// 		long color; // $a1
	// 		struct __ReaverTuneData *tuneData; // $v0
	/* end block 1 */
	// End offset: 0x80079B60
	// End Line: 385

	/* begin block 2 */
		// Start line: 847
	/* end block 2 */
	// End Line: 848

void SoulReaverImbue(_Instance *instance,int number)

{
  FX_DoBlastRing(instance,(_SVector *)&instance->position,instance->matrix,0,0x140,0,0xf0,0,0,
                 -0x10000,0,0,0xa0,0x140,*(long *)((int)instance->data + number * 4 + -4),0,0,0x14,1
                );
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverCharge(struct _Instance *instance /*$s2*/, struct __ReaverData *data /*$s0*/)
 // line 416, offset 0x80079bec
	/* begin block 1 */
		// Start line: 417
		// Start offset: 0x80079BEC
		// Variables:
	// 		long color; // $v1
	// 		long shock; // $a0
	// 		struct __ReaverTuneData *tuneData; // $s1
	/* end block 1 */
	// End offset: 0x80079D08
	// End Line: 462

	/* begin block 2 */
		// Start line: 920
	/* end block 2 */
	// End Line: 921

void SoulReaverCharge(_Instance *instance,__ReaverData *data)

{
  int motor1_speed;
  
  if (data->ReaverChargeTime != 0) {
    data->ReaverChargeTime = data->ReaverChargeTime - gameTrackerX.timeMult;
    if (data->ReaverShockAmount < 0x3c000) {
      motor1_speed = data->ReaverShockAmount + gameTrackerX.timeMult;
      data->ReaverShockAmount = motor1_speed;
      motor1_speed = motor1_speed / 0xdb6 + 0x50;
    }
    else {
      motor1_speed = 0x96;
    }
                    /* WARNING: Subroutine does not return */
    GAMEPAD_Shock1(motor1_speed,(int)&DAT_00005000);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StopSoulReaverCharge(struct __ReaverData *data /*$v0*/, struct _Instance *instance /*$s0*/)
 // line 464, offset 0x80079d20
	/* begin block 1 */
		// Start line: 1033
	/* end block 1 */
	// End Line: 1034

void StopSoulReaverCharge(__ReaverData *data,_Instance *instance)

{
  data->ReaverChargeTime = 0;
                    /* WARNING: Subroutine does not return */
  data->ReaverShockAmount = 0;
  GAMEPAD_Shock1(0,0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ SoulReaverPost(struct _Instance *instance /*$s1*/, unsigned long message /*$a1*/, unsigned long data /*$s3*/)
 // line 476, offset 0x80079d60
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x80079D60
		// Variables:
	// 		struct __ReaverData *reaverData; // $s0

		/* begin block 1.1 */
			// Start line: 523
			// Start offset: 0x80079F24
			// Variables:
		// 		struct SVECTOR oldVector; // stack offset -40
		// 		struct SVECTOR startPos; // stack offset -32

			/* begin block 1.1.1 */
				// Start line: 527
				// Start offset: 0x80079F24
				// Variables:
			// 		struct __ReaverData *reaverData; // $v0
			// 		struct evObjectBirthProjectileData *pData; // $s0

				/* begin block 1.1.1.1 */
					// Start line: 567
					// Start offset: 0x80079FBC
					// Variables:
				// 		short _x1; // $v1
				// 		short _y1; // $a0
				// 		short _z1; // $a2
				// 		struct _Position *_v0; // $v0
				/* end block 1.1.1.1 */
				// End offset: 0x80079FBC
				// End Line: 567

				/* begin block 1.1.1.2 */
					// Start line: 567
					// Start offset: 0x80079FBC
					// Variables:
				// 		short _x1; // $v1
				// 		short _y1; // $a0
				// 		short _z1; // $a1
				// 		struct _Position *_v0; // $v0
				/* end block 1.1.1.2 */
				// End offset: 0x80079FBC
				// End Line: 567
			/* end block 1.1.1 */
			// End offset: 0x80079FBC
			// End Line: 567
		/* end block 1.1 */
		// End offset: 0x80079FBC
		// End Line: 567
	/* end block 1 */
	// End offset: 0x8007A06C
	// End Line: 611

	/* begin block 2 */
		// Start line: 1060
	/* end block 2 */
	// End Line: 1061

void SoulReaverPost(_Instance *instance,ulong message,ulong data)

{
  int Data;
  __ReaverData *data_00;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined local_20 [8];
  
  data_00 = (__ReaverData *)instance->extraData;
  if (message == 0x800101) {
    data_00->ReaverOn = '\0';
    StopSoulReaverCharge(data_00,instance);
    instance->flags = instance->flags | 0x800;
  }
  else {
    if (message < 0x800102) {
      if (message == 0x800002) {
        if (instance->LinkParent == (_Instance *)0x0) {
          INSTANCE_LinkToParent(instance,(_Instance *)data,0x29);
        }
        data_00->ReaverOn = '\x01';
        data_00->ReaverPickedUp = '\x01';
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
                    /* WARNING: Subroutine does not return */
          COLLIDE_SegmentCollisionOff(instance,0);
        }
        if (message == 0x800010) {
          StopSoulReaverCharge(data_00,instance);
          local_28 = 0;
          local_26 = 0;
          local_24 = 400;
                    /* WARNING: Subroutine does not return */
          ApplyMatrixSV(instance->matrix,&local_28,local_20);
        }
        if (message != 0x800100) {
          return;
        }
        data_00->ReaverOn = '\x01';
      }
      instance->flags = instance->flags & 0xfffff7ff;
    }
    else {
      if (message == 0x800105) {
        StopSoulReaverCharge(data_00,instance);
      }
      else {
        if (message < 0x800106) {
          if (message == 0x800103) {
            data_00->CurrentReaver = (short)data;
            SoulReaverImbue(instance,data);
          }
          else {
            if (message == 0x800104) {
              data_00->ReaverChargeTime = 0xf000;
              Data = SetObjectAbsorbData(instance,0,0x3c);
              INSTANCE_Broadcast(instance,0x20,0x800028,Data);
            }
          }
        }
        else {
          if (message == 0x800108) {
            data_00->ReaverTargetScale = 0x1000;
          }
          else {
            if (message < 0x800109) {
              if (message == 0x800107) {
                data_00->ReaverTargetScale = (short)data;
              }
            }
            else {
              if (message == 0x800109) {
                StopSoulReaverCharge(data_00,instance);
                data_00->ReaverTargetScale = 0;
              }
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
// unsigned long /*$ra*/ REAVER_GetGlowColor(struct _Instance *instance /*$a0*/)
 // line 613, offset 0x8007a088
	/* begin block 1 */
		// Start line: 615
		// Start offset: 0x8007A088
		// Variables:
	// 		struct __ReaverTuneData *tuneData; // $v1
	// 		struct __ReaverData *data; // $v0
	/* end block 1 */
	// End offset: 0x8007A088
	// End Line: 619

	/* begin block 2 */
		// Start line: 1348
	/* end block 2 */
	// End Line: 1349

	/* begin block 3 */
		// Start line: 1349
	/* end block 3 */
	// End Line: 1350

	/* begin block 4 */
		// Start line: 1353
	/* end block 4 */
	// End Line: 1354

ulong REAVER_GetGlowColor(_Instance *instance)

{
  return *(ulong *)((int)instance->data + (int)*(short *)((int)instance->extraData + 4) * 4 + -4);
}



// decompiled code
// original method signature: 
// void /*$ra*/ _SoulReaverAnimate(struct _Instance *instance /*$s2*/)
 // line 631, offset 0x8007a0ac
	/* begin block 1 */
		// Start line: 632
		// Start offset: 0x8007A0AC
		// Variables:
	// 		struct __ReaverData *data; // $s0
	// 		struct __ReaverTuneData *tuneData; // $s1
	/* end block 1 */
	// End offset: 0x8007A208
	// End Line: 676

	/* begin block 2 */
		// Start line: 1389
	/* end block 2 */
	// End Line: 1390

void _SoulReaverAnimate(_Instance *instance)

{
  FX_SetReaverInstance(instance);
                    /* WARNING: Subroutine does not return */
  rand();
}





