#include "THISDUST.H"
#include "GENERIC.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GenericInit(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 28, offset 0x8003ed00
	/* begin block 1 */
		// Start line: 29
		// Start offset: 0x8003ED00
		// Variables:
	// 		struct Spline *spline; // $v1
	// 		struct Object *object; // $s1

		/* begin block 1.1 */
			// Start line: 56
			// Start offset: 0x8003ED84

			/* begin block 1.1.1 */
				// Start line: 66
				// Start offset: 0x8003EE1C
				// Variables:
			// 		static struct _G2AnimInterpInfo_Type crap; // offset 0x0
			/* end block 1.1.1 */
			// End offset: 0x8003EE2C
			// End Line: 68
		/* end block 1.1 */
		// End offset: 0x8003EE2C
		// End Line: 69
	/* end block 1 */
	// End offset: 0x8003EE2C
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
               (short)(((u_int)*(ushort *)&pOVar3->modelList[instance->currentModel]->numSegments - 1
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
 // line 74, offset 0x8003ee40
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
 // line 134, offset 0x8003ee48
	/* begin block 1 */
		// Start line: 135
		// Start offset: 0x8003EE48
		// Variables:
	// 		struct Object *object; // $v1
	/* end block 1 */
	// End offset: 0x8003EE8C
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
 // line 149, offset 0x8003ee9c
	/* begin block 1 */
		// Start line: 150
		// Start offset: 0x8003EE9C
		// Variables:
	// 		long ret; // $a2

		/* begin block 1.1 */
			// Start line: 181
			// Start offset: 0x8003EF70
			// Variables:
		// 		struct evControlSaveDataData *pdata; // $v0
		/* end block 1.1 */
		// End offset: 0x8003EFB0
		// End Line: 191

		/* begin block 1.2 */
			// Start line: 195
			// Start offset: 0x8003EFB0
			// Variables:
		// 		struct Object *object; // $a0
		/* end block 1.2 */
		// End offset: 0x8003EFF8
		// End Line: 203
	/* end block 1 */
	// End offset: 0x8003F004
	// End Line: 212

	/* begin block 2 */
		// Start line: 301
	/* end block 2 */
	// End Line: 302

u_long GenericQuery(_Instance *instance,u_long query)

{
  short sVar1;
  short sVar2;
  short sVar3;
  long *plVar4;
  u_int uVar5;
  MATRIX *pMVar6;
  long lVar7;
  
  pMVar6 = (MATRIX *)0x0;
  switch(query) {
  case 1:
    uVar5 = instance->object->oflags2;
    if ((uVar5 & 0x4000000) == 0) {
      if ((instance->object->oflags & 0x100000U) == 0) {
        if ((uVar5 & 0x20) != 0) {
          pMVar6 = (MATRIX *)0x200000;
        }
      }
      else {
        pMVar6 = (MATRIX *)&DAT_00100000;
      }
    }
    else {
      pMVar6 = (MATRIX *)0x40000;
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
    pMVar6 = (MATRIX *)0x0;
    break;
  case 6:
    sVar1 = (instance->position).x;
    sVar2 = (instance->position).y;
    sVar3 = (instance->position).z;
    goto LAB_8003eefc;
  case 7:
    sVar1 = (instance->rotation).x;
    sVar2 = (instance->rotation).y;
    sVar3 = (instance->rotation).z;
LAB_8003eefc:
    pMVar6 = (MATRIX *)SetPositionData((int)sVar1,(int)sVar2,(int)sVar3);
    break;
  case 0xb:
    pMVar6 = (MATRIX *)&UNK_00000001;
    if ((instance->flags2 & 0x8000000U) != 0) {
      pMVar6 = (MATRIX *)&UNK_00000002;
    }
    break;
  case 0xc:
    pMVar6 = instance->matrix;
    break;
  case 0x11:
    pMVar6 = (MATRIX *)G2EmulationInstanceQueryAnimation(instance,0);
    break;
  case 0x12:
    pMVar6 = (MATRIX *)G2EmulationInstanceQueryFrame(instance,0);
    break;
  case 0x18:
    if ((instance->flags2 & 4U) != 0) {
      pMVar6 = (MATRIX *)CIRC_Alloc(0xc);
      plVar4 = *(long **)(pMVar6->m + 2);
      *(undefined4 *)pMVar6->m = 8;
      lVar7 = instance->flags2;
      *plVar4 = instance->flags;
      plVar4[1] = lVar7;
    }
    break;
  default:
    return 0;
  }
  return (u_long)pMVar6;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GenericMessage(struct _Instance *instance /*$s0*/, unsigned long message /*$a1*/, unsigned long data /*$v1*/)
 // line 218, offset 0x8003f018
	/* begin block 1 */
		// Start line: 219
		// Start offset: 0x8003F018

		/* begin block 1.1 */
			// Start line: 224
			// Start offset: 0x8003F0AC
			// Variables:
		// 		struct evAnimationInstanceSwitchData *Ptr; // $s1
		/* end block 1.1 */
		// End offset: 0x8003F0FC
		// End Line: 235

		/* begin block 1.2 */
			// Start line: 241
			// Start offset: 0x8003F114
		/* end block 1.2 */
		// End offset: 0x8003F114
		// End Line: 242

		/* begin block 1.3 */
			// Start line: 256
			// Start offset: 0x8003F160
		/* end block 1.3 */
		// End offset: 0x8003F188
		// End Line: 264
	/* end block 1 */
	// End offset: 0x8003F188
	// End Line: 271

	/* begin block 2 */
		// Start line: 445
	/* end block 2 */
	// End Line: 446

void GenericMessage(_Instance *instance,u_long message,u_long data)

{
  int local_18;
  
  if (message == 0x4000b) {
    (instance->rotation).x = *(short *)data;
    (instance->rotation).y = *(short *)(data + 2);
    (instance->rotation).z = *(short *)(data + 4);
  }
  else {
    if (message < 0x4000c) {
      if (message == 0x40002) {
        ScriptKillInstance(instance,data);
      }
      else {
        if (message == 0x4000a) {
          STREAM_SetInstancePosition(&gameTrackerX,instance,(evPositionData *)data);
        }
      }
    }
    else {
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
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GenericRelocateTune(struct Object *object /*$a0*/, long offset /*$a1*/)
 // line 273, offset 0x8003f19c
	/* begin block 1 */
		// Start line: 275
		// Start offset: 0x8003F19C
		// Variables:
	// 		struct GenericTune *tune; // $v1
	/* end block 1 */
	// End offset: 0x8003F1C0
	// End Line: 281

	/* begin block 2 */
		// Start line: 557
	/* end block 2 */
	// End Line: 558

	/* begin block 3 */
		// Start line: 558
	/* end block 3 */
	// End Line: 559

void GenericRelocateTune(Object *object,long offset)

{
  void *pvVar1;
  
  pvVar1 = object->data;
  if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 4) != 0)) {
    *(int *)((int)pvVar1 + 4) = *(int *)((int)pvVar1 + 4) + offset;
  }
  return;
}





