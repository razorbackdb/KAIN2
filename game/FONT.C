#include "THISDUST.H"
#include "FONT.H"

void FONT_MakeSpecialFogClut(int x, int y)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 local_30[15];
  undefined2 local_12;
  u_char local_10;
  undefined2 local_c;
  undefined2 local_a;

  iVar2 = 0xf;
  puVar1 = &local_12;
  do
  {
    *puVar1 = 0x4210;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  local_c = 0x10;
  local_a = 1;
  SpecialFogClut = (u_short)(y << 6) | (u_short)(x >> 4) & 0x3f;
  local_30[0] = 0;
  local_10._0_2_ = (undefined2)x;
  local_10._2_2_ = (undefined2)y;
  DrawSync(0);
  LoadImage(&local_10, local_30);
  DrawSync(0);
  return;
}

void EVENT_Init(void)

{
  long *addr;
  u_short local_10;
  u_short local_e[3];

  FONT_vramBlock = VRAM_CheckVramSlot((short *)&local_10, (short *)local_e, 0x10, 0x80, 3, -1);
  if (FONT_vramBlock != (_BlockVramEntry *)0x0)
  {
    addr = LOAD_ReadFileFromCD("\\kain2\\game\\font.tim", '\x05');
    LOAD_LoadToAddress(addr, (int)(short)local_10, (int)(short)local_e[0], (int)(short)local_10,
                       (int)(short)local_e[0] + 0x7e);
    MEMPACK_Init((char *)addr);
    fontTracker.sprite_sort_push = 0;
    fontTracker.font_tpage =
        (short)(local_e[0] & 0x100) >> 4 | (u_short)(((u_int)local_10 & 0x3ff) >> 6) |
        (u_short)(((u_int)local_e[0] & 0x200) << 2);
    fontTracker.font_clut = (local_e[0] + 0x7e) * 0x40 | (short)local_10 >> 4 & 0x3fU;
    fontTracker.font_vramX = local_10;
    fontTracker.font_vramY = local_e[0];
    fontTracker.font_vramV = local_e[0] & 0xff;
    fontTracker.font_vramU = (short)(((u_int)local_10 & 0x3f) << 2);
    FONT_MakeSpecialFogClut((int)(short)local_10, (int)(short)local_e[0] + 0x7f);
  }
  fontTracker.font_xpos = 10;
  fontTracker.font_ypos = 0x10;
  fontTracker.font_buffIndex = 0;
  fontTracker.sprite_sort_push = 0;
  fontTracker.color_global = '\0';
  fontTracker.color_local = '\0';
  return;
}

void FONT_ReloadFont(void)

{
  long *addr;

  addr = LOAD_ReadFileFromCD("\\kain2\\game\\font.tim", '\x05');
  LOAD_LoadToAddress(addr, (int)fontTracker.font_vramX, (int)fontTracker.font_vramY,
                     (int)fontTracker.font_vramX, (int)fontTracker.font_vramY + 0x7e);
  MEMPACK_Init((char *)addr);
  FONT_MakeSpecialFogClut((int)fontTracker.font_vramX, (int)fontTracker.font_vramY + 0x7f);
  return;
}

void FONT_DrawChar2D(FontChar *fontChar)

{
  fontTracker.color_local = fontChar->color;
  drawChar2DPoly(fontChar->c, (int)fontChar->x, (int)fontChar->y);
  return;
}

long FONT_Get2DImageIndex(u_char c)

{
  return (u_int)-2\'$&\x1a\x1b\x1c\x1d\x1e\x1f !\"#*$U.T0$456789:;<=>?@ABCDEFGHIJKLMN$OR$$"
      [c];
}

void FONT_DrawChar(long fpi, long x, long y)

{
  char cVar1;
  char cVar2;
  short sVar3;
  u_long **ppuVar4;
  u_int uVar5;
  short sVar6;
  u_long *puVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  short sVar13;
  short sVar14;

  ppuVar4 = gameTrackerX.drawOT;
  cVar11 = (&fontPos)[fpi].x;
  if (cVar11 < '\0')
  {
    cVar11 = -cVar11;
  }
  cVar10 = (&fontPos)[fpi].y;
  if (cVar10 < '\0')
  {
    cVar10 = -cVar10;
  }
  cVar1 = (&fontPos)[fpi].w;
  sVar14 = (short)cVar1;
  cVar2 = (&fontPos)[fpi].h;
  sVar6 = (short)cVar2;
  cVar11 = cVar11 + (char)fontTracker.font_vramU;
  cVar10 = cVar10 + (char)fontTracker.font_vramV;
  if (cVar1 < '\0')
  {
    sVar14 = -(short)cVar1;
  }
  cVar12 = cVar11 + (char)sVar14;
  if (cVar2 < '\0')
  {
    sVar6 = -(short)cVar2;
  }
  cVar8 = cVar10 + (char)sVar6;
  sVar3 = (short)x;
  sVar6 = (short)y - (sVar6 + -0xc);
  puVar7 = (gameTrackerX.primPool)->nextPrim;
  sVar13 = (short)y + 0xc;
  cVar9 = cVar10;
  if (cVar2 < '\0')
  {
    cVar9 = cVar8;
    cVar8 = cVar10;
  }
  cVar10 = cVar11;
  if (cVar1 < '\0')
  {
    cVar10 = cVar12;
    cVar12 = cVar11;
  }
  *(undefined *)((int)puVar7 + 3) = 9;
  *(undefined *)((int)puVar7 + 7) = 0x2c;
  if (fontTracker.color_local == '\0')
  {
    *(undefined *)((int)puVar7 + 7) = 0x2d;
  }
  else
  {
    uVar5 = (u_int)(byte)fontTracker.color_local;
    *(undefined *)((int)puVar7 + 7) = 0x2c;
    *(undefined *)(puVar7 + 1) = *(undefined *)&(&the_font_color_table)[uVar5].r;
    *(undefined *)((int)puVar7 + 5) = *(undefined *)&(&the_font_color_table)[uVar5].g;
    *(undefined *)((int)puVar7 + 6) = *(undefined *)&(&the_font_color_table)[uVar5].b;
  }
  *(char *)(puVar7 + 3) = cVar10;
  *(char *)((int)puVar7 + 0xd) = cVar9;
  *(char *)(puVar7 + 5) = cVar12;
  *(char *)((int)puVar7 + 0x15) = cVar9;
  *(char *)(puVar7 + 7) = cVar10;
  *(char *)((int)puVar7 + 0x1d) = cVar8;
  *(char *)(puVar7 + 9) = cVar12;
  *(char *)((int)puVar7 + 0x25) = cVar8;
  *(short *)(puVar7 + 2) = sVar3;
  *(short *)((int)puVar7 + 10) = sVar6;
  *(short *)(puVar7 + 4) = sVar3 + sVar14;
  *(short *)((int)puVar7 + 0x12) = sVar6;
  *(short *)(puVar7 + 6) = sVar3;
  *(short *)((int)puVar7 + 0x1a) = sVar13;
  *(short *)(puVar7 + 8) = sVar3 + sVar14;
  *(short *)((int)puVar7 + 0x22) = sVar13;
  *(byte *)((int)puVar7 + 7) = *(byte *)((int)puVar7 + 7) & 0xfd;
  *(short *)((int)puVar7 + 0x16) = fontTracker.font_tpage;
  *(short *)((int)puVar7 + 0xe) = fontTracker.font_clut;
  *puVar7 = (u_int)*ppuVar4 & 0xffffff | 0x9000000;
  *ppuVar4 = (u_long *)((u_int)puVar7 & 0xffffff);
  (gameTrackerX.primPool)->nextPrim = puVar7 + 10;
  return;
}

void drawChar2DPoly(u_char c, long x, long y)

{
  long y_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int fpi;
  int iVar5;
  int fpi_00;
  int fpi_01;

  if ((gameTrackerX.primPool)->nextPrim <= (gameTrackerX.primPool)->lastPrim + -0xc)
  {
    y_00 = FONT_Get2DImageIndex(c);
    fpi_01 = y_00 * 3;
    fpi = (int)""[fpi_01];
    fpi_00 = (int)(&CHAR_FFh_800c8d81)[fpi_01];
    fpi_01 = (int)(&CHAR_FFh_800c8d82)[fpi_01];
    if (fpi < 0)
    {
      iVar1 = 8;
    }
    else
    {
      iVar1 = (int)(&fontPos)[fpi].w;
      if (iVar1 < 0)
      {
        iVar1 = -iVar1;
      }
    }
    iVar2 = iVar1;
    if ((-1 < fpi_00) && (iVar2 = (int)(&fontPos)[fpi_00].w, iVar2 < 0))
    {
      iVar2 = -iVar2;
    }
    iVar3 = iVar1;
    if ((-1 < fpi_01) && (iVar3 = (int)(&fontPos)[fpi_01].w, iVar3 < 0))
    {
      iVar3 = -iVar3;
    }
    iVar5 = iVar3;
    if (iVar2 < iVar1)
    {
      if (iVar3 < iVar1)
      {
        iVar5 = iVar1;
      }
    }
    else
    {
      if (iVar3 < iVar2)
      {
        iVar5 = iVar2;
      }
    }
    if (fpi < 0)
    {
      iVar4 = 0xc;
    }
    else
    {
      iVar4 = (int)(&fontPos)[fpi].h;
      if (iVar4 < 0)
      {
        iVar4 = -iVar4;
      }
    }
    if (-1 < fpi)
    {
 2,y);
    }
    y_00 = y;
    if (c == 'A')
    {
      y_00 = y + 2;
    }
    if (c == '\'')
    {
      y = y + 3;
    }
    if (-1 < fpi_00)
    {
 2,y_00);
    }
    if (-1 < fpi_01)
    {
 2,(y - iVar4) + -1);
    }
  }
  return;
}

long FONT_CharSpacing(char c, long fontXSize)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;

  if ((c != ' ') && (lVar2 = FONT_Get2DImageIndex(c), lVar2 != -1))
  {
    iVar1 = lVar2 * 3;
    iVar3 = (int)""[iVar1];
    iVar5 = (int)(&fontPos)[iVar3].w;
    if (iVar5 < 0)
    {
      iVar5 = -iVar5;
    }
    if ((&fontPos)[iVar3].x < '\0')
    {
      iVar5 = (int)(&fontPos)[iVar3].h;
    }
    iVar3 = 8;
    if (-1 < (int)((u_int)(byte) ""[iVar1] << 0x18))
    {
      iVar3 = iVar5;
    }
    iVar5 = (int)(&fontPos)[(int)(&CHAR_FFh_800c8d81)[iVar1]].w;
    if (iVar5 < 0)
    {
      iVar5 = -iVar5;
    }
    iVar6 = iVar3;
    if (-1 < (int)(&CHAR_FFh_800c8d81)[iVar1])
    {
      iVar6 = iVar5;
    }
    iVar5 = (int)(&fontPos)[(int)(&CHAR_FFh_800c8d82)[iVar1]].w;
    if (iVar5 < 0)
    {
      iVar5 = -iVar5;
    }
    iVar4 = iVar3;
    if (-1 < (int)(&CHAR_FFh_800c8d82)[iVar1])
    {
      iVar4 = iVar5;
    }
    if (iVar6 < iVar3)
    {
      iVar6 = iVar3;
    }
    fontXSize = iVar4 + 1;
    if (iVar4 < iVar6)
    {
      fontXSize = iVar6 + 1;
    }
  }
  return fontXSize;
}

void FONT_AddCharToBuffer(char c, long x, long y)

{
  long lVar1;

  lVar1 = fontTracker.font_buffIndex;
  if (fontTracker.font_buffIndex < 0xff)
  {
    if (c == '@')
    {
      fontTracker.font_buffer[fontTracker.font_buffIndex].x = (u_short)x & 0xff;
      fontTracker.font_buffer[lVar1].y = (u_short)y & 0xff;
    }
    else
    {
      fontTracker.font_buffer[fontTracker.font_buffIndex].x = (u_short)x;
      fontTracker.font_buffer[lVar1].y = (u_short)y;
    }
    fontTracker.font_buffer[lVar1].c = c;
    fontTracker.font_buffIndex = fontTracker.font_buffIndex + 1;
    fontTracker.font_buffer[lVar1].color = fontTracker.color_global;
  }
  return;
}

void FONT_Print(char *fmt)

{
  byte bVar1;
  char *pcVar2;
  undefined local_res4[12];

  vsprintf(&fp_str, fmt, local_res4);
  pcVar2 = &fp_str;
  bVar1 = fp_str;
  while (bVar1 != 0)
  {
    if ((u_int)(byte)*pcVar2 - 0x41 < 0x1a)
    {
      *pcVar2 = *pcVar2 + 0x20;
    }
    pcVar2 = (char *)((byte *)pcVar2 + 1);
    bVar1 = *pcVar2;
  }
  FONT_VaReallyPrint(&fp_str, local_res4);
  return;
}

void FONT_Print2(char *fmt)

{
  undefined local_res4[12];

  vsprintf(&fp_str, fmt, local_res4);
  FONT_VaReallyPrint(&fp_str, local_res4);
  return;
}

int FONT_GetStringWidth(char *str)

{
  size_t sVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  int iVar5;

  sVar1 = strlen(str);
  iVar4 = 0;
  iVar5 = 0;
  pcVar2 = str;
  if (0 < (int)sVar1)
  {
    do
    {
      iVar4 = iVar4 + 1;
      lVar3 = FONT_CharSpacing(*pcVar2, 8);
      iVar5 = iVar5 + lVar3;
      pcVar2 = str + iVar4;
    } while (iVar4 < (int)sVar1);
  }
  return iVar5;
}

void FONT_Flush(void)

{
  FontTracker *fontChar;
  long lVar1;

  fontTracker.font_xpos = 10;
  fontTracker.font_ypos = 0x10;
  if (fontTracker.font_buffIndex != 0)
  {
    fontChar = &fontTracker;
    lVar1 = fontTracker.font_buffIndex;
    do
    {
      if ((*(char *)fontChar->font_buffer != ' ') && (*(char *)fontChar->font_buffer != '@'))
      {
        FONT_DrawChar2D((FontChar *)fontChar);
      }
      lVar1 = lVar1 + -1;
      fontChar = (FontTracker *)(fontChar->font_buffer + 1);
    } while (lVar1 != 0);
    fontTracker.font_buffIndex = 0;
  }
  return;
}

void FONT_SetCursor(short x, short y)

{
  fontTracker.font_xpos = (int)x;
  fontTracker.font_ypos = (int)y;
  return;
}

void FONT_VaReallyPrint(char *fmt, void *ap)

{
  byte bVar1;
  byte bVar2;
  long lVar3;

  bVar1 = *fmt;
  do
  {
    if (bVar1 == 0)
    {
      return;
    }
    if (bVar1 == 10)
    {
      fontTracker.font_ypos = fontTracker.font_ypos + 0xc;
      fontTracker.font_xpos = (u_int)bVar1;
    LAB_8002d650:
      fmt = (char *)((byte *)fmt + 1);
    }
    else
    {
      if (bVar1 != 0x40)
      {
        if (bVar1 == 0x24)
        {
          fontTracker.font_xpos = 10;
          fontTracker.font_ypos = 0x10;
        }
        else
        {
          if (bVar1 == 0xd)
          {
            fontTracker.font_xpos = 10;
          }
          else
          {
            if (bVar1 == 9)
            {
              fontTracker.font_xpos = fontTracker.font_xpos + 0x20;
            }
            else
            {
              if ((bVar1 == 0x20) || (bVar1 == 0x5f))
              {
                fontTracker.font_xpos = fontTracker.font_xpos + 8;
              }
              else
              {
                FONT_AddCharToBuffer(*fmt, fontTracker.font_xpos, fontTracker.font_ypos);
                lVar3 = FONT_CharSpacing(*fmt, 8);
                fontTracker.font_xpos = fontTracker.font_xpos + lVar3;
              }
            }
          }
        }
        goto LAB_8002d650;
      }
      bVar1 = ((byte *)fmt)[1];
      bVar2 = ((byte *)fmt)[2];
      FONT_AddCharToBuffer('@', fontTracker.font_xpos, fontTracker.font_ypos);
      FONT_AddCharToBuffer('@', (u_int)bVar2 - 0x40 & 0xff, (u_int)bVar1 - 0x40 & 0xff);
      fmt = (char *)((byte *)fmt + 3);
    }
    bVar1 = *fmt;
  } while (true);
}

void FONT_FontPrintCentered(char *text, long y)

{
  int iVar1;

  iVar1 = FONT_GetStringWidth(text);
  FONT_SetCursor((short)((u_int)((0x100 - (iVar1 >> 1)) * 0x10000) >> 0x10), (short)y);
  FONT_Print2(text);
  return;
}

void FONT_SetColorIndex(int color)

{
  fontTracker.color_global = (char)color;
  return;
}
