#include "stdafx.h"
#include "YangLiuImageProcess.h"

#include"cxcore.h"
#include"highgui.h"

#include"wongTri.h"

CYangLiuImageProcess::CYangLiuImageProcess()
{
	m_pBits = NULL;
	lpbmi = NULL;
	imageWidth = 0;
	imageHeight = 0;
	m_nOpenMode = 0;
	m_nColorBits = 8;

	voidImage = NULL;

	m_lValue[256] = NULL;
	m_dValue[256] = NULL;
	m_lValueG[256] = NULL;
	m_dValueG[256] = NULL;
	m_lValueB[256] = NULL;
	m_dValueB[256] = NULL;
	dMax = 0.0;
	dMaxG = 0.0;
	dMaxB = 0.0;

	x=0;
	y=0;
	m_dZoom = 1.0;
}

CYangLiuImageProcess::~CYangLiuImageProcess()
{
	IplImage *image = (IplImage*)voidImage;
	if (m_nOpenMode == 1)
	{
		if (m_pBits != NULL)
		{
			delete m_pBits;
			m_pBits = NULL;
		}
		if (lpbmi != NULL)
		{
			delete lpbmi;
			lpbmi = NULL;
		}
	}
	if (m_nOpenMode == 2)
	{
		if (image != NULL)
		{
			cvReleaseImage(&image);
			image = NULL;
		}
		
	}
}

//∂¡»°BMP
BOOL CYangLiuImageProcess::ReadBMP(LPCTSTR lpszPathName)
{
	long lTotal = 0;
	CFile file;
	file.Open(lpszPathName, CFile::modeRead);
	file.Read(&bmpFH, sizeof(BITMAPFILEHEADER));
	lpbmi = (LPBITMAPINFO) new char[sizeof(BITMAPINFO)+4 * (1 << 8)];
	file.Read(lpbmi, sizeof(BITMAPINFOHEADER));
	m_nColorBits = lpbmi->bmiHeader.biBitCount;
	imageHeight = lpbmi->bmiHeader.biHeight;
	imageWidth = lpbmi->bmiHeader.biWidth;
	if (m_nColorBits == 8)
	{
		lTotal = imageWidth*imageHeight;
		file.Read(&(lpbmi->bmiColors[0]), 256 * 4);
	}
	else if (m_nColorBits == 24)
	{
		lTotal = imageWidth*imageHeight * 3;
	}
	else
	{
		file.Close();
		return FALSE;
	}
	m_pBits = new unsigned char[lTotal];
	file.Read(m_pBits, lTotal);
	file.Close();
	return TRUE;
}

//±£¥ÊBMP
BOOL CYangLiuImageProcess::SaveBMP(LPCTSTR lpszPathName)
{
	long lTotal = 0;
	CFile file;
	file.Open(lpszPathName, CFile::modeCreate || CFile::modeReadWrite);
	file.Write(&bmpFH, sizeof(BITMAPFILEHEADER));
	file.Write(lpbmi, sizeof(BITMAPINFOHEADER));
	if (m_nColorBits == 8)
	{
		lTotal = imageWidth*imageHeight;
		file.Write(&(lpbmi->bmiColors[0]), 256 * 4);
	}
	else if (m_nColorBits == 24)
	{
		lTotal = imageWidth*imageHeight * 3;
	}
	else
	{
		file.Close();
		return FALSE;
	}
	//m_pBits = new unsigned char[lTotal];
	file.Write(m_pBits, lTotal);
	file.Close();
	return TRUE;
}

BOOL CYangLiuImageProcess::ReadImage(LPCTSTR lpszPathName)
{
	IplImage *image = (IplImage*)voidImage;
	CString str = lpszPathName;
	str.MakeLower();
	if (str.Find(_TEXT(".bmp")) != -1)
	{
		m_nOpenMode = 1;
		if (!ReadBMP(lpszPathName)) return FALSE;
		
		CvSize size;
		size.height = imageHeight;
		size.width = imageWidth;
		image = cvCreateImageHeader(size, 8, m_nColorBits / 8);
		image->imageData = (char *)m_pBits;
	}
	if (str.Find(_TEXT(".jpg")) != -1)
	{
		m_nOpenMode = 2;
		image = cvLoadImage(lpszPathName);
		lpbmi = (LPBITMAPINFO) new char[sizeof(BITMAPINFO)+4 * (1 << 8)];
		lpbmi->bmiHeader.biBitCount = image->depth*image->nChannels;
		lpbmi->bmiHeader.biClrUsed = 0;
		lpbmi->bmiHeader.biHeight = image->height;
		lpbmi->bmiHeader.biWidth = image->width;
		lpbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		lpbmi->bmiHeader.biSizeImage = image->width*image->height*image->nChannels;
		lpbmi->bmiHeader.biClrImportant = 0;
		lpbmi->bmiHeader.biCompression = 0;
		lpbmi->bmiHeader.biPlanes = 1; //image->nChannels;
		imageWidth = image->width;
		imageHeight = image->height;
		for (int i = 0; i<(1 << 8); i++)
		{
			RGBQUAD &o = lpbmi->bmiColors[i];
			o.rgbBlue = i;
			o.rgbGreen = i;
			o.rgbRed = i;
			o.rgbReserved = 0;
		}
		m_nColorBits = image->depth*image->nChannels;
		m_pBits = (unsigned char *)image->imageData;
	}
	voidImage = (void *)image;
	return TRUE;
}

//±£¥ÊÕºœÒ
BOOL CYangLiuImageProcess::SaveImage(LPCTSTR lpszPathName)
{
	IplImage *image = (IplImage*)voidImage;
	if (m_nOpenMode == 1 && m_pBits != NULL)
	{
		SaveBMP(lpszPathName);
	}
	if (m_nOpenMode == 2 && image != NULL)
	{
		cvSaveImage(lpszPathName, image);
	}
	return TRUE;
}

//≈–∂œBMPªÚJPG≤¢œ‘ æÕºœÒ
void CYangLiuImageProcess::ImageDisplay(CDC * pDC, double dZoom)
{
	IplImage *image = (IplImage*)voidImage;
	if (m_nOpenMode == 1) //BMP
	{
		StretchDIBits(pDC->m_hDC, 0, 0,
			int(dZoom*imageWidth + 0.5), int(dZoom* imageHeight + 0.5), 0, 0, imageWidth, imageHeight,
			m_pBits, lpbmi, DIB_RGB_COLORS, SRCCOPY);
	}
	if (m_nOpenMode == 2) //JPG
	{
		StretchDIBits(pDC->m_hDC, 0, 0, int(dZoom*image->width + 0.5), int(dZoom*image->height + 0.5),
			0, image->height, image->width, -image->height,
			image->imageData, lpbmi,
			DIB_RGB_COLORS, SRCCOPY);
	}
}



void CYangLiuImageProcess::WongTrinder(void)
{
	wongTri wt;
	if(m_pBits==NULL)
		return;
	wt.searchCenter(m_pBits,imageWidth,imageHeight);
	x=wt.getX();
	y=wt.getY();
}