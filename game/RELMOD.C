#include "THISDUST.H"
#include "RELMOD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ RELMOD_InitModulePointers(int baseaddr /*$a0*/, int *relocs /*$a1*/)
 // line 11, offset 0x8007b9cc
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x8007B9CC
		// Variables:
	// 		unsigned int *rel_addr; // $a2
	/* end block 1 */
	// End offset: 0x8007BAA8
	// End Line: 38

	/* begin block 2 */
		// Start line: 22
	/* end block 2 */
	// End Line: 23

	/* begin block 3 */
		// Start line: 23
	/* end block 3 */
	// End Line: 24

	/* begin block 4 */
		// Start line: 25
	/* end block 4 */
	// End Line: 26

void RELMOD_InitModulePointers(int baseaddr,int *relocs)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  
  if (*relocs != -1) {
    uVar1 = *relocs;
    puVar3 = (uint *)(relocs + 1);
    do {
      uVar2 = uVar1 & 3;
      piVar4 = (int *)(baseaddr + (uVar1 & 0xfffffffc));
      if (uVar2 == 1) {
        uVar1 = *puVar3;
        puVar3 = puVar3 + 1;
        *(short *)piVar4 = (short)(baseaddr + uVar1 + 0x8000 >> 0x10);
      }
      else {
        if (uVar2 < 2) {
          if ((uVar2 == 0) && (-1 < *piVar4)) {
            *piVar4 = *piVar4 + baseaddr;
          }
        }
        else {
          if (uVar2 == 2) {
            *(short *)piVar4 = *(short *)piVar4 + (short)baseaddr;
          }
          else {
            if (uVar2 == 3) {
              *piVar4 = *piVar4 + ((uint)(baseaddr << 4) >> 6);
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



// decompiled code
// original method signature: 
// void /*$ra*/ RELMOD_RelocModulePointers(int baseaddr /*$a0*/, int offset /*$a1*/, int *relocs /*$a2*/)
 // line 42, offset 0x8007bab0
	/* begin block 1 */
		// Start line: 44
		// Start offset: 0x8007BAB0
		// Variables:
	// 		int oldbaseaddr; // $v0
	// 		int *rel_addr; // $a3
	/* end block 1 */
	// End offset: 0x8007BB90
	// End Line: 69

	/* begin block 2 */
		// Start line: 86
	/* end block 2 */
	// End Line: 87

	/* begin block 3 */
		// Start line: 87
	/* end block 3 */
	// End Line: 88

	/* begin block 4 */
		// Start line: 90
	/* end block 4 */
	// End Line: 91

void RELMOD_RelocModulePointers(int baseaddr,int offset,int *relocs)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  
  if (*relocs != -1) {
    uVar2 = *relocs;
    puVar4 = (uint *)(relocs + 1);
    do {
      uVar3 = uVar2 & 3;
      piVar5 = (int *)(baseaddr + (uVar2 & 0xfffffffc));
      if (uVar3 == 1) {
        uVar2 = *puVar4;
        puVar4 = puVar4 + 1;
        *(short *)piVar5 = (short)(baseaddr + uVar2 + 0x8000 >> 0x10);
      }
      else {
        if (uVar3 < 2) {
          if (uVar3 == 0) {
            iVar1 = *piVar5 + offset;
LAB_8007bb7c:
            *piVar5 = iVar1;
          }
        }
        else {
          if (uVar3 == 2) {
            *(short *)piVar5 = *(short *)piVar5 + (short)offset;
          }
          else {
            if (uVar3 == 3) {
              iVar1 = (*piVar5 - ((uint)((baseaddr - offset) * 0x10) >> 6)) +
                      ((uint)(baseaddr << 4) >> 6);
              goto LAB_8007bb7c;
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





