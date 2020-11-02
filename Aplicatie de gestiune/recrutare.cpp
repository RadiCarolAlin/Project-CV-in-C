#include <string.h>
#include "recrutare.h"

Boleean ValidationPersonalData(PersonalData p)
{
    if(p.name[0]<'A' && p.name[0]>'Z')
    {
        printf("\n Name invalid");
        return FALSE;
    }
    if(p.surname[0]<'A' && p.surname[0]>'Z')
    {
        printf("\n Surname invalid");
        return FALSE;
    }
    int k=0;
    int t=p.telephone;
    while(t!=0)
    {
       t=t/10;
       k++;
    };
    if(k!=9)
    {
        printf("\n Telephone invalid");
        return FALSE;
    }
    int x=-1;
    int y=-1;
    int z=-1;
    for(int i=0;i<(int)strlen(p.email);i++)
    {
        if(p.email[i]=='@')
         {
             x=i;
         }
         if(p.email[i]=='.')
         {
             y=i;
         }
    }
    z=strlen(p.email);
    if(x<=0 || (y-(x))<=0 || (z-(y))<=3 )
    {
        printf("\n Email invalid");
        return FALSE;
    }
    else
        return TRUE;


}
void ReadPersonalData(PersonalData *p)
{
    printf("\n the name is=");
    scanf("%s",p->name);
    printf("\n surname is=");
    gets(p->surname);
    gets(p->surname);
    printf("\n telephone=");
    scanf("%d",&p->telephone);
    printf("\n email is=");
    scanf("%s",p->email);
}
void PrintPersonalData(PersonalData p)
{
    printf("\n name= %s surname= %s  telephone=%d  email= %s",p.name,p.surname,p.telephone,p.email);
}
void ReadDiploma(Diploma *p)
{
    int r;
    do{
        printf("EducationType= ");
        printf("1-HighScholl   ");
        printf("2-Bachelor     ");
        printf("3-Master       ");
        printf("4-Phd          ");
        scanf("%d",&r);
    }while(r<1||r>4);


    switch(r+1)
    {
       case 2: p->type=HighScholl;
       break;
       case 3: p->type=Bachelor;
       break;
       case 4: p->type=Master;
       break;
       case 5: p->type=Phd;
       break;
    }

    printf("\n Name of the institution");
    gets(p->name);
    gets(p->name);
    printf("\n profile=");
    gets(p->profile);
    //gets(p->profile);
    printf("\n StartYear=");
    scanf("%d",&p->startYear);
    printf("\n EndYear=");
    scanf("%d",&p->endYear);
    p->next=NULL;
}

char *toString(EducationType p)
{
    char *s=(char*)malloc(20*sizeof(char));

    switch(p)
    {
       case 2: strcpy(s,"HighScholl");
       break;
       case 3: strcpy(s,"Bachelor");
       break;
       case 4: strcpy(s,"Master");
       break;
       case 5: strcpy(s,"Phd");
       break;
    }
    return s;

}

void PrintDiploma(Diploma p)
{
    printf("\n DIPLOMA:");
    printf("%s",toString(p.type));
    printf("\n %s",p.name);
    printf("\n %s",p.profile);
    printf("\n %d",p.startYear);
    printf("\n %d \n",p.endYear);
}
Boleean ValidationDiploma(Diploma p)
{
    if(p.type<2 || p.type>5 )
    {
        return FALSE;
    }
    if(p.name[0]<'A' && p.name[0]>'Z')
    {
        return FALSE;
    }
    if(strlen(p.profile)<=0)
    {
        return FALSE;
    }
    if(p.startYear>p.endYear)
    {
        return FALSE;
    }
    return TRUE;
}
void ReadJob(Job *p)
{
    printf("Company name=");
    gets(p->companyName);
    gets(p->companyName);
    printf("StartYear=");
    scanf("%d",&p->startYear);
    printf("EndYear=");
    scanf("%d",&p->endYear);
    printf("position=");
    gets(p->position);
    gets(p->position);
    p->next=NULL;
}
void PrintJob(Job p)
{
    printf("\n %s",p.companyName);
    printf("\n %d",p.startYear);
    printf("\n %d",p.endYear);
    printf("\n %s",p.position);
}
Boleean ValidationJob(Job p)
{
    if(p.companyName[0]<'A' && p.companyName[0]>'Z')
    {
        return FALSE;
    }
    if(p.startYear>p.endYear)
    {
        return FALSE;
    }
    if(p.position[0]<'A' && p.position[0]>'Z')
    {
        return FALSE;
    }
    return TRUE;
}
void ReadLanguage(Languages *p)
{
    printf("\n Language=");
    scanf("%s",p->language);
    p->next=NULL;
}
void PrintLanguage(Languages p)
{
    printf("\n %s",p.language);
}
void ReadSkill(Skills *p)
{
    printf("\n skill =");
    scanf("%s",p->skill);
    p->next=NULL;
}
void PrintSkill(Skills p)
{
    printf("\n %s",p.skill);
}
void initDiplomaList(DiplomaList *l)
{
  l->root=NULL;
}
void initJobList(JobList *l)
{
  l->root=NULL;
}
void initLanguageList(LanguageList *l)
{
  l->root=NULL;
}
void initSkillList(SkillList *l)
{
  l->root=NULL;
}
Boleean equalSkills(Skills a,Skills b)
{
    if(strcmp(a.skill,b.skill)==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void addSkill(SkillList* l,Skills* a)
{
    int k=0;
    Skills* x=l->root;
    while(x!=NULL)
    {
        if(equalSkills(*x,*a)==TRUE)
        {
          k++;
        }
        x=x->next;
    }
    if(k==0)
    {
       if(l->root==NULL)
           l->root=a;
       else
        {
           a->next=l->root;
           l->root=a;
        }
    }
    else
    {
      printf("The Skill is already in the List");
    }
}
void printListskills(SkillList a)
{
    Skills*x=a.root;
    while(x!=NULL)
    {
        PrintSkill(*x);
        x=x->next;
    }
}
Boleean equalPeriod(Job *a,Job *b)
{
    if(a!=NULL && b!=NULL)
    {
    if(a->startYear==b->startYear && a->endYear==b->endYear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    }
    else
    {
        return FALSE;
    }
}
int compareJob(Job *a,Job *b)
{
    if(a!=NULL && b!=NULL)
    {
       if(a->endYear>b->endYear)
            return 1;
       else if(a->endYear<b->endYear)
            return -1;
    }
    return 0;
}
void addJob(JobList *l,Job *a)
{

    if(l->root==NULL)
    {
        printf("Introducere prim element");
        l->root=a;
    }
    else if(compareJob(a,l->root)==1)
    {
        Job* prev=NULL;
        Job* next=NULL;
        Job* x=l->root;
        while(x->next!=NULL && compareJob(a,x->next)==1)
        {
           x=x->next;
        }
        printf("am trecut de while");
        if(equalPeriod(a,x->next)==TRUE)
        {
            printf("Introducere duplicat");
            return;
        }
        if(x->next==NULL)
        {
           printf("Introducere final");
           x->next=a;
        }
        else
        {
            printf("Introducere mijloc");
            prev=x;
            next=x->next;
            a->next=next;
            prev->next=a;
        }
    }
    else
    {
        // in fata root
        printf("Introducere in fata");
        a->next=l->root;
        l->root=a;
    }

}
void printJobList(JobList l)
{

    Job* x=l.root;
    while(x!=NULL)
    {
        printf("************");
        PrintJob(*x);
        x=x->next;
    }
}
Boleean equalLanguage(Languages a,Languages b)
{
     if(strcmp(a.language,b.language)==0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void addLanguage(LanguageList *l,Languages *a)
{
    int k=0;
    Languages* x=l->root;
    while(x!=NULL)
    {
        if(equalLanguage(*x,*a)==TRUE)
        {
          k++;
        }
        x=x->next;
    }
    if(k==0)
    {
       if(l->root==NULL)
           l->root=a;
       else
        {
           a->next=l->root;
           l->root=a;
        }
    }
    else
    {
      printf("The Language is already in the List");
    }
}
void printLanguageList(LanguageList a)
{
    Languages *x=a.root;
    while(x!=NULL)
    {
        PrintLanguage(*x);
        x=x->next;
    }
}
Boleean equalDiploma(Diploma *a,Diploma *b)
{
   if(a!=NULL && b!=NULL)
    {
    if(a->name==b->name && a->profile==b->profile && a->startYear==b->startYear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    }
    else
    {
        return FALSE;
    }
}
void addDiploma(DiplomaList *l,Diploma *a)
{
   int k=0;
    Diploma* x=l->root;
    while(x!=NULL)
    {
        if(equalDiploma(x,a)==TRUE)
        {
          k++;
        }
        x=x->next;
    }
    if(k==0)
    {
       if(l->root==NULL)
           l->root=a;
       else
        {
           a->next=l->root;
           l->root=a;
        }
    }
    else
    {
      printf("The Diploma is already in the List");
    }
}
void printDiplomaList(DiplomaList l)
{
    Diploma *x=l.root;
    while(x!=NULL)
    {
        PrintDiploma(*x);
        x=x->next;
    }
}
void readCv(char filename[])
{
    char str[250];
    FILE* fp=fopen(filename,"r");
    if (fp == NULL){
        printf("Could not open file ");
    }
    while (fgets(str, 1000, fp) !=NULL)
    {

    //fscanf(fp, "%[^\n]",str);
    printf(" \n %s", str);
    //printf("******");
    //char* str=(char*)malloc(50*sizeof(char));
    }
    fclose(fp);
}
void copydata(char filename[],Cv* data)
{
    char str[250];
    FILE* fp=fopen(filename,"r");
    if (fp == NULL){
        printf("Could not open file ");
    }
    while (fgets(str, 1000, fp) !=NULL)
    {
        //printf(" \n%s", str);
        //printf("\n %d",strlen(str));
        //char str2[30];
        //strcpy(str2,"PersonalData")
        if(strncmp(str,"PersonalData",12)==0)
        {
            while(strncmp(str,"Diploma",7)!=0)
            {
               fgets(str, 1000, fp);
               if(strncmp(str,"Diploma",7)==0)
                break;
               printf(" \n %s", str);
            }
        }
    }
    fclose(fp);
}


