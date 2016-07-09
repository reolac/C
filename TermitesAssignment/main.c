   #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>



 const float FPS = 60; //target frames per second
     typedef struct Termite { 
 int x; 
 int y; 
 int carrying; 
} Termite; 

    int width = 10;
    int height = 10;
    int numWoodchips = 2;
    int numTermites = 6;
    int cellSize = 50;

int* createEnvironment(); 
void printEnvironment();
Termite* createTermites();
void printEnvironmentAndTermites(); 
void drawSimulation(int* environment, Termite* mites, int width, int height, int numMites);
int main(int argc, char **argv)
{
    	/* ----- Setup Allegro 5 ----- */

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(512, 512);
	timer = al_create_timer(1.0 / FPS);
	
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	
    //install any addons (graphic primitives, keyboard)
	al_init_primitives_addon();
	al_install_keyboard();

    //create event queues (keyboard, display window, timer)
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);


    int* environment = createEnvironment(width, height, numWoodchips); 
    //printEnvironment(environment, width, height);
	Termite* termites = createTermites(numTermites, width, height);
	printEnvironmentAndTermites(environment, termites, width, height, numTermites);
	

    /* ----- Game Loop ----- */ 
	
    while(1)
    {
        //Wait for event (keyboard, new frame)
   		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
   	
        //clear the screen
   		al_clear_to_color(al_map_rgb(70,70,100));

        //setup code
        drawSimulation(environment, termites, width, height, numTermites);
        


        

        //flip buffers
		al_flip_display();
   	
        //process exit events	
		if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) //pressed escape key
			break;
        if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //clicked x to close window
            break;
	}
	
    /* ----- Clean up ----- */ 

 	al_destroy_display(display);
 
	return 0;
}
    



 
	


    int* createEnvironment(int width, int height, int numWoodchips)
    {
    	srand (time(NULL));
   

     	int *array = malloc(sizeof(int) * width * height);

  
   int x,y;
   for(x=0; x< width; x++)
   {
   
     for(y=0; y< height; y++)
     {
     
         array[(x * height) + y] = (rand()%2);
         //printf("%d", array[(x * height) + y]);
 }
 //printf("\n");
}
	free(array);
	return array;
    }

void printEnvironment(int* environment, int width, int height)
{
	int x,y;
	for(x=0; x<height; x++)
	{	
		for(y=0; y<width; y++){
			{
			int element = environment[(x * width) + y];
			
			
			if(element == 0)
				printf(" ");  
			else if(element == 1)
				printf("@");   
			}			
		}	
		printf("\n");  			
	}	
}



Termite* createTermites(int numTermites, int width, int height)
{
	 
    int i,x,y;
    
    //printf("random x = %d\n", x);
	
	
Termite* termites = malloc(numTermites* sizeof *termites);
for (i = 0; i < numTermites; i++)
{
	x = (rand()%width); 
    y = (rand()%height);
    termites[i].x = x; 
    termites[i].y = y;
	termites[i].carrying = 0;
	printf("Termite #%d\tX = %d\tY = %d\tCarrying = %d\n", i, termites[i].x, termites[i].y, termites[i].carrying);

}
free(termites);
return termites;	

// x = 0 && direction = -1 x = max width

	
	
	
}

void printEnvironmentAndTermites(int* environment, Termite* termites, int 
width, int height, int numTermites)
{
int i,j,k,x,y,carryX,carryY;
		
	for(j=0; j<height; j++)
	{	
		for(k=0; k<width; k++)
        {
			{   
			int element = environment[(j * width) + k];	
            
		if(element == 0)
			printf(" ");
            
		else if(element == 1)
		{
			printf("W");

			
      }       
                for (i=0; i<numTermites; i++)
            { 
                
                if(termites[i].x == j && termites[i].y == k && element == 1)
                {
                                 printf("C");
                termites[i].carrying = 1;
                }
                
                else if(termites[i].x == j && termites[i].y == k && element == 0)
                printf("T");   
                } 
			}			
		}	
		printf("\n");  			
	}	
}

void drawSimulation(int* environment, Termite* termites, int width, int height, int numMites)
{
int i,j,k,x,y;
 
for(j=0; j<width; j++) 
 { 
 for(k=0; k<height; k++) 
 { 
          int element = environment[(j * width) + k];	
          
          
          if(element == 0)
          al_draw_filled_rectangle( 
           j * cellSize, 
           k * cellSize, 
            (j * cellSize) + cellSize, 
            (k * cellSize) + cellSize, 
            al_map_rgb(255,255,255)); 
            
                      else if(element == 0)
          al_draw_filled_rectangle( 
           j * cellSize, 
           k * cellSize, 
            (j * cellSize) + cellSize, 
            (k * cellSize) + cellSize, 
            al_map_rgb(0,255,0));
 
          

 for (i=0; i<numTermites; i++)
            { 
                
                if(termites[i].x == j && termites[i].y == k && element == 1)
                  al_draw_filled_rectangle( 
                   j * cellSize, 
                   k * cellSize, 
                   (j * cellSize) + cellSize, 
                   (k * cellSize) + cellSize, 
                   al_map_rgb(255,255,0));
             
                
                else if(termites[i].x == j && termites[i].y == k && element == 0)
                                al_draw_filled_rectangle( 
                                j * cellSize, 
                                k * cellSize, 
                                (j * cellSize) + cellSize, 
                                (k * cellSize) + cellSize, 
                                al_map_rgb(1,1,0));
                 
                } 
                
			}			
		}	
 
 
}
 
 
 



     

 
   

