#pragma once

#if defined(_MSC_VER)

#	if(_MSC_VER == 1500)
#		define ATTOWER_LIB_NAME_TOOLSET "vc90"
#	elif (_MSC_VER == 1800)
#		define ATTOWER_LIB_NAME_TOOLSET "vc120"
#	elif (_MSC_VER >= 1910 && _MSC_VER < 2000)
#		define ATTOWER_LIB_NAME_TOOLSET "vc141"
#	else
#		error "Visual Studio version not supported"
#	endif

#	if defined(_M_X64)
#		define ATTOWER_LIB_NAME_PLATFORM "_x64"
#	else
#		define ATTOWER_LIB_NAME_PLATFORM ""
#	endif

#	if defined(_MT)
#		define ATTOWER_LIB_NAME_THREAD_OPT "-mt"
#	else
#		define ATTOWER_LIB_NAME_THREAD_OPT ""
#	endif

#	if defined(_DLL)
#		if !defined(_DEBUG) && defined(NDEBUG)
#			define ATTOWER_LIB_NAME_RT_OPT ""
#		elif defined(_DEBUG) && !defined(NDEBUG)
#			define ATTOWER_LIB_NAME_RT_OPT "-gd"
#		else
#			error "Runtime option set not supported"
#		endif
#	else
#		error "Static runtime library not supported"
#	endif

/// Expands to a library name string literal
/**
	ATTower libraries are named by using a naming scheme derived from boost libraries.
	This macro expands a prefix, a name and a extension to a full-fledged library name, including toolset, runtime options etc.

	For example: <prefix><name>-vc120_x64-mt-gd<extension>

	All three parameters must be string literals.
	This can be used to auto-link static libraries (by using pragma comment lib) or to load dynamic libraries.
*/
#	define ATTOWER_LIB_NAME(prefix_, name_, extension_)	\
		prefix_ name_ "-" ATTOWER_LIB_NAME_TOOLSET ATTOWER_LIB_NAME_PLATFORM ATTOWER_LIB_NAME_THREAD_OPT ATTOWER_LIB_NAME_RT_OPT extension_

#else
#	error "Compiler not supported"
#endif