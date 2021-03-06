#include "THISDUST.H"
#include "GENERIC.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GenericInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 28, offset 0x8003e7a0
	/* begin block 1 */
		// Start line: 29
		// Start offset: 0x8003E7A0
		// Variables:
	// 		struct Spline *spline; // $v1
	// 		struct Object *object; // $s1

		/* begin block 1.1 */
			// Start line: 56
			// Start offset: 0x8003E824

			/* begin block 1.1.1 */
				// Start line: 66
				// Start offset: 0x8003E8BC
				// Variables:
			// 		static struct _G2AnimInterpInfo_Type crap; // offset 0x0
			/* end block 1.1.1 */
			// End offset: 0x8003E8C8
			// End Line: 68
		/* end block 1.1 */
		// End offset: 0x8003E8C8
		// End Line: 69
	/* end block 1 */
	// End offset: 0x8003E8C8
	// End Line: 72

	/* begin block 2 */
		// Start line: 56
	/* end block 2 */
	// End Line: 57

void GenericInit(_Instance *instance,GameTracker *gameTracker)

{
  MultiSpline *pMVar1;
  Spline *pSVar2;
  Object *pOVar3;
  
  pOVar3 = instance->object;
  pSVar2 = (Spline *)0x0;
  if ((instance->intro != (Intro *)0x0) &&
     (pMVar1 = instance->intro->multiSpline, pMVar1 != (MultiSpline *)0x0)) {
    pSVar2 = pMVar1->positional;
  }
  if (pSVar2 == (Spline *)0x0) {
    instance->zAccl = -10;
    instance->maxXVel = 100;
    instance->maxYVel = 100;
    instance->maxZVel = 100;
  }
  if (((pOVar3 != (Object *)0x0) && (pOVar3->numAnims != 0)) &&
     ((pOVar3->oflags2 & 0x40000000U) == 0)) {
    G2EmulationInstanceSetTotalSections(instance,1);
    G2EmulationInstanceSetStartAndEndSegment
              (instance,0,0,
               (short)(((uint)*(ushort *)&pOVar3->modelList[instance->currentModel]->numSegments - 1
                       ) * 0x10000 >> 0x10));
    G2EmulationInstanceSetAnimation(instance,0,0,0,0);
    G2EmulationInstanceSetMode(instance,0,0);
    if ((*(int *)pOVar3->name == 0x65697261) && (*(int *)(pOVar3->name + 1) == 0x5f5f5f6c)) {
      G2AnimSection_SetInterpInfo((instance->anim).section,(_G2AnimInterpInfo_Type *)&crap_24);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GenericCollide(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 74, offset 0x8003e8dc
	/* begin block 1 */
		// Start line: 151
	/* end block 1 */
	// End Line: 152

	/* begin block 2 */
		// Start line: 205
	/* end block 2 */
	// End Line: 206

void GenericCollide(_Instance *instance,GameTracker *gameTracker)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GenericProcess(struct _Instance *instance /*$a0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 134, offset 0x8003e8e4
	/* begin block 1 */
		// Start line: 135
		// Start offset: 0x8003E8E4
		// Variables:
	// 		struct Object *object; // $v1
	/* end block 1 */
	// End offset: 0x8003E928
	// End Line: 144

	/* begin block 2 */
		// Start line: 271
	/* end block 2 */
	// End Line: 272

void GenericProcess(_Instance *instance,GameTracker *gameTracker)

{
  Object *pOVar1;
  
  pOVar1 = instance->object;
  if (((pOVar1 != (Object *)0x0) && (pOVar1->numAnims != 0)) &&
     ((pOVar1->oflags2 & 0x40000000U) == 0)) {
    G2EmulationInstancePlayAnimation(instance);
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ GenericQuery(struct _Instance *instance /*$s0*/, unsigned long query /*$a1*/)
 // line 149, offset 0x8003e938
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8003E938
		// Variables:
	// 		long ret; // $a0

		/* begin block 1.1 */
			// Start line: 181
			// Start offset: 0x8003EA0C
			// Variables:
		// 		struct evControlSaveDataData *pdata; // $v0
		/* end block 1.1 */
		// End offset: 0x8003EA4C
		// End Line: 191

		/* begin block 1.2 */
			// Start line: 195
			// Start offset: 0x8003EA4C
			// Variables:
		// 		struct Object *object; // $a0
		/* end block 1.2 */
		// End offset: 0x8003EA90
		// End Line: 203
	/* end block 1 */
	// End offset: 0x8003EA9C
	// End Line: 216

	/* begin block 2 */
		// Start line: 301
	/* end block 2 */
	// End Line: 302

ulong GenericQuery(_Instance *instance,ulong query)

{
  short sVar1;
  short sVar2;
  short sVar3;
  long *plVar4;
  MATRIX *pMVar5;
  uint uVar6;
  long lVar7;
  
  pMVar5 = (MATRIX *)0x0;
  switch(query) {
  case 1:
    uVar6 = instance->object->oflags2;
    if ((uVar6 & 0x4000000) == 0) {
      pMVar5 = (MATRIX *)&DAT_00100000;
      if (((instance->object->oflags & 0x100000U) == 0) &&
         (pMVar5 = (MATRIX *)&DAT_80000000, (uVar6 & 0x20) != 0)) {
        pMVar5 = (MATRIX *)0x200000;
      }
    }
    else {
      pMVar5 = (MATRIX *)&DAT_00040000;
    }
    break;
  case 2:
  case 3:
  case 4:
  case 5:
  case 8:
  case 9:
  case 10:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
    pMVar5 = (MATRIX *)0x0;
    break;
  case 6:
    sVar1 = (instance->position).x;
    sVar2 = (instance->position).y;
    sVar3 = (instance->position).z;
    goto LAB_8003e998;
  case 7:
    sVar1 = (instance->rotation).x;
    sVar2 = (instance->rotation).y;
    sVar3 = (instance->rotation).z;
LAB_8003e998:
    pMVar5 = (MATRIX *)SetPositionData((int)sVar1,(int)sVar2,(int)sVar3);
    break;
  case 0xb:
    pMVar5 = (MATRIX *)&UNK_00000001;
    if ((instance->flags2 & 0x8000000U) != 0) {
      pMVar5 = (MATRIX *)&UNK_00000002;
    }
    break;
  case 0xc:
    pMVar5 = instance->matrix;
    break;
  case 0x11:
    pMVar5 = (MATRIX *)G2EmulationInstanceQueryAnimation(instance,0);
    break;
  case 0x12:
    pMVar5 = (MATRIX *)G2EmulationInstanceQueryFrame(instance,0);
    break;
  case 0x18:
    if ((instance->flags2 & 4U) != 0) {
      pMVar5 = (MATRIX *)CIRC_Alloc(0xc);
      plVar4 = *(long **)(pMVar5->m + 2);
      *(undefined4 *)pMVar5->m = 8;
      lVar7 = instance->flags2;
      *plVar4 = instance->flags;
      plVar4[1] = lVar7;
    }
    break;
  default:
    return 0;
  }
  return (ulong)pMVar5;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GenericMessage(struct _Instance *instance /*$s0*/, unsigned long message /*$a1*/, unsigned long data /*$v1*/)
 // line 222, offset 0x8003eab0
	/* begin block 1 */
		// Start line: 223
		// Start offset: 0x8003EAB0

		/* begin block 1.1 */
			// Start line: 228
			// Start offset: 0x8003EB44
			// Variables:
		// 		struct evAnimationInstanceSwitchData *Ptr; // $s1
		/* end block 1.1 */
		// End offset: 0x8003EB94
		// End Line: 239

		/* begin block 1.2 */
			// Start line: 245
			// Start offset: 0x8003EBA4
		/* end block 1.2 */
		// End offset: 0x8003EBA4
		// End Line: 246

		/* begin block 1.3 */
			// Start line: 260
			// Start offset: 0x8003EBF0
		/* end block 1.3 */
		// End offset: 0x8003EC18
		// End Line: 268
	/* end block 1 */
	// End offset: 0x8003EC18
	// End Line: 275

	/* begin block 2 */
		// Start line: 453
	/* end block 2 */
	// End Line: 454

void GenericMessage(_Instance *instance,ulong message,ulong data)

{
  int local_18;
  
  if ((undefined *)message == &DAT_0004000b) {
    (instance->rotation).x = *(short *)data;
    (instance->rotation).y = *(short *)(data + 2);
    (instance->rotation).z = *(short *)(data + 4);
  }
  else {
    if (&DAT_0004000b < message) {
      if (message == 0x8000008) {
        if ((instance->anim).section[0].interpInfo == (_G2AnimInterpInfo_Type *)0x0) {
          local_18 = 0;
        }
        else {
          local_18 = *(int *)(data + 0xc);
        }
        G2EmulationInstanceSetAnimation(instance,0,*(int *)(data + 4),*(int *)(data + 8),local_18);
        G2EmulationInstanceSetMode(instance,0,*(int *)(data + 0x10));
      }
      else {
        if (message < 0x8000009) {
          if ((undefined *)message == &DAT_00100007) {
            instance->flags = **(long **)(data + 4);
            instance->flags2 = *(long *)(*(int *)(data + 4) + 4);
          }
        }
        else {
          if (message == 0x8000010) {
            G2EmulationInstanceSetMode(instance,0,data);
          }
        }
      }
    }
    else {
      if ((undefined *)message == &DAT_00040002) {
        ScriptKillInstance(instance,data);
      }
      else {
        if ((undefined *)message == &DAT_0004000a) {
          STREAM_SetInstancePosition(instance,(evPositionData *)data);
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GenericRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 277, offset 0x8003ec2c
	/* begin block 1 */
		// Start line: 279
		// Start offset: 0x8003EC2C
		// Variables:
	// 		struct GenericTune *tune; // $v1
	/* end block 1 */
	// End offset: 0x8003EC50
	// End Line: 285

	/* begin block 2 */
		// Start line: 565
	/* end block 2 */
	// End Line: 566

	/* begin block 3 */
		// Start line: 566
	/* end block 3 */
	// End Line: 567

void GenericRelocateTune(Object *object,long offset)

{
  void *pvVar1;
  
  pvVar1 = object->data;
  if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 4) != 0)) {
    *(int *)((int)pvVar1 + 4) = *(int *)((int)pvVar1 + 4) + offset;
  }
  return;
}





