#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <string.h>

#define ROWS		480
#define COLUMNS		640
#define FSIZE       9
#define corner      4
#define sqr(x)		((x)*(x))

void averagefilter(unsigned char image[][COLUMNS], unsigned char output[][COLUMNS-FSIZE+1])
{
    int i,j;
    int k,l;
//    int corner =（FSIZE-1）/2;
   /* double filteravg[FSIZE][FSIZE];
    for(k=0;k<FSIZE;k++)
        for(l=0;l<FSIZE;l++){
            filteravg[k][l]=1.0;//(FSIZE*FSIZE);
        }
    */
    int sum =0;
	for( i=corner; i<ROWS-corner; i++)
        for (j = corner; j < COLUMNS-corner; j++){
            sum = 0;
            for(k=-corner;k<=corner;k++)
                for(l=-corner;l<=corner;l++){
                    sum += image[i+k][j+l];
                }
            output[i-corner][j-corner]=sum/(FSIZE*FSIZE);
            //printf("%d\t",output[i][j]);
        }
         //printf("\n");

			//printf("%d \t %d \t %d \t %d\n",j,i, col,row);

}

int partition( int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;
    
    while( 1)
    {
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}



void quickSort( int a[], int l, int r)
{
    int j;
    
    if( l < r )
    {
        // divide and conquer
        j = partition( a, l, r);
        quickSort( a, l, j-1);
        quickSort( a, j+1, r);
    }
    
}

void  medianfilter(unsigned char image[][COLUMNS], unsigned char output[][COLUMNS-FSIZE+1])
{
    int i,j;
    int k,l;
    //    int corner =（FSIZE-1）/2;
    int median[FSIZE*FSIZE];

    
    int sum =0;
    for( i=corner; i<ROWS-corner; i++)
        for (j = corner; j < COLUMNS-corner; j++){
            for(k=-corner;k<=corner;k++)
                for(l=-corner;l<=corner;l++){
                    median[(k+corner)*FSIZE+(l+corner)]=image[i+k][j+l];
                    quickSort(median,0,FSIZE*FSIZE-1);
                }
			
            output[i-corner][j-corner]=median[40];
            //printf("%d\t",median[k][l]);
        }
    //printf("\n");
=======

#define ROWS		480
#define COLUMNS		640

#define sqr(x)		((x)*(x))

void subsampling(int subrate, unsigned char image[][COLUMNS], unsigned char output[][COLUMNS/subrate])
{
	int i;
	int j;

	for( i=0; i<ROWS/subrate; i++)
		for (j = 0; j < COLUMNS/subrate; j++)
		{

			//int col = (j - 1) * subrate + 1;
			//int row = (i - 1) * subrate + 1;
			int row = i * subrate;
			
			int col = j * subrate;
			//printf("%d \t %d \t %d \t %d\n",j,i, col,row);
			output[i][j] = image[row][col];

		}

}
void nearestneighboring(int r, unsigned char image[][COLUMNS/r],unsigned char output[][COLUMNS])
{
	int i, j, k, l;


	for (i = 0; i<ROWS/r; ++i) {

		for (j = 0; j<COLUMNS/r; ++j) {

			unsigned char element = image[i][j];
		

			for (k = 0; k<r; ++k)
			{
				for (l = 0; l<r; ++l) {

					output[i*r + l][j*r + k] = element;
				}
			}
		}
	}
>>>>>>> e9d53f1533eec71f76174ed87f8b04f9443810b7
}

int main( int argc, char **argv )
{

	int		i;
<<<<<<< HEAD
	FILE		*fp;
	char		*ifile, *ofile;
    char        *choice;
	unsigned char	image[ROWS][COLUMNS];
    int hist[256]={0};

	if ( argc != 4 )
	{
	    fprintf( stderr, "command line input: %s input output choice\n", argv[0] );
=======
	int		subrate;
	FILE		*fp;
	char		*ifile, *ofile;
	unsigned char	image[ROWS][COLUMNS];

	if ( argc != 4 )
	{
	    fprintf( stderr, "command line input: %s input output subrate\n", argv[0] );
>>>>>>> e9d53f1533eec71f76174ed87f8b04f9443810b7
	    exit( 1 );
	}

	ifile = argv[1];
	ofile = argv[2];
<<<<<<< HEAD
	choice = argv[3];
   


    
=======
	subrate = atoi(argv[3]);

>>>>>>> e9d53f1533eec71f76174ed87f8b04f9443810b7
	if (( fp = fopen( ifile, "rb" )) == NULL )
	{
	  fprintf( stderr, "error: couldn't open %s\n", ifile );
	  exit( 1 );
	}			

	for ( i = 0; i < ROWS ; i++ )
	  if ( fread( image[i], 1, COLUMNS, fp ) != COLUMNS )
	  {
	    fprintf( stderr, "error: couldn't read enough stuff\n" );
	    exit( 1 );
	  }
	fclose( fp );
<<<<<<< HEAD
    
    //get histogram
    int x, y, p;
    for (x = 0; x < ROWS; x++)
        for (y = 0; y < COLUMNS; y++){
            p = image[x][y];
            hist[p]++;
        }

	//image processing from here
    unsigned char averagedimage[ROWS-FSIZE+1][COLUMNS-FSIZE+1];
    unsigned char medianimage[ROWS-FSIZE+1][COLUMNS-FSIZE+1];
	// apply average filter
    if (strcmp(choice, "average") == 0){
         printf("choice is %s\n",choice);
        printf("new image size: %d * %d\n", ROWS-FSIZE+1 , COLUMNS-FSIZE+1 );
        
        averagefilter(image,averagedimage);
    }else if(strcmp(choice, "median") == 0){
        // apply medianfilter
         printf("choice is %s\n",choice);
		 
        medianfilter(image,medianimage);
    }else{
        printf("Please enter average or median as the third parameter in command line");
        return -1;
    }
    
	
=======

	//image processing from here
	// image subsampling
	printf("new image size: %d * %d\n", ROWS / subrate, COLUMNS / subrate);
	unsigned char subimage[ROWS/subrate][COLUMNS/subrate];

	subsampling(subrate,image,subimage);

	// image interpolation
	unsigned char interpoedimage[ROWS][COLUMNS];
	int r = subrate;
	nearestneighboring(r, subimage, interpoedimage);
>>>>>>> e9d53f1533eec71f76174ed87f8b04f9443810b7



	if (( fp = fopen( ofile, "wb" )) == NULL )
	{
	  fprintf( stderr, "error: could not open %s\n", ofile );
	  exit( 1 );
	}
<<<<<<< HEAD
    if (strcmp(choice, "average") == 0){
        for ( i = 0 ; i < ROWS-FSIZE+1 ; i++ ) fwrite( averagedimage[i], 1, COLUMNS-FSIZE+1, fp );
    }else{
        for ( i = 0 ; i < ROWS-FSIZE+1 ; i++ ) fwrite( medianimage[i], 1, COLUMNS-FSIZE+1, fp );
        
    }

=======
	for ( i = 0 ; i < ROWS ; i++ ) fwrite( interpoedimage[i], 1, COLUMNS, fp );
>>>>>>> e9d53f1533eec71f76174ed87f8b04f9443810b7
	fclose( fp );

	return 0;
}

