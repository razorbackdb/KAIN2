#include "THISDUST.H"
#include "WORSHIP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ WORSHIP_Init(struct _Instance *instance /*$s2*/)
 // line 47, offset 0x8008ea5c
	/* begin block 1 */
		// Start line: 48
		// Start offset: 0x8008EA5C
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s0
	// 		struct _MonsterVars *mv; // $s1
	// 		struct _Instance *weapon; // $v0
	/* end block 1 */
	// End offset: 0x8008EAE4
	// End Line: 68

	/* begin block 2 */
		// Start line: 94
	/* end block 2 */
	// End Line: 95

void WORSHIP_Init(_Instance *instance)

{
  byte bVar1;
  undefined2 uVar2;
  _Instance *p_Var3;
  int weaponid;
  void *pvVar4;
  void *pvVar5;
  
  pvVar5 = instance->extraData;
  pvVar4 = instance->data;
  weaponid = 0xc;
  if (*(char *)((int)pvVar5 + 0x15a) == '\0') {
    bVar1 = *(byte *)((int)pvVar4 + 0x24);
  }
  else {
    HUMAN_CreateWeapon(instance,0xb,(uint)*(byte *)((int)pvVar4 + 0x23));
    bVar1 = *(byte *)((int)pvVar4 + 0x24);
    weaponid = 0xb;
  }
  p_Var3 = HUMAN_CreateWeapon(instance,weaponid,(uint)bVar1);
  if (p_Var3 != (_Instance *)0x0) {
    HUMAN_Init(instance);
  }
  uVar2 = 0x6000;
  if (*(char *)((int)pvVar5 + 0x15a) == '\0') {
    uVar2 = 0x5000;
  }
  *(undefined2 *)((int)pvVar5 + 0x144) = uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WORSHIP_CombatEntry(struct _Instance *instance /*$s3*/)
 // line 73, offset 0x8008eafc
	/* begin block 1 */
		// Start line: 74
		// Start offset: 0x8008EAFC
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 79
			// Start offset: 0x8008EB64
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s2

			/* begin block 1.1.1 */
				// Start line: 83
				// Start offset: 0x8008EB74
			/* end block 1.1.1 */
			// End offset: 0x8008EB98
			// End Line: 89
		/* end block 1.1 */
		// End offset: 0x8008EBD8
		// End Line: 100
	/* end block 1 */
	// End offset: 0x8008EBD8
	// End Line: 102

	/* begin block 2 */
		// Start line: 150
	/* end block 2 */
	// End Line: 151

void WORSHIP_CombatEntry(_Instance *instance)

{
  _Instance *instance_00;
  uint *puVar1;
  void *pvVar2;
  
  puVar1 = (uint *)instance->extraData;
  if (((puVar1[0x31] != 0) &&
      (*(short *)(puVar1[0x31] + 0x14) < *(short *)(*(int *)(puVar1[0x59] + 8) + 10))) &&
     (*(char *)((int)puVar1 + 0x15a) == '\x01')) {
    instance_00 = instance->LinkChild;
    pvVar2 = instance->data;
    if (instance_00 == (_Instance *)0x0) {
      HUMAN_CreateWeapon(instance,0xb,(uint)*(byte *)((int)pvVar2 + 0x23));
    }
    else {
      if ((instance_00->LinkSibling != (_Instance *)0x0) ||
         (instance_00->ParentLinkNode != (uint)*(byte *)((int)pvVar2 + 0x24))) goto LAB_8008ebd8;
      INSTANCE_UnlinkFromParent(instance_00);
      INSTANCE_LinkToParent(instance_00,instance,(uint)*(byte *)((int)pvVar2 + 0x23));
    }
    *puVar1 = *puVar1 | 0x20;
  }
LAB_8008ebd8:
  MON_CombatEntry(instance);
  return;
}





