
// To run the program, type
//   animate_rectangle_sv px pz
// which will create
// xxxxxrectangle_sv.bmp that is a rectangle with width px pixels and height pz pixels,
// and where xxxxx is the frame number.

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

struct p_color
{
   unsigned char r;
   unsigned char g;
   unsigned char b;
};

struct r_circle
{
   double cx;
   double cy;
   double radius;
   struct p_color circle_color;
};

using namespace std;

string int_to_five_digit_string(int frame_number)
{
   ostringstream strm;
   strm << setfill('0') << setw(5) << frame_number;
   return strm.str();
}

int string_to_int(string s)
{
   istringstream strm;
   strm.str(s);
   int n=0;
   strm >> n;
   return n;
}
void write_bmp_header_file(ofstream& output_file, int px, int pz)
{
	unsigned short int bfType;
	bfType = 0x4D42;
   output_file.write ((char*)&bfType, sizeof (short int));   

   unsigned int bfSize;
	int rem;
	rem=3*px%4;
	int padding;
	if(rem==0)
	{
		padding=0;
	}
	else
	{
		padding=4-rem;
	}

	bfSize = 14 + 40 + (3 * px+padding) * pz;   
//	bfSize = 14 + 40 + (3 * px+padding) * pz + 2;
   output_file.write ((char*)&bfSize, sizeof (int));   

    unsigned short int bfReserved1;
	bfReserved1 = 0;
   output_file.write ((char*)&bfReserved1, sizeof (short int));   

	unsigned short int bfReserved2;
	bfReserved2 = 0;
   output_file .write ((char*)&bfReserved2, sizeof (short int));   

	unsigned int bfOffsetBits;
	bfOffsetBits = 14 + 40;
   output_file.write ((char*)&bfOffsetBits, sizeof (int));   

	unsigned int biSize;
	biSize=40;
   output_file.write ((char*)&biSize, sizeof (int));   
   
	int biWidth;
	biWidth=px;
   output_file.write ((char*)&biWidth, sizeof (int));   

	int biHeight;
	biHeight=pz;
   output_file.write ((char*)&biHeight, sizeof (int));   

	unsigned short int biPlanes;
	biPlanes=1;
   output_file.write ((char*)&biPlanes, sizeof (short int));   

	unsigned short int biBitCount;
	biBitCount=24;
   output_file.write ((char*)&biBitCount, sizeof (short int));   

	unsigned int biCompression;
// #define BI_RGB 0
   unsigned int bi_rgb = 0;
//	biCompression=BI_RGB;
	biCompression=bi_rgb;
   output_file.write ((char*)&biCompression, sizeof (int));   

	unsigned int biSizeImage;
	biSizeImage=0;
   output_file.write ((char*)&biSizeImage, sizeof (int));   

	unsigned int biXPelsPerMeter;
	biXPelsPerMeter=0;
   output_file.write ((char*)&biXPelsPerMeter, sizeof (int));   

	unsigned int biYPelsPerMeter;
	biYPelsPerMeter=0;
   output_file.write ((char*)&biYPelsPerMeter, sizeof (int));   

	unsigned int biClrUsed;
	biClrUsed = 0;
   output_file.write ((char*)&biClrUsed, sizeof (int));   

	unsigned int biClrImportant;
	biClrImportant = 0;
   output_file.write ((char*)&biClrImportant, sizeof (int));   
}
void write_bmp_file(int f_number, string output_file_name, unsigned char * * * output_buffer, int px, int pz)
{
   ofstream ostrm_1;
   string o_file_name = int_to_five_digit_string(f_number)+output_file_name;
   ostrm_1.open(o_file_name.c_str(), ios::out | ios::binary);
   if(ostrm_1.fail())
   {
      cout << "Error.  Can't open output file " << o_file_name << "." << endl;
      return;
   }
   cout << "Opening output file " << o_file_name <<"." << endl;

	int rem;
	rem=3*px%4;
	int padding;
	if(rem==0)
	{
		padding=0;
	}
	else
	{
		padding=4-rem;
	}
   //cout << "padding is " << padding << "." << endl;
   //cout << "rem is "  << rem << "." << endl;
   write_bmp_header_file(ostrm_1, px, pz);

	unsigned char p_buffer[4];
	p_buffer[0]=0;
	p_buffer[1]=0;
	p_buffer[2]=0;
	p_buffer[3]=0;
   
   unsigned char * line_buffer = new unsigned char[px*3];

   int i;
   int j;
 	for(i=pz-1;i>=0;i--)
	{
      for(j=0;j<px;j++)
      {
         line_buffer[3*j+0]=output_buffer[i][j][2];
         line_buffer[3*j+1]=output_buffer[i][j][1];
         line_buffer[3*j+2]=output_buffer[i][j][0];         
      }
      ostrm_1.write ((char*)line_buffer, px*3*sizeof (unsigned char));      
      ostrm_1.write ((char*)p_buffer, padding*sizeof (unsigned char));      
	}
   delete[] line_buffer;
   line_buffer = NULL;
   ostrm_1.close();   
}

void fill_background(unsigned char * * * o_buffer, int px, int pz, p_color bg_color)
{
      int i;
      int j;
      for (i=0;i<pz;i++)
      {
         for(j=0;j<px;j++)
         {
            o_buffer[i][j][0]=bg_color.r;
            o_buffer[i][j][1]=bg_color.g;
            o_buffer[i][j][2]=bg_color.b;           
         }
      }
}

void fill_big_circle(unsigned char * * * o_buffer, int px, int pz, r_circle b_circle)
{
      // students:  complete this section of the code.
}

void fill_border(unsigned char * * * o_buffer, int px, int pz, int b_width, p_color b_color)
{
      // students:  complete this section of the code.
}

void set_big_circle_values(r_circle& b_circle, int b_width, int px, int pz)
{
      // students:  complete this section of the code.
}

int main(int argc, char * argv[])
{
   
   string arg_1 = "rectangle_sv.bmp";   
	int px;
	int pz;
   string arg;
   arg = argv[1];
   px = string_to_int(arg);
   arg = argv[2];
   pz = string_to_int(arg);
   cout << "px is " << px << "." << endl;
   cout << "pz is " << pz << "." << endl;

	if(px<=0)
	{   
		return -1;
	}
	if(pz<=0)
	{     
		return -1;
	}

	unsigned char * * * buffer = new unsigned char * * [pz];
   int i,j;
   for (i=0; i< pz; i++)
   {
      buffer[i]= new unsigned char * [px];
      for(j=0;j<px;j++)
      {
         buffer[i][j] = new unsigned char [3];
      }
   }

   struct p_color background_color;
   background_color.r = 173;
   background_color.g = 216;
   background_color.b = 230;
   
   fill_background(buffer, px, pz, background_color);
   
   int border_width = 20;
   struct p_color border_color;
   border_color.r = 255;
   border_color.g = 255;
   border_color.b = 255;

   //  students:  complete the fill_border code.
   fill_border(buffer, px, pz, border_width, border_color);

   struct r_circle big_circle;
   //  students:  complete the set_big_circle_values code.
   set_big_circle_values(big_circle, border_width, px, pz);
     
   big_circle.circle_color.r = 0;
   big_circle.circle_color.g = 0;
   big_circle.circle_color.b = 0;
   //  students:  complete the fill_big_circle code.
   fill_big_circle(buffer, px, pz, big_circle);
      
   int current_frame_number = 0;
   write_bmp_file(current_frame_number, arg_1, buffer, px, pz);

   for(i = 0; i<pz;i++)
   {
      for(j=0;j<px;j++)
      {
         delete[] buffer[i][j];
         buffer[i][j] = NULL;
      }
      delete[] buffer[i];
      buffer[i] = NULL;       
   }   
   delete[] buffer;
   buffer = NULL;
   
	return 0;
}