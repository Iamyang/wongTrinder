#pragma once


// wongTri

class wongTri : public CWnd
{
	DECLARE_DYNAMIC(wongTri)

public:
	wongTri();
	virtual ~wongTri();

protected:
	DECLARE_MESSAGE_MAP()


public:
	void searchCenter(unsigned char *pbits, long width, long height);
	int getX(void);
	int getY(void);
private:
	int x;
	int y;
};


