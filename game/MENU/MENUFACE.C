#include "THISDUST.H"
#include "MENUFACE.H"

void menu_initialize(void)

{
  u_int uVar1;
  u_int uVar2;
  menuface_t *pmVar3;
  int iVar4;
  int iVar5;
  char acStack168[128];

  if (hack_initialized == 0)
  {
    FaceButtons = (_ButtonTexture *)MEMPACK_Malloc(0x180, '-');
    iVar4 = 0;
    if (FaceButtons != (_ButtonTexture *)0x0)
    {
      pmVar3 = &MenuFaces;
      iVar5 = 0;
      do
      {
        uVar2 = 0;
        pmVar3->curFrame = -1;
        pmVar3->transitionDir = '\0';
        pmVar3->loaded = '\0';
        do
        {
          sprintf(acStack168, "\\kain2\\game\\psx\\frontend\\%s_%s.tim");
          DRAW_LoadButtonByName(acStack168, FaceButtons + iVar5 + uVar2);
          uVar1 = uVar2 & 0x1f;
          uVar2 = uVar2 + 1;
          pmVar3->loaded = pmVar3->loaded | (byte)(1 << uVar1);
        } while ((int)uVar2 < 3);
        pmVar3 = pmVar3 + 1;
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 3;
      } while (iVar4 < 8);
      hack_initialized = 1;
    }
  }
  return;
}

void menuface_terminate(void)

{
  u_int uVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;

  if (hack_initialized != 0)
  {
    iVar4 = 0;
    pmVar3 = &MenuFaces;
    iVar2 = 0;
    do
    {
      uVar1 = 0;
      do
      {
        if (((int)(u_int)pmVar3->loaded >> (uVar1 & 0x1f) & 1U) != 0)
        {
          DRAW_LoadButton(FaceButtons + iVar2 + uVar1);
        }
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < 3);
      pmVar3 = pmVar3 + 1;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 3;
    } while (iVar4 < 8);
    MEMPACK_Init((char *)FaceButtons);
    hack_initialized = 0;
  }
  return;
}

void MENUFACE_ChangeStateRandomly(int index)

{
  u_char uVar1;
  u_char uVar2;
  int iVar3;
  u_char *puVar4;
  menuface_t *pmVar5;

  if (hack_initialized != 0)
  {
    pmVar5 = &MenuFaces;
    puVar4 = &MenuFaces.delay;
    do
    {
      uVar1 = *puVar4 + -1;
      if (*puVar4 == '\0')
      {
        if (puVar4[-1] == '\0')
        {
          iVar3 = rand();
 0x96) * 0x96)
 {
   if (puVar4[-2] == -1)
   {
     puVar4[-1] = '\x01';
   }
   else
   {
     puVar4[-1] = -1;
   }
 }
        }
        else
        {
          uVar2 = puVar4[-2] + puVar4[-1];
          puVar4[-2] = uVar2;
          uVar1 = 'd';
          if (((int)(char)uVar2 == (u_int)puVar4[-3] * 3 + -1) || ((int)(char)uVar2 == -1))
          {
            puVar4[-1] = '\0';
            goto LAB_800b80ec;
          }
        }
      }
      else
      {
      LAB_800b80ec:
        *puVar4 = uVar1;
      }
      pmVar5 = pmVar5 + 1;
      puVar4 = puVar4 + 0xc;
    } while (pmVar5 < &hack_initialized);
  }
  return;
}

void MENUFACE_RefreshFaces(void)

{
  short *psVar1;
  int iVar2;
  menuface_t *pmVar3;
  int iVar4;

  if (hack_initialized != 0)
  {
    iVar4 = 0;
    pmVar3 = &MenuFaces;
    psVar1 = &MenuFaces.y;
    iVar2 = 0;
    do
    {
      if (-1 < (int)*(char *)((int)psVar1 + 5))
      {
        DRAW_DrawButton(FaceButtons +
                            (int)(u_int) * (byte *)(psVar1 + 2),
                        pmVar3->x, *psVar1, gameTrackerX.drawOT + 1);
      }
      iVar2 = iVar2 + 3;
      iVar4 = iVar4 + 1;
      psVar1 = psVar1 + 6;
      pmVar3 = pmVar3 + 1;
    } while (iVar4 < 8);
  }
  return;
}
