#pragma once

#include "HRMTimeAPI.h"
#include "QuickUSB.h"
#include "ni4882.h"
#include "MTIDevice.h"
#include "MTIDefinitions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <string>
#include <time.h>
#include <stdlib.h>


// for the delay***********************
#define DLY_BOARDID 0
#define DLY_PRIMARYADD 5
#define DLY_SECONDARYADD 0
#define DLY_TIMEOUT 10
#define DLY_EOS 1
#define DLY_EOT 0
unsigned int dly_ud;
int getCount();
int connect_dly();
void setDly(float dly);



//int change_delay(int dly);
//int change_offs

//for the TDC***************************************************************************
typedef unsigned char Ubyte; /* Unsigned byte */
typedef char Sbyte; /* Signed byte */
typedef unsigned short Uword; /* Unsigned 16 bits */
typedef short Sword; /* Signed 16 bits */
typedef unsigned int Ulong; /* Unsigned 32 bits */
typedef int Slong; /* Signed 32 bits */
typedef double Sdoub; /* Double */
#define CH0_ADDR 0
#define CH1_ADDR CH0_ADDR+0x80000
#define CH2_ADDR CH1_ADDR+0x80000
#define CH3_ADDR CH2_ADDR+0x80000
#define TCSPC 1
#define CHANN 0x9999

#define  MEMORY_SZ      (Ulong)0x200000
FILE *fl;
HANDLE hdl[1];
HRM_STATUS error;
HANDLE connect_tdc();
Ulong buffer[0x200000];

//for the Mirror*************************************************************************
#define OUTCHAR 255
MTIDevice* connect_mems();
 MTIDevice *mti;
 MTIError LastError;

float minX;
float minY;
float maxX;
float maxY;
float xSteps;
float ySteps;
char fileName[255];
char portNo[5];
float macroSteps;
float microSteps;
float peakCheck;
int threshold;
int tdcTime;
float delayMin;
float delayMax;
char fileName2[255];

FILE *alldata, *adpdata;

void usage();

float getAdaptive(float x, float y, float fnlDlymin, float fnlDlymax);

// structure to process the adaptive
struct delayNCount {
	float delay;
	int count;
};
delayNCount dc[300];