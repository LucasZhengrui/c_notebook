#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFLEN 100
#define LEN 15
#define N 100
struct record
{
  char name[LEN+1];
  char code[LEN+1];
  char classify[100];
  char brand[LEN+1];
  char place[30];

  float price;
  float cost;
  float profit;

  int dateyear;
  int datemonth;
  int dateday;

  int expiration;

  int deadlineyear;
  int deadlinemonth;
  int deadlineday;

  char inventory[LEN+1];
  char warehouse[30];
}com[N];

int k=1,n,m;
void menu();

void help();
void refresh();
void search();
void modify();
void insert();
void del();      //The funtion of delete
void display();
void discount();
void save();
void sort();

void sort()
{
  int i,j,*p,*q,s;
  char temp[10];
  for(i=0;i<n-1;i++)
  {
    for(j=n-1;j>i;j--)
    if(strcmp(com[j-1].code,com[j].code)>0)
    {
      strcpy(temp,com[j-1].name);
      strcpy(com[j-1].name,com[j].name);
      strcpy(com[j].name,temp);

      strcpy(temp,com[j-1].code);
      strcpy(com[j-1].code,com[j].code);
      strcpy(com[j].code,temp);

      strcpy(temp,com[j-1].classify);
      strcpy(com[j-1].classify,com[j].classify);
      strcpy(com[j].classify,temp);

      strcpy(temp,com[j-1].brand);
      strcpy(com[j-1].brand,com[j].brand);
      strcpy(com[j].brand,temp);

      strcpy(temp,com[j-1].place);
      strcpy(com[j-1].place,com[j].place);
      strcpy(com[j].place,temp);

      com[j-1].price=(com[j].price);
      com[j-1].cost=(com[j].cost);
      com[j-1].profit=(com[j].profit);

      // strcpy(temp,com[j-1].date);
      // strcpy(com[j-1].date,com[j].date);
      // strcpy(com[j].date,temp);
      com[j-1].dateyear=(com[j].dateyear);
      com[j-1].datemonth=(com[j].datemonth);
      com[j-1].dateday=(com[j].dateyear);

      com[j-1].expiration=(com[j].expiration);

      // strcpy(temp,com[j-1].deadline);
      // strcpy(com[j-1].deadline,com[j].deadline);
      // strcpy(com[j].deadline,temp);
      com[j-1].deadlineyear=(com[j].deadlineyear);
      com[j-1].deadlinemonth=(com[j].deadlinemonth);
      com[j-1].deadlineday=(com[j].deadlineyear);

      strcpy(temp,com[j-1].inventory);
      strcpy(com[j-1].inventory,com[j].inventory);
      strcpy(com[j].inventory,temp);

      strcpy(temp,com[j-1].warehouse);
      strcpy(com[j-1].warehouse,com[j].warehouse);
      strcpy(com[j].warehouse,temp);
    }
  }
}

void help()//num 1
{
  printf("                          Explain of System                            \n");
  printf("_______________________________________________________________________\n");
  printf("|    Welcome to use this system!                                      |\n");
  printf("|    Use the number of the menu's tips;                               |\n");
  printf("|    The profit and the deadline will caculate automatically!         |\n");
  printf("|    Thanks for your using!                                           |\n");
  printf("|_____________________________________________________________________|\n");
}

void refresh()//num 2
{
  char *p="Commodity.txt";
  FILE *fp;
  int i=0;
  if ((fp=fopen("Commodity.txt","r"))==NULL)
  {
    printf("Open file is error! Strike any key to exit!",p);
    system("pause");
    exit(0);
  }
  while(fscanf(fp,"%s %s %s %s %s %f %f %f %d.%d.%d %d %d.%d.%d %s %s",com[i].name,&com[i].code,
  com[i].classify,com[i].brand,com[i].place,&com[i].price,&com[i].cost,&com[i].profit,&com[i].dateyear,&com[i].datemonth,&com[i].dateday,&com[i].expiration,
  &com[i].deadlineyear,&com[i].deadlinemonth,&com[i].deadlineday,com[i].inventory,com[i].warehouse)==17)
  {
    i++;
    i=i;
  }
  fclose(fp);
  n=i;
}

void search()
{
  int i,item,flag;
  char s1[21];
  while(1)
  {
    printf("             Search            \n");
    printf("_______________________________\n");
    printf("|      1.Search by code       |\n");
    printf("|      2.Search by name       |\n");
    printf("|      3.Search by brand      |\n");
    printf("|      4.Search by place      |\n");
    printf("|      5.Search by classify   |\n");
    printf("|      6.Search by warehouse  |\n");
    printf("|      7.Exit                 |\n");
    printf("|_____________________________|\n");
    printf("Please choose the way to search(1-7) ");
    scanf("%d",&item);
    flag=0;
    switch(item)
    {
      case 1:
      {
        printf("To check the only one commodity!\n");
        printf("Please input the code:\n");
        scanf("%s",s1);
        printf("\n");
        for(i=0;i<n;i++)
        if(strcmp(com[i].code,s1)==0)
        {
          flag=1;
          printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
          com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
          com[i].deadlineday,com[i].inventory,com[i].warehouse);
        }
        if(flag==0)
        printf("The code is nothingness!\n");
        break;
      }
      case 2:
      {
        printf("To check the commodity of the same name!\n");
        printf("Please input the name:\n");
        scanf("%s",s1);
        printf("\n");
        for(i=0;i<n;i++)
        if(strcmp(com[i].name,s1)==0)
        {
          flag=1;
          printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
          com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
          com[i].deadlineday,com[i].inventory,com[i].warehouse);
        }
        if(flag==0)
        printf("The name is nothingness!\n");
        break;
      }
      case 3:
      {
        printf("To check the commodity of the same brand!\n");
        printf("Please input the brand:\n");
        scanf("%s",s1);
        printf("\n");
        for(i=0;i<n;i++)
        if(strcmp(com[i].brand,s1)==0)
        {
          flag=1;
          printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
          com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
          com[i].deadlineday,com[i].inventory,com[i].warehouse);
        }
        if(flag==0)
        printf("The brand is nothingness!\n");
        break;
      }
      case 4:
      {
        printf("To check the commodity from the same place!\n");
        printf("Please input the place: \n");
        scanf("%s",s1);
        for(i=0;i<n;i++)
        if(strcmp(com[i].place,s1)==0)
        {
          flag=1;
          printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
          com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
          com[i].deadlineday,com[i].inventory,com[i].warehouse);
        }
        if(flag==0)
        printf("The place is nothingness!\n");
        break;
      }
      case 5:
      {
        printf("To check the commodity of the same classify!\n");
        printf("Please input the name of the classify: \n");
        scanf("%s",s1);
        for(i=0;i<n;i++)
        if(strcmp(com[i].classify,s1)==0)
        {
          flag=1;
          printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
          com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
          com[i].deadlineday,com[i].inventory,com[i].warehouse);
        }
        if(flag==0)
        printf("The classify is nothingness!\n");
        break;
      }
      case 6:
      {
        printf("To check the warehouse!\n");
        printf("Please input the name of the warehouse: \n");
        scanf("%s",s1);
        for(i=0;i<n;i++)
        if(strcmp(com[i].warehouse,s1)==0)
        {
          flag=1;
          printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
          com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
          com[i].deadlineday,com[i].inventory,com[i].warehouse);
        }
        if(flag==0)
        printf("The warehouse is nothingness!\n");
        break;
      }
      case 7:
      {
        return;
      }
      default:
      {
        printf("Please input the 'item' between 1 to 6!\n");
        exit(0);
      }
    }
  }
}

void modify()
{
  int i,item,num;
  char s1[LEN+1],s2[LEN+1];
  printf("Please input the code of the commodity\n");
  scanf("%s",s1);
  for(i=0;i<n;i++)
  if(strcmp(com[i].code,s1)==0)
  num=i;
  while(1)
  {
    printf("          Modify           \n");
    printf("____________________________\n");
    printf("|  1.Modify the name       |\n");
    printf("|  2.Modify the classify   |\n");
    printf("|  3.Modify the brand      |\n");
    printf("|  4.Modify the place      |\n");
    printf("|  5.Modify the price      |\n");
    printf("|  6.Modify the cost       |\n");
    printf("|  7.Modify the date       |\n");
    printf("|  8.Modify the expiration |\n");
    printf("|  9.Modify the inventory  |\n");
    printf("|  10.Modify the warehouse |\n");
    printf("|  11.Exit                 |\n");
    printf("|__________________________|\n");
    printf("Please input the number between 1 to 11 of the menu ");
    scanf("%d",&item);
    switch(item)
    {
      case 1:
      {
        printf("Please input the new name \n");
        scanf("%s",s2);
        strcpy(com[num].name,s2);
        save();
        break;
      }
      case 2:
      {
        printf("Please input the new classify \n");
        scanf("%s",s2);
        strcpy(com[num].classify,s2);
        save();
        break;
      }
      case 3:
      {
        printf("Please input the new brand \n");
        scanf("%s",s2);
        strcpy(com[num].brand,s2);
        save();
        break;
      }
      case 4:
      {
        printf("Please input the new place \n");
        scanf("%s",s2);
        strcpy(com[num].place,s2);
        save();
        break;
      }
      case 5:
      {
        printf("Please input the new price(RMB x.xx) \n");
        scanf("%f",&com[num].price);
        com[num].profit=com[num].price-com[num].cost;
        save();
        break;
      }
      case 6:
      {
        printf("Please input the new cost(RMB x.xx) \n");
        scanf("%f",&com[num].cost);
        com[num].profit=com[num].price-com[num].cost;
        save();
        break;
      }
      case 7:
      {
        printf("Please input the new date \n");
        scanf("%d.%d.%d",&com[num].dateyear,&com[num].datemonth,&com[num].dateday);
        if(com[num].datemonth+com[num].expiration<=12)
        {
          com[num].deadlinemonth=(com[num].expiration+com[num].datemonth);
          com[num].deadlineday=(com[num].dateday);
          com[num].deadlineyear=(com[num].dateyear);
        }
        else
        {
          // com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12);
          if( ( ((com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)%4==0) && ((com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)%100!=0) )||((com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)%400==0))//To judge the deadlineyear(Leap year)
          {
            com[num].deadlineday=(com[num].dateday);
            if((com[num].expiration+com[num].datemonth)%12==0)
            {
              com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)-1;
              com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12+12;
            }
            else
            {
              com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12;
              com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12);
            }
          }
          else
          {
            if(com[num].dateday>28)
            {
              com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12);
              com[num].deadlineday=31-com[num].dateday;
              com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12+1;
            }
            else
            {
              com[num].deadlineday=com[num].dateday;
              if((com[num].expiration+com[num].datemonth)%12==0)
              {
                com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)-1;
                com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12+12;
              }
              else
              {
                com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12;
                com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12);
              }
            }
          }
        }
        save();
        break;
      }
      case 8:
      {
        printf("Please input the new expiration \n");
        scanf("%d",&com[num].expiration);
        if(com[num].datemonth+com[num].expiration<=12)
        {
          com[num].deadlinemonth=(com[num].expiration+com[num].datemonth);
          com[num].deadlineday=(com[num].dateday);
          com[num].deadlineyear=(com[num].dateyear);
        }
        else
        {
          // com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12);
          if( ( ((com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)%4==0) && ((com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)%100!=0) )||((com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)%400==0))//To judge the deadlineyear(Leap year)
          {
            com[num].deadlineday=(com[num].dateday);
            if((com[num].expiration+com[num].datemonth)%12==0)
            {
              com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)-1;
              com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12+12;
            }
            else
            {
              com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12;
              com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12);
            }
          }
          else
          {
            if(com[num].dateday>28)
            {
              com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12);
              com[num].deadlineday=31-com[num].dateday;
              com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12+1;
            }
            else
            {
              com[num].deadlineday=com[num].dateday;
              if((com[num].expiration+com[num].datemonth)%12==0)
              {
                com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12)-1;
                com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12+12;
              }
              else
              {
                com[num].deadlinemonth=(com[num].expiration+com[num].datemonth)%12;
                com[num].deadlineyear=(com[num].dateyear+(com[num].expiration+com[num].datemonth)/12);
              }
            }
          }
        }
        save();
        break;
      }
      case 9:
      {
        printf("Please input the new inventory \n");
        scanf("%s",s2);
        strcpy(com[num].inventory,s2);
        save();
        break;
      }
      case 10:
      {
        printf("Please input the new warehouse \n");
        scanf("%s",s2);
        strcpy(com[num].warehouse,s2);
        save();
        break;
      }
      case 11:
      {
        return;
      }
      default:
      {
        printf("Please input the number between 1 to 11!\n");
        exit(0);
      }
    }
  }
}

void insert()
{
  int i=n,j,flag;
  printf("Please input the quantity of insert:\n");
  scanf("%d",&m);
  do
  {
    flag=1;
    while(flag)
    {
      flag=0;
      printf("Please input the code of the No.%d commodity to judge how the number is already exist :\n",i+1);
      scanf("%s",com[i].code);
      for(j=0;j<i;j++)
      if(strcmp(com[i].code,com[j].code)==0)
      {
        printf("This code is already exist!\n");
        flag=1;
        break;
      }
    }
    printf("Please input the name of the No.%d commodity:\n",i+1);
    scanf("%s",com[i].name);
    printf("Please input the classify of the No.%d commodity:\n",i+1);
    scanf("%s",com[i].classify);
    printf("Please input the brand of the No.%d commodity:\n",i+1);
    scanf("%s",com[i].brand);
    printf("Please input the place of the No.%d commodity:\n",i+1);
    scanf("%s",com[i].place);
    printf("Please input the price(RMB x.xx) of the No.%d commodity:\n",i+1);
    scanf("%f",&com[i].price);
    printf("Please input the cost(RMB x.xx) of the No.%d commodity:\n",i+1);
    scanf("%f",&com[i].cost);
    com[i].profit=com[i].price-com[i].cost;
    printf("Please input the date of the No.%d commodity:(xxxx.x.x)\n",i+1);
    scanf("%d.%d.%d",&com[i].dateyear,&com[i].datemonth,&com[i].dateday);
    printf("Please input the expiration(months) of the No.%d commodity::\n",i+1);
    scanf("%d",&com[i].expiration);
    // printf("Please input the deadline of the No.%d commodity:(xxxx.x.x)\n",i+1);
    // scanf("%s",com[i].deadline);
    if(com[i].datemonth+com[i].expiration<=12)
    {
      com[i].deadlinemonth=(com[i].expiration+com[i].datemonth);
      com[i].deadlineday=(com[i].dateday);
      com[i].deadlineyear=(com[i].dateyear);
    }
    else
    {
      // com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12);
      if( ( ((com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)%4==0) && ((com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)%100!=0) )||((com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)%400==0))//To judge the deadlineyear(Leap year)
      {
        com[i].deadlineday=(com[i].dateday);
        if((com[i].expiration+com[i].datemonth)%12==0)
        {
          com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)-1;
          com[i].deadlinemonth=(com[i].expiration+com[i].datemonth)%12+12;
        }
        else
        {
          com[i].deadlinemonth=(com[i].expiration+com[i].datemonth)%12;
          com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12);
        }
      }
      else
      {
        if(com[i].dateday>28)
        {
          com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12);
          com[i].deadlineday=31-com[i].dateday;
          com[i].deadlinemonth=(com[i].expiration+com[i].datemonth)%12+1;
        }
        else
        {
          com[i].deadlineday=com[i].dateday;
          if((com[i].expiration+com[i].datemonth)%12==0)
          {
            com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12)-1;
            com[i].deadlinemonth=(com[i].expiration+com[i].datemonth)%12+12;
          }
          else
          {
            com[i].deadlinemonth=(com[i].expiration+com[i].datemonth)%12;
            com[i].deadlineyear=(com[i].dateyear+(com[i].expiration+com[i].datemonth)/12);
          }
        }
      }
    }
    printf("Please input the inventory of the No.%d commodity:\n",i+1);
    scanf("%s",com[i].inventory);
    printf("Please input the warehouse of the No.%d commodity:\n",i+1);
    scanf("%s",com[i].warehouse);
    if(flag==0)
    {
      i=i;
      i++;
    }
  }
  while(i<n+m);
  n+=m;
  printf("Finishing!\n\n");
  sort();
  save();
}

void del()
{
  int i,j,flag=0;
  char s1[LEN+1];
  printf("Please input the code:\n");
  scanf("%s",s1);
  for(i=0;i<n;i++)
  if(strcmp(com[i].code,s1)==0)
  {
    flag=1;
    for(j=i;j<n-1;j++)
    com[j]=com[j+1];
  }
  if(flag==0)
  {
    printf("The number is nothingness!\n");
  }
  if(flag==1)
  {
    printf("Succeed!\n");
    n--;
  }
  save();
}

void display()
{
  int i;
  printf("The all commodity's message are \n\n");
  for(i=0;i<n;i++)
  {
    printf("\nname:%s\ncode:%s\nclassify:%s\nbrand:%s\nplace:%s\nprice:%.2f\ncost:%.2f\nprofit:%.2f\ndate:%d.%d.%d\nexpiration:%d\ndeadline:%d.%d.%d\ninventory:%s\nwarehourse:%s\n\n",com[i].name,com[i].code,com[i].classify,
    com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,
    com[i].deadlineday,com[i].inventory,com[i].warehouse);
  }
}

void discount()
{
  int i,item,num,flag;
  int discount;
  char s1[LEN+1],s2[LEN+1];
  while(1)
  {
    printf("                  Discount                     \n");
    printf("_______________________________________________\n");
    printf("|    1.Give a discount to this classify       |\n");
    printf("|    2.Give a discount to only the commodity  |\n");
    printf("|    3.Exit                                   |\n");
    printf("|_____________________________________________|\n");
    printf("Please input the number to choose the funtion ");
    scanf("%d",&item);
    switch(item)
    {
      case 1:
      {
        printf("Please input the classify of the commodity: \n");
        scanf("%s",s1);
        printf("Please input the discount(percent) \n");
        scanf("%d",&discount);
        for(i=0;i<n;i++)
        if(strcmp(com[i].classify,s1)==0)
        {
          flag=1;
          com[i].price=com[i].price*(discount/100.00);
          com[i].profit=com[i].price-com[i].cost;
          save();
        }
        if(flag==0)
        printf("The classify is nothingness!\n");
        break;
      }
      case 2:
      {
        printf("Please input the code of the commodity: \n");
        scanf("%s",s1);
        printf("Please input the discount(percent) \n");
        scanf("%d",&discount);
        for(i=0;i<n;i++)
        if(strcmp(com[i].code,s1)==0)
        {
          flag=1;
          com[i].price=com[i].price*(discount/100.00);
          com[i].profit=com[i].price-com[i].cost;
          save();
        }
        if(flag==0)
        printf("The code is nothingness!\n");
        break;
      }
      case 3:
      {
        return;
      }
      default:
      {
        printf("Please input the number between 1 to 3!\n");
        exit(0);
      }
    }
  }
}

void save()
{
  int i;
  FILE *fp;
  fp=fopen("Commodity.txt","w");
  for(i=0;i<n;i++)
  {
    fprintf(fp,"%s  %s  %s  %s  %s  %.2f  %.2f  %.2f  %d.%d.%d  %d  %d.%d.%d  %s  %s\n",com[i].name,com[i].code,com[i].classify,
    com[i].brand,com[i].place,com[i].price,com[i].cost,com[i].profit,com[i].dateyear,com[i].datemonth,com[i].dateday,com[i].expiration,com[i].deadlineyear,com[i].deadlinemonth,com[i].deadlineday,
    com[i].inventory,com[i].warehouse);
  }
  fclose(fp);
}

void menu()
{
  int num;
  printf(" \n\n          Commodiity management system                 \n\n");
  printf("------------------------ MENU --------------------------------\n");
  printf("    ___________________________________________________       \n");
  printf("    |                      |                          |       \n");
  printf("    | 1.Search             |    5.Display             |       \n");
  printf("    |                      |                          |       \n");
  printf("    | 2.Modify             |    6.Discount            |       \n");
  printf("    |                      |                          |       \n");
  printf("    | 3.Insert             |    7.Exit                |       \n");
  printf("    |                      |                          |       \n");
  printf("    | 4.Delete             |                          |       \n");
  printf("    |______________________|__________________________|       \n");
  printf("--------------------------------------------------------------\n");
  printf("Please input the number between 1 to 8 to choose the funtion :\n");
  scanf("%d",&num);
  switch(num)
  {
    case 1:
    {
      search();
      break;
    }
    case 2:
    {
      modify();
      break;
    }
    case 3:
    {
      insert();
      break;
    }
    case 4:
    {
      del();
      break;
    }
    case 5:
    {
      display();
      break;
    }
    case 6:
    {
      discount();
      break;
    }
    case 7:
    {
      k=0;
      break;
    }
    default:
    {
      printf("Pleace input the number between 1 to 8!\n");
      exit(0);
    }
  }
}
int main(int argc, char const *argv[]) {
  help();
  while(k)
  {
    refresh();
    menu();
  }
  system("pause");
  return 0;
}
