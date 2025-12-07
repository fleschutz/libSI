#pragma once

/// Function attribute to enable printf-format string checks
/**
	Currently only supported in ATTowerTidy (no effect in MSVC) and only for variadic
	functions (C-style `...`, not working for variadic function templates)

	First argument is the 1-based index of the format string parameter, second argument
	is the 1-based index of the first format parameter.

	Example:
	```
	void CORE_ATTRIBUTE_PRINTF(1, 2) my_printf(const char* fmt, ...);
	void CORE_ATTRIBUTE_PRINTF(2, 4) my_printf2(int level, const char* fmt, bool flush, ...);
	```
*/
#if ATTOWER_TIDY
#define CORE_ATTRIBUTE_PRINTF(fmt_, args_)	\
 __attribute__((__format__ (__printf__, fmt_, args_)))
#else
#define CORE_ATTRIBUTE_PRINTF(fmt_, args_)
#endif

#define CORE_DETAIL_CONCAT(lhs_, rhs_)	\
	CORE_DETAIL_CONCAT2(lhs_, rhs_)

#define CORE_DETAIL_CONCAT2(lhs_, rhs_)	\
	lhs_ ## rhs_

/// Function attribute to mark "wire" functions that are transmitting data in some way (via network or file)
/**
	Arguments are the 1-based indices of data parameters (either data itself or sizeof). Note that for object methods,
	the first "actual" argument is index 2 (index 1 is the implicit `this` pointer).
	
	ATTowerTidy uses this information to run additional checks e.g. for 64bit compatibility.
	
	Example:
	```
	void CORE_ATTRIBUTE_WIRE(2, 3) transmit(int opcode, const void* data, size_t len);
	void CORE_ATTRIBUTE_WIRE(1) transmit(const T& data);
	```
	
	Can be also used to mark struct member pointers which are then ignored in 64bit checks.
*/
#if ATTOWER_TIDY
#define CORE_ATTRIBUTE_WIRE(...)	\
 [[attower::wire(__VA_ARGS__)]]
#else
#define CORE_ATTRIBUTE_WIRE(...)
#endif