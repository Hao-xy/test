#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<pwd.h>
#include<grp.h>
#include<errno.h>
#include<string.h>
#include<linux/fs.h>
#include<time.h>

void printf_size(struct stat*statp)
{
	switch(statp->st_mode&S_IFMT)
	{
		case S_IFCHR:
		case S_IFBLK:
		printf(" %u, %u",(unsigned)(statp->st_rdev>>8),
		(unsigned)(statp->st_rdev&0xFF));
		break;
		default:
		printf(" %lu",(unsigned long)statp->st_size);
	}
}

void printf_data(struct stat*statp)
{
	time_t now;
	double diff;
	char buf[100],*fmt;
	if(time(&now)==-1)
	{
		printf(" ??????????????");
		return;
	}
	diff =difftime(now,statp->st_mtime);
	if(diff<0||diff>60*60*24*182.5)
		fmt="%b %e %Y";
	else
		fmt="%b %e %H:%M";
	strftime(buf,sizeof(buf),fmt,localtime(&statp->st_mtime));
	printf(" %s",buf);
}
void myls(char const* fname)
{
  struct stat buf;
  int rt;
  rt=lstat(fname,&buf);
  int typeflag=0;
  if(rt==1)
  {
    perror("lstat");
    exit(1);
  }
  switch(buf.st_mode& S_IFMT)
  {
    case S_IFREG:printf("-");
           break;
      case S_IFDIR:printf("d");
           break;
      case S_IFCHR:printf("c");typeflag=1;
           break;
      case S_IFBLK:printf("b");typeflag=1;
           break;
      case S_IFIFO:printf("p");
           break;
      case S_IFLNK:printf("l");typeflag=2;
           break;
      case S_IFSOCK:printf("s");
            break;
      default:printf("?");
        break;
  }
  (buf.st_mode & S_IRUSR) ? printf("r") : printf("-");
  (buf.st_mode & S_IWUSR) ? printf("w") : printf("-");
  if((buf.st_mode & S_ISUID) == 0)
    (buf.st_mode & S_IXUSR) ? printf("x") :printf("-");
  else
    (buf.st_mode & S_IXUSR) ? printf("s") :printf("S");

  (buf.st_mode &S_IRGRP) ? printf("r") : printf("-");
  (buf.st_mode &S_IWGRP) ? printf("w") : printf("-");
  if((buf.st_mode & S_ISGID)==0)
    (buf.st_mode & S_IXGRP) ? printf("x") : printf("-");
  else
    (buf.st_mode & S_IXGRP) ? printf("s") : printf("S");

  (buf.st_mode & S_IROTH) ? printf("r") : printf("-");
  (buf.st_mode & S_IWOTH) ? printf("w") : printf("-");
  if((buf.st_mode & S_ISVTX)==0)
    (buf.st_mode & S_IXOTH) ? printf("x") : printf("-");
  else
    (buf.st_mode & S_IXOTH) ? printf("t") : printf("T");

  printf(" %ld",buf.st_nlink);

  struct passwd *usr;
  usr=getpwuid(buf.st_uid);
  printf(" %s",usr->pw_name);
  struct group *grp;
  grp=getgrgid(buf.st_gid);
  printf(" %s",grp->gr_name);
  
  if(typeflag==1)
  	printf("%u,%u",(unsigned)(buf.st_rdev>>8),(unsigned)(buf.st_rdev & 0xFF));
  else
  printf("%ld",buf.st_size);
  
  time_t now;
  double diff;
  char timebuf[100],*fmt;
  if(time(&now)==-1)
  	printf("?????????");
  diff=difftime(now,buf.st_mtime);
  if(diff <0||diff>60*60*24*182.5)
  	fmt="%b %e %y";
  else
  	fmt="%b %e %h:%m";
  strftime(timebuf,sizeof(timebuf),fmt,localtime(&buf.st_mtime));
  printf(" %s",timebuf);
  printf(" %s",fname);
  if(typeflag==2){
  	char namebuf[128];
  	int num=readlink(fname,namebuf,sizeof(namebuf)-1);
  	if(num!=-1){
  		namebuf[num]='\0';
  		printf("\033[40;33m%s\033[0m",namebuf);
  	}
  }
  printf("\n");
}
int main(int argc, char const *argv[])
  {
    if(argc==1)
    {
      printf("usage:%s filename\n",argv[0]);
      exit(1);
    }
    myls(argv[1]);
    return 0;
  }