#include "THISDUST.H"
#include "SENSES.H"

int SetEngagedInstance(__Player *player, evCollideInstanceStatsData *Ptr, u_long Attribute)

{
  u_int uVar1;
  __EngagedInstance *p_Var2;
  u_int uVar3;
  int iVar4;

  uVar3 = (player->Senses).EngagedMask;
  uVar1 = 1 << (Attribute & 0x1f);
  iVar4 = 0;
  if ((uVar3 & uVar1) == 0)
  {
    iVar4 = 1;
    (player->Senses).EngagedMask = uVar3 | uVar1;
    (player->Senses).EngagedList[Attribute].instance = Ptr->instance;
    (player->Senses).EngagedList[Attribute].distance = Ptr->distance;
  }
  else
  {
    p_Var2 = (player->Senses).EngagedList + Attribute;
    if (Ptr->distance < p_Var2->distance)
    {
      iVar4 = 1;
      p_Var2->instance = Ptr->instance;
      (player->Senses).EngagedList[Attribute].distance = Ptr->distance;
    }
  }
  return iVar4;
}

void UpdateEngagementList(evCollideInstanceStatsData *Ptr, __Player *player)

{
  short sVar1;
  u_long uVar2;
  u_long Attribute;
  short *Data;
  u_long uVar3;
  MATRIX *pMVar4;
  _Instance *Inst;
  u_int uVar5;
  int Data_00;
  u_int in_t1;
  u_char in_t2;
  u_char in_t3;
  u_int uVar6;
  u_int Data_01;
  int iVar7;
  int local_40;
  u_char local_3c;
  u_char local_38;
  short local_34;
  int local_30;
  int local_2c;
  u_char local_28;

  uVar2 = INSTANCE_Post(Ptr->instance, 1);
  Inst = Ptr->instance;
  Data_01 = Inst->flags & 0x800;
  if ((uVar2 & 0x20) == 0)
  {
    if (((uVar2 & 0x10000a) == 0) || ((Inst->flags2 & 0x20000000U) != 0))
    {
      if (((uVar2 & 0x20000) != 0) && (Raziel.soulReaver == (_Instance *)0x0))
      {
        if (((Ptr->instance->LinkParent != (player->State).CharacterInstance) &&
             (Ptr->xyDistance < 0x200)) &&
            (Ptr->zDelta + 99U < 0x2e3))
        {
          SetEngagedInstance(player, Ptr, 0xb);
        }
        if ((Raziel.Abilities & 8U) != 0)
        {
          razReaverImbue((player->State).CharacterInstance, Ptr->instance);
        }
      }
      goto LAB_800a32a0;
    }
    Attribute = INSTANCE_Post(Inst, 0);
    if ((Attribute & 0x44000000) != 0)
      goto LAB_800a32a0;
    Inst = Ptr->instance;
    if ((((Inst->flags2 & 0x20U) != 0) && (Ptr->xyDistance < 0x780)) &&
        (Ptr->zDelta + 0x1ffU < 0x3ff))
    {
      if ((ControlFlag & 4U) == 0)
      {
        if ((Inst != Raziel.Senses.LastAutoFace) ||
            (Raziel.Senses.CurrentAutoFace == (_Instance *)0x0))
          goto LAB_800a30a0;
      }
      else
      {
        if (Raziel.Senses.CurrentAutoFace == (_Instance *)0x0)
        {
        LAB_800a30a0:
          Data_00 = SetEngagedInstance(player, Ptr, 6);
          if (Data_00 != 0)
          {
          LAB_800a30b4:
            AutoFaceAngle = UpdateAutoFaceAngle((player->State).CharacterInstance, Ptr->instance);
          }
        }
        else
        {
          if (Inst == Raziel.Senses.CurrentAutoFace)
          {
            Data_00 = SetEngagedInstance(player, Ptr, 6);
            if (Data_00 != 0)
              goto LAB_800a30b4;
            Raziel.Senses.CurrentAutoFace = (_Instance *)0x0;
          }
        }
      }
    }
    if ((0x3c0 < Ptr->distance) &&
        (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x2aa, 0x2aa), Data_00 != 0))
    {
      SetEngagedInstance(player, Ptr, 7);
    }
    if (((Ptr->xyDistance < 0x280) && (Ptr->zDelta + 0xffU < 0x1ff)) &&
        (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x555, 0x38e), Data_00 != 0))
    {
      SetEngagedInstance(player, Ptr, 8);
    }
    if (((Ptr->xyDistance < 0x3c0) && (Ptr->zDelta + 0xffU < 0x1ff)) &&
        (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x555, 0x38e), Data_00 != 0))
    {
      SetEngagedInstance(player, Ptr, 9);
    }
    if ((Ptr->distance < 0xc80) &&
        (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x3c7, 0x3c7), Data_00 != 0))
    {
      SetEngagedInstance(player, Ptr, 10);
    }
    if ((Ptr->distance < 0x1e00) && (Attribute = INSTANCE_Post(Ptr->instance, 0x25), Attribute != 0))
    {
      Raziel.Senses.Flags = Raziel.Senses.Flags | 0x20;
    }
    goto LAB_800a32a0;
  }
  Attribute = INSTANCE_Post(Inst, 2);
  if (((Attribute & 0x100) != 0) && ((Ptr->instance->flags & 0x800U) == 0))
  {
    Data = (short *)INSTANCE_Post(Ptr->instance, 0x16);
    if ((Ptr->xyDistance < (int)(u_int)(u_short)Data[1]) && (Data_00 = Ptr->zDelta, Data_00 < 0))
    {
      if ((int)-(u_int)(u_short)Data[3] < Data_00)
      {
        in_t2 = 0x1000;
 (int)(u_int)(u_short)Data[1]) * (int)*Data;
 if (iVar7 < 0)
 {
   iVar7 = iVar7 + 0xfff;
 }
 in_t1 = (u_int)(u_short)Data[2];
 iVar7 = (iVar7 >> 0xc) * in_t1;
 if (iVar7 < 0)
 {
   iVar7 = iVar7 + 0xfff;
 }
 (int)(u_int)(u_short)Data[3]) * (int)*Data;
 if (Data_00 < 0)
 {
   Data_00 = Data_00 + 0xfff;
 }
 Data_00 = (Data_00 >> 0xc) * (0x1000 - in_t1);
 if (Data_00 < 0)
 {
   Data_00 = Data_00 + 0xfff;
 }
 *Data = (short)(iVar7 >> 0xc) + (short)(Data_00 >> 0xc);
 INSTANCE_Query((player->State).CharacterInstance, 0x4000007, (int)Data);
      }
    }
  }
  if ((Attribute & 1) != 0)
  {
    if (player->Mode == 0x40000)
    {
      2;
      2;
    }
    Inst = Ptr->instance->LinkParent;
    if ((((Inst == (_Instance *)0x0) || (uVar3 = INSTANCE_Post(Inst, 0), (uVar3 & 0x40000000) != 0)) && (Ptr->xyDistance < 0x200)) && (Ptr->zDelta + 0xffU < 0x37f))
    {
      SetEngagedInstance(player, Ptr, 5);
    }
  }
  if ((((Attribute & 0xe) != 0) && (Data_01 == 0)) &&
      (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x3c7, 0x3c7), Data_00 != 0))
  {
    PHYSICS_GenericLineCheckMask(0, 0, 0, (SVECTOR *)&local_40);
    PHYSICS_GenericLineCheckMask(0, -0x140, 0, (SVECTOR *)&local_38);
    Data_00 = PHYSICS_CheckForTerrainCollide(gameTrackerX.playerInstance, (SVECTOR *)&local_40, (SVECTOR *)&local_38, 1);
    if (Data_00 == 0)
    {
      if ((Ptr->xyDistance < 0x280) && (Ptr->zDelta + 0xfU < 0x1f))
      {
        if ((Attribute & 4) != 0)
        {
          SetEngagedInstance(player, Ptr, 1);
        }
        if ((Attribute & 2) != 0)
        {
          SetEngagedInstance(player, Ptr, 2);
        }
      }
      if (((Ptr->xyDistance < 0x20d) && (Ptr->zDelta + 0xffU < 0x1ff)) && ((Attribute & 8) != 0))
      {
        SetEngagedInstance(player, Ptr, 0);
      }
    }
  }
  if ((((Attribute & 0x40) != 0) &&
       (uVar3 = INSTANCE_Post(Ptr->instance, 0x17),
        Ptr->xyDistance < (int)(u_int) * (u_short *)(uVar3 + 0x1a))) &&
      (((int)*(char *)(uVar3 + 0x1c) < Ptr->zDelta && (Ptr->zDelta < (int)*(char *)(uVar3 + 0x1d)))))
  {
    Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,
                                0x168,
                                0x168);
    if (Data_00 != 0)
    {
      SetEngagedInstance(player, Ptr, 3);
    }
    INSTANCE_Post(Ptr->instance, 5);
  }
  if ((Attribute & 0x80) != 0)
  {
    Attribute = INSTANCE_Post(Ptr->instance, 0x15);
    uVar6 = 0;
    if (((*(u_short *)(Attribute + 8) & 1) == 0) && ((*(u_short *)(Attribute + 10) & 1) == 0))
    {
      Inst = razGetHeldItem();
      if (Inst == (_Instance *)0x0)
      {
        uVar6 = 0x800;
        if (Raziel.soulReaver != (_Instance *)0x0)
        {
          uVar6 = (u_int)Raziel.Abilities >> 9 & 0x1fe & (u_int) * (u_short *)(Attribute + 8) | 0x800;
        }
        if (Raziel.currentSoulReaver == 6)
        {
          uVar6 = uVar6 | 0x200;
        }
      }
      else
      {
        uVar3 = INSTANCE_Post(Inst, 2);
        if ((uVar3 & 0x20) != 0)
        {
          uVar3 = INSTANCE_Post(Inst, 3);
          uVar6 = 0x400;
          if ((uVar3 & 0x10000) != 0)
          {
            uVar6 = 0x200;
          }
        }
      }
    }
    else
    {
      uVar6 = 0xffff;
    }
    if (((((uVar6 & *(u_short *)(Attribute + 8)) != 0) ||
          ((uVar6 & *(u_short *)(Attribute + 10)) != 0)) &&
         (*(short *)(Attribute + 0x1c) != 2)) &&
        (((Ptr->xyDistance < (int)(u_int) * (u_short *)(Attribute + 0x1e) &&
           ((int)*(short *)(Attribute + 0x20) < Ptr->zDelta)) &&
          ((Ptr->zDelta < (int)*(short *)(Attribute + 0x22) &&
            (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition,
                                         0x168,
                                         0x168),
             Data_00 != 0))))))
    {
      if ((uVar6 & *(u_short *)(Attribute + 8)) == 0)
      {
        Attribute = 0xd;
      }
      else
      {
        Attribute = 4;
      }
      SetEngagedInstance(player, Ptr, Attribute);
    }
  }
  Attribute = INSTANCE_Post(Ptr->instance, 0x1d);
  if ((Attribute != 0) && (Data_01 == 0))
  {
    uVar3 = INSTANCE_Post(Ptr->instance, 0xe);
    if (uVar3 != 0)
    {
      local_38 = CONCAT22(*(undefined2 *)(uVar3 + 0x18), *(undefined2 *)(uVar3 + 0x14));
      local_34 = *(short *)(uVar3 + 0x1c);
    }
    local_40 = CONCAT22(*(undefined2 *)((gameTrackerX.playerInstance)->matrix[0x12].t + 1),
                        *(undefined2 *)(gameTrackerX.playerInstance)->matrix[0x12].t);
    local_3c._0_2_ = *(short *)((gameTrackerX.playerInstance)->matrix[0x12].t + 2);
    Data_01 = MATH3D_DistanceBetweenPositions((_Position *)&local_40, (_Position *)&local_38);
    local_40 = CONCAT22(*(undefined2 *)((gameTrackerX.playerInstance)->matrix[1].t + 1),
                        *(undefined2 *)(gameTrackerX.playerInstance)->matrix[1].t);
    local_3c = CONCAT22(local_3c._2_2_,
                        *(undefined2 *)((gameTrackerX.playerInstance)->matrix[1].t + 2));
    uVar6 = MATH3D_DistanceBetweenPositions((_Position *)&local_40, (_Position *)&local_38);
    uVar5 = *(u_int *)(Attribute + 0xc);
    if (((Ptr->distance < uVar5) || (Data_01 < uVar5)) || (uVar6 < uVar5))
    {
      switch ((int)(((u_int) * (u_short *)(Attribute + 8) - 1) * 0x10000) >> 0x10)
      {
      case 0:
        Raziel.HealthBalls = Raziel.HealthBalls + 1;
        in_t3 = (u_char)((u_longlong)((longlong)(int)Raziel.HealthBalls * 0x66666667) >> 0x20);
 5) * 0x10000 >> 0x10) + 1)
 {
   BumpUpHealth();
 }
 Inst = Ptr->instance;
 Data_01 = SEXT24(Raziel.HealthBalls);
      LAB_800a2e9c:
        INSTANCE_Query(Inst, 0x800026, Data_01);
        break;
      case 1:
        if (Raziel.GlyphManaBalls < Raziel.GlyphManaMax)
        {
          Raziel.GlyphManaBalls = Raziel.GlyphManaBalls + *(short *)(Attribute + 10);
          if (Raziel.GlyphManaMax < Raziel.GlyphManaBalls)
          {
            Raziel.GlyphManaBalls = Raziel.GlyphManaMax;
          }
          Inst = Ptr->instance;
          Data_01 = (u_int)Raziel.GlyphManaBalls;
          goto LAB_800a2e9c;
        }
        break;
      case 2:
        INSTANCE_Query(Ptr->instance, 0x800026, 0);
        debugRazielFlags1 = Raziel.Abilities | (int)*(short *)(Attribute + 10) << 0x11;
        Raziel.Abilities = debugRazielFlags1;
        break;
      case 4:
        Raziel.GlyphManaBalls = Raziel.GlyphManaMax + *(short *)(Attribute + 10);
        Raziel.GlyphManaMax = Raziel.GlyphManaBalls;
        INSTANCE_Query(Ptr->instance, 0x800026, 0);
        break;
      case 5:
        INSTANCE_Query(Ptr->instance, 0x800026, (u_int)Raziel.GlyphManaBalls);
        RAZIEL_DebugManaSetMax();
        break;
      case 6:
        INSTANCE_Query(Ptr->instance, 0x800026, (u_int)Raziel.GlyphManaBalls);
        SetMana(1);
      }
    }
  }
  if ((((Ptr->instance->object->oflags2 & 0x400000U) != 0) && (Ptr->distance < 0xc80)) &&
      (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x3c7, 0x3c7), Data_00 != 0))
  {
    SetEngagedInstance(player, Ptr, 10);
  }
LAB_800a32a0:
  Attribute = INSTANCE_Post(Ptr->instance, 0);
  if ((((Attribute & 0x8000000) != 0) && (Ptr->xyDistance < 0x200)) &&
      ((Ptr->zDelta + 99U < 0x2e3 &&
        (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x2aa, 0x2aa), Data_00 != 0))))
  {
    SetEngagedInstance(player, Ptr, 0xc);
  }
  if (((uVar2 & 4) != 0) &&
      (Raziel.playerEvent = Raziel.playerEvent | 0x1000, (ControlFlag & 0x40U) != 0))
  {
    Inst = (player->State).CharacterInstance;
    pMVar4 = Inst->matrix;
    Data_00 = SetMonsterHitData(Inst, pMVar4[0xf].t[0], pMVar4[0xf].t[1], pMVar4[0xf].t[2]);
    INSTANCE_Query(Ptr->instance, 0x1000009, Data_00);
  }
  if ((Ptr->instance->object->oflags2 & 0x4000000U) != 0)
  {
    if ((Raziel.constrictFlag & 0x20U) != 0)
    {
      local_40 = (int)(Ptr->instance->position).x - (int)Raziel.constrictCenter.x;
      local_38 = 0;
      local_3c = (int)(Ptr->instance->position).y - (int)Raziel.constrictCenter.y;
      setCopReg(2, in_t1, local_40);
      setCopReg(2, in_t2, local_3c);
      setCopReg(2, in_t3, 0);
      copFunction(2, 0xa00428);
      local_30 = getCopReg(2, 0x19);
      local_2c = getCopReg(2, 0x1a);
      local_28 = getCopReg(2, 0x1b);
      if (local_30 + local_2c < 0x64000)
      {
        Data_00 = razConstrictAngle(Ptr->instance);
        if (((Raziel.constrictFlag & 0x10U) == 0) || (Data_00 == 0))
        {
          Ptr->instance->constrictAngle = 0;
          FX_EndConstrict(0, (_Instance *)0x0);
        }
        else
        {
          if (Data_00 < 1)
          {
            Inst = Ptr->instance;
            if (0 < Inst->constrictAngle)
            {
              Inst->constrictAngle = 0;
              Inst = Ptr->instance;
            }
            sVar1 = Inst->constrictAngle + -1;
          }
          else
          {
            Inst = Ptr->instance;
            if (Inst->constrictAngle < 0)
            {
              Inst->constrictAngle = 0;
              Inst = Ptr->instance;
            }
            sVar1 = Inst->constrictAngle + 1;
          }
          Inst->constrictAngle = sVar1;
          Inst = Ptr->instance;
          if ((Inst->constrictAngle == 1) || (Inst->constrictAngle == -1))
          {
            FX_StartConstrict(Raziel.State.CharacterInstance, &Raziel.constrictCenter, 1, 0x12);
            INSTANCE_Query(Ptr->instance, 0x40009, 0);
          }
          else
          {
            if (2 < (u_short)(Inst->constrictAngle + 1U))
            {
              FX_EndConstrict(1, Inst);
              Raziel.constrictFlag = 1;
              Data_00 = SetMonsterImpaleData((player->State).CharacterInstance, Ptr->instance, 0x3000, 0, 0);
              INSTANCE_Query(Ptr->instance, 0x1000000, Data_00);
              razSetupSoundRamp(gameTrackerX.playerInstance, (_SoundRamp *)&Raziel.soundHandle, 0x30,
                                100, 100, 100, 100, 0, 0xdac);
            }
          }
        }
      }
    }
    if (Raziel.constrictGoodCircle == 0)
    {
      Ptr->instance->constrictAngle = 0;
    }
  }
  if (((((Ptr->instance->object->oflags2 & 0x1000000U) != 0) &&
        (gameTrackerX.gameData.asmData.MorphType != 0)) &&
       (Raziel.CurrentPlane == 2)) &&
      ((Ptr->xyDistance < 0x1c2 && (Ptr->zDelta + 0x3fU < 0x7f))))
  {
    Raziel.Senses.Flags = Raziel.Senses.Flags | 0x40;
  }
  if ((((Ptr->instance->object->oflags & 0x100000U) != 0) && (0x3c0 < Ptr->distance)) &&
      (Data_00 = MATH3D_ConeDetect(&Ptr->relativePosition, 0x2aa, 0x2aa), Data_00 != 0))
  {
    SetEngagedInstance(player, Ptr, 7);
  }
  if (((Ptr->instance->object->oflags2 & 0x20U) != 0) && (Ptr->distance < 0x100))
  {
    SetEngagedInstance(player, Ptr, 0xe);
  }
  return;
}

long UpdateAutoFaceAngle(_Instance *player, _Instance *instance)

{
  short sVar1;

  sVar1 = MATH3D_FastAtan2((int)(player->position).y - (int)(instance->position).y,
                           (int)(player->position).x - (int)(instance->position).x);
  return (int)sVar1 + 0xc00U & 0xfff;
}
