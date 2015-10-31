#pragma once




class   CYangLiuImageProcess
{
public:
	CYangLiuImageProcess();
	virtual ~CYangLiuImageProcess();
public:
	//IplImage* image; //OpenCV图像指针
	void * voidImage;

	BITMAPINFO * lpbmi;
	unsigned char * m_pBits;
	BITMAPFILEHEADER bmpFH;
	int imageWidth;
	int imageHeight;
	int m_nColorBits; //8 24
	int m_nOpenMode; // BMP =1 JPG=2

	long m_lValue[256]; //红色分量灰度统计
	double m_dValue[256]; // 红色分量灰度频数
	long m_lValueG[256]; //绿色分量灰度统计
	double m_dValueG[256]; // 绿色分量灰度频数
	long m_lValueB[256]; //蓝色分量灰度统计
	double m_dValueB[256]; //蓝色分量灰度频数
	double dMax, dMaxG, dMaxB; //红、 绿、 蓝频数最大值
	
	double m_dZoom;//放大或缩小倍数
	int x;
	int y;
	// 操作
public:
	BOOL ReadBMP(LPCTSTR lpszPathName);
	BOOL SaveBMP(LPCTSTR lpszPathName);
	BOOL ReadImage(LPCTSTR lpszPathName);
	BOOL SaveImage(LPCTSTR lpszPathName);
	
	void ImageDisplay(CDC * pDC, double dZoom);
	
	void WongTrinder(void);
};

