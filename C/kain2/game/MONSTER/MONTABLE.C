#include "THISDUST.H"
#include "MONTABLE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ MONTABLE_SetupTablePointer(struct Object *object /*$a0*/)
 // line 376, offset 0x8008d044
	/* begin block 1 */
		// Start line: 378
		// Start offset: 0x8008D044
		// Variables:
	// 		long whatAmI; // $a1
	/* end block 1 */
	// End offset: 0x8008D08C
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

void MONTABLE_SetupTablePointer(Object *object)

{
  int iVar1;
  MONTABLE_207fake *pMVar2;
  int iVar3;
  
  iVar3 = *(int *)((int)object->data + 0x10);
  pMVar2 = &functionChoiceTable;
  iVar1 = 4;
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
 // line 392, offset 0x8008d094
	/* begin block 1 */
		// Start line: 394
		// Start offset: 0x8008D094
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0

		/* begin block 1.1 */
			// Start line: 398
			// Start offset: 0x8008D0AC
			// Variables:
		// 		struct _MonsterStateChoice *choice; // $a0
		/* end block 1.1 */
		// End offset: 0x8008D0E8
		// End Line: 403
	/* end block 1 */
	// End offset: 0x8008D0F4
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
 // line 408, offset 0x8008d104
	/* begin block 1 */
		// Start line: 410
		// Start offset: 0x8008D104
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D130
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
 // line 418, offset 0x8008d138
	/* begin block 1 */
		// Start line: 420
		// Start offset: 0x8008D138
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D164
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
 // line 428, offset 0x8008d16c
	/* begin block 1 */
		// Start line: 430
		// Start offset: 0x8008D16C
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D198
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
 // line 438, offset 0x8008d1a0
	/* begin block 1 */
		// Start line: 440
		// Start offset: 0x8008D1A0
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D1CC
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
 // line 446, offset 0x8008d1d4
	/* begin block 1 */
		// Start line: 448
		// Start offset: 0x8008D1D4
		// Variables:
	// 		struct _MonsterFunctionTable *ft; // $v0
	/* end block 1 */
	// End offset: 0x8008D200
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
  if ((pvVar1 != (void *)0x0) &&
     (p_Var2 = *(_func_5 **)((int)pvVar1 + 0x10), p_Var2 != (_func_5 *)0x0)) {
    instance->messageFunc = p_Var2;
  }
  return;
}





