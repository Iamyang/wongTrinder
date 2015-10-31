#pragma once




class   CYangLiuImageProcess
{
public:
	CYangLiuImageProcess();
	virtual ~CYangLiuImageProcess();
public:
	//IplImage* image; //OpenCVͼ��ָ��
	void * voidImage;

	BITMAPINFO * lpbmi;
	unsigned char * m_pBits;
	BITMAPFILEHEADER bmpFH;
	int imageWidth;
	int imageHeight;
	int m_nColorBits; //8 24
	int m_nOpenMode; // BMP =1 JPG=2

	long m_lValue[256]; //��ɫ�����Ҷ�ͳ��
	double m_dValue[256]; // ��ɫ�����Ҷ�Ƶ��
	long m_lValueG[256]; //��ɫ�����Ҷ�ͳ��
	double m_dValueG[256]; // ��ɫ�����Ҷ�Ƶ��
	long m_lValueB[256]; //��ɫ�����Ҷ�ͳ��
	double m_dValueB[256]; //��ɫ�����Ҷ�Ƶ��
	double dMax, dMaxG, dMaxB; //�졢 �̡� ��Ƶ�����ֵ
	
	double m_dZoom;//�Ŵ����С����
	int x;
	int y;
	// ����
public:
	BOOL ReadBMP(LPCTSTR lpszPathName);
	BOOL SaveBMP(LPCTSTR lpszPathName);
	BOOL ReadImage(LPCTSTR lpszPathName);
	BOOL SaveImage(LPCTSTR lpszPathName);
	
	void ImageDisplay(CDC * pDC, double dZoom);
	
	void WongTrinder(void);
};

