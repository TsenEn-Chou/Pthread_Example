objects = pthread.o pthread_comm.o pthread_mutex_race.o pthread_semaphore.o

edit: $(objects)
	cc -o pth pthread.o
	cc -o pth_comm pthread_comm.o
	cc -o pth_mutex_race pthread_mutex_race.o
	cc -o pthread_semaphore pthread_semaphore.o
pthread.o: 
pthread_comm.o: 
pthread_mutex_race.o:
pthread_semaphore.o:

.PHONY: clean
clean:
	rm pth pth_comm pth_mutex_race pthread_semaphore $(objects)