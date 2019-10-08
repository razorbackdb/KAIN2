#include "THISDUST.H"
#include "PLAN.H"

long PLAN_CalcMinDistFromExistingNodes(_Position *pos, PlanningNode *planningPool, char distanceType)

{
  PlanningNode *pPVar1;
  long lVar2;

  pPVar1 = PLANPOOL_GetNodeByPosition(pos, planningPool, distanceType);
  if (pPVar1 == (PlanningNode *)0x0)
  {
    lVar2 = 0x7fffffff;
  }
  else
  {
    if (distanceType == '\0')
    {
      lVar2 = MATH3D_LengthXYZ((int)pos->x - (int)(pPVar1->pos).x, (int)pos->y - (int)(pPVar1->pos).y);
    }
    else
    {
      lVar2 = MATH3D_LengthXY((int)pos->x - (int)(pPVar1->pos).x, (int)pos->y - (int)(pPVar1->pos).y,
                              (int)pos->z - (int)(pPVar1->pos).z);
    }
  }
  return lVar2;
}

void PLAN_UpdatePlanMkrNodes(PlanningNode *planningPool, _Position *playerPos)

{
  u_short uVar1;
  long lVar2;
  PlanningNode *nodeToDelete;
  int iVar3;
  short type;
  u_short *puVar4;
  _PlanMkr *pos;
  int iVar5;
  int iVar6;
  Level **ppLVar7;
  STracker *pSVar8;
  int local_30;

  pSVar8 = &StreamTracker;
  ppLVar7 = &StreamTracker.StreamList[0].level;
  local_30 = 0;
  do
  {
    if ((*(short *)(ppLVar7 + -1) == 2) &&
        (lVar2 = MEMPACK_ReportMemory((char *)*ppLVar7), lVar2 != 0))
    {
      iVar6 = (*ppLVar7)->NumberOfPlanMarkers;
      pos = (*ppLVar7)->PlanMarkerList;
      if ((iVar6 != 0) && (iVar5 = 0, 0 < iVar6))
      {
        puVar4 = (u_short *)&pos->id;
        do
        {
          lVar2 = MATH3D_LengthXYZ((int)(pos->pos).x - (int)playerPos->x,
                                   (int)(short)puVar4[-2] - (int)playerPos->y);
          iVar3 = (int)playerPos->z - (int)(short)puVar4[-1];
          if (iVar3 < 0)
          {
            iVar3 = -iVar3;
          }
          if ((lVar2 < 8000) && (iVar3 < 4000))
          {
            uVar1 = *puVar4;
            if ((uVar1 & 0x1000) == 0)
            {
              type = 0xc;
              if ((((uVar1 & 0x8000) == 0) && (type = 0x1c, (uVar1 & 0x4000) == 0)) &&
                  (type = 4, (uVar1 & 0x2000) != 0))
              {
                type = 0x14;
              }
              nodeToDelete = PLANPOOL_GetNodeWithID(planningPool, type, uVar1 & 0xfff);
              if (nodeToDelete == (PlanningNode *)0x0)
              {
                PLANPOOL_AddNodeToPool((_Position *)pos, planningPool, type, uVar1 & 0xfff,
                                       pSVar8->StreamList[0].StreamUnitID);
              }
            }
          }
          iVar5 = iVar5 + 1;
          puVar4 = puVar4 + 4;
          pos = pos + 1;
        } while (iVar5 < iVar6);
      }
    }
    ppLVar7 = ppLVar7 + 0x10;
    pSVar8 = (STracker *)(pSVar8->StreamList + 1);
    local_30 = local_30 + 1;
  } while (local_30 < 0x10);
  iVar6 = 0;
  nodeToDelete = planningPool;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      if ((nodeToDelete->nodeType & 7) == 4)
      {
        lVar2 = MATH3D_LengthXYZ((int)(nodeToDelete->pos).x - (int)playerPos->x,
                                 (int)(nodeToDelete->pos).y - (int)playerPos->y);
        iVar5 = (int)playerPos->z - (int)(nodeToDelete->pos).z;
        if (iVar5 < 0)
        {
          iVar5 = -iVar5;
        }
        if ((10000 < lVar2) || (5000 < iVar5))
        {
          PLANAPI_DeleteNodesFromPoolByType(nodeToDelete, planningPool);
        }
      }
      iVar6 = iVar6 + 1;
      nodeToDelete = nodeToDelete + 1;
    } while (iVar6 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return;
}

void PLAN_UpdatePlanMkrNodes(PlanningNode *planningPool, _Position *playerPos)

{
  u_short uVar1;
  PlanningNode *nodeToChange;
  int iVar2;
  long lVar3;
  _PlanCollideInfo _Stack48;
  u_short local_20[4];

  nodeToChange = PLANPOOL_GetClosestNode(planningPool, '\x01');
  if (nodeToChange != (PlanningNode *)0x0)
  {
    iVar2 = PLANCOLL_CheckUnderwaterPoint(playerPos);
    if (iVar2 == -1)
    {
      _Stack48.collidePos.x = playerPos->x;
      _Stack48.collidePos.y = playerPos->y;
      _Stack48.collidePos.z = playerPos->z;
      iVar2 = PLANCOLL_FindTerrainHitFinal(&_Stack48, (int *)local_20, 0x100, -0x280, 0, 5);
      if (iVar2 == 0)
      {
        lVar3 = MATH3D_LengthXY((int)playerPos->x - (int)(nodeToChange->pos).x,
                                (int)playerPos->y - (int)(nodeToChange->pos).y,
                                (int)playerPos->z - (int)(nodeToChange->pos).z);
        if (lVar3 < 0x2ee1)
        {
          return;
        }
        PLANPOOL_ChangeNodePosition(playerPos, nodeToChange, planningPool);
        uVar1 = 1;
      }
      else
      {
        PLANPOOL_ChangeNodePosition(&_Stack48.collidePos, nodeToChange, planningPool);
        uVar1 = (u_short)(((u_int)local_20[0] & 3) << 3) | 1;
      }
    }
    else
    {
      PLANPOOL_ChangeNodePosition(playerPos, nodeToChange, planningPool);
      uVar1 = 0x19;
    }
    nodeToChange->nodeType = uVar1;
  }
  return;
}

void PLAN_AddRandomNode(PlanningNode *planningPool, _Position *playerPos)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  Level *pLVar4;
  int iVar5;
  _PlanCollideInfo local_38;
  _SVector _Stack40;

  bVar1 = false;
  iVar5 = 0;
  while (true)
  {
    local_38.collidePos.x = playerPos->x;
    local_38.collidePos.y = playerPos->y;
    local_38.collidePos.z = playerPos->z;
    iVar2 = rand();
    local_38.collidePos.x =
 24000) * -24000;
    iVar2 = rand();
    iVar2 = ((u_int)local_38.collidePos.y - 12000) + iVar2 % 24000;
    local_38.collidePos.y = (u_short)iVar2;
    lVar3 = MATH3D_LengthXY((int)playerPos->x - (int)local_38.collidePos.x,
                            (int)playerPos->y - (iVar2 * 0x10000 >> 0x10),
                            (int)playerPos->z - (int)local_38.collidePos.z);
    if ((lVar3 < 12000) &&
        (lVar3 = PLAN_CalcMinDistFromExistingNodes(&local_38.collidePos, planningPool, '\0'),
         1000 < lVar3))
      break;
    iVar5 = iVar5 + 1;
    if (4 < iVar5)
    {
    LAB_80097070:
      if (bVar1)
      {
        iVar5 = PLANCOLL_FindTerrainHitFinal(&local_38, (int *)0x0, 0x100, -2000, 0, 0);
        if ((iVar5 == 0) &&
            (iVar5 = PLANCOLL_FindTerrainHitFinal(&local_38, (int *)0x0, 2000, 0, 0, 0), iVar5 == 0))
        {
          return;
        }
        pLVar4 = STREAM_GetWaterZLevel(local_38.StreamUnitID);
        COLLIDE_GetNormal((local_38.tFace)->normal, (short *)pLVar4->terrain->normalList, &_Stack40);
        if (0x800 < _Stack40.z)
        {
          PLANPOOL_AddNodeToPool(&local_38.collidePos, planningPool, 0, 0, local_38.StreamUnitID);
        }
      }
      return;
    }
  }
  bVar1 = true;
  goto LAB_80097070;
}

void PLAN_AddRandomNode(PlanningNode *planningPool)

{
  PlanningNode *nodeToDelete;

  nodeToDelete = PLANPOOL_GetClosestNode(planningPool, '\0');
  PLANAPI_DeleteNodesFromPoolByType(nodeToDelete, planningPool);
  return;
}

void PLAN_DeleteOutOfRangeNodesOfSource(PlanningNode *planningPool, _Position *playerPos, char nodeSourceToCheck,
                                        long removeDist)

{
  long lVar1;
  PlanningNode *nodeToDelete;
  int iVar2;

  iVar2 = 0;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    nodeToDelete = planningPool;
    do
    {
      if ((((u_int)nodeToDelete->nodeType & 7) == (u_int)(byte)nodeSourceToCheck) &&
          (lVar1 = MATH3D_LengthXY((int)playerPos->x - (int)(nodeToDelete->pos).x,
                                   (int)playerPos->y - (int)(nodeToDelete->pos).y,
                                   (int)playerPos->z - (int)(nodeToDelete->pos).z),
           removeDist < lVar1))
      {
        PLANAPI_DeleteNodesFromPoolByType(nodeToDelete, planningPool);
      }
      iVar2 = iVar2 + 1;
      nodeToDelete = nodeToDelete + 1;
    } while (iVar2 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return;
}

void PLAN_AddOrRemoveRandomNodes(PlanningNode *planningPool, _Position *playerPos)

{
  int iVar1;

  iVar1 = (u_int) * (byte *)(poolManagementData + 1) - 0x10;
  if (iVar1 < 0)
  {
    PLAN_AddRandomNode(planningPool, playerPos);
  }
  else
  {
    if (0 < iVar1)
    {
      PLAN_AddRandomNode(planningPool);
    }
  }
  return;
}

void PLAN_AddInitialNodes(PlanningNode *planningPool, _Instance *player)

{
  short sVar1;
  int iVar2;
  _PlanCollideInfo _Stack40;

  _Stack40.collidePos.x = (player->position).x;
  _Stack40.collidePos.y = (player->position).y;
  _Stack40.collidePos.z = (player->position).z;
  PLANCOLL_FindTerrainHitFinal(&_Stack40, (int *)0x0, 0x100, -0x400, 0, 0);
  PLANPOOL_AddNodeToPool(&_Stack40.collidePos, planningPool, 1, 0, player->currentStreamUnitID);
  PLAN_UpdatePlanMkrNodes(planningPool, &player->position);
  iVar2 = poolManagementData;
  sVar1 = (player->position).z;
  *(u_char *)(poolManagementData + 2) = *(u_char *)&player->position;
  *(short *)(iVar2 + 6) = sVar1;
  return;
}

void PLAN_DeleteRandomNode(PlanningNode *planningPool, _Instance *player)

{
  short sVar1;
  int iVar2;
  long lVar3;
  _Position *playerPos;

  lVar3 = MATH3D_LengthXY((int)(player->position).x - (int)*(short *)(poolManagementData + 2),
                          (int)(player->position).y - (int)*(short *)(poolManagementData + 4),
                          (int)(player->position).z - (int)*(short *)(poolManagementData + 6));
  if (500 < lVar3)
  {
    playerPos = &player->position;
    PLAN_UpdatePlanMkrNodes(planningPool, playerPos);
    PLAN_UpdatePlanMkrNodes(planningPool, playerPos);
    PLAN_DeleteOutOfRangeNodesOfSource(planningPool, playerPos, '\0', (long)&DAT_00002ee0);
    PLAN_DeleteOutOfRangeNodesOfSource(planningPool, playerPos, '\x02', (long)&DAT_00002ee0);
    PLAN_DeleteOutOfRangeNodesOfSource(planningPool, playerPos, '\x03', (long)&DAT_00002ee0);
    iVar2 = poolManagementData;
    sVar1 = (player->position).z;
    *(u_char *)(poolManagementData + 2) = *(u_char *)&player->position;
    *(short *)(iVar2 + 6) = sVar1;
  }
  PLAN_AddOrRemoveRandomNodes(planningPool, &player->position);
  return;
}

PlanningNode *PLAN_FindNodeMostInNeedOfConnectivityExpansion(PlanningNode *planningPool)

{
  int iVar1;
  u_int uVar2;
  int iVar3;
  PlanningNode *pPVar4;
  int iVar5;

  iVar5 = 0xffff;
  iVar3 = 0;
  pPVar4 = (PlanningNode *)0x0;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      iVar1 = PLANPOOL_NumConnectionsForNode(planningPool);
      if ((iVar1 < iVar5) &&
          (uVar2 = PLANPOOL_NumConnectionsExaminedForNode(planningPool),
           uVar2 != (u_int) * (byte *)(poolManagementData + 1)))
      {
        pPVar4 = planningPool;
        iVar5 = iVar1;
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
    } while (iVar3 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return pPVar4;
}
