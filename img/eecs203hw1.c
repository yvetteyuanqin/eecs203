#include <stdio.h>
#include <stdlib.h>

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
}

int main( int argc, char **argv )
{

	int		i;
	int		subrate;
	FILE		*fp;
	char		*ifile, *ofile;
	unsigned char	image[ROWS][COLUMNS];

	if ( argc != 4 )
	{
	    fprintf( stderr, "command line input: %s input output subrate\n", argv[0] );
	    exit( 1 );
	}

	ifile = argv[1];
	ofile = argv[2];
	subrate = atoi(argv[3]);

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

	//image processing from here
	// image subsampling
	printf("new image size: %d * %d\n", ROWS / subrate, COLUMNS / subrate);
	unsigned char subimage[ROWS/subrate][COLUMNS/subrate];

	subsampling(subrate,image,subimage);

	// image interpolation
	unsigned char interpoedimage[ROWS][COLUMNS];
	int r = subrate;
	nearestneighboring(r, subimage, interpoedimage);



	if (( fp = fopen( ofile, "wb" )) == NULL )
	{
	  fprintf( stderr, "error: could not open %s\n", ofile );
	  exit( 1 );
	}
	for ( i = 0 ; i < ROWS ; i++ ) fwrite( interpoedimage[i], 1, COLUMNS, fp );
	fclose( fp );

	return 0;
}

