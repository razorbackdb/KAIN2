#include "THISDUST.H"
#include "VM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ VM_Tick(long time /*$a0*/)
 // line 105, offset 0x8004fe84
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
 // line 295, offset 0x8004fea4
	/* begin block 1 */
		// Start line: 296
		// Start offset: 0x8004FEA4
		// Variables:
	// 		struct _VMObject *vmobject; // $s3
	// 		int i; // $s4

		/* begin block 1.1 */
			// Start line: 305
			// Start offset: 0x8004FF00
			// Variables:
		// 		struct _VMOffsetTable *curTable; // $a0

			/* begin block 1.1.1 */
				// Start line: 308
				// Start offset: 0x8004FF10
			/* end block 1.1.1 */
			// End offset: 0x8004FF84
			// End Line: 337

			/* begin block 1.1.2 */
				// Start line: 341
				// Start offset: 0x8004FFA0
				// Variables:
			// 		short ratio; // $s2
			// 		int j; // $t1
			// 		long num; // $s1

				/* begin block 1.1.2.1 */
					// Start line: 353
					// Start offset: 0x8004FFC4
					// Variables:
				// 		long len; // $a0
				/* end block 1.1.2.1 */
				// End offset: 0x8004FFFC
				// End Line: 360

				/* begin block 1.1.2.2 */
					// Start line: 362
					// Start offset: 0x80050010
					// Variables:
				// 		struct _VMOffset *material; // $a1
				// 		struct _VMOffset *spectral; // $a0
				// 		struct _VMOffset *offset; // $v1
				/* end block 1.1.2.2 */
				// End offset: 0x800500E4
				// End Line: 374

				/* begin block 1.1.2.3 */
					// Start line: 374
					// Start offset: 0x800500EC
					// Variables:
				// 		short dr; // $a3
				// 		short dg; // $a0
				// 		short db; // $v1
				// 		struct _VMColorOffset *material; // $a1
				// 		struct _VMColorOffset *spectral; // $a0
				// 		struct _VMColorOffset *offset; // $v1
				/* end block 1.1.2.3 */
				// End offset: 0x80050248
				// End Line: 403
			/* end block 1.1.2 */
			// End offset: 0x80050248
			// End Line: 405
		/* end block 1.1 */
		// End offset: 0x80050248
		// End Line: 406
	/* end block 1 */
	// End offset: 0x80050258
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
  char cVar8;
  _VMOffsetTable *address;
  short *psVar9;
  short *psVar10;
  char *pcVar11;
  _union_369 *p_Var12;
  char *pcVar13;
  short sVar14;
  int iVar15;
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
      if ((*(short *)(pp_Var17 + -8) != *(short *)((int)pp_Var17 + -0x1e)) ||
         ((p_Var19->flags & 0x100) != 0)) {
        address = *pp_Var17;
        if (gameTrackerX.gameData.asmData.MorphTime == 1000) {
          if (address != (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)])
          {
                    /* WARNING: Subroutine does not return */
            MEMPACK_Free((char *)address);
          }
          if (initFlg == 0) {
            if (gameTrackerX.gameData.asmData.MorphType == 0)
            goto MEMPACK_GetSmallestBlockTopBottom;
            *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)(pp_Var17 + -8);
          }
          else {
            if (gameTrackerX.gameData.asmData.MorphType == 0) {
              *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)(pp_Var17 + -8);
            }
            else {
MEMPACK_GetSmallestBlockTopBottom:
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
              iVar18 = iVar18 * 3;
            }
            else {
              iVar18 = iVar18 * 6;
            }
                    /* WARNING: Subroutine does not return */
            MEMPACK_Malloc(iVar18 + 4,'(');
          }
          iVar15 = 0;
          if ((p_Var19->flags & 8) == 0) {
            pcVar11 = (char *)((&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -8)] + 4);
            pcVar13 = (char *)((&pp_Var17[-1]->numVMOffsets)[*(short *)((int)pp_Var17 + -0x1e)] + 4)
            ;
            p_Var12 = &(*pp_Var17)->offsets;
            if (0 < iVar18) {
              iVar16 = (int)gameTrackerX.spectral_fadeValue;
              do {
                if ((p_Var19->flags & 0x100) == 0) {
                  cVar8 = pcVar13[1];
                  sVar14 = (short)*pcVar13 - (short)*pcVar11;
                  cVar5 = pcVar11[1];
                  cVar6 = pcVar13[2];
                }
                else {
                  cVar8 = pcVar13[1];
                  sVar14 = (short)pcVar13[2] - (short)*pcVar11;
                  cVar5 = pcVar11[1];
                  cVar6 = *pcVar13;
                }
                cVar7 = pcVar11[2];
                pcVar13 = pcVar13 + 3;
                iVar15 = iVar15 + 1;
                *(char *)p_Var12 = *pcVar11 + (char)(sVar14 * iVar16 >> 0xc);
                *(char *)((int)p_Var12 + 1) =
                     pcVar11[1] +
                     (char)((((int)cVar8 - (int)cVar5) * 0x10000 >> 0x10) * iVar16 >> 0xc);
                pcVar4 = pcVar11 + 2;
                pcVar11 = pcVar11 + 3;
                *(char *)((int)p_Var12 + 2) =
                     *pcVar4 + (char)((((int)cVar6 - (int)cVar7) * 0x10000 >> 0x10) * iVar16 >> 0xc)
                ;
                p_Var12 = (_union_369 *)((int)p_Var12 + 3);
              } while (iVar15 < iVar18);
            }
          }
          else {
            psVar10 = (short *)((&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -8)] + 4);
            psVar9 = (short *)((&pp_Var17[-1]->numVMOffsets)[*(short *)((int)pp_Var17 + -0x1e)] + 4)
            ;
            p_Var12 = &(*pp_Var17)->offsets;
            if (0 < iVar18) {
              iVar20 = (int)gameTrackerX.spectral_fadeValue;
              do {
                *(short *)p_Var12 =
                     *psVar10 + (short)(((int)*psVar9 - (int)*psVar10) * iVar20 >> 0xc);
                *(short *)((int)p_Var12 + 2) =
                     psVar10[1] + (short)(((int)psVar9[1] - (int)psVar10[1]) * iVar20 >> 0xc);
                psVar1 = psVar9 + 2;
                psVar2 = psVar10 + 2;
                iVar15 = iVar15 + 1;
                psVar9 = psVar9 + 3;
                psVar3 = psVar10 + 2;
                psVar10 = psVar10 + 3;
                *(short *)((int)p_Var12 + 4) =
                     *psVar3 + (short)(((int)*psVar1 - (int)*psVar2) * iVar20 >> 0xc);
                p_Var12 = p_Var12 + 1;
              } while (iVar15 < iVar18);
              MEMORY_MergeAddresses((char)psVar9,(char)psVar10);
              return;
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
// void /*$ra*/ VM_VMObjectSetTable(struct Level *level /*$a0*/, struct _VMObject *vmobject /*$s0*/, int table /*$s1*/)
 // line 521, offset 0x8005027c
	/* begin block 1 */
		// Start line: 522
		// Start offset: 0x8005027C
		// Variables:
	// 		struct _VMOffsetTable *curTable; // $a0
	/* end block 1 */
	// End offset: 0x800502BC
	// End Line: 530

	/* begin block 2 */
		// Start line: 1056
	/* end block 2 */
	// End Line: 1057

void VM_VMObjectSetTable(Level *level,_VMObject *vmobject,int table)

{
  if (vmobject->curVMOffsetTable != vmobject->vmoffsetTableList[vmobject->currentIdx]) {
                    /* WARNING: Subroutine does not return */
    MEMPACK_Free((char *)vmobject->curVMOffsetTable);
  }
  vmobject->currentIdx = (short)table;
  vmobject->curVMOffsetTable =
       *(_VMOffsetTable **)(((table << 0x10) >> 0xe) + (int)vmobject->vmoffsetTableList);
  return;
}





