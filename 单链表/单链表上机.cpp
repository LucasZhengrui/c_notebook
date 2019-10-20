#include <stdio.h>
#include <stdlib.h>
#define ERROR 1
#define OK 0
typedef char ElemType;//type�൱��char
typedef struct node   //������͵Ķ���
{
  ElemType data;
  struct node *next;
// }Node,*LinkList;    //LinkListΪ�ṹָ������
}LinkList;
//��ʼ��������
// InitList(LinkList *L)
// {
//   *L=(LinkList)malloc(sizeof(Node)); //����ͷ���
//   (*L)->next=NULL;   //�����յĵ�����L
// }//���ϵ�������ָ�룬������,����"��ʼ��������2��

//��ʼ��������2
LinkList *Init()
{
  LinkList *L = (LinkList*)malloc(sizeof(LinkList));
  L->next = NULL;

  return L;
}

//����

//1����ͷ�巨����������
void *CreateFromHead(LinkList *L)
//L�Ǵ�ͷ���Ŀ�����ͷָ�룬ͨ�������������Ԫ��ֵ������ͷ�巨��������L
{
  LinkList *s;
  char c;
  int flag = 1;
  while(flag)  //flag��ֵΪ1��������"$"ʱ����flagΪ0���������
  {
    c=getchar(); //�����ַ�c
    if(c!='$')   //flag��ֵΪ1��������"$"ʱ����flagΪ0���������
    {
      s = (LinkList*)malloc(sizeof(LinkList));//�����½��
      s->data = c;
      s->next = L->next;  //��s�������ͷ
      L->next = s;
    }
    else
    {
      flag = 0;
    }
  }
}

//2����β�巨����������
void *CreateFromTail(LinkList *L)
//L�Ǵ�ͷ���Ŀ�����ͷָ�룬ͨ����������Ԫ��ֵ������β�巨��������L
{
    LinkList *r,*s;
    char c;
    int flag = 1;//����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������
    r=L;//rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���
    while(flag)// ѭ���������Ԫ��ֵ���������½��s�����β
    {
      c = getchar();//����Ԫ��ֵ
      if(c != '$')
      {
        s = (LinkList*)malloc(sizeof(LinkList));
        s->data = c;
        r->next = s;
        r = s;
      }
      else
      {
        flag = 0;
        r->next = NULL;//�����һ������next������Ϊ�գ���ʾ����Ľ���
      }
    }//while,ѭ������!
}//CreateFromTail is done!

//����

// 1������Ų��ң�������L�в��ҵ�i�����
LinkList *Get(LinkList *L,int i)
// �ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬���ҵ�(1 <= i <= n)���򷵻ظý��Ĵ洢λ�ã����򷵻�NULL
{
  int j;
  LinkList *p;
  if(i <= 0)
  {
    return NULL;
  }
  p=L;
  j=0; // ��ͷ��㿪ʼɨ��
  while((p->next != NULL)&&(j < i))
  {
    p=p->next;// ɨ����һ���
    j++;// ��ɨ���������
  }// while is done;
  if(i == j)
  {
    printf("���ҳɹ���\n");
    return p;// �ҵ��˵�i�����
  }
  else
  {
    printf("����ʧ��\n");
    return NULL;// �Ҳ�����i <= 0 �� i > n
  }
}//Get is done!

//2���ڵ�����L�в���ֵΪkey�Ľ��
LinkList *Locate(LinkList *L,ElemType key)
//�ڴ�ͷ���ĵ�����L�в�������ֵ����key�ĵ�һ����㣬���ҵ��򷵻ظý���λ��p�����򷵻�NULL
{
  int j = 0;
  LinkList *p;
  p = L->next;//�ӱ��е�һ����㿪ʼ
  while(p != NULL)//��ǰ��δ����
  {
    if(p->data!=key)
    {
      p = p->next;
    }
    else
    {
      j++;
      printf("���ҳɹ���\n");
      break;//�ҵ����ֵ����keyʱ�˳�ѭ��
    }
  }
  return p;
}//locate

//������ĳ���
int ListLength(LinkList *L)
{
  LinkList *p;
  p=L->next;
  int j = 0;//������ŵ�����ĳ���
  while(p!=NULL)
  {
    p = p->next;
    j++;
  }
  printf("%d",j);//���ϻ�ʱ����ʱ���ӵĴ��룩������ʾ������ĳ���
  return j;//jΪ��õĵ�������
}//ListLength

//������������
int InsList(LinkList *L,int i,ElemType e)
//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
{
  LinkList *pre,*s;
  int k;
  if(i <= 0)
  {
    return 1;
  }
  pre = L;
  k = 0;  //��"ͷ"��ʼ�����ҵ�i-1�����
  while(pre != NULL && k < i-1) // ��δ������δ�鵽��i-1��ʱ�ظ����ҵ�preָ���i-1��
  {
    pre = pre -> next;
    k = k + 1;
  }  // ���ҵ�i-1�����
  if(pre == NULL) // �統ǰλ��preΪ�ձ�ʾ�����꣬����δ������i����˵������λ�ò�����
  {
    printf(" ����λ�ò�����");
    return 1;
  }
  s = (LinkList*)malloc(sizeof(LinkList)); // ����һ���µĽ��s
  s->data = e; // ֵe����s��������
  s->next = pre->next; // �޸�ָ�룬��ɲ������
  pre->next = s;
  return 0;
}

//������ɾ������
int DeleteList(LinkList *L,int i,ElemType e)
//�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��
{
  LinkList *pre,*r;
  int k;
  pre=L;
  k=0;
  while(pre->next != NULL && k < i-1 )
  //Ѱ�ұ�ɾ�����i��ǰ�����i-1ʹpָ����
  {
    pre = pre ->next;
    k = k + 1;
  }//���ҵ�i-1�����
  if(pre->next == NULL)//whileѭ������Ϊp->next = NULL �� i < 1 �������ģ���Ϊpre->nextΪ�գ�û���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��i���Ϸ�
  {
    printf("ɾ������λ��i������!");
    return 1;
  }
  r = pre -> next;
  pre -> next = r -> next;//�޸�ָ�룬ɾ�����r
  e = r -> data;
  free(r);//�ͷű�ɾ���Ľ���������ڴ�ռ�
  return 1;
}

//��ʾ����
void print(LinkList *L) {
  while (L) {
    printf("%c ", L->data);
    L = L->next;
  }
  printf("\n");
}

//����������
LinkList *Init();//��ʼ��������
void *CreateFromHead(LinkList *L);//��ͷ�巨����������
void *CreateFromTail(LinkList *L);//��β�巨����������
LinkList *Get(LinkList *L,int i);//����Ų��ң�������L�в��ҵ�i�����
LinkList *Locate(LinkList *L,ElemType key);//�ڵ�����L�в���ֵΪkey�Ľ��
int ListLength(LinkList *L);//������ĳ���
int InsList(LinkList *L,int i,ElemType e);//������������
int DeleteList(LinkList *L,int i,ElemType e);//������ɾ������
void print(LinkList *L);//��ʾ����
//�Ա������������е���

int main()
{
//���Գ�ʼ����������
  LinkList *L = Init();
  int k=1;
  int num;
  while(k)
  {
    printf("\n\n     ������       \n\n");
    printf("---------�˵�----------------\n");
    printf(" 1,��ͷ�巨      2,��ʾ       \n");
    printf(" 3,���㳤��      4,ɾ��       \n");
    printf(" 5,��ֵ��ѯ      6,���Ų�ѯ    \n");
    printf(" 7,ִ�н���      8,           \n");
    printf("-----------------------------\n");
    printf("����������ѡ��Ĺ�����ţ�    \n");
    scanf("%d",&num);
    switch(num)
    {
    //������ͷ�巨��������
      case 1:
      {
        printf("���������ݣ�\n");
        CreateFromHead(L);
        break;
      }

    //������ʾ����
      case 2:
      {
        printf("��ʼ��֮����������������\n");
        print(L);
        break;
      }

    //���Գ��Ⱥ���
      case 3:
      {
        printf("���������ݵĳ���Ϊ��\n");
        ListLength(L);
        printf("\n");
        break;
      }

    //����ɾ������
      case 4:
      {
        int a;
        printf("��������ɾ����������ţ�");
        scanf("%d",&a);
        DeleteList(L,a,'e');
        printf("����ɾ�����������Ϊ%d\n",a);
        printf("ɾ��֮����������������\n");
        break;
      }

    //���Բ�ѯ��������ֵ��ѯ��
      case 5:
      {
        ElemType key;
        printf("�����������ѯ���ݵ�ֵ��\n");
        scanf("%s",&key);
        Locate(L,key);
        break;
      }

    //���Բ�ѯ��������ţ�
      case 6:
      {
        int i;//�������
        printf("�������������ѯ�Ľ�㣺\n");
        scanf("%d",&i);
        Get(L,i);
        break;
      }

    }
  }
  return 0;
}
