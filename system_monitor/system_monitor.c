#include <stdio.h>
#include <string.h>
#define MAX 128

void cpuinfo();
void kernel_version();

int main() {
	cpuinfo();
	kernel_version();
	return 0;
}


void cpuinfo() {
	int ok_cputype = 0;
	int ok_cpumodel = 0;

	FILE *fd= fopen("/proc/cpuinfo","r");
	char buf[MAX];
	char tag[MAX], rem[MAX], tag1[MAX];
	char ch[MAX];
	char cpuType[MAX], cpuModel[MAX];

	while (ok_cputype != 1 || ok_cpumodel !=1)
	{
		fgets(buf,MAX + 1,fd);
		sscanf(buf,"%s%[^\n]s", tag, rem);
		if (strcmp(tag, "vendor_id") == 0) {
			sscanf(rem, "%s %s", ch, tag);
			strcpy(cpuType, tag);
			strcat(cpuType," ");
		}

		if (strcmp(tag, "model") == 0){
			sscanf(rem,"%s", tag1);
			printf("%s\n",tag1);
			if (strcmp(tag1, "name") == 0){
				sscanf(rem,"%s %s %[^\n]s",tag1,ch,cpuModel);
				ok_cpumodel = 1;
			} else {
				sscanf(rem, "%s %s", ch, tag);
				strcat(cpuType, tag);
			}
		}

		if (strcmp(tag,"stepping") == 0) {
			sscanf(rem, "%s %s", ch, tag);
			strcat(cpuType, tag);
			ok_cputype = 1;
		}

	}

	fclose(fd);
	printf("CPU Type is:	%s\n", cpuType);
}

void kernel_version()
{
    FILE *fd = fopen("/proc/version","r");
	char buf[MAX];
	while(fgets(buf,MAX,fd))
    {
        printf("%s",buf);
    }

    fclose(fd);
}
