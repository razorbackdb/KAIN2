#include "THISDUST.H"
#include "PLANPOOL.H"

int PLANPOOL_NumNodesInPlan(PlanningNode *goalNode, PlanningNode *planningPool)

{
  u_short uVar1;
  int iVar2;

  uVar1 = goalNode->parent;
  iVar2 = 0;
  while (goalNode != planningPool + uVar1)
  {
    goalNode = planningPool + goalNode->parent;
    uVar1 = goalNode->parent;
    iVar2 = iVar2 + 1;
  }
  return iVar2 + 1;
}

int PLANPOOL_CountBitsSetInLong(long mylong)

{
  int iVar1;

  iVar1 = 0;
  if (mylong != 0)
  {
    do
    {
      mylong = mylong & mylong - 1U;
      iVar1 = iVar1 + 1;
    } while (mylong != 0);
  }
  return iVar1;
}

int PLANPOOL_NumConnectionsExaminedForNode(PlanningNode *node)

{
  int iVar1;

  iVar1 = PLANPOOL_CountBitsSetInLong(node->connectionStatus);
  return iVar1;
}

int PLANPOOL_NumConnectionsForNode(PlanningNode *node)

{
  int iVar1;

  iVar1 = PLANPOOL_CountBitsSetInLong(node->connections);
  return iVar1;
}

PlanningNode *PLANPOOL_GetClosestNode(PlanningNode *planningPool, char nodeSource)

{
  int iVar1;

  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0)
  {
    do
    {
      iVar1 = iVar1 + 1;
      if (((u_int)planningPool->nodeType & 7) == (u_int)(byte)nodeSource)
      {
        return planningPool;
      }
      planningPool = planningPool + 1;
    } while (iVar1 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return (PlanningNode *)0x0;
}

int PLANPOOL_NumberOfNodesOfType(PlanningNode *planningPool, char nodeType)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0)
  {
    do
    {
      if ((u_int)planningPool->nodeType == (u_int)(byte)nodeType)
      {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return iVar1;
}

int PLANPOOL_NumberOfNodesOfSource(PlanningNode *planningPool, char nodeSource)

{
  int iVar1;
  int iVar2;

  iVar2 = 0;
  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0)
  {
    do
    {
      if (((u_int)planningPool->nodeType & 7) == (u_int)(byte)nodeSource)
      {
        iVar1 = iVar1 + 1;
      }
      iVar2 = iVar2 + 1;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return iVar1;
}

PlanningNode *PLANPOOL_GetNodeWithID(PlanningNode *planningPool, short type, short id)

{
  int iVar1;

  iVar1 = 0;
  if (*(byte *)(poolManagementData + 1) != 0)
  {
    do
    {
      if (((u_int)planningPool->nodeType == (int)type) && ((u_int)planningPool->id == (int)id))
      {
        return planningPool;
      }
      iVar1 = iVar1 + 1;
      planningPool = planningPool + 1;
    } while (iVar1 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return (PlanningNode *)0x0;
}

PlanningNode *PLANPOOL_GetFirstNodeOfSource(_Position *currentPos, PlanningNode *planningPool)

{
  long lVar1;
  int iVar2;
  int iVar3;
  PlanningNode *pPVar4;

  iVar3 = 0;
  pPVar4 = (PlanningNode *)0x0;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      lVar1 = MATH3D_LengthXYZ((int)currentPos->x - (int)(planningPool->pos).x,
                               (int)currentPos->y - (int)(planningPool->pos).y);
      if (lVar1 < 0xb)
      {
        iVar2 = (int)currentPos->z - (int)(planningPool->pos).z;
        if (iVar2 < 0)
        {
          iVar2 = -iVar2;
        }
        if (iVar2 != -1)
        {
          pPVar4 = planningPool;
        }
      }
      iVar3 = iVar3 + 1;
      planningPool = planningPool + 1;
    } while (iVar3 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return pPVar4;
}

PlanningNode *
PLANPOOL_GetNodeByPosition(_Position *pos, PlanningNode *planningPool, char distanceType)

{
  long lVar1;
  int iVar2;
  PlanningNode *pPVar3;
  int iVar4;

  iVar4 = 0x7fffffff;
  iVar2 = 0;
  pPVar3 = (PlanningNode *)0x0;
  if (*(char *)(poolManagementData + 1) != '\0')
  {
    do
    {
      if (distanceType == '\0')
      {
        lVar1 = MATH3D_LengthXYZ((int)pos->x - (int)(planningPool->pos).x,
                                 (int)pos->y - (int)(planningPool->pos).y);
      }
      else
      {
        lVar1 = MATH3D_LengthXY((int)pos->x - (int)(planningPool->pos).x,
                                (int)pos->y - (int)(planningPool->pos).y,
                                (int)pos->z - (int)(planningPool->pos).z);
      }
      if (lVar1 < iVar4)
      {
        pPVar3 = planningPool;
        iVar4 = lVar1;
      }
      iVar2 = iVar2 + 1;
      planningPool = planningPool + 1;
    } while (iVar2 < (int)(u_int) * (byte *)(poolManagementData + 1));
  }
  return pPVar3;
}

int PLANPOOL_AppropriatePair(PlanningNode *node1, PlanningNode *node2)

{
  long lVar1;
  u_int uVar2;
  int iVar3;
  u_int uVar4;
  int iVar5;
  PlanningNode *pPVar6;
  u_int uVar7;
  u_int uVar8;
  u_int uVar9;

  uVar9 = (u_int)(node1->nodeType >> 3) & 3;
  uVar7 = (u_int)(node2->nodeType >> 3) & 3;
  uVar4 = (u_int)node1->nodeType & 7;
  uVar8 = (u_int)node2->nodeType & 7;
  pPVar6 = node2;
  if (uVar7 < uVar9)
  {
    uVar9 = uVar9 ^ uVar7;
    uVar7 = uVar7 ^ uVar9;
    uVar9 = uVar9 ^ uVar7;
    pPVar6 = node1;
    node1 = node2;
  }
  uVar2 = uVar4 ^ uVar8;
  if (uVar8 < uVar4)
  {
    uVar8 = uVar8 ^ uVar2;
    uVar4 = uVar2 ^ uVar8;
  }
  uVar7 = uVar7 | uVar9 << 8;
  uVar8 = uVar8 | uVar4 << 8;
  if (uVar7 == 3)
  {
    if (uVar8 != 0x404)
    {
      return 0;
    }
    return 1;
  }
  if (uVar7 < 4)
  {
    if (uVar7 != 1)
    {
      if (uVar7 == 2)
      {
        return 0;
      }
      return 1;
    }
  }
  else
  {
    if (uVar7 == 0x103)
    {
      return 0;
    }
    if (0x103 < uVar7)
    {
      if (uVar7 == 0x203)
      {
        return 0;
      }
      return 1;
    }
    if (uVar7 != 0x102)
    {
      return 1;
    }
  }
  if (uVar8 == 0x404)
  {
    iVar3 = (int)(node1->pos).z;
    iVar5 = (int)(pPVar6->pos).z;
    if (((iVar3 < iVar5) && (iVar5 < iVar3 + 800)) &&
        (lVar1 = MATH3D_LengthXYZ((int)(node1->pos).x - (int)(pPVar6->pos).x,
                                  (int)(node1->pos).y - (int)(pPVar6->pos).y),
         lVar1 < 0x321))
    {
      return 1;
    }
  }
  return 0;
}

int PLANPOOL_AreTwoNodesConnected(PlanningNode *node1, PlanningNode *node2, PlanningNode *planningPool)

{
  int iVar1;
  u_int uVar2;

  uVar2 = 1 << ((int)((int)node2 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  iVar1 = 0;
  if (((node1->connectionStatus & uVar2) != 0) && (iVar1 = 1, (node1->connections & uVar2) == 0))
  {
    iVar1 = 0;
  }
  return iVar1;
}

void PLANPOOL_MarkTwoNodesAsConnected(PlanningNode *node1, PlanningNode *node2, PlanningNode *planningPool)

{
  int iVar1;
  long lVar2;
  u_int uVar3;
  undefined2 uVar4;
  u_int uVar5;
  u_int uVar6;

  uVar6 = (int)((int)node1 - (int)planningPool) * -0x49249249 >> 2;
  uVar5 = (int)((int)node2 - (int)planningPool) * -0x49249249 >> 2;
  lVar2 = MATH3D_DistanceBetweenPositions((_Position *)node1, (_Position *)node2);
  iVar1 = poolManagementData;
  if (lVar2 < 0)
  {
    lVar2 = 0;
  }
  uVar4 = (undefined2)lVar2;
  if (0x10000 < lVar2)
  {
    uVar4 = 0;
  }
  *(undefined2 *)(uVar5 * 2 + uVar6 * 0x40 + *(int *)(poolManagementData + 0x10)) = uVar4;
  *(undefined2 *)(uVar6 * 2 + uVar5 * 0x40 + *(int *)(iVar1 + 0x10)) = uVar4;
  uVar3 = 1 << (uVar5 & 0x1f);
  node1->connectionStatus = node1->connectionStatus | uVar3;
  uVar5 = 1 << (uVar6 & 0x1f);
  node2->connectionStatus = node2->connectionStatus | uVar5;
  node1->connections = node1->connections | uVar3;
  node2->connections = node2->connections | uVar5;
  return;
}

void PLANPOOL_MarkTwoNodesAsNotConnected(PlanningNode *node1, PlanningNode *node2, PlanningNode *planningPool)

{
  u_int uVar1;
  u_int uVar2;

  uVar1 = 1 << ((int)((int)node2 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  node1->connectionStatus = node1->connectionStatus | uVar1;
  uVar2 = 1 << ((int)((int)node1 - (int)planningPool) * -0x49249249 >> 2 & 0x1fU);
  node2->connectionStatus = node2->connectionStatus | uVar2;
  node1->connections = node1->connections & ~uVar1;
  node2->connections = node2->connections & ~uVar2;
  return;
}

PlanningNode *
PLANPOOL_GetClosestUnexploredValidNeighbor(PlanningNode *startNode, PlanningNode *planningPool)

{
  int iVar1;
  u_int uVar2;
  PlanningNode *node2;
  u_int uVar3;
  int iVar4;
  PlanningNode *pPVar5;
  u_int uVar6;

  uVar6 = 0xffffffff;
  pPVar5 = (PlanningNode *)0x0;
  if (startNode != (PlanningNode *)0x0)
  {
    uVar3 = startNode->connectionStatus;
    iVar4 = 0;
    node2 = planningPool;
    if (*(char *)(poolManagementData + 1) != '\0')
    {
      do
      {
        if ((uVar3 & 1) == 0)
        {
          iVar1 = PLANPOOL_AppropriatePair(startNode, node2);
          if (iVar1 == 0)
          {
            PLANPOOL_MarkTwoNodesAsNotConnected(startNode, node2, planningPool);
          }
          else
          {
            uVar2 = MATH3D_LengthXY((int)(startNode->pos).x - (int)(node2->pos).x,
                                    (int)(startNode->pos).y - (int)(node2->pos).y,
                                    (int)(startNode->pos).z - (int)(node2->pos).z);
            if (uVar2 < uVar6)
            {
              pPVar5 = node2;
              uVar6 = uVar2;
            }
          }
        }
        uVar3 = uVar3 >> 1;
        iVar4 = iVar4 + 1;
        node2 = node2 + 1;
      } while (iVar4 < (int)(u_int) * (byte *)(poolManagementData + 1));
    }
  }
  return pPVar5;
}

void PLANPOOL_ChangeNodePosition(_Position *newPos, PlanningNode *nodeToChange, PlanningNode *planningPool)

{
  short sVar1;
  int iVar2;
  int iVar3;
  u_int uVar4;

  iVar2 = poolManagementData;
  if (nodeToChange != (PlanningNode *)0x0)
  {
    sVar1 = newPos->z;
    *(u_char *)&nodeToChange->pos = *(u_char *)newPos;
    (nodeToChange->pos).z = sVar1;
    nodeToChange->connectionStatus = 0;
    nodeToChange->connections = 0;
    iVar3 = 0;
    if (*(char *)(iVar2 + 1) != '\0')
    {
      uVar4 = ~(1 << ((int)((int)nodeToChange - (int)planningPool) * -0x49249249 >> 2 & 0x1fU) &
                0xffU);
      do
      {
        iVar3 = iVar3 + 1;
        planningPool->connectionStatus = planningPool->connectionStatus & uVar4;
        planningPool->connections = planningPool->connections & uVar4;
        planningPool = planningPool + 1;
      } while (iVar3 < (int)(u_int) * (byte *)(iVar2 + 1));
    }
  }
  return;
}

PlanningNode *
PLANPOOL_AddNodeToPool(_Position *pos, PlanningNode *planningPool, short nodeType, short nodeID, long streamUnitID)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  PlanningNode *pPVar7;

  iVar4 = poolManagementData;
  pPVar7 = (PlanningNode *)0x0;
  if (*(byte *)(poolManagementData + 1) < 0x20)
  {
    sVar2 = pos->z;
    sVar3 = pos->x;
    pPVar7 = planningPool + *(byte *)(poolManagementData + 1);
    (pPVar7->pos).y = pos->y;
    (pPVar7->pos).z = sVar2;
    (pPVar7->pos).x = sVar3;
    bVar1 = *(byte *)(iVar4 + 1);
    pPVar7->connections = 0;
    pPVar7->flags = 0;
    pPVar7->nodeType = nodeType;
    pPVar7->id = nodeID;
    pPVar7->streamUnitID = streamUnitID;
    pPVar7->connectionStatus = 1 << ((u_int)bVar1 & 0x1f);
    *(char *)(iVar4 + 1) = *(char *)(iVar4 + 1) + '\x01';
    iVar4 = poolManagementData;
    iVar6 = 0;
    if (*(char *)(poolManagementData + 1) != '\0')
    {
      iVar5 = 0;
      do
      {
        *(undefined2 *)(iVar5 + (u_int) * (byte *)(iVar4 + 1) * 0x40 + *(int *)(iVar4 + 0x10) + -0x40) = 0;
        *(undefined2 *)((u_int) * (byte *)(iVar4 + 1) * 2 + iVar6 * 0x40 + *(int *)(iVar4 + 0x10) + -2) = 0;
        iVar6 = iVar6 + 1;
        iVar5 = iVar6 * 2;
      } while (iVar6 < (int)(u_int) * (byte *)(iVar4 + 1));
    }
  }
  return pPVar7;
}

void PLANAPI_DeleteNodesFromPoolByType(PlanningNode *nodeToDelete, PlanningNode *planningPool)

{
  PlanningNode *pPVar1;
  u_int uVar2;
  int iVar3;
  u_int uVar4;
  u_int uVar5;
  int iVar6;
  int iVar7;
  u_int uVar8;
  u_int uVar9;
  u_int uVar10;
  u_char uVar11;
  u_long uVar12;
  long lVar13;
  u_long uVar14;

  iVar6 = 0;
  if (nodeToDelete != (PlanningNode *)0x0)
  {
    uVar9 = (u_int) * (byte *)(poolManagementData + 1) - 1;
    pPVar1 = planningPool + uVar9;
    uVar11 = *(u_char *)&(pPVar1->pos).z;
    uVar12 = pPVar1->connectionStatus;
    uVar14 = pPVar1->connections;
    *(u_char *)&nodeToDelete->pos = *(u_char *)&pPVar1->pos;
    *(u_char *)&(nodeToDelete->pos).z = uVar11;
    nodeToDelete->connectionStatus = uVar12;
    nodeToDelete->connections = uVar14;
    uVar11 = *(u_char *)&pPVar1->nodeType;
    lVar13 = pPVar1->streamUnitID;
    *(u_char *)&nodeToDelete->cost = *(u_char *)&pPVar1->cost;
    *(u_char *)&nodeToDelete->nodeType = uVar11;
    nodeToDelete->streamUnitID = lVar13;
    iVar7 = poolManagementData;
    uVar10 = (int)((int)nodeToDelete - (int)planningPool) * -0x49249249 >> 2;
    uVar8 = 1 << (uVar10 & 0x1f);
    uVar4 = 1 << (uVar9 & 0x1f);
    if (0 < (int)((u_int) * (byte *)(poolManagementData + 1) - 1))
    {
      do
      {
        uVar5 = planningPool->connectionStatus;
        uVar2 = uVar5 | uVar8;
        if ((uVar5 & uVar4) == 0)
        {
          uVar2 = uVar5 & ~uVar8;
        }
        planningPool->connectionStatus = uVar2;
        uVar5 = planningPool->connections;
        planningPool->connectionStatus = planningPool->connectionStatus & ~uVar4;
        uVar2 = uVar5 | uVar8;
        if ((uVar5 & uVar4) == 0)
        {
          uVar2 = uVar5 & ~uVar8;
        }
        planningPool->connections = uVar2;
        iVar6 = iVar6 + 1;
        planningPool->connections = planningPool->connections & ~uVar4;
        planningPool = planningPool + 1;
      } while (iVar6 < (int)((u_int) * (byte *)(iVar7 + 1) - 1));
    }
    iVar6 = poolManagementData;
    iVar7 = 0;
    if (0 < (int)((u_int) * (byte *)(poolManagementData + 1) - 1))
    {
      do
      {
        *(undefined2 *)(iVar7 * 2 + uVar10 * 0x40 + *(int *)(iVar6 + 0x10)) =
            *(undefined2 *)(iVar7 * 2 + uVar9 * 0x40 + *(int *)(iVar6 + 0x10));
        iVar3 = iVar7 * 0x40 + *(int *)(iVar6 + 0x10);
        *(undefined2 *)(uVar10 * 2 + iVar3) = *(undefined2 *)(uVar9 * 2 + iVar3);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)((u_int) * (byte *)(iVar6 + 1) - 1));
    }
    *(char *)(poolManagementData + 1) = *(char *)(poolManagementData + 1) + -1;
  }
  return;
}
