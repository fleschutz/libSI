#pragma once
#include <string>
#include <vector>

/** \file
	Utility functions for working with strings.

	Unlike most standard functions, this functions are UTF-8 aware, i.e. have special
	treatment for UTF-8 characters if necessary.

	As UTF-8 is our preferred encoding for Unicode support, any new code should
	assume that any C-string / std::string contains UTF-8 encoding and should be
	treated as such.

	Functions prefixed with "i" are case-insensitive.
	Functions suffixed with "_view" return a `std::string_view` instead of a
	`std::string`, which is more efficient but requires more care regarding
	lifetime.

	### IMPORTANT: Case Conversion ###
	Except for the string variants of `tolower`/`toupper`, all functions in this module,
	including the various functors, perform case conversion ONLY FOR ASCII CHARACTERS.
	Case conversion for unicode characters in general is an expensive task and thus
	cannot performed transparently.
*/
namespace core
{
	///@{
	/// Converts the given character to lower-case / upper-case
	/**
		Converts only ASCII characters. Returns all other values as-is (including
		parts of UTF-8 multi-byte characters).

		`std::tolower`/`std::toupper` are not UTF-8 aware and would fail for multi-byte
		characters.

		It is not possible to convert all UTF-8 characters as they can be assembled
		of multiple `char`.

		See general note about "Case Conversion" above.
	*/
	[[nodiscard]] char tolower(char c);
	[[nodiscard]] char toupper(char c);
	///@}

	///@{
	/// Converts the given string to lower-case / upper-case
	/**
		UTF-8 aware, also properly converts any unicode characters.

		See general note about "Case Conversion" above.
	*/
	[[nodiscard]] std::string tolower(std::string_view str);
	[[nodiscard]] std::string toupper(std::string_view str);
	///@}

	/// Case-insensitive compare function
	/**
		Returns `-1` if lhs is less than rhs, `1` if rhs is less than lhs, `0` if both are equal.

		See general note about "Case Conversion" above.
	*/
	[[nodiscard]] int icompare(std::string_view lhs, std::string_view rhs);

	/// Case-insensitive compare function
	/**
		Returns `true` if both strings are equal.

		Does only support ASCII case conversion, does not convert UTF-8 characters. Which makes
		this much (!) more performant than e.g. `boost::iequals`.

		See general note about "Case Conversion" above.
	*/
	[[nodiscard]] bool iequals(std::string_view lhs, std::string_view rhs);

	/// Case-insensitive comparison function
	/**
		Can be used to instantiate case-insensitive associative containers,
		e.g. `std::set<std::string, core::iless>`.

		See general note about "Case Conversion" above.
	*/
	struct iless
	{
		using is_transparent = void;
		[[nodiscard]] bool operator()(std::string_view lhs, std::string_view rhs) const;
	};

	/// Case-insensitive hash function
	/**
		Can be used to instantiate case-insensitive associative containers,
		e.g. `std::unordered_set<std::string, core::ihash, core::iequal_to>`.

		See general note about "Case Conversion" above.
	*/
	struct ihash
	{
		[[nodiscard]] size_t operator()(std::string_view str) const;
	};

	/// Case-insensitive comparsion function
	/**
		Can be used to instantiate case-insensitive associative containers,
		e.g. `std::unordered_set<std::string, core::ihash, core::iequal_to>`.

		See general note about "Case Conversion" above.
	*/
	struct iequal_to
	{
		[[nodiscard]] bool operator()(std::string_view lhs, std::string_view rhs) const;
	};

	///@{
	/// Trims a string by removing any whitespaces left and right
	/**
		Can also be used to trim arbitrary characters by passing them as second argument.
	*/
	[[nodiscard]] std::string trim(std::string_view str, std::string_view c = " \t\n\r\f\v");
	[[nodiscard]] std::string_view trim_view(std::string_view str, std::string_view c = " \t\n\r\f\v");
	///@}

	///@{
	/// Returns `true` if a string starts / ends with the given prefix / suffix
	/**
		See general note about "Case Conversion" above.
	*/
	[[nodiscard]] bool starts_with(std::string_view str, std::string_view prefix);
	[[nodiscard]] bool istarts_with(std::string_view str, std::string_view prefix);
	[[nodiscard]] bool ends_with(std::string_view str, std::string_view suffix);
	[[nodiscard]] bool iends_with(std::string_view str, std::string_view suffix);
	///@}

	///@{
	/// Removes a prefix / suffix if existent
	/**
		See general note about "Case Conversion" above.

		Example:

		    iremove_suffix("FILE.TXT", ".txt") -> "FILE"
	*/
	[[nodiscard]] std::string remove_prefix(std::string_view str, std::string_view prefix);
	[[nodiscard]] std::string iremove_prefix(std::string_view str, std::string_view prefix);
	[[nodiscard]] std::string_view remove_prefix_view(std::string_view str, std::string_view prefix);
	[[nodiscard]] std::string_view iremove_prefix_view(std::string_view str, std::string_view prefix);

	[[nodiscard]] std::string remove_suffix(std::string_view str, std::string_view suffix);
	[[nodiscard]] std::string iremove_suffix(std::string_view str, std::string_view suffix);
	[[nodiscard]] std::string_view remove_suffix_view(std::string_view str, std::string_view suffix);
	[[nodiscard]] std::string_view iremove_suffix_view(std::string_view str, std::string_view suffix);
	///@}

	///@{
	/// Replaces all occurrences of `search` with `replace`
	/**
		See general note about "Case Conversion" above.
	*/
	[[nodiscard]] std::string replace_all(std::string_view str, std::string_view search, std::string_view replace);
	[[nodiscard]] std::string ireplace_all(std::string_view str, std::string_view search, std::string_view replace);
	///@}

	///@{
	/// Removes a token separated by any of the given delims
	/**
		No effect if given string doesn't contain any delimiter.
		Removes the leading/trailing token together with its delimiter.

		Example:

		    remove_prefix_token("aaa/bbb/ccc", "/") -> "bbb/ccc"
		    remove_suffix_token("aaa.bbb,ccc", ".,") -> "aaa.bbb"
		
	*/
	[[nodiscard]] std::string remove_first_token(std::string_view str, std::string_view delims);
	[[nodiscard]] std::string_view remove_first_token_view(std::string_view str, std::string_view delims);
	[[nodiscard]] std::string remove_last_token(std::string_view str, std::string_view delims);
	[[nodiscard]] std::string_view remove_last_token_view(std::string_view str, std::string_view delims);
	///@}

	/// Normalizes a delimited string
	/**
		Removes any duplicated, leading or trailing delimiters.
		Replaces any delimiter with the first of the given delimiters.

		Example:

		    normalize_delims(".aaa.,bbb..ccc,,") -> "aaa.bbb.ccc"
		
	*/
	[[nodiscard]] std::string normalize_delims(std::string_view str, std::string_view delims);

	/// Splits a delimited string into its tokens
	/**
		Keeps empty tokens.
	*/
	[[nodiscard]] std::vector<std::string> split(std::string_view str, std::string_view delims);

	///@{
	/// Returns the n-th token of a delimited string
	/**
		Like `split(str, delims)[n]`, but more efficient.
		Returns empty string if there is no n-th token.

		Example:

		    split_nth("key = value; # comment", "#", 0) -> "key = value; "
		
	*/
	[[nodiscard]] std::string split_nth(std::string_view str, std::string_view delims, size_t n);
	[[nodiscard]] std::string_view split_nth_view(std::string_view str, std::string_view delims, size_t n);
	///@}

	/// Joins the given strings to a compound string by simply concatenating them as-is
	template <class... StringView>
	[[nodiscard]] std::string join(const StringView&... str)
	{
		std::string_view e[] = { str... , ""};
		return detail::join_impl(e, sizeof...(str));
	}

	/// Joins the given strings to a delimited string
	/**
		Individual tokens are trimmed by the given delimiters and concatenated by
		inserting the first of the given delimiters inbetween non-empty tokens.

		Example:

		    join_delimited(" ", " aaa", "  bbb ", " ccc") -> "aaa bbb ccc"
		
	*/
	template <class... StringView>
	[[nodiscard]] std::string join_delimited(std::string_view delims, const StringView&... str)
	{
		std::string_view e[] = { str... , ""};
		return detail::join_impl(e, sizeof...(str), delims);
	}

	namespace detail
	{
		[[nodiscard]] std::string join_impl(const std::string_view* list, size_t n, std::string_view delims = {});
	}
}