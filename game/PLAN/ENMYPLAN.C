#include "THISDUST.H"
#include "ENMYPLAN.H"


// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool /*$a0*/)
 // line 107, offset 0x80095fe8
	/* begin block 1 */
		// Start line: 109
		// Start offset: 0x80095FE8
		// Variables:
	// 		int i; // $v0
	/* end block 1 */
	// End offset: 0x80096000
	// End Line: 117

	/* begin block 2 */
		// Start line: 214
	/* end block 2 */
	// End Line: 215

	/* begin block 3 */
		// Start line: 215
	/* end block 3 */
	// End Line: 216

	/* begin block 4 */
		// Start line: 220
	/* end block 4 */
	// End Line: 221

void ENMYPLAN_InitEnemyPlanPool(void *enemyPlanPool)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = 9;
  puVar2 = (undefined *)((int)enemyPlanPool + 0x34e);
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + -0x5e;
  } while (-1 < iVar1);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetNextAvailablePlanningSlot()
 // line 131, offset 0x80096008
	/* begin block 1 */
		// Start line: 133
		// Start offset: 0x80096008
		// Variables:
	// 		int slotID; // $a1
	// 		int i; // $v1
	/* end block 1 */
	// End offset: 0x80096040
	// End Line: 143

	/* begin block 2 */
		// Start line: 263
	/* end block 2 */
	// End Line: 264

	/* begin block 3 */
		// Start line: 264
	/* end block 3 */
	// End Line: 265

	/* begin block 4 */
		// Start line: 265
	/* end block 4 */
	// End Line: 266

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetNextAvailablePlanningSlot(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  pcVar2 = (char *)gameTrackerX.enemyPlanPool;
  do {
    if (*pcVar2 == '\0') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    pcVar2 = pcVar2 + 0x5e;
  } while (iVar1 < 10);
  return -1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetInitializedPlanningWorkspaceFinal()
 // line 167, offset 0x80096048
	/* begin block 1 */
		// Start line: 168
		// Start offset: 0x80096048
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s0
	// 		int slotID; // $a0
	/* end block 1 */
	// End offset: 0x80096090
	// End Line: 181

	/* begin block 2 */
		// Start line: 338
	/* end block 2 */
	// End Line: 339

/* WARNING: Unknown calling convention yet parameter storage is locked */

int ENMYPLAN_GetInitializedPlanningWorkspaceFinal(void)

{
  void *pvVar1;
  int iVar2;
  undefined *puVar3;
  
  pvVar1 = gameTrackerX.enemyPlanPool;
  iVar2 = ENMYPLAN_GetNextAvailablePlanningSlot();
  if (iVar2 != -1) {
    puVar3 = (undefined *)(iVar2 * 0x5e + (int)pvVar1);
    *puVar3 = 1;
    puVar3[1] = 0;
  }
  return iVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_ReleasePlanningWorkspace(int slotID /*$s0*/)
 // line 185, offset 0x800960a4
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x800960A4
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	/* end block 1 */
	// End offset: 0x800960F8
	// End Line: 203

	/* begin block 2 */
		// Start line: 376
	/* end block 2 */
	// End Line: 377

void ENMYPLAN_ReleasePlanningWorkspace(int slotID)

{
  void *pvVar1;
  
  pvVar1 = gameTrackerX.enemyPlanPool;
  if ((-1 < slotID) && (slotID < 10)) {
    PLANAPI_DeleteNodesFromPoolByType(2);
    PLANAPI_DeleteNodesFromPoolByType(3);
    *(undefined *)(slotID * 0x5e + (int)pvVar1) = 0;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_WayPointSkipped(struct _Position *currentPos /*$a0*/, struct _Position *targetPos /*$s0*/, struct _Position *nextTargetPos /*$s1*/)
 // line 208, offset 0x8009610c
	/* begin block 1 */
		// Start line: 209
		// Start offset: 0x8009610C
		// Variables:
	// 		long range[2]; // stack offset -40
	// 		struct _Position vector[2]; // stack offset -32

		/* begin block 1.1 */
			// Start line: 209
			// Start offset: 0x8009610C
			// Variables:
		// 		short _x0; // $v1
		// 		short _y0; // $v0
		// 		short _z0; // $a1
		// 		short _x1; // $a2
		// 		short _y1; // $a3
		// 		short _z1; // $t0
		// 		struct _Position *_v; // $a0
		/* end block 1.1 */
		// End offset: 0x8009610C
		// End Line: 209

		/* begin block 1.2 */
			// Start line: 209
			// Start offset: 0x8009610C
			// Variables:
		// 		short _x0; // $a0
		// 		short _y0; // $v0
		// 		short _z0; // $v1
		// 		short _x1; // $a1
		// 		short _y1; // $a2
		// 		short _z1; // $a3
		// 		struct _Position *_v; // $a1
		/* end block 1.2 */
		// End offset: 0x8009610C
		// End Line: 209
	/* end block 1 */
	// End offset: 0x800961E4
	// End Line: 225

	/* begin block 2 */
		// Start line: 423
	/* end block 2 */
	// End Line: 424

int ENMYPLAN_WayPointSkipped(_Position *currentPos,_Position *targetPos,_Position *nextTargetPos)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(((uint)(ushort)targetPos->x - (uint)(ushort)currentPos->x) * 0x10000) >>
                   0x10,(int)(short)(targetPos->y - currentPos->y),
                   (int)(short)(targetPos->z - currentPos->z));
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_WayPointReached(struct _Position *currentPos /*$v1*/, struct _Position *oldCurrentPos /*$s1*/, struct _Position *targetPos /*$s0*/)
 // line 235, offset 0x80096278
	/* begin block 1 */
		// Start line: 236
		// Start offset: 0x80096278
		// Variables:
	// 		long range[2]; // stack offset -24
	/* end block 1 */
	// End offset: 0x80096314
	// End Line: 249

	/* begin block 2 */
		// Start line: 487
	/* end block 2 */
	// End Line: 488

int ENMYPLAN_WayPointReached(_Position *currentPos,_Position *oldCurrentPos,_Position *targetPos)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)targetPos->x - (int)currentPos->x,(int)targetPos->y - (int)currentPos->y,
                   (int)targetPos->z - (int)currentPos->z);
}



// decompiled code
// original method signature: 
// void /*$ra*/ ENMYPLAN_Replan(struct EnemyPlanSlotData *planSlot /*$a0*/)
 // line 267, offset 0x80096328
	/* begin block 1 */
		// Start line: 552
	/* end block 1 */
	// End Line: 553

void ENMYPLAN_Replan(EnemyPlanSlotData *planSlot)

{
  planSlot->state = '\0';
  PLANAPI_DeleteNodesFromPoolByType(2);
  PLANAPI_DeleteNodesFromPoolByType(3);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_PathClear(struct _Position *pos /*$s0*/, struct _Position *target /*$a1*/)
 // line 274, offset 0x80096354
	/* begin block 1 */
		// Start line: 275
		// Start offset: 0x80096354
		// Variables:
	// 		int len; // $a1
	// 		struct _Position *tpos; // $a1
	// 		struct _Position newTarget; // stack offset -16
	/* end block 1 */
	// End offset: 0x80096494
	// End Line: 299

	/* begin block 2 */
		// Start line: 566
	/* end block 2 */
	// End Line: 567

int ENMYPLAN_PathClear(_Position *pos,_Position *target)

{
                    /* WARNING: Subroutine does not return */
  MATH3D_LengthXYZ((int)(((uint)(ushort)target->x - (uint)(ushort)pos->x) * 0x10000) >> 0x10,
                   (int)(((uint)(ushort)target->y - (uint)(ushort)pos->y) * 0x10000) >> 0x10,
                   (int)(((uint)(ushort)target->z - (uint)(ushort)pos->z) * 0x10000) >> 0x10);
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_MoveToTargetFinal(struct _Instance *instance /*stack 0*/, struct _Position *outputPos /*$s6*/, int slotID /*$a2*/, struct _Position *targetPos /*$s2*/, int validNodeTypes /*stack 16*/)
 // line 304, offset 0x800964b0
	/* begin block 1 */
		// Start line: 305
		// Start offset: 0x800964B0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $a0
	// 		struct EnemyPlanSlotData *planSlot; // $s0
	// 		struct EnemyPlanData *planData; // $s4
	// 		int nextWayPointType; // $a0
	// 		int nextNextWayPointType; // $s2
	// 		int pathFound; // $v0
	// 		int nextWayPointIdx; // $s5
	// 		int nextNextWayPointIdx; // $s3
	// 		int nextWayPointSkip; // $v1
	// 		int i; // $v1
	// 		struct _Position *nextWayPointPos; // $fp
	// 		struct _Position *nextNextWayPointPos; // $s6
	/* end block 1 */
	// End offset: 0x8009695C
	// End Line: 531

	/* begin block 2 */
		// Start line: 635
	/* end block 2 */
	// End Line: 636

int ENMYPLAN_MoveToTargetFinal
              (_Instance *instance,_Position *outputPos,int slotID,_Position *targetPos,
              int validNodeTypes)

{
  uchar uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  uchar *puVar9;
  void *pvVar10;
  uchar *puVar11;
  byte bVar12;
  EnemyPlanData *planData;
  uint uVar13;
  _Position *nextTargetPos;
  _Position *targetPos_00;
  
  pvVar10 = gameTrackerX.enemyPlanPool;
  gameTrackerX.plan_collide_override = '\x01';
  sVar6 = targetPos->z;
  *(undefined4 *)outputPos = *(undefined4 *)targetPos;
  outputPos->z = sVar6;
  if ((slotID == -1) || (9 < slotID)) {
    gameTrackerX.plan_collide_override = '\x01';
    iVar4 = 2;
  }
  else {
    pvVar10 = (void *)((int)pvVar10 + slotID * 0x5e);
    bVar12 = *(byte *)((int)pvVar10 + 1);
    planData = (EnemyPlanData *)((int)pvVar10 + 0x16);
    if (bVar12 == 1) {
      iVar4 = PLANAPI_FindPathInGraphToTarget
                        ((_Position *)((int)pvVar10 + 4),planData,validNodeTypes);
      sVar6 = *(short *)((int)pvVar10 + 0x5c) + 1;
      *(short *)((int)pvVar10 + 0x5c) = sVar6;
      if (iVar4 == 0) {
        if (0x3c < sVar6) {
          *(undefined *)((int)pvVar10 + 1) = 4;
        }
      }
      else {
        *(undefined *)((int)pvVar10 + 1) = 2;
        *(undefined *)((int)pvVar10 + 2) = 1;
      }
    }
    else {
      if (bVar12 < 2) {
        if (bVar12 == 0) {
          sVar6 = (instance->position).z;
          *(undefined4 *)((int)pvVar10 + 4) = *(undefined4 *)&instance->position;
          *(short *)((int)pvVar10 + 8) = sVar6;
          sVar6 = targetPos->z;
          *(undefined4 *)((int)pvVar10 + 10) = *(undefined4 *)targetPos;
          *(short *)((int)pvVar10 + 0xe) = sVar6;
          *(undefined2 *)((int)pvVar10 + 0x5c) = 0;
          iVar4 = PLANAPI_AddNodeOfTypeToPool((_Position *)((int)pvVar10 + 10),3);
          if (iVar4 != 0) {
            PLANAPI_AddNodeOfTypeToPool((_Position *)((int)pvVar10 + 4),2);
            *(undefined *)((int)pvVar10 + 1) = 1;
          }
        }
      }
      else {
        if (bVar12 == 2) {
          bVar12 = *(byte *)((int)pvVar10 + 2);
          uVar13 = (uint)bVar12;
          puVar11 = planData->nodeSkipArray + uVar13;
          uVar1 = *puVar11;
          targetPos_00 = planData->wayPointArray + uVar13;
          sVar6 = targetPos_00->z;
          *(undefined4 *)outputPos = *(undefined4 *)targetPos_00;
          outputPos->z = sVar6;
          if (uVar1 == '\x02') {
            iVar4 = ENMYPLAN_PathClear(&instance->position,targetPos_00);
            if (((iVar4 == 0) && (*(char *)(&planData[-1].field_0x43 + uVar13) == '\x01')) &&
               (bVar12 != 0)) {
              do {
                uVar7 = uVar13 - 1;
                if ((*(char *)(&planData[-1].field_0x43 + uVar13) != '\x01') || (uVar7 == 0)) {
                  *(undefined *)((int)pvVar10 + 2) = (char)uVar7;
                  planData->nodeSkipArray[uVar13] = '\x02';
                  break;
                }
                uVar13 = uVar7;
              } while (0 < (int)uVar7);
            }
          }
          else {
            iVar4 = (uint)*(byte *)((int)pvVar10 + 2) + 1;
            iVar8 = iVar4 * 6 + 0x10;
            bVar12 = planData->nodeTypeArray[(uint)*(byte *)((int)pvVar10 + 2) + 1] >> 3 & 3;
            if (((puVar11[8] >> 3 & 3) == bVar12) &&
               (bVar3 = puVar11[8] >> 3 & 3, *puVar11 != '\x02')) {
              do {
                bVar2 = bVar12;
                if (bVar3 != 0) goto LAB_800967d8;
                nextTargetPos = (_Position *)(planData->nodeSkipArray + iVar8);
                iVar5 = ENMYPLAN_WayPointSkipped(&instance->position,targetPos_00,nextTargetPos);
                puVar9 = planData->nodeSkipArray + uVar13;
                if (iVar5 == 0) break;
                if ((int)((uint)*(byte *)((int)pvVar10 + 0x58) - 2) <=
                    (int)(uint)*(byte *)((int)pvVar10 + 2)) goto LAB_800967d8;
                *puVar11 = '\x01';
                puVar11 = puVar11 + 1;
                uVar13 = uVar13 + 1;
                iVar8 = iVar8 + 6;
                *(char *)((int)pvVar10 + 2) = *(char *)((int)pvVar10 + 2) + '\x01';
                bVar12 = planData->nodeTypeArray[iVar4 + 1] >> 3 & 3;
                targetPos_00 = nextTargetPos;
                if (bVar2 != bVar12) goto LAB_800967d8;
                puVar9 = planData->nodeSkipArray + uVar13;
                iVar4 = iVar4 + 1;
                bVar3 = bVar2;
              } while (*puVar11 != '\x02');
            }
            else {
LAB_800967d8:
              puVar9 = planData->nodeSkipArray + uVar13;
            }
            *puVar9 = '\x02';
          }
          iVar4 = ENMYPLAN_WayPointReached
                            (&instance->position,(_Position *)((int)pvVar10 + 0x10),targetPos_00);
          if ((iVar4 != 0) &&
             (*(char *)((int)pvVar10 + 2) = *(char *)((int)pvVar10 + 2) + '\x01',
             (int)((uint)*(byte *)((int)pvVar10 + 0x58) - 1) <=
             (int)(uint)*(byte *)((int)pvVar10 + 2))) {
            *(undefined *)((int)pvVar10 + 1) = 3;
            PLANAPI_DeleteNodesFromPoolByType(2);
            PLANAPI_DeleteNodesFromPoolByType(3);
          }
        }
        else {
          if (bVar12 == 3) {
                    /* WARNING: Subroutine does not return */
            MATH3D_LengthXYZ((int)targetPos->x - (int)(instance->position).x,
                             (int)targetPos->y - (int)(instance->position).y,
                             (int)targetPos->z - (int)(instance->position).z);
          }
        }
      }
    }
    sVar6 = (instance->position).z;
    *(undefined4 *)((int)pvVar10 + 0x10) = *(undefined4 *)&instance->position;
    *(short *)((int)pvVar10 + 0x14) = sVar6;
    switch(*(undefined *)((int)pvVar10 + 1)) {
    case 0:
    case 1:
      iVar4 = 0;
      break;
    case 2:
      iVar4 = 1;
      break;
    case 3:
      iVar4 = 2;
      break;
    default:
      iVar4 = 3;
    }
    gameTrackerX.plan_collide_override = '\0';
  }
  return iVar4;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ValidSlotAndState(struct EnemyPlanSlotData *pool /*$a0*/, int slotID /*$a1*/)
 // line 533, offset 0x8009698c
	/* begin block 1 */
		// Start line: 1166
	/* end block 1 */
	// End Line: 1167

	/* begin block 2 */
		// Start line: 1168
	/* end block 2 */
	// End Line: 1169

int ValidSlotAndState(EnemyPlanSlotData *pool,int slotID)

{
  if ((slotID != -1) && (slotID < 10)) {
    return (uint)((uint)(byte)pool[slotID].state - 2 < 2);
  }
  return 0;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID /*$s0*/)
 // line 546, offset 0x800969d0
	/* begin block 1 */
		// Start line: 547
		// Start offset: 0x800969D0
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v0
	/* end block 1 */
	// End offset: 0x80096A28
	// End Line: 559

	/* begin block 2 */
		// Start line: 1192
	/* end block 2 */
	// End Line: 1193

int ENMYPLAN_GetNodeTypeOfNextWaypoint(int slotID)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  
  pvVar3 = gameTrackerX.enemyPlanPool;
  iVar1 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.enemyPlanPool,slotID);
  if (iVar1 == 0) {
    uVar2 = 0x40;
  }
  else {
    pvVar3 = (void *)((int)pvVar3 + slotID * 0x5e);
    uVar2 = (uint)*(byte *)((int)pvVar3 + (uint)*(byte *)((int)pvVar3 + 2) + 0x1e);
  }
  return uVar2;
}



// decompiled code
// original method signature: 
// int /*$ra*/ ENMYPLAN_GetPosOfNextWaypoint(int slotID /*$s0*/, struct _Position *pos /*$s2*/)
 // line 561, offset 0x80096a3c
	/* begin block 1 */
		// Start line: 562
		// Start offset: 0x80096A3C
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $s1
	// 		struct EnemyPlanSlotData *planSlot; // $v1

		/* begin block 1.1 */
			// Start line: 566
			// Start offset: 0x80096A70
			// Variables:
		// 		short _x1; // $a0
		// 		short _y1; // $a1
		// 		short _z1; // $v1
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x80096A70
		// End Line: 566
	/* end block 1 */
	// End offset: 0x80096AC4
	// End Line: 575

	/* begin block 2 */
		// Start line: 1230
	/* end block 2 */
	// End Line: 1231

int ENMYPLAN_GetPosOfNextWaypoint(int slotID,_Position *pos)

{
  short sVar1;
  short sVar2;
  int iVar3;
  void *pvVar4;
  short *psVar5;
  
  pvVar4 = gameTrackerX.enemyPlanPool;
  iVar3 = ValidSlotAndState((EnemyPlanSlotData *)gameTrackerX.enemyPlanPool,slotID);
  if (iVar3 != 0) {
    pvVar4 = (void *)((int)pvVar4 + slotID * 0x5e);
    psVar5 = (short *)((int)pvVar4 + (uint)*(byte *)((int)pvVar4 + 2) * 6 + 0x26);
    sVar1 = psVar5[1];
    sVar2 = psVar5[2];
    pos->x = *psVar5;
    pos->y = sVar1;
    pos->z = sVar2;
  }
  return (uint)(iVar3 != 0);
}



// decompiled code
// original method signature: 
// short /*$ra*/ ENMYPLAN_ReportCurrentGoalUnitID(int slotID /*$a0*/)
 // line 622, offset 0x80096adc
	/* begin block 1 */
		// Start line: 624
		// Start offset: 0x80096ADC
		// Variables:
	// 		struct EnemyPlanSlotData *pool; // $v1
	/* end block 1 */
	// End offset: 0x80096B0C
	// End Line: 630

	/* begin block 2 */
		// Start line: 1362
	/* end block 2 */
	// End Line: 1363

	/* begin block 3 */
		// Start line: 1363
	/* end block 3 */
	// End Line: 1364

short ENMYPLAN_ReportCurrentGoalUnitID(int slotID)

{
  if (slotID != -1) {
    return *(short *)((int)gameTrackerX.enemyPlanPool + slotID * 0x5e + 0x56);
  }
  return 0;
}





