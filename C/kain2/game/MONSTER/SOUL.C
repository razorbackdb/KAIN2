#include "THISDUST.H"
#include "SOUL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_QueueHandler(struct _Instance *instance /*$s0*/)
 // line 80, offset 0x8008d890
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x8008D890
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x8008D910
	// End Line: 95

	/* begin block 2 */
		// Start line: 160
	/* end block 2 */
	// End Line: 161

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
 // line 100, offset 0x8008d92c
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x8008D92C
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int a; // $a1
	/* end block 1 */
	// End offset: 0x8008D958
	// End Line: 114

	/* begin block 2 */
		// Start line: 208
	/* end block 2 */
	// End Line: 209

void SOUL_Physics(_Instance *instance,long time)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = instance->extraData;
  iVar2 = -4;
  if ((*(ushort *)((int)pvVar1 + 0x12a) & 0x1f) < 0x10) {
    iVar2 = 4;
  }
  instance->zAccl = instance->zAccl + iVar2;
  *(short *)((int)pvVar1 + 0x12a) = *(short *)((int)pvVar1 + 0x12a) + 1;
  PhysicsMove(instance,&instance->position,time);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Fade(struct _Instance *instance /*$s0*/)
 // line 120, offset 0x8008d98c
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x8008D98C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		unsigned long time; // $a0
	/* end block 1 */
	// End offset: 0x8008DA2C
	// End Line: 145

	/* begin block 2 */
		// Start line: 251
	/* end block 2 */
	// End Line: 252

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
        MORPH_SetupInstanceFlags(instance);
        instance->fadeValue = 0;
      }
    }
  }
  else {
    *(undefined **)((int)pvVar3 + 0x10c) = &DAT_00001964 + uVar2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_MoveToDest(struct _Instance *instance /*$a3*/, long maxAccel /*$t0*/, long time /*$a2*/)
 // line 147, offset 0x8008da40
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8008DA40
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x8008DB14
	// End Line: 158

	/* begin block 2 */
		// Start line: 305
	/* end block 2 */
	// End Line: 306

void SOUL_MoveToDest(_Instance *instance,long maxAccel,long time)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  instance->xAccl =
       ((int)*(short *)((int)pvVar1 + 0x124) - (int)(instance->position).x) - instance->xVel;
  instance->yAccl =
       ((int)*(short *)((int)pvVar1 + 0x126) - (int)(instance->position).y) - instance->yVel;
  instance->zAccl =
       ((int)*(short *)((int)pvVar1 + 0x128) - (int)(instance->position).z) - instance->zVel;
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
// void /*$ra*/ SOUL_MovePastWall(struct _Instance *instance /*$s2*/, struct _Instance *sucker /*$a1*/)
 // line 162, offset 0x8008db30
	/* begin block 1 */
		// Start line: 163
		// Start offset: 0x8008DB30
		// Variables:
	// 		struct _PCollideInfo pcollideInfo; // stack offset -88
	// 		struct _Position newPos; // stack offset -40
	// 		struct _Position oldPos; // stack offset -32
	// 		struct _Position delta; // stack offset -24
	// 		struct MATRIX *to; // $a2
	// 		struct MATRIX *from; // $v1

		/* begin block 1.1 */
			// Start line: 163
			// Start offset: 0x8008DB30
			// Variables:
		// 		short _x0; // $v0
		// 		short _y0; // $v1
		// 		short _z0; // $a2
		// 		short _x1; // $a3
		// 		short _y1; // $t1
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $s1
		// 		struct _Position *_v1; // $t0
		/* end block 1.1 */
		// End offset: 0x8008DB30
		// End Line: 163
	/* end block 1 */
	// End offset: 0x8008DB30
	// End Line: 163

	/* begin block 2 */
		// Start line: 336
	/* end block 2 */
	// End Line: 337

/* WARNING: Could not reconcile some variable overlaps */

void SOUL_MovePastWall(_Instance *instance,_Instance *sucker)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;
  _PCollideInfo _Stack88;
  undefined4 local_28;
  short local_24;
  SVECTOR local_20;
  SVECTOR local_18;
  
  pMVar1 = sucker->matrix;
  pMVar2 = instance->matrix;
  local_20.vx = *(short *)pMVar1->t;
  local_20.vy = *(short *)(pMVar1->t + 1);
  local_20.vz = *(short *)(pMVar1->t + 2);
  _Stack88.newPoint = (SVECTOR *)&local_28;
  local_28 = CONCAT22(*(undefined2 *)(pMVar2->t + 1),*(undefined2 *)pMVar2->t);
  local_24 = *(short *)(pMVar2->t + 2);
  _Stack88.oldPoint = &local_20;
  PHYSICS_CheckLineInWorld(instance,&_Stack88);
  local_18.vx = (short)local_28 - (instance->position).x;
  local_18.vy = local_28._2_2_ - (instance->position).y;
  local_18.vz = local_24 - (instance->position).z;
  COLLIDE_UpdateAllTransforms(instance,&local_18);
  COLLIDE_MoveAllTransforms(instance,(_Position *)&local_18);
  *(undefined4 *)&instance->position = local_28;
  (instance->position).z = local_24;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Init(struct _Instance *instance /*$s0*/)
 // line 193, offset 0x8008dc24
	/* begin block 1 */
		// Start line: 194
		// Start offset: 0x8008DC24
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008DCD4
	// End Line: 217

	/* begin block 2 */
		// Start line: 417
	/* end block 2 */
	// End Line: 418

void SOUL_Init(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  MON_DefaultInit(instance);
  *puVar2 = *puVar2 | 0x200880;
  instance->maxXVel = 600;
  instance->maxYVel = 600;
  instance->maxZVel = 600;
  instance->flags2 = instance->flags2 | 0x20000;
  *(undefined2 *)((int)puVar2 + 0x12a) = 0;
  uVar1 = MON_GetTime(instance);
  *(undefined **)(puVar2 + 0x43) = &DAT_00001964 + uVar1;
  if (instance->parent != (_Instance *)0x0) {
    puVar2[0x36] = instance->parent->introUniqueID;
  }
  if ((instance->flags & 2U) == 0) {
    instance->flags2 = instance->flags2 | 0x8000000;
    MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_CleanUp(struct _Instance *instance /*$a0*/)
 // line 223, offset 0x8008dce8
	/* begin block 1 */
		// Start line: 488
	/* end block 1 */
	// End Line: 489

void SOUL_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 233, offset 0x8008dd08
	/* begin block 1 */
		// Start line: 234
		// Start offset: 0x8008DD08
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008DD08
	// End Line: 234

	/* begin block 2 */
		// Start line: 508
	/* end block 2 */
	// End Line: 509

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
 // line 244, offset 0x8008dd5c
	/* begin block 1 */
		// Start line: 245
		// Start offset: 0x8008DD5C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008DDA8
	// End Line: 256

	/* begin block 2 */
		// Start line: 534
	/* end block 2 */
	// End Line: 535

void SOUL_Birth(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  void *pvVar2;
  undefined4 local_c;
  
  instance->zAccl = 0;
  pvVar2 = instance->extraData;
  SOUL_Physics(instance,gameTrackerX.timeMult);
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
 // line 262, offset 0x8008ddc4
	/* begin block 1 */
		// Start line: 573
	/* end block 1 */
	// End Line: 574

	/* begin block 2 */
		// Start line: 576
	/* end block 2 */
	// End Line: 577

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
 // line 270, offset 0x8008ddec
	/* begin block 1 */
		// Start line: 272
		// Start offset: 0x8008DDEC
		// Variables:
	// 		long rv; // $a2
	/* end block 1 */
	// End offset: 0x8008DE24
	// End Line: 297

	/* begin block 2 */
		// Start line: 586
	/* end block 2 */
	// End Line: 587

	/* begin block 3 */
		// Start line: 591
	/* end block 3 */
	// End Line: 592

	/* begin block 4 */
		// Start line: 592
	/* end block 4 */
	// End Line: 593

	/* begin block 5 */
		// Start line: 598
	/* end block 5 */
	// End Line: 599

long SOUL_CalcAccel(long delta,long vel,long magnitude)

{
  int iVar1;
  
  if (delta < 1) {
    if (0 < vel) {
      iVar1 = delta << 4;
      goto LAB_8008de1c;
    }
  }
  else {
    if (vel < 0) {
      iVar1 = delta << 4;
      goto LAB_8008de1c;
    }
  }
  iVar1 = delta * 5;
LAB_8008de1c:
  return iVar1 / magnitude;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuck(struct _Instance *instance /*$s2*/)
 // line 300, offset 0x8008de2c
	/* begin block 1 */
		// Start line: 301
		// Start offset: 0x8008DE2C
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $s0
	// 		struct _Instance *sucker; // $s4
	// 		struct _Instance *collidedWith; // $s6
	// 		int collisionCnt; // $s5

		/* begin block 1.1 */
			// Start line: 317
			// Start offset: 0x8008DED8
			// Variables:
		// 		long distance; // $s1
		// 		struct evMonsterSoulSuckData *suckData; // $s0

			/* begin block 1.1.1 */
				// Start line: 344
				// Start offset: 0x8008DFFC
				// Variables:
			// 		struct _SVector dir; // stack offset -48

				/* begin block 1.1.1.1 */
					// Start line: 355
					// Start offset: 0x8008E030
					// Variables:
				// 		long animLen; // $s0
				// 		long curTim; // $v0

					/* begin block 1.1.1.1.1 */
						// Start line: 366
						// Start offset: 0x8008E0C8
						// Variables:
					// 		short _x0; // $a3
					// 		short _y0; // $a0
					// 		short _z0; // $v1
					// 		short _x1; // $v0
					// 		short _y1; // $a2
					// 		short _z1; // $a1
					// 		struct _SVector *_v; // $s7
					// 		struct _Position *_v0; // $v1
					// 		struct _Position *_v1; // $a1
					/* end block 1.1.1.1.1 */
					// End offset: 0x8008E0C8
					// End Line: 366
				/* end block 1.1.1.1 */
				// End offset: 0x8008E17C
				// End Line: 376
			/* end block 1.1.1 */
			// End offset: 0x8008E17C
			// End Line: 376
		/* end block 1.1 */
		// End offset: 0x8008E1B4
		// End Line: 385

		/* begin block 1.2 */
			// Start line: 439
			// Start offset: 0x8008E328
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.2 */
		// End offset: 0x8008E348
		// End Line: 443
	/* end block 1 */
	// End offset: 0x8008E3A4
	// End Line: 456

	/* begin block 2 */
		// Start line: 651
	/* end block 2 */
	// End Line: 652

/* WARNING: Type propagation algorithm not settling */

void SOUL_SoulSuck(_Instance *instance)

{
  short sVar1;
  short sVar2;
  __Event *message;
  long magnitude;
  long lVar3;
  _MonsterAnim *p_Var4;
  int iVar5;
  int iVar6;
  _Instance *p_Var7;
  uint *puVar8;
  _Instance *sucker;
  int Data;
  _Instance *instance_00;
  undefined4 local_38;
  undefined4 in_stack_ffffffcc;
  undefined2 local_30;
  short local_2e;
  short local_2c;
  undefined2 in_stack_ffffffd6;
  
  sucker = (_Instance *)0x0;
  instance_00 = (_Instance *)0x0;
  Data = 0;
  puVar8 = (uint *)instance->extraData;
  do {
    while( true ) {
      message = DeMessageQueue((__MessageQueue *)(puVar8 + 2));
      if (message == (__Event *)0x0) {
        if ((Data == 0) || (sucker == (_Instance *)0x0)) {
          puVar8[0x46] = 0;
        }
        else {
          puVar8[0x46] = puVar8[0x46] + 1;
        }
        if (10 < puVar8[0x46]) {
          puVar8[0x46] = 0;
          SOUL_MovePastWall(instance,sucker);
        }
        if ((*puVar8 & 0x800) == 0) {
          PhysicsMove(instance,&instance->position,gameTrackerX.timeMult);
        }
        else {
          SOUL_Physics(instance,gameTrackerX.timeMult);
        }
        if ((instance_00 == (_Instance *)0x0) || (instance_00 != sucker)) {
          if (sucker == (_Instance *)0x0) {
            if ((instance->flags2 & 0x20000000U) != 0) {
              instance->flags2 = instance->flags2 & 0xdfffffff;
            }
            MON_SwitchState(instance,(MonsterState)CONCAT44(in_stack_ffffffcc,local_38));
          }
        }
        else {
          Data = SetMonsterSoulSuckData(instance,0,0,0);
          INSTANCE_Post(sucker,0x1000009,Data);
          INSTANCE_Post(sucker,0x1000016,(int)*(short *)(puVar8 + 0x52));
          SOUND_Play3dSound(&instance->position,8,-0x1c2,0x50,0xdac);
          if (sucker == gameTrackerX.playerInstance) {
            GAMEPAD_Shock1(0x80,(int)&DAT_00005000);
          }
          if (puVar8[0x36] != 0) {
            instance_00 = INSTANCE_Find(puVar8[0x36]);
            if (instance_00 != (_Instance *)0x0) {
              MON_SoulSucked(instance_00);
            }
            SAVE_DeleteInstance(instance);
          }
          MON_KillMonster(instance);
        }
        return;
      }
      iVar5 = message->ID;
      if (iVar5 != 0x1000008) break;
      Data = Data + 1;
      p_Var4 = MON_GetAnim(instance,*(char **)puVar8[0x5a],0x2d);
      if ((p_Var4 == (_MonsterAnim *)0x0) || ((*puVar8 & 0x4000000) == 0)) {
        instance_00 = *(_Instance **)&((_Instance *)message->Data)->node;
      }
LAB_8008e210:
      MON_DefaultMessageHandler(instance,message);
    }
    if (iVar5 < 0x1000009) {
      if (iVar5 != 0x1000007) goto LAB_8008e210;
      Data = Data + 1;
    }
    else {
      if (iVar5 == 0x1000009) {
        p_Var7 = (_Instance *)message->Data;
        *(undefined2 *)(puVar8 + 0x49) = *(undefined2 *)((int)&p_Var7->node + 4);
        *(undefined2 *)((int)puVar8 + 0x126) = *(undefined2 *)((int)&p_Var7->node + 6);
        if ((*puVar8 & 0x800) == 0) {
          *(short *)(puVar8 + 0x4a) = (instance->position).z;
        }
        else {
          *(undefined2 *)(puVar8 + 0x4a) = *(undefined2 *)&p_Var7->next;
        }
        magnitude = MATH3D_DistanceBetweenPositions
                              ((_Position *)(puVar8 + 0x49),&instance->position);
        if (magnitude < 7000) {
          sucker = *(_Instance **)&p_Var7->node;
          MONSENSE_SetEnemy(instance,sucker);
          if ((*(char *)(*(int *)puVar8[0x5a] + 0x2d) == -1) || (0x500 < magnitude)) {
            lVar3 = SOUL_CalcAccel((int)*(short *)(puVar8 + 0x49) - (int)(instance->position).x,
                                   instance->xVel,magnitude);
            instance->xAccl = lVar3;
            lVar3 = SOUL_CalcAccel((int)*(short *)((int)puVar8 + 0x126) -
                                   (int)(instance->position).y,instance->yVel,magnitude);
            instance->yAccl = lVar3;
            magnitude = SOUL_CalcAccel((int)*(short *)(puVar8 + 0x4a) - (int)(instance->position).z,
                                       instance->zVel,magnitude);
            instance->zAccl = magnitude;
            instance->maxXVel = 600;
            instance->maxYVel = 600;
            instance->maxZVel = 0x11;
          }
          else {
            iVar5 = (int)(instance->position).z - (int)*(short *)(puVar8 + 0x4a);
            if (iVar5 < 0) {
              iVar5 = -iVar5;
            }
            if (iVar5 < 200) {
              iVar5 = MON_AnimPlaying(instance,(MonsterAnim)
                                               CONCAT214(in_stack_ffffffd6,
                                                         CONCAT212(local_2c,CONCAT210(local_2e,
                                                  CONCAT28(local_30,CONCAT44(in_stack_ffffffcc,
                                                                             local_38))))));
              if ((iVar5 == 0) && (0x32 < magnitude)) {
                MON_PlayAnim(instance,(MonsterAnim)
                                      CONCAT214(in_stack_ffffffd6,
                                                CONCAT212(local_2c,CONCAT210(local_2e,CONCAT28(
                                                  local_30,CONCAT44(in_stack_ffffffcc,local_38))))),
                             0x2d);
                instance->flags2 = instance->flags2 | 0x20000000;
              }
              p_Var4 = MON_GetAnim(instance,*(char **)puVar8[0x5a],0x2d);
              sVar1 = G2AnimKeylist_GetDuration(instance->object->animList[p_Var4->index[0]]);
              sVar2 = G2Anim_GetElapsedTime(&instance->anim);
              iVar5 = ((int)sVar1 * 0x1e000) / 3000 - ((int)sVar2 * 0x1e000) / 3000;
              if (0 < iVar5) {
                iVar6 = (uint)*(ushort *)(puVar8 + 0x49) - (uint)(ushort)(instance->position).x;
                local_30 = (undefined2)iVar6;
                local_2e = *(short *)((int)puVar8 + 0x126) - (instance->position).y;
                local_2c = *(short *)(puVar8 + 0x4a) - (instance->position).z;
                instance->xVel = (int)(short)((iVar6 * 0x10000 >> 4) / iVar5);
                instance->yVel = (int)(short)(((int)local_2e << 0xc) / iVar5);
                instance->zVel = (int)(short)(((int)local_2c << 0xc) / iVar5);
              }
              if ((*puVar8 & 0x4000000) == 0) {
                instance_00 = sucker;
              }
              instance->zAccl = 0;
              instance->yAccl = 0;
              instance->xAccl = 0;
              sVar1 = MON_FacingOffset(sucker,instance);
              (instance->rotation).z = (instance->rotation).z + sVar1;
              *puVar8 = *puVar8 & 0xfffff7ff;
            }
          }
        }
        else {
          instance->zAccl = 0;
          instance->yAccl = 0;
          instance->xAccl = 0;
        }
      }
      else {
        if (iVar5 != 0x100000b) goto LAB_8008e210;
      }
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_WanderEntry(struct _Instance *instance /*$a0*/)
 // line 461, offset 0x8008e3d4
	/* begin block 1 */
		// Start line: 462
		// Start offset: 0x8008E3D4
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	/* end block 1 */
	// End offset: 0x8008E434
	// End Line: 474

	/* begin block 2 */
		// Start line: 1016
	/* end block 2 */
	// End Line: 1017

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
      r = *(short *)((int)puVar1 + 0x13a);
      in = &instance->position;
    }
    else {
      r = *(short *)((int)puVar1 + 0x13a);
    }
    MON_GetRandomDestinationInWorld(instance,in,r);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Wander(struct _Instance *instance /*$s0*/)
 // line 476, offset 0x8008e444
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x8008E444
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 489
			// Start offset: 0x8008E4B0
		/* end block 1.1 */
		// End offset: 0x8008E560
		// End Line: 502
	/* end block 1 */
	// End offset: 0x8008E5B8
	// End Line: 517

	/* begin block 2 */
		// Start line: 1046
	/* end block 2 */
	// End Line: 1047

void SOUL_Wander(_Instance *instance)

{
  long lVar1;
  undefined4 local_10;
  undefined4 local_c;
  uint *puVar2;
  
  puVar2 = (uint *)instance->extraData;
  if ((*puVar2 & 0x40000) == 0) {
    if (instance->intro == (Intro *)0x0) {
      MON_GetRandomDestinationInWorld(instance,&instance->position,*(short *)((int)puVar2 + 0x13a));
      instance->zAccl = 0;
    }
    else {
      MON_GetRandomDestinationInWorld
                (instance,&instance->intro->position,*(short *)((int)puVar2 + 0x13a));
      instance->zAccl = 0;
    }
  }
  else {
    lVar1 = MATH3D_LengthXY((int)*(short *)(puVar2 + 0x49) - (int)(instance->position).x,
                            (int)*(short *)((int)puVar2 + 0x126) - (int)(instance->position).y);
    if (lVar1 < 100) {
      MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
      instance->zAccl = 0;
    }
    else {
      instance->xAccl =
           ((int)*(short *)(puVar2 + 0x49) - (int)(instance->position).x) - instance->xVel;
      instance->yAccl =
           ((int)*(short *)((int)puVar2 + 0x126) - (int)(instance->position).y) - instance->yVel;
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
  SOUL_Physics(instance,gameTrackerX.timeMult);
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
 // line 523, offset 0x8008e5d4
	/* begin block 1 */
		// Start line: 1141
	/* end block 1 */
	// End Line: 1142

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
 // line 530, offset 0x8008e604
	/* begin block 1 */
		// Start line: 531
		// Start offset: 0x8008E604
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 540
			// Start offset: 0x8008E640
			// Variables:
		// 		struct _Instance *enemy; // $a0
		// 		int dx; // $s1
		// 		int dy; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E724
		// End Line: 555
	/* end block 1 */
	// End offset: 0x8008E754
	// End Line: 561

	/* begin block 2 */
		// Start line: 1156
	/* end block 2 */
	// End Line: 1157

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
  SOUL_Physics(instance,gameTrackerX.timeMult);
  SOUL_QueueHandler(instance);
  if ((instance->flags2 & 0x8000000U) == 0) {
    SOUL_Fade(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 566, offset 0x8008e768
	/* begin block 1 */
		// Start line: 567
		// Start offset: 0x8008E768
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008E768
	// End Line: 567

	/* begin block 2 */
		// Start line: 1231
	/* end block 2 */
	// End Line: 1232

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
 // line 574, offset 0x8008e80c
	/* begin block 1 */
		// Start line: 575
		// Start offset: 0x8008E80C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long xAccl; // $a1
	// 		long yAccl; // $a0
	/* end block 1 */
	// End offset: 0x8008E8F0
	// End Line: 610

	/* begin block 2 */
		// Start line: 1248
	/* end block 2 */
	// End Line: 1249

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
  SOUL_Physics(instance,gameTrackerX.timeMult);
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
 // line 616, offset 0x8008e90c
	/* begin block 1 */
		// Start line: 617
		// Start offset: 0x8008E90C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _Instance *body; // $v0
	/* end block 1 */
	// End offset: 0x8008E90C
	// End Line: 617

	/* begin block 2 */
		// Start line: 1335
	/* end block 2 */
	// End Line: 1336

void SOUL_ReanimateEntry(_Instance *instance)

{
  _Instance *p_Var1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  p_Var1 = INSTANCE_Find(*(long *)((int)pvVar2 + 0xd8));
  *(short *)((int)pvVar2 + 0x124) = (p_Var1->position).x;
  *(short *)((int)pvVar2 + 0x126) = (p_Var1->position).y;
  *(short *)((int)pvVar2 + 0x128) = (p_Var1->position).z + 0xa0;
  MON_TurnOffBodySpheres(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_Reanimate(struct _Instance *instance /*$s1*/)
 // line 633, offset 0x8008e974
	/* begin block 1 */
		// Start line: 634
		// Start offset: 0x8008E974
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 646
			// Start offset: 0x8008E9D0
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E9F8
		// End Line: 650
	/* end block 1 */
	// End offset: 0x8008EA18
	// End Line: 658

	/* begin block 2 */
		// Start line: 1371
	/* end block 2 */
	// End Line: 1372

void SOUL_Reanimate(_Instance *instance)

{
  long lVar1;
  _Instance *Inst;
  __Event *p_Var2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  SOUL_MoveToDest(instance,0x10,gameTrackerX.timeMult);
  lVar1 = MATH3D_LengthXY((int)(instance->position).x - (int)*(short *)((int)pvVar3 + 0x124),
                          (int)(instance->position).y - (int)*(short *)((int)pvVar3 + 0x126));
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
 // line 663, offset 0x8008ea2c
	/* begin block 1 */
		// Start line: 1435
	/* end block 1 */
	// End Line: 1436

	/* begin block 2 */
		// Start line: 1437
	/* end block 2 */
	// End Line: 1438

void SOUL_Effect(_Instance *instance,evFXHitData *data)

{
  return;
}





