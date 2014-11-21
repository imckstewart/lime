/*
 *  curses.c
 *  LIME, The versatile 3D line modeling environment 
 *
 *  Created by Christian Brinch on 29/10/08.
 *  Copyright 2006-2014, Christian Brinch, 
 *  <brinch@nbi.dk>
 *  Niels Bohr institutet
 *  University of Copenhagen
 *	All rights reserved.
 *
 */

#include <curses.h>
#include <time.h>

void
greetings(){
#ifndef DEBUG
	initscr();
	printw("*** LIME, The versatile line modeling engine, Ver.1.31\n*** Copyright 2006--2014, Christian Brinch <brinch@nbi.dk>\n");
	refresh();	
#endif
}

void
screenInfo(){
#ifndef DEBUG
  move(4,4);  printw("Building grid      :");
  move(4,51); printw("|");
  move(5,4);  printw("Smoothing grid     :");
  move(5,51); printw("|");
  move(7,4);  printw("Statistics         :");
  move(9,4);  printw("Iterations         :"); 
  move(10,4); printw("Propagating photons:");
  move(10,51);printw("|");
  move(13,4); printw("Ray-tracing model  :");
  move(13,51);printw("|");
  move(4,60); printw("|      Molecular data");
  move(5,60); printw("|");
  move(6,60); printw("|");  
  move(7,60); printw("|");
  move(8,60); printw("|");
  move(9,60); printw("|");
  move(10,60); printw("|");
  move(11,60); printw("|");
  move(12,60); printw("|");
  move(13,60); printw("|");
  move(14,60); printw("|");
  refresh();	
#endif
}

void
done(int line){
#ifndef DEBUG
	move(line,52); printw(" [ok]");
    refresh();
#endif
}

void
progressbar(double percent, int line){
#ifndef DEBUG
  int i;
  for(i=0;i<(int)(percent*25.);i++){
    move(line,25+i);
    printw("#");
  }
  refresh();
#endif
}

void 
progressbar2(int prog, double percent, double minsnr, double median){
#ifndef DEBUG
  move(7,38); printw("                    ");            
  move(8,38); printw("                    ");
  if(minsnr<1000){
    move(7,25); printw("Min(SNR)    %3.3f", minsnr);
  } else {
    move(7,25); printw("Min(SNR)    %.3e", minsnr);
  }
  if(median<1000){
    move(8,25);	printw("Median(SNR) %3.3f", median);
  } else {
    move(8,25); printw("Median(SNR) %.3e", median);
  }    
  move(9,25+prog); printw("#");
  if(percent<100) {
    move(10,25);	 printw("                         ");
  }
  refresh();	
#endif
}

void 
goodnight(int initime, char filename[80]){
#ifndef DEBUG
	int runtime=time(0)-initime;
	move(14,4); printw("Output written to %s", filename);
	move(22,0); printw("*** Program ended succesfully               ");
	move(22,58); printw("runtime: %3dh %2dm %2ds", runtime/3600, runtime/60%60, runtime%60);
	move(23,0); printw("*** [Press any key to quit]");
    refresh();
	getch();
	endwin();
#endif
}

void
quotemass(double mass){
#ifndef DEBUG
  move(21,6); printw("Total mass contained in model: %3.2e solar masses", mass);
  refresh();
#endif
}



void 
warning(char message[80]){
#ifndef DEBUG
	move(22,0); printw("*** %s\n",message);
	refresh();
#endif
}

void 
bail_out(char message[80]){
#ifndef DEBUG
	move(22,0); printw("*** %s",message);
	move(23,0); printw("*** [Press any key to quit]");
    refresh();
	getch();
	endwin();
#endif
}

void
collpartmesg(char molecule[90], int partners, int specnumber){
#ifndef DEBUG
  move(6,63); printw("%.25s", molecule);
  move(7,63); printw("%d collision partner(s):", partners);

  refresh();
#endif
}

void
collpartmesg2(char name[10], int partner){
#ifndef DEBUG
  move(8,63); printw("%s ",name);
  refresh();
#endif
}

void
collpartmesg3(int number, int flag){
#ifndef DEBUG
  move(10,63); printw("Model provides:");
  move(11,63); printw("%d density profile(s)", number);
  if(flag==1) {
    move(13,63); printw("*** Warning! ***");  
    move(14,63); printw("Too few density profiles");  
  }
  refresh();
#endif
}
