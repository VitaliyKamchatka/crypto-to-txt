// EXE to TXT
#include <iostream>  // #include <iostream.h> DEV-C++ isnt a compiler (maybe after installing VS2019 you got new another compiler
#include <stdio.h>   /* fopen  fseek fwrite  write buffer */
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <malloc.h>
#include <conio.h> // cout - borland library

int main(int argc, char** argv) 
{	
printf("\nThis is PART 1: bin to txt conversion. \n Use data.dat.txt as a name of your input file and textOut.txt will be created.\n");

char SourseFileName[]="data.dat.txt";
FILE * pFileDataSourse;	// open sourse file xxx.data.txt	
pFileDataSourse = fopen (SourseFileName,"rb");    //  int MaxFileSize = 1024*1024;

char crpt_table[]  = "zzzfz2z3z4z5z6z7z8znazafa2a3a4a5a6a7a8a9bzbfb2b3b4b5b6b7b8b9czcfc2c3c4c5c6c7c8c9dzdfd2d3d4d5d6d7d8d9ezefe2e3e4e5e6e7e8e9fzfff2f3f4f5f6f7f8f9yzyfy2y3y4y5y6y7y8y9hzhfh2h3h4h5h6h7h8h9*z*f*2*3*4*5*6*7*8*9=z=f=2=3=4=5=6=7=8=9kzkfk2k3k4k5k6k7k8k9-z-f-2-3-4-5-6-7-8-9mzmfm2m3m4m5m6m7m8m9+z+f+2+3+4+5+6+7+8+9:z:f:2:3:4:5:6:7:8:9pzpfp2p3p4p5p6p7p8p9?z?f?2?3?4?5?6?7?8?9rzrfr2r3r4r5r6r7r8r9szsfs2s3s4s5s6s7s8s9tztft2t3t4t5t6t7t8t9uzufu2u3u4u5u6u7u8u9vzvfv2v3v4v5v6v7v8v9wzwfw2w3w4w5w6w7w8w9xzxfx2x3x4x5x6x7x8x9!z!f!2!3!4!5!6!7";  // END
//                    00 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 END
//                    00                  10                  20                  30                  40                  50                  60                  70                  80                  90                 100                 110                 120                 130                 140                 150                 160                 170                 180                 190                 200                 210                 220                 230                 240                 250                 260 END

if (pFileDataSourse!=NULL)
{
	printf("\n\n Sourse file opened: %s", SourseFileName );
	char OutputFileName[]="textOut.txt";
  	FILE * pFileTxtOutput;
  	pFileTxtOutput = fopen (OutputFileName,"wb");
 	if (pFileTxtOutput!=NULL) 
 	{ 				 	 			 	  				
 		printf("\n Output file created: %s", OutputFileName );
 	
		long lSize;	 
	
 		fseek (pFileDataSourse , 0 , SEEK_END);     // obtain file size:
 		lSize = ftell (pFileDataSourse);
 		rewind (pFileDataSourse); 				
 		
		size_t result;
		char * buffer;	//	unsigned
		buffer = ( char*) malloc (sizeof(unsigned char)*lSize); 	// allocate memory to contain the whole file:
		char* ch_ptr = buffer;
			 
		result = fread (buffer,1,lSize,pFileDataSourse); // bytes read
		printf("\n result of fread function is: %d bytes.", result   );
		
		unsigned char* newBuffer = (unsigned char*) malloc (sizeof(unsigned char)*lSize*2);
			
		for( int cntr=0; cntr < result; cntr++ )
		{   
			unsigned char ch=*ch_ptr;
	    	int index=0;
			newBuffer[  cntr * 2     ] = crpt_table[    ch * 2        ] ;	
			newBuffer[ (cntr * 2 )+ 1] = crpt_table[ (  ch * 2  ) + 1 ] ;
			ch_ptr++;
		}
								
		long written=0;
		written =	fwrite (newBuffer , sizeof(char), result*2, pFileTxtOutput); 
		
		printf("\n\n written: %d bytes. \n\n", written    );
					//   the whole file is now loaded in the memory buffer. 
		free(buffer);
		free(newBuffer);
	}				   
  	fclose (pFileDataSourse); 
	fclose (pFileTxtOutput);
} else printf("\n\n Sourse file  %s  not found.", SourseFileName );
	
printf("\n\n Here is the crypto table hard coded:\n\n" );
printf(crpt_table);
printf("\n\n Press any key to exit.");

getch();
return 0; // EXE to TXT
}




