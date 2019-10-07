#include <stdio.h>
#include <stdlib.h>
#define ERROR 1
#define OK 0
typedef char ElemType;//type相当于char
typedef struct node   //结点类型的定义
{
  ElemType data;
  struct node *next;
// }Node,*LinkList;    //LinkList为结构指针类型
}LinkList;
//初始化单链表
// InitList(LinkList *L)
// {
//   *L=(LinkList)malloc(sizeof(Node)); //建立头结点
//   (*L)->next=NULL;   //建立空的单链表L
// }//书上的隐藏了指针，故舍弃,改用"初始化单链表2。

//初始化单链表2
LinkList *Init()
{
  LinkList *L = (LinkList*)malloc(sizeof(LinkList));
  L->next = NULL;

  return L;
}

//插入

//1、用头插法建立单链表
void *CreateFromHead(LinkList *L)
//L是带头结点的空链表头指针，通过键盘输入表中元素值，利用头插法建单链表L
{
  LinkList *s;
  char c;
  int flag = 1;
  while(flag)  //flag初值为1，当输入"$"时，置flag为0，建表结束
  {
    c=getchar(); //输入字符c
    if(c!='$')   //flag初值为1，当输入"$"时，置flag为0，建表结束
    {
      s = (LinkList*)malloc(sizeof(LinkList));//建立新结点
      s->data = c;
      s->next = L->next;  //将s结点插入表头
      L->next = s;
    }
    else
    {
      flag = 0;
    }
  }
}

//2、用尾插法建立单链表
void *CreateFromTail(LinkList *L)
//L是带头结点的空链表头指针，通过键盘输入元素值，利用尾插法建单链表L
{
    LinkList *r,*s;
    char c;
    int flag = 1;//设置一个标志，初值为1，当输入"$"时，flag为0，建表结束
    r=L;//r指针动态指向链表的当前表尾，以便于做尾插入，其初值指向头结点
    while(flag)// 循环输入表中元素值，将建立新结点s插入表尾
    {
      c = getchar();//输入元素值
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
        r->next = NULL;//将最后一个结点的next链域置为空，表示链表的结束
      }
    }//while,循环结束!
}//CreateFromTail is done!

//查找

// 1、按序号查找，在链表L中查找第i个结点
LinkList *Get(LinkList *L,int i)
// 在带头结点的单链表L中查找第i个结点，若找到(1 <= i <= n)，则返回该结点的存储位置；否则返回NULL
{
  int j;
  LinkList *p;
  if(i <= 0)
  {
    return NULL;
  }
  p=L;
  j=0; // 从头结点开始扫描
  while((p->next != NULL)&&(j < i))
  {
    p=p->next;// 扫描下一结点
    j++;// 已扫描结点计数器
  }// while is done;
  if(i == j)
  {
    return p;// 找到了第i个结点
  }
  else
  {
    return NULL;// 找不到，i <= 0 或 i > n
  }
}//Get is done!

//2、在单链表L中查找值为key的结点
LinkList *Locate(LinkList *L,ElemType key)
//在带头结点的单链表L中查找其结点值等于key的第一个结点，若找到则返回该结点的位置p，否则返回NULL
{
  int j = 0;
  LinkList *p;
  p = L->next;//从表中第一个结点开始
  while(p != NULL)//当前表未查完
  {
    if(p->data!=key)
    {
      p = p->next;
    }
    else
    {
      j++;
      break;//找到结点值等于key时退出循环
    }
  }
  return p;
}//locate

//求单链表的长度
int ListLength(LinkList *L)
{
  LinkList *p;
  p=L->next;
  int j = 0;//用来存放单链表的长度
  while(p!=NULL)
  {
    p = p->next;
    j++;
  }
  printf("%d",j);//（上机时测试时增加的代码）用于显示单链表的长度
  return j;//j为求得的单链表长度
}//ListLength

//单链表插入操作
int InsList(LinkList *L,int i,ElemType e)
//在带头结点的单链表L中第i个位置插入值为e的新结点
{
  LinkList *pre,*s;
  int k;
  if(i <= 0)
  {
    return 1;
  }
  pre = L;
  k = 0;  //从"头"开始，查找第i-1个结点
  while(pre != NULL && k < i-1) // 表未查完且未查到第i-1个时重复，找到pre指向第i-1个
  {
    pre = pre -> next;
    k = k + 1;
  }  // 查找第i-1个结点
  if(pre == NULL) // 如当前位置pre为空表示已找完，但还未数到第i个，说明插入位置不合理
  {
    printf(" 插入位置不合理！");
    return 1;
  }
  s = (LinkList*)malloc(sizeof(LinkList)); // 申请一个新的结点s
  s->data = e; // 值e置入s的数据域
  s->next = pre->next; // 修改指针，完成插入操作
  pre->next = s;
  return 0;
}

//单链表删除操作
int DeleteList(LinkList *L,int i,ElemType e)
//在带头结点的单链表L中删除第i个元素，并将删除的元素保存到变量*e中
{
  LinkList *pre,*r;
  int k;
  pre=L;
  k=0;
  while(pre->next != NULL && k < i-1 )
  //寻找被删除结点i的前驱结点i-1使p指向它
  {
    pre = pre ->next;
    k = k + 1;
  }//查找第i-1个结点
  if(pre->next == NULL)//while循环是因为p->next = NULL 或 i < 1 而跳出的，因为pre->next为空，没有找到合法的前驱位置，说明删除位置i不合法
  {
    printf("删除结点的位置i不合理!");
    return 1;
  }
  r = pre -> next;
  pre -> next = r -> next;//修改指针，删除结点r
  e = r -> data;
  free(r);//释放被删除的结点所含的内存空间
  return 1;
}

//显示函数
void print(LinkList *L) {
  while (L) {
    printf("%c ", L->data);
    L = L->next;
  }
  printf("\n");
}

//函数的声明
LinkList *Init();//初始化单链表
void *CreateFromHead(LinkList *L);//用头插法建立单链表
void *CreateFromTail(LinkList *L);//用尾插法建立单链表
LinkList *Get(LinkList *L,int i);//按序号查找，在链表L中查找第i个结点
LinkList *Locate(LinkList *L,ElemType key);//在单链表L中查找值为key的结点
int ListLength(LinkList *L);//求单链表的长度
int InsList(LinkList *L,int i,ElemType e);//单链表插入操作
int DeleteList(LinkList *L,int i,ElemType e);//单链表删除操作
void print(LinkList *L);//显示函数
//以便于在主函数中调用

int main()
{
//测试初始化单链表函数
  LinkList *L = Init();

//测试用头插法插入数据
  CreateFromHead(L);

//测试显示函数
  printf("After Init\n");
  print(L);

//测试长度函数
  printf("The Length is ");
  ListLength(L);
  printf("\n");

//测试删除函数
  int a;
  printf("Input the number you want to delete ");
  scanf("%d",&a);
  DeleteList(L,a,'e');
  printf("Delete Num.%d point.\n",a);
  printf("After delete \n");
  print(L);

  return 0;
}
