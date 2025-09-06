#include "constants.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
  const char* grayShade[] = GRAY_SCALE_ORD;

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
    char nCharArr[FADE_SIZE] = {0};
    for(char *p=banner; *p!='\0'; p++){

        //-------- SHADE THE BITCH --------
        usleep(SLEEP_TIME);
        for(int i = 0; i < FADE_SIZE && counter>=i+1; i++){
          printf("\033[1;%dH%s%c",counter-i, grayShade[i], nCharArr[i]);
        }
        //---------------------------------

        printf("\033[1;%dH%s%c",counter+1,WHITE_COLOR, *p);

        //NOTE: Shifting right array logic
        for(int i=FADE_SIZE-1; i>0; i--){
          nCharArr[i] = nCharArr[i-1];
        }
        
        nCharArr[0] = *p;
      //NOTE: Flush the printf or it will buffer
      fflush(stdout);
      counter++;
    }

    printf("%s", CLEAR_TERMINAL);
  }

  printf(SHOW_CURSOR);
  return 0;
}
