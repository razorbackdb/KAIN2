#include "THISDUST.H"
#include "PLANPOOL.H"


// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode /*$a0*/, struct PlanningNode *planningPool /*$a1*/)
 // line 122, offset 0x80096be4
	/* begin block 1 */
		// Start line: 124
		// Start offset: 0x80096BE4
		// Variables:
	// 		struct PlanningNode *currentNode; // $a0
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80096C28
	// End Line: 132

	/* begin block 2 */
		// Start line: 244
	/* end block 2 */
	// End Line: 245

	/* begin block 3 */
		// Start line: 245
	/* end block 3 */
	// End Line: 246

	/* begin block 4 */
		// Start line: 248
	/* end block 4 */
	// End Line: 249

int PLANPOOL_NumNodesInPlan(PlanningNode *goalNode,PlanningNode *planningPool)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = goalNode->parent;
  iVar2 = 0;
  while (goalNode != planningPool + uVar1) {
    goalNode = planningPool + goalNode->parent;
    uVar1 = goalNode->parent;
    iVar2 = iVar2 + 1;
  }
  return iVar2 + 1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_CountBitsSetInLong(long mylong /*$a0*/)
 // line 137, offset 0x80096c30
	/* begin block 1 */
		// Start line: 139
		// Start offset: 0x80096C30
		// Variables:
	// 		int numBitsSet; // $v1
	/* end block 1 */
	// End offset: 0x80096C48
	// End Line: 146

	/* begin block 2 */
		// Start line: 276
	/* end block 2 */
	// End Line: 277

	/* begin block 3 */
		// Start line: 277
	/* end block 3 */
	// End Line: 278

	/* begin block 4 */
		// Start line: 279
	/* end block 4 */
	// End Line: 280

int PLANPOOL_CountBitsSetInLong(long mylong)

{
  int iVar1;
  
  iVar1 = 0;
  if (mylong != 0) {
    do {
      mylong = mylong & mylong - 1U;
      iVar1 = iVar1 + 1;
    } while (mylong != 0);
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_NumConnectionsExaminedForNode(struct PlanningNode *node /*$a0*/)
 // line 150, offset 0x80096c50
	/* begin block 1 */
		// Start line: 302
	/* end block 1 */
	// End Line: 303

int PLANPOOL_NumConnectionsExaminedForNode(PlanningNode *node)

{
  int iVar1;
  
  iVar1 = PLANPOOL_CountBitsSetInLong(node->connectionStatus);
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_NumConnectionsForNode(struct PlanningNode *node /*$a0*/)
 // line 158, offset 0x80096c74
	/* begin block 1 */
		// Start line: 318
	/* end block 1 */
	// End Line: 319

int PLANPOOL_NumConnectionsForNode(PlanningNode *node)

{
  int iVar1;
  
  iVar1 = PLANPOOL_CountBitsSetInLong(node->connections);
  return iVar1;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_GetFirstNodeOfSource(struct PlanningNode *planningPool /*$a0*/, char nodeSource /*$a1*/)
 // line 177, offset 0x80096c98
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x80096C98
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80096CE0
	// End Line: 186

	/* begin block 2 */
		// Start line: 350
	/* end block 2 */
	// End Line: 351

	/* begin block 3 */
		// Start line: 342
	/* end block 3 */
	// End Line: 343

PlanningNode * PLANPOOL_GetFirstNodeOfSource(PlanningNode *planningPool,char nodeSource)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0) {
    do {
      iVar1 = iVar1 + 1;
      if (((uint)planningPool->nodeType & 7) == (uint)(byte)nodeSource) {
        return planningPool;
      }
      planningPool = planningPool + 1;
    } while (iVar1 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return (PlanningNode *)0x0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_NumberOfNodesOfType(struct PlanningNode *planningPool /*$a0*/, char nodeType /*$a1*/)
 // line 189, offset 0x80096ce8
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x80096CE8
		// Variables:
	// 		int i; // $a2
	// 		int numNodesOfType; // $v1
	/* end block 1 */
	// End offset: 0x80096D2C
	// End Line: 197

	/* begin block 2 */
		// Start line: 364
	/* end block 2 */
	// End Line: 365

	/* begin block 3 */
		// Start line: 367
	/* end block 3 */
	// End Line: 368

int PLANPOOL_NumberOfNodesOfType(PlanningNode *planningPool,char nodeType)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0) {
    do {
      if ((uint)planningPool->nodeType == (uint)(byte)nodeType) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_NumberOfNodesOfSource(struct PlanningNode *planningPool /*$a0*/, char nodeSource /*$a1*/)
 // line 201, offset 0x80096d34
	/* begin block 1 */
		// Start line: 202
		// Start offset: 0x80096D34
		// Variables:
	// 		int i; // $a2
	// 		int numNodesOfSource; // $v1
	/* end block 1 */
	// End offset: 0x80096D7C
	// End Line: 209

	/* begin block 2 */
		// Start line: 389
	/* end block 2 */
	// End Line: 390

	/* begin block 3 */
		// Start line: 392
	/* end block 3 */
	// End Line: 393

int PLANPOOL_NumberOfNodesOfSource(PlanningNode *planningPool,char nodeSource)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0) {
    do {
      if (((uint)planningPool->nodeType & 7) == (uint)(byte)nodeSource) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool /*$a0*/, short type /*$a1*/, short id /*$a2*/)
 // line 213, offset 0x80096d84
	/* begin block 1 */
		// Start line: 215
		// Start offset: 0x80096D84
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80096DE8
	// End Line: 223

	/* begin block 2 */
		// Start line: 414
	/* end block 2 */
	// End Line: 415

	/* begin block 3 */
		// Start line: 415
	/* end block 3 */
	// End Line: 416

	/* begin block 4 */
		// Start line: 417
	/* end block 4 */
	// End Line: 418

PlanningNode * PLANPOOL_GetNodeWithID(PlanningNode *planningPool,short type,short id)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0) {
    do {
      if (((uint)planningPool->nodeType == (int)type) && ((uint)planningPool->id == (int)id)) {
        return planningPool;
      }
      iVar1 = iVar1 + 1;
      planningPool = planningPool + 1;
    } while (iVar1 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return (PlanningNode *)0x0;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_GetNodeByPosition(struct _Position *currentPos /*$s3*/, struct PlanningNode *planningPool /*$a1*/)
 // line 229, offset 0x80096df0
	/* begin block 1 */
		// Start line: 230
		// Start offset: 0x80096DF0
		// Variables:
	// 		int i; // $s1
	// 		unsigned long zDiff; // $v0
	// 		unsigned long minZDiff; // $s4
	// 		struct PlanningNode *returnNode; // $s2
	/* end block 1 */
	// End offset: 0x80096EA0
	// End Line: 246

	/* begin block 2 */
		// Start line: 448
	/* end block 2 */
	// End Line: 449

	/* begin block 3 */
		// Start line: 453
	/* end block 3 */
	// End Line: 454

PlanningNode * PLANPOOL_GetNodeByPosition(_Position *currentPos,PlanningNode *planningPool)

{
  long lVar1;
  int iVar2;
  int iVar3;
  PlanningNode *pPVar4;
  
  iVar3 = 0;
  pPVar4 = (PlanningNode *)0x0;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      lVar1 = MATH3D_LengthXY((int)currentPos->x - (int)(planningPool->pos).x,
                              (int)currentPos->y - (int)(planningPool->pos).y);
      if (lVar1 < 0xb) {
        iVar2 = (int)currentPos->z - (int)(planningPool->pos).z;
        if (iVar2 < 0) {
          iVar2 = -iVar2;
        }
        if (iVar2 != -1) {
          pPVar4 = planningPool;
        }
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
    } while (iVar3 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return pPVar4;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_GetClosestNode(struct _Position *pos /*$s1*/, struct PlanningNode *planningPool /*$a1*/, char distanceType /*$s5*/)
 // line 250, offset 0x80096ec4
	/* begin block 1 */
		// Start line: 251
		// Start offset: 0x80096EC4
		// Variables:
	// 		int i; // $s2
	// 		long dist; // $v1
	// 		long minDist; // $s4
	// 		struct PlanningNode *closestNode; // $s3
	/* end block 1 */
	// End offset: 0x80096F9C
	// End Line: 269

	/* begin block 2 */
		// Start line: 511
	/* end block 2 */
	// End Line: 512

PlanningNode * PLANPOOL_GetClosestNode(_Position *pos,PlanningNode *planningPool,char distanceType)

{
  long lVar1;
  int iVar2;
  PlanningNode *pPVar3;
  int iVar4;
  
  iVar4 = 0x7fffffff;
  iVar2 = 0;
  pPVar3 = (PlanningNode *)0x0;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      if (distanceType == '\0') {
        lVar1 = MATH3D_LengthXY((int)pos->x - (int)(planningPool->pos).x,
                                (int)pos->y - (int)(planningPool->pos).y);
      }
      else {
        lVar1 = MATH3D_LengthXYZ((int)pos->x - (int)(planningPool->pos).x,
                                 (int)pos->y - (int)(planningPool->pos).y,
                                 (int)pos->z - (int)(planningPool->pos).z);
      }
      if (lVar1 < iVar4) {
        pPVar3 = planningPool;
        iVar4 = lVar1;
      }
      iVar2 = iVar2 + 1;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return pPVar3;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_AppropriatePair(struct PlanningNode *node1 /*$t1*/, struct PlanningNode *node2 /*$a1*/)
 // line 276, offset 0x80096fc4
	/* begin block 1 */
		// Start line: 277
		// Start offset: 0x80096FC4
		// Variables:
	// 		struct PlanningNode *temp; // $v0
	// 		int res; // $s0
	// 		int src; // $a0
	// 		int plc; // $v1
	// 		short type1; // $a0
	// 		short type2; // $v1
	// 		short placement1; // $t5
	// 		short placement2; // $t4
	// 		short source1; // $t2
	// 		short source2; // $t3
	/* end block 1 */
	// End offset: 0x80097124
	// End Line: 344

	/* begin block 2 */
		// Start line: 592
	/* end block 2 */
	// End Line: 593

int PLANPOOL_AppropriatePair(PlanningNode *node1,PlanningNode *node2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  PlanningNode *pPVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = (uint)(node1->nodeType >> 3) & 3;
  uVar7 = (uint)(node2->nodeType >> 3) & 3;
  uVar4 = (uint)node1->nodeType & 7;
  uVar8 = (uint)node2->nodeType & 7;
  pPVar6 = node2;
  if (uVar7 < uVar9) {
    uVar9 = uVar9 ^ uVar7;
    uVar7 = uVar7 ^ uVar9;
    uVar9 = uVar9 ^ uVar7;
    pPVar6 = node1;
    node1 = node2;
  }
  uVar2 = uVar4 ^ uVar8;
  if (uVar8 < uVar4) {
    uVar8 = uVar8 ^ uVar2;
    uVar4 = uVar2 ^ uVar8;
  }
  uVar7 = uVar7 | uVar9 << 8;
  uVar8 = uVar8 | uVar4 << 8;
  if (uVar7 == 3) {
    if (uVar8 != 0x404) {
      return 0;
    }
    return 1;
  }
  if (uVar7 < 4) {
    if (uVar7 != 1) {
      if (uVar7 == 2) {
        return 0;
      }
      return 1;
    }
  }
  else {
    if (uVar7 == 0x103) {
      return 0;
    }
    if (0x103 < uVar7) {
      if (uVar7 == 0x203) {
        return 0;
      }
      return 1;
    }
    if (uVar7 != 0x102) {
      return 1;
    }
  }
  if (uVar8 == 0x404) {
    iVar3 = (int)(node1->pos).z;
    iVar5 = (int)(pPVar6->pos).z;
    if (((iVar3 < iVar5) && (iVar5 < iVar3 + 800)) &&
       (lVar1 = MATH3D_LengthXY((int)(node1->pos).x - (int)(pPVar6->pos).x,
                                (int)(node1->pos).y - (int)(pPVar6->pos).y), lVar1 < 0x321)) {
      return 1;
    }
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_AreTwoNodesConnected(struct PlanningNode *node1 /*$a3*/, struct PlanningNode *node2 /*$a1*/, struct PlanningNode *planningPool /*$a2*/)
 // line 349, offset 0x80097138
	/* begin block 1 */
		// Start line: 350
		// Start offset: 0x80097138
		// Variables:
	// 		long node2Mask; // $a0
	/* end block 1 */
	// End offset: 0x800971A0
	// End Line: 360

	/* begin block 2 */
		// Start line: 738
	/* end block 2 */
	// End Line: 739

int PLANPOOL_AreTwoNodesConnected
              (PlanningNode *node1,PlanningNode *node2,PlanningNode *planningPool)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 1 << ((int)((int)node2 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  iVar1 = 0;
  if (((node1->connectionStatus & uVar2) != 0) && (iVar1 = 1, (node1->connections & uVar2) == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1 /*$s2*/, struct PlanningNode *node2 /*$s3*/, struct PlanningNode *planningPool /*$a2*/)
 // line 364, offset 0x800971a8
	/* begin block 1 */
		// Start line: 365
		// Start offset: 0x800971A8
		// Variables:
	// 		int node1Index; // $s1
	// 		int node2Index; // $s0
	/* end block 1 */
	// End offset: 0x80097258
	// End Line: 376

	/* begin block 2 */
		// Start line: 770
	/* end block 2 */
	// End Line: 771

void PLANPOOL_MarkTwoNodesAsConnected
               (PlanningNode *node1,PlanningNode *node2,PlanningNode *planningPool)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = (int)((int)node1 - (int)planningPool) * -0x49249249 >> 2;
  uVar5 = (int)((int)node2 - (int)planningPool) * -0x49249249 >> 2;
  lVar2 = MATH3D_DistanceBetweenPositions((_Position *)node1,(_Position *)node2);
  iVar1 = poolManagementData;
  if (lVar2 < 0) {
    lVar2 = 0;
  }
  uVar4 = (undefined2)lVar2;
  if (0x10000 < lVar2) {
    uVar4 = 0;
  }
  *(undefined2 *)(uVar5 * 2 + uVar6 * 0x40 + *(int *)(poolManagementData + 0x10)) = uVar4;
  *(undefined2 *)(uVar6 * 2 + uVar5 * 0x40 + *(int *)(iVar1 + 0x10)) = uVar4;
  uVar3 = 1 << (uVar5 & 0x1f);
  node1->connectionStatus = node1->connectionStatus | uVar3;
  uVar5 = 1 << (uVar6 & 0x1f);
  node2->connectionStatus = node2->connectionStatus | uVar5;
  node1->connections = node1->connections | uVar3;
  node2->connections = node2->connections | uVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1 /*$a0*/, struct PlanningNode *node2 /*$a1*/, struct PlanningNode *planningPool /*$a2*/)
 // line 392, offset 0x800972ec
	/* begin block 1 */
		// Start line: 394
		// Start offset: 0x800972EC
	/* end block 1 */
	// End offset: 0x800972EC
	// End Line: 395

	/* begin block 2 */
		// Start line: 840
	/* end block 2 */
	// End Line: 841

	/* begin block 3 */
		// Start line: 841
	/* end block 3 */
	// End Line: 842

	/* begin block 4 */
		// Start line: 842
	/* end block 4 */
	// End Line: 843

void PLANPOOL_MarkTwoNodesAsNotConnected
               (PlanningNode *node1,PlanningNode *node2,PlanningNode *planningPool)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1 << ((int)((int)node2 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  node1->connectionStatus = node1->connectionStatus | uVar1;
  uVar2 = 1 << ((int)((int)node1 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  node2->connectionStatus = node2->connectionStatus | uVar2;
  node1->connections = node1->connections & ~uVar1;
  node2->connections = node2->connections & ~uVar2;
  return;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode /*$s1*/, struct PlanningNode *planningPool /*$s6*/)
 // line 414, offset 0x8009739c
	/* begin block 1 */
		// Start line: 415
		// Start offset: 0x8009739C
		// Variables:
	// 		int i; // $s3
	// 		unsigned long connectionStatus; // $s2
	// 		unsigned long dist; // $v1
	// 		unsigned long minDist; // $s5
	// 		struct PlanningNode *returnNode; // $s4
	/* end block 1 */
	// End offset: 0x80097484
	// End Line: 443

	/* begin block 2 */
		// Start line: 894
	/* end block 2 */
	// End Line: 895

PlanningNode *
PLANPOOL_GetClosestUnexploredValidNeighbor(PlanningNode *startNode,PlanningNode *planningPool)

{
  int iVar1;
  uint uVar2;
  PlanningNode *node2;
  uint uVar3;
  int iVar4;
  PlanningNode *pPVar5;
  uint uVar6;
  
  uVar6 = 0xffffffff;
  pPVar5 = (PlanningNode *)0x0;
  if (startNode != (PlanningNode *)0x0) {
    uVar3 = startNode->connectionStatus;
    iVar4 = 0;
    node2 = planningPool;
    if (*(char *)(poolManagementData + 1) != '\0') {
      do {
        if ((uVar3 & 1) == 0) {
          iVar1 = PLANPOOL_AppropriatePair(startNode,node2);
          if (iVar1 == 0) {
            PLANPOOL_MarkTwoNodesAsNotConnected(startNode,node2,planningPool);
          }
          else {
            uVar2 = MATH3D_LengthXYZ((int)(startNode->pos).x - (int)(node2->pos).x,
                                     (int)(startNode->pos).y - (int)(node2->pos).y,
                                     (int)(startNode->pos).z - (int)(node2->pos).z);
            if (uVar2 < uVar6) {
              pPVar5 = node2;
              uVar6 = uVar2;
            }
          }
        }
        uVar3 = uVar3 >> 1;
        iVar4 = iVar4 + 1;
        node2 = node2 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(poolManagementData + 1));
    }
  }
  return pPVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANPOOL_ChangeNodePosition(struct _Position *newPos /*$t0*/, struct PlanningNode *nodeToChange /*$a1*/, struct PlanningNode *planningPool /*$a2*/)
 // line 450, offset 0x800974ac
	/* begin block 1 */
		// Start line: 451
		// Start offset: 0x800974AC
		// Variables:
	// 		int i; // $a0
	// 		unsigned char nodeToChangeMask; // $v1
	/* end block 1 */
	// End offset: 0x8009755C
	// End Line: 468

	/* begin block 2 */
		// Start line: 988
	/* end block 2 */
	// End Line: 989

void PLANPOOL_ChangeNodePosition
               (_Position *newPos,PlanningNode *nodeToChange,PlanningNode *planningPool)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = poolManagementData;
  if (nodeToChange != (PlanningNode *)0x0) {
    sVar1 = newPos->z;
    *(undefined4 *)&nodeToChange->pos = *(undefined4 *)newPos;
    (nodeToChange->pos).z = sVar1;
    nodeToChange->connectionStatus = 0;
    nodeToChange->connections = 0;
    iVar3 = 0;
    if (*(char *)(iVar2 + 1) != '\0') {
      uVar4 = ~(1 << ((int)((int)nodeToChange - (int)planningPool) * -0x49249249 >> 2 & 0x1fU) &
               0xffU);
      do {
        iVar3 = iVar3 + 1;
        planningPool->connectionStatus = planningPool->connectionStatus & uVar4;
        planningPool->connections = planningPool->connections & uVar4;
        planningPool = planningPool + 1;
      } while (iVar3 < (int)(uint)*(byte *)(iVar2 + 1));
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_AddNodeToPool(struct _Position *pos /*$t2*/, struct PlanningNode *planningPool /*$t3*/, short nodeType /*$a2*/, short nodeID /*$a3*/, long streamUnitID /*stack 16*/)
 // line 471, offset 0x80097564
	/* begin block 1 */
		// Start line: 472
		// Start offset: 0x80097564
		// Variables:
	// 		struct PlanningNode *nextAvailableNode; // $t0
	// 		int i; // $a1

		/* begin block 1.1 */
			// Start line: 478
			// Start offset: 0x80097584
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.1 */
		// End offset: 0x80097584
		// End Line: 478
	/* end block 1 */
	// End offset: 0x80097650
	// End Line: 498

	/* begin block 2 */
		// Start line: 1040
	/* end block 2 */
	// End Line: 1041

PlanningNode *
PLANPOOL_AddNodeToPool
          (_Position *pos,PlanningNode *planningPool,short nodeType,short nodeID,long streamUnitID)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  PlanningNode *pPVar7;
  
  iVar4 = poolManagementData;
  pPVar7 = (PlanningNode *)0x0;
  if (*(byte *)(poolManagementData + 1) < 0x20) {
    sVar2 = pos->z;
    sVar3 = pos->x;
    pPVar7 = planningPool + *(byte *)(poolManagementData + 1);
    (pPVar7->pos).y = pos->y;
    (pPVar7->pos).z = sVar2;
    (pPVar7->pos).x = sVar3;
    bVar1 = *(byte *)(iVar4 + 1);
    pPVar7->connections = 0;
    pPVar7->flags = 0;
    pPVar7->nodeType = nodeType;
    pPVar7->id = nodeID;
    pPVar7->streamUnitID = streamUnitID;
    pPVar7->connectionStatus = 1 << ((uint)bVar1 & 0x1f);
    *(char *)(iVar4 + 1) = *(char *)(iVar4 + 1) + '\x01';
    iVar4 = poolManagementData;
    iVar6 = 0;
    if (*(char *)(poolManagementData + 1) != '\0') {
      iVar5 = 0;
      do {
        *(undefined2 *)(iVar5 + (uint)*(byte *)(iVar4 + 1) * 0x40 + *(int *)(iVar4 + 0x10) + -0x40)
             = 0;
        *(undefined2 *)((uint)*(byte *)(iVar4 + 1) * 2 + iVar6 * 0x40 + *(int *)(iVar4 + 0x10) + -2)
             = 0;
        iVar6 = iVar6 + 1;
        iVar5 = iVar6 * 2;
      } while (iVar6 < (int)(uint)*(byte *)(iVar4 + 1));
    }
  }
  return pPVar7;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANPOOL_DeleteNodeFromPool(struct PlanningNode *nodeToDelete /*$a0*/, struct PlanningNode *planningPool /*$a1*/)
 // line 509, offset 0x80097658
	/* begin block 1 */
		// Start line: 511
		// Start offset: 0x80097658
		// Variables:
	// 		int indexOfNodeToDelete; // $t3
	// 		int lastNodeIndex; // $t2
	// 		long oldConnectionMask; // $v1
	// 		long newConnectionMask; // $a3
	// 		int i; // $a2
	// 		struct PlanningNode *lastNode; // $v0
	/* end block 1 */
	// End offset: 0x8009781C
	// End Line: 555

	/* begin block 2 */
		// Start line: 1132
	/* end block 2 */
	// End Line: 1133

	/* begin block 3 */
		// Start line: 1133
	/* end block 3 */
	// End Line: 1134

	/* begin block 4 */
		// Start line: 1138
	/* end block 4 */
	// End Line: 1139

void PLANPOOL_DeleteNodeFromPool(PlanningNode *nodeToDelete,PlanningNode *planningPool)

{
  PlanningNode *pPVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  
  iVar6 = 0;
  if (nodeToDelete != (PlanningNode *)0x0) {
    uVar9 = (uint)*(byte *)(poolManagementData + 1) - 1;
    pPVar1 = planningPool + uVar9;
    uVar11 = *(undefined4 *)&(pPVar1->pos).z;
    uVar12 = pPVar1->connectionStatus;
    uVar14 = pPVar1->connections;
    *(undefined4 *)&nodeToDelete->pos = *(undefined4 *)&pPVar1->pos;
    *(undefined4 *)&(nodeToDelete->pos).z = uVar11;
    nodeToDelete->connectionStatus = uVar12;
    nodeToDelete->connections = uVar14;
    uVar11 = *(undefined4 *)&pPVar1->nodeType;
    lVar13 = pPVar1->streamUnitID;
    *(undefined4 *)&nodeToDelete->cost = *(undefined4 *)&pPVar1->cost;
    *(undefined4 *)&nodeToDelete->nodeType = uVar11;
    nodeToDelete->streamUnitID = lVar13;
    iVar7 = poolManagementData;
    uVar10 = (int)((int)nodeToDelete - (int)planningPool) * -0x49249249 >> 2;
    uVar8 = 1 << (uVar10 & 0x1f);
    uVar4 = 1 << (uVar9 & 0x1f);
    if (0 < (int)((uint)*(byte *)(poolManagementData + 1) - 1)) {
      do {
        uVar5 = planningPool->connectionStatus;
        uVar2 = uVar5 | uVar8;
        if ((uVar5 & uVar4) == 0) {
          uVar2 = uVar5 & ~uVar8;
        }
        planningPool->connectionStatus = uVar2;
        uVar5 = planningPool->connections;
        planningPool->connectionStatus = planningPool->connectionStatus & ~uVar4;
        uVar2 = uVar5 | uVar8;
        if ((uVar5 & uVar4) == 0) {
          uVar2 = uVar5 & ~uVar8;
        }
        planningPool->connections = uVar2;
        iVar6 = iVar6 + 1;
        planningPool->connections = planningPool->connections & ~uVar4;
        planningPool = planningPool + 1;
      } while (iVar6 < (int)((uint)*(byte *)(iVar7 + 1) - 1));
    }
    iVar6 = poolManagementData;
    iVar7 = 0;
    if (0 < (int)((uint)*(byte *)(poolManagementData + 1) - 1)) {
      do {
        *(undefined2 *)(iVar7 * 2 + uVar10 * 0x40 + *(int *)(iVar6 + 0x10)) =
             *(undefined2 *)(iVar7 * 2 + uVar9 * 0x40 + *(int *)(iVar6 + 0x10));
        iVar3 = iVar7 * 0x40 + *(int *)(iVar6 + 0x10);
        *(undefined2 *)(uVar10 * 2 + iVar3) = *(undefined2 *)(uVar9 * 2 + iVar3);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)((uint)*(byte *)(iVar6 + 1) - 1));
    }
    *(char *)(poolManagementData + 1) = *(char *)(poolManagementData + 1) + -1;
  }
  return;
}





