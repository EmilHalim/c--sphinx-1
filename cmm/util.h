#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
long fgetsize(FILE* handle);

struct ftime
{
	unsigned ft_tsec: 5; /* ��� ������� */
	unsigned ft_min: 6;  /* ������ */
	unsigned ft_hour: 5; /* ���� */
	unsigned ft_day: 5;  /* ���� */
	unsigned ft_month: 4; /* ����� */
	unsigned ft_year: 7; /* ���-1980 */
};

void GetFileTime(char* fname, struct ftime* buf);

#endif
