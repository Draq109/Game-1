
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"

/*{pal:"nes",layout:"nes"}*/
void write_message(unsigned int adr,const char *str)
{
  vram_adr(adr);
  vram_write(str,strlen(str));
};
void clear_screen(void) {
	vram_adr(0x2000);
	vram_fill(' ' - 0x20, 0x0400);
}
void draw_title_screen(void) {
    	ppu_off();
	oam_clear();
  	

    
    	write_message(NTADR_A(6, 12), "Traveling Adventure");
	write_message(NTADR_A(9, 15), "City of Ledus");
	write_message(NTADR_A(10, 18), "Press Start!");
	ppu_on_all();
	while(1){ 
	if (pad_trigger(0) & PAD_START){
          ppu_off();
          clear_screen();
          break;}
        };
	
};

void start_scenario(){
      
      write_message(NTADR_A(9,15),"                  ");
      write_message(NTADR_A(2,2), "As you are traveling the ro ");
      write_message(NTADR_A(2,4), "-ad you notice a wagon stuck");
      write_message(NTADR_A(2,6),"on the side of the road.You");
      write_message(NTADR_A(2,8),"see a lady with an elegant  ");
      write_message(NTADR_A(2,10),"man trying to push the wagon");
      write_message(NTADR_A(2,12),"out.                        ");
      write_message(NTADR_A(2,14),"                  ");
      write_message(NTADR_A(2,16),"Press A to help them");
      write_message(NTADR_A(2,18),"Press B to ignore them.");
};
void scenario_0_a(){
      write_message(NTADR_A(2,2), "You approach the couple and ");
      write_message(NTADR_A(2,4), "are greeted with a smile.The");
      write_message(NTADR_A(2,6), "wagon is pulled out from the");
      write_message(NTADR_A(2,8), "mud.The couple is grateful  ");
      write_message(NTADR_A(2,10),"and while they seem nervous ");
      write_message(NTADR_A(2,12),"to offer you a ride,they do ");
      write_message(NTADR_A(2,14),"give you plenty of water and");
      write_message(NTADR_A(2,16),"food,the couple sets off.   ");
      write_message(NTADR_A(2,18),"                            ");
      write_message(NTADR_A(2,20),"Press Start to continue...  ");
};
void scenario_0_b(){
      write_message(NTADR_A(2,2), "The couple gives you a scowl");
      write_message(NTADR_A(2,4), "and you hear some angry murm");
      write_message(NTADR_A(2,6), "-uring as you go along your ");
      write_message(NTADR_A(2,8), "way.                        ");
      write_message(NTADR_A(2,10),"                            ");
      write_message(NTADR_A(2,12),"Press Start to continue...  ");
      write_message(NTADR_A(2,14),"                            ");
      write_message(NTADR_A(2,16),"                            ");
      write_message(NTADR_A(2,18),"                            ");
};

void scenario_1(){
      write_message(NTADR_A(2,2), "The sun starts setting in.  ");
      write_message(NTADR_A(2,4), "You begin looking for a plac");
      write_message(NTADR_A(2,6), "-e to rest for tonight.Thats");
      write_message(NTADR_A(2,8), "when you start hearing loud ");
      write_message(NTADR_A(2,10),"growling.You encounter a dog");
      write_message(NTADR_A(2,12),"who looks quite hungry.     ");
      write_message(NTADR_A(2,14),"                            ");
      write_message(NTADR_A(2,16),"Press A to run away         ");
      write_message(NTADR_A(2,18),"Press B to feed him         ");
      write_message(NTADR_A(2,20),"                            ");
};
void scenario_1_a(){
      write_message(NTADR_A(2,2), "As you runaway you are bit  ");
      write_message(NTADR_A(2,4), "on your leg. After a while  ");
      write_message(NTADR_A(2,6), "you turn around and the dog ");
      write_message(NTADR_A(2,8), "is no longer chasing you.   ");
      write_message(NTADR_A(2,10),"You tend to your leg with a ");
      write_message(NTADR_A(2,12),"white cloth,it does not do  ");
      write_message(NTADR_A(2,14),"much. You spend the night   ");
      write_message(NTADR_A(2,16),"under a tree.                ");
      write_message(NTADR_A(2,18),"Press Start to continue...  ");
      write_message(NTADR_A(2,20),"                            ");
  
  
  
};
void scenario_1_b(){
      write_message(NTADR_A(2,2), "You extend a piece of bread ");
      write_message(NTADR_A(2,4), "to the dog. The dog settles ");
      write_message(NTADR_A(2,6), "down and wags his tail as he");
      write_message(NTADR_A(2,8), "begins to eat. The dog wont ");
      write_message(NTADR_A(2,10),"stop following you. You've  ");
      write_message(NTADR_A(2,12),"gained a new pet!You spend  ");
      write_message(NTADR_A(2,14),"the night under a tree.     ");
      write_message(NTADR_A(2,16),"Press Start to continue...  ");
      write_message(NTADR_A(2,18),"                            ");
};

void middle_scenario(char * choices){
      write_message(NTADR_A(2,2), "Its sunrise and you are more");
      write_message(NTADR_A(2,4), "than halfway to the city.   ");
      write_message(NTADR_A(2,6), "You continue your journey   ");
      if(choices[0]== 'a' && choices[1] == 'b'){
      write_message(NTADR_A(2,8), "with your new pet and enough");
      write_message(NTADR_A(2,10),"food to arrive to the city  ");
      }
      else if(choices[0]=='a' && choices[1] == 'a'){
      write_message(NTADR_A(2,8), "with a wound and plenty of  ");
      write_message(NTADR_A(2,10),"food to arrive to the city  ");
      }
      else if(choices[0]=='b' && choices[1] == 'b'){
      write_message(NTADR_A(2,8), "with your new pet and hardly");
      write_message(NTADR_A(2,10),"any food.                   ");
      }
      else if(choices[0]=='b' && choices[1] == 'a'){
      write_message(NTADR_A(2,8), "with a wound and hardly any ");
      write_message(NTADR_A(2,10),"food.The situation looks bad");
      }
      
      write_message(NTADR_A(2,12),"                            ");
      write_message(NTADR_A(2,14),"                            ");
      write_message(NTADR_A(2,16),"Press SELECT to continue... ");
      write_message(NTADR_A(2,18),"                            ");
};

void scenario_2(){
      write_message(NTADR_A(2,2), "As you are making your way  ");
      write_message(NTADR_A(2,4), "down the road, you hear a   ");
      write_message(NTADR_A(2,6), "rustling sound coming from  ");
      write_message(NTADR_A(2,8), "the bushes.You stop to look ");
      write_message(NTADR_A(2,10),"around, when suddenly a pack");
      write_message(NTADR_A(2,12),"of bandits jump from both   ");
      write_message(NTADR_A(2,14),"sides of the road!          ");
      write_message(NTADR_A(2,16),"Press A to run away         ");
      write_message(NTADR_A(2,18),"Press B to try to bargain   ");
      write_message(NTADR_A(2,20),"                            ");
};
void scenario_2_a(char * choices){
  if(choices[1] == 'b'){ 
      write_message(NTADR_A(2,2), "You try to make an escape,  ");
      write_message(NTADR_A(2,4), "and start running as quickly");
      write_message(NTADR_A(2,6), "as possible. Thankfully the ");
      write_message(NTADR_A(2,8), "dog bought enough time for  ");
      write_message(NTADR_A(2,10),"you to escape. Unfortunately");
      write_message(NTADR_A(2,12),"your dog most likely died.  ");
      write_message(NTADR_A(2,14),"                            ");
      write_message(NTADR_A(2,16),"                            ");
      write_message(NTADR_A(2,18),"Press Start to continue...  ");
      write_message(NTADR_A(2,20),"                            ");
        }
  else{
      write_message(NTADR_A(2,2), "You try to make an escape,  ");
      write_message(NTADR_A(2,4), "and start running as quickly");
      write_message(NTADR_A(2,6), "as possible.Unfortunately   ");
      write_message(NTADR_A(2,8), "with that wound you are caug");
      write_message(NTADR_A(2,10),"-ht almost immediately...    ");
      write_message(NTADR_A(2,12),"You are dead...             ");
      write_message(NTADR_A(2,14),"                            ");
      write_message(NTADR_A(2,16),"Game Over                   ");
      write_message(NTADR_A(2,18),"                            ");
      write_message(NTADR_A(2,20),"                            ");
      } 
  
  
};
void scenario_2_b(char * choices){
  if(choices[0] == 'a'){
      write_message(NTADR_A(2,2), "While the bandits surround  ");
      write_message(NTADR_A(2,4), "you, you plead for your life");
      write_message(NTADR_A(2,6), "offering them all the food  ");
      write_message(NTADR_A(2,8), "and water you have on you.  ");
      write_message(NTADR_A(2,10),"The bandit leader takes your");
      write_message(NTADR_A(2,12),"food and decides to let you ");
      write_message(NTADR_A(2,14),"go.                         ");
      write_message(NTADR_A(2,16),"Press Start to continue...  ");
      write_message(NTADR_A(2,18),"                            ");
  }
  else
  {
      write_message(NTADR_A(2,2), "While the bandits surround  ");
      write_message(NTADR_A(2,4), "you, you plead for your life");
      write_message(NTADR_A(2,6), "offering them all the food  ");
      write_message(NTADR_A(2,8), "and water you have on you.  ");
      write_message(NTADR_A(2,10),"The bandit leader laughs and");
      write_message(NTADR_A(2,12),"says \"you have nothing of  ");
      write_message(NTADR_A(2,14),"value\"This does not end well");
      write_message(NTADR_A(2,16),"You are dead...             ");
      write_message(NTADR_A(2,18),"                            ");
      write_message(NTADR_A(2,20),"Game Over                   ");
  }
};
void you_won_scenario(){
      write_message(NTADR_A(2,2), "You finally made it to the  ");
      write_message(NTADR_A(2,4), "city of Ledus! Congrats you ");
      write_message(NTADR_A(2,6), "have Won.                   ");
      write_message(NTADR_A(2,8), "                            ");
      write_message(NTADR_A(2,10),"Thanks for playing!         ");
      write_message(NTADR_A(2,12),"                            ");
      write_message(NTADR_A(2,14),"                            ");
      write_message(NTADR_A(2,16),"                            ");
      write_message(NTADR_A(2,18),"                            ");
      write_message(NTADR_A(2,20),"                            ");
};

  

const char PALETTE[16] = { 
  0x08,			// screen color

  0x11,0x30,0x27,0x0,	// background palette 0
  0x1c,0x20,0x2c,0x0,	// background palette 1
  0x00,0x10,0x20,0x0,	// background palette 2
  0x06,0x16,0x26	// sprite palette 3
};

void main(void)
{
  char pad1; // our controller input
  int start_flag[3] = {0,0,0}, middle_point_flag = 0; //keeps track on whether the user has pressed start to start a scenario
  int scenarioflag[3]={0,0,0}; //keeps track of what scenarios have been done
  char choicesmade[3] = {'x','x','x'}; //choices made at each scenario
  pal_bg(PALETTE); // The colors we chose for our attribute table
  // draw message  
  draw_title_screen();
  clear_screen();
  
 
  vrambuf_clear();
  set_vram_update(updbuf);
  // enable rendering
  ppu_on_all();
 
  // infinite loop
  while(1) {
   pad1 = pad_poll(0); // reading controler input
    //vrambuf_clear();
    
    //Scenario#1 
    
    if(pad1 & PAD_START && start_flag[0] == 0) // 
    {
      ppu_off();
      start_scenario();
      start_flag[0] = 1;
      ppu_on_all();
    }
    
    if (start_flag[0] == 1 && scenarioflag[0] == 0){ //if the scenario has been started and that scenario has not been done before
      					 	     //we want these to be our choices when we press a or b
    	if(pad1 & PAD_A){
      	ppu_off();
      	scenario_0_a();
      	choicesmade[0] = 'a';
      	scenarioflag[0] = 1;
      	ppu_on_all();
    	}
    	else if(pad1 & PAD_B){
      	ppu_off();
      	scenario_0_b();
      	choicesmade[0] = 'b';
      	scenarioflag[0] = 1;
      	ppu_on_all();
    	}
      	continue; //continue assures us that the while loop starts fresh from the top and does not go on to further scenes below
    }
    
     //Scenario#2
     if(pad1 & PAD_START && start_flag[1]==0){
	start_flag[1] = 1;
	ppu_off();
	scenario_1();
	ppu_on_all();
        continue;
       } 
    
     if (start_flag[1] == 1 && scenarioflag[1] == 0){
       	if (pad1 & PAD_A){
      	ppu_off();
      	scenario_1_a();
      	choicesmade[1] = 'a';
      	scenarioflag[1] = 1;
      	ppu_on_all();
    	}
    	else if(pad1 & PAD_B){
      	ppu_off();
      	scenario_1_b();
      	choicesmade[1] = 'b';
      	scenarioflag[1] = 1;
      	ppu_on_all();
    	}
       continue;
     }
    
      //middle point
     if(middle_point_flag == 0 && scenarioflag[1] == 1 && pad1 & PAD_START){
       ppu_off();
       middle_scenario(choicesmade);
       middle_point_flag = 1;
       ppu_on_all();
       continue;
     }
    
      //Scenario#3
     if(pad1 & PAD_SELECT && start_flag[2]==0){
	start_flag[2] = 1;
	ppu_off();
	scenario_2();
	ppu_on_all();
        continue;
       } 
    
     if (start_flag[2] == 1 && scenarioflag[2] == 0){
       	if (pad1 & PAD_A){
      	ppu_off();
      	scenario_2_a(choicesmade);
        if(choicesmade[1]=='a'){
          ppu_on_all();
          while(1){};//do nothing game over
        }
      	choicesmade[2] = 'a';
      	scenarioflag[2] = 1;
      	ppu_on_all();
    	}
    	else if(pad1 & PAD_B){
      	ppu_off();
      	scenario_2_b(choicesmade);
        if(choicesmade[0]=='b'){
          ppu_on_all();
          while(1){};//do nothing game over
        }
      	choicesmade[2] = 'b';
      	scenarioflag[2] = 1;
      	ppu_on_all();
    	}
       continue;
     }
    if(pad1 & PAD_START && scenarioflag[2] == 1){
	ppu_off();
	you_won_scenario();
	ppu_on_all();
      while(1){};//do nothing
        continue;
       } 
    
  }
}
