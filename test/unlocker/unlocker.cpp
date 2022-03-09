#pragma once

#include <stdio.h>

#include "..\..\unlocker.hpp"

#include <cstdlib>
#include <wchar.h>
#include <locale.h>

const wchar_t *GetWC(const char *c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

int version = 2;

// main
int _tmain(int argc, _TCHAR* argv[])
{
	if (version == 1)
	{
		tstring path = _T("F:\\projects\\vscodeProjects\\nuxt\\test安安");
		
		unlocker::File* file = unlocker::Path::Exists(path);
		if (file) {
			file->Unlock();
			wprintf(L"unlock成功！\n");
			delete file;
		}
	}
	else {
		setlocale(LC_ALL, "zh-CN");

		const char p[2048] = {};
		char p1[2048] = {};
		int j = 0;
		printf("请输入要解锁的文件(夹)路径：");
		scanf("%[^\n]", p);
		for (int i = 0; i < 2048; i++){
			if (p[i] == '/') {
				p1[j] = '\\'; 
			}
			else 
				p1[j] = p[i];
			if (p[i] == '\0')
				break;
			j++;
		}

		const wchar_t* path = GetWC(p1);
		//tstring path1 = path;
		////wscanf(L"%s", path1);
		//tstring path2 = _T("F:\\projects\\vscodeProjects\\nuxt\\test安安");
		//printf("%d", path1.compare(path2));
		//wprintf(L"path1: %s---\npath2: %s---\n", path1, path2);
		//system("pause");
		//return -2;

		unlocker::File* file = unlocker::Path::Exists(path);
		if (file) {
			file->Unlock();
			wprintf(L"unlock：%s 成功！\n", path);
			delete file;
		}
		else {
			wprintf(L"文件(夹)：%s 不存在！\n", path);
			system("pause");
		}
		delete path;
	}
	
	return 0;
}
