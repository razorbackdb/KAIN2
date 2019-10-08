#include "THISDUST.H"
#include "ENMYPLAN.H"

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

int ENMYPLAN_GetNextAvailablePlanningSlot(void)

{
  int iVar1;
  char *pcVar2;

  iVar1 = 0;
  pcVar2 = (char *)gameTrackerX.enemyPlanPool;
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

int ENMYPLAN_ReleasePlanningWorkspace(void)

{
  void *pvVar1;
  int iVar2;
  undefined *puVar3;

  pvVar1 = gameTrackerX.enemyPlanPool;
  iVar2 = ENMYPLAN_GetNextAvailablePlanningSlot();
  if (iVar2 != -1)
  {
    puVar3 = (undefined *)(iVar2 * 0x5e + (int)pvVar1);
    *puVar3 = 1;
    puVar3[1] = 0;
  }
  return iVar2;
}

void ENMYPLAN_GetInitializedPlanningWorkspaceFinal(int slotID)

{
  void *pvVar1;

  pvVar1 = gameTrackerX.enemyPlanPool;
  if ((-1 < slotID) && (slotID < 10))
  {
    PLANAPI_DeleteNodeFromPoolByUnit(2);
    PLANAPI_DeleteNodeFromPoolByUnit(3);
    *(undefined *)(slotID * 0x5e + (int)pvVar1) = 0;
  }
  return;
}

int ENMYPLAN_WayPointSkipped(_Position *currentPos, _Position *targetPos, _Position *nextTargetPos)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  u_int local_28;
  u_int local_24;

  iVar4 = (u_int)(u_short)targetPos->x - (u_int)(u_short)currentPos->x;
  sVar1 = targetPos->y - currentPos->y;
  sVar6 = targetPos->z - currentPos->z;
  local_28 = MATH3D_LengthXY(iVar4 * 0x10000 >> 0x10, (int)sVar1, (int)sVar6);
  iVar5 = (u_int)(u_short)nextTargetPos->x - (u_int)(u_short)targetPos->x;
  sVar2 = nextTargetPos->y - targetPos->y;
  sVar3 = nextTargetPos->z - targetPos->z;
  local_24 = MATH3D_LengthXY(iVar5 * 0x10000 >> 0x10, (int)sVar2, (int)sVar3);
  if ((int)local_28 < (int)local_24)
  {
    local_28 = local_28 ^ local_24;
    local_24 = local_24 ^ local_28;
    local_28 = local_28 ^ local_24;
  }
  return (u_int)((int)(((int)(local_28 * 0x2d4) >> 10) * local_24) <
                 (int)(short)iVar4 * (int)(short)iVar5 + (int)sVar1 * (int)sVar2 +
                     (int)sVar6 * (int)sVar3) ^
         1;
}

int ENMYPLAN_WayPointReached(_Position *currentPos, _Position *oldCurrentPos, _Position *targetPos)

{
  long lVar1;
  long lVar2;
  int iVar3;

  lVar1 = MATH3D_LengthXY((int)targetPos->x - (int)currentPos->x,
                          (int)targetPos->y - (int)currentPos->y,
                          (int)targetPos->z - (int)currentPos->z);
  lVar2 = MATH3D_LengthXY((int)targetPos->x - (int)oldCurrentPos->x,
                          (int)targetPos->y - (int)oldCurrentPos->y,
                          (int)targetPos->z - (int)oldCurrentPos->z);
  if (((lVar1 <= lVar2) || (iVar3 = 1, 399 < lVar1)) && (iVar3 = 1, 0x31 < lVar1))
  {
    iVar3 = 0;
  }
  return iVar3;
}

void ENMYPLAN_ReportCurrentGoalUnitID(EnemyPlanSlotData *planSlot)

{
  planSlot->state = '\0';
  PLANAPI_DeleteNodeFromPoolByUnit(2);
  PLANAPI_DeleteNodeFromPoolByUnit(3);
  return;
}

int ENMYPLAN_PathClear(_Position *pos, _Position *target)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  _Position *endPos;
  _Position local_10;

  iVar4 = (u_int)(u_short)target->x - (u_int)(u_short)pos->x;
  local_10.x = (short)iVar4;
  iVar1 = (u_int)(u_short)target->y - (u_int)(u_short)pos->y;
  local_10.y = (short)iVar1;
  iVar3 = (u_int)(u_short)target->z - (u_int)(u_short)pos->z;
  local_10.z = (short)iVar3;
  lVar2 = MATH3D_LengthXY(iVar4 * 0x10000 >> 0x10, iVar1 * 0x10000 >> 0x10, iVar3 * 0x10000 >> 0x10);
  endPos = pos;
  if (0x500 < lVar2)
  {
 lVar2) * 0x500;
 if (iVar1 < 0)
 {
   iVar1 = iVar1 + 0xfff;
 }
 lVar2) * 0x500;
 if (iVar3 < 0)
 {
   iVar3 = iVar3 + 0xfff;
 }
 lVar2) * 0x500;
 if (iVar4 < 0)
 {
   iVar4 = iVar4 + 0xfff;
 }
 local_10.x = (short)(iVar1 >> 0xc) + pos->x;
 local_10.y = (short)(iVar3 >> 0xc) + pos->y;
 local_10.z = (short)(iVar4 >> 0xc) + pos->z;
 endPos = &local_10;
  }
  iVar1 = PLANCOLL_DoesWaterPathUpExist(pos, endPos, 0);
  return iVar1;
}

int ENMYPLAN_MoveToTargetFinal(_Instance *instance, _Position *outputPos, int slotID, _Position *targetPos,
                               int validNodeTypes)

{
  u_char uVar1;
  byte bVar2;
  byte bVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  short sVar8;
  u_int uVar9;
  int iVar10;
  u_char *puVar11;
  EnemyPlanSlotData *planSlot;
  u_char *puVar12;
  byte bVar13;
  EnemyPlanData *planData;
  u_int uVar14;
  _Position *nextTargetPos;
  _Position *targetPos_00;

  pvVar4 = gameTrackerX.enemyPlanPool;
  gameTrackerX.plan_collide_override = '\x01';
  sVar8 = targetPos->z;
  *(u_char *)outputPos = *(u_char *)targetPos;
  outputPos->z = sVar8;
  if ((slotID == -1) || (9 < slotID))
  {
    gameTrackerX.plan_collide_override = '\x01';
    iVar5 = 2;
  }
  else
  {
    planSlot = (EnemyPlanSlotData *)((int)pvVar4 + slotID * 0x5e);
    bVar13 = planSlot->state;
    planData = &planSlot->planData;
    if (bVar13 == 1)
    {
      iVar5 = PLANSRCH_FindPathInGraph(&planSlot->startPos, planData, validNodeTypes);
      sVar8 = planSlot->timer + 1;
      planSlot->timer = sVar8;
      if (iVar5 == 0)
      {
        if (0x3c < sVar8)
        {
          planSlot->state = '\x04';
        }
      }
      else
      {
        planSlot->state = '\x02';
        planSlot->wayPointBeingServoedTo = '\x01';
      }
    }
    else
    {
      if (bVar13 < 2)
      {
        if (bVar13 == 0)
        {
          sVar8 = (instance->position).z;
          *(u_char *)&planSlot->startPos = *(u_char *)&instance->position;
          (planSlot->startPos).z = sVar8;
          sVar8 = targetPos->z;
          *(u_char *)&planSlot->goalPos = *(u_char *)targetPos;
          (planSlot->goalPos).z = sVar8;
          planSlot->timer = 0;
          iVar5 = PLANAPI_AddNodeOfTypeToPool(&planSlot->goalPos, 3);
          if (iVar5 != 0)
          {
            PLANAPI_AddNodeOfTypeToPool(&planSlot->startPos, 2);
            planSlot->state = '\x01';
          }
        }
      }
      else
      {
        if (bVar13 == 2)
        {
          bVar13 = planSlot->wayPointBeingServoedTo;
          uVar14 = (u_int)bVar13;
          puVar12 = planData->nodeSkipArray + uVar14;
          uVar1 = *puVar12;
          targetPos_00 = planData->wayPointArray + uVar14;
          sVar8 = targetPos_00->z;
          *(u_char *)outputPos = *(u_char *)targetPos_00;
          outputPos->z = sVar8;
          if (uVar1 == '\x02')
          {
            iVar5 = ENMYPLAN_PathClear(&instance->position, targetPos_00);
            if (((iVar5 == 0) && (*(char *)(&planData[-1].field_0x43 + uVar14) == '\x01')) &&
                (bVar13 != 0))
            {
              do
              {
                uVar9 = uVar14 - 1;
                if ((*(char *)(&planData[-1].field_0x43 + uVar14) != '\x01') || (uVar9 == 0))
                {
                  planSlot->wayPointBeingServoedTo = (char)uVar9;
                  planData->nodeSkipArray[uVar14] = '\x02';
                  break;
                }
                uVar14 = uVar9;
              } while (0 < (int)uVar9);
            }
          }
          else
          {
            iVar5 = (u_int)(byte)planSlot->wayPointBeingServoedTo + 1;
            iVar10 = iVar5 * 6 + 0x10;
            bVar13 = planData->nodeTypeArray[(u_int)(byte)planSlot->wayPointBeingServoedTo + 1] >> 3 & 3;
            if (((puVar12[8] >> 3 & 3) == bVar13) &&
                (bVar3 = puVar12[8] >> 3 & 3, *puVar12 != '\x02'))
            {
              do
              {
                bVar2 = bVar13;
                if (bVar3 != 0)
                  goto LAB_800967d8;
                nextTargetPos = (_Position *)(planData->nodeSkipArray + iVar10);
                iVar6 = ENMYPLAN_WayPointSkipped(&instance->position, targetPos_00, nextTargetPos);
                puVar11 = planData->nodeSkipArray + uVar14;
                if (iVar6 == 0)
                  break;
                if ((int)((u_int)(planSlot->planData).numWayPoints - 2) <=
                    (int)(u_int)(byte)planSlot->wayPointBeingServoedTo)
                  goto LAB_800967d8;
                *puVar12 = '\x01';
                puVar12 = puVar12 + 1;
                uVar14 = uVar14 + 1;
                iVar10 = iVar10 + 6;
                planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01';
                bVar13 = planData->nodeTypeArray[iVar5 + 1] >> 3 & 3;
                targetPos_00 = nextTargetPos;
                if (bVar2 != bVar13)
                  goto LAB_800967d8;
                puVar11 = planData->nodeSkipArray + uVar14;
                iVar5 = iVar5 + 1;
                bVar3 = bVar2;
              } while (*puVar12 != '\x02');
            }
            else
            {
            LAB_800967d8:
              puVar11 = planData->nodeSkipArray + uVar14;
            }
            *puVar11 = '\x02';
          }
          iVar5 = ENMYPLAN_WayPointReached(&instance->position, &planSlot->oldCurrentPos, targetPos_00);
          if ((iVar5 != 0) &&
              (planSlot->wayPointBeingServoedTo = planSlot->wayPointBeingServoedTo + '\x01',
               (int)((u_int)(planSlot->planData).numWayPoints - 1) <=
                   (int)(u_int)(byte)planSlot->wayPointBeingServoedTo))
          {
            planSlot->state = '\x03';
            PLANAPI_DeleteNodeFromPoolByUnit(2);
            PLANAPI_DeleteNodeFromPoolByUnit(3);
          }
        }
        else
        {
          if (bVar13 == 3)
          {
            lVar7 = MATH3D_LengthXY((int)targetPos->x - (int)(instance->position).x,
                                    (int)targetPos->y - (int)(instance->position).y,
                                    (int)targetPos->z - (int)(instance->position).z);
            if (0x400 < lVar7)
            {
              targetPos_00 = planData->wayPointArray + (byte)planSlot->wayPointBeingServoedTo;
              lVar7 = MATH3D_LengthXY((int)targetPos->x - (int)targetPos_00->x,
                                      (int)targetPos->y - (int)targetPos_00->y,
                                      (int)targetPos->z - (int)targetPos_00->z);
              if (0x400 < lVar7)
              {
                ENMYPLAN_ReportCurrentGoalUnitID(planSlot);
              }
            }
            sVar8 = targetPos->z;
            *(u_char *)outputPos = *(u_char *)targetPos;
            outputPos->z = sVar8;
          }
        }
      }
    }
    sVar8 = (instance->position).z;
    *(u_char *)&planSlot->oldCurrentPos = *(u_char *)&instance->position;
    (planSlot->oldCurrentPos).z = sVar8;
    switch (planSlot->state)
    {
    case '\0':
    case '\x01':
      iVar5 = 0;
      break;
    case '\x02':
      iVar5 = 1;
      break;
    case '\x03':
      iVar5 = 2;
      break;
    default:
      iVar5 = 3;
    }
    gameTrackerX.plan_collide_override = '\0';
  }
  return iVar5;
}

int ValidSlotAndState(EnemyPlanSlotData *pool, int slotID)

{
  if ((slotID != -1) && (slotID < 10))
  {
    return (u_int)((u_int)(byte)pool[slotID].state - 2 < 2);
  }
  return 0;
}

int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID)

{
  int iVar1;
  u_int uVar2;
  void *pvVar3;

  pvVar3 = gameTrackerX.enemyPlanPool;
  iVar1 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.enemyPlanPool, slotID);
  if (iVar1 == 0)
  {
    uVar2 = 0x40;
  }
  else
  {
    pvVar3 = (void *)((int)pvVar3 + slotID * 0x5e);
    uVar2 = (u_int) * (byte *)((int)pvVar3 + (u_int) * (byte *)((int)pvVar3 + 2) + 0x1e);
  }
  return uVar2;
}

int ENMYPLAN_GetPosOfNextWaypoint(int slotID, _Position *pos)

{
  short sVar1;
  short sVar2;
  int iVar3;
  void *pvVar4;
  short *psVar5;

  pvVar4 = gameTrackerX.enemyPlanPool;
  iVar3 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.enemyPlanPool, slotID);
  if (iVar3 != 0)
  {
    pvVar4 = (void *)((int)pvVar4 + slotID * 0x5e);
    psVar5 = (short *)((int)pvVar4 + (u_int) * (byte *)((int)pvVar4 + 2) * 6 + 0x26);
    sVar1 = psVar5[1];
    sVar2 = psVar5[2];
    pos->x = *psVar5;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return (u_int)(iVar3 != 0);
}

short ENMYPLAN_Replan(int slotID)

{
  if (slotID != -1)
  {
    return *(short *)((int)gameTrackerX.enemyPlanPool + slotID * 0x5e + 0x56);
  }
  return 0;
}
