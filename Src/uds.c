#include "uds.h"
//���г�ʼ��
void Que_Init(CircleQue_TypeDef * pq)
{
  pq->front = pq->rear = 0;
}
//���
uint8_t Que_In(CircleQue_TypeDef * pq, uint8_t c)
{
  pq->data[pq->rear] = c;
  pq->rear = (pq->rear + 1) % QUESIZE;
  if (pq->front == pq->rear)
    pq->front = (pq->front + 1) % QUESIZE;
  return 1;
}
//����
uint8_t Que_Out(CircleQue_TypeDef * pq, uint8_t *c)
{
  if (pq->front == pq->rear) {
    return 0;
  }
  *c = pq->data[pq->front];
  pq->front = (pq->front + 1) % QUESIZE;
  return 1;
}
//��ѯ���У�ȡ����ͷ������ɾ��
uint8_t Que_Query(CircleQue_TypeDef * pq, uint8_t *c)
{
  if (pq->front == pq->rear) {
    return 0;
  }
  *c = pq->data[pq->front];
  return 1;
}
