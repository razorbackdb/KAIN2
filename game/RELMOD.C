#include "THISDUST.H"
#include "RELMOD.H"

void RELMOD_InitModulePointers(int baseaddr, int *relocs)

{
  u_int uVar1;
  u_int uVar2;
  u_int *puVar3;
  int *piVar4;

  if (*relocs != -1)
  {
    uVar1 = *relocs;
    puVar3 = (u_int *)(relocs + 1);
    do
    {
      uVar2 = uVar1 & 3;
      piVar4 = (int *)(baseaddr + (uVar1 & 0xfffffffc));
      if (uVar2 == 1)
      {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        *(short *)piVar4 = (short)(baseaddr + uVar1 + 0x8000 >> 0x10);
      }
      else
      {
        if (uVar2 < 2)
        {
          if ((uVar2 == 0) && (-1 < *piVar4))
          {
            *piVar4 = *piVar4 + baseaddr;
          }
        }
        else
        {
          if (uVar2 == 2)
          {
            *(short *)piVar4 = *(short *)piVar4 + (short)baseaddr;
          }
          else
          {
            if (uVar2 == 3)
            {
              *piVar4 = *piVar4 + ((u_int)(baseaddr << 4) >> 6);
            }
          }
        }
      }
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
    } while (uVar1 != 0xffffffff);
  }
  return;
}

void RELMOD_RelocModulePointers(int baseaddr, int offset, int *relocs)

{
  int iVar1;
  u_int uVar2;
  u_int uVar3;
  u_int *puVar4;
  int *piVar5;

  if (*relocs != -1)
  {
    uVar2 = *relocs;
    puVar4 = (u_int *)(relocs + 1);
    do
    {
      uVar3 = uVar2 & 3;
      piVar5 = (int *)(baseaddr + (uVar2 & 0xfffffffc));
      if (uVar3 == 1)
      {
        uVar2 = *puVar4;
        puVar4 = puVar4 + 1;
        *(short *)piVar5 = (short)(baseaddr + uVar2 + 0x8000 >> 0x10);
      }
      else
      {
        if (uVar3 < 2)
        {
          if (uVar3 == 0)
          {
            iVar1 = *piVar5 + offset;
          LAB_8007c35c:
            *piVar5 = iVar1;
          }
        }
        else
        {
          if (uVar3 == 2)
          {
            *(short *)piVar5 = *(short *)piVar5 + (short)offset;
          }
          else
          {
            if (uVar3 == 3)
            {
              iVar1 = (*piVar5 - ((u_int)((baseaddr - offset) * 0x10) >> 6)) +
                      ((u_int)(baseaddr << 4) >> 6);
              goto LAB_8007c35c;
            }
          }
        }
      }
      uVar2 = *puVar4;
      puVar4 = puVar4 + 1;
    } while (uVar2 != 0xffffffff);
  }
  return;
}
