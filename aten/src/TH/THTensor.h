#ifndef TH_TENSOR_INC
#define TH_TENSOR_INC

#include <TH/THStorageFunctions.h>
#include <TH/THTensorApply.h>

#define THTensor_(NAME)   TH_CONCAT_4(TH,Real,Tensor_,NAME)

//THtensor头文件实际上是一个集合
//包含了THTensor的基本操作类

//基本操作 产生不同的数据类型 
/* basics */
#include <TH/generic/THTensor.h>
#include <TH/THGenerateAllTypes.h>

#include <TH/generic/THTensor.h>
#include <TH/THGenerateHalfType.h>

//随机数生成
/* random numbers */
#include <TH/THRandom.h>
#include <TH/generic/THTensorRandom.h>
#include <TH/THGenerateAllTypes.h>

/* maths */
//基本的数学计算
#include <TH/generic/THTensorMath.h>
#include <TH/THGenerateAllTypes.h>

/* convolutions */
//基本的卷积计算
//实现代码在generic文件夹中
//包含 stride！= 1  2D 3D  4D 卷积 
#include <TH/generic/THTensorConv.h>
#include <TH/THGenerateAllTypes.h>

/* lapack support */
//基本的LAPACK && BLAS 计算实现 
#include <TH/generic/THTensorLapack.h>
#include <TH/THGenerateFloatTypes.h>
#endif
