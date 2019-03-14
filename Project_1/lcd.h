#ifndef __LCD_H__
#define __LCD_H__

	#define		W_CMD		1			//ָ��
	#define		W_DAT		0			//����
	#define SetLCDRS  P4 |= 0x08 		 //�궨�壬��LCD_RS����λ����
	#define ClrLCDRS  P4 &= ~0x08
	#define SetLCDRST P4 |= 0x80 		 //�궨�壬��LCD_RST����λ����
	#define ClrLCDRST P4 &= ~0x80

	void Delayms(unsigned int ms);
	void WrateC(unsigned char com);	     	//��������	��LCDWrite�Ⱥ�������
	void WrateD(unsigned char dat);
	void LCDWrite(unsigned char type,unsigned char dat);
	void newLCDInit();
	void LCD_setXY(unsigned char X, unsigned char Y);
	void LCD_draw_point(unsigned char x,unsigned char y);
	void DrawPoint(unsigned char x,unsigned char y);
	void Clear();
	void Drawchar(unsigned char C,unsigned char row,unsigned char col);
	void DrawcharS(unsigned char *C,unsigned char row,unsigned char col);


	void Drawhanzi(unsigned char C,unsigned char row,unsigned char col);
	void Drawhanzifix(unsigned char C,unsigned char row,unsigned char col);	
		 
	void DrawhanziS(unsigned char *C,unsigned char row,unsigned char col);
	void DrawhanzifixS(unsigned char C,unsigned char row,unsigned char col);		 

#endif