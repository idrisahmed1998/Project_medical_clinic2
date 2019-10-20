/*
* Programming By : -
* idris ahmed
* type : application console
* programming language using by (C);
*/
//////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
//////////////////////////////////////////////////////////////////
void addnew();
void search();
void remove();
void display();
void modfay();
//////////////////////////////////////////////////////////////////
struct dates1{
int y,m,d;};
struct dates2{
int y,m,d;};
//////////////////////////////////////////////////////////////////
struct homes{
int id;
char name[120];
char gender[7];
char state[100];
char dis[100];
struct dates1 STARTD;
struct dates2 ENDD;}s;
//////////////////////////////////////////////////////////////////
void main(){
clrscr();
printf("\n*************************************************************************\n");
printf("* 1 - AddNew  2 - Display  3 - Remove  4 - Search  5 - Modfay  6 - Exit *");
printf("\n*************************************************************************\n");
printf("Enter Your Choise ! : ");
int sel;
scanf("%d",&sel);
if(sel==1){addnew(); }
if(sel == 2){ display();}
if(sel == 3){ remove(); }
if(sel == 4){ search(); }
if(sel == 5){ modfay(); }
if(sel == 6){ exit(0);  }
else{main();}
if(isalpha(sel)){
printf("\nThe Choise Is Not True ! \n");
getch();
main();}}
//////////////////////////////////////////////////////////////////
void addnew(){
FILE *all;
struct homes m;
struct homes menu;
fflush(stdin);
all = fopen("project.data","rb");
int STR = 0;
while(1){
int rob = fread(&m,sizeof(m),1,all);
if(rob !=0){
STR++;}
if(rob==0){
if(m.id==1){
STR++;}
break;}}
fclose(all);
menu.id = STR;
///////////////////////////////////////////
fflush(stdin);
NM:
printf("Enetr Name :  ");
gets(menu.name);
if((strlen(menu.name))==0){
printf("\n Field Name Is Empty : ");
goto NM;}
GN:
printf("\nEnter Gender (Male / Female ) : ");
gets(menu.gender);
if((strlen(menu.gender))==0){
printf("\n Field Gender Is Empty : ");
goto GN;}
ST:
printf("Enter State : ");
fflush(stdin);
gets(menu.state);
if((strlen(menu.state))==0){
printf("\n Field State Is Empty : ");
goto ST;}
printf("\nEnter Discryption Doctor : ");
fflush(stdin);
gets(menu.dis);
D1:
printf("\nEnter Comeing Date (D/M/Y) :");
fflush(stdin);
scanf("%d%d%d",&menu.STARTD.d,&menu.STARTD.m,&menu.STARTD.y);
if(menu.STARTD.d > 31 || menu.STARTD.d < 1){
printf("The Day IS error !");
goto D1;}
if(menu.STARTD.m > 12 || menu.STARTD.m < 1){
printf("The Month IS error !");
goto D1;}
if(menu.STARTD.y > 2019 || menu.STARTD.y < 1950){
printf("The Day Years error !");
goto D1;}
D2:
printf("\nEnter  Meeting Date (D/M/Y) : ");
fflush(stdin);
scanf("%d%d%d",&menu.ENDD.	d,&menu.ENDD.m,&menu.ENDD.y);
if(menu.ENDD.d > 31 || menu.ENDD.d < 1){
printf("The Day IS error !");
goto D2;}
if(menu.ENDD.m > 12 || menu.ENDD.m < 1){
printf("The Day Month error !");
goto D2;}
if(menu.ENDD.y > 2025 || menu.ENDD.y < 2019){
printf("The Day Year error !");
goto D2;}
fflush(stdin);
all = fopen("project.dat","a+b");
fwrite(&menu,sizeof(menu),1,all);
fclose(all);
getch();
main();}
//////////////////////////////////////////////////////////////////
void display(){
struct homes dis;
FILE *all;
all = fopen("project.dat","rb");
while(1){
int set = fread(&dis,sizeof(dis),1,all);
if(set==0){break;}
printf("\n_______________________________________________\n");
printf("\nID : %d",dis.id);
printf("\nName : %s ",dis.name);
printf("\nGender : %s",dis.gender);
printf("\nState : %s", dis.state);
printf("\nDiscription Doctor : %s ",dis.dis);
printf("\nDate Of Coming : %d:%d:%d",dis.STARTD.d,dis.STARTD.m,dis.STARTD.y);
printf("\nDate Of Meeting : %d:%d:%d",dis.ENDD.d,dis.ENDD.m,dis.ENDD.y);
printf("\n\n press any key to next record !");
getch();}
main();}
//////////////////////////////////////////////////////////////////
void remove(){
struct homes del;
FILE *all,*all2;
all = fopen("project.dat","rb");
all2 = fopen("project2.dat","wb");
int id;
printf("Enter ID to rmove : ");
fflush(stdin);
scanf("%d",&id);
fflush(stdin);
int rem = 0;
while(1){
int res = fread(&del,sizeof(del),1,all);
if(res==0){break;}
if(id==del.id){rem=1;}
if(id!=del.id){
fwrite(&del,sizeof(del),1,all2);}}
fclose(all);
fclose(all2);
remove("project.dat");
rename("project2.dat","project.dat");
if(rem==1){
printf("\nthe record is delete !");}
else{printf("\n The record is not found !");}
getch();
main();}
//////////////////////////////////////////////////////////////////
void search(){
struct homes ser;
FILE *all;
all = fopen("project.dat","rb");
int id;
printf("Enter ID to Search : ");
fflush(stdin);
scanf("%d",&id);
int rem = 0;
while(1){
int res = fread(&ser,sizeof(ser),1,all);
if(res==0){break;}
if(ser.id == id){
printf("\n_______________________________________________\n");
printf("\nID : %d ",ser.id);
printf("\nName : %s ",ser.name);
printf("\nGender : %s",ser.gender);
printf("\nState : %s", ser.state);
printf("\nDIs Doctor : %s",ser.dis);
printf("\nDate Of Coming : %d:%d:%d",ser.STARTD.d,ser.STARTD.m,ser.STARTD.y);
printf("\nDate Of Meeting : %d:%d:%d",ser.ENDD.d,ser.ENDD.m,ser.ENDD.y);
printf("\n\n Press Any Key To Return MenuBar !");
rem=1;}}
fclose(all);
if(rem!=1){
printf("\nThe Record Is Not Found !");}
getch();
main();}
//////////////////////////////////////////////////////////////////
void modfay(){
struct homes mod;
FILE *all,*all2;
all = fopen("project.dat","rb");
all2 = fopen("project2.dat","wb");
int id;
printf("Enter ID to Search : ");
fflush(stdin);
scanf("%d",&id);
fflush(stdin);
int rem = 0;
while(1){
int res = fread(&mod,sizeof(mod),1,all);
if(res==0){break;}
char sol;
if(mod.id == id){
printf("\n_______________________________________________\n");
printf("\nName : %s ",mod.name);
printf("\nDo Yo Need Modfay Name (Y) !");
sol = getch();
if(sol=='y' || sol == 'Y'){
fflush(stdin);
printf("\nEnter New Name : ");
gets(mod.name);}
printf("\nStete : %s", mod.state);
printf("\nDo Yo Need Modfay state (Y) !");
sol = getch();
if(sol=='y' || sol == 'Y'){
fflush(stdin);
printf("\nEnter New state : ");
gets(mod.state);}
printf("\nDIs Dictor : %s ",mod.dis);
printf("\nDo Yo Need Modfay dis Doctor (Y)!");
sol = getch();
if(sol=='y' || sol == 'Y'){
fflush(stdin);
printf("\nEnter New dis doctor : ");
gets(mod.dis);}
printf("\nDate Of Coming : %d:%d:%d",mod.STARTD.d,mod.STARTD.m,mod.STARTD.y);
printf("\nDo Yo Need Modfay Date Of Coming (Y)!");
sol = getch();
if(sol=='y' || sol == 'Y'){
fflush(stdin);
printf("\nEnter New Date Coming : ");
scanf("%d%d%d",&mod.STARTD.d,&mod.STARTD.m,&mod.STARTD.y);}
printf("\nDate Of Meeting : %d:%d:%d",mod.ENDD.d,mod.ENDD.m,mod.ENDD.y);
printf("\nDo Yo Need Modfay Date Of Meeting (Y)!");
sol = getch();
if(sol=='y' || sol == 'Y'){
fflush(stdin);
printf("\nEnter New Date Meeting : ");
scanf("%d%d%d",&mod.ENDD.d,&mod.ENDD.m,&mod.ENDD.y);}
printf("\n\n Press Any Key To Return MenuBar !");
rem=1;}
fwrite(&mod,sizeof(mod),1,all2);}
fclose(all);
fclose(all2);
remove("project.dat");
rename("project2.dat","project.dat");
if(rem!=1){
printf("\nThe Record Is Not Found !");}
getch();
main();}
