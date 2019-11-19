#include "THISDUST.H"
#include "MONTABLE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetupTablePointer(struct Object *object /*$a0*/)
 // line 375, offset 0x8008ae7c
	/* begin block 1 */
		// Start line: 377
		// Start offset: 0x8008AE7C
		// Variables:
	// 		long whatAmI; // $a1
	/* end block 1 */
	// End offset: 0x8008AEC4
	// End Line: 389

	/* begin block 2 */
		// Start line: 750
	/* end block 2 */
	// End Line: 751

	/* begin block 3 */
		// Start line: 751
	/* end block 3 */
	// End Line: 752

	/* begin block 4 */
		// Start line: 756
	/* end block 4 */
	// End Line: 757

void MONTABLE_SetupTablePointer(Object *object)

{
  int iVar1;
  MONTABLE_202fake *pMVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)object->data + 0x10);
  pMVar2 = &functionChoiceTable;
  iVar1 = 0x42;
  do {
    if (iVar3 == iVar1) {
      *(_MonsterFunctionTable **)&object->relocModule = pMVar2->table;
    }
    pMVar2 = pMVar2 + 1;
    iVar1 = pMVar2->whatAmI;
  } while (iVar1 != 0);
  return;
}



// decompiled code
// original method signature: 
// struct _MonsterState * /*$ra*/ MONTABLE_GetStateFuncs(struct _Instance *instance /*$a0*/, int state /*$a1*/)
 // line 391, offset 0x8008aecc
	/* begin block 1 */
		// Start line: 393
		// Start offset: 0x8008AECC
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0

		/* begin block 1.1 */
			// Start line: 397
			// Start offset: 0x8008AEE4
			// Variables:
		// 		struct _MonsterStateChoice *choice; // $a0
		/* end block 1.1 */
		// End offset: 0x8008AF20
		// End Line: 402
	/* end block 1 */
	// End offset: 0x8008AF2C
	// End Line: 405

	/* begin block 2 */
		// Start line: 796
	/* end block 2 */
	// End Line: 797

	/* begin block 3 */
		// Start line: 797
	/* end block 3 */
	// End Line: 798

_MonsterState * MONTABLE_GetStateFuncs(_Instance *instance,int state)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  pvVar1 = instance->object->relocModule;
  if (pvVar1 != (void *)0x0) {
    piVar3 = *(int **)((int)pvVar1 + 0x14);
    iVar2 = *piVar3;
    while (iVar2 != -1) {
      if (state == *piVar3) {
        return (_MonsterState *)(piVar3 + 1);
      }
      piVar3 = piVar3 + 3;
      iVar2 = *piVar3;
    }
  }
  return &DefaultStateTable + state;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_MONTABLE_GetDamageEffectFunc /*$ra*/ MONTABLE_GetDamageEffectFunc(struct _Instance *instance /*$a0*/)
 // line 407, offset 0x8008af3c
	/* begin block 1 */
		// Start line: 409
		// Start offset: 0x8008AF3C
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008AF68
	// End Line: 415

	/* begin block 2 */
		// Start line: 829
	/* end block 2 */
	// End Line: 830

	/* begin block 3 */
		// Start line: 830
	/* end block 3 */
	// End Line: 831

TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(_Instance *instance)

{
  void *pvVar1;
  code *pcVar2;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 == (void *)0x0) ||
     (pcVar2 = *(TDRFuncPtr_MONTABLE_GetDamageEffectFunc *)((int)pvVar1 + 8),
     pcVar2 == (TDRFuncPtr_MONTABLE_GetDamageEffectFunc)0x0)) {
    pcVar2 = MON_DamageEffect;
  }
  return pcVar2;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_MONTABLE_GetInitFunc /*$ra*/ MONTABLE_GetInitFunc(struct _Instance *instance /*$a0*/)
 // line 417, offset 0x8008af70
	/* begin block 1 */
		// Start line: 419
		// Start offset: 0x8008AF70
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008AF9C
	// End Line: 425

	/* begin block 2 */
		// Start line: 849
	/* end block 2 */
	// End Line: 850

	/* begin block 3 */
		// Start line: 850
	/* end block 3 */
	// End Line: 851

TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(_Instance *instance)

{
  TDRFuncPtr_MONTABLE_GetInitFunc *ppTVar1;
  code *pcVar2;
  
  ppTVar1 = (TDRFuncPtr_MONTABLE_GetInitFunc *)instance->object->relocModule;
  if ((ppTVar1 == (TDRFuncPtr_MONTABLE_GetInitFunc *)0x0) ||
     (pcVar2 = *ppTVar1, pcVar2 == (TDRFuncPtr_MONTABLE_GetInitFunc)0x0)) {
    pcVar2 = MON_DefaultInit;
  }
  return pcVar2;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_MONTABLE_GetCleanUpFunc /*$ra*/ MONTABLE_GetCleanUpFunc(struct _Instance *instance /*$a0*/)
 // line 427, offset 0x8008afa4
	/* begin block 1 */
		// Start line: 429
		// Start offset: 0x8008AFA4
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008AFD0
	// End Line: 435

	/* begin block 2 */
		// Start line: 869
	/* end block 2 */
	// End Line: 870

	/* begin block 3 */
		// Start line: 870
	/* end block 3 */
	// End Line: 871

TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(_Instance *instance)

{
  void *pvVar1;
  code *pcVar2;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 == (void *)0x0) ||
     (pcVar2 = *(TDRFuncPtr_MONTABLE_GetCleanUpFunc *)((int)pvVar1 + 4),
     pcVar2 == (TDRFuncPtr_MONTABLE_GetCleanUpFunc)0x0)) {
    pcVar2 = MON_CleanUp;
  }
  return pcVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetQueryFunc(struct _Instance *instance /*$a0*/)
 // line 437, offset 0x8008afd8
	/* begin block 1 */
		// Start line: 439
		// Start offset: 0x8008AFD8
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008B004
	// End Line: 443

	/* begin block 2 */
		// Start line: 889
	/* end block 2 */
	// End Line: 890

	/* begin block 3 */
		// Start line: 890
	/* end block 3 */
	// End Line: 891

void MONTABLE_SetQueryFunc(_Instance *instance)

{
  void *pvVar1;
  _func_4392 *p_Var2;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 != (void *)0x0) &&
     (p_Var2 = *(_func_4392 **)((int)pvVar1 + 0xc), p_Var2 != (_func_4392 *)0x0)) {
    instance->queryFunc = p_Var2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetMessageFunc(struct _Instance *instance /*$a0*/)
 // line 445, offset 0x8008b00c
	/* begin block 1 */
		// Start line: 447
		// Start offset: 0x8008B00C
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008B038
	// End Line: 451

	/* begin block 2 */
		// Start line: 905
	/* end block 2 */
	// End Line: 906

	/* begin block 3 */
		// Start line: 906
	/* end block 3 */
	// End Line: 907

void MONTABLE_SetMessageFunc(_Instance *instance)

{
  void *pvVar1;
  _func_4393 *p_Var2;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 != (void *)0x0) &&
     (p_Var2 = *(_func_4393 **)((int)pvVar1 + 0x10), p_Var2 != (_func_4393 *)0x0)) {
    instance->messageFunc = p_Var2;
  }
  return;
}





