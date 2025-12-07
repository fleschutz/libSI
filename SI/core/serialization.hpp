#pragma once

/** \file

	This includes all serialization headers with support for all types.

	If you want to reduce dependencies / optimize compilation time, only include `fwd.hpp` or, if
	necessary, `serialization/core.hpp` in your headers. Implementation files are free to always use
	this comprehensive include.

	### Serialize Data ###

	Serialization starts by picking a `serialization_sink` implementation, most commonly
	`serialization_data_sink` for serializing to raw bytes. All to-be-serialized variables are then
	passed to the `serialization_sink::write` method.

	Example:
	~~~
	core::serialization_data_sink sink;
	sink.write(someInteger);
	sink.write(someVector);
	sink.write(someObject);

	transmitRawData(sink.data(), sink.size());
	~~~

	### Deserialize Data ###

	Deserialization starts by picking a `serialization_source` implementation, most commonly
	`serialization_data_source` for deserializing from raw bytes. Differing variations of
	`serialization_source::read` are available to read variables from the source.

	Note that you have to use exactly the same types for serializaton and deserialization.

	Example:
	~~~
	core::serialization_data_source source(data, size);
	source.read(&someInteger);
	auto vec = source.read<SomeVectorType>();
	auto someObject = source.read_unique<SomeObjectType>();
	~~~

	### Implementing serialization for your own types ###

	This module supports serialization for trivial types and some std / 3rdparty types (e.g. unique_ptr,
	optionals, containers, etc...)

	To add support for your own class, implement an `operator()` accepting a `serialization_visitor`. The
	operator should pass all its members to the visitor (including types that should not be serialized
	like mutexes, see `serialization_visitor::ignore`).

	Example:
	~~~
	struct MyData
	{
		std::mutex mutex;
		std::string str;
		int id;

		void operator()(serialization_visitor v)
		{
			v.ignore(mutex);
			v(str);
			v(id);
		}
	};
	~~~

	Classes that don't support default construction have to implement a constructor taking a `serialization_key`,
	this makes it possible to construct these types during deserialization.
*/

#include "fwd.hpp"
#include "serialization/core.hpp"
#include "serialization/std.hpp"
#include "serialization/3rdparty.hpp"