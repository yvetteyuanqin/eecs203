#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FIXED_POINT_SHIFT  16

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
void GLT(double gamma, unsigned char image[][COLUMNS], unsigned char GLTedImage[][COLUMNS]) {
	int i, j, k, l;

	double c = 255.0 / pow(255.0, gamma);

	for (i = 0; i < ROWS; ++i) {

		for (j = 0; j<COLUMNS; ++j) {

			GLTedImage[i][j] = (int)(c * pow(image[i][j], gamma));
			
		}
	}
	printf("Graylevel:%d gamma:%f c:%f \n", GLTedImage[200][200],gamma,c);
	

}
void histEq(unsigned char image_in[][COLUMNS],unsigned char image_out[][COLUMNS])
{
	unsigned int hist[256];
	unsigned int eqHist[256];
	unsigned int histIndex = 0;
	unsigned int pixIndex = 0;
	//shifted histogram value at pos i
	unsigned long Ni = 0;
	//shifted equalized histogram value at pos i
	unsigned long Kn = 0;
	unsigned int size = COLUMNS * ROWS;
	unsigned char data[size];
	int k = 0, i = 0, j = 0;
	for (i = 0; i < ROWS; ++i) {

		for (j = 0; j<COLUMNS; ++j) {

			data[k] =image_in[i][j];
			k++;
		}
	}

	for (histIndex = 0; histIndex < 256; histIndex++)
	{
		hist[histIndex] = 0;
	}

	/* orginal data histogram */
	for (pixIndex = 0; pixIndex < size; pixIndex++)
	{
		hist[data[pixIndex]] += 1;
	}

	/* generate equalized histogram */
	for (histIndex = 0; histIndex<256; histIndex++)
	{
		Ni = ((unsigned long)hist[histIndex] << FIXED_POINT_SHIFT);
		Kn += 256 * (Ni / (unsigned long)size);
		eqHist[histIndex] = ((unsigned long)(Kn >> FIXED_POINT_SHIFT)) & 0xff;
	}

	/* update data */
	for (pixIndex = 0; pixIndex < size; pixIndex++)
	{
		data[pixIndex] = ((unsigned char)(eqHist[data[pixIndex]])) & 0xff;
	}

	for (i = 0; i < ROWS; ++i) {

		for (j = 0; j<COLUMNS; ++j) {

			image_out[i][j] = data[i*COLUMNS+j];
		
		}
	}
	printf("Graylevel:%d \n", image_out[200][200]);



}

// gcc -o hw2 eecs203hw2.c -lm
//compile with -lm math library

int main( int argc, char **argv )
{

	int		i;
	int		subrate;
	FILE		*fp;
	char		*ifile, *ofile;
	unsigned char	image[ROWS][COLUMNS];
	/*hW1*/
	/*if ( argc != 4 )
	{
	    fprintf( stderr, "command line input: %s input output subrate\n", argv[0] );
	    exit( 1 );
	}

	ifile = argv[1];
	ofile = argv[2];
	//double gamma = atof(argv[3]);//power of GLT transform
	subrate = atoi(argv[3]);*/


	if ( argc != 3 )
	{
	    fprintf( stderr, "command line input: %s input output gamma\n", argv[0] );
	    exit( 1 );
	}

	ifile = argv[1];
	ofile = argv[2];
	
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
	/*// image subsampling
	printf("new image size: %d * %d\n", ROWS / subrate, COLUMNS / subrate);
	unsigned char subimage[ROWS/subrate][COLUMNS/subrate];

	subsampling(subrate,image,subimage);

	// image interpolation
	unsigned char interpoedimage[ROWS][COLUMNS];
	int r = subrate;
	nearestneighboring(r, subimage, interpoedimage);*/

	/*HW2*/
	/*unsigned char GLTedImage[ROWS][COLUMNS];
	GLT(gamma, image, GLTedImage);*/
	
	unsigned char histimage[ROWS][COLUMNS];
	histEq(image, histimage);
	
	// image processing end here


	if (( fp = fopen( ofile, "wb" )) == NULL )
	{
	  fprintf( stderr, "error: could not open %s\n", ofile );
	  exit( 1 );
	}
	for ( i = 0 ; i < ROWS ; i++ ) fwrite( histimage[i], 1, COLUMNS, fp );
	fclose( fp );

	return 0;
}

