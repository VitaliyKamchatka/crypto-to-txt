// bin to TXT. Some extra debugging code is cleaned for gitHub publishing
#include <iostream> 
#include <stdio.h>   
#include <malloc.h>
#include <conio.h> 

int main(int argc, char** argv) {

FILE * pFileDataSourse;	// open sourse file xxx.data.txt	
pFileDataSourse = fopen ("data.dat.txt","rb");    //  sourse file

char *crpt_table  = "zzzfz2z3z4z5z6z7z8znazafa2a3a4a5a6a7a8a9bzbfb2b3b4b5b6b7b8b9czcfc2c3c4c5c6c7c8c9dzdfd2d3d4d5d6d7d8d9ezefe2e3e4e5e6e7e8e9fzfff2f3f4f5f6f7f8f9yzyfy2y3y4y5y6y7y8y9hzhfh2h3h4h5h6h7h8h9*z*f*2*3*4*5*6*7*8*9=z=f=2=3=4=5=6=7=8=9kzkfk2k3k4k5k6k7k8k9-z-f-2-3-4-5-6-7-8-9mzmfm2m3m4m5m6m7m8m9+z+f+2+3+4+5+6+7+8+9:z:f:2:3:4:5:6:7:8:9pzpfp2p3p4p5p6p7p8p9?z?f?2?3?4?5?6?7?8?9rzrfr2r3r4r5r6r7r8r9szsfs2s3s4s5s6s7s8s9tztft2t3t4t5t6t7t8t9uzufu2u3u4u5u6u7u8u9vzvfv2v3v4v5v6v7v8v9wzwfw2w3w4w5w6w7w8w9xzxfx2x3x4x5x6x7x8x9!z!f!2!3!4!5!6!7";  // END
//                   00 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 END
//                   00                  10                  20                  30                  40                  50                  60                  70                  80                  90                 100                 110                 120                 130                 140                 150                 160                 170                 180                 190                 200                 210                 220                 230                 240                 250                 260 END

if (pFileDataSourse!=NULL)
	{
  	FILE * pFileTxtOutput;
  	pFileTxtOutput = fopen ("textOut.txt","wb"); // output file
 	if (pFileTxtOutput!=NULL) 
 	{ 				 	 			 	  				
 		
 		printf(crpt_table); // show encription table to the user
 		
		long lSize;	 
 		fseek (pFileDataSourse , 0 , SEEK_END);     // obtain file size:
 		lSize = ftell (pFileDataSourse);
 		rewind (pFileDataSourse); 					
 		
		size_t result;
		char * buffer;	//	unsigned
		buffer = ( char*) malloc (sizeof(unsigned char)*lSize); 	// allocate memory to contain the whole file:
	
		result = fread (buffer,1,lSize,pFileDataSourse); // bytes read
		
		char newBuffer[result*2] ; 
			
		for( int cntr=0; cntr < result; cntr++ )   
		{   
			char * tmp;
			tmp =  (buffer + cntr); // pntr to byte of data
			char ch;
			ch = *tmp; // byte of data	
		
			printf("\n --   char = %c  -------------\n", ch   ); // for debugging
			int index = (int)ch; //dec val of char
		
			printf("\n --   cntr = %d  -------------\n", cntr   );
			newBuffer[  cntr * 2     ] = crpt_table[    index * 2        ] ;
			newBuffer[ (cntr * 2 )+ 1] = crpt_table[ (  index * 2  ) + 1 ] ;		
			printf("\n --   newBuffer = %s  -------------\n", newBuffer   );
		}
								
		printf("\n NNNNNN   newBuffer = %s  -------------\n", newBuffer   );
		long written=0;
		written =	fwrite (newBuffer , sizeof(char), result*2, pFileTxtOutput); 

		printf("\n 09-------- size of char = %d  -------------\n", sizeof(char)    );	
		printf("\n 10-------- str buffer = %s  -------------\n",buffer);	
		printf("\n 11-------- written = %d  -------------\n", written    );
					//   the whole file is now loaded in the RAM memory buffer. 
		}
 				   
  	fclose (pFileDataSourse); 
	fclose (pFileTxtOutput);
	}
getch();
return 0;
//*********************    See also The   PART 2 of the project, to convert back TXT to bin       ***********************************

}




