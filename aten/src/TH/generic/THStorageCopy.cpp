#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "TH/generic/THStorageCopy.cpp"
#else
//THTensor的拷贝函数定义

//原始拷贝/暴力拷贝 
//实际上就是遍历+复制 
void THStorage_(rawCopy)(THStorage *storage, scalar_t *src)
{
  ptrdiff_t i;
  scalar_t *data = THStorage_(data)(storage);
  for(i = 0; i < storage->numel(); i++)
    data[i] = src[i];
}

//在暴力拷贝的基础上做预判断，保障数据尺寸一致
void THStorage_(copy)(THStorage *storage, THStorage *src)
{
  THArgCheck(storage->numel() == src->numel(), 2, "size mismatch");
  THStorage_(rawCopy)(storage, THStorage_(data)(src));
}

// NOTE: for performance, these macros generally use the raw data pointer in the inner loops,
// rather than repeated THStorage_(data) calls.

//开始宏定义
//利用宏定义的方式实现了泛型的效果
//拷贝不同数据类型的THTensor
#define IMPLEMENT_THStorage_COPY(TYPENAMESRC) \
void THStorage_(copy##TYPENAMESRC)(THStorage *storage, TH##TYPENAMESRC##Storage *src) \
{ \
  ptrdiff_t i;                                                          \
  auto data = THStorage_(data)(storage);                                \
  auto src_data = TH##TYPENAMESRC##Storage_data(src);                   \
  for(i = 0; i < storage->numel(); i++)                                    \
    data[i] = static_cast<scalar_t>(src_data[i]);                           \
}

IMPLEMENT_THStorage_COPY(Byte)
IMPLEMENT_THStorage_COPY(Char)
IMPLEMENT_THStorage_COPY(Short)
IMPLEMENT_THStorage_COPY(Int)
IMPLEMENT_THStorage_COPY(Long)
IMPLEMENT_THStorage_COPY(Float)
IMPLEMENT_THStorage_COPY(Double)
IMPLEMENT_THStorage_COPY(Half)

#endif
