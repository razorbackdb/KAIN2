#include "THISDUST.H"
#include "SOUL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_QueueHandler(struct _Instance *instance /*$s0*/)
 // line 79, offset 0x8008bd4c
	/* begin block 1 */
		// Start line: 80
		// Start offset: 0x8008BD4C
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x8008BDCC
	// End Line: 94

	/* begin block 2 */
		// Start line: 158
	/* end block 2 */
	// End Line: 159

void SOUL_QueueHandler(_Instance *instance)

{
  __Event *message;
  undefined4 local_18;
  undefined4 local_14;
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  while (message = DeMessageQueue((__MessageQueue *)((int)pvVar1 + 8)), message != (__Event *)0x0) {
    if (message->ID == 0x100000d) {
      if (instance->currentMainState != 0x17) {
        MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
      }
    }
    else {
      MON_DefaultMessageHandler(instance,message);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Physics(struct _Instance *instance /*$a0*/, long time /*$a2*/)
 // line 99, offset 0x8008bde8
	/* begin block 1 */
		// Start line: 100
		// Start offset: 0x8008BDE8
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int a; // $a1
	/* end block 1 */
	// End offset: 0x8008BE14
	// End Line: 113

	/* begin block 2 */
		// Start line: 206
	/* end block 2 */
	// End Line: 207

void SOUL_Physics(_Instance *instance,long time)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = instance->extraData;
  iVar2 = -4;
  if ((*(ushort *)((int)pvVar1 + 0x126) & 0x1f) < 0x10) {
    iVar2 = 4;
  }
  instance->zAccl = instance->zAccl + iVar2;
  *(short *)((int)pvVar1 + 0x126) = *(short *)((int)pvVar1 + 0x126) + 1;
  PhysicsMove(instance,&instance->position,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Fade(struct _Instance *instance /*$s0*/)
 // line 119, offset 0x8008be48
	/* begin block 1 */
		// Start line: 120
		// Start offset: 0x8008BE48
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		unsigned long time; // $a0
	/* end block 1 */
	// End offset: 0x8008BEF0
	// End Line: 144

	/* begin block 2 */
		// Start line: 249
	/* end block 2 */
	// End Line: 250

void SOUL_Fade(_Instance *instance)

{
  short sVar1;
  ulong uVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  uVar2 = MON_GetTime(instance);
  if ((gameTrackerX.gameFlags & 0x80U) == 0) {
    if (*(uint *)((int)pvVar3 + 0x10c) < uVar2) {
      sVar1 = instance->fadeValue;
      if (sVar1 == 0) {
        MON_StartSpecialFade(instance,0x1000,100);
        sVar1 = instance->fadeValue;
      }
      if (0xfff < sVar1) {
        instance->flags2 = instance->flags2 | 0x8000000;
        MORPH_SetupInstanceFlags(&gameTrackerX,instance);
        instance->fadeValue = 0;
      }
    }
  }
  else {
    *(int *)((int)pvVar3 + 0x10c) = uVar2 + 0x1964;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_MoveToDest(struct _Instance *instance /*$a3*/, long maxAccel /*$t0*/, long time /*$a2*/)
 // line 146, offset 0x8008bf04
	/* begin block 1 */
		// Start line: 147
		// Start offset: 0x8008BF04
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x8008BFD8
	// End Line: 157

	/* begin block 2 */
		// Start line: 304
	/* end block 2 */
	// End Line: 305

void SOUL_MoveToDest(_Instance *instance,long maxAccel,long time)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  instance->xAccl =
       ((int)*(short *)((int)pvVar1 + 0x120) - (int)(instance->position).x) - instance->xVel;
  instance->yAccl =
       ((int)*(short *)((int)pvVar1 + 0x122) - (int)(instance->position).y) - instance->yVel;
  instance->zAccl =
       ((int)*(short *)((int)pvVar1 + 0x124) - (int)(instance->position).z) - instance->zVel;
  if (instance->xAccl < -maxAccel) {
    instance->xAccl = -maxAccel;
  }
  else {
    if (maxAccel < instance->xAccl) {
      instance->xAccl = maxAccel;
    }
  }
  if (instance->yAccl < -maxAccel) {
    instance->yAccl = -maxAccel;
  }
  else {
    if (maxAccel < instance->yAccl) {
      instance->yAccl = maxAccel;
    }
  }
  if (instance->zAccl < -maxAccel) {
    instance->zAccl = -maxAccel;
  }
  else {
    if (maxAccel < instance->zAccl) {
      instance->zAccl = maxAccel;
    }
  }
  SOUL_Physics(instance,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Init(struct _Instance *instance /*$s1*/)
 // line 163, offset 0x8008bff4
	/* begin block 1 */
		// Start line: 164
		// Start offset: 0x8008BFF4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008C0A0
	// End Line: 187

	/* begin block 2 */
		// Start line: 339
	/* end block 2 */
	// End Line: 340

void SOUL_Init(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  uint *puVar2;
  undefined4 local_c;
  
  puVar2 = (uint *)instance->extraData;
  MON_DefaultInit(instance);
  *puVar2 = *puVar2 | 0x200880;
  instance->maxXVel = 600;
  instance->maxYVel = 600;
  instance->maxZVel = 600;
  *(undefined2 *)((int)puVar2 + 0x126) = 0;
  uVar1 = MON_GetTime(instance);
  puVar2[0x43] = uVar1 + 0x1964;
  if (instance->parent != (_Instance *)0x0) {
    puVar2[0x36] = instance->parent->introUniqueID;
  }
  if ((instance->flags & 2U) == 0) {
    instance->flags2 = instance->flags2 | 0x8000000;
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_CleanUp(struct _Instance *instance /*$a0*/)
 // line 193, offset 0x8008c0b4
	/* begin block 1 */
		// Start line: 407
	/* end block 1 */
	// End Line: 408

void SOUL_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 203, offset 0x8008c0d4
	/* begin block 1 */
		// Start line: 204
		// Start offset: 0x8008C0D4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008C0D4
	// End Line: 204

	/* begin block 2 */
		// Start line: 427
	/* end block 2 */
	// End Line: 428

void SOUL_BirthEntry(_Instance *instance)

{
  short sVar1;
  ulong uVar2;
  void *pvVar3;
  
  sVar1 = (instance->position).z;
  pvVar3 = instance->extraData;
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  instance->zAccl = 0;
  instance->zVel = 0;
  (instance->position).z = sVar1 + 0x78;
  uVar2 = MON_GetTime(instance);
  *(int *)((int)pvVar3 + 0x114) = uVar2 + 0x5dc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Birth(struct _Instance *instance /*$s1*/)
 // line 214, offset 0x8008c128
	/* begin block 1 */
		// Start line: 215
		// Start offset: 0x8008C128
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008C174
	// End Line: 226

	/* begin block 2 */
		// Start line: 453
	/* end block 2 */
	// End Line: 454

void SOUL_Birth(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  void *pvVar2;
  undefined4 local_c;
  
  instance->zAccl = 0;
  pvVar2 = instance->extraData;
  SOUL_Physics(instance,gameTrackerX.idleTime);
  uVar1 = MON_GetTime(instance);
  if (*(uint *)((int)pvVar2 + 0x114) < uVar1) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  SOUL_QueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuckEntry(struct _Instance *instance /*$a0*/)
 // line 232, offset 0x8008c190
	/* begin block 1 */
		// Start line: 492
	/* end block 1 */
	// End Line: 493

	/* begin block 2 */
		// Start line: 495
	/* end block 2 */
	// End Line: 496

void SOUL_SoulSuckEntry(_Instance *instance)

{
  instance->maxXVel = 600;
  instance->maxYVel = 600;
  instance->maxZVel = 0x11;
  instance->flags = instance->flags & 0xfffff7ff;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SOUL_CalcAccel(long delta /*$a0*/, long vel /*$a1*/, long magnitude /*$a2*/)
 // line 240, offset 0x8008c1b8
	/* begin block 1 */
		// Start line: 242
		// Start offset: 0x8008C1B8
		// Variables:
	// 		long rv; // $a2
	/* end block 1 */
	// End offset: 0x8008C1F0
	// End Line: 267

	/* begin block 2 */
		// Start line: 505
	/* end block 2 */
	// End Line: 506

	/* begin block 3 */
		// Start line: 510
	/* end block 3 */
	// End Line: 511

	/* begin block 4 */
		// Start line: 511
	/* end block 4 */
	// End Line: 512

	/* begin block 5 */
		// Start line: 517
	/* end block 5 */
	// End Line: 518

long SOUL_CalcAccel(long delta,long vel,long magnitude)

{
  int iVar1;
  
  if (delta < 1) {
    if (0 < vel) {
      iVar1 = delta << 4;
      goto LAB_8008c1e8;
    }
  }
  else {
    if (vel < 0) {
      iVar1 = delta << 4;
      goto LAB_8008c1e8;
    }
  }
  iVar1 = delta * 5;
LAB_8008c1e8:
  return iVar1 / magnitude;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuck(struct _Instance *instance /*$s2*/)
 // line 270, offset 0x8008c1f8
	/* begin block 1 */
		// Start line: 271
		// Start offset: 0x8008C1F8
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $s0
	// 		int mindist; // $fp
	// 		struct _Instance *sucker; // $s4
	// 		struct _Instance *collidedWith; // $s5

		/* begin block 1.1 */
			// Start line: 286
			// Start offset: 0x8008C298
			// Variables:
		// 		long distance; // $s1
		// 		struct evMonsterSoulSuckData *suckData; // $s0

			/* begin block 1.1.1 */
				// Start line: 313
				// Start offset: 0x8008C394
				// Variables:
			// 		struct _SVector dir; // stack offset -48

				/* begin block 1.1.1.1 */
					// Start line: 324
					// Start offset: 0x8008C3C8
					// Variables:
				// 		long animLen; // $s0
				// 		long curTim; // $v0

					/* begin block 1.1.1.1.1 */
						// Start line: 335
						// Start offset: 0x8008C460
						// Variables:
					// 		short _x0; // $a3
					// 		short _y0; // $a0
					// 		short _z0; // $v1
					// 		short _x1; // $v0
					// 		short _y1; // $a2
					// 		short _z1; // $a1
					// 		struct _SVector *_v; // $s6
					// 		struct _Position *_v0; // $v1
					// 		struct _Position *_v1; // $a1
					/* end block 1.1.1.1.1 */
					// End offset: 0x8008C460
					// End Line: 335
				/* end block 1.1.1.1 */
				// End offset: 0x8008C514
				// End Line: 345
			/* end block 1.1.1 */
			// End offset: 0x8008C514
			// End Line: 345
		/* end block 1.1 */
		// End offset: 0x8008C54C
		// End Line: 354

		/* begin block 1.2 */
			// Start line: 385
			// Start offset: 0x8008C654
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.2 */
		// End offset: 0x8008C674
		// End Line: 389
	/* end block 1 */
	// End offset: 0x8008C6D0
	// End Line: 402

	/* begin block 2 */
		// Start line: 570
	/* end block 2 */
	// End Line: 571

/* WARNING: Type propagation algorithm not settling */

void SOUL_SoulSuck(_Instance *instance)

{
  short sVar1;
  short sVar2;
  __Event *message;
  long magnitude;
  long lVar3;
  _MonsterAnim *p_Var4;
  int Data;
  int iVar5;
  _Instance *p_Var6;
  uint *puVar7;
  _Instance *Inst;
  _Instance *instance_00;
  undefined4 local_38;
  undefined4 in_stack_ffffffcc;
  undefined2 local_30;
  short local_2e;
  short local_2c;
  undefined2 in_stack_ffffffd6;
  
  Inst = (_Instance *)0x0;
  instance_00 = (_Instance *)0x0;
  puVar7 = (uint *)instance->extraData;
LAB_8008c244:
  while( true ) {
    message = DeMessageQueue((__MessageQueue *)(puVar7 + 2));
    if (message == (__Event *)0x0) {
      if ((*puVar7 & 0x800) == 0) {
        PhysicsMove(instance,&instance->position,gameTrackerX.idleTime);
      }
      else {
        SOUL_Physics(instance,gameTrackerX.idleTime);
      }
      if ((instance_00 == (_Instance *)0x0) || (instance_00 != Inst)) {
        if (Inst == (_Instance *)0x0) {
          if ((instance->flags2 & 0x20000000U) != 0) {
            instance->flags2 = instance->flags2 & 0xdfffffff;
          }
          MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffcc,local_38));
        }
      }
      else {
        Data = SetMonsterSoulSuckData(instance,0,0,0);
        INSTANCE_Post(Inst,0x1000009,Data);
        INSTANCE_Post(Inst,0x1000016,(int)*(short *)(puVar7 + 0x51));
        SOUND_Play3dSound(&instance->position,9,-0x1c2,0x50,0xdac);
        if (puVar7[0x36] != 0) {
          instance_00 = INSTANCE_Find(puVar7[0x36]);
          if (instance_00 != (_Instance *)0x0) {
            MON_SoulSucked(instance_00);
          }
          SAVE_DeleteInstance(instance);
        }
        MON_KillMonster(instance);
      }
      return;
    }
    Data = message->ID;
    if (Data != 0x1000009) break;
    p_Var6 = (_Instance *)message->Data;
    *(undefined2 *)(puVar7 + 0x48) = *(undefined2 *)((int)&p_Var6->node + 4);
    *(undefined2 *)((int)puVar7 + 0x122) = *(undefined2 *)((int)&p_Var6->node + 6);
    if ((*puVar7 & 0x800) == 0) {
      *(short *)(puVar7 + 0x49) = (instance->position).z;
    }
    else {
      *(undefined2 *)(puVar7 + 0x49) = *(undefined2 *)&p_Var6->next;
    }
    magnitude = MATH3D_DistanceBetweenPositions((_Position *)(puVar7 + 0x48),&instance->position);
    if (magnitude < 7000) {
      Inst = *(_Instance **)&p_Var6->node;
      MONSENSE_SetEnemy(instance,Inst);
      if ((*(char *)(*(int *)puVar7[0x59] + 0x2d) == -1) || (0x500 < magnitude)) {
        lVar3 = SOUL_CalcAccel((int)*(short *)(puVar7 + 0x48) - (int)(instance->position).x,
                               instance->xVel,magnitude);
        instance->xAccl = lVar3;
        lVar3 = SOUL_CalcAccel((int)*(short *)((int)puVar7 + 0x122) - (int)(instance->position).y,
                               instance->yVel,magnitude);
        instance->yAccl = lVar3;
        magnitude = SOUL_CalcAccel((int)*(short *)(puVar7 + 0x49) - (int)(instance->position).z,
                                   instance->zVel,magnitude);
        instance->zAccl = magnitude;
        instance->maxXVel = 600;
        instance->maxYVel = 600;
        instance->maxZVel = 0x11;
      }
      else {
        Data = MON_AnimPlaying(instance,(MonsterAnim)
                                        CONCAT214(in_stack_ffffffd6,
                                                  CONCAT212(local_2c,CONCAT210(local_2e,CONCAT28(
                                                  local_30,CONCAT44(in_stack_ffffffcc,local_38))))))
        ;
        if ((Data == 0) && (0x32 < magnitude)) {
          MON_PlayAnim(instance,(MonsterAnim)
                                CONCAT214(in_stack_ffffffd6,
                                          CONCAT212(local_2c,CONCAT210(local_2e,CONCAT28(local_30,
                                                  CONCAT44(in_stack_ffffffcc,local_38))))),0x2d);
          instance->flags2 = instance->flags2 | 0x20000000;
        }
        p_Var4 = MON_GetAnim(instance,*(char **)puVar7[0x59],0x2d);
        sVar1 = G2AnimKeylist_GetDuration(instance->object->animList[p_Var4->index[0]]);
        sVar2 = G2Anim_GetElapsedTime(&instance->anim);
        Data = ((int)sVar1 * 0x1e000) / 3000 - ((int)sVar2 * 0x1e000) / 3000;
        if (0 < Data) {
          iVar5 = (uint)*(ushort *)(puVar7 + 0x48) - (uint)(ushort)(instance->position).x;
          local_30 = (undefined2)iVar5;
          local_2e = *(short *)((int)puVar7 + 0x122) - (instance->position).y;
          local_2c = *(short *)(puVar7 + 0x49) - (instance->position).z;
          instance->xVel = (int)(short)((iVar5 * 0x10000 >> 4) / Data);
          instance->yVel = (int)(short)(((int)local_2e << 0xc) / Data);
          instance->zVel = (int)(short)(((int)local_2c << 0xc) / Data);
        }
        if ((*puVar7 & 0x4000000) == 0) {
          instance_00 = Inst;
        }
        instance->zAccl = 0;
        instance->yAccl = 0;
        instance->xAccl = 0;
        sVar1 = MON_FacingOffset(Inst,instance);
        (instance->rotation).z = (instance->rotation).z + sVar1;
        *puVar7 = *puVar7 & 0xfffff7ff;
      }
    }
    else {
      instance->zAccl = 0;
      instance->yAccl = 0;
      instance->xAccl = 0;
    }
  }
  if (0x1000009 < Data) goto LAB_8008c284;
  if ((Data == 0x1000008) &&
     ((p_Var4 = MON_GetAnim(instance,*(char **)puVar7[0x59],0x2d), p_Var4 == (_MonsterAnim *)0x0 ||
      ((*puVar7 & 0x4000000) == 0)))) {
    instance_00 = *(_Instance **)&((_Instance *)message->Data)->node;
  }
  goto LAB_8008c59c;
LAB_8008c284:
  if (Data != 0x100000b) {
LAB_8008c59c:
    MON_DefaultMessageHandler(instance,message);
  }
  goto LAB_8008c244;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_WanderEntry(struct _Instance *instance /*$a0*/)
 // line 407, offset 0x8008c700
	/* begin block 1 */
		// Start line: 408
		// Start offset: 0x8008C700
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	/* end block 1 */
	// End offset: 0x8008C760
	// End Line: 420

	/* begin block 2 */
		// Start line: 882
	/* end block 2 */
	// End Line: 883

void SOUL_WanderEntry(_Instance *instance)

{
  _Position *in;
  short r;
  uint *puVar1;
  
  puVar1 = (uint *)instance->extraData;
  instance->maxXVel = 10;
  instance->maxYVel = 10;
  instance->maxZVel = 0x11;
  if ((*puVar1 & 0x40000) == 0) {
    in = &instance->intro->position;
    if (instance->intro == (Intro *)0x0) {
      r = *(short *)((int)puVar1 + 0x136);
      in = &instance->position;
    }
    else {
      r = *(short *)((int)puVar1 + 0x136);
    }
    MON_GetRandomDestinationInWorld(instance,in,r);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Wander(struct _Instance *instance /*$s0*/)
 // line 422, offset 0x8008c770
	/* begin block 1 */
		// Start line: 423
		// Start offset: 0x8008C770
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 435
			// Start offset: 0x8008C7DC
		/* end block 1.1 */
		// End offset: 0x8008C88C
		// End Line: 448
	/* end block 1 */
	// End offset: 0x8008C8E4
	// End Line: 463

	/* begin block 2 */
		// Start line: 912
	/* end block 2 */
	// End Line: 913

void SOUL_Wander(_Instance *instance)

{
  long lVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x40000) == 0) {
    if (instance->intro == (Intro *)0x0) {
      MON_GetRandomDestinationInWorld(instance,&instance->position,*(short *)((int)puVar2 + 0x136));
      instance->zAccl = 0;
    }
    else {
      MON_GetRandomDestinationInWorld
                (instance,&instance->intro->position,*(short *)((int)puVar2 + 0x136));
      instance->zAccl = 0;
    }
  }
  else {
    lVar1 = MATH3D_LengthXY((int)*(short *)(puVar2 + 0x48) - (int)(instance->position).x,
                            (int)*(short *)((int)puVar2 + 0x122) - (int)(instance->position).y);
    if (lVar1 < 100) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
      instance->zAccl = 0;
    }
    else {
      instance->xAccl =
           ((int)*(short *)(puVar2 + 0x48) - (int)(instance->position).x) - instance->xVel;
      instance->yAccl =
           ((int)*(short *)((int)puVar2 + 0x122) - (int)(instance->position).y) - instance->yVel;
      lVar1 = -2;
      if ((instance->xAccl < -2) || (lVar1 = 2, 2 < instance->xAccl)) {
        instance->xAccl = lVar1;
      }
      lVar1 = -2;
      if ((instance->yAccl < -2) || (lVar1 = 2, 2 < instance->yAccl)) {
        instance->yAccl = lVar1;
      }
      instance->zAccl = 0;
    }
  }
  SOUL_Physics(instance,gameTrackerX.idleTime);
  if ((*puVar2 & 4) == 0) {
    if ((instance->flags2 & 0x8000000U) == 0) {
      SOUL_Fade(instance);
    }
    if (puVar2[0x31] != 0) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
  }
  SOUL_QueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_FleeEntry(struct _Instance *instance /*$a0*/)
 // line 469, offset 0x8008c900
	/* begin block 1 */
		// Start line: 1007
	/* end block 1 */
	// End Line: 1008

void SOUL_FleeEntry(_Instance *instance)

{
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  MON_FleeEntry(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Flee(struct _Instance *instance /*$s0*/)
 // line 476, offset 0x8008c930
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x8008C930
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 486
			// Start offset: 0x8008C96C
			// Variables:
		// 		struct _Instance *enemy; // $a0
		// 		int dx; // $s1
		// 		int dy; // $v0
		/* end block 1.1 */
		// End offset: 0x8008CA50
		// End Line: 501
	/* end block 1 */
	// End offset: 0x8008CA80
	// End Line: 507

	/* begin block 2 */
		// Start line: 1022
	/* end block 2 */
	// End Line: 1023

void SOUL_Flee(_Instance *instance)

{
  short angle;
  int iVar1;
  int iVar2;
  long lVar3;
  undefined4 unaff_s0;
  undefined4 unaff_s1;
  
  iVar1 = *(int *)((int)instance->extraData + 0xc4);
  if (iVar1 == 0) {
    MON_SwitchState(instance,(MonsterState)CONCAT44(unaff_s1,unaff_s0));
  }
  else {
    angle = MATH3D_AngleFromPosToPos((_Position *)(*(int *)(iVar1 + 4) + 0x5c),&instance->position);
    angle = MONSENSE_GetClosestFreeDirection(instance,angle,500);
    iVar1 = rsin((int)angle);
    iVar1 = iVar1 * 2000;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xfff;
    }
    iVar2 = rcos((int)angle);
    iVar2 = iVar2 * -2000;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0xfff;
    }
    instance->xAccl = (iVar1 >> 0xc) - instance->xVel;
    instance->yAccl = (iVar2 >> 0xc) - instance->yVel;
    lVar3 = -2;
    if ((instance->xAccl < -2) || (lVar3 = 2, 2 < instance->xAccl)) {
      instance->xAccl = lVar3;
    }
    lVar3 = -2;
    if ((instance->yAccl < -2) || (lVar3 = 2, 2 < instance->yAccl)) {
      instance->yAccl = lVar3;
    }
    instance->zAccl = 0;
  }
  SOUL_Physics(instance,gameTrackerX.idleTime);
  SOUL_QueueHandler(instance);
  if ((instance->flags2 & 0x8000000U) == 0) {
    SOUL_Fade(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 512, offset 0x8008ca94
	/* begin block 1 */
		// Start line: 513
		// Start offset: 0x8008CA94
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008CA94
	// End Line: 513

	/* begin block 2 */
		// Start line: 1097
	/* end block 2 */
	// End Line: 1098

void SOUL_IdleEntry(_Instance *instance)

{
  ulong uVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)instance->extraData;
  instance->maxXVel = 0xf;
  instance->maxYVel = 0xf;
  instance->maxZVel = 0x11;
  uVar1 = MON_GetTime(instance);
  iVar2 = rand();
  *puVar3 = *puVar3 & 0xfffbffff;
  puVar3[0x45] = uVar1 + iVar2 % 3000 + 3000;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Idle(struct _Instance *instance /*$s0*/)
 // line 520, offset 0x8008cb38
	/* begin block 1 */
		// Start line: 521
		// Start offset: 0x8008CB38
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long xAccl; // $a1
	// 		long yAccl; // $a0
	/* end block 1 */
	// End offset: 0x8008CC1C
	// End Line: 556

	/* begin block 2 */
		// Start line: 1114
	/* end block 2 */
	// End Line: 1115

void SOUL_Idle(_Instance *instance)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar5;
  
  iVar2 = instance->xVel;
  puVar5 = (uint *)instance->extraData;
  iVar4 = 3;
  if ((-4 < iVar2) && (iVar4 = -3, iVar2 < 4)) {
    iVar4 = -iVar2;
  }
  iVar3 = instance->yVel;
  iVar2 = 3;
  if ((-4 < iVar3) && (iVar2 = -3, iVar3 < 4)) {
    iVar2 = -iVar3;
  }
  instance->xAccl = iVar4;
  instance->yAccl = iVar2;
  instance->zAccl = 0;
  SOUL_Physics(instance,gameTrackerX.idleTime);
  if ((*puVar5 & 4) == 0) {
    if ((puVar5[0x31] != 0) || (uVar1 = MON_GetTime(instance), puVar5[0x45] < uVar1)) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
    }
    if ((instance->flags2 & 0x8000000U) == 0) {
      SOUL_Fade(instance);
    }
  }
  SOUL_QueueHandler(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_ReanimateEntry(struct _Instance *instance /*$s1*/)
 // line 562, offset 0x8008cc38
	/* begin block 1 */
		// Start line: 563
		// Start offset: 0x8008CC38
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _Instance *body; // $v0
	/* end block 1 */
	// End offset: 0x8008CC38
	// End Line: 563

	/* begin block 2 */
		// Start line: 1201
	/* end block 2 */
	// End Line: 1202

void SOUL_ReanimateEntry(_Instance *instance)

{
  _Instance *p_Var1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  p_Var1 = INSTANCE_Find(*(long *)((int)pvVar2 + 0xd8));
  *(short *)((int)pvVar2 + 0x120) = (p_Var1->position).x;
  *(short *)((int)pvVar2 + 0x122) = (p_Var1->position).y;
  *(short *)((int)pvVar2 + 0x124) = (p_Var1->position).z + 0xa0;
  MON_TurnOffBodySpheres(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Reanimate(struct _Instance *instance /*$s1*/)
 // line 579, offset 0x8008cca0
	/* begin block 1 */
		// Start line: 580
		// Start offset: 0x8008CCA0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 592
			// Start offset: 0x8008CCFC
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.1 */
		// End offset: 0x8008CD24
		// End Line: 596
	/* end block 1 */
	// End offset: 0x8008CD44
	// End Line: 604

	/* begin block 2 */
		// Start line: 1237
	/* end block 2 */
	// End Line: 1238

void SOUL_Reanimate(_Instance *instance)

{
  long lVar1;
  _Instance *Inst;
  __Event *p_Var2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  SOUL_MoveToDest(instance,0x10,gameTrackerX.idleTime);
  lVar1 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)((int)pvVar3 + 0x120),
                          (int)(instance->position).y - (int)*(short *)((int)pvVar3 + 0x122));
  if (lVar1 < 0xfa) {
    if (*(int *)((int)pvVar3 + 0xd8) != 0) {
      Inst = INSTANCE_Find(*(int *)((int)pvVar3 + 0xd8));
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Post(Inst,0x100000d,0);
      }
      SAVE_DeleteInstance(instance);
    }
    MON_KillMonster(instance);
  }
  else {
    do {
      p_Var2 = DeMessageQueue((__MessageQueue *)((int)pvVar3 + 8));
    } while (p_Var2 != (__Event *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Effect(struct _Instance *instance /*$a0*/, struct evFXHitData *data /*$a1*/)
 // line 609, offset 0x8008cd58
	/* begin block 1 */
		// Start line: 1301
	/* end block 1 */
	// End Line: 1302

	/* begin block 2 */
		// Start line: 1303
	/* end block 2 */
	// End Line: 1304

void SOUL_Effect(_Instance *instance,evFXHitData *data)

{
  return;
}





