#include "THISDUST.H"
#include "HUNTER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_InitFlamethrow(struct _Instance *instance /*$a0*/)
 // line 87, offset 0x8007c59c
	/* begin block 1 */
		// Start line: 89
		// Start offset: 0x8007C59C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		struct _HunterVars *hv; // $v0
	/* end block 1 */
	// End offset: 0x8007C5D0
	// End Line: 98

	/* begin block 2 */
		// Start line: 174
	/* end block 2 */
	// End Line: 175

	/* begin block 3 */
		// Start line: 175
	/* end block 3 */
	// End Line: 176

void HUNTER_InitFlamethrow(_Instance *instance)

{
  undefined2 *puVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  puVar1 = *(undefined2 **)((int)pvVar2 + 0x16c);
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[1] = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xfffffffb;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HUNTER_Flamethrow(struct _Instance *instance /*$s5*/, int damage /*$s4*/, int newPoint /*$s7*/, int segment /*$s6*/)
 // line 135, offset 0x8007c5d8
	/* begin block 1 */
		// Start line: 136
		// Start offset: 0x8007C5D8
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _HunterVars *hv; // $s3
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct _MonsterIR *enemy; // $s2
	// 		struct MATRIX *matrix; // $a1
	// 		int tick; // $v1
	// 		int time; // $a0
	// 		int dist; // $s1
	// 		int angle; // $v1
	// 		struct _Instance *weapon; // $s0
	// 		struct _Position mypos; // stack offset -72
	// 		struct _Position targpos; // stack offset -64
	// 		struct _Rotation rot; // stack offset -56
	// 		struct _Position zero; // stack offset -48

		/* begin block 1.1 */
			// Start line: 272
			// Start offset: 0x8007C8C8
			// Variables:
		// 		int i; // $s4
		// 		int size; // $v1
		// 		int angle; // $s6
		// 		int flamedist; // $s0

			/* begin block 1.1.1 */
				// Start line: 287
				// Start offset: 0x8007C930
				// Variables:
			// 		int flamesize; // $v1
			/* end block 1.1.1 */
			// End offset: 0x8007C950
			// End Line: 289
		/* end block 1.1 */
		// End offset: 0x8007C98C
		// End Line: 296
	/* end block 1 */
	// End offset: 0x8007C998
	// End Line: 301

	/* begin block 2 */
		// Start line: 270
	/* end block 2 */
	// End Line: 271

int HUNTER_Flamethrow(_Instance *instance,int damage,int newPoint,int segment)

{
  ushort uVar1;
  short sVar2;
  _Instance *p_Var3;
  uint uVar4;
  long lVar5;
  int iVar6;
  int Data;
  MATRIX *pMVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  int size;
  _SVector local_48;
  _Position local_40;
  _Rotation local_38;
  _Position _Stack48;
  
  pvVar8 = instance->data;
  puVar11 = *(ushort **)((int)instance->extraData + 0x16c);
  iVar9 = *(int *)((int)instance->extraData + 0xc4);
  memset(&_Stack48,0,6);
  p_Var3 = INSTANCE_GetChildLinkedToSegment(instance,(uint)*(byte *)((int)pvVar8 + 0x23));
  if ((puVar11 != (ushort *)0x0) && (p_Var3 != (_Instance *)0x0)) {
    pMVar7 = p_Var3->matrix;
    local_48.x = -pMVar7->m[3];
    local_48.y = -pMVar7->m[4];
    local_48.z = -pMVar7->m[5];
    sVar2 = MATH3D_AngleFromPosToPos(&_Stack48,(_Position *)&local_48);
    pMVar7 = p_Var3->matrix + segment;
    local_48.x = *(short *)pMVar7->t;
    local_48.y = *(short *)(pMVar7->t + 1);
    local_48.z = *(short *)(pMVar7->t + 2);
    Data = *(int *)(puVar11 + 2) + gameTrackerX.idleTime;
    while (0xfff < Data) {
      if (newPoint == 0) {
        puVar11[(int)(short)puVar11[1] + 4] = 0xffff;
      }
      else {
        puVar11[(int)(short)puVar11[1] + 4] = 0x1000 - sVar2;
      }
      uVar4 = (uint)puVar11[1] + 1 & 0xf;
      puVar11[1] = (ushort)uVar4;
      if (uVar4 == (int)(short)*puVar11) {
        if (puVar11[uVar4 + 4] == 0xffff) {
          return 1;
        }
        *puVar11 = *puVar11 + 1 & 0xf;
      }
      Data = Data + -0x1000;
    }
    *(int *)(puVar11 + 2) = Data;
    if (*puVar11 != puVar11[1]) {
      if (iVar9 != 0) {
        local_40.x = *(short *)(*(int *)(iVar9 + 4) + 0x5c);
        local_40.y = *(short *)(*(int *)(iVar9 + 4) + 0x5e);
        local_40.z = *(short *)(*(int *)(iVar9 + 4) + 0x60) + local_48.z;
        MATH3D_RotationFromPosToPos((_Position *)&local_48,&local_40,&local_38);
        Data = (int)local_38.x;
        if (Data < 0) {
          Data = -Data;
        }
        if (((Data < 0x555) &&
            (lVar5 = MATH3D_LengthXY((int)local_48.x - (int)local_40.x,
                                     (int)local_48.y - (int)local_40.y), lVar5 < 0x4b0)) &&
           ((int)(short)puVar11[((int)(short)puVar11[1] - (lVar5 / 0x4b + 1) & 0xfU) + 4] != -1)) {
          uVar4 = (int)local_38.z -
                  (int)(short)puVar11[((int)(short)puVar11[1] - (lVar5 / 0x4b + 1) & 0xfU) + 4] &
                  0xfff;
          if (uVar4 < 0x801) {
            if (0x50 < uVar4) goto LAB_8007c8cc;
          }
          else {
            Data = uVar4 - 0x1000;
            if (Data < 0) {
              Data = -Data;
            }
            if (0x50 < Data) goto LAB_8007c8cc;
          }
          Data = SetMonsterHitData(instance,(_Instance *)0x0,damage << 8,0,0);
          INSTANCE_Post(*(_Instance **)(iVar9 + 4),0x1000000,Data);
        }
      }
LAB_8007c8cc:
      Data = 0;
      uVar4 = SEXT24((short)puVar11[1]);
      iVar10 = 0x4b;
      iVar9 = Data;
      do {
        uVar4 = uVar4 - 1 & 0xf;
        uVar1 = puVar11[uVar4 + 4];
        if ((int)(short)uVar1 != -1) {
          iVar6 = iVar9;
          if (iVar9 < 0) {
            iVar6 = iVar9 + 7;
          }
          iVar6 = iVar6 >> 3;
          if (iVar6 < 0x12) {
            iVar6 = 0x12;
          }
          if (Data < iVar10) {
            size = Data / 6 + (Data >> 0x1f);
            do {
              size = size - (Data >> 0x1f);
              if (size < 0x25) {
                size = 0x25;
              }
              FX_MakeHitFlame(&local_48,0,(int)(short)uVar1,Data,size);
              Data = Data + iVar6 / 2;
              size = Data / 6 + (Data >> 0x1f);
            } while (Data < iVar10);
          }
        }
        iVar10 = iVar10 + 0x4b;
        iVar9 = iVar9 + 0x4b;
      } while (uVar4 != (int)(short)*puVar11);
      return 0;
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_Init(struct _Instance *instance /*$s2*/)
 // line 307, offset 0x8007c9c4
	/* begin block 1 */
		// Start line: 308
		// Start offset: 0x8007C9C4
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _HunterVars *hv; // $v0
	/* end block 1 */
	// End offset: 0x8007CA40
	// End Line: 344

	/* begin block 2 */
		// Start line: 791
	/* end block 2 */
	// End Line: 792

void HUNTER_Init(_Instance *instance)

{
  char *pcVar1;
  void *pvVar2;
  void *pvVar3;
  
  pvVar3 = instance->data;
  pvVar2 = instance->extraData;
  HUMAN_Init(instance);
  *(undefined4 *)((int)pvVar2 + 0x16c) = 0;
  if (*(char *)((int)pvVar2 + 0x15a) == '\0') {
    HUMAN_CreateWeapon(instance,0xd,(uint)*(byte *)((int)pvVar3 + 0x23));
  }
  else {
    HUMAN_CreateWeapon(instance,0xe,(uint)*(byte *)((int)pvVar3 + 0x23));
    if ((pvVar2 != (void *)0x0) && (pcVar1 = MEMPACK_Malloc(0x28,'$'), pcVar1 != (char *)0x0)) {
      *(char **)((int)pvVar2 + 0x16c) = pcVar1;
    }
  }
  G2Anim_DisableSegment(&instance->anim,0x1f);
  G2Anim_DisableSegment(&instance->anim,0x17);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_CleanUp(struct _Instance *instance /*$s0*/)
 // line 348, offset 0x8007ca74
	/* begin block 1 */
		// Start line: 349
		// Start offset: 0x8007CA74
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		struct _HunterVars *hv; // $a0
	/* end block 1 */
	// End offset: 0x8007CAAC
	// End Line: 361

	/* begin block 2 */
		// Start line: 873
	/* end block 2 */
	// End Line: 874

void HUNTER_CleanUp(_Instance *instance)

{
  char *address;
  
  if ((instance->extraData != (void *)0x0) &&
     (address = *(char **)((int)instance->extraData + 0x16c), address != (char *)0x0)) {
    MEMPACK_Free(address);
  }
  HUMAN_CleanUp(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_ProjectileEntry(struct _Instance *instance /*$a0*/)
 // line 364, offset 0x8007cac4
	/* begin block 1 */
		// Start line: 365
		// Start offset: 0x8007CAC4
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007CB04
	// End Line: 376

	/* begin block 2 */
		// Start line: 905
	/* end block 2 */
	// End Line: 906

void HUNTER_ProjectileEntry(_Instance *instance)

{
  void *pvVar1;
  
  pvVar1 = instance->extraData;
  MON_ProjectileEntry(instance);
  if (*(char *)((int)pvVar1 + 0x15a) != '\0') {
    *(uint *)((int)pvVar1 + 4) = *(uint *)((int)pvVar1 + 4) & 0xfffffffc;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_Projectile(struct _Instance *instance /*$s2*/)
 // line 378, offset 0x8007cb14
	/* begin block 1 */
		// Start line: 379
		// Start offset: 0x8007CB14
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterMissile *missileDef; // $s1
	// 		int playMode; // $a3
	/* end block 1 */
	// End offset: 0x8007CD40
	// End Line: 465

	/* begin block 2 */
		// Start line: 933
	/* end block 2 */
	// End Line: 934

void HUNTER_Projectile(_Instance *instance)

{
  char cVar1;
  long lVar2;
  uint animtype;
  int mode;
  undefined4 local_10;
  void *pvVar3;
  undefined4 local_c;
  int iVar4;
  
  pvVar3 = instance->extraData;
  iVar4 = *(int *)((int)instance->data + 0x40) +
          (int)*(char *)(*(int *)(*(int *)((int)pvVar3 + 0x164) + 8) + 0x18) * 0x10;
  if (*(char *)((int)pvVar3 + 0x15a) == '\0') {
    MON_Projectile(instance);
    goto LAB_8007cd40;
  }
  if ((*(uint *)((int)pvVar3 + 4) & 1) == 0) {
    if (*(int *)((int)pvVar3 + 0xc4) != 0) {
      if ((instance->flags2 & 0x10U) == 0) {
        mode = MON_AnimPlayingFromList(instance,(char *)(iVar4 + 0xe),(uint)*(byte *)(iVar4 + 5));
        if ((mode != 0) &&
           (iVar4 = G2EmulationInstanceQueryPassedFrame(instance,0,(uint)*(byte *)(iVar4 + 4)),
           iVar4 != 0)) {
          *(uint *)((int)pvVar3 + 4) = *(uint *)((int)pvVar3 + 4) | 1;
          HUNTER_InitFlamethrow(instance);
        }
        goto LAB_8007cd40;
      }
      cVar1 = *(char *)((int)pvVar3 + 0x15b) + '\x01';
      *(char *)((int)pvVar3 + 0x15b) = cVar1;
      animtype = SEXT14(cVar1);
      if ((int)animtype < (int)(uint)*(byte *)(iVar4 + 0xd)) {
        mode = 1;
        if (animtype == (uint)*(byte *)(iVar4 + 5)) {
          mode = 2;
        }
        MON_PlayAnimFromList(instance,(char *)(iVar4 + 0xe),animtype,mode);
        goto LAB_8007cd40;
      }
    }
  }
  else {
    if ((*(uint *)((int)pvVar3 + 4) & 2) == 0) {
      HUNTER_Flamethrow(instance,(uint)*(byte *)(iVar4 + 7),1,(uint)*(byte *)(iVar4 + 6));
      *(uint *)((int)pvVar3 + 4) = *(uint *)((int)pvVar3 + 4) | 2;
      if (*(int *)((int)pvVar3 + 0xc4) != 0) {
        iVar4 = *(int *)(*(int *)((int)pvVar3 + 0xc4) + 4);
        lVar2 = MATH3D_LengthXY((int)*(short *)(iVar4 + 0x5c) - (int)(instance->position).x,
                                (int)*(short *)(iVar4 + 0x5e) - (int)(instance->position).y);
        if (lVar2 < 0x4b0) {
          *(uint *)((int)pvVar3 + 4) = *(uint *)((int)pvVar3 + 4) & 0xfffffffd;
        }
        MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar3 + 0xc4) + 4) + 0x5c)
                           ,*(short *)(*(int *)((int)pvVar3 + 0x164) + 0x1c));
      }
      goto LAB_8007cd40;
    }
    if (*(int *)((int)pvVar3 + 0xc4) != 0) {
      MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar3 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar3 + 0x164) + 0x1c));
    }
    mode = HUNTER_Flamethrow(instance,(uint)*(byte *)(iVar4 + 7),0,(uint)*(byte *)(iVar4 + 6));
    if (mode == 0) goto LAB_8007cd40;
    cVar1 = *(char *)((int)pvVar3 + 0x15b) + '\x01';
    *(char *)((int)pvVar3 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)(uint)*(byte *)(iVar4 + 0xd)) {
      MON_PlayAnimFromList(instance,(char *)(iVar4 + 0xe),(int)cVar1,1);
      goto LAB_8007cd40;
    }
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_c,local_10));
LAB_8007cd40:
  MON_DefaultQueueHandler(instance);
  return;
}





