#include "recrutare.h"
#include "recrutare.cpp"
#define filename "C:\\Users\\AlinPC\\Desktop\\prega C\\Aplicatie de gestiune\\informatiicv.txt"
int main()
{
 /*
 PersonalData p;
 ReadPersonalData(&p);
 PrintPersonalData(p);
 Boleean x=ValidationPersonalData(p);
 printf("\n %s",BOLEEAN(x));
 Diploma d;
 ReadDiploma(&d);
 PrintDiploma(d);
 ValidationDiploma(d);
 Job j;
 ReadJob(&j);
 PrintJob(j);
 ValidationJob(j);
 Languages t;
 ReadLanguage(&t);
 PrintLanguage(t);
 Skills s;
 ReadSkill(&s);
 PrintSkill(s);
 DiplomaList v;
 initDiplomaList(&v);
 JobList f;
 initJobList(&f);
 LanguageList m;
 initLanguageList(&m);
 SkillList o;
 initSkillList(&o);
 */
 /*
 SkillList t;
 initSkillList(&t);
 Skills s,p,g;
 ReadSkill(&s);
 ReadSkill(&p);
 ReadSkill(&g);
 addSkill(&t,&s);
 addSkill(&t,&p);
 addSkill(&t,&g);
 printListskills(t);

 JobList l;
 initJobList(&l);
 Job a={"Hella",2000,2004,"Inginer",NULL};
 Job b={"Continental",2000,2002,"Operator",NULL};
 Job c={"Huf",1994,1998,"Manager",NULL};
 Job d={"Buf",2000,2003,"Manager",NULL};
 Job e={"Visteon",1994,2001,"IT",NULL};
 Job f={"Atos",1993,2020,"Supervizor",NULL};
 //ReadJob(&a);
 //ReadJob(&b);
 //ReadJob(&c);
 addJob(&l,&a);
 addJob(&l,&b);
 addJob(&l,&c);
 addJob(&l,&d);
 addJob(&l,&e);
 addJob(&l,&f);
 printJobList(l);
 */
Cv *data;
//readCv(filename);
copydata(filename,data);

}

