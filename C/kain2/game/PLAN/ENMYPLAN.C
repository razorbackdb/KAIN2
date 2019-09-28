#include "THISDUST.H"
#include "ENMYPLAN.H"

// decompiled code
// original method signature:
// void /*$ra*/ ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool /*$a0*/)
// line 107, offset 0x800965a4
/* begin block 1 */
// Start line: 109
// Start offset: 0x800965A4
// Variables:
// 		int i; // $v0
/* end block 1 */
// End offset: 0x800965BC
// End Line: 117

/* begin block 2 */
// Start line: 214
/* end block 2 */
// End Line: 215

/* begin block 3 */
// Start line: 215
/* end block 3 */
// End Line: 216

/* begin block 4 */
// Start line: 220
/* end block 4 */
// End Line: 221

void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool)

{
  int iVar1;
  undefined *puVar2;

  iVar1 = 9;
  puVar2 = (undefined *)((int)enemyPlanPool + 0x34e);
  do
  {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + -0x5e;
  } while (-1 < iVar1);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_GetNextAvailablePlanningSlot()
// line 131, offset 0x800965c4
/* begin block 1 */
// Start line: 133
// Start offset: 0x800965C4
// Variables:
// 		int slotID; // $a1
// 		int i; // $v1
/* end block 1 */
// End offset: 0x800965FC
// End Line: 143

/* begin block 2 */
// Start line: 263
/* end block 2 */
// End Line: 264

/* begin block 3 */
// Start line: 264
/* end block 3 */
// End Line: 265

/* begin block 4 */
// Start line: 265
/* end block 4 */
// End Line: 266

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetNextAvailablePlanningSlot(void)

{
  int iVar1;
  char *pcVar2;

  iVar1 = 0;
  pcVar2 = DAT_800d11c0;
  do
  {
    if (*pcVar2 == '\0')
    {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x5e;
  } while (iVar1 < 10);
  return -1;
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_GetInitializedPlanningWorkspaceFinal()
// line 167, offset 0x80096604
/* begin block 1 */
// Start line: 168
// Start offset: 0x80096604
// Variables:
// 		struct EnemyPlanSlotData *pool; // $s0
// 		int slotID; // $a0
/* end block 1 */
// End offset: 0x8009664C
// End Line: 181

/* begin block 2 */
// Start line: 338
/* end block 2 */
// End Line: 339

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;

  iVar1 = DAT_800d11c0;
  iVar2 = ENMYPLAN_GetNextAvailablePlanningSlot();
  if (iVar2 != -1)
  {
    puVar3 = (undefined *)(iVar2 * 0x5e + iVar1);
    *puVar3 = 1;
    puVar3[1] = 0;
  }
  return iVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ ENMYPLAN_ReleasePlanningWorkspace(int slotID /*$s0*/)
// line 185, offset 0x80096660
/* begin block 1 */
// Start line: 186
// Start offset: 0x80096660
// Variables:
// 		struct EnemyPlanSlotData *pool; // $s1
/* end block 1 */
// End offset: 0x800966B4
// End Line: 203

/* begin block 2 */
// Start line: 376
/* end block 2 */
// End Line: 377

void ENMYPLAN_ReleasePlanningWorkspace(int slotID)

{
  int iVar1;

  iVar1 = DAT_800d11c0;
  if ((-1 < slotID) && (slotID < 10))
  {
    PLANAPI_DeleteNodesFromPoolByType(2);
    PLANAPI_DeleteNodesFromPoolByType(3);
    *(undefined *)(slotID * 0x5e + iVar1) = 0;
  }
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_WayPointSkipped(struct _Position *currentPos /*$a0*/, struct _Position *targetPos /*$s0*/, struct _Position *nextTargetPos /*$s1*/)
// line 208, offset 0x800966c8
/* begin block 1 */
// Start line: 209
// Start offset: 0x800966C8
// Variables:
// 		long range[2]; // stack offset -40
// 		struct _Position vector[2]; // stack offset -32

/* begin block 1.1 */
// Start line: 209
// Start offset: 0x800966C8
// Variables:
// 		short _x0; // $v1
// 		short _y0; // $v0
// 		short _z0; // $a1
// 		short _x1; // $a2
// 		short _y1; // $a3
// 		short _z1; // $t0
// 		struct _Position *_v; // $a0
/* end block 1.1 */
// End offset: 0x800966C8
// End Line: 209

/* begin block 1.2 */
// Start line: 209
// Start offset: 0x800966C8
// Variables:
// 		short _x0; // $a0
// 		short _y0; // $v0
// 		short _z0; // $v1
// 		short _x1; // $a1
// 		short _y1; // $a2
// 		short _z1; // $a3
// 		struct _Position *_v; // $a1
/* end block 1.2 */
// End offset: 0x800966C8
// End Line: 209
/* end block 1 */
// End offset: 0x800967A0
// End Line: 225

/* begin block 2 */
// Start line: 423
/* end block 2 */
// End Line: 424

void ENMYPLAN_WayPointSkipped(ushort *param_1, ushort *param_2)

{
  /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(((uint)*param_2 - (uint)*param_1) * 0x10000) >> 0x10,
                   (int)(short)(param_2[1] - param_1[1]), (int)(short)(param_2[2] - param_1[2]));
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_WayPointReached(struct _Position *currentPos /*$v1*/, struct _Position *oldCurrentPos /*$s1*/, struct _Position *targetPos /*$s0*/)
// line 235, offset 0x80096834
/* begin block 1 */
// Start line: 236
// Start offset: 0x80096834
// Variables:
// 		long range[2]; // stack offset -24
/* end block 1 */
// End offset: 0x800968D0
// End Line: 249

/* begin block 2 */
// Start line: 487
/* end block 2 */
// End Line: 488

void ENMYPLAN_WayPointReached(short *param_1, undefined4 param_2, short *param_3)

{
  /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)*param_3 - (int)*param_1, (int)param_3[1] - (int)param_1[1],
                   (int)param_3[2] - (int)param_1[2]);
}

// decompiled code
// original method signature:
// void /*$ra*/ ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot /*$a0*/)
// line 267, offset 0x800968e4
/* begin block 1 */
// Start line: 552
/* end block 1 */
// End Line: 553

void ENMYPLAN_Replan(EnemyPlanSlotData *planSlot)

{
  planSlot->state = '\0';
  PLANAPI_DeleteNodesFromPoolByType(2);
  PLANAPI_DeleteNodesFromPoolByType(3);
  return;
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_PathClear(struct _Position *pos /*$s1*/, struct _Position *target /*$s0*/)
// line 274, offset 0x80096910
/* begin block 1 */
// Start line: 275
// Start offset: 0x80096910
// Variables:
// 		int len; // $a1
// 		int oldPCO; // $s2
// 		struct _Position *tpos; // $a1
// 		struct _Position newTarget; // stack offset -24
/* end block 1 */
// End offset: 0x80096A68
// End Line: 304

/* begin block 2 */
// Start line: 566
/* end block 2 */
// End Line: 567

void ENMYPLAN_PathClear(ushort *param_1, ushort *param_2)

{
  uGpffffb6be = 1;
  /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(((uint)*param_2 - (uint)*param_1) * 0x10000) >> 0x10,
                   (int)(((uint)param_2[1] - (uint)param_1[1]) * 0x10000) >> 0x10,
                   (int)(((uint)param_2[2] - (uint)param_1[2]) * 0x10000) >> 0x10);
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_MoveToTargetFinal(struct _Instance *instance /*stack 0*/, struct _Position *outputPos /*stack 4*/, int slotID /*$a2*/, struct _Position *targetPos /*$s1*/, int validNodeTypes /*stack 16*/)
// line 313, offset 0x80096a90
/* begin block 1 */
// Start line: 314
// Start offset: 0x80096A90
// Variables:
// 		struct EnemyPlanSlotData *pool; // $a0
// 		struct EnemyPlanSlotData *planSlot; // $s0
// 		struct EnemyPlanData *planData; // $s5
// 		int nextWayPointType; // $a0
// 		int nextNextWayPointType; // $s2
// 		int pathFound; // $v0
// 		int nextWayPointIdx; // $s1
// 		int nextNextWayPointIdx; // $s4
// 		int nextWayPointSkip; // $a3
// 		int i; // $v1
// 		struct _Position *nextWayPointPos; // $s6
// 		struct _Position *nextNextWayPointPos; // $fp
/* end block 1 */
// End offset: 0x80096F6C
// End Line: 540

/* begin block 2 */
// Start line: 664
/* end block 2 */
// End Line: 665

undefined4
ENMYPLAN_MoveToTargetFinal(int param_1, undefined4 *param_2, int param_3, undefined4 *param_4, int param_5)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short sVar6;
  uint uVar7;
  uchar *puVar8;
  int iVar9;
  EnemyPlanSlotData *planSlot;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  uchar *puVar13;
  EnemyPlanData *planData;
  _Position *p_Var14;
  _Position *p_Var15;

  uGpffffb6be = 1;
  uVar2 = *(undefined2 *)(param_4 + 1);
  *param_2 = *param_4;
  *(undefined2 *)(param_2 + 1) = uVar2;
  if ((param_3 == -1) || (9 < param_3))
  {
    uGpffffb6be = 1;
    return 2;
  }
  planSlot = (EnemyPlanSlotData *)(iGpffffb70c + param_3 * 0x5e);
  bVar11 = planSlot->state;
  planData = &planSlot->planData;
  if (bVar11 == 1)
  {
    iVar3 = PLANAPI_FindPathInGraphToTarget(&planSlot->startPos, planData, param_5);
    sVar6 = planSlot->timer + 1;
    planSlot->timer = sVar6;
    if (iVar3 == 0)
    {
      if (100 < sVar6)
      {
        planSlot->state = '\x04';
      }
    }
    else
    {
      planSlot->state = '\x02';
      planSlot->wayPointBeingServoedTo = '\x01';
    }
    goto LAB_80096efc;
  }
  if (bVar11 < 2)
  {
    if (bVar11 == 0)
    {
      sVar6 = *(short *)(param_1 + 0x60);
      *(undefined4 *)&planSlot->startPos = *(undefined4 *)(param_1 + 0x5c);
      (planSlot->startPos).z = sVar6;
      sVar6 = *(short *)(param_4 + 1);
      *(undefined4 *)&planSlot->goalPos = *param_4;
      (planSlot->goalPos).z = sVar6;
      planSlot->timer = 0;
      iVar3 = PLANAPI_AddNodeOfTypeToPool(&planSlot->goalPos, 3);
      if (iVar3 != 0)
      {
        PLANAPI_AddNodeOfTypeToPool(&planSlot->startPos, 2);
        planSlot->state = '\x01';
      }
    }
    goto LAB_80096efc;
  }
  if (bVar11 != 2)
  {
    if (bVar11 == 3)
    {
      iVar3 = ENMYPLAN_PathClear((ushort *)(param_1 + 0x5c), (ushort *)param_4);
      if (iVar3 != 0)
      {
        /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)*(short *)param_4 - (int)*(short *)(param_1 + 0x5c),
                         (int)*(short *)((int)param_4 + 2) - (int)*(short *)(param_1 + 0x5e),
                         (int)*(short *)(param_4 + 1) - (int)*(short *)(param_1 + 0x60));
      }
      ENMYPLAN_Replan(planSlot);
      uVar2 = *(undefined2 *)(param_4 + 1);
      *param_2 = *param_4;
      *(undefined2 *)(param_2 + 1) = uVar2;
    }
    goto LAB_80096efc;
  }
  bVar11 = planSlot->wayPointBeingServoedTo;
  uVar10 = (uint)bVar11;
  puVar13 = planData->nodeSkipArray + uVar10;
  p_Var14 = planData->wayPointArray + uVar10;
  if (*puVar13 == '\x02')
  {
    iVar3 = ENMYPLAN_PathClear((ushort *)(param_1 + 0x5c), (ushort *)p_Var14);
    if (iVar3 == 0)
    {
      if (*(char *)(&planData[-1].field_0x43 + uVar10) == '\x01')
      {
        if (bVar11 != 0)
        {
          do
          {
            uVar7 = uVar10 - 1;
            if ((*(char *)(&planData[-1].field_0x43 + uVar10) != '\x01') || (uVar7 == 0))
            {
              planSlot->wayPointBeingServoedTo = (char)uVar7;
              planData->nodeSkipArray[uVar10] = '\x02';
              break;
            }
            uVar10 = uVar7;
          } while (0 < (int)uVar7);
        }
      }
      else
      {
        ENMYPLAN_Replan(planSlot);
      }
    }
  }
  else
  {
    iVar3 = uVar10 + 1;
    iVar9 = iVar3 * 6 + 0x10;
    bVar11 = planData->nodeTypeArray[uVar10 + 1] >> 3 & 3;
    if ((puVar13[8] >> 3 & 3) == bVar11)
    {
      puVar8 = planData->nodeSkipArray + uVar10;
      if ((*puVar13 != '\x02') && ((puVar13[8] >> 3 & 3) == 0))
      {
        do
        {
          p_Var15 = (_Position *)(planData->nodeSkipArray + iVar9);
          iVar4 = ENMYPLAN_WayPointSkipped((ushort *)(param_1 + 0x5c), (ushort *)p_Var14);
          puVar8 = planData->nodeSkipArray + uVar10;
          if (iVar4 == 0)
            goto LAB_80096db0;
          if ((int)((uint)(planSlot->planData).numWayPoints - 2) <=
              (int)(uint)(byte)planSlot->wayPointBeingServoedTo)
            break;
          *puVar13 = '\x01';
          puVar13 = puVar13 + 1;
          uVar10 = uVar10 + 1;
          iVar9 = iVar9 + 6;
          planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01';
          bVar12 = planData->nodeTypeArray[iVar3 + 1] >> 3 & 3;
          p_Var14 = p_Var15;
          if (bVar11 != bVar12)
            break;
          puVar8 = planData->nodeSkipArray + uVar10;
          if (*puVar13 == '\x02')
            goto LAB_80096db0;
          bVar1 = bVar11 == 0;
          iVar3 = iVar3 + 1;
          bVar11 = bVar12;
        } while (bVar1);
        goto LAB_80096da8;
      }
    }
    else
    {
    LAB_80096da8:
      puVar8 = planData->nodeSkipArray + uVar10;
    }
  LAB_80096db0:
    *puVar8 = '\x02';
  }
  iVar3 = ENMYPLAN_WayPointReached((short *)(param_1 + 0x5c), &planSlot->oldCurrentPos, (short *)p_Var14);
  if ((iVar3 != 0) &&
      (planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01',
       (int)((uint)(planSlot->planData).numWayPoints - 1) <=
           (int)(uint)(byte)planSlot->wayPointBeingServoedTo))
  {
    planSlot->state = '\x03';
    PLANAPI_DeleteNodesFromPoolByType(2);
    PLANAPI_DeleteNodesFromPoolByType(3);
  }
  sVar6 = planData->wayPointArray[(byte)planSlot->wayPointBeingServoedTo].z;
  *param_2 = *(undefined4 *)(planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo);
  *(short *)(param_2 + 1) = sVar6;
LAB_80096efc:
  sVar6 = *(short *)(param_1 + 0x60);
  *(undefined4 *)&planSlot->oldCurrentPos = *(undefined4 *)(param_1 + 0x5c);
  (planSlot->oldCurrentPos).z = sVar6;
  switch (planSlot->state)
  {
  case '\0':
  case '\x01':
    uVar5 = 0;
    break;
  case '\x02':
    uVar5 = 1;
    break;
  case '\x03':
    uVar5 = 2;
    break;
  default:
    uVar5 = 3;
  }
  uGpffffb6be = 0;
  return uVar5;
}

// decompiled code
// original method signature:
// int /*$ra*/ ValidSlotAndState(struct EnemyPlanSlotData *pool /*$a0*/, int slotID /*$a1*/)
// line 542, offset 0x80096f9c
/* begin block 1 */
// Start line: 1206
/* end block 1 */
// End Line: 1207

/* begin block 2 */
// Start line: 1208
/* end block 2 */
// End Line: 1209

int ValidSlotAndState(EnemyPlanSlotData *pool, int slotID)

{
  if ((slotID != -1) && (slotID < 10))
  {
    return (uint)((uint)(byte)pool[slotID].state - 2 < 2);
  }
  return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID /*$s0*/)
// line 555, offset 0x80096fe0
/* begin block 1 */
// Start line: 556
// Start offset: 0x80096FE0
// Variables:
// 		struct EnemyPlanSlotData *pool; // $s1
// 		struct EnemyPlanSlotData *planSlot; // $v0
/* end block 1 */
// End offset: 0x80097038
// End Line: 568

/* begin block 2 */
// Start line: 1232
/* end block 2 */
// End Line: 1233

int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID)

{
  EnemyPlanSlotData *pEVar1;
  int iVar2;
  uint uVar3;

  pEVar1 = DAT_800d11c0;
  iVar2 = ValidSlotAndState(DAT_800d11c0, slotID);
  if (iVar2 == 0)
  {
    uVar3 = 0x40;
  }
  else
  {
    uVar3 = (uint)pEVar1[slotID].planData.nodeTypeArray[(byte)pEVar1[slotID].wayPointBeingServoedTo];
  }
  return uVar3;
}

// decompiled code
// original method signature:
// int /*$ra*/ ENMYPLAN_GetPosOfNextWaypoint(int slotID /*$s0*/, struct _Position *pos /*$s2*/)
// line 570, offset 0x8009704c
/* begin block 1 */
// Start line: 571
// Start offset: 0x8009704C
// Variables:
// 		struct EnemyPlanSlotData *pool; // $s1
// 		struct EnemyPlanSlotData *planSlot; // $v1

/* begin block 1.1 */
// Start line: 575
// Start offset: 0x80097080
// Variables:
// 		short _x1; // $a0
// 		short _y1; // $a1
// 		short _z1; // $v1
// 		struct _Position *_v1; // $v1
/* end block 1.1 */
// End offset: 0x80097080
// End Line: 575
/* end block 1 */
// End offset: 0x800970D4
// End Line: 584

/* begin block 2 */
// Start line: 1270
/* end block 2 */
// End Line: 1271

int ENMYPLAN_GetPosOfNextWaypoint(int slotID, _Position *pos)

{
  short sVar1;
  short sVar2;
  EnemyPlanSlotData *pEVar3;
  int iVar4;
  _Position *p_Var5;

  pEVar3 = DAT_800d11c0;
  iVar4 = ValidSlotAndState(DAT_800d11c0, slotID);
  if (iVar4 != 0)
  {
    p_Var5 = pEVar3[slotID].planData.wayPointArray + (byte)pEVar3[slotID].wayPointBeingServoedTo;
    sVar1 = p_Var5->y;
    sVar2 = p_Var5->z;
    pos->x = p_Var5->x;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return (uint)(iVar4 != 0);
}

// decompiled code
// original method signature:
// void /*$ra*/ ENMYPLAN_RelocatePlanPositions(int slotID /*$a0*/, struct _Position *offset /*$t2*/)
// line 641, offset 0x800970ec
/* begin block 1 */
// Start line: 642
// Start offset: 0x800970EC
// Variables:
// 		struct EnemyPlanSlotData *pool; // $v1
// 		struct EnemyPlanSlotData *planSlot; // $t1
// 		struct _Position *pos; // $a0
// 		int i; // $a3
// 		int numWayPoints; // $v1

/* begin block 1.1 */
// Start line: 659
// Start offset: 0x80097140
// Variables:
// 		short _x0; // $v0
// 		short _y0; // $v0
// 		short _z0; // $v1
// 		short _x1; // $v1
// 		short _y1; // $a1
// 		short _z1; // $a2
/* end block 1.1 */
// End offset: 0x80097140
// End Line: 659
/* end block 1 */
// End offset: 0x80097180
// End Line: 663

/* begin block 2 */
// Start line: 1282
/* end block 2 */
// End Line: 1283

/* begin block 3 */
// Start line: 1370
/* end block 3 */
// End Line: 1371

void ENMYPLAN_RelocatePlanPositions(int slotID, _Position *offset)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  int iVar7;

  iVar7 = DAT_800d11c0 + slotID * 0x5e;
  bVar1 = *(byte *)(iVar7 + 0x58);
  uVar4 = (uint)bVar1;
  if ((((slotID != -1) && (slotID < 10)) && (bVar1 < 8)) && (bVar1 != 0))
  {
    iVar6 = uVar4 * 6 + 0x26;
    do
    {
      iVar6 = iVar6 + -6;
      uVar4 = uVar4 - 1;
      psVar5 = (short *)(iVar7 + iVar6);
      sVar2 = offset->y;
      sVar3 = offset->z;
      *psVar5 = *psVar5 + offset->x;
      psVar5[1] = psVar5[1] + sVar2;
      psVar5[2] = psVar5[2] + sVar3;
    } while (0 < (int)uVar4);
  }
  return;
}
