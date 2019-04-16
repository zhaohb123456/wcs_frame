#ifndef _THREAD_POOL_
#define _THREAD_POOL_


#ifndef TPBOOL   
typedef int TPBOOL;
#endif   

#ifndef TRUE   
#define TRUE 1   
#endif   

#ifndef FALSE   
#define FALSE 0   
#endif   

#define THRESHOLD_BUSY 2  //(busy thread)/(all thread threshold)   
#define MANAGE_INTERVAL 5   //tp manage thread sleep interval   

typedef struct tp_work_param_s tp_work_param;
typedef struct tp_work_s tp_work;
typedef struct tp_thread_info_s tp_thread_info;
typedef struct tp_thread_pool_s tp_thread_pool;

//thread parm   
struct tp_work_param_s {
	char *inum; //call in   
	char *onum; //call out   
	int reserve;  //channel num   
};

struct tp_work_s {
	void(*work_func)(tp_work_param *param);
};

//thread info   
struct tp_thread_info_s {
	unsigned long   thread_id;  //thread id num   
	TPBOOL          is_busy;    //thread status:true-busy;flase-idle   
	pthread_cond_t          thread_cond;
	pthread_mutex_t     thread_lock;
	tp_work *work;
	tp_work_param *work_param;
};

//main thread pool struct   
struct tp_thread_pool_s {
	TPBOOL(*init)(tp_thread_pool *this);
	void(*close)(tp_thread_pool *this);
	void(*process_job)(tp_thread_pool *this, tp_work *worker, tp_work_desc *job);
	int(*get_thread_by_id)(tp_thread_pool *this, int id);
	TPBOOL(*add_thread)(tp_thread_pool *this);
	TPBOOL(*delete_thread)(tp_thread_pool *this);
	int(*get_tp_status)(tp_thread_pool *this);

	int min_th_num;     //min thread number in the pool   
	int cur_th_num;     //current thread number in the pool   
	int max_th_num;         //max thread number in the pool   
	pthread_mutex_t tp_lock;
	unsigned long manage_thread_id; //manage thread id num   
	tp_thread_info *thread_info;    //work thread relative thread info   
};

tp_thread_pool *creat_thread_pool(int min_num, int max_num);

#endif // !_THREAD_POOL_
