#include "THISDUST.H"
#include "SPLINE.H"


// decompiled code
// original method signature: 
// void /*$ra*/ _SplineS2Pos(struct vecS *p /*$t6*/, long s /*$t1*/, struct SplineKey *key /*$t2*/, struct SplineKey *key2 /*$t5*/)
 // line 70, offset 0x800415e8
	/* begin block 1 */
		// Start line: 71
		// Start offset: 0x800415E8
		// Variables:
	// 		long s2; // $a3
	// 		long s3; // $t0
	// 		long h0; // $a2
	// 		long h1; // $a1
	// 		long h2; // $a0
	// 		long h3; // $t0
	/* end block 1 */
	// End offset: 0x80041750
	// End Line: 96

	/* begin block 2 */
		// Start line: 140
	/* end block 2 */
	// End Line: 141

void _SplineS2Pos(vecS *p,long s,SplineKey *key,SplineKey *key2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (s != 0) {
    iVar4 = s * s >> 0xf;
    iVar5 = iVar4 * s >> 0xf;
    iVar3 = iVar5 * 2 + iVar4 * -3 + 0x8000;
    iVar2 = iVar4 * 3 + iVar5 * -2;
    iVar1 = iVar5 + iVar4 * -2 + s;
    iVar5 = iVar5 - iVar4;
    p->x = (short)((key->point).x * iVar3 + (key2->point).x * iVar2 + (key->dd).x * iVar1 +
                   (key2->ds).x * iVar5 >> 0xf);
    p->y = (short)((key->point).y * iVar3 + (key2->point).y * iVar2 + (key->dd).y * iVar1 +
                   (key2->ds).y * iVar5 >> 0xf);
    p->z = (short)((key->point).z * iVar3 + (key2->point).z * iVar2 + (key->dd).z * iVar1 +
                   (key2->ds).z * iVar5 >> 0xf);
    return;
  }
  p->x = (key->point).x;
  p->y = (key->point).y;
  p->z = (key->point).z;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SplineSetDefDenom(struct Spline *spline /*$a0*/, struct SplineDef *def /*$a1*/, int denomFlag /*$a2*/)
 // line 132, offset 0x80041758
	/* begin block 1 */
		// Start line: 140
		// Start offset: 0x80041758
		// Variables:
	// 		unsigned long denom; // $v1
	/* end block 1 */
	// End offset: 0x80041814
	// End Line: 165

	/* begin block 2 */
		// Start line: 261
	/* end block 2 */
	// End Line: 262

	/* begin block 3 */
		// Start line: 257
	/* end block 3 */
	// End Line: 258

	/* begin block 4 */
		// Start line: 263
	/* end block 4 */
	// End Line: 264

void SplineSetDefDenom(Spline *spline,SplineDef *def,int denomFlag)

{
  short sVar1;
  uint uVar2;
  
  if ((uint)def->denomFlag != denomFlag) {
    if (def->fracCurr != 0) {
      if (spline->type == '\x01') {
        sVar1 = (&spline->key->count)[(int)def->currkey * 5];
      }
      else {
        sVar1 = spline->key[def->currkey].count;
      }
      uVar2 = SEXT24(sVar1);
      if (uVar2 == 0) {
        uVar2 = 1;
      }
      if (denomFlag == 0) {
        uVar2 = (uint)(def->fracCurr << 0xf) / uVar2;
      }
      else {
        uVar2 = def->fracCurr * uVar2 >> 0xf;
      }
      def->fracCurr = uVar2;
    }
    def->denomFlag = (ushort)denomFlag;
  }
  return;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ SplineGetFrameNumber(struct Spline *spline /*$a0*/, struct SplineDef *def /*$a1*/)
 // line 248, offset 0x8004181c
	/* begin block 1 */
		// Start line: 249
		// Start offset: 0x8004181C
		// Variables:
	// 		unsigned short frame; // $s0
	// 		unsigned int i; // $v1
	// 		struct SplineKey *key; // $a2
	// 		struct SplineDef temp; // stack offset -16
	/* end block 1 */
	// End offset: 0x8004189C
	// End Line: 285

	/* begin block 2 */
		// Start line: 492
	/* end block 2 */
	// End Line: 493

ushort SplineGetFrameNumber(Spline *spline,SplineDef *def)

{
  ushort uVar1;
  uint local_10;
  long local_c;
  
  if ((spline != (Spline *)0x0) && (def != (SplineDef *)0x0)) {
    local_c = def->fracCurr;
    _uVar1 = 0;
    uVar1 = 0;
    if ((int)def->currkey != 0) {
      do {
        _uVar1 = _uVar1 + 1;
        uVar1 = (ushort)_uVar1;
      } while (_uVar1 < (uint)(int)def->currkey);
    }
    local_10 = *(uint *)def & 0xffff0000 | (uint)uVar1;
                    /* WARNING: Subroutine does not return */
    SplineSetDefDenom(spline,(SplineDef *)&local_10,0);
  }
  return 0xffff;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SplineSetDef2FrameNumber(struct Spline *spline /*$a0*/, struct SplineDef *def /*$a1*/, unsigned short frame_number /*$a2*/)
 // line 288, offset 0x800418b0
	/* begin block 1 */
		// Start line: 289
		// Start offset: 0x800418B0
		// Variables:
	// 		unsigned long isRot; // $t3
	// 		short status; // $t4
	// 		struct SplineKey *key; // $t0
	// 		struct SplineRotKey *rkey; // $a3
	// 		unsigned short frame; // $t2
	// 		short deltaFrame; // $t1
	/* end block 1 */
	// End offset: 0x800419D4
	// End Line: 347

	/* begin block 2 */
		// Start line: 481
	/* end block 2 */
	// End Line: 482

	/* begin block 3 */
		// Start line: 493
	/* end block 3 */
	// End Line: 494

short SplineSetDef2FrameNumber(Spline *spline,SplineDef *def,ushort frame_number)

{
  short sVar1;
  bool bVar2;
  SplineKey *pSVar3;
  SplineKey *pSVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  
  sVar6 = 0;
  uVar5 = 0;
  def->currkey = 0;
  def->fracCurr = 0;
  if ((spline == (Spline *)0x0) || (def == (SplineDef *)0x0)) {
    sVar6 = -1;
  }
  else {
    pSVar3 = spline->key;
    bVar2 = spline->type != '\x01';
    pSVar4 = pSVar3;
    if (frame_number != 0) {
      do {
        if (spline->numkeys <= def->currkey) break;
        if (bVar2) {
          sVar1 = pSVar4->count;
        }
        else {
          sVar1 = pSVar3->count;
        }
        if ((int)((frame_number - uVar5) * 0x10000) >> 0x10 < (int)sVar1) {
          def->fracCurr = (int)((frame_number - uVar5) * 0x10000) >> 4;
          break;
        }
        if (bVar2) {
          sVar1 = pSVar4->count;
        }
        else {
          sVar1 = pSVar3->count;
        }
        uVar5 = (uVar5 & 0xffff) + (int)sVar1;
        uVar7 = ((int)def->currkey + 1) % (int)spline->numkeys;
        def->currkey = (short)uVar7;
        if ((uVar7 & 0xffff) == 0) {
          pSVar3 = spline->key;
          pSVar4 = pSVar3;
        }
        else {
          pSVar3 = (SplineKey *)((int)&(pSVar3->dd).x + 2);
          pSVar4 = pSVar4 + 1;
        }
      } while ((uVar5 & 0xffff) < (uint)frame_number);
    }
    def->denomFlag = 0;
  }
  return sVar6;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SplineIsWhere(struct Spline *spline /*$a0*/, struct SplineDef *def /*$a1*/)
 // line 355, offset 0x800419e0
	/* begin block 1 */
		// Start line: 357
		// Start offset: 0x800419E0
		// Variables:
	// 		short curr; // $v1
	/* end block 1 */
	// End offset: 0x80041A40
	// End Line: 367

	/* begin block 2 */
		// Start line: 618
	/* end block 2 */
	// End Line: 619

	/* begin block 3 */
		// Start line: 619
	/* end block 3 */
	// End Line: 620

short SplineIsWhere(Spline *spline,SplineDef *def)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = def->fracCurr >> 0xc;
  if (((uVar2 & 0xffff) == 0) && (def->currkey == 0)) {
    return -1;
  }
  sVar1 = 0;
  if (((int)(short)uVar2 == (int)spline->numkeys + -1) && (sVar1 = 1, def->currkey != 0)) {
    sVar1 = 0;
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// short /*$ra*/ SplineMultiIsWhere(struct MultiSpline *multi /*$s0*/)
 // line 368, offset 0x80041a48
	/* begin block 1 */
		// Start line: 369
		// Start offset: 0x80041A48
		// Variables:
	// 		short where; // $v1
	/* end block 1 */
	// End offset: 0x80041ABC
	// End Line: 384

	/* begin block 2 */
		// Start line: 644
	/* end block 2 */
	// End Line: 645

short SplineMultiIsWhere(MultiSpline *multi)

{
  short sVar1;
  
  sVar1 = 0;
  if (multi->positional != (Spline *)0x0) {
    sVar1 = SplineIsWhere(multi->positional,&multi->curPositional);
  }
  if (((Spline *)multi->rotational != (Spline *)0x0) && (sVar1 == 0)) {
    sVar1 = SplineIsWhere((Spline *)multi->rotational,&multi->curRotational);
  }
  if ((multi->scaling != (Spline *)0x0) && (sVar1 == 0)) {
    sVar1 = SplineIsWhere(multi->scaling,&multi->curScaling);
  }
  return sVar1;
}



// decompiled code
// original method signature: 
// struct _G2Quat_Type * /*$ra*/ SplineGetFirstRot(struct RSpline *rspline /*$a0*/, struct SplineDef *def /*$a1*/)
 // line 423, offset 0x80041ad4
	/* begin block 1 */
		// Start line: 819
	/* end block 1 */
	// End Line: 820

	/* begin block 2 */
		// Start line: 718
	/* end block 2 */
	// End Line: 719

_G2Quat_Type * SplineGetFirstRot(RSpline *rspline,SplineDef *def)

{
  if (rspline != (RSpline *)0x0) {
    def->fracCurr = 0;
    def->currkey = 0;
    def->denomFlag = 0;
    return &rspline->key->q;
  }
  return (_G2Quat_Type *)0x0;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetFirstPoint(struct Spline *spline /*$a0*/, struct SplineDef *def /*$a1*/)
 // line 435, offset 0x80041afc
	/* begin block 1 */
		// Start line: 741
	/* end block 1 */
	// End Line: 742

	/* begin block 2 */
		// Start line: 745
	/* end block 2 */
	// End Line: 746

	/* begin block 3 */
		// Start line: 746
	/* end block 3 */
	// End Line: 747

_SVector * SplineGetFirstPoint(Spline *spline,SplineDef *def)

{
  if (spline != (Spline *)0x0) {
    def->fracCurr = 0;
    def->currkey = 0;
    def->denomFlag = 0;
    return (_SVector *)&spline->key->point;
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetNextPoint(struct Spline *spline /*$s0*/, struct SplineDef *def /*$s1*/)
 // line 499, offset 0x80041b24
	/* begin block 1 */
		// Start line: 500
		// Start offset: 0x80041B24
		// Variables:
	// 		static struct _SVector point; // offset 0x8
	/* end block 1 */
	// End offset: 0x80041B70
	// End Line: 511

	/* begin block 2 */
		// Start line: 995
	/* end block 2 */
	// End Line: 996

_SVector * SplineGetNextPoint(Spline *spline,SplineDef *def)

{
  ulong uVar1;
  
  uVar1 = SplineGetNext(spline,def);
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,def,&point_53);
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetPreviousPoint(struct Spline *spline /*$s0*/, struct SplineDef *def /*$s1*/)
 // line 513, offset 0x80041b84
	/* begin block 1 */
		// Start line: 514
		// Start offset: 0x80041B84
		// Variables:
	// 		static struct _SVector point; // offset 0x10
	/* end block 1 */
	// End offset: 0x80041BD0
	// End Line: 525

	/* begin block 2 */
		// Start line: 846
	/* end block 2 */
	// End Line: 847

_SVector * SplineGetPreviousPoint(Spline *spline,SplineDef *def)

{
  ulong uVar1;
  
  uVar1 = SplineGetPrev(spline,def);
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,def,&point_56);
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetNearestPoint(struct Spline *spline /*$fp*/, struct _SVector *point /*$s4*/, struct SplineDef *def /*$t1*/)
 // line 539, offset 0x80041be4
	/* begin block 1 */
		// Start line: 540
		// Start offset: 0x80041BE4
		// Variables:
	// 		static struct _SVector dpoint; // offset 0x18
	// 		long dist; // $a1
	// 		long dist1; // $v0
	// 		long closest_dist; // $s6
	// 		int closest_keyframe; // $s3
	// 		int adjacent_keyframe; // $s5
	// 		int closest_ib; // $s2
	// 		int saved_closest_key_dist; // stack offset -56
	// 		int i; // $s0
	// 		int frame_count; // $s7
	// 		int swapped_keys; // stack offset -52
	// 		struct SplineKey *key; // $a3
	// 		struct _Vector d; // stack offset -80
	// 		struct SplineDef tempdef; // stack offset -64
	/* end block 1 */
	// End offset: 0x80041F5C
	// End Line: 681

	/* begin block 2 */
		// Start line: 900
	/* end block 2 */
	// End Line: 901

/* WARNING: Removing unreachable block (ram,0x80041f4c) */

_SVector * SplineGetNearestPoint(Spline *spline,_SVector *point,SplineDef *def)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  SplineKey *pSVar6;
  int iVar7;
  short *psVar8;
  undefined4 in_t2;
  undefined4 in_t3;
  int iVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  SplineDef SStack64;
  int iStack56;
  uint uStack52;
  SplineDef *pSStack48;
  
  iStack56 = 0x7fffffff;
  iVar9 = 0;
  iVar11 = 0;
  if (0 < spline->numkeys) {
    psVar8 = &(spline->key->point).z;
    do {
      setCopReg(2,def,(int)point->x - (int)psVar8[-2]);
      setCopReg(2,in_t2,(int)point->y - (int)psVar8[-1]);
      setCopReg(2,in_t3,(int)point->z - (int)*psVar8);
      copFunction(2,0xa00428);
      iVar2 = getCopReg(2,0x19);
      iVar3 = getCopReg(2,0x1a);
      iVar7 = getCopReg(2,0x1b);
      iVar7 = iVar2 + iVar3 + iVar7;
      if (iVar7 < iStack56) {
        iVar11 = iVar9;
        iStack56 = iVar7;
      }
      iVar9 = iVar9 + 1;
      psVar8 = psVar8 + 0x10;
    } while (iVar9 < spline->numkeys);
  }
  if (iVar11 == 0) {
    iVar12 = 1;
  }
  else {
    if (iVar11 == (int)spline->numkeys + -1) {
      iVar12 = (int)spline->numkeys + -2;
    }
    else {
      pSVar6 = spline->key + iVar11;
      setCopReg(2,def,(int)point->x - (int)pSVar6[-1].point.x);
      setCopReg(2,in_t2,(int)point->y - (int)pSVar6[-1].point.y);
      setCopReg(2,in_t3,(int)point->z - (int)pSVar6[-1].point.z);
      copFunction(2,0xa00428);
      iVar9 = getCopReg(2,0x19);
      iVar2 = getCopReg(2,0x1a);
      iVar3 = getCopReg(2,0x1b);
      pSVar6 = spline->key + iVar11;
      setCopReg(2,def,(int)point->x - (int)pSVar6[1].point.x);
      setCopReg(2,in_t2,(int)point->y - (int)pSVar6[1].point.y);
      setCopReg(2,in_t3,(int)point->z - (int)pSVar6[1].point.z);
      copFunction(2,0xa00428);
      iVar7 = getCopReg(2,0x19);
      iVar4 = getCopReg(2,0x1a);
      iVar5 = getCopReg(2,0x1b);
      iVar12 = iVar11 + 1;
      if (iVar9 + iVar2 + iVar3 <= iVar7 + iVar4 + iVar5) {
        iVar12 = iVar11 + -1;
      }
    }
  }
  bVar1 = iVar12 < iVar11;
  sVar10 = (short)iVar11;
  SStack64.currkey = sVar10;
  if (bVar1) {
    SStack64.currkey = (short)iVar12;
  }
  uStack52 = (uint)bVar1;
  SStack64.fracCurr = 0;
  SStack64.denomFlag = 0;
  if (0 < spline->key[SStack64.currkey].count) {
    pSStack48 = def;
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,&SStack64,&dpoint_59);
  }
  if (bVar1) {
    def->currkey = sVar10;
    def->fracCurr = 0;
  }
  else {
    def->currkey = sVar10;
    def->fracCurr = 0;
  }
                    /* WARNING: Subroutine does not return */
  def->denomFlag = 0;
  SplineGetData(spline,def,&dpoint_59);
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SplineGetData(struct Spline *spline /*$s1*/, struct SplineDef *def /*$s0*/, void *p /*$s4*/)
 // line 933, offset 0x80041fac
	/* begin block 1 */
		// Start line: 934
		// Start offset: 0x80041FAC
		// Variables:
	// 		unsigned long gotDataOk; // $s3
	// 		unsigned long isRot; // $s2
	// 		int count; // $v1
	// 		struct _G2Quat_Type quat; // stack offset -40
	// 		struct _G2EulerAngles_Type ea; // stack offset -32

		/* begin block 1.1 */
			// Start line: 965
			// Start offset: 0x80042080
		/* end block 1.1 */
		// End offset: 0x80042080
		// End Line: 966

		/* begin block 1.2 */
			// Start line: 976
			// Start offset: 0x800420BC
		/* end block 1.2 */
		// End offset: 0x800420BC
		// End Line: 977

		/* begin block 1.3 */
			// Start line: 990
			// Start offset: 0x80042138
			// Variables:
		// 		short _x1; // $v1
		// 		short _y1; // $a0
		// 		short _z1; // $v0
		// 		struct vecS *_v1; // $v0
		/* end block 1.3 */
		// End offset: 0x80042164
		// End Line: 990
	/* end block 1 */
	// End offset: 0x80042198
	// End Line: 1000

	/* begin block 2 */
		// Start line: 1852
	/* end block 2 */
	// End Line: 1853

ulong SplineGetData(Spline *spline,SplineDef *def,void *p)

{
  if ((((spline != (Spline *)0x0) && (def != (SplineDef *)0x0)) && (def->currkey < spline->numkeys))
     && (-1 < def->currkey)) {
                    /* WARNING: Subroutine does not return */
    SplineSetDefDenom(spline,def,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SplineGetQuatData(struct Spline *spline /*$s1*/, struct SplineDef *def /*$s0*/, void *p /*$s3*/)
 // line 1003, offset 0x800421bc
	/* begin block 1 */
		// Start line: 1004
		// Start offset: 0x800421BC
		// Variables:
	// 		unsigned long gotDataOk; // $s2
	// 		int count; // $a0
	// 		struct _G2Quat_Type quat; // stack offset -32

		/* begin block 1.1 */
			// Start line: 1023
			// Start offset: 0x80042254
		/* end block 1.1 */
		// End offset: 0x80042254
		// End Line: 1024
	/* end block 1 */
	// End offset: 0x800422D0
	// End Line: 1039

	/* begin block 2 */
		// Start line: 1703
	/* end block 2 */
	// End Line: 1704

ulong SplineGetQuatData(Spline *spline,SplineDef *def,void *p)

{
  if ((((spline != (Spline *)0x0) && (def != (SplineDef *)0x0)) && (def->currkey < spline->numkeys))
     && (-1 < def->currkey)) {
                    /* WARNING: Subroutine does not return */
    SplineSetDefDenom(spline,def,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SplineGetNext(struct Spline *spline /*$s1*/, struct SplineDef *def /*$s0*/)
 // line 1052, offset 0x800422f0
	/* begin block 1 */
		// Start line: 1053
		// Start offset: 0x800422F0
		// Variables:
	// 		unsigned long movedSplineOk; // $s3
	// 		int count; // $s2
	/* end block 1 */
	// End offset: 0x800423EC
	// End Line: 1106

	/* begin block 2 */
		// Start line: 1805
	/* end block 2 */
	// End Line: 1806

ulong SplineGetNext(Spline *spline,SplineDef *def)

{
  if (((spline != (Spline *)0x0) && (def != (SplineDef *)0x0)) && (def->currkey < spline->numkeys))
  {
                    /* WARNING: Subroutine does not return */
    SplineSetDefDenom(spline,def,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SplineGetPrev(struct Spline *spline /*$s0*/, struct SplineDef *def /*$s1*/)
 // line 1118, offset 0x8004240c
	/* begin block 1 */
		// Start line: 1119
		// Start offset: 0x8004240C
		// Variables:
	// 		unsigned long movedSplineOk; // $s2
	// 		unsigned long isRot; // $a1
	// 		int count; // $v0
	/* end block 1 */
	// End offset: 0x8004251C
	// End Line: 1184

	/* begin block 2 */
		// Start line: 1941
	/* end block 2 */
	// End Line: 1942

ulong SplineGetPrev(Spline *spline,SplineDef *def)

{
  if ((spline != (Spline *)0x0) && (def != (SplineDef *)0x0)) {
                    /* WARNING: Subroutine does not return */
    SplineSetDefDenom(spline,def,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SplineGetOffsetNext(struct Spline *spline /*$s2*/, struct SplineDef *def /*$s1*/, long fracOffset /*$s5*/)
 // line 1205, offset 0x80042538
	/* begin block 1 */
		// Start line: 1206
		// Start offset: 0x80042538
		// Variables:
	// 		unsigned long movedSplineOk; // $s3
	// 		unsigned long isRot; // $s4
	// 		int count; // $s0
	/* end block 1 */
	// End offset: 0x800426F4
	// End Line: 1271

	/* begin block 2 */
		// Start line: 2119
	/* end block 2 */
	// End Line: 2120

ulong SplineGetOffsetNext(Spline *spline,SplineDef *def,long fracOffset)

{
  short sVar1;
  ulong uVar2;
  undefined1 in_a3;
  
  if ((spline == (Spline *)0x0) || (def == (SplineDef *)0x0)) {
    return 0;
  }
  sVar1 = def->currkey;
  if ((int)spline->numkeys <= (int)sVar1) {
                    /* WARNING: Subroutine does not return */
    printf("def->currkey=%d spline->numkeys=%d\n");
  }
  if (spline->type == '\x01') {
    uVar2 = (int)sVar1 * 10;
    FX_AniTexSetup((char)spline,(char)sVar1,(char)spline->numkeys,in_a3);
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  SplineSetDefDenom(spline,def,0);
}



// decompiled code
// original method signature: 
// unsigned long /*$ra*/ SplineGetOffsetPrev(struct Spline *spline /*$s1*/, struct SplineDef *def /*$s0*/, long fracOffset /*$s3*/)
 // line 1284, offset 0x8004271c
	/* begin block 1 */
		// Start line: 1285
		// Start offset: 0x8004271C
		// Variables:
	// 		unsigned long movedSplineOk; // $s2
	// 		unsigned long isRot; // $a1
	// 		int count; // $v1
	/* end block 1 */
	// End offset: 0x80042870
	// End Line: 1350

	/* begin block 2 */
		// Start line: 2280
	/* end block 2 */
	// End Line: 2281

ulong SplineGetOffsetPrev(Spline *spline,SplineDef *def,long fracOffset)

{
  if ((spline != (Spline *)0x0) && (def != (SplineDef *)0x0)) {
                    /* WARNING: Subroutine does not return */
    SplineSetDefDenom(spline,def,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetOffsetNextPoint(struct Spline *spline /*$s0*/, struct SplineDef *def /*$s1*/, long offset /*$a2*/)
 // line 1354, offset 0x80042890
	/* begin block 1 */
		// Start line: 1355
		// Start offset: 0x80042890
		// Variables:
	// 		static struct _SVector point; // offset 0x28
	/* end block 1 */
	// End offset: 0x800428DC
	// End Line: 1366

	/* begin block 2 */
		// Start line: 2425
	/* end block 2 */
	// End Line: 2426

_SVector * SplineGetOffsetNextPoint(Spline *spline,SplineDef *def,long offset)

{
  ulong uVar1;
  
  uVar1 = SplineGetOffsetNext(spline,def,offset);
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,def,&point_77);
  }
  return (_SVector *)0x0;
}



// decompiled code
// original method signature: 
// struct _SVector * /*$ra*/ SplineGetOffsetPreviousPoint(struct Spline *spline /*$s0*/, struct SplineDef *def /*$s1*/, long offset /*$a2*/)
 // line 1368, offset 0x800428f0
	/* begin block 1 */
		// Start line: 1369
		// Start offset: 0x800428F0
		// Variables:
	// 		static struct _SVector point; // offset 0x30
	/* end block 1 */
	// End offset: 0x8004293C
	// End Line: 1380

	/* begin block 2 */
		// Start line: 2455
	/* end block 2 */
	// End Line: 2456

_SVector * SplineGetOffsetPreviousPoint(Spline *spline,SplineDef *def,long offset)

{
  ulong uVar1;
  
  uVar1 = SplineGetOffsetPrev(spline,def,offset);
  if (uVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SplineGetData(spline,def,&point_80);
  }
  return (_SVector *)0x0;
}





