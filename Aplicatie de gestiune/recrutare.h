#pragma once
#include <stdio.h>
#include <stdlib.h>
#define BOLEEAN(x) x==TRUE?"TRUE":"FALSE"


typedef enum{
FALSE,TRUE
}Boleean;
typedef struct{
 char name[30];
 char surname[30];
 int telephone;
 char email[30];
}PersonalData;
typedef enum{
HighScholl=2,Bachelor,Master,Phd
}EducationType;

typedef struct Diploma{
 EducationType type;
 char name[50];
 char profile[30];
 int startYear;
 int endYear;
 struct Diploma *next;
 }Diploma;

typedef struct {
   Diploma *root;
 }DiplomaList;

typedef struct Job{
 char companyName[30];
 int startYear;
 int endYear;
 char position[30];
 struct Job *next;
}Job;

typedef struct{
Job *root;
}JobList;

typedef struct Languages{
  char language[30];
  struct Languages *next;
}Languages;

typedef struct{
  Languages *root;
}LanguageList;

typedef struct Skills{
char skill[30];
struct Skills *next;
}Skills;

typedef struct{
Skills *root;
}SkillList;

typedef struct{
PersonalData personalData;
DiplomaList listDiploma;
JobList listJob;
LanguageList listLanguage;
SkillList listSkill;
}Cv;
void ReadPersonalData(PersonalData *p);
void PrintPersonalData(PersonalData p);
Boleean ValidationPersonalData(PersonalData p);
void ReadDiploma(Diploma *d);
void PrintDiploma(Diploma d);
Boleean ValidationDiploma(Diploma d);
void ReadJob(Job *j);
void PrintJob(Job j);
Boleean ValidationJob(Job j);
void ReadLanguage(Languages *l);
void PrintLanguage(Languages l);
void ReadSkill(Skills *s);
void PrintSkill(Skills s);

void initDiplomaList(DiplomaList *t);
Boleean equalDiploma(Diploma *a,Diploma *b);
void addDiploma(DiplomaList *l,Diploma *a);
void printDiplomaList(DiplomaList l);

void initJobList(JobList *l);
Boleean equalPeriod(Job *a,Job *b);
void addJob(JobList *l,Job *a);
int compareJob(Job *a,Job *b);
void printJobList(JobList l);

void initLanguageList(LanguageList *m);
Boleean equalLanguage(Languages a,Languages b);
void addLanguage(LanguageList *l,Languages *a);
void printLanguageList(LanguageList a);



//List of skills is a set(it does not allow duplicate elements)
void initSkillList(SkillList *o);
Boleean equalSkills(Skills a,Skills b);
void addSkill(SkillList *l,Skills *a);
void printListskills(SkillList a);

void readCv(char filename[]);
void copydata(char filename[],Cv *data);

