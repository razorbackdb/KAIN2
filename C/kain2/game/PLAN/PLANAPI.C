#include "THISDUST.H"
#include "PLANAPI.H"


// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(struct PlanningNode *goalNode /*$a0*/, struct EnemyPlanData *planData /*$s1*/, struct PlanningNode *planningPool /*$s2*/)
 // line 131, offset 0x80097ccc
	/* begin block 1 */
		// Start line: 132
		// Start offset: 0x80097CCC
		// Variables:
	// 		struct PlanningNode *currentNode; // $s0
	// 		int i; // $a0
	/* end block 1 */
	// End offset: 0x80097D68
	// End Line: 151

	/* begin block 2 */
		// Start line: 262
	/* end block 2 */
	// End Line: 263

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
 // line 157, offset 0x80097d80
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x80097D80
		// Variables:
	// 		struct PlanningNode *planningPool; // $s1
	// 		int successFlag; // $s2
	/* end block 1 */
	// End offset: 0x80097DE8
	// End Line: 172

	/* begin block 2 */
		// Start line: 317
	/* end block 2 */
	// End Line: 318

int PLANAPI_FindPathBetweenNodes
              (PlanningNode *startNode,PlanningNode *goalNode,EnemyPlanData *planData,
              int validNodeTypes)

{
  void *planningPool;
  PlanningNode *goalNode_00;
  int iVar1;
  
  planningPool = gameTrackerX.planningPool;
  iVar1 = 0;
  if (((startNode != (PlanningNode *)0x0) && (goalNode != (PlanningNode *)0x0)) &&
     (goalNode_00 = PLANSRCH_FindPathInGraph
                              ((PlanningNode *)gameTrackerX.planningPool,startNode,goalNode,
                               validNodeTypes), goalNode_00 != (PlanningNode *)0x0)) {
    PLANAPI_ConvertPlanIntoEnmyPlanDataFormat(goalNode_00,planData,(PlanningNode *)planningPool);
    iVar1 = 1;
    planData->goalUnitID = *(short *)&goalNode_00->streamUnitID;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_DoTimingCalcsAndDrawing(long startTime /*$a0*/, struct PlanningNode *planningPool /*$s2*/)
 // line 177, offset 0x80097e08
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x80097E08
		// Variables:
	// 		int i; // $a1
	// 		long minTime; // $s1
	// 		long maxTime; // $s0

		/* begin block 1.1 */
			// Start line: 199
			// Start offset: 0x80097EB0
		/* end block 1.1 */
		// End offset: 0x80097F0C
		// End Line: 221
	/* end block 1 */
	// End offset: 0x80097F0C
	// End Line: 222

	/* begin block 2 */
		// Start line: 361
	/* end block 2 */
	// End Line: 362

void PLANAPI_DoTimingCalcsAndDrawing(long startTime,PlanningNode *planningPool)

{
  ulong uVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0x7fffffff;
  iVar5 = 0;
  uVar1 = TIMER_TimeDiff(startTime);
  iVar4 = 0;
  plVar3 = &timerArray;
  (&timerArray)[timerIndex] = uVar1;
  do {
    iVar2 = *plVar3;
    if (iVar2 < iVar6) {
      iVar6 = iVar2;
    }
    if (iVar5 < iVar2) {
      iVar5 = iVar2;
    }
    iVar4 = iVar4 + 1;
    plVar3 = plVar3 + 1;
  } while (iVar4 < 10);
  timerIndex = timerIndex + 1;
  if (9 < timerIndex) {
    timerIndex = 0;
  }
  if ((gameTrackerX.debugFlags2 & 0x10U) != 0) {
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
 // line 269, offset 0x80097f24
	/* begin block 1 */
		// Start line: 270
		// Start offset: 0x80097F24
		// Variables:
	// 		struct PlanningNode *planningPool; // $s1
	// 		int foundHit; // $v1
	// 		int nodePlacement; // stack offset -24
	// 		struct _PlanCollideInfo pci; // stack offset -40

		/* begin block 1.1 */
			// Start line: 284
			// Start offset: 0x80097F70
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $s0
		/* end block 1.1 */
		// End offset: 0x80097F70
		// End Line: 284
	/* end block 1 */
	// End offset: 0x80097FEC
	// End Line: 294

	/* begin block 2 */
		// Start line: 552
	/* end block 2 */
	// End Line: 553

int PLANAPI_AddNodeOfTypeToPool(_Position *pos,int type)

{
  void *planningPool;
  int iVar1;
  ushort nodeType;
  _PlanCollideInfo local_28;
  ushort local_18 [4];
  
  planningPool = gameTrackerX.planningPool;
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
  PLANPOOL_AddNodeToPool(pos,(PlanningNode *)planningPool,nodeType,0,local_28.StreamUnitID);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_DeleteNodesFromPoolByType(int nodeSource /*$s3*/)
 // line 306, offset 0x80098004
	/* begin block 1 */
		// Start line: 307
		// Start offset: 0x80098004
		// Variables:
	// 		struct PlanningNode *planningPool; // $s2
	// 		struct PlanningNode *nodeToDelete; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80098084
	// End Line: 324

	/* begin block 2 */
		// Start line: 612
	/* end block 2 */
	// End Line: 613

	/* begin block 3 */
		// Start line: 626
	/* end block 3 */
	// End Line: 627

void PLANAPI_DeleteNodesFromPoolByType(int nodeSource)

{
  void *planningPool;
  PlanningNode *nodeToDelete;
  int iVar1;
  
  planningPool = gameTrackerX.planningPool;
  iVar1 = 0;
  nodeToDelete = (PlanningNode *)gameTrackerX.planningPool;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      if (((uint)nodeToDelete->nodeType & 7) == nodeSource) {
        PLANPOOL_DeleteNodeFromPool(nodeToDelete,(PlanningNode *)planningPool);
      }
      else {
        iVar1 = iVar1 + 1;
        nodeToDelete = nodeToDelete + 1;
      }
    } while (iVar1 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID /*$s3*/)
 // line 327, offset 0x800980a0
	/* begin block 1 */
		// Start line: 328
		// Start offset: 0x800980A0
		// Variables:
	// 		struct PlanningNode *planningPool; // $s2
	// 		struct PlanningNode *nodeToDelete; // $s0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8009811C
	// End Line: 347

	/* begin block 2 */
		// Start line: 683
	/* end block 2 */
	// End Line: 684

	/* begin block 3 */
		// Start line: 688
	/* end block 3 */
	// End Line: 689

void PLANAPI_DeleteNodeFromPoolByUnit(long streamUnitID)

{
  void *planningPool;
  PlanningNode *nodeToDelete;
  int iVar1;
  
  planningPool = gameTrackerX.planningPool;
  iVar1 = 0;
  nodeToDelete = (PlanningNode *)gameTrackerX.planningPool;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      if (nodeToDelete->streamUnitID == streamUnitID) {
        PLANPOOL_DeleteNodeFromPool(nodeToDelete,(PlanningNode *)planningPool);
      }
      else {
        iVar1 = iVar1 + 1;
        nodeToDelete = nodeToDelete + 1;
      }
    } while (iVar1 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_FindPathInGraphToTarget(struct _Position *startPos /*$a0*/, struct EnemyPlanData *planData /*$s1*/, int validNodeTypes /*$s2*/)
 // line 388, offset 0x80098138
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x80098138
		// Variables:
	// 		struct PlanningNode *planningPool; // $s0
	// 		struct PlanningNode *startNode; // $s0
	/* end block 1 */
	// End offset: 0x80098138
	// End Line: 389

	/* begin block 2 */
		// Start line: 827
	/* end block 2 */
	// End Line: 828

int PLANAPI_FindPathInGraphToTarget(_Position *startPos,EnemyPlanData *planData,int validNodeTypes)

{
  void *planningPool;
  PlanningNode *startNode;
  PlanningNode *goalNode;
  int iVar1;
  
  planningPool = gameTrackerX.planningPool;
  startNode = PLANPOOL_GetNodeByPosition(startPos,(PlanningNode *)gameTrackerX.planningPool);
  goalNode = PLANPOOL_GetFirstNodeOfSource((PlanningNode *)planningPool,'\x03');
  iVar1 = PLANAPI_FindPathBetweenNodes(startNode,goalNode,planData,validNodeTypes);
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_InitPlanning(void *planningPool /*$a0*/)
 // line 405, offset 0x8009819c
	/* begin block 1 */
		// Start line: 407
		// Start offset: 0x8009819C
		// Variables:
	// 		int i; // $a1
	// 		int j; // $a0
	/* end block 1 */
	// End offset: 0x80098210
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

void PLANAPI_InitPlanning(void *planningPool)

{
  int iVar1;
  long *plVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  DAT_800d6b48 = (int)planningPool + 0x380;
  poolManagementData = &poolManagementDataStorage;
  poolManagementDataStorage = 0;
  DAT_800d6b39 = 0;
  do {
    iVar3 = 0;
    iVar1 = 0;
    do {
      iVar3 = iVar3 + 1;
      *(undefined2 *)(iVar1 + iVar4 * 0x40 + DAT_800d6b48) = 0;
      iVar1 = iVar3 * 2;
    } while (iVar3 < 0x20);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  iVar4 = 9;
  plVar2 = &LONG_800d6b7c;
  do {
    *plVar2 = 0;
    iVar4 = iVar4 + -1;
    plVar2 = plVar2 + -1;
  } while (-1 < iVar4);
  timerIndex = 0;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ PLANAPI_PairType(struct PlanningNode *node1 /*$a0*/, struct PlanningNode *node2 /*$a1*/)
 // line 446, offset 0x8009821c
	/* begin block 1 */
		// Start line: 448
		// Start offset: 0x8009821C
		// Variables:
	// 		short placement1; // $a2
	// 		short placement2; // $a1
	/* end block 1 */
	// End offset: 0x80098258
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
 // line 462, offset 0x80098264
	/* begin block 1 */
		// Start line: 464
		// Start offset: 0x80098264
		// Variables:
	// 		int src1; // $a0
	// 		int src2; // $v1
	// 		int res; // $v1
	/* end block 1 */
	// End offset: 0x800982C8
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

int PLANAPI_PassThroughHit(PlanningNode *node1,PlanningNode *node2)

{
  uint uVar1;
  uint uVar2;
  
  if (gameTrackerX.gameFlags < 0) {
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
 // line 491, offset 0x800982d0
	/* begin block 1 */
		// Start line: 492
		// Start offset: 0x800982D0
		// Variables:
	// 		struct PlanningNode *planningPool; // $s3
	// 		struct PlanningNode *node1; // $s0
	// 		struct PlanningNode *node2; // $s1
	// 		long startTime; // $s4
	// 		int pathExistsAbove; // $s2
	// 		int pathExistsBelow; // $v1

		/* begin block 1.1 */
			// Start line: 537
			// Start offset: 0x8009849C
			// Variables:
		// 		struct PlanningNode *temp; // $v0
		/* end block 1.1 */
		// End offset: 0x800984A8
		// End Line: 541
	/* end block 1 */
	// End offset: 0x800986E8
	// End Line: 652

	/* begin block 2 */
		// Start line: 1056
	/* end block 2 */
	// End Line: 1057

void PLANAPI_UpdatePlanningDatabase(GameTracker *gameTracker,_Instance *player)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  long lVar5;
  int passThroughHit;
  int passThroughHit_00;
  uint uVar6;
  PlanningNode *node1;
  PlanningNode *node2;
  PlanningNode *node2_00;
  PlanningNode *startNode;
  PlanningNode *planningPool;
  int local_20;
  
  planningPool = (PlanningNode *)gameTracker->planningPool;
  uVar4 = GetRCnt(0xf2000000);
  gameTrackerX.plan_collide_override = '\x01';
  uVar6 = gameTimer << 0x10;
  bVar2 = *poolManagementData;
  if (bVar2 == 1) {
    PLAN_AddOrRemoveNodes(planningPool,player);
    bVar2 = 2;
  }
  else {
    if (bVar2 < 2) {
      if (bVar2 == 0) {
        PLAN_AddInitialNodes(planningPool,player);
        *poolManagementData = 1;
        goto LAB_800986ec;
      }
    }
    else {
      if (bVar2 == 2) {
        startNode = PLAN_FindNodeMostInNeedOfConnectivityExpansion(planningPool);
        node2_00 = PLANPOOL_GetClosestUnexploredValidNeighbor(startNode,planningPool);
        *poolManagementData = 1;
        if ((startNode == (PlanningNode *)0x0) || (node2_00 == (PlanningNode *)0x0))
        goto LAB_800986ec;
        lVar5 = MATH3D_LengthXYZ((int)(startNode->pos).x - (int)(node2_00->pos).x,
                                 (int)(startNode->pos).y - (int)(node2_00->pos).y,
                                 (int)(startNode->pos).z - (int)(node2_00->pos).z);
        if (5999 < lVar5) {
          PLANPOOL_MarkTwoNodesAsNotConnected(startNode,node2_00,planningPool);
          PLANPOOL_MarkTwoNodesAsNotConnected(node2_00,startNode,planningPool);
          goto LAB_800986ec;
        }
        uVar3 = PLANAPI_PairType(startNode,node2_00);
        *(ushort *)(poolManagementData + 0x14) = uVar3;
        node1 = startNode;
        if (uVar3 == 3) {
          if ((startNode->nodeType >> 3 & 3) == 3) {
            node1 = node2_00;
            node2_00 = startNode;
          }
          startNode = node2_00;
          passThroughHit = PLANAPI_PassThroughHit(node1,startNode);
          passThroughHit =
               PLANCOLL_DoesWaterPathUpExist
                         ((_Position *)node1,(_Position *)startNode,0,
                          (_Position *)(poolManagementData + 0x16),passThroughHit);
          passThroughHit_00 = PLANAPI_PassThroughHit(node1,startNode);
          local_20 = 0;
          node2_00 = (PlanningNode *)(poolManagementData + 0x16);
          node2 = startNode;
LAB_800984f8:
          passThroughHit_00 =
               PLANCOLL_DoesLOSExistFinal
                         ((_Position *)startNode,(_Position *)node2_00,0,passThroughHit_00,local_20)
          ;
        }
        else {
          node2 = node2_00;
          if (uVar3 < 4) {
            if (uVar3 == 0) {
LAB_80098430:
              passThroughHit = PLANAPI_PassThroughHit(startNode,node2_00);
              passThroughHit =
                   PLANCOLL_DoesLOSExistFinal
                             ((_Position *)startNode,(_Position *)node2_00,0,passThroughHit,0x100);
              passThroughHit_00 = PLANAPI_PassThroughHit(startNode,node2_00);
              local_20 = -0x100;
              goto LAB_800984f8;
            }
          }
          else {
            if (uVar3 == 0x202) goto LAB_80098430;
          }
          passThroughHit = PLANAPI_PassThroughHit(startNode,node2_00);
          passThroughHit_00 =
               PLANCOLL_DoesLOSExistFinal
                         ((_Position *)startNode,(_Position *)node2_00,0,passThroughHit,0);
          passThroughHit = passThroughHit_00;
        }
        pbVar1 = poolManagementData;
        *(PlanningNode **)(poolManagementData + 8) = node1;
        *(PlanningNode **)(pbVar1 + 0xc) = node2;
        if ((passThroughHit == 0) || (passThroughHit_00 == 0)) {
          PLANPOOL_MarkTwoNodesAsNotConnected(node1,node2,planningPool);
        }
        else {
          PLANPOOL_MarkTwoNodesAsConnected(node1,node2,planningPool);
        }
        bVar2 = 3;
        goto LAB_800986e4;
      }
      if (bVar2 == 3) {
        node2_00 = *(PlanningNode **)(poolManagementData + 8);
        uVar3 = *(ushort *)(poolManagementData + 0x14);
        startNode = *(PlanningNode **)(poolManagementData + 0xc);
        if ((uint)uVar3 == (uint)bVar2) {
          passThroughHit = PLANAPI_PassThroughHit(startNode,node2_00);
          passThroughHit =
               PLANCOLL_DoesWaterPathUpExist
                         ((_Position *)startNode,(_Position *)node2_00,0,
                          (_Position *)(poolManagementData + 0x16),passThroughHit);
          passThroughHit_00 = PLANAPI_PassThroughHit(startNode,node2_00);
          local_20 = 0;
          node2 = (PlanningNode *)(poolManagementData + 0x16);
          node1 = node2_00;
LAB_80098678:
          passThroughHit_00 =
               PLANCOLL_DoesLOSExistFinal
                         ((_Position *)node1,(_Position *)node2,0,passThroughHit_00,local_20);
        }
        else {
          if (uVar3 < 4) {
            if (uVar3 == 0) {
LAB_800985d4:
              passThroughHit = PLANAPI_PassThroughHit(startNode,node2_00);
              passThroughHit =
                   PLANCOLL_DoesLOSExistFinal
                             ((_Position *)startNode,(_Position *)node2_00,0,passThroughHit,0x100);
              passThroughHit_00 = PLANAPI_PassThroughHit(startNode,node2_00);
              local_20 = -0x100;
              node1 = startNode;
              node2 = node2_00;
              goto LAB_80098678;
            }
          }
          else {
            if (uVar3 == 0x202) goto LAB_800985d4;
          }
          passThroughHit = PLANAPI_PassThroughHit(startNode,node2_00);
          passThroughHit_00 =
               PLANCOLL_DoesLOSExistFinal
                         ((_Position *)startNode,(_Position *)node2_00,0,passThroughHit,0);
          passThroughHit = passThroughHit_00;
        }
        if ((passThroughHit == 0) || (passThroughHit_00 == 0)) {
          PLANPOOL_MarkTwoNodesAsNotConnected(startNode,node2_00,planningPool);
        }
        else {
          PLANPOOL_MarkTwoNodesAsConnected(startNode,node2_00,planningPool);
        }
      }
    }
    bVar2 = 1;
  }
LAB_800986e4:
  *poolManagementData = bVar2;
LAB_800986ec:
  PLANAPI_DoTimingCalcsAndDrawing(uVar4 & 0xffff | uVar6,planningPool);
  gameTrackerX.plan_collide_override = '\0';
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANAPI_NumNodesInPool(void *planningPool /*$a0*/)
 // line 660, offset 0x80098718
	/* begin block 1 */
		// Start line: 1423
	/* end block 1 */
	// End Line: 1424

	/* begin block 2 */
		// Start line: 1424
	/* end block 2 */
	// End Line: 1425

int PLANAPI_NumNodesInPool(void *planningPool)

{
  return (uint)*(byte *)(poolManagementData + 1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANAPI_InitPlanMkrList(struct _StreamUnit *streamUnit /*$a0*/)
 // line 668, offset 0x8009872c
	/* begin block 1 */
		// Start line: 669
		// Start offset: 0x8009872C
		// Variables:
	// 		int i; // $s2
	// 		int terrainFoundFlag; // $v0
	// 		struct Level *level; // $v0
	// 		unsigned short numPlanMkrs; // $s3
	// 		struct _PlanMkr *planMkrList; // $v1

		/* begin block 1.1 */
			// Start line: 683
			// Start offset: 0x8009876C
			// Variables:
		// 		struct _PlanCollideInfo pci; // stack offset -40

			/* begin block 1.1.1 */
				// Start line: 684
				// Start offset: 0x8009876C
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			// 		struct _Position *_v0; // $s1
			/* end block 1.1.1 */
			// End offset: 0x8009876C
			// End Line: 684

			/* begin block 1.1.2 */
				// Start line: 709
				// Start offset: 0x80098808
				// Variables:
			// 		short _x1; // $v0
			// 		short _y1; // $v1
			// 		short _z1; // $a0
			/* end block 1.1.2 */
			// End offset: 0x80098820
			// End Line: 709
		/* end block 1.1 */
		// End offset: 0x80098820
		// End Line: 712
	/* end block 1 */
	// End offset: 0x80098834
	// End Line: 713

	/* begin block 2 */
		// Start line: 1439
	/* end block 2 */
	// End Line: 1440

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
 // line 726, offset 0x80098850
	/* begin block 1 */
		// Start line: 728
		// Start offset: 0x80098850
		// Variables:
	// 		int chk; // $v0
	/* end block 1 */
	// End offset: 0x800988B0
	// End Line: 750

	/* begin block 2 */
		// Start line: 1452
	/* end block 2 */
	// End Line: 1453

	/* begin block 3 */
		// Start line: 1573
	/* end block 3 */
	// End Line: 1574

	/* begin block 4 */
		// Start line: 1575
	/* end block 4 */
	// End Line: 1576

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
 // line 752, offset 0x800988b8
	/* begin block 1 */
		// Start line: 753
		// Start offset: 0x800988B8

		/* begin block 1.1 */
			// Start line: 756
			// Start offset: 0x800988DC
			// Variables:
		// 		struct Level *level; // $v0
		// 		int numPlanMkrs; // $s0
		// 		struct _PlanMkr *planMkr; // $s1
		// 		int i; // $s0

			/* begin block 1.1.1 */
				// Start line: 766
				// Start offset: 0x80098910
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			/* end block 1.1.1 */
			// End offset: 0x80098910
			// End Line: 766
		/* end block 1.1 */
		// End offset: 0x8009893C
		// End Line: 770
	/* end block 1 */
	// End offset: 0x80098940
	// End Line: 772

	/* begin block 2 */
		// Start line: 1624
	/* end block 2 */
	// End Line: 1625

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
 // line 777, offset 0x8009895c
	/* begin block 1 */
		// Start line: 778
		// Start offset: 0x8009895C
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
			// Start line: 817
			// Start offset: 0x80098A94
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		/* end block 1.1 */
		// End offset: 0x80098AAC
		// End Line: 817
	/* end block 1 */
	// End offset: 0x80098AAC
	// End Line: 820

	/* begin block 2 */
		// Start line: 1681
	/* end block 2 */
	// End Line: 1682

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





