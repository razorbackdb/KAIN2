#include "THISDUST.H"
#include "WORSHIP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ WORSHIP_Init(struct _Instance *instance /*$s2*/)
 // line 47, offset 0x8008d1f4
	/* begin block 1 */
		// Start line: 48
		// Start offset: 0x8008D1F4
		// Variables:
	// 		struct _MonsterAttributes *ma; // $s1
	// 		struct _MonsterVars *mv; // $s0
	/* end block 1 */
	// End offset: 0x8008D258
	// End Line: 61

	/* begin block 2 */
		// Start line: 94
	/* end block 2 */
	// End Line: 95

void WORSHIP_Init(_Instance *instance)

{
  byte bVar1;
  int weaponid;
  void *pvVar2;
  void *pvVar3;
  
  pvVar3 = instance->data;
  pvVar2 = instance->extraData;
  HUMAN_Init(instance);
  if (*(char *)((int)pvVar2 + 0x15a) == '\0') {
    bVar1 = *(byte *)((int)pvVar3 + 0x24);
    weaponid = 0xc;
  }
  else {
    HUMAN_CreateWeapon(instance,0xb,(uint)*(byte *)((int)pvVar3 + 0x23));
    bVar1 = *(byte *)((int)pvVar3 + 0x24);
    weaponid = 0xb;
  }
  HUMAN_CreateWeapon(instance,weaponid,(uint)bVar1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ WORSHIP_CombatEntry(struct _Instance *instance /*$s3*/)
 // line 66, offset 0x8008d270
	/* begin block 1 */
		// Start line: 67
		// Start offset: 0x8008D270
		// Variables:
	// 		struct _MonsterVars *mv; // $s1

		/* begin block 1.1 */
			// Start line: 72
			// Start offset: 0x8008D2D8
			// Variables:
		// 		struct _MonsterAttributes *ma; // $s2

			/* begin block 1.1.1 */
				// Start line: 76
				// Start offset: 0x8008D2E8
			/* end block 1.1.1 */
			// End offset: 0x8008D30C
			// End Line: 82
		/* end block 1.1 */
		// End offset: 0x8008D34C
		// End Line: 93
	/* end block 1 */
	// End offset: 0x8008D34C
	// End Line: 95

	/* begin block 2 */
		// Start line: 132
	/* end block 2 */
	// End Line: 133

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
         (instance_00->ParentLinkNode != (uint)*(byte *)((int)pvVar2 + 0x24))) goto LAB_8008d34c;
      INSTANCE_UnlinkFromParent(instance_00);
      INSTANCE_LinkToParent(instance_00,instance,(uint)*(byte *)((int)pvVar2 + 0x23));
    }
    *puVar1 = *puVar1 | 0x20;
  }
LAB_8008d34c:
  MON_CombatEntry(instance);
  return;
}





