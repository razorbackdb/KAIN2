
#include "SOUL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_QueueHandler(struct _Instance *instance /*$s0*/)
 // line 80, offset 0x8008d504
	/* begin block 1 */
		// Start line: 81
		// Start offset: 0x8008D504
		// Variables:
	// 		struct _MonsterVars *mv; // $s2
	// 		struct __Event *message; // $a1
	/* end block 1 */
	// End offset: 0x8008D584
	// End Line: 95

	/* begin block 2 */
		// Start line: 160
	/* end block 2 */
	// End Line: 161

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 100, offset 0x8008d5a0
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x8008D5A0
		// Variables:
	// 		struct _MonsterVars *mv; // $v1
	// 		int a; // $a1
	/* end block 1 */
	// End offset: 0x8008D5CC
	// End Line: 114

	/* begin block 2 */
		// Start line: 208
	/* end block 2 */
	// End Line: 209

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 120, offset 0x8008d600
	/* begin block 1 */
		// Start line: 121
		// Start offset: 0x8008D600
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		unsigned long time; // $a0
	/* end block 1 */
	// End offset: 0x8008D6A8
	// End Line: 145

	/* begin block 2 */
		// Start line: 251
	/* end block 2 */
	// End Line: 252

/* File: C:\kain2\game\MONSTER\SOUL.C */

void SOUL_Fade(_Instance *instance)

{
  short sVar1;
  ulong uVar2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  uVar2 = MON_GetTime(instance);
  if ((DAT_800d220c & 0x80) == 0) {
    if (*(uint *)((int)pvVar3 + 0x10c) < uVar2) {
      sVar1 = instance->fadeValue;
      if (sVar1 == 0) {
        MON_StartSpecialFade(instance,0x1000,100);
        sVar1 = instance->fadeValue;
      }
      if (0xfff < sVar1) {
        instance->flags2 = instance->flags2 | 0x8000000;
        MORPH_SetupInstanceFlags((GameTracker *)&gameTrackerX,instance);
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
 // line 147, offset 0x8008d6bc
	/* begin block 1 */
		// Start line: 148
		// Start offset: 0x8008D6BC
		// Variables:
	// 		struct _MonsterVars *mv; // $a1
	/* end block 1 */
	// End offset: 0x8008D790
	// End Line: 158

	/* begin block 2 */
		// Start line: 306
	/* end block 2 */
	// End Line: 307

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
// void /*$ra*/ SOUL_Init(struct _Instance *instance /*$s0*/)
 // line 164, offset 0x8008d7ac
	/* begin block 1 */
		// Start line: 165
		// Start offset: 0x8008D7AC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008D868
	// End Line: 189

	/* begin block 2 */
		// Start line: 341
	/* end block 2 */
	// End Line: 342

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
  *(undefined2 *)((int)puVar2 + 0x126) = 0;
  uVar1 = MON_GetTime(instance);
  *(undefined **)(puVar2 + 0x43) = &DAT_00001964 + uVar1;
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
 // line 195, offset 0x8008d87c
	/* begin block 1 */
		// Start line: 414
	/* end block 1 */
	// End Line: 415

/* File: C:\kain2\game\MONSTER\SOUL.C */

void SOUL_CleanUp(_Instance *instance)

{
  MON_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_BirthEntry(struct _Instance *instance /*$a0*/)
 // line 205, offset 0x8008d89c
	/* begin block 1 */
		// Start line: 206
		// Start offset: 0x8008D89C
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D89C
	// End Line: 206

	/* begin block 2 */
		// Start line: 434
	/* end block 2 */
	// End Line: 435

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 216, offset 0x8008d8f0
	/* begin block 1 */
		// Start line: 217
		// Start offset: 0x8008D8F0
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D93C
	// End Line: 228

	/* begin block 2 */
		// Start line: 460
	/* end block 2 */
	// End Line: 461

/* File: C:\kain2\game\MONSTER\SOUL.C */

void SOUL_Birth(_Instance *instance)

{
  ulong uVar1;
  undefined4 local_10;
  void *pvVar2;
  undefined4 local_c;
  
  instance->zAccl = 0;
  pvVar2 = instance->extraData;
  SOUL_Physics(instance,DAT_800d2314);
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
 // line 234, offset 0x8008d958
	/* begin block 1 */
		// Start line: 499
	/* end block 1 */
	// End Line: 500

	/* begin block 2 */
		// Start line: 502
	/* end block 2 */
	// End Line: 503

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 242, offset 0x8008d980
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8008D980
		// Variables:
	// 		long rv; // $a2
	/* end block 1 */
	// End offset: 0x8008D9B8
	// End Line: 269

	/* begin block 2 */
		// Start line: 512
	/* end block 2 */
	// End Line: 513

	/* begin block 3 */
		// Start line: 517
	/* end block 3 */
	// End Line: 518

	/* begin block 4 */
		// Start line: 518
	/* end block 4 */
	// End Line: 519

	/* begin block 5 */
		// Start line: 524
	/* end block 5 */
	// End Line: 525

/* File: C:\kain2\game\MONSTER\SOUL.C */

long SOUL_CalcAccel(long delta,long vel,long magnitude)

{
  int iVar1;
  
  if (delta < 1) {
    if (0 < vel) {
      iVar1 = delta << 4;
      goto LAB_8008d9b0;
    }
  }
  else {
    if (vel < 0) {
      iVar1 = delta << 4;
      goto LAB_8008d9b0;
    }
  }
  iVar1 = delta * 5;
LAB_8008d9b0:
  return iVar1 / magnitude;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_SoulSuck(struct _Instance *instance /*$s2*/)
 // line 272, offset 0x8008d9c0
	/* begin block 1 */
		// Start line: 273
		// Start offset: 0x8008D9C0
		// Variables:
	// 		struct _MonsterVars *mv; // $s3
	// 		struct __Event *message; // $s0
	// 		int mindist; // $fp
	// 		struct _Instance *sucker; // $s4
	// 		struct _Instance *collidedWith; // $s5

		/* begin block 1.1 */
			// Start line: 288
			// Start offset: 0x8008DA60
			// Variables:
		// 		long distance; // $s1
		// 		struct evMonsterSoulSuckData *suckData; // $s0

			/* begin block 1.1.1 */
				// Start line: 315
				// Start offset: 0x8008DB84
				// Variables:
			// 		struct _SVector dir; // stack offset -48

				/* begin block 1.1.1.1 */
					// Start line: 326
					// Start offset: 0x8008DBB8
					// Variables:
				// 		long animLen; // $s0
				// 		long curTim; // $v0

					/* begin block 1.1.1.1.1 */
						// Start line: 337
						// Start offset: 0x8008DC50
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
					// End offset: 0x8008DC50
					// End Line: 337
				/* end block 1.1.1.1 */
				// End offset: 0x8008DD04
				// End Line: 347
			/* end block 1.1.1 */
			// End offset: 0x8008DD04
			// End Line: 347
		/* end block 1.1 */
		// End offset: 0x8008DD3C
		// End Line: 356

		/* begin block 1.2 */
			// Start line: 389
			// Start offset: 0x8008DE5C
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.2 */
		// End offset: 0x8008DE7C
		// End Line: 393
	/* end block 1 */
	// End offset: 0x8008DED8
	// End Line: 406

	/* begin block 2 */
		// Start line: 577
	/* end block 2 */
	// End Line: 578

/* WARNING: Type propagation algorithm not settling */
/* File: C:\kain2\game\MONSTER\SOUL.C */

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
LAB_8008da0c:
  while( true ) {
    message = DeMessageQueue((__MessageQueue *)(puVar7 + 2));
    if (message == (__Event *)0x0) {
      if ((*puVar7 & 0x800) == 0) {
        PhysicsMove(instance,&instance->position,DAT_800d2314);
      }
      else {
        SOUL_Physics(instance,DAT_800d2314);
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
        SOUND_Play3dSound(&instance->position,8,-0x1c2,0x50,0xdac);
        if (Inst == DAT_800d20f8) {
          GAMEPAD_Shock1(0x80,(int)&DAT_00005000);
        }
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
        Data = (int)(instance->position).z - (int)*(short *)(puVar7 + 0x49);
        if (Data < 0) {
          Data = -Data;
        }
        if (Data < 200) {
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
    }
    else {
      instance->zAccl = 0;
      instance->yAccl = 0;
      instance->xAccl = 0;
    }
  }
  if (0x1000009 < Data) goto LAB_8008da4c;
  if ((Data == 0x1000008) &&
     ((p_Var4 = MON_GetAnim(instance,*(char **)puVar7[0x59],0x2d), p_Var4 == (_MonsterAnim *)0x0 ||
      ((*puVar7 & 0x4000000) == 0)))) {
    instance_00 = *(_Instance **)&((_Instance *)message->Data)->node;
  }
  goto LAB_8008dd8c;
LAB_8008da4c:
  if (Data != 0x100000b) {
LAB_8008dd8c:
    MON_DefaultMessageHandler(instance,message);
  }
  goto LAB_8008da0c;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_WanderEntry(struct _Instance *instance /*$a0*/)
 // line 411, offset 0x8008df08
	/* begin block 1 */
		// Start line: 412
		// Start offset: 0x8008DF08
		// Variables:
	// 		struct _MonsterVars *mv; // $a2
	/* end block 1 */
	// End offset: 0x8008DF68
	// End Line: 424

	/* begin block 2 */
		// Start line: 893
	/* end block 2 */
	// End Line: 894

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 426, offset 0x8008df78
	/* begin block 1 */
		// Start line: 427
		// Start offset: 0x8008DF78
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 439
			// Start offset: 0x8008DFE4
		/* end block 1.1 */
		// End offset: 0x8008E094
		// End Line: 452
	/* end block 1 */
	// End offset: 0x8008E0EC
	// End Line: 467

	/* begin block 2 */
		// Start line: 923
	/* end block 2 */
	// End Line: 924

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
  SOUL_Physics(instance,DAT_800d2314);
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
 // line 473, offset 0x8008e108
	/* begin block 1 */
		// Start line: 1018
	/* end block 1 */
	// End Line: 1019

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 480, offset 0x8008e138
	/* begin block 1 */
		// Start line: 481
		// Start offset: 0x8008E138
		// Variables:
	// 		struct _MonsterVars *mv; // $v0

		/* begin block 1.1 */
			// Start line: 490
			// Start offset: 0x8008E174
			// Variables:
		// 		struct _Instance *enemy; // $a0
		// 		int dx; // $s1
		// 		int dy; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E258
		// End Line: 505
	/* end block 1 */
	// End offset: 0x8008E288
	// End Line: 511

	/* begin block 2 */
		// Start line: 1033
	/* end block 2 */
	// End Line: 1034

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
  SOUL_Physics(instance,DAT_800d2314);
  SOUL_QueueHandler(instance);
  if ((instance->flags2 & 0x8000000U) == 0) {
    SOUL_Fade(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SOUL_IdleEntry(struct _Instance *instance /*$a0*/)
 // line 516, offset 0x8008e29c
	/* begin block 1 */
		// Start line: 517
		// Start offset: 0x8008E29C
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	/* end block 1 */
	// End offset: 0x8008E29C
	// End Line: 517

	/* begin block 2 */
		// Start line: 1108
	/* end block 2 */
	// End Line: 1109

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 524, offset 0x8008e340
	/* begin block 1 */
		// Start line: 525
		// Start offset: 0x8008E340
		// Variables:
	// 		struct _MonsterVars *mv; // $s1
	// 		long xAccl; // $a1
	// 		long yAccl; // $a0
	/* end block 1 */
	// End offset: 0x8008E424
	// End Line: 560

	/* begin block 2 */
		// Start line: 1125
	/* end block 2 */
	// End Line: 1126

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
  SOUL_Physics(instance,DAT_800d2314);
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
 // line 566, offset 0x8008e440
	/* begin block 1 */
		// Start line: 567
		// Start offset: 0x8008E440
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _Instance *body; // $v0
	/* end block 1 */
	// End offset: 0x8008E440
	// End Line: 567

	/* begin block 2 */
		// Start line: 1212
	/* end block 2 */
	// End Line: 1213

/* File: C:\kain2\game\MONSTER\SOUL.C */

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
 // line 583, offset 0x8008e4a8
	/* begin block 1 */
		// Start line: 584
		// Start offset: 0x8008E4A8
		// Variables:
	// 		struct _MonsterVars *mv; // $s0

		/* begin block 1.1 */
			// Start line: 596
			// Start offset: 0x8008E504
			// Variables:
		// 		struct _Instance *body; // $v0
		/* end block 1.1 */
		// End offset: 0x8008E52C
		// End Line: 600
	/* end block 1 */
	// End offset: 0x8008E54C
	// End Line: 608

	/* begin block 2 */
		// Start line: 1248
	/* end block 2 */
	// End Line: 1249

/* File: C:\kain2\game\MONSTER\SOUL.C */

void SOUL_Reanimate(_Instance *instance)

{
  long lVar1;
  _Instance *Inst;
  __Event *p_Var2;
  void *pvVar3;
  
  pvVar3 = instance->extraData;
  SOUL_MoveToDest(instance,0x10,DAT_800d2314);
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
 // line 613, offset 0x8008e560
	/* begin block 1 */
		// Start line: 1312
	/* end block 1 */
	// End Line: 1313

	/* begin block 2 */
		// Start line: 1314
	/* end block 2 */
	// End Line: 1315

/* File: C:\kain2\game\MONSTER\SOUL.C */

void SOUL_Effect(_Instance *instance,evFXHitData *data)

{
  return;
}





