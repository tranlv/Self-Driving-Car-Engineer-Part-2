#include <stdio.h>
#define MAX 1024

int main() {
	FILE *fd = fopen("/proc/cpuinfo","r");
	char buf[MAX];
	char tag[MAX];
	char rem[MAX];
	while(fgets(buf,MAX,fd)) {
		sscanf(buf,"%s%[^\n]s", tag, rem);
		printf("%s",tag);
		printf("%s\r\n", rem);
	}
	fclose(fd);
	return 0;
}


