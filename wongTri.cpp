// wongTri.cpp : 实现文件
//

#include "stdafx.h"
#include "wongTrinder.h"
#include "wongTri.h"


// wongTri

IMPLEMENT_DYNAMIC(wongTri, CWnd)

wongTri::wongTri()
{

	x = 0;
	y = 0;
}

wongTri::~wongTri()
{
}


BEGIN_MESSAGE_MAP(wongTri, CWnd)
END_MESSAGE_MAP()



// search the center of the circle




void wongTri::searchCenter(unsigned char *pbits, long width, long height)
{
	float m00,m10,m01;
	m00=0;
	m10=0;
	m01=0;
	for(int i=0;i<width;i++)
		for(int j=0;j<height;j++)
		{
			m00+=*(pbits+j*width+i);
			m10+=(i+1)*(*(pbits+j*width+i));
			m01+=(j+1)*(*(pbits+j*width+i));
		}
	x=(int)(m10/m00+0.5);
	y=(int)(m01/m00+0.5);
}


int wongTri::getX(void)
{
	return x;
}


int wongTri::getY(void)
{
	return y;
}
