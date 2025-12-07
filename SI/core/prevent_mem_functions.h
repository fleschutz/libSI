#pragma once

#if (_MSC_VER > 1500)
#	define ATTOWER_PREVENT_MEM_FAILURE	\
	static_assert(false, "Thou shalt not use mem functions!")
#else
#	define ATTOWER_PREVENT_MEM_FAILURE	\
	sizeof(void);
#endif


#define ATTOWER_PREVENT_MEM_FUNCTIONS(class_)					\
																\
template <class T = void>										\
void memset(const class_*, int, size_t)							\
{																\
	ATTOWER_PREVENT_MEM_FAILURE;								\
}																\
																\
template <class T = void>										\
void memcpy(const class_*, const void*, size_t)					\
{																\
	ATTOWER_PREVENT_MEM_FAILURE;								\
}																\
																\
template <class T = void>										\
void memcpy(const void*, const class_*, size_t)					\
{																\
	ATTOWER_PREVENT_MEM_FAILURE;								\
}

