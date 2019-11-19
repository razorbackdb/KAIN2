#include "THISDUST.H"
#include "VM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VM_Tick(long time /*$a0*/)
 // line 105, offset 0x80050a54
	/* begin block 1 */
		// Start line: 210
	/* end block 1 */
	// End Line: 211

	/* begin block 2 */
		// Start line: 211
	/* end block 2 */
	// End Line: 212

void VM_Tick(long time)

{
  vmRealClock = vmRealClock + time;
  vmClock = vmRealClock >> 8;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VM_UpdateMorph(struct Level *level /*$a0*/, int initFlg /*$s5*/)
 // line 295, offset 0x80050a74
	/* begin block 1 */
		// Start line: 296
		// Start offset: 0x80050A74
		// Variables:
	// 		struct _VMObject *vmobject; // $s3
	// 		int i; // $s4

		/* begin block 1.1 */
			// Start line: 305
			// Start offset: 0x80050AD0
			// Variables:
		// 		struct _VMOffsetTable *curTable; // $a0

			/* begin block 1.1.1 */
				// Start line: 308
				// Start offset: 0x80050AE0
			/* end block 1.1.1 */
			// End offset: 0x80050B54
			// End Line: 337

			/* begin block 1.1.2 */
				// Start line: 341
				// Start offset: 0x80050B70
				// Variables:
			// 		short ratio; // $s2
			// 		int j; // $t1
			// 		long num; // $s1

				/* begin block 1.1.2.1 */
					// Start line: 353
					// Start offset: 0x80050B94
					// Variables:
				// 		long len; // $a0
				/* end block 1.1.2.1 */
				// End offset: 0x80050BCC
				// End Line: 360

				/* begin block 1.1.2.2 */
					// Start line: 362
					// Start offset: 0x80050BE0
					// Variables:
				// 		struct _VMOffset *material; // $a1
				// 		struct _VMOffset *spectral; // $a0
				// 		struct _VMOffset *offset; // $v1
				/* end block 1.1.2.2 */
				// End offset: 0x80050CB4
				// End Line: 374

				/* begin block 1.1.2.3 */
					// Start line: 374
					// Start offset: 0x80050CBC
					// Variables:
				// 		short dr; // $a3
				// 		short dg; // $a0
				// 		short db; // $v1
				// 		struct _VMColorOffset *material; // $a1
				// 		struct _VMColorOffset *spectral; // $a0
				// 		struct _VMColorOffset *offset; // $v1
				/* end block 1.1.2.3 */
				// End offset: 0x80050E18
				// End Line: 403
			/* end block 1.1.2 */
			// End offset: 0x80050E18
			// End Line: 405
		/* end block 1.1 */
		// End offset: 0x80050E18
		// End Line: 406
	/* end block 1 */
	// End offset: 0x80050E28
	// End Line: 408

	/* begin block 2 */
		// Start line: 585
	/* end block 2 */
	// End Line: 586

void VM_UpdateMorph(Level *level,int initFlg)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  char *pcVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  char cVar9;
  _VMOffsetTable *address;
  short *psVar10;
  short *psVar11;
  char *pcVar12;
  _union_7330 *p_Var13;
  char *pcVar14;
  short sVar15;
  int iVar16;
  _VMOffsetTable **pp_Var17;
  int iVar18;
  _VMObject *p_Var19;
  int iVar20;
  
  iVar20 = level->numVMObjects;
  p_Var19 = level->vmobjectList;
  if (iVar20 != 0) {
    pp_Var17 = &p_Var19->curVMOffsetTable;
    do {
      sVar15 = (short)gameTrackerX.lastLoopTime;
      if ((*(short *)(pp_Var17 + -8) != *(short *)((int)pp_Var17 + -0x1e)) ||
         ((p_Var19->flags & 0x100) != 0)) {
        address = *pp_Var17;
        if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
          if (address != (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)])
          {
            MEMPACK_Free((char *)address);
          }
          if (initFlg == 0) {
            if (gameTrackerX.gameData.asmData.MorphType == 0) goto LAB_80050b48;
            *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)(pp_Var17 + -8);
          }
          else {
            if (gameTrackerX.gameData.asmData.MorphType == 0) {
              *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)(pp_Var17 + -8);
            }
            else {
LAB_80050b48:
              *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)((int)pp_Var17 + -0x1e);
            }
          }
          *pp_Var17 = (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)];
        }
        else {
          iVar18 = address->numVMOffsets;
          if (address == (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)])
          {
            if ((p_Var19->flags & 8) == 0) {
              iVar8 = iVar18 * 3;
            }
            else {
              iVar8 = iVar18 * 6;
            }
            address = (_VMOffsetTable *)MEMPACK_Malloc(iVar8 + 4,'(');
            *pp_Var17 = address;
            address->numVMOffsets = iVar18;
          }
          iVar8 = 0;
          if ((p_Var19->flags & 8) == 0) {
            pcVar12 = (char *)((&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -8)] + 4);
            pcVar14 = (char *)((&pp_Var17[-1]->numVMOffsets)[*(short *)((int)pp_Var17 + -0x1e)] + 4)
            ;
            p_Var13 = &(*pp_Var17)->offsets;
            if (0 < iVar18) {
              iVar16 = (int)sVar15;
              do {
                if ((p_Var19->flags & 0x100) == 0) {
                  cVar9 = pcVar14[1];
                  sVar15 = (short)*pcVar14 - (short)*pcVar12;
                  cVar5 = pcVar12[1];
                  cVar6 = pcVar14[2];
                }
                else {
                  cVar9 = pcVar14[1];
                  sVar15 = (short)pcVar14[2] - (short)*pcVar12;
                  cVar5 = pcVar12[1];
                  cVar6 = *pcVar14;
                }
                cVar7 = pcVar12[2];
                pcVar14 = pcVar14 + 3;
                iVar8 = iVar8 + 1;
                *(char *)p_Var13 = *pcVar12 + (char)(sVar15 * iVar16 >> 0xc);
                *(char *)((int)p_Var13 + 1) =
                     pcVar12[1] +
                     (char)((((int)cVar9 - (int)cVar5) * 0x10000 >> 0x10) * iVar16 >> 0xc);
                pcVar4 = pcVar12 + 2;
                pcVar12 = pcVar12 + 3;
                *(char *)((int)p_Var13 + 2) =
                     *pcVar4 + (char)((((int)cVar6 - (int)cVar7) * 0x10000 >> 0x10) * iVar16 >> 0xc)
                ;
                p_Var13 = (_union_7330 *)((int)p_Var13 + 3);
              } while (iVar8 < iVar18);
            }
          }
          else {
            psVar11 = (short *)((&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -8)] + 4);
            psVar10 = (short *)((&pp_Var17[-1]->numVMOffsets)[*(short *)((int)pp_Var17 + -0x1e)] + 4
                               );
            p_Var13 = &(*pp_Var17)->offsets;
            if (0 < iVar18) {
              iVar16 = (int)sVar15;
              do {
                *(short *)p_Var13 =
                     *psVar11 + (short)(((int)*psVar10 - (int)*psVar11) * iVar16 >> 0xc);
                *(short *)((int)p_Var13 + 2) =
                     psVar11[1] + (short)(((int)psVar10[1] - (int)psVar11[1]) * iVar16 >> 0xc);
                psVar1 = psVar10 + 2;
                psVar2 = psVar11 + 2;
                iVar8 = iVar8 + 1;
                psVar10 = psVar10 + 3;
                psVar3 = psVar11 + 2;
                psVar11 = psVar11 + 3;
                *(short *)((int)p_Var13 + 4) =
                     *psVar3 + (short)(((int)*psVar1 - (int)*psVar2) * iVar16 >> 0xc);
                p_Var13 = p_Var13 + 1;
              } while (iVar8 < iVar18);
            }
          }
        }
      }
      iVar20 = iVar20 + -1;
      pp_Var17 = pp_Var17 + 0xf;
      p_Var19 = p_Var19 + 1;
    } while (iVar20 != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VM_VMOUpdateTimeOfDay(struct Level *level /*$s3*/, struct _VMObject *vmobject /*$s1*/, int startTimeIdx /*$s2*/, int ratio /*$s4*/)
 // line 412, offset 0x80050e4c
	/* begin block 1 */
		// Start line: 413
		// Start offset: 0x80050E4C
		// Variables:
	// 		struct _VMOffsetTable *curTable; // $a1

		/* begin block 1.1 */
			// Start line: 426
			// Start offset: 0x80050EE0
			// Variables:
		// 		long num; // $s0
		// 		long len; // $a0
		// 		int j; // $a3
		// 		int endTimeIdx; // $s3

			/* begin block 1.1.1 */
				// Start line: 441
				// Start offset: 0x80050F40
				// Variables:
			// 		struct _VMOffset *start; // $a0
			// 		struct _VMOffset *end; // $v0
			// 		struct _VMOffset *offset; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80051010
			// End Line: 453

			/* begin block 1.1.2 */
				// Start line: 453
				// Start offset: 0x80051018
				// Variables:
			// 		struct _VMColorOffset *start; // $a0
			// 		struct _VMColorOffset *end; // $v0
			// 		struct _VMColorOffset *offset; // $v1
			/* end block 1.1.2 */
			// End offset: 0x800510E8
			// End Line: 466
		/* end block 1.1 */
		// End offset: 0x800510E8
		// End Line: 467

		/* begin block 1.2 */
			// Start line: 474
			// Start offset: 0x80051134
			// Variables:
		// 		long num; // $s0
		// 		long len; // $a0
		// 		int j; // $a2

			/* begin block 1.2.1 */
				// Start line: 485
				// Start offset: 0x80051194
				// Variables:
			// 		struct _VMColorOffset *src; // $v0
			// 		struct _VMColorOffset *offset; // $v1
			/* end block 1.2.1 */
			// End offset: 0x8005123C
			// End Line: 499
		/* end block 1.2 */
		// End offset: 0x8005123C
		// End Line: 501
	/* end block 1 */
	// End offset: 0x8005123C
	// End Line: 503

	/* begin block 2 */
		// Start line: 838
	/* end block 2 */
	// End Line: 839

void VM_VMOUpdateTimeOfDay(Level *level,_VMObject *vmobject,int startTimeIdx,int ratio)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  _union_7330 *p_Var8;
  _VMOffsetTable *address;
  _union_7330 *p_Var9;
  _union_7330 *p_Var10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  address = vmobject->curVMOffsetTable;
  if ((vmobject->flags & 0x80) == 0) {
    if ((((level->unitFlags & 2U) != 0) ||
        ((*(ushort *)((int)level->terrain->signals->signalList + (int)vmobject->bspIdx * 0x24 + 10)
         & 0x10) != 0)) && (iVar11 = address->numVMOffsets, (vmobject->flags & 4) != 0)) {
      if (address != vmobject->vmoffsetTableList[vmobject->currentIdx]) {
        MEMPACK_Free((char *)address);
      }
      if ((vmobject->flags & 8) == 0) {
        iVar12 = iVar11 * 3;
      }
      else {
        iVar12 = iVar11 * 6;
      }
      address = (_VMOffsetTable *)MEMPACK_Malloc(iVar12 + 4,'(');
      iVar12 = 0;
      vmobject->curVMOffsetTable = address;
      address->numVMOffsets = iVar11;
      p_Var8 = &vmobject->vmoffsetTableList[vmobject->currentIdx]->offsets;
      p_Var10 = &vmobject->curVMOffsetTable->offsets;
      if (0 < iVar11) {
        do {
          *(char *)p_Var10 = (char)((int)*(char *)p_Var8 * (int)level->TODRedScale >> 0xc);
          *(undefined *)((int)p_Var10 + 1) =
               (char)((int)*(char *)((int)p_Var8 + 1) * (int)level->TODGrnScale >> 0xc);
          pcVar6 = (char *)((int)p_Var8 + 2);
          iVar12 = iVar12 + 1;
          p_Var8 = (_union_7330 *)((int)p_Var8 + 3);
          *(undefined *)((int)p_Var10 + 2) = (char)((int)*pcVar6 * (int)level->TODBluScale >> 0xc);
          p_Var10 = (_union_7330 *)((int)p_Var10 + 3);
        } while (iVar12 < iVar11);
      }
    }
  }
  else {
    if (address != vmobject->vmoffsetTableList[vmobject->currentIdx]) {
      MEMPACK_Free((char *)address);
    }
    if (ratio == 0) {
      startTimeIdx = (uint)(ushort)vmobject->materialIdx + startTimeIdx;
      vmobject->currentIdx = (short)startTimeIdx;
      vmobject->curVMOffsetTable =
           *(_VMOffsetTable **)((startTimeIdx * 0x10000 >> 0xe) + (int)vmobject->vmoffsetTableList);
    }
    else {
      iVar12 = startTimeIdx + (int)vmobject->materialIdx;
      iVar13 = (startTimeIdx + 1U & 3) + (int)vmobject->materialIdx;
      iVar11 = vmobject->curVMOffsetTable->numVMOffsets;
      if ((vmobject->flags & 8) == 0) {
        iVar7 = iVar11 * 3;
      }
      else {
        iVar7 = iVar11 * 6;
      }
      address = (_VMOffsetTable *)MEMPACK_Malloc(iVar7 + 4,'(');
      vmobject->curVMOffsetTable = address;
      address->numVMOffsets = iVar11;
      if ((vmobject->flags & 8) == 0) {
        iVar7 = 0;
        p_Var9 = &vmobject->vmoffsetTableList[iVar12]->offsets;
        p_Var8 = &vmobject->vmoffsetTableList[iVar13]->offsets;
        p_Var10 = &vmobject->curVMOffsetTable->offsets;
        if (0 < iVar11) {
          do {
            *(char *)p_Var10 =
                 *(char *)p_Var9 +
                 (char)(((int)*(char *)p_Var8 - (int)*(char *)p_Var9) * ratio >> 0xc);
            *(char *)((int)p_Var10 + 1) =
                 *(char *)((int)p_Var9 + 1) +
                 (char)(((int)*(char *)((int)p_Var8 + 1) - (int)*(char *)((int)p_Var9 + 1)) * ratio
                       >> 0xc);
            pcVar6 = (char *)((int)p_Var8 + 2);
            pcVar4 = (char *)((int)p_Var9 + 2);
            iVar7 = iVar7 + 1;
            p_Var8 = (_union_7330 *)((int)p_Var8 + 3);
            pcVar5 = (char *)((int)p_Var9 + 2);
            p_Var9 = (_union_7330 *)((int)p_Var9 + 3);
            *(char *)((int)p_Var10 + 2) =
                 *pcVar5 + (char)(((int)*pcVar6 - (int)*pcVar4) * ratio >> 0xc);
            p_Var10 = (_union_7330 *)((int)p_Var10 + 3);
          } while (iVar7 < iVar11);
        }
      }
      else {
        iVar7 = 0;
        p_Var9 = &vmobject->vmoffsetTableList[iVar12]->offsets;
        p_Var8 = &vmobject->vmoffsetTableList[iVar13]->offsets;
        p_Var10 = &vmobject->curVMOffsetTable->offsets;
        if (0 < iVar11) {
          do {
            *(short *)p_Var10 =
                 *(short *)p_Var9 +
                 (short)(((int)*(short *)p_Var8 - (int)*(short *)p_Var9) * ratio >> 0xc);
            *(short *)((int)p_Var10 + 2) =
                 *(short *)((int)p_Var9 + 2) +
                 (short)(((int)*(short *)((int)p_Var8 + 2) - (int)*(short *)((int)p_Var9 + 2)) *
                         ratio >> 0xc);
            psVar1 = (short *)((int)p_Var8 + 4);
            psVar2 = (short *)((int)p_Var9 + 4);
            iVar7 = iVar7 + 1;
            p_Var8 = p_Var8 + 1;
            psVar3 = (short *)((int)p_Var9 + 4);
            p_Var9 = p_Var9 + 1;
            *(short *)((int)p_Var10 + 4) =
                 *psVar3 + (short)(((int)*psVar1 - (int)*psVar2) * ratio >> 0xc);
            p_Var10 = p_Var10 + 1;
          } while (iVar7 < iVar11);
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VM_UpdateTimeOfDay(struct Level *level /*$s2*/, int startTimeIdx /*$s3*/, int ratio /*$s4*/)
 // line 507, offset 0x8005125c
	/* begin block 1 */
		// Start line: 508
		// Start offset: 0x8005125C
		// Variables:
	// 		struct _VMObject *vmobject; // $s1
	// 		int i; // $s0
	/* end block 1 */
	// End offset: 0x800512B0
	// End Line: 516

	/* begin block 2 */
		// Start line: 1095
	/* end block 2 */
	// End Line: 1096

void VM_UpdateTimeOfDay(Level *level,int startTimeIdx,int ratio)

{
  int iVar1;
  _VMObject *vmobject;
  
  iVar1 = level->numVMObjects;
  vmobject = level->vmobjectList;
  while (iVar1 != 0) {
    VM_VMOUpdateTimeOfDay(level,vmobject,startTimeIdx,ratio);
    iVar1 = iVar1 + -1;
    vmobject = vmobject + 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ VM_VMObjectSetTable(struct Level *level /*$s3*/, struct _VMObject *vmobject /*$s1*/, int table /*$s2*/)
 // line 521, offset 0x800512d0
	/* begin block 1 */
		// Start line: 522
		// Start offset: 0x800512D0
		// Variables:
	// 		struct _VMOffsetTable *curTable; // $a0
	// 		int timeOfDay; // $s0
	/* end block 1 */
	// End offset: 0x8005131C
	// End Line: 529

	/* begin block 2 */
		// Start line: 1125
	/* end block 2 */
	// End Line: 1126

void VM_VMObjectSetTable(Level *level,_VMObject *vmobject,int table)

{
  int startTimeIdx;
  int timeOfDay;
  
  timeOfDay = (int)gameTrackerX.currentMaterialTime._2_2_;
  if (vmobject->curVMOffsetTable != vmobject->vmoffsetTableList[vmobject->currentIdx]) {
    MEMPACK_Free((char *)vmobject->curVMOffsetTable);
  }
  vmobject->currentIdx = (short)table;
  vmobject->curVMOffsetTable =
       *(_VMOffsetTable **)(((table << 0x10) >> 0xe) + (int)vmobject->vmoffsetTableList);
  startTimeIdx = GAMELOOP_GetTimeOfDayIdx(timeOfDay);
  timeOfDay = GAMELOOP_TimeOfDayRatio(timeOfDay);
  VM_VMOUpdateTimeOfDay(level,vmobject,startTimeIdx,timeOfDay);
  return;
}





