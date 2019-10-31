#include<stdio.h>
#include<time.h>


void Timestamp(char Timestamp[200])
{

  time_t rawtime;
  struct tm *timeinfo;
  
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(Timestamp,200, "%Y%m%d-%H:%M:%S", timeinfo);
  puts(Timestamp);
}
