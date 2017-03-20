/* this program is just for testing */
#include "wave.h"
#include <stdio.h>
#include <math.h>
#include <signal.h>
#include <sys/wait.h>
#include "screen.h"
#include <stdlib.h>	// eliminate the warning
int main(int argc, char *argv[]){
	FILE *fp;
	WAVHDR myhdr;
	int answer, ret;
	short int sa[SAMPLE_RATE];
/*	if(argc != 2){
		printf("Usage: %s wav_file\n", argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("Cannot find file %s\n", argv[1]);
		return -1;
	} */
	while(1){
		ret = system("arecord -r16000 -c1 -d1 -f S16_LE -q data.wav");
		clearScreen();
		if(WIFSIGNALED(ret) && (WTERMSIG(ret) == SIGINT || WTERMSIG(ret)==SIGQUIT))break;
		fp = fopen("data.wav", "r");	// open the wav file to read data
		fread(&myhdr, sizeof(myhdr), 1, fp);	// read wav header
		displayWAVHDR(myhdr);		// display wav header
		fread(&sa, sizeof(short int), SAMPLE_RATE, fp);	// read wav samples
		displayWAVdata(sa);		// calculate RMS values and display time
		fclose(fp);			// close the opened file
	}
	printf("Do you want to generate a test tone? (1: yes, 0: no)\n");
	scanf("%d", &answer);
	if (answer == 1) testTone(1000, 5);
}
	
