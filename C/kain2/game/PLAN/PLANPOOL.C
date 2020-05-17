#include "THISDUST.H"
#include "PLANPOOL.H"


// decompiled code
// original method signature: 
// int /*$ra*/ PLANPOOL_NumNodesInPlan(struct PlanningNode *goalNode /*$a0*/, struct PlanningNode *planningPool /*$a1*/)
 // line 122, offset 0x800991d4
	/* begin block 1 */
		// Start line: 124
		// Start offset: 0x800991D4
		// Variables:
	// 		struct PlanningNode *currentNode; // $a0
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x80099218
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
 // line 137, offset 0x80099220
	/* begin block 1 */
		// Start line: 139
		// Start offset: 0x80099220
		// Variables:
	// 		int numBitsSet; // $v1
	/* end block 1 */
	// End offset: 0x80099238
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
 // line 150, offset 0x80099240
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
 // line 158, offset 0x80099264
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
 // line 177, offset 0x80099288
	/* begin block 1 */
		// Start line: 178
		// Start offset: 0x80099288
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800992D0
	// End Line: 186

	/* begin block 2 */
		// Start line: 354
	/* end block 2 */
	// End Line: 355

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
 // line 189, offset 0x800992d8
	/* begin block 1 */
		// Start line: 190
		// Start offset: 0x800992D8
		// Variables:
	// 		int i; // $a2
	// 		int numNodesOfType; // $v1
	/* end block 1 */
	// End offset: 0x8009931C
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
 // line 201, offset 0x80099324
	/* begin block 1 */
		// Start line: 202
		// Start offset: 0x80099324
		// Variables:
	// 		int i; // $a2
	// 		int numNodesOfSource; // $v1
	/* end block 1 */
	// End offset: 0x8009936C
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
// struct PlanningNode * /*$ra*/ PLANPOOL_GetNodeWithID(struct PlanningNode *planningPool /*$a0*/, int type /*$a1*/, int id /*$a2*/, long suID /*$a3*/)
 // line 213, offset 0x80099374
	/* begin block 1 */
		// Start line: 215
		// Start offset: 0x80099374
		// Variables:
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x800993D8
	// End Line: 224

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

PlanningNode * PLANPOOL_GetNodeWithID(PlanningNode *planningPool,int type,int id,long suID)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0) {
    do {
      if ((((uint)planningPool->nodeType == type) && ((uint)planningPool->id == id)) &&
         (planningPool->streamUnitID == suID)) {
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
 // line 230, offset 0x800993e0
	/* begin block 1 */
		// Start line: 231
		// Start offset: 0x800993E0
		// Variables:
	// 		int i; // $s1
	// 		unsigned long zDiff; // $v0
	// 		unsigned long minZDiff; // $s4
	// 		struct PlanningNode *returnNode; // $s2
	/* end block 1 */
	// End offset: 0x80099490
	// End Line: 247

	/* begin block 2 */
		// Start line: 451
	/* end block 2 */
	// End Line: 452

	/* begin block 3 */
		// Start line: 456
	/* end block 3 */
	// End Line: 457

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
 // line 251, offset 0x800994b4
	/* begin block 1 */
		// Start line: 252
		// Start offset: 0x800994B4
		// Variables:
	// 		int i; // $s2
	// 		long dist; // $v1
	// 		long minDist; // $s4
	// 		struct PlanningNode *closestNode; // $s3
	/* end block 1 */
	// End offset: 0x8009958C
	// End Line: 270

	/* begin block 2 */
		// Start line: 514
	/* end block 2 */
	// End Line: 515

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
 // line 277, offset 0x800995b4
	/* begin block 1 */
		// Start line: 278
		// Start offset: 0x800995B4
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
	// End offset: 0x80099714
	// End Line: 345

	/* begin block 2 */
		// Start line: 595
	/* end block 2 */
	// End Line: 596

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
 // line 350, offset 0x80099728
	/* begin block 1 */
		// Start line: 351
		// Start offset: 0x80099728
		// Variables:
	// 		long node2Mask; // $a0
	/* end block 1 */
	// End offset: 0x80099790
	// End Line: 361

	/* begin block 2 */
		// Start line: 741
	/* end block 2 */
	// End Line: 742

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
// void /*$ra*/ PLANPOOL_MarkTwoNodesAsConnected(struct PlanningNode *node1 /*$s1*/, struct PlanningNode *node2 /*$a1*/, struct PlanningNode *planningPool /*$a2*/)
 // line 365, offset 0x80099798
	/* begin block 1 */
		// Start line: 366
		// Start offset: 0x80099798
		// Variables:
	// 		int node1Index; // $s2
	// 		int node2Index; // $s0
	/* end block 1 */
	// End offset: 0x80099840
	// End Line: 377

	/* begin block 2 */
		// Start line: 773
	/* end block 2 */
	// End Line: 774

void PLANPOOL_MarkTwoNodesAsConnected
               (PlanningNode *node1,PlanningNode *node2,PlanningNode *planningPool)

{
  long lVar1;
  uint uVar2;
  undefined2 uVar3;
  uint uVar4;
  
  uVar4 = (int)((int)node2 - (int)planningPool) * -0x49249249 >> 2;
  lVar1 = MATH3D_DistanceBetweenPositions((_Position *)node1,(_Position *)node2);
  if (lVar1 < 0) {
    lVar1 = 0;
  }
  uVar3 = (undefined2)lVar1;
  if (0x10000 < lVar1) {
    uVar3 = 0;
  }
  uVar2 = 1 << (uVar4 & 0x1f);
  *(undefined2 *)
   (uVar4 * 2 +
   ((int)((int)node1 - (int)planningPool) * -0x49249249 >> 2) * 0x40 +
   *(int *)(poolManagementData + 0x10)) = uVar3;
  node1->connectionStatus = node1->connectionStatus | uVar2;
  node1->connections = node1->connections | uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLANPOOL_MarkTwoNodesAsNotConnected(struct PlanningNode *node1 /*$a0*/, struct PlanningNode *node2 /*$a1*/, struct PlanningNode *planningPool /*$a2*/)
 // line 393, offset 0x80099894
	/* begin block 1 */
		// Start line: 395
		// Start offset: 0x80099894
	/* end block 1 */
	// End offset: 0x80099894
	// End Line: 396

	/* begin block 2 */
		// Start line: 856
	/* end block 2 */
	// End Line: 857

	/* begin block 3 */
		// Start line: 857
	/* end block 3 */
	// End Line: 858

	/* begin block 4 */
		// Start line: 858
	/* end block 4 */
	// End Line: 859

void PLANPOOL_MarkTwoNodesAsNotConnected
               (PlanningNode *node1,PlanningNode *node2,PlanningNode *planningPool)

{
  uint uVar1;
  
  uVar1 = 1 << ((int)((int)node2 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  node1->connectionStatus = node1->connectionStatus | uVar1;
  node1->connections = node1->connections & ~uVar1;
  return;
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLANPOOL_GetClosestUnexploredValidNeighbor(struct PlanningNode *startNode /*$s1*/, struct PlanningNode *planningPool /*$s6*/)
 // line 415, offset 0x800998f0
	/* begin block 1 */
		// Start line: 416
		// Start offset: 0x800998F0
		// Variables:
	// 		int i; // $s3
	// 		unsigned long connectionStatus; // $s2
	// 		unsigned long dist; // $v1
	// 		unsigned long minDist; // $s5
	// 		struct PlanningNode *returnNode; // $s4
	/* end block 1 */
	// End offset: 0x800999D8
	// End Line: 444

	/* begin block 2 */
		// Start line: 908
	/* end block 2 */
	// End Line: 909

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
 // line 451, offset 0x80099a00
	/* begin block 1 */
		// Start line: 452
		// Start offset: 0x80099A00
		// Variables:
	// 		int i; // $a0
	// 		unsigned char nodeToChangeMask; // $v1
	/* end block 1 */
	// End offset: 0x80099AB0
	// End Line: 469

	/* begin block 2 */
		// Start line: 1002
	/* end block 2 */
	// End Line: 1003

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
 // line 472, offset 0x80099ab8
	/* begin block 1 */
		// Start line: 473
		// Start offset: 0x80099AB8
		// Variables:
	// 		struct PlanningNode *nextAvailableNode; // $t0
	// 		int i; // $a1

		/* begin block 1.1 */
			// Start line: 479
			// Start offset: 0x80099AD8
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $a1
		/* end block 1.1 */
		// End offset: 0x80099AD8
		// End Line: 479
	/* end block 1 */
	// End offset: 0x80099BA4
	// End Line: 499

	/* begin block 2 */
		// Start line: 1054
	/* end block 2 */
	// End Line: 1055

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
 // line 510, offset 0x80099bac
	/* begin block 1 */
		// Start line: 512
		// Start offset: 0x80099BAC
		// Variables:
	// 		int indexOfNodeToDelete; // $t3
	// 		int lastNodeIndex; // $t2
	// 		long oldConnectionMask; // $v1
	// 		long newConnectionMask; // $a3
	// 		int i; // $a2
	// 		struct PlanningNode *lastNode; // $v0
	/* end block 1 */
	// End offset: 0x80099D70
	// End Line: 556

	/* begin block 2 */
		// Start line: 1146
	/* end block 2 */
	// End Line: 1147

	/* begin block 3 */
		// Start line: 1147
	/* end block 3 */
	// End Line: 1148

	/* begin block 4 */
		// Start line: 1152
	/* end block 4 */
	// End Line: 1153

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





