#include "THISDUST.H"
#include "PLAN.H"

// decompiled code
// original method signature:
// long /*$ra*/ PLAN_CalcMinDistFromExistingNodes(struct _Position *pos /*$s0*/, struct PlanningNode *planningPool /*$a1*/, int distanceType /*$s1*/)
// line 129, offset 0x80097188
/* begin block 1 */
// Start line: 130
// Start offset: 0x80097188
// Variables:
// 		struct PlanningNode *closestNode; // $a2
// 		long minDist; // $v0
/* end block 1 */
// End offset: 0x80097210
// End Line: 148

/* begin block 2 */
// Start line: 258
/* end block 2 */
// End Line: 259

long PLAN_CalcMinDistFromExistingNodes(_Position *pos, PlanningNode *planningPool, int distanceType)

{
  PlanningNode *pPVar1;
  long lVar2;

  pPVar1 = PLANPOOL_GetClosestNode(pos, planningPool, (char)distanceType);
  if (pPVar1 == (PlanningNode *)0x0)
  {
    lVar2 = 0x7fffffff;
  }
  else
  {
    if (distanceType == 0)
    {
      lVar2 = MATH3D_LengthXY((int)pos->x - (int)(pPVar1->pos).x, (int)pos->y - (int)(pPVar1->pos).y);
    }
    else
    {
      lVar2 = MATH3D_LengthXYZ((int)pos->x - (int)(pPVar1->pos).x, (int)pos->y - (int)(pPVar1->pos).y, (int)pos->z - (int)(pPVar1->pos).z);
    }
  }
  return lVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool /*stack 0*/, struct _Position *playerPos /*$fp*/)
// line 158, offset 0x80097224
/* begin block 1 */
// Start line: 159
// Start offset: 0x80097224
// Variables:
// 		int i; // $s4
// 		int d; // stack offset -48
// 		long zDiff; // $v1
// 		struct _StreamUnit *streamUnit; // $s7

/* begin block 1.1 */
// Start line: 169
// Start offset: 0x80097288
// Variables:
// 		int numPlanMkrs; // $s5
// 		struct _PlanMkr *planMkr; // $s2
// 		long suID; // stack offset -44

/* begin block 1.1.1 */
// Start line: 181
// Start offset: 0x800972F8
// Variables:
// 		long nodeType; // $s0
// 		long nodeID; // $s3
/* end block 1.1.1 */
// End offset: 0x8009736C
// End Line: 203
/* end block 1.1 */
// End offset: 0x80097380
// End Line: 206
/* end block 1 */
// End offset: 0x80097440
// End Line: 221

/* begin block 2 */
// Start line: 316
/* end block 2 */
// End Line: 317

void PLAN_UpdatePlanMkrNodes(PlanningNode *planningPool, _Position *playerPos)

{
  ushort uVar1;
  long suID;
  long lVar2;
  PlanningNode *nodeToDelete;
  int type;
  ushort *puVar3;
  _PlanMkr *pos;
  uint id;
  int iVar4;
  int iVar5;
  Level **ppLVar6;
  STracker *pSVar7;
  int local_30;

  pSVar7 = &StreamTracker;
  ppLVar6 = &StreamTracker.StreamList[0].level;
  local_30 = 0;
  do
  {
    if ((*(short *)(ppLVar6 + -1) == 2) &&
        (suID = MEMPACK_MemoryValidFunc((char *)*ppLVar6), suID != 0))
    {
      suID = pSVar7->StreamList[0].StreamUnitID;
      pos = (*ppLVar6)->PlanMarkerList;
      iVar5 = (*ppLVar6)->NumberOfPlanMarkers;
      if ((iVar5 != 0) && (iVar4 = 0, 0 < iVar5))
      {
        puVar3 = (ushort *)&pos->id;
        do
        {
          /* WARNING: ptrarith problems */
          lVar2 = MATH3D_LengthXY((int)(pos->pos).x - (int)playerPos->x,
                                  (int)(short)puVar3[-2] - (int)playerPos->y);
          type = (int)playerPos->z - (int)(short)puVar3[1];
          if (type < 0)
          {
            type = -type;
          }
          if ((lVar2 < 8000) && (type < 4000))
          {
            uVar1 = *puVar3;
            id = (int)(short)*puVar3 & 0xffff0fff;
            if ((uVar1 & 0x1000) == 0)
            {
              type = 0xc;
              if (((((int)(short)*puVar3 & 0x8000U) == 0) && (type = 0x1c, (uVar1 & 0x4000) == 0)) && (type = 4, (uVar1 & 0x2000) != 0))
              {
                type = 0x14;
              }
              nodeToDelete = PLANPOOL_GetNodeWithID(planningPool, type, id, suID);
              if (nodeToDelete == (PlanningNode *)0x0)
              {
                PLANPOOL_AddNodeToPool((_Position *)pos, planningPool, (short)type, (short)id,
                                       pSVar7->StreamList[0].StreamUnitID);
              }
            }
          }
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 4;
          pos = pos + 1;
        } while (iVar4 < iVar5);
      }
    }
    ppLVar6 = ppLVar6 + 0x10;
    pSVar7 = (STracker *)(pSVar7->StreamList + 1);
    local_30 = local_30 + 1;
  } while (local_30 < 0x10);
  iVar5 = 0;
  nodeToDelete = planningPool;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      if ((nodeToDelete->nodeType & 7) == 4)
      {
        suID = MATH3D_LengthXY((int)(nodeToDelete->pos).x - (int)playerPos->x,
                               (int)(nodeToDelete->pos).y - (int)playerPos->y);
        iVar4 = (int)playerPos->z - (int)(nodeToDelete->pos).z;
        if (iVar4 < 0)
        {
          iVar4 = -iVar4;
        }
        if ((10000 < suID) || (5000 < iVar4))
        {
          PLANPOOL_DeleteNodeFromPool(nodeToDelete, planningPool);
        }
      }
      iVar5 = iVar5 + 1;
      nodeToDelete = nodeToDelete + 1;
    } while (iVar5 < (int)(uint) * (byte *)(poolManagementData + 1));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_UpdatePlayerNode(struct PlanningNode *planningPool /*$s3*/, struct _Position *playerPos /*$s2*/)
// line 226, offset 0x80097470
/* begin block 1 */
// Start line: 227
// Start offset: 0x80097470
// Variables:
// 		struct PlanningNode *playerNode; // $s1
// 		int nodePlacement; // stack offset -32
// 		int foundHit; // $s0
// 		struct _PlanCollideInfo pci; // stack offset -48

/* begin block 1.1 */
// Start line: 245
// Start offset: 0x800974D8
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a3
// 		struct _Position *_v0; // $s0
/* end block 1.1 */
// End offset: 0x800974D8
// End Line: 245
/* end block 1 */
// End offset: 0x800975A8
// End Line: 265

/* begin block 2 */
// Start line: 539
/* end block 2 */
// End Line: 540

void PLAN_UpdatePlayerNode(PlanningNode *planningPool, _Position *playerPos)

{
  PlanningNode *nodeToChange;
  int iVar1;
  long lVar2;
  _PlanCollideInfo local_30;
  ushort local_20[4];

  nodeToChange = PLANPOOL_GetFirstNodeOfSource(planningPool, '\x01');
  if (nodeToChange != (PlanningNode *)0x0)
  {
    iVar1 = PLANCOLL_CheckUnderwaterPoint(playerPos);
    if (iVar1 == -1)
    {
      local_30.collidePos.x = playerPos->x;
      local_30.collidePos.y = playerPos->y;
      local_30.collidePos.z = playerPos->z;
      iVar1 = PLANCOLL_FindTerrainHitFinal(&local_30, (int *)local_20, 0x100, -0x280, 0, 5);
      if (iVar1 == 0)
      {
        lVar2 = MATH3D_LengthXYZ((int)playerPos->x - (int)(nodeToChange->pos).x,
                                 (int)playerPos->y - (int)(nodeToChange->pos).y,
                                 (int)playerPos->z - (int)(nodeToChange->pos).z);
        if (12000 < lVar2)
        {
          PLANPOOL_ChangeNodePosition(playerPos, nodeToChange, planningPool);
          nodeToChange->nodeType = 1;
          nodeToChange->streamUnitID = (gameTrackerX.playerInstance)->currentStreamUnitID;
        }
      }
      else
      {
        PLANPOOL_ChangeNodePosition(&local_30.collidePos, nodeToChange, planningPool);
        nodeToChange->nodeType = (ushort)(((uint)local_20[0] & 3) << 3) | 1;
        nodeToChange->streamUnitID = local_30.StreamUnitID;
      }
    }
    else
    {
      PLANPOOL_ChangeNodePosition(playerPos, nodeToChange, planningPool);
      nodeToChange->nodeType = 0x19;
      nodeToChange->streamUnitID = iVar1;
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_AddRandomNode(struct PlanningNode *planningPool /*$s5*/, struct _Position *playerPos /*$s0*/)
// line 273, offset 0x800975c4
/* begin block 1 */
// Start line: 274
// Start offset: 0x800975C4
// Variables:
// 		int i; // $s2
// 		struct _PlanCollideInfo pci; // stack offset -56
// 		int successFlag; // $s4

/* begin block 1.1 */
// Start line: 282
// Start offset: 0x80097600
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $a0
// 		struct _Position *_v0; // $s1
/* end block 1.1 */
// End offset: 0x80097600
// End Line: 282

/* begin block 1.2 */
// Start line: 301
// Start offset: 0x8009771C

/* begin block 1.2.1 */
// Start line: 307
// Start offset: 0x8009775C
// Variables:
// 		struct _SVector normal; // stack offset -40
/* end block 1.2.1 */
// End offset: 0x800977AC
// End Line: 313
/* end block 1.2 */
// End offset: 0x800977AC
// End Line: 314
/* end block 1 */
// End offset: 0x800977AC
// End Line: 315

/* begin block 2 */
// Start line: 643
/* end block 2 */
// End Line: 644

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
        local_38.collidePos.x + -12000 + (short)iVar2 + (short)(iVar2 / 24000) * -24000;
    iVar2 = rand();
    iVar2 = ((uint)local_38.collidePos.y - 12000) + iVar2 % 24000;
    local_38.collidePos.y = (ushort)iVar2;
    lVar3 = MATH3D_LengthXYZ((int)playerPos->x - (int)local_38.collidePos.x,
                             (int)playerPos->y - (iVar2 * 0x10000 >> 0x10),
                             (int)playerPos->z - (int)local_38.collidePos.z);
    if ((lVar3 < 12000) &&
        (lVar3 = PLAN_CalcMinDistFromExistingNodes(&local_38.collidePos, planningPool, 0), 1000 < lVar3))
      break;
    iVar5 = iVar5 + 1;
    if (4 < iVar5)
    {
    LAB_80097710:
      if (bVar1)
      {
        iVar5 = PLANCOLL_FindTerrainHitFinal(&local_38, (int *)0x0, 0x100, -2000, 0, 0);
        if ((iVar5 == 0) &&
            (iVar5 = PLANCOLL_FindTerrainHitFinal(&local_38, (int *)0x0, 2000, 0, 0, 0), iVar5 == 0))
        {
          return;
        }
        pLVar4 = STREAM_GetLevelWithID(local_38.StreamUnitID);
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
  goto LAB_80097710;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_DeleteRandomNode(struct PlanningNode *planningPool /*$s0*/)
// line 321, offset 0x800977d0
/* begin block 1 */
// Start line: 322
// Start offset: 0x800977D0
/* end block 1 */
// End offset: 0x800977D0
// End Line: 322

/* begin block 2 */
// Start line: 773
/* end block 2 */
// End Line: 774

void PLAN_DeleteRandomNode(PlanningNode *planningPool)

{
  PlanningNode *nodeToDelete;

  nodeToDelete = PLANPOOL_GetFirstNodeOfSource(planningPool, '\0');
  PLANPOOL_DeleteNodeFromPool(nodeToDelete, planningPool);
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool /*$s3*/, struct _Position *playerPos /*$s2*/, int nodeSourceToCheck /*$s4*/, long removeDist /*$s5*/)
// line 332, offset 0x80097804
/* begin block 1 */
// Start line: 333
// Start offset: 0x80097804
// Variables:
// 		int i; // $s1
/* end block 1 */
// End offset: 0x800978B8
// End Line: 345

/* begin block 2 */
// Start line: 795
/* end block 2 */
// End Line: 796

/* begin block 3 */
// Start line: 799
/* end block 3 */
// End Line: 800

void PLAN_DeleteOutOfRangeNodesOfSource(PlanningNode *planningPool, _Position *playerPos, int nodeSourceToCheck,
                                        long removeDist)

{
  long lVar1;
  PlanningNode *nodeToDelete;
  int iVar2;

  iVar2 = 0;
  nodeToDelete = planningPool;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      if ((((uint)nodeToDelete->nodeType & 7) == nodeSourceToCheck) &&
          (lVar1 = MATH3D_LengthXYZ((int)playerPos->x - (int)(nodeToDelete->pos).x,
                                    (int)playerPos->y - (int)(nodeToDelete->pos).y,
                                    (int)playerPos->z - (int)(nodeToDelete->pos).z),
           removeDist < lVar1))
      {
        PLANPOOL_DeleteNodeFromPool(nodeToDelete, planningPool);
      }
      iVar2 = iVar2 + 1;
      nodeToDelete = nodeToDelete + 1;
    } while (iVar2 < (int)(uint) * (byte *)(poolManagementData + 1));
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool /*$a0*/, struct _Position *playerPos /*$a1*/)
// line 348, offset 0x800978dc
/* begin block 1 */
// Start line: 349
// Start offset: 0x800978DC
// Variables:
// 		int numNodeError; // $v0
/* end block 1 */
// End offset: 0x8009791C
// End Line: 360

/* begin block 2 */
// Start line: 835
/* end block 2 */
// End Line: 836

/* begin block 3 */
// Start line: 836
/* end block 3 */
// End Line: 837

void PLAN_AddOrRemoveRandomNodes(PlanningNode *planningPool, _Position *playerPos)

{
  int iVar1;

  iVar1 = (uint) * (byte *)(poolManagementData + 1) - 0x10;
  if (iVar1 < 0)
  {
    PLAN_AddRandomNode(planningPool, playerPos);
  }
  else
  {
    if (0 < iVar1)
    {
      PLAN_DeleteRandomNode(planningPool);
    }
  }
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_AddInitialNodes(struct PlanningNode *planningPool /*$s3*/, struct _Instance *player /*$s2*/)
// line 372, offset 0x8009792c
/* begin block 1 */
// Start line: 373
// Start offset: 0x8009792C
// Variables:
// 		struct _PlanCollideInfo pci; // stack offset -40

/* begin block 1.1 */
// Start line: 373
// Start offset: 0x8009792C
// Variables:
// 		short _x1; // $v0
// 		short _y1; // $v1
// 		short _z1; // $t0
// 		struct _Position *_v0; // $s0
// 		struct _Position *_v1; // $s1
/* end block 1.1 */
// End offset: 0x8009792C
// End Line: 373
/* end block 1 */
// End offset: 0x8009792C
// End Line: 373

/* begin block 2 */
// Start line: 884
/* end block 2 */
// End Line: 885

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
  *(undefined4 *)(poolManagementData + 2) = *(undefined4 *)&player->position;
  *(short *)(iVar2 + 6) = sVar1;
  return;
}

// decompiled code
// original method signature:
// void /*$ra*/ PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool /*$s1*/, struct _Instance *player /*$s2*/)
// line 385, offset 0x800979e8
/* begin block 1 */
// Start line: 386
// Start offset: 0x800979E8
/* end block 1 */
// End offset: 0x80097AAC
// End Line: 399

/* begin block 2 */
// Start line: 918
/* end block 2 */
// End Line: 919

/* begin block 3 */
// Start line: 921
/* end block 3 */
// End Line: 922

void PLAN_AddOrRemoveNodes(PlanningNode *planningPool, _Instance *player)

{
  short sVar1;
  int iVar2;
  long lVar3;
  _Position *playerPos;

  lVar3 = MATH3D_LengthXYZ((int)(player->position).x - (int)*(short *)(poolManagementData + 2),
                           (int)(player->position).y - (int)*(short *)(poolManagementData + 4),
                           (int)(player->position).z - (int)*(short *)(poolManagementData + 6));
  if (500 < lVar3)
  {
    playerPos = &player->position;
    PLAN_UpdatePlayerNode(planningPool, playerPos);
    PLAN_UpdatePlanMkrNodes(planningPool, playerPos);
    PLAN_DeleteOutOfRangeNodesOfSource(planningPool, playerPos, 0, (long)&DAT_00002ee0);
    PLAN_DeleteOutOfRangeNodesOfSource(planningPool, playerPos, 2, (long)&DAT_00002ee0);
    PLAN_DeleteOutOfRangeNodesOfSource(planningPool, playerPos, 3, (long)&DAT_00002ee0);
    iVar2 = poolManagementData;
    sVar1 = (player->position).z;
    *(undefined4 *)(poolManagementData + 2) = *(undefined4 *)&player->position;
    *(short *)(iVar2 + 6) = sVar1;
  }
  PLAN_AddOrRemoveRandomNodes(planningPool, &player->position);
  return;
}

// decompiled code
// original method signature:
// struct PlanningNode * /*$ra*/ PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool /*$a0*/)
// line 405, offset 0x80097ad0
/* begin block 1 */
// Start line: 406
// Start offset: 0x80097AD0
// Variables:
// 		int i; // $s2
// 		int numConnections; // $s1
// 		int minNumConnections; // $s4
// 		struct PlanningNode *nodeToReturn; // $s3
/* end block 1 */
// End offset: 0x80097B68
// End Line: 423

/* begin block 2 */
// Start line: 961
/* end block 2 */
// End Line: 962

/* begin block 3 */
// Start line: 966
/* end block 3 */
// End Line: 967

PlanningNode *PLAN_FindNodeMostInNeedOfConnectivityExpansion(PlanningNode *planningPool)

{
  int iVar1;
  uint uVar2;
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
           uVar2 != (uint) * (byte *)(poolManagementData + 1)))
      {
        pPVar4 = planningPool;
        iVar5 = iVar1;
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
    } while (iVar3 < (int)(uint) * (byte *)(poolManagementData + 1));
  }
  return pPVar4;
}
