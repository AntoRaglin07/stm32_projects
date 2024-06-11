/*
 * main.c
 *
 *  Created on: Jun 10, 2024
 *      Author: antor
 */


#include <stdio.h>
#include <stdint.h>


int main(){
	int arr[2]={0x00,0x11 };
	printf("%d\n",arr[0]);
	printf("%d",*(arr+1));


}
