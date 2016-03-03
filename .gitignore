/*##################################################################*/
/*HW08_<IlaydaZeynep>_<Ozdemir>_<131044022>_part2.c                 */
/*_____________________________________                             */
/*Written by Ilayda Ozdemir                                         */
/*Input:                                                            */
/*  -Request of appointments 	                                    */ 
/*  -Information of people                                          */
/*Output:                                                           */
/*  -Appointments list (for available date)                         */
/*##################################################################*/



#include <stdio.h>
#include <string.h>
#define STRING_SIZE 30
#define SIZE_OF_ARRAY 100
#define MAX_SIZE 50

typedef enum {
	MALE,FEMALE
}Gender_t;

typedef enum {
	JANUARY=1,FEBRUARY=2,MARCH=3,APRIL=4,MAY=5,JUNE=6,JULY=7,AUGUST=8,SEPTEMBER=9,OCTOBER=10,NOVEMBER=11,DECEMBER=12
}Months_t;

typedef struct {
	int first_half,
		second_half; 
}TCId_no_t;

typedef struct {
	TCId_no_t id_no;
	char name[STRING_SIZE];
	char surname[STRING_SIZE];
	Gender_t gender;	
}People_t;

typedef struct {
	int hour,
		minute;
}Time_t;

typedef struct {
	int year;
	Months_t month;
	int day;
	Time_t time;
		
}Date_t;

typedef struct {
	People_t people;
	Date_t date;	
}Appointment_t;

/*People.txt'deki bilgilerle people arrayini doldurur.Size'ini dondurur.*/
int get_people(const char *file_name, People_t people[], int max_size);
/*AppointmentReqs.txt'deki bilgilerle appointments arrayini doldurur.Size'ini dondurur.*/
int get_appointments(const char *file_name, Appointment_t appointments[], int max_size); 
/*id.no'lari karsilastirarak insanlarin appointments arrayindeki bilgilerini tamamlar*/
void write_names(Appointment_t appointments[], int size_app, const People_t people[], int size_people); 
/*ayni randevu bir kac kisiye verildiyse bir tanesini alip digerlerini siliyor. Yeni size'i donduruyor*/
int check_appointments(Appointment_t appointments[], int size);
/*Yer degisimi yapar.Sort fonksiyonu icin yazdim*/
void swap(Appointment_t array[],int i,int j,int size);
/*Tarihlere gore siralar*/
void sort_appointments(Appointment_t appointments[], int size);
/*Dosyaya yazdirir*/
void write_appointments(const char *file_name, Appointment_t appointments[], int size);

/***************************************************************/
/*                       MAIN                                  */
/***************************************************************/
int main(void)
{
	char file1[STRING_SIZE]="People.txt";
	char file2[STRING_SIZE]="AppointmentReqs.txt";
	char file3[STRING_SIZE]="Appointments.txt";
	int size_appoint,
		size_peop,
		new_size;
	People_t people[SIZE_OF_ARRAY];
	Appointment_t appointments[SIZE_OF_ARRAY];
	
	size_peop=get_people(file1,people,MAX_SIZE);
	
	size_appoint=get_appointments(file2,appointments,MAX_SIZE);
	
	write_names(appointments,size_appoint,people,size_peop);
	
	new_size=check_appointments(appointments,size_appoint);
	
	sort_appointments(appointments,new_size);
	
	write_appointments(file3,appointments,new_size);
	
	return 0;
}

/**********************************************************************************************/
/* reads all people from the file and record them into the array. Returns number records read.*/
/**********************************************************************************************/

int get_people(const char *file_name, People_t people[], int max_size)
{
	FILE *inp;
	int i=0,status;
	char c;
	if((inp=fopen(file_name,"r")) == NULL)
	{	
		return 1;
		printf("ERROR!!! File1 is not open!\n");	
	}
	status=fscanf(inp,"%5d%6d%s %s %c",&(people[i].id_no.first_half),&(people[i].id_no.second_half),people[i].name,people[i].surname,&c);
	while(status!=EOF && i<=max_size)
	{
		people[i].gender=(Gender_t)c;
		++i;
		status=fscanf(inp,"%5d%6d%s %s %c",&(people[i].id_no.first_half),&(people[i].id_no.second_half),people[i].name,people[i].surname,&c);
	}
	fclose(inp);
	return (i);
}

/************************************************************************************************************************/
/*reads all appointment records from the file and record them into the array leaving name and surname fields unassigned.*/ 
/*Returns number records read.																							*/
/************************************************************************************************************************/

int get_appointments(const char *file_name, Appointment_t appointments[], int max_size)
{
	FILE *inp;
	int i=0,status;
	int mon;
	char ch;
	if((inp=fopen(file_name,"r")) == NULL){	
		printf("ERROR!! File2 is not open!\n");
		return 1;
	}
	status=fscanf(inp,"%5d %6d %d %d %d %2d%c%2d",&(appointments[i].people.id_no.first_half),&(appointments[i].people.id_no.second_half),
										&(appointments[i].date.year),&mon,&(appointments[i].date.day),
										&(appointments[i].date.time.hour),&ch,&(appointments[i].date.time.minute));	
	while(status!=EOF && i<=max_size)
	{
		switch(mon)
		{
			case 1: appointments[i].date.month=JANUARY;		break;
			case 2:	appointments[i].date.month=FEBRUARY;	break;
			case 3:	appointments[i].date.month=MARCH;		break;
			case 4:	appointments[i].date.month=APRIL;		break;
			case 5:	appointments[i].date.month=MAY;			break;
			case 6:	appointments[i].date.month=JUNE;		break;
			case 7:	appointments[i].date.month=JULY;		break;
			case 8:	appointments[i].date.month=AUGUST;		break;
			case 9:	appointments[i].date.month=SEPTEMBER;	break;
			case 10:appointments[i].date.month=OCTOBER;		break;
			case 11:appointments[i].date.month=NOVEMBER;	break;
			case 12:appointments[i].date.month=DECEMBER;	break;
		}
		++i;
		status=fscanf(inp,"%5d %6d %d %d %d %2d%c%2d",&(appointments[i].people.id_no.first_half),&(appointments[i].people.id_no.second_half),
										&(appointments[i].date.year),&mon,&(appointments[i].date.day),
										&(appointments[i].date.time.hour),&ch,&(appointments[i].date.time.minute));
	}
	fclose(inp);
	return (i);
}

/*********************************************************************/
/*fills the name and surname fields of people fields of appointments.*/
/*********************************************************************/

void write_names(Appointment_t appointments[], int size_app, const People_t people[], int size_people)
{
	int i=0,j=0;	
	while(i<size_people && j<size_app)
	{
		if(people[i].id_no.first_half == appointments[j].people.id_no.first_half){
			if(people[i].id_no.second_half == appointments[j].people.id_no.second_half){
				strcpy(appointments[j].people.name,people[i].name);
				strcpy(appointments[j].people.surname,people[i].surname);
				appointments[j].people.gender = people[i].gender;
			}
	    }
	  	++j;
	  	++i;
	}

}

/**************************************************************************************************************/
/*considers all appointment requests, deletes the rejected ones and returns the new size as the return value.*/
/**************************************************************************************************************/

int check_appointments(Appointment_t appointments[], int size)
{
	int i,j,k,count=0;
	int keep_size=size;					

	/*bu 2 dongu new_size'i yani fonksiyonun return degerini elde etmek icin*/
	for(i=0;i<keep_size;++i){	
		for(j=i+1;j<keep_size;++j){
			if(	appointments[i].date.year == appointments[j].date.year && 
				appointments[i].date.month == appointments[j].date.month &&
				appointments[i].date.day == appointments[j].date.day &&
				appointments[i].date.time.hour == appointments[j].date.time.hour &&
				appointments[i].date.time.minute == appointments[j].date.time.minute) {	
					j=keep_size;/*ikinci for dongusunden cikmasi icin*/
					--size;
			}
		}
	}
/*----------------------------------bu kisim silme islemi icin------------------------------------------*/
	for (k = 0; k<keep_size; ++k){ 		/*k sayacli dongu butun elemanlar icin bastan kontrol etsin diye*/
		for(i=0;i<keep_size;++i){ 		/*bir elemani alir ve j indexlilerle karsilastiririz*/	
			for(j=i+1;j<keep_size;++j){ /*karsilatirdigimiz elemanlarin indexleri icin*/
				if(	appointments[i].date.year == appointments[j].date.year && 
					appointments[i].date.month == appointments[j].date.month &&
					appointments[i].date.day == appointments[j].date.day &&
					appointments[i].date.time.hour == appointments[j].date.time.hour &&
					appointments[i].date.time.minute == appointments[j].date.time.minute) {	
						appointments[j]=appointments[j+1]; /*eger ayni randevu verilmisse silmek icin bir sonraki kisi*/
														   /*bir ust siraya kaydirilir.							      */
				}
			}
		}
	}
/*printf("**%d**\n",size );*/
return (size);
}

/**********************************************************/
/*				   swap function						  */
/**********************************************************/
void swap(Appointment_t array[],int i,int j,int size)
{
	Appointment_t temp[100];
	temp[i]=array[i];
	array[i]=array[j];
	array[j]=temp[i];
}

/**************************************************************/
/* sort the array with respect to the date of the appointment.*/
/**************************************************************/
void sort_appointments(Appointment_t appointments[], int size)
{
	int i,j;
	/*Appointment_t temp[100];*/

	for (i = 0; i < size; ++i)
	{
		for (j = i+1; j < size; ++j)

		{
			if(appointments[i].date.year > appointments[j].date.year )	
				swap(appointments,i,j,size);
			
			else if(appointments[i].date.year == appointments[j].date.year && appointments[i].date.month > appointments[j].date.month )
				swap(appointments,i,j,size);

			else if(appointments[i].date.year == appointments[j].date.year && appointments[i].date.month == appointments[j].date.month && 
					appointments[i].date.day > appointments[j].date.day)			
				swap(appointments,i,j,size);

			else if(appointments[i].date.year == appointments[j].date.year && appointments[i].date.month == appointments[j].date.month && 
					appointments[i].date.day == appointments[j].date.day && appointments[i].date.time.hour > appointments[j].date.time.hour )	
				swap(appointments,i,j,size);

			else if(appointments[i].date.year == appointments[j].date.year && appointments[i].date.month == appointments[j].date.month && 
					appointments[i].date.day == appointments[j].date.day && appointments[i].date.time.hour == appointments[j].date.time.hour &&
					appointments[i].date.time.minute > appointments[j].date.time.minute)	
				swap(appointments,i,j,size);
		}		
	}
}

/*****************************************/
/*writes all appointments to a text file.*/
/*****************************************/

void write_appointments(const char *file_name, Appointment_t appointments[], int size)
{
	FILE *outp;
	int i;
	if((outp=fopen(file_name,"w")) == NULL )
		printf("ERROR!!!File3 is not open.");
	
	for ( i = 0; i < size; ++i)
	{
		fprintf(outp," %4d %2d %2d %2d%c",appointments[i].date.year,appointments[i].date.month,appointments[i].date.day,
										  appointments[i].date.time.hour,':');												
		if(appointments[i].date.time.minute == 0) /*Mesela 12:00 gibi bir saati "12:0 " olarak yazmasın diye*/
			fprintf(outp,"0%d ",appointments[i].date.time.minute);
		else
			fprintf(outp,"%2d ",appointments[i].date.time.minute);

		fprintf(outp," %5d%6d %-10s %-10s %c\n",appointments[i].people.id_no.first_half,appointments[i].people.id_no.second_half,
			 									appointments[i].people.name,appointments[i].people.surname,
			 									appointments[i].people.gender);
	}
	fclose(outp);
}
/*##################################################################*/
/*    End of HW08_<IlaydaZeynep>_<Ozdemir>_<131044022>_part2.c      */
/*##################################################################*/
