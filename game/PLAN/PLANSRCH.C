#include "THISDUST.H"
#include "PLANSRCH.H"


// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANSRCH_FindNodeToExpand(struct PlanningNode *planningPool /*$a0*/, struct PlanningNode *goalNode /*$s5*/, int validNodeTypes /*$s6*/)
 // line 78, offset 0x80099534
	/* begin block 1 */
		// Start line: 79
		// Start offset: 0x80099534
		// Variables:
	// 		int i; // $s2
	// 		struct PlanningNode *nodeToExpand; // $s3
	// 		unsigned long bestValueSoFar; // $s4
	// 		unsigned long valueForCurrentNode; // $v1
	// 		struct PlanningNode *currentNode; // $s1
	/* end block 1 */
	// End offset: 0x80099620
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
PLANSRCH_ExpandNode(PlanningNode *planningPool,PlanningNode *goalNode,int validNodeTypes)

{
  long lVar1;
  u_int uVar2;
  PlanningNode *pPVar3;
  int iVar4;
  PlanningNode *pPVar5;
  u_int uVar6;
  
  uVar6 = 0xffffffff;
  iVar4 = 0;
  pPVar5 = (PlanningNode *)0x0;
  pPVar3 = planningPool;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      if ((((validNodeTypes >> ((u_int)planningPool->nodeType & 0x1f) & 1U) != 0) &&
          ((planningPool->flags & 1) != 0)) && ((planningPool->flags & 2) == 0)) {
        lVar1 = MATH3D_LengthXY((int)(pPVar3->pos).x - (int)(goalNode->pos).x,
                                (int)(planningPool->pos).y - (int)(goalNode->pos).y,
                                (int)(planningPool->pos).z - (int)(goalNode->pos).z);
        uVar2 = (u_int)planningPool->cost + lVar1;
        if (uVar2 <= uVar6) {
          pPVar5 = planningPool;
          uVar6 = uVar2;
        }
      }
      planningPool = planningPool + 1;
      iVar4 = iVar4 + 1;
      pPVar3 = pPVar3 + 1;
    } while (iVar4 < (int)(u_int)*(byte *)(poolManagementData + 1));
  }
  return pPVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANSRCH_ExpandNode(struct PlanningNode *planningPool /*$a2*/, struct PlanningNode *nodeToExpand /*$a1*/)
 // line 109, offset 0x8009964c
	/* begin block 1 */
		// Start line: 110
		// Start offset: 0x8009964C
		// Variables:
	// 		int i; // $t0
	// 		int nodeToExpandIndex; // $t2
	// 		long nodeToExpandMask; // $t1

		/* begin block 1.1 */
			// Start line: 125
			// Start offset: 0x800996E0
			// Variables:
		// 		long newCost; // $a0
		/* end block 1.1 */
		// End offset: 0x80099758
		// End Line: 140
	/* end block 1 */
	// End offset: 0x80099774
	// End Line: 144

	/* begin block 2 */
		// Start line: 251
	/* end block 2 */
	// End Line: 252

void PLANSRCH_FindNodeToExpand(PlanningNode *planningPool,PlanningNode *nodeToExpand)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;
  u_int uVar5;
  
  iVar2 = poolManagementData;
  iVar3 = 0;
  nodeToExpand->flags = nodeToExpand->flags | 2;
  uVar5 = (int)((int)nodeToExpand - (int)planningPool) * -0x49249249 >> 2;
  uVar4 = 1 << (uVar5 & 0x1f);
  if (*(char *)(iVar2 + 1) != '\0') {
    do {
      if (((((planningPool->connectionStatus & uVar4) != 0) &&
           ((planningPool->connections & uVar4) != 0)) && (planningPool != nodeToExpand)) &&
         ((iVar2 = (u_int)nodeToExpand->cost +
                   (int)*(short *)(iVar3 * 2 + uVar5 * 0x40 + *(int *)(iVar2 + 0x10)),
          (planningPool->flags & 1) == 0 || (iVar2 < (int)(u_int)planningPool->cost)))) {
        planningPool->parent = (ushort)uVar5;
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
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
      iVar2 = poolManagementData;
    } while (iVar3 < (int)(u_int)*(byte *)(poolManagementData + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANSRCH_InitNodesForSearch(struct PlanningNode *planningPool /*$a0*/)
 // line 148, offset 0x8009977c
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8009977C
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800997C0
	// End Line: 158

	/* begin block 2 */
		// Start line: 368
	/* end block 2 */
	// End Line: 369

	/* begin block 3 */
		// Start line: 369
	/* end block 3 */
	// End Line: 370

	/* begin block 4 */
		// Start line: 371
	/* end block 4 */
	// End Line: 372

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
    } while (iVar2 < (int)(u_int)*(byte *)(iVar1 + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANSRCH_FindPathInGraph(struct PlanningNode *planningPool /*$s2*/, struct PlanningNode *startNode /*$s0*/, struct PlanningNode *goalNode /*$s1*/, int validNodeTypes /*$s3*/)
 // line 169, offset 0x800997c8
	/* begin block 1 */
		// Start line: 170
		// Start offset: 0x800997C8
		// Variables:
	// 		struct PlanningNode *nodeToExpand; // $v0
	/* end block 1 */
	// End offset: 0x800998E4
	// End Line: 203

	/* begin block 2 */
		// Start line: 415
	/* end block 2 */
	// End Line: 416

PlanningNode *
PLANAPI_FindPathInGraphToTarget
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
    while (nodeToExpand = PLANSRCH_ExpandNode(planningPool,goalNode,validNodeTypes),
          nodeToExpand != (PlanningNode *)0x0) {
      if (nodeToExpand == goalNode) {
        return nodeToExpand;
      }
      PLANSRCH_FindNodeToExpand(planningPool,nodeToExpand);
    }
  }
  return (PlanningNode *)0x0;
}





