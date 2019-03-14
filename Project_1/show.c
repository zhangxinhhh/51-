
#include "show.h"
#include "key.h"
#include "lcd.h"



//  ��ʾ a:b:c
//	
void show_time(int a,int b,int c){

	
}


// ��ʼ����ʾ 00:00:00
void Init_time(){
	show_time(0,0,0);
}



// �趨ʱ��	
// ʵ��: ����A ����������B ѡȡ ʱ���֣��룿  
int* set_time(int arr[]){
   int a,b,c ;
   int flag=1; 
   unsigned char key;

   a=b=c=0;
   Clear();
   show_time(0,0,0);
   while(1){
	 key = KeyScan();
	 if(key!=0){
	 	switch(key){
			case 'A':
				   clear();
				   if(flag == 1)     {a = Press_A(a);}
				   else if(flag == 2){b = Press_A(b);}
				   else              {c = Press_A(c);}
				   show_time(a,b,c);
				   break;

			case 'B':
				   flag = Press_B(flag);
				   break;

			default: break;		
		}	 
	 }else{break;}	  // ��0ʱ���˳�while ѭ����������ʱ���趨	    	 
   }
   arr[0] = a; arr[1] = b; arr[2] = c;		 //�� a��b��c��ֵ���������У�
  return arr;
}


// ����B 
// 	��ʾ�����趨��ʱ/��/�롱
int Press_B(int flag){
	if(flag<3)
	 	{flag++;  }
	else
		{flag = 1;}
	return flag;
}

// ����A ������60�ж� 
int Press_A(int a){
	if(a<60)
	{a++;}
	else
	{a = 0;}
	return a;
}

// �ڹ̶������ӡ��ʾ��䣻���磺�����趨��ʱ��
void print(unsigned char *C) {

}