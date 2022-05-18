#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
	time_t curt;
	struct tm *ptm;
	char *ctm;
	//curt=timr(NULL);
	time(&curt);
	printf("%ld\n",curt );
	ptm=localtime(&curt);
	printf("%d年%d月%d日%d:%d:%d\n",
			ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
			ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
	ctm=ctime(&curt);
	printf("%s\n",ctm );
	printf("end");

	return 0;
}

