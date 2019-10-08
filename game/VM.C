#include "THISDUST.H"
#include "VM.H"

void VM_Tick(long time)

{
  vmRealClock = vmRealClock + time;
  vmClock = vmRealClock >> 8;
  return;
}

void VRAM_UpdateMorphPalettes(Level *level, int initFlg)

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
  _union_369 *p_Var13;
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
          if (address != (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)])
          {
            MEMPACK_Init((char *)address);
          }
          if (initFlg == 0)
          {
            if (gameTrackerX.gameData.asmData.MorphType == 0)
              goto LAB_8004ff78;
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
            LAB_8004ff78:
              *(undefined2 *)(pp_Var17 + -7) = *(undefined2 *)((int)pp_Var17 + -0x1e);
            }
          }
          *pp_Var17 = (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)];
        }
        else
        {
          iVar18 = address->numVMOffsets;
          if (address == (_VMOffsetTable *)(&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -7)])
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
            pcVar12 = (char *)((&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -8)] + 4);
            pcVar14 = (char *)((&pp_Var17[-1]->numVMOffsets)[*(short *)((int)pp_Var17 + -0x1e)] + 4);
            p_Var13 = &(*pp_Var17)->offsets;
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
                *(char *)p_Var13 = *pcVar12 + (char)(sVar15 * iVar16 >> 0xc);
                *(char *)((int)p_Var13 + 1) =
                    pcVar12[1] +
                    (char)((((int)cVar9 - (int)cVar5) * 0x10000 >> 0x10) * iVar16 >> 0xc);
                pcVar4 = pcVar12 + 2;
                pcVar12 = pcVar12 + 3;
                *(char *)((int)p_Var13 + 2) =
                    *pcVar4 + (char)((((int)cVar6 - (int)cVar7) * 0x10000 >> 0x10) * iVar16 >> 0xc);
                p_Var13 = (_union_369 *)((int)p_Var13 + 3);
              } while (iVar8 < iVar18);
            }
          }
          else
          {
            psVar11 = (short *)((&pp_Var17[-1]->numVMOffsets)[*(short *)(pp_Var17 + -8)] + 4);
            psVar10 = (short *)((&pp_Var17[-1]->numVMOffsets)[*(short *)((int)pp_Var17 + -0x1e)] + 4);
            p_Var13 = &(*pp_Var17)->offsets;
            if (0 < iVar18)
            {
              iVar16 = (int)sVar15;
              do
              {
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

void VM_VMObjectSetTable(Level *level, _VMObject *vmobject, int table)

{
  if (vmobject->curVMOffsetTable != vmobject->vmoffsetTableList[vmobject->currentIdx])
  {
    MEMPACK_Init((char *)vmobject->curVMOffsetTable);
  }
  vmobject->currentIdx = (short)table;
  vmobject->curVMOffsetTable =
      *(_VMOffsetTable **)(((table << 0x10) >> 0xe) + (int)vmobject->vmoffsetTableList);
  return;
}
