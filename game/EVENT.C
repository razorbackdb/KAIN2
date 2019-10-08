#include "THISDUST.H"
#include "EVENT.H"

void EVENT_UpdateResetSignalArrayAndWaterMovement(Level *oldLevel, Level *newLevel, long sizeOfLevel)

{
  _MultiSignal *p_Var1;
  _MultiSignal *p_Var2;
  SignalResetStruct *pSVar3;
  int iVar4;

  if (NumSignalsToReset != 0)
  {
    iVar4 = 0;
    pSVar3 = &ResetSignalArray;
    do
    {
      if (0 < pSVar3->timeLeft)
      {
        p_Var2 = pSVar3->mSignal;
        if ((oldLevel <= p_Var2) &&
            (p_Var2 <= (_MultiSignal *)((int)&oldLevel->terrain + sizeOfLevel)))
        {
          p_Var1 = (_MultiSignal *)0x0;
          if (p_Var2 != (_MultiSignal *)0x0)
          {
            p_Var1 = (_MultiSignal *)((int)p_Var2 + (int)((int)newLevel - (int)oldLevel));
          }
          pSVar3->mSignal = p_Var1;
        }
      }
      iVar4 = iVar4 + 1;
      pSVar3 = pSVar3 + 1;
    } while (iVar4 < 0x10);
  }
  return;
}

void EVENT_ResetAllOneTimeVariables(void)

{
  int iVar1;
  SignalResetStruct *pSVar2;
  int iVar3;

  iVar3 = 0;
  if (NumSignalsToReset != 0)
  {
    pSVar2 = &ResetSignalArray;
    do
    {
      iVar1 = pSVar2->timeLeft + -1;
      if ((0 < pSVar2->timeLeft) && (pSVar2->timeLeft = iVar1, iVar1 == 0))
      {
        NumSignalsToReset = NumSignalsToReset + -1;
        pSVar2->mSignal->flags = pSVar2->mSignal->flags & 0xfffe;
        pSVar2->timeLeft = 0;
      }
      iVar3 = iVar3 + 1;
      pSVar2 = pSVar2 + 1;
    } while (iVar3 < 0x10);
  }
  return;
}

void EVENT_AddSignalToReset(_MultiSignal *mSignal)

{
  SignalResetStruct *pSVar1;
  int iVar2;

  iVar2 = 0;
  if (NumSignalsToReset < 0x10)
  {
    pSVar1 = &ResetSignalArray;
    while (iVar2 = iVar2 + 1, pSVar1->timeLeft != 0)
    {
      pSVar1 = pSVar1 + 1;
      if (0xf < iVar2)
      {
        return;
      }
    }
    *(undefined **)&pSVar1->timeLeft = &UNK_00000001;
    pSVar1->mSignal = mSignal;
    NumSignalsToReset = NumSignalsToReset + 1;
  }
  return;
}

void HINT_ResetHint(void)

{
  memset(&gHintSystem, 0, 0x10);
  return;
}

void HINT_StartHint(short hintNumber)

{
  gHintSystem.stringNumber = hintNumber + 0x37;
  if (0x35 < (u_short)hintNumber)
  {
    gHintSystem.stringNumber = 0x6c;
  }
  gHintSystem.flags = 3;
  gHintSystem.hintNumber = hintNumber;
  gHintSystem.fadeTimer = 0x1e000;
  gHintSystem.spawningUnitID = (gameTrackerX.playerInstance)->currentStreamUnitID;
  return;
}

void HINT_StopHint(void)

{
  u_int uVar1;

  uVar1 = gHintSystem._0_4_;
  if ((gHintSystem._0_4_ & 1) == 0)
  {
    return;
  }
  if ((gHintSystem._0_4_ & 6) == 0)
  {
    gHintSystem._0_4_ = gHintSystem._0_4_ | 4;
    if ((uVar1 & 2) == 0)
    {
      gHintSystem.fadeTimer = 0x1e000;
      return;
    }
    gHintSystem._0_4_ = uVar1 & 0xfffffffd | 4;
    gHintSystem.fadeTimer = 0x1e000 - gHintSystem.fadeTimer;
  }
  return;
}

void HINT_KillSpecificHint(short hintNumber)

{
  if (gHintSystem.hintNumber == hintNumber)
  {
    HINT_StopHint();
  }
  return;
}

long HINT_GetCurrentHint(void)

{
  long lVar1;

  lVar1 = -1;
  if ((gHintSystem.flags & 1U) != 0)
  {
    lVar1 = (long)gHintSystem.hintNumber;
  }
  return lVar1;
}

void EVENT_ProcessTimers(void)

{
  long lVar1;
  u_int uVar2;
  int iVar3;
  EventTimer *timer;
  int iVar4;
  int iVar5;

  if (numActiveEventTimers != 0)
  {
    iVar5 = 0;
    iVar4 = 0;
    do
    {
      timer = (EventTimer *)((int)&eventTimerArray.flags + iVar4);
      uVar2 = timer->flags;
      if ((uVar2 & 1) != 0)
      {
        if ((u_int)((int)uVar2 >> 1) < gameTrackerX.timeMult)
        {
          timer->flags = uVar2 & 1;
        }
        else
        {
          timer->flags = uVar2 & 1 | (((int)uVar2 >> 1) - gameTrackerX.timeMult) * 2;
        }
        if (timer->flags >> 1 < 1)
        {
          iVar3 = *(int *)((int)&eventTimerArray.event + iVar4);
          currentEventInstance = *(Event **)((int)&eventTimerArray.time + iVar4);
          timer->flags = timer->flags & 1;
          *(u_short *)(iVar3 + 2) = *(u_short *)(iVar3 + 2) & 0xfffe;
          EVENT_RemoveTimer(timer);
          CurrentPuzzleLevel = *(Level **)((int)&eventTimerArray.scriptPos + iVar4);
          EventCurrentEventIndex = *(long *)((int)&eventTimerArray.level + iVar4);
          EventAbortLine = 0;
          lVar1 = EVENT_DoInstanceAction(*(Event **)((int)&eventTimerArray.time + iVar4),
                                         *(ScriptPCode **)((int)&eventTimerArray.event + iVar4),
                                         *(short **)((int)&eventTimerArray.actionScript + iVar4));
          if ((lVar1 != 0) && (EventCurrentEventIndex != -1))
          {
            EVENT_ProcessPuppetShow(*(Event **)((int)&eventTimerArray.time + iVar4), EventCurrentEventIndex);
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x18;
    } while (iVar5 < 0x18);
  }
  return;
}

void EVENT_Process(void)

{
  bool bVar1;
  int len;
  long y;
  char acStack136[128];

  if ((gHintSystem.flags & 1U) != 0)
  {
    localstr_get((int)gHintSystem.stringNumber);
    sprintf(acStack136, (char *)&PTR_LAB_000a7324_1_800d0794);
    if ((gHintSystem.flags & 2U) == 0)
    {
      y = 200;
      if ((gHintSystem.flags & 4U) != 0)
      {
        0x1e000;
      }
    }
    else
    {
      0x1e000 + 200;
    }
    FONT_FontPrintCentered(acStack136, y);
    FONT_FontPrintCentered("$\n", y);
    len = FONT_GetStringWidth(acStack136);
    DisplayHintBox(len, y);
    if ((gHintSystem.fadeTimer != 0) &&
        (bVar1 = (u_int)gHintSystem.fadeTimer <= gameTrackerX.timeMult,
         gHintSystem.fadeTimer = gHintSystem.fadeTimer - gameTrackerX.timeMult, bVar1))
    {
      gHintSystem.fadeTimer = 0;
      if ((gHintSystem.flags & 2U) == 0)
      {
        if ((gHintSystem.flags & 4U) != 0)
        {
          gHintSystem.flags = 0;
          gHintSystem.hintNumber = -1;
          gHintSystem.stringNumber = -1;
        }
      }
      else
      {
        gHintSystem.flags = gHintSystem.flags & 0xfffd;
      }
    }
    if (gHintSystem.spawningUnitID != (gameTrackerX.playerInstance)->currentStreamUnitID)
    {
      HINT_StopHint();
    }
    if ((gameTrackerX.gameFlags & 0x10U) != 0)
    {
      HINT_StopHint();
    }
  }
  return;
}

EventTimer *EVENT_GetNextTerrainMove(void)

{
  EventTimer *pEVar1;
  int iVar2;

  if (numActiveEventTimers < 0x18)
  {
    pEVar1 = &eventTimerArray;
    iVar2 = 0x18;
    do
    {
      iVar2 = iVar2 + -1;
      if ((pEVar1->flags & 1U) == 0)
      {
        numActiveEventTimers = numActiveEventTimers + 1;
        pEVar1->flags = pEVar1->flags & 0xfffffffeU | 1;
        return pEVar1;
      }
      pEVar1 = (EventTimer *)&pEVar1->nextEventIndex;
    } while (0 < iVar2);
  }
  return (EventTimer *)0x0;
}

void EVENT_RemoveTimer(EventTimer *timer)

{
  if (timer != (EventTimer *)0x0)
  {
    numActiveEventTimers = numActiveEventTimers + -1;
    timer->flags = timer->flags & 0xfffffffe;
  }
  return;
}

void FONT_Init(void)

{
  numActiveEventTimers = 0;
  memset(&eventTimerArray, 0, 0x240);
  return;
}

void EVENT_InitTerrainMovement(void)

{
  WaterLevelProcess *__s;
  int iVar1;

  iVar1 = 0;
  __s = &WaterLevelArray;
  do
  {
    memset(__s, 0x1c, 0);
    iVar1 = iVar1 + 1;
    __s = __s + 1;
  } while (iVar1 < 5);
  WaterInUse = 0;
  return;
}

void EVENT_InitTimers(void)

{
  EVENT_InitTerrainMovement();
  FONT_Init();
  HINT_ResetHint();
  WaitingForVoiceNumber = -1;
  WaitingToLoadSound = 0x96000;
  return;
}

WaterLevelProcess *EVENT_GetNextTimer(void)

{
  WaterLevelProcess *pWVar1;
  int iVar2;

  iVar2 = 0;
  pWVar1 = &WaterLevelArray;
  do
  {
    iVar2 = iVar2 + 1;
    if ((pWVar1->flags & 1U) == 0)
    {
      return pWVar1;
    }
    pWVar1 = pWVar1 + 1;
  } while (iVar2 < 5);
  return (WaterLevelProcess *)0x0;
}

void EVENT_BSPProcess(void)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  WaterLevelProcess *pWVar5;
  int iVar6;

  bVar2 = false;
  if (WaterInUse != 0)
  {
    pWVar5 = &WaterLevelArray;
    iVar6 = 5;
    plVar4 = &WaterLevelArray.maxSteps;
    do
    {
      if ((pWVar5->flags & 1U) != 0)
      {
        iVar3 = plVar4[1] + gameTrackerX.timeMult;
        plVar4[1] = iVar3;
        bVar2 = true;
        if (*plVar4 < iVar3)
        {
          plVar4[1] = *plVar4;
        }
        iVar3 = (((int)*(short *)((int)plVar4 + -2) - (int)*(short *)(plVar4 + -1)) *
 (*plVar4 >> 0xc);
        sVar1 = (short)iVar3;
        *(short *)(plVar4[-4] + 0x10) = *(short *)((int)plVar4 + -6) + sVar1;
        *(short *)(plVar4[-4] + 0x18) = *(short *)(plVar4 + -1) + sVar1;
        if ((pWVar5->flags & 2U) != 0) {
          *(int *)(*(int *)(plVar4[-3] + 8) + 0x38) = *(short *)(plVar4 + -2) + iVar3;
          ***(u_short ***)(plVar4[-3] + 8) = ***(u_short ***)(plVar4[-3] + 8) | 1;
        }
        if (plVar4[1] == *plVar4) {
          pWVar5->flags = 0;
        }
      }
      iVar6 = iVar6 + -1;
      plVar4 = plVar4 + 7;
      pWVar5 = pWVar5 + 1;
    } while (0 < iVar6);
  }
  if (!bVar2)
  {
    WaterInUse = 0;
  }
  return;
}

void EVENT_ProcessEvents(void)

{
  EVENT_BSPProcess();
  EVENT_ProcessTimers();
  return;
}

void EVENT_DoProcess(_StreamUnit *streamUnit)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _Instance *instance;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  int iVar9;
  _Terrain *p_Var10;
  int iVar11;
  SVECTOR local_30;

  p_Var10 = streamUnit->level->terrain;
  iVar9 = 0;
  if (0 < p_Var10->numBSPTrees)
  {
    iVar11 = 0;
    do
    {
      iVar4 = (int)&p_Var10->BSPTreeArray->bspRoot + iVar11;
      if ((-1 < *(short *)(iVar4 + 0x1a)) && (iVar5 = *(int *)(iVar4 + 0x20), iVar5 != 0))
      {
        iVar2 = *(int *)(iVar5 + 0x40);
        if ((iVar2 == 0) || (iVar3 = *(int *)(iVar5 + 0x44), iVar3 == 0))
        {
          sVar6 = *(short *)(iVar5 + 0x60);
          sVar8 = *(short *)(iVar5 + 0x5c) - *(short *)(iVar5 + 100);
          sVar1 = *(short *)(iVar5 + 0x68);
          sVar7 = *(short *)(iVar5 + 0x5e) - *(short *)(iVar5 + 0x66);
        }
        else
        {
          sVar6 = *(short *)(iVar2 + 0x1c);
          sVar8 = *(short *)(iVar2 + 0x14) - *(short *)(iVar3 + 0x14);
          sVar1 = *(short *)(iVar3 + 0x1c);
          sVar7 = *(short *)(iVar2 + 0x18) - *(short *)(iVar3 + 0x18);
        }
        sVar6 = sVar6 - sVar1;
        if (((sVar8 != 0) || (sVar7 != 0)) || (sVar6 != 0))
        {
          *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + sVar8;
          *(short *)(iVar4 + 0xe) = *(short *)(iVar4 + 0xe) + sVar7;
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + sVar6;
          *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) + sVar8;
          *(short *)(iVar4 + 0x16) = *(short *)(iVar4 + 0x16) + sVar7;
          *(short *)(iVar4 + 0x18) = *(short *)(iVar4 + 0x18) + sVar6;
          p_Var10->UnitChangeFlags = p_Var10->UnitChangeFlags | 2;
          instance = (gameTrackerX.instanceList)->first;
          local_30.vx = sVar8;
          local_30.vy = sVar7;
          local_30.vz = sVar6;
          while (instance != (_Instance *)0x0)
          {
            if (((*(int *)(iVar5 + 0x8c) == 0) &&
                 (instance->currentStreamUnitID == streamUnit->StreamUnitID)) &&
                (instance->bspTree == iVar9))
            {
              (instance->position).x = (instance->position).x + sVar8;
              (instance->position).z = (instance->position).z + sVar6;
              (instance->position).y = (instance->position).y + sVar7;
              COLLIDE_MoveAllTransforms(instance, &local_30);
            }
            instance = instance->next;
          }
        }
      }
      iVar9 = iVar9 + 1;
      iVar11 = iVar11 + 0x24;
    } while (iVar9 < p_Var10->numBSPTrees);
  }
  return;
}

void EVENT_ProcessPuppetShow(Event *eventInstance, long startIndex)

{
  long lVar1;
  ScriptPCode **ppSVar2;
  ScriptPCode *actionScript;
  int iVar3;

  iVar3 = startIndex << 2;
  currentEventInstance = eventInstance;
  if (startIndex < (int)(u_int)eventInstance->numActions)
  {
    do
    {
      EventCurrentEventIndex = startIndex + 1;
      if (EventCurrentEventIndex == (u_int)eventInstance->numActions)
      {
        EventCurrentEventIndex = -1;
      }
      if (*(int *)(iVar3 + (int)eventInstance->conditionalList) == 0)
      {
      LAB_800617e0:
        if ((*(u_short *)(*(int *)(iVar3 + (int)eventInstance->actionList) + 2) & 2) == 0)
        {
          actionScript = *(ScriptPCode **)(iVar3 + (int)eventInstance->actionList);
          EventAbortLine = 0;
          EVENT_DoInstanceAction(eventInstance, actionScript, actionScript->data);
        }
      }
      else
      {
        EventAbortLine = 0;
        CurrentEventLine = 0;
        lVar1 = EVENT_IsConditionTrue(eventInstance,
                                      *(ScriptPCode **)(iVar3 + (int)eventInstance->conditionalList));
        if (lVar1 != 0)
        {
          if (*(int *)(iVar3 + (int)eventInstance->actionList) == 0)
          {
            ppSVar2 = eventInstance->actionList + startIndex;
            do
            {
              ppSVar2 = ppSVar2 + 1;
              if ((int)(u_int)eventInstance->numActions <= startIndex)
                goto LAB_8006182c;
              iVar3 = iVar3 + 4;
              startIndex = startIndex + 1;
            } while (*ppSVar2 == (ScriptPCode *)0x0);
          }
          if (startIndex < (int)(u_int)eventInstance->numActions)
            goto LAB_800617e0;
        }
      }
    LAB_8006182c:
      startIndex = startIndex + 1;
      iVar3 = iVar3 + 4;
    } while (startIndex < (int)(u_int)eventInstance->numActions);
  }
  return;
}

void EVENT_ProcessMovingWater(Event *eventInstance, long startIndex)

{
  bool bVar1;
  long lVar2;
  ScriptPCode **ppSVar3;
  ScriptPCode *actionScript;
  char cVar4;

  cVar4 = (char)startIndex;
  EventJustRecievedTimer = 0;
  bVar1 = true;
  if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0)
  {
    EventJustRecievedTimer = 0;
    currentEventInstance = eventInstance;
    return;
  }
  EventCurrentEventIndex = startIndex + 1;
  if (EventCurrentEventIndex == (u_int)eventInstance->numActions)
  {
    EventCurrentEventIndex = -1;
  }
  currentEventInstance = eventInstance;
  if (eventInstance->conditionalList[startIndex] == (ScriptPCode *)0x0)
  {
    if ((eventInstance->actionList[startIndex]->conditionBits & 2) != 0)
      goto LAB_800619c8;
    actionScript = eventInstance->actionList[startIndex];
  }
  else
  {
    EventAbortLine = 0;
    CurrentEventLine = 0;
    lVar2 = EVENT_IsConditionTrue(eventInstance, eventInstance->conditionalList[startIndex]);
    if (lVar2 == 0)
    {
      bVar1 = false;
      goto LAB_800619c8;
    }
    ppSVar3 = eventInstance->actionList + startIndex;
    if (*ppSVar3 == (ScriptPCode *)0x0)
    {
      do
      {
        cVar4 = (char)startIndex;
        ppSVar3 = ppSVar3 + 1;
        if ((int)(u_int)eventInstance->numActions <= startIndex)
          goto LAB_800619c8;
        startIndex = startIndex + 1;
      } while (*ppSVar3 == (ScriptPCode *)0x0);
    }
    cVar4 = (char)startIndex;
    if ((int)(u_int)eventInstance->numActions <= startIndex)
      goto LAB_800619c8;
    actionScript = eventInstance->actionList[startIndex];
  }
  EventAbortLine = 0;
  EVENT_DoInstanceAction(eventInstance, actionScript, actionScript->data);
LAB_800619c8:
  if ((((EventAbortLine == 0) || (EventJustRecievedTimer == 1)) && (bVar1)) &&
      (eventInstance->processingPuppetShow = cVar4 + '\x02',
       (u_int)eventInstance->numActions + 1 <= (u_int)eventInstance->processingPuppetShow))
  {
    eventInstance->processingPuppetShow = '\0';
  }
  return;
}

void EVENT_ProcessHints(EventPointers *eventPointers, Level *level)

{
  Event *eventInstance;
  int iVar1;
  EventPointers *pEVar2;

  iVar1 = 0;
  pEVar2 = eventPointers;
  CurrentPuzzleLevel = level;
  if (0 < eventPointers->numPuzzles)
  {
    do
    {
      eventInstance = (Event *)pEVar2->eventInstances[0];
      if (eventInstance->eventNumber < 0)
      {
        if (eventInstance->processingPuppetShow != 0)
        {
          EVENT_ProcessMovingWater(eventInstance, (u_int)eventInstance->processingPuppetShow - 1);
        }
      }
      else
      {
        EVENT_ProcessPuppetShow(eventInstance, 0);
      }
      iVar1 = iVar1 + 1;
      pEVar2 = (EventPointers *)pEVar2->eventInstances;
    } while (iVar1 < eventPointers->numPuzzles);
  }
  return;
}

long EVENT_DoInstanceAction(Event *eventInstance, ScriptPCode *actionScript, short *scriptData)

{
  long lVar1;
  short *psVar2;
  Level *pLVar3;
  EventTimer *pEVar4;
  int iVar5;
  long lVar6;
  _PCodeStack local_4a8;
  int local_20[2];

  local_4a8.topOfStack = 0;
  EventJustRecievedTimer = 0;
  lVar6 = 1;
  currentActionScript = actionScript;
  EventAbortedPosition = scriptData;
  if ((((actionScript->conditionBits & 1) == 0) && (lVar6 = 1, scriptData != (short *)0x0)) &&
      (lVar6 = 1, EventAbortLine == 0))
  {
    lVar6 = 1;
    do
    {
      scriptData = EVENT_ParseOperand2(&local_4a8, scriptData, local_20);
      if (((EventAbortLine != 0) && (EventJustRecievedTimer == 0)) &&
          (pEVar4 = EVENT_GetNextTerrainMove(), psVar2 = EventAbortedPosition,
           lVar1 = EventCurrentEventIndex, pEVar4 != (EventTimer *)0x0))
      {
        lVar6 = 0;
        *(Event **)&pEVar4->time = eventInstance;
        *(ScriptPCode **)&pEVar4->event = actionScript;
        pEVar4->flags = pEVar4->flags & 1;
        *(short **)&pEVar4->actionScript = psVar2;
        pLVar3 = CurrentPuzzleLevel;
        actionScript->conditionBits = actionScript->conditionBits | 1;
        *(Level **)&pEVar4->scriptPos = pLVar3;
        *(long *)&pEVar4->level = lVar1;
      }
      if (((local_20[0] != 0) && (EventAbortLine == 0)) &&
          (iVar5 = local_4a8.topOfStack + -1, 0 < local_4a8.topOfStack))
      {
        local_4a8.topOfStack = iVar5;
        EVENT_ExecuteActionCommand(local_4a8.stack + iVar5, (StackType *)0x0, &local_4a8, scriptData);
      }
    } while ((scriptData != (short *)0x0) && (EventAbortLine == 0));
  }
  return lVar6;
}

long EVENT_IsConditionTrue(Event *eventInstance, ScriptPCode *conditionScript)

{
  int iVar1;
  long lVar2;
  short *codeStream;
  _PCodeStack local_4a8;
  int local_20;
  int local_1c;
  short asStack24[4];

  local_4a8.topOfStack = 0;
  codeStream = conditionScript->data;
  currentActionScript = (ScriptPCode *)0x0;
  lVar2 = 0;
  while (true)
  {
    do
    {
      do
      {
        if ((codeStream == (short *)0x0) || (EventAbortLine != 0))
          goto LAB_80061d0c;
        codeStream = EVENT_ParseOperand2(&local_4a8, codeStream, &local_20);
      } while ((local_20 == 0) || (EventAbortLine != 0));
      CurrentEventLine = CurrentEventLine + 1;
      iVar1 = local_4a8.topOfStack + -1;
    } while (local_4a8.topOfStack < 1);
    local_4a8.topOfStack = iVar1;
    lVar2 = EVENT_GetScalerValueFromOperand(local_4a8.stack + iVar1, &local_1c, asStack24);
    if (local_1c != 0)
      break;
    if (lVar2 == 0)
    {
    LAB_80061d0c:
      if (EventAbortLine == 1)
      {
        lVar2 = 0;
      }
      return lVar2;
    }
  }
  lVar2 = 0;
  goto LAB_80061d0c;
}

long EVENT_WriteEventObject(StackType *stackEntry, long areaID, Event *event, long number)

{
  SavedBasic *pSVar1;
  long lVar2;

  lVar2 = 0;
  if (event == (Event *)0x0)
  {
    pSVar1 = SAVE_GetSavedNextEvent(areaID, number);
    if (pSVar1 == (SavedBasic *)0x0)
    {
      stackEntry->id = 0x15;
      pSVar1 = EVENT_CreateSaveEvent(areaID, number);
      *(SavedBasic **)stackEntry->data = pSVar1;
    }
    else
    {
      stackEntry->id = 0x15;
      *(SavedBasic **)stackEntry->data = pSVar1;
    }
    lVar2 = 1;
    *(long *)(stackEntry->data + 8) = areaID;
    *(long *)(stackEntry->data + 0xc) = number;
  }
  else
  {
    stackEntry->id = 0x10;
    *(Event **)stackEntry->data = event;
  }
  *(u_char *)(stackEntry->data + 4) = 0xffffffff;
  return lVar2;
}

_MultiSignal *EVENT_ResolveObjectSignal(_StreamUnit *stream, long signalNumber)

{
  Level *level;
  _MultiSignal *p_Var1;

  level = stream->level;
  p_Var1 = (_MultiSignal *)0x0;
  if (signalNumber < 0)
  {
    switch (signalNumber)
    {
    case -5:
      p_Var1 = level->startUnitMainSignal;
      break;
    case -4:
      p_Var1 = level->startUnitLoadedSignal;
      break;
    case -3:
      p_Var1 = level->materialSignal;
      break;
    case -2:
      p_Var1 = level->spectralSignal;
      break;
    case -1:
      p_Var1 = level->startSignal;
    }
  }
  else
  {
    p_Var1 = SIGNAL_HandleSignal(level, signalNumber);
  }
  return p_Var1;
}

Intro *EVENT_ResolveSFXMarker(EventInstanceObject *instanceObject)

{
  Intro *pIVar1;

  pIVar1 = INSTANCE_FindIntro(instanceObject->unitID, instanceObject->introUniqueID);
  return pIVar1;
}

_SFXMkr *EVENT_ResolveObjectIntro(_StreamUnit *stream, EventInstanceObject *instanceObject)

{
  int iVar1;
  _SFXMkr *p_Var2;
  int iVar3;

  iVar1 = stream->level->NumberOfSFXMarkers;
  if ((iVar1 != 0) && (iVar3 = 0, 0 < iVar1))
  {
    p_Var2 = stream->level->SFXMarkerList;
    do
    {
      iVar3 = iVar3 + 1;
      if (instanceObject->introUniqueID == p_Var2->uniqueID)
      {
        return p_Var2;
      }
      p_Var2 = p_Var2 + 1;
    } while (iVar3 < iVar1);
  }
  return (_SFXMkr *)0x0;
}

void EVENT_AddGameObjectToStack(_PCodeStack *stack)

{
  int iVar1;

  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20)
  {
    stack->stack[iVar1].id = 3;
    *(u_char *)stack->stack[iVar1].data = 0xffffffff;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

void EVENT_AddObjectToStack(_PCodeStack *stack)

{
  _Instance *p_Var1;
  StackType *pSVar2;

  if (stack->topOfStack < 0x20)
  {
    pSVar2 = stack->stack + stack->topOfStack;
    pSVar2->id = 2;
    p_Var1 = gameTrackerX.playerInstance;
    *(u_char *)(pSVar2->data + 4) = 0xffffffff;
    *(_Instance **)pSVar2->data = p_Var1;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

void EVENT_AddCharPointerToStack(_PCodeStack *stack, long item)

{
  long lVar1;
  Level *pLVar2;
  u_char uVar3;
  EventBasicObject *pEVar4;
  StackType *stackEntry;
  long lVar5;

  lVar1 = CurrentEventLine;
  lVar5 = stack->topOfStack;
  if (0x1f < lVar5)
    goto LAB_800621c8;
  pEVar4 = currentEventInstance->instanceList[item];
  stackEntry = stack->stack + lVar5;
  switch ((int)(((u_int)(u_short)pEVar4->id - 1) * 0x10000) >> 0x10)
  {
  case 0:
    if ((pEVar4[1].id & 1U) == 0)
    {
      if (*(int *)(pEVar4 + 6) == 0)
      {
        if (*(int *)(pEVar4 + 8) == 0)
          goto LAB_800621b0;
        stackEntry->id = 4;
        uVar3 = *(u_char *)(pEVar4 + 8);
      }
      else
      {
        stackEntry->id = 2;
        uVar3 = *(u_char *)(pEVar4 + 6);
      }
    LAB_80062168:
      *(u_char *)(stackEntry->data + 4) = 0xffffffff;
      *(u_char *)stackEntry->data = uVar3;
    }
    else
    {
      stackEntry->id = 0x1b;
      *(undefined2 *)stackEntry->data = 1;
      uVar3 = *(u_char *)(pEVar4 + 8);
      *(undefined2 *)(stackEntry->data + 2) = 0xffff;
      *(u_char *)(stackEntry->data + 4) = 0xffffffff;
      *(u_char *)(stackEntry->data + 8) = 0xffffffff;
      *(u_char *)(stackEntry->data + 0xc) = 0xffffffff;
      *(u_char *)(stackEntry->data + 0x10) = uVar3;
    }
    break;
  case 1:
    stackEntry->id = 0x12;
    *(EventBasicObject **)stackEntry->data = pEVar4;
    *(u_char *)(stackEntry->data + 0x18) = 0;
    *(long *)(stackEntry->data + 0x1c) = lVar1;
    break;
  case 2:
    EVENT_WriteEventObject(stackEntry, *(long *)(pEVar4 + 2), *(Event **)(pEVar4 + 4), (int)pEVar4[1].id);
    lVar5 = lVar5 + 1;
    goto LAB_800621c8;
  case 3:
    if (*(int *)(pEVar4 + 4) == 0)
      goto LAB_800621b0;
    stackEntry->id = 0x17;
    *(u_char *)stackEntry->data = *(u_char *)(pEVar4 + 4);
    uVar3 = *(u_char *)(pEVar4 + 6);
    *(u_char *)(stackEntry->data + 8) = 0xffffffff;
    *(u_char *)(stackEntry->data + 4) = uVar3;
    break;
  case 4:
    stackEntry->id = 1;
    uVar3 = *(u_char *)(pEVar4 + 4);
    *(u_char *)(stackEntry->data + 4) = 0xffffffff;
    *(u_char *)stackEntry->data = uVar3;
    *(u_char *)(stackEntry->data + 8) = *(u_char *)(pEVar4 + 2);
    break;
  case 5:
    if (*(int *)(pEVar4 + 4) != 0)
    {
      stackEntry->id = 0x11;
      uVar3 = *(u_char *)(pEVar4 + 4);
      goto LAB_80062168;
    }
    goto LAB_800621b0;
  case 6:
    if (*(int *)(pEVar4 + 10) != 0)
    {
      stackEntry->id = 0x1a;
      *(u_char *)stackEntry->data = *(u_char *)(pEVar4 + 10);
      lVar5 = lVar5 + 1;
      pLVar2 = STREAM_GetWaterZLevel(*(long *)(pEVar4 + 2));
      *(Level **)(stackEntry->data + 4) = pLVar2;
      *(u_char *)(stackEntry->data + 8) = 0xffffffff;
      goto LAB_800621c8;
    }
  LAB_800621b0:
    stackEntry->id = 6;
    *(long *)stackEntry->data = item;
    *(u_char *)(stackEntry->data + 4) = 0xffffffff;
  }
  lVar5 = lVar5 + 1;
LAB_800621c8:
  stack->topOfStack = lVar5;
  return;
}

void EVENT_AddShortPointerToStack(_PCodeStack *stack, char *pointer)

{
  int iVar1;

  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20)
  {
    stack->stack[iVar1].id = 0x1c;
    *(char **)stack->stack[iVar1].data = pointer;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

void EVENT_AddShortPointerToStack(_PCodeStack *stack, short *pointer)

{
  int iVar1;

  iVar1 = stack->topOfStack;
  if (iVar1 < 0x20)
  {
    stack->stack[iVar1].id = 10;
    *(short **)stack->stack[iVar1].data = pointer;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

void EVENT_AddPlayerObjectToStack(_PCodeStack *stack, long item, long flags)

{
  StackType *pSVar1;

  if (stack->topOfStack < 0x20)
  {
    pSVar1 = stack->stack + stack->topOfStack;
    pSVar1->id = 7;
    *(long *)pSVar1->data = item;
    *(u_char *)(pSVar1->data + 4) = 0;
    *(short *)(pSVar1->data + 8) = (short)flags;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

void EVENT_ChangeOperandToNumber(StackType *operand, long item, long flags)

{
  operand->id = 7;
  *(long *)operand->data = item;
  *(u_char *)(operand->data + 4) = 0;
  *(short *)(operand->data + 8) = (short)flags;
  return;
}

void EVENT_ChangeOperandToNumber(StackType *operand, short x, short y, short z, long streamUnitID)

{
  operand->id = 9;
  *(short *)operand->data = x;
  *(short *)(operand->data + 2) = y;
  *(short *)(operand->data + 4) = z;
  *(undefined2 *)(operand->data + 8) = 0xa0;
  *(undefined2 *)(operand->data + 10) = 0xa0;
  *(undefined2 *)(operand->data + 0xc) = 0xa0;
  *(long *)(operand->data + 0x10) = streamUnitID;
  return;
}

void EVENT_Addvector3dToStack(_PCodeStack *stack, short x, short y, short z, long streamUnitID)

{
  if (stack->topOfStack < 0x20)
  {
    EVENT_ChangeOperandToNumber(stack->stack + stack->topOfStack, x, y, z, streamUnitID);
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

void EVENT_ChangeOperandVector3d(StackType *operand, Rotation3d *rotation)

{
  short sVar1;

  operand->id = 0xe;
  *(short *)operand->data = rotation->vx;
  *(short *)(operand->data + 2) = rotation->vy;
  *(short *)(operand->data + 4) = rotation->vz;
  *(short *)(operand->data + 8) = rotation->errorx;
  *(short *)(operand->data + 10) = rotation->errory;
  sVar1 = rotation->errorz;
  *(u_char *)(operand->data + 0x10) = 0xffffffff;
  *(short *)(operand->data + 0xc) = sVar1;
  return;
}

long EVENT_AddNumberToStack(_PCodeStack *stack, long listNumber)

{
  StackType *pSVar1;

  if (stack->topOfStack < 0x20)
  {
    pSVar1 = stack->stack + stack->topOfStack;
    pSVar1->id = 0x16;
    if (*(int *)(&eventListNumInstances + listNumber * 4) < 1)
    {
      *(u_char *)pSVar1->data = 0;
    }
    else
    {
      *(_Instance **)pSVar1->data = (_Instance *)(&eventListArray2010 + listNumber * 10);
    }
    *(int *)(pSVar1->data + 4) = *(int *)(&eventListNumInstances + listNumber * 4);
    *(u_char *)(pSVar1->data + 8) = 0;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return 0;
}

void EVENT_StackDuplicate(_PCodeStack *stack)

{
  int iVar1;
  long *plVar2;
  StackType *pSVar3;
  long lVar4;
  long lVar5;
  long lVar6;

  iVar1 = stack->topOfStack;
  if ((iVar1 < 0x20) && (iVar1 != 0))
  {
    pSVar3 = stack->stack + iVar1;
    plVar2 = &stack->topOfStack + (iVar1 + -1) * 9 + 1;
    do
    {
      lVar4 = plVar2[1];
      lVar5 = plVar2[2];
      lVar6 = plVar2[3];
      pSVar3->id = *plVar2;
      *(long *)pSVar3->data = lVar4;
      *(long *)(pSVar3->data + 4) = lVar5;
      *(long *)(pSVar3->data + 8) = lVar6;
      plVar2 = plVar2 + 4;
      pSVar3 = (StackType *)(pSVar3->data + 0xc);
    } while (plVar2 != &stack->topOfStack + (iVar1 + -1) * 9 + 9);
    pSVar3->id = *plVar2;
    stack->topOfStack = stack->topOfStack + 1;
  }
  return;
}

long EVENT_TransformVector3dAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  long lVar1;

  lVar1 = 0;
  if (*(int *)(stackObject->data + 8) == -1)
  {
    *(long *)(stackObject->data + 8) = item;
    lVar1 = 1;
    switch (item)
    {
    default:
      goto switchD_80062544_caseD_5;
    case 0x2c:
    case 0x2e:
      if (codeStream != (short *)0x0)
      {
        MoveCodeStreamExtra = 2;
        *(short *)(stackObject->data + 0xc) = codeStream[1];
        *(short *)(stackObject->data + 0xe) = codeStream[2];
      }
      break;
    case 0x2d:
    case 0x2f:
      if (codeStream != (short *)0x0)
      {
        MoveCodeStreamExtra = 1;
        *(short *)(stackObject->data + 0xc) = codeStream[1];
      }
    }
    lVar1 = 1;
  }
switchD_80062544_caseD_5:
  return lVar1;
}

long EVENT_TransformSignalAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  u_int item_00;

  if (item == 0x3a)
  {
    item_00 = (u_int)(*(short *)(*(int *)stackObject->data + 0x16c) < -1);
  }
  else
  {
    if (item != 0x3b)
    {
      return 0;
    }
    item_00 = (u_int)(*(short *)(*(int *)stackObject->data + 0x16c) < 2) ^ 1;
  }
  EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
  return 1;
}

long EVENT_TransformEventAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  bool bVar1;
  short *psVar2;
  MultiSpline *pMVar3;
  int item_00;
  u_long item_01;
  _StreamUnit *p_Var4;
  long lVar5;
  AniTex *pAVar6;
  u_int uVar7;
  long item_02;
  _Terrain *p_Var8;
  short x;
  short y;
  short z;
  _Instance *Inst;
  Rotation3d local_28;

  Inst = *(_Instance **)stackObject->data;
  item_02 = 0;
  switch (item)
  {
  case 4:
  case 10:
  case 0xb:
  case 0x14:
  case 0x15:
  case 0x20:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x3e:
  case 0x40:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x5b:
  case 0x5c:
  case 0x5e:
  case 0x5f:
  case 0x67:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x72:
  case 0x74:
  case 0x7b:
  case 0x7c:
  case 0x8a:
  case 0x8c:
  case 0x8d:
  case 0x8f:
  case 0x90:
  case 0xa3:
  case 0xa4:
  case 0xa5:
    *(long *)(stackObject->data + 4) = item;
    item_02 = 1;
    break;
  case 5:
    psVar2 = (short *)INSTANCE_Post(Inst, 6);
    if (psVar2 == (short *)0x0)
    {
      x = (Inst->position).x;
      y = (Inst->position).y;
      z = (Inst->position).z;
    }
    else
    {
      x = *psVar2;
      y = psVar2[1];
      z = psVar2[2];
    }
    EVENT_ChangeOperandToNumber(stackObject, x, y, z, Inst->currentStreamUnitID);
    item_02 = 1;
    break;
  case 9:
    psVar2 = (short *)INSTANCE_Post(Inst, 7);
    if (psVar2 == (short *)0x0)
    {
      local_28.vx = (Inst->rotation).x;
      local_28.vy = (Inst->rotation).y;
      local_28.vz = (Inst->rotation).z;
    }
    else
    {
      local_28.vx = *psVar2;
      local_28.vy = psVar2[1];
      local_28.vz = psVar2[2];
    }
    local_28.errorx = 0x200;
    local_28.errorz = 0x200;
    local_28.errory = 0x200;
    EVENT_ChangeOperandVector3d(stackObject, &local_28);
    item_02 = 1;
    break;
  case 0xc:
    stackObject->id = 0xf;
    *(_Instance **)stackObject->data = Inst;
    pMVar3 = SCRIPT_GetMultiSpline(Inst, (u_long *)(stackObject->data + 0xc), (u_long *)(stackObject->data + 0x10));
    item_02 = 1;
    *(MultiSpline **)(stackObject->data + 4) = pMVar3;
    *(u_char *)(stackObject->data + 0x14) = 0;
    *(u_char *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x12:
    item_01 = INSTANCE_Post(Inst, 9);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 1);
    item_02 = 1;
    break;
  case 0x13:
    item_01 = INSTANCE_Post(Inst, 10);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 3);
    item_02 = 1;
    break;
  case 0x1d:
    lVar5 = 0x13;
    if (Inst->object->animList == (_G2AnimKeylist_Type **)0x0)
    {
      return 0;
    }
    goto LAB_80062af0;
  case 0x21:
    stackObject->id = 0x14;
    *(_Instance **)stackObject->data = Inst;
    item_02 = 1;
    pAVar6 = Inst->object->modelList[Inst->currentModel]->aniTextures;
    *(u_char *)(stackObject->data + 8) = 0xffffffff;
    *(AniTex **)(stackObject->data + 4) = pAVar6;
    break;
  case 0x2b:
    item_00 = Inst->attachedID;
    if ((item_00 == 0) &&
        (p_Var4 = STREAM_GetStreamUnitWithID(Inst->currentStreamUnitID), item_00 = 0,
         p_Var4 != (_StreamUnit *)0x0))
    {
      p_Var8 = p_Var4->level->terrain;
      if (Inst->bspTree < p_Var8->numBSPTrees)
      {
        item_00 = -(Inst->currentStreamUnitID * 0x100 + (int)p_Var8->BSPTreeArray[Inst->bspTree].ID);
      }
    }
    EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
    item_02 = 1;
    break;
  case 0x38:
    item_01 = INSTANCE_Post(Inst, 0x1e);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 0);
    item_02 = 1;
    break;
  case 0x39:
    lVar5 = 0x18;
  LAB_80062af0:
    item_02 = 1;
    stackObject->id = lVar5;
    *(_Instance **)stackObject->data = Inst;
    *(u_char *)(stackObject->data + 4) = 0xffffffff;
    break;
  case 0x3c:
    bVar1 = (Inst->flags & 4U) != 0;
    if (bVar1)
    {
      Inst->flags = Inst->flags & 0xfffffffb;
    }
    EVENT_ChangeOperandToNumber(stackObject, (u_int)bVar1, 0);
    item_02 = 1;
    break;
  case 0x3f:
    EVENT_ChangeOperandToNumber(stackObject, 1, 0);
    item_02 = 1;
    break;
  case 0x6a:
    uVar7 = Inst->flags;
    if ((int)uVar7 < 0)
    {
      Inst->flags = uVar7 & 0x7fffffff;
    }
    EVENT_ChangeOperandToNumber(stackObject, (u_int)((int)uVar7 < 0), 0);
    item_02 = 1;
    break;
  case 0x79:
    bVar1 = (Inst->flags & 8U) != 0;
    if (bVar1)
    {
      Inst->flags = Inst->flags & 0xfffffff7;
    }
    EVENT_ChangeOperandToNumber(stackObject, (u_int)bVar1, 0);
    item_02 = 1;
    break;
  case 0x7a:
    bVar1 = (Inst->flags & 0x10U) != 0;
    if (bVar1)
    {
      Inst->flags = Inst->flags & 0xffffffef;
    }
    EVENT_ChangeOperandToNumber(stackObject, (u_int)bVar1, 0);
    item_02 = 1;
    break;
  case 0x7d:
    bVar1 = (Inst->flags2 & 0x10000U) != 0;
    if (bVar1)
    {
      Inst->flags2 = Inst->flags2 & 0xfffeffff;
    }
    EVENT_ChangeOperandToNumber(stackObject, (u_int)bVar1, 0);
    item_02 = 1;
    break;
  case 0x7e:
    stackObject->id = 0x1b;
    *(_Instance **)(stackObject->data + 0x10) = Inst;
    *(undefined2 *)(stackObject->data + 2) = 0xffff;
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 1;
      *(int *)(stackObject->data + 4) = (int)codeStream[1];
    }
    item_00 = SOUND_IsInstanceSoundLoaded(Inst->object->soundData, *(long *)(stackObject->data + 4));
    if (item_00 == 0)
    {
      if (0 < (int)(WaitingToLoadSound - gameTrackerX.timeMult))
      {
        WaitingToLoadSound = WaitingToLoadSound - gameTrackerX.timeMult;
        EventAbortLine = 1;
        return 1;
      }
    }
    else
    {
      if (item_00 == -1)
      {
        return 1;
      }
    }
    WaitingToLoadSound = 0x96000;
    item_02 = 1;
    break;
  case 0x89:
    item_01 = INSTANCE_Post(Inst, 0x24);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 3);
    item_02 = 1;
    break;
  case 0x8b:
  case 0xa6:
    item_01 = INSTANCE_Post(Inst, 0);
    EVENT_ChangeOperandToNumber(stackObject, item_01 >> 0x1e & 1, 0);
    item_02 = 1;
    break;
  case 0x92:
    EVENT_ChangeOperandToNumber(stackObject, 0, 0);
    item_02 = 1;
    break;
  case 0x97:
    EVENT_ChangeOperandToNumber(stackObject, Inst->currentStreamUnitID, 0);
    item_02 = 1;
    break;
  case 0x99:
    EVENT_ChangeOperandToNumber(stackObject, (u_int)(Inst->tface != (_TFace *)0x0), 0);
    item_02 = 1;
    break;
  case 0x9f:
    item_01 = INSTANCE_Post(Inst, 0x2b);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 0);
    item_02 = 1;
    break;
  case 0xa0:
    item_01 = INSTANCE_Post(Inst, 1);
    EVENT_ChangeOperandToNumber(stackObject, (u_int)((item_01 & 4) != 0), 0);
    item_02 = 1;
    break;
  case 0xa1:
    Inst = (_Instance *)INSTANCE_Post(Inst, 0x2c);
    if (Inst == (_Instance *)0x0)
    {
      item_02 = 0;
    }
    else
    {
      item_01 = INSTANCE_Post(Inst, 1);
      if ((item_01 & 0x20) != 0)
      {
        item_01 = INSTANCE_Post(Inst, 4);
        if ((item_01 & 3) != 0)
        {
          return 1;
        }
        return 2;
      }
      item_02 = 3;
    }
    EVENT_ChangeOperandToNumber(stackObject, item_02, 0);
    item_02 = 1;
    break;
  case 0xa7:
    item_01 = INSTANCE_Post(Inst, 0);
    EVENT_ChangeOperandToNumber(stackObject, item_01 >> 0x1a & 1, 0);
    item_02 = 1;
    break;
  case 0xa9:
    item_01 = INSTANCE_Post(Inst, 0x1f);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 0);
    item_02 = 1;
    break;
  case 0xaa:
    item_01 = INSTANCE_Post(Inst, 0x20);
    EVENT_ChangeOperandToNumber(stackObject, item_01, 0);
    item_02 = 1;
  }
  return item_02;
}

long EVENT_TransformSubListObjectAttribute(_PCodeStack *stack, SoundObject *soundObject, long item, short *codeStream)

{
  int iVar1;
  long lVar2;

  lVar2 = 0;
  if (item == 0x7e)
  {
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 1;
      soundObject->soundNumber = (int)codeStream[1];
    }
    iVar1 = SOUND_IsInstanceSoundLoaded(*(u_char **)soundObject->data, soundObject->soundNumber);
    lVar2 = 1;
    if (iVar1 == 0)
    {
      EventAbortLine = 1;
    }
  }
  else
  {
    if (item < 0x7f)
    {
      if ((item < 0xf) && (0xc < item))
      {
        soundObject->attribute = (short)item;
        lVar2 = 1;
      }
    }
    else
    {
      if ((item == 0x7f) || (item == 0x80))
      {
        soundObject->attribute = (short)item;
        if (codeStream != (short *)0x0)
        {
          MoveCodeStreamExtra = 2;
          soundObject->value = (int)codeStream[1];
          soundObject->duration = (int)codeStream[2];
        }
        lVar2 = 1;
      }
    }
  }
  return lVar2;
}

long EVENT_SetSplineLoop(GameObject *gameObject)

{
  int iVar1;

  if (gameObject->attribute != -1)
  {
    if (gameObject->attribute != 2)
    {
      return 0;
    }
    iVar1 = GAMELOOP_GetTimeOfDay();
    if (iVar1 == 700)
    {
      return 2;
    }
    if (700 < iVar1)
    {
      if (iVar1 == 0x708)
      {
        return 3;
      }
      if (iVar1 != 0x76c)
      {
        return iVar1;
      }
      return 4;
    }
    if (iVar1 != 600)
    {
      return iVar1;
    }
  }
  return 1;
}

long EVENT_TransformSavedEventAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  u_short uVar5;
  Event *pEVar6;
  ScriptPCode *pSVar7;
  Level *pLVar8;
  EventTimer *pEVar9;
  u_long item_00;
  int Data;
  long item_01;
  u_int item_02;

  item_01 = 0;
  switch (item)
  {
  case 1:
 1000,0);
 item_01 = 1;
 break;
  case 2:
  case 0x58:
  case 0x59:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x76:
  case 0x77:
  case 0x87:
  case 0x88:
  case 0x89:
  case 0x8c:
  case 0x8e:
  case 0x93:
  case 0x96:
  case 0x9c:
    *(long *)stackObject->data = item;
    goto LAB_80063268;
  case 0x14:
    item_00 = INSTANCE_Post(gameTrackerX.playerInstance, 0xb);
    item_02 = item_00 >> 1 & 1;
    Data = STREAM_IsMonster();
    if (Data != 0)
    {
      item_02 = 0;
    }
    EVENT_ChangeOperandToNumber(stackObject, item_02, 0);
    item_01 = 1;
    break;
  case 0x15:
    item_00 = INSTANCE_Post(gameTrackerX.playerInstance, 0xb);
    item_02 = item_00 & 1;
    Data = STREAM_IsMonster();
    if (Data != 0)
    {
      item_02 = 0;
    }
    EVENT_ChangeOperandToNumber(stackObject, item_02, 0);
    item_01 = 1;
    break;
  case 0x1b:
    item_02 = gameTrackerX.controlCommand[0][0];
    if (((gameTrackerX.debugFlags & 0x40000U) != 0) &&
        ((gameTrackerX.controlCommand[0][0] & 0x90U) == 0x90))
    {
      item_02 = gameTrackerX.controlCommand[0][0] & 0xffffff6f;
    }
    EVENT_ChangeOperandToNumber(stackObject, item_02, 1);
    item_01 = 1;
    break;
  case 0x31:
    pEVar9 = EVENT_GetNextTerrainMove();
    pLVar8 = CurrentPuzzleLevel;
    pSVar7 = currentActionScript;
    pEVar6 = currentEventInstance;
    if (pEVar9 == (EventTimer *)0x0)
    {
      return 1;
    }
    if (codeStream == (short *)0x0)
    {
      return 1;
    }
    MoveCodeStreamExtra = 1;
    uVar5 = codeStream[1];
    EventAbortLine = 1;
    EventJustRecievedTimer = 1;
    pEVar9->actionScript = (ScriptPCode *)(codeStream + 2);
    pEVar9->flags = pEVar9->flags & 1U | (int)((u_int)uVar5 << 0x10) >> 3;
    *(ScriptPCode **)&pEVar9->event = pSVar7;
    *(Event **)&pEVar9->time = pEVar6;
    item_01 = EventCurrentEventIndex;
    pSVar7->conditionBits = pSVar7->conditionBits | 1;
    *(Level **)&pEVar9->scriptPos = pLVar8;
    *(long *)&pEVar9->level = item_01;
    goto LAB_80063268;
  case 0x3d:
    EVENT_ChangeOperandToNumber(stackObject, (int)gameTrackerX.timeOfDay, 0);
    item_01 = 1;
    break;
  case 0x42:
    item_01 = 1;
    stackObject->id = 0x19;
    *(u_char *)stackObject->data = 0x800d0f9c;
    *(u_char *)(stackObject->data + 8) = 0xffffffff;
    break;
  case 0x4a:
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 2;
      gameTrackerX.wipeTime = codeStream[2];
      gameTrackerX.wipeType = codeStream[1];
      gameTrackerX.maxWipeTime = gameTrackerX.wipeTime;
      if (gameTrackerX.wipeTime < 0)
      {
        gameTrackerX.maxWipeTime = -gameTrackerX.wipeTime;
      }
      if (gameTrackerX.wipeType == 0xb)
      {
        if (gameTrackerX.wipeTime < 0)
        {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x2000000;
        }
        else
        {
          gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfdffffff;
        }
      }
      stack->topOfStack = stack->topOfStack + -1;
    }
    goto LAB_80063268;
  case 0x51:
    Data = 0;
    goto LAB_80063128;
  case 0x52:
    Data = 1;
  LAB_80063128:
    INSTANCE_Broadcast((_Instance *)0x0, 10, 0x4000e, Data);
    item_01 = 1;
    stack->topOfStack = stack->topOfStack + -1;
    break;
  case 0x5a:
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 2;
      sVar1 = codeStream[1];
      sVar2 = codeStream[2];
      Data = rand();
      EVENT_ChangeOperandToNumber(stackObject, Data % ((int)sVar2 - (int)sVar1) + (int)sVar1, 0);
      return 1;
    }
    goto LAB_80063268;
  case 0x78:
    Data = LOAD_IsXAInQueue();
    EVENT_ChangeOperandToNumber(stackObject, (u_int)(Data == 0), 0);
    item_01 = 1;
    break;
  case 0x86:
    EVENT_ChangeOperandToNumber(stackObject, (u_int)gameTrackerX.streamFlags >> 0x17 & 1, 0);
    item_01 = 1;
    break;
  case 0x91:
    stack->topOfStack = stack->topOfStack + -1;
    EVENT_AddShortPointerToStack(stack, &gEndGameNow);
    item_01 = 1;
    break;
  case 0x9a:
    item_00 = INSTANCE_Post(gameTrackerX.playerInstance, 0x29);
    EVENT_ChangeOperandToNumber(stackObject, item_00, 3);
    item_01 = 1;
    break;
  case 0x9b:
    item_00 = INSTANCE_Post(gameTrackerX.playerInstance, 0x2a);
    EVENT_ChangeOperandToNumber(stackObject, item_00, 3);
    item_01 = 1;
    break;
  case 0x9d:
    item_01 = HINT_GetCurrentHint();
    EVENT_ChangeOperandToNumber(stackObject, item_01, 0);
    item_01 = 1;
    break;
  case 0x9e:
    EVENT_ChangeOperandToNumber(stackObject, gameTrackerX.streamFlags & 0x100000, 0);
    item_01 = 1;
    break;
  case 0xa2:
    if (codeStream != (short *)0x0)
    {
      MoveCodeStreamExtra = 4;
      sVar1 = codeStream[1];
      sVar2 = codeStream[2];
      sVar3 = codeStream[4];
      sVar4 = codeStream[3];
      stack->topOfStack = stack->topOfStack + -1;
      GAMEPAD_DisableDualShock((int)sVar1, (int)sVar2 << 0xc, (int)sVar4, (int)sVar3 << 0xc);
      return 1;
    }
  LAB_80063268:
    item_01 = 1;
    break;
  case 0xa8:
    stack->topOfStack = stack->topOfStack + -1;
    item_01 = 1;
    if ((gameTrackerX.debugFlags & 0x80000U) != 0)
    {
      Data = VOICEXA_IsPlaying();
      item_01 = 1;
      if (Data == 2)
      {
        EventAbortLine = 1;
      }
    }
  }
  return item_01;
}

long EVENT_TransformRotation3dAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;

  iVar3 = *(int *)stackObject->data;
  lVar2 = 0;
  if (iVar3 == 0)
  {
    EventAbortLine = 1;
    lVar2 = 1;
  }
  else
  {
    if (item == 0x41)
    {
      stack->topOfStack = stack->topOfStack + -1;
      EVENT_AddShortPointerToStack(stack, (short *)(*(int *)(iVar3 + 8) + 0x38));
      lVar2 = 1;
    }
    else
    {
      if (item < 0x42)
      {
        if (item == 3)
        {
          MoveCodeStreamExtra = 1;
          sVar1 = codeStream[1];
          if ((u_int)(int)sVar1 < 6)
          {
            stack->topOfStack = stack->topOfStack + -1;
            EVENT_AddShortPointerToStack(stack, (short *)(iVar3 + (int)sVar1 * 2 + 0x24));
            lVar2 = 1;
          }
        }
      }
      else
      {
        if ((item < 0x72) && (0x6f < item))
        {
          *(long *)(stackObject->data + 4) = item;
          lVar2 = 1;
        }
      }
    }
  }
  return lVar2;
}

long EVENT_TransformIntroAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  long lVar2;
  int iVar3;

  iVar3 = *(int *)stackObject->data;
  lVar2 = 0;
  if (item == 3)
  {
    MoveCodeStreamExtra = 1;
    sVar1 = codeStream[1];
    if ((u_int)(int)sVar1 < 6)
    {
      stack->topOfStack = stack->topOfStack + -1;
      EVENT_AddShortPointerToStack(stack, (short *)(iVar3 + (int)sVar1 * 2 + 6));
      lVar2 = 1;
    }
  }
  else
  {
    if ((item == 0x1a) && (lVar2 = 1, *(char *)(iVar3 + 5) == '\0'))
    {
      *(undefined *)(iVar3 + 5) = 1;
    }
  }
  return lVar2;
}

long EVENT_TransformIntroAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  long lVar1;
  u_int uVar2;
  char *pcVar3;

  lVar1 = 0;
  if (item == 3)
  {
    MoveCodeStreamExtra = 1;
    uVar2 = SEXT24(codeStream[1]);
    if (uVar2 < 6)
    {
      pcVar3 = *(char **)stackObject->data;
      if (pcVar3 == (char *)0x0)
      {
        EVENT_ChangeOperandToNumber(stackObject, 0, 0);
        lVar1 = 1;
      }
      else
      {
        if (*pcVar3 == '\x02')
        {
          stack->topOfStack = stack->topOfStack + -1;
          EVENT_AddShortPointerToStack(stack, (short *)(pcVar3 + uVar2 * 2 + 6));
          lVar1 = 1;
        }
        else
        {
          stack->topOfStack = stack->topOfStack + -1;
          EVENT_AddShortPointerToStack(stack, pcVar3 + uVar2 + 5);
          lVar1 = 1;
        }
      }
    }
  }
  return lVar1;
}

long EVENT_TransformGameAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  int iVar1;

  iVar1 = *(int *)(stackObject->data + 8);
  if (iVar1 < 5)
  {
    *(long *)(stackObject->data + iVar1 * 4 + 0xc) = item;
    *(int *)(stackObject->data + 8) = iVar1 + 1;
  }
  return (u_int)(iVar1 < 5);
}

long EVENT_TransformSoundObjectAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  int iVar1;

  iVar1 = *(int *)(stackObject->data + 0x18);
  if (iVar1 < 5)
  {
    *(long *)(stackObject->data + iVar1 * 4 + 4) = item;
    *(int *)(stackObject->data + 0x18) = iVar1 + 1;
  }
  return (u_int)(iVar1 < 5);
}

long EVENT_TransformAreaAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  if (item < 0x4a)
  {
    if (((item < 0x43) && (item != 9)) && (item != 0x10))
    {
      return 0;
    }
  }
  else
  {
    if (item != 0x68)
    {
      if (item < 0x69)
      {
        if (item != 0x5d)
        {
          return 0;
        }
        if (codeStream == (short *)0x0)
        {
          return 1;
        }
        MoveCodeStreamExtra = 2;
        CAMERA_SetMaxVel(*(Camera **)stackObject->data, (int)codeStream[1],
                         100);
        stack->topOfStack = stack->topOfStack + -1;
        return 1;
      }
      if (item != 0x69)
      {
        if (item == 0x75)
        {
          EVENT_ChangeOperandToNumber(stackObject,
                                      (u_int)(((*(Camera **)stackObject->data)->data).Cinematic.cinema_done != 0), 0);
          return 1;
        }
        return 0;
      }
      if (codeStream != (short *)0x0)
      {
        MoveCodeStreamExtra = 1;
        *(int *)(stackObject->data + 4) = (int)codeStream[1];
      }
    }
  }
  *(long *)(stackObject->data + 8) = item;
  return 1;
}

long EVENT_TransformSplineAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  u_short uVar1;
  short sVar2;
  _Instance *instance;

  instance = *(_Instance **)stackObject->data;
  if (item == 0x22)
  {
    *(u_int *)(stackObject->data + 0x14) = *(u_int *)(stackObject->data + 0x14) | 4;
  }
  else
  {
    if (item < 0x23)
    {
      if (item == 0x1f)
      {
        MoveCodeStreamExtra = 2;
        instance->clipBeg = codeStream[1];
        uVar1 = instance->splineFlags;
        instance->clipEnd = codeStream[2];
        instance->splineFlags = uVar1 | 2;
        if (*(int *)&instance->clipBeg == -1)
        {
          instance->splineFlags = uVar1 & 0xfffd;
        }
        else
        {
          sVar2 = SCRIPTCountFramesInSpline(instance);
          if (sVar2 <= instance->clipEnd)
          {
            instance->clipEnd = sVar2;
          }
          if (instance->clipBeg < 0)
          {
            instance->clipBeg = 0;
          }
        }
      }
      else
      {
        *(long *)(stackObject->data + 8) = item;
      }
    }
    else
    {
      if (item == 0x23)
      {
        *(u_int *)(stackObject->data + 0x14) = *(u_int *)(stackObject->data + 0x14) | 8;
      }
      else
      {
        *(long *)(stackObject->data + 8) = item;
      }
    }
  }
  return 1;
}

long EVENT_TransformInstanceAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  short x;
  short y;
  short z;
  _StreamUnit *p_Var1;
  void *pointer;
  Rotation3d local_30;

  pointer = *(void **)stackObject->data;
  switch (item)
  {
  case 5:
    if ((*(u_int *)((int)pointer + 0x2c) & 0x4000) != 0)
    {
      x = *(short *)((int)pointer + 0x20);
      y = *(short *)((int)pointer + 0x22);
      z = *(short *)((int)pointer + 0x24);
      p_Var1 = STREAM_WhichUnitPointerIsIn(pointer);
      EVENT_ChangeOperandToNumber(stackObject, x, y, z, p_Var1->StreamUnitID);
      return 1;
    }
  default:
    EventAbortLine = 1;
    break;
  case 9:
    local_30.vx = *(short *)((int)pointer + 0x18);
    local_30.vy = *(short *)((int)pointer + 0x1a);
    local_30.vz = *(short *)((int)pointer + 0x1c);
    local_30.errorx = 0x200;
    local_30.errorz = 0x200;
    local_30.errory = 0x200;
    EVENT_ChangeOperandVector3d(stackObject, &local_30);
    break;
  case 0x3e:
  case 0x8a:
  case 0x92:
  case 0xa0:
  case 0xa6:
    *(long *)(stackObject->data + 4) = item;
    break;
  case 0x3f:
    EVENT_ChangeOperandToNumber(stackObject, 0, 0);
  }
  return 1;
}

long EVENT_ParseOpcode(StackType *operand2, long *error, long *trueValue)

{
  long lVar1;
  short asStack24[4];

  lVar1 = -1;
  if (((operand2 != (StackType *)0x0) &&
       (lVar1 = EVENT_GetScalerValueFromOperand(operand2, error, asStack24), *error == 0)) &&
      (lVar1 == 0))
  {
    *trueValue = 0;
  }
  return lVar1;
}

long EVENT_DoIntroAction(EventVmObject *vmobject, StackType *operand2)

{
  u_short uVar1;
  long table;
  int iVar2;
  _VMObject *p_Var3;
  long local_18;
  u_int local_14;

  local_14 = 1;
  local_18 = 1;
  if (vmobject->attribute == -1)
  {
    return 0;
  }
  table = EVENT_ParseOpcode(operand2, &local_18, (long *)&local_14);
  iVar2 = vmobject->attribute;
  if (iVar2 == 0xe)
  {
    local_14 = (u_int)(local_14 == 0);
  }
  else
  {
    if (0xe < iVar2)
    {
      if (iVar2 == 99)
      {
        if (table == -1)
        {
          return 0;
        }
        if (table < 0)
        {
          return 0;
        }
        if (vmobject->vmObjectPtr->numVMOffsetTables <= table)
        {
          return 0;
        }
        VM_VMObjectSetTable(vmobject->level, vmobject->vmObjectPtr, table);
        if ((vmobject->vmObjectPtr->flags & 2) != 0)
        {
          if (vmobject->level != (Level *)0x0)
          {
            VM_ProcessVMObjectSetColor_S();
            return 0;
          }
          return 0;
        }
        return 0;
      }
      if (iVar2 != 100)
      {
        return 0;
      }
      if (table == -1)
      {
        return 1;
      }
      vmobject->vmObjectPtr->timer = table;
      if ((vmobject->vmObjectPtr->flags & 2) == 0)
      {
        return 1;
      }
      if (vmobject->level != (Level *)0x0)
      {
        VM_ProcessVMObjectSetColor_S();
        return 1;
      }
      return 1;
    }
    if (iVar2 != 0xd)
    {
      return 0;
    }
  }
  if (local_14 == 0)
  {
    p_Var3 = vmobject->vmObjectPtr;
    uVar1 = p_Var3->flags | 2;
  }
  else
  {
    p_Var3 = vmobject->vmObjectPtr;
    uVar1 = p_Var3->flags & 0xfffd;
  }
  p_Var3->flags = uVar1;
  return 1;
}

long EVENT_GetInstanceValue(EventVmObject *vmobject)

{
  int iVar1;
  u_int uVar2;

  iVar1 = vmobject->attribute;
  uVar2 = 1;
  if (iVar1 == 0xe)
  {
    uVar2 = 0;
  }
  else
  {
    if (0xe < iVar1)
    {
      if (iVar1 == 99)
      {
        return (int)vmobject->vmObjectPtr->currentIdx;
      }
      if (iVar1 != 100)
      {
        return 0;
      }
      return vmobject->vmObjectPtr->timer % vmobject->vmObjectPtr->curVMOffsetTable->numVMOffsets;
    }
    if (iVar1 == -1)
    {
      return 1;
    }
    if (iVar1 != 0xd)
    {
      return 0;
    }
  }
  if ((vmobject->vmObjectPtr->flags & 2) != 0)
  {
    uVar2 = (u_int)(uVar2 == 0);
  }
  return uVar2;
}

long EVENT_DoGameAction(GameObject *gameObject, StackType *operand2)

{
  long modifier;
  int iVar1;
  int local_20;
  long local_1c;

  local_20 = 1;
  local_1c = 1;
  if (gameObject->attribute != -1)
  {
    modifier = EVENT_ParseOpcode(operand2, &local_20, &local_1c);
    iVar1 = gameObject->attribute;
    if (iVar1 == 0x87)
    {
      SOUND_ResetMusicModifier(modifier);
    }
    else
    {
      if (iVar1 < 0x88)
      {
        if (iVar1 == 0x59)
        {
          if (local_20 == 0)
          {
            FX_Start_Rain(modifier);
          }
          else
          {
            FX_Start_Rain(100);
          }
        }
        else
        {
          if (iVar1 < 0x5a)
          {
            if (iVar1 == 2)
            {
              if (modifier == 2)
              {
                GAMELOOP_SetGameTime(700);
              }
              else
              {
                if (modifier < 3)
                {
                  if (modifier == 1)
                  {
                    GAMELOOP_SetGameTime(600);
                  }
                }
                else
                {
                  if (modifier == 3)
                  {
                    GAMELOOP_SetGameTime(0x708);
                  }
                  else
                  {
                    if (modifier == 4)
                    {
                      GAMELOOP_SetGameTime(0x76c);
                    }
                  }
                }
              }
            }
            else
            {
              if (iVar1 == 0x58)
              {
                if (local_20 == 0)
                {
                  FX_Start_Snow(modifier);
                }
                else
                {
                  FX_Start_Snow(100);
                }
              }
            }
          }
          else
          {
            if (iVar1 == 0x76)
            {
              if ((-1 < modifier) && ((gameTrackerX.debugFlags & 0x80000U) != 0))
              {
                if (WaitingForVoiceNumber == modifier)
                {
                  iVar1 = VOICEXA_IsPlaying();
                  if (iVar1 == 2)
                  {
                    WaitingForVoiceNumber = -1;
                    return 1;
                  }
                }
                else
                {
                  iVar1 = VOICEXA_IsPlaying();
                  if (iVar1 != 2)
                  {
                    LOAD_PlayXA(modifier);
                    WaitingForVoiceNumber = modifier;
                    EventAbortLine = 1;
                    return 1;
                  }
                }
                EventAbortLine = 1;
              }
            }
            else
            {
              if ((iVar1 == 0x77) && (modifier - 1U < 0x7f))
              {
                SpuSetVoiceVolume(modifier);
              }
            }
          }
        }
      }
      else
      {
        if (iVar1 == 0x93)
        {
          HINT_StopHint();
        }
        else
        {
          if (iVar1 < 0x94)
          {
            if (iVar1 == 0x88)
            {
              SOUND_SetMusicModifier(modifier);
            }
            else
            {
              if (iVar1 == 0x8e)
              {
                HINT_StartHint((short)modifier);
              }
            }
          }
          else
          {
            if (iVar1 == 0x96)
            {
              CINE_PlayIngame(modifier);
            }
            else
            {
              if (iVar1 == 0x9c)
              {
                HINT_KillSpecificHint((short)modifier);
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

long EVENT_DoSubListAction(SignalObject *signalObject, StackType *operand2)

{
  long lStack16;
  int local_c;

  local_c = 1;
  if (((signalObject->attribute != -1) &&
       (EVENT_ParseOpcode(operand2, &lStack16, &local_c), signalObject->attribute == 0x1a)) &&
      (local_c != 0))
  {
    COLLIDE_HandleSignal(gameTrackerX.playerInstance, signalObject->msignal->signalList,
                         signalObject->msignal->numSignals, 0);
  }
  return 0;
}

long EVENT_TransformCameraObjectAttribute(_PCodeStack *stack, StackType *stackObject, long item)

{
  if (item == 0x1a)
  {
    *(u_char *)(stackObject->data + 4) = 0x1a;
  }
  else
  {
    if (item != 0x32)
    {
      return 0;
    }
    EVENT_ChangeOperandToNumber(stackObject, (u_int) * (u_short *)(*(int *)stackObject->data + 6) & 1, 0);
  }
  return 1;
}

long EVENT_TransformTGroupAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  if ((5 < item) && ((item < 9 || ((item < 99 && (0x5f < item))))))
  {
    *(long *)(stackObject->data + 0x10) = item;
    return 1;
  }
  return 0;
}

long EVENT_TransformListObjectAttribute(_PCodeStack *stack, StackType *stackObject, long item, short *codeStream)

{
  short sVar1;
  long item_00;

  switch (item)
  {
  case 6:
    item_00 = (long)*(short *)stackObject->data;
    goto LAB_80063f80;
  case 7:
    item_00 = (long)*(short *)(stackObject->data + 2);
    goto LAB_80063f80;
  case 8:
    item_00 = (long)*(short *)(stackObject->data + 4);
  LAB_80063f80:
    EVENT_ChangeOperandToNumber(stackObject, item_00, 0);
    item_00 = 1;
    break;
  default:
    item_00 = 0;
    break;
  case 0x17:
    item_00 = 1;
    sVar1 = codeStream[1];
    *(undefined2 *)(stackObject->data + 10) = 0xffff;
    *(undefined2 *)(stackObject->data + 0xc) = 0xffff;
    MoveCodeStreamExtra = 1;
    *(short *)(stackObject->data + 8) = sVar1;
    break;
  case 0x18:
    MoveCodeStreamExtra = 2;
    item_00 = 1;
    *(short *)(stackObject->data + 8) = codeStream[1];
    sVar1 = codeStream[2];
    *(undefined2 *)(stackObject->data + 0xc) = 0xffff;
    *(short *)(stackObject->data + 10) = sVar1;
    break;
  case 0x19:
    MoveCodeStreamExtra = 3;
    *(short *)(stackObject->data + 8) = codeStream[1];
    *(short *)(stackObject->data + 10) = codeStream[2];
    item_00 = 1;
    *(short *)(stackObject->data + 0xc) = codeStream[3];
  }
  return item_00;
}

void EVENT_ModifyObjectToStackWithAttribute(_PCodeStack *stack, long item, short *codeStream)

{
  if (stack->topOfStack != 0)
  {
    EVENT_TransformObjectOnStack(stack, item, codeStream);
  }
  return;
}

long EVENT_DoInstanceAnimateTextureAction(InstanceAnimateTexture *instanceAniTexture, StackType *operand2)

{
  long lVar1;
  long lVar2;
  int local_18;
  u_int local_14;

  local_14 = 1;
  local_18 = 1;
  if (instanceAniTexture->attribute == -1)
  {
    lVar2 = 1;
  }
  else
  {
    lVar1 = EVENT_ParseOpcode(operand2, &local_18, (long *)&local_14);
    lVar2 = 0;
    switch (instanceAniTexture->attribute)
    {
    case 0xe:
      local_14 = local_14 ^ 1;
    case 0xd:
    case 0x29:
      lVar2 = 1;
      if (local_14 == 0)
      {
        instanceAniTexture->instance->flags = instanceAniTexture->instance->flags | 0x80;
      }
      else
      {
        instanceAniTexture->instance->flags = instanceAniTexture->instance->flags & 0xffffff7f;
      }
      break;
    case 0xf:
    case 0x28:
      lVar2 = 0;
      if (local_18 == 0)
      {
        instanceAniTexture->instance->currentTextureAnimFrame = (short)lVar1;
        lVar2 = 0;
      }
    }
  }
  return lVar2;
}

void EVENT_ResetAllSplineFlags(MultiSpline *spline)

{
  Spline *pSVar1;
  RSpline *pRVar2;

  pSVar1 = spline->positional;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  pRVar2 = spline->rotational;
  if (pRVar2 != (RSpline *)0x0)
  {
    pRVar2->flags = pRVar2->flags & 0xf8;
  }
  pSVar1 = spline->scaling;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  pSVar1 = spline->color;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags & 0xf8;
  }
  return;
}

void EVENT_GetSplineValue(MultiSpline *spline)

{
  Spline *pSVar1;
  RSpline *pRVar2;

  pSVar1 = spline->positional;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags | 2;
  }
  pRVar2 = spline->rotational;
  if (pRVar2 != (RSpline *)0x0)
  {
    pRVar2->flags = pRVar2->flags | 2;
  }
  pSVar1 = spline->scaling;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags | 2;
  }
  pSVar1 = spline->color;
  if (pSVar1 != (Spline *)0x0)
  {
    pSVar1->flags = pSVar1->flags | 2;
  }
  return;
}

long EVENT_DoSoundMarkerAction(InstanceSpline *instanceSpline, StackType *operand2)

{
  short sVar1;
  u_short uVar2;
  int iVar3;
  u_int uVar4;
  long lVar5;
  u_int uVar6;
  Spline *pSVar7;
  RSpline *pRVar8;
  _Instance *instance;
  MultiSpline *spline;
  long lVar9;
  long lStack32;
  u_int local_1c;

  lVar9 = 0;
  local_1c = 1;
  if (instanceSpline->attribute == -1)
  {
    return 1;
  }
  instance = instanceSpline->instance;
  spline = instanceSpline->spline;
  iVar3 = EVENT_ParseOpcode(operand2, &lStack32, (long *)&local_1c);
  switch (instanceSpline->attribute)
  {
  case 0xd:
  case 0x29:
    goto switchD_800642f4_caseD_d;
  case 0xe:
    local_1c = local_1c ^ 1;
  switchD_800642f4_caseD_d:
    lVar9 = 1;
    if (local_1c == 0)
    {
      uVar6 = instance->flags;
      uVar4 = 0xfdffffff;
    LAB_800644a4:
      instance->flags = uVar6 & uVar4;
    }
    else
    {
      uVar4 = instance->flags;
      uVar6 = 0x2000000;
    LAB_8006448c:
      instance->flags = uVar4 | uVar6;
    }
  switchD_800642f4_caseD_12:
    return lVar9;
  case 0xf:
  case 0x28:
    if (iVar3 == -1)
    {
      return 0;
    }
    SCRIPT_InstanceSplineProcess(instance, (short)iVar3, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
    uVar4 = 0xfdff0000;
    goto LAB_8006449c;
  case 0x10:
    EVENT_ResetAllSplineFlags(spline);
    instance->splineFlags = instance->splineFlags & 0xff8f;
    if (iVar3 == 2)
    {
      EVENT_GetSplineValue(spline);
      uVar2 = instance->splineFlags | 0x20;
    }
    else
    {
      if ((iVar3 < 3) && (iVar3 == 1))
      {
        pSVar7 = spline->positional;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 1;
        }
        pRVar8 = spline->rotational;
        if (pRVar8 != (RSpline *)0x0)
        {
          pRVar8->flags = pRVar8->flags | 1;
        }
        pSVar7 = spline->scaling;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 1;
        }
        pSVar7 = spline->color;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 1;
        }
        uVar2 = instance->splineFlags | 0x10;
      }
      else
      {
        pSVar7 = spline->positional;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 4;
        }
        pRVar8 = spline->rotational;
        if (pRVar8 != (RSpline *)0x0)
        {
          pRVar8->flags = pRVar8->flags | 4;
        }
        pSVar7 = spline->scaling;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 4;
        }
        pSVar7 = spline->color;
        if (pSVar7 != (Spline *)0x0)
        {
          pSVar7->flags = pSVar7->flags | 4;
        }
        uVar2 = instance->splineFlags | 0x40;
      }
    }
    instance->splineFlags = uVar2;
    return 0;
  case 0x11:
    uVar4 = 0xfeff0000;
    if (iVar3 < 1)
      goto LAB_80064484;
  LAB_8006449c:
    uVar6 = instance->flags;
    uVar4 = uVar4 | 0xffff;
    goto LAB_800644a4;
  default:
    goto switchD_800642f4_caseD_12;
  case 0x1c:
    if (iVar3 < 0)
    {
      iVar3 = 0;
    }
    else
    {
      sVar1 = SCRIPTCountFramesInSpline(instance);
      if ((int)sVar1 <= iVar3)
      {
        iVar3 = (int)sVar1;
      }
    }
    lVar5 = INSTANCE_GetSplineFrameNumber(instanceSpline);
    if (lVar5 == iVar3)
    {
      SCRIPT_InstanceSplineProcess(instance, (short)iVar3, (SplineDef *)0x0, (SplineDef *)0x0, (SplineDef *)0x0);
      uVar4 = 0xfdff0000;
      goto LAB_8006449c;
    }
    instance->splineFlags = instance->splineFlags | 1;
    instance->targetFrame = (short)iVar3;
    instance->flags = instance->flags | 0x2000000;
    if (iVar3 < lVar5)
    {
      uVar4 = instanceSpline->splineFlags & 4;
      instanceSpline->splineFlags = uVar4;
      if (uVar4 != 0)
      {
        EVENT_ResetAllSplineFlags(spline);
        EVENT_GetSplineValue(spline);
        instance->splineFlags = instance->splineFlags | 0x20;
        instance->flags = instance->flags & 0xfeffffff;
        return 0;
      }
    }
    else
    {
      uVar4 = instanceSpline->splineFlags & 8;
      instanceSpline->splineFlags = uVar4;
      if (uVar4 == 0)
      {
        uVar4 = 0xfeff0000;
        goto LAB_8006449c;
      }
      EVENT_ResetAllSplineFlags(spline);
      EVENT_GetSplineValue(spline);
      instance->splineFlags = instance->splineFlags | 0x20;
    }
  LAB_80064484:
    uVar4 = instance->flags;
    uVar6 = 0x1000000;
    goto LAB_8006448c;
  }
}

long EVENT_DoAreaAction(InstanceAnimate *instanceAnimate, StackType *operand2)

{
  long lVar1;
  int Data;
  short sVar2;
  int Message;
  _Instance *instance;
  long lVar3;
  long lStack32;
  u_int local_1c;

  lVar3 = 0;
  local_1c = 1;
  if (instanceAnimate->attribute == -1)
  {
    return 0;
  }
  instance = instanceAnimate->instance;
  lVar1 = EVENT_ParseOpcode(operand2, &lStack32, (long *)&local_1c);
  sVar2 = (short)lVar1;
  switch (instanceAnimate->attribute)
  {
  case 0xe:
    local_1c = local_1c ^ 1;
  case 0xd:
  case 0x29:
    if (local_1c == 0)
    {
      Message = 0x8000010;
      Data = 0;
    }
    else
    {
      if ((instance->aliasCommand).hostInstance == (_Instance *)0x0)
      {
        Data = SetAnimationInstanceSwitchData(instance, (int)(instance->aliasCommand).newanim,
                                              (int)(instance->aliasCommand).newframe,
                                              (int)(instance->aliasCommand).interpframes, 1);
        Message = 0x8000008;
      }
      else
      {
        Data = SetActionPlayHostAnimationData(instance, (instance->aliasCommand).hostInstance,
                                              (int)(instance->aliasCommand).newanim,
                                              (int)(instance->aliasCommand).newframe,
                                              (int)(instance->aliasCommand).interpframes, 1);
        Message = 0x40003;
      }
    }
    INSTANCE_Query(instance, Message, Data);
    memset(&instance->aliasCommand, 0, 0xc);
    lVar3 = 1;
    break;
  case 0xf:
  case 0x28:
    lVar3 = 0;
    if (lVar1 != -1)
    {
      (instance->aliasCommand).newframe = sVar2;
    }
    break;
  case 0x1e:
    lVar3 = 1;
    if (lVar1 != -1)
    {
      (instance->aliasCommand).newanim = sVar2;
    }
    break;
  case 0x2a:
    if ((instance->aliasCommand).hostInstance == (_Instance *)0x0)
    {
      Data = SetAnimationInstanceSwitchData(instance, (int)(instance->aliasCommand).newanim,
                                            (int)(instance->aliasCommand).newframe,
                                            (int)(instance->aliasCommand).interpframes, 2);
      Message = 0x8000008;
    }
    else
    {
      Data = SetActionPlayHostAnimationData(instance, (instance->aliasCommand).hostInstance,
                                            (int)(instance->aliasCommand).newanim, (int)(instance->aliasCommand).newframe, (int)(instance->aliasCommand).interpframes, 2);
      Message = 0x40003;
    }
  LAB_800648d4:
    INSTANCE_Query(instance, Message, Data);
    goto LAB_800648dc;
  case 0x65:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id == 2)
      {
        (instance->aliasCommand).hostInstance = *(_Instance **)operand2->data;
      }
      else
      {
        EventAbortLine = 1;
        lVar3 = 0;
      }
    }
    break;
  case 0x66:
    lVar3 = 0;
    if (lVar1 != -1)
    {
      (instance->aliasCommand).interpframes = sVar2;
    }
    break;
  case 0x6b:
    if ((instance->aliasCommand).hostInstance == (_Instance *)0x0)
    {
      Data = SetAnimationInstanceSwitchData(instance, (int)(instance->aliasCommand).newanim,
                                            (int)(instance->aliasCommand).newframe,
                                            (int)(instance->aliasCommand).interpframes, 0);
      Message = 0x8000008;
    }
    else
    {
      Data = SetActionPlayHostAnimationData(instance, (instance->aliasCommand).hostInstance,
                                            (int)(instance->aliasCommand).newanim, (int)(instance->aliasCommand).newframe, (int)(instance->aliasCommand).interpframes, 0);
      Message = 0x40003;
    }
    INSTANCE_Query(instance, Message, Data);
    Data = (int)(instance->aliasCommand).speed;
    if (0 < Data)
    {
      Message = 0x40020;
      goto LAB_800648d4;
    }
  LAB_800648dc:
    memset(&instance->aliasCommand, 0, 0xc);
    lVar3 = 1;
    break;
  case 0x84:
    (instance->aliasCommand).speed = sVar2;
  }
  return lVar3;
}

long EVENT_DoCameraAction(InstanceObject *instanceObject, StackType *operand2, short *codeStream)

{
  long lVar1;
  Event *pEVar2;
  ScriptPCode *pSVar3;
  Level *pLVar4;
  u_int type;
  u_long uVar5;
  EventTimer *pEVar6;
  int Data;
  Intro *pIVar7;
  int y;
  u_int Message;
  _Instance *sender;
  Object *pOVar8;
  long lStack40;
  u_int local_24;

  local_24 = 1;
  sender = instanceObject->instance;
  if (instanceObject->attribute == -1)
  {
    return 0;
  }
  type = EVENT_ParseOpcode(operand2, &lStack40, (long *)&local_24);
  switch (instanceObject->attribute)
  {
  case 4:
    if (0xff < (int)type)
    {
      INSTANCE_Query(sender, 0x40017, type - 0x100);
      return 0;
    }
    if (type - 1 < 7)
    {
      ScriptKillInstance(sender, type);
      return 0;
    }
    if (type != 0)
    {
      return 0;
    }
    SAVE_Init(sender);
    return 0;
  case 10:
    goto switchD_80064994_caseD_a;
  case 0xb:
    local_24 = local_24 ^ 1;
  switchD_80064994_caseD_a:
    if (local_24 == 0)
    {
      type = sender->flags;
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = type & 0xfffff7ff;
      sender->flags = type & 0xfffbf7ff;
      if ((sender->object->oflags2 & 0x80000U) != 0)
      {
        type = sender->flags2 & 0xefffffff;
        goto LAB_80064bd8;
      }
    }
    else
    {
      sender->flags = sender->flags | 0x800;
      sender->flags2 = sender->flags2 | 0x20000000;
      sender->flags = sender->flags | 0x40000;
      if ((sender->object->oflags2 & 0x80000U) != 0)
      {
        type = sender->flags2 | 0x10000000;
      LAB_80064bd8:
        sender->flags2 = type;
      }
    }
    uVar5 = INSTANCE_Post(sender, 1);
    if ((uVar5 & 0xe) == 0)
    {
      return 1;
    }
    Data = 0x40013;
    type = local_24;
  LAB_80064c00:
    INSTANCE_Query(sender, Data, type);
    return 1;
  case 0x14:
    local_24 = local_24 ^ 1;
  case 0x15:
    if (local_24 == 0)
    {
      Data = 0x10002001;
      type = 0;
    }
    else
    {
      Data = 0x10002002;
      type = 0;
    }
    goto LAB_80064c00;
  case 0x20:
    if (type == 2)
    {
      type = 0x40012;
    }
    else
    {
      if ((int)type < 3)
      {
        if (type != 1)
        {
          return 0;
        }
        type = 0x40000;
      }
      else
      {
        if (type != 3)
        {
          if (type != 4)
          {
            return 0;
          }
          INSTANCE_Query(sender, 0x40005, (int)&DAT_0000a000);
          return 0;
        }
        type = 0x40014;
      }
    }
    goto LAB_80065338;
  case 0x24:
    goto switchD_80064994_caseD_24;
  case 0x25:
    local_24 = local_24 ^ 1;
  switchD_80064994_caseD_24:
    if (local_24 == 0)
    {
      uVar5 = INSTANCE_Post(instanceObject->instance, 5);
      if ((uVar5 & 1) == 0)
      {
        return 0;
      }
      type = 0x800020;
    }
    else
    {
      uVar5 = INSTANCE_Post(instanceObject->instance, 5);
      if ((uVar5 & 1) != 0)
      {
        return 0;
      }
      type = 0x800020;
    }
    goto LAB_80065338;
  case 0x26:
    local_24 = local_24 ^ 1;
  case 0x27:
    if (local_24 == 0)
    {
      type = 0x800000;
    LAB_80065334:
      type = type | 0x22;
    }
    else
    {
      type = 0x800021;
    }
    goto LAB_80065338;
  case 0x33:
    if (type == 0xffffffff)
    {
      type = 0;
    }
    Message = 0x1000017;
    goto LAB_8006531c;
  case 0x34:
    if (local_24 == 0)
    {
      type = sender->flags & 0xfffff7ff;
    }
    else
    {
      type = sender->flags | 0x800;
    }
    goto LAB_80064aa4;
  case 0x35:
    if (local_24 == 0)
    {
      sender->flags2 = sender->flags2 & 0xdfffffff;
      sender->flags = sender->flags & 0xfffbffff;
      return 1;
    }
    sender->flags2 = sender->flags2 | 0x20000000;
    type = sender->flags | 0x40000;
  LAB_80064aa4:
    sender->flags = type;
    return 1;
  case 0x36:
    Data = 0;
    if (type < 4)
    {
      y = 0;
      if (type == 1)
      {
        Data = 1;
      }
      else
      {
        if ((int)type < 2)
        {
          if (type == 0)
          {
            y = 1;
          }
        }
        else
        {
          if (type == 2)
          {
            Data = 0;
            y = -1;
          }
          else
          {
            if (type == 3)
            {
              Data = -1;
            }
          }
        }
      }
      Data = SetObjectBreakOffData(Data, y, 6, (_Instance *)0x0, 0);
      y = 0x800000;
      goto LAB_8006528c;
    }
    break;
  case 0x37:
    pOVar8 = sender->object;
    Data = (int)pOVar8->numberOfEffects;
    if (Data != 0)
    {
      if (type == 0xffffffff)
      {
        y = 0;
        if (0 < Data)
        {
          do
          {
            FX_StartInstanceEffect(sender, pOVar8->effectList + y, 0);
            y = y + 1;
          } while (y < pOVar8->numberOfEffects);
          return 0;
        }
      }
      else
      {
        if ((int)type < Data)
        {
          FX_StartInstanceEffect(sender, pOVar8->effectList + type, 0);
          return 0;
        }
      }
    }
    break;
  case 0x40:
    if (type != 0)
    {
      type = 1;
    }
    Message = 0x100001a;
    goto LAB_8006531c;
  case 0x4b:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x40016;
      goto LAB_8006528c;
    }
    break;
  case 0x4c:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      INSTANCE_Query(sender, 0x4000a, Data);
      sender->currentStreamUnitID = *(long *)(operand2->data + 0x10);
    }
    break;
  case 0x4d:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 0xe)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000b;
      goto LAB_8006528c;
    }
    break;
  case 0x4e:
    goto switchD_80064994_caseD_4e;
  case 0x4f:
    local_24 = (u_int)(local_24 == 0);
  switchD_80064994_caseD_4e:
    if (sender != gameTrackerX.playerInstance)
    {
      INSTANCE_Query(sender, 0x4000e, local_24);
      return 0;
    }
    INSTANCE_Query(sender, 0x4000e, local_24);
    if (local_24 == 0)
    {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
      return 0;
    }
    gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
    pEVar6 = EVENT_GetNextTerrainMove();
    pSVar3 = currentActionScript;
    pEVar2 = currentEventInstance;
    lVar1 = EventCurrentEventIndex;
    if (pEVar6 != (EventTimer *)0x0)
    {
      EventAbortLine = 1;
      EventJustRecievedTimer = 1;
      *(short **)&pEVar6->actionScript = codeStream;
      pEVar6->flags = pEVar6->flags & 1U | 0x2000;
      *(Event **)&pEVar6->time = pEVar2;
      *(ScriptPCode **)&pEVar6->event = pSVar3;
      pLVar4 = CurrentPuzzleLevel;
      pSVar3->conditionBits = pSVar3->conditionBits | 1;
      *(Level **)&pEVar6->scriptPos = pLVar4;
      *(long *)&pEVar6->level = lVar1;
    }
    break;
  case 0x50:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 0xe)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000d;
      goto LAB_8006528c;
    }
    break;
  case 0x53:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000f;
      goto LAB_8006528c;
    }
    break;
  case 0x54:
    if (local_24 != 0)
    {
      type = 0x40010;
      goto LAB_80065338;
    }
    break;
  case 0x55:
    INSTANCE_Query(sender, 0x800027, local_24);
    return 0;
  case 0x5b:
    if ((int)type < 0)
    {
      return 0;
    }
    sender->lightGroup = (u_char)type;
    return 0;
  case 0x5c:
    if ((int)type < 0)
    {
      return 0;
    }
    sender->spectralLightGroup = (u_char)type;
    return 0;
  case 0x5e:
    goto switchD_80064994_caseD_5e;
  case 0x5f:
    local_24 = 0;
  switchD_80064994_caseD_5e:
    INSTANCE_Query(sender, 0x800029, local_24);
    return 0;
  case 0x67:
    if (local_24 == 0)
    {
      sender->flags = sender->flags | 0x400000;
    }
    else
    {
      sender->flags = sender->flags & 0xffbfffff;
    }
    break;
  case 0x6c:
    Data = (int)type % 0x168;
    if (Data < 0)
    {
      Data = Data + 0x168;
    }
 0x168);
 y = 0x4000005;
  LAB_8006528c:
    INSTANCE_Query(sender, y, Data);
    return 0;
  case 0x6d:
    type = 0x4000006;
    goto LAB_80065338;
  case 0x6e:
    type = 0x40011;
  LAB_80065338:
    INSTANCE_Query(sender, type, 0);
    return 0;
  case 0x6f:
    INSTANCE_Query(sender, 0x40015, 1 << (type & 0x1f));
    return 0;
  case 0x72:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x4000c;
      goto LAB_8006528c;
    }
    break;
  case 0x74:
    INSTANCE_Query(sender, 0x40006, type << 0xc);
    return 0;
  case 0x7b:
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id != 9)
      {
        return 0;
      }
      Data = SetPositionData((int)*(short *)operand2->data, (int)*(short *)(operand2->data + 2),
                             (int)*(short *)(operand2->data + 4));
      y = 0x40018;
      goto LAB_8006528c;
    }
    break;
  case 0x7c:
    type = type << 0xc;
    INSTANCE_Query(sender, 0x40019, type);
  case 0xa3:
    Message = 0x1000000;
  LAB_80065318:
    Message = Message | 0x22;
  LAB_8006531c:
    INSTANCE_Query(sender, Message, type);
    return 0;
  case 0x85:
    Message = 0x40021;
    goto LAB_8006531c;
  case 0x8a:
    pIVar7 = sender->intro;
    if (pIVar7 == (Intro *)0x0)
    {
      return 0;
    }
    if (local_24 == 0)
    {
      pIVar7->flags = pIVar7->flags & 0xfffffbff;
    }
    else
    {
      pIVar7->flags = pIVar7->flags | 0x400;
    }
    break;
  case 0x8c:
    Message = 0x40000;
    goto LAB_80065318;
  case 0x8d:
    if (-1 < (int)type)
    {
      Data = SetMonsterAlarmData(sender, (_Position *)0x0, type);
      INSTANCE_Broadcast((_Instance *)0x0, 10, 0x1000011, Data);
      return 0;
    }
    break;
  case 0xa4:
    type = 0x1000000;
    goto LAB_80065334;
  case 0xa5:
    if (sender != gameTrackerX.playerInstance)
    {
      return 0;
    }
    if (local_24 == 0)
    {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
    }
    else
    {
      gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
    }
  }
  return 0;
}

long EVENT_GetIntroValue(TGroupObject *terrainGroup)

{
  u_short uVar1;
  int iVar2;
  BSPTree *pBVar3;
  u_int uVar4;

  iVar2 = terrainGroup->attribute;
  pBVar3 = terrainGroup->bspTree;
  uVar4 = 1;
  if (iVar2 == 0x35)
  {
    uVar1 = pBVar3->flags & 2;
  }
  else
  {
    if (iVar2 < 0x36)
    {
      if (iVar2 != 10)
      {
        if (iVar2 < 0xb)
        {
          if (iVar2 != -1)
          {
            return 0;
          }
          return -(terrainGroup->streamUnit->StreamUnitID * 0x100 + (int)pBVar3->ID);
        }
        if (iVar2 != 0xb)
        {
          if (iVar2 != 0x34)
          {
            return 0;
          }
          return (u_int)(u_short)pBVar3->flags & 1;
        }
        uVar4 = 0;
      }
      if ((pBVar3->flags & 3U) == 3)
      {
        return uVar4;
      }
      return uVar4 ^ 1;
    }
    if (iVar2 == 0x73)
    {
      uVar1 = pBVar3->flags & 0x40;
    }
    else
    {
      if (iVar2 < 0x74)
      {
        if (iVar2 == 0x3c)
        {
          if ((pBVar3->flags & 0x800U) == 0)
          {
            return 0;
          }
          pBVar3->flags = pBVar3->flags & 0xf7ff;
          return 1;
        }
        if (iVar2 != 0x6a)
        {
          return 0;
        }
        if ((pBVar3->flags & 0x400U) == 0)
        {
          return 0;
        }
        pBVar3->flags = pBVar3->flags & 0xfbff;
        return 1;
      }
      if (iVar2 == 0x7d)
      {
        if ((pBVar3->flags & 0x2000U) == 0)
        {
          return 0;
        }
        pBVar3->flags = pBVar3->flags & 0xdfff;
        return 1;
      }
      if (iVar2 != 0x95)
      {
        return 0;
      }
      uVar1 = pBVar3->flags & 0x20;
    }
  }
  return (u_int)(uVar1 != 0);
}

long EVENT_DoSignalAction(TGroupObject *terrainGroup, StackType *operand2)

{
  short sVar1;
  u_short uVar2;
  WaterLevelProcess *pWVar3;
  int iVar4;
  Level *pLVar5;
  _Terrain *p_Var6;
  int iVar7;
  BSPTree *pBVar8;
  long lStack24;
  u_int local_14;

  local_14 = 1;
  if (terrainGroup->attribute == -1)
  {
    return 0;
  }
  pBVar8 = terrainGroup->bspTree;
  EVENT_ParseOpcode(operand2, &lStack24, (long *)&local_14);
  iVar4 = terrainGroup->attribute;
  if (iVar4 < 0x31)
  {
    if (0x2e < iVar4)
    {
      iVar4 = (int)(pBVar8->localOffset).z;
      iVar7 = (int)terrainGroup->arg[0] - iVar4;
      if (iVar4 == (int)terrainGroup->arg[0])
      {
        return 1;
      }
      (pBVar8->globalOffset).z = (pBVar8->globalOffset).z + (short)iVar7;
      (pBVar8->localOffset).z = terrainGroup->arg[0];
      if (terrainGroup->attribute == 0x2f)
      {
        pLVar5 = terrainGroup->streamUnit->level;
        pLVar5->waterZLevel = pLVar5->waterZLevel + iVar7;
        p_Var6 = terrainGroup->streamUnit->level->terrain;
        p_Var6->UnitChangeFlags = p_Var6->UnitChangeFlags | 3;
        return 1;
      }
      return 1;
    }
    if (iVar4 == 0xb)
    {
      local_14 = local_14 ^ 1;
    }
    else
    {
      if (0xb < iVar4)
      {
        if ((iVar4 != 0x2c) && (iVar4 != 0x2e))
        {
          return 0;
        }
        pWVar3 = EVENT_GetNextTimer();
        if (pWVar3 == (WaterLevelProcess *)0x0)
        {
          return 0;
        }
        pWVar3->bspTree = pBVar8;
        pWVar3->streamUnit = terrainGroup->streamUnit;
        pWVar3->oldWaterZ = *(short *)&terrainGroup->streamUnit->level->waterZLevel;
        pWVar3->oldGlobalOffset = (pBVar8->globalOffset).z;
        pWVar3->zValueFrom = (pBVar8->localOffset).z;
        pWVar3->zValueTo = terrainGroup->arg[0];
        sVar1 = terrainGroup->arg[1];
        WaterInUse = 1;
        pWVar3->curStep = 0;
        pWVar3->flags = 1;
        pWVar3->maxSteps = (int)sVar1 << 0xc;
        if (terrainGroup->attribute == 0x2e)
        {
          pWVar3->flags = pWVar3->flags | 2;
          return 0;
        }
        return 0;
      }
      if (iVar4 != 10)
      {
        return 0;
      }
    }
    if (local_14 == 0)
    {
      uVar2 = pBVar8->flags & 0xfffc;
    }
    else
    {
      uVar2 = pBVar8->flags | 3;
    }
  }
  else
  {
    if (iVar4 == 0x35)
    {
      if (local_14 == 0)
      {
        uVar2 = pBVar8->flags & 0xfffd;
      }
      else
      {
        uVar2 = pBVar8->flags | 2;
      }
    }
    else
    {
      if (iVar4 < 0x36)
      {
        if (iVar4 != 0x34)
        {
          return 0;
        }
        if (local_14 == 0)
        {
          uVar2 = pBVar8->flags & 0xfffe;
        }
        else
        {
          uVar2 = pBVar8->flags | 1;
        }
      }
      else
      {
        if (iVar4 == 0x73)
        {
          if (local_14 == 0)
          {
            uVar2 = pBVar8->flags & 0xffbf;
          }
          else
          {
            uVar2 = pBVar8->flags | 0x40;
          }
        }
        else
        {
          if (iVar4 != 0x95)
          {
            return 0;
          }
          if (local_14 == 0)
          {
            uVar2 = pBVar8->flags & 0xffdf;
          }
          else
          {
            uVar2 = pBVar8->flags | 0x20;
          }
        }
      }
    }
  }
  pBVar8->flags = uVar2;
  return 1;
}

long EVENT_DoSplineAction(CameraObject *cameraObject, StackType *operand2, short *codeStream)

{
  long dist;
  int iVar1;
  int frames;
  Camera *camera;
  int iVar2;
  int local_18;
  long local_14;

  local_14 = 1;
  local_18 = 1;
  camera = cameraObject->camera;
  if (cameraObject->attribute == -1)
  {
    return 0;
  }
  dist = EVENT_ParseOpcode(operand2, &local_18, &local_14);
  switch (cameraObject->attribute)
  {
  case 9:
  case 0x46:
    if (local_18 == 0)
    {
      if (cameraObject->attribute == 0x46)
      {
        iVar1 = -dist % 0x168;
        if (iVar1 < 0)
        {
          iVar1 = iVar1 + 0x168;
        }
 0x168);
      }
      else
      {
        iVar1 = -dist % 0x168;
        if (iVar1 < 0)
        {
          iVar1 = iVar1 + 0x168;
        }
 0x168);
      }
    }
    break;
  case 0x10:
    if (local_18 == 0)
    {
      CAMERA_Save(camera, dist);
    }
    break;
  case 0x43:
    if (local_18 == 0)
    {
      CAMERA_SetSmoothValue(camera, dist);
    }
    break;
  case 0x44:
  case 0x45:
    iVar1 = 0;
    if (operand2 != (StackType *)0x0)
    {
      if (operand2->id == 2)
      {
        iVar1 = *(int *)(*(int *)operand2->data + 0x20);
      }
      else
      {
        if (operand2->id == 4)
        {
          iVar1 = *(int *)operand2->data;
        }
      }
    }
    if (iVar1 != 0)
    {
      if (cameraObject->attribute == 0x44)
      {
        camera->Spline00 = *(MultiSpline **)(iVar1 + 0x38);
      }
      else
      {
        camera->Spline01 = *(MultiSpline **)(iVar1 + 0x38);
      }
    }
    break;
  case 0x47:
    if (local_18 == 0)
    {
      CAMERA_Adjust_rotation(cameraObject->camera, dist);
    }
    break;
  case 0x48:
    CAMERA_RestoreMode(camera);
    break;
  case 0x49:
    if ((operand2 != (StackType *)0x0) && (operand2->id == 2))
    {
      CAMERA_SetProjDistance(camera, *(_Instance **)operand2->data);
    }
    break;
  case 0x68:
    if (local_18 != 0)
    {
      return 0;
    }
    iVar1 = dist % 0x168;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0x168;
    }
    iVar1 = iVar1 << 0xc;
    iVar2 = (int)((u_longlong)((longlong)iVar1 * -0x49f49f49) >> 0x20);
    frames = 0;
    goto LAB_80065b10;
  case 0x69:
    if (local_18 != 0)
    {
      return 0;
    }
    iVar1 = dist % 0x168;
    if (iVar1 < 0)
    {
      iVar1 = iVar1 + 0x168;
    }
    iVar1 = iVar1 << 0xc;
    frames = cameraObject->frames;
    iVar2 = (int)((u_longlong)((longlong)iVar1 * -0x49f49f49) >> 0x20);
  LAB_80065b10:
    CAMERA_Adjust_roll((iVar2 + iVar1 >> 8) - (iVar1 >> 0x1f), frames);
  }
  return 0;
}

long EVENT_DoAction(SoundObject *soundObject, StackType *operand2)

{
  short sVar1;
  SoundInstance *soundInst;
  long lVar2;
  long lStack24;
  u_int local_14;

  lVar2 = 1;
  local_14 = 1;
  if (soundObject->attribute != -1)
  {
    soundInst = (SoundInstance *)(soundObject->data + soundObject->soundNumber * 3 + 0x48);
    EVENT_ParseOpcode(operand2, &lStack24, (long *)&local_14);
    sVar1 = soundObject->attribute;
    if (sVar1 == 0x7f)
    {
      SOUND_EndInstanceSounds(soundInst, soundObject->value, soundObject->duration);
      lVar2 = 1;
    }
    else
    {
      if (sVar1 < 0x80)
      {
        if (sVar1 != 0xd)
        {
          if (sVar1 != 0xe)
          {
            return 0;
          }
          local_14 = (u_int)(local_14 == 0);
        }
        if (local_14 == 0)
        {
          SOUND_SetInstanceSoundPitch(soundInst);
          lVar2 = 1;
        }
        else
        {
          SOUND_ProcessInstanceSounds(soundInst);
          lVar2 = 1;
        }
      }
      else
      {
        if (sVar1 == 0x80)
        {
          SOUND_SetInstanceSoundPitch(soundInst, soundObject->value, soundObject->duration);
          lVar2 = 1;
        }
        else
        {
          lVar2 = 1;
          if (0x83 < sVar1)
          {
            lVar2 = 0;
          }
        }
      }
    }
  }
  return lVar2;
}

long EVENT_DoObjectSoundAction(SoundObject *soundObject, StackType *operand2)

{
  short sVar1;
  SoundInstance *soundInst;
  long lVar2;
  long lStack24;
  u_int local_14;

  lVar2 = 1;
  local_14 = 1;
  if (soundObject->attribute != -1)
  {
    soundInst = (SoundInstance *)(soundObject->data + soundObject->soundNumber * 3 + 8);
    EVENT_ParseOpcode(operand2, &lStack24, (long *)&local_14);
    sVar1 = soundObject->attribute;
    if (sVar1 == 0x7f)
    {
      SOUND_EndInstanceSounds(soundInst, soundObject->value, soundObject->duration);
      lVar2 = 1;
    }
    else
    {
      if (sVar1 < 0x80)
      {
        if (sVar1 != 0xd)
        {
          if (sVar1 != 0xe)
          {
            return 0;
          }
          local_14 = (u_int)(local_14 == 0);
        }
        if (local_14 == 0)
        {
          SOUND_SetInstanceSoundPitch(soundInst);
          lVar2 = 1;
        }
        else
        {
          SOUND_ProcessInstanceSounds(soundInst);
          lVar2 = 1;
        }
      }
      else
      {
        if (sVar1 == 0x80)
        {
          SOUND_SetInstanceSoundPitch(soundInst, soundObject->value, soundObject->duration);
          lVar2 = 1;
        }
        else
        {
          lVar2 = 1;
          if (0x83 < sVar1)
          {
            lVar2 = 0;
          }
        }
      }
    }
  }
  return lVar2;
}

long EVENT_GetTGroupValue(SoundObject *soundObject)

{
  return 0;
}

long EVENT_DoAnimateAction(AreaObject *areaObject, StackType *operand2)

{
  long lVar1;
  u_short uVar2;
  _StreamUnit *p_Var3;
  int local_18;
  long local_14;

  local_14 = 1;
  p_Var3 = areaObject->streamUnit;
  if (areaObject->attribute != -1)
  {
    lVar1 = EVENT_ParseOpcode(operand2, &local_18, &local_14);
    uVar2 = (u_short)lVar1;
    if (areaObject->attribute == 0x70)
    {
      if (local_18 == 0)
      {
        p_Var3->TargetFogFar = uVar2;
        p_Var3->level->fogFar = uVar2;
      }
    }
    else
    {
      if ((areaObject->attribute == 0x71) && (local_18 == 0))
      {
        p_Var3->TargetFogNear = uVar2;
        p_Var3->level->fogNear = uVar2;
      }
    }
  }
  return 0;
}

long EVENT_DoTGroupAction(IntroObject *introObject, StackType *operand2)

{
  u_int uVar1;
  Level *pLVar2;
  Intro *pIVar3;
  _Instance *p_Var4;
  u_int uVar5;
  int iVar6;
  int iVar7;
  STracker *pSVar8;
  long lVar9;
  Intro *intro;
  long lVar10;
  long lStack24;
  u_int local_14;

  local_14 = 1;
  lVar10 = 0;
  lVar9 = lVar10;
  if (introObject->attribute != -1)
  {
    intro = introObject->intro;
    EVENT_ParseOpcode(operand2, &lStack24, (long *)&local_14);
    iVar7 = introObject->attribute;
    if (iVar7 != 0x14)
    {
      if (iVar7 < 0x15)
      {
        if (iVar7 != 10)
        {
          if (iVar7 != 0xb)
          {
            return 0;
          }
          local_14 = local_14 ^ 1;
        }
        uVar5 = 0xfffffff7;
        if (local_14 == 0)
        {
          uVar1 = intro->flags;
          uVar5 = 0xffffff7f;
        }
        else
        {
          uVar1 = intro->flags | 0x80;
        }
        intro->flags = uVar1 & uVar5;
        lVar9 = 1;
      }
      else
      {
        if (iVar7 == 0x3e)
        {
          lVar9 = 0;
          iVar7 = 0;
          pSVar8 = &StreamTracker;
          do
          {
            if (pSVar8->StreamList[0].used == 2)
            {
              pLVar2 = pSVar8->StreamList[0].level;
              iVar6 = pLVar2->numIntros;
              pIVar3 = pLVar2->introList;
              while (iVar6 != 0)
              {
                if (pIVar3 == intro)
                {
                  lVar9 = pSVar8->StreamList[0].StreamUnitID;
                  break;
                }
                iVar6 = iVar6 + -1;
                pIVar3 = pIVar3 + 1;
              }
            }
            pSVar8 = (STracker *)(pSVar8->StreamList + 1);
            iVar7 = iVar7 + 1;
          } while (iVar7 < 0x10);
          p_Var4 = INSTANCE_InsertInstanceGroup(intro, (short)lVar9);
          lVar9 = 0;
          if (p_Var4 == (_Instance *)0x0)
          {
            EventAbortLine = 1;
            lVar9 = lVar10;
          }
        }
        else
        {
          lVar9 = 0;
          if ((0x3e < iVar7) && (lVar9 = 0, iVar7 == 0x8a))
          {
            if (local_14 == 0)
            {
              intro->flags = intro->flags & 0xfffffbff;
              lVar9 = lVar10;
            }
            else
            {
              intro->flags = intro->flags | 0x400;
              lVar9 = lVar10;
            }
          }
        }
      }
    }
  }
  return lVar9;
}

void EVENT_DoStackMathOperation(_PCodeStack *stack, short *codeStream)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long local_58[10];
  long local_30[10];

  plVar3 = (long *)local_30;
  iVar1 = stack->topOfStack + -1;
  plVar2 = &stack->topOfStack + iVar1 * 9 + 1;
  stack->topOfStack = iVar1;
  do
  {
    lVar4 = plVar2[1];
    lVar5 = plVar2[2];
    lVar6 = plVar2[3];
    *plVar3 = *plVar2;
    plVar3[1] = lVar4;
    plVar3[2] = lVar5;
    plVar3[3] = lVar6;
    plVar2 = plVar2 + 4;
    plVar3 = plVar3 + 4;
  } while (plVar2 != &stack->topOfStack + iVar1 * 9 + 9);
  *plVar3 = *plVar2;
  plVar3 = (long *)local_58;
  iVar1 = stack->topOfStack + -1;
  plVar2 = &stack->topOfStack + iVar1 * 9 + 1;
  stack->topOfStack = iVar1;
  do
  {
    lVar4 = plVar2[1];
    lVar5 = plVar2[2];
    lVar6 = plVar2[3];
    *plVar3 = *plVar2;
    plVar3[1] = lVar4;
    plVar3[2] = lVar5;
    plVar3[3] = lVar6;
    plVar2 = plVar2 + 4;
    plVar3 = plVar3 + 4;
  } while (plVar2 != &stack->topOfStack + iVar1 * 9 + 9);
  *plVar3 = *plVar2;
  EVENT_ExecuteActionCommand((StackType *)local_58, (StackType *)local_30, stack, codeStream);
  return;
}

long EVENT_CompareVector3d(Vector3d *vector1, Vector3d *vector2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;

  if (vector1->streamUnitID != vector2->streamUnitID)
  {
    return 0;
  }
  iVar4 = (int)vector1->errory;
  if (iVar4 != -1)
  {
    iVar3 = (int)vector1->errorz;
    if (iVar3 != -1)
    {
      if ((int)vector2->vx < (int)vector1->vx - (int)vector1->errorx)
      {
        return 0;
      }
      if ((int)vector1->vx + (int)vector1->errorx < (int)vector2->vx)
      {
        return 0;
      }
      if ((int)vector2->vy < vector1->vy - iVar4)
      {
        return 0;
      }
      if ((int)vector2->vy <= vector1->vy + iVar4)
      {
        if (vector1->vz - iVar3 <= (int)vector2->vz)
        {
          return (u_int)(vector1->vz + iVar3 < (int)vector2->vz) ^ 1;
        }
        return 0;
      }
      return 0;
    }
    if (iVar4 != -1)
    {
      iVar3 = (int)vector2->vx - (int)vector1->vx;
      iVar2 = (int)vector2->vy - (int)vector1->vy;
      if ((int)vector1->errorx * (int)vector1->errorx <= iVar3 * iVar3 + iVar2 * iVar2)
      {
        return 0;
      }
      iVar3 = (int)vector2->vz - (int)vector1->vz;
      if (-1 < iVar3)
      {
        if (iVar3 < iVar4)
        {
          return 1;
        }
        return 0;
      }
      bVar1 = (int)vector1->vz - (int)vector2->vz < iVar4;
      goto LAB_80066348;
    }
  }
  iVar4 = (int)vector2->vx - (int)vector1->vx;
  iVar3 = (int)vector2->vy - (int)vector1->vy;
  iVar2 = (int)vector2->vz - (int)vector1->vz;
  bVar1 = iVar4 * iVar4 + iVar3 * iVar3 + iVar2 * iVar2 <
          (int)vector1->errorx * (int)vector1->errorx;
LAB_80066348:
  if (bVar1)
  {
    return 1;
  }
  return 0;
}

long EVENT_CompareRotationVectors(Rotation3d *rot1, Rotation3d *rot2, long trueValue)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;
  MATRIX MStack104;
  MATRIX MStack72;
  _SVector local_28;

  uVar4 = (u_int)(trueValue == 0);
  iVar3 = rot1->attribute;
  bVar1 = false;
  if (iVar3 == -1)
  {
    iVar3 = rot2->attribute;
  }
  RotMatrixZYX((u_short *)rot1, (u_int *)&MStack104);
  RotMatrixZYX((u_short *)rot2, (u_int *)&MStack72);
  if (iVar3 == 8)
  {
  LAB_800664c0:
    local_28.x = 0;
    local_28.y = 0;
    local_28.z = 0x1000;
    goto LAB_800664d4;
  }
  if (iVar3 < 9)
  {
    if (iVar3 == 6)
    {
    LAB_80066490:
      local_28.x = 0x1000;
      local_28.y = 0;
      local_28.z = 0;
      goto LAB_800664d4;
    }
    if (iVar3 < 7)
    {
      if (iVar3 == -1)
      {
        local_28.x = 0x1000;
        local_28.y = 0;
        local_28.z = 0;
        iVar2 = PHYSOBS_CheckObjectAxisAlignment(&MStack104, &MStack72, &local_28);
        if (iVar2 - 0xf80U < 0x101)
        {
          local_28.x = 0;
          local_28.y = 0x1000;
          local_28.z = 0;
          iVar2 = PHYSOBS_CheckObjectAxisAlignment(&MStack104, &MStack72, &local_28);
          if (iVar2 - 0xf80U < 0x101)
          {
            uVar4 = trueValue;
          }
        }
      }
      goto LAB_800664d4;
    }
  }
  else
  {
    if (iVar3 != 0x61)
    {
      if (0x61 < iVar3)
      {
        if (iVar3 != 0x62)
          goto LAB_800664d4;
        bVar1 = true;
        goto LAB_800664c0;
      }
      if (iVar3 != 0x60)
        goto LAB_800664d4;
      bVar1 = true;
      goto LAB_80066490;
    }
    bVar1 = true;
  }
  local_28.x = 0;
  local_28.y = 0x1000;
  local_28.z = 0;
LAB_800664d4:
  if (iVar3 != -1)
  {
    iVar3 = PHYSOBS_CheckObjectAxisAlignment(&MStack104, &MStack72, &local_28);
    if (bVar1)
    {
      uVar4 = trueValue;
      if ((0x100 < iVar3 - 0xf80U) && (&DAT_00000100 < &DAT_00001080 + iVar3))
      {
        uVar4 = (u_int)(trueValue == 0);
      }
    }
    else
    {
      uVar4 = trueValue;
      if (0x100 < iVar3 - 0xf80U)
      {
        uVar4 = (u_int)(trueValue == 0);
      }
    }
  }
  return uVar4;
}

long EVENT_CompareSubListWithOperation(_PCodeStack *stack, ListObject *listObject, StackType *operand2, long operation)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  ListObject *pLVar5;
  _Instance *startInstance;
  long lVar6;
  long areaID;
  long local_60;
  _Instance *local_5c;
  u_char local_58;
  char acStack56[16];

  lVar6 = 0;
  if (CurrentEventLine < 0x14)
  {
    *(u_char *)(&eventListNumInstances + CurrentEventLine * 4) = 0;
  }
  strcmp(acStack56, listObject->eventInstance->objectName);
  pcVar1 = strchr(acStack56, 0x3f);
  if (pcVar1 != (char *)0x0)
  {
    *pcVar1 = '\0';
  }
  areaID = listObject->eventInstance->unitID;
  startInstance = (_Instance *)0x0;
  if (areaID == 0x3f)
  {
    areaID = 0;
  }
  do
  {
    startInstance = INSTANCE_FindWithName(areaID, acStack56, startInstance);
    if (startInstance == (_Instance *)0x0)
    {
      return lVar6;
    }
    local_60 = 2;
    local_58 = 0xffffffff;
    iVar4 = 0;
    pLVar5 = listObject;
    local_5c = startInstance;
    if (0 < listObject->numberOfAttributes)
    {
      do
      {
        EVENT_TransformConstrictAttribute((StackType *)&local_60, stack, pLVar5->attribute[0], (short *)0x0);
        iVar4 = iVar4 + 1;
        pLVar5 = (ListObject *)pLVar5->attribute;
      } while (iVar4 < listObject->numberOfAttributes);
    }
    lVar2 = EVENT_CompareListWithOperation(stack, (StackType *)&local_60, operand2, operation);
    if (lVar2 == 0)
    {
      if (operation == 0xb)
      {
        if (9 < *(int *)(&eventListNumInstances + CurrentEventLine * 4))
        {
          return 0;
        }
        *(int *)(&eventListNumInstances + CurrentEventLine * 4) = 0;
        return 0;
      }
    }
    else
    {
      iVar4 = CurrentEventLine * 4;
      if (CurrentEventLine < 0x14)
      {
        iVar3 = *(int *)(&eventListNumInstances + iVar4);
        if (iVar3 < 10)
        {
          (&eventListArray2010)[CurrentEventLine * 10 + iVar3] = startInstance;
          *(int *)(&eventListNumInstances + iVar4) = iVar3 + 1;
        }
      }
      lVar6 = 1;
    }
  } while (startInstance != (_Instance *)0x0);
  return lVar6;
}

long EVENT_CompareOperandsWithOperation(_PCodeStack *stack, SubListObject *subListObject, StackType *operand2, long operation)

{
  long lVar1;
  int iVar2;
  int iVar3;
  SubListObject *pSVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long local_50;
  u_char local_4c;
  u_char local_48;

  lVar7 = 0;
  if (CurrentEventLine < 0x14)
  {
    *(u_char *)(&eventListNumInstances + CurrentEventLine * 4) = 0;
  }
  iVar6 = 0;
  if (0 < subListObject->numberOfInstances)
  {
    iVar5 = 0;
    do
    {
      local_50 = 2;
      local_4c = *(u_char *)(iVar5 + (int)subListObject->instanceList);
      local_48 = 0xffffffff;
      iVar3 = 0;
      pSVar4 = subListObject;
      if (0 < subListObject->numberOfAttributes)
      {
        do
        {
          EVENT_TransformConstrictAttribute((StackType *)&local_50, stack, pSVar4->attribute[0], (short *)0x0);
          iVar3 = iVar3 + 1;
          pSVar4 = (SubListObject *)&pSVar4->numberOfInstances;
        } while (iVar3 < subListObject->numberOfAttributes);
      }
      lVar1 = EVENT_CompareListWithOperation(stack, (StackType *)&local_50, operand2, operation);
      if (lVar1 != 0)
      {
        iVar3 = CurrentEventLine * 4;
        if (CurrentEventLine < 0x14)
        {
          iVar2 = *(int *)(&eventListNumInstances + iVar3);
          if (iVar2 < 10)
          {
            (&eventListArray2010)[CurrentEventLine * 10 + iVar2] =
                *(_Instance **)(iVar5 + (int)subListObject->instanceList);
            *(int *)(&eventListNumInstances + iVar3) = iVar2 + 1;
          }
        }
        lVar7 = 1;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar6 < subListObject->numberOfInstances);
  }
  return lVar7;
}

long EVENT_CompareListWithOperation(_PCodeStack *stack, StackType *operand1, StackType *operand2, long operation)

{
  u_int uVar1;
  u_int uVar2;
  int iVar3;
  int iVar4;
  short z;
  u_int uVar5;
  u_int trueValue;
  long lStack32;
  u_short local_1c;
  u_short local_1a;

  uVar5 = 0;
  trueValue = 1;
  switch (operand1->id)
  {
  case 8:
    break;
  case 9:
    if (operand2->id != 9)
    {
      return 0;
    }
    if (operation == 2)
    {
      iVar3 = (u_int) * (u_short *)operand1->data - (u_int) * (u_short *)operand2->data;
      iVar4 = (u_int) * (u_short *)(operand1->data + 2) - (u_int) * (u_short *)(operand2->data + 2);
      z = *(short *)(operand1->data + 4) - *(short *)(operand2->data + 4);
    }
    else
    {
      if (2 < operation)
      {
        uVar5 = trueValue;
        if (operation != 10)
        {
          if (operation != 0xb)
          {
            return 0;
          }
          uVar5 = 0;
        }
        trueValue = EVENT_CompareVector3d((Vector3d *)operand1->data, (Vector3d *)operand2->data);
        goto LAB_80066b94;
      }
      if (operation != 1)
      {
        return 0;
      }
      iVar3 = (u_int) * (u_short *)operand1->data + (u_int) * (u_short *)operand2->data;
      iVar4 = (u_int) * (u_short *)(operand1->data + 2) + (u_int) * (u_short *)(operand2->data + 2);
      z = *(short *)(operand1->data + 4) + *(short *)(operand2->data + 4);
    }
    EVENT_Addvector3dToStack(stack, (short)((u_int)(iVar3 * 0x10000) >> 0x10),
                             (short)((u_int)(iVar4 * 0x10000) >> 0x10), z, 0);
    uVar5 = 0xffffffff;
    break;
  default:
    uVar1 = EVENT_GetScalerValueFromOperand(operand1, &lStack32, (short *)&local_1c);
    uVar2 = EVENT_GetScalerValueFromOperand(operand2, &lStack32, (short *)&local_1a);
    switch (operation)
    {
    case 1:
      uVar5 = uVar1 + uVar2;
      break;
    case 2:
      uVar5 = uVar1 - uVar2;
      break;
    case 3:
      uVar5 = uVar1 * uVar2;
      break;
    case 4:
      uVar5 = 0;
      if (uVar2 != 0)
      {
        (int)uVar2;
      }
      break;
    case 5:
      uVar5 = (int)uVar1 % uVar2;
      if ((int)uVar5 < 0)
      {
        uVar5 = uVar5 + uVar2;
      }
      break;
    case 6:
    switchD_80066b1c_caseD_6:
      uVar5 = trueValue;
      trueValue = (u_int)((int)uVar2 < (int)uVar1);
      goto LAB_80066b94;
    case 7:
    switchD_80066b1c_caseD_7:
      uVar5 = trueValue;
      trueValue = (u_int)((int)uVar1 < (int)uVar2);
      goto LAB_80066b94;
    case 8:
      trueValue = 0;
      goto switchD_80066b1c_caseD_7;
    case 9:
      trueValue = 0;
      goto switchD_80066b1c_caseD_6;
    case 10:
    switchD_80066b1c_caseD_a:
      uVar5 = trueValue;
      if (((local_1c & 1) == 0) && ((local_1a & 1) == 0))
      {
        if (uVar1 != uVar2)
        {
          uVar5 = uVar5 ^ 1;
        }
      }
      else
      {
        if ((local_1c & 2) != 0)
        {
          uVar2 = 1 << (uVar2 & 0x1f);
        }
        if ((uVar1 & uVar2) != uVar2)
        {
          uVar5 = uVar5 ^ 1;
        }
      }
      break;
    case 0xb:
      trueValue = 0;
      goto switchD_80066b1c_caseD_a;
    case 0xc:
      uVar5 = (u_int)((uVar1 & uVar2) != 0);
    }
    break;
  case 0xe:
    uVar5 = 0;
    if (operand2->id == 0xe)
    {
      if (operation != 10)
      {
        if (operation != 0xb)
        {
          return 0;
        }
        trueValue = 0;
      }
      uVar5 = EVENT_CompareRotationVectors((Rotation3d *)operand1->data, (Rotation3d *)operand2->data, trueValue);
    }
    break;
  case 0x12:
    trueValue = EVENT_CompareSubListWithOperation(stack, (ListObject *)operand1->data, operand2, operation);
    uVar5 = 1;
    goto LAB_80066b94;
  case 0x16:
    trueValue = EVENT_CompareOperandsWithOperation(stack, (SubListObject *)operand1->data, operand2, operation);
    uVar5 = 1;
  LAB_80066b94:
    if (trueValue == 0)
    {
      uVar5 = uVar5 ^ 1;
    }
  }
  return uVar5;
}

void EVENT_DoStackOperationEquals(_PCodeStack *stack, long operation)

{
  u_char *puVar1;
  int iVar2;
  u_char *puVar3;
  long *plVar4;
  long *plVar5;
  long item;
  u_char uVar6;
  long lVar7;
  u_char uVar8;
  long lVar9;
  u_char uVar10;
  long local_80[8];
  u_char auStack96[2];
  int local_58;
  long local_54[7];
  u_char auStack56[2];
  u_char local_30[8];
  u_char auStack16[2];

  plVar5 = (long *)&local_58;
  iVar2 = stack->topOfStack + -1;
  plVar4 = &stack->topOfStack + iVar2 * 9 + 1;
  stack->topOfStack = iVar2;
  do
  {
    item = plVar4[1];
    lVar7 = plVar4[2];
    lVar9 = plVar4[3];
    *plVar5 = *plVar4;
    plVar5[1] = item;
    plVar5[2] = lVar7;
    plVar5[3] = lVar9;
    plVar4 = plVar4 + 4;
    plVar5 = plVar5 + 4;
  } while (plVar4 != &stack->topOfStack + iVar2 * 9 + 9);
  *plVar5 = *plVar4;
  plVar5 = (long *)local_80;
  iVar2 = stack->topOfStack + -1;
  plVar4 = &stack->topOfStack + iVar2 * 9 + 1;
  stack->topOfStack = iVar2;
  do
  {
    item = plVar4[1];
    lVar7 = plVar4[2];
    lVar9 = plVar4[3];
    *plVar5 = *plVar4;
    plVar5[1] = item;
    plVar5[2] = lVar7;
    plVar5[3] = lVar9;
    plVar4 = plVar4 + 4;
    plVar5 = plVar5 + 4;
  } while (plVar4 != &stack->topOfStack + iVar2 * 9 + 9);
  *plVar5 = *plVar4;
  if ((local_58 == 0x12) || (local_58 == 0x16))
  {
    puVar3 = local_30;
    puVar1 = (u_char *)local_80;
    do
    {
      uVar6 = puVar1[1];
      uVar8 = puVar1[2];
      uVar10 = puVar1[3];
      *puVar3 = *puVar1;
      puVar3[1] = uVar6;
      puVar3[2] = uVar8;
      puVar3[3] = uVar10;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar1 != auStack96);
    *puVar3 = *puVar1;
    puVar3 = (u_char *)local_80;
    puVar1 = (u_char *)&local_58;
    do
    {
      uVar6 = puVar1[1];
      uVar8 = puVar1[2];
      uVar10 = puVar1[3];
      *puVar3 = *puVar1;
      puVar3[1] = uVar6;
      puVar3[2] = uVar8;
      puVar3[3] = uVar10;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar1 != auStack56);
    *puVar3 = *puVar1;
    puVar3 = (u_char *)&local_58;
    puVar1 = local_30;
    do
    {
      uVar6 = puVar1[1];
      uVar8 = puVar1[2];
      uVar10 = puVar1[3];
      *puVar3 = *puVar1;
      puVar3[1] = uVar6;
      puVar3[2] = uVar8;
      puVar3[3] = uVar10;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (puVar1 != auStack16);
    *puVar3 = *puVar1;
  }
  item = EVENT_CompareListWithOperation(stack, (StackType *)local_80, (StackType *)&local_58, operation);
  EVENT_AddPlayerObjectToStack(stack, item, 0);
  return;
}

short *EVENT_ParseOperand2(_PCodeStack *stack, short *codeStream, long *operateOnStack)

{
  u_short uVar1;
  long operation;
  short *codeStream_00;

  uVar1 = *codeStream;
  codeStream_00 = codeStream + 1;
  MoveCodeStreamExtra = 0;
  *operateOnStack = 0;
  switch ((int)(((u_int)uVar1 - 1) * 0x10000) >> 0x10)
  {
  case 0:
    EVENT_AddCharPointerToStack(stack, (int)*codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 1:
    EVENT_ModifyObjectToStackWithAttribute(stack, (int)*codeStream_00, codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 2:
    goto switchD_80066e74_caseD_2;
  case 3:
    EVENT_DoStackOperationEquals(stack, 10);
    break;
  case 4:
    EventAbortedPosition = codeStream_00;
    *operateOnStack = 1;
    break;
  case 6:
  case 8:
  case 9:
    codeStream_00 = (short *)0x0;
    break;
  case 0xb:
    EVENT_AddPlayerObjectToStack(stack, (int)*codeStream_00, 0);
    codeStream_00 = codeStream + 2;
    break;
  case 0xc:
    EVENT_DoStackOperationEquals(stack, 1);
    break;
  case 0xd:
    EVENT_DoStackOperationEquals(stack, 2);
    break;
  case 0xe:
    EVENT_DoStackOperationEquals(stack, 3);
    break;
  case 0xf:
    EVENT_DoStackOperationEquals(stack, 4);
    break;
  case 0x10:
    EVENT_StackDuplicate(stack);
    EVENT_AddPlayerObjectToStack(stack, 1, 0);
    operation = 1;
    goto LAB_80066fb4;
  case 0x11:
    EVENT_StackDuplicate(stack);
    EVENT_AddPlayerObjectToStack(stack, 1, 0);
    operation = 2;
  LAB_80066fb4:
    EVENT_DoStackOperationEquals(stack, operation);
  switchD_80066e74_caseD_2:
    EVENT_DoStackMathOperation(stack, codeStream_00);
    break;
  case 0x12:
    EVENT_DoStackOperationEquals(stack, 6);
    break;
  case 0x13:
    EVENT_DoStackOperationEquals(stack, 8);
    break;
  case 0x14:
    EVENT_DoStackOperationEquals(stack, 7);
    break;
  case 0x15:
    EVENT_DoStackOperationEquals(stack, 9);
    break;
  case 0x16:
    EVENT_DoStackOperationEquals(stack, 0xb);
    break;
  case 0x17:
    EVENT_DoStackOperationEquals(stack, 5);
    break;
  case 0x1b:
    EVENT_AddGameObjectToStack(stack);
    break;
  case 0x1c:
    EVENT_AddObjectToStack(stack);
    break;
  case 0x1d:
    EVENT_AddNumberToStack(stack, (int)*codeStream_00);
    codeStream_00 = codeStream + 2;
    break;
  case 0x1e:
    if (currentActionScript != (ScriptPCode *)0x0)
    {
      currentActionScript->conditionBits = currentActionScript->conditionBits | 2;
    }
    break;
  case 0x1f:
    EVENT_DoStackOperationEquals(stack, 0xc);
  }
  return codeStream_00 + MoveCodeStreamExtra;
}

long EVENT_GetIntroValue(IntroObject *introObject)

{
  u_int uVar1;
  u_int uVar2;

  uVar2 = 0;
  uVar1 = 1;
  switch (introObject->attribute)
  {
  case 5:
  case 9:
  case 0xc:
  case 0x10:
  case 0x24:
  case 0x25:
  case 0x2b:
  case 0x7e:
  case 0x8f:
  case 0x90:
  case 0xa0:
    uVar2 = 0;
    break;
  case 0xb:
    uVar1 = 0;
  case 10:
    uVar2 = uVar1;
    uVar1 = introObject->intro->flags & 0x80;
    goto LAB_80067114;
  case 0x14:
  case 0x15:
    uVar2 = 0xffffffff;
    break;
  case 0x92:
  case 0xa6:
    uVar2 = 1;
    uVar1 = introObject->intro->flags & 8;
  LAB_80067114:
    if (uVar1 == 0)
    {
      uVar2 = uVar2 ^ 1;
    }
    break;
  case -1:
    uVar2 = 1;
  }
  return uVar2;
}

void EVENT_DoVMObjectAction(SubListObject *subListObject, StackType *operand2, _PCodeStack *stack,
                            short *codeStream)

{
  int iVar1;
  SubListObject *pSVar2;
  int iVar3;
  long local_48;
  _Instance *local_44;
  u_char local_40;

  iVar3 = 0;
  if (0 < subListObject->numberOfInstances)
  {
    do
    {
      local_48 = 2;
      local_44 = subListObject->instanceList[iVar3];
      local_40 = 0xffffffff;
      iVar1 = 0;
      pSVar2 = subListObject;
      if (0 < subListObject->numberOfAttributes)
      {
        do
        {
          EVENT_TransformConstrictAttribute((StackType *)&local_48, stack, pSVar2->attribute[0], (short *)0x0);
          iVar1 = iVar1 + 1;
          pSVar2 = (SubListObject *)&pSVar2->numberOfInstances;
        } while (iVar1 < subListObject->numberOfAttributes);
      }
      EVENT_ExecuteActionCommand((StackType *)&local_48, operand2, stack, codeStream);
      iVar3 = iVar3 + 1;
    } while (iVar3 < subListObject->numberOfInstances);
  }
  return;
}

long EVENT_GetVMObjectValue(InstanceObject *instanceObject)

{
  u_int uVar1;
  _Instance *Inst;
  int Query;
  u_long uVar2;

  Inst = instanceObject->instance;
  uVar2 = 0;
  switch (instanceObject->attribute)
  {
  case 5:
  case 9:
  case 0xc:
  case 0x20:
  case 0x36:
  case 0x37:
  case 0x5e:
  case 0x5f:
  case 0x7e:
    goto switchD_80067264_caseD_5;
  case 10:
  case 0x34:
    uVar2 = (u_long)((Inst->flags & 0x800U) != 0);
    break;
  case 0xb:
    uVar2 = (u_long)((Inst->flags & 0x800U) == 0);
    break;
  case 0x10:
    Query = 10;
    goto LAB_80067354;
  case 0x14:
    uVar2 = INSTANCE_Post(Inst, 0xb);
    uVar1 = uVar2 >> 1;
    goto LAB_80067298;
  case 0x15:
    uVar1 = INSTANCE_Post(Inst, 0xb);
  LAB_80067298:
    uVar2 = uVar1 & 1;
    Query = STREAM_IsMonster();
    if (Query != 0)
    {
    switchD_80067264_caseD_5:
      uVar2 = 0;
    }
    break;
  case 0x24:
    uVar2 = INSTANCE_Post(Inst, 5);
    uVar2 = (u_long)((uVar2 & 5) == 1);
    break;
  case 0x25:
    uVar2 = INSTANCE_Post(Inst, 5);
    uVar2 = (u_long)((uVar2 & 9) == 0);
    break;
  case 0x26:
    Query = 0x1b;
    goto LAB_80067354;
  case 0x27:
    Query = 0x1a;
  LAB_80067354:
    uVar2 = INSTANCE_Post(Inst, Query);
    break;
  case 0x35:
    uVar2 = (u_long)((Inst->flags2 & 0x20000000U) != 0);
    break;
  case 0x5b:
    uVar2 = (u_long)Inst->lightGroup;
    break;
  case 0x5c:
    uVar2 = (u_long)Inst->spectralLightGroup;
    break;
  case 0x67:
    uVar2 = (u_long)((Inst->flags & 0x400000U) == 0);
    break;
  case 0x8f:
    uVar2 = INSTANCE_Post(Inst, 5);
    uVar2 = uVar2 >> 2 & 1;
    break;
  case 0x90:
    uVar2 = INSTANCE_Post(Inst, 5);
    uVar2 = uVar2 >> 3 & 1;
    break;
  case -1:
    uVar2 = Inst->introUniqueID;
  }
  return uVar2;
}

long INSTANCE_GetSplineFrameNumber(InstanceSpline *instanceSpline)

{
  SplineDef *splineDef;
  int iVar1;

  splineDef = SCRIPT_GetPosSplineDef(instanceSpline->instance, instanceSpline->spline, instanceSpline->isParent,
                                     instanceSpline->isClass);
  iVar1 = EVENT_GetSplineFrameNumber(instanceSpline->instance, splineDef);
  return iVar1;
}

long EVENT_GetGameValue(InstanceSpline *instanceSpline)

{
  byte bVar1;
  short sVar2;
  Spline *pSVar3;
  _Instance *instance;
  u_int uVar4;

  instance = instanceSpline->instance;
  uVar4 = 0;
  switch (instanceSpline->attribute)
  {
  case 0xd:
  case 0x29:
    uVar4 = (u_int)((instance->flags & 0x2000000U) != 0);
    break;
  case 0xe:
    uVar4 = (u_int)((instance->flags & 0x2000000U) == 0);
    break;
  case 0xf:
  case 0x28:
    uVar4 = INSTANCE_GetSplineFrameNumber(instanceSpline);
    break;
  case 0x10:
    pSVar3 = instanceSpline->spline->positional;
    if (pSVar3 == (Spline *)0x0)
    {
      return 0;
    }
    bVar1 = pSVar3->flags;
    uVar4 = (u_int)bVar1 & 1;
    if ((bVar1 & 2) != 0)
    {
      uVar4 = 2;
    }
    if ((bVar1 & 4) == 0)
    {
      return uVar4;
    }
  case -1:
    uVar4 = 1;
    break;
  case 0x11:
    uVar4 = 1;
    if ((instance->flags & 0x1000000U) != 0)
    {
      uVar4 = 0xffffffff;
    }
    break;
  case 0x16:
    sVar2 = SCRIPTCountFramesInSpline(instance);
    uVar4 = SEXT24(sVar2);
  }
  return uVar4;
}

long EVENT_GetAnimateTextureValue(InstanceAnimateTexture *instanceAniTexture)

{
  u_int uVar1;
  AniTex *pAVar2;
  u_int uVar3;

  uVar3 = 0;
  uVar1 = 1;
  switch (instanceAniTexture->attribute)
  {
  case 0xd:
  case 0x29:
    uVar1 = 0;
  case 0xe:
    uVar3 = uVar1;
    if ((instanceAniTexture->instance->flags & 0x80U) == 0)
    {
      uVar3 = uVar3 ^ 1;
    }
    break;
  case 0xf:
  case 0x28:
    pAVar2 = instanceAniTexture->aniTextures;
    if (pAVar2 != (AniTex *)0x0)
    {

             (pAVar2->aniTexInfo).speed) % (pAVar2->aniTexInfo).numFrames;
    }
    uVar3 = 0;
    break;
  case -1:
  case 0x11:
    uVar3 = 1;
  }
  return uVar3;
}

long EVENT_GetSoundValue(InstanceAnimate *instanceAnimate)

{
  u_long uVar1;
  int Query;

  uVar1 = 0;
  switch (instanceAnimate->attribute)
  {
  case 0xd:
  case 0x29:
    uVar1 = 0;
    break;
  case 0xf:
  case 0x28:
    Query = 0x12;
    goto LAB_800675ec;
  case 0x1e:
    Query = 0x11;
  LAB_800675ec:
    uVar1 = INSTANCE_Post(instanceAnimate->instance, Query);
    break;
  case -1:
  case 0xe:
    uVar1 = 1;
  }
  return uVar1;
}

long EVENT_TransformObjectOnStack(_PCodeStack *stack, long item, short *codeStream)

{
  long lVar1;

  lVar1 = 0;
  if (stack->topOfStack != 0)
  {
    lVar1 = EVENT_TransformConstrictAttribute((StackType *)stack[-1].stack[stack->topOfStack + 0x1f].data, stack, item,
                                              codeStream);
  }
  return lVar1;
}

void FX_UpdateTexturePointers(EventPointers *events, long offset)

{
  _func_15 *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  EventPointers *pEVar7;
  int iVar8;

  if ((events != (EventPointers *)0x0) && (iVar8 = 0, pEVar7 = events, 0 < events->numPuzzles))
  {
    do
    {
      p_Var1 = (_func_15 *)0x0;
      if (pEVar7->eventInstances[0] != (_func_15 *)0x0)
      {
        p_Var1 = pEVar7->eventInstances[0] + offset;
      }
      pEVar7->eventInstances[0] = p_Var1;
      iVar3 = 0;
      if (*(int *)(p_Var1 + 0x10) != 0)
      {
        iVar3 = *(int *)(p_Var1 + 0x10) + offset;
      }
      iVar5 = 0;
      *(int *)(p_Var1 + 0x10) = iVar3;
      if (*(int *)(p_Var1 + 0x14) != 0)
      {
        iVar5 = *(int *)(p_Var1 + 0x14) + offset;
      }
      iVar3 = 0;
      *(int *)(p_Var1 + 0x14) = iVar5;
      if (*(int *)(p_Var1 + 0x18) != 0)
      {
        iVar3 = *(int *)(p_Var1 + 0x18) + offset;
      }
      iVar5 = 0;
      *(int *)(p_Var1 + 0x18) = iVar3;
      if (0 < *(short *)(p_Var1 + 2))
      {
        iVar3 = 0;
        do
        {
          iVar4 = *(int *)(iVar3 + *(int *)(p_Var1 + 0x10));
          iVar2 = 0;
          if (iVar4 != 0)
          {
            iVar2 = iVar4 + offset;
          }
          *(int *)(iVar3 + *(int *)(p_Var1 + 0x10)) = iVar2;
          psVar6 = *(short **)(iVar3 + *(int *)(p_Var1 + 0x10));
          if (*psVar6 == 2)
          {
            iVar2 = 0;
            if (*(int *)(psVar6 + 4) != 0)
            {
              iVar2 = *(int *)(psVar6 + 4) + offset;
            }
            *(int *)(psVar6 + 4) = iVar2;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar3 + 4;
        } while (iVar5 < *(short *)(p_Var1 + 2));
      }
      iVar3 = 0;
      if (p_Var1[4] != (_func_15)0x0)
      {
        iVar5 = 0;
        do
        {
          iVar2 = *(int *)(iVar5 + *(int *)(p_Var1 + 0x14));
          if (iVar2 != 0)
          {
            *(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) = iVar2 + offset;
            iVar4 = *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) + 4);
            iVar2 = 0;
            if (iVar4 != 0)
            {
              iVar2 = iVar4 + offset;
            }
            *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x14)) + 4) = iVar2;
          }
          iVar2 = *(int *)(iVar5 + *(int *)(p_Var1 + 0x18));
          if (iVar2 != 0)
          {
            *(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) = iVar2 + offset;
            iVar4 = *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) + 4);
            iVar2 = 0;
            if (iVar4 != 0)
            {
              iVar2 = iVar4 + offset;
            }
            *(int *)(*(int *)(iVar5 + *(int *)(p_Var1 + 0x18)) + 4) = iVar2;
          }
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 4;
        } while (iVar3 < (int)(u_int)(byte)p_Var1[4]);
      }
      iVar8 = iVar8 + 1;
      pEVar7 = (EventPointers *)pEVar7->eventInstances;
    } while (iVar8 < events->numPuzzles);
  }
  return;
}

void EVENT_SaveEventsFromLevel(long levelID, Level *level)

{
  bool bVar1;
  bool bVar2;
  short *psVar3;
  undefined *puVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  EventPointers *pEVar9;

  pEVar9 = level->PuzzleInstances;
  if ((pEVar9 != (EventPointers *)0x0) && (iVar8 = 0, 0 < pEVar9->numPuzzles))
  {
    do
    {
      bVar1 = false;
      psVar5 = (short *)pEVar9->eventInstances[iVar8];
      iVar6 = 0;
      psVar3 = psVar5;
      bVar2 = bVar1;
      do
      {
        if ((psVar3[3] != 0) && (bVar1 = true, 0xfe < (u_short)(psVar3[3] + 0x7fU)))
        {
          bVar2 = true;
        }
        iVar6 = iVar6 + 1;
        psVar3 = psVar3 + 1;
      } while (iVar6 < 5);
      SAVE_DeleteSavedEvent(levelID, (int)*psVar5);
      if (bVar1)
      {
        if (bVar2)
        {
          puVar4 = (undefined *)SAVE_GetSavedBlock(2, 0);
          iVar6 = 0;
          *puVar4 = 2;
          *(short *)(puVar4 + 2) = (short)levelID;
          *(short *)(puVar4 + 4) = *psVar5;
          do
          {
            psVar3 = psVar5 + 3;
            psVar5 = psVar5 + 1;
            iVar6 = iVar6 + 1;
            *(short *)(puVar4 + 6) = *psVar3;
            puVar4 = puVar4 + 2;
          } while (iVar6 < 5);
        }
        else
        {
          puVar4 = (undefined *)SAVE_GetSavedBlock(9, 0);
          *puVar4 = 9;
          *(short *)(puVar4 + 2) = (short)levelID;
          puVar4[4] = *(undefined *)psVar5;
          iVar6 = 0;
          do
          {
            iVar7 = iVar6 + 1;
            puVar4[iVar6 + 5] = *(undefined *)(psVar5 + 3);
            psVar5 = psVar5 + 1;
            iVar6 = iVar7;
          } while (iVar7 < 5);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < pEVar9->numPuzzles);
  }
  return;
}

void EVENT_LoadEventsForLevel(long levelID, Level *level)

{
  byte *pbVar1;
  SavedBasic *curSave;
  int iVar2;
  short *psVar3;
  EventPointers *pEVar4;
  SavedBasic *pSVar5;
  u_int uVar6;
  EventPointers *pEVar7;

  pEVar7 = level->PuzzleInstances;
  if (pEVar7 != (EventPointers *)0x0)
  {
    curSave = SAVE_GetSavedEvent(levelID, (SavedBasic *)0x0);
    while (curSave != (SavedBasic *)0x0)
    {
      if (pEVar7->numPuzzles != 0)
      {
        if (curSave->savedID == '\x02')
        {
          uVar6 = SEXT24((short)curSave[2]);
        }
        else
        {
          uVar6 = (u_int)curSave[2].savedID;
        }
        iVar2 = 0;
        pEVar4 = pEVar7;
        psVar3 = (short *)0x0;
        if (0 < pEVar7->numPuzzles)
        {
          do
          {
            psVar3 = (short *)pEVar4->eventInstances[0];
            iVar2 = iVar2 + 1;
            if ((int)*psVar3 == uVar6)
              break;
            pEVar4 = (EventPointers *)pEVar4->eventInstances;
            psVar3 = (short *)0x0;
          } while (iVar2 < pEVar7->numPuzzles);
        }
        if (psVar3 != (short *)0x0)
        {
          iVar2 = 0;
          pSVar5 = curSave;
          if (curSave->savedID == '\x02')
          {
            do
            {
              iVar2 = iVar2 + 1;
              *(SavedBasic *)(psVar3 + 3) = pSVar5[3];
              psVar3 = psVar3 + 1;
              pSVar5 = pSVar5 + 1;
            } while (iVar2 < 5);
          }
          else
          {
            do
            {
              pbVar1 = &curSave[2].shiftedSaveSize + iVar2;
              iVar2 = iVar2 + 1;
              psVar3[3] = (u_short)*pbVar1;
              psVar3 = psVar3 + 1;
            } while (iVar2 < 5);
          }
        }
      }
      curSave = SAVE_GetSavedEvent(levelID, curSave);
    }
  }
  return;
}

SavedBasic *EVENT_CreateSaveEvent(long levelID, long eventNumber)

{
  SavedBasic *pSVar1;
  SavedBasic *pSVar2;
  int iVar3;

  pSVar1 = (SavedBasic *)SAVE_GetSavedBlock(9, 0);
  if (pSVar1 != (SavedBasic *)0x0)
  {
    iVar3 = 4;
    pSVar2 = pSVar1 + 2;
    pSVar1->savedID = '\t';
    pSVar1[1] = SUB42(levelID, 0);
    pSVar1[2].savedID = (u_char)eventNumber;
    do
    {
      pSVar2[2].shiftedSaveSize = '\0';
      iVar3 = iVar3 + -1;
      pSVar2 = (SavedBasic *)&pSVar2[-1].shiftedSaveSize;
    } while (-1 < iVar3);
  }
  return pSVar1;
}

void EVENT_RemoveInstanceFromInstanceList(_Instance *instance)

{
  short **ppsVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;

  iVar7 = 0;
  iVar2 = 0;
  do
  {
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar2) == 2) &&
         (piVar6 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar2) + 0xdc),
          piVar6 != (int *)0x0)) &&
        (iVar2 = 0, piVar5 = piVar6, 0 < *piVar6))
    {
      do
      {
        ppsVar1 = *(short ***)(piVar5[1] + 0x10);
        iVar4 = 0;
        if (0 < *(short *)(piVar5[1] + 2))
        {
          do
          {
            psVar3 = *ppsVar1;
            if ((*psVar3 == 1) && (*(_Instance **)(psVar3 + 6) == instance))
            {
              *(u_char *)(psVar3 + 6) = 0;
              break;
            }
            iVar4 = iVar4 + 1;
            ppsVar1 = ppsVar1 + 1;
          } while (iVar4 < *(short *)(piVar5[1] + 2));
        }
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < *piVar6);
    }
    iVar7 = iVar7 + 1;
    iVar2 = iVar7 * 0x40;
    if (0xf < iVar7)
    {
      return;
    }
  } while (true);
}

void EVENT_UpdatePuzzleWithInstance(EventPointers *puzzle, _Instance *instance)

{
  short **ppsVar1;
  short *psVar2;
  int iVar3;
  EventPointers *pEVar4;
  int iVar5;

  iVar5 = 0;
  pEVar4 = puzzle;
  if (0 < puzzle->numPuzzles)
  {
    do
    {
      ppsVar1 = *(short ***)(pEVar4->eventInstances[0] + 0x10);
      iVar3 = 0;
      if (0 < *(short *)(pEVar4->eventInstances[0] + 2))
      {
        do
        {
          psVar2 = *ppsVar1;
          if ((*psVar2 == 1) && (instance->introUniqueID == *(int *)(psVar2 + 4)))
          {
            *(_Instance **)(psVar2 + 6) = instance;
            break;
          }
          iVar3 = iVar3 + 1;
          ppsVar1 = ppsVar1 + 1;
        } while (iVar3 < *(short *)(pEVar4->eventInstances[0] + 2));
      }
      iVar5 = iVar5 + 1;
      pEVar4 = (EventPointers *)pEVar4->eventInstances;
    } while (iVar5 < puzzle->numPuzzles);
  }
  return;
}

void EVENT_AddInstanceToInstanceList(_Instance *instance)

{
  _Terrain *p_Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  Level *pLVar5;
  int iVar6;

  iVar6 = 0;
  do
  {
    if (StreamTracker.StreamList[iVar6].used == 2)
    {
      pLVar5 = StreamTracker.StreamList[iVar6].level;
      if (pLVar5->PuzzleInstances != (EventPointers *)0x0)
      {
        EVENT_UpdatePuzzleWithInstance(pLVar5->PuzzleInstances, instance);
      }
      p_Var1 = pLVar5->terrain;
      iVar3 = 0;
      if (0 < p_Var1->numBSPTrees)
      {
        iVar4 = 0;
        do
        {
          iVar2 = (int)&p_Var1->BSPTreeArray->bspRoot + iVar4;
          if ((-1 < *(short *)(iVar2 + 0x1a)) && (*(int *)(iVar2 + 0x1c) == instance->introUniqueID))
          {
            *(_Instance **)(iVar2 + 0x20) = instance;
          }
          p_Var1 = pLVar5->terrain;
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x24;
        } while (iVar3 < p_Var1->numBSPTrees);
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  return;
}

_VMObject *EVENT_FindVMObject(_StreamUnit *stream, char *vmoName)

{
  int iVar1;
  int iVar2;
  Level *pLVar3;
  int iVar4;

  pLVar3 = stream->level;
  iVar4 = 0;
  if (0 < pLVar3->numVMObjects)
  {
    iVar2 = 0;
    do
    {
      iVar1 = strcpy(*(char **)((int)&pLVar3->vmobjectList->name + iVar2), vmoName);
      iVar4 = iVar4 + 1;
      if (iVar1 == 0)
      {
        return (_VMObject *)((int)&pLVar3->vmobjectList->flags + iVar2);
      }
      iVar2 = iVar2 + 0x3c;
    } while (iVar4 < pLVar3->numVMObjects);
  }
  return (_VMObject *)0x0;
}

void EVENT_FixPuzzlesForStream(_StreamUnit *stream)

{
  short sVar1;
  long *plVar2;
  int iVar3;
  _StreamUnit *stream_00;
  _Terrain *p_Var4;
  _MultiSignal *p_Var5;
  Intro *pIVar6;
  _SFXMkr *p_Var7;
  _VMObject *p_Var8;
  EventPointers *pEVar9;
  _Instance *instance;
  int iVar10;
  BSPTree *pBVar11;
  _Instance *p_Var12;
  EventInstanceObject *instanceObject;
  int iVar13;
  EventPointers *pEVar14;
  int iVar15;
  EventPointers *puzzle;
  int iVar16;

  puzzle = stream->level->PuzzleInstances;
  instance = (gameTrackerX.instanceList)->first;
  if (puzzle != (EventPointers *)0x0)
  {
    while (instance != (_Instance *)0x0)
    {
      p_Var12 = instance->next;
      EVENT_UpdatePuzzleWithInstance(puzzle, instance);
      instance = p_Var12;
    }
    iVar15 = 0;
    pEVar14 = puzzle;
    if (0 < puzzle->numPuzzles)
    {
      do
      {
        iVar16 = *(int *)(pEVar14->eventInstances[0] + 0x10);
        iVar13 = 0;
        if (0 < *(short *)(pEVar14->eventInstances[0] + 2))
        {
          iVar3 = 0;
          do
          {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar16);
            sVar1 = instanceObject->id;
            if (sVar1 == 5)
            {
              stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
              if (stream_00 != (_StreamUnit *)0x0)
              {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream_00;
              }
            }
            else
            {
              if (sVar1 == 3)
              {
                stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                if ((stream_00 != (_StreamUnit *)0x0) &&
                    (pEVar9 = stream_00->level->PuzzleInstances, pEVar9 != (EventPointers *)0x0))
                {
                  plVar2 = &pEVar9->numPuzzles;
                  iVar3 = 0;
                  if (0 < *plVar2)
                  {
                    do
                    {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar9->eventInstances[0] == instanceObject->flags)
                      {
                        *(_func_15 **)&instanceObject->introUniqueID = pEVar9->eventInstances[0];
                        break;
                      }
                      pEVar9 = (EventPointers *)pEVar9->eventInstances;
                    } while (iVar3 < *plVar2);
                  }
                }
              }
              else
              {
                if (sVar1 == 4)
                {
                  stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                  if (stream_00 != (_StreamUnit *)0x0)
                  {
                    p_Var4 = stream_00->level->terrain;
                    iVar3 = p_Var4->numBSPTrees;
                    iVar10 = 0;
                    if (0 < iVar3)
                    {
                      pBVar11 = p_Var4->BSPTreeArray;
                      do
                      {
                        iVar10 = iVar10 + 1;
                        if (pBVar11->ID == instanceObject->flags)
                        {
                          *(BSPTree **)&instanceObject->introUniqueID = pBVar11;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        pBVar11 = pBVar11 + 1;
                      } while (iVar10 < iVar3);
                    }
                  }
                }
                else
                {
                  if (sVar1 == 6)
                  {
                    stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                    if (stream_00 != (_StreamUnit *)0x0)
                    {
                      p_Var5 = EVENT_ResolveObjectSignal(stream_00, (int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var5;
                    }
                  }
                  else
                  {
                    if (sVar1 == 1)
                    {
                      pIVar6 = EVENT_ResolveSFXMarker(instanceObject);
                      if (pIVar6 == (Intro *)0x0)
                      {
                        stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID);
                        if ((stream_00 != (_StreamUnit *)0x0) &&
                            (p_Var7 = EVENT_ResolveObjectIntro(stream_00, instanceObject),
                             p_Var7 != (_SFXMkr *)0x0))
                        {
                          *(_SFXMkr **)&instanceObject->data = p_Var7;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else
                      {
                        *(Intro **)&instanceObject->data = pIVar6;
                      }
                    }
                    else
                    {
                      if ((sVar1 == 7) &&
                          (stream_00 = STREAM_GetStreamUnitWithID(instanceObject->unitID),
                           stream_00 != (_StreamUnit *)0x0))
                      {
                        p_Var8 = EVENT_FindVMObject(stream_00, (char *)&instanceObject->introUniqueID);
                        *(_VMObject **)(instanceObject + 1) = p_Var8;
                      }
                    }
                  }
                }
              }
            }
            iVar13 = iVar13 + 1;
            iVar3 = iVar13 * 4;
          } while (iVar13 < *(short *)(pEVar14->eventInstances[0] + 2));
        }
        iVar15 = iVar15 + 1;
        pEVar14 = (EventPointers *)pEVar14->eventInstances;
      } while (iVar15 < puzzle->numPuzzles);
    }
  }
  return;
}

void EVENT_AddStreamToInstanceList(_StreamUnit *stream)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  _Terrain *p_Var4;
  _MultiSignal *p_Var5;
  Intro *pIVar6;
  _SFXMkr *p_Var7;
  _VMObject *p_Var8;
  int iVar9;
  EventPointers *pEVar10;
  int iVar11;
  BSPTree *pBVar12;
  EventInstanceObject *instanceObject;
  int iVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;
  int iVar17;

  iVar16 = 0;
  iVar9 = 0;
  do
  {
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar9) == 2) &&
         (piVar15 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar9) + 0xdc),
          piVar15 != (int *)0x0)) &&
        (iVar9 = 0, piVar14 = piVar15, 0 < *piVar15))
    {
      do
      {
        iVar17 = *(int *)(piVar14[1] + 0x10);
        iVar13 = 0;
        if (0 < *(short *)(piVar14[1] + 2))
        {
          iVar3 = 0;
          do
          {
            instanceObject = *(EventInstanceObject **)(iVar3 + iVar17);
            sVar1 = instanceObject->id;
            if (sVar1 == 5)
            {
              if (instanceObject->unitID == stream->StreamUnitID)
              {
                *(_StreamUnit **)&instanceObject->introUniqueID = stream;
              }
            }
            else
            {
              if (sVar1 == 3)
              {
                if ((instanceObject->unitID == stream->StreamUnitID) &&
                    (pEVar10 = stream->level->PuzzleInstances, pEVar10 != (EventPointers *)0x0))
                {
                  piVar2 = &pEVar10->numPuzzles;
                  iVar3 = 0;
                  if (0 < *piVar2)
                  {
                    do
                    {
                      iVar3 = iVar3 + 1;
                      if (*(short *)pEVar10->eventInstances[0] == instanceObject->flags)
                      {
                        *(_func_15 **)&instanceObject->introUniqueID = pEVar10->eventInstances[0];
                        break;
                      }
                      pEVar10 = (EventPointers *)pEVar10->eventInstances;
                    } while (iVar3 < *piVar2);
                  }
                }
              }
              else
              {
                if (sVar1 == 4)
                {
                  if (instanceObject->unitID == stream->StreamUnitID)
                  {
                    p_Var4 = stream->level->terrain;
                    iVar3 = p_Var4->numBSPTrees;
                    iVar11 = 0;
                    if (0 < iVar3)
                    {
                      pBVar12 = p_Var4->BSPTreeArray;
                      do
                      {
                        iVar11 = iVar11 + 1;
                        if (pBVar12->ID == instanceObject->flags)
                        {
                          *(BSPTree **)&instanceObject->introUniqueID = pBVar12;
                          *(_StreamUnit **)&instanceObject->instance = stream;
                          break;
                        }
                        pBVar12 = pBVar12 + 1;
                      } while (iVar11 < iVar3);
                    }
                  }
                }
                else
                {
                  if (sVar1 == 6)
                  {
                    if (instanceObject->unitID == stream->StreamUnitID)
                    {
                      p_Var5 = EVENT_ResolveObjectSignal(stream, (int)instanceObject->flags);
                      *(_MultiSignal **)&instanceObject->introUniqueID = p_Var5;
                    }
                  }
                  else
                  {
                    if (sVar1 == 1)
                    {
                      pIVar6 = EVENT_ResolveSFXMarker(instanceObject);
                      if (pIVar6 == (Intro *)0x0)
                      {
                        p_Var7 = EVENT_ResolveObjectIntro(stream, instanceObject);
                        if (p_Var7 != (_SFXMkr *)0x0)
                        {
                          *(_SFXMkr **)&instanceObject->data = p_Var7;
                          instanceObject->flags = instanceObject->flags | 1;
                        }
                      }
                      else
                      {
                        *(Intro **)&instanceObject->data = pIVar6;
                      }
                    }
                    else
                    {
                      if ((sVar1 == 7) && (stream->StreamUnitID == instanceObject->unitID))
                      {
                        p_Var8 = EVENT_FindVMObject(stream, (char *)&instanceObject->introUniqueID);
                        *(_VMObject **)(instanceObject + 1) = p_Var8;
                      }
                    }
                  }
                }
              }
            }
            iVar13 = iVar13 + 1;
            iVar3 = iVar13 * 4;
          } while (iVar13 < *(short *)(piVar14[1] + 2));
        }
        iVar9 = iVar9 + 1;
        piVar14 = piVar14 + 1;
      } while (iVar9 < *piVar15);
    }
    iVar16 = iVar16 + 1;
    iVar9 = iVar16 * 0x40;
    if (0xf < iVar16)
    {
      EVENT_FixPuzzlesForStream(stream);
      return;
    }
  } while (true);
}

void STREAM_RemoveInstancesWithIDInInstanceList(_StreamUnit *stream)

{
  short sVar1;
  short **ppsVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  EventTimer *timer;

  iVar8 = 0;
  iVar3 = 0;
  do
  {
    if ((((*(short *)((int)&StreamTracker.StreamList[0].used + iVar3) == 2) &&
          ((_StreamUnit *)((int)&StreamTracker.StreamList[0].StreamUnitID + iVar3) != stream)) &&
         (piVar7 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar3) + 0xdc),
          piVar7 != (int *)0x0)) &&
        (iVar3 = 0, piVar6 = piVar7, 0 < *piVar7))
    {
      do
      {
        ppsVar2 = *(short ***)(piVar6[1] + 0x10);
        iVar5 = 0;
        if (0 < *(short *)(piVar6[1] + 2))
        {
          do
          {
            psVar4 = *ppsVar2;
            sVar1 = *psVar4;
            if ((sVar1 == 5) || (sVar1 == 3))
            {
            LAB_80068538:
              if (*(int *)(psVar4 + 2) == stream->StreamUnitID)
              {
                *(u_char *)(psVar4 + 4) = 0;
              }
            }
            else
            {
              if (sVar1 == 4)
              {
                if (*(int *)(psVar4 + 2) == stream->StreamUnitID)
                {
                  *(u_char *)(psVar4 + 4) = 0;
                  *(u_char *)(psVar4 + 6) = 0;
                }
              }
              else
              {
                if (sVar1 == 6)
                  goto LAB_80068538;
                if ((sVar1 == 1) && (*(int *)(psVar4 + 2) == stream->StreamUnitID))
                {
                  *(u_char *)(psVar4 + 8) = 0;
                }
              }
            }
            iVar5 = iVar5 + 1;
            ppsVar2 = ppsVar2 + 1;
          } while (iVar5 < *(short *)(piVar6[1] + 2));
        }
        iVar3 = iVar3 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar3 < *piVar7);
    }
    iVar8 = iVar8 + 1;
    iVar3 = iVar8 * 0x40;
    if (0xf < iVar8)
    {
      iVar3 = 0;
      timer = &eventTimerArray;
      do
      {
        if (((timer->flags & 1U) != 0) && ((Level *)timer->scriptPos == stream->level))
        {
          EVENT_RemoveTimer(timer);
        }
        iVar3 = iVar3 + 1;
        timer = (EventTimer *)&timer->nextEventIndex;
      } while (iVar3 < 0x18);
      return;
    }
  } while (true);
}

void OBTABLE_RelocateInstanceObject(Level *oldLevel, Level *newLevel, long sizeOfLevel)

{
  short sVar1;
  short **ppsVar2;
  int iVar3;
  ScriptPCode *pSVar4;
  int iVar5;
  Level *pLVar6;
  EventTimer *pEVar7;
  short *psVar8;
  long lVar9;
  int iVar10;
  Event *pEVar11;
  Level *pLVar12;
  Level *pLVar13;
  int *piVar14;
  int *piVar15;
  int iVar16;

  pLVar12 = (Level *)((int)newLevel - (int)oldLevel);
  iVar16 = 0;
  pLVar13 = (Level *)((int)&oldLevel->terrain + sizeOfLevel);
  iVar5 = 0;
  do
  {
    if (((*(short *)((int)&StreamTracker.StreamList[0].used + iVar5) == 2) &&
         (piVar15 = *(int **)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar5) + 0xdc),
          piVar15 != (int *)0x0)) &&
        (iVar5 = 0, piVar14 = piVar15, 0 < *piVar15))
    {
      do
      {
        ppsVar2 = *(short ***)(piVar14[1] + 0x10);
        iVar10 = 0;
        if (0 < *(short *)(piVar14[1] + 2))
        {
          do
          {
            psVar8 = *ppsVar2;
            sVar1 = *psVar8;
            if (((sVar1 == 3) || (sVar1 == 4)) || (sVar1 == 6))
            {
              pLVar6 = *(Level **)(psVar8 + 4);
              if ((oldLevel <= pLVar6) && (pLVar6 <= pLVar13))
              {
                iVar3 = 0;
                if (pLVar6 != (Level *)0x0)
                {
                  iVar3 = (int)pLVar6 + (int)pLVar12;
                }
                *(int *)(psVar8 + 4) = iVar3;
              }
            }
            else
            {
              if (sVar1 == 1)
              {
                pLVar6 = *(Level **)(psVar8 + 8);
                if ((oldLevel <= pLVar6) && (pLVar6 <= pLVar13))
                {
                  iVar3 = 0;
                  if (pLVar6 != (Level *)0x0)
                  {
                    iVar3 = (int)pLVar6 + (int)pLVar12;
                  }
                  *(int *)(psVar8 + 8) = iVar3;
                }
              }
              else
              {
                if (sVar1 == 7)
                {
                  pLVar6 = *(Level **)(psVar8 + 10);
                  if ((oldLevel <= pLVar6) && (pLVar6 <= pLVar13))
                  {
                    iVar3 = 0;
                    if (pLVar6 != (Level *)0x0)
                    {
                      iVar3 = (int)pLVar6 + (int)pLVar12;
                    }
                    *(int *)(psVar8 + 10) = iVar3;
                  }
                }
              }
            }
            iVar10 = iVar10 + 1;
            ppsVar2 = ppsVar2 + 1;
          } while (iVar10 < *(short *)(piVar14[1] + 2));
        }
        iVar5 = iVar5 + 1;
        piVar14 = piVar14 + 1;
      } while (iVar5 < *piVar15);
    }
    iVar16 = iVar16 + 1;
    iVar5 = iVar16 * 0x40;
  } while (iVar16 < 0x10);
  pEVar7 = &eventTimerArray;
  do
  {
    if (((pEVar7->flags & 1U) != 0) && ((Level *)pEVar7->scriptPos == oldLevel))
    {
      lVar9 = 0;
      if (pEVar7->time != 0)
      {
        lVar9 = (int)&pLVar12->terrain + pEVar7->time;
      }
      pEVar11 = (Event *)0x0;
      pEVar7->time = lVar9;
      if (pEVar7->event != (Event *)0x0)
      {
        pEVar11 = (Event *)((int)&pLVar12->terrain + (int)pEVar7->event);
      }
      pSVar4 = (ScriptPCode *)0x0;
      pEVar7->event = pEVar11;
      if (pEVar7->actionScript != (ScriptPCode *)0x0)
      {
        pSVar4 = (ScriptPCode *)((int)&pLVar12->terrain + (int)pEVar7->actionScript);
      }
      pEVar7->actionScript = pSVar4;
      *(Level **)&pEVar7->scriptPos = newLevel;
    }
    pEVar7 = (EventTimer *)&pEVar7->nextEventIndex;
  } while ((int)pEVar7 < -0x7ff2cf00);
  return;
}

void EVENT_PrintVars(void)

{
  return;
}

void EVENT_ExecuteActionCommand(StackType *operand1, StackType *operand2, _PCodeStack *stack, short *codeStream)

{
  long lVar1;
  int local_10;
  short asStack12[2];

  switch (operand1->id)
  {
  case 1:
    EVENT_DoAnimateAction((AreaObject *)operand1->data, operand2);
    break;
  case 2:
    EVENT_DoCameraAction((InstanceObject *)operand1->data, operand2, codeStream);
    break;
  case 3:
    EVENT_DoGameAction((GameObject *)operand1->data, operand2);
    break;
  case 4:
    EVENT_DoTGroupAction((IntroObject *)operand1->data, operand2);
    break;
  case 10:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2, &local_10, asStack12);
    if (local_10 == 0)
    {
      **(undefined2 **)operand1->data = (short)lVar1;
    }
    break;
  case 0xb:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2, &local_10, asStack12);
    if (local_10 == 0)
    {
      **(long **)operand1->data = lVar1;
    }
    break;
  case 0xf:
    EVENT_DoSoundMarkerAction((InstanceSpline *)operand1->data, operand2);
    break;
  case 0x11:
    EVENT_DoSubListAction((SignalObject *)operand1->data, operand2);
    break;
  case 0x13:
    EVENT_DoAreaAction((InstanceAnimate *)operand1->data, operand2);
    break;
  case 0x14:
    EVENT_DoInstanceAnimateTextureAction((InstanceAnimateTexture *)operand1->data, operand2);
    break;
  case 0x16:
    EVENT_DoVMObjectAction((SubListObject *)operand1->data, operand2, stack, codeStream);
    break;
  case 0x17:
    EVENT_DoSignalAction((TGroupObject *)operand1->data, operand2);
    break;
  case 0x19:
    EVENT_DoSplineAction((CameraObject *)operand1->data, operand2, codeStream);
    break;
  case 0x1a:
    EVENT_DoIntroAction((EventVmObject *)operand1->data, operand2);
    break;
  case 0x1b:
    if (*(short *)operand1->data == 1)
    {
      EVENT_DoObjectSoundAction((SoundObject *)operand1->data, operand2);
    }
    else
    {
      EVENT_DoAction((SoundObject *)operand1->data, operand2);
    }
    break;
  case 0x1c:
    lVar1 = EVENT_GetScalerValueFromOperand(operand2, &local_10, asStack12);
    if (local_10 == 0)
    {
      **(undefined **)operand1->data = (char)lVar1;
    }
  }
  return;
}

long EVENT_GetScalerValueFromOperand(StackType *operand, long *error, short *flags)

{
  long lVar1;
  u_int uVar2;

  *error = 0;
  *flags = 0;
  uVar2 = 0x7fff;
  switch (operand->id)
  {
  case 1:
    uVar2 = *(u_int *)(operand->data + 8);
    break;
  case 2:
    uVar2 = EVENT_GetVMObjectValue((InstanceObject *)operand->data);
    break;
  case 3:
    uVar2 = EVENT_SetSplineLoop((GameObject *)operand->data);
    break;
  case 4:
    uVar2 = EVENT_GetIntroValue((IntroObject *)operand->data);
    break;
  case 7:
    uVar2 = *(u_int *)operand->data;
    *flags = *(short *)(operand->data + 8);
    break;
  case 10:
    uVar2 = SEXT24(**(short **)operand->data);
    break;
  case 0xb:
    uVar2 = **(u_int **)operand->data;
    break;
  case 0xf:
    uVar2 = EVENT_GetGameValue((InstanceSpline *)operand->data);
    break;
  case 0x13:
    uVar2 = EVENT_GetSoundValue((InstanceAnimate *)operand->data);
    break;
  case 0x14:
    uVar2 = EVENT_GetAnimateTextureValue((InstanceAnimateTexture *)operand->data);
    break;
  case 0x17:
    uVar2 = EVENT_GetIntroValue((TGroupObject *)operand->data);
    break;
  case 0x18:
    uVar2 = (u_int)((int)*(short *)(*(int *)operand->data + 0x16c) + 1U < 3) ^ 1;
    break;
  case 0x1a:
    uVar2 = EVENT_GetInstanceValue((EventVmObject *)operand->data);
    break;
  case 0x1b:
    if (*(short *)operand->data != 1)
    {
      lVar1 = EVENT_GetTGroupValue((SoundObject *)operand->data);
      return lVar1;
    }
  case 0x15:
    uVar2 = 0;
    break;
  case 0x1c:
    uVar2 = (u_int) * *(byte **)operand->data;
  }
  return uVar2;
}

long EVENT_TransformConstrictAttribute(StackType *stackObject, _PCodeStack *stack, long item, short *codeStream)

{
  long lVar1;

  switch (stackObject->id)
  {
  case 1:
    lVar1 = EVENT_TransformRotation3dAttribute(stack, stackObject, item, codeStream);
    break;
  case 2:
    lVar1 = EVENT_TransformEventAttribute(stack, stackObject, item, codeStream);
    break;
  case 3:
    lVar1 = EVENT_TransformSavedEventAttribute(stack, stackObject, item, codeStream);
    break;
  case 4:
    lVar1 = EVENT_TransformInstanceAttribute(stack, stackObject, item);
    break;
  default:
    lVar1 = 0;
    break;
  case 6:
    EventAbortLine = 1;
    lVar1 = 1;
    break;
  case 9:
    lVar1 = EVENT_TransformListObjectAttribute(stack, stackObject, item, codeStream);
    break;
  case 0xe:
    lVar1 = EVENT_TransformTGroupAttribute(stack, stackObject, item, codeStream);
    break;
  case 0xf:
    lVar1 = EVENT_TransformSplineAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x10:
    lVar1 = EVENT_TransformIntroAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x11:
    lVar1 = EVENT_TransformCameraObjectAttribute(stack, stackObject, item);
    break;
  case 0x12:
    lVar1 = EVENT_TransformSoundObjectAttribute(stack, stackObject, item);
    break;
  case 0x13:
    lVar1 = 0;
    if (*(int *)(stackObject->data + 4) == -1)
    {
      *(long *)(stackObject->data + 4) = item;
      lVar1 = 1;
    }
    break;
  case 0x14:
    if (*(int *)(stackObject->data + 8) != -1)
    {
      return 0;
    }
  case 0x1a:
    *(long *)(stackObject->data + 8) = item;
    lVar1 = 1;
    break;
  case 0x15:
    lVar1 = EVENT_TransformIntroAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x16:
    lVar1 = EVENT_TransformGameAttribute(stack, stackObject, item);
    break;
  case 0x17:
    lVar1 = EVENT_TransformVector3dAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x18:
    lVar1 = EVENT_TransformSignalAttribute(stack, stackObject, item);
    break;
  case 0x19:
    lVar1 = EVENT_TransformAreaAttribute(stack, stackObject, item, codeStream);
    break;
  case 0x1b:
    lVar1 = EVENT_TransformSubListObjectAttribute(stack, (SoundObject *)stackObject->data, item, codeStream);
  }
  return lVar1;
}
