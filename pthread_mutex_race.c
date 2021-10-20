#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// 計數器
int counter = 0;

//加入 mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// 子執行緒函數
void* child() {
  for(int i = 0;i < 3;++i) {
    pthread_mutex_lock(&mutex1);//非同步空間上鎖
    int tmp = counter;
    // 故意讓它延遲一下，因為加入延遲可以讓不同的 core 看到對 counter value 是一樣的
    sleep(1); 
    counter = tmp + 1;
     pthread_mutex_unlock(&mutex1);//解鎖
    printf("Counter = %d\n", counter);
  }
  pthread_exit(NULL);
}

// 主程式
int main() {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, child, NULL);
  pthread_create(&t2, NULL, child, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}