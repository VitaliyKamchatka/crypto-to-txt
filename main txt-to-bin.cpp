#include <iostream> // txt to bin
#include <stdio.h>   /* fopen  fseek fwrite  write buffer */
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <malloc.h>
#include <conio.h> // cout, getch
 
int main(int argc, char** argv) {

char *crpt_table  = "zzzfz2z3z4z5z6z7z8znazafa2a3a4a5a6a7a8a9bzbfb2b3b4b5b6b7b8b9czcfc2c3c4c5c6c7c8c9dzdfd2d3d4d5d6d7d8d9ezefe2e3e4e5e6e7e8e9fzfff2f3f4f5f6f7f8f9yzyfy2y3y4y5y6y7y8y9hzhfh2h3h4h5h6h7h8h9*z*f*2*3*4*5*6*7*8*9=z=f=2=3=4=5=6=7=8=9kzkfk2k3k4k5k6k7k8k9-z-f-2-3-4-5-6-7-8-9mzmfm2m3m4m5m6m7m8m9+z+f+2+3+4+5+6+7+8+9:z:f:2:3:4:5:6:7:8:9pzpfp2p3p4p5p6p7p8p9?z?f?2?3?4?5?6?7?8?9rzrfr2r3r4r5r6r7r8r9szsfs2s3s4s5s6s7s8s9tztft2t3t4t5t6t7t8t9uzufu2u3u4u5u6u7u8u9vzvfv2v3v4v5v6v7v8v9wzwfw2w3w4w5w6w7w8w9xzxfx2x3x4x5x6x7x8x9!z!f!2!3!4!5!6!7";  // END
//                   00 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 END
//                   00                  10                  20                  30                  40                  50                  60                  70                  80                  90                 100                 110                 120                 130                 140                 150                 160                 170                 180                 190                 200                 210                 220                 230                 240                 250                 260 END

printf("\nThis is PART 2: txt to bin conversion. \n Use data.txt as a name of your input file and dataOutput.dat.txt will be created.\n");

FILE * pFileDataTxtSource;	// open sourse file xxx.data.txt
char FileName_Input[]="data.txt";
pFileDataTxtSource = fopen ( FileName_Input ,"rb");    //  int MaxFileSize = 1024*1024;
if (pFileDataTxtSource!=NULL)
{  
	printf("\n Source file opened: %s", FileName_Input );
  	char FileName_FileDataOutput[]="dataOutput.dat.txt";
  	FILE * pFileDataOutput;
  	pFileDataOutput = fopen (FileName_FileDataOutput,"wb");
  	
 	if (pFileDataOutput!=NULL) 
 	{ 	
 		printf("\n Output file created: %s", FileName_FileDataOutput);
 		long FSize;	 
 		fseek (pFileDataTxtSource , 0 , SEEK_END);     // obtain file size:
 		FSize = ftell (pFileDataTxtSource);
 		rewind (pFileDataTxtSource); 				
 		
		size_t result;
		unsigned char * buff = (unsigned char*) malloc (sizeof(unsigned char)*FSize); 	// allocate memory to contain the whole file:
		result = fread (buff,1,FSize,pFileDataTxtSource);
		printf("\n Sourse file size: %d", result );
		unsigned char* newBuff = (unsigned char*) malloc (sizeof(unsigned char) * (FSize/2) ); 	// allocate memory to contain the whole file, new file is twice smaller:

		long bytes_written=0;
		
 		for( long k=0; k < result; k+=2 ) // read sembol
 		{   
		 	int any_luck = 0; // check if there are some alian symbols
			for( unsigned char index=0; index<256; index++)    // Find correspondent symbol in crypto table
 			{
	
 				if( ( buff[k] == crpt_table[ index*2 ] ) && ( buff[k+1] == crpt_table[  (index*2) + 1]) ) // symbol found
 					{ 					 
 					newBuff[k/2] = index ;  //record index
		 			//		printf("\n symbol found. index = %d  ,   newBuff[ (k/2=%d=) %c ]\n",index, k/2, newBuff[k/2] );
					any_luck++;
 					break;
					}
			 }
			
 			if( any_luck == 0 ) 
			{ 
			 system("COLOR 6C");  // change backgraund color
			 printf("\n Error: symbol code was not found in crypto table! You have alien symlols in your input file. k = %d  ,\n",k);
 			}
 			
		 }
	
		bytes_written =	fwrite (newBuff , sizeof(char), result/2, pFileDataOutput); 
		free(buff);
		free(newBuff); 
		fclose (pFileDataOutput);
		printf("\n bytes written: %d bytes\n\n Here is the crypto table hard coded:\n\n", bytes_written    );
		printf(crpt_table);
	}
	fclose (pFileDataTxtSource );
}
else printf("\n Source file  %s  not found.", FileName_Input );
 	
printf("\n\n Press any key to exit.");
getch();
return 0; // txt to bin
}




