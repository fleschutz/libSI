#pragma once
#include <utility>

/** \file
	Functions for registering and querying resource data.

	Benefits compared to windows resources:
	- supports compressed data, data does not show up as cleartext in executable
	- no fiddling around with resource IDs and such
	- access to binary data as-is

	This module is intended to be used together with the internal\ResourceCompiler. The resource compiler compresses multiple files
	into one single CPP file that is compiled into the project. The CPP file statically registers all its resources into this module.

	All functions are thread-safe.
*/
namespace core
{
	/// Register a compressed resource
	/**
		Data has to be compressed with zlib 'compress' function
	*/
	void resource_register_compressed(const char* path, const void* compressedData, size_t compressedSize, size_t uncompressedSize);

	/// Query resource, returns {nullptr, 0} if resource is not available
	std::pair<const void*, size_t> resource_query(const char* path);

	/// Query resource as null-terminated string, useful for text file resources and such
	const char* resource_query_string(const char* path);
}