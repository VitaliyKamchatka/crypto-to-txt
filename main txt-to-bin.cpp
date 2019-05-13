
//   PART 2:   decription from txt to binary
#include <iostream>
#include <stdio.h>  
#include <malloc.h>
#include <conio.h> 

int main(int argc, char** argv) {

char *crpt_table  = "zzzfz2z3z4z5z6z7z8znazafa2a3a4a5a6a7a8a9bzbfb2b3b4b5b6b7b8b9czcfc2c3c4c5c6c7c8c9dzdfd2d3d4d5d6d7d8d9ezefe2e3e4e5e6e7e8e9fzfff2f3f4f5f6f7f8f9yzyfy2y3y4y5y6y7y8y9hzhfh2h3h4h5h6h7h8h9*z*f*2*3*4*5*6*7*8*9=z=f=2=3=4=5=6=7=8=9kzkfk2k3k4k5k6k7k8k9-z-f-2-3-4-5-6-7-8-9mzmfm2m3m4m5m6m7m8m9+z+f+2+3+4+5+6+7+8+9:z:f:2:3:4:5:6:7:8:9pzpfp2p3p4p5p6p7p8p9?z?f?2?3?4?5?6?7?8?9rzrfr2r3r4r5r6r7r8r9szsfs2s3s4s5s6s7s8s9tztft2t3t4t5t6t7t8t9uzufu2u3u4u5u6u7u8u9vzvfv2v3v4v5v6v7v8v9wzwfw2w3w4w5w6w7w8w9xzxfx2x3x4x5x6x7x8x9!z!f!2!3!4!5!6!7";  // END
//                   00 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 END
//                   00                  10                  20                  30                  40                  50                  60                  70                  80                  90                 100                 110                 120                 130                 140                 150                 160                 170                 180                 190                 200                 210                 220                 230                 240                 250                 260 END

	printf("\n03-***PART 2: decription from txt to binary *** \n");

FILE * pFileDataTxtSourse;	// open sourse file xxx.data.txt	
pFileDataTxtSourse = fopen ("data.txt","rb");    //  int MaxFileSize = 1024*1024;
if (pFileDataTxtSourse!=NULL)
{
  	FILE * pFileDataOutput;
  	pFileDataOutput = fopen ("dataOutput.dat.txt","wb");
 	if (pFileDataOutput!=NULL) 
 	{ 	
 	
 		long FSize;	 
 		fseek (pFileDataTxtSourse , 0 , SEEK_END);     // obtain file size:
 		FSize = ftell (pFileDataTxtSourse);
 		rewind (pFileDataTxtSourse); 
 		
		size_t result;
		char * buff;	//	unsigned
		buff = ( char*) malloc (sizeof(unsigned char)*FSize); 	// allocate memory to contain the whole file:

		result = fread (buff,1,FSize,pFileDataTxtSourse);
		
		unsigned char newBuff[result] ; 
		
 		for( int k=0; k < result; k++) // read sembol
 		{
 			
 			for( unsigned char l=0; l<170; l++)    // Find correspondent symbol in crypto table
 			{
 				if( ( buff[k] == crpt_table[ l ] ) && ( buff[k+1] == crpt_table[ l + 1]) )
 				{ 					 
 					newBuff[k/2] =  ( unsigned char ) (l/2) ; //record index
 					printf("\n ++========+++ l = %d  ,     newBuff[ (k/2=%d=) %c ]  ++++============================================++++\n",l, k/2, newBuff[k/2] );
 					l=250;   //exit;
				 }
				 l++;
			 }
 			
		 }
 		
 		long written=0;
		written =	fwrite (newBuff , sizeof(char), result/2, pFileDataOutput); 
	
		printf("\n 505 -------- str buff = %s  -------------\n",buff);	
		printf("\n 506 -------- str newBuff = %s  -------------\n",newBuff);		
		printf("\n 111-------- written = %d  -------------\n", written    );
 	
	}

}
getch();
return 0;
}




