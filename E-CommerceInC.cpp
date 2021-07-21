#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
//structure for details of date in product//
struct P_Date{
        int day;
		int month;
		int year;
};
//structure for store products//
struct P_Detail
{
char P_name[30];
int P_id;
float price;
int qty;
struct P_Date mfg;
};

//structure for admin//
struct Bill
{
    char customername[20];
	int number;
	float mobile_no;
	char street[100];
	char city[100];
};

void menu();
void adminmenu();
void addprod();
void editprod();
void deleteprod();
void viewall();
bool validateUser();
void customermenu();
void quit();
void firstPage();
void createCustomer();
void loginAsCustomer();
//bool validateuser();

//main Menu
int main(){
	
	menu();
firstPage();
	return 0;
}
void addprod(){
	
}
void createCustomer(){
	
}
void loginAsCustomer(){
	
}

//first Page show Up
void firstPage(){
		int choice;
	printf("enter your choice ");
	scanf("%d",&choice);
	if(choice==1){
		if(validateUser()){
			
		adminmenu();
	}
	else {
		printf("Enter valid Id or Password in order to login as Admin Thanks!!!");
	}
		}
		else if(choice==2){
		customermenu();	
		}
		else if(choice==3){
		quit();	
		}
		else
		printf("choose any valid option given THANKS! \n");	
}




void customermenu(){
	int choice;
	system("cls");
	printf("\n"	);
	printf("enter your choice?");	
	printf("1) Create Account \n");
	printf("2) Login Your Account To see Offers and discount associated with your account\n");
	printf("3) go to main page");
	scanf("%d",&choice);
	if(choice==1){
		createCustomer();
		system("cls");
		firstPage();
	}
	else if(choice==2){
		loginAsCustomer();
		system("cls");
		firstPage();
	}
	else if(choice==3){
		system("cls");
		firstPage();
	}
}

void menu(){
	printf("***********Project Name*************\n");
	printf("******Submitted By: Project MEmber 1 \t Project Member 2****\n" );
	printf("****Submitted By: Citizen College KumariPati Lalitpur Nepal (PU)****\n" );
	printf("****Project Coordinator: Er. Hem Raj Bhattarai*****\n");
	printf("Enter ANy key to continue Thanks!!!");
	getch();
	system("cls");
	printf("Enter YOur Option \n");
	printf("\n");
	printf("1) ADMIN");
	printf("\n");
	printf("2) customer");
	printf("\n");
	printf("3) QUIT");
	printf("/n");
	}
	
	
void adminmenu(){
	
	int choice;
	
	system("cls");
	printf("\n"	);
	printf("enter your choice?");	
	printf("1) Add Product to the bill \n");
	printf("2) edit product \n");
	printf("3) delete the product\n");
	printf("4) view the product \n");
	printf("5) Add Customer \n");
	printf("6) go to main page");
	scanf("%d",&choice);
	 if(choice==1){
		addprod();
	}
	else if (choice==2){
	editprod();	
	}
	else if(choice==3){
	deleteprod();	
	}
	else if(choice==4){
	viewall();	
	}
	else if(choice==5){
		createCustomer();
	}
	else if(choice==6){
	system("cls");	
	menu();
	//exit();
	}
	else {
	printf("select valid option \n");
	
	adminmenu();	
	}
}



	
 bool validateUser()
{
	char pass[20];
		char id[20];
		
		printf("ENter ID:");
		
		scanf("%s",id);
	
	printf("Enter password:");
		int index=0;
		char c;
		while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       /* 8 is ASCII value of BACKSPACE character */
       if(c == 8){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       pass[index++] = c;
       putch('*');
   }
   pass[index] = '\0';
    if(strcmp(id,"admin")==0&&strcmp(pass,"admin")==0){
    	return true;
	}
	else{
		return false;
	}
}


	
void addproduct(){
	struct P_Detail s[10];
	
	FILE *fp;
	fp=fopen("BuyerDataBase.txt","a");
	if(fp==NULL){
		printf("FIle Can not be opened");
	}
	else {
	int n,i;
    system("cls");
	printf("Enter number of products:");
	scanf("%d",&n);
	fflush(stdin);
	for (i=0;i<n;i++){	
    fflush(stdin);
    printf("Enter the product Name\n");
	scanf("%s",s[i].P_name);
	printf("Enter the product id \n");
		scanf("%d",&s[i].P_id);
	printf("Enter the rate \n");
	scanf("%f",&s[i].price);
    printf("enter the quantity");
    scanf("%d",&s[i].qty);	
	printf("Manufacturing date(dd-mm-yyyy):");
    scanf("%d%d%d",&s[i].mfg.day,&s[i].mfg.month,&s[i].mfg.year);
	}
   printf("             *****  INVENTORY *****\n");
   printf("------------------------------------------------------------------\n");
   printf("S.N.|    NAME           |   ID  |  QUANTITY |  PRICE  |MFG.DATE\n");
   printf("------------------------------------------------------------------\n");
   for (i=0;i<n;i++)
      printf("%d   %-15s   %-d  %-5d  %-5d %d/%d/%d\n",i+1,s[i].P_name,s[i].P_id,s[i].qty,s[i].price,s[i].mfg.day,s[i].mfg.month,s[i].mfg.year);
	printf("------------------------------------------------------------------\n");
	getch();
	for (i=0;i<n;i++){
fwrite(&s[i],sizeof(struct P_Detail),1,fp);
}
printf("All products has been added");
fclose(fp);
}
}


void editprod(){
		 struct P_Detail s;
	int count=0,stid;
	FILE *fp;
	FILE *temp;
	printf("ENter the id \n");
	scanf("%d",&stid);
	fp=fopen("BuyerDataBase.txt","r");
	temp=fopen("temp.txt","w");
	if(fp==NULL){
		printf("FIle Can not be opened");
	}
	else{
		while(fread(&s, sizeof(struct P_Detail), 1, fp)){
			if(stid==s.P_id){
				fflush(stdin);
		printf("Enter the Edited Name\n");
	scanf("%s",s.P_name);
		printf("Enter the Edited id \n");
		//scanf("%d",&s.p_id);
		scanf("%d",&s.P_id);
	printf("Enter the Edited quantity\n");
	scanf("%f",&s.qty);
	printf("Enter the Edited price\n");
	scanf("%d",&s.price);
				fwrite(&s,sizeof(struct P_Detail),1,temp);
				
			printf("\n");
			count++;
			}
			else{
				fwrite(&s,sizeof(struct P_Detail),1,temp);	
			}
			
	}
	if(count==0){
		printf("Data not found related with id= %d",stid);
	}
	fclose(fp);
	fclose(temp);
	
	
	if(count!=0){//Copy temp file to original file  only if there are edited information
	
	fp=fopen("BuyerDataBase.txt","w");
		temp=fopen("Database//temp.txt","r");
		while(fread(&s,sizeof(struct P_Detail),1,temp)){
			fwrite(&s,sizeof(struct P_Detail),1,fp);
		}
		fclose(fp);
		fclose(temp);
	}
}
}


void deleteprod(){
		
	
		struct P_Detail p;
		
		
	int count=0,prodid;
	FILE *fp;
	FILE *temp;
	printf("ENter the product id \n");
	scanf("%d",&prodid);
	fp=fopen("BuyerDataBase.txt","r");
	temp=fopen("temp.txt","w");
	if(fp==NULL){
		printf("FIle Can not be opened");
	}
	else{
		while(fread(&p, sizeof(struct P_Detail), 1, fp)){
			
			if(prodid==p.P_id){
	
			count++;
			}
			else{
				fwrite(&p,sizeof(struct P_Detail),1,temp);	
			}
			
	}
	if(count==0){
		printf("Data not found related to the product = %d",prodid);
	}
	fclose(fp);
	fclose(temp);
	fp=fopen("BuyerDataBase.txt","w");
		temp=fopen("temp.txt","r");
		while(fread(&p,sizeof(struct P_Detail),1,temp)){
			fwrite(&p,sizeof(struct P_Detail),1,fp);
		}
		fclose(fp);
		fclose(temp);
		
		
	}
}
//viewing the foods in file
void viewall(){
	int i=0;
		FILE *fp;
	struct P_Detail s;
	fp=fopen("BuyerDataBase.txt","r");
	if(fp==NULL){
		printf("File can not be opened \n");
		printf("Press any key to continue@ \n");
		getch();
		system("cls");
		adminmenu();
	}
	else{
	printf("             *****  INVENTORY *****\n");
   printf("------------------------------------------------------------------\n");
   printf("S.N.|    NAME           |   ID  |  QUANTITY |  PRICE  |MFG.DATE\n");
   printf("------------------------------------------------------------------\n");
   while(fread(&s,sizeof(struct P_Detail),1,fp)){
   }
   printf("%d   %-15s   %-d  %-5d  %-5d %d/%d/%d\n",i+1,s.P_name,s.P_id,s.qty,s.price,s.mfg.day,s.mfg.month,s.mfg.year);
	printf("------------------------------------------------------------------\n");
		}
		printf("Press any key to continue@ \n");
		getch();
		system("cls");
		adminmenu();
	}
			
void quit(){
exit(0);
}

void customer_detail()
{	
    FILE *bill;
	struct Bill s;
	bill=fopen("customer_bill.txt","r");
	if(bill==NULL){
		printf("File can not be opened \n");
		printf("Press any key to continue@ \n");
		getch();
		system("cls");
		adminmenu();
	}
	else{
	while(fread(&s,sizeof(struct P_Detail),1,bill)){
		printf("\n\n    Customer no    :%d\n",s.number);
	   printf("    Name 	   :%s\n",s.customername);
	   printf("    Mobile no      :%.f\n",s.mobile_no);
	   printf("    Street         :%s\n",s.street);
	   printf("    City           :%s\n",s.city);
	}

	   }	
}
