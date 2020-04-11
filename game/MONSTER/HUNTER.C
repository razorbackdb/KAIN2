
#include "HUNTER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_InitFlamethrow(struct _Instance *instance /*$a0*/)
 // line 98, offset 0x8007cf6c
	/* begin block 1 */
		// Start line: 100
		// Start offset: 0x8007CF6C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		struct _HunterVars *hv; // $v0
	/* end block 1 */
	// End offset: 0x8007CFA4
	// End Line: 109

	/* begin block 2 */
		// Start line: 196
	/* end block 2 */
	// End Line: 197

	/* begin block 3 */
		// Start line: 197
	/* end block 3 */
	// End Line: 198

/* File: C:\kain2\game\MONSTER\HUNTER.C */

void HUNTER_InitFlamethrow(_Instance *instance)

{
  undefined2 *puVar1;
  void *pvVar2;
  
  pvVar2 = instance->extraData;
  puVar1 = *(undefined2 **)((int)pvVar2 + 0x16c);
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[1] = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
    *(uint *)((int)pvVar2 + 4) = *(uint *)((int)pvVar2 + 4) & 0xfffffffb;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ HUNTER_Flamethrow(struct _Instance *instance /*$s5*/, int damage /*$s4*/, int newPoint /*$s7*/, int segment /*$s6*/)
 // line 146, offset 0x8007cfac
	/* begin block 1 */
		// Start line: 147
		// Start offset: 0x8007CFAC
		// Variables:
	// 		struct _MonsterVars *mv; // $v0
	// 		struct _HunterVars *hv; // $s3
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct _MonsterIR *enemy; // $s2
	// 		struct MATRIX *matrix; // $a1
	// 		int tick; // $v1
	// 		int time; // $a1
	// 		int dist; // $s1
	// 		int angle; // $s0
	// 		struct _Instance *weapon; // $s0
	// 		struct _Position mypos; // stack offset -72
	// 		struct _Position targpos; // stack offset -64
	// 		struct _Rotation rot; // stack offset -56
	// 		struct _Position zero; // stack offset -48

		/* begin block 1.1 */
			// Start line: 220
			// Start offset: 0x8007D170
		/* end block 1.1 */
		// End offset: 0x8007D29C
		// End Line: 254

		/* begin block 1.2 */
			// Start line: 288
			// Start offset: 0x8007D29C
			// Variables:
		// 		int i; // $s4
		// 		int size; // $v1
		// 		int angle; // $s6
		// 		int flamedist; // $s0

			/* begin block 1.2.1 */
				// Start line: 303
				// Start offset: 0x8007D304
				// Variables:
			// 		int flamesize; // $v1
			/* end block 1.2.1 */
			// End offset: 0x8007D324
			// End Line: 305
		/* end block 1.2 */
		// End offset: 0x8007D360
		// End Line: 312
	/* end block 1 */
	// End offset: 0x8007D36C
	// End Line: 317

	/* begin block 2 */
		// Start line: 292
	/* end block 2 */
	// End Line: 293

/* File: C:\kain2\game\MONSTER\HUNTER.C */

int HUNTER_Flamethrow(_Instance *instance,int damage,int newPoint,int segment)

{
  ushort uVar1;
  short sVar2;
  _Instance *p_Var3;
  uint uVar4;
  long lVar5;
  int iVar6;
  MATRIX *pMVar7;
  int Data;
  void *pvVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  int size;
  _SVector local_48;
  short local_40;
  short local_3e;
  short local_3c;
  _Position _Stack48;
  
  pvVar8 = instance->data;
  puVar11 = *(ushort **)((int)instance->extraData + 0x16c);
  iVar9 = *(int *)((int)instance->extraData + 0xc4);
  memset();
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
    Data = *(int *)(puVar11 + 2) + DAT_800d2314;
    while (0xfff < Data) {
      if (newPoint == 0) {
        puVar11[(int)(short)puVar11[1] + 6] = 0xffff;
      }
      else {
        puVar11[(int)(short)puVar11[1] + 6] = 0x1000 - sVar2;
      }
      uVar4 = (uint)puVar11[1] + 1 & 0xf;
      puVar11[1] = (ushort)uVar4;
      if (uVar4 == (int)(short)*puVar11) {
        if (puVar11[uVar4 + 6] == 0xffff) {
          return 1;
        }
        *puVar11 = *puVar11 + 1 & 0xf;
      }
      Data = Data + -0x1000;
    }
    *(int *)(puVar11 + 2) = Data;
    if (*puVar11 != puVar11[1]) {
      if (iVar9 != 0) {
        if (*(int *)(*(int *)(iVar9 + 4) + 0x40) != 0) {
          local_40 = *(short *)(*(int *)(iVar9 + 4) + 0x5c);
          local_3e = *(short *)(*(int *)(iVar9 + 4) + 0x5e);
          local_3c = local_48.z;
          sVar2 = MATH3D_AngleFromPosToPos
                            (&instance->position,(_Position *)(*(int *)(iVar9 + 4) + 0x5c));
          Data = (int)local_48.z - *(int *)(*(int *)(*(int *)(iVar9 + 4) + 0x40) + 0x3c);
          if (Data < 0) {
            Data = -Data;
          }
          if (((Data < 200) &&
              (lVar5 = MATH3D_LengthXY((int)local_48.x - (int)local_40,
                                       (int)local_48.y - (int)local_3e), lVar5 < 0x4b0)) &&
             ((int)(short)puVar11[((int)(short)puVar11[1] - (lVar5 / 0x4b + 1) & 0xfU) + 6] != -1))
          {
            uVar4 = (int)sVar2 -
                    (int)(short)puVar11[((int)(short)puVar11[1] - (lVar5 / 0x4b + 1) & 0xfU) + 6] &
                    0xfff;
            if (uVar4 < 0x801) {
              if (0x50 < uVar4) goto LAB_8007d2a0;
            }
            else {
              Data = uVar4 - 0x1000;
              if (Data < 0) {
                Data = -Data;
              }
              if (0x50 < Data) goto LAB_8007d2a0;
            }
            Data = SetMonsterHitData(instance,(_Instance *)0x0,damage << 8,0,0);
            INSTANCE_Post(*(_Instance **)(iVar9 + 4),0x1000000,Data);
          }
        }
      }
LAB_8007d2a0:
      Data = 0;
      uVar4 = SEXT24((short)puVar11[1]);
      iVar10 = 0x4b;
      iVar9 = Data;
      do {
        uVar4 = uVar4 - 1 & 0xf;
        uVar1 = puVar11[uVar4 + 6];
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
// void /*$ra*/ HUNTER_Init(struct _Instance *instance /*$s1*/)
 // line 323, offset 0x8007d398
	/* begin block 1 */
		// Start line: 324
		// Start offset: 0x8007D398
		// Variables:
	// 		struct _MonsterAttributes *ma; // $v1
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _HunterVars *hv; // $v0
	// 		struct _Instance *weapon; // $v0
	/* end block 1 */
	// End offset: 0x8007D448
	// End Line: 371

	/* begin block 2 */
		// Start line: 828
	/* end block 2 */
	// End Line: 829

/* File: C:\kain2\game\MONSTER\HUNTER.C */

void HUNTER_Init(_Instance *instance)

{
  byte bVar1;
  undefined2 uVar2;
  _Instance *p_Var3;
  char *pcVar4;
  int weaponid;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  weaponid = 0xe;
  if (*(char *)((int)pvVar5 + 0x15a) == '\0') {
    bVar1 = *(byte *)((int)instance->data + 0x23);
    weaponid = 0xd;
  }
  else {
    bVar1 = *(byte *)((int)instance->data + 0x23);
  }
  p_Var3 = HUMAN_CreateWeapon(instance,weaponid,(uint)bVar1);
  if (p_Var3 != (_Instance *)0x0) {
    HUMAN_Init(instance);
    *(undefined4 *)((int)pvVar5 + 0x16c) = 0;
    if (*(char *)((int)pvVar5 + 0x15a) == '\0') {
      uVar2 = 0x5000;
    }
    else {
      if ((pvVar5 != (void *)0x0) && (pcVar4 = MEMPACK_Malloc(0x2c,'$'), pcVar4 != (char *)0x0)) {
        *(char **)((int)pvVar5 + 0x16c) = pcVar4;
      }
      uVar2 = 0x6000;
    }
    *(undefined2 *)((int)pvVar5 + 0x144) = uVar2;
    G2Anim_DisableSegment(&instance->anim,0x1f);
    G2Anim_DisableSegment(&instance->anim,0x17);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ HUNTER_CleanUp(struct _Instance *instance /*$s0*/)
 // line 373, offset 0x8007d45c
	/* begin block 1 */
		// Start line: 374
		// Start offset: 0x8007D45C
		// Variables:
	// 		struct _MonsterVars *mv; // $a0
	// 		struct _HunterVars *hv; // $a0
	/* end block 1 */
	// End offset: 0x8007D494
	// End Line: 386

	/* begin block 2 */
		// Start line: 933
	/* end block 2 */
	// End Line: 934

/* File: C:\kain2\game\MONSTER\HUNTER.C */

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
 // line 389, offset 0x8007d4ac
	/* begin block 1 */
		// Start line: 390
		// Start offset: 0x8007D4AC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8007D4EC
	// End Line: 401

	/* begin block 2 */
		// Start line: 965
	/* end block 2 */
	// End Line: 966

/* File: C:\kain2\game\MONSTER\HUNTER.C */

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
 // line 403, offset 0x8007d4fc
	/* begin block 1 */
		// Start line: 404
		// Start offset: 0x8007D4FC
		// Variables:
	// 		struct _MonsterVars *mv; // $s0
	// 		struct _MonsterAttributes *ma; // $a0
	// 		struct _MonsterMissile *missileDef; // $s1
	// 		struct _HunterVars *hv; // $s3
	// 		struct _HunterAttributes *ha; // $s4
	// 		int dist; // $s1
	// 		int playMode; // $a3
	/* end block 1 */
	// End offset: 0x8007D78C
	// End Line: 496

	/* begin block 2 */
		// Start line: 993
	/* end block 2 */
	// End Line: 994

/* File: C:\kain2\game\MONSTER\HUNTER.C */

void HUNTER_Projectile(_Instance *instance)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  uint animtype;
  undefined4 local_18;
  void *pvVar5;
  undefined4 local_14;
  int iVar6;
  int mode;
  int *piVar7;
  
  pvVar5 = instance->extraData;
  mode = *(int *)((int)pvVar5 + 0x16c);
  iVar6 = *(int *)((int)instance->data + 0x3c) +
          (int)*(char *)(*(int *)(*(int *)((int)pvVar5 + 0x164) + 8) + 0x1a) * 0x10;
  piVar7 = *(int **)((int)instance->data + 4);
  if (*(char *)((int)pvVar5 + 0x15a) == '\0') {
    MON_Projectile(instance);
    goto LAB_8007d784;
  }
  if (mode == 0) {
    return;
  }
  if (piVar7 == (int *)0x0) {
    return;
  }
  if ((*(uint *)((int)pvVar5 + 4) & 1) == 0) {
    if (*(int *)((int)pvVar5 + 0xc4) != 0) {
      if ((instance->flags2 & 0x10U) == 0) {
        iVar2 = MON_AnimPlayingFromList(instance,(char *)(iVar6 + 0xe),(uint)*(byte *)(iVar6 + 5));
        if ((iVar2 != 0) &&
           (iVar6 = G2EmulationInstanceQueryPassedFrame(instance,0,(uint)*(byte *)(iVar6 + 4)),
           iVar6 != 0)) {
          *(uint *)((int)pvVar5 + 4) = *(uint *)((int)pvVar5 + 4) | 1;
          HUNTER_InitFlamethrow(instance);
          uVar3 = MON_GetTime(instance);
          *(int *)(mode + 8) = uVar3 + *piVar7 * 0x21;
        }
        goto LAB_8007d784;
      }
      cVar1 = *(char *)((int)pvVar5 + 0x15b) + '\x01';
      *(char *)((int)pvVar5 + 0x15b) = cVar1;
      animtype = SEXT14(cVar1);
      if ((int)animtype < (int)(uint)*(byte *)(iVar6 + 0xd)) {
        mode = 1;
        if (animtype == (uint)*(byte *)(iVar6 + 5)) {
          mode = 2;
        }
        MON_PlayAnimFromList(instance,(char *)(iVar6 + 0xe),animtype,mode);
        goto LAB_8007d784;
      }
    }
  }
  else {
    if ((*(uint *)((int)pvVar5 + 4) & 2) == 0) {
      HUNTER_Flamethrow(instance,(uint)*(byte *)(iVar6 + 7),1,(uint)*(byte *)(iVar6 + 6));
      *(uint *)((int)pvVar5 + 4) = *(uint *)((int)pvVar5 + 4) | 2;
      if (*(int *)((int)pvVar5 + 0xc4) != 0) {
        iVar6 = *(int *)(*(int *)((int)pvVar5 + 0xc4) + 4);
        lVar4 = MATH3D_LengthXY((int)*(short *)(iVar6 + 0x5c) - (int)(instance->position).x,
                                (int)*(short *)(iVar6 + 0x5e) - (int)(instance->position).y);
        uVar3 = MON_GetTime(instance);
        if ((uVar3 <= *(uint *)(mode + 8)) || (lVar4 < 0x4b0)) {
          *(uint *)((int)pvVar5 + 4) = *(uint *)((int)pvVar5 + 4) & 0xfffffffd;
        }
        MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar5 + 0xc4) + 4) + 0x5c)
                           ,*(short *)(*(int *)((int)pvVar5 + 0x164) + 0x1c));
      }
      goto LAB_8007d784;
    }
    if (*(int *)((int)pvVar5 + 0xc4) != 0) {
      MON_TurnToPosition(instance,(_Position *)(*(int *)(*(int *)((int)pvVar5 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar5 + 0x164) + 0x1c));
    }
    mode = HUNTER_Flamethrow(instance,(uint)*(byte *)(iVar6 + 7),0,(uint)*(byte *)(iVar6 + 6));
    if (mode == 0) goto LAB_8007d784;
    cVar1 = *(char *)((int)pvVar5 + 0x15b) + '\x01';
    *(char *)((int)pvVar5 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)(uint)*(byte *)(iVar6 + 0xd)) {
      MON_PlayAnimFromList(instance,(char *)(iVar6 + 0xe),(int)cVar1,1);
      goto LAB_8007d784;
    }
  }
  MON_SwitchState(instance,(MonsterState)CONCAT44(local_14,local_18));
LAB_8007d784:
  MON_DefaultQueueHandler(instance);
  return;
}





