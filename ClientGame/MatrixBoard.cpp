#include <iostream>
#include <fstream>

using namespace std;

class MatrixBoard
{
	public:
	int Matrix[443];
	void setMatrix()
	{
		for(int i=0;i<21;i++)
			for(int j=0;j<21;j++)
				Matrix[i*21+j] = 0;
	}
	
	void modifiedMatrix(int row,int col,int type)//type = 0 noting 1 black 2 white
	{
			Matrix[row*21+col] = type+1;
	}

	void outputMatrix()//0 is noting,1 is black, 2 is white 
	{
		ofstream file;
		file.open("output.txt");
		
		for(int i=0;i<21;i++)
			for(int j=0;j<21;j++)
			{
				file<<Matrix[i*21+j];
				file<<" ";
				if(j == 20)
					file<<"\n";		
			}
		file.close();
	}

	void inputBoard()
	{
		ifstream ifs;
		ifs.open ("output.txt", std::ifstream::in);
		for(int i=0;i<21;i++)
			for(int j=0;j<21;j++){
				ifs>>Matrix[i*21+j];
			}
		ifs.close();
	}
	
};
