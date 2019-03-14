

//定时器初始化
void  Time_Init(){


}

//进入中断函数，每隔一秒调用一次
void Enter_IQR(int run_time[]){
		
}

//启动定时器
void run(int set_time[],int run_time[]){
	Time_Init();
	while(1){
	   show_time(run_time[0],run_time[1],run_time[2]);
	}

}