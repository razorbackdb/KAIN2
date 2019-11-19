#include "THISDUST.H"
#include "SCRIPT2.H"


// decompiled code
// original method signature: 
// void /*$ra*/ LitShaftInit(struct _Instance *instance /*$s1*/, struct GameTracker *gameTracker /*$a1*/)
 // line 127, offset 0x80061930
	/* begin block 1 */
		// Start line: 128
		// Start offset: 0x80061930
		// Variables:
	// 		struct LitShaftProperties *Prop; // $s0

		/* begin block 1.1 */
			// Start line: 133
			// Start offset: 0x80061954
			// Variables:
		// 		int curTimeOfDay; // $v1
		/* end block 1.1 */
		// End offset: 0x800619AC
		// End Line: 146
	/* end block 1 */
	// End offset: 0x800619AC
	// End Line: 147

	/* begin block 2 */
		// Start line: 188
	/* end block 2 */
	// End Line: 189

	/* begin block 3 */
		// Start line: 243
	/* end block 3 */
	// End Line: 244

void LitShaftInit(_Instance *instance,GameTracker *gameTracker)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  psVar3 = (short *)instance->data;
  if (psVar3 == (short *)0x0) {
    return;
  }
  iVar2 = GAMELOOP_GetTimeOfDay();
  if (iVar2 != 700) {
    if (iVar2 < 0x2bd) {
      sVar1 = 0x1000;
      if (iVar2 != 600) {
        return;
      }
      goto code_r0x800619a8;
    }
    if (iVar2 != 0x708) {
      if (iVar2 != 0x76c) {
        return;
      }
      instance->fadeValue = 0x1000;
      return;
    }
  }
  sVar1 = *psVar3;
code_r0x800619a8:
  instance->fadeValue = sVar1;
  return;
}



// decompiled code
// original method signature: 
// short /*$ra*/ LitShaft_GetFadeValue(struct _Instance *instance /*$a0*/)
 // line 149, offset 0x800619c0
	/* begin block 1 */
		// Start line: 151
		// Start offset: 0x800619C0
		// Variables:
	// 		struct LitShaftProperties *Prop; // $v0
	/* end block 1 */
	// End offset: 0x800619DC
	// End Line: 156

	/* begin block 2 */
		// Start line: 232
	/* end block 2 */
	// End Line: 233

	/* begin block 3 */
		// Start line: 233
	/* end block 3 */
	// End Line: 234

short LitShaft_GetFadeValue(_Instance *instance)

{
  if ((short *)instance->data == (short *)0x0) {
    return 0;
  }
  return *(short *)instance->data;
}





