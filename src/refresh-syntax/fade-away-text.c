#include "constants.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
printf(CLEAR_TERMINAL);
printf(HIDE_CURSOR);
  char *banners[] = {
    "I have to pee now",
    "AHHHHHHHHHHHHHHHHHHHH",
    "Let's parse this bitch",
    "Okeeeeeeeeeeey, let's go",
    "From great powers comes great responsibility",
    NULL
  };
  int max = 0;
  for(char **b = banners; *b!=NULL;b++){
    char *banner = *b;
    int bannerSize = strlen(banner);
    if(bannerSize>max){
      max=bannerSize;
    }
    int counter = 0;
    char l_char;
    char g_char;
    char d_char;
    char f_char;
    char t_char;
    char r_char;
    for(char *p=banner; *p!='\0'; p++){
      if (counter+1<bannerSize){


        usleep(SLEEP_TIME);
        if(counter>=6)
          printf("\033[1;%dH%s%c",counter-5,VERY_DARK_GRAY, r_char);
        if(counter>=5)
          printf("\033[1;%dH%s%c",counter-4,VERY_DARK_GRAY, t_char);
        if(counter>=4)
          printf("\033[1;%dH%s%c",counter-3,DARKER_GRAY, f_char);
        if(counter>=3)
          printf("\033[1;%dH%s%c",counter-2,DARK_GRAY, d_char);
        if(counter>=2)
          printf("\033[1;%dH%s%c",counter-1,MEDIUM_GRAY, g_char);
        if (counter>=1)
          printf("\033[1;%dH%s%c",counter,LIGHT_GRAY, l_char);
        printf("\033[1;%dH%s%c",counter+1,WHITE_COLOR, *p);
        
        r_char = t_char;
        t_char = f_char;
        f_char = d_char;
        d_char = g_char;
        g_char = l_char;
        l_char = *p;

      }else{
        printf("%c",*p);
        for(int i=max-bannerSize; i!=0; i--){
          printf("%s", RESET_COLOR);
          max = 0;
        }
      }

      
      fflush(stdout);
      counter++;

    }

    //printf("%s\033[1;%dH%c", RESET_COLOR,counter,last_char);
    printf("%s", CLEAR_TERMINAL);
  }

printf(SHOW_CURSOR);
return 0;
}
