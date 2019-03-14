
#include "show.h"
#include "key.h"
#include "lcd.h"



//  显示 a:b:c
//	
void show_time(int a,int b,int c){

	
}


// 初始化显示 00:00:00
void Init_time(){
	show_time(0,0,0);
}



// 设定时间	
// 实现: 按键A 递增；按键B 选取 时？分？秒？  
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
	 }else{break;}	  // 按0时，退出while 循环，即结束时间设定	    	 
   }
   arr[0] = a; arr[1] = b; arr[2] = c;		 //将 a，b，c的值传入数组中；
  return arr;
}


// 按键B 
// 	显示：“设定：时/分/秒”
int Press_B(int flag){
	if(flag<3)
	 	{flag++;  }
	else
		{flag = 1;}
	return flag;
}

// 按键A ：超过60判断 
int Press_A(int a){
	if(a<60)
	{a++;}
	else
	{a = 0;}
	return a;
}

// 在固定区域打印提示语句；例如：”请设定：时“
void print(unsigned char *C) {

}