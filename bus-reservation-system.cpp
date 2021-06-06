
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define LSIZ 20
#define RSIZ 20

/*****************************************GLOBAL VARIABLES*************************************************************/
char line[RSIZ][LSIZ];
int tot = 20;
int seats[20];
char empt[] = "empty";

/*******************************************FUNCTION PROTOTYPE**********************************************************/
//function prototypes to be used
void reservation();	//main reservation function
void viewdetails();	//view details of all the bus
void cancel(); //cancel reservation
void printTicket(int numOfSeats,int busNumber,float charges); //print ticket
void specificbus(int busNumber); //print data related to specific bus
float charge(int busNumber,int numOfSeats);	//charge automatically w.r.t number of bus
void login(); //login function
void readFile(char fileName[]); //reads data from particular file and store it on global variable line[]
void reservedSeats(); //show reserved seats from global variable line[]
void writeFile(char fileName[]); //writes data on particular file from global variable line[]
void seatsInitialize(); //initialize seats
void bookSeat(int busNumber); //book seat
void editSeats(char name[],int index); //edit data on global variable line[]
void viewAvalableSeats(int busNumber); //show seats available in particular bus

/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/

int main()

{
    system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        ***********************************    |\n");
	printf("\t\t|        *  simple bus reservation system  *    |\n");
	printf("\t\t|        ***********************************    |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=============================================\n");
	printf("    SIMPLE BUS TICKET RESERVATION  SYSTEM");
	printf("\n=============================================");
	printf("\n1>> View All Available buses");
	printf("\n------------------------------");
	printf("\n2>> Reserve A Ticket");
	printf("\n------------------------------");
	printf("\n3>> View Available Seats");
	printf("\n------------------------------");
	printf("\n4>> Cancel Reservation");
	printf("\n------------------------------");
	printf("\n5>> Exit");
	printf("\n------------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
		    viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 2:
			reservation();
			break;
        case 3:
            int busNumber;
            viewdetails();
            printf("\n\nEnter Bus Number To See Available Seats:");
            scanf("%d",&busNumber);
            viewAvalableSeats(busNumber);
			break;
		case 4:
			cancel();
			break;
		case 5:
			return(0);
			printf("\nInvalid choice");
			getch();
	}
	goto start;
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

//list all buses and routes

void viewdetails(void)
{
	system("cls");
	printf("-----------------------------------------------------------------------------");
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("-----------------------------------------------------------------------------");
	printf("\n1001\tTexas Express\t\tTexas To LA\t\tRs.6000\t\t12pm");
	printf("\n1002\tRed Lines Express\tManhattan To Boston\tRs.5000\t\t12pm");
	printf("\n1003\tLA City Express\t\tBoston To L.A\t\tRs.4500\t\t8am");
	printf("\n1004\tLA City Express\t\tL.A To Boston\t\tRs.4500\t\t11am");
	printf("\n1005\tIron City Express\tBoston To Chicago\tRs.4000\t\t7am");
	printf("\n1006\tIron City Express\tChicago To Boston\tRs.4000\t\t9.30am");
    printf("\n1007\tKeystone Express\tBoston To Washington\tRs.3500\t\t1pm");
    printf("\n1008\tKeystone Express\tWashington To Boston\tRs.3500\t\t4pm");
    printf("\n1009\tMeteor Express\t\tBoston To Miami\t\tRs.6000\t\t3.35pm");
    printf("\n1010\tMeteor Express\t\tMiami To Boston\t\tRs.6000\t\t4.15pm");

}

/*********************************************RESERVATION()*************************************************/
// reserve n number of seats in particular bus
void reservation(){
    char fileName[50];
    int busNumber;
    int j=0;
    system("cls");
    viewdetails();
    printf("\n\nEnter bus number:");
    scanf("%d",&busNumber);
    sprintf(fileName, "%d", busNumber);
    strcat(fileName, ".txt");
    readFile(fileName);
    reservedSeats();
    seatsInitialize();
    bookSeat(busNumber);
    printf("\n====================================");
    printf("\n Reservation Done\n");
    printf("====================================");
    printf("\n\nSeat booked successfully.");
    printf("\nPress any key to return main menu.");
    getch();
}
/*********************************************CHARGE()*************************************************/
// helper function for printTicket()
float charge(int busNumber,int numOfSeats)
{
    if (busNumber==1001)
	{
		return(6000.0*numOfSeats);
	}
	if (busNumber==1002)
	{
		return(5000.0*numOfSeats);
	}
	if (busNumber==1003)
	{
		return(4500.0*numOfSeats);
	}
	if (busNumber==1004)
	{
		return(4500.0*numOfSeats);
	}
	if (busNumber==1005)
	{
		return(4000.0*numOfSeats);
	}
	if (busNumber==1006)
	{
		return(4000.0*numOfSeats);
	}
	if (busNumber==1007)
	{
		return(3500.0*numOfSeats);
	}
	if (busNumber==1008)
	{
		return(3500.0*numOfSeats);
	}
	if (busNumber==1009)
	{
		return(6000.0*numOfSeats);
	}
	if (busNumber==1010)
	{
		return(6000.0*numOfSeats);
	}
}


/*********************************************PRINTTICKET()*************************************************/
// this function print ticket
void printTicket(int numOfSeats,int busNumber,float charges)
{
	system("cls");
	printf("------------------------------------\n");
	printf("\tTICKET\n");
	printf("------------------------------------\n\n");
	printf("\nNumber Of Seats:\t%d",numOfSeats);
	printf("\nbus Number:\t\t%d",busNumber);
	specificbus(busNumber);
	printf("\nCharges:\t\t%.2f",charges);
}

/*********************************************SPECIFICBUS()*************************************************/
// helper function for printTicket()
void specificbus(int busNumber)
{
	if (busNumber == 1001)
	{
		printf("\nbus:\t\t\tTexas Express");
		printf("\nDestination:\t\tTexas to LA");
		printf("\nDeparture:\t\t12am ");
	}
	if (busNumber == 1002)
	{
		printf("\nbus:\t\t\tRed Lines Express");
		printf("\nDestination:\t\tManhattan to Boston");
		printf("\nDeparture:\t\t12pm");
	}
	if (busNumber == 1003)
	{
		printf("\nbus:\t\t\tLA City Express");
		printf("\nDestination:\t\tBoston to L.A");
		printf("\nDeparture:\t\t8am");
	}
	if (busNumber == 1004)
	{
		printf("\nbus:\t\t\tLA City Express");
		printf("\nDestination:\t\tL.A to Boston");
		printf("\nDeparture:\t\t11am ");
	}
	if (busNumber == 1005)
	{
		printf("\nbus:\t\t\tIron City Express");
		printf("\nDestination:\t\tBoston to Chicago");
		printf("\nDeparture:\t\t7am");
	}
	if (busNumber == 1006)
	{
		printf("\nbus:\t\t\tIron City Express");
		printf("\nDestination:\t\tChicago to Boston");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (busNumber == 1007)
	{
		printf("\nbus:\t\t\tKeystone Express");
		printf("\nDestination:\t\tBoston to Washington");
		printf("\nDeparture:\t\t1pm ");
	}
	if (busNumber == 1008)
	{
		printf("\nbus:\t\t\tKeystone Express");
		printf("\n Destination:\t\tWashington to Boston");
		printf("\nDeparture:\t\t4pm ");
	}
	if (busNumber == 1009)
	{
		printf("\nbus:\t\t\tMeteor Express");
		printf("\nDestination:\t\tBoston to Miami");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (busNumber == 1010)
	{
		printf("\nbus:\t\t\tMeteor Express");
		printf("\nDestination:\t\tMiami to Boston");
		printf("\nDeparture:\t\t1.15 ");
	}
}
/*********************************************LOGIN()*************************************************/
// check for user login
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL!!!!!!!!!!!!!!!!! TRY AGAIN");
		a++;

		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
/*********************************************CANCEL()*************************************************/
// cancels reservation
void cancel()
{
    char fileName[50];
    int busNumber;
    int seatNumber;
    system("cls");
    viewdetails();
	printf("\n\nEnter Bus Number:");
	scanf("%d",&busNumber);
	sprintf(fileName, "%d", busNumber);
    strcat(fileName, ".txt");
	system("cls");
	readFile(fileName);
	reservedSeats();
	printf("\n\nEnter seat number:");
    scanf("%d",&seatNumber);
    editSeats(empt,seatNumber-1);
    writeFile(fileName);
    system("cls");
    reservedSeats();
    printf("\n====================================");
    printf("\n Rservation Cancelled\n");
    printf("====================================");
    printf("\nEnter any key to return main menu.");
    getch();
}
/*********************************************READFILE()*************************************************/
// read data from particular text file and stores that data in global variable line[]
void readFile(char fileName[]){
    system("cls");
    char ch;
    int i = 0;
    FILE *p;
    p = fopen(fileName,"r");
    if(p == NULL){
        perror("Error,file not found.");
        exit(EXIT_FAILURE);
    }
   while(fgets(line[i], LSIZ, p))
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    //tot = i;
    fclose(p);
}
/*********************************************WRITEFILE()*************************************************/
// reads data from global variable line[] and stores that data in particular text file
void writeFile(char fileName[]){
    FILE *p;
    p = fopen(fileName,"w");
    if(p == NULL){
        printf("Error while opening file");
    }
    for(int i=0;i<tot;i++){
        fprintf(p, "%s\n", line[i]);
    }
    fclose(p);
}
/*********************************************RESERVEDSEATS()*************************************************/
// show reserved seats from global variable line[]
void reservedSeats(){
    int j = 0;
    printf("====================================\n");
    printf("\t Seats\t\n");
    printf("====================================\n");
    while(j<tot){
        if(line[j]){
         printf("%d:",j+1);
         printf("%s",line[j]);
        }
        if(line[j+1]){
         printf("             %d:",j+2);
        printf("%s",line[j+1]);
        printf("\n");
        }
        j += 2;
    }
}
/*********************************************SEATSINITIALIZE()*************************************************/
// initialize seats in global variable seats[]
void seatsInitialize(){
    int j=0;
    while(j<tot){
        if(strcmp(line[j],empt)){
            seats[j] = 1;/*1 means seat is already taken*/
        }else{
            seats[j] = 0;/*0 means seat is not taken*/
        }
        j++;
    }
}
/*********************************************BOOKSEAT()*************************************************/
// book n number of seat in particular bus,then print ticket
void bookSeat(int busNumber){
    char fileName[50];
    int seatNumber;
    int numberOfSeat;
    float charges;
    char name[20];
    sprintf(fileName, "%d", busNumber);
    strcat(fileName, ".txt");
    printf("Enter Number of Seats:");
    scanf("%d",&numberOfSeat);
    for(int i=0;i<numberOfSeat;i++){
        printf("Enter Seat Number:");
        scanf("%d",&seatNumber);
        if(seats[seatNumber-1] == 0){
            printf("Enter Name:");
            fflush(stdin);
            gets(name);
            editSeats(name,seatNumber-1);
            writeFile(fileName);
            system("cls");
            reservedSeats();

        }else{
            printf("This seat is not available.\n");
        }
    }
    printf("\nPress Any Key...");
    getch();
    charges = charge(busNumber,numberOfSeat);
    printTicket(numberOfSeat,busNumber,charges);
}
/*********************************************EDITSEATS()*************************************************/
// helper function for bookSeat(),cancel()
void editSeats(char name[],int index){
    strcpy(line[index], name);
}
/*****************************************VIEWAVAILABLESSEATS()*******************************************/
// shows seats available in particular bus
void viewAvalableSeats(int busNumber){
    char fileName[20];
    sprintf(fileName, "%d", busNumber);
    strcat(fileName, ".txt");
    readFile(fileName);
    reservedSeats();
    printf("\n\nPress any key to return main menu:");
    getch();
}
