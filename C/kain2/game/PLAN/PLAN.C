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

long PLAN_CalcMinDistFromExistingNodes(_Position *param_1,PlanningNode *param_2,int param_3)

{
  PlanningNode *pPVar1;
  long lVar2;
  
  pPVar1 = PLANPOOL_GetClosestNode(param_1,param_2,(char)param_3);
  if (pPVar1 == (PlanningNode *)0x0) {
    lVar2 = 0x7fffffff;
  }
  else {
    if (param_3 != 0) {
                    /* WARNING: Subroutine does not return */
      MATH3D_LengthXYZ((int)param_1->x - (int)(pPVar1->pos).x,(int)param_1->y - (int)(pPVar1->pos).y
                       ,(int)param_1->z - (int)(pPVar1->pos).z);
    }
    lVar2 = MATH3D_LengthXY((int)param_1->x - (int)(pPVar1->pos).x,
                            (int)param_1->y - (int)(pPVar1->pos).y);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PLAN_UpdatePlanMkrNodes(PlanningNode *planningPool,_Position *playerPos)

{
  ushort uVar1;
  long suID;
  long lVar2;
  PlanningNode *nodeToDelete;
  int type;
  _Position *p_Var3;
  _Position *pos;
  uint id;
  int iVar4;
  int iVar5;
  char **ppcVar6;
  FontChar *pFVar7;
  int local_30;
  
  pFVar7 = fontTracker.font_buffer + 0x5c;
  ppcVar6 = (char **)&fontTracker.font_buffer[0x5d].y;
  local_30 = 0;
  do {
    if ((*(short *)(ppcVar6 + -1) == 2) && (suID = MEMPACK_MemoryValidFunc(*ppcVar6), suID != 0)) {
      suID = *(long *)pFVar7;
      pos = *(_Position **)(*ppcVar6 + 0xe4);
      iVar5 = *(int *)(*ppcVar6 + 0xe0);
      if ((iVar5 != 0) && (iVar4 = 0, 0 < iVar5)) {
        p_Var3 = pos + 1;
        do {
          lVar2 = MATH3D_LengthXY((int)pos->x - (int)playerPos->x,
                                  (int)p_Var3[-1].y - (int)playerPos->y);
          type = (int)playerPos->z - (int)p_Var3[-1].z;
          if (type < 0) {
            type = -type;
          }
          if ((lVar2 < 8000) && (type < 4000)) {
            uVar1 = p_Var3->x;
            id = (int)p_Var3->x & 0xffff0fff;
            if ((uVar1 & 0x1000) == 0) {
              type = 0xc;
              if (((((int)p_Var3->x & 0x8000U) == 0) && (type = 0x1c, (uVar1 & 0x4000) == 0)) &&
                 (type = 4, (uVar1 & 0x2000) != 0)) {
                type = 0x14;
              }
              nodeToDelete = PLANPOOL_GetNodeWithID(planningPool,type,id,suID);
              if (nodeToDelete == (PlanningNode *)0x0) {
                PLANPOOL_AddNodeToPool(pos,planningPool,(short)type,(short)id,*(long *)pFVar7);
              }
            }
          }
          iVar4 = iVar4 + 1;
          p_Var3 = (_Position *)&p_Var3[1].y;
          pos = (_Position *)&pos[1].y;
        } while (iVar4 < iVar5);
      }
    }
    ppcVar6 = ppcVar6 + 0x10;
    pFVar7 = (FontChar *)&pFVar7[10].c;
    local_30 = local_30 + 1;
  } while (local_30 < 0x10);
  iVar5 = 0;
  nodeToDelete = planningPool;
  if (*(char *)(_poolManagementData + 1) != '\0') {
    do {
      if ((nodeToDelete->nodeType & 7) == 4) {
        suID = MATH3D_LengthXY((int)(nodeToDelete->pos).x - (int)playerPos->x,
                               (int)(nodeToDelete->pos).y - (int)playerPos->y);
        iVar4 = (int)playerPos->z - (int)(nodeToDelete->pos).z;
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if ((10000 < suID) || (5000 < iVar4)) {
          PLANPOOL_DeleteNodeFromPool(nodeToDelete,planningPool);
        }
      }
      iVar5 = iVar5 + 1;
      nodeToDelete = nodeToDelete + 1;
    } while (iVar5 < (int)(uint)*(byte *)(_poolManagementData + 1));
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

void PLAN_UpdatePlayerNode(PlanningNode *param_1,undefined4 *param_2)

{
  PlanningNode *pPVar1;
  int iVar2;
  long local_30;
  short local_28;
  short local_26;
  short local_24;
  ushort local_20 [4];
  
  pPVar1 = PLANPOOL_GetFirstNodeOfSource(param_1,'\x01');
  if (pPVar1 != (PlanningNode *)0x0) {
    iVar2 = PLANCOLL_CheckUnderwaterPoint((short *)param_2);
    if (iVar2 == -1) {
      local_28 = *(short *)param_2;
      local_26 = *(short *)((int)param_2 + 2);
      local_24 = *(short *)(param_2 + 1);
      iVar2 = PLANCOLL_FindTerrainHitFinal
                        ((_PlanCollideInfo *)&local_30,(int *)local_20,0x100,-0x280,0,5);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)*(short *)param_2 - (int)(pPVar1->pos).x,
                         (int)*(short *)((int)param_2 + 2) - (int)(pPVar1->pos).y,
                         (int)*(short *)(param_2 + 1) - (int)(pPVar1->pos).z);
      }
      PLANPOOL_ChangeNodePosition((undefined4 *)(&local_30 + 8),(undefined4 *)pPVar1,(int)param_1);
      pPVar1->nodeType = (ushort)(((uint)local_20[0] & 3) << 3) | 1;
      pPVar1->streamUnitID = local_30;
    }
    else {
      PLANPOOL_ChangeNodePosition(param_2,(undefined4 *)pPVar1,(int)param_1);
      pPVar1->nodeType = 0x19;
      pPVar1->streamUnitID = iVar2;
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

void PLAN_AddRandomNode(PlanningNode *planningPool,_Position *playerPos)

{
                    /* WARNING: Subroutine does not return */
  rand();
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
  
  nodeToDelete = PLANPOOL_GetFirstNodeOfSource(planningPool,'\0');
  PLANPOOL_DeleteNodeFromPool(nodeToDelete,planningPool);
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PLAN_DeleteOutOfRangeNodesOfSource
               (PlanningNode *planningPool,_Position *playerPos,int nodeSourceToCheck,
               long removeDist)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(_poolManagementData + 1) != '\0') {
    do {
      if (((uint)planningPool->nodeType & 7) == nodeSourceToCheck) {
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)playerPos->x - (int)(planningPool->pos).x,
                         (int)playerPos->y - (int)(planningPool->pos).y,
                         (int)playerPos->z - (int)(planningPool->pos).z);
      }
      iVar1 = iVar1 + 1;
      planningPool = planningPool + 1;
    } while (iVar1 < (int)(uint)*(byte *)(_poolManagementData + 1));
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PLAN_AddOrRemoveRandomNodes(PlanningNode *planningPool,_Position *playerPos)

{
  int iVar1;
  
  iVar1 = (uint)*(byte *)(_poolManagementData + 1) - 0x10;
  if (iVar1 < 0) {
    PLAN_AddRandomNode(planningPool,playerPos);
  }
  else {
    if (0 < iVar1) {
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PLAN_AddInitialNodes(PlanningNode *planningPool,_Instance *player)

{
  short sVar1;
  int iVar2;
  _PlanCollideInfo _Stack40;
  
  _Stack40.collidePos.x = (player->position).x;
  _Stack40.collidePos.y = (player->position).y;
  _Stack40.collidePos.z = (player->position).z;
  PLANCOLL_FindTerrainHitFinal(&_Stack40,(int *)0x0,0x100,-0x400,0,0);
  PLANPOOL_AddNodeToPool(&_Stack40.collidePos,planningPool,1,0,player->currentStreamUnitID);
  PLAN_UpdatePlanMkrNodes(planningPool,&player->position);
  iVar2 = _poolManagementData;
  sVar1 = (player->position).z;
  *(undefined4 *)(_poolManagementData + 2) = *(undefined4 *)&player->position;
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void PLAN_AddOrRemoveNodes(PlanningNode *planningPool,_Instance *player)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(player->position).x - (int)*(short *)(_poolManagementData + 2),
                   (int)(player->position).y - (int)*(short *)(_poolManagementData + 4),
                   (int)(player->position).z - (int)*(short *)(_poolManagementData + 6));
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

PlanningNode * PLAN_FindNodeMostInNeedOfConnectivityExpansion(PlanningNode *planningPool)

{
  int iVar1;
  PlanningNode *pPVar2;
  PlanningNode *in_a1;
  short in_a2;
  short in_a3;
  long local_18;
  int iVar3;
  PlanningNode *pPVar4;
  int iVar5;
  
  iVar5 = 0xffff;
  iVar3 = 0;
  pPVar4 = (PlanningNode *)0x0;
  if (*(char *)(_poolManagementData + 1) != '\0') {
    do {
      iVar1 = PLANPOOL_NumConnectionsForNode(planningPool);
      if ((iVar1 < iVar5) &&
         (pPVar2 = PLANPOOL_AddNodeToPool((_Position *)planningPool,in_a1,in_a2,in_a3,local_18),
         pPVar2 != (PlanningNode *)(uint)*(byte *)(_poolManagementData + 1))) {
        pPVar4 = planningPool;
        iVar5 = iVar1;
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
    } while (iVar3 < (int)(uint)*(byte *)(_poolManagementData + 1));
  }
  return pPVar4;
}





