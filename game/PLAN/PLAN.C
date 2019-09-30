#include "THISDUST.H"
#include "PLAN.H"


// decompiled code
// original method signature: 
// long /*$ra*/ PLAN_CalcMinDistFromExistingNodes(struct _Position *pos /*$s1*/, struct PlanningNode *planningPool /*$a1*/, char distanceType /*$a2*/)
 // line 129, offset 0x80096b14
	/* begin block 1 */
		// Start line: 130
		// Start offset: 0x80096B14
		// Variables:
	// 		struct PlanningNode *closestNode; // $a2
	// 		long minDist; // $v0
	/* end block 1 */
	// End offset: 0x80096BA0
	// End Line: 148

	/* begin block 2 */
		// Start line: 258
	/* end block 2 */
	// End Line: 259

long PLAN_CalcMinDistFromExistingNodes(_Position *pos,PlanningNode *planningPool,char distanceType)

{
  PlanningNode *pPVar1;
  
  pPVar1 = PLANPOOL_GetClosestNode(pos,planningPool,distanceType);
  if (pPVar1 == (PlanningNode *)0x0) {
    return 0x7fffffff;
  }
  if (distanceType == '\0') {
                    /* WARNING: Subroutine does not return */
    MATH3D_LengthXY((int)pos->x - (int)(pPVar1->pos).x,(int)pos->y - (int)(pPVar1->pos).y);
  }
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)pos->x - (int)(pPVar1->pos).x,(int)pos->y - (int)(pPVar1->pos).y,
                   (int)pos->z - (int)(pPVar1->pos).z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_UpdatePlanMkrNodes(struct PlanningNode *planningPool /*stack 0*/, struct _Position *playerPos /*$fp*/)
 // line 158, offset 0x80096bb4
	/* begin block 1 */
		// Start line: 159
		// Start offset: 0x80096BB4
		// Variables:
	// 		int i; // $s4
	// 		int d; // stack offset -48
	// 		long zDiff; // $v1
	// 		struct _StreamUnit *streamUnit; // $s7

		/* begin block 1.1 */
			// Start line: 169
			// Start offset: 0x80096C20
			// Variables:
		// 		int numPlanMkrs; // $s5
		// 		struct _PlanMkr *planMkr; // $s3

			/* begin block 1.1.1 */
				// Start line: 181
				// Start offset: 0x80096C8C
				// Variables:
			// 		unsigned short nodeType; // $a1
			// 		unsigned short nodeID; // $a2
			/* end block 1.1.1 */
			// End offset: 0x80096CF8
			// End Line: 202
		/* end block 1.1 */
		// End offset: 0x80096D0C
		// End Line: 205
	/* end block 1 */
	// End offset: 0x80096DCC
	// End Line: 220

	/* begin block 2 */
		// Start line: 320
	/* end block 2 */
	// End Line: 321

void PLAN_UpdatePlanMkrNodes(PlanningNode *planningPool,_Position *playerPos)

{
  long lVar1;
  _PlanMkr *p_Var2;
  int iVar3;
  Level **ppLVar4;
  int local_30;
  
  ppLVar4 = &StreamTracker.StreamList[0].level;
  local_30 = 0;
  do {
    if ((*(short *)(ppLVar4 + -1) == 2) &&
       (lVar1 = MEMPACK_MemoryValidFunc((char *)*ppLVar4), lVar1 != 0)) {
      iVar3 = (*ppLVar4)->NumberOfPlanMarkers;
      p_Var2 = (*ppLVar4)->PlanMarkerList;
      if ((iVar3 != 0) && (0 < iVar3)) {
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXY((int)(p_Var2->pos).x - (int)playerPos->x,
                        (int)(p_Var2->pos).y - (int)playerPos->y);
      }
    }
    ppLVar4 = ppLVar4 + 0x10;
    local_30 = local_30 + 1;
    if (0xf < local_30) {
      iVar3 = 0;
      if (*(char *)(poolManagementData + 1) != '\0') {
        do {
          if ((planningPool->nodeType & 7) == 4) {
                    /* WARNING: Subroutine does not return */
            MATH3D_LengthXY((int)(planningPool->pos).x - (int)playerPos->x,
                            (int)(planningPool->pos).y - (int)playerPos->y);
          }
          iVar3 = iVar3 + 1;
          planningPool = planningPool + 1;
        } while (iVar3 < (int)(uint)*(byte *)(poolManagementData + 1));
      }
      return;
    }
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_UpdatePlayerNode(struct PlanningNode *planningPool /*$s3*/, struct _Position *playerPos /*$s2*/)
 // line 225, offset 0x80096dfc
	/* begin block 1 */
		// Start line: 226
		// Start offset: 0x80096DFC
		// Variables:
	// 		struct PlanningNode *playerNode; // $s1
	// 		int nodePlacement; // stack offset -32
	// 		struct _PlanCollideInfo pci; // stack offset -48

		/* begin block 1.1 */
			// Start line: 243
			// Start offset: 0x80096E58
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a3
		// 		struct _Position *_v0; // $s0
		/* end block 1.1 */
		// End offset: 0x80096E58
		// End Line: 243
	/* end block 1 */
	// End offset: 0x80096F08
	// End Line: 261

	/* begin block 2 */
		// Start line: 538
	/* end block 2 */
	// End Line: 539

void PLAN_UpdatePlayerNode(PlanningNode *planningPool,_Position *playerPos)

{
  ushort uVar1;
  PlanningNode *nodeToChange;
  int iVar2;
  _PlanCollideInfo _Stack48;
  ushort auStack32 [4];
  
  nodeToChange = PLANPOOL_GetFirstNodeOfSource(planningPool,'\x01');
  if (nodeToChange != (PlanningNode *)0x0) {
    iVar2 = PLANCOLL_CheckUnderwaterPoint(playerPos);
    if (iVar2 == -1) {
      _Stack48.collidePos.x = playerPos->x;
      _Stack48.collidePos.y = playerPos->y;
      _Stack48.collidePos.z = playerPos->z;
      iVar2 = PLANCOLL_FindTerrainHitFinal(&_Stack48,(int *)auStack32,0x100,-0x280,0,5);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)playerPos->x - (int)(nodeToChange->pos).x,
                         (int)playerPos->y - (int)(nodeToChange->pos).y,
                         (int)playerPos->z - (int)(nodeToChange->pos).z);
      }
      PLANPOOL_ChangeNodePosition(&_Stack48.collidePos,nodeToChange,planningPool);
      uVar1 = (ushort)(((uint)auStack32[0] & 3) << 3) | 1;
    }
    else {
      PLANPOOL_ChangeNodePosition(playerPos,nodeToChange,planningPool);
      uVar1 = 0x19;
    }
    nodeToChange->nodeType = uVar1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_AddRandomNode(struct PlanningNode *planningPool /*$s5*/, struct _Position *playerPos /*$s0*/)
 // line 269, offset 0x80096f24
	/* begin block 1 */
		// Start line: 270
		// Start offset: 0x80096F24
		// Variables:
	// 		int i; // $s2
	// 		struct _PlanCollideInfo pci; // stack offset -56
	// 		int successFlag; // $s4

		/* begin block 1.1 */
			// Start line: 278
			// Start offset: 0x80096F60
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $a0
		// 		struct _Position *_v0; // $s1
		/* end block 1.1 */
		// End offset: 0x80096F60
		// End Line: 278

		/* begin block 1.2 */
			// Start line: 297
			// Start offset: 0x8009707C

			/* begin block 1.2.1 */
				// Start line: 303
				// Start offset: 0x800970BC
				// Variables:
			// 		struct _SVector normal; // stack offset -40
			/* end block 1.2.1 */
			// End offset: 0x8009710C
			// End Line: 309
		/* end block 1.2 */
		// End offset: 0x8009710C
		// End Line: 310
	/* end block 1 */
	// End offset: 0x8009710C
	// End Line: 311

	/* begin block 2 */
		// Start line: 636
	/* end block 2 */
	// End Line: 637

void PLAN_AddRandomNode(PlanningNode *planningPool,_Position *playerPos)

{
                    /* WARNING: Subroutine does not return */
  rand();
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_DeleteRandomNode(struct PlanningNode *planningPool /*$s0*/)
 // line 317, offset 0x80097130
	/* begin block 1 */
		// Start line: 318
		// Start offset: 0x80097130
	/* end block 1 */
	// End offset: 0x80097130
	// End Line: 318

	/* begin block 2 */
		// Start line: 766
	/* end block 2 */
	// End Line: 767

void PLAN_DeleteRandomNode(PlanningNode *planningPool)

{
  PlanningNode *nodeToDelete;
  
  nodeToDelete = PLANPOOL_GetFirstNodeOfSource(planningPool,'\0');
  PLANPOOL_DeleteNodeFromPool(nodeToDelete,planningPool);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_DeleteOutOfRangeNodesOfSource(struct PlanningNode *planningPool /*$s3*/, struct _Position *playerPos /*$s2*/, char nodeSourceToCheck /*$a2*/, long removeDist /*$s5*/)
 // line 328, offset 0x80097164
	/* begin block 1 */
		// Start line: 329
		// Start offset: 0x80097164
		// Variables:
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x80097218
	// End Line: 341

	/* begin block 2 */
		// Start line: 788
	/* end block 2 */
	// End Line: 789

	/* begin block 3 */
		// Start line: 792
	/* end block 3 */
	// End Line: 793

void PLAN_DeleteOutOfRangeNodesOfSource
               (PlanningNode *planningPool,_Position *playerPos,char nodeSourceToCheck,
               long removeDist)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      if (((uint)planningPool->nodeType & 7) == (uint)(byte)nodeSourceToCheck) {
                    /* WARNING: Subroutine does not return */
        MATH3D_LengthXYZ((int)playerPos->x - (int)(planningPool->pos).x,
                         (int)playerPos->y - (int)(planningPool->pos).y,
                         (int)playerPos->z - (int)(planningPool->pos).z);
      }
      iVar1 = iVar1 + 1;
      planningPool = planningPool + 1;
    } while (iVar1 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_AddOrRemoveRandomNodes(struct PlanningNode *planningPool /*$a0*/, struct _Position *playerPos /*$a1*/)
 // line 344, offset 0x8009723c
	/* begin block 1 */
		// Start line: 345
		// Start offset: 0x8009723C
		// Variables:
	// 		int numNodeError; // $v0
	/* end block 1 */
	// End offset: 0x8009727C
	// End Line: 356

	/* begin block 2 */
		// Start line: 832
	/* end block 2 */
	// End Line: 833

	/* begin block 3 */
		// Start line: 833
	/* end block 3 */
	// End Line: 834

void PLAN_AddOrRemoveRandomNodes(PlanningNode *planningPool,_Position *playerPos)

{
  int iVar1;
  
  iVar1 = (uint)*(byte *)(poolManagementData + 1) - 0x10;
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
 // line 368, offset 0x8009728c
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x8009728C
		// Variables:
	// 		struct _PlanCollideInfo pci; // stack offset -40

		/* begin block 1.1 */
			// Start line: 369
			// Start offset: 0x8009728C
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $v1
		// 		short _z1; // $t0
		// 		struct _Position *_v0; // $s0
		// 		struct _Position *_v1; // $s1
		/* end block 1.1 */
		// End offset: 0x8009728C
		// End Line: 369
	/* end block 1 */
	// End offset: 0x8009728C
	// End Line: 369

	/* begin block 2 */
		// Start line: 881
	/* end block 2 */
	// End Line: 882

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
  iVar2 = poolManagementData;
  sVar1 = (player->position).z;
  *(undefined4 *)(poolManagementData + 2) = *(undefined4 *)&player->position;
  *(short *)(iVar2 + 6) = sVar1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PLAN_AddOrRemoveNodes(struct PlanningNode *planningPool /*$s1*/, struct _Instance *player /*$s2*/)
 // line 381, offset 0x80097348
	/* begin block 1 */
		// Start line: 382
		// Start offset: 0x80097348
	/* end block 1 */
	// End offset: 0x8009740C
	// End Line: 395

	/* begin block 2 */
		// Start line: 915
	/* end block 2 */
	// End Line: 916

	/* begin block 3 */
		// Start line: 918
	/* end block 3 */
	// End Line: 919

void PLAN_AddOrRemoveNodes(PlanningNode *planningPool,_Instance *player)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(player->position).x - (int)*(short *)(poolManagementData + 2),
                   (int)(player->position).y - (int)*(short *)(poolManagementData + 4),
                   (int)(player->position).z - (int)*(short *)(poolManagementData + 6));
}



// decompiled code
// original method signature: 
// struct PlanningNode * /*$ra*/ PLAN_FindNodeMostInNeedOfConnectivityExpansion(struct PlanningNode *planningPool /*$a0*/)
 // line 401, offset 0x80097430
	/* begin block 1 */
		// Start line: 402
		// Start offset: 0x80097430
		// Variables:
	// 		int i; // $s2
	// 		int numConnections; // $s1
	// 		int minNumConnections; // $s4
	// 		struct PlanningNode *nodeToReturn; // $s3
	/* end block 1 */
	// End offset: 0x800974C8
	// End Line: 419

	/* begin block 2 */
		// Start line: 958
	/* end block 2 */
	// End Line: 959

	/* begin block 3 */
		// Start line: 963
	/* end block 3 */
	// End Line: 964

PlanningNode * PLAN_FindNodeMostInNeedOfConnectivityExpansion(PlanningNode *planningPool)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  PlanningNode *pPVar4;
  int iVar5;
  
  iVar5 = 0xffff;
  iVar3 = 0;
  pPVar4 = (PlanningNode *)0x0;
  if (*(char *)(poolManagementData + 1) != '\0') {
    do {
      iVar1 = PLANPOOL_NumConnectionsForNode(planningPool);
      if ((iVar1 < iVar5) &&
         (uVar2 = PLANPOOL_NumConnectionsExaminedForNode(planningPool),
         uVar2 != (uint)*(byte *)(poolManagementData + 1))) {
        pPVar4 = planningPool;
        iVar5 = iVar1;
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
    } while (iVar3 < (int)(uint)*(byte *)(poolManagementData + 1));
  }
  return pPVar4;
}





