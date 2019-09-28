#include "THISDUST.H"
#include "MONTABLE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetupTablePointer(struct Object *object /*$a0*/)
 // line 376, offset 0x8008ce88
	/* begin block 1 */
		// Start line: 378
		// Start offset: 0x8008CE88
		// Variables:
	// 		long whatAmI; // $a1
	/* end block 1 */
	// End offset: 0x8008CED0
	// End Line: 390

	/* begin block 2 */
		// Start line: 752
	/* end block 2 */
	// End Line: 753

	/* begin block 3 */
		// Start line: 753
	/* end block 3 */
	// End Line: 754

	/* begin block 4 */
		// Start line: 758
	/* end block 4 */
	// End Line: 759

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MONTABLE_SetupTablePointer(Object *object)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)object->data + 0x10);
  psVar2 = &functionChoiceTable;
  iVar1 = _functionChoiceTable;
  if (_functionChoiceTable != 0) {
    do {
      if (iVar3 == iVar1) {
        object->relocModule = (void *)((int *)psVar2)[1];
      }
      psVar2 = (short *)((int *)psVar2 + 2);
      iVar1 = *(int *)psVar2;
    } while (*(int *)psVar2 != 0);
  }
  return;
}



// decompiled code
// original method signature: 
// struct _MonsterState * /*$ra*/ MONTABLE_GetStateFuncs(struct _Instance *instance /*$a0*/, int state /*$a1*/)
 // line 392, offset 0x8008ced8
	/* begin block 1 */
		// Start line: 394
		// Start offset: 0x8008CED8
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0

		/* begin block 1.1 */
			// Start line: 398
			// Start offset: 0x8008CEF0
			// Variables:
		// 		struct _MonsterStateChoice *choice; // $a0
		/* end block 1.1 */
		// End offset: 0x8008CF2C
		// End Line: 403
	/* end block 1 */
	// End offset: 0x8008CF38
	// End Line: 406

	/* begin block 2 */
		// Start line: 798
	/* end block 2 */
	// End Line: 799

	/* begin block 3 */
		// Start line: 799
	/* end block 3 */
	// End Line: 800

_MonsterState * MONTABLE_GetStateFuncs(_Instance *instance,int state)

{
  _MonsterState *p_Var1;
  int iVar2;
  int *piVar3;
  
  p_Var1 = (_MonsterState *)instance->object->relocModule;
  if (p_Var1 == (_MonsterState *)0x0) {
    MON_CleanUp(instance);
    return p_Var1;
  }
  piVar3 = (int *)p_Var1[2].stateFunction;
  iVar2 = *piVar3;
  while( true ) {
    if (iVar2 == -1) {
      return (_MonsterState *)(&DefaultStateTable + state * 4);
    }
    if (state == *piVar3) break;
    piVar3 = piVar3 + 3;
    iVar2 = *piVar3;
  }
  return (_MonsterState *)(piVar3 + 1);
}



// decompiled code
// original method signature: 
// TDRFuncPtr_MONTABLE_GetDamageEffectFunc /*$ra*/ MONTABLE_GetDamageEffectFunc(struct _Instance *instance /*$a0*/)
 // line 408, offset 0x8008cf48
	/* begin block 1 */
		// Start line: 410
		// Start offset: 0x8008CF48
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008CF74
	// End Line: 416

	/* begin block 2 */
		// Start line: 831
	/* end block 2 */
	// End Line: 832

	/* begin block 3 */
		// Start line: 832
	/* end block 3 */
	// End Line: 833

TDRFuncPtr_MONTABLE_GetDamageEffectFunc MONTABLE_GetDamageEffectFunc(_Instance *instance)

{
  void *pvVar1;
  TDRFuncPtr_MONTABLE_GetDamageEffectFunc pTVar2;
  evFXHitData *in_a1;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 != (void *)0x0) &&
     (pTVar2 = *(TDRFuncPtr_MONTABLE_GetDamageEffectFunc *)((int)pvVar1 + 8),
     pTVar2 != (TDRFuncPtr_MONTABLE_GetDamageEffectFunc)0x0)) {
    SLUAGH_DamageEffect(instance,in_a1);
    return pTVar2;
  }
  return (TDRFuncPtr_MONTABLE_GetDamageEffectFunc)DefaultFunctionTable.damageEffectFunc;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_MONTABLE_GetInitFunc /*$ra*/ MONTABLE_GetInitFunc(struct _Instance *instance /*$a0*/)
 // line 418, offset 0x8008cf7c
	/* begin block 1 */
		// Start line: 420
		// Start offset: 0x8008CF7C
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008CFA8
	// End Line: 426

	/* begin block 2 */
		// Start line: 851
	/* end block 2 */
	// End Line: 852

	/* begin block 3 */
		// Start line: 852
	/* end block 3 */
	// End Line: 853

TDRFuncPtr_MONTABLE_GetInitFunc MONTABLE_GetInitFunc(_Instance *instance)

{
  TDRFuncPtr_MONTABLE_GetInitFunc *ppTVar1;
  TDRFuncPtr_MONTABLE_GetInitFunc pTVar2;
  
  ppTVar1 = (TDRFuncPtr_MONTABLE_GetInitFunc *)instance->object->relocModule;
  if ((ppTVar1 == (TDRFuncPtr_MONTABLE_GetInitFunc *)0x0) ||
     (pTVar2 = *ppTVar1, pTVar2 == (TDRFuncPtr_MONTABLE_GetInitFunc)0x0)) {
    pTVar2 = (TDRFuncPtr_MONTABLE_GetInitFunc)DefaultFunctionTable.initFunc;
  }
  return pTVar2;
}



// decompiled code
// original method signature: 
// TDRFuncPtr_MONTABLE_GetCleanUpFunc /*$ra*/ MONTABLE_GetCleanUpFunc(struct _Instance *instance /*$a0*/)
 // line 428, offset 0x8008cfb0
	/* begin block 1 */
		// Start line: 430
		// Start offset: 0x8008CFB0
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008CFDC
	// End Line: 436

	/* begin block 2 */
		// Start line: 871
	/* end block 2 */
	// End Line: 872

	/* begin block 3 */
		// Start line: 872
	/* end block 3 */
	// End Line: 873

TDRFuncPtr_MONTABLE_GetCleanUpFunc MONTABLE_GetCleanUpFunc(_Instance *instance)

{
  void *pvVar1;
  TDRFuncPtr_MONTABLE_GetCleanUpFunc pTVar2;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 == (void *)0x0) ||
     (pTVar2 = *(TDRFuncPtr_MONTABLE_GetCleanUpFunc *)((int)pvVar1 + 4),
     pTVar2 == (TDRFuncPtr_MONTABLE_GetCleanUpFunc)0x0)) {
    pTVar2 = (TDRFuncPtr_MONTABLE_GetCleanUpFunc)DefaultFunctionTable.cleanUpFunc;
  }
  return pTVar2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetQueryFunc(struct _Instance *instance /*$a0*/)
 // line 438, offset 0x8008cfe4
	/* begin block 1 */
		// Start line: 440
		// Start offset: 0x8008CFE4
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D010
	// End Line: 444

	/* begin block 2 */
		// Start line: 891
	/* end block 2 */
	// End Line: 892

	/* begin block 3 */
		// Start line: 892
	/* end block 3 */
	// End Line: 893

void MONTABLE_SetQueryFunc(_Instance *instance)

{
  void *pvVar1;
  _func_4 *p_Var2;
  
  pvVar1 = instance->object->relocModule;
  if ((pvVar1 != (void *)0x0) &&
     (p_Var2 = *(_func_4 **)((int)pvVar1 + 0xc), p_Var2 != (_func_4 *)0x0)) {
    instance->queryFunc = p_Var2;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetMessageFunc(struct _Instance *instance /*$a0*/)
 // line 446, offset 0x8008d018
	/* begin block 1 */
		// Start line: 448
		// Start offset: 0x8008D018
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D044
	// End Line: 452

	/* begin block 2 */
		// Start line: 907
	/* end block 2 */
	// End Line: 908

	/* begin block 3 */
		// Start line: 908
	/* end block 3 */
	// End Line: 909

void MONTABLE_SetMessageFunc(_Instance *instance)

{
  void *pvVar1;
  _func_5 *p_Var2;
  
  pvVar1 = instance->object->relocModule;
  if (pvVar1 == (void *)0x0) {
    MONTABLE_SetupTablePointer((Object *)instance);
    return;
  }
  p_Var2 = *(_func_5 **)((int)pvVar1 + 0x10);
  if (p_Var2 == (_func_5 *)0x0) {
    MONTABLE_SetupTablePointer((Object *)instance);
    return;
  }
  instance->messageFunc = p_Var2;
  return;
}





