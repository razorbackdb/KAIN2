#include "THISDUST.H"
#include "VM.H"

// long @0x800CEBD8, len = 0x00000004
vmClock = 0x0;
// long @0x800CEBD4, len = 0x00000004
vmRealClock = 0x0;
// decompiled code
// original method signature:
// void /*$ra*/ VM_Tick(long time /*$a0*/)
// line 105, offset 0x8004f638
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
// line 295, offset 0x8004f658
/* begin block 1 */
// Start line: 296
// Start offset: 0x8004F658
// Variables:
// 		struct _VMObject *vmobject; // $s3
// 		int i; // $s4

/* begin block 1.1 */
// Start line: 305
// Start offset: 0x8004F6B4
// Variables:
// 		struct _VMOffsetTable *curTable; // $a0

/* begin block 1.1.1 */
// Start line: 308
// Start offset: 0x8004F6C4
/* end block 1.1.1 */
// End offset: 0x8004F738
// End Line: 337

/* begin block 1.1.2 */
// Start line: 341
// Start offset: 0x8004F754
// Variables:
// 		short ratio; // $s2
// 		int j; // $t1
// 		long num; // $s1

/* begin block 1.1.2.1 */
// Start line: 353
// Start offset: 0x8004F778
// Variables:
// 		long len; // $a0
/* end block 1.1.2.1 */
// End offset: 0x8004F7B0
// End Line: 360

/* begin block 1.1.2.2 */
// Start line: 362
// Start offset: 0x8004F7C4
// Variables:
// 		struct _VMOffset *material; // $a1
// 		struct _VMOffset *spectral; // $a0
// 		struct _VMOffset *offset; // $v1
/* end block 1.1.2.2 */
// End offset: 0x8004F898
// End Line: 374

/* begin block 1.1.2.3 */
// Start line: 374
// Start offset: 0x8004F8A0
// Variables:
// 		short dr; // $a3
// 		short dg; // $a0
// 		short db; // $v1
// 		struct _VMColorOffset *material; // $a1
// 		struct _VMColorOffset *spectral; // $a0
// 		struct _VMColorOffset *offset; // $v1
/* end block 1.1.2.3 */
// End offset: 0x8004F9FC
// End Line: 403
/* end block 1.1.2 */
// End offset: 0x8004F9FC
// End Line: 405
/* end block 1.1 */
// End offset: 0x8004F9FC
// End Line: 406
/* end block 1 */
// End offset: 0x8004FA0C
// End Line: 408

/* begin block 2 */
// Start line: 590
/* end block 2 */
// End Line: 591

void VM_UpdateMorph(Level *level, int initFlg)

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
  PLAYER_108fake *pPVar13;
  char *pcVar14;
  short sVar15;
  int iVar16;
  _VMOffsetTable **pp_Var17;
  int iVar18;
  _VMObject *p_Var19;
  int iVar20;

  iVar20 = level->numVMObjects;
  p_Var19 = level->vmobjectList;
  if (iVar20 != 0)
  {
    pp_Var17 = &p_Var19->curVMOffsetTable;
    do
    {
      sVar15 = gameTrackerX.spectral_fadeValue;
      if ((*(short *)(pp_Var17 + -8) != *(short *)((int)pp_Var17 + -0x1e)) ||
          ((p_Var19->flags & 0x100) != 0))
      {
        address = *pp_Var17;
        if (gameTrackerX.gameData.asmData.MorphTime == 1000)
        {
          if (address !=
              (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[(int)*(short *)(pp_Var17 + -7)])
          {
            MEMPACK_Free((char *)address);
          }
          if (initFlg == 0)
          {
            if (gameTrackerX.gameData.asmData.MorphType == 0)
              goto LAB_8004f72c;
            *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)(pp_Var17 + -8);
          }
          else
          {
            if (gameTrackerX.gameData.asmData.MorphType == 0)
            {
              *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)(pp_Var17 + -8);
            }
            else
            {
            LAB_8004f72c:
              *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)((int)pp_Var17 + -0x1e);
            }
          }
          *pp_Var17 = (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[(int)*(short *)(pp_Var17 + -7)];
        }
        else
        {
          iVar18 = address->numVMOffsets;
          if (address ==
              (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[(int)*(short *)(pp_Var17 + -7)])
          {
            if ((p_Var19->flags & 8) == 0)
            {
              iVar8 = iVar18 * 3;
            }
            else
            {
              iVar8 = iVar18 * 6;
            }
            address = (_VMOffsetTable *)MEMPACK_Malloc(iVar8 + 4, '(');
            *pp_Var17 = address;
            address->numVMOffsets = iVar18;
          }
          iVar8 = 0;
          if ((p_Var19->flags & 8) == 0)
          {
            pcVar12 = (char *)((&pp_Var17[-1]->numVMOffsets)[(int)*(short *)(pp_Var17 + -8)] + 4);
            pcVar14 = (char *)((&pp_Var17[-1]->numVMOffsets)[(int)*(short *)((int)pp_Var17 + -0x1e)] + 4);
            pPVar13 = &(*pp_Var17)->offsets;
            if (0 < iVar18)
            {
              iVar16 = (int)sVar15;
              do
              {
                if ((p_Var19->flags & 0x100) == 0)
                {
                  cVar9 = pcVar14[1];
                  sVar15 = (short)*pcVar14 - (short)*pcVar12;
                  cVar5 = pcVar12[1];
                  cVar6 = pcVar14[2];
                }
                else
                {
                  cVar9 = pcVar14[1];
                  sVar15 = (short)pcVar14[2] - (short)*pcVar12;
                  cVar5 = pcVar12[1];
                  cVar6 = *pcVar14;
                }
                cVar7 = pcVar12[2];
                pcVar14 = pcVar14 + 3;
                iVar8 = iVar8 + 1;
                *(char *)pPVar13 = *pcVar12 + (char)((int)sVar15 * iVar16 >> 0xc);
                *(char *)((int)pPVar13 + 1) =
                    pcVar12[1] +
                    (char)((((int)cVar9 - (int)cVar5) * 0x10000 >> 0x10) * iVar16 >> 0xc);
                pcVar4 = pcVar12 + 2;
                pcVar12 = pcVar12 + 3;
                *(char *)((int)pPVar13 + 2) =
                    *pcVar4 + (char)((((int)cVar6 - (int)cVar7) * 0x10000 >> 0x10) * iVar16 >> 0xc);
                pPVar13 = (PLAYER_108fake *)((int)pPVar13 + 3);
              } while (iVar8 < iVar18);
            }
          }
          else
          {
            psVar11 = (short *)((&pp_Var17[-1]->numVMOffsets)[(int)*(short *)(pp_Var17 + -8)] + 4);
            psVar10 = (short *)((&pp_Var17[-1]->numVMOffsets)
                                    [(int)*(short *)((int)pp_Var17 + -0x1e)] +
                                4);
            pPVar13 = &(*pp_Var17)->offsets;
            if (0 < iVar18)
            {
              iVar16 = (int)sVar15;
              do
              {
                *(short *)pPVar13 =
                    *psVar11 + (short)(((int)*psVar10 - (int)*psVar11) * iVar16 >> 0xc);
                *(short *)((int)pPVar13 + 2) =
                    psVar11[1] + (short)(((int)psVar10[1] - (int)psVar11[1]) * iVar16 >> 0xc);
                psVar1 = psVar10 + 2;
                psVar2 = psVar11 + 2;
                iVar8 = iVar8 + 1;
                psVar10 = psVar10 + 3;
                psVar3 = psVar11 + 2;
                psVar11 = psVar11 + 3;
                *(short *)((int)pPVar13 + 4) =
                    *psVar3 + (short)(((int)*psVar1 - (int)*psVar2) * iVar16 >> 0xc);
                pPVar13 = pPVar13 + 1;
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
// void /*$ra*/ VM_VMObjectSetTable(struct Level *level /*$a0*/, struct _VMObject *vmobject /*$s0*/, int table /*$s1*/)
// line 521, offset 0x8004fa30
/* begin block 1 */
// Start line: 522
// Start offset: 0x8004FA30
// Variables:
// 		struct _VMOffsetTable *curTable; // $a0
/* end block 1 */
// End offset: 0x8004FA70
// End Line: 530

/* begin block 2 */
// Start line: 1056
/* end block 2 */
// End Line: 1057

void VM_VMObjectSetTable(Level *level, _VMObject *vmobject, int table)

{
  if (vmobject->curVMOffsetTable != vmobject->vmoffsetTableList[(int)vmobject->currentIdx])
  {
    MEMPACK_Free((char *)vmobject->curVMOffsetTable);
  }
  vmobject->currentIdx = (short)table;
  vmobject->curVMOffsetTable =
      *(_VMOffsetTable **)(((table << 0x10) >> 0xe) + (int)vmobject->vmoffsetTableList);
  return;
}
