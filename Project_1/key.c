#include "C8051F020.h"
//#include "DataType.h"
//#include "math.h"
//#include "string.h"
//#include "stdio.h"
//#include "Device.h"

/*
void KeyPort_Init ()
{
   P74OUT |= BIT0 ; //P4.0-P4.3����Ϊ�������
   P74OUT &= ~BIT1; //P4.4-P4.7���ó�©����·���
	P4 |= BIT4 + BIT5 + BIT6 +BIT7; //��1©����·���ŵ����ݼĴ�����ʹ��Ϊ��������ģʽ
}
*/

/**********************************************************************************************************
PA1=P4.0  PA2=P4.1 PA3=P4.2 PB1=P4.4 PB2=P4.5 PB3=P4.6
* �������ƣ�KeyScan
* �������ܣ�����ɨ�裬����0��ʾ�޼����£�1-16����������
**********************************************************************************************************/
unsigned char KeyScan(void)
{
  unsigned long i;

  P4=(P4&0x80)|(P4&0x08)|0x70;
  if(0x70 == (P4 & 0x70)) // û�а���������0
  {
    return 0;
  }
 
  for(i = 0;i < 12000;i ++);  // �м����£���ʱ�� ���޸�
  
 // ɨ��KEY1 - KEY3
  P4=(P4&0x80)|(P4&0x08)|0x76;
  if(0x70 != (P4 & 0x70))
  {
    switch((P4 & 0x70))
    {
    case 0x60:
      return 1;
    case 0x50:
      return 2;
    case 0x30:
      return 3;      
  
    default:
      return 0; 
    }
  } 

  P4=(P4&0x80)|(P4&0x08)|0x75; // ɨ��KEY4 - KEY6
  if(0x70 != (P4 & 0x70))
  {
    switch((P4 & 0x70))
    {
    case 0x60:
      return 4;
    case 0x50:
      return 5;
    case 0x30:
      return 6;     
    default:
      return 0; 
    }
  }    

  P4=(P4&0x80)|(P4&0x08)|0x73; // ɨ��KEY7- KEY9
  if(0x70 != (P4 & 0x70))
  {
    switch((P4 & 0x70))
    {
    case 0x60:
      return 7;
    case 0x50:
      return 8;
    case 0x30:
      return 9;      
    default:
      return 0; 
    }
  }  
  return 0;
}