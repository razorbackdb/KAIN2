#include "THISDUST.H"
#include "HUNTER.H"

void HUNTER_InitFlamethrow(_Instance *instance)

{
  undefined2 *puVar1;
  void *pvVar2;

  pvVar2 = instance->extraData;
  puVar1 = *(undefined2 **)((int)pvVar2 + 0x16c);
  if (puVar1 != (undefined2 *)0x0)
  {
    puVar1[1] = 0;
    *puVar1 = 0;
    *(u_char *)(puVar1 + 4) = 0;
    *(u_char *)(puVar1 + 2) = 0;
    *(u_int *)((int)pvVar2 + 4) = *(u_int *)((int)pvVar2 + 4) & 0xfffffffb;
  }
  return;
}

int HUNTER_Flamethrow(_Instance *instance, int damage, int newPoint, int segment)

{
  u_short uVar1;
  short sVar2;
  _Instance *p_Var3;
  u_int uVar4;
  long lVar5;
  int iVar6;
  MATRIX *pMVar7;
  int Data;
  void *pvVar8;
  int iVar9;
  int iVar10;
  u_short *puVar11;
  int size;
  _SVector local_48;
  short local_40;
  short local_3e;
  short local_3c;
  _Position _Stack48;

  pvVar8 = instance->data;
  puVar11 = *(u_short **)((int)instance->extraData + 0x16c);
  iVar9 = *(int *)((int)instance->extraData + 0xc4);
  memset(&_Stack48, 0, 6);
  p_Var3 = INSTANCE_GetChildLinkedToSegment(instance, (u_int) * (byte *)((int)pvVar8 + 0x23));
  if ((puVar11 != (u_short *)0x0) && (p_Var3 != (_Instance *)0x0))
  {
    pMVar7 = p_Var3->matrix;
    local_48.x = -pMVar7->m[3];
    local_48.y = -pMVar7->m[4];
    local_48.z = -pMVar7->m[5];
    sVar2 = MATH3D_AngleFromPosToPos(&_Stack48, (_Position *)&local_48);
    pMVar7 = p_Var3->matrix + segment;
    local_48.x = *(short *)pMVar7->t;
    local_48.y = *(short *)(pMVar7->t + 1);
    local_48.z = *(short *)(pMVar7->t + 2);
    Data = *(int *)(puVar11 + 2) + gameTrackerX.timeMult;
    while (0xfff < Data)
    {
      if (newPoint == 0)
      {
        puVar11[(int)(short)puVar11[1] + 6] = 0xffff;
      }
      else
      {
        puVar11[(int)(short)puVar11[1] + 6] = 0x1000 - sVar2;
      }
      uVar4 = (u_int)puVar11[1] + 1 & 0xf;
      puVar11[1] = (u_short)uVar4;
      if (uVar4 == (int)(short)*puVar11)
      {
        if (puVar11[uVar4 + 6] == 0xffff)
        {
          return 1;
        }
        *puVar11 = *puVar11 + 1 & 0xf;
      }
      Data = Data + -0x1000;
    }
    *(int *)(puVar11 + 2) = Data;
    if (*puVar11 != puVar11[1])
    {
      if (iVar9 != 0)
      {
        if (*(int *)(*(int *)(iVar9 + 4) + 0x40) != 0)
        {
          local_40 = *(short *)(*(int *)(iVar9 + 4) + 0x5c);
          local_3e = *(short *)(*(int *)(iVar9 + 4) + 0x5e);
          local_3c = local_48.z;
          sVar2 = MATH3D_AngleFromPosToPos(&instance->position, (_Position *)(*(int *)(iVar9 + 4) + 0x5c));
          Data = (int)local_48.z - *(int *)(*(int *)(*(int *)(iVar9 + 4) + 0x40) + 0x3c);
          if (Data < 0)
          {
            Data = -Data;
          }
          if (((Data < 200) &&
               (lVar5 = MATH3D_LengthXYZ((int)local_48.x - (int)local_40,
                                         (int)local_48.y - (int)local_3e),
                lVar5 < 0x4b0)) &&
              0x4b + 1) & 0xfU) + 6] != -1))
            {
            uVar4 = (int)sVar2 -
 0x4b + 1) & 0xfU) + 6] &
                    0xfff;
            if (uVar4 < 0x801)
            {
              if (0x50 < uVar4)
                goto LAB_8007d2a0;
            }
            else
            {
              Data = uVar4 - 0x1000;
              if (Data < 0)
              {
                Data = -Data;
              }
              if (0x50 < Data)
                goto LAB_8007d2a0;
            }
            Data = SetMonsterImpaleData(instance, (_Instance *)0x0, damage << 8, 0, 0);
            INSTANCE_Query(*(_Instance **)(iVar9 + 4), 0x1000000, Data);
            }
        }
      }
    LAB_8007d2a0:
      Data = 0;
      uVar4 = SEXT24((short)puVar11[1]);
      iVar10 = 0x4b;
      iVar9 = Data;
      do
      {
        uVar4 = uVar4 - 1 & 0xf;
        uVar1 = puVar11[uVar4 + 6];
        if ((int)(short)uVar1 != -1)
        {
          iVar6 = iVar9;
          if (iVar9 < 0)
          {
            iVar6 = iVar9 + 7;
          }
          iVar6 = iVar6 >> 3;
          if (iVar6 < 0x12)
          {
            iVar6 = 0x12;
          }
          if (Data < iVar10)
          {
            6 + (Data >> 0x1f);
            do
            {
              size = size - (Data >> 0x1f);
              if (size < 0x25)
              {
                size = 0x25;
              }
              FX_MakeHitFX(&local_48, 0, (int)(short)uVar1, Data, size);
              2;
              6 + (Data >> 0x1f);
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
  if (*(char *)((int)pvVar5 + 0x15a) == '\0')
  {
    bVar1 = *(byte *)((int)instance->data + 0x23);
    weaponid = 0xd;
  }
  else
  {
    bVar1 = *(byte *)((int)instance->data + 0x23);
  }
  p_Var3 = HUMAN_CreateWeapon(instance, weaponid, (u_int)bVar1);
  if (p_Var3 != (_Instance *)0x0)
  {
    HUMAN_Init(instance);
    *(u_char *)((int)pvVar5 + 0x16c) = 0;
    if (*(char *)((int)pvVar5 + 0x15a) == '\0')
    {
      uVar2 = 0x5000;
    }
    else
    {
      if ((pvVar5 != (void *)0x0) && (pcVar4 = MEMPACK_Malloc(0x2c, '$'), pcVar4 != (char *)0x0))
      {
        *(char **)((int)pvVar5 + 0x16c) = pcVar4;
      }
      uVar2 = 0x6000;
    }
    *(undefined2 *)((int)pvVar5 + 0x144) = uVar2;
    G2Anim_EnableSegment(&instance->anim, 0x1f);
    G2Anim_EnableSegment(&instance->anim, 0x17);
  }
  return;
}

void HUNTER_CleanUp(_Instance *instance)

{
  char *address;

  if ((instance->extraData != (void *)0x0) &&
      (address = *(char **)((int)instance->extraData + 0x16c), address != (char *)0x0))
  {
    MEMPACK_Init(address);
  }
  MON_CleanUp(instance);
  return;
}

void HUNTER_ProjectileEntry(_Instance *instance)

{
  void *pvVar1;

  pvVar1 = instance->extraData;
  MON_ProjectileEntry(instance);
  if (*(char *)((int)pvVar1 + 0x15a) != '\0')
  {
    *(u_int *)((int)pvVar1 + 4) = *(u_int *)((int)pvVar1 + 4) & 0xfffffffc;
  }
  return;
}

void BirthProjectilePhysOb(_Instance *instance)

{
  char cVar1;
  int iVar2;
  u_long uVar3;
  long lVar4;
  u_int animtype;
  u_char local_18;
  void *pvVar5;
  u_char local_14;
  int iVar6;
  int mode;
  int *piVar7;

  pvVar5 = instance->extraData;
  mode = *(int *)((int)pvVar5 + 0x16c);
  iVar6 = *(int *)((int)instance->data + 0x3c) +
          (int)*(char *)(*(int *)(*(int *)((int)pvVar5 + 0x164) + 8) + 0x1a) * 0x10;
  piVar7 = *(int **)((int)instance->data + 4);
  if (*(char *)((int)pvVar5 + 0x15a) == '\0')
  {
    MON_ProjectileEntry(instance);
    goto LAB_8007d784;
  }
  if (mode == 0)
  {
    return;
  }
  if (piVar7 == (int *)0x0)
  {
    return;
  }
  if ((*(u_int *)((int)pvVar5 + 4) & 1) == 0)
  {
    if (*(int *)((int)pvVar5 + 0xc4) != 0)
    {
      if ((instance->flags2 & 0x10U) == 0)
      {
        iVar2 = MON_AnimPlayingFromList(instance, (char *)(iVar6 + 0xe), (u_int) * (byte *)(iVar6 + 5));
        if ((iVar2 != 0) &&
            (iVar6 = G2EmulationInstanceQueryPassedFrame(instance, 0, (u_int) * (byte *)(iVar6 + 4)),
             iVar6 != 0))
        {
          *(u_int *)((int)pvVar5 + 4) = *(u_int *)((int)pvVar5 + 4) | 1;
          HUNTER_InitFlamethrow(instance);
          uVar3 = MON_GetAnim(instance);
          *(int *)(mode + 8) = uVar3 + *piVar7 * 0x21;
        }
        goto LAB_8007d784;
      }
      cVar1 = *(char *)((int)pvVar5 + 0x15b) + '\x01';
      *(char *)((int)pvVar5 + 0x15b) = cVar1;
      animtype = SEXT14(cVar1);
      if ((int)animtype < (int)(u_int) * (byte *)(iVar6 + 0xd))
      {
        mode = 1;
        if (animtype == (u_int) * (byte *)(iVar6 + 5))
        {
          mode = 2;
        }
        MON_PlayAnimFromListIfNotPlaying(instance, (char *)(iVar6 + 0xe), animtype, mode);
        goto LAB_8007d784;
      }
    }
  }
  else
  {
    if ((*(u_int *)((int)pvVar5 + 4) & 2) == 0)
    {
      HUNTER_Flamethrow(instance, (u_int) * (byte *)(iVar6 + 7), 1, (u_int) * (byte *)(iVar6 + 6));
      *(u_int *)((int)pvVar5 + 4) = *(u_int *)((int)pvVar5 + 4) | 2;
      if (*(int *)((int)pvVar5 + 0xc4) != 0)
      {
        iVar6 = *(int *)(*(int *)((int)pvVar5 + 0xc4) + 4);
        lVar4 = MATH3D_LengthXYZ((int)*(short *)(iVar6 + 0x5c) - (int)(instance->position).x,
                                 (int)*(short *)(iVar6 + 0x5e) - (int)(instance->position).y);
        uVar3 = MON_GetAnim(instance);
        if ((uVar3 <= *(u_int *)(mode + 8)) || (lVar4 < 0x4b0))
        {
          *(u_int *)((int)pvVar5 + 4) = *(u_int *)((int)pvVar5 + 4) & 0xfffffffd;
        }
        MON_MoveToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar5 + 0xc4) + 4) + 0x5c), *(short *)(*(int *)((int)pvVar5 + 0x164) + 0x1c));
      }
      goto LAB_8007d784;
    }
    if (*(int *)((int)pvVar5 + 0xc4) != 0)
    {
      MON_MoveToPosition(instance, (_Position *)(*(int *)(*(int *)((int)pvVar5 + 0xc4) + 4) + 0x5c),
                         *(short *)(*(int *)((int)pvVar5 + 0x164) + 0x1c));
    }
    mode = HUNTER_Flamethrow(instance, (u_int) * (byte *)(iVar6 + 7), 0, (u_int) * (byte *)(iVar6 + 6));
    if (mode == 0)
      goto LAB_8007d784;
    cVar1 = *(char *)((int)pvVar5 + 0x15b) + '\x01';
    *(char *)((int)pvVar5 + 0x15b) = cVar1;
    if ((int)cVar1 < (int)(u_int) * (byte *)(iVar6 + 0xd))
    {
      MON_PlayAnimFromListIfNotPlaying(instance, (char *)(iVar6 + 0xe), (int)cVar1, 1);
      goto LAB_8007d784;
    }
  }
  MON_SwitchState(instance, (MonsterState)CONCAT44(local_14, local_18));
LAB_8007d784:
  MON_DefaultMessageHandler(instance);
  return;
}
