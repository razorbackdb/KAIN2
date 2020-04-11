
#include "PLANAPI.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode /*$a0*/, struct EnemyPlanData *planData /*$s1*/, struct PlanningNode *planningPool /*$s2*/)
 // line 131, offset 0x800974ec
	/* begin block 1 */
		// Start line: 132
		// Start offset: 0x800974EC
		// Variables:
	// 		struct PlanningNode *currentNode; // $s0
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80097588
	// End Line: 151

	/* begin block 2 */
		// Start line: 262
	/* end block 2 */
	// End Line: 263

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_ConvertPlanIntoEnmyPlanDataFormat
               (PlanningNode *goalNode,EnemyPlanData *planData,PlanningNode *planningPool)

{
  uchar uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uchar *puVar5;
  
  uVar3 = PLANPOOL_NumNodesInPlan(goalNode,planningPool);
  planData->numWayPoints = (uchar)uVar3;
  iVar4 = (uVar3 & 0xff) - 1;
  if (-1 < iVar4) {
    puVar5 = planData->nodeSkipArray + iVar4 * 6;
    do {
      if (iVar4 < 8) {
        sVar2 = (goalNode->pos).z;
        *(undefined4 *)(puVar5 + 0x10) = *(undefined4 *)&goalNode->pos;
        *(short *)(puVar5 + 0x14) = sVar2;
        uVar1 = *(uchar *)&goalNode->nodeType;
        planData->nodeSkipArray[iVar4] = '\0';
        (planData->nodeSkipArray + iVar4)[8] = uVar1;
      }
      puVar5 = puVar5 + -6;
      iVar4 = iVar4 + -1;
      goalNode = planningPool + goalNode->parent;
    } while (-1 < iVar4);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_FindPathBetweenNodes(struct PlanningNode *startNode /*$v0*/, struct PlanningNode *goalNode /*$v1*/, struct EnemyPlanData *planData /*$s3*/, int validNodeTypes /*$a3*/)
 // line 157, offset 0x800975a0
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x800975A0
		// Variables:
	// 		struct PlanningNode *planningPool; // $s1
	// 		int successFlag; // $s2
	/* end block 1 */
	// End offset: 0x80097608
	// End Line: 172

	/* begin block 2 */
		// Start line: 317
	/* end block 2 */
	// End Line: 318

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_FindPathBetweenNodes
              (PlanningNode *startNode,PlanningNode *goalNode,EnemyPlanData *planData,
              int validNodeTypes)

{
  PlanningNode *planningPool;
  PlanningNode *goalNode_00;
  int iVar1;
  
  planningPool = DAT_800d22e4;
  iVar1 = 0;
  if (((startNode != (PlanningNode *)0x0) && (goalNode != (PlanningNode *)0x0)) &&
     (goalNode_00 = PLANSRCH_FindPathInGraph(DAT_800d22e4,startNode,goalNode,validNodeTypes),
     goalNode_00 != (PlanningNode *)0x0)) {
    PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(goalNode_00,planData,planningPool);
    iVar1 = 1;
    planData->goalUnitID = *(short *)&goalNode_00->streamUnitID;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_DoTimingCalcsAndDrawing(long startTime /*$a0*/, struct PlanningNode *planningPool /*$s2*/)
 // line 177, offset 0x80097628
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x80097628
		// Variables:
	// 		int i; // $a1
	// 		long minTime; // $s1
	// 		long maxTime; // $s0

		/* begin block 1.1 */
			// Start line: 199
			// Start offset: 0x800976D4
		/* end block 1.1 */
		// End offset: 0x80097730
		// End Line: 221
	/* end block 1 */
	// End offset: 0x80097730
	// End Line: 222

	/* begin block 2 */
		// Start line: 361
	/* end block 2 */
	// End Line: 362

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_DoTimingCalcsAndDrawing(long startTime,PlanningNode *planningPool)

{
  ulong uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0x7fffffff;
  iVar5 = 0;
  uVar1 = TIMER_TimeDiff(startTime);
  iVar4 = 0;
  piVar3 = (int *)&poolManagementDataStorage.peakPos.z;
  *(ulong *)(&poolManagementDataStorage.peakPos.z + timerIndex * 2) = uVar1;
  do {
    iVar2 = *piVar3;
    if (iVar2 < iVar6) {
      iVar6 = iVar2;
    }
    if (iVar5 < iVar2) {
      iVar5 = iVar2;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 10);
  timerIndex = timerIndex + 1;
  if (9 < timerIndex) {
    timerIndex = 0;
  }
  if ((DAT_800d2190 & 0x10) != 0) {
    PLANPOOL_NumberOfNodesOfType(planningPool,'\x04');
    PLANPOOL_NumberOfNodesOfType(planningPool,'\f');
    PLANPOOL_NumberOfNodesOfType(planningPool,'\x14');
    PLANPOOL_NumberOfNodesOfType(planningPool,'\x1c');
    PLANPOOL_NumberOfNodesOfSource(planningPool,'\0');
    PLANPOOL_NumberOfNodesOfSource(planningPool,'\x02');
    PLANPOOL_NumberOfNodesOfSource(planningPool,'\x03');
    PLANPOOL_NumberOfNodesOfSource(planningPool,'\x01');
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_AddNodeOfTypeToPool(struct _Position *pos /*$s0*/, int type /*$s2*/)
 // line 269, offset 0x80097748
	/* begin block 1 */
		// Start line: 270
		// Start offset: 0x80097748
		// Variables:
	// 		struct PlanningNode *planningPool; // $s1
	// 		int foundHit; // $v1
	// 		int nodePlacement; // stack offset -24
	// 		struct _PlanCollideInfo pci; // stack offset -40

		/* begin block 1.1 */
			// Start line: 284
			// Start offset: 0x80097794
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $s0
		/* end block 1.1 */
		// End offset: 0x80097794
		// End Line: 284
	/* end block 1 */
	// End offset: 0x80097810
	// End Line: 294

	/* begin block 2 */
		// Start line: 552
	/* end block 2 */
	// End Line: 553

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_AddNodeOfTypeToPool(_Position *pos,int type)

{
  PlanningNode *planningPool;
  int iVar1;
  ushort nodeType;
  _PlanCollideInfo local_28;
  ushort local_18 [4];
  
  planningPool = DAT_800d22e4;
  iVar1 = PLANCOLL_CheckUnderwaterPoint(pos);
  if (iVar1 == -1) {
    local_28.collidePos.x = pos->x;
    local_28.collidePos.y = pos->y;
    local_28.collidePos.z = pos->z;
    pos = &local_28.collidePos;
    iVar1 = PLANCOLL_FindTerrainHitFinal(&local_28,(int *)local_18,0x100,-0x280,0,5);
    if (iVar1 == 0) {
      return 0;
    }
    nodeType = (ushort)(((uint)local_18[0] & 3) << 3) | (ushort)type & 7;
  }
  else {
    nodeType = (ushort)type & 7 | 0x18;
    local_28.StreamUnitID = iVar1;
  }
  PLANPOOL_AddNodeToPool(pos,planningPool,nodeType,0,local_28.StreamUnitID);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_DeleteNodesFromPoolByType(int nodeSource /*$s3*/)
 // line 306, offset 0x80097828
	/* begin block 1 */
		// Start line: 307
		// Start offset: 0x80097828
		// Variables:
	// 		struct PlanningNode *planningPool; // $s2
	// 		struct PlanningNode *nodeToDelete; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x800978A8
	// End Line: 324

	/* begin block 2 */
		// Start line: 609
	/* end block 2 */
	// End Line: 610

	/* begin block 3 */
		// Start line: 626
	/* end block 3 */
	// End Line: 627

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_DeleteNodesFromPoolByType(int nodeSource)

{
  PlanningNode *planningPool;
  PlanningNode *nodeToDelete;
  int iVar1;
  
  planningPool = DAT_800d22e4;
  iVar1 = 0;
  nodeToDelete = DAT_800d22e4;
  if (poolManagementData->numNodesInPool != '\0') {
    do {
      if (((uint)nodeToDelete->nodeType & 7) == nodeSource) {
        PLANPOOL_DeleteNodeFromPool(nodeToDelete,planningPool);
      }
      else {
        iVar1 = iVar1 + 1;
        nodeToDelete = nodeToDelete + 1;
      }
    } while (iVar1 < (int)(uint)poolManagementData->numNodesInPool);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID /*$s3*/)
 // line 327, offset 0x800978c4
	/* begin block 1 */
		// Start line: 328
		// Start offset: 0x800978C4
		// Variables:
	// 		struct PlanningNode *planningPool; // $s2
	// 		struct PlanningNode *nodeToDelete; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80097940
	// End Line: 347

	/* begin block 2 */
		// Start line: 683
	/* end block 2 */
	// End Line: 684

	/* begin block 3 */
		// Start line: 688
	/* end block 3 */
	// End Line: 689

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID)

{
  PlanningNode *planningPool;
  PlanningNode *nodeToDelete;
  int iVar1;
  
  planningPool = DAT_800d22e4;
  iVar1 = 0;
  nodeToDelete = DAT_800d22e4;
  if (poolManagementData->numNodesInPool != '\0') {
    do {
      if (nodeToDelete->streamUnitID == streamUnitID) {
        PLANPOOL_DeleteNodeFromPool(nodeToDelete,planningPool);
      }
      else {
        iVar1 = iVar1 + 1;
        nodeToDelete = nodeToDelete + 1;
      }
    } while (iVar1 < (int)(uint)poolManagementData->numNodesInPool);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_FindPathInGraphToTarget(struct _Position *startPos /*$a0*/, struct EnemyPlanData *planData /*$s1*/, int validNodeTypes /*$s2*/)
 // line 388, offset 0x8009795c
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x8009795C
		// Variables:
	// 		struct PlanningNode *planningPool; // $s0
	// 		struct PlanningNode *startNode; // $s0
	/* end block 1 */
	// End offset: 0x8009795C
	// End Line: 389

	/* begin block 2 */
		// Start line: 827
	/* end block 2 */
	// End Line: 828

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_FindPathInGraphToTarget(_Position *startPos,EnemyPlanData *planData,int validNodeTypes)

{
  PlanningNode *startNode;
  PlanningNode *planningPool;
  int iVar1;
  
  planningPool = DAT_800d22e4;
  startNode = PLANPOOL_GetNodeByPosition(startPos,DAT_800d22e4);
  planningPool = PLANPOOL_GetFirstNodeOfSource(planningPool,'\x03');
  iVar1 = PLANAPI_FindPathBetweenNodes(startNode,planningPool,planData,validNodeTypes);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_InitPlanning(void *planningPool /*$a0*/)
 // line 405, offset 0x800979c0
	/* begin block 1 */
		// Start line: 407
		// Start offset: 0x800979C0
		// Variables:
	// 		int i; // $a1
	// 		int j; // $a0
	/* end block 1 */
	// End offset: 0x80097A3C
	// End Line: 439

	/* begin block 2 */
		// Start line: 862
	/* end block 2 */
	// End Line: 863

	/* begin block 3 */
		// Start line: 863
	/* end block 3 */
	// End Line: 864

	/* begin block 4 */
		// Start line: 885
	/* end block 4 */
	// End Line: 886

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_InitPlanning(void *planningPool)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  poolManagementDataStorage.expansionNode2 = (PlanningNode *)((int)planningPool + 0x380);
  poolManagementData = &poolManagementDataStorage;
  poolManagementDataStorage.state = '\0';
  poolManagementDataStorage.numNodesInPool = '\0';
  do {
    iVar3 = 0;
    iVar1 = 0;
    do {
      iVar3 = iVar3 + 1;
      *(undefined2 *)((int)&poolManagementDataStorage.expansionNode2[iVar4 * 2].pos.x + iVar1) = 0;
      iVar1 = iVar3 * 2;
    } while (iVar3 < 0x20);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  iVar4 = 9;
  puVar2 = &DAT_800d56f8;
  do {
    *puVar2 = 0;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + -1;
  } while (-1 < iVar4);
  timerIndex = 0;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ PLANAPI_PairType(struct PlanningNode *node1 /*$a0*/, struct PlanningNode *node2 /*$a1*/)
 // line 446, offset 0x80097a48
	/* begin block 1 */
		// Start line: 448
		// Start offset: 0x80097A48
		// Variables:
	// 		short placement1; // $a2
	// 		short placement2; // $a1
	/* end block 1 */
	// End offset: 0x80097A84
	// End Line: 457

	/* begin block 2 */
		// Start line: 964
	/* end block 2 */
	// End Line: 965

	/* begin block 3 */
		// Start line: 965
	/* end block 3 */
	// End Line: 966

	/* begin block 4 */
		// Start line: 969
	/* end block 4 */
	// End Line: 970

/* File: C:\kain2\game\PLAN\PLANAPI.C */

short PLANAPI_PairType(PlanningNode *node1,PlanningNode *node2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  
  uVar2 = (uint)(node1->nodeType >> 3) & 3;
  _uVar3 = (uint)(node2->nodeType >> 3) & 3;
  uVar3 = (ushort)_uVar3;
  if (_uVar3 < uVar2) {
    uVar1 = _uVar3 ^ uVar2 ^ _uVar3;
    uVar3 = (ushort)uVar1;
    uVar2 = uVar2 ^ _uVar3 ^ uVar1;
  }
  return (short)(uVar3 | (ushort)(uVar2 << 8));
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_PassThroughHit(struct PlanningNode *node1 /*$a0*/, struct PlanningNode *node2 /*$a1*/)
 // line 462, offset 0x80097a90
	/* begin block 1 */
		// Start line: 464
		// Start offset: 0x80097A90
		// Variables:
	// 		int src1; // $a0
	// 		int src2; // $v1
	// 		int res; // $v1
	/* end block 1 */
	// End offset: 0x80097AF4
	// End Line: 485

	/* begin block 2 */
		// Start line: 997
	/* end block 2 */
	// End Line: 998

	/* begin block 3 */
		// Start line: 998
	/* end block 3 */
	// End Line: 999

	/* begin block 4 */
		// Start line: 1002
	/* end block 4 */
	// End Line: 1003

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_PassThroughHit(PlanningNode *node1,PlanningNode *node2)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_800d220c < 0) {
    uVar2 = (uint)node1->nodeType & 7;
    uVar1 = (uint)node2->nodeType & 7;
    if (uVar1 < uVar2) {
      uVar2 = uVar2 ^ uVar1;
      uVar1 = uVar1 ^ uVar2;
      uVar2 = uVar2 ^ uVar1;
    }
    uVar1 = uVar2 << 8 | uVar1;
    if (((uVar1 == 0x104) || (uVar1 == 0x304)) || (uVar1 == 0x204)) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_UpdatePlanningDatabase(struct GameTracker *gameTracker /*$a0*/, struct _Instance *player /*$s0*/)
 // line 491, offset 0x80097afc
	/* begin block 1 */
		// Start line: 492
		// Start offset: 0x80097AFC
		// Variables:
	// 		struct PlanningNode *planningPool; // $s3
	// 		struct PlanningNode *node1; // $s0
	// 		struct PlanningNode *node2; // $s1
	// 		long startTime; // $s4
	// 		int pathExistsAbove; // $v0
	// 		int pathExistsBelow; // $v0

		/* begin block 1.1 */
			// Start line: 534
			// Start offset: 0x80097C8C
			// Variables:
		// 		struct PlanningNode *temp; // $v0
		/* end block 1.1 */
		// End offset: 0x80097C98
		// End Line: 538
	/* end block 1 */
	// End offset: 0x80097DF8
	// End Line: 636

	/* begin block 2 */
		// Start line: 1056
	/* end block 2 */
	// End Line: 1057

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_UpdatePlanningDatabase(GameTracker *gameTracker,_Instance *player)

{
  byte bVar1;
  PoolManagementData *pPVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  PlanningNode *startNode;
  long lVar6;
  int passThroughHit;
  uint uVar7;
  PlanningNode *node1;
  PlanningNode *node1_00;
  PlanningNode *node2;
  PlanningNode *planningPool;
  int local_20;
  
  planningPool = (PlanningNode *)gameTracker->planningPool;
  uVar5 = GetRCnt(0xf2000000);
  DAT_800d2296 = 1;
  uVar7 = gameTimer << 0x10;
  bVar1 = poolManagementData->state;
  if (bVar1 == 1) {
    PLAN_AddOrRemoveNodes(planningPool,player);
    cVar3 = '\x02';
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        PLAN_AddInitialNodes(planningPool,player);
        poolManagementData->state = '\x01';
        goto LAB_80097dfc;
      }
    }
    else {
      if (bVar1 == 2) {
        startNode = (PlanningNode *)PLAN_FindNodeMostInNeedOfConnectivityExpansion(planningPool);
        node2 = (PlanningNode *)
                PLANPOOL_GetClosestUnexploredValidNeighbor((PlanningNode *)startNode,planningPool);
        poolManagementData->state = '\x01';
        if ((startNode == (PlanningNode *)0x0) || (node2 == (PlanningNode *)0x0)) goto LAB_80097dfc;
        lVar6 = MATH3D_LengthXYZ((int)(startNode->pos).x - (int)(node2->pos).x,
                                 (int)(startNode->pos).y - (int)(node2->pos).y,
                                 (int)(startNode->pos).z - (int)(node2->pos).z);
        node1 = startNode;
        if (lVar6 < 6000) {
          uVar4 = PLANAPI_PairType((PlanningNode *)startNode,(PlanningNode *)node2);
          *(ushort *)&poolManagementData->distanceMatrix = uVar4;
          if (uVar4 == 3) {
            if ((startNode->cost >> 3 & 3) == 3) {
              node1 = node2;
              node2 = startNode;
            }
            passThroughHit = PLANAPI_PassThroughHit((PlanningNode *)node1,(PlanningNode *)node2);
            passThroughHit =
                 PLANCOLL_DoesWaterPathUpExist
                           ((_Position *)node1,(_Position *)node2,0,
                            (_Position *)((int)&poolManagementData->distanceMatrix + 2),
                            passThroughHit);
          }
          else {
            if (uVar4 < 4) {
              if (uVar4 == 0) goto LAB_80097c5c;
LAB_80097cc8:
              passThroughHit =
                   PLANAPI_PassThroughHit((PlanningNode *)startNode,(PlanningNode *)node2);
              local_20 = 0;
            }
            else {
              if (uVar4 != 0x202) goto LAB_80097cc8;
LAB_80097c5c:
              passThroughHit =
                   PLANAPI_PassThroughHit((PlanningNode *)startNode,(PlanningNode *)node2);
              local_20 = 0x100;
            }
            passThroughHit =
                 PLANCOLL_DoesLOSExistFinal
                           ((_Position *)startNode,(_Position *)node2,0,passThroughHit,local_20);
          }
          pPVar2 = poolManagementData;
          if (passThroughHit != 0) {
            *(PlanningNode **)&(poolManagementData->playerPosAtLastPlanMkrUpdate).z = node1;
            pPVar2->expansionNode1 = node2;
            pPVar2->state = '\x03';
            goto LAB_80097dfc;
          }
        }
        PLANPOOL_MarkTwoNodesAsNotConnected
                  ((PlanningNode *)node1,(PlanningNode *)node2,planningPool);
        goto LAB_80097dfc;
      }
      if (bVar1 == 3) {
        node1_00 = *(PlanningNode **)&(poolManagementData->playerPosAtLastPlanMkrUpdate).z;
        uVar4 = *(ushort *)&poolManagementData->distanceMatrix;
        node2 = poolManagementData->expansionNode1;
        if ((uint)uVar4 == (uint)bVar1) {
          passThroughHit = PLANAPI_PassThroughHit(node1_00,(PlanningNode *)node2);
          passThroughHit =
               PLANCOLL_DoesLOSExistFinal
                         ((_Position *)node2,
                          (_Position *)((int)&poolManagementData->distanceMatrix + 2),0,
                          passThroughHit,0);
        }
        else {
          if (uVar4 < 4) {
            passThroughHit = 1;
            if (uVar4 == 0) {
LAB_80097d54:
              passThroughHit = PLANAPI_PassThroughHit(node1_00,(PlanningNode *)node2);
              passThroughHit =
                   PLANCOLL_DoesLOSExistFinal
                             ((_Position *)node1_00,(_Position *)node2,0,passThroughHit,0x3c0);
            }
          }
          else {
            passThroughHit = 1;
            if (uVar4 == 0x202) goto LAB_80097d54;
          }
        }
        if (passThroughHit == 0) {
          PLANPOOL_MarkTwoNodesAsNotConnected
                    (*(PlanningNode **)&(poolManagementData->playerPosAtLastPlanMkrUpdate).z,
                     (PlanningNode *)poolManagementData->expansionNode1,planningPool);
        }
        else {
          PLANPOOL_MarkTwoNodesAsConnected
                    (*(PlanningNode **)&(poolManagementData->playerPosAtLastPlanMkrUpdate).z,
                     (PlanningNode *)poolManagementData->expansionNode1,planningPool);
        }
      }
    }
    cVar3 = '\x01';
  }
  poolManagementData->state = cVar3;
LAB_80097dfc:
  PLANAPI_DoTimingCalcsAndDrawing(uVar5 & 0xffff | uVar7,planningPool);
  DAT_800d2296 = 0;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_NumNodesInPool(void *planningPool /*$a0*/)
 // line 644, offset 0x80097e28
	/* begin block 1 */
		// Start line: 1391
	/* end block 1 */
	// End Line: 1392

	/* begin block 2 */
		// Start line: 1392
	/* end block 2 */
	// End Line: 1393

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_NumNodesInPool(void *planningPool)

{
  return (uint)poolManagementData->numNodesInPool;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit /*$a0*/)
 // line 652, offset 0x80097e3c
	/* begin block 1 */
		// Start line: 653
		// Start offset: 0x80097E3C
		// Variables:
	// 		int i; // $s2
	// 		int terrainFoundFlag; // $v0
	// 		struct Level *level; // $v0
	// 		unsigned short numPlanMkrs; // $s3
	// 		struct _PlanMkr *planMkrList; // $v1

		/* begin block 1.1 */
			// Start line: 667
			// Start offset: 0x80097E7C
			// Variables:
		// 		struct _PlanCollideInfo pci; // stack offset -40

			/* begin block 1.1.1 */
				// Start line: 668
				// Start offset: 0x80097E7C
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $s1
			/* end block 1.1.1 */
			// End offset: 0x80097E7C
			// End Line: 668

			/* begin block 1.1.2 */
				// Start line: 693
				// Start offset: 0x80097F18
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.1.2 */
			// End offset: 0x80097F30
			// End Line: 693
		/* end block 1.1 */
		// End offset: 0x80097F30
		// End Line: 696
	/* end block 1 */
	// End offset: 0x80097F44
	// End Line: 697

	/* begin block 2 */
		// Start line: 1407
	/* end block 2 */
	// End Line: 1408

/* File: C:\kain2\game\PLAN\PLANAPI.C */

void PLANAPI_InitPlanMkrList(_StreamUnit *streamUnit)

{
  ushort uVar1;
  ushort uVar2;
  _PlanMkr *p_Var3;
  int distBefore;
  int distAfter;
  int iVar4;
  int local_30;
  int local_2c;
  _PlanCollideInfo _Stack40;
  
  p_Var3 = streamUnit->level->PlanMarkerList;
  uVar1 = *(ushort *)&streamUnit->level->NumberOfPlanMarkers;
  if ((p_Var3 != (_PlanMkr *)0x0) && (iVar4 = 0, uVar1 != 0)) {
    do {
      _Stack40.collidePos.x = (p_Var3->pos).x;
      _Stack40.collidePos.y = (p_Var3->pos).y;
      _Stack40.collidePos.z = (p_Var3->pos).z;
      uVar2 = p_Var3->id;
      if ((uVar2 & 0x5000) == 0) {
        if ((uVar2 & 0x8000) == 0) {
          if ((uVar2 & 0x2000) == 0) {
            distBefore = 0x80;
            distAfter = -0x400;
            local_30 = 0;
            local_2c = 0;
          }
          else {
            distBefore = -0x100;
            distAfter = 0x280;
            local_30 = 5;
            local_2c = 5;
          }
        }
        else {
          distBefore = -0x100;
          distAfter = 0x280;
          local_30 = 1;
          local_2c = 4;
        }
        distBefore = PLANCOLL_FindTerrainHitFinal
                               (&_Stack40,(int *)0x0,distBefore,distAfter,local_30,local_2c);
        if (distBefore != 0) {
          (p_Var3->pos).x = _Stack40.collidePos.x;
          (p_Var3->pos).y = _Stack40.collidePos.y;
          (p_Var3->pos).z = _Stack40.collidePos.z;
        }
      }
      iVar4 = iVar4 + 1;
      p_Var3 = p_Var3 + 1;
    } while (iVar4 < (int)(uint)uVar1);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_GetFlags(int type /*$a0*/)
 // line 710, offset 0x80097f60
	/* begin block 1 */
		// Start line: 712
		// Start offset: 0x80097F60
		// Variables:
	// 		int chk; // $v0
	/* end block 1 */
	// End offset: 0x80097FC0
	// End Line: 734

	/* begin block 2 */
		// Start line: 1417
	/* end block 2 */
	// End Line: 1418

	/* begin block 3 */
		// Start line: 1541
	/* end block 3 */
	// End Line: 1542

	/* begin block 4 */
		// Start line: 1543
	/* end block 4 */
	// End Line: 1544

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_GetFlags(int type)

{
  if (type == 0xc) {
    return 0x8000;
  }
  if (type < 0xd) {
    if (type == 5) {
      return 0x1000;
    }
  }
  else {
    if (type == 0x14) {
      return 0x2000;
    }
    if (type == 0x1c) {
      return 0x4000;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_FindNodePositionInUnit(struct _StreamUnit *streamUnit /*$a0*/, struct _Position *pos /*$s3*/, int id /*$s2*/, int type /*$a3*/)
 // line 736, offset 0x80097fc8
	/* begin block 1 */
		// Start line: 737
		// Start offset: 0x80097FC8

		/* begin block 1.1 */
			// Start line: 740
			// Start offset: 0x80097FEC
			// Variables:
		// 		struct Level *level; // $v0
		// 		int numPlanMkrs; // $s0
		// 		struct _PlanMkr *planMkr; // $s1
		// 		int i; // $s0

			/* begin block 1.1.1 */
				// Start line: 750
				// Start offset: 0x80098020
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			/* end block 1.1.1 */
			// End offset: 0x80098020
			// End Line: 750
		/* end block 1.1 */
		// End offset: 0x8009804C
		// End Line: 754
	/* end block 1 */
	// End offset: 0x80098050
	// End Line: 756

	/* begin block 2 */
		// Start line: 1592
	/* end block 2 */
	// End Line: 1593

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_FindNodePositionInUnit(_StreamUnit *streamUnit,_Position *pos,int id,int type)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  _PlanMkr *p_Var6;
  
  if (streamUnit != (_StreamUnit *)0x0) {
    p_Var6 = streamUnit->level->PlanMarkerList;
    iVar5 = streamUnit->level->NumberOfPlanMarkers;
    uVar3 = PLANAPI_GetFlags(type);
    if (iVar5 != 0) {
      psVar4 = &(p_Var6->pos).z;
      do {
        iVar5 = iVar5 + -1;
        if ((int)psVar4[1] == (id | uVar3)) {
          sVar1 = psVar4[-1];
          sVar2 = *psVar4;
          pos->x = (p_Var6->pos).x;
          pos->y = sVar1;
          pos->z = sVar2;
          return 1;
        }
        psVar4 = psVar4 + 4;
        p_Var6 = p_Var6 + 1;
      } while (iVar5 != 0);
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_FindClosestNodePositionInUnit(struct _StreamUnit *streamUnit /*$a0*/, struct _Position *target /*$s3*/, struct _Position *pos /*$fp*/, int offset /*stack 12*/, int max /*stack 16*/, int type /*stack 20*/, int distanceCheck /*stack 24*/)
 // line 761, offset 0x8009806c
	/* begin block 1 */
		// Start line: 762
		// Start offset: 0x8009806C
		// Variables:
	// 		struct Level *level; // $v0
	// 		int numPlanMkrs; // $s0
	// 		struct _PlanMkr *planMkr; // $s1
	// 		struct _Position *ptr; // $s4
	// 		int dist; // $v1
	// 		int min_dist; // $s5
	// 		int chk; // $s7
	// 		int res; // $s6
	// 		int i; // $s2

		/* begin block 1.1 */
			// Start line: 801
			// Start offset: 0x800981A4
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x800981BC
		// End Line: 801
	/* end block 1 */
	// End offset: 0x800981BC
	// End Line: 804

	/* begin block 2 */
		// Start line: 1649
	/* end block 2 */
	// End Line: 1650

/* File: C:\kain2\game\PLAN\PLANAPI.C */

int PLANAPI_FindClosestNodePositionInUnit
              (_StreamUnit *streamUnit,_Position *target,_Position *pos,int offset,int max,int type,
              int distanceCheck)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  _PlanMkr *p_Var7;
  _PlanMkr *p_Var8;
  _PlanMkr *p_Var9;
  int iVar10;
  int iVar11;
  
  p_Var9 = (_PlanMkr *)0x0;
  iVar10 = 0x7fff;
  p_Var7 = streamUnit->level->PlanMarkerList;
  iVar6 = streamUnit->level->NumberOfPlanMarkers;
  iVar11 = 0;
  uVar3 = PLANAPI_GetFlags(type);
  p_Var8 = p_Var7;
  while (0 < iVar6) {
    if (((int)p_Var7->id & uVar3) != 0) {
      if (distanceCheck == 0) {
        lVar4 = MATH3D_LengthXY((int)target->x - (int)(p_Var8->pos).x,
                                (int)target->y - (int)(p_Var7->pos).y);
      }
      else {
        lVar4 = MATH3D_LengthXYZ((int)target->x - (int)(p_Var8->pos).x,
                                 (int)target->y - (int)(p_Var7->pos).y,
                                 (int)target->z - (int)(p_Var7->pos).z);
      }
      if (lVar4 < max) {
        iVar5 = lVar4 - offset;
        if (iVar5 < 0) {
          iVar5 = -iVar5;
        }
        if (iVar5 < iVar10) {
          iVar11 = 1;
          p_Var9 = p_Var7;
          iVar10 = iVar5;
        }
      }
    }
    iVar6 = iVar6 + -1;
    p_Var7 = p_Var7 + 1;
    p_Var8 = p_Var8 + 1;
  }
  if (iVar11 != 0) {
    sVar1 = (p_Var9->pos).y;
    sVar2 = (p_Var9->pos).z;
    pos->x = (p_Var9->pos).x;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return iVar11;
}





