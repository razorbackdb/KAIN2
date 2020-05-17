#include "THISDUST.H"
#include "PLANSRCH.H"


// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANSRCH_FindNodeToExpand(struct PlanningNode *planningPool /*$a0*/, struct PlanningNode *goalNode /*$s5*/, int validNodeTypes /*$s6*/)
 // line 78, offset 0x80099d78
	/* begin block 1 */
		// Start line: 79
		// Start offset: 0x80099D78
		// Variables:
	// 		int i; // $s2
	// 		struct PlanningNode *nodeToExpand; // $s3
	// 		unsigned long bestValueSoFar; // $s4
	// 		unsigned long valueForCurrentNode; // $v1
	// 		struct PlanningNode *currentNode; // $s1
	/* end block 1 */
	// End offset: 0x80099E64
	// End Line: 102

	/* begin block 2 */
		// Start line: 156
	/* end block 2 */
	// End Line: 157

	/* begin block 3 */
		// Start line: 162
	/* end block 3 */
	// End Line: 163

PlanningNode *
PLANSRCH_FindNodeToExpand(PlanningNode *planningPool,PlanningNode *goalNode,int validNodeTypes)

{
  long lVar1;
  uint uVar2;
  PlanningNode *pPVar3;
  int iVar4;
  PlanningNode *pPVar5;
  uint uVar6;
  
  uVar6 = 0xffffffff;
  iVar4 = 0;
  pPVar5 = (PlanningNode *)0x0;
  pPVar3 = planningPool;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      if ((((validNodeTypes >> ((uint)planningPool->nodeType & 0x1f) & 1U) != 0) &&
          ((planningPool->flags & 1) != 0)) && ((planningPool->flags & 2) == 0)) {
        lVar1 = MATH3D_LengthXYZ((int)(pPVar3->pos).x - (int)(goalNode->pos).x,
                                 (int)(planningPool->pos).y - (int)(goalNode->pos).y,
                                 (int)(planningPool->pos).z - (int)(goalNode->pos).z);
        uVar2 = (uint)planningPool->cost + lVar1;
        if (uVar2 <= uVar6) {
          pPVar5 = planningPool;
          uVar6 = uVar2;
        }
      }
      planningPool = planningPool + 1;
      iVar4 = iVar4 + 1;
      pPVar3 = pPVar3 + 1;
    } while (iVar4 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return pPVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANSRCH_ExpandNode(struct PlanningNode *planningPool /*$a2*/, struct PlanningNode *nodeToExpand /*$a1*/)
 // line 109, offset 0x80099e90
	/* begin block 1 */
		// Start line: 110
		// Start offset: 0x80099E90
		// Variables:
	// 		int i; // $t0
	// 		int connectionStatus; // $t2
	// 		int connections; // $t1
	// 		int nodeToExpandIndex; // $t3

		/* begin block 1.1 */
			// Start line: 124
			// Start offset: 0x80099F10
			// Variables:
		// 		long newCost; // $a0
		/* end block 1.1 */
		// End offset: 0x80099F88
		// End Line: 139
	/* end block 1 */
	// End offset: 0x80099FAC
	// End Line: 145

	/* begin block 2 */
		// Start line: 251
	/* end block 2 */
	// End Line: 252

void PLANSRCH_ExpandNode(PlanningNode *planningPool,PlanningNode *nodeToExpand)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = poolManagementData;
  iVar3 = 0;
  uVar5 = nodeToExpand->connectionStatus;
  uVar4 = nodeToExpand->connections;
  nodeToExpand->flags = nodeToExpand->flags | 2;
  iVar6 = (int)((int)nodeToExpand - (int)planningPool) * -0x49249249 >> 2;
  if (*(char *)(iVar2 + 1) != '\0') {
    do {
      if (((((uVar5 & 1) != 0) && ((uVar4 & 1) != 0)) && (planningPool != nodeToExpand)) &&
         ((iVar2 = (uint)nodeToExpand->cost +
                   (int)*(short *)(iVar3 * 2 + iVar6 * 0x40 + *(int *)(iVar2 + 0x10)),
          (planningPool->flags & 1) == 0 || (iVar2 < (int)(uint)planningPool->cost)))) {
        planningPool->parent = (ushort)iVar6;
        if (iVar2 < -0x7fff) {
          iVar2 = -0x7fff;
        }
        uVar1 = (ushort)iVar2;
        if (0x7fff < iVar2) {
          uVar1 = 0x7fff;
        }
        planningPool->cost = uVar1;
        planningPool->flags = planningPool->flags | 1;
      }
      uVar5 = (int)uVar5 >> 1;
      uVar4 = (int)uVar4 >> 1;
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
      iVar2 = poolManagementData;
    } while (iVar3 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANSRCH_InitNodesForSearch(struct PlanningNode *planningPool /*$a0*/)
 // line 149, offset 0x80099fb4
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x80099FB4
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80099FF8
	// End Line: 159

	/* begin block 2 */
		// Start line: 369
	/* end block 2 */
	// End Line: 370

	/* begin block 3 */
		// Start line: 370
	/* end block 3 */
	// End Line: 371

	/* begin block 4 */
		// Start line: 372
	/* end block 4 */
	// End Line: 373

void PLANSRCH_InitNodesForSearch(PlanningNode *planningPool)

{
  int iVar1;
  int iVar2;
  
  iVar1 = poolManagementData;
  iVar2 = 0;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      iVar2 = iVar2 + 1;
      planningPool->cost = 0;
      planningPool->parent = 0;
      planningPool->flags = planningPool->flags & 0xfffc;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(uint)*(byte *)(iVar1 + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANSRCH_FindPathInGraph(struct PlanningNode *planningPool /*$s2*/, struct PlanningNode *startNode /*$s0*/, struct PlanningNode *goalNode /*$s1*/, int validNodeTypes /*$s3*/)
 // line 170, offset 0x8009a000
	/* begin block 1 */
		// Start line: 171
		// Start offset: 0x8009A000
		// Variables:
	// 		struct PlanningNode *nodeToExpand; // $v0
	/* end block 1 */
	// End offset: 0x8009A11C
	// End Line: 204

	/* begin block 2 */
		// Start line: 416
	/* end block 2 */
	// End Line: 417

PlanningNode *
PLANSRCH_FindPathInGraph
          (PlanningNode *planningPool,PlanningNode *startNode,PlanningNode *goalNode,
          int validNodeTypes)

{
  int iVar1;
  PlanningNode *nodeToExpand;
  ushort uVar2;
  
  if ((goalNode->connections &
      ~(1 << ((int)((int)goalNode - (int)planningPool) * -0x49249249 >> 2 & 0x1fU))) != 0) {
    PLANSRCH_InitNodesForSearch(planningPool);
    uVar2 = (ushort)((int)((int)startNode - (int)planningPool) * -0x49249249 >> 2);
    startNode->parent = uVar2;
    startNode->cost = 0;
    startNode->flags = startNode->flags | 1;
    iVar1 = PLANPOOL_AreTwoNodesConnected(startNode,goalNode,planningPool);
    if (iVar1 != 0) {
      goalNode->parent = uVar2;
      return goalNode;
    }
    while (nodeToExpand = PLANSRCH_FindNodeToExpand(planningPool,goalNode,validNodeTypes),
          nodeToExpand != (PlanningNode *)0x0) {
      if (nodeToExpand == goalNode) {
        return nodeToExpand;
      }
      PLANSRCH_ExpandNode(planningPool,nodeToExpand);
    }
  }
  return (PlanningNode *)0x0;
}





