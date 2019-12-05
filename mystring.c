/*
 * @Author: herhan
 * @Date: 2019-11-26 15:25:38
 * @LastEditTime: 2019-12-04 17:07:33
 * @LastEditors: Please set LastEditors
 * @Description: 常见字符串操作函数的实现
 * @FilePath: /root/.vscode/mystrcpy.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//strlen 计算字符串长短
size_t mystrlen(const char * src){
    assert(src);
    size_t count = 0;
    while (*src++){
        count++;
    }
    return count;
}
//strcpy 拷贝 将参数src字符串拷贝至参数dest所指的地址
char * mystrcpy(char * dest, const char * src){
    assert(dest != NULL);
    assert(src != NULL);
    char * ptr = dest;
    while (*src){
        *dest++ = *src++;
    }
    *dest = *src;
    return ptr;
}
//strncpy 将字符串src前n个字符拷贝到字符串dest。
char * mystrncpy(char *dest,const char *src, size_t count){
    assert(dest != NULL);
    assert(src != NULL);
    char * ptr = dest;
    while (count-- && *src != '\0'){
          *ptr++ = *src++;
    }
    if (*src == '\0')
        *ptr = '\0';
    return dest;    
}
//mystrcmp 字符串比较
int mystrcmp(const char * dest, const char * src){
    assert(dest);
    assert(src);
    char * dtr = dest;
    char * str = src;
    while ( (*dtr == *str)&&(*dtr != '\0')&&(*str != '\0' )){
        dtr++;
        str++;
    }
    if ( *dtr > *str)
        return 1;
    else if (*dtr < *str)
        return -1;
    if ( *dtr == *str == '\0')
        return 0; 
}
//mystrncmp 字符串前n个字符比较。
int mystrncmp(const char *dest,const char * src, size_t count){
    assert(dest);
    assert(src);
    char * dtr = dest;
    char * str = src;
    while((count--)&&(*dtr != '\0')&&(*str != '\0')){
        if(*dtr > *str)
            return 1;
        if(*dtr < *str)
            return -1;
        dtr++;
        str++;
    }
    if(*dtr != '\0')
        return 1;
    if(*str != '\0')
        return -1;
    return 0;
}
//strcat 字符串拼接函数
char * mystrcat(char * dest ,const char * src){
    assert(dest != NULL);
    assert(src != NULL);
    char * ptr = dest;
    while(*dest != '\0'){
        dest++;
    }
    while(*dest++ = *src++);
    *dest = *src;
    return ptr;    
}
//strncat
char *mystrncat(char * dest,const char * src,size_t count){
    assert(dest);
    assert(src);
    char * dtr = dest;
    while(count-- && *dest != '\0'){
        dest++;
    }
    while(*dest++ = *src++);
    *dest = *src;
    return dtr;
}
//strchr 在一个字符串中查找给定字符的第一个匹配之处
char *mystrchr(const char * dest,char c){
    assert(dest != NULL);
    char *ptr = dest;
    while(*ptr++ != c);
    if(*ptr != '\0'){
        return --ptr;
    }
    else{
        return NULL;
    }
}
//strstr 检索子串在字符串中首次出现的位置。
char * mystrstr(const char * dest, const char * src){
    assert(dest);
    assert(src);
    char * ptr1 = dest;
    char * ptr2 = NULL;
    while(*ptr1 != '\0' && *ptr1 != *src){
        ptr1++;
        ptr2 = ptr1;
    }
    while(*ptr1 == *src){
        ptr1++;
        src++;
    }
    if(*src != '\0')
        return NULL;
    else
        return ptr2;
}


int main (void){
    char a[] = "111hello";
    char b[] = "world";
    //printf("%s\n",mystrcpy(a,b));
    printf("a:%d b:%d \n",mystrlen(a),mystrlen(b));
    printf("%s\n",mystrncat(a,b,2));
    return 0;
}
