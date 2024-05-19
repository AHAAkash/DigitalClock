#include<stdio.h>
#include<stdlib.h>  // clear screen
#include<time.h>   //Header file use for help to show current time and formating time
#include<unistd.h>  //sleep the system

void fill_time(char*,int); //  7. Anyone called get_time then it give current time
void fill_date(char*);
int input_format();
void clear_screen();

int main(){
  char time[50],date[100];  //5. define string that store final format of time
  int format = input_format();

  while (1)
  {
  fill_time(time,format);
  fill_date(date);
  clear_screen();
  printf("Current Time: %s\n",time);
  printf("\nCurrent Date: %s\n",date);
  sleep(1); // Sleep for one second

  }

  return 0;
}
void clear_screen(){
  //         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //noob process
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
void fill_date(char* buffer){
  time_t rawtime;
  struct tm *current_time;

  time(&rawtime);
  current_time= localtime(&rawtime);
  strftime(buffer,100 ,"%A %B %d %Y",current_time);
}
int input_format(){
  int format;

  printf("\n Choose the time format: ");
  printf("\n 1.   24 Hour format: ");
  printf("\n 2.   12 Hour format(Default): ");
  printf("\n Make a choise(1/2): ");
  scanf("%d",&format);
}

void fill_time(char* buffer,int format){
  time_t rawtime;  //1
  struct tm *current_time; //3. declare a structer for formatting current time that store in rawtime in
                           //time function

  time(&rawtime); // 2. time function (Passing reference of rawtime) that include in time.h means it fill
          //rawtime with system current time.
  current_time= localtime(&rawtime);  //4. we fixed the rawtime by local time because location differ the time
  if(format == 1){
    strftime(buffer,50 ,"%H:%M:%S",current_time);
  }else{
    strftime(buffer,50 ,"%I:%M:%S %p",current_time);      //6.strftime = String Format Time
  }
}
