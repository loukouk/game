#include <iostream>
#include <unistd.h>
#include <limits>
#include <time.h>
#include <pthread.h>


using namespace std;


void *thread1(void *)
{
	cout << "thread1 start" << endl;
	char buf2[16];
	while (1) {
//		usleep(100);
		if (read(STDIN_FILENO, buf2, 16) < 0)
			cout << "read error" << endl;
		else
			cout << "buf2: " << buf2 <<"/end2"<< endl;
	}
}

void *thread2(void *)
{
	cout << "thread2 start" << endl;
	char buf[16];
	while (1) {
		fgets(buf, 16, stdin);
		cout << endl << "buf:" << buf << "/end" << endl;
	}
}

int main()
{char buf2[16];
	while (1) {
//		usleep(100);
		if (read(STDIN_FILENO, buf2, 16) < 0)
			cout << "read error" << endl;
		else
			cout << "buf2: " << buf2 <<"/end2"<< endl;
	}
	pthread_t thr1, thr2;

	pthread_create(&thr1, NULL, thread1, NULL);
	pthread_create(&thr2, NULL, thread2, NULL);

	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
/*
	char c;
	char buf[16];
	fd_set read_set;
	struct timespec tv = {2,0};


	while(1) {

		cout << "start" << endl;
		FD_ZERO(&read_set);
		FD_SET(STDIN_FILENO, &read_set);
		if (pselect(STDIN_FILENO+1, &read_set, NULL, NULL, &tv, NULL) < 0)
			perror("pselect() - timeout failed");
		cout << "pselect done" << endl;

		if (FD_ISSET(STDIN_FILENO, &read_set)) {
//			fgets(&buf, 1, stdin);
			cout << "WE\nARE\nHERE" << endl;
//			buf = getchar();
			cin.ignore(numeric_limits<streamsize>::max(), EOF);
//			cout << endl << buf << endl;
		}
	}

*/
	return 0;
}
